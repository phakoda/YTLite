#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <math.h>
#import "../source/Playback/SBPlayerDecorator.h"
#import "../source/Playback/SBManager.h"
#import "../source/Models/SBSegment.h"
#import "../source/Models/SBPlayerDecorationData.h"

static NSUInteger assertions;
#define CHECK(expression) do { \
    assertions++; \
    if (!(expression)) { \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #expression); \
        abort(); \
    } \
} while (0)

extern NSMutableDictionary *YTLPlaybackPreferencesFixture(void);

// Implementations of these host test classes live in sb_playback_runtime.m.
@interface YTWatchViewController : NSObject
@property(nonatomic) BOOL fullscreen;
@property(nonatomic) BOOL fullscreenResult;
@end
@interface YTPlayerViewController : NSObject
@property(nonatomic, strong) NSString *contentVideoID;
@property(nonatomic, strong) id parentViewController;
@property(nonatomic, strong) id view;
@property(nonatomic) double currentVideoTotalMediaTime;
@end

@interface FixtureDurationBar : UIView
@property(nonatomic, strong) UILabel *durationLabel;
@property(nonatomic, copy) NSString *sbTimeString;
@end
@implementation FixtureDurationBar @end
@interface YTMainAppVideoPlayerOverlayView : UIView
@property(nonatomic, strong) FixtureDurationBar *playerBar;
@end
@implementation YTMainAppVideoPlayerOverlayView @end
@interface FixtureVideoRoot : UIView
@property(nonatomic, strong) id overlayView;
@end
@implementation FixtureVideoRoot @end
@interface YTMainAppVideoPlayerOverlayViewController : NSObject
@property(nonatomic, strong) id parentViewController;
@end
@implementation YTMainAppVideoPlayerOverlayViewController @end
@interface FixtureHiddenFullscreenWatch : YTWatchViewController @end
@implementation FixtureHiddenFullscreenWatch
- (BOOL)respondsToSelector:(SEL)selector {
    return selector == @selector(fullscreen) ? NO : [super respondsToSelector:selector];
}
@end
@interface FixtureRoundedBar : UIView
@property(nonatomic) NSUInteger playedProgressRoundedCorners;
@end
@implementation FixtureRoundedBar @end
@interface FixtureGradientBar : UIView
@property(nonatomic, strong) UIView *brandGradient;
@end
@implementation FixtureGradientBar @end
@interface FixtureChapterBar : UIView
@property(nonatomic, strong) NSArray<UIView *> *segmentViews;
@end
@implementation FixtureChapterBar @end
@interface FixtureInvalidFrameView : UIView
@property(nonatomic) CGRect reportedFrame;
@end
@implementation FixtureInvalidFrameView
- (CGRect)frame { return self.reportedFrame; }
@end

static SBPlayerDecorationData *lastDecoration;
@interface FixtureDecoratorDispatch : SBPlayerDecorator @end
@implementation FixtureDecoratorDispatch
+ (void)_drawSegmentsForData:(SBPlayerDecorationData *)data { lastDecoration = data; }
@end

static SBSegment *makeSegment(NSString *category, double start, double end) {
    SBSegment *segment = [SBSegment new];
    segment.uuid = NSUUID.UUID.UUIDString;
    segment.category = category;
    segment.start = start;
    segment.end = end;
    return segment;
}
static UIView *makeView(CGRect frame) {
    UIView *view = [UIView new];
    view.frame = frame;
    view.window = [NSObject new];
    return view;
}
static void checkRect(CGRect actual, CGRect expected) {
    CHECK(fabs(actual.origin.x - expected.origin.x) < 0.000001);
    CHECK(fabs(actual.origin.y - expected.origin.y) < 0.000001);
    CHECK(fabs(actual.size.width - expected.size.width) < 0.000001);
    CHECK(fabs(actual.size.height - expected.size.height) < 0.000001);
}
static void setSegments(YTPlayerViewController *player, NSArray<SBSegment *> *segments) {
    [SBManager sharedManager].segments[player.contentVideoID] = [segments mutableCopy];
}
static void installColors(void) {
    NSMutableDictionary *preferences = YTLPlaybackPreferencesFixture();
    UIColor *color = [UIColor colorWithRed:0.2 green:0.4 blue:0.6 alpha:0.8];
    NSData *data = [NSKeyedArchiver archivedDataWithRootObject:color requiringSecureCoding:YES error:NULL];
    CHECK(data != nil);
    for (NSString *category in @[@"sponsor", @"intro", @"poi_highlight", @"unknown"]) {
        preferences[[NSString stringWithFormat:@"sb_%@", category]] = @1;
        preferences[[NSString stringWithFormat:@"sb_%@_color", category]] = data;
    }
}

