/* ============================================================
 *  LNDH Timestamp System - NTP Mode (with Internal Fallback)
 *  Device: Arduino Nano ESP32
 *  Version: 0.4 (NTP + Internal)
 *  Author: L. H. Dima
 *  Description:
 *    - Connects to WiFi and syncs with NTP server.
 *    - Falls back to internal millis() if no WiFi/NTP.
 *    - Displays ISO 8601 timestamps with +8:00 timezone.
 * ============================================================ */

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

/* ------------------------------------------------------------
 * CONFIGURATION
 * ------------------------------------------------------------ */

const char* WIFI_SSID     = "Your_WiFi_SSID";
const char* WIFI_PASSWORD = "Your_WiFi_Password";

const long TIMEZONE_OFFSET_SEC = 8 * 3600;  // +8 hours offset
const long NTP_UPDATE_INTERVAL = 3600000;   // update every 1 hour (ms)

/* ------------------------------------------------------------
 * ENUMS & STRUCTS
 * ------------------------------------------------------------ */

enum TimeSourceCode : uint8_t {
  SRC_NTP = 0b0100,  // NTP Server
  SRC_RTC = 0b1010,  // RTC Module (for future)
  SRC_INT = 0b1101   // Internal millis()
};

struct TimeStatus {
  TimeSourceCode timeSource;
  unsigned long syncAge;
  bool validTime;
  String isoString;
};

/* ------------------------------------------------------------
 * OBJECTS
 * ------------------------------------------------------------ */

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", TIMEZONE_OFFSET_SEC, NTP_UPDATE_INTERVAL);

TimeStatus currentTime;
bool wifiConnected = false;

/* ------------------------------------------------------------
 * UTILITIES
 * ------------------------------------------------------------ */

String getSourceTag(TimeSourceCode src) {
  switch (src) {
    case SRC_NTP: return "S1";
    case SRC_RTC: return "S3";
    case SRC_INT: return "S4";
    default: return "S?";
  }
}

// ISO8601 formatter
String formatISOtime(time_t rawTime) {
  struct tm *timeInfo = gmtime(&rawTime);

  char buffer[40];
  snprintf(buffer, sizeof(buffer),
           "%04d-%02d-%02dT%02d:%02d:%02d+8:00",
           timeInfo->tm_year + 1900,
           timeInfo->tm_mon + 1,
           timeInfo->tm_mday,
           timeInfo->tm_hour,
           timeInfo->tm_min,
           timeInfo->tm_sec);
  return String(buffer);
}

// Fallback internal ISO formatter
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

String formatTimestamp(const TimeStatus &status) {
  return "[" + getSourceTag(status.timeSource) + ": " + status.isoString + "]";
}

/* ------------------------------------------------------------
 * CORE LOGIC
 * ------------------------------------------------------------ */

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("=== LNDH Timestamp System (NTP Mode) ===");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");

  unsigned long startAttempt = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttempt < 8000) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.print("WiFi connected: ");
    Serial.println(WiFi.localIP());

    timeClient.begin();
    timeClient.update();

    currentTime.timeSource = SRC_NTP;
    currentTime.validTime = true;
  } else {
    Serial.println("WiFi not available, using internal clock fallback.");
    currentTime.timeSource = SRC_INT;
    currentTime.validTime = true;
  }
}

void loop() {
  if (wifiConnected && WiFi.status() == WL_CONNECTED) {
    if (timeClient.update()) {
      time_t ntpTime = timeClient.getEpochTime();
      currentTime.timeSource = SRC_NTP;
      currentTime.isoString = formatISOtime(ntpTime);
    }
  } else {
    unsigned long now = millis();
    currentTime.timeSource = SRC_INT;
    currentTime.isoString = formatInternalISO(now);
  }

  Serial.println(formatTimestamp(currentTime));
  delay(1000);
}
