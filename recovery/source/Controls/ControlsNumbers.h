#pragma once
#include <stdint.h>
#include <math.h>

// ARM64 FCVTZS returns zero for NaN and saturates on overflow. These helpers
// retain that behavior without undefined C floating-to-integer conversions.
static inline int64_t YTLControlsInt64(double value) {
    if (isnan(value)) return 0;
    if (value >= 0x1p63) return INT64_MAX;
    if (value <= -0x1p63) return INT64_MIN;
    return (int64_t)value;
}
static inline int32_t YTLControlsInt32(float value) {
    if (isnan(value)) return 0;
    if (value >= 0x1p31f) return INT32_MAX;
    if (value <= -0x1p31f) return INT32_MIN;
    return (int32_t)value;
}
static inline float YTLControlsQuantize(float value, float step) {
    // Original FRINTA rounds to nearest with ties away from zero.
    return step * roundf(value / step);
}
