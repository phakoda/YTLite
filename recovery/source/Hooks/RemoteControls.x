#import "RemoteControlsHost.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../Runtime/YTLFeaturePolicy.h"

// Original process-wide bytes 0x1226848 and 0x1226849. Set after the nested registration returns.
static BOOL YTLRemoteBackwardRegistered;
static BOOL YTLRemoteForwardRegistered;

// Original 0xbc45c. The class floatForKey: accessor returns double.
static void YTLUpdateRemoteControls(void) {
    MPRemoteCommandCenter *center=[MPRemoteCommandCenter sharedCommandCenter];
    BOOL backward=[[YTLUserDefaults standardUserDefaults] boolForKey:@"rcSkipBackward"];
    BOOL forward=[[YTLUserDefaults standardUserDefaults] boolForKey:@"rcSkipForward"];
    center.skipBackwardCommand.preferredIntervals=@[@([YTLUserDefaults floatForKey:@"rcSkipBackwardSec"])];
    center.skipForwardCommand.preferredIntervals=@[@([YTLUserDefaults floatForKey:@"rcSkipForwardSec"])];
    center.skipBackwardCommand.enabled=backward;
    center.skipForwardCommand.enabled=forward;
    center.previousTrackCommand.enabled=!backward;
    center.nextTrackCommand.enabled=!forward;
}
%group YTLRemoteControlsEarly
%hook MPRemoteCommand
- (void)addTarget:(id)target action:(SEL)action {
    %orig;
    MPRemoteCommandCenter *center=[MPRemoteCommandCenter sharedCommandCenter];
    if (self==center.previousTrackCommand && !YTLRemoteBackwardRegistered) {
        [center.skipBackwardCommand addTarget:target action:action];
        YTLRemoteBackwardRegistered=YES;
    }
    if (self==center.nextTrackCommand && !YTLRemoteForwardRegistered) {
        [center.skipForwardCommand addTarget:target action:action];
        YTLRemoteForwardRegistered=YES;
    }
    YTLUpdateRemoteControls();
}
%end
%hook MPNowPlayingInfoCenter
- (void)setNowPlayingInfo:(NSDictionary *)info { %orig; YTLUpdateRemoteControls(); }
%end
%end
%group YTLRemoteControlsMain
%hook YTWatchController
- (void)handleRemoteControlEvent:(NSInteger)event withInterval:(double)interval {
    if (event==105 && ytpBool(@"rcSkipBackward")) {
        event=108;
        interval=-[YTLUserDefaults floatForKey:@"rcSkipBackwardSec"];
    } else if (event==104 && ytpBool(@"rcSkipForward")) {
        event=108;
        interval=[YTLUserDefaults floatForKey:@"rcSkipForwardSec"];
    }
    %orig(event,interval);
}
%end
%end
void YTLInstallRemoteControlsEarlyHooks(void) { %init(YTLRemoteControlsEarly); }
void YTLInstallRemoteControlsMainHooks(void) { %init(YTLRemoteControlsMain); }
