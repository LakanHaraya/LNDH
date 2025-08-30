#include <Arduino.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  delay(TIMEOUT_MS);
  printVersion("TD");
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(TIMEOUT_MS);
}
