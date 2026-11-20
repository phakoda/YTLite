#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Hooks/ThemeStylesHost.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Subtitles/TranslatorVC.h"
#import "../source/Presentation/DVNImageViewController.h"
#import "../source/Presentation/DVNSheetPresenter.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastWindow.h"
#import "../source/Presentation/ToastManager.h"
#import "../../Utils/YTLUserDefaults.h"
#import <Photos/Photos.h>
static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { NSLog(@"FAIL %d %s",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
static NSMutableDictionary *prefs;
static NSMutableArray *events,*queued;
static UIImage *fixtureImage;
static NSURL *readURL,*downloadURL,*openedURL;
static BOOL downloadFlag,canOpen=YES,photoSuccess=YES;
static CALayer *generatedLayer;
static UIColor *generatedBackground,*convertedColor;
static UIWindow *toastWindow;
static UIViewController *sheetPresenter;
static NSString *translatedText,*toastText;
static CGFloat sheetHeight;
static BOOL toastSuccess;
BOOL ytpBool(NSString *key) { return [prefs[key] boolValue]; }
NSInteger ytpInt(NSString *key) { return [prefs[key] longLongValue]; }
void ThemeFixtureDispatch(dispatch_queue_t queue,dispatch_block_t block) { CHECK(queue==dispatch_get_main_queue()); [queued addObject:[block copy]]; }
static void Drain(void) { while(queued.count) { dispatch_block_t b=queued[0]; [queued removeObjectAtIndex:0]; b(); } }
@implementation NSData (ThemeFixtureData)
+ (NSData *)themeDataWithContentsOfURL:(NSURL *)url { readURL=url; [events addObject:@"read"]; return [NSData data]; }
@end
@implementation UIResponder @end
@implementation NSLayoutConstraint @end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor { [events addObject:@"anchor"]; return [NSLayoutConstraint new]; }
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)c { CHECK(c==40); NSLayoutConstraint *x=[NSLayoutConstraint new]; x.constant=c; return x; }
@end
@implementation UIView
- (instancetype)init { if((self=[super init])) { _layer=[CALayer layer]; _alpha=1; _subviews=[NSMutableArray array]; _gestureRecognizers=[NSMutableArray array]; } return self; }
- (NSString *)description { return self.fixtureDescription ?: @"fixture"; }
- (UIViewController *)_viewControllerForAncestor { return self.ancestor; }
- (void)layoutSubviews { [events addObject:@"layout"]; }
- (void)didMoveToWindow { [events addObject:@"move"]; }
- (void)removeFromSuperview { self.superview=nil; [events addObject:@"remove"]; }
- (void)addSubview:(UIView *)v { [self.subviews addObject:v]; v.superview=self; }
- (UIView *)viewWithTag:(NSInteger)tag { for(UIView *v in self.subviews)if(v.tag==tag)return v;return nil; }
- (void)addGestureRecognizer:(id)g { [self.gestureRecognizers addObject:g]; }
- (NSLayoutAnchor *)centerXAnchor { return [NSLayoutAnchor new]; }
- (NSLayoutAnchor *)topAnchor { return [NSLayoutAnchor new]; }
- (NSLayoutAnchor *)widthAnchor { return [NSLayoutAnchor new]; }
- (NSLayoutAnchor *)heightAnchor { return [NSLayoutAnchor new]; }
@end
@implementation UITraitCollection @end
@implementation UIColor
+ (BOOL)supportsSecureCoding { return YES; }
- (void)encodeWithCoder:(NSCoder *)coder { [coder encodeObject:self.name forKey:@"name"]; }
- (instancetype)initWithCoder:(NSCoder *)coder { if((self=[super init]))_name=[coder decodeObjectOfClass:NSString.class forKey:@"name"];return self; }
+ (instancetype)named:(NSString *)name white:(CGFloat)white alpha:(CGFloat)alpha { UIColor *c=[self new];c.name=name;c.white=white;c.alpha=alpha;c.gray=YES;return c; }
+ (instancetype)blackColor { return [self named:@"black" white:0 alpha:1]; }
+ (instancetype)whiteColor { return [self named:@"white" white:1 alpha:1]; }
+ (instancetype)clearColor { return [self named:@"clear" white:0 alpha:0]; }
+ (instancetype)labelColor { return [self named:@"label" white:0 alpha:1]; }
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a { CHECK(r==0.75&&g==0.5&&b==0.9&&a==1);return [self named:@"purple" white:0 alpha:a]; }
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))p { UIColor *c=[self new];c.provider=p;return c; }
- (instancetype)colorWithAlphaComponent:(CGFloat)a { return [UIColor named:self.name white:self.white alpha:a]; }
- (BOOL)getWhite:(CGFloat *)w alpha:(CGFloat *)a { if(self.gray){*w=self.white;*a=self.alpha;}return self.gray; }
- (CGColorRef)CGColor { static CGColorRef c; if(!c)c=CGColorCreateGenericGray(0,1);return c; }
@end
@implementation UIImage
- (NSString *)description { return self.fixtureDescription ?: @"image"; }
+ (instancetype)imageWithData:(NSData *)data { return fixtureImage; }
- (UIImage *)_flatImageWithColor:(UIColor *)color { UIImage *i=[UIImage new];i.tint=color;return i; }
@end
@implementation UIImageView
@synthesize image=_image;
- (void)setImage:(UIImage *)image { _image=image; [events addObject:@"setImage"]; }
- (UIImage *)image { [events addObject:@"image"];return _image; }
@end
@implementation UIFont @end
@implementation UINavigationBar @end
@implementation UIViewController
- (instancetype)init { if((self=[super init])){_view=[UIView new];_traitCollection=[UITraitCollection new];}return self; }
- (void)presentViewController:(UIViewController *)c animated:(BOOL)a completion:(void (^)(void))b { CHECK(a&&b==nil);self.presented=c;[events addObject:@"present"]; }
@end
@implementation UINavigationController
- (instancetype)initWithRootViewController:(UIViewController *)c { if((self=[super init])){_root=c;_navigationBar=[UINavigationBar new];}return self; }
@end
@implementation UITableViewController @end
@implementation UIWindow @end
@interface ThemeAppDelegate : NSObject<UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window;
@end
@implementation ThemeAppDelegate @end
@implementation UIApplication
+ (instancetype)sharedApplication { static UIApplication *x; if(!x){x=[self new];ThemeAppDelegate *d=[ThemeAppDelegate new];d.window=[UIWindow new];d.window.rootViewController=[UIViewController new];x.delegate=d;}return x; }
- (BOOL)canOpenURL:(NSURL *)url { [events addObject:@"canOpen"];return canOpen; }
- (void)openURL:(NSURL *)url options:(NSDictionary *)o completionHandler:(void (^)(BOOL))b { CHECK(o.count==0&&b==nil);openedURL=url; }
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard { static UIPasteboard *p;if(!p)p=[self new];return p; }
@end
@implementation UIGestureRecognizer @end
@implementation UILongPressGestureRecognizer
- (instancetype)initWithTarget:(id)t action:(SEL)a { if((self=[super init])){_target=t;_action=a;}return self; }
@end
@implementation UIInputView @end
@implementation UIButton
- (YTLThemeTouchFeedbackView *)touchFeedbackView { return [YTLThemeTouchFeedbackView new]; }
@end
@implementation UILabel @end
@implementation UIScrollView @end
@implementation UIVisualEffectView @end
@implementation UIProgressView @end
@implementation UIStackView @end
@implementation UIActivityIndicatorView @end
@implementation UITableView @end
@implementation UITextView @end
@implementation NSParagraphStyle
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString *)l { [events addObject:l?:@"nilLanguage"];return (NSInteger)0x123456789; }
+ (NSWritingDirection)_defaultWritingDirection { [events addObject:@"direction"];return -7; }
@end
@implementation YTColor
+ (UIColor *)blackPure { return UIColor.blackColor; }
+ (UIColor *)black0 { [events addObject:@"black0"];return UIColor.labelColor; }
+ (UIColor *)black1 { [events addObject:@"black1"];return UIColor.labelColor; }
+ (UIColor *)black2 { [events addObject:@"black2"];return UIColor.labelColor; }
+ (UIColor *)black3 { [events addObject:@"black3"];return UIColor.labelColor; }
+ (UIColor *)black4 { [events addObject:@"black4"];return UIColor.labelColor; }
@end
@implementation GOODimmingBackgroundView
- (BOOL)_mapkit_isDarkModeEnabled { return self.ancestor.traitCollection.userInterfaceStyle==2; }
@end
static UIKeyboard *activeKeyboard;
@implementation UIKeyboard
+ (instancetype)activeKeyboard { return activeKeyboard; }
- (void)displayLayer:(CALayer *)layer { CHECK(layer==self.layer);[events addObject:@"display"]; }
@end
@implementation UIPredictionViewController
- (id)_currentTextSuggestions { [events addObject:@"suggestions"];return @"suggestion-result"; }
@end
@implementation UIKeyboardDockView @end
@implementation UIKBVisualEffectView
- (void)setBackgroundEffects:(NSArray *)effects { CHECK(!effects);[events addObject:@"effects"]; }
@end
@interface TUIEmojiSearchInputView : UIInputView @end
@implementation TUIEmojiSearchInputView @end
@interface _SFAutoFillInputView : UIInputView @end
@implementation _SFAutoFillInputView @end
@interface ThemeMapkitKeyboard : UIKeyboard @end
@implementation ThemeMapkitKeyboard
- (BOOL)_mapkit_isDarkModeEnabled { return YES; }
@end
@implementation YTUIResources
+ (UIImage *)youtubePremiumLogoWithPageStyle:(long long)style { CHECK(style==9);UIImage *i=[UIImage new];i.fixtureDescription=@"premium";return i; }
+ (UIImage *)youtubeLogoWithPageStyle:(long long)style { CHECK(style==9);UIImage *i=[UIImage new];i.fixtureDescription=@"standard";return i; }
@end
@interface ThemeNode : NSObject<YTLThemeNode>
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,strong) NSArray *yogaChildren;
@property(nonatomic,strong) UIViewController *closestViewController;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) NSString *copiedComment;
@property(nonatomic,copy) NSString *fixtureDescription;
@property(nonatomic,strong) NSURL *copiedURL,*URL;
@end
@implementation ThemeNode
- (NSString *)description { return self.fixtureDescription?:@"node"; }
@end
@interface ASNetworkImageNode : ThemeNode @end
@implementation ASNetworkImageNode @end
@implementation _ASDisplayView
@synthesize keepalive_node=_keepalive_node;
- (void)setKeepalive_node:(id<YTLThemeNode>)node { _keepalive_node=node;[events addObject:@"node"]; }
- (id<YTLThemeNode>)keepalive_node { return _keepalive_node; }
@end
static YTDefaultSheetController *lastSheet;
@interface YTActionSheetAction ()
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) void (^handler)(void);
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)t iconImage:(UIImage *)i style:(NSInteger)s handler:(void (^)(void))b { CHECK(s==0);YTActionSheetAction *a=[self new];a.title=t;a.handler=b;return a; }
+ (instancetype)actionWithTitle:(NSString *)t titleColor:(UIColor *)c iconImage:(UIImage *)i iconColor:(UIColor *)ic disableAutomaticButtonColor:(BOOL)d accessibilityIdentifier:(NSString *)a handler:(void (^)(void))b { CHECK([c.name isEqual:@"purple"]&&[ic.name isEqual:@"purple"]&&d&&!a);return [self actionWithTitle:t iconImage:i style:0 handler:b]; }
@end
@interface YTDefaultSheetController ()
@property(nonatomic,strong) NSMutableArray<YTActionSheetAction *> *actions;
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithParentResponder:(UIResponder *)r { CHECK(r==nil);lastSheet=[self new];lastSheet.actions=[NSMutableArray array];return lastSheet; }
- (void)addAction:(YTActionSheetAction *)a { [self.actions addObject:a]; }
- (void)presentFromViewController:(UIViewController *)c animated:(BOOL)a completion:(void (^)(void))b { CHECK(c==toastWindow.rootViewController&&a&&!b); }
@end
@implementation YTDefaultTypeStyle
- (UIFont *)ytSansFontOfSize:(CGFloat)s weight:(CGFloat)w { CHECK(s==20&&w==UIFontWeightBold);return [UIFont new]; }
@end
@implementation YTLThemeTouchFeedbackView
- (void)setCustomTouchFeedbackColor:(UIColor *)c { CHECK([c.name isEqual:@"white"]); }
@end
@interface YCHLiveChatView ()
@property(nonatomic,strong) UIView *lightweightInteractivityView;
@end
@implementation YCHLiveChatView @end
@interface YTLivePlayerViewController ()
@property(nonatomic,copy) NSString *activeVideoID;
@end
@implementation YTLivePlayerViewController @end
@interface YTShortsPlayerViewController : UIViewController @end
@implementation YTShortsPlayerViewController @end
@interface YTWatchNextResultsViewController : UIViewController @end
@implementation YTWatchNextResultsViewController @end
@interface YTInlineMutedPlaybackScrubberViewController : UIViewController @end
@implementation YTInlineMutedPlaybackScrubberViewController @end
@implementation YTPMedia
+ (long long)pageStyle { return 9; }
+ (UIColor *)oledForColor:(UIColor *)c { [events addObject:@"oled"];return convertedColor ?: c; }
+ (UIImage *)imageWithName:(NSString *)n { UIImage *i=[UIImage new];i.fixtureDescription=n;return i; }
+ (UIImage *)localization { return [self imageWithName:@"localization"]; }
@end
@implementation YTLHelper
+ (void)downloadImageFromURL:(NSURL *)u download:(BOOL)d { downloadURL=u;downloadFlag=d; }
+ (void)genImageFromLayer:(CALayer *)l backgroundColor:(UIColor *)c completionHandler:(void (^)(UIImage *))b { generatedLayer=l;generatedBackground=c;b(fixtureImage); }
+ (UIButton *)createYTQTMButton:(id)t accessibilityLabel:(NSString *)a buttonLabel:(NSString *)b icon:(UIImage *)i selector:(SEL)s { CHECK([a isEqual:@"OpenAsRegularVideo"]&&!b&&s==@selector(didTapYtlButton:));return [UIButton new]; }
@end
@implementation TranslatorVC
- (instancetype)initWithText:(NSString *)text { if((self=[super init]))translatedText=text;return self; }
@end
@implementation DVNImageViewController @end
@implementation DVNSheetPresenter
+ (void)presentViewController:(UIViewController *)c fromViewController:(UIViewController *)p withHeight:(double)h { sheetPresenter=p;sheetHeight=h; }
@end
@implementation ToastView
+ (ToastWindow *)toastWindow { return (ToastWindow *)toastWindow; }
@end
@implementation ToastManager
+ (void)showMessageWithText:(NSString *)t isSuccess:(BOOL)s { toastText=t;toastSuccess=s; }
@end
@implementation NSBundle (ThemeFixtureBundle)
+ (NSBundle *)ytl_defaultBundle { return NSBundle.mainBundle; }
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults { static YTLUserDefaults *d;if(!d)d=[[self alloc]initWithSuiteName:@"theme-fixture"];return d; }
- (id)objectForKey:(NSString *)k { return prefs[k]; }
@end
void UIImageWriteToSavedPhotosAlbum(UIImage *i,id t,SEL s,void *c) { CHECK(i==fixtureImage&&!t&&!s&&!c);[events addObject:@"saveImage"]; }
@implementation PHPhotoLibrary
+ (instancetype)sharedPhotoLibrary { static PHPhotoLibrary *p;if(!p)p=[self new];return p; }
- (void)performChanges:(void (^)(void))b completionHandler:(void (^)(BOOL,NSError *))c { b();c(photoSuccess,[NSError errorWithDomain:@"fixture" code:1 userInfo:@{NSLocalizedDescriptionKey:@"failure"}]); }
@end
@implementation PHAssetCreationRequest
+ (instancetype)creationRequestForAssetFromImage:(UIImage *)i { CHECK(i==fixtureImage);return [self new]; }
@end
static UIImage *Image(NSString *s) { UIImage *i=[UIImage new];i.fixtureDescription=s;return i; }
static void Action(NSString *title) { for(YTActionSheetAction *a in lastSheet.actions)if([a.title isEqual:title]){a.handler();return;}CHECK(NO); }
static void Reset(void) { [events removeAllObjects];[prefs removeAllObjects];lastSheet=nil;readURL=nil;downloadURL=nil;openedURL=nil;translatedText=nil;toastText=nil; }
int main(void) { @autoreleasepool {
    prefs=[NSMutableDictionary dictionary];events=[NSMutableArray array];queued=[NSMutableArray array];
    fixtureImage=Image(@"downloaded");toastWindow=[UIWindow new];toastWindow.rootViewController=[UIViewController new];
    YTLInstallThemeStylesHooks();
    for(NSInteger enabled=0;enabled<2;enabled++) {
        prefs[@"oledTheme"]=@(enabled);
        for(NSString *s in @[@"black0",@"black1",@"black2",@"black3",@"black4"]) {
            [events removeAllObjects];
            UIColor *c=((UIColor *(*)(id,SEL))[YTColor methodForSelector:NSSelectorFromString(s)])(YTColor.class,NSSelectorFromString(s));
            CHECK([c.name isEqual:enabled?@"black":@"label"]);CHECK(events.count==(enabled?0:1));
        }
        UIView *view=[UIView new];UIColor *c=UIColor.whiteColor;[events removeAllObjects];view.backgroundColor=c;
        CHECK(view.backgroundColor==c&&events.count==(enabled?1:0));
        for(NSInteger dark=0;dark<2;dark++) {
            GOODimmingBackgroundView *v=[GOODimmingBackgroundView new];v.ancestor=[UIViewController new];v.ancestor.traitCollection.userInterfaceStyle=dark?2:1;[v layoutSubviews];
            CHECK([v.backgroundColor.name isEqual:enabled&&dark?@"white":@"black"]);CHECK(v.backgroundColor.alpha==(enabled&&dark?0.2:1));
        }
    }
    CHECK([YTColor bgColorForPageStyle:0].alpha==0.05);
    CHECK([YTColor bgColorForPageStyle:0x100000000LL].alpha==0.10000000149011612);
    Reset();
    for(NSInteger enabled=0;enabled<2;enabled++)for(NSInteger dark=0;dark<2;dark++) {
        prefs[@"oledKeyboard"]=@(enabled);
        NSArray *views=@[[UIKeyboard new],[UIKeyboardDockView new],[UIInputView new],[TUIEmojiSearchInputView new],[_SFAutoFillInputView new],[UIKBVisualEffectView new]];
        for(UIView *v in views) {
            v.ancestor=[UIViewController new];v.ancestor.traitCollection.userInterfaceStyle=dark?2:1;
            [events removeAllObjects];
            if([v isKindOfClass:UIKeyboard.class])[(UIKeyboard *)v displayLayer:v.layer];else[v layoutSubviews];
            CHECK(events.count>=1);
            BOOL qualifies=enabled&&![v isMemberOfClass:UIInputView.class]&&(![v isKindOfClass:UIKBVisualEffectView.class]||dark);
            CHECK(qualifies?[v.backgroundColor.name isEqual:dark?@"black":@"clear"]:v.backgroundColor==nil);
            CHECK([events containsObject:@"effects"]==(enabled&&dark&&[v isKindOfClass:UIKBVisualEffectView.class]));
        }
        activeKeyboard=[UIKeyboard new];activeKeyboard.ancestor=[UIViewController new];activeKeyboard.ancestor.traitCollection.userInterfaceStyle=dark?2:1;
        UIPredictionViewController *p=[UIPredictionViewController new];[events removeAllObjects];
        CHECK([[p _currentTextSuggestions] isEqual:@"suggestion-result"]);
        CHECK([events.lastObject isEqual:@"suggestions"]);
        CHECK(enabled?[p.view.backgroundColor.name isEqual:dark?@"black":@"clear"]:p.view.backgroundColor==nil);
        CHECK(enabled?[activeKeyboard.backgroundColor.name isEqual:dark?@"black":@"clear"]:activeKeyboard.backgroundColor==nil);
    }
    prefs[@"oledKeyboard"]=@YES;ThemeMapkitKeyboard *mk=[ThemeMapkitKeyboard new];[mk displayLayer:mk.layer];CHECK([mk.backgroundColor.name isEqual:@"black"]);
    Reset();CHECK([NSParagraphStyle defaultWritingDirectionForLanguage:@"ar"]==(NSInteger)0x123456789);CHECK([NSParagraphStyle _defaultWritingDirection]==-7);
    prefs[@"disableRTL"]=@YES;[events removeAllObjects];CHECK([NSParagraphStyle defaultWritingDirectionForLanguage:nil]==0);CHECK([NSParagraphStyle _defaultWritingDirection]==0&&events.count==0);
    for(NSInteger index=0;index<4;index++)for(NSString *name in @[@"other",@"Resources: youtube_logo_dark",@"Resources: youtube_premium_logo_white"]) {
        Reset();prefs[@"logoIndex"]=@(index);UIImageView *v=[UIImageView new];UIImage *im=Image(name);v.image=im;
        CHECK([events.firstObject isEqual:@"setImage"]);
        NSString *expected=index==1&&[name containsString:@"Resources: youtube_logo"]?@"premium":index==2&&[name containsString:@"Resources: youtube_premium_logo"]?@"standard":name;
        CHECK([v.image.description isEqual:expected]);CHECK(v.alpha==(index==3&&![name isEqual:@"other"]?0:1));
    }
    for(NSInteger ancestor=0;ancestor<2;ancestor++)for(NSInteger enabled=0;enabled<2;enabled++) {
        Reset();prefs[@"progressBarIndex"]=@(enabled);UIColor *color=UIColor.whiteColor;
        prefs[@"scrubberColor"]=[NSKeyedArchiver archivedDataWithRootObject:color requiringSecureCoding:YES error:nil];
        UIImageView *v=[UIImageView new];v.ancestor=ancestor?[YTInlineMutedPlaybackScrubberViewController new]:[UIViewController new];UIImage *im=Image(@"player_scrubber_thumb_cairo");v.image=im;
        CHECK(ancestor&&enabled?[v.image.tint.name isEqual:@"white"]:v.image==im);
    }
    Reset();_ASDisplayView *v=[_ASDisplayView new];v.accessibilityIdentifier=@"eml.expandable_metadata.vpp";v.superview=[UIView new];prefs[@"noAds"]=@YES;[v didMoveToWindow];CHECK([events isEqual:@[@"move",@"remove"]]&&v.superview==nil);
    NSArray *descriptions=@[@"id.ui.backstage.original_post",@"ELMImageNode-View",@"decorated-avatar-id",@"id.ui.comment_cell"];
    NSArray *keys=@[@"postManager",@"saveProfilePhoto",@"saveProfilePhoto",@"commentManager"];
    for(NSUInteger i=0;i<4;i++) {
        Reset();v=[_ASDisplayView new];v.fixtureDescription=descriptions[i];prefs[keys[i]]=@YES;v.keepalive_node=[ThemeNode new];
        CHECK(v.gestureRecognizers.count==1);UILongPressGestureRecognizer *g=v.gestureRecognizers[0];CHECK(g.minimumPressDuration==0.3&&g.target==v);CHECK(g.action==(i==0?@selector(postManager:):i==3?@selector(commentManager:):@selector(savePFP:)));
        v.keepalive_node=[ThemeNode new];CHECK(v.gestureRecognizers.count==2);
    }
    Reset();prefs[@"shortsNoSubButton"]=@YES;v=[_ASDisplayView new];v.ancestor=[YTShortsPlayerViewController new];ThemeNode *node=[ThemeNode new];node.fixtureDescription=@"eml.compact_subscribe_button";v.keepalive_node=node;CHECK(v.alpha==0);
    Reset();prefs[@"noPlayerSubButton"]=@YES;v=[_ASDisplayView new];v.ancestor=[YTWatchNextResultsViewController new];node.fixtureDescription=@"eml.animated_subscribe_button";v.keepalive_node=node;CHECK(v.alpha==0);
    for(NSNumber *white in @[@0.1,@0.11,@0.13]) {
        Reset();prefs[@"oledTheme"]=@YES;v=[_ASDisplayView new];UIColor *c=UIColor.blackColor;c.white=white.doubleValue;v.backgroundColor=c;v.keepalive_node=node;
        CHECK((v.backgroundColor.provider!=nil)==(white.doubleValue>0.1&&white.doubleValue<0.13));
        if(v.backgroundColor.provider){UITraitCollection *t=[UITraitCollection new];t.userInterfaceStyle=2;CHECK([v.backgroundColor.provider(t).name isEqual:@"black"]);t.userInterfaceStyle=1;CHECK([v.backgroundColor.provider(t).name isEqual:@"white"]);}
    }
    Reset();prefs[@"oledTheme"]=@YES;v=[_ASDisplayView new];v.accessibilityIdentifier=@"eml.live_chat_text_message";v.keepalive_node=node;CHECK([v.backgroundColor.name isEqual:@"clear"]);
    Reset();v=[_ASDisplayView new];node=[ThemeNode new];node.closestViewController=[UIViewController new];node.closestViewController.view.backgroundColor=UIColor.whiteColor;node.layer=[CALayer layer];node.copiedComment=@"body";node.copiedURL=[NSURL URLWithString:@"https://fixture.invalid/image=c-fcrop-tail"];v.keepalive_node=node;v.ancestor=[UIViewController new];
    UILongPressGestureRecognizer *gesture=[UILongPressGestureRecognizer new];gesture.state=0;[v postManager:gesture];CHECK(!lastSheet);[v commentManager:gesture];CHECK(!lastSheet);[v savePFP:gesture];CHECK(!lastSheet);
    gesture.state=1;[v postManager:gesture];CHECK(lastSheet.actions.count==7&&lastSheet.sourceView==v);CHECK([[lastSheet.actions valueForKey:@"title"] isEqual:@[@"TranslatePost",@"CopyPostText",@"SaveCurrentImage",@"ShowCurrentImage",@"CopyCurrentImage",@"SavePostAsImage",@"CopyPostAsImage"]]);
    Action(@"TranslatePost");CHECK([translatedText isEqual:@"body"]&&sheetHeight==520&&sheetPresenter==v.ancestor);
    Action(@"CopyPostText");CHECK([UIPasteboard.generalPasteboard.string isEqual:@"body"]);Drain();CHECK([toastText isEqual:@"Copied"]&&toastSuccess);
    Action(@"SaveCurrentImage");CHECK(downloadURL==node.copiedURL&&downloadFlag);Action(@"CopyCurrentImage");CHECK(downloadURL==node.copiedURL&&!downloadFlag);
    Action(@"ShowCurrentImage");CHECK([readURL.absoluteString isEqual:@"https://fixture.invalid/image=nd-v1"]);CHECK([UIApplication.sharedApplication.delegate.window.rootViewController.presented isKindOfClass:UINavigationController.class]);
    Action(@"SavePostAsImage");Drain();CHECK(generatedLayer==node.layer&&generatedBackground==node.closestViewController.view.backgroundColor&&[toastText isEqual:@"Saved"]&&toastSuccess);
    photoSuccess=NO;Action(@"SavePostAsImage");Drain();CHECK([toastText isEqual:@"Error: failure"]&&!toastSuccess);photoSuccess=YES;
    Action(@"CopyPostAsImage");Drain();CHECK(UIPasteboard.generalPasteboard.image==fixtureImage&&[toastText isEqual:@"Copied"]);
    node.copiedURL=nil;[v postManager:gesture];CHECK(lastSheet.actions.count==4);
    [v commentManager:gesture];CHECK([[lastSheet.actions valueForKey:@"title"] isEqual:@[@"TranslateComment",@"CopyCommentText",@"SaveCommentAsImage",@"CopyCommentAsImage"]]);
    Action(@"TranslateComment");CHECK([translatedText isEqual:@"body"]);Action(@"CopyCommentText");Drain();Action(@"SaveCommentAsImage");Drain();CHECK(generatedLayer==v.layer);Action(@"CopyCommentAsImage");Drain();CHECK(generatedLayer==v.layer);
    ASNetworkImageNode *avatar=[ASNetworkImageNode new];avatar.URL=[NSURL URLWithString:@"https://fixture.invalid/avatar=s88-c"];avatar.closestViewController=node.closestViewController;v.keepalive_node=avatar;[v savePFP:gesture];CHECK(lastSheet.actions.count==3&&[readURL.absoluteString isEqual:@"https://fixture.invalid/avatar=s1024-c"]);
    Action(@"SaveProfilePicture");Drain();CHECK([toastText isEqual:@"Saved"]);Action(@"ShowProfilePicture");CHECK([avatar.closestViewController.presented isKindOfClass:UINavigationController.class]);Action(@"CopyProfilePicture");Drain();CHECK(UIPasteboard.generalPasteboard.image==fixtureImage);
    v.fixtureDescription=@"decorated-avatar-id";ThemeNode *root=[ThemeNode new];avatar.fixtureDescription=@"eml.avatar";root.yogaChildren=@[avatar];node.yogaChildren=@[root];v.keepalive_node=node;lastSheet=nil;[v savePFP:gesture];CHECK(lastSheet!=nil);
    Reset();YCHLiveChatView *chat=[YCHLiveChatView new];chat.ancestor=[UIViewController new];YTLivePlayerViewController *live=[YTLivePlayerViewController new];chat.ancestor.parentViewController=live;chat.lightweightInteractivityView=[UIView new];[chat layoutSubviews];CHECK(chat.lightweightInteractivityView.subviews.count==1);UIView *button=chat.lightweightInteractivityView.subviews[0];CHECK(button.tag==999&&button.layer.shadowOpacity==0.5f&&button.layer.shadowRadius==4);[chat layoutSubviews];CHECK(chat.lightweightInteractivityView.subviews.count==1);
    live.activeVideoID=@"abc123";[chat didTapYtlButton:nil];CHECK([openedURL.absoluteString isEqual:@"vnd.youtube://abc123"]);openedURL=nil;canOpen=NO;[chat didTapYtlButton:nil];CHECK(!openedURL);canOpen=YES;live.activeVideoID=nil;[chat didTapYtlButton:nil];CHECK(!openedURL);
    Reset();prefs[@"oledTheme"]=@YES;convertedColor=UIColor.clearColor;UIView *converted=[UIView new];converted.backgroundColor=UIColor.whiteColor;CHECK(converted.backgroundColor==convertedColor);convertedColor=nil;
    Reset();prefs[@"oledKeyboard"]=@YES;UIKeyboard *noAncestor=[UIKeyboard new];[noAncestor displayLayer:noAncestor.layer];CHECK([noAncestor.backgroundColor.name isEqual:@"clear"]);
    Reset();v=[_ASDisplayView new];v.accessibilityIdentifier=@"eml.expandable_metadata.vpp";UIView *parent=[UIView new];v.superview=parent;[v didMoveToWindow];CHECK(v.superview==parent&&[events isEqual:@[@"move"]]);
    Reset();prefs[@"shortsNoSubButton"]=@YES;prefs[@"noPlayerSubButton"]=@YES;v=[_ASDisplayView new];v.ancestor=[UIViewController new];node.fixtureDescription=@"eml.compact_subscribe_button";v.keepalive_node=node;CHECK(v.alpha==1);
    Reset();prefs[@"oledTheme"]=@YES;v=[_ASDisplayView new];UIColor *translucent=UIColor.blackColor;translucent.white=0.11;translucent.alpha=0.5;v.backgroundColor=translucent;v.keepalive_node=node;CHECK(v.backgroundColor==translucent);translucent.alpha=1;translucent.gray=NO;v.keepalive_node=node;CHECK(v.backgroundColor==translucent);
    Reset();v=[_ASDisplayView new];avatar=[ASNetworkImageNode new];v.keepalive_node=avatar;
    for(id candidate in @[[NSNull null],@"https://fixture.invalid/image",@"https://fixture.invalid/image=s88"]) { avatar.URL=candidate==NSNull.null?nil:[NSURL URLWithString:candidate];[v savePFP:gesture];CHECK(lastSheet==nil&&readURL==nil); }
    avatar.URL=[NSURL URLWithString:@"https://fixture.invalid/image=s88-c"];UIImage *savedFixture=fixtureImage;fixtureImage=nil;[v savePFP:gesture];CHECK(lastSheet==nil&&readURL!=nil);fixtureImage=savedFixture;
    Reset();v=[_ASDisplayView new];node=[ThemeNode new];node.closestViewController=[UIViewController new];node.layer=[CALayer layer];node.copiedComment=@"captured text";NSURL *capturedURL=[NSURL URLWithString:@"https://fixture.invalid/plain"];node.copiedURL=capturedURL;v.keepalive_node=node;[v postManager:gesture];node.copiedComment=@"changed";node.copiedURL=nil;Action(@"CopyPostText");Drain();CHECK([UIPasteboard.generalPasteboard.string isEqual:@"captured text"]);Action(@"SaveCurrentImage");CHECK(downloadURL==capturedURL);Action(@"ShowCurrentImage");CHECK([readURL isEqual:capturedURL]);
    node.copiedComment=nil;[v commentManager:gesture];translatedText=nil;[queued removeAllObjects];Action(@"TranslateComment");Action(@"CopyCommentText");CHECK(!translatedText&&queued.count==0);
    Reset();chat=[YCHLiveChatView new];[chat layoutSubviews];CHECK([events isEqual:@[@"layout"]]);[chat didTapYtlButton:nil];CHECK(!openedURL);
    NSLog(@"ThemeStyles: %lu real Logos runtime checks passed",(unsigned long)checks);
}return 0;}
