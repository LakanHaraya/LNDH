#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("\nKumusta mula sa LH.TD!\n");
  Serial.println("Bersiyon: " + String(LH_TD_VERSION));
  Serial.println();
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
