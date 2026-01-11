#pragma once

#include <Arduino.h>

/**
 * LNDH Timebase
 * --------------
 * Isang punto ng abstraksiyon para sa oras ng sistema
 * Dinisenyo nang hindi-bumabalakid
 */

inline uint32_t lndh_now_ms() {
    // TODO: Palitan sa esp_timer_get_time()/1000 kapag ang RTOS ay pinagana
    return millis();
}