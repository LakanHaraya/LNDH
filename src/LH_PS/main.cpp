#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  delay(TIMEOUT_MS);
  Serial.println("\nTatagsil: " + String(LH_PS_VERSION) + "\n");
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
