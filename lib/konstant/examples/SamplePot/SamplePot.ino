/*
 * Simpleng koneksiyon sa pagitan ng Arduino Uno at potentiometer:
 * - Ikonekta ang gitnang pin ng potentiometer sa A0 pin ng Arduino.
 * - Ikonekta ang isang dulo ng potentiometer sa 5V pin ng Arduino.
 * - Ikonekta ang kabilang dulo ng potentiometer sa GND pin ng Arduino.
 */

#include <Arduino.h>
#include <konstant.h>

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("Binabanhaw ang Yunit LNDH...");
}

void loop() {
  int sensorValue = analogRead(A0);

  if (sensorValue > SENSOR_THRESHOLD) {
    Serial.println("Pinasikad ang sensor!");
  }

  delay(HEARTBEAT_INTERVAL);
  Serial.println("Buhay pa din...");
}
