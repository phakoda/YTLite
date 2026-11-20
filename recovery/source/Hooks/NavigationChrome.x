#import "NavigationChromeHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Downloads/YTPMedia.h"
#import "../Settings/TabbarVC.h"
#import "../Whitelist/SbWhitelistVC.h"
#import "../SleepTimer/YTPSleepTimer.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>

static NSString *NavigationText(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}
static void NavigationPresent(BOOL whitelist) {
    UINavigationController *navigation = [UINavigationController alloc];
    UIViewController *controller = whitelist ? [[SbWhitelistVC alloc] init] : [[TabbarVC alloc] initForSettings:NO];
    navigation = [navigation initWithRootViewController:controller];
    navigation.modalPresentationStyle = UIModalPresentationPageSheet;
    static Class styleClass;
    if (!styleClass) styleClass = NSClassFromString(@"YTDefaultTypeStyle");
    YTDefaultTypeStyle *probe = [[styleClass alloc] init];
    if ([probe respondsToSelector:@selector(ytSansFontOfSize:weight:)]) {
        // Original allocates a second style instance without init for this call.
        YTDefaultTypeStyle *style = [styleClass alloc];
        UIFont *font = [style ytSansFontOfSize:20 weight:UIFontWeightBold];
        navigation.navigationBar.titleTextAttributes = @{NSFontAttributeName:font, NSForegroundColorAttributeName:UIColor.labelColor};
    }
    [[[[UIApplication sharedApplication] delegate] window].rootViewController presentViewController:navigation animated:YES completion:nil];
}
static void NavigationOpenLink(void) {
    NSString *text = [UIPasteboard generalPasteboard].string;
    if (!text.length) return;
    for (NSString *domain in @[@"youtube.com", @"youtu.be", @"youtube-nocookie.com"]) {
        if ([text containsString:domain]) {
            NSString *path = [text stringByReplacingOccurrencesOfString:@"^https?://" withString:@"" options:NSRegularExpressionSearch range:NSMakeRange(0, text.length)];
            NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"vnd.youtube://%@", path]];
            [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
            break;
        }
    }
}

%group YTLNavigationChromeEarly
%hook YTHeaderView
- (BOOL)stickyNavHeaderEnabled { return [[YTLUserDefaults standardUserDefaults] boolForKey:@"stickyNavbar"] ? YES : %orig; }
- (BOOL)clipsToStatusArea { return [[YTLUserDefaults standardUserDefaults] boolForKey:@"stickyNavbar"] ? NO : %orig; }
%end
%hook YTChipCloudCell
- (id)framesForChipViewsWithWidth:(double)width {
    if ([[YTLUserDefaults standardUserDefaults] boolForKey:@"noSubbar"] || ytpBool(@"hideInlineComment")) return nil;
    return %orig;
}
%end
%hook YTMySubsFilterHeaderView
- (void)setChipFilterView:(id)view { if (![[YTLUserDefaults standardUserDefaults] boolForKey:@"noSubbar"]) %orig; }
%end
%hook YTHeaderContentComboView
- (void)enableSubheaderBarWithView:(id)view { if (![[YTLUserDefaults standardUserDefaults] boolForKey:@"noSubbar"]) %orig; }
- (void)setFeedHeaderScrollMode:(int)mode { %orig([[YTLUserDefaults standardUserDefaults] boolForKey:@"noSubbar"] ? 0 : mode); }
%end
%hook YTIPivotBarRenderer
- (int)backgroundStyle { return [[YTLUserDefaults standardUserDefaults] boolForKey:@"frostedPivot"] ? 2 : 1; }
%end
%hook YTPivotBarViewController
- (void)viewDidAppear:(BOOL)animated {
    %orig;
    if (!isTabSelected && ![[YTLUserDefaults standardUserDefaults] boolForKey:@"shortsOnlyMode"]) {
        [self resetViewControllersCache];
        [self resetViewControllersCacheForPivotIdentifiers:@[@"FElibrary, FEsubscriptions"]];
        [self selectItemWithPivotIdentifier:[[YTLUserDefaults standardUserDefaults] objectForKey:@"startupTab"]];
        isTabSelected = YES;
    }
    if ([[YTLUserDefaults standardUserDefaults] boolForKey:@"shortsOnlyMode"]) {
        [self selectItemWithPivotIdentifier:@"FEshorts"];
        [self.parentViewController hidePivotBar];
    }
}
- (BOOL)isFrostedPivotBarPermitted { return [[YTLUserDefaults standardUserDefaults] boolForKey:@"frostedPivot"]; }
%end
%hook YTPivotBarView
- (UIView *)itemView1 {
    UIView *item = %orig;
    UIContextMenuInteraction *interaction = [[UIContextMenuInteraction alloc] initWithDelegate:self];
    item.userInteractionEnabled = YES;
    [item addInteraction:interaction];
    return item;
}
%new
- (UIContextMenuConfiguration *)contextMenuInteraction:(UIContextMenuInteraction *)interaction configurationForMenuAtLocation:(CGPoint)location {
    return [UIContextMenuConfiguration configurationWithIdentifier:nil previewProvider:nil actionProvider:^UIMenu *(NSArray<UIMenuElement *> *suggestedActions) {
        NSMutableArray *actions = [NSMutableArray array];
        [actions addObject:[UIAction actionWithTitle:NavigationText(@"Tabbar") image:[YTPMedia tabbar] identifier:nil handler:^(UIAction *action) {
            NavigationPresent(NO);
        }]];
        [actions addObject:[UIAction actionWithTitle:NavigationText(@"OpenLink") image:[YTPMedia link] identifier:nil handler:^(UIAction *action) {
            NavigationOpenLink();
        }]];
        UIAction *sleep = [UIAction actionWithTitle:NavigationText(@"SleepTimer") image:[YTPMedia moon] identifier:nil handler:^(UIAction *action) {
            [[YTPSleepTimer sharedTimer] showOptions:[self itemView1]];
        }];
        if ([[YTLUserDefaults standardUserDefaults] integerForKey:@"ytlSleepTimerIndex"] == 2 || [[YTLUserDefaults standardUserDefaults] integerForKey:@"ytlSleepTimerIndex"] == 3) [actions addObject:sleep];
        UIAction *whitelist = [UIAction actionWithTitle:NavigationText(@"SbWhitelist") image:[YTPMedia sponsorblock] identifier:nil handler:^(UIAction *action) {
            NavigationPresent(YES);
        }];
        UIMenu *sbMenu = [UIMenu menuWithTitle:@"" image:nil identifier:@"sb_menu" options:1 children:@[whitelist]];
        UIMenu *tabsMenu = [UIMenu menuWithTitle:@"" image:nil identifier:@"tabs_menu" options:1 children:actions];
        return [UIMenu menuWithTitle:@"" children:@[sbMenu, tabsMenu]];
    }];
}
%end
%end