static void testDurationLabel(void) {
    NSMutableDictionary *preferences = YTLPlaybackPreferencesFixture();
    YTPlayerViewController *player = [YTPlayerViewController new];
    player.currentVideoTotalMediaTime = 100;
    FixtureVideoRoot *root = [FixtureVideoRoot new];
    YTMainAppVideoPlayerOverlayView *overlay = [YTMainAppVideoPlayerOverlayView new];
    FixtureDurationBar *bar = [FixtureDurationBar new];
    bar.durationLabel = [UILabel new];
    bar.durationLabel.text = @"01:40";
    overlay.playerBar = bar; root.overlayView = overlay; player.view = root;
    NSArray *segments = @[makeSegment(@"sponsor", 10, 20), makeSegment(@"intro", 15, 30),
        makeSegment(@"unknown", 40, 45), makeSegment(@"poi_highlight", 0, 50), makeSegment(@"outro", 50, 60)];
    setSegments(player, segments);
    preferences[@"sb_sponsor"] = @1; preferences[@"sb_intro"] = @2;
    preferences[@"sb_unknown"] = @-1; preferences[@"sb_poi_highlight"] = @1;
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:[NSObject new]];
    CHECK([bar.sbTimeString isEqual:@"01:10"]);
    CHECK([bar.durationLabel.text isEqual:@"01:40 (01:10)"] && bar.durationLabel.sizeToFitCalls == 1);
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.durationLabel.text isEqual:@"01:40 (01:10)"] && bar.durationLabel.sizeToFitCalls == 1);

    [preferences removeAllObjects];
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK(bar.sbTimeString == nil && [bar.durationLabel.text isEqual:@"01:40 (01:10)"]);
    CHECK(bar.durationLabel.sizeToFitCalls == 1);
    bar.sbTimeString = @"unchanged";
    player.currentVideoTotalMediaTime = 0;
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.sbTimeString isEqual:@"unchanged"]);
    player.currentVideoTotalMediaTime = 100;
    player.parentViewController = [NSObject new];
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.sbTimeString isEqual:@"unchanged"]);
    player.parentViewController = [YTWatchViewController new];
    setSegments(player, nil);
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.sbTimeString isEqual:@"unchanged"]);
    setSegments(player, @[]);
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK(bar.sbTimeString == nil);
    preferences[@"sb_sponsor"] = @2;
    setSegments(player, @[makeSegment(@"sponsor", 0, 100)]);
    player.currentVideoTotalMediaTime = 3700;
    bar.durationLabel.text = @"61:40";
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.sbTimeString isEqual:@"01:00:00"]);
    root.overlayView = [UIView new];
    bar.sbTimeString = @"sentinel";
    [SBPlayerDecorator addDurationWithoutSegments:player videoController:nil];
    CHECK([bar.sbTimeString isEqual:@"sentinel"]);
    [preferences removeAllObjects];
}

