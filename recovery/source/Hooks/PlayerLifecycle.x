#import "PlayerLifecycleHost.h"
#import "PlayerLifecycleHelpers.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../SleepTimer/YTPSleepTimer.h"
#import "../Controls/YTPSpeedMaster.h"
#import "../Helpers/YTLHelper.h"
#import "../Support/YTPDB.h"
#import "../Controls/PlaybackPreferences.h"
#import "../../../Utils/YTLUserDefaults.h"
#include <stdint.h>
#include <string.h>

static BOOL PlayerLifecycleIsWatch(YTPlayerViewController *player) {
    return [player.parentViewController isKindOfClass:NSClassFromString(@"YTWatchViewController")];
}

%group YTLPlayerLifecycle
%hook YTPlayerViewController
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {
    [[YTPSleepTimer sharedTimer] cancelIfPlayerClosed];
    canRememberLoopMode = NO;
    %orig;
    if (ytpInt(@"wiFiQualityIndex") || ytpInt(@"cellQualityIndex")) [self performSelector:@selector(autoQuality) withObject:nil afterDelay:0.75];
    if (ytpBool(@"autoFullscreen")) [self performSelector:@selector(autoFullscreen) withObject:nil afterDelay:0.75];
    if (ytpInt(@"autoSpeedIndex") != 3 || ytpBool(@"rememberPlaybackSpeed")) [self performSelector:@selector(setAutoSpeed) withObject:nil afterDelay:0.75];
    if (ytpInt(@"captionsIndex")) [self performSelector:@selector(selectCaptions) withObject:nil afterDelay:0.75];
    if (ytpInt(@"audioTrackIndex")) [self performSelector:@selector(selectAudioTrack) withObject:nil afterDelay:0.75];
    if (ytpBool(@"rememberLoop")) [self performSelector:@selector(restoreLoopMode) withObject:nil afterDelay:3];
}
%new
- (void)restoreLoopMode {
    if ([self.activeVideoPlayerOverlay isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")]) {
        id<YTLPlayerLoopOverlay> overlay = self.activeVideoPlayerOverlay;
        if ([overlay respondsToSelector:@selector(loopMode)]) [overlay setLoopMode:ytpInt(@"loopMode")];
    }
    if ([self.activeVideo.delegate isKindOfClass:NSClassFromString(@"YTLocalPlaybackController")]) {
        id<YTLPlayerLocalPlayback> controller = self.activeVideo.delegate;
        if ([controller respondsToSelector:@selector(loopingEnabled)] && ytpInt(@"loopMode")) [controller setLoopingEnabled:YES];
    }
    canRememberLoopMode = YES;
}
%new
- (void)autoFullscreen { [(id<YTLPlayerFullscreenDelegate>)[self valueForKey:@"_UIDelegate"] showFullScreen]; }
%new
- (void)setAutoSpeed {
    if (!PlayerLifecycleIsWatch(self)) return;
    double rate = YTLPreferredPlaybackRate([YTLUserDefaults standardUserDefaults], ytpInt(@"autoSpeedIndex"));
    [YTPSpeedMaster setPlaybackRate:rate forPlayer:self];
}
%new
- (void)selectCaptions {
    if (!PlayerLifecycleIsWatch(self) || !self.activeVideo || self.isMDXActive) return;
    if (!self.activeVideo.availableCaptionTracks) {
        [self performSelector:@selector(selectCaptions) withObject:nil afterDelay:1];
        return;
    }
    if (ytpInt(@"captionsIndex") == 1) {
        if ([self.activeVideo respondsToSelector:@selector(setActiveCaptionTrack:source:)]) [self.activeVideo setActiveCaptionTrack:nil source:0];
        else if ([self.activeVideo respondsToSelector:@selector(setActiveCaptionTrack:)]) [self.activeVideo setActiveCaptionTrack:nil];
        return;
    }
    NSArray<id<YTLPlayerCaption>> *tracks = self.activeVideo.availableCaptionTracks;
    if (!tracks.count) return;
    id<YTLPlayerCaption> original = nil;
    for (id<YTLPlayerCaption> track in tracks) {
        id<YTLPlayerResponse> response = nil;
        if ([self respondsToSelector:@selector(playerResponse)]) response = self.playerResponse;
        else if ([self respondsToSelector:@selector(contentPlayerResponse)]) response = self.contentPlayerResponse;
        if (!response) return;
        id<YTLPlayerCaptionList> list = response.playerData.captions.playerCaptionsTracklistRenderer;
        if (!list.captionTracksArray.count) continue;
        id<YTLPlayerCaption> first = list.captionTracksArray[0];
        NSString *audioID = list.ml_defaultAudioTrackData.audioTrackId;
        NSString *language = audioID.length ? [audioID stringByReplacingOccurrencesOfString:@".4" withString:@""] : first.languageCode;
        NSString *candidate = [NSString stringWithFormat:@".%@", track.languageCode];
        if ([candidate isEqualToString:language]) { original = track; break; }
        if ([candidate hasSuffix:language] && ytpBool(@"autoGenCaps")) original = track;
    }
    id<YTLPlayerCaption> custom = nil;
    for (id<YTLPlayerCaption> track in tracks) {
        NSString *candidate = [NSString stringWithFormat:@".%@", track.languageCode];
        NSString *language = [NSString stringWithFormat:@".%@", [YTPDB langCodeForIndex:ytpInt(@"customCaption")]];
        if ([candidate isEqualToString:language]) { custom = track; break; }
        if ([candidate hasSuffix:language] && ytpBool(@"autoGenCaps")) custom = track;
    }
    if ([self.activeVideo respondsToSelector:@selector(setActiveCaptionTrack:source:)]) {
        if (ytpInt(@"captionsIndex") == 1) [self.activeVideo setActiveCaptionTrack:nil source:0];
        if (ytpInt(@"captionsIndex") == 2 && original) [self.activeVideo setActiveCaptionTrack:original source:0];
        if (ytpInt(@"captionsIndex") == 3 && custom) [self.activeVideo setActiveCaptionTrack:custom source:0];
    } else if ([self.activeVideo respondsToSelector:@selector(setActiveCaptionTrack:)]) {
        if (ytpInt(@"captionsIndex") == 1) [self.activeVideo setActiveCaptionTrack:nil];
        if (ytpInt(@"captionsIndex") == 2 && original) [self.activeVideo setActiveCaptionTrack:original];
        if (ytpInt(@"captionsIndex") == 3 && custom) [self.activeVideo setActiveCaptionTrack:custom];
    }
}
%new
- (void)autoQuality {
    if (!PlayerLifecycleIsWatch(self) || !self.activeVideo || self.isMDXActive) return;
    if (!self.activeVideo.selectableVideoFormats) {
        [self performSelector:@selector(autoQuality) withObject:nil afterDelay:3];
        return;
    }
    NSInteger index = ytpInt([YTLHelper isConnectedToWiFi] ? @"wiFiQualityIndex" : @"cellQualityIndex");
    NSString *best = nil;
    int highest = 0;
    for (id<YTLPlayerFormat> format in self.activeVideo.selectableVideoFormats) {
        int resolution = format.singleDimensionResolution;
        if (resolution > highest && ![format.qualityLabel containsString:@"Premium"]) { highest = resolution; best = format.qualityLabel; }
    }
    NSArray *labels = @[@"Default", best, @"2160p60", @"2160p", @"1440p60", @"1440p", @"1080p60", @"1080p", @"720p60", @"720p", @"480p", @"360p", @"240p", @"144p"];
    NSString *label = labels[index];
    if (![label isEqualToString:best]) {
        BOOL exact = NO;
        for (id<YTLPlayerFormat> format in self.activeVideo.selectableVideoFormats) {
            if ([format.qualityLabel isEqualToString:label]) { exact = YES; break; }
        }
        if (!exact) {
            NSString *closest = label;
            int64_t bestDifference = INT64_MAX;
            for (id<YTLPlayerFormat> format in self.activeVideo.selectableVideoFormats) {
                if ([format.qualityLabel containsString:@"Premium"]) continue;
                NSArray *parts = [format.qualityLabel componentsSeparatedByString:@"p"];
                NSArray *target = [label componentsSeparatedByString:@"p"];
                if (parts.count == 2) {
                    // ARM SUB/CNEG wrap at 64 bits, including INT64_MIN.
                    uint64_t bits = (uint64_t)[parts.firstObject integerValue] - (uint64_t)[target.firstObject integerValue];
                    int64_t difference;
                    memcpy(&difference, &bits, sizeof difference);
                    if (difference < 0) { bits = 0 - bits; memcpy(&difference, &bits, sizeof difference); }
                    if (difference < bestDifference) { bestDifference = difference; closest = format.qualityLabel; }
                }
            }
            label = closest;
        }
    }
    id<YTLPlayerVideoConstraint> constraint = [NSClassFromString(@"MLQuickMenuVideoQualitySettingFormatConstraint") new];
    if ([constraint respondsToSelector:@selector(initWithVideoQualitySetting:formatSelectionReason:qualityLabel:)]) {
        [self.activeVideo setVideoFormatConstraint:[constraint initWithVideoQualitySetting:3 formatSelectionReason:2 qualityLabel:label]];
    }
}
%new
- (void)selectAudioTrack {
    if (!self.activeVideo || self.isMDXActive) return;
    if (!self.activeVideo.selectableAudioFormats) {
        [self performSelector:@selector(selectAudioTrack) withObject:nil afterDelay:3];
        return;
    }
    if (!self.activeVideo.selectedAudioFormat.audioTrack) return;
    NSArray<id<YTLPlayerFormat>> *formats = self.activeVideo.selectableAudioFormats;
    BOOL drc = self.activeVideo.audioFormatConstraint.DRCEnabled;
    id<YTLPlayerAudioTrack> original = nil;
    for (id<YTLPlayerFormat> format in formats) if ([format.audioTrack.id_p hasSuffix:@".4"]) original = format.audioTrack;
    id<YTLPlayerAudioTrack> custom = nil;
    for (id<YTLPlayerFormat> format in formats) {
        NSString *identifier = format.audioTrack.id_p;
        NSString *language = [YTPDB langCodeForIndex:ytpInt(@"customTrack")];
        if ([identifier containsString:language]) {
            custom = format.audioTrack;
            if ([identifier hasSuffix:@".3"] || [identifier hasSuffix:@".6"]) break;
        }
    }
    id<YTLPlayerAudioConstraint> constraint = [NSClassFromString(@"MLAudioFormatConstraint") new];
    if ([constraint respondsToSelector:@selector(initWithAudioTrack:audioQualityConfig:formatSelectionReason:DRCEnabled:)]) {
        if (ytpInt(@"audioTrackIndex") == 1) {
            [self.activeVideo setAudioFormatConstraint:[constraint initWithAudioTrack:original audioQualityConfig:nil formatSelectionReason:2 DRCEnabled:drc]];
        } else if (ytpInt(@"audioTrackIndex") == 2 && custom) {
            if (![custom.id_p hasSuffix:@".10"] || !ytpBool(@"ignoreAutoDub")) {
                [self.activeVideo setAudioFormatConstraint:[constraint initWithAudioTrack:custom audioQualityConfig:nil formatSelectionReason:2 DRCEnabled:drc]];
            }
        }
    }
    if (ytpInt(@"captionsIndex")) [self selectCaptions];
}
- (void)singleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time {
    %orig;
    addEndTime(self, video, time);
    autoSkipShortsLegacy(self, video, time);
}
- (void)potentiallyMutatedSingleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time {
    %orig;
    addEndTime(self, video, time);
    autoSkipShortsLegacy(self, video, time);
}
- (void)dealloc {
    [[YTPSleepTimer sharedTimer] cancelIfPlayerClosed];
    %orig;
}
%end
%end

void YTLInstallPlayerLifecycleHooks(void) {
    %init(YTLPlayerLifecycle);
}
