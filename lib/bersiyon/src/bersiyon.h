#pragma once

// --- Format: <Proyekto>.<Yunit>.<HenerasyonRebisyon>.<Mayor>.<Menor>.<Patse>.<Yugto>
// Proyekto = LH (LundayHangin)
// Yunit = PS | MK | TD | KL
// HenerasyonRebisyon = hal. 01A, 01B, ...
// Mayor = 0..n
// Menor = 0..n
// Patse = 0..n
// Yugto = X (Eksperimental), B (Beta), L (Labas), ...

// bersiyon.h
#pragma once
#include <Arduino.h>

// Pangunahing bersiyon ng bawat yunit
#define LH_PS_VERSION "vLH.PS.01A.0.1.0.X"
#define LH_MK_VERSION "vLH.MK.01A.0.1.0.X"
#define LH_TD_VERSION "vLH.TD.01A.0.1.0.X"
#define LH_KL_VERSION "vLH.KL.01A.0.1.0.X"

// Minimal function (string key ang gamit)
void printVersion(const char* unit = "ALL", Stream &out = Serial);
