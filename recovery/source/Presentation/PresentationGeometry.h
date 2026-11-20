#pragma once
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

// Pure arithmetic shared by UIKit implementations and repository-only host tests.
static inline double YTLToastWidthFraction(bool pad, bool landscape) {
    return pad ? (landscape ? 0.3 : 0.5) : (landscape ? 0.5 : 0.95);
}

static inline double YTLToastPanTranslation(double translation, bool pinnedTop) {
    return pinnedTop ? fmin(translation, 80.0) : fmax(fmin(translation, 0.0), -80.0);
}

static inline double YTLImageInset(double content, double fittedImage, double viewport) {
    double result = (content - fittedImage) * 0.5;
    if (fittedImage < viewport) result -= (viewport - fittedImage) * 0.5;
    return -result;
}

static inline double YTLDetentHeight(double width, double height, double custom, bool half) {
    return width > height ? height : (half ? height * 0.5 : custom);
}

static inline double YTLUnitProgress(double value) {
    // A nonfinite value must not poison a CALayer geometry transaction.
    return isfinite(value) ? fmax(0, fmin(value, 1)) : 0;
}

// Asset indices: sun.min/mid/max, speed.slow/reg/fast, vol.off/low/mid/max.
// The small gaps between 33.3/33.4 and 66.6/66.7 are intentional evidence.
static inline int YTLPlayerIconIndex(double value, long style) {
    if (style == 1) {
        const float rounded = roundf((float)(value * 10.0)) / 10.0f;
        if (rounded < 1) return 3;
        if (rounded == 1) return 4;
        if ((double)rounded >= 1.01) return 5;
        return -1;
    }
    if (style == 2 && value == 0) return 6;
    if (style != 0 && style != 2) return -1;
    const int base = style == 2 ? 7 : 0;
    if (value >= (style == 2 ? 1 : 0) && value <= 33.3) return base;
    if (value >= 33.4 && value <= 66.6) return base + 1;
    if (value >= 66.7 && value <= 100) return base + 2;
    return -1;
}
