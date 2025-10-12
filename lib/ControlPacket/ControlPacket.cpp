#include "ControlPacket.h"
#include <string.h>

// CRC-8 (polynomial 0x07)
uint8_t computeCRC8(const uint8_t *data, size_t length) {
  uint8_t crc = 0x00;
  for (size_t i = 0; i < length; i++) {
    crc ^= data[i];
    for (uint8_t j = 0; j < 8; j++) {
      crc = (crc & 0x80) ? (crc << 1) ^ 0x07 : (crc << 1);
    }
  }
  return crc;
}

void buildMKPSControlPacket(const ControlData &ctrl, uint8_t *buffer, size_t &len) {
  const uint8_t startByte = 0x7E;
  const uint8_t endByte   = 0x7F;
  static uint8_t seq = 0;

  uint8_t header[3] = {0x01, seq++, 0xAA};
  uint8_t payload[6] = {
    ctrl.mode, ctrl.throttle, ctrl.swiveller,
    ctrl.rudder, ctrl.elevator, ctrl.ballonet
  };

  uint8_t temp[sizeof(header) + sizeof(payload)];
  memcpy(temp, header, sizeof(header));
  memcpy(temp + sizeof(header), payload, sizeof(payload));

  uint8_t crc = computeCRC8(temp, sizeof(temp));

  // Assemble framed packet
  size_t idx = 0;
  buffer[idx++] = startByte;
  memcpy(buffer + idx, temp, sizeof(temp));
  idx += sizeof(temp);
  buffer[idx++] = crc;
  buffer[idx++] = endByte;

  len = idx; // kabuuang haba ng pakete
}

void printMKPSControlPacket(const uint8_t *buffer, size_t len) {
  Serial.print("    [MK:PS] Pakete: ");
  for (size_t i = 0; i < len; i++) {
    if (buffer[i] < 16) Serial.print("0");
    Serial.print(buffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
