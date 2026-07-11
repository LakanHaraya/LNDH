# LNDH Starter Architecture Proposal

## Overview

Layunin: magtayo ng malinaw na pangunang balangkas para sa LNDH ecosystem na tumatakbo sa Arduino Nano ESP32 (Arduino framework) at gumagamit ng environment-specific sources para sa bawat node.

Ang apat na node:
- `LNDH_MK` (RCU / remote controller unit)
- `LNDH_PS` (ADU / airship drone unit)
- `LNDH_TD` (DBU / docking base unit)
- `LNDH_KL` (GCS / ground control station)

## PlatformIO Context

Ang bawat node ay binubuo paiba sa `platformio.ini` gamit ang `build_src_filter`:
- `src/LH_MK/`
- `src/LH_PS/`
- `src/LH_TD/`
- `src/LH_KL/`

May build-time macro din para sa role:
- `-DLNDH_ROLE=LNDH_ROLE_MK`
- `-DLNDH_ROLE=LNDH_ROLE_PS`
- `-DLNDH_ROLE=LNDH_ROLE_TD`
- `-DLNDH_ROLE=LNDH_ROLE_KL`

Ang target board ay `arduino_nano_esp32` at framework ay `arduino`.

## Suggested Folder Layout

```
include/
  lndh_core.h
  lndh_packet.h
  lndh_config.h

lib/lndh_comm/
  comm_interface.h
  comm_manager.h
  lndh_node_base.h
  mock_comm.h

src/LH_MK/main.cpp
src/LH_PS/main.cpp
src/LH_TD/main.cpp
src/LH_KL/main.cpp

test/
  test.cpp
```

## Architecture Layers

### 1. Core Protocol (`include/`)

Dito ilalagay ang shared definitions na walang depende sa transport o node:
- node identities
- system states
- command definitions
- packet payload schema
- helper functions para sa packet validation

#### Example: `include/lndh_core.h`

```cpp
#pragma once

#include <stdint.h>

enum class NodeID : uint8_t {
  NONE = 0,
  RCU = 1,
  ADU = 2,
  DBU = 3,
  GCS = 4,
};

enum class SystemState : uint8_t {
  IDLE = 0,
  ARMED,
  ACTIVE,
  DOCKED,
  FAILSAFE,
  EMERGENCY,
};

enum class CommandType : uint8_t {
  NONE = 0,
  ARM,
  DISARM,
  MOVE,
  STOP,
  TAKEOFF,
  LAND,
  DOCK,
  RETURN,
  STATUS,
  ACK,
  NACK,
  HEARTBEAT,
};

static inline const char* toString(NodeID role) {
  switch (role) {
    case NodeID::RCU: return "RCU";
    case NodeID::ADU: return "ADU";
    case NodeID::DBU: return "DBU";
    case NodeID::GCS: return "GCS";
    default: return "NONE";
  }
}
```

#### Example: `include/lndh_packet.h`

```cpp
#pragma once

#include <stdint.h>
#include "lndh_core.h"

struct LNDHPacket {
  NodeID source;
  NodeID target;
  CommandType command;
  SystemState state;
  uint16_t sequence;
  float value;
  float value2;
  uint32_t timestamp;
  uint8_t checksum;
};

static inline uint8_t calculateChecksum(const LNDHPacket& packet) {
  // TODO: implement lightweight checksum or CRC
  // For now, simple XOR of bytes can be used as placeholder.
  return 0;
}
```

### 2. Communication Layer (`lib/lndh_comm/`)

Ito ang abstraction layer para sa transport:
- `CommInterface` ay abstract driver interface
- `CommManager` ay delegator at queue / retry placeholder
- `mock_comm.h` ay local loopback para simulation at unit testing

#### Example: `lib/lndh_comm/comm_interface.h`

```cpp
#pragma once

#include "lndh_packet.h"

class CommInterface {
public:
  virtual void init() = 0;
  virtual bool send(const LNDHPacket& packet) = 0;
  virtual bool receive(LNDHPacket& packet) = 0;
  virtual bool isConnected() = 0;
  virtual ~CommInterface() {}
};
```

#### Example: `lib/lndh_comm/comm_manager.h`

```cpp
#pragma once

#include "comm_interface.h"

class CommManager {
public:
  void begin(CommInterface* driver);
  bool sendPacket(const LNDHPacket& packet);
  bool receivePacket(LNDHPacket& packet);
  void update();

private:
  CommInterface* driver = nullptr;
};
```

### 3. Shared Node Base (`lib/lndh_comm/lndh_node_base.h`)

Dito dapat maganap ang common lifecycle:
- `begin()`
- `update()`
- heartbeat timer
- state transition helper
- packet dispatch
- virtual callbacks para sa node-specific logic

