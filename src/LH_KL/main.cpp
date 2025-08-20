#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hello from LH_KL!");
}

void loop() {
  Serial.println("Looping...");
  delay(1000);
}
