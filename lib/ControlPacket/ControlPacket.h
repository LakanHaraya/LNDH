#ifndef CONTROL_PACKET_H
#define CONTROL_PACKET_H

#include <Arduino.h>

struct ControlData {
  uint8_t mode;
  uint8_t throttle;
  uint8_t swiveller;
  uint8_t rudder;
  uint8_t elevator;
  uint8_t ballonet;
};

// --- Mga Prototipo ---

uint8_t computeCRC8(const uint8_t *data, size_t length);
void buildMKPSControlPacket(const ControlData &ctrl, uint8_t *buffer, size_t &len);
void printMKPSControlPacket(const uint8_t *buffer, size_t len);

// Magdagdag ng iba pa para sa MKTD at MKKL

// void buildMKTDControlPacket(const ControlData &ctrl, uint8_t *buffer, size_t &len);
// void printMKTDControlPacket(const uint8_t *buffer, size_t len);
// void buildMKKLStatusPacket(const ControlData &ctrl, uint8_t *buffer, size_t &len);
// void printMKKLStatusPacket(const uint8_t *buffer, size_t len);

#endif
