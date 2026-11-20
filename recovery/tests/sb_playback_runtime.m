#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>
#import <math.h>
#import "../source/Playback/SBPlaybackController.h"
#import "../source/Playback/SBManager.h"
#import "../source/Playback/PlaybackHost.h"
#import "../source/Models/SBSegment.h"

static NSUInteger assertions;
#define CHECK(expression) do { \
    assertions++; \
    if (!(expression)) { \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #expression); \
        abort(); \
    } \
} while (0)

extern NSUInteger YTLPlaybackHTTPTaskCount(void);
static NSMutableDictionary *preferences;
static NSMutableArray<NSDictionary *> *toasts;
static NSUInteger audioPlays;

NSMutableDictionary *YTLPlaybackPreferencesFixture(void) { return preferences; }

@interface FixturePlaybackPreferencesStore : NSObject
- (id)objectForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
@end
@implementation FixturePlaybackPreferencesStore
- (id)objectForKey:(NSString *)key { return preferences[key]; }
- (BOOL)boolForKey:(NSString *)key { return [preferences[key] boolValue]; }
- (NSInteger)integerForKey:(NSString *)key { return [preferences[key] integerValue]; }
@end

@interface YTLUserDefaults : NSObject
+ (BOOL)boolForKey:(NSString *)key;
+ (NSInteger)integerForKey:(NSString *)key;
+ (double)floatForKey:(NSString *)key;
+ (id)standardUserDefaults;
@end
@implementation YTLUserDefaults
+ (BOOL)boolForKey:(NSString *)key { return [preferences[key] boolValue]; }
+ (NSInteger)integerForKey:(NSString *)key { return [preferences[key] integerValue]; }
+ (double)floatForKey:(NSString *)key { return [preferences[key] doubleValue]; }
+ (id)standardUserDefaults {
    static FixturePlaybackPreferencesStore *store;
    if (!store) store = [FixturePlaybackPreferencesStore new];
    return store;
}
@end

@implementation NSString (YTLPlaybackLocalization)
- (NSString *)ytl_localized {
    NSDictionary *strings = @{@"SegmentSkipped": @"Skipped %@", @"SegmentDetected": @"Detected %@ (%@)",
        @"SkipSegment": @"skip", @"SkipToSegment": @"jump", @"sb_sponsor": @"Sponsor",
        @"sb_poi_highlight": @"Highlight"};
    return strings[self] ?: self;
}
@end
@implementation NSBundle (YTLPlaybackResources)
+ (NSBundle *)ytl_defaultBundle { return [NSBundle mainBundle]; }
- (id)imageWithName:(NSString *)name { return name; }
@end

@interface ToastView : NSObject <YTLPlaybackToast> @end
@implementation ToastView
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(id)icon actionCompletion:(void (^)(void))completion {
    [toasts addObject:@{@"text": text, @"duration": @(duration), @"icon": icon, @"action": [completion copy]}];
}
@end
@interface AudioManager : NSObject <YTLPlaybackAudio> @end
@implementation AudioManager
+ (instancetype)sharedInstance {
    static AudioManager *instance;
    if (!instance) instance = [self new];
    return instance;
}
- (void)playAudio { audioPlays++; }
@end

@interface FixtureScheduledPlayback : NSObject
@property(nonatomic) dispatch_time_t when;
@property(nonatomic, copy) dispatch_block_t block;
@end
@implementation FixtureScheduledPlayback @end
static NSMutableArray<FixtureScheduledPlayback *> *scheduled;

// Only the host-test compile aliases dispatch_after to this function. The iOS
// objects retain the real libdispatch call and exact recovered delay constants.
void YTLPlaybackTestDispatchAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block) {
    CHECK(queue == dispatch_get_main_queue());
    FixtureScheduledPlayback *task = [FixtureScheduledPlayback new];
    task.when = when;
    task.block = block;
    [scheduled addObject:task];
}
static void runFirstScheduled(void) {
    CHECK(scheduled.count > 0);
    FixtureScheduledPlayback *task = scheduled[0];
    [scheduled removeObjectAtIndex:0];
    task.block();
}

