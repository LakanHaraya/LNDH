#pragma once

#include <Arduino.h>
#include "lndh_role/lndh_role.h"
#include "lndh_version/lndh_version.h"

void lndh_print_banner(Stream& out = Serial);
const char* lndh_role_code();
const char* lndh_role_name();