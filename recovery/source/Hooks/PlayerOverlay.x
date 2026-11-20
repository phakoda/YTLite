#import "PlayerOverlayHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Runtime/YTLHookEntrypoints.h"
#import "../Controls/YTPSpeedMaster.h"
#import "../Controls/DVNHorizontalPanDelegate.h"
#import "../Presentation/PlayerToast.h"
#import "../Helpers/YTLHelper.h"
#import "../Downloads/DownloadMenuHelper.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
#include <math.h>
#include <stdint.h>
static char OverlayButtonKey,OverlayIconKey,OverlayInitialPanKey;
static NSInteger OverlayGestureMode = -1;
static double OverlayInitialBrightness = -1, OverlayInitialVolume = -1;
static BOOL OverlayForceInlineStyle(void) { return ytpBool(@"downloadManager") || ytpBool(@"sponsorBlock"); }
static NSString *OverlayLocalized(NSString *key) { return [NSBundle.ytl_defaultBundle localizedStringForKey:key value:nil table:nil]; }
static int64_t OverlayIntegerTime(double value, BOOL nearest) {
    if (isnan(value)) return 0;
    if (value >= 0x1p63) return INT64_MAX;
    if (value <= -0x1p63) return INT64_MIN;
    return (int64_t)(nearest ? round(value) : value);
}
// FCSEL/GT followed by FMAXNM preserves an unordered input until it becomes zero.
static double OverlayClamp(double value,double maximum) { return fmax(value > maximum ? maximum : value, 0); }
%group YTLPlayerOverlay
%hook YTInlineMutedPlaybackPlayerOverlayView
- (NSInteger)audioControlUIStyle { if (OverlayForceInlineStyle()) return 2; return %orig; }
- (NSInteger)scrubbingUIStyle { if (OverlayForceInlineStyle()) return 2; return %orig; }
- (void)updateAudioControlUIStyle:(NSInteger)style { %orig(OverlayForceInlineStyle() ? 2 : style); }
- (void)resetWithAudioControlUIStyle:(NSInteger)style { %orig(OverlayForceInlineStyle() ? 2 : style); }
- (void)setAudioControlUIStyle:(NSInteger)style { %orig(OverlayForceInlineStyle() ? 2 : style); }
%end
%hook YTInlineMutedPlaybackPlayerOverlayViewController
- (NSInteger)scrubbingUIStyle { if (OverlayForceInlineStyle()) return 2; return %orig; }
- (void)setPaidContentWithPlayerData:(id)data { if (!ytpBool(@"noPromotionCards")) %orig; }
- (void)viewDidLoad {
    %orig;
    UIPanGestureRecognizer *pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handleHorizontalPan:)];
    pan.minimumNumberOfTouches = 1; pan.maximumNumberOfTouches = 1; pan.delegate = self;
    [self.view addGestureRecognizer:pan];
}
%new
- (BOOL)gestureRecognizerShouldBegin:(UIPanGestureRecognizer *)gesture {
    CGPoint velocity = [gesture velocityInView:self.view];
    return fabs(velocity.x) > fabs(velocity.y);
}
%new
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)other { return YES; }
%new
- (void)handleHorizontalPan:(UIPanGestureRecognizer *)gesture {
    if (!ytpBool(@"seekAnywhereFeed") || ![self.parentViewController isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) return;
    id<YTLOverlayPlayer> player = (id)self.parentViewController;
    if (![player respondsToSelector:@selector(seekToTime:)]) return;
    double total = self.totalTime, width = CGRectGetWidth(self.view.bounds);
    if (gesture.state == 1) objc_setAssociatedObject(self, &OverlayInitialPanKey, @(self.mediaTime), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if (gesture.state == 2) {
        NSNumber *initial = objc_getAssociatedObject(self, &OverlayInitialPanKey);
        double start = initial ? initial.doubleValue : self.mediaTime;
        total = (double)OverlayIntegerTime(total, YES);
        double change = [gesture translationInView:self.view].x * ((double)[YTLUserDefaults.standardUserDefaults floatForKey:@"seekSensitivity"] / 10);
        if (!ytpInt(@"seekMethodIndex")) change = (total / width) * change;
        [player seekToTime:OverlayClamp(start + change, total)];
    }
}
%end
%hook YTInlineMutedPlaybackAudioIconViewController
%new
- (UIButton *)ytlButton { return objc_getAssociatedObject(self,&OverlayButtonKey); }
%new
- (void)setYtlButton:(UIButton *)button { objc_setAssociatedObject(self,&OverlayButtonKey,button,OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIView *)ytlIcon { return objc_getAssociatedObject(self,&OverlayIconKey); }
%new
- (void)setYtlIcon:(UIView *)view { objc_setAssociatedObject(self,&OverlayIconKey,view,OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
- (void)viewDidLoad {
    %orig;
    if (!ytpBool(@"downloadManager")) return;
    YTInlineMutedPlaybackAudioIconView *view = (id)self.view;
    UIView *audio = [view valueForKey:@"_audioIconWithOverlayView"];
    UIView *sound = [view valueForKey:@"_audioSoundIconImageView"];
    id<YTLOverlayAssetLoader> loader = [(id<YTLOverlayAssetLoader>)[NSClassFromString(@"YTAssetLoader") alloc] initWithBundle:NSBundle.ytl_defaultBundle];
    UIImage *icon = [YTLHelper resizeImage:[loader imageNamed:@"ytl_icon"] toSize:24];
    self.ytlButton = [YTLHelper createYTQTMButton:self accessibilityLabel:OverlayLocalized(@"YTLButton") buttonLabel:nil icon:icon selector:@selector(handleYTLIconTap:)];
    self.ytlIcon = [UIView new]; self.ytlIcon.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:.6];
    self.ytlIcon.clipsToBounds = YES; self.ytlIcon.translatesAutoresizingMaskIntoConstraints = NO;
    if (audio) {
        self.ytlIcon.layer.cornerRadius = audio.frame.size.height * .5;
        [view addSubview:self.ytlIcon]; [self.ytlIcon addSubview:self.ytlButton];
        if ([view goo_shouldRelayoutSubviewsForRTL]) [self.ytlIcon.trailingAnchor constraintEqualToAnchor:view.trailingAnchor].active = YES;
        else [self.ytlIcon.trailingAnchor constraintEqualToAnchor:audio.leadingAnchor constant:-10].active = YES;
        [self.ytlIcon.centerYAnchor constraintEqualToAnchor:audio.centerYAnchor].active = YES;
        [self.ytlIcon.widthAnchor constraintEqualToAnchor:audio.widthAnchor].active = YES;
        [self.ytlIcon.heightAnchor constraintEqualToAnchor:audio.heightAnchor].active = YES;
        [self.ytlButton.centerXAnchor constraintEqualToAnchor:self.ytlIcon.centerXAnchor].active = YES;
        [self.ytlButton.centerYAnchor constraintEqualToAnchor:self.ytlIcon.centerYAnchor].active = YES;
        [self.ytlButton.widthAnchor constraintEqualToAnchor:sound.widthAnchor].active = YES;
        [self.ytlButton.heightAnchor constraintEqualToAnchor:sound.heightAnchor].active = YES;
    }
}
%new
- (void)handleYTLIconTap:(id)sender { [DownloadMenuHelper showDownloadSheet:self.parentResponder withSender:sender]; }
%end
%hook YTInlineMutedPlaybackAudioIconView
- (void)updateColors {
    %orig;
    if (!ytpBool(@"downloadManager")) return;
    YTInlineMutedPlaybackAudioIconViewController *controller = self._viewControllerForAncestor;
    UIView *audio = [self valueForKey:@"_audioIconWithOverlayView"];
    if (audio) [UIView animateWithDuration:.8 delay:0 options:UIViewAnimationOptionCurveEaseIn animations:^{
        controller.ytlIcon.backgroundColor = audio.backgroundColor;
        if (!audio.backgroundColor) {
            controller.ytlButton.layer.shadowColor = UIColor.blackColor.CGColor;
            controller.ytlButton.layer.shadowOpacity = .5f;
            controller.ytlButton.layer.shadowOffset = CGSizeMake(0,1);
            controller.ytlButton.layer.shadowRadius = 4;
        }
    } completion:nil];
}
%end
%hook YTMainAppVideoPlayerOverlayView
- (void)setBackgroundVisible:(BOOL)visible isGradientBackground:(BOOL)gradient { BOOL hide = ytpBool(@"noDarkBg"); %orig(visible && !hide, gradient); }
- (id)autonavPreviewView { if (ytpBool(@"autonavEndScreenCards")) return nil; return %orig; }
- (BOOL)isWatermarkEnabled { if (ytpBool(@"noWatermarks")) return NO; return %orig; }
- (id)featuredChannelWatermarkImageView { if (ytpBool(@"noWatermarks")) return nil; return %orig; }
- (void)setSeekAnywherePanGestureRecognizer:(UIGestureRecognizer *)recognizer {
    if (!ytpInt(@"speedIndex")) { %orig; }
    else {
        UILongPressGestureRecognizer *press = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(speedmasterYtLite:)];
        press.minimumPressDuration = .3;
        if (ytpInt(@"speedIndex")) [self addGestureRecognizer:press];
    }
}
%new
- (void)speedmasterYtLite:(UILongPressGestureRecognizer *)recognizer { [[YTPSpeedMaster sharedMaster] manageSpeedMaster:recognizer playerOverlayVC:self.delegate]; }
%end
%hook YTMainAppVideoPlayerOverlayViewController
- (BOOL)shouldShowAutonavEndscreen { if (ytpBool(@"autonavEndScreenCards")) return NO; return %orig; }
- (void)setFeaturedChannelWatermarkImageView:(id)view { if (!ytpBool(@"noWatermarks")) %orig; }
- (void)setPaidContentWithPlayerData:(id)data { if (!ytpBool(@"noPromotionCards")) %orig; }
- (void)playerOverlayProvider:(id)provider didInsertPlayerOverlay:(id<YTLOverlayIdentifier>)overlay {
    if ([overlay.overlayIdentifier isEqualToString:@"player_overlay_paid_content"] && ytpBool(@"noPromotionCards")) return;
    if ([overlay.overlayIdentifier isEqualToString:@"player_overlay_product_in_video"] && ytpBool(@"noAds")) return;
    %orig;
}
- (NSString *)selectedVarispeedLabelText { if (self.currentPlaybackRate == 1) return %orig; return [NSString stringWithFormat:@"%@x", @(self.currentPlaybackRate).stringValue]; }
- (BOOL)allowDoubleTapToSeekGestureRecognizer { if (ytpBool(@"noDoubleTapToSeek")) return NO; return %orig; }
- (BOOL)allowTwoFingerDoubleTapGestureRecognizer { if (ytpBool(@"noTwoFingerSnapToChapter")) return NO; return %orig; }
- (void)didPressPause:(id)sender {
    %orig;
    if (ytpBool(@"copyWithTimestamp")) {
        int64_t seconds = OverlayIntegerTime(self.mediaTime, NO);
        UIPasteboard.generalPasteboard.string = [NSString stringWithFormat:@"https://www.youtube.com/watch?v=%@&t=%lds", self.videoID, (long)seconds];
    }
}
- (void)setLoopMode:(NSInteger)mode { %orig; if (canRememberLoopMode) [YTLUserDefaults.standardUserDefaults setInteger:mode forKey:@"loopMode"]; }
- (void)viewDidLoad {
    %orig;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTwoFingerTap:)];
    tap.numberOfTouchesRequired = 2; [self.view addGestureRecognizer:tap];
    UIPanGestureRecognizer *finger = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handleFingerPan:)];
    finger.minimumNumberOfTouches = 1; finger.maximumNumberOfTouches = 1; finger.delegate = self; [self.view addGestureRecognizer:finger];
    UIPanGestureRecognizer *horizontal = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handleHorizontalPan:)];
    horizontal.minimumNumberOfTouches = 1; horizontal.maximumNumberOfTouches = 1;
    DVNHorizontalPanDelegate *delegate = [DVNHorizontalPanDelegate new];
    objc_setAssociatedObject(self,@selector(handleHorizontalPan:),delegate,OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    horizontal.delegate = delegate; [self.view addGestureRecognizer:horizontal];
}
%new
- (void)handleTwoFingerTap:(UITapGestureRecognizer *)gesture { if (ytpBool(@"twoFingerTap")) [self didTogglePlayPause]; }
%new
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture {
    if (![gesture isKindOfClass:UIPanGestureRecognizer.class]) return NO;
    double x = [gesture locationInView:self.view].x, width = self.view.bounds.size.width;
    double edge = [YTLUserDefaults.standardUserDefaults floatForKey:@"gestWideness"];
    BOOL left = x <= edge && ytpInt(@"leftGestureIndex") != 0;
    BOOL right = x >= width - edge && ytpInt(@"rightGestureIndex") != 0;
    return left || right;
}
%new
- (void)handleHorizontalPan:(UIPanGestureRecognizer *)gesture {
    if (!ytpBool(@"seekAnywhere")) return;
    id<YTLOverlayScrubber> bar = self.playerBarController.playerBar;
    if (![bar respondsToSelector:@selector(fineScrubberDidStartSeeking)] || ![bar respondsToSelector:@selector(fineScrubberDidSeekToTime:)] || ![bar respondsToSelector:@selector(fineScrubberDidEndSeekingWithSeekSource:)]) return;
    double start = self.mediaTime, maximum = self.maximumSeekableTime, width = CGRectGetWidth(self.view.bounds);
    if (gesture.state == 1) { start = self.mediaTime; [bar fineScrubberDidStartSeeking]; }
    else start = (double)OverlayIntegerTime(start, YES);
    if (gesture.state == 2) {
        maximum = (double)OverlayIntegerTime(maximum, YES);
        double change = [gesture translationInView:self.view].x * ((double)[YTLUserDefaults.standardUserDefaults floatForKey:@"seekSensitivity"] / 10);
        if (!ytpInt(@"seekMethodIndex")) change = (maximum / width) * change;
        double value = OverlayClamp(start + change, maximum);
        [bar fineScrubberDidSeekToTime:value];
        if ([bar respondsToSelector:@selector(currentTimeLabel)]) {
            int64_t seconds = OverlayIntegerTime(value, NO);
            NSString *text = seconds < 3600 ? [NSString stringWithFormat:@"%ld:%02ld", (long)((seconds % 3600)/60), (long)(seconds%60)] : [NSString stringWithFormat:@"%ld:%02ld:%02ld", (long)(seconds/3600), (long)((seconds%3600)/60), (long)(seconds%60)];
            bar.currentTimeLabel.text = text; [bar.currentTimeLabel sizeToFit]; bar.currentTimeLabel.superview.alpha = 1;
        }
    }
    if (gesture.state == 3 || gesture.state == 4) [bar fineScrubberDidEndSeekingWithSeekSource:25];
}
%new
- (void)handleFingerPan:(UIPanGestureRecognizer *)gesture {
    if (gesture.state == 1) {
        double x = [gesture locationInView:self.view].x, width = self.view.bounds.size.width;
        double edge = [YTLUserDefaults.standardUserDefaults floatForKey:@"gestWideness"];
        if (x <= edge) OverlayGestureMode = ytpInt(@"leftGestureIndex");
        else if (x >= width - edge) OverlayGestureMode = ytpInt(@"rightGestureIndex");
        else OverlayGestureMode = -1;
        OverlayInitialBrightness = UIScreen.mainScreen.brightness;
        OverlayInitialVolume = [(id<YTLOverlayVolume>)[NSClassFromString(@"LDVideoAdBlock") new] systemVolume];
        if (OverlayGestureMode > 0) {
            NSString *text = OverlayLocalized(OverlayGestureMode == 1 ? @"Toast.Brightness" : @"Toast.Volume");
            double initial = OverlayGestureMode == 1 ? OverlayInitialBrightness : OverlayInitialVolume;
            [[PlayerToast sharedToast] showPlayerToastWithText:text value:(double)OverlayIntegerTime(initial * 100, YES) style:OverlayGestureMode == 2 ? 2 : 0 isCompact:ytpBool(@"compactToast")];
        }
    }
    if (gesture.state == 2 && OverlayGestureMode > 0) {
        double y = [gesture translationInView:self.view].y;
        BOOL brightness = OverlayGestureMode == 1;
        double value = OverlayClamp(fma(-y, brightness ? .005 : .008, brightness ? OverlayInitialBrightness : OverlayInitialVolume), 1);
        [[PlayerToast sharedToast] updateToastText:OverlayLocalized(brightness ? @"Toast.Brightness" : @"Toast.Volume") value:value];
    }
    if (gesture.state == 3 || gesture.state == 4) {
        OverlayGestureMode = -1; OverlayInitialBrightness = OverlayInitialVolume = -1;
        if ([PlayerToast sharedToast].alpha == 0) @throw [NSException exceptionWithName:@"YouTubePlusException" reason:@"Attempt to hide the toast outside of YouTube Plus detected. Please don't do that." userInfo:nil];
        [[PlayerToast sharedToast] hideToast];
    }
}
%end
%end
void YTLInstallPlayerOverlayHooks(void) {
    Class cls = NSClassFromString(@"YTInlineMutedPlaybackAudioIconViewController");
    const objc_property_attribute_t button[] = {{"T","@\"YTQTMButton\""},{"&",""},{"N",""}};
    const objc_property_attribute_t view[] = {{"T","@\"UIView\""},{"&",""},{"N",""}};
    class_addProperty(cls,"ytlButton",button,3); class_addProperty(cls,"ytlIcon",view,3);
    %init(YTLPlayerOverlay);
}