@interface YTWatchViewController : NSObject
@property(nonatomic) BOOL fullscreen;
@property(nonatomic) BOOL fullscreenResult;
- (BOOL)isFullscreen;
@end
@implementation YTWatchViewController
- (BOOL)isFullscreen { return self.fullscreenResult; }
@end
@interface YTWatchMiniBarViewController : NSObject @end
@implementation YTWatchMiniBarViewController @end
@interface YTPlayerViewController : NSObject
@property(nonatomic, strong) NSString *contentVideoID;
@property(nonatomic, strong) id parentViewController;
@property(nonatomic) double currentVideoMediaTime;
@property(nonatomic) double currentVideoTotalMediaTime;
@property(nonatomic, strong) id view;
@property(nonatomic) BOOL applySeek;
@property(nonatomic, strong) NSMutableArray<NSNumber *> *seekTimes;
- (void)seekToTime:(double)time;
@end
@implementation YTPlayerViewController
- (instancetype)init {
    self = [super init];
    if (self) {
        _contentVideoID = @"playback-video";
        _parentViewController = [YTWatchViewController new];
        _currentVideoMediaTime = 1;
        _seekTimes = [NSMutableArray array];
    }
    return self;
}
- (void)seekToTime:(double)time {
    [self.seekTimes addObject:@(time)];
    if (self.applySeek) self.currentVideoMediaTime = time;
}
@end
@interface FixtureSBVideoDetails : NSObject
@property(nonatomic, strong) NSString *channelId;
@end
@implementation FixtureSBVideoDetails @end
@interface FixtureSBPlayerData : NSObject
@property(nonatomic, strong) FixtureSBVideoDetails *videoDetails;
@end
@implementation FixtureSBPlayerData @end
@interface FixtureSBResponse : NSObject
@property(nonatomic, strong) FixtureSBPlayerData *playerData;
@end
@implementation FixtureSBResponse @end
@interface FixtureSBFallbackPlayer : YTPlayerViewController
@property(nonatomic, strong) FixtureSBResponse *response;
@property(nonatomic) NSUInteger fallbackCalls;
- (FixtureSBResponse *)contentPlayerResponse;
@end
@implementation FixtureSBFallbackPlayer
- (FixtureSBResponse *)contentPlayerResponse { self.fallbackCalls++; return self.response; }
@end
@interface FixtureSBPrimaryPlayer : FixtureSBFallbackPlayer
@property(nonatomic, strong) FixtureSBResponse *primaryResponse;
- (FixtureSBResponse *)playerResponse;
@end
@implementation FixtureSBPrimaryPlayer
- (FixtureSBResponse *)playerResponse { return self.primaryResponse; }
@end

@interface FixtureSBBoundsController : SBPlaybackController
@property(nonatomic) BOOL allowed;
@property(nonatomic, strong) NSMutableArray<SBSegment *> *skips;
@property(nonatomic, strong) NSMutableArray<SBSegment *> *highlights;
@end
@implementation FixtureSBBoundsController
- (BOOL)shouldCheckSponsorBlock { return self.allowed; }
- (void)handleSkipSegment:(SBSegment *)segment { [self.skips addObject:segment]; }
- (void)handleHighlightSegment:(SBSegment *)segment { [self.highlights addObject:segment]; }
@end
@interface FixtureSBDecisionController : SBPlaybackController
@property(nonatomic, strong) NSMutableArray<NSDictionary *> *decisions;
@end
@implementation FixtureSBDecisionController
- (void)seekToTime:(double)time forSegment:(SBSegment *)segment undoTime:(double)undoTime attempts:(int)attempts {
    [self.decisions addObject:@{@"kind": @"seek", @"time": @(time), @"segment": segment,
                                @"undo": @(undoTime), @"attempts": @(attempts)}];
}
- (void)showSkipPromptToast:(SBSegment *)segment timeBeforeSkip:(double)time target:(double)target {
    [self.decisions addObject:@{@"kind": @"prompt", @"time": @(target), @"segment": segment, @"undo": @(time)}];
}
@end
@interface FixtureSBSeekController : SBPlaybackController
@property(nonatomic) NSUInteger successAudio;
@property(nonatomic) NSUInteger successToasts;
@property(nonatomic) double lastUndo;
@end
@implementation FixtureSBSeekController
- (void)playSkipAudioIfNeeded { self.successAudio++; }
- (void)showSkippedToast:(SBSegment *)segment undoTime:(double)undoTime {
    (void)segment;
    self.successToasts++; self.lastUndo = undoTime;
}
@end

