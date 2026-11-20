#import "ShortsInterfaceHost.h"
#import "../Helpers/YTLHelper.h"
#import "../Downloads/DownloadMenuHelper.h"
#import "../Downloads/YTPMedia.h"
#import "../Controls/DVNLongPressDelegate.h"
#import "../Controls/YTPSpeedMaster.h"
#import "../Presentation/PlayerToast.h"
#import "../Presentation/ToastManager.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import "../../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>

static NSString *ShortsText(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}
static void ShortsStyleButton(YTQTMButton *button) {
    button.layer.shadowColor = UIColor.blackColor.CGColor;
    button.layer.shadowOpacity = 0.5f;
    button.layer.shadowOffset = CGSizeZero;
    button.layer.shadowRadius = 4;
    [[button touchFeedbackView] setCustomTouchFeedbackColor:UIColor.whiteColor];
    button.tag = 999;
}
// Packaged helper 0xc9f04. The false branch deliberately has only two constraints.
static void ShortsAddButton(UIView *overlay, UIView *reference, BOOL matchWidth) {
    CGFloat iconSize = matchWidth ? 32 : 24;
    UIImage *icon = [YTLHelper resizeImage:[YTPMedia ytPlusShorts] toSize:iconSize];
    YTQTMButton *button = (id)[YTLHelper createYTQTMButton:overlay accessibilityLabel:ShortsText(@"ShortsYTLButton") buttonLabel:nil icon:icon size:CGSizeMake(64,60) selector:@selector(didTapYtlButton:)];
    ShortsStyleButton(button);
    [overlay addSubview:button];
    if (matchWidth) {
        [button.centerXAnchor constraintEqualToAnchor:reference.centerXAnchor].active = YES;
        [button.bottomAnchor constraintEqualToAnchor:reference.topAnchor].active = YES;
        [button.widthAnchor constraintEqualToAnchor:reference.widthAnchor].active = YES;
        [button.heightAnchor constraintEqualToAnchor:reference.widthAnchor].active = YES;
    } else {
        [button.trailingAnchor constraintEqualToAnchor:reference.trailingAnchor].active = YES;
        [button.bottomAnchor constraintEqualToAnchor:reference.topAnchor].active = YES;
    }
}
static void ShortsLayoutActionButton(UIView *overlay) {
    if (!ytpBool(@"downloadManager") || [overlay viewWithTag:999]) return;
    if (!class_getInstanceVariable([overlay class], "_playerOverlayView")) return;
    UIView *playerOverlay = [overlay valueForKey:@"_playerOverlayView"];
    if (!class_getInstanceVariable([playerOverlay class], "_elementView")) return;
    id element = [playerOverlay valueForKey:@"_elementView"];
    if (!class_getInstanceVariable([element class], "_rootNode")) return;
    id<YTLShortsNode> root = [element valueForKey:@"_rootNode"];
    for (id<YTLShortsNode> node in [[[root yogaChildren] firstObject] yogaChildren]) {
        if ([[[node controller] key] isEqualToString:@"reel_player_overlay.reel_action_bar_key"]) {
            ShortsAddButton(overlay, playerOverlay, NO);
            break;
        }
    }
}
static void ShortsDownload(UIView *overlay, id sender, BOOL inlinePlayer) {
    id parent = [overlay parentResponder];
    static Class reelClass, playerClass;
    Class cls;
    if (inlinePlayer) {
        if (!playerClass) playerClass = NSClassFromString(@"YTPlayerViewController");
        cls = playerClass;
    } else {
        if (!reelClass) reelClass = NSClassFromString(@"YTReelPlayerViewController");
        cls = reelClass;
    }
    if ([parent isKindOfClass:cls]) {
        id<YTLShortsPlayerProvider> currentParent = [overlay parentResponder];
        [DownloadMenuHelper showDownloadSheetShorts:inlinePlayer ? currentParent : [currentParent player] withSender:sender];
    }
}
// Same filtering order in 0x98710, 0x99070, 0x999d8 and block 0xca6ac.
static BOOL ShortsRemoveModel(id<YTLShortsModel> model) {
    if ([model respondsToSelector:@selector(videoType)]) {
        if (ytpBool(@"noAds") && [model videoType] == 3) return YES;
        if (ytpBool(@"removeShortsPosts") && [model videoType] == 10) return YES;
    }
    if ([model respondsToSelector:@selector(presentation)]) {
        if (ytpBool(@"noAds") && [[model presentation] type] == 4) return YES;
        if (ytpBool(@"removeShortsPosts") && [[model presentation] type] == 5) return YES;
        if (ytpBool(@"removeShortsLive") && ([[model presentation] type] == 3 || [[model presentation] type] == 7)) return YES;
    }
    // Availability deliberately checks the selector without the "is" prefix.
    if ([model respondsToSelector:@selector(livePreviewVideo)] && ytpBool(@"removeShortsLive") && [model isLivePreviewVideo]) return YES;
    if ([model respondsToSelector:@selector(liveVideo)] && ytpBool(@"removeShortsLive") && [model isLiveVideo]) return YES;
    return NO;
}
static void ShortsShowSpeed(double rate, id player) {
    [YTPSpeedMaster setPlaybackRate:rate forPlayer:player];
    [[PlayerToast sharedToast] showPlayerToastWithText:ShortsText(@"Toast.PlaybackSpeed") value:rate style:1 isCompact:ytpBool(@"compactToast")];
}

