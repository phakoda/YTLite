#import "GeneralInterfaceHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Presentation/ToastManager.h"
#import "../Helpers/YTPPlayerHelper.h"
#import "../Support/YTPDB.h"
#import "../Controls/YTPSpeedPopupController.h"
#import "../SleepTimer/YTPSleepTimer.h"
#import "../Downloads/DownloadMenuHelper.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>

static char GeneralHelperKey;
static BOOL GeneralIsCommentPanel(UIViewController *controller) {
    return ([controller isKindOfClass:NSClassFromString(@"YTEngagementPanelViewControllerImpl")] ||
            [controller isKindOfClass:NSClassFromString(@"YTMainAppEngagementPanelViewController")]) &&
        [[[controller panelIdentifier] description] containsString:@"comment-item-section"];
}
static void GeneralMutateGuide(id<YTLGeneralGuideResponse> response) {
    for (id<YTLGeneralGuideItem> item in response.itemsArray) {
        NSMutableArray<id<YTLGeneralPivotSupported>> *items = item.pivotBarRenderer.itemsArray;
        if (!items.count) continue;
        NSMutableArray *active = [[[YTLUserDefaults standardUserDefaults] objectForKey:@"activeTabs"] mutableCopy];
        if (!active) continue;
        NSDictionary *custom = @{
            @"FEexplore":@{@"browseId":@"FEexplore",@"iconType":@292},
            @"FEhistory":@{@"browseId":@"FEhistory",@"iconType":@876},
            @"VLWL":@{@"browseId":@"VLWL",@"iconType":@877},
            @"FEpost_home":@{@"browseId":@"FEpost_home",@"iconType":@878},
            @"FEhype_leaderboard":@{@"browseId":@"FEhype_leaderboard",@"iconType":@879},
            @"UC-9-kyTW8ZkZNDHQJ6FgpwQ":@{@"browseId":@"UC-9-kyTW8ZkZNDHQJ6FgpwQ",@"iconType":@880},
            @"UC4R8DWoMoI7CAwX8_LjQHig":@{@"browseId":@"UC4R8DWoMoI7CAwX8_LjQHig",@"iconType":@881},
            @"UCOpNcN46UbXVtpKMrmU4Abg":@{@"browseId":@"UCOpNcN46UbXVtpKMrmU4Abg",@"iconType":@882},
            @"UCEgdi0XIXXZ-qJOFPf4JSKw":@{@"browseId":@"UCEgdi0XIXXZ-qJOFPf4JSKw",@"iconType":@883},
            @"FEnotifications_inbox":@{@"browseId":@"FEnotifications_inbox",@"iconType":@884}
        };
        NSMutableIndexSet *removed = [NSMutableIndexSet indexSet];
        for (NSUInteger index = 0; index < items.count; index++) {
            id<YTLGeneralPivotSupported> renderer = items[index];
            NSString *identifier = renderer.pivotBarItemRenderer.pivotIdentifier;
            if (!identifier.length) identifier = renderer.pivotBarIconOnlyItemRenderer.pivotIdentifier;
            if (![active containsObject:identifier]) [removed addIndex:index];
        }
        [items removeObjectsAtIndexes:removed];
        for (NSUInteger index = 0; index < active.count; index++) {
            NSString *identifier = active[index];
            NSDictionary *entry = custom[identifier];
            if (entry) {
                NSUInteger found = [items indexOfObjectPassingTest:^BOOL(id<YTLGeneralPivotSupported> renderer, NSUInteger i, BOOL *stop) {
                    return [renderer.pivotBarItemRenderer.pivotIdentifier isEqualToString:entry[@"browseId"]];
                }];
                if (found == NSNotFound) {
                    NSString *title = [[NSBundle ytl_defaultBundle] localizedStringForKey:entry[@"browseId"] value:nil table:nil];
                    id<YTLGeneralPivotSupported> renderer = [%c(YTIPivotBarRenderer) pivotSupportedRenderersWithBrowseId:entry[@"browseId"] title:title iconType:[entry[@"iconType"] intValue]];
                    if (items.count < index) [items addObject:renderer];
                    else [items insertObject:renderer atIndex:index];
                }
            } else {
                NSUInteger found = [items indexOfObjectPassingTest:^BOOL(id<YTLGeneralPivotSupported> renderer, NSUInteger i, BOOL *stop) {
                    id<YTLGeneralPivotItem> pivot = [identifier isEqualToString:@"FEuploads"] ? renderer.pivotBarIconOnlyItemRenderer : renderer.pivotBarItemRenderer;
                    return [pivot.pivotIdentifier isEqualToString:identifier];
                }];
                if (found != NSNotFound) {
                    id<YTLGeneralPivotSupported> renderer = items[found];
                    [items removeObjectAtIndex:found];
                    if (items.count < index) [items addObject:renderer];
                    else [items insertObject:renderer atIndex:index];
                }
            }
        }
    }
}

