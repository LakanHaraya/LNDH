#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("\nKumusta mula sa LH.PS!\n");
  Serial.println("Bersiyon: " + String(LH_PS_VERSION));
  Serial.println();
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
