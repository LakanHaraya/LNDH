#include <Arduino.h>
#include <bersiyon.h>

void setup() {
  Serial.begin(9600);
  Serial.println("=== Mga Yunit ng Bersiyon ng LNDH ===");
  Serial.println(LH_PS_VERSION);
  Serial.println(LH_MK_VERSION);
  Serial.println(LH_TD_VERSION);
  Serial.println(LH_KL_VERSION);
}

void loop() {
  // Wala pa tayong gagawin dito
}
