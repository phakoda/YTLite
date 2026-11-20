#import "ThemeStylesHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Downloads/YTPMedia.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../Helpers/YTLHelper.h"
#import "../Subtitles/TranslatorVC.h"
#import "../Presentation/DVNImageViewController.h"
#import "../Presentation/DVNSheetPresenter.h"
#import "../Presentation/ToastManager.h"
#import "../Presentation/ToastView.h"
#import "../Presentation/ToastWindow.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <Photos/Photos.h>

static NSString *ThemeText(NSString *key) { return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil]; }
static BOOL ThemeDark(UIView *view) {
    if ([view respondsToSelector:@selector(_mapkit_isDarkModeEnabled)]) return [view _mapkit_isDarkModeEnabled];
    return view._viewControllerForAncestor.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark;
}
static void ThemeNotice(NSString *key) { dispatch_async(dispatch_get_main_queue(), ^{ [ToastManager showMessageWithText:ThemeText(key) isSuccess:YES]; }); }
static void ThemeShowImage(UIImage *image, UIViewController *presenter) {
    DVNImageViewController *viewer = [DVNImageViewController new]; viewer.fullImage = image;
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:viewer];
    nav.modalPresentationStyle = UIModalPresentationFormSheet;
    [presenter presentViewController:nav animated:YES completion:nil];
}
static void ThemeTranslate(NSString *text, _ASDisplayView *view) {
    if (!text) return;
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:[[TranslatorVC alloc] initWithText:text]];
    if ([[%c(YTDefaultTypeStyle) new] respondsToSelector:@selector(ytSansFontOfSize:weight:)]) {
        nav.navigationBar.titleTextAttributes = @{NSFontAttributeName:[[%c(YTDefaultTypeStyle) alloc] ytSansFontOfSize:20 weight:UIFontWeightBold], NSForegroundColorAttributeName:UIColor.labelColor};
    }
    [DVNSheetPresenter presentViewController:nav fromViewController:view._viewControllerForAncestor withHeight:520];
}
static void ThemeCopyText(NSString *text) { if (text) { UIPasteboard.generalPasteboard.string=text; ThemeNotice(@"Copied"); } }
static void ThemeCopyImage(UIImage *image) { UIPasteboard.generalPasteboard.image=image; ThemeNotice(@"Copied"); }
static void ThemeProfile(_ASDisplayView *view, id<YTLThemeNode> node) {
    NSString *url=node.URL.absoluteString;
    if (!url) return;
    NSRange size=[url rangeOfString:@"=s"];
    if (size.location==NSNotFound) return;
    NSRange dash=[url rangeOfString:@"-" options:0 range:NSMakeRange(size.location,url.length-size.location)];
    if (dash.location==NSNotFound) return;
    NSURL *fullURL=[NSURL URLWithString:[url stringByReplacingCharactersInRange:NSMakeRange(size.location+2,dash.location-size.location-2) withString:@"1024"]];
    UIImage *image=[UIImage imageWithData:[NSData dataWithContentsOfURL:fullURL]];
    if (!image) return;
    YTDefaultSheetController *sheet=[%c(YTDefaultSheetController) sheetControllerWithParentResponder:nil];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"SaveProfilePicture") iconImage:[YTPMedia imageWithName:@"image"] style:0 handler:^{ UIImageWriteToSavedPhotosAlbum(image,nil,nil,nil); ThemeNotice(@"Saved"); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"ShowProfilePicture") iconImage:[YTPMedia imageWithName:@"show_image"] style:0 handler:^{ ThemeShowImage(image,view.keepalive_node.closestViewController); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyProfilePicture") iconImage:[YTPMedia imageWithName:@"image_library"] style:0 handler:^{ ThemeCopyImage(image); }]];
    sheet.sourceView=view;
    [sheet presentFromViewController:ToastView.toastWindow.rootViewController animated:YES completion:nil];
}

