#include <LundayHangin.h>
// task

/**
 * HeartbeatTask
 * -------------
 * Tumutukoy na ang firmware ay buhay.
 */

class HeartbeatTask : public LndhTask {
public: 
    HeartbeatTask() {
        name = "tibok";
        period_ms = 1000;
    }

    void loop(uint32_t now_ms) override {
        // TODO: itikwas ang LED (tungkulin ang magpapasya sa pin)
        // TODO: ilabas ang telemetriya ng tibok
        (void)now_ms;
    }
};

// TODO: ilantad ang factory o static instance kung kailangan
