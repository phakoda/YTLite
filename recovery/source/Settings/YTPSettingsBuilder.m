#import "YTPSettingsBuilder.h"
#import "SettingsContracts.h"
#import "TabbarVC.h"
#import "DVNSupportersVC.h"
#import "../Support/YTPDB.h"
#import <QuartzCore/QuartzCore.h>

// Helpers only factor repeated, unconditional construction. They do not cache
// cells, providers, localization, defaults, or host objects. The four sections
// originally built by addCells: retain their distinct identifier-stamping path.
static NSString *SettingsL(NSString *key) { return [key ytl_localized]; }
static UIImage *SettingsImage(NSString *name) {
    return [(Class<YTLSettingsMedia>)NSClassFromString(@"YTPMedia") imageWithName:name];
}
static UIImage *SettingsOriginalImage(NSString *name) {
    return [NSBundle.ytl_defaultBundle originalImageWithName:name];
}
static DVNTableModel *SettingsSearchableModel(NSString *title) {
    DVNTableModel *model = [DVNTableModel modelWithTitle:SettingsL(title) sections:nil];
    model.supportsSearching = YES;
    return model;
}
static DVNCell *SettingsSwitch(NSString *title, NSString *key) {
    return [DVNCell cellWithTitle:SettingsL(title) subtitle:SettingsL([title stringByAppendingString:@"Desc"]) type:0 key:key];
}
static NSArray *SettingsSwitches(NSArray<NSArray<NSString *> *> *rows) {
    NSMutableArray *cells = [NSMutableArray array];
    for (NSArray *row in rows) [cells addObject:SettingsSwitch(row[0], row[1])];
    return cells;
}
static NSArray *SettingsLocalizedOptions(NSArray<NSString *> *keys) {
    NSMutableArray *result = [NSMutableArray array];
    for (NSString *key in keys) [result addObject:SettingsL(key)];
    return result;
}
static DVNCell *SettingsSegment(NSArray *items, NSString *key) {
    return [DVNCell cellWithTitleIndexes:items key:key];
}
static DVNCell *SettingsMenu(NSString *title, NSArray *items, NSString *key) {
    return [DVNCell cellWithTitle:SettingsL(title) subtitle:SettingsL([title stringByAppendingString:@"Desc"])
                    titleIndexes:items type:3 key:key];
}
static DVNCell *SettingsColor(NSString *title, NSString *key) {
    return [DVNCell cellWithTitle:SettingsL(title) subtitle:nil type:8 key:key];
}
static DVNCell *SettingsSlider(double minimum, double maximum, double divider, NSInteger format, NSString *key) {
    return [DVNCell sliderCellWithMinimum:minimum maximum:maximum divider:divider format:format key:key];
}
static DVNSection *SettingsSection(NSString *identifier, NSString *header, NSArray *cells) {
    return [DVNSection sectionWithHeader:SettingsL(header) cells:cells identifier:identifier];
}
static DVNSection *SettingsPlainSection(NSString *identifier, NSArray *cells) {
    return [DVNSection sectionWithCells:cells identifier:identifier];
}
static DVNSection *SettingsFooterSection(NSString *identifier, NSString *header, NSString *footer, NSArray *cells) {
    return [DVNSection sectionWithHeader:SettingsL(header) footer:SettingsL(footer) cells:cells identifier:identifier];
}
static DVNCell *SettingsController(DVNTableModel *model, NSString *title, NSString *icon) {
    return [DVNCell controllerCellWithModel:model title:SettingsL(title) subtitle:nil icon:SettingsImage(icon)];
}
static DVNCell *SettingsLink(YTPSettingsBuilder *builder, NSString *title, NSString *subtitle,
                            NSString *icon, NSString *url) {
    return [DVNCell cellWithTitle:title subtitle:subtitle icon:SettingsImage(icon) accessoryIcon:SettingsImage(@"open_new")
                            type:5 handler:(DVNStoredBlock)^{ [builder openURL:url]; }];
}
static void SettingsToast(NSString *key, BOOL success) {
    [(Class<YTLSettingsToast>)NSClassFromString(@"ToastManager") showMessageWithText:SettingsL(key) isSuccess:success];
}

@implementation YTPSettingsBuilder
@synthesize presenter = _presenter;

// 0x138f34. Literal root title and version are not localization keys.
- (DVNTableModel *)rootTable {
    DVNTableModel *model = [DVNTableModel modelWithTitle:@"YTLite" sections:nil];
    model.supportsSearching = YES;
    model.footer = [NSString stringWithFormat:@"YouTube Plus: %@ • YouTube: %@", @"5.2.2-local",
                    NSBundle.mainBundle.infoDictionary[@"CFBundleShortVersionString"]];
    model.footerFont = [UIFont systemFontOfSize:14 weight:UIFontWeightLight];
    model.footerAlignment = NSTextAlignmentNatural;
    // This fork has no account, subscription, activation or sign-in section.
    [model addSection:[DVNSection sectionWithHeader:SettingsL(@"Main") footer:nil cells:@[
        SettingsController([self downloadingTable], @"Downloading", @"downloading"),
        SettingsController([self navbarTable], @"Navbar", @"navbar"),
        SettingsController([self feedTable], @"Feed", @"feed"),
        SettingsController([self playerTable], @"Player", @"player"),
        SettingsController([self shortsTable], @"Shorts", @"FEshorts"),
        SettingsController([self tabBarTable], @"Tabbar", @"tabbar"),
        SettingsController([self interfaceTable], @"Interface", @"interface")
    ] identifier:@"mainCell"]];
    [model addSection:SettingsPlainSection(@"additionalCell", @[
        SettingsController([self sbTable], @"SponsorBlock", @"sponsorblock"),
        SettingsController([self rpcTable], @"DiscordRPC", @"discord")
    ])];
    // Local UI preference: omit the developer/promotional section.
    [model addSection:[self creditsSection]];
    return model;
}

