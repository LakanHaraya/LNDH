#include <Arduino.h>
#include "bersiyon.h"

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("=== Mga Bersiyon ng Yunit ng LNDH ===");
  Serial.println("Pangunahing Sasakyan  : " LH_PS_VERSION);
  Serial.println("Malayuang Kontroler   : " LH_MK_VERSION);
  Serial.println("Takad Daungan         : " LH_TD_VERSION);
  Serial.println("Kontrol sa Lupa       : " LH_KL_VERSION);
}

void loop() {
  // wala pa
}