static SBSegment *segment(NSString *category, double start, double end) {
    SBSegment *value = [SBSegment new];
    value.uuid = NSUUID.UUID.UUIDString;
    value.category = category;
    value.start = start;
    value.end = end;
    return value;
}
static FixtureSBResponse *responseForChannel(NSString *channel) {
    FixtureSBResponse *response = [FixtureSBResponse new];
    response.playerData = [FixtureSBPlayerData new];
    response.playerData.videoDetails = [FixtureSBVideoDetails new];
    response.playerData.videoDetails.channelId = channel;
    return response;
}

static void testRequestAndWeakOwnership(void) {
    NSUInteger before = YTLPlaybackHTTPTaskCount();
    YTPlayerViewController *player = [YTPlayerViewController new];
    NSMutableString *identifier = [@"retained-video" mutableCopy];
    player.contentVideoID = identifier;
    SBPlaybackController *controller = [[SBPlaybackController alloc] initWithPlayer:player];
    CHECK(YTLPlaybackHTTPTaskCount() == before + 1);
    CHECK([controller valueForKey:@"_videoID"] == identifier);
    CHECK([[controller valueForKey:@"_skippedUUIDs"] count] == 0);
    CHECK(scheduled.count == 0);

    player.contentVideoID = nil;
    controller = [[SBPlaybackController alloc] initWithPlayer:player];
    CHECK(scheduled.count == 1 && [controller valueForKey:@"_videoID"] == nil);
    player.contentVideoID = @"retry-video";
    runFirstScheduled();
    CHECK(scheduled.count == 0 && [[controller valueForKey:@"_videoID"] isEqual:@"retry-video"]);
    CHECK(YTLPlaybackHTTPTaskCount() == before + 2);

    __weak YTPlayerViewController *weakPlayer;
    @autoreleasepool {
        YTPlayerViewController *temporary = [YTPlayerViewController new];
        weakPlayer = temporary;
        controller = [[SBPlaybackController alloc] initWithPlayer:temporary];
    }
    CHECK(weakPlayer == nil && [controller valueForKey:@"_player"] == nil);
    CHECK(![controller shouldCheckSponsorBlock]);

    __weak SBPlaybackController *weakController;
    @autoreleasepool {
        SBPlaybackController *temporary = [[SBPlaybackController alloc] initWithPlayer:nil];
        weakController = temporary;
        CHECK(scheduled.count == 1);
    }
    CHECK(weakController == nil);
    runFirstScheduled();
    CHECK(scheduled.count == 0);
}

static void testEligibility(void) {
    YTPlayerViewController *player = [YTPlayerViewController new];
    SBPlaybackController *controller = [[SBPlaybackController alloc] initWithPlayer:player];
    CHECK([controller shouldCheckSponsorBlock]);
    player.parentViewController = [NSObject new];
    CHECK(![controller shouldCheckSponsorBlock]);
    preferences[@"sbFeedPlayer"] = @YES;
    CHECK([controller shouldCheckSponsorBlock]);
    preferences[@"sbFeedPlayer"] = @NO;
    preferences[@"sbMiniPlayer"] = @YES;
    CHECK([controller shouldCheckSponsorBlock]);
    preferences[@"sbMiniPlayer"] = @NO;
    player.parentViewController = [YTWatchMiniBarViewController new];
    CHECK([controller shouldCheckSponsorBlock]);
    player.currentVideoMediaTime = 0;
    CHECK(![controller shouldCheckSponsorBlock]);
    player.currentVideoMediaTime = -0.0;
    CHECK(![controller shouldCheckSponsorBlock]);
    player.currentVideoMediaTime = -1;
    CHECK([controller shouldCheckSponsorBlock]);
    player.contentVideoID = nil;
    CHECK(![controller shouldCheckSponsorBlock]);
    player.contentVideoID = @"";
    CHECK([controller shouldCheckSponsorBlock]);

    FixtureSBFallbackPlayer *fallback = [FixtureSBFallbackPlayer new];
    fallback.response = responseForChannel(@"channel");
    controller = [[SBPlaybackController alloc] initWithPlayer:fallback];
    CHECK([controller shouldCheckSponsorBlock] && fallback.fallbackCalls == 1);
    preferences[@"sbWhitelist"] = @{@"channel": @NO};
    CHECK(![controller shouldCheckSponsorBlock]);
    preferences[@"sbWhitelist"] = @{@"other": @YES};
    CHECK([controller shouldCheckSponsorBlock]);
    fallback.response = nil;
    CHECK([controller shouldCheckSponsorBlock]);

    FixtureSBPrimaryPlayer *primary = [FixtureSBPrimaryPlayer new];
    primary.response = responseForChannel(@"channel");
    preferences[@"sbWhitelist"] = @{@"channel": @YES};
    controller = [[SBPlaybackController alloc] initWithPlayer:primary];
    CHECK([controller shouldCheckSponsorBlock] && primary.fallbackCalls == 0);
    primary.primaryResponse = primary.response;
    CHECK(![controller shouldCheckSponsorBlock] && primary.fallbackCalls == 0);
    [preferences removeAllObjects];
}

