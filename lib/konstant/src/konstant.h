#pragma once

// Global na konstant para sa Proyektong LNDH

// === Komunikasyon ===
#define BAUD_RATE 115200
#define MAX_PACKET_SIZE 256

// === Pagtitiyempo ===
#define TIMEOUT_MS 1000
#define HEARTBEAT_INTERVAL 1000
#define RETRY_DELAY 500

// === Mga Sensor ===
#define SENSOR_THRESHOLD 500
#define SENSOR_MAX_VALUE 1023
#define SENSOR_MIN_VALUE 0

/**
 * BERSIYON
 * 
 * Format: <Proyekto>.<Yunit>.<HenerasyonRebisyon>.<Mayor>.<Menor>.<Patse>.<Yugto>
 * Proyekto = LH (LundayHangin)
 * Yunit = PS | MK | TD | KL
 * HenerasyonRebisyon = hal. 01A, 01B, ...
 * Mayor = 0..n
 * Menor = 0..n
 * Patse = 0..n
 * Yugto = X (Eksperimental), B (Beta), L (Labas), ...
 *
 * Pangunahing bersiyon ng bawat yunit
 */

// Bersiyon ng yunit ng Pangunahing Sasakyan
#define LH_PS_VERSION "vLH.PS.01A.0.1.0.X"

// Bersiyon ng yunit ng Malayuang Kontrol
#define LH_MK_VERSION "vLH.MK.01A.0.1.0.X"

// Bersiyon ng yunit ng Takad Daungan
#define LH_TD_VERSION "vLH.TD.01A.0.1.0.X"

// Bersiyon ng yunit ng Kontrol sa Lupa
#define LH_KL_VERSION "vLH.KL.01A.0.1.0.X"

// ==============================================
// ==============================================
// ==============================================
// ==============================================

// Struct para sa mas madaling management
struct UnitVersion {
    const char* key;     // short code ("PS", "MK", ...)
    const char* label;   // human-readable label
    const char* version; // version string
};

extern const UnitVersion unitVersions[];
extern const size_t unitCount;

void printVersion(const char* unit = "ALL", Stream &out = Serial);