%group YTLNavigationChrome
%hook YTWatchMiniBarViewController
- (void)updateMiniBarPlayerStateFromRenderer { if (!ytpBool(@"miniplayer")) %orig; }
%end
%hook YTPlaylistMiniBarView
- (void)setFrame:(CGRect)frame { %orig; }
%end
%hook YTPivotBarItemView
- (YTQTMButton *)navigationButton {
    YTQTMButton *button = %orig;
    [YTPMedia sharedMedia].cairo = [[[[self _viewControllerForAncestor] renderer] description] containsString:@"_CAIRO"];
#define NAV_ICON(code,normal,selected) if ([[[self renderer] icon] iconType] == code) { [button setImage:[YTPMedia normal] forState:0]; [button setImage:[YTPMedia selected] forState:4]; }
    NAV_ICON(876,historyTab,historyTabSelected)
    NAV_ICON(877,watchLaterTab,watchLaterTabSelected)
    NAV_ICON(878,postsTab,postsTabSelected)
    NAV_ICON(879,hypeTab,hypeTabSelected)
    NAV_ICON(880,musicTab,musicTabSelected)
    NAV_ICON(881,liveTab,liveTabSelected)
    NAV_ICON(882,gamingTab,gamingTabSelected)
    NAV_ICON(883,sportsTab,sportsTabSelected)
    NAV_ICON(884,notificationsTab,notificationsTabSelected)
#undef NAV_ICON
    return button;
}
- (void)setRenderer:(uintptr_t)renderer {
    %orig;
    [[self navigationButton] setSizeWithPaddingAndInsets:!ytpBool(@"removeLabels")];
    if (ytpBool(@"removeLabels")) [[self navigationButton] setTitle:@"" forState:0];
}
- (void)layoutSubviews {
    %orig;
    if (ytpBool(@"removeIndicators") && [self indicatorDot]) [self indicatorDot].alpha = 0;
}
%end
%hook YTAppViewController
- (void)showPivotBar { if (!ytpBool(@"shortsOnlyMode")) { %orig; isOverlayShown = YES; } }
%end
%end

// Separate original __init_offsets entry 0xb9804c -> 0x1b6d44.
static id (*NavigationOriginalRenderer)(id, SEL);
static id NavigationRenderer(id receiver, SEL selector) {
    id renderer = NavigationOriginalRenderer(receiver, selector);
    if ([[renderer description] containsString:@"_CAIRO"]) [YTPMedia sharedMedia].cairo = YES;
    return renderer;
}
void YTLInstallNavigationChromeEarlyHooks(void) { %init(YTLNavigationChromeEarly); }
void YTLInstallNavigationChromeHooks(void) { %init(YTLNavigationChrome); }
void YTLInstallNavigationChromeRendererHook(void) {
    Class cls = NSClassFromString(@"YTPivotBarViewController");
    if (cls) {
        Method method = class_getInstanceMethod(cls, @selector(renderer));
        if (method) NavigationOriginalRenderer = (id (*)(id, SEL))method_setImplementation(method, (IMP)NavigationRenderer);
    }
}
