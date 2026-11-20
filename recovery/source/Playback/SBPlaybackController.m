#import "SBPlaybackController.h"
#import "SBManager.h"
#import "PlaybackHost.h"
#import "../Models/SBSegment.h"
#import <dispatch/dispatch.h>
#import <math.h>

static Class<YTLPlaybackPreferences> YTLSponsorPreferences(void) {
    return (Class<YTLPlaybackPreferences>)NSClassFromString(@"YTLUserDefaults");
}

@implementation SBPlaybackController

// 0x194914. Player ownership is weak, unlike the retained video ID and UUID set.
- (instancetype)initWithPlayer:(YTPlayerViewController *)player {
    self = [super init];
    if (self) {
        _player = player;
        _skippedUUIDs = [NSMutableSet set];
        [self requestSbSegments];
    }
    return self;
}

// 0x194a04, delayed block 0x194bdc. A missing ID is retried after three seconds;
// an empty but nonnil ID takes the immediate request path, as in the package.
- (void)requestSbSegments {
    if ([(id<YTLSponsorPlayer>)_player contentVideoID]) {
        _videoID = [(id<YTLSponsorPlayer>)_player contentVideoID];
        [[SBManager sharedManager] getSegmentsForID:[(id<YTLSponsorPlayer>)_player contentVideoID]];
    } else {
        __weak SBPlaybackController *weakSelf = self;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3000000000), dispatch_get_main_queue(), ^{
            [weakSelf requestSbSegments];
        });
    }
}

// 0x194c24. The response checks and whitelist return were verified against
// 0x1954b4..0x1956f4; a missing response allows playback, not a failed check.
- (BOOL)shouldCheckSponsorBlock {
    if (![YTLSponsorPreferences() boolForKey:@"sbFeedPlayer"] &&
        ![[(id<YTLSponsorPlayer>)_player parentViewController]
            isKindOfClass:NSClassFromString(@"YTWatchViewController")]) {
        if (![YTLSponsorPreferences() boolForKey:@"sbMiniPlayer"] &&
            ![[(id<YTLSponsorPlayer>)_player parentViewController]
                isKindOfClass:NSClassFromString(@"YTWatchMiniBarViewController")]) {
            return NO;
        }
    }
    if (![(id<YTLSponsorPlayer>)_player contentVideoID] ||
        [(id<YTLSponsorPlayer>)_player currentVideoMediaTime] == 0.0) return NO;

    id<YTLPlaybackResponse> response;
    if ([(id)_player respondsToSelector:@selector(playerResponse)]) {
        response = [(id<YTLSponsorPlayer>)_player playerResponse];
    } else if ([(id)_player respondsToSelector:@selector(contentPlayerResponse)]) {
        response = [(id<YTLSponsorPlayer>)_player contentPlayerResponse];
    } else {
        return YES;
    }
    if (!response) return YES;
    NSString *channel = [[[response playerData] videoDetails] channelId];
    NSDictionary *whitelist = [[YTLSponsorPreferences() standardUserDefaults] objectForKey:@"sbWhitelist"];
    // Presence, not the stored object's boolValue, determines whitelisting.
    return whitelist[channel] == nil;
}

// 0x1956f8. Both ordinary segment bounds are inclusive, but the upper bound is
// end - 1 second. Highlights are offered before (or exactly at) their start.
// The original reads the player's time separately for each ordinary bound.
- (void)skipSegmentIfNeeded {
    if (![self shouldCheckSponsorBlock]) return;
    NSArray<NSString *> *categories = @[@"sponsor", @"intro", @"outro", @"interaction",
                                       @"selfpromo", @"music_offtopic", @"preview", @"filler"];
    NSArray<SBSegment *> *segments = [[SBManager sharedManager].segments objectForKey:_videoID];
    for (SBSegment *segment in segments) {
        if ([_skippedUUIDs containsObject:segment.uuid]) continue;
        if ([segment.category isEqualToString:@"poi_highlight"]) {
            if ([(id<YTLSponsorPlayer>)_player currentVideoMediaTime] <= segment.start) {
                [self handleHighlightSegment:segment];
            }
        } else if ([categories containsObject:segment.category] &&
                   [(id<YTLSponsorPlayer>)_player currentVideoMediaTime] >= segment.start &&
                   [(id<YTLSponsorPlayer>)_player currentVideoMediaTime] <= segment.end - 1.0 &&
                   [self segmentMeetsMinimumDuration:segment]) {
            [self handleSkipSegment:segment];
        }
    }
}

// 0x1964b8. The class accessor returns double, despite its floatForKey: selector.
- (BOOL)segmentMeetsMinimumDuration:(SBSegment *)segment {
    double minimum = [YTLSponsorPreferences() floatForKey:@"sbSkipDuration"];
    if (minimum > 0.0 && ![segment.category isEqualToString:@"poi_highlight"]) {
        return segment.end - segment.start >= minimum;
    }
    return YES;
}