%group YTLGeneralInterfaceEarly
%hook YTToastOffsetController
- (void)update { %orig; [ToastManager sharedManager].offsetController = self; [[ToastManager sharedManager] updateAllToasts]; }
- (void)setWasPinnedTop:(BOOL)pinned { %orig(pinned); [ToastManager sharedManager].isPinnedTop = pinned; }
%end
%hook YTWatchViewController
- (void)setFullscreen:(BOOL)fullscreen { %orig(fullscreen); [ToastManager sharedManager].isFullscreen = fullscreen; }
%end
%hook UIDevice
- (void)setOrientation:(NSInteger)orientation animated:(BOOL)animated {
    %orig(orientation, animated);
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 300000000), dispatch_get_main_queue(), ^{ [[ToastManager sharedManager] updateAllToasts]; });
}
%end
%hook UIViewController
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion {
    if (![controller isKindOfClass:NSClassFromString(@"YTInterstitialElementsViewController")]) %orig(controller, animated, completion);
}
- (void)viewDidLoad {
    %orig;
    if (GeneralIsCommentPanel(self)) [[NSNotificationCenter defaultCenter] postNotificationName:@"GOODHeightDidChangeNotification" object:self userInfo:@{@"height":@90}];
    if ([self isKindOfClass:NSClassFromString(@"YTInterstitialElementsViewController")]) [self dismissViewControllerAnimated:NO completion:nil];
}
- (void)viewDidDisappear:(BOOL)animated {
    %orig(animated);
    if (GeneralIsCommentPanel(self)) [[NSNotificationCenter defaultCenter] postNotificationName:@"GOODHeightDidChangeNotification" object:self userInfo:@{@"height":@0}];
}
%end
%end

