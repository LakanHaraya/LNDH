#include "InputSystem.h"

void initInputSystem() {
  Serial.println("    [SYS] Nasimulan ang kunwariang sistema ng input.");
  randomSeed(analogRead(A0));
}

void readInputs(ControlData &ctrl) {
  ctrl.mode      = random(0, 4);
  ctrl.throttle  = random(0, 255);
  ctrl.swiveller = random(0, 255);
  ctrl.rudder    = random(0, 255);
  ctrl.elevator  = random(0, 255);
  ctrl.ballonet  = random(0, 255);
    // add more here if needed
}
