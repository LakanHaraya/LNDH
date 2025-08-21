#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Kumusta mula sa LH.TD!");
}

void loop() {
  Serial.println("Lumilikaw...");
  delay(1000);
}
