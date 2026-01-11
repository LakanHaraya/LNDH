#include <LundayHangin.h>
// core 
// timebase

static LndhTask* tasks[8];  // TODO: naikukumpigurang limitasyon
static uint32_t task_count = 0;

void lndh_core_init() {
    task_count = 0;
    // TODO: watchdog hook
    // TODO: power-management hook
}

bool lndh_core_register(LndhTask* task) {
    if (!task || task_count >= 8) {
        // TODO: diagnostics hook
        return false;  
    }

    tasks[task_count++] = task;
    task->setup();
    return true;
}

void lndh_core_loop() {
    const uint32_t now = lndh_now_ms();

    for (uint32_t i = 0; i < task_count; i++) {
        LndhTask* t = tasks[i];
        if (t->is_due(now)){
            t->loop(now);
            t->mark_run(now);
        }
    }

    // TODO: idle hook (low power / yield)
}