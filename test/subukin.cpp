/* ======================================================
 *  MK Main Control Program (Simulation Build)
 *  Device: Arduino Nano ESP32
 *  Version: 0.2 (with ControlPacket simulation)
 *  Author: L. H. Dima
 *  Reference: mLNDH-0010 (Control Packet Specification)
 * ======================================================
 */

#include <Arduino.h>
#include <string.h>

// ======================================================
// 🕒 Utility: ISO Timestamp for Serial prints
// ======================================================
String timeStamp() {
  unsigned long ms = millis();
  unsigned long s = ms / 1000;
  unsigned long m = s / 60;
  unsigned long h = m / 60;
  char buf[32];
  sprintf(buf, "[%02lu:%02lu:%02lu.%03lu]", h % 24, m % 60, s % 60, ms % 1000);
  return String(buf);
}

// ======================================================
// ⚙️ Data Structures (Mock Control values)
// ======================================================
struct ControlData {
  uint8_t throttle;
  uint8_t swiveller;
  uint8_t rudder;
  uint8_t elevator;
  uint8_t ballonet;
  uint8_t mode;
};

ControlData ctrl;  // global instance

// ======================================================
// 🔢 CRC8 Computation (Polynomial 0x07)
// ======================================================
uint8_t computeCRC8(const uint8_t *data, size_t length) {
  uint8_t crc = 0x00;
  for (size_t i = 0; i < length; i++) {
    crc ^= data[i];
    for (uint8_t j = 0; j < 8; j++) {
      if (crc & 0x80)
        crc = (crc << 1) ^ 0x07;
      else
        crc <<= 1;
    }
  }
  return crc;
}

// ======================================================
// 🧮 Mock Input Generator
// ======================================================
void readInputs() {
  // Simulate changing values
  ctrl.mode     = random(0, 4);
  ctrl.throttle = random(0, 255);
  ctrl.swiveller = random(0, 255);
  ctrl.rudder   = random(0, 255);
  ctrl.elevator = random(0, 255);
  ctrl.ballonet = random(0, 255);  
  // add more here if needed
}

// ======================================================
// 📦 Control Packet Sender (Simulated Framing)
// ======================================================
void sendControlToPS() {
  Serial.print(timeStamp());
  Serial.println(" [KTRL] Nagpapadala ng mga kunwariang halaga ng kontrol:");
  Serial.print("    flg: "); Serial.print(ctrl.mode);
  Serial.print(" | thr: "); Serial.print(ctrl.throttle);
  Serial.print(" | swi: "); Serial.print(ctrl.swiveller);
  Serial.print(" | rud: "); Serial.print(ctrl.rudder);
  Serial.print(" | ele: "); Serial.print(ctrl.elevator);
  Serial.print(" | bal: "); Serial.println(ctrl.ballonet);

  // --- ControlPacket Simulation ---
  uint8_t startByte = 0x7E;
  uint8_t endByte   = 0x7F;

  // Example header (ID, Seq, Flags)
  static uint8_t seq = 0;
  uint8_t header[3] = {0x01, seq++, 0xAA}; 

  // Payload (mock control data)
  uint8_t payload[sizeof(ctrl)];
  payload[0] = ctrl.mode;
  payload[1] = ctrl.throttle;
  payload[2] = ctrl.swiveller;
  payload[3] = ctrl.rudder;
  payload[4] = ctrl.elevator;
  payload[5] = ctrl.ballonet;

  // Combine header + payload for CRC computation
  uint8_t temp[sizeof(header) + sizeof(payload)];
  memcpy(temp, header, sizeof(header));
  memcpy(temp + sizeof(header), payload, sizeof(payload));
  uint8_t crc = computeCRC8(temp, sizeof(temp));

  // Print the packet as hex (framed)
  Serial.print("    [KTRL] Pakete: ");
  Serial.print("7E ");
  for (int i = 0; i < sizeof(temp); i++) {
    if (i < 3) Serial.print("(H)");
    else Serial.print("(P)");
    if (temp[i] < 16) Serial.print("0");
    Serial.print(temp[i], HEX);
    Serial.print(" ");
  }
  Serial.print("(C)");
  if (crc < 16) Serial.print("0");
  Serial.print(crc, HEX);
  Serial.println(" 7F");

  Serial.println();
}

// ======================================================
// 📡 Telemetry Sender (Mock)
// ======================================================
void sendTelemetryToKL() {
  Serial.print(timeStamp());
  Serial.println(" [TLM] Nagpapadala ng telemetriya (kunwarian)");
  Serial.println();
  // Placeholder for telemetry structure
}

// ======================================================
// ⚙️ Setup
// ======================================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n === Pagsisimula ng MK Simulasyon ng Kontrol === \n");
  randomSeed(analogRead(A0));
}

// ======================================================
// 🔁 Main Loop
// ======================================================
void loop() {
  readInputs();
  sendControlToPS();
  sendTelemetryToKL();
  delay(100);  // simulate update interval
}
