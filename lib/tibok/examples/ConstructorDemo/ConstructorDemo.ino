/*
  ConstructorDemo.ino - Halimbawa para sa Tibok Library
  Iba't ibang paraan ng pagbuo ng Tibok object gamit ang constructor.

  Ipinapakita ng sketch na ito kung paano lumikha ng maramihang `Tibok` objects
  gamit ang iba't ibang kombinasyon ng constructor arguments. Sa pamamagitan ng
  paggamit ng default at explicit na mga argumento, ipinapakita rito kung paano
  i-configure ang tibok level, logic level (activeHigh), at initial enabled state.

  Mga Halimbawa ng Konstruksiyon:
    - Tibok(2)
      → Itinakda ang unang parameter at default values sa tatlong huling parameter.
    - Tibok(3, Tibok::WARNING)
      → Itinakda ang unang dalawang parameter at default values sa dalawang huling parameter.
    - Tibok(4, Tibok::CRITICAL, true)
      → Itinakda ang unang tatlong parameter at default values sa huling parameter.ed = true (default)
    - Tibok(5, Tibok::EMERGENCY, true, true)
      → Kompletong custom configuration.

  Layunin:
    - Ipakita ang flexibility ng constructor ng `Tibok` class.
    - I-highlight kung paano maaaring i-set ang iba't ibang configuration sa pagsisimula pa lamang.

  Tandaan:
    - Walang Serial output sa sketch na ito; pagmasdan ang mga LED sa mga pin na 2–5.
    - Siguraduhing may tamang resistors at LEDs ang mga pin para sa visual feedback.

  Author: Lakan Haraya Dima
  Date: 2025-04-25
*/
#include <Arduino.h>
#include <Tibok.h>

// Apat na magkakaibang setup ng Tibok
Tibok tibok2(2);  // level = NORMAL (default), activeHigh = true (default), enabled = true (default) 
Tibok tibok3(3, Tibok::WARNING);  // activeHigh = true (default), enabled = true (default)
Tibok tibok4(4, Tibok::CRITICAL, true); // enabled = true (default)
Tibok tibok5(5, Tibok::EMERGENCY, true, true); 

void setup() {
    // Walang kailangang setup code bukod sa automatic constructor init
}

void loop() {
    // Patakbuhin ang update para sa bawat instance
    tibok2.update();
    tibok3.update();
    tibok4.update();
    tibok5.update();
}
