#pragma once

#include <Arduino.h>

/**
 * LNDH Task
 * ---------
 * Baseng klase para sa lahat ng kooperatibong hindi-bumabalakid na gawain.
 */

struct LndhTask {
    const char* name = "walang ngalan";
    uint32_t period_ms = 1000;
    uint32_t last_run_ms = 0;

    virtual void setup() {
        // TODO: opsiyonal na isang-beses na inisyalisasyon
    }

    virtual void loop(uint32_t now_ms) = 0;

    bool is_due(uint32_t now_ms) const {
        return (now_ms - last_run_ms) >= period_ms;
    }

    void mark_run(uint32_t now_ms) {
        last_run_ms = now_ms;
    }

    virtual ~LndhTask() = default;
};
