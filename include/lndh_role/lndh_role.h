#pragma once

#define LNDH_ROLE_PS 1
#define LNDH_ROLE_MK 2
#define LNDH_ROLE_TD 3
#define LNDH_ROLE_KL 4
#define LNDH_ROLE_TEST 99

#define LNDH_ROLE_CODE_PS "LH_PS"
#define LNDH_ROLE_CODE_MK "LH_MK"
#define LNDH_ROLE_CODE_TD "LH_TD"
#define LNDH_ROLE_CODE_KL "LH_KL"
#define LNDH_ROLE_CODE_TEST "LH_TEST"
#define LNDH_ROLE_CODE_X "WALA"

#define LNDH_ROLE_NAME_PS "Pangunahing Sasakyan"
#define LNDH_ROLE_NAME_MK "Malayuang Kontroler"
#define LNDH_ROLE_NAME_TD "Takad Daungan"
#define LNDH_ROLE_NAME_KL "Kontrol sa Lupa"
#define LNDH_ROLE_NAME_TEST "Kaligirang Pansubok"
#define LNDH_ROLE_NAME_X "Hindi Kilala"

#ifndef LNDH_ROLE
#error "Ang LNDH_ROLE ay hindi itinuring! Pakitsek ang platform.ini"
#endif