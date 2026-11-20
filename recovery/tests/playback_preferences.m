#import <Foundation/Foundation.h>
#import "../source/Controls/PlaybackPreferences.h"
#import "../source/Hooks/ContentLayout.h"
#include <assert.h>
int main(void) { @autoreleasepool {
    NSString *suite = [@"YTLite.Regression." stringByAppendingString:NSUUID.UUID.UUIDString];
    NSUserDefaults *defaults = [[NSUserDefaults alloc] initWithSuiteName:suite];
    [defaults registerDefaults:@{@"rememberPlaybackSpeed":@YES}];
    assert(YTLPreferredPlaybackRate(defaults, 5) == 1.5);
    YTLRememberPlaybackRate(defaults, 1.75);
    [defaults synchronize];
    NSUserDefaults *nextLaunch = [[NSUserDefaults alloc] initWithSuiteName:suite];
    assert(YTLPreferredPlaybackRate(nextLaunch, 3) == 1.75);
    for (NSNumber *invalid in @[@0, @(-1), @11, @(NAN), @(INFINITY)]) {
        YTLRememberPlaybackRate(defaults, invalid.doubleValue);
        assert(YTLPreferredPlaybackRate(defaults, 3) == 1.75);
    }
    [defaults setBool:NO forKey:@"rememberPlaybackSpeed"];
    YTLRememberPlaybackRate(defaults, 2.0);
    assert(YTLPreferredPlaybackRate(defaults, 3) == 1.0);
    assert([defaults doubleForKey:@"rememberedPlaybackRate"] == 1.75);
    [defaults setBool:YES forKey:@"rememberPlaybackSpeed"];
    YTLRememberPlaybackRate(defaults, 1.0);
    assert(YTLPreferredPlaybackRate(defaults, 5) == 1.0);
    [defaults removeObjectForKey:@"rememberedPlaybackRate"];
    assert(YTLPreferredPlaybackRate(defaults, 5) == 1.5);
    assert(YTLPreferredPlaybackRate(defaults, -1) == 1.0);
    assert(YTLPreferredPlaybackRate(defaults, 11) == 1.0);
    [defaults setDouble:NAN forKey:@"rememberedPlaybackRate"];
    assert(YTLPreferredPlaybackRate(defaults, 5) == 1.5);
    [defaults removePersistentDomainForName:suite];
    unsigned checks = 0;
    for (int enabled=0; enabled<2; enabled++)
    for (int fullscreen=0; fullscreen<2; fullscreen++)
    for (int zoom=0; zoom<2; zoom++)
    for (int panel=0; panel<2; panel++)
    for (int all=0; all<2; all++) {
        assert(YTLShouldProtectContent(enabled,fullscreen,zoom,panel,all,2.0) == (enabled&&fullscreen&&!zoom&&!panel));
        assert(YTLShouldProtectContent(enabled,fullscreen,zoom,panel,all,16.0/9) == (enabled&&fullscreen&&!zoom&&!panel&&all));
        checks += 2;
    }
    for (NSNumber *ratio in @[@1, @(16.0/9), @2, @2.4])
    for (NSNumber *width in @[@300, @694, @1024]) {
        double r=ratio.doubleValue, w=width.doubleValue, h=YTLContentScale(w,390,r);
        assert(h>0 && h<=390 && h*r<=w+0.000001);
        checks++;
    }
    assert(YTLContentScale(0,390,2)==0);
    assert(YTLContentScale(700,390,NAN)==0);
    assert(!YTLShouldProtectContent(1,1,0,0,1,NAN));
    printf("Playback preferences passed; %u content layout cases passed\n", checks+3);
} return 0; }
