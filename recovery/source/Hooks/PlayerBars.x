#import "PlayerBarsHost.h"
#import "../Playback/SBPlayerDecorator.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>

static UIColor *PlayerBarsColor(NSString *key) {
    NSData *data = [[YTLUserDefaults standardUserDefaults] objectForKey:key];
    return [NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:data error:nil];
}
static void PlayerBarsReadColors(UIColor *__strong *main, UIColor *__strong *end) {
    NSData *mainData = [[YTLUserDefaults standardUserDefaults] objectForKey:@"progressMainColor"];
    NSData *endData = [[YTLUserDefaults standardUserDefaults] objectForKey:@"progressGradientColor"];
    *main = [NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:mainData error:nil];
    *end = [NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:endData error:nil];
}
static BOOL PlayerBarsHasIvar(id object, const char *name) {
    return class_getInstanceVariable([object class], name) != NULL;
}
static void PlayerBarsSetGradientColors(CAGradientLayer *gradient, UIColor *main, UIColor *end) {
    if (ytpInt(@"progressBarIndex") == 1 && main) {
        gradient.colors = @[(__bridge id)main.CGColor, (__bridge id)main.CGColor];
    } else if (ytpInt(@"progressBarIndex") == 2 && main && end) {
        gradient.colors = @[(__bridge id)main.CGColor, (__bridge id)end.CGColor];
    }
}
static void PlayerBarsInstallGradient(UIView *view, UIColor *main, UIColor *end) {
    CAGradientLayer *gradient = nil;
    for (CALayer *layer in view.layer.sublayers) {
        if ([layer.name isEqualToString:@"ytpGradient"]) { gradient = (CAGradientLayer *)layer; break; }
    }
    if (!gradient) {
        gradient = [CAGradientLayer layer];
        gradient.name = @"ytpGradient";
        [view.layer addSublayer:gradient];
    }
    gradient.frame = view.bounds;
    gradient.startPoint = CGPointMake(0, 0.5);
    gradient.endPoint = CGPointMake(1, 0.5);
    gradient.colors = @[(__bridge id)main.CGColor, (__bridge id)main.CGColor, (__bridge id)end.CGColor];
    gradient.locations = @[@0.0, @0.75, @1.0];
    view.layer.masksToBounds = YES;
}
static void PlayerBarsApplyBrandGradient(UIView *bar) {
    if (!ytpInt(@"progressBarIndex") || !PlayerBarsHasIvar(bar, "_brandGradient")) return;
    UIView *brand = [bar valueForKey:@"_brandGradient"];
    if (!brand) return;
    UIColor *main = nil, *end = nil;
    PlayerBarsReadColors(&main, &end);
    if (main) {
        if (ytpInt(@"progressBarIndex") == 1) end = main;
        // Other nonzero indices also reach installation; nil end then raises in the colors literal.
        if (ytpInt(@"progressBarIndex") != 2 || end) PlayerBarsInstallGradient(brand, main, end);
    }
}
static void PlayerBarsConfigureMuted(YTInlineMutedPlaybackScrubberView *bar) {
    if (!ytpBool(@"sponsorBlock") || !ytpBool(@"sbFeedPlayer")) return;
    static Class scrubberClass, overlayClass, playerClass;
    UIViewController *ancestor = [bar _viewControllerForAncestor];
    if (!scrubberClass) scrubberClass = objc_getClass("YTInlineMutedPlaybackScrubberViewController");
    if (![ancestor isKindOfClass:scrubberClass]) return;
    UIViewController *controller = [bar _viewControllerForAncestor];
    UIViewController *parent = controller.parentViewController;
    if (!overlayClass) overlayClass = objc_getClass("YTInlineMutedPlaybackPlayerOverlayViewController");
    if (![parent isKindOfClass:overlayClass]) return;
    UIViewController *overlay = controller.parentViewController;
    id responder = [overlay parentResponder];
    if (!playerClass) playerClass = objc_getClass("YTPlayerViewController");
    if (![responder isKindOfClass:playerClass]) return;
    id player = [overlay parentResponder];
    if (!PlayerBarsHasIvar(bar, "_playingProgress")) return;
    UIView *progress = [bar valueForKey:@"_playingProgress"];
    if ([bar respondsToSelector:@selector(segmentablePlayerBarEnabled)]) {
        [bar segmentablePlayerBarEnabled]; // Original calls this accessor but does not branch on its result.
        [SBPlayerDecorator drawSegmentableSegments:bar playerBar:[bar segmentablePlayerBar] playerVC:player];
    } else {
        [SBPlayerDecorator drawSegments:bar layer:progress.layer playerVC:player];
    }
}
static void PlayerBarsConfigureMini(YTProgressView *bar) {
    if (!ytpBool(@"sponsorBlock") || !ytpBool(@"sbMiniPlayer")) return;
    static Class miniClass, floatingClass;
    UIViewController *ancestor = [bar _viewControllerForAncestor];
    if (!miniClass) miniClass = objc_getClass("YTWatchMiniBarViewController");
    id player = nil;
    if ([ancestor isKindOfClass:miniClass]) {
        UIViewController *controller = [bar _viewControllerForAncestor];
        if (!PlayerBarsHasIvar(controller, "_playerViewController")) return;
        player = [controller valueForKey:@"_playerViewController"];
    } else {
        UIViewController *controller = [bar _viewControllerForAncestor];
        if (!floatingClass) floatingClass = objc_getClass("YTWatchFloatingMiniplayerViewController");
        if ([controller isKindOfClass:floatingClass]) {
            controller = [bar _viewControllerForAncestor];
            if (!PlayerBarsHasIvar(controller, "_playerViewController")) return;
            player = [controller valueForKey:@"_playerViewController"];
        }
    }
    [SBPlayerDecorator drawSegments:bar layer:bar.layer playerVC:player];
}

