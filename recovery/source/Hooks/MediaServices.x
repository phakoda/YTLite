#import "MediaServicesHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import <objc/runtime.h>

// Original 0xcc72c removes the first tracking query item and everything after it.
static NSString *YTLTruncateShareQuery(NSString *string) {
    if (!string.length) return string;
    NSURLComponents *components = [NSURLComponents componentsWithString:string];
    if (!components || !components.queryItems) return string;
    NSArray *names = @[@"si", @"is", @"pp"];
    for (NSUInteger index = 0; index < components.queryItems.count; index++) {
        if ([names containsObject:components.queryItems[index].name]) {
            components.queryItems = index == 0 ? nil : [components.queryItems subarrayWithRange:NSMakeRange(0, index)];
            return components.URL.absoluteString ?: string;
        }
    }
    return string;
}
%group YTLMediaServices
%hook MDXPlaybackRouteButtonController
- (BOOL)isPersistentCastIconEnabled { return ytpBool(@"noCast") ? NO : %orig; }
- (void)updateRouteButton:(id)button { if (!ytpBool(@"noCast")) %orig; }
- (void)updateAllRouteButtons { if (!ytpBool(@"noCast")) %orig; }
%end
%hook YTSettings
- (void)setDisableMDXDeviceDiscovery:(BOOL)disabled { %orig(ytpBool(@"noCast") | disabled); }
- (BOOL)areHintsDisabled { return ytpBool(@"noHints"); }
- (void)setHintsDisabled:(BOOL)disabled { %orig(ytpBool(@"noHints") | disabled); }
%end
%hook _UIConcretePasteboard
- (void)setString:(NSString *)value { %orig(ytpBool(@"noShareChunk") ? YTLTruncateShareQuery(value) : value); }
%end
%hook YTIIosSystemShareEndpoint
- (NSString *)shareURL {
    BOOL enabled = ytpBool(@"noShareChunk");
    NSString *url = %orig;
    return enabled ? YTLTruncateShareQuery(url) : url;
}
%end
%hook YTSingleVideoController
- (void)setAudioFormatConstraint:(uintptr_t)constraint {
    %orig;
    if (class_getInstanceVariable([self class], "_playerView")) {
        id<YTLMediaServicesPlayerView> view = [self valueForKey:@"_playerView"];
        [[view _viewControllerForAncestor] selectCaptions];
    }
}
%end
%hook YTWatchFlowController
- (BOOL)shouldExitFullScreenOnFinish { return ytpBool(@"exitFullscreen"); }
%end
%end
void YTLInstallMediaServicesHooks(void) { %init(YTLMediaServices); }