static void testBoundsAndMinimums(void) {
    YTPlayerViewController *player = [YTPlayerViewController new];
    FixtureSBBoundsController *controller = [[FixtureSBBoundsController alloc] initWithPlayer:player];
    controller.allowed = YES;
    controller.skips = [NSMutableArray array]; controller.highlights = [NSMutableArray array];
    SBSegment *ordinary = segment(@"sponsor", 10, 20);
    [SBManager sharedManager].segments[player.contentVideoID] = [NSMutableArray arrayWithObject:ordinary];
    NSArray *times = @[@9.999, @10, @19, @19.001, @(NAN)];
    NSArray *expected = @[@0, @1, @1, @0, @0];
    for (NSUInteger index = 0; index < times.count; index++) {
        [controller.skips removeAllObjects];
        player.currentVideoMediaTime = [times[index] doubleValue];
        [controller skipSegmentIfNeeded];
        CHECK(controller.skips.count == [expected[index] unsignedIntegerValue]);
    }
    player.currentVideoMediaTime = 10;
    for (NSString *category in @[@"sponsor", @"intro", @"outro", @"interaction", @"selfpromo", @"music_offtopic", @"preview", @"filler"]) {
        ordinary.category = category;
        [controller.skips removeAllObjects];
        [controller skipSegmentIfNeeded];
        CHECK(controller.skips.count == 1);
    }
    ordinary.category = @"unknown";
    [controller.skips removeAllObjects]; [controller skipSegmentIfNeeded];
    CHECK(controller.skips.count == 0);
    ordinary.category = @"sponsor";
    preferences[@"sbSkipDuration"] = @10;
    CHECK([controller segmentMeetsMinimumDuration:ordinary]);
    preferences[@"sbSkipDuration"] = @10.001;
    CHECK(![controller segmentMeetsMinimumDuration:ordinary]);
    [controller skipSegmentIfNeeded];
    CHECK(controller.skips.count == 0);
    preferences[@"sbSkipDuration"] = @0;
    [[controller valueForKey:@"_skippedUUIDs"] addObject:ordinary.uuid];
    [controller skipSegmentIfNeeded];
    CHECK(controller.skips.count == 0);

    SBSegment *highlight = segment(@"poi_highlight", 10, 10);
    [SBManager sharedManager].segments[player.contentVideoID] = [NSMutableArray arrayWithObject:highlight];
    preferences[@"sbSkipDuration"] = @9999;
    CHECK([controller segmentMeetsMinimumDuration:highlight]);
    NSArray *highlightTimes = @[@1, @10, @10.001, @(NAN)];
    NSArray *highlightExpected = @[@1, @1, @0, @0];
    for (NSUInteger index = 0; index < highlightTimes.count; index++) {
        [controller.highlights removeAllObjects];
        player.currentVideoMediaTime = [highlightTimes[index] doubleValue];
        [controller skipSegmentIfNeeded];
        CHECK(controller.highlights.count == [highlightExpected[index] unsignedIntegerValue]);
    }
    controller.allowed = NO;
    player.currentVideoMediaTime = 1;
    [controller.highlights removeAllObjects]; [controller skipSegmentIfNeeded];
    CHECK(controller.highlights.count == 0);
    [preferences removeAllObjects];
}