// 0x196834. An automatic skip undoes to segment.start, not the measured time.
// Every invocation records the UUID even when the selected behavior is disabled.
- (void)handleSkipSegment:(SBSegment *)segment {
    [_skippedUUIDs addObject:segment.uuid];
    NSInteger mode = [YTLSponsorPreferences() integerForKey:
                       [NSString stringWithFormat:@"sb_%@", segment.category]];
    double current = [(id<YTLSponsorPlayer>)_player currentVideoMediaTime];
    if (mode == 1) {
        [self seekToTime:segment.end forSegment:segment undoTime:segment.start attempts:1];
    } else if (mode == 2) {
        [self showSkipPromptToast:segment timeBeforeSkip:current target:segment.end];
    }
}

// 0x196b54. Highlight undo uses the measured time, unlike ordinary auto-skips.
- (void)handleHighlightSegment:(SBSegment *)segment {
    [_skippedUUIDs addObject:segment.uuid];
    NSInteger mode = [YTLSponsorPreferences() integerForKey:
                       [NSString stringWithFormat:@"sb_%@", segment.category]];
    double current = [(id<YTLSponsorPlayer>)_player currentVideoMediaTime];
    if (mode == 1) {
        [self seekToTime:segment.start forSegment:segment undoTime:current attempts:1];
    } else if (mode == 2) {
        [self showSkipPromptToast:segment timeBeforeSkip:current target:segment.start];
    }
}

// 0x196e7c, block 0x197000. The original block contains BOTH a weak reference
// and a strong capture of self; retaining self through the delayed check is
// intentional here. The remaining-attempt count is decremented on failure.
- (void)seekToTime:(double)time forSegment:(SBSegment *)segment
         undoTime:(double)undoTime attempts:(int)attempts {
    if (attempts <= 0) return;
    [(id<YTLSponsorPlayer>)_player seekToTime:time];
    __weak SBPlaybackController *weakSelf = self;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 300000000), dispatch_get_main_queue(), ^{
        SBPlaybackController *controller = weakSelf;
        if (!controller || !self->_player) return;
        BOOL highlight = [segment.category isEqualToString:@"poi_highlight"];
        double current = [(id<YTLSponsorPlayer>)self->_player currentVideoMediaTime];
        BOOL failed = highlight ? !(fabs(current - time) <= 1.0) : !(current >= time - 1.0);
        if (failed) {
            [controller seekToTime:time forSegment:segment undoTime:undoTime attempts:attempts - 1];
        } else {
            [controller playSkipAudioIfNeeded];
            [controller showSkippedToast:segment undoTime:undoTime];
        }
    });
}

// 0x197448, action block 0x197b84. Undo directly seeks and does not remove the
// UUID from the handled set, so an undone segment is not immediately skipped.
- (void)showSkippedToast:(SBSegment *)segment undoTime:(double)undoTime {
    if (![YTLSponsorPreferences() boolForKey:@"sbNotifications"]) return;
    NSString *key = [NSString stringWithFormat:@"sb_%@", segment.category];
    double duration = [YTLSponsorPreferences() floatForKey:@"sbSkippedDuration"];
    id<YTLPlaybackToast> toast = (id)[NSClassFromString(@"ToastView") new];
    NSString *text = [NSString stringWithFormat:[@"SegmentSkipped" ytl_localized], [key ytl_localized]];
    [toast showProgressiveToastWithText:text duration:duration
        actionIcon:[[NSBundle ytl_defaultBundle] imageWithName:@"backward.circle"]
        actionCompletion:^{ [(id<YTLSponsorPlayer>)self->_player seekToTime:undoTime]; }];
}

// 0x197be0, action block 0x1985c4. Prompts are also suppressed by sbNotifications.
- (void)showSkipPromptToast:(SBSegment *)segment timeBeforeSkip:(double)time target:(double)target {
    if (![YTLSponsorPreferences() boolForKey:@"sbNotifications"]) return;
    NSString *key = [NSString stringWithFormat:@"sb_%@", segment.category];
    double duration = [YTLSponsorPreferences() floatForKey:@"sbDuration"];
    NSString *action = [segment.category isEqualToString:@"poi_highlight"] ? @"SkipToSegment" : @"SkipSegment";
    id<YTLPlaybackToast> toast = (id)[NSClassFromString(@"ToastView") new];
    NSString *text = [NSString stringWithFormat:[@"SegmentDetected" ytl_localized],
                       [key ytl_localized], [action ytl_localized]];
    [toast showProgressiveToastWithText:text duration:duration
        actionIcon:[[NSBundle ytl_defaultBundle] imageWithName:@"forward.circle"]
        actionCompletion:^{ [self seekToTime:target forSegment:segment undoTime:time attempts:1]; }];
}

// 0x198608.
- (void)playSkipAudioIfNeeded {
    if ([YTLSponsorPreferences() boolForKey:@"sbAudio"]) {
        Class<YTLPlaybackAudio> audioClass = (Class<YTLPlaybackAudio>)NSClassFromString(@"AudioManager");
        [[audioClass sharedInstance] playAudio];
    }
}

// 0x1987ac. ARC supplies the superclass deallocation and weak/strong destruction.
- (void)dealloc {
    [NSObject cancelPreviousPerformRequestsWithTarget:self];
}

@end