%group YTLThemeStyles
%hook YTColor
+ (UIColor *)black0 { return ytpBool(@"oledTheme") ? [self blackPure] : %orig; }
+ (UIColor *)black1 { return ytpBool(@"oledTheme") ? [self blackPure] : %orig; }
+ (UIColor *)black2 { return ytpBool(@"oledTheme") ? [self blackPure] : %orig; }
+ (UIColor *)black3 { return ytpBool(@"oledTheme") ? [self blackPure] : %orig; }
+ (UIColor *)black4 { return ytpBool(@"oledTheme") ? [self blackPure] : %orig; }
%new
+ (UIColor *)bgColorForPageStyle:(long long)style { return [UIColor.labelColor colorWithAlphaComponent:style==0 ? 0.05 : 0.10000000149011612]; }
%end
%hook UIView
- (void)setBackgroundColor:(UIColor *)color { %orig(ytpBool(@"oledTheme") ? [YTPMedia oledForColor:color] : color); }
%end
%hook GOODimmingBackgroundView
- (void)layoutSubviews { %orig; self.backgroundColor=ytpBool(@"oledTheme") && [self _mapkit_isDarkModeEnabled] ? [UIColor.whiteColor colorWithAlphaComponent:0.2] : UIColor.blackColor; }
%end
%hook UIKeyboard
- (void)displayLayer:(CALayer *)layer { %orig; if (ytpBool(@"oledKeyboard")) self.backgroundColor=ThemeDark(self) ? UIColor.blackColor : UIColor.clearColor; }
%end
%hook UIPredictionViewController
- (id)_currentTextSuggestions {
    if (ytpBool(@"oledKeyboard")) {
        UIKeyboard *keyboard=[%c(UIKeyboard) activeKeyboard]; BOOL dark=ThemeDark(keyboard);
        self.view.backgroundColor=dark ? UIColor.blackColor : UIColor.clearColor;
        keyboard.backgroundColor=dark ? UIColor.blackColor : UIColor.clearColor;
    }
    return %orig;
}
%end
%hook UIKeyboardDockView
- (void)layoutSubviews { %orig; if (ytpBool(@"oledKeyboard")) self.backgroundColor=ThemeDark(self) ? UIColor.blackColor : UIColor.clearColor; }
%end
%hook UIInputView
- (void)layoutSubviews {
    %orig;
    if (ytpBool(@"oledKeyboard") && ([self isKindOfClass:NSClassFromString(@"TUIEmojiSearchInputView")] || [self isKindOfClass:NSClassFromString(@"_SFAutoFillInputView")])) self.backgroundColor=ThemeDark(self) ? UIColor.blackColor : UIColor.clearColor;
}
%end
%hook UIKBVisualEffectView
- (void)layoutSubviews { %orig; if (ytpBool(@"oledKeyboard") && ThemeDark(self)) { [self setBackgroundEffects:nil]; self.backgroundColor=UIColor.blackColor; } }
%end
%hook NSParagraphStyle
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString *)language { return ytpBool(@"disableRTL") ? NSWritingDirectionLeftToRight : %orig; }
+ (NSWritingDirection)_defaultWritingDirection { return ytpBool(@"disableRTL") ? NSWritingDirectionLeftToRight : %orig; }
%end
%hook UIImageView
- (void)setImage:(UIImage *)image {
    if (ytpInt(@"logoIndex")==1 && [image.description containsString:@"Resources: youtube_logo"]) image=[%c(YTUIResources) youtubePremiumLogoWithPageStyle:[YTPMedia pageStyle]];
    if (ytpInt(@"logoIndex")==2 && [image.description containsString:@"Resources: youtube_premium_logo"]) image=[%c(YTUIResources) youtubeLogoWithPageStyle:[YTPMedia pageStyle]];
    if (ytpInt(@"logoIndex")==3 && ([image.description containsString:@"Resources: youtube_logo"] || [image.description containsString:@"Resources: youtube_premium_logo"])) self.alpha=0;
    %orig(image);
}
- (UIImage *)image {
    UIImage *image=%orig;
    if ([self._viewControllerForAncestor isKindOfClass:NSClassFromString(@"YTInlineMutedPlaybackScrubberViewController")] && [image.description containsString:@"player_scrubber_thumb_cairo"]) {
        NSData *data=[[YTLUserDefaults standardUserDefaults] objectForKey:@"scrubberColor"];
        UIColor *color=[NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:data error:nil];
        if (ytpInt(@"progressBarIndex")!=0 && color) image=[image _flatImageWithColor:color];
    }
    return image;
}
%end
static void ThemeSaveLayer(CALayer *layer, UIColor *background) {
    [YTLHelper genImageFromLayer:layer backgroundColor:background completionHandler:^(UIImage *image) {
        [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
            PHAssetCreationRequest *request=[PHAssetCreationRequest creationRequestForAssetFromImage:image];
            request.creationDate=[NSDate date];
        } completionHandler:^(BOOL success,NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *message=success ? ThemeText(@"Saved") : [NSString stringWithFormat:ThemeText(@"%@: %@"),ThemeText(@"Error"),error.localizedDescription];
                [ToastManager showMessageWithText:message isSuccess:success];
            });
        }];
    }];
}
static void ThemeCopyLayer(CALayer *layer, UIColor *background) {
    [YTLHelper genImageFromLayer:layer backgroundColor:background completionHandler:^(UIImage *image) { ThemeCopyImage(image); }];
}
static void ThemeShowCurrent(NSURL *url) {
    if ([url.absoluteString containsString:@"c-fcrop"]) {
        NSRange crop=[url.absoluteString rangeOfString:@"c-fcrop"];
        url=crop.location==NSNotFound ? nil : [NSURL URLWithString:[url.absoluteString stringByReplacingOccurrencesOfString:[url.absoluteString substringFromIndex:crop.location] withString:@"nd-v1"]];
    }
    UIImage *image=[UIImage imageWithData:[NSData dataWithContentsOfURL:url]];
    ThemeShowImage(image,UIApplication.sharedApplication.delegate.window.rootViewController);
}
%hook _ASDisplayView
- (void)didMoveToWindow {
    %orig;
    if (ytpBool(@"noAds") && [self.accessibilityIdentifier isEqualToString:@"eml.expandable_metadata.vpp"]) [self removeFromSuperview];
}
- (void)setKeepalive_node:(id<YTLThemeNode>)node {
    %orig;
    if (ytpBool(@"oledTheme")) self.backgroundColor=[YTPMedia oledForColor:self.backgroundColor];
    if (ytpBool(@"shortsNoSubButton") && [node.description containsString:@"eml.compact_subscribe_button"] && [self._viewControllerForAncestor isKindOfClass:NSClassFromString(@"YTShortsPlayerViewController")]) self.alpha=0;
    if (ytpBool(@"noPlayerSubButton") && ([node.description containsString:@"eml.animated_subscribe_button"] || [node.description containsString:@"eml.compact_subscribe_button"]) && [self._viewControllerForAncestor isKindOfClass:NSClassFromString(@"YTWatchNextResultsViewController")]) self.alpha=0;
    NSArray *gestures=@[
        @{@"selector":@"postManager:",@"text":@"id.ui.backstage.original_post",@"key":@(ytpBool(@"postManager"))},
        @{@"selector":@"savePFP:",@"text":@"ELMImageNode-View",@"key":@(ytpBool(@"saveProfilePhoto"))},
        @{@"selector":@"savePFP:",@"text":@"decorated-avatar-id",@"key":@(ytpBool(@"saveProfilePhoto"))},
        @{@"selector":@"commentManager:",@"text":@"id.ui.comment_cell",@"key":@(ytpBool(@"commentManager"))}
    ];
    for (NSDictionary *entry in gestures) {
        SEL selector=NSSelectorFromString(entry[@"selector"]);
        if ([entry[@"key"] boolValue] && [self.description containsString:entry[@"text"]]) {
            UILongPressGestureRecognizer *gesture=[[UILongPressGestureRecognizer alloc] initWithTarget:self action:selector];
            gesture.minimumPressDuration=0.3; [self addGestureRecognizer:gesture]; break;
        }
    }
    if (ytpBool(@"oledTheme")) {
        CGFloat white,alpha;
        if ([self.backgroundColor getWhite:&white alpha:&alpha] && white>0.1 && white<0.13 && alpha==1) {
            self.backgroundColor=[UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) { return traits.userInterfaceStyle==UIUserInterfaceStyleDark ? UIColor.blackColor : UIColor.whiteColor; }];
        }
        if ([self.accessibilityIdentifier isEqualToString:@"eml.live_chat_text_message"]) self.backgroundColor=UIColor.clearColor;
    }
}
%new
- (void)savePFP:(UILongPressGestureRecognizer *)sender {
    if (sender.state!=UIGestureRecognizerStateBegan) return;
    if ([self.keepalive_node isKindOfClass:NSClassFromString(@"ASNetworkImageNode")]) { ThemeProfile(self,self.keepalive_node); return; }
    if ([self.description containsString:@"decorated-avatar-id"]) {
        id<YTLThemeNode> root=self.keepalive_node.yogaChildren[0];
        for (id<YTLThemeNode> child in root.yogaChildren) if ([child.description containsString:@"eml.avatar"]) ThemeProfile(self,child);
    }
}
%new
- (void)postManager:(UILongPressGestureRecognizer *)sender {
    if (sender.state!=UIGestureRecognizerStateBegan) return;
    id<YTLThemeNode> node=self.keepalive_node;
    NSString *text=node.copiedComment; NSURL *url=node.copiedURL; CALayer *layer=node.layer;
    UIColor *background=node.closestViewController.view.backgroundColor;
    YTDefaultSheetController *sheet=[%c(YTDefaultSheetController) sheetControllerWithParentResponder:nil];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"TranslatePost") iconImage:[YTPMedia localization] style:0 handler:^{ ThemeTranslate(text,self); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyPostText") iconImage:[YTPMedia imageWithName:@"message"] style:0 handler:^{ ThemeCopyText(text); }]];
    if (url) {
        [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"SaveCurrentImage") iconImage:[YTPMedia imageWithName:@"image"] style:0 handler:^{ [YTLHelper downloadImageFromURL:url download:YES]; }]];
        [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"ShowCurrentImage") iconImage:[YTPMedia imageWithName:@"show_image"] style:0 handler:^{ ThemeShowCurrent(url); }]];
        [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyCurrentImage") iconImage:[YTPMedia imageWithName:@"image_library"] style:0 handler:^{ [YTLHelper downloadImageFromURL:url download:NO]; }]];
    }
    UIColor *purple=[UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:1];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"SavePostAsImage") titleColor:purple iconImage:[YTPMedia imageWithName:@"image"] iconColor:purple disableAutomaticButtonColor:YES accessibilityIdentifier:nil handler:^{ ThemeSaveLayer(layer,background); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyPostAsImage") titleColor:purple iconImage:[YTPMedia imageWithName:@"image_library"] iconColor:purple disableAutomaticButtonColor:YES accessibilityIdentifier:nil handler:^{ ThemeCopyLayer(layer,background); }]];
    sheet.sourceView=self;
    [sheet presentFromViewController:ToastView.toastWindow.rootViewController animated:YES completion:nil];
}
%new
- (void)commentManager:(UILongPressGestureRecognizer *)sender {
    if (sender.state!=UIGestureRecognizerStateBegan) return;
    id<YTLThemeNode> node=self.keepalive_node; NSString *text=node.copiedComment;
    CALayer *layer=self.layer; UIColor *background=node.closestViewController.view.backgroundColor;
    YTDefaultSheetController *sheet=[%c(YTDefaultSheetController) sheetControllerWithParentResponder:nil];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"TranslateComment") iconImage:[YTPMedia localization] style:0 handler:^{ ThemeTranslate(text,self); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyCommentText") iconImage:[YTPMedia imageWithName:@"message"] style:0 handler:^{ ThemeCopyText(text); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"SaveCommentAsImage") iconImage:[YTPMedia imageWithName:@"image"] style:0 handler:^{ ThemeSaveLayer(layer,background); }]];
    [sheet addAction:[%c(YTActionSheetAction) actionWithTitle:ThemeText(@"CopyCommentAsImage") iconImage:[YTPMedia imageWithName:@"image_library"] style:0 handler:^{ ThemeCopyLayer(layer,background); }]];
    sheet.sourceView=self;
    [sheet presentFromViewController:ToastView.toastWindow.rootViewController animated:YES completion:nil];
}
%end
%hook YCHLiveChatView
- (void)layoutSubviews {
    %orig;
    if ([self._viewControllerForAncestor.parentViewController isKindOfClass:%c(YTLivePlayerViewController)]) {
        UIButton *button=[YTLHelper createYTQTMButton:self accessibilityLabel:ThemeText(@"OpenAsRegularVideo") buttonLabel:nil icon:[YTPMedia imageWithName:@"youtube_logo"] selector:@selector(didTapYtlButton:)];
        button.tag=999; button.layer.shadowColor=UIColor.blackColor.CGColor; button.layer.shadowOpacity=0.5f;
        button.layer.shadowOffset=CGSizeZero; button.layer.shadowRadius=4;
        [button.touchFeedbackView setCustomTouchFeedbackColor:UIColor.whiteColor];
        if (self.lightweightInteractivityView && ![self.lightweightInteractivityView viewWithTag:999]) {
            [self.lightweightInteractivityView addSubview:button];
            [button.centerXAnchor constraintEqualToAnchor:self.lightweightInteractivityView.centerXAnchor].active=YES;
            [button.topAnchor constraintEqualToAnchor:self.lightweightInteractivityView.topAnchor].active=YES;
            [button.widthAnchor constraintEqualToConstant:40].active=YES;
            [button.heightAnchor constraintEqualToConstant:40].active=YES;
        }
    }
}
%new
- (void)didTapYtlButton:(id)sender {
    if ([self._viewControllerForAncestor.parentViewController isKindOfClass:%c(YTLivePlayerViewController)]) {
        YTLivePlayerViewController *controller=(YTLivePlayerViewController *)self._viewControllerForAncestor.parentViewController;
        if (controller.activeVideoID) {
            NSString *urlString=[NSString stringWithFormat:@"vnd.youtube://%@",controller.activeVideoID];
            if ([UIApplication.sharedApplication canOpenURL:[NSURL URLWithString:urlString]]) [UIApplication.sharedApplication openURL:[NSURL URLWithString:urlString] options:@{} completionHandler:nil];
        }
    }
}
%end
%end
void YTLInstallThemeStylesHooks(void) { %init(YTLThemeStyles); }
