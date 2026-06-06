#pragma once

#include "comm_interface.h"

class CommManager {
public:
  void init(CommInterface* driver);

  bool sendPacket(const LNDHPacket& packet);
  bool receivePacket(LNDHPacket& packet);

  void update(); // polling / background handling

private:
  CommInterface* driver;
};