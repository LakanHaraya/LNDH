#pragma once 

#define LNDH_VERSION_MAJOR 0
#define LNDH_VERSION_MINOR 1
#define LNDH_VERSION_PATCH 1
#define LNDH_VERSION_CODENAME "Core Runtime"

//// #define LNDH_VERSION_STRING "0.1.0"

// Pantulong na macro para sa stringification
#define LNDH_STR_HELPER(x) #x
#define LNDH_STR(x) LNDH_STR_HELPER(x)

// Buoin ang "major.minor.patch"
#define LNDH_VERSION_STRING LNDH_STR(LNDH_VERSION_MAJOR) "." LNDH_STR(LNDH_VERSION_MINOR) "." LNDH_STR(LNDH_VERSION_PATCH)
