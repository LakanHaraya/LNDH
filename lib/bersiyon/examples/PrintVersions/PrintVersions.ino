#include <Arduino.h>
#include <bersiyon.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  printUnitVersions();   // Tawag sa function
}

void loop() {
  // walang laman
}