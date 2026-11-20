#import "PlayerControlsHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Helpers/YTLHelper.h"
#import "../Controls/YTPSpeedMaster.h"
#import "../Controls/YTPSpeedPopupController.h"
#import "../Downloads/DownloadMenuHelper.h"
#import "../Downloads/YTPMedia.h"
#import "../Downloads/YTPAPIHelper.h"
#import "../SleepTimer/YTPSleepTimer.h"
#import "../Presentation/ToastView.h"
#import "../Presentation/ToastWindow.h"
#import "../Presentation/ToastManager.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
static NSString *ControlsLocalized(NSString *key) { return [NSBundle.ytl_defaultBundle localizedStringForKey:key value:nil table:nil]; }
static id<YTLControlsController> ControlsController(YTMainAppControlsOverlayView *view) {
    id<YTLControlsController> controller = view._viewControllerForAncestor;
    if (![(id)controller isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")]) controller = view.eventsDelegate;
    return controller;
}
static char ControlsKey_speedControls;
static char ControlsKey_ytlButtons;
static char ControlsKey_speedMinus;
static char ControlsKey_speedPlus;
static char ControlsKey_speedValue;
static char ControlsKey_ytlButton;
static char ControlsKey_ytlMuteButton;
static char ControlsKey_ytlLockButton;
static char ControlsKey_ytlSleepButton;
static char ControlsKey_ytlDiscordButton;
static char ControlsKey_ytlSbButton;
static char ControlsKey_ytlButtonsTopAnchor;
static char ControlsKey_ytlButtonsTrailingAnchor;
static char ControlsKey_ytlButtonsFSTopAnchor;
static char ControlsKey_ytlButtonsFSTrailingAnchor;
%group YTLPlayerControls
%hook YTMainAppControlsOverlayView
%new
- (UIStackView *)speedControls { return objc_getAssociatedObject(self, &ControlsKey_speedControls); }
%new
- (void)setSpeedControls:(UIStackView *)value { objc_setAssociatedObject(self, &ControlsKey_speedControls, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIStackView *)ytlButtons { return objc_getAssociatedObject(self, &ControlsKey_ytlButtons); }
%new
- (void)setYtlButtons:(UIStackView *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButtons, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)speedMinus { return objc_getAssociatedObject(self, &ControlsKey_speedMinus); }
%new
- (void)setSpeedMinus:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_speedMinus, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)speedPlus { return objc_getAssociatedObject(self, &ControlsKey_speedPlus); }
%new
- (void)setSpeedPlus:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_speedPlus, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)speedValue { return objc_getAssociatedObject(self, &ControlsKey_speedValue); }
%new
- (void)setSpeedValue:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_speedValue, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlButton { return objc_getAssociatedObject(self, &ControlsKey_ytlButton); }
%new
- (void)setYtlButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlMuteButton { return objc_getAssociatedObject(self, &ControlsKey_ytlMuteButton); }
%new
- (void)setYtlMuteButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlMuteButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlLockButton { return objc_getAssociatedObject(self, &ControlsKey_ytlLockButton); }
%new
- (void)setYtlLockButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlLockButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlSleepButton { return objc_getAssociatedObject(self, &ControlsKey_ytlSleepButton); }
%new
- (void)setYtlSleepButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlSleepButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlDiscordButton { return objc_getAssociatedObject(self, &ControlsKey_ytlDiscordButton); }
%new
- (void)setYtlDiscordButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlDiscordButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (UIButton *)ytlSbButton { return objc_getAssociatedObject(self, &ControlsKey_ytlSbButton); }
%new
- (void)setYtlSbButton:(UIButton *)value { objc_setAssociatedObject(self, &ControlsKey_ytlSbButton, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (NSLayoutConstraint *)ytlButtonsTopAnchor { return objc_getAssociatedObject(self, &ControlsKey_ytlButtonsTopAnchor); }
%new
- (void)setYtlButtonsTopAnchor:(NSLayoutConstraint *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButtonsTopAnchor, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (NSLayoutConstraint *)ytlButtonsTrailingAnchor { return objc_getAssociatedObject(self, &ControlsKey_ytlButtonsTrailingAnchor); }
%new
- (void)setYtlButtonsTrailingAnchor:(NSLayoutConstraint *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButtonsTrailingAnchor, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (NSLayoutConstraint *)ytlButtonsFSTopAnchor { return objc_getAssociatedObject(self, &ControlsKey_ytlButtonsFSTopAnchor); }
%new
- (void)setYtlButtonsFSTopAnchor:(NSLayoutConstraint *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButtonsFSTopAnchor, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%new
- (NSLayoutConstraint *)ytlButtonsFSTrailingAnchor { return objc_getAssociatedObject(self, &ControlsKey_ytlButtonsFSTrailingAnchor); }
%new
- (void)setYtlButtonsFSTrailingAnchor:(NSLayoutConstraint *)value { objc_setAssociatedObject(self, &ControlsKey_ytlButtonsFSTrailingAnchor, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
- (instancetype)initWithDelegate:(id)delegate {
    YTMainAppControlsOverlayView *view = %orig;
    view.speedPlus = [YTLHelper createYTQTMButton:view accessibilityLabel:ControlsLocalized(@"SpeedButton") buttonLabel:nil icon:[UIImage systemImageNamed:@"plus"] selector:@selector(speedValuePlus:)];
    view.speedMinus = [YTLHelper createYTQTMButton:view accessibilityLabel:ControlsLocalized(@"SpeedButton") buttonLabel:nil icon:[UIImage systemImageNamed:@"minus"] selector:@selector(speedValueMinus:)];
    view.speedValue = [YTLHelper createYTQTMButton:view accessibilityLabel:ControlsLocalized(@"SpeedButton") buttonLabel:[NSString stringWithFormat:@"%@×", @((float)[YTPSpeedMaster currentPlaybackRate])] icon:nil selector:@selector(resetSpeedValue:)];
    UILongPressGestureRecognizer *press = [[UILongPressGestureRecognizer alloc] initWithTarget:view action:@selector(showSpeedControl:)];
    press.minimumPressDuration = 0.4;
    [view.speedValue addGestureRecognizer:press];
    [NSNotificationCenter.defaultCenter addObserver:view selector:@selector(speedDidChange:) name:@"YTPSpeedDidChange" object:nil];
    view.speedControls = [[UIStackView alloc] initWithArrangedSubviews:@[view.speedPlus, view.speedValue, view.speedMinus]];
    view.speedControls.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:(double)(float)0.3];
    view.speedControls.axis = UILayoutConstraintAxisVertical;
    view.speedControls.distribution = UIStackViewDistributionFillEqually;
    view.speedControls.alignment = UIStackViewAlignmentCenter;
    view.speedControls.clipsToBounds = YES;
    view.speedControls.layer.cornerRadius = 20;
    view.speedControls.tag = 999;
    view.speedControls.translatesAutoresizingMaskIntoConstraints = NO;
    [view addSubview:view.speedControls];
    [view.speedControls.centerYAnchor constraintEqualToAnchor:view.centerYAnchor].active = YES;
    [view.speedControls.leadingAnchor constraintEqualToAnchor:view.safeAreaLayoutGuide.leadingAnchor constant:10].active = YES;
    view.ytlButtons = [UIStackView new];
    view.ytlButtons.axis = UILayoutConstraintAxisHorizontal;
    view.ytlButtons.distribution = UIStackViewDistributionFillEqually;
    view.ytlButtons.alignment = UIStackViewAlignmentCenter;
    view.ytlButtons.spacing = 10;
    view.ytlButtons.translatesAutoresizingMaskIntoConstraints = NO;
    view.ytlButtons.tag = 998;
    view.ytlButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLButton") buttonLabel:nil icon:[YTPMedia ytPlus] selector:@selector(handleYTLIconTap:)];
    view.ytlMuteButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLMuteButton") buttonLabel:nil icon:[YTPMedia volumeOn] selector:@selector(handleYTLMuteTap:)];
    view.ytlLockButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLLockButton") buttonLabel:nil icon:[YTPMedia lock] selector:@selector(handleYTLLockTap:)];
    view.ytlSbButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLSbButton") buttonLabel:nil icon:[YTPMedia sponsorblock] selector:@selector(handleYTLSbTap:)];
    view.ytlSleepButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLSleepButton") buttonLabel:nil icon:[YTPMedia moon] selector:@selector(handleYTLSleepTap:)];
    view.ytlDiscordButton = [YTLHelper createOverlayButton:view accessibilityLabel:ControlsLocalized(@"YTLDiscordButton") buttonLabel:nil icon:[YTPMedia adaptiveDiscord] selector:@selector(handleYTLDiscordTap:)];
    if (view.topControlsAccessibilityContainerView && ![view viewWithTag:998]) {
        [view addSubview:view.ytlButtons];
        [view.ytlButtons addArrangedSubview:view.ytlMuteButton];
        [view.ytlButtons addArrangedSubview:view.ytlLockButton];
        [view.ytlButtons addArrangedSubview:view.ytlSleepButton];
        [view.ytlButtons addArrangedSubview:view.ytlDiscordButton];
        [view.ytlButtons addArrangedSubview:view.ytlSbButton];
        [view.ytlButtons addArrangedSubview:view.ytlButton];
        view.ytlButtonsTopAnchor = [view.ytlButtons.topAnchor constraintEqualToAnchor:view.topControlsAccessibilityContainerView.bottomAnchor];
        view.ytlButtonsTrailingAnchor = [view.ytlButtons.trailingAnchor constraintEqualToAnchor:view.topControlsAccessibilityContainerView.trailingAnchor];
        view.ytlButtonsFSTopAnchor = [view.ytlButtons.topAnchor constraintEqualToAnchor:view.topControlsAccessibilityContainerView.topAnchor];
        view.ytlButtonsFSTrailingAnchor = [view.ytlButtons.trailingAnchor constraintEqualToAnchor:view.topControlsAccessibilityContainerView.leadingAnchor constant:-10];
        view.ytlButtonsTopAnchor.active = YES;
        view.ytlButtonsTrailingAnchor.active = YES;
    }
    return view;
}
- (void)layoutSubviews {
    %orig;
    if (ytpBool(@"hideOverlayTitle")) self.titleView.alpha = 0;
    self.speedControls.hidden = !ytpBool(@"speedControls");
    if (!self.topControlsAccessibilityContainerView || ![self viewWithTag:998]) return;
    self.ytlMuteButton.hidden = !ytpBool(@"ytlMuteButton");
    self.ytlLockButton.hidden = !ytpBool(@"ytlLockButton");
    self.ytlSleepButton.hidden = ytpInt(@"ytlSleepTimerIndex") != 1 && ytpInt(@"ytlSleepTimerIndex") != 3;
    self.ytlDiscordButton.hidden = !ytpBool(@"rpcOverlayButton");
    self.ytlSbButton.hidden = !ytpBool(@"sponsorBlock") || !ytpBool(@"sbPlayerButton");
    self.ytlButton.hidden = !ytpBool(@"downloadManager") || ytpInt(@"ytlButtonIndex") == 0;
    self.ytlButtons.hidden = [self.ytlButtons.arrangedSubviews filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"hidden == NO"]].count == 0;
    id<YTLControlsController> controller = self._viewControllerForAncestor;
    if (![controller respondsToSelector:@selector(isFullscreen)] || ![controller respondsToSelector:@selector(statusBarOrientation)]) return;
    BOOL portraitFullscreen = controller.isFullscreen && (controller.statusBarOrientation == 1 || controller.statusBarOrientation == 2);
    self.ytlButtonsTopAnchor.active = !portraitFullscreen;
    self.ytlButtonsTrailingAnchor.active = !portraitFullscreen;
    self.ytlButtonsFSTopAnchor.active = portraitFullscreen;
    self.ytlButtonsFSTrailingAnchor.active = portraitFullscreen;
    [self layoutIfNeeded];
}
%new
- (void)speedValueMinus:(id)sender {
    [self.eventsDelegate resetAutoHideTimer];
    id player = self._viewControllerForAncestor.parentViewController;
    double rate = [YTPSpeedMaster playbackRateForPlayer:player];
    // FCMP/HI also takes the unordered (NaN) branch.
    if (!(rate <= 0.25)) [YTPSpeedMaster setPlaybackRate:(double)(float)(rate - 0.25) forPlayer:player];
}
%new
- (void)speedValuePlus:(id)sender {
    [self.eventsDelegate resetAutoHideTimer];
    id player = self._viewControllerForAncestor.parentViewController;
    double rate = [YTPSpeedMaster playbackRateForPlayer:player];
    // FCMP/LT also takes the unordered (NaN) branch.
    if (!(rate >= 5)) [YTPSpeedMaster setPlaybackRate:(double)(float)(rate + 0.25) forPlayer:player];
}
%new
- (void)resetSpeedValue:(id)sender {
    id<YTLControlsController> delegate = self.eventsDelegate;
    [delegate resetAutoHideTimer];
    [delegate setPlaybackRate:1];
    [self.speedValue setTitle:@"1×" forState:0];
}
%new
- (void)speedDidChange:(NSNotification *)notification {
    float rate = [notification.object floatValue];
    [self.speedValue setTitle:[NSString stringWithFormat:@"%@×", @(rate)] forState:0];
}
%new
- (void)showSpeedControl:(UILongPressGestureRecognizer *)gesture {
    if (gesture.state == 1 && ytpBool(@"speedControls")) [[YTPSpeedPopupController speedController] presentFromViewController:self._viewControllerForAncestor];
}
%new
- (void)handleYTLIconTap:(id)sender { [DownloadMenuHelper showDownloadSheet:ControlsController(self).parentViewController withSender:sender]; }
%new
- (void)handleYTLMuteTap:(UIButton *)sender {
    id<YTLControlsVideo> video = ControlsController(self).parentViewController.activeVideo;
    BOOL muted = video.isMuted;
    [video setMuted:!muted];
    [sender setImage:muted ? [YTPMedia volumeOn] : [YTPMedia volumeOff] forState:0];
}
%new
- (void)handleYTLLockTap:(id)sender {
    id<YTLControlsController> controller = ControlsController(self);
    if (controller.lockModeStateEntityController) {
        [controller lockModeDidRequestShowFullscreen];
        [controller.lockModeStateEntityController setLockModeActive:YES];
    }
}
%new
- (void)handleYTLSleepTap:(UIView *)sender { [[YTPSleepTimer sharedTimer] showOptions:sender]; }
%new
- (void)handleYTLSbTap:(UIView *)sender {
    UIViewController<YTLControlsPlayer> *player = ControlsController(self).parentViewController;
    if (![player isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) return;
    id<YTLControlsResponse> response = nil;
    if ([player respondsToSelector:@selector(playerResponse)]) response = player.playerResponse;
    else if ([player respondsToSelector:@selector(contentPlayerResponse)]) response = player.contentPlayerResponse;
    if (!response) return;
    NSString *channelID = response.playerData.videoDetails.channelId;
    NSString *author = response.playerData.videoDetails.author;
    NSString *title = response.playerData.videoDetails.title;
    NSMutableDictionary *whitelist = [[YTLUserDefaults.standardUserDefaults objectForKey:@"sbWhitelist"] mutableCopy];
    if (!whitelist) whitelist = [NSMutableDictionary dictionary];
    BOOL listed = whitelist[channelID] != nil;
    id<YTLControlsSheet> sheet = [(Class<YTLControlsSheet>)NSClassFromString(@"YTDefaultSheetController") sheetControllerWithMessage:author subMessage:title delegate:nil parentResponder:nil];
    [(id<YTLControlsSheetHeader>)[(id)sheet valueForKey:@"_headerView"] showHeaderDivider];
    id<YTLControlsImage> chevron = [(Class<YTLControlsResources>)NSClassFromString(@"YTUIResources") chevronRightImage];
    [chevron setFlipsForRightToLeftLayoutDirection:YES];
    id action = [(Class<YTLControlsAction>)NSClassFromString(@"YTActionSheetAction") actionWithTitle:ControlsLocalized(listed ? @"SbRemoveFromWhitelist" : @"SbAddToWhitelist") iconImage:[YTPMedia imageWithName:@"star_half"] secondaryIconImage:[YTPMedia imageWithName:listed ? @"box_checkmark" : @"box_empty"] accessibilityIdentifier:nil handler:^(YTActionSheetAction *action) {
        if (listed) {
            [whitelist removeObjectForKey:channelID];
            [YTLUserDefaults.standardUserDefaults setObject:whitelist forKey:@"sbWhitelist"];
        } else {
            NSMutableDictionary *entry = [NSMutableDictionary dictionary];
            entry[@"name"] = author;
            entry[@"link"] = [NSString stringWithFormat:@"vnd.youtube://www.youtube.com/channel/%@", channelID];
            entry[@"date"] = @([NSDate.date timeIntervalSince1970]);
            [YTPAPIHelper fetchChannelImageWithChannelID:channelID completion:^(NSURL *url) {
                if (url) {
                    NSData *data = [NSData dataWithContentsOfURL:url];
                    if (data) entry[@"pfp"] = data;
                }
                whitelist[channelID] = entry;
                [YTLUserDefaults.standardUserDefaults setObject:whitelist forKey:@"sbWhitelist"];
                dispatch_async(dispatch_get_main_queue(), ^{ [ToastManager showMessageWithText:ControlsLocalized(@"Sb.Whitelisted") isSuccess:YES]; });
            }];
        }
    }];
    [sheet addAction:action];
    [sheet setSourceView:sender];
    [sheet presentFromViewController:ToastView.toastWindow.rootViewController animated:YES completion:nil];
}
- (void)setAutoplaySwitchButtonRenderer:(id)renderer { if (!ytpBool(@"hideAutoplay")) %orig; }
- (void)setClosedCaptionsOrSubtitlesButtonAvailable:(BOOL)available { BOOL hide = ytpBool(@"hideSubs"); %orig(available && !hide); }
- (void)setOverlayVisible:(BOOL)visible {
    if ((ytpBool(@"downloadManager") && ytpInt(@"ytlButtonIndex")) || ytpBool(@"ytlMuteButton") || ytpBool(@"ytlLockButton")) self.ytlButtons.alpha = visible;
    if (ytpBool(@"speedControls")) {
        self.speedControls.alpha = visible;
        [self.speedValue setTitle:[NSString stringWithFormat:@"%@×", @((float)[YTPSpeedMaster currentPlaybackRate])] forState:0];
    }
    %orig;
    if (ytpBool(@"pauseOnOverlay") && [self._viewControllerForAncestor.parentViewController isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) {
        id<YTLControlsPlayer> player = (id)self._viewControllerForAncestor.parentViewController;
        if (visible) [player pause]; else [player play];
    }
}
- (id)playbackRouteButton {
    if (ytpBool(@"noCast")) { [self setValue:nil forKey:@"_playbackRouteButton"]; return nil; }
    return %orig;
}
- (void)dealloc { [NSNotificationCenter.defaultCenter removeObserver:self]; %orig; }
%end
%end
void YTLInstallPlayerControlsHooks(void) {
    Class cls = NSClassFromString(@"YTMainAppControlsOverlayView");
    const objc_property_attribute_t stack[] = {{"T", "@\"UIStackView\""}, {"&", ""}, {"N", ""}};
    const objc_property_attribute_t button[] = {{"T", "@\"YTQTMButton\""}, {"&", ""}, {"N", ""}};
    const objc_property_attribute_t constraint[] = {{"T", "@\"NSLayoutConstraint\""}, {"&", ""}, {"N", ""}};
    class_addProperty(cls, "speedControls", stack, 3);
    class_addProperty(cls, "ytlButtons", stack, 3);
    class_addProperty(cls, "speedMinus", button, 3);
    class_addProperty(cls, "speedPlus", button, 3);
    class_addProperty(cls, "speedValue", button, 3);
    class_addProperty(cls, "ytlButton", button, 3);
    class_addProperty(cls, "ytlMuteButton", button, 3);
    class_addProperty(cls, "ytlLockButton", button, 3);
    class_addProperty(cls, "ytlSleepButton", button, 3);
    class_addProperty(cls, "ytlDiscordButton", button, 3);
    class_addProperty(cls, "ytlSbButton", button, 3);
    class_addProperty(cls, "ytlButtonsTopAnchor", constraint, 3);
    class_addProperty(cls, "ytlButtonsTrailingAnchor", constraint, 3);
    class_addProperty(cls, "ytlButtonsFSTopAnchor", constraint, 3);
    class_addProperty(cls, "ytlButtonsFSTrailingAnchor", constraint, 3);
    %init(YTLPlayerControls);
}
