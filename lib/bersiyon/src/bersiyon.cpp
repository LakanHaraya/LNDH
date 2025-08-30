#include <Arduino.h>
#include "bersiyon.h"

void printVersion(const char* unit, Stream &out) {
    if (strcmp(unit, "PS") == 0)      out.println(F("Tatagsil: " LH_PS_VERSION));
    else if (strcmp(unit, "MK") == 0) out.println(F("Tatagsil: " LH_MK_VERSION));
    else if (strcmp(unit, "TD") == 0) out.println(F("Tatagsil: " LH_TD_VERSION));
    else if (strcmp(unit, "KL") == 0) out.println(F("Tatagsil: " LH_KL_VERSION));
    else {
        out.println(F("Mga Tatagsil:"));
        out.println(LH_PS_VERSION);
        out.println(LH_MK_VERSION);
        out.println(LH_TD_VERSION);
        out.println(LH_KL_VERSION);
    }
}
