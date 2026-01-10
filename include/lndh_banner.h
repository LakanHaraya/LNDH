#pragma once

#include <Arduino.h>
#include "lndh_role.h"

inline const char* lndh_role_name() {
    switch (LNDH_ROLE) {
        case LNDH_ROLE_PS: return "PS (Pangunahing Sasakyan)";
        case LNDH_ROLE_MK: return "MK (Malayuang Kontroler)";
        case LNDH_ROLE_TD: return "TD (Takad Daungan)";
        case LNDH_ROLE_KL: return "KL (Kontrol sa Lupa)";
        case LNDH_ROLE_TEST: return "TEST (Kaligirang Pansubok)";
        default: return "HINDI KILALA";
    }
}
