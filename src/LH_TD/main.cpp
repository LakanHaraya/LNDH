#include <Arduino.h>

// ======================
// KUMPIGURASYON
// ======================
#define SERIAL_BAUD 115200
#define HEARTBEAT_INTERVAL 1000
#define SETUP_DELAY 1000

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(SETUP_DELAY);
  Serial.println("Kumusta mula sa LH_TD!");
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(HEARTBEAT_INTERVAL);
}
