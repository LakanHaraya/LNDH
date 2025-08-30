#include "Tibok.h"

// Private helper method para ipatupad ang kasalukuyang estado ng output pin.
void Tibok::_applyState() {
    bool _effectiveState = _state;

    if (_level == STANDBY) {
        // Baliktarin ang active logic para sa STANDBY lang
        _effectiveState = !_state;
    }

    digitalWrite(_pin, (_activeHigh ? _effectiveState : !_effectiveState));
}

//
void Tibok::_toggle() {
    _lastToggle = millis();
    _state = !_state;
    _applyState();
}

// STANDBY:
void Tibok::_updateStandby(unsigned long now) {
    constexpr uint8_t BURST_COUNT = 2;
    constexpr uint16_t BURST_INTERVAL = 150;    // bawat tikwas (150 * 4 = 600ms)
    constexpr uint16_t BURST_PAUSE = 1400;      // tigil sa pagitan ng bugso

    if (_stdbyInBurst) {
        if (now - _lastToggle >= BURST_INTERVAL) {
            _toggle();
            _stdbyBurstCtr++;
            _lastToggle = now;

            if (_stdbyBurstCtr >= BURST_COUNT * 2) { 
                _stdbyInBurst = false;
                _stdbyBurstCtr = 0;
                _lastToggle = now;
            }
        }
    }
    else {
        if (now - _lastToggle >= BURST_PAUSE) {
            _stdbyInBurst = true;
            _lastToggle = now;
        }
    }
}

void Tibok::_updateWithInterval(unsigned long now, uint16_t interval) {
    if (now - _lastToggle >= interval) {
        _toggle();
        _lastToggle = now;
    }
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

// Konstruktor ng Tibok class na tumatanggap ng pin number, heartbeat level, active HIGH/LOW flag, at enabled flag.
Tibok::Tibok(int pin, HeartbeatLevel level, bool activeHigh, bool enabled) : _pin(pin), _level(level), _lastToggle(0), _state(false), _activeHigh(activeHigh), _enabled(enabled) {
    pinMode(_pin, OUTPUT);  // Itinatakda ang pin bilang output
    _applyState();           // Itinatakda ang default state
}

// I-update ang estado ng status indicator batay sa kasalukuyang antas ng pagtibok (dapat ilagay sa loob ng `loop()`).
void Tibok::update() {
    if (!_enabled) return;
    unsigned long now = millis();

    switch (_level) {
        case EMERGENCY:
            _updateWithInterval(now, 125); // 4Hz
            break;

        case CRITICAL:
            _updateWithInterval(now, 250); // 2Hz
            break;

        case WARNING:
            _updateWithInterval(now, 500); // 1Hz
            break;

        case NORMAL:
            _updateWithInterval(now, 1000); // 0.5Hz
            break;

        case STANDBY:
            _updateStandby(now);
            break;
    }
}

// Itinatakda ang estado ng pagtibok (enabled o disabled).
Tibok& Tibok::enable(bool enabled) {
    _enabled = enabled;
    _applyState(); // I-reset ang estado ng pin ayon sa bagong logic level
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Itinatakda ang estado ng active HIGH o active LOW.
Tibok& Tibok::setActiveHigh(bool activeHigh) {
    _activeHigh = activeHigh;
    // I-reset ang estado ng pin ayon sa bagong logic level
    _applyState();
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Itinatakda ang bagong heartbeat level at ina-update ang tagal ng pagtikwas.
Tibok& Tibok::setHeartbeat(HeartbeatLevel level) {
    _level = level;
    _lastToggle = millis(); // Magreset ng pagtitityempo
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Kinukuha ang pin number ng status indicator.
int Tibok::getPin() const {
    return _pin;
}

// Kinukuha ang label ng kasalukuyang Heartbeat level.
String Tibok::getLabel() const {
    switch (_level) {
        case EMERGENCY: return F("KAGIPITAN");
        case CRITICAL:  return F("KRITIKAL");
        case WARNING:   return F("BABALA");
        case NORMAL:    return F("NORMAL");
        case STANDBY:   return F("ANTABAY");
        default:        return F("DI-KILALA");
    }
}

// Kinukuha ang estado ng active HIGH o active LOW.
bool Tibok::isActiveHigh() const {
    return _activeHigh;
}

// Kinukuha ang estado ng pagtibok (enabled o disabled).
bool Tibok::isEnabled() const {
    return _enabled;
}

// Kinukuha ang kasalukuyang estado ng status indicator.
bool Tibok::getState() const {
    return _state;
}

// Kinukuha ang huling tagal ng pagtikwas ng status indicator.
unsigned long Tibok::getLastToggle() const {
    return _lastToggle;
}