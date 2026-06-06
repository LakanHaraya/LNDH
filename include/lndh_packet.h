#pragma once

#include <stdint.h>
#include "lndh_core.h"

// ==========================
// CORE PACKET STRUCTURE
// ==========================
struct LNDHPacket {
  NodeID source;        // sino ang nagpadala
  NodeID target;        // para kanino

  CommandType command;  // anong utos

  SystemState state;    // optional system context

  float value;          // primary payload
  float value2;         // secondary payload

  uint32_t timestamp;   // sync / debugging

  uint8_t checksum;     // integrity check
};