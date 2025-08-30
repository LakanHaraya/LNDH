#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  delay(TIMEOUT_MS);
  printVersion("PS");
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
