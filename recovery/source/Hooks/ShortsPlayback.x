#import "ShortsPlaybackHost.h"
#import "../Helpers/YTLHelper.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import <objc/runtime.h>
#include <string.h>

// Match the ARM64 subtract/conditional-negate even for an overflowing label value.
static NSInteger ShortsPlaybackDistance(NSInteger candidate, NSInteger target) {
    uint64_t bits = (uint64_t)candidate - (uint64_t)target;
    if (bits >> 63) bits = (uint64_t)0 - bits;
    NSInteger result;
    memcpy(&result, &bits, sizeof(result));
    return result;
}

%group YTLShortsPlayback
%hook YTReelPlayerViewController
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLShortsForwardedArgument)transition {
    if ([self respondsToSelector:@selector(maybeLoopPlayback)]) {
        %orig;
        if (ytpInt(@"shortsPlaybackIndex") == 2) [self pause];
    } else if (ytpInt(@"shortsPlaybackIndex") != 2) {
        %orig;
    }
}

- (void)maybeLoopPlayback {
    SEL advance = @selector(reelContentViewRequestsAdvanceToNextVideo:);
    if (ytpInt(@"shortsPlaybackIndex") == 1 && [self respondsToSelector:advance]) {
        if (class_getInstanceVariable([self class], "_isEngagementPanelVisible") &&
            [[self valueForKey:@"_isEngagementPanelVisible"] boolValue]) {
            %orig;
        } else {
            // The packaged call is performSelector:, without a supplied argument.
            [self performSelector:@selector(reelContentViewRequestsAdvanceToNextVideo:)];
        }
    } else {
        %orig;
    }
}

- (void)playbackControllerDidActivateVideo:(YTLShortsForwardedArgument)controller withPlayerResponse:(YTLShortsForwardedArgument)response {
    %orig;
    if (ytpBool(@"restrictShortsPortion")) {
        id firstParent = [self parentResponder];
        static Class rootClass;
        if (!rootClass) rootClass = NSClassFromString(@"YTReelWatchRootViewController");
        if ([firstParent isKindOfClass:rootClass]) {
            id parent = [self parentResponder];
            if (class_getInstanceVariable([parent class], "_isInfinitePlaybackMode")) {
                [parent setValue:@NO forKey:@"_isInfinitePlaybackMode"];
            }
        }
    }
    if (ytpInt(@"shortsWiFiQualityIndex") != 0 || ytpInt(@"shortsCellQualityIndex") != 0) {
        [self autoQuality];
    }
}

%new
- (void)autoQuality {
    if (![self videoQualityController]) return;
    if (!class_getInstanceVariable([[self videoQualityController] class], "_sortedSelectableFormats")) return;
    NSArray<id<YTLShortsSelectableFormat>> *formats = [[self videoQualityController] valueForKey:@"_sortedSelectableFormats"];
    if (!formats.count) return;

    NSInteger index = ytpInt([YTLHelper isConnectedToWiFi] ? @"shortsWiFiQualityIndex" : @"shortsCellQualityIndex");
    int highestResolution = 0;
    NSString *highestLabel = @"144p";
    for (id<YTLShortsSelectableFormat> format in formats) {
        int resolution = [format singleDimensionResolution];
        if (resolution > highestResolution && ![[format qualityLabel] containsString:@"Premium"]) {
            highestLabel = [format qualityLabel];
            highestResolution = resolution;
        }
    }
    NSArray<NSString *> *labels = @[@"Default", highestLabel, @"1080p60", @"1080p", @"720p60", @"720p", @"480p", @"360p", @"240p", @"144p"];
    NSString *selectedLabel = labels[index];
    if (![selectedLabel isEqualToString:highestLabel]) {
        BOOL exact = NO;
        for (id<YTLShortsSelectableFormat> format in formats) {
            if ([[format qualityLabel] isEqualToString:selectedLabel]) { exact = YES; break; }
        }
        if (!exact) {
            NSString *closestLabel = selectedLabel;
            NSInteger closestDistance = NSIntegerMax;
            for (id<YTLShortsSelectableFormat> format in formats) {
                if ([[format qualityLabel] containsString:@"Premium"]) continue;
                NSArray<NSString *> *candidate = [[format qualityLabel] componentsSeparatedByString:@"p"];
                NSArray<NSString *> *desired = [selectedLabel componentsSeparatedByString:@"p"];
                if (candidate.count == 2) {
                    NSInteger distance = ShortsPlaybackDistance([candidate.firstObject integerValue], [desired.firstObject integerValue]);
                    if (distance < closestDistance) {
                        closestLabel = [format qualityLabel];
                        closestDistance = distance;
                    }
                }
            }
            selectedLabel = closestLabel;
        }
    }
    static Class constraintClass;
    if (!constraintClass) constraintClass = NSClassFromString(@"MLQuickMenuVideoQualitySettingFormatConstraint");
    id<YTLShortsConstraint> constraint = [[constraintClass alloc] init];
    if ([constraint respondsToSelector:@selector(initWithVideoQualitySetting:formatSelectionReason:qualityLabel:)]) {
        id qualityController = [self videoQualityController];
        id selectedConstraint = [constraint initWithVideoQualitySetting:3 formatSelectionReason:2 qualityLabel:selectedLabel];
        [self videoQualitySwitchController:qualityController didSelectFormatConstraint:selectedConstraint forSelectableVideoFormats:formats];
    }
}

- (BOOL)shouldEnablePlayerBar { return ytpBool(@"shortsProgress"); }
- (BOOL)shouldAlwaysEnablePlayerBar { return ytpBool(@"shortsProgress"); }
- (BOOL)shouldEnablePlayerBarOnlyOnPause { return !ytpBool(@"shortsProgress"); }
%end

%hook YTReelPlayerViewControllerSub
- (BOOL)shouldEnablePlayerBar { return ytpBool(@"shortsProgress"); }
- (BOOL)shouldAlwaysEnablePlayerBar { return ytpBool(@"shortsProgress"); }
- (BOOL)shouldEnablePlayerBarOnlyOnPause { return !ytpBool(@"shortsProgress"); }
%end

%hook YTShortsPlayerViewController
- (BOOL)shouldAlwaysEnablePlayerBar { return ytpBool(@"shortsProgress"); }
- (BOOL)shouldEnablePlayerBarOnlyOnPause { return !ytpBool(@"shortsProgress"); }
%end
%end

void YTLInstallShortsPlaybackHooks(void) {
    %init(YTLShortsPlayback);
}