// 0x13aa40.
- (DVNTableModel *)downloadingTable {
    DVNTableModel *model = SettingsSearchableModel(@"Downloading");
    [model addSections:@[
        SettingsSection(@"downloadingCell", @"Downloading", SettingsSwitches(@[
            @[@"DownloadManager",@"downloadManager"], @[@"PostManager",@"postManager"],
            @[@"SaveProfilePhoto",@"saveProfilePhoto"], @[@"CommentManager",@"commentManager"]])),
        SettingsSection(@"positionCell", @"YtlButtonPosition", @[
            SettingsSegment(SettingsLocalizedOptions(@[@"UnderPlayer",@"Overlay",@"Both"]), @"ytlButtonIndex")]),
        SettingsFooterSection(@"behaviorCell", @"PostDownloadAction", @"PostDownloadDesc", @[
            SettingsSegment(SettingsLocalizedOptions(@[@"SaveToPhotos",@"Share",@"Ask"]), @"postDownloadIndex")]),
        SettingsSection(@"tracksCell", @"PreferredAudio", @[
            SettingsSegment(SettingsLocalizedOptions(@[@"Default",@"Selected",@"English",@"Ask"]), @"ytlAudioIndex")]),
        SettingsSection(@"audioCell", @"Audios", @[SettingsSwitch(@"AudioDRC", @"preferDrc")]),
        SettingsSection(@"captionsCell", @"CaptionsAndThumbnails", SettingsSwitches(@[
            @[@"EmbedThumbnailsToVideos",@"embedThumbnails"], @[@"EmbedCapsToVideos",@"downloadWithCaps"],
            @[@"EmbedAutoGenCaps",@"addAutoCaps"]]))
    ]];
    return model;
}

// 0x13e384.
- (DVNTableModel *)navbarTable {
    DVNTableModel *model = SettingsSearchableModel(@"Navbar");
    NSMutableArray *cells = [SettingsSwitches(@[
        @[@"RemoveCast",@"noCast"], @[@"RemoveNotifications",@"noNotifsButton"],
        @[@"RemoveSearch",@"noSearchButton"], @[@"RemoveVoiceSearch",@"noVoiceSearchButton"],
        @[@"StickyNavbar",@"stickyNavbar"], @[@"NoSubbar",@"noSubbar"]]) mutableCopy];
    [cells addObject:SettingsMenu(@"LogoImage", @[SettingsL(@"Default"),@"Premium",@"YouTube",SettingsL(@"NoLogo")], @"logoIndex")];
    [model addSection:SettingsPlainSection(@"navbarCell", cells)];
    return model;
}

// 0x13fec0.
- (DVNTableModel *)feedTable {
    DVNTableModel *model = SettingsSearchableModel(@"Feed");
    [model addSection:SettingsPlainSection(@"feedCell", SettingsSwitches(@[
        @[@"RemoveAds",@"noAds"], @[@"HideShorts",@"hideShorts"], @[@"KeepSubsShorts",@"keepSubsShorts"],
        @[@"RemoveMoreTopics",@"hideMoreTopicsChip"], @[@"RemoveCommunityPosts",@"hideCommunityPosts"],
        @[@"RemoveMixPlaylists",@"hideMixPlaylists"], @[@"RemoveLiveVids",@"hideLiveInFeed"],
        @[@"RemoveHorizontalFeeds",@"hideHorizontalFeeds"], @[@"RemovePlayables",@"hidePlayables"]]))];
    return model;
}

