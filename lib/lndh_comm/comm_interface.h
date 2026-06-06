#pragma once

#include "lndh_packet.h"

// ==========================
// ABSTRACT COMMUNICATION LAYER
// ==========================
class CommInterface {
public:
  virtual void init() = 0;

  virtual bool send(const LNDHPacket& packet) = 0;

  virtual bool receive(LNDHPacket& packet) = 0;

  virtual bool isConnected() = 0;

  virtual ~CommInterface() {}
};