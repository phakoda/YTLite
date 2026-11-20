#import "SponsorPlaybackHost.h"
#import "../Playback/SBPlaybackController.h"
#import "../Playback/SBPlayerDecorator.h"
#import "../Runtime/YTLFeaturePolicy.h"

%group YTLSponsorPlayback
%hook YTPlayerViewController
%property(nonatomic, retain) SBPlaybackController *sbPlaybackController;

// Original registrar 0x1efd4. Keep this layer distinct from Discord and the
// primary player hooks; each original IMP must continue down the same chain.
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {
    %orig;
    if ([self isPlayingAd] || !ytpBool(@"sponsorBlock")) return;
    if (!ytpBool(@"sbFeedPlayer") && ![[self parentViewController] isKindOfClass:%c(YTWatchViewController)]) return;
    self.sbPlaybackController = [[SBPlaybackController alloc] initWithPlayer:self];
}
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id)time {
    %orig;
    if (ytpBool(@"sponsorBlock")) {
        [self.sbPlaybackController skipSegmentIfNeeded];
        if (ytpBool(@"sbDuration")) [SBPlayerDecorator addDurationWithoutSegments:self videoController:video];
    }
}
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id)time {
    %orig;
    if (ytpBool(@"sponsorBlock")) {
        [self.sbPlaybackController skipSegmentIfNeeded];
        if (ytpBool(@"sbDurationLabel")) [SBPlayerDecorator addDurationWithoutSegments:self videoController:video];
    }
}
%end
%end

void YTLInstallSponsorPlaybackHooks(void) { %init(YTLSponsorPlayback); }