static void testAncestorAndFactory(void) {
    NSMutableDictionary *preferences = YTLPlaybackPreferencesFixture();
    YTPlayerViewController *player = [YTPlayerViewController new];
    player.currentVideoTotalMediaTime = 1234.5;
    YTWatchViewController *watch = player.parentViewController;
    watch.fullscreen = NO; watch.fullscreenResult = YES;
    YTMainAppVideoPlayerOverlayViewController *ancestor = [YTMainAppVideoPlayerOverlayViewController new];
    ancestor.parentViewController = player;
    UIView *parent = makeView(CGRectMake(0, 0, 250, 6));
    UIView *bar = makeView(CGRectMake(40, 0, 60, 6));
    bar.superview = parent; bar.recoveredAncestor = ancestor;
    CHECK([SBPlayerDecorator shouldDrawRoundedForBarView:bar]);
    watch.fullscreenResult = NO;
    CHECK(![SBPlayerDecorator shouldDrawRoundedForBarView:bar]);
    FixtureHiddenFullscreenWatch *hidden = [FixtureHiddenFullscreenWatch new];
    hidden.fullscreenResult = YES; player.parentViewController = hidden;
    CHECK(![SBPlayerDecorator shouldDrawRoundedForBarView:bar]);
    player.parentViewController = [NSObject new];
    CHECK(![SBPlayerDecorator shouldDrawRoundedForBarView:bar]);

    NSMutableArray *segments = [NSMutableArray array];
    [SBManager sharedManager].segments[player.contentVideoID] = segments;
    CHECK([SBPlayerDecorator _decorationDataForBarView:bar] == nil);
    preferences[@"sponsorBlock"] = @YES;
    SBPlayerDecorationData *data = [SBPlayerDecorator _decorationDataForBarView:bar];
    CHECK(data != nil && data.barView == bar && data.segments == segments);
    CHECK(data.playerBarWidth == 250 && data.mediaDuration == 1234.5);
    player.currentVideoTotalMediaTime = 0;
    CHECK([SBPlayerDecorator _decorationDataForBarView:bar].mediaDuration == 0);
    lastDecoration = nil;
    [FixtureDecoratorDispatch drawSegmentsDecorationView:bar];
    CHECK(lastDecoration != nil && lastDecoration.barView == bar);
    lastDecoration = nil;
    [FixtureDecoratorDispatch drawSegmentsOnActiveDecorationView:bar];
    CHECK(lastDecoration != nil && lastDecoration.barView == bar);

    FixtureGradientBar *gradientBar = [FixtureGradientBar new];
    gradientBar.superview = parent; gradientBar.recoveredAncestor = ancestor;
    gradientBar.brandGradient = makeView(CGRectMake(70, 0, 20, 4));
    [FixtureDecoratorDispatch drawSegmentsOnActiveDecorationView:gradientBar];
    CHECK(lastDecoration.barView == gradientBar.brandGradient && lastDecoration.playerBarWidth == 250);
    gradientBar.brandGradient = nil;
    [FixtureDecoratorDispatch drawSegmentsOnActiveDecorationView:gradientBar];
    CHECK(lastDecoration.barView == gradientBar);
    lastDecoration = nil;
    preferences[@"sponsorBlock"] = @NO;
    [FixtureDecoratorDispatch drawSegmentsDecorationView:bar];
    [FixtureDecoratorDispatch drawSegmentsOnActiveDecorationView:gradientBar];
    CHECK(lastDecoration == nil);
    preferences[@"sponsorBlock"] = @YES;
    bar.recoveredAncestor = [NSObject new];
    CHECK([SBPlayerDecorator _decorationDataForBarView:bar] == nil);
    CHECK(![SBPlayerDecorator shouldDrawRoundedForBarView:bar]);
    bar.recoveredAncestor = ancestor;
    ancestor.parentViewController = [NSObject new];
    CHECK([SBPlayerDecorator _decorationDataForBarView:bar] == nil);
    [preferences removeAllObjects];
}

static void testClippedDecoration(void) {
    installColors();
    FixtureRoundedBar *bar = [FixtureRoundedBar new];
    bar.frame = CGRectMake(40, 0, 99, 99);
    bar.layer.bounds = CGRectMake(0, 0, 60, 6);
    bar.playedProgressRoundedCorners = 8;
    SBSegment *left = makeSegment(@"sponsor", 10, 25);
    SBSegment *interior = makeSegment(@"sponsor", 30, 40);
    SBSegment *right = makeSegment(@"sponsor", 45, 55);
    SBSegment *full = makeSegment(@"sponsor", 0, 100);
    SBSegment *highlight = makeSegment(@"poi_highlight", 35, 35);
    SBSegment *zero = makeSegment(@"sponsor", 40, 40);
    SBSegment *duplicate = makeSegment(@"sponsor", 32, 39);
    duplicate.uuid = interior.uuid;
    SBPlayerDecorationData *data = [SBPlayerDecorationData new];
    data.barView = bar; data.playerBarWidth = 200; data.mediaDuration = 100;
    data.segments = @[left, interior, right, full, highlight, zero, duplicate,
        makeSegment(@"sponsor", 5, 20), makeSegment(@"sponsor", 50, 60),
        makeSegment(@"outro", 22, 40), makeSegment(@"sponsor", NAN, 60)];
    [[UIBezierPath recoveredCalls] removeAllObjects];
    [SBPlayerDecorator _drawSegmentsForData:data];
    NSArray<CALayer *> *layers = bar.layer.sublayers;
    CHECK(layers.count == 6);
    checkRect(layers[0].frame, CGRectMake(0, 0, 10, 6));
    checkRect(layers[1].frame, CGRectMake(20, 0, 20, 6));
    checkRect(layers[2].frame, CGRectMake(50, 0, 10, 6));
    checkRect(layers[3].frame, CGRectMake(0, 0, 60, 6));
    checkRect(layers[4].frame, CGRectMake(30, 0, 10, 6));
    checkRect(layers[5].frame, CGRectMake(40, 0, 0, 6));
    for (CALayer *layer in layers) {
        CHECK(layer.zPosition == 999 && layer.backgroundColor != NULL);
        CHECK(fabs(CGColorGetAlpha(layer.backgroundColor) - 0.8) < 0.00001);
    }
    CHECK(layers[0].mask != nil && layers[1].mask == nil && layers[2].mask != nil);
    CHECK(layers[3].mask != nil && layers[4].mask == nil && layers[5].mask == nil);
    NSArray *paths = [UIBezierPath recoveredCalls];
    CHECK(paths.count == 3);
    CHECK([paths[0][@"corners"] unsignedIntegerValue] == 5);
    CHECK([paths[1][@"corners"] unsignedIntegerValue] == 10);
    CHECK([paths[2][@"corners"] unsignedIntegerValue] == 15);
    CGSize radii;
    [paths[0][@"radii"] getValue:&radii]; CHECK(radii.width == 5 && radii.height == 5);
    [paths[2][@"radii"] getValue:&radii]; CHECK(radii.width == 8 && radii.height == 8);
    CHECK(((CAShapeLayer *)layers[0].mask).path != NULL);
    [SBPlayerDecorator _drawSegmentsForData:data];
    CHECK(bar.layer.sublayers.count == 12);
    UIView *plain = makeView(CGRectMake(40, 0, 60, 6));
    data.barView = plain; data.segments = @[full];
    [SBPlayerDecorator _drawSegmentsForData:data];
    CHECK(plain.layer.sublayers.count == 1 && plain.layer.sublayers[0].mask == nil);
    [YTLPlaybackPreferencesFixture() removeAllObjects];
}

