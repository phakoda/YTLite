#pragma once
#include <math.h>

// Fit the full frame inside the usable area without cropping either dimension.
static inline double YTLContentScale(double width, double height, double ratio) {
    if (!isfinite(width) || !isfinite(height) || !isfinite(ratio) || width <= 0 || height <= 0 || ratio <= 0) return 0;
    return fmin(width / ratio, height);
}
static inline int YTLShouldProtectContent(int enabled, int fullscreen, int zoomed, int panel, int allVideos, double ratio) {
    return enabled && fullscreen && !zoomed && !panel && isfinite(ratio) && ratio > 0 && (allVideos || ratio >= 1.97);
}