#### Example: `lib/lndh_comm/lndh_node_base.h`

```cpp
#pragma once

#include <Arduino.h>
#include "lndh_core.h"
#include "lndh_packet.h"
#include "comm_manager.h"

class LNDHNodeBase {
public:
  explicit LNDHNodeBase(NodeID id, const char* name);
  void begin(uint32_t baud = 115200);
  void update();
  void handlePacket(const LNDHPacket& packet);
  void sendState(SystemState state);
  void sendCommand(NodeID target, CommandType command, float value = 0.0f, float value2 = 0.0f);
  void setState(SystemState nextState);

  NodeID nodeId() const;
  SystemState state() const;
  bool isInitialized() const;

protected:
  virtual void onSetup() {}
  virtual void onLoop(uint32_t now) {}
  virtual void onHeartbeat(uint32_t now) {}
  virtual void onStateChange(SystemState from, SystemState to) {}
  virtual void onPacket(const LNDHPacket& packet) {}
  virtual void onCommand(CommandType command) {}

  void log(const char* message) const;

private:
  NodeID nodeId_;
  const char* nodeName_;
  SystemState currentState_;
  uint32_t lastHeartbeatMs_;
  uint32_t lastLoopMs_;
  uint32_t heartbeatIntervalMs_;
  uint32_t loopIntervalMs_;
  CommManager comm_;
  bool initialized_;
};
```

## Node-Specific Source (`src/LH_*/`)

Bawat node ay dapat maglaan ng maliit na application layer na nag-iinherit mula sa base class. Ang `main.cpp` ay boot / wiring code lang.

#### Example entry point: `src/LH_MK/main.cpp`

```cpp
#include <Arduino.h>
#include "lndh_node_base.h"
#include "lndh_core.h"
#include "mock_comm.h"

class MKNode : public LNDHNodeBase {
public:
  MKNode() : LNDHNodeBase(NodeID::RCU, "LH_MK") {}

protected:
  void onSetup() override {
    log("MK ready");
    setState(SystemState::IDLE);
  }

  void onLoop(uint32_t now) override {
    (void)now;
    // TODO: read input, send commands, handle retries
  }

  void onCommand(CommandType command) override {
    // TODO: handle local commands or mode changes
  }

  void onPacket(const LNDHPacket& packet) override {
    // TODO: process ACK/NACK/state updates from PS
  }
};

MKNode node;

void setup() {
  node.begin(115200);
}

void loop() {
  node.update();
}
```

#### Example entry point: `src/LH_PS/main.cpp`

```cpp
#include <Arduino.h>
#include "lndh_node_base.h"
#include "lndh_core.h"
#include "mock_comm.h"

class PSNode : public LNDHNodeBase {
public:
  PSNode() : LNDHNodeBase(NodeID::DBU, "LH_PS") {}

protected:
  void onSetup() override {
    log("PS ready");
    setState(SystemState::IDLE);
  }

  void onCommand(CommandType command) override {
    // TODO: execute safe payload actions for MOVE/ARM/STOP
    sendCommand(NodeID::RCU, CommandType::ACK);
    sendState(currentState());
  }
};

PSNode node;

void setup() {
  node.begin(115200);
}

void loop() {
  node.update();
}
```

## Recommended Design Principles

- `include/` = pure shared protocol types, no hardware logic
- `lib/` = reusable runtime and transport abstraction
- `src/` = node-specific wiring and behavior only
- `test/` = compile-time mock harness and smoke tests
- `platformio.ini` = one project, multiple node builds

## Minimum Viable Protocol

Commands:
- `ARM`
- `DISARM`
- `MOVE`
- `STOP`
- `ACK`
- `NACK`
- `HEARTBEAT`

States:
- `IDLE`
- `ARMED`
- `ACTIVE`
- `DOCKED`
- `FAILSAFE`

## Early Milestones

1. Buoin ang `include/` at `lib/lndh_comm/` ayon sa shared model.
2. Gumawa ng `MockComm` para sa local message loop.
3. I-wire ang `src/LH_MK/main.cpp` at `src/LH_PS/main.cpp` sa minimal command flow.
4. Patunayan ang `CMD_ARM` → `ACK` → `STATE_ARMED` loop.
5. Idagdag `TD` at `KL` bilang observer stubs.

## TODO

- [ ] Implement packet serialization / checksum
- [ ] Add sequence numbering at protocol layer
- [ ] Add timeout/retry policy in `CommManager`
- [ ] Add `PacketLogger` / diagnostics helper
- [ ] Implement transport backends: Serial, ESP-NOW, WiFi
- [ ] Create `src/LH_TD/` and `src/LH_KL/` node classes