static void testModesAndUndoTimes(void) {
    YTPlayerViewController *player = [YTPlayerViewController new];
    player.currentVideoMediaTime = 12.5;
    FixtureSBDecisionController *controller = [[FixtureSBDecisionController alloc] initWithPlayer:player];
    controller.decisions = [NSMutableArray array];
    SBSegment *ordinary = segment(@"sponsor", 10, 20);
    [controller handleSkipSegment:ordinary];
    CHECK(controller.decisions.count == 0 && [[controller valueForKey:@"_skippedUUIDs"] containsObject:ordinary.uuid]);
    preferences[@"sb_sponsor"] = @1;
    [controller handleSkipSegment:ordinary];
    NSDictionary *decision = controller.decisions.lastObject;
    CHECK([decision[@"kind"] isEqual:@"seek"] && [decision[@"time"] doubleValue] == 20);
    CHECK([decision[@"undo"] doubleValue] == 10 && [decision[@"attempts"] intValue] == 1);
    preferences[@"sb_sponsor"] = @2;
    [controller handleSkipSegment:ordinary];
    decision = controller.decisions.lastObject;
    CHECK([decision[@"kind"] isEqual:@"prompt"] && [decision[@"time"] doubleValue] == 20);
    CHECK([decision[@"undo"] doubleValue] == 12.5);
    NSUInteger before = controller.decisions.count;
    preferences[@"sb_sponsor"] = @3; [controller handleSkipSegment:ordinary];
    preferences[@"sb_sponsor"] = @-1; [controller handleSkipSegment:ordinary];
    CHECK(controller.decisions.count == before);

    SBSegment *highlight = segment(@"poi_highlight", 30, 30);
    preferences[@"sb_poi_highlight"] = @1;
    [controller handleHighlightSegment:highlight];
    decision = controller.decisions.lastObject;
    CHECK([decision[@"kind"] isEqual:@"seek"] && [decision[@"time"] doubleValue] == 30);
    CHECK([decision[@"undo"] doubleValue] == 12.5 && [decision[@"attempts"] intValue] == 1);
    preferences[@"sb_poi_highlight"] = @2;
    [controller handleHighlightSegment:highlight];
    decision = controller.decisions.lastObject;
    CHECK([decision[@"kind"] isEqual:@"prompt"] && [decision[@"time"] doubleValue] == 30);
    CHECK([decision[@"undo"] doubleValue] == 12.5);
    CHECK([[controller valueForKey:@"_skippedUUIDs"] containsObject:highlight.uuid]);
    [preferences removeAllObjects];
}

static void testSeekVerification(void) {
    YTPlayerViewController *player = [YTPlayerViewController new];
    FixtureSBSeekController *controller = [[FixtureSBSeekController alloc] initWithPlayer:player];
    SBSegment *ordinary = segment(@"sponsor", 2, 10);
    [controller seekToTime:10 forSegment:ordinary undoTime:2 attempts:0];
    CHECK(player.seekTimes.count == 0 && scheduled.count == 0);
    [controller seekToTime:10 forSegment:ordinary undoTime:2 attempts:2];
    CHECK(player.seekTimes.count == 1 && scheduled.count == 1);
    runFirstScheduled();
    CHECK(player.seekTimes.count == 2 && scheduled.count == 1 && controller.successAudio == 0);
    player.currentVideoMediaTime = 9;
    runFirstScheduled();
    CHECK(controller.successAudio == 1 && controller.successToasts == 1 && controller.lastUndo == 2);
    CHECK(scheduled.count == 0);
    player.currentVideoMediaTime = 100;
    [controller seekToTime:10 forSegment:ordinary undoTime:3 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 2 && controller.lastUndo == 3);

    SBSegment *highlight = segment(@"poi_highlight", 10, 10);
    [controller seekToTime:10 forSegment:highlight undoTime:4 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 2 && scheduled.count == 0);
    player.currentVideoMediaTime = 11;
    [controller seekToTime:10 forSegment:highlight undoTime:4 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 3 && controller.lastUndo == 4);
    player.currentVideoMediaTime = 9;
    [controller seekToTime:10 forSegment:highlight undoTime:5 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 4 && controller.lastUndo == 5);
    player.currentVideoMediaTime = NAN;
    [controller seekToTime:10 forSegment:highlight undoTime:6 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 4);
    [controller seekToTime:10 forSegment:ordinary undoTime:7 attempts:1]; runFirstScheduled();
    CHECK(controller.successAudio == 4);

    __weak FixtureSBSeekController *weakController;
    @autoreleasepool {
        FixtureSBSeekController *temporary = [[FixtureSBSeekController alloc] initWithPlayer:player];
        weakController = temporary;
        [temporary seekToTime:10 forSegment:ordinary undoTime:0 attempts:1];
    }
    CHECK(weakController != nil);
    runFirstScheduled();
    CHECK(weakController == nil);
    @autoreleasepool {
        YTPlayerViewController *temporaryPlayer = [YTPlayerViewController new];
        controller = [[FixtureSBSeekController alloc] initWithPlayer:temporaryPlayer];
        [controller seekToTime:10 forSegment:ordinary undoTime:0 attempts:1];
    }
    runFirstScheduled();
    CHECK(controller.successAudio == 0 && controller.successToasts == 0);
}

