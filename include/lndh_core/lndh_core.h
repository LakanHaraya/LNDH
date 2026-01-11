#pragma once

#include <Arduino.h>
#include <lndh_task/lndh_task.h>

/**
 * LNDH Core Scheduler
 * -------------------
 * Kooperatibo, at agnostiko sa tungkulin na tagapagpatakbo ng gawain.
 */

void lndh_core_init();
bool lndh_core_register(LndhTask* task);
void lndh_core_loop();