// 0x14218c..0x156a94. Screen width/height are sampled separately (0x152884,
// 0x1528b8); fcmp/fcsel picks width only when width < height, including NaN behavior.
- (DVNTableModel *)playerTable {
    double width = UIScreen.mainScreen.bounds.size.width;
    double height = UIScreen.mainScreen.bounds.size.height;
    double dimension = width < height ? width : height;
    DVNTableModel *model = SettingsSearchableModel(@"Player");
    [model addSection:SettingsSection(@"qualityCell", @"Main", @[
        SettingsMenu(@"PlaybackQualityOnWiFi", @[SettingsL(@"Default"),SettingsL(@"Best"),@"2160p60",@"2160p",@"1440p60",@"1440p",@"1080p60",@"1080p",@"720p60",@"720p",@"480p",@"360p",@"240p",@"144p"], @"wiFiQualityIndex"),
        SettingsMenu(@"PlaybackQualityOnCellular", @[SettingsL(@"Default"),SettingsL(@"Best"),@"2160p60",@"2160p",@"1440p60",@"1440p",@"1080p60",@"1080p",@"720p60",@"720p",@"480p",@"360p",@"240p",@"144p"], @"cellQualityIndex")
    ])];
    [model addSection:SettingsSection(@"audioTrackCell", @"PreferredAudio", @[
        SettingsSegment(SettingsLocalizedOptions(@[@"Default",@"Original",@"Custom"]), @"audioTrackIndex"),
        SettingsMenu(@"CustomAudioTrack", [YTPDB supportedLanguages], @"customTrack"),
        SettingsSwitch(@"IgnoreAutoDub", @"ignoreAutoDub")
    ])];
    [model addSection:SettingsSection(@"captionsCell", @"PreferredCaptions", @[
        SettingsSegment(SettingsLocalizedOptions(@[@"Default",@"Disabled",@"Original",@"Custom"]), @"captionsIndex"),
        SettingsMenu(@"CustomCaptions", [YTPDB supportedLanguages], @"customCaption"),
        SettingsSwitch(@"AutoGenCaps", @"autoGenCaps")
    ])];
    DVNSection *interface = [DVNSection sectionWithIdentifier:@"playerInterfaceCell"];
    interface.header = SettingsL(@"Player.Interface");
    NSMutableArray *interfaceCells = [NSMutableArray arrayWithObject:
        SettingsMenu(@"SleepTimer", SettingsLocalizedOptions(@[@"Disabled",@"Overlay",@"Tabbar",@"Both"]), @"ytlSleepTimerIndex")];
    [interfaceCells addObjectsFromArray:SettingsSwitches(@[
        @[@"SpeedControls",@"speedControls"], @[@"MuteButton",@"ytlMuteButton"], @[@"LockButton",@"ytlLockButton"],
        @[@"HideOverlayTitle",@"hideOverlayTitle"], @[@"HideAutoplay",@"hideAutoplay"], @[@"HideSubs",@"hideSubs"],
        @[@"HidePrevNext",@"hidePrevNext"], @[@"ReplacePrevNext",@"replacePrevNext"], @[@"RememberLoopMode",@"rememberLoop"],
        @[@"PortraitFullscreen",@"portraitFullscreen"], @[@"ClassicQuality",@"classicQuality"], @[@"NoDarkBg",@"noDarkBg"],
        @[@"NoEndScreenCards",@"endScreenCards"], @[@"NoAutonavEndScreenCards",@"autonavEndScreenCards"],
        @[@"NoFullscreenActions",@"noFullscreenActions"], @[@"NoMoreVideosButton",@"noMoreVideos"],
        @[@"NoHudMsgs",@"noHudMsgs"], @[@"PersistentProgressBar",@"persistentProgressBar"], @[@"StockVolumeHUD",@"stockVolumeHUD"],
        @[@"NoRelatedVids",@"noRelatedVids"], @[@"NoPromotionCards",@"noPromotionCards"], @[@"NoWatermarks",@"noWatermarks"],
        @[@"DisableAmbientMode",@"disableAmbientMode"], @[@"VideoEndTime",@"videoEndTime"], @[@"24hrFormat",@"24hrFormat"],
        @[@"NoRelatedWatchNexts",@"noRelatedWatchNexts"], @[@"RemoveInlineComment",@"hideInlineComment"],
        @[@"NoSubUnderPlayer",@"noPlayerSubButton"], @[@"PlayerNoShare",@"playerNoShare"], @[@"PlayerNoThanks",@"playerNoThanks"],
        @[@"PlayerNoRemix",@"playerNoRemix"], @[@"PlayerNoDownload",@"playerNoDownload"], @[@"PlayerNoClip",@"playerNoClip"],
        @[@"PlayerNoSave",@"playerNoSave"], @[@"PlayerNoReport",@"playerNoReport"], @[@"PlayerNoHype",@"playerNoHype"],
        @[@"PlayerNoStopAds",@"playerNoStopAds"]])];
    [interface addCells:interfaceCells];
    [model addSection:interface];
    [model addSection:SettingsSection(@"progressBarCell", @"ProgressBarStyle", @[
        SettingsSegment(SettingsLocalizedOptions(@[@"Default",@"SolidColor",@"Gradient"]), @"progressBarIndex"),
        SettingsColor(@"MainColor", @"progressMainColor"), SettingsColor(@"GradientColor", @"progressGradientColor"),
        SettingsColor(@"ScrubberColor", @"scrubberColor")
    ])];
    NSMutableArray *behavior = [NSMutableArray arrayWithObject:
        SettingsMenu(@"DefaultPlaybackRate", @[@"0.25×",@"0.5×",@"0.75×",@"1.0×",@"1.25×",@"1.5×",@"1.75×",@"2.0×",@"3.0×",@"4.0×",@"5.0×"], @"autoSpeedIndex")];
    [behavior addObjectsFromArray:SettingsSwitches(@[
        @[@"BackgroundPlayback",@"backgroundPlayback"], @[@"Miniplayer",@"miniplayer"], @[@"DisableAutoplay",@"disableAutoplay"],
        @[@"NoContentWarning",@"noContentWarning"], @[@"NoHints",@"noHints"], @[@"AutoFullscreen",@"autoFullscreen"],
        @[@"ExitFullscreen",@"exitFullscreen"]])];
    [model addSection:SettingsSection(@"behaviorCell", @"Player.Actions", behavior)];
    [model addSection:SettingsSection(@"remoteControlCell", @"Player.ControlCenter", @[
        SettingsSwitch(@"RcSkipBackward", @"rcSkipBackward"), SettingsSlider(5,60,1,2,@"rcSkipBackwardSec"),
        SettingsSwitch(@"RcSkipForward", @"rcSkipForward"), SettingsSlider(5,60,1,2,@"rcSkipForwardSec")
    ])];
    [model addSection:SettingsSection(@"gesturesCell", @"Player.Gestures", @[
        SettingsSwitch(@"CompactToast", @"compactToast"),
        SettingsMenu(@"LeftSideGesture", SettingsLocalizedOptions(@[@"Disabled",@"Toast.Brightness",@"Toast.Volume"]), @"leftGestureIndex"),
        SettingsMenu(@"RightSideGesture", SettingsLocalizedOptions(@[@"Disabled",@"Toast.Brightness",@"Toast.Volume"]), @"rightGestureIndex")
    ])];
    [model addSection:SettingsFooterSection(@"widenessCell", @"ActivationAreaWidth", @"ActivationAreaWidthDesc", @[
        SettingsSlider(50,dimension/3,1,0,@"gestWideness")
    ])];
    [model addSection:SettingsPlainSection(@"speedCell", @[
        SettingsMenu(@"HoldToSpeed", SettingsLocalizedOptions(@[@"Disabled",@"Default",@"Standard",@"Extended"]), @"speedIndex"),
        SettingsSlider(0.25,10,0.25,1,@"playbackRate"), SettingsSwitch(@"AdjustWithFinger", @"adjustByFinger"),
        SettingsSwitch(@"PreserveSpeed", @"preserveSpeed"), SettingsSwitch(@"SeekAnywhere", @"seekAnywhere"),
        SettingsSwitch(@"SeekAnywhereFeed", @"seekAnywhereFeed")
    ])];
    [model addSection:SettingsFooterSection(@"seekMethodCell", @"SeekMethod", @"SeekMethodDesc", @[
        SettingsSegment(SettingsLocalizedOptions(@[@"Independent",@"DurationBased"]), @"seekMethodIndex")
    ])];
    [model addSection:SettingsSection(@"sensitivityCell", @"SeekSensitivity", @[SettingsSlider(3,30,1,0,@"seekSensitivity")])];
    [model addSection:SettingsPlainSection(@"gestureSwitchCell", SettingsSwitches(@[
        @[@"TapToSeek",@"tapToSeek"], @[@"TwoFingerTapToPause",@"twoFingerTap"], @[@"CopyWithTimestamp",@"copyWithTimestamp"],
        @[@"PauseOnOverlay",@"pauseOnOverlay"], @[@"DontSnap2Chapter",@"dontSnapToChapter"],
        @[@"NoTwoFingerSnapToChapter",@"noTwoFingerSnapToChapter"], @[@"NoFreeZoom",@"noFreeZoom"],
        @[@"NoDoubleTap2Seek",@"noDoubleTapToSeek"]]))];
    return model;
}

