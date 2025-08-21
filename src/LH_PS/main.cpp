#include <Arduino.h>
#include <bersiyon.h>

void setup() {
  Serial.begin(115200);

  Version v1 = Bersiyon::parse("LH.PS.01A.0.1.0.X");
  Version v2 = Bersiyon::parse("LH.PS.01A.0.2.0.X");

  Serial.println(Bersiyon::toString(v1));
  Serial.println(Bersiyon::toString(v2));

  Serial.println(Bersiyon::compareMessage(v1, v2));

  // Example incomparable
  Version v3 = Bersiyon::parse("LH.MK.01A.0.1.0.X");
  Serial.println(Bersiyon::compareMessage(v1, v3));
}

void loop() {}