static void testToastsAndAudio(void) {
    YTPlayerViewController *player = [YTPlayerViewController new];
    SBPlaybackController *controller = [[SBPlaybackController alloc] initWithPlayer:player];
    SBSegment *ordinary = segment(@"sponsor", 2, 10);
    SBSegment *highlight = segment(@"poi_highlight", 20, 20);
    [controller showSkippedToast:ordinary undoTime:2];
    [controller showSkipPromptToast:ordinary timeBeforeSkip:3 target:10];
    CHECK(toasts.count == 0);
    preferences[@"sbNotifications"] = @YES;
    preferences[@"sbSkippedDuration"] = @2.125;
    preferences[@"sbDuration"] = @3.75;
    [[controller valueForKey:@"_skippedUUIDs"] addObject:ordinary.uuid];
    [controller showSkippedToast:ordinary undoTime:2.5];
    NSDictionary *toast = toasts.lastObject;
    CHECK([toast[@"text"] isEqual:@"Skipped Sponsor"] && [toast[@"duration"] doubleValue] == 2.125);
    CHECK([toast[@"icon"] isEqual:@"backward.circle"]);
    ((dispatch_block_t)toast[@"action"])();
    CHECK(player.seekTimes.lastObject.doubleValue == 2.5);
    CHECK([[controller valueForKey:@"_skippedUUIDs"] containsObject:ordinary.uuid]);
    [controller showSkipPromptToast:ordinary timeBeforeSkip:4.5 target:10];
    toast = toasts.lastObject;
    CHECK([toast[@"text"] isEqual:@"Detected Sponsor (skip)"] && [toast[@"duration"] doubleValue] == 3.75);
    CHECK([toast[@"icon"] isEqual:@"forward.circle"]);
    player.applySeek = YES;
    ((dispatch_block_t)toast[@"action"])();
    CHECK(player.seekTimes.lastObject.doubleValue == 10 && scheduled.count == 1);
    runFirstScheduled();
    CHECK([toasts.lastObject[@"text"] isEqual:@"Skipped Sponsor"]);
    ((dispatch_block_t)toasts.lastObject[@"action"])();
    CHECK(player.seekTimes.lastObject.doubleValue == 4.5);
    [controller showSkipPromptToast:highlight timeBeforeSkip:5 target:20];
    CHECK([toasts.lastObject[@"text"] isEqual:@"Detected Highlight (jump)"]);
    [controller playSkipAudioIfNeeded]; CHECK(audioPlays == 0);
    preferences[@"sbAudio"] = @YES;
    [controller playSkipAudioIfNeeded]; CHECK(audioPlays == 1);
    [toasts removeAllObjects];
    [preferences removeAllObjects];
}

NSUInteger testSponsorPlayback(void) {
    preferences = [NSMutableDictionary dictionary];
    toasts = [NSMutableArray array];
    scheduled = [NSMutableArray array];
    testRequestAndWeakOwnership(); testEligibility(); testBoundsAndMinimums();
    testModesAndUndoTimes(); testSeekVerification(); testToastsAndAudio();
    CHECK(scheduled.count == 0);
    printf("SponsorBlock playback tests: %lu assertions passed.\n", (unsigned long)assertions);
    return assertions;
}
