/* ======================================================
 *  MK Main Control Program (Modular Simulation Build)
 *  Device: Arduino Nano ESP32
 *  Version: 0.3 Modular
 *  Author: L. H. Dima
 * ====================================================== */

#include <Arduino.h>
#include "ControlPacket.h"
#include "InputSystem.h"

// 🕒 Timestamp function
String timeStamp() {
  unsigned long ms = millis();
  unsigned long s = ms / 1000;
  unsigned long m = s / 60;
  unsigned long h = m / 60;
  char buf[32];
  sprintf(buf, "[%02lu:%02lu:%02lu.%03lu]", h % 24, m % 60, s % 60, ms % 1000);
  return String(buf);
}

// 🧩 Mga Global na Bagay
ControlData ctrl;
uint8_t packetBuf[64];
size_t packetLen = 0;

// ======================================================
// Setup
// ======================================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== MK Modular Simulation Start ===\n");
  initInputSystem();
}

// ======================================================
// Main Loop
// ======================================================
void loop() {
  readInputs(ctrl);

  Serial.print(timeStamp());
  Serial.println(" [MK:PS] Nagpapadala ng kunwariang kontrol...");

  buildMKPSControlPacket(ctrl, packetBuf, packetLen);
  printMKPSControlPacket(packetBuf, packetLen);

  Serial.println();
  delay(500);
}
