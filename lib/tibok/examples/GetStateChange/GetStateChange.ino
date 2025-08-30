/*
  GetStateChange.ino - Halimbawa para sa Tibok Library
  Pagmamasid sa pagbabago ng estado ng LED gamit ang getters.

  Ipinapakita ng sketch na ito kung paano gamitin ang `getState()` at 
  `getLastToggle()` methods mula sa Tibok library upang mag-log ng mga 
  pagbabago sa LED state habang tumitibok ito sa isang partikular na pattern.

  Sa tuwing magbabago ang estado ng LED (mula ON patungong OFF o vice versa),
  ipi-print sa Serial Monitor ang kasalukuyang estado at kung anong millisecond
  ito huling nagbago. Nililimitahan ang pag-print sa 10 pagbabago lamang para sa demo.

  Mga Tampok:
    - Ginagamit ang built-in LED ng board.
    - Gumagamit ng NORMAL heartbeat level (default: 1000ms).
    - Maaari ring subukang palitan ang heartbeat level sa WARNING o CRITICAL 
      upang makita ang epekto sa bilis ng tibok at log output.

  Author: Lakan Haraya Dima
  Date: 2025-04-25
*/

#include <Arduino.h>
#include <Tibok.h>

Tibok statusLed(LED_BUILTIN, Tibok::NORMAL);  // Gumamit ng built-in LED para sa demo
// Subukang palitan ang HEARTBEAT level sa WARNING o CRITICAL para sa iba't ibang mga epekto

unsigned int printCounter = 0;  // Counter para sa bilang ng mga pag-print
const unsigned int maxPrints = 10;  // Limitahan ang pag-print sa 10 beses para sa demo
bool lastState = LOW;  // I-save ang huling estado ng LED

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Hintayin ang Serial monitor

    Serial.println(F("=== Tibok Getters Demo ==="));
    Serial.println(F("[Kasalukuyang Estado] | [Huling Tikwas]"));
}

void loop() {
    // Patuloy na ina-update ang estado ng LED (pagtibok)
    statusLed.update();

    // I-print lamang kung nagbago ang estado ng LED
    bool currentState = statusLed.getState();

    if (currentState != lastState && printCounter < maxPrints) {
        // I-print ang kasalukuyang estado (HIGH/LOW) at ang huling tikwas (sa ms)
        Serial.print(currentState ? F("HIGH") : F("LOW "));
        Serial.print(F(" | "));
        Serial.println(statusLed.getLastToggle());
        
        printCounter++;  // I-increment ang counter
        lastState = currentState;  // I-update ang last state
    }
}
