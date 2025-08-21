#include "bersiyon.h"

namespace Bersiyon {

// --- Parse version string to struct ---
Version parse(const String &versionString) {
    Version v;
    int idx1 = versionString.indexOf('.');
    int idx2 = versionString.indexOf('.', idx1 + 1);
    int idx3 = versionString.indexOf('.', idx2 + 1);
    int idx4 = versionString.indexOf('.', idx3 + 1);
    int idx5 = versionString.indexOf('.', idx4 + 1);
    int idx6 = versionString.indexOf('.', idx5 + 1);

    v.project   = versionString.substring(0, idx1);
    v.unit      = versionString.substring(idx1 + 1, idx2);

    String genRev = versionString.substring(idx2 + 1, idx3);
    v.generation  = genRev.substring(0, genRev.length() - 1).toInt();
    v.revision    = genRev.charAt(genRev.length() - 1);

    v.major = versionString.substring(idx3 + 1, idx4).toInt();
    v.minor = versionString.substring(idx4 + 1, idx5).toInt();
    v.patch = versionString.substring(idx5 + 1, idx6).toInt();

    v.stage = versionString.charAt(idx6 + 1);

    return v;
}

// --- Convert struct back to string ---
String toString(const Version &v) {
    char buf[50];
    sprintf(buf, "%s.%s.%02d%c.%d.%d.%d.%c",
            v.project.c_str(),
            v.unit.c_str(),
            v.generation,
            v.revision,
            v.major,
            v.minor,
            v.patch,
            v.stage);
    return String(buf);
}

// --- Compare versions numerically ---
int compare(const Version &a, const Version &b) {
    if (a.project != b.project || a.unit != b.unit) {
        return -10; // incomparable
    }

    if (a.generation != b.generation) return (a.generation > b.generation) ? 1 : -1;
    if (a.revision != b.revision)     return (a.revision > b.revision) ? 1 : -1;
    if (a.major != b.major)           return (a.major > b.major) ? 1 : -1;
    if (a.minor != b.minor)           return (a.minor > b.minor) ? 1 : -1;
    if (a.patch != b.patch)           return (a.patch > b.patch) ? 1 : -1;
    if (a.stage != b.stage)           return (a.stage > b.stage) ? 1 : -1;

    return 0; // equal
}

// --- Human-readable message ---
String compareMessage(const Version &a, const Version &b) {
    int res = compare(a, b);
    switch (res) {
        case 0:  return "Versions are equal";
        case 1:  return "First version is newer";
        case -1: return "First version is older";
        case -10: return "Cannot compare: different project or unit";
        default: return "Unknown comparison result";
    }
}

} // namespace Bersiyon
