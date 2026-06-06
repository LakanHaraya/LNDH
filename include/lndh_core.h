#pragma once

// ==========================
// NODE IDENTITIES
// ==========================
enum NodeID {
  NODE_RCU = 1,  // LH_MK
  NODE_ADU = 2,  // LH_KL
  NODE_DBU = 3,  // LH_PS
  NODE_GCS = 4   // LH_TD
};

// ==========================
// SYSTEM STATES
// ==========================
enum SystemState {
  STATE_IDLE,
  STATE_ARMED,
  STATE_ACTIVE,
  STATE_DOCKED,
  STATE_FAILSAFE,
  STATE_EMERGENCY
};

// ==========================
// COMMAND TYPES
// ==========================
enum CommandType {
  CMD_NONE,
  CMD_ARM,
  CMD_DISARM,
  CMD_TAKEOFF,
  CMD_LAND,
  CMD_MOVE,
  CMD_DOCK,
  CMD_RETURN,
  CMD_STATUS
};