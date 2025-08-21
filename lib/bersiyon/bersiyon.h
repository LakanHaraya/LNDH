#ifndef BERSIYON_H
#define BERSIYON_H

#include <Arduino.h>

// --- Format: <Project>.<Unit>.<GenerationRevision>.<Major>.<Minor>.<Patch>.<Stage>
// Project = LH (LundayHangin)
// Unit = PS | MK | TD | KL
// GenerationRevision = hal. 01A, 01B, ...
// Major = 0..n
// Minor = 0..n
// Patch = 0..n
// Stage = X (Experimental), B (Beta), L (Labas), ...

struct Version {
    String project;
    String unit;
    int generation;     // numeric part (e.g., 01)
    char revision;      // letter part (e.g., A, B, C)
    int major;
    int minor;
    int patch;
    char stage;         // e.g., X, B, L
};

namespace Bersiyon {
    Version parse(const String &versionString);
    String toString(const Version &v);

    // Compare two versions
    // Returns:
    //   0  = equal
    //   1  = first > second
    //  -1  = first < second
    // -10  = incomparable (different project or unit)
    int compare(const Version &a, const Version &b);

    // Human-readable message version of compare()
    String compareMessage(const Version &a, const Version &b);
}

#endif
