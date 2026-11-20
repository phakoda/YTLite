#import "downloads_doubles.h"
#import <objc/runtime.h>
#import "../source/Downloads/DownloadsHost.h"
// Boundary doubles only. Production code is linked unmodified into this harness.
NSString *DownloadsFixtureRoot, *DownloadsBundleVersion;
NSMutableDictionary *DownloadsPreferences;
NSMutableArray *DownloadsEvents;
long long DownloadsFreeSpace;
BOOL DownloadsAuthorized;
NSError *DownloadsAudioCategoryError, *DownloadsAudioPlayerError;
int DownloadsFFmpegResult;
NSString *DownloadsFFmpegLog;
id DownloadsSRTResult;
NSError *DownloadsSRTError;
YTDefaultSheetController *DownloadsLastSheet;
ToastView *DownloadsLastToast;
DownloadsSession *DownloadsLastSession, *DownloadsSharedSession;
NSString * const NSForegroundColorAttributeName = @"NSColor";
NSString * const NSFontAttributeName = @"NSFont";
NSString * const NSBaselineOffsetAttributeName = @"NSBaselineOffset";
NSString * const AVAudioSessionCategoryPlayback = @"AVAudioSessionCategoryPlayback";
const int RETURN_CODE_SUCCESS = 0, RETURN_CODE_CANCEL = 255;
static void Event(NSDictionary *event) { @synchronized (DownloadsEvents) { [DownloadsEvents addObject:event]; } }
static id NotNil(id value) { return value ?: [NSNull null]; }
// Feature policy is the actual production YTLFeaturePolicy.m, not an auth mock.
NSString *DownloadsTestTemporaryDirectory(void) { return [DownloadsFixtureRoot stringByAppendingString:@"/temporary/"]; }
@implementation UITraitCollection @end
@implementation UIColor
+ (UIColor *)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a { UIColor *c=[self new];c.red=r;c.green=g;c.blue=b;c.alpha=a;return c; }
+ (UIColor *)blackColor { return [self colorWithRed:0 green:0 blue:0 alpha:1]; }
+ (UIColor *)whiteColor { return [self colorWithRed:1 green:1 blue:1 alpha:1]; }
+ (UIColor *)redColor { return [self colorWithRed:1 green:0 blue:0 alpha:1]; }
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider { UIColor *c=[self new];c.provider=provider;return c; }
- (BOOL)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a {
    if (self.provider) return [self.provider([UITraitCollection new]) getRed:r green:g blue:b alpha:a];
    if (self.cannotDecode) return NO;
    if(r)*r=self.red;if(g)*g=self.green;if(b)*b=self.blue;if(a)*a=self.alpha;return YES;
}
@end
@implementation UIImage
+ (UIImage *)imageWithData:(NSData *)data { if(!data)return nil;UIImage *i=[self new];i.data=data;return i; }
+ (UIImage *)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits { (void)bundle;(void)traits;UIImage *i=[self new];i.name=name;return i; }
@end
@implementation UIFont
+ (UIFont *)systemFontOfSize:(CGFloat)size { UIFont *f=[self new];f.pointSize=size;return f; }
@end
NSString * const UIActivityTypeAssignToContact = @"fixture-assign-contact";
NSString * const UIActivityTypePrint = @"fixture-print";
@implementation UIView @end
@implementation UIButton
- (void)setAttributedTitle:(NSAttributedString *)title forState:(UIControlState)state { (void)state;self.currentAttributedTitle=title; }
@end
@implementation UIViewController
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion { self.presented=controller;Event(@{@"kind":@"presentation",@"controller":controller,@"animated":@(animated)});if(completion)completion(); }
@end
@implementation UINavigationController
- (instancetype)initWithRootViewController:(UIViewController *)root { if((self=[super init]))self.root=root;return self; }
@end
@implementation UIWindow @end
@implementation UIApplication
+ (UIApplication *)sharedApplication { static UIApplication *a;static dispatch_once_t once;dispatch_once(&once,^{a=[self new];});return a; }
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion { self.openedURL=url;self.openedOptions=options;completion(self.openResult); }
@end
@implementation UIPasteboard
+ (UIPasteboard *)generalPasteboard { static UIPasteboard *p;static dispatch_once_t once;dispatch_once(&once,^{p=[self new];});return p; }
@end
@implementation UIPopoverPresentationController @end
@implementation UIActivityViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities { (void)activities;if((self=[super init])){self.items=items;self.popoverPresentationController=[UIPopoverPresentationController new];}return self; }
@end
@implementation AVPlayerViewController @end
@implementation AVAudioSession
+ (AVAudioSession *)sharedInstance { static AVAudioSession *s;static dispatch_once_t once;dispatch_once(&once,^{s=[self new];});return s; }
- (BOOL)setCategory:(NSString *)category withOptions:(AVAudioSessionCategoryOptions)options error:(NSError **)error { self.category=category;self.options=options;if(error&&DownloadsAudioCategoryError)*error=DownloadsAudioCategoryError;return !DownloadsAudioCategoryError; }
@end
@implementation AVAudioPlayer
- (instancetype)initWithContentsOfURL:(NSURL *)url error:(NSError **)error { if((self=[super init])){self.url=url;if(error&&DownloadsAudioPlayerError)*error=DownloadsAudioPlayerError;}return self; }
- (BOOL)prepareToPlay { self.prepareCount++;return YES; }
- (BOOL)play { self.playCount++;self.playing=YES;return YES; }
- (void)stop { self.stopCount++;self.playing=NO; }
@end
@implementation AVPlayer
+ (instancetype)playerWithURL:(NSURL *)url { AVPlayer *p=[self new];p.url=url;return p; }
- (void)play { self.playing=YES; }
@end
@interface DownloadsBundle : NSObject @end
@implementation DownloadsBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table { (void)value;(void)table;return [key isEqual:@"Error.NoSpace"]?@"Need %@; free %@":key; }
- (NSString *)pathForResource:(NSString *)name ofType:(NSString *)extension { return [DownloadsFixtureRoot stringByAppendingPathComponent:[name stringByAppendingPathExtension:extension]]; }
- (UIImage *)imageWithName:(NSString *)name { if(!name)return nil;UIImage *i=[UIImage new];i.name=name;return i; }
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color { UIImage *i=[self imageWithName:name];i.tint=color;return i; }
@end
@implementation NSBundle (YTPDownloadsHost)
+ (NSBundle *)ytl_defaultBundle { static DownloadsBundle *b;static dispatch_once_t once;dispatch_once(&once,^{b=[DownloadsBundle new];});return (id)b; }
- (UIImage *)imageWithName:(NSString *)name { return [(DownloadsBundle *)(id)[NSBundle ytl_defaultBundle] imageWithName:name]; }
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color { return [(DownloadsBundle *)(id)[NSBundle ytl_defaultBundle] imageWithName:name tintColor:color]; }
@end
@implementation YTLUserDefaults
+ (BOOL)boolForKey:(NSString *)key { Event(@{@"kind":@"boolPref",@"key":key});return [DownloadsPreferences[key] boolValue]; }
+ (long long)integerForKey:(NSString *)key { Event(@{@"kind":@"intPref",@"key":key});return [DownloadsPreferences[key] longLongValue]; }
+ (double)floatForKey:(NSString *)key { return [DownloadsPreferences[key] doubleValue]; }
+ (instancetype)standardUserDefaults { static YTLUserDefaults *d;static dispatch_once_t once;dispatch_once(&once,^{d=[self new];});return d; }
- (BOOL)boolForKey:(NSString *)key { return [YTLUserDefaults boolForKey:key]; }
- (NSInteger)integerForKey:(NSString *)key { return (NSInteger)[YTLUserDefaults integerForKey:key]; }
- (void)setInteger:(long long)value forKey:(NSString *)key { DownloadsPreferences[key]=@(value);Event(@{@"kind":@"setPref",@"key":key,@"value":@(value)}); }
@end
@implementation DownloadsNode
- (void)pause { self.paused=YES; }
@end
@implementation DownloadsOldPlayer @end
@implementation DownloadsRoot @end
@implementation DownloadsAppDelegate @end
@implementation YTActionSheetAction
+ (id)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon style:(long long)style handler:(void (^)(void))handler { (void)style;YTActionSheetAction *a=[self new];a.title=title;a.icon=icon;a.handler=handler;a.button=[UIButton new];a.button.currentAttributedTitle=[[NSAttributedString alloc]initWithString:title?:@""];return a; }
+ (id)actionWithTitle:(NSString *)title currentValue:(NSString *)value iconImage:(UIImage *)icon accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler { (void)identifier;YTActionSheetAction *a=[self actionWithTitle:title iconImage:icon style:0 handler:handler];a.value=value;return a; }
+ (id)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler { (void)identifier;YTActionSheetAction *a=[self actionWithTitle:title iconImage:icon style:0 handler:handler];a.secondary=secondary;return a; }
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithParentResponder:(id)parent { (void)parent;YTDefaultSheetController *s=[self new];s.actions=[NSMutableArray array];return s; }
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent { (void)delegate;YTDefaultSheetController *s=[self sheetControllerWithParentResponder:parent];s.message=message;s.subMessage=subMessage;return s; }
- (void)addAction:(id)action { [self.actions addObject:action]; }
- (void)setSourceView:(id)source { self.source=source; }
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion { (void)animated;self.presenter=controller;DownloadsLastSheet=self;if(completion)completion(); }
- (id)valueForKey:(NSString *)key { return [key isEqual:@"_headerView"]?self:[super valueForKey:key]; }
- (void)showHeaderDivider { self.divider=YES; }
@end
@implementation ToastView
+ (UIWindow *)toastWindow { static UIWindow *w;static dispatch_once_t once;dispatch_once(&once,^{w=[UIWindow new];w.rootViewController=[UIViewController new];});return w; }
- (instancetype)init { if((self=[super init]))DownloadsLastToast=self;return self; }
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success { self.text=text;self.success=success;DownloadsLastToast=self;Event(@{@"kind":@"toast",@"text":NotNil(text),@"success":@(success)}); }
- (void)showLoaderWithText:(NSString *)text withStop:(BOOL)withStop stopCompletion:(void (^)(void))completion { self.text=text;self.withStop=withStop;self.stop=completion;DownloadsLastToast=self; }
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)withStop stopCompletion:(void (^)(void))completion { [self showLoaderWithText:text withStop:withStop stopCompletion:completion];self.progress=progress; }
- (void)updateText:(NSString *)text progress:(float)progress { self.text=text;self.progress=progress; }
- (void)showToast:(NSString *)text { self.text=text;DownloadsLastToast=self; }
- (void)hide { self.hidden=YES; }
@end
@interface YTToastController : NSObject @end
@implementation YTToastController
- (void)showMessage:(NSString *)text { Event(@{@"kind":@"legacyToast",@"text":NotNil(text)}); }
@end
@interface YTUIResources : NSObject @end
@implementation YTUIResources
+ (UIImage *)chevronRightImage { UIImage *i=[UIImage new];i.name=@"host-chevron";return i; }
@end
@interface YTUIUtils : NSObject @end
@implementation YTUIUtils
+ (UIViewController *)topViewControllerForPresenting { return [ToastView toastWindow].rootViewController; }
+ (UIView *)sourceViewForActionSheetFromSourceView:(UIView *)source { return source; }
@end
@interface YTAutoOfflineController : NSObject @end
@implementation YTAutoOfflineController
- (long long)freeDeviceStorageBytes { return DownloadsFreeSpace; }
@end
@interface YTLHelper : NSObject @end
@implementation YTLHelper
+ (void)downloadImageFromURL:(NSURL *)url download:(BOOL)download { Event(@{@"kind":@"imagePipeline",@"url":NotNil(url),@"download":@(download)}); }
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL fileName:(NSString *)name format:(NSString *)format videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions {
    Event(@{@"kind":@"videoPipeline",@"helper":self,@"videoURL":NotNil(videoURL),@"audioURL":NotNil(audioURL),@"name":NotNil(name),@"format":NotNil(format),@"videoID":NotNil(videoID),@"videoSize":@(videoSize),@"audioSize":@(audioSize),@"duration":@(duration),@"captions":NotNil(captions)});
}
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID audioSize:(unsigned long long)size duration:(unsigned long long)duration {
    Event(@{@"kind":@"audioPipeline",@"helper":self,@"url":NotNil(url),@"name":NotNil(name),@"videoID":NotNil(videoID),@"size":@(size),@"duration":@(duration)});
}
@end
// Boundary-only parser double with the actual selectors in 0x10a480/10b56c/10d304.
// The real parser has a separate XML/storage runtime suite.
@interface SRTParser : NSObject @end
@implementation SRTParser
- (void)parseXMLFromURL:(NSURL *)url forLanguage:(NSString *)languageCode videoID:(NSString *)videoID completion:(void (^)(NSURL *,NSError *))completion {
    Event(@{@"kind":@"srt",@"url":NotNil(url),@"videoID":NotNil(videoID),@"language":NotNil(languageCode),@"download":@YES});completion(DownloadsSRTResult,DownloadsSRTError);
}
- (void)parseTranscriptFromURL:(NSURL *)url completion:(void (^)(NSString *,NSError *))completion {
    Event(@{@"kind":@"srt",@"url":NotNil(url),@"videoID":[NSNull null],@"language":[NSNull null],@"download":@NO});completion(DownloadsSRTResult,DownloadsSRTError);
}
@end
@interface DVNImageViewController : UIViewController
@property(nonatomic,strong) UIImage *fullImage;
@end
@implementation DVNImageViewController @end
@interface YTPPlayerHelper : NSObject @end
@implementation YTPPlayerHelper
+ (void)openVideoWithID:(NSString *)videoID viewController:(id)controller { Event(@{@"kind":@"openRegular",@"videoID":NotNil(videoID),@"controller":NotNil(controller)}); }
@end
@implementation MobileFFmpeg
+ (int)execute:(NSString *)command { Event(@{@"kind":@"ffmpeg",@"command":command,@"mainThread":@([NSThread isMainThread])});return DownloadsFFmpegResult; }
+ (void)cancel { Event(@{@"kind":@"ffmpegCancel"}); }
@end
@implementation MobileFFmpegConfig
+ (void)resetStatistics { Event(@{@"kind":@"ffmpegReset"}); }
+ (void)setLogDelegate:(id<LogDelegate>)delegate { Event(@{@"kind":@"ffmpegLogDelegate",@"delegate":NotNil(delegate)}); }
+ (void)setStatisticsDelegate:(id<StatisticsDelegate>)delegate { Event(@{@"kind":@"ffmpegStatisticsDelegate",@"delegate":NotNil(delegate)}); }
+ (NSString *)getLastCommandOutput { return DownloadsFFmpegLog; }
@end
@implementation Statistics
- (int)getTime { return self.time; }
@end
@implementation DownloadsTask
- (void)resume { self.resumed=YES; }
- (void)cancel { self.cancelled=YES; }
@end
@implementation DownloadsSession
- (instancetype)init { if((self=[super init]))self.tasks=[NSMutableArray array];return self; }
- (id)dataTaskWithRequest:(NSURLRequest *)request { DownloadsTask *t=[DownloadsTask new];t.originalRequest=request;[self.tasks addObject:t];return t; }
- (id)downloadTaskWithRequest:(NSURLRequest *)request { return [self dataTaskWithRequest:request]; }
- (id)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData *,NSURLResponse *,NSError *))completion { DownloadsTask *t=[self dataTaskWithRequest:request];t.completion=completion;return t; }
@end
static id SessionFactory(id cls,SEL sel,NSURLSessionConfiguration *config,id delegate,NSOperationQueue *queue) { (void)cls;(void)sel;(void)config;DownloadsSession *s=[DownloadsSession new];s.delegate=delegate;s.delegateQueue=queue;DownloadsLastSession=s;return s; }
static id SharedSession(id cls,SEL sel) { (void)cls;(void)sel;return DownloadsSharedSession; }
static IMP OriginalInfo;
static id Info(id bundle,SEL selector,NSString *key) { if([key isEqual:@"CFBundleShortVersionString"])return DownloadsBundleVersion;return ((id(*)(id,SEL,id))OriginalInfo)(bundle,selector,key); }
void DownloadsInstallDoubles(void) {
    DownloadsPreferences=[NSMutableDictionary dictionary];DownloadsEvents=[NSMutableArray array];
    DownloadsBundleVersion=@"20.12.4";DownloadsFreeSpace=1000000000;DownloadsAuthorized=YES;DownloadsSharedSession=[DownloadsSession new];
    method_setImplementation(class_getClassMethod([NSURLSession class],@selector(sessionWithConfiguration:delegate:delegateQueue:)),(IMP)SessionFactory);
    method_setImplementation(class_getClassMethod([NSURLSession class],@selector(sharedSession)),(IMP)SharedSession);
    OriginalInfo=method_setImplementation(class_getInstanceMethod([NSBundle class],@selector(objectForInfoDictionaryKey:)),(IMP)Info);
    DownloadsAppDelegate *d=[DownloadsAppDelegate new];d.window=[UIWindow new];DownloadsRoot *root=[DownloadsRoot new];root.pageStyle=0;d.window.rootViewController=root;d.responderRoot=root;[UIApplication sharedApplication].delegate=d;
}