// 0x156a98.
- (DVNTableModel *)shortsTable {
    DVNTableModel *model = SettingsSearchableModel(@"Shorts");
    [model addSection:SettingsSection(@"playbackCell", @"PlaybackMode", @[
        SettingsSegment(SettingsLocalizedOptions(@[@"Loop",@"ScrollToNext",@"Stop"]), @"shortsPlaybackIndex")
    ])];
    [model addSection:SettingsPlainSection(@"shortsCell", @[
        SettingsSwitch(@"ForceBestQuality", @"shortsForceQuality"), SettingsSwitch(@"ShortsOnlyMode", @"shortsOnlyMode"),
        SettingsSwitch(@"RestrictShorts", @"restrictShortsPortion"), SettingsSwitch(@"ShortsProgress", @"shortsProgress"),
        SettingsMenu(@"SpeedByLongTap", SettingsLocalizedOptions(@[@"Disabled",@"LeftSide",@"RightSide",@"BothSides"]), @"shortsSpeedIndex"),
        SettingsSwitch(@"PinchToFullscreenShorts", @"pinchToFullscreenShorts"), SettingsSwitch(@"ShortsToRegular", @"shortsToRegular"),
        SettingsSwitch(@"RemoveShortsPosts", @"removeShortsPosts"), SettingsSwitch(@"RemoveShortsLive", @"removeShortsLive")
    ])];
    DVNSection *interface = [DVNSection sectionWithIdentifier:@"shortsInterfaceCell"];
    interface.header = SettingsL(@"Interface");
    [interface addCells:SettingsSwitches(@[
        @[@"HideShortsLogo",@"hideShortsLogo"], @[@"HideShortsSearch",@"hideShortsSearch"],
        @[@"HideShortsCamera",@"hideShortsCamera"], @[@"HideShortsMore",@"hideShortsMore"],
        @[@"HideCarouselSub",@"carouselNoSub"], @[@"HideCarouselLive",@"carouselNoLive"],
        @[@"HideCarouselTrends",@"carouselNoTrends"], @[@"HideCarouselShop",@"carouselNoShopping"],
        @[@"HideShortsLike",@"shortsNoLike"], @[@"HideShortsDislike",@"shortsNoDislike"],
        @[@"HideShortsComments",@"shortsNoComment"], @[@"HideShortsShare",@"shortsNoShare"],
        @[@"HideShortsRemix",@"shortsNoRemix"], @[@"HideShortsAudioButton",@"shortsNoAudioButton"],
        @[@"HideShortsProducts",@"shortsNoProducts"], @[@"NoPromotionCards",@"hideShortsPromoCards"],
        @[@"HideShortsSuggestion",@"shortsNoSuggestion"], @[@"HideShortsSubscribe",@"shortsNoSubButton"],
        @[@"HideShortsUsername",@"shortsNoTitle"], @[@"HideShortsDescription",@"shortsNoDescription"],
        @[@"HideShortsSource",@"shortsNoSource"], @[@"HideShortsAudio",@"shortsNoAudio"],
        @[@"HideShortsCommentBar",@"shortsNoCommentBar"]])];
    [model addSection:interface];
    return model;
}

// 0x15f514; custom-animation invoke 0x166620 captures the model strongly.
- (DVNTableModel *)interfaceTable {
    DVNTableModel *model = SettingsSearchableModel(@"Interface");
    [model addSection:SettingsSection(@"interfaceCell", @"Interface", SettingsSwitches(@[
        @[@"OledTheme",@"oledTheme"], @[@"OledKeyboard",@"oledKeyboard"], @[@"FloatingKeyboard",@"floatingKeyboard"],
        @[@"NoSearchHistory",@"noSearchHistory"], @[@"RemoveCommentGuidelines",@"hideGuidelines"],
        @[@"StickSortComments",@"stickSortComments"], @[@"HideSortComments",@"hideSortComments"],
        @[@"PlaylistOldMinibar",@"playlistOldMinibar"], @[@"DisableRTL",@"disableRTL"]]))];
    [model addSection:SettingsPlainSection(@"startupCell", @[
        SettingsMenu(@"StartupAnimation", SettingsLocalizedOptions(@[@"Default",@"Show",@"Disable",@"Custom"]), @"startupAnimation"),
        [DVNCell cellWithTitle:SettingsL(@"SelectCustomAnimation") subtitle:nil handler:(DVNStoredBlock)^{
            [[(Class<YTLSettingsMediaPicker>)NSClassFromString(@"DVNMediaPicker") sharedPicker] presentImagePickerForVC:model.selfViewController];
        }]
    ])];
    [model addSection:SettingsSection(@"idiomCell", @"InterfaceStyle", @[
        SettingsSegment(@[SettingsL(@"Default"),@"iPad",@"iPhone"], @"idiomIndex")
    ])];
    [model addSection:SettingsSection(@"otherCell", @"Other", SettingsSwitches(@[
        @[@"NoLinkTracking",@"noLinkTracking"], @[@"NoShareChunk",@"noShareChunk"], @[@"AutoCheckLinks",@"autoCheckCb"]]))];
    DVNSection *menu = [DVNSection sectionWithIdentifier:@"menuCell"];
    menu.header = SettingsL(@"ContextMenu");
    [menu addCells:SettingsSwitches(@[
        @[@"NativeShare",@"nativeShare"], @[@"RemovePlayNext",@"removePlayNext"], @[@"RemoveDownloadMenu",@"removeDownloadMenu"],
        @[@"RemoveWatchLaterMenu",@"removeWatchLaterMenu"], @[@"RemoveSaveToPlaylistMenu",@"removeSaveToPlaylistMenu"],
        @[@"RemoveShareMenu",@"removeShareMenu"], @[@"RemoveNotInterestedMenu",@"removeNotInterestedMenu"],
        @[@"RemoveDontRecommendMenu",@"removeDontRecommendMenu"], @[@"RemoveFeedbackMenu",@"removeFeedbackMenu"],
        @[@"RemoveReportMenu",@"removeReportMenu"], @[@"RemoveRemixMenu",@"removeRemixMenu"], @[@"RemoveYTMMenu",@"removeYTMMenu"]])];
    [model addSection:menu];
    return model;
}