static void testLayerCache(void) {
    installColors();
    YTPlayerViewController *player = [YTPlayerViewController new];
    player.currentVideoTotalMediaTime = 100;
    UIView *bar = makeView(CGRectMake(0, 0, 200, 8));
    bar.layer.bounds = CGRectMake(0, 0, 240, 6);
    CALayer *target = [CALayer layer]; target.bounds = CGRectMake(0, 0, 300, 7);
    CALayer *unowned = [CALayer layer]; [target addSublayer:unowned];
    SBSegment *first = makeSegment(@"sponsor", 10, 20);
    SBSegment *duplicate = makeSegment(@"sponsor", 30, 50); duplicate.uuid = first.uuid;
    SBSegment *highlight = makeSegment(@"poi_highlight", 80, 80);
    setSegments(player, @[first, duplicate, highlight, makeSegment(@"sponsor", NAN, 60),
        makeSegment(@"sponsor", 10, 10), makeSegment(@"sponsor", 30, 20)]);
    [SBPlayerDecorator drawSegments:bar layer:target playerVC:player];
    CHECK(target.sublayers.count == 3 && target.sublayers[0] == unowned);
    checkRect(target.sublayers[1].frame, CGRectMake(72, 0, 48, 2));
    checkRect(target.sublayers[2].frame, CGRectMake(192, 0, 10, 2));
    // Core Animation's returned collection can reflect later mutations. Keep
    // our own immutable snapshot before the source removes cached sublayers.
    NSArray<CALayer *> *old = @[target.sublayers[0], target.sublayers[1], target.sublayers[2]];
    [SBPlayerDecorator drawSegments:bar layer:nil playerVC:player];
    CHECK([target.sublayers isEqual:old]);
    bar.window = nil;
    [SBPlayerDecorator drawSegments:bar layer:target playerVC:player];
    CHECK([target.sublayers isEqual:old]);
    bar.window = [NSObject new];
    player.currentVideoTotalMediaTime = 0;
    [SBPlayerDecorator drawSegments:bar layer:target playerVC:player];
    CHECK([target.sublayers isEqual:old]);
    player.currentVideoTotalMediaTime = 100;
    CALayer *other = [CALayer layer]; other.bounds = CGRectMake(0, 0, 300, 8);
    [SBPlayerDecorator drawSegments:bar layer:other playerVC:player];
    CHECK(target.sublayers.count == 1 && target.sublayers[0] == unowned && other.sublayers.count == 2);
    CHECK(old[1].superlayer == nil && old[2].superlayer == nil);
    setSegments(player, @[makeSegment(@"sponsor", -10, 120)]);
    [SBPlayerDecorator drawSegments:bar layer:other playerVC:player];
    CHECK(other.sublayers.count == 1);
    checkRect(other.sublayers[0].frame, CGRectMake(-24, 0, 312, 2));
    setSegments(player, nil);
    [SBPlayerDecorator drawSegments:bar layer:other playerVC:player];
    CHECK(other.sublayers.count == 0 && target.sublayers.count == 1);
    setSegments(player, @[first]);
    [SBPlayerDecorator drawSegments:bar layer:other playerVC:player];
    CHECK(other.sublayers.count == 1);
    bar.layer.bounds = CGRectMake(0, 0, 0, 6);
    [SBPlayerDecorator drawSegments:bar layer:other playerVC:player];
    CHECK(other.sublayers.count == 0);
    [YTLPlaybackPreferencesFixture() removeAllObjects];
}

