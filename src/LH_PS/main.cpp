#include <LundayHangin.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("[LNDH] Tungkulin: ");
  Serial.println(lndh_role_name());
}

void loop() {
  static uint32_t last = 0;
  if (millis() - last > 5000) {
    last = millis();
    Serial.print("[LNDH] Tungkulin: ");
    Serial.println(lndh_role_name());
  }
}