// 0x1666b4.
- (DVNTableModel *)tabBarTable {
    DVNTableModel *model = [DVNTableModel modelWithTitle:SettingsL(@"Tabbar") header:nil footer:nil
                                       viewController:[[TabbarVC alloc] initForSettings:YES]];
    model.supportsSearching = NO;
    return model;
}

// 0x166854; public/private editor invokes 0x16a0f8, 0x16a290. Empty/nil input
// regenerates from defaults. The private ID condition is length > 31, not 64.
- (DVNTableModel *)sbTable {
    DVNCell *publicID = [DVNCell cellWithTitle:SettingsL(@"PublicUserID") subtitle:nil type:11 key:@"sbPublicUserID"];
    publicID.shouldHideDetail = NO;
    publicID.errorText = SettingsL(@"Error.SbPublicID");
    publicID.validationHandler = (DVNStoredBlock)^NSString *(NSString *text) {
        if (text.length == 64) return text;
        if (text.length == 0) return [YTLUserDefaults.standardUserDefaults sbPublicUserID:YTLUserDefaults.standardUserDefaults.sbPrivateUserID];
        return nil;
    };
    DVNCell *privateID = [DVNCell cellWithTitle:SettingsL(@"PrivateUserID") subtitle:nil type:11 key:@"sbPrivateUserID"];
    privateID.shouldHideDetail = YES;
    privateID.detailText = SettingsL(@"TapToReveal");
    privateID.errorText = SettingsL(@"Error.SbPrivateID");
    privateID.validationHandler = (DVNStoredBlock)^NSString *(NSString *text) {
        if (text.length > 31) return text;
        if (text.length == 0) return YTLUserDefaults.standardUserDefaults.sbPrivateUserID;
        return nil;
    };
    DVNTableModel *model = SettingsSearchableModel(@"SponsorBlock");
    NSMutableArray *main = [SettingsSwitches(@[
        @[@"EnableSponsorBlock",@"sponsorBlock"], @[@"SbPlayerButton",@"sbPlayerButton"],
        @[@"ShowNotifications",@"sbNotifications"], @[@"SegmentsInFeedPlayer",@"sbFeedPlayer"],
        @[@"SegmentsInMiniPlayer",@"sbMiniPlayer"], @[@"SegmentSkipAudio",@"sbAudio"], @[@"DurationWithoutSegments",@"sbDurationLabel"]]) mutableCopy];
    [main addObjectsFromArray:@[
        [DVNCell timePickerWithTitle:SettingsL(@"MinimumSkipDuration") subtitle:nil minimum:0 maximum:60 format:2 key:@"sbSkipDuration"],
        [DVNCell timePickerWithTitle:SettingsL(@"SkipAlertDuration") subtitle:nil minimum:2 maximum:20 format:2 key:@"sbDuration"],
        [DVNCell timePickerWithTitle:SettingsL(@"UnskipAlertDuration") subtitle:nil minimum:2 maximum:20 format:2 key:@"sbSkippedDuration"]
    ]];
    [model addSection:SettingsSection(@"sbMainCell", @"Main", main)];
    NSArray *actions = SettingsLocalizedOptions(@[@"Sb.Disable",@"Sb.Skip",@"Sb.Ask",@"Sb.Display"]);
    for (NSArray *segment in [self sbSegments]) {
        [model addSection:SettingsPlainSection(@"segmentCell", @[
            [DVNCell cellWithTitle:SettingsL(segment[0]) subtitle:SettingsL(segment[1]) titleIndexes:actions type:3 key:segment[2]],
            SettingsColor(segment[0], segment[3])
        ])];
    }
    [model addSection:SettingsPlainSection(@"userCell", @[publicID,privateID])];
    return model;
}

// 0x16a3d4; how-to invoke 0x16bb48.
- (DVNTableModel *)rpcTable {
    DVNTableModel *model = SettingsSearchableModel(@"DiscordRPC");
    [model addSection:SettingsFooterSection(@"rpcMainCell", @"Main", @"RPC.AddressDesc", @[
        SettingsSwitch(@"EnableDiscordRPC", @"discordRPC"), SettingsSwitch(@"RPC.OverlayButton", @"rpcOverlayButton"),
        SettingsSwitch(@"RPC.DisableServerAlerts", @"rpcNoServerAlerts"),
        [DVNCell textFieldCellWithTitle:SettingsL(@"RPC.Address") subtitle:nil placeholder:@"192.168.x.x" key:@"rpcAddress"]
    ])];
    [model addSection:SettingsSection(@"rpcInfoCell", @"RPC.Information", @[
        [DVNCell cellWithTitle:SettingsL(@"RPC.HowTo") subtitle:nil icon:nil accessoryIcon:SettingsImage(@"open_new")
                         type:5 handler:(DVNStoredBlock)^{ [self openURL:@"https://github.com/dayanch96/YTPlus-Discord-RPC/blob/main/README.md"]; }]
    ])];
    return model;
}

// 0x16bfd8. Callback addresses/URLs are independently retained in provenance.
// This model is deliberately excluded from recursive search.
- (DVNTableModel *)contribsTable {
    DVNTableModel *model = [DVNTableModel modelWithTitle:SettingsL(@"Contributors") sections:nil];
    model.showsThanksHeart = YES;
    model.supportsSearching = NO;
    [model addSection:SettingsSection(@"specialCell", @"DevContribution", @[
        SettingsLink(self,@"Dan Pashin",SettingsL(@"SpecialThanks"),@"credits",@"https://github.com/danpashin/"),
        SettingsLink(self,@"Furman (iApps)",SettingsL(@"SpecialThanks"),@"credits",@"https://t.me/mdfurman/"),
        SettingsLink(self,@"Magwaer",SettingsL(@"SpecialThanks.Test"),@"credits",@"https://t.me/MagwaerTim/")
    ])];
    [model addSection:SettingsSection(@"localizationCell", @"Localization", @[
        SettingsLink(self,@"Stalker",SettingsL(@"ChineseSimplified"),@"localization",@"https://github.com/xiangfeidexiaohuo"),
        SettingsLink(self,@"Clement",SettingsL(@"ChineseTraditional"),@"localization",@"https://twitter.com/a100900900"),
        SettingsLink(self,@"Balackburn",SettingsL(@"French"),@"localization",@"https://github.com/Balackburn"),
        SettingsLink(self,@"DeciBelioS",SettingsL(@"Spanish"),@"localization",@"https://github.com/Deci8BelioS"),
        SettingsLink(self,@"ichitaso",SettingsL(@"Japanese"),@"localization",@"https://github.com/ichitaso"),
        SettingsLink(self,@"Hiepvk",SettingsL(@"Vietnamese"),@"localization",@"https://github.com/hiepvk"),
        SettingsLink(self,@"BVN",SettingsL(@"Vietnamese"),@"localization",@"https://t.me/bvnsupport"),
        SettingsLink(self,@"riad",SettingsL(@"Arabic"),@"localization",@"https://twitter.com/r22i0"),
        SettingsLink(self,@"gototheskinny",SettingsL(@"Turkish"),@"localization",@"https://github.com/gototheskinny"),
        SettingsLink(self,@"basketshoe",SettingsL(@"Italian"),@"localization",@"https://github.com/basketshoe"),
        SettingsLink(self,@"HM",SettingsL(@"Korean"),@"localization",@"https://github.com/pshyomin"),
        SettingsLink(self,@"Marcin Maj",SettingsL(@"Polish"),@"localization",@"https://github.com/marcinmajsc")
    ])];
    return model;
}

