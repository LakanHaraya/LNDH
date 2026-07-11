# LNDH Development Notes — TO BE CONTINUED

## Kasalukuyang Yugto

Nasa **Foundation Architecture Phase** ng LNDH.

Layunin:

* Magtatag ng scalable at modular na architecture.
* Magkaroon ng iisang communication language para sa lahat ng nodes.
* Iwasan ang maagang hardware-specific implementation.

---

## Mga Natapos

### System Nodes

| Code | Unit                         | Role                                      |
| ---- | ---------------------------- | ----------------------------------------- |
| MK   | RCU (Remote Controller Unit) | Human control input                       |
| PS   | ADU (Airship Drone Unit)     | Pangunahing sasakyan                      |
| TD   | DBU (Docking Base Unit)      | Charging at docking infrastructure        |
| KL   | GCS (Ground Control Station) | Monitoring, diagnostics, mission planning |

---

### Napagkasunduang Architecture

Communication Model:

* Bidirectional
* Asymmetric
* Role-based messaging

Ibig sabihin:

* Lahat ng nodes ay maaaring magpadala at tumanggap ng mensahe.
* Hindi pare-pareho ang uri ng mensaheng ipinapadala ng bawat node.
* Ang kahulugan ng mensahe ay nakabatay sa papel ng node.

---

<!-- ### Mga Nagawa nang Files

```txt
include/
├── lndh_core.h
└── lndh_packet.h

lib/
└── lndh_comm/
    ├── comm_interface.h
    ├── comm_manager.h
    └── comm_manager.cpp
``` -->

---

## Kasalukuyang Focus

MK ↔ PS Minimal Working Protocol

RCU ↔ ADU

Layunin:

* Makapagpadala ng command ang MK.
* Makatanggap ng command ang PS.
* Makapagpadala ng ACK ang PS.
* Makapagbalik ng state update ang PS.

---

## Proposed Initial Commands

```cpp
CMD_ARM
CMD_DISARM
CMD_MOVE
CMD_STOP

CMD_ACK
CMD_NACK
CMD_HEARTBEAT
```

---

## Proposed Initial States

```cpp
STATE_IDLE
STATE_ARMED
STATE_ACTIVE
STATE_FAILSAFE
```

---

## Minimal Handshake Flow

### 1. ARM

MK → PS

```txt
CMD_ARM
```

PS → MK

```txt
CMD_ACK
STATE_ARMED
```

---

### 2. MOVE

MK → PS

```txt
CMD_MOVE
```

PS → MK

```txt
CMD_ACK
STATE_ACTIVE
```

---

### 3. STOP

MK → PS

```txt
CMD_STOP
```

PS → MK

```txt
CMD_ACK
STATE_IDLE
```

---

## Hindi Pa Gagawin

Mga bagay na sadyang ipinagpaliban:

* ESP-NOW implementation
* RF implementation
* WiFi transport
* Retry system
* Packet priority
* Encryption
* Telemetry streams
* Mission planning
* Docking logic
* GCS logic

Dahilan:

Mas mahalaga munang gumana ang MK ↔ PS command loop.

---

## Susunod na Hakbang

1. Suriin ang kasalukuyang laman ng:

   * lndh_core.h
   * lndh_packet.h

2. I-finalize ang minimal command set.

3. Gumawa ng:

   * MK command sender
   * PS command processor

4. Gumamit muna ng mock transport o serial simulation.

5. Patunayan ang buong flow:

```txt
MK
 ↓
CMD_ARM
 ↓
PS
 ↓
ACK
 ↓
STATE_ARMED
```

Kapag gumana ito, mayroon nang unang operational slice ng LNDH ecosystem.

---

## Prinsipyong Napagkasunduan

"Control loop first, ecosystem later."

Unahin ang MK ↔ PS communication bago ang TD (DBU) at KL (GCS).

Ang protocol at architecture ay dapat mauna bago ang hardware-specific implementation.
