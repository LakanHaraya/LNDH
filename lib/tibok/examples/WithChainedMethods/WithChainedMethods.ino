/*
  WithChainedMethods.ino
  Pagpapakita ng paggamit ng chaining method sa Tibok library.

  Ipinapakita sa sketch na ito ang paggamit ng Tibok library na may chaining method.
  Ginagamit nito ang GPIO pin 13 upang makontrol ang isang LED na may iba't ibang
  configurations tulad ng Active LOW logic, CRITICAL heartbeat level (250ms pulse), 
  at enable state na naka-set sa true.

  Author: Lakan Haraya Dima
  Date: 2025-04-28
*/

#include <Arduino.h>
#include <Tibok.h>

// Gumamit ng GPIO pin 13 para sa LED
Tibok tibok(13);

void setup() {
    // Itakda ang LED sa mga sumusunod na kumpigurasyon gamit ang dugtungang metodo:
    // Itinakda sa active LOW logic, heartbeat sa CRITICAL (250ms pulse), at naka-enable
    tibok.setActiveHigh(false).setHeartbeat(Tibok::CRITICAL).enable();

    // Pag-verify sa mga setting
    Serial.begin(115200);
    Serial.println("Sinimulan ang Tibok");

    Serial.print("Pin: ");
    Serial.println(tibok.getPin());
    Serial.print("Antas ng Tibok: ");
    Serial.println(tibok.getLabel());
    Serial.print("Aktibong Mataas: ");
    Serial.println(tibok.isActiveHigh() ? "OPO" : "DIPO");
    Serial.print("Pinagana: ");
    Serial.println(tibok.isEnabled() ? "OPO" : "DIPO");
}

void loop() {
    // Patuloy na i-update ang estado ng Tibok (heartbeat) sa LED
    tibok.update();
}