// 0x170eec; invokes 0x172664,0x17297c,0x172c70,0x172ffc,0x173354,
// 0x1736ac,0x173af4,0x173e0c,0x17419c. Titles/authors/URLs stay literal.
- (DVNTableModel *)libsTable {
    DVNTableModel *model = [DVNTableModel modelWithTitle:SettingsL(@"OpenSourceLibs") sections:nil];
    model.showsThanksHeart = YES;
    model.supportsSearching = NO;
    [model addSection:SettingsPlainSection(@"libsCell", @[
        SettingsLink(self,@"YouTubeHeaders",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YouTubeHeader"),
        SettingsLink(self,@"YouTube-X",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YouTube-X"),
        SettingsLink(self,@"YTClassicVideoQuality",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YTClassicVideoQuality"),
        SettingsLink(self,@"YTShortsProgress",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YTShortsProgress"),
        SettingsLink(self,@"YTAutoFullscreen",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YTAutoFullScreen"),
        SettingsLink(self,@"Skip Content Warning",@"PoomSmart",@"libs",@"https://github.com/dayanch96/YTLite/blob/main/YTLite.x#L310-L312"),
        SettingsLink(self,@"YouAreThere",@"PoomSmart",@"libs",@"https://github.com/PoomSmart/YouAreThere"),
        SettingsLink(self,@"YouTube Native Share",@"jkhsjdhjs",@"libs",@"https://github.com/jkhsjdhjs/youtube-native-share"),
        SettingsLink(self,@"MobileFFmpeg",@"Taner Sener",@"libs",@"https://github.com/tanersener/mobile-ffmpeg")
    ])];
    return model;
}

// 0x1744a0.
- (DVNTableModel *)thanksTable {
    DVNTableModel *model = [DVNTableModel modelWithTitle:SettingsL(@"SpecialThanks") header:nil footer:nil viewController:[DVNSupportersVC new]];
    model.supportsSearching = NO;
    return model;
}

// 0x174690; subtitle/completion/import/export/reset invokes 0x175830..0x175934.
- (DVNTableModel *)prefsTable {
    DVNCell *clear = [DVNCell cellWithTitle:SettingsL(@"ClearCache") subtitle:nil icon:nil type:12 key:nil];
    clear.subtitleProvider = (DVNStoredBlock)^NSString *{ return [self getCacheSize]; };
    clear.reloadsCell = YES;
    clear.handlerWithCompletion = (DVNStoredBlock)^(void (^completion)(void)) { [self clearCacheWithCompletion:completion]; };
    DVNTableModel *model = [DVNTableModel modelWithTitle:[NSString stringWithFormat:SettingsL(@"Preferences"),@"YouTube Plus"] sections:nil];
    model.supportsSearching = YES;
    [model addSections:@[
        SettingsSection(@"prefsCell", @"ManagePreferences", @[
            [DVNCell cellWithTitle:SettingsL(@"ImportPreferences") subtitle:nil handler:(DVNStoredBlock)^{ [self importPreferences]; }],
            [DVNCell cellWithTitle:SettingsL(@"ExportPreferences") subtitle:nil selfHandler:(DVNStoredBlock)^(DVNCell *cell) {
                [YTLUserDefaults exportYtlSettings:cell.sourceView];
            }],
            [DVNCell cellWithTitle:SettingsL(@"ResetSettings") subtitle:nil handler:(DVNStoredBlock)^{ [self resetSettings]; }]
        ]),
        SettingsSection(@"cacheCell", @"ManageCache", @[SettingsSwitch(@"ClearCacheAtStart",@"autoClearCache"),clear])
    ]];
    return model;
}

// 0x175934; image factory stores selfHandler, not handler (0x176bf4,0x176e68,
// 0x176ed8,0x1771b0). Only the donation callback consumes its DVNCell argument.
- (DVNSection *)devSection {
    return [DVNSection sectionWithHeader:SettingsL(@"Developer") footer:nil cells:@[
        [DVNCell cellWithTitle:@"Dayanch96" subtitle:SettingsL(@"FollowMe") image:SettingsOriginalImage(@"dvn")
                 accessoryIcon:SettingsOriginalImage(@"x_prefs") type:5 handler:(DVNStoredBlock)^(DVNCell *cell){
            (void)cell;
            [self openURL:@"https://twitter.com/dayanch96"];
        }],
        [DVNCell cellWithTitle:SettingsL(@"SupportDevelopment") subtitle:SettingsL(@"DonateDesc") image:SettingsOriginalImage(@"heart_prefs")
                 accessoryIcon:SettingsImage(@"support") type:5 handler:(DVNStoredBlock)^(DVNCell *cell) {
            [self showDonationSheet:cell.sourceView];
        }],
        [DVNCell cellWithTitle:SettingsL(@"VisitGithub") subtitle:SettingsL(@"VisitGithubDesc") image:SettingsOriginalImage(@"github_logo")
                 accessoryIcon:SettingsImage(@"open_new") type:5 handler:(DVNStoredBlock)^(DVNCell *cell){
            (void)cell;
            [self openURL:@"https://github.com/dayanch96/YTLite"];
        }],
        [DVNCell cellWithTitle:SettingsL(@"VisitTelegram") subtitle:SettingsL(@"VisitTelegramDesc") image:SettingsOriginalImage(@"tg_logo")
                 accessoryIcon:SettingsImage(@"open_new") type:5 handler:(DVNStoredBlock)^(DVNCell *cell){
            (void)cell;
            [self openURL:@"https://t.me/dvntms"];
        }]
    ] identifier:@"devCell"];
}

// Local UI change from 0x177370: omit the Special thanks/supporters entry.
- (DVNSection *)creditsSection {
    DVNTableModel *contributors = [self contribsTable];
    DVNCell *contributorCell = SettingsController(contributors,@"Contributors",@"credits");
    DVNCell *libraries = SettingsController([self libsTable],@"OpenSourceLibs",@"libs");
    DVNTableModel *preferences = [self prefsTable];
    DVNCell *preferencesCell = [DVNCell controllerCellWithModel:preferences title:[NSString stringWithFormat:SettingsL(@"Preferences"),@"YouTube Plus"]
                                                    subtitle:nil icon:SettingsImage(@"ytl_settings")];
    return [DVNSection sectionWithHeader:SettingsL(@"Credits") footer:nil cells:@[contributorCell,libraries,preferencesCell] identifier:@"creditsCell"];
}

// Intentional change from 0x177f70: retained selector for source compatibility,
// but never added to rootTable. Old callers receive an informational section,
// not a login prompt, an account-status query, or a subscription purchase link.
- (DVNSection *)patreonSection:(DVNTableModel *)model {
    return [DVNSection sectionWithHeader:@"Local features"
        cells:@[[self patreonButtonCellWithType:nil model:model]] identifier:@"localFeaturesCell"];
}

// Intentional replacement of 0x178a68. No activation/device-management/logout
// callbacks are installed. In particular, this never claims a server account
// is authenticated, and does not access or erase existing Keychain records.
- (DVNCell *)patreonButtonCellWithType:(NSString *)type model:(DVNTableModel *)model {
    (void)type;
    (void)model;
    return [DVNCell cellWithTitle:@"No sign-in required"
        subtitle:@"Features use your local settings. No subscription or device activation is required."
        icon:nil type:5 key:nil];
}

// 0x179c84, invokes 0x17a110 and 0x17a154.
- (void)importPreferences {
    YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") confirmationDialogWithAction:^{
        [YTLUserDefaults importYtlSettings:^(BOOL success) {
            SettingsToast(success ? @"Done" : @"Error.FailedToImport", success);
        }];
    } actionTitle:SettingsL(@"Yes") cancelTitle:SettingsL(@"No")];
    alert.title = SettingsL(@"Warning");
    alert.subtitle = SettingsL(@"PreImportMessage");
    [alert show];
}
// 0x17a478, invoke 0x17a8d4.
- (void)resetSettings {
    YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") confirmationDialogWithAction:^{
        [YTLUserDefaults resetUserDefaults];
        SettingsToast(@"Done", YES);
    } actionTitle:SettingsL(@"Yes") cancelTitle:SettingsL(@"No")];
    alert.title = SettingsL(@"Warning");
    alert.subtitle = SettingsL(@"ResetMessage");
    [alert show];
}

// 0x17aa28, NSURLSession invoke 0x17adb8, main-queue invoke 0x17ce10,
// link/copy invokes 0x17dfe4/0x17e100. Default descriptors were decoded from
// CFString objects 0x11a6160..0x11a67e0; the network overrides only array values.
- (void)showDonationSheet:(UIView *)sourceView {
    [[NSURLSession.sharedSession dataTaskWithURL:[NSURL URLWithString:@"https://api.dvntm.com/api/getlinks"]
                             completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        (void)response;
        NSArray *links = @[
            @{@"name":@"Patreon",@"key":@"patreon",@"url":@"https://www.patreon.com/dayanch96"},
            @{@"name":@"Github Sponsors",@"key":@"githubsp",@"url":@"https://github.com/sponsors/dayanch96"},
            @{@"name":@"Buy Me a Coffee",@"key":@"bmc",@"url":@"https://www.buymeacoffee.com/dayanch96"},
            @{@"name":@"Boosty",@"key":@"boosty",@"url":@"https://boosty.to/dayanch96"}
        ];
        NSArray *addresses = @[
            @{@"name":@"USDT (TRC20)",@"key":@"usdt",@"address":@"TEdKJdKwc1Bbu8Py4um8qPQ6MbproEqNJw"},
            @{@"name":@"BNB Smart Chain (BEP20)",@"key":@"bsc",@"address":@"0xc6f9fddb30ce10d70e6497950f44c8e10b72bcd6"}
        ];
        NSDictionary *icons = @{@"boosty":@"boosty", @"bmc":@"coffee", @"githubsp":@"github",
                                @"patreon":@"patreon", @"usdt":@"usdt", @"bsc":@"bnb"};
        if (data && !error) {
            NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];
            if ([json[@"sponsor_links"] isKindOfClass:NSArray.class]) links = json[@"sponsor_links"];
            if ([json[@"addresses"] isKindOfClass:NSArray.class]) addresses = json[@"addresses"];
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            YTLSettingsHostSheet *sheet = [(id)NSClassFromString(@"YTDefaultSheetController")
                sheetControllerWithMessage:SettingsL(@"SupportDevelopment") subMessage:SettingsL(@"SupportDevelopmentDesc")
                delegate:nil parentResponder:nil];
            UIView *header = [sheet valueForKey:@"_headerView"];
            UILabel *subtitle = [header valueForKey:@"_subtitleLabel"];
            subtitle.numberOfLines = 0;
            for (NSDictionary *entry in links) {
                UIImage *image = [NSBundle.ytl_defaultBundle originalImageWithName:icons[entry[@"key"]]];
                id action = [(Class<YTLSettingsSheetAction>)NSClassFromString(@"YTActionSheetAction")
                    actionWithTitle:entry[@"name"] iconImage:image secondaryIconImage:nil accessibilityIdentifier:nil
                    handler:^(YTActionSheetAction *action) { (void)action; [self openURL:entry[@"url"]]; }];
                [sheet addAction:action];
            }
            for (NSDictionary *entry in addresses) {
                UIImage *image = [NSBundle.ytl_defaultBundle originalImageWithName:icons[entry[@"key"]]];
                id action = [(Class<YTLSettingsSheetAction>)NSClassFromString(@"YTActionSheetAction")
                    actionWithTitle:entry[@"name"] iconImage:image secondaryIconImage:nil accessibilityIdentifier:nil
                    handler:^(YTActionSheetAction *action) {
                        (void)action;
                        UIPasteboard.generalPasteboard.string = entry[@"address"];
                        SettingsToast(@"Copied", YES);
                    }];
                [sheet addAction:action];
            }
            sheet.sourceView = sourceView;
            [sheet presentFromViewController:self.presenter animated:YES completion:nil];
        });
    }] resume];
}