static void testChapterDrawing(void) {
    installColors();
    YTPlayerViewController *player = [YTPlayerViewController new];
    player.currentVideoTotalMediaTime = 100;
    UIView *bar = makeView(CGRectMake(0, 0, 200, 10));
    FixtureChapterBar *chapters = [FixtureChapterBar new];
    UIView *first = makeView(CGRectMake(0, 0, 50, 8));
    UIView *second = makeView(CGRectMake(50, 0, 50, 8));
    UIView *third = makeView(CGRectMake(100, 0, 50, 8));
    first.layer.bounds = CGRectMake(0, 0, 50, 4);
    chapters.segmentViews = @[first, second, third];
    SBSegment *crossing = makeSegment(@"sponsor", 20, 40);
    SBSegment *contained = makeSegment(@"sponsor", 35, 45);
    SBSegment *highlight = makeSegment(@"poi_highlight", 49, 49);
    setSegments(player, @[crossing, contained, highlight]);
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:[UIView new] playerVC:player];
    CHECK(first.layer.sublayers.count == 0);
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(first.layer.sublayers.count == 1 && second.layer.sublayers.count == 2 && third.layer.sublayers.count == 0);
    checkRect(first.layer.sublayers[0].frame, CGRectMake(40, 0, 10, 4));
    checkRect(second.layer.sublayers[0].frame, CGRectMake(20, 0, 20, 8));
    checkRect(second.layer.sublayers[1].frame, CGRectMake(48, 0, 2, 8));
    CHECK(first.layer.sublayers[0].zPosition == 0 && first.layer.sublayers[0].mask == nil);
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(first.layer.sublayers.count == 2 && second.layer.sublayers.count == 4);
    first.window = nil;
    setSegments(player, @[crossing]);
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(first.layer.sublayers.count == 2 && second.layer.sublayers.count == 5);
    checkRect(second.layer.sublayers.lastObject.frame, CGRectMake(0, 0, 30, 8));
    FixtureInvalidFrameView *invalid = [FixtureInvalidFrameView new];
    invalid.bounds = CGRectMake(0, 0, 50, 8); invalid.window = [NSObject new];
    invalid.reportedFrame = CGRectMake(NAN, 0, 50, 8);
    chapters.segmentViews = @[invalid];
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(invalid.layer.sublayers.count == 0);
    invalid.reportedFrame = CGRectMake(0, NAN, 50, 8);
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(invalid.layer.sublayers.count == 0);
    invalid.reportedFrame = CGRectMake(0, 0, 50, 8);
    invalid.bounds = CGRectZero;
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(invalid.layer.sublayers.count == 0);
    chapters.segmentViews = @[second];
    NSUInteger count = second.layer.sublayers.count;
    player.currentVideoTotalMediaTime = 0;
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(second.layer.sublayers.count == count);
    player.currentVideoTotalMediaTime = 100;
    YTLPlaybackPreferencesFixture()[@"sb_sponsor"] = @0;
    [SBPlayerDecorator drawSegmentableSegments:bar playerBar:chapters playerVC:player];
    CHECK(second.layer.sublayers.count == count);
    [YTLPlaybackPreferencesFixture() removeAllObjects];
}

NSUInteger testSponsorDrawing(void) {
    [CATransaction begin]; [CATransaction setDisableActions:YES];
    fprintf(stderr, "Drawing checks: duration label\n"); testDurationLabel();
    fprintf(stderr, "Drawing checks: ancestor and data factory\n"); testAncestorAndFactory();
    fprintf(stderr, "Drawing checks: clipped decoration\n"); testClippedDecoration();
    fprintf(stderr, "Drawing checks: layer cache\n"); testLayerCache();
    fprintf(stderr, "Drawing checks: chapter drawing\n"); testChapterDrawing();
    fprintf(stderr, "Drawing checks: transaction commit\n");
    [CATransaction commit];
    printf("SponsorBlock decoration tests: %lu assertions passed (geometry and UIKit message arguments).\n", (unsigned long)assertions);
    return assertions;
}
