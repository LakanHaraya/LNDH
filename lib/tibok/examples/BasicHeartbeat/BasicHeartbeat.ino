/*
  BasicHeartbeat.ino
  Simpleng paggamit ng default heartbeat na may Active HIGH logic.

  Ipinapakita sa sketch na ito ang pinakapangunahing gamit ng Tibok library,
  kung saan ang isang LED (sa pin 13) ay tumitibok gamit ang default na "Tibok::NORMAL"
  na antas (1000ms interval), na may Active HIGH logic (HIGH = ON).

  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <Tibok.h>

// Lumikha ng Tibok object sa pin 13 na may NORMAL tibok (1000ms)
Tibok tibok(13, Tibok::NORMAL);

void setup() {
}

void loop() {
    // Panatilihin ang tibok
    tibok.update();
}
