#include <LundayHangin.h>
// task

/**
 * UptimeTask
 * ----------
 * Paulit-ulit na pag-uulat ng aktibong oras
 */

class UptimeTask : public LndhTask {
public:
    UptimeTask() {
        name = "aktibong oras";
        period_ms = 5000;
    }

    void loop(uint32_t now_ms) override {
        // TODO: ilimbag ang aktibong oras sa logger / GCS
        (void)now_ms;
    }
};