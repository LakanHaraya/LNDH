#include <Arduino.h>
#include "konstant.h"

// Listahan ng lahat ng mga yunit
const UnitVersion unitVersions[] = {
    { "PS", "Pangunahing Sasakyan", LH_PS_VERSION },
    { "MK", "Malayuang Kontrol", LH_MK_VERSION },
    { "TD", "Takad Daungan", LH_TD_VERSION },
    { "KL", "Kontrol sa Lupa", LH_KL_VERSION }
    // Magdagdag lang ng bagong entri dito
};
const size_t unitCount = sizeof(unitVersions) / sizeof(unitVersions[0]);

/**
 * @brief Maglimbag ng bersiyon ng yunit (string key ang gamit)
 *
 * @param unit Ang key ng yunit, alinman sa `"PS"`, `"MK"`, `"TD"`, `"KL"` (default sa `"ALL"`)
 * @param out Ang stream na paglalagyan ng output (default sa `Serial`)
 */
void printVersion(const char* unit, Stream &out) {
    if (strcmp(unit, "ALL") == 0) {
        out.println(F("Mga Tatagsil:"));
        for (size_t i = 0; i < unitCount; i++) {
            out.print(unitVersions[i].label);
            out.print(F(": "));
            out.println(unitVersions[i].version);
        }
    } else {
        for (size_t i = 0; i < unitCount; i++) {
            if (strcmp(unit, unitVersions[i].key) == 0) {
                out.print(F("Tatagsil: "));
                out.println(unitVersions[i].version);
                return;
            }
        }
        out.println(F("Hindi kilalang susi ng yunit."));
    }
}
