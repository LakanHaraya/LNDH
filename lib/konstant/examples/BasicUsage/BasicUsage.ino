#include <Arduino.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("Binabanhaw ang Yunit LNDH...");
}

void loop() {
  // halimbawa gamit ng ibang konstant
  delay(TIMEOUT_MS);
  Serial.println("Tumatakbo pa rin...");
}