%group YTLGeneralInterface
%hook YTMultiSizeViewController
%new
- (YTLHelper *)helper { return objc_getAssociatedObject(self, &GeneralHelperKey); }
%new
- (void)setHelper:(YTLHelper *)helper { objc_setAssociatedObject(self, &GeneralHelperKey, helper, OBJC_ASSOCIATION_RETAIN_NONATOMIC); }
%end
%hook YTSettingsSectionItemManager
- (void)updatePremiumEarlyAccessSectionWithEntry:(id)entry {}
%end
%hook YTRightNavigationButtons
- (void)layoutSubviews {
    %orig;
    if (ytpBool(@"noNotifsButton")) self.notificationButton.hidden = YES;
    if (ytpBool(@"noSearchButton")) self.searchButton.hidden = YES;
    for (UIView *view in self.subviews) {
        if (ytpBool(@"noVoiceSearchButton") && [view.accessibilityLabel isEqualToString:[[NSBundle mainBundle] localizedStringForKey:@"search.voice.access" value:@"" table:nil]]) view.hidden = YES;
        if (ytpBool(@"noCast") && [view.accessibilityIdentifier isEqualToString:@"id.mdx.playbackroute.button"]) view.hidden = YES;
    }
}
%end
%hook YTSearchViewController
- (void)viewDidLoad { %orig; if (ytpBool(@"noVoiceSearchButton")) [self setValue:@NO forKey:@"_isVoiceSearchAllowed"]; }
- (void)setSuggestions:(id)suggestions { if (!ytpBool(@"noSearchHistory")) %orig(suggestions); }
%end
%hook YTWatchViewController
- (NSUInteger)allowedFullScreenOrientations { return ytpBool(@"portraitFullscreen") ? 0x1a : %orig; }
%end
%hook ASCollectionView
- (CGSize)sizeForElement:(id<YTLGeneralNode>)element {
    if ([self.accessibilityIdentifier isEqualToString:@"id.video.scrollable_action_bar"]) {
        id<YTLGeneralNode> first = [[element node].yogaChildren firstObject];
        for (id<YTLGeneralNode> child in first.yogaChildren) {
            NSDictionary *identifiers = @{
                @"id.video.remix.button":@(ytpBool(@"playerNoRemix")),
                @"id.video.share.button":@(ytpBool(@"playerNoShare")),
                @"id.ui.add_to.offline.button":@(ytpBool(@"playerNoDownload")),
                @"id.video.add_to.button":@(ytpBool(@"playerNoSave"))
            };
            for (NSString *identifier in identifiers)
                if ([[child description] containsString:identifier] && [identifiers[identifier] boolValue]) return CGSizeZero;
            if (child.yogaChildren.count > 1) {
                for (id<YTLGeneralNode> text in child.yogaChildren) {
                    if (![text isKindOfClass:%c(ASTextNode)]) continue;
                    NSDictionary *labels = @{
                        @"Thanks":@{@"array":[YTPDB thanks],@"shouldRemove":@(ytpBool(@"playerNoThanks"))},
                        @"Clip":@{@"array":[YTPDB clip],@"shouldRemove":@(ytpBool(@"playerNoClip"))},
                        @"Report":@{@"array":[YTPDB report],@"shouldRemove":@(ytpBool(@"playerNoReport"))},
                        @"Hype":@{@"array":[YTPDB hype],@"shouldRemove":@(ytpBool(@"playerNoHype"))},
                        @"StopAds":@{@"array":[YTPDB stopAds],@"shouldRemove":@(ytpBool(@"playerNoStopAds"))}
                    };
                    for (NSString *key in labels) {
                        NSDictionary *entry = labels[key];
                        NSArray *titles = entry[@"array"];
                        if ([entry[@"shouldRemove"] boolValue] && [titles containsObject:text.attributedText.string]) return CGSizeZero;
                    }
                }
            }
        }
    }
    return %orig(element);
}
%end
%hook ELMTouchCommandPropertiesHandler
- (void)handleTap {
    id<YTLGeneralNode> node = [[self valueForKey:@"_controller"] node];
    NSString *identifier = [node valueForKey:@"_accessibilityIdentifier"];
    if (ytpBool(@"shortsToRegular") && ((int)[identifier containsString:@"short"] | [identifier containsString:@"eml.video_card"] | [identifier containsString:@"eml.cvr"])) {
        id<YTLGeneralNode> current = node;
        for (NSUInteger depth = 0; current && depth < 10; depth++) {
            if (!current.subnodes.count) break;
            id<YTLGeneralNode> next = current.subnodes.firstObject;
            if (!next) break;
            if ([[next valueForKey:@"_accessibilityIdentifier"] isEqualToString:@"primary_image"]) {
                NSString *videoID = [YTPPlayerHelper getVideoID:next.URL];
                if (videoID) { [YTPPlayerHelper openVideoWithID:videoID handler:self]; return; }
                break;
            }
            current = next;
        }
    }
    if ([identifier isEqualToString:@"id.ui.add_to.offline.button"] && ytpBool(@"downloadManager") && ytpInt(@"ytlButtonIndex") != 1) {
        id player = [[[node.closestViewController valueForKey:@"_metadataPanelStateProvider"] valueForKey:@"_watchViewController"] valueForKey:@"_playerViewController"];
        [DownloadMenuHelper showDownloadSheet:player withSender:node.view];
        return;
    }
    if ([identifier isEqualToString:@"id.elements.list_item"] && ytpBool(@"downloadManager") && ytpInt(@"ytlButtonIndex") != 1) {
        for (id<YTLGeneralNode> child in node.subnodes) {
            if ([child isKindOfClass:%c(ASImageNode)] && [child.image.accessibilityIdentifier isEqualToString:@"youtube_outline_experimental/arrow_down_24pt"]) {
                id player = [[YTPSleepTimer sharedTimer] getPlayerIfAvailable];
                if (player) { [DownloadMenuHelper showDownloadSheet:player withSender:node.view]; return; }
                break;
            }
        }
    }
    for (id<YTLGeneralNode> child in node.subnodes) {
        if (![child isKindOfClass:%c(ASImageNode)]) continue;
        if ([@[@"yt_outline_play_arrow_half_circle_24pt", @"youtube_outline_experimental/play_circle_half_dashed_24pt"] containsObject:child.image.accessibilityIdentifier]) {
            UIViewController *delegate = [node.closestViewController valueForKey:@"_delegate"];
            if ([[delegate parentResponder] isKindOfClass:%c(YTMainAppVideoPlayerOverlayViewController)]) {
                UIViewController *parent = [delegate parentResponder];
                [delegate dismissViewControllerAnimated:YES completion:^{ [[YTPSpeedPopupController speedController] presentFromViewController:parent]; }];
                return;
            }
        }
        break;
    }
    if ([node.accessibilityIdentifier hasPrefix:@"id.elements.components.overflow_menu_item_"]) {
        NSString *label = node.accessibilityLabel;
        NSRegularExpression *expression = [NSRegularExpression regularExpressionWithPattern:@"\\d+p" options:0 error:nil];
        if ([expression firstMatchInString:label options:0 range:NSMakeRange(0, label.length)] && ytpBool(@"classicQuality")) {
            UIViewController *controller = node.closestViewController;
            if ([controller isKindOfClass:%c(YTActionSheetDialogViewController)] && [controller.parentViewController isKindOfClass:%c(YTBottomSheetController)]) {
                YTMainAppVideoPlayerOverlayViewController *parent = [[controller delegate] parentResponder];
                if ([parent isKindOfClass:%c(YTMainAppVideoPlayerOverlayViewController)]) {
                    [parent dismissViewControllerAnimated:YES completion:^{ [parent didPressVideoQuality:nil]; }];
                    return;
                }
            }
        }
    }
    %orig;
}
%end
%hook YTUserDefaults
- (BOOL)areHintsDisabled { return ytpBool(@"noHints"); }
- (void)setHintsDisabled:(BOOL)disabled { %orig(ytpBool(@"noHints") | disabled); }
%end
%hook YTGuideServiceCoordinator
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response withCompletion:(id)completion { GeneralMutateGuide(response); %orig(response, completion); }
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion { GeneralMutateGuide(response); %orig(response, error, completion); }
%end
%hook YTGuideServiceCoordinatorImpl
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion { GeneralMutateGuide(response); %orig(response, error, completion); }
- (void)handleLegacyResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion { GeneralMutateGuide(response); %orig(response, error, completion); }
%end
%hook YTAppGuideServiceCoordinator
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion { GeneralMutateGuide(response); %orig(response, error, completion); }
%end
%hook UIDevice
- (UIUserInterfaceIdiom)userInterfaceIdiom { return ytpInt(@"idiomIndex") ? (ytpInt(@"idiomIndex") == 1 ? UIUserInterfaceIdiomPad : UIUserInterfaceIdiomPhone) : %orig; }
%end
%hook UIKeyboardImpl
- (BOOL)floatingForced { return ytpBool(@"floatingKeyboard") ? YES : %orig; }
%end
%hook UIApplication
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {
    if (ytpBool(@"noLinkTracking")) {
        NSURLComponents *components = [NSURLComponents componentsWithURL:url resolvingAgainstBaseURL:NO];
        if ([components.host containsString:@"youtube.com"] && [components.path isEqualToString:@"/redirect"]) {
            for (NSURLQueryItem *item in components.queryItems) {
                if ([item.name isEqualToString:@"q"] && item.value) {
                    NSURL *destination = [NSURL URLWithString:item.value];
                    if (destination) { url = destination; break; }
                }
            }
        }
    }
    %orig(url, options, completion);
}
%end
%end
void YTLInstallGeneralInterfaceEarlyHooks(void) { %init(YTLGeneralInterfaceEarly); }
void YTLInstallGeneralInterfaceHooks(void) {
    objc_property_attribute_t attributes[] = {{"T", "@\"YTLHelper\""}, {"&", ""}, {"N", ""}};
    class_addProperty(%c(YTMultiSizeViewController), "helper", attributes, 3);
    %init(YTLGeneralInterface);
}
