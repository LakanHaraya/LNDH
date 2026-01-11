#include <LundayHangin.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  lndh_print_banner();

  lndh_core_init();

  // TODO: irehistro ang, ibinabahagi + pantungkulin, na mga gawain
}

void loop() {
  lndh_core_loop();
}