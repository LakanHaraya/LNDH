#include "comm_manager.h"

void CommManager::init(CommInterface* driverInstance) {
  driver = driverInstance;
  driver->init();
}

bool CommManager::sendPacket(const LNDHPacket& packet) {
  if (!driver) return false;
  return driver->send(packet);
}

bool CommManager::receivePacket(LNDHPacket& packet) {
  if (!driver) return false;
  return driver->receive(packet);
}

void CommManager::update() {
  // TODO:
  // - retry logic
  // - timeout handling
  // - future queue system
}