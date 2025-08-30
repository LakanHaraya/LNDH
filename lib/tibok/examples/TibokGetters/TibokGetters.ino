/*
  GettersDemo.ino - Halimbawa para sa Tibok Library
  Paggamit ng iba't ibang getter methods upang kunin ang estado ng LED.

  Ipinapakita ng sketch na ito kung paano gamitin ang iba't ibang 
  getter functions ng Tibok library upang makuha ang mga sumusunod:

    - Numero ng pin na ginagamit
    - Tatak (label) ng heartbeat level
    - Kasalukuyang heartbeat interval sa milliseconds
    - Kung Active HIGH o Active LOW ang logic ng LED
    - Kung enabled o disabled ang tibok
    - Ang kasalukuyang estado ng output pin (HIGH o LOW)
    - Oras (in ms) kung kailan huling nagpalit ang LED ng estado

  Ang impormasyong ito ay ipinapadala sa Serial Monitor sa pagsisimula ng sketch.
  Bukod dito, nagpapatuloy pa rin ang tibok ng LED gamit ang update() function.

  Author: Lakan Haraya Dima
  Date: 2025-04-25
*/
#include <Arduino.h>
#include <Tibok.h>

Tibok statusLed(LED_BUILTIN, Tibok::WARNING);  // Gumamit ng built-in LED para sa demo

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Hintayin ang Serial monitor

    Serial.println("=== Tibok Getters Demo ===");

    Serial.print("Pin: ");
    Serial.println(statusLed.getPin());

    Serial.print("Tatak: ");
    Serial.println(statusLed.getLabel());

    Serial.print("Aktibong Mataas: ");
    Serial.println(statusLed.isActiveHigh() ? "true" : "false");

    Serial.print("Pinagana: ");
    Serial.println(statusLed.isEnabled() ? "true" : "false");

    Serial.print("Kasalukuyang Estado (Nakasindi ba LED?): ");
    Serial.println(statusLed.getState() ? "HIGH" : "LOW");

    Serial.print("Huling Tikwas (ms): ");
    Serial.println(statusLed.getLastToggle());
}

void loop() {
    statusLed.update();
}
