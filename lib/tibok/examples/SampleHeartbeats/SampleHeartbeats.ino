/*
  SampleHeartbeats.ino
  Simpleng paggamit ng lahat ng heartbeat na may Active HIGH logic.

  Ipinapakita sa sketch na ito ang iba't ibang uri ng `HeartbeatLevel`,
  kung saan ang bawat LED (o buzzer, o vibration motor) sa pin 13 hanggang 8 ay
  tumitibok sa kaukulang  antas, na may default na Active HIGH logic (HIGH = ON).

  Author: Lakan Haraya Dima
  Date: 2025-08-17
*/

#include <Arduino.h>
#include <Tibok.h>

// Lumikha ng `Tibok` limbagay
Tibok indicator1(13, Tibok::EMERGENCY);
Tibok indicator2(12, Tibok::CRITICAL);
Tibok indicator3(11, Tibok::WARNING);
Tibok indicator5(10, Tibok::NORMAL);
Tibok indicator4(9, Tibok::STANDBY);

void setup() {
}

void loop() {
    // Panatilihin ang tibok
    indicator1.update();
    indicator2.update();
    indicator3.update();
    indicator4.update();
    indicator5.update();
}
