/* ============================================================
 *  LNDH Timestamp System
 *  Device: Arduino Nano ESP32
 *  Version: 0.3 (Internal only, expandable framework)
 *  Author: L. H. Dima
 *  Description:
 *    - Internal millis() timekeeping na may ISO 8601 display.
 *    - May unified source tag + priority code.
 *    - Modular design para sa madaling pagdagdag ng RTC, GPS, NTP.
 * ============================================================ */

#include <Arduino.h>

/* ------------------------------------------------------------
 * ENUMS & STRUCTS
 * ------------------------------------------------------------ */

// === Time Source Definitions ===
enum TimeSourceCode : uint8_t {
  SRC_NTP = 0b0100,  // NTP Server, priority 4
  SRC_SAT = 0b0111,  // GPS Satellite, priority 7
  SRC_RTC = 0b1010,  // RTC Module, priority 10
  SRC_INT = 0b1101   // Internal Clock, priority 13
};

// === TimeZone Offset (Hours) ===
const int TIMEZONE_OFFSET_HOURS = 8; // +8:00 for Philippines Standard Time (PhST)

struct TimeStatus {
  TimeSourceCode timeSource;  // Unified code (tag + priority)
  unsigned long syncAge;      // seconds since last sync (for future use)
  bool validTime;             // true if time source is valid
  String isoString;           // formatted timestamp
};

/* ------------------------------------------------------------
 * UTILITY FUNCTIONS
 * ------------------------------------------------------------ */

// Kunin ang 3-letter tag mula sa source code
String getSourceTag(TimeSourceCode src) {
  switch (src) {
    case SRC_NTP: return "NTP";
    case SRC_SAT: return "SAT";
    case SRC_RTC: return "RTC";
    case SRC_INT: return "INT";
    default: return "UNK";
  }
}

// Simpleng ISO formatter para sa internal millis-based time
String formatInternalISO(unsigned long ms) {
  unsigned long totalSeconds = ms / 1000;
  unsigned long hours   = (totalSeconds / 3600) % 24;
  unsigned long minutes = (totalSeconds / 60) % 60;
  unsigned long seconds = totalSeconds % 60;

  char buffer[40];
  snprintf(buffer, sizeof(buffer),
           "YYYY-MM-DDT%02lu:%02lu:%02lu+8:00",
           hours, minutes, seconds);
  return String(buffer);
}

// I-format bilang [TAG: ISO_STRING]
String formatTimestamp(const TimeStatus &status) {
  String tag = getSourceTag(status.timeSource);
  return "[" + tag + ": " + status.isoString + "]";
}

/* ------------------------------------------------------------
 * CORE TIMEKEEPING
 * ------------------------------------------------------------ */

TimeStatus currentTime;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("=== LNDH Timestamp System (Internal Mode) ===");

  // Initial state
  currentTime.timeSource = SRC_INT;
  currentTime.syncAge = 0;
  currentTime.validTime = true;
}

void loop() {
  unsigned long now = millis();
  currentTime.isoString = formatInternalISO(now);

  Serial.println(formatTimestamp(currentTime));

  delay(1000);
}
