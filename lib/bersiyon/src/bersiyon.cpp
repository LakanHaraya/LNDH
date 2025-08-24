#include <Arduino.h>
#include "bersiyon.h"

void printUnitVersions(Stream &out) {
    out.println(F("======= Mga Bersiyon ng Yunit ng LNDH ======="));
    out.print(F("Pangunahing Sasakyan (PS)  : "));
    out.println(LH_PS_VERSION);
    out.print(F("Malayuang Kontroler (MK)   : "));
    out.println(LH_MK_VERSION);
    out.print(F("Takad Daungan (TD)         : "));
    out.println(LH_TD_VERSION);
    out.print(F("Kontrol sa Lupa (KL)       : "));
    out.println(LH_KL_VERSION);
}
