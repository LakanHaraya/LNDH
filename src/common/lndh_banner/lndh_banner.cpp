#include <LundayHangin.h>

const char* lndh_role_name() {
    switch (LNDH_ROLE) {
        case LNDH_ROLE_PS:      return "LH_PS (Pangunahing Sasakyan)";
        case LNDH_ROLE_MK:      return "LH_MK (Malayuang Kontroler)";
        case LNDH_ROLE_TD:      return "LH_TD (Takad Daungan)";
        case LNDH_ROLE_KL:      return "LH_KL (Kontrol sa Lupa)";
        case LNDH_ROLE_TEST:    return "LH_TEST (Kaligirang Pansubok)";
        default:                return "HINDI KILALA";
    }
}

void lndh_print_banner(Stream& out) {
    out.print("[LNDH] Tungkulin: ");
    out.print(lndh_role_name());
    out.print(" | Bersiyon: ");
    out.println(LNDH_VERSION_STRING);
}
