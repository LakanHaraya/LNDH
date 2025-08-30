/*
  ActiveLowHighHeartbeat.ino
  Gamit ang Active LOW at Active HIGH configuration ng LED.

  Ang sketch na ito ay nagpapakita kung paano gamitin ang Tibok library
  upang makontrol ang dalawang LED: isa sa Active LOW (pin 13) at isa sa Active HIGH (pin 12).
  Ang parehong LED ay kikilos sa pattern ng "Tibok::WARNING" heartbeat (500ms interval).
  
  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <Tibok.h>

// Lumikha ng Tibok object para sa pin 13 (Active LOW).
Tibok invertedLED(13, Tibok::WARNING, false); // Active LOW configuration (true = Active HIGH, false = Active LOW)

// Lumikha ng Tibok object para sa pin 12 (Active HIGH).
Tibok normalLED(12, Tibok::WARNING, true); // Active HIGH configuration (true = Active HIGH, false = Active LOW)

void setup() { 
}

void loop() {
    // Tawagin ito sa bawat ikot ng loop upang panatilihin ang tibok para sa parehong LED.
    invertedLED.update();
    normalLED.update();
}
