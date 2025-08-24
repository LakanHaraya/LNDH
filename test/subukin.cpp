#include <Arduino.h>
#include <bersiyon.h>
#include <konstant.h>

void testVersion() {
    Serial.println("=== Bersiyon Test ===");
    printUnitVersions();
}

void testKonstant() {
    Serial.println("=== Konstant Test ===");
    Serial.print("BAUD_RATE = ");
    Serial.println(BAUD_RATE);
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("=== Pagsubok LNDH ===");
    testVersion();
    testKonstant();
}

void loop() {
    // optional, kung may gusto kang ulitin
}