// Earlier registration pass. Later customization hooks chain through these originals.
%group YTLPlayerBarsSponsor
%hook YTInlinePlayerBarContainerView
%property (nonatomic, retain) NSString *sbTimeString;
- (void)setPeekableViewVisible:(BOOL)visible {
    %orig;
    if (ytpBool(@"sponsorBlock") && ytpBool(@"sbDurationLabel") && self.sbTimeString && ![self.durationLabel.text containsString:self.sbTimeString]) {
        self.durationLabel.text = [self.durationLabel.text stringByAppendingString:[NSString stringWithFormat:@" (%@)", self.sbTimeString]];
        [self.durationLabel sizeToFit];
    }
}
%end
%hook YTPlayerBarRectangleDecorationView
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient {
    %orig;
    [SBPlayerDecorator drawSegmentsDecorationView:self];
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color {
    %orig;
    [SBPlayerDecorator drawSegmentsDecorationView:self];
}
- (BOOL)isStateActive {
    [SBPlayerDecorator drawSegmentsDecorationView:self];
    return %orig;
}
%end
%hook YTPlayerBarProgressDecorationView
- (void)applyGradientForRect:(CGRect)rect {
    %orig;
    [SBPlayerDecorator drawSegmentsDecorationView:self];
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color {
    %orig;
    [SBPlayerDecorator drawSegmentsDecorationView:self];
}
- (BOOL)isStateActive {
    [SBPlayerDecorator drawSegmentsDecorationView:self];
    return %orig;
}
%end
%hook YTProgressView
- (void)setProgress:(double)progress {
    %orig;
    PlayerBarsConfigureMini(self);
}
%end
%hook YTInlineMutedPlaybackScrubberView
- (void)setMediaTime:(double)time {
    %orig;
    PlayerBarsConfigureMuted(self);
}
- (void)addGradient {
    %orig;
    PlayerBarsConfigureMuted(self);
}
%end
%end

%group YTLPlayerBarsAppearance
%hook YTInlinePlayerBarContainerView
%property (nonatomic, retain) NSString *endTimeString;
- (void)setPlayerBarAlpha:(CGFloat)alpha {
    %orig(ytpBool(@"persistentProgressBar") ? 1.0 : alpha);
}
- (void)setFrame:(CGRect)frame {
    CGFloat screenWidth = [UIScreen mainScreen].bounds.size.width;
    CGFloat screenHeight = [UIScreen mainScreen].bounds.size.height;
    CGFloat shortSide = screenWidth < screenHeight ? screenWidth : screenHeight;
    if (frame.size.width > shortSide && ytpBool(@"noFullscreenActions")) {
        CGFloat bottomInset = self.superview.safeAreaInsets.bottom;
        CGFloat height = self.superview.bounds.size.height;
        frame.origin.y = height - bottomInset - frame.size.height - 10;
    }
    %orig(frame);
}
- (UIColor *)quietProgressBarColor {
    UIColor *color = PlayerBarsColor(@"progressMainColor");
    return ytpInt(@"progressBarIndex") != 0 && color ? color : %orig;
}
- (void)setPeekableViewVisible:(BOOL)visible {
    %orig;
    if (ytpBool(@"videoEndTime") && self.endTimeString && ![self.durationLabel.text containsString:self.endTimeString]) {
        self.durationLabel.text = [self.durationLabel.text stringByAppendingString:[NSString stringWithFormat:@" • %@", self.endTimeString]];
        [self.durationLabel sizeToFit];
    }
}
- (void)didPressScrubber:(UIGestureRecognizer *)recognizer {
    %orig;
    UIViewController<YTLPlayerBarsPlayer> *player = (id)[self _viewControllerForAncestor].parentViewController;
    static Class playerClass;
    if (!playerClass) playerClass = objc_getClass("YTPlayerViewController");
    if ([player isKindOfClass:playerClass] && ytpBool(@"tapToSeek")) {
        CGFloat fraction = [self scrubRangeForScrubX:[recognizer locationInView:self].x];
        [player seekToTime:fraction * [player currentVideoTotalMediaTime]];
    }
}
%end
%hook YTPlayerBarScrubberDotDecorationView
- (UIView *)scrubberDot {
    UIView *dot = %orig;
    if (dot) {
        UIColor *color = PlayerBarsColor(@"scrubberColor");
        if (ytpInt(@"progressBarIndex") != 0 && color) dot.backgroundColor = color;
    }
    return dot;
}
%end
%hook YTPlayerBarScrubberDotDecorationViewV1
- (UIView *)scrubberDot {
    UIView *dot = %orig;
    if (dot) {
        UIColor *color = PlayerBarsColor(@"scrubberColor");
        if (ytpInt(@"progressBarIndex") != 0 && color) dot.backgroundColor = color;
    }
    return dot;
}
%end
%hook YTPlayerBarRectangleDecorationView
- (void)applyGradientForRect:(CGRect)rect {
    %orig;
    PlayerBarsApplyBrandGradient(self);
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color {
    UIColor *custom = PlayerBarsColor(@"progressMainColor");
    %orig(rect, ytpInt(@"progressBarIndex") != 0 && custom ? custom : color);
}
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient {
    UIColor *main = nil, *end = nil;
    PlayerBarsReadColors(&main, &end);
    PlayerBarsSetGradientColors(gradient, main, end);
    %orig;
}
%end
%hook YTPlayerBarProgressDecorationView
- (void)applyGradientForRect:(CGRect)rect {
    %orig;
    PlayerBarsApplyBrandGradient(self);
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color {
    UIColor *custom = PlayerBarsColor(@"progressMainColor");
    %orig(rect, ytpInt(@"progressBarIndex") != 0 && custom ? custom : color);
}
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient {
    UIColor *main = nil, *end = nil;
    PlayerBarsReadColors(&main, &end);
    PlayerBarsSetGradientColors(gradient, main, end);
    %orig;
}
%end
%hook YTModularPlayerBarView
- (void)layoutSubviews {
    %orig;
    if (PlayerBarsHasIvar(self, "_scrubberCircle")) {
        UIView *circle = [self valueForKey:@"_scrubberCircle"];
        UIColor *color = PlayerBarsColor(@"scrubberColor");
        if (ytpInt(@"progressBarIndex") != 0 && color) circle.backgroundColor = color;
    }
}
%end
%hook YTInlineMutedPlaybackScrubberView
- (void)addGradient {
    if (ytpInt(@"progressBarIndex") == 0) %orig;
}
- (void)layoutSubviews {
    %orig;
    if (PlayerBarsHasIvar(self, "_progressBarGradient")) {
        CAGradientLayer *gradient = [self valueForKey:@"_progressBarGradient"];
        UIColor *main = nil, *end = nil;
        PlayerBarsReadColors(&main, &end);
        PlayerBarsSetGradientColors(gradient, main, end);
    }
}
%end
%hook YTInlineMutedPlaybackScrubbingSlider
- (UIImage *)currentMinimumTrackImage {
    UIImage *image = %orig;
    UIColor *color = PlayerBarsColor(@"progressMainColor");
    if (ytpInt(@"progressBarIndex") != 0 && color) image = [image _flatImageWithColor:color];
    return image;
}
%end
%hook YTProgressView
- (void)setProgressBarColor:(UIColor *)color {
    UIColor *main = nil, *end = nil;
    PlayerBarsReadColors(&main, &end);
    %orig(ytpInt(@"progressBarIndex") != 0 && main ? main : color);
    if (PlayerBarsHasIvar(self, "_progressBarGradient")) {
        CAGradientLayer *gradient = [self valueForKey:@"_progressBarGradient"];
        PlayerBarsSetGradientColors(gradient, main, end);
    }
}
- (void)setProgress:(double)progress {
    %orig;
    if ([self.superview isKindOfClass:objc_getClass("YTVideoThumbnailView")] || !ytpInt(@"progressBarIndex")) return;
    UIColor *main = nil, *end = nil;
    PlayerBarsReadColors(&main, &end);
    if (main) {
        if (ytpInt(@"progressBarIndex") == 1) end = main;
        if ((ytpInt(@"progressBarIndex") != 2 || end) && PlayerBarsHasIvar(self, "_progressBarGradientView")) {
            UIView *gradientView = [self valueForKey:@"_progressBarGradientView"];
            PlayerBarsInstallGradient(gradientView, main, end);
        }
    }
}
%end
%end

void YTLInstallPlayerBarsSponsorHooks(void) {
    %init(YTLPlayerBarsSponsor);
}
void YTLInstallPlayerBarsAppearanceHooks(void) {
    %init(YTLPlayerBarsAppearance);
}
