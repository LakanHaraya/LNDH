#include <Arduino.h>
#include <konstant.h>
#include <Tibok.h>

Tibok tibok(13, Tibok::EMERGENCY);

void setup() {
    // 1. Simulan ang Sunurang Komunikasyon
    Serial.begin(BAUD_RATE);
    delay(TIMEOUT_MS);

    // 2. Italatag ang Impormasyon ng Tatagsil
    printVersion("PS");

    // 3. Inisyalisasyon ng mga Estado

    // 4. Simpleng tibok at pagsubok ng mga sensor at aktuweytor

    // 5. Mensahe ng Pagtapos ng Panimula
}

void loop() {
    // optional, kung may gusto kang ulitin
    tibok.update();
}