// 0x17e400. Preserve canOpenURL: gating, empty options, nil completion.
- (void)openURL:(NSString *)string {
    NSURL *url = [NSURL URLWithString:string];
    if ([UIApplication.sharedApplication canOpenURL:url]) {
        [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
    }
}

// 0x17e534, renderer invoke 0x17e608. The border belongs to the image view.
- (UIImage *)thanksImage:(NSString *)name {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(40,40)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIImage *source = [UIImage imageNamed:name inBundle:NSBundle.ytl_defaultBundle compatibleWithTraitCollection:nil];
        UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0,0,40,40)];
        UIImageView *image = [[UIImageView alloc] initWithImage:source];
        image.frame = container.bounds;
        image.contentMode = UIViewContentModeScaleAspectFit;
        image.clipsToBounds = YES;
        image.layer.cornerRadius = 20;
        image.layer.borderWidth = 1;
        image.layer.borderColor = [UIColor.whiteColor colorWithAlphaComponent:0.25].CGColor;
        [container addSubview:image];
        [container.layer renderInContext:context.CGContext];
    }];
}

// 0x17e8d4. Segment ordering and storage keys are literal, case-sensitive data.
- (NSArray *)sbSegments {
    return @[
        @[@"sponsors",@"sponsorsDesc",@"sbSponsorIndex",@"sbSponsorColor"],
        @[@"intros",@"introsDesc",@"sbIntroIndex",@"sbIntroColor"],
        @[@"outros",@"outrosDesc",@"sbOutroIndex",@"sbOutroColor"],
        @[@"interactions",@"interactionsDesc",@"sbInteractionIndex",@"sbInteractionColor"],
        @[@"selfpromos",@"selfpromosDesc",@"sbSelfPromoIndex",@"sbSelfPromoColor"],
        @[@"nonmusic",@"nonmusicDesc",@"sbNonMusicIndex",@"sbNonMusicColor"],
        @[@"previews",@"previewsDesc",@"sbPreviewIndex",@"sbPreviewColor"],
        @[@"tangent",@"tangentDesc",@"sbTangentIndex",@"sbTangentColor"]
    ];
}

// 0x1809f4; worker/main invokes 0x180aac/0x180e8c. Original removes the entire
// temporary directory and ignores filesystem errors. Fixtures redirect BOTH
// Foundation path APIs before ever exercising this method; no real cache tests.
- (void)clearCacheWithCompletion:(void (^)(void))completion {
    dispatch_async(dispatch_get_global_queue(0,0), ^{
        NSString *cache = NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES).firstObject;
        NSFileManager *manager = NSFileManager.defaultManager;
        for (NSString *entry in [manager contentsOfDirectoryAtPath:cache error:NULL]) {
            [manager removeItemAtPath:[cache stringByAppendingPathComponent:entry] error:NULL];
        }
        [NSFileManager.defaultManager removeItemAtPath:NSTemporaryDirectory() error:NULL];
        dispatch_async(dispatch_get_main_queue(), ^{ completion(); });
    });
}

// 0x180ec0. Includes directory-entry sizes and repeats paths as returned; the
// accumulating register is 64-bit, then passed to stringFromByteCount: (q).
- (NSString *)getCacheSize {
    NSArray *roots = @[NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES).firstObject,NSTemporaryDirectory()];
    unsigned long long size = 0;
    for (NSString *root in roots) {
        for (NSString *entry in [NSFileManager.defaultManager subpathsOfDirectoryAtPath:root error:NULL]) {
            size += [[NSFileManager.defaultManager attributesOfItemAtPath:[root stringByAppendingPathComponent:entry] error:NULL] fileSize];
        }
    }
    NSByteCountFormatter *formatter = [NSByteCountFormatter new];
    formatter.countStyle = NSByteCountFormatterCountStyleFile;
    return [formatter stringFromByteCount:(long long)size];
}
// Weak accessors and .cxx_destruct are ARC-synthesized (0x1814dc..0x181528).
@end
