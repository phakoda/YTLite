#import "DiscordLifecycleHost.h"
#import "../Discord/YTPDiscordRPC.h"
#import "../Models/RPCMedia.h"
#import "../Downloads/YTPMedia.h"
#import "../../../Utils/YTLUserDefaults.h"

static BOOL DiscordLifecycleAcceptsPlayer(YTPlayerViewController *player) {
    if ([player.parentViewController isKindOfClass:NSClassFromString(@"YTInlineMutedPlaybackWatchViewController")]) return NO;
    return ![player.parentViewController isKindOfClass:NSClassFromString(@"YTShortsPlayerViewController")];
}
static void DiscordLifecycleSeek(YTPlayerViewController *player, double time) {
    if (!DiscordLifecycleAcceptsPlayer(player) || ![YTLUserDefaults boolForKey:@"discordRPC"]) return;
    YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
    presence.media.currentTime = time;
    [presence updateTime];
}

%group YTLDiscordLifecycle
%hook YTPlayerViewController
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {
    %orig;
    if (!DiscordLifecycleAcceptsPlayer(self)) return;
    YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
    presence.media = [RPCMedia mediaWithPlayer:self];
    presence.media.isPaused = NO;
    [presence startIfPossible];
}
- (void)seekToTime:(double)time {
    %orig;
    DiscordLifecycleSeek(self, time);
}
- (void)seekToTime:(double)time seekSource:(YTLDiscordForwardedInteger)source {
    %orig;
    DiscordLifecycleSeek(self, time);
}
- (void)seekToTime:(double)time toleranceBefore:(double)before toleranceAfter:(double)after seekSource:(YTLDiscordForwardedInteger)source {
    %orig;
    DiscordLifecycleSeek(self, time);
}
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time {
    %orig;
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) {
        YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
        double currentTime = time.time;
        presence.media.currentTime = currentTime;
    }
}
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time {
    %orig;
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) {
        YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
        double currentTime = time.time;
        presence.media.currentTime = currentTime;
    }
}
%end

%hook YTWatchPlaybackController
- (void)playbackControllerDidPlay {
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) {
        YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
        presence.media.isPaused = NO;
        [presence updateState];
    }
    %orig;
}
- (void)playbackControllerDidPause {
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) {
        YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
        presence.media.isPaused = YES;
        [presence updateState];
    }
    %orig;
}
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLDiscordForwardedInteger)transition {
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) [[YTPDiscordRPC sharedPresence] clearPlayback];
    %orig;
}
- (void)clearPlaybackController {
    if ([YTLUserDefaults boolForKey:@"discordRPC"]) [[YTPDiscordRPC sharedPresence] clearPlayback];
    %orig;
}
%end

%hook YTMainAppControlsOverlayView
%new
- (void)handleYTLDiscordTap:(UIButton *)sender {
    BOOL enabled = [YTLUserDefaults boolForKey:@"discordRPC"];
    [YTLUserDefaults setBool:!enabled forKey:@"discordRPC"];
    YTPDiscordRPC *presence = [YTPDiscordRPC sharedPresence];
    if (enabled) {
        [presence clearPlayback];
    } else {
        UIViewController *player = [self _viewControllerForAncestor].parentViewController;
        presence.media = [RPCMedia mediaWithPlayer:player];
        [presence startIfPossible];
    }
    [sender setImage:[YTPMedia adaptiveDiscord] forState:UIControlStateNormal];
}
%end
%end

void YTLInstallDiscordLifecycleHooks(void) {
    %init(YTLDiscordLifecycle);
}
