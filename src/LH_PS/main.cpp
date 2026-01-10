#include <LundayHangin.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  lndh_print_banner();
}

void loop() {
  static uint32_t last = 0;
  if (millis() - last > 5000) {
    last = millis();
    lndh_print_banner();
  }
}