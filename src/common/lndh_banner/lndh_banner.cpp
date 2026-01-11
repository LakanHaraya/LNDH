#include <LundayHangin.h>

const char* lndh_role_code() {
    switch (LNDH_ROLE) {
        case LNDH_ROLE_PS:      return LNDH_ROLE_CODE_PS;
        case LNDH_ROLE_MK:      return LNDH_ROLE_CODE_MK;
        case LNDH_ROLE_TD:      return LNDH_ROLE_CODE_TD;
        case LNDH_ROLE_KL:      return LNDH_ROLE_CODE_KL;
        case LNDH_ROLE_TEST:    return LNDH_ROLE_CODE_TEST;
        default:                return LNDH_ROLE_CODE_X;
    }
}

const char* lndh_role_name() {
    switch (LNDH_ROLE) {
        case LNDH_ROLE_PS:      return LNDH_ROLE_NAME_PS;
        case LNDH_ROLE_MK:      return LNDH_ROLE_NAME_MK;
        case LNDH_ROLE_TD:      return LNDH_ROLE_NAME_TD;
        case LNDH_ROLE_KL:      return LNDH_ROLE_NAME_KL;
        case LNDH_ROLE_TEST:    return LNDH_ROLE_NAME_TEST;
        default:                return LNDH_ROLE_NAME_X;
    }
}

void lndh_print_banner(Stream& out) {
    out.print("[LNDH] Tungkulin: ");
    out.print(lndh_role_code());
    out.print(" (");
    out.print(lndh_role_name());
    out.print(") | Bersiyon: ");
    out.print(LNDH_VERSION_STRING);
    out.print(" (");
    out.print(LNDH_VERSION_CODENAME);
    out.println(")");
}