%group YTLShortsInterface
%hook YTReelWatchPlaybackOverlayViewSub
- (void)layoutSubviews { %orig; ShortsLayoutActionButton(self); }
%new
- (void)didTapYtlButton:(id)sender { ShortsDownload(self, sender, NO); }
%end
%hook YTReelWatchPlaybackOverlayView
- (void)layoutSubviews { %orig; ShortsLayoutActionButton(self); }
- (void)setActionBarElementRenderer:(uintptr_t)renderer {
    %orig;
    if (ytpBool(@"downloadManager")) {
        if (class_getInstanceVariable([self class], "_actionBarComponentView")) {
            UIView *view = [self valueForKey:@"_actionBarComponentView"];
            if (view) ShortsAddButton(self, view, YES);
        }
        if (class_getInstanceVariable([self class], "_actionBarView")) {
            UIView *view = [self valueForKey:@"_actionBarView"];
            if (view) ShortsAddButton(self, view, YES);
        }
    }
}
- (void)setReelLikeButton:(UIView *)button {
    %orig;
    if (ytpBool(@"downloadManager") && !button.hidden && button) ShortsAddButton(self, button, YES);
}
%new
- (void)didTapYtlButton:(id)sender { ShortsDownload(self, sender, NO); }
%end
%hook YTInlineMutedPlaybackShortsPlayerOverlayView
- (void)layoutSubviews {
    %orig;
    if (!ytpBool(@"downloadManager")) return;
    id parent = [self parentResponder];
    static Class playerClass, assetClass;
    if (!playerClass) playerClass = NSClassFromString(@"YTPlayerViewController");
    if (![parent isKindOfClass:playerClass]) return;
    if (!assetClass) assetClass = NSClassFromString(@"YTAssetLoader");
    YTAssetLoader *loader = [[assetClass alloc] initWithBundle:[NSBundle ytl_defaultBundle]];
    UIImage *icon = [YTLHelper resizeImage:[loader imageNamed:@"ytl_icon"] toSize:20];
    YTQTMButton *button = (id)[YTLHelper createYTQTMButton:self accessibilityLabel:ShortsText(@"ShortsYTLButton") buttonLabel:nil icon:icon selector:@selector(didTapYtlButton:)];
    ShortsStyleButton(button);
    if (![self viewWithTag:999]) {
        [self addSubview:button];
        [button.leadingAnchor constraintEqualToAnchor:self.leadingAnchor].active = YES;
        [button.topAnchor constraintEqualToAnchor:self.topAnchor].active = YES;
        [button.widthAnchor constraintEqualToConstant:32].active = YES;
        [button.heightAnchor constraintEqualToConstant:32].active = YES;
    }
}
%new
- (void)didTapYtlButton:(id)sender { ShortsDownload(self, sender, YES); }
%end
%hook YTReelContentModel
+ (id)makeContentModelForEntry:(uintptr_t)entry { id model = %orig; return ShortsRemoveModel(model) ? nil : model; }
%end
%hook YTReelDataSource
- (id)makeContentModelForEntry:(uintptr_t)entry { id model = %orig; return ShortsRemoveModel(model) ? nil : model; }
%end
%hook YTReelInfinitePlaybackDataSource
- (id)makeContentModelForEntry:(uintptr_t)entry { id model = %orig; return ShortsRemoveModel(model) ? nil : model; }
- (NSArray *)reels {
    BOOL hasFactory = [self respondsToSelector:@selector(makeContentModelForEntry:)];
    NSArray *reels = %orig;
    if (hasFactory) return reels;
    NSMutableArray *filtered = [reels mutableCopy];
    NSIndexSet *indexes = [filtered indexesOfObjectsPassingTest:^BOOL(id model, NSUInteger index, BOOL *stop) { return ShortsRemoveModel(model); }];
    if (indexes.count) [filtered removeObjectsAtIndexes:indexes];
    return [filtered copy];
}
%end
%hook YTShortsStartupCoordinator
- (id)evaluateResumeToShorts { return nil; }
%end
%hook YTReelHeaderView
- (void)setTitleLabelVisible:(BOOL)visible animated:(BOOL)animated { %orig(visible & !ytpBool(@"hideShortsLogo"), animated); }
- (void)addView:(UIView *)view toStackView:(id)stack withSize:(CGSize)size {
    static Class buttonClass;
    if (!buttonClass) buttonClass = NSClassFromString(@"YTQTMButton");
    if ([view isKindOfClass:buttonClass]) {
        NSDictionary *hidden = @{@1045:@(ytpBool(@"hideShortsSearch")), @1046:@(ytpBool(@"hideShortsCamera")), @1047:@(ytpBool(@"hideShortsMore"))};
        if ([hidden[@([[(YTQTMButton *)view buttonRenderer] icon].iconType)] boolValue]) return;
    }
    %orig;
}
%end
%hook YTReelWatchHeaderView
- (void)setChannelBarElementRenderer:(id)value { if (!ytpBool(@"hideShortsChannelName")) %orig; }
- (void)setHeaderRenderer:(id)value { if (!ytpBool(@"hideShortsDescription")) %orig; }
- (void)setShortsVideoTitleElementRenderer:(id)value { if (!ytpBool(@"hideShortsDescription")) %orig; }
- (void)setSoundMetadataElementRenderer:(id)value { if (!ytpBool(@"hideShortsAudioTrack")) %orig; }
- (void)setActionElement:(id)value { if (!ytpBool(@"hideShortsPromoCards")) %orig; }
- (void)setBadgeRenderer:(id)value { if (!ytpBool(@"hideShortsThanks")) %orig; }
- (void)setMultiFormatLinkElementRenderer:(id)value { if (!ytpBool(@"hideShortsSource")) %orig; }
%end
%hook YTReelContentView
- (void)setPlaybackView:(uintptr_t)view {
    %orig;
    [self playbackOverlay].alpha = isOverlayShown ? 1 : 0;
    if (ytpBool(@"shortsOnlyMode")) {
        UILongPressGestureRecognizer *exitGesture = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(turnShortsOnlyModeOff:)];
        exitGesture.numberOfTouchesRequired = 2;
        exitGesture.minimumPressDuration = 0.5;
        [self addGestureRecognizer:exitGesture];
    }
    DVNLongPressDelegate *delegate = [DVNLongPressDelegate new];
    delegate.view = self;
    delegate.mode = ytpInt(@"shortsSpeedIndex");
    UILongPressGestureRecognizer *speed = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(reelSpeedmaster:)];
    speed.numberOfTouchesRequired = 1;
    speed.minimumPressDuration = 0.3;
    speed.delegate = delegate;
    objc_setAssociatedObject(self, @selector(reelSpeedmaster:), delegate, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self addGestureRecognizer:speed];
}
%new
- (void)reelSpeedmaster:(UILongPressGestureRecognizer *)gesture {
    DVNLongPressDelegate *delegate = (id)gesture.delegate;
    CGPoint point = [gesture locationInView:self];
    if (!delegate || ![delegate isTouchInSpeedZone:point]) return;
    id player = [[self delegate] player];
    if (gesture.state == UIGestureRecognizerStateBegan) ShortsShowSpeed(2, player);
    if (gesture.state == UIGestureRecognizerStateEnded || gesture.state == UIGestureRecognizerStateCancelled) {
        if ([PlayerToast sharedToast].alpha == 0) {
            @throw [NSException exceptionWithName:@"YouTubePlusException" reason:@"Attempt to hide the toast outside of YouTube Plus detected." userInfo:nil];
        }
        ShortsShowSpeed(1, player);
        [[PlayerToast sharedToast] hideToast];
    }
}
- (void)dealloc {
    if ([PlayerToast sharedToast].alpha == 1) {
        ShortsShowSpeed(1, [[self delegate] player]);
        [[PlayerToast sharedToast] hideToast];
    }
    %orig;
}
%new
- (void)turnShortsOnlyModeOff:(UILongPressGestureRecognizer *)gesture {
    if (gesture.state == UIGestureRecognizerStateBegan) {
        [[YTLUserDefaults standardUserDefaults] setBool:NO forKey:@"shortsOnlyMode"];
        dispatch_async(dispatch_get_main_queue(), ^{ [ToastManager showMessageWithText:ShortsText(@"ShortsModeTurnedOff") isSuccess:YES]; });
        UIWindow *window = [[[UIApplication sharedApplication] delegate] window];
        [window.rootViewController performSelector:@selector(showPivotBar) withObject:nil afterDelay:1.0];
    }
}
%end
%hook YTReelWatchRootViewController
- (void)viewDidAppear:(BOOL)animated { %orig; if (ytpBool(@"shortsOnlyMode")) [[self.navigationController parentViewController] hidePivotBar]; }
%end
%end
void YTLInstallShortsInterfaceHooks(void) { %init(YTLShortsInterface); }
