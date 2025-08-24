#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("\nKumusta mula sa LH.MK!\n");
  Serial.println("Bersiyon: " + String(LH_MK_VERSION));
  Serial.println();
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
