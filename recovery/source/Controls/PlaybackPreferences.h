#pragma once
#import <Foundation/Foundation.h>
#include <math.h>

// These preferences describe a deliberate speed choice, not a temporary hold.
static inline void YTLRememberPlaybackRate(NSUserDefaults *defaults, double rate) {
    if ([defaults boolForKey:@"rememberPlaybackSpeed"] && isfinite(rate) && rate >= 0.25 && rate <= 10.0)
        [defaults setDouble:rate forKey:@"rememberedPlaybackRate"];
}
static inline double YTLPreferredPlaybackRate(NSUserDefaults *defaults, NSInteger index) {
    if ([defaults boolForKey:@"rememberPlaybackSpeed"]) {
        double rate = [defaults doubleForKey:@"rememberedPlaybackRate"];
        if (isfinite(rate) && rate >= 0.25 && rate <= 10.0) return rate;
    }
    const double rates[] = {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 3, 4, 5};
    return index >= 0 && index < 11 ? rates[index] : 1.0;
}
