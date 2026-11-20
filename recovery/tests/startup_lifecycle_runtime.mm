#import "StartupLifecycleHost.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastWindow.h"
#import "../source/Welcome/WelcomeVC.h"
#import <objc/runtime.h>
#import "../source/Support/YTPDB.h"
static NSUInteger checks;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static NSMutableArray *events,*pathsChecked,*pathsRemoved,*observerTokens,*removedTokens,*searchDirectories,*preferenceReads;
static NSMutableDictionary *preferences;
static NSMutableSet *files;
static NSString *documentPath,*cachePath,*temporaryPath,*clipboard;
static dispatch_block_t pendingAsync,pendingAfter,transactionCompletion,toastAction;
static void (^openCompletion)(BOOL);
static NSURL *playerURL,*openedURL;
static NSDictionary *openedOptions;
static NSArray *launchArguments;
static BOOL launchResult,darkMode;
static NSUInteger playCalls,pauseCalls,dismissCalls,originalPlayCalls,deallocCalls,darkQueries,viewReads,activeCalls,toastCalls,pasteboardReads,presentationCalls;
static int64_t delayedDelta;
static UIColor *black,*adaptive;
static UIImage *originalImage;
static NSString *receivedImageName;
static UIColor *receivedImageColor;
static AVPlayer *lastPlayer;
static AVPlayerLayer *lastLayer;
static UIViewController *presentedController;
static ToastWindow *toastWindow;
static NSString *toastText,*toastTitle;
static double toastDuration;
static NSUInteger defaultsInstances,privateCalls,publicCalls,synchronizations,languageCalls,preferredCalls;
static NSString *generatedPrivate,*generatedPublic,*publicInput;
static NSArray<NSNumber *> *languageCounts,*preferredIndices;
static NSMutableArray *defaultWrites;
NSString *const AVAudioSessionCategoryPlayback=@"playback";
NSString *const AVLayerVideoGravityResizeAspectFill=@"aspectFill";
NSString *const AVPlayerItemDidPlayToEndTimeNotification=@"ended";
NSString *const UIApplicationDidEnterBackgroundNotification=@"background";
@implementation StartupFixtureLayer
- (instancetype)init {if((self=[super init]))_sublayers=[NSMutableArray new];return self;}
- (void)addSublayer:(StartupFixtureLayer *)layer {[_sublayers addObject:layer];[events addObject:@"addLayer"];}
- (void)setOpacity:(float)value {_opacity=value;[events addObject:[NSString stringWithFormat:@"opacity:%g",value]];}
- (void)removeFromSuperlayer {[events addObject:@"removeLayer"];}
@end
@implementation StartupFixtureTransaction
+ (void)begin {[events addObject:@"transactionBegin"];}
+ (void)setAnimationDuration:(double)duration {CHECK(duration==0.2);[events addObject:@"duration"];}
+ (void)setCompletionBlock:(dispatch_block_t)block {transactionCompletion=[block copy];[events addObject:@"transactionCompletion"];}
+ (void)commit {[events addObject:@"transactionCommit"];}
@end
@implementation StartupFixtureFileManager
+ (instancetype)defaultManager {return [self new];}
- (BOOL)fileExistsAtPath:(NSString *)path {[pathsChecked addObject:path?:NSNull.null];return path&&[files containsObject:path];}
- (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error {CHECK(error==NULL);[pathsRemoved addObject:path?:NSNull.null];[events addObject:@"removeFile"];return NO;}
@end
@interface StartupToken : NSObject
@property(nonatomic,copy) NSString *name;
@property(nonatomic,strong) id object;
@property(nonatomic,copy) void (^block)(NSNotification *);
@end
@implementation StartupToken @end
@implementation StartupFixtureNotificationCenter
+ (instancetype)defaultCenter {return [self new];}
- (id)addObserverForName:(NSString *)name object:(id)object queue:(NSOperationQueue *)queue usingBlock:(void (^)(NSNotification *))block {CHECK(queue==NSOperationQueue.mainQueue);StartupToken *token=[StartupToken new];token.name=name;token.object=object;token.block=block;[observerTokens addObject:token];[events addObject:[@"observe:" stringByAppendingString:name]];return token;}
- (void)removeObserver:(id)observer {[removedTokens addObject:observer];[events addObject:@"removeObserver"];}
@end
@implementation StartupFixtureBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table {CHECK(value==nil&&table==nil);return [@"localized:" stringByAppendingString:key];}
@end
@implementation StartupFixtureBundle (YTLite)
+ (instancetype)ytl_defaultBundle {return [self new];}
@end
NSArray<NSString *> *StartupFixtureSearchPaths(NSSearchPathDirectory directory,NSSearchPathDomainMask mask,BOOL expand) {CHECK(mask==NSUserDomainMask&&expand);[searchDirectories addObject:@(directory)];NSString *path=directory==NSDocumentDirectory?documentPath:cachePath;CHECK(directory==NSDocumentDirectory||directory==NSCachesDirectory);return path?@[path]:@[];}
NSString *StartupFixtureTemporaryDirectory(void) {return temporaryPath;}
void StartupFixtureAsync(dispatch_queue_t queue,dispatch_block_t block) {CHECK(queue==dispatch_get_global_queue(0,0));pendingAsync=[block copy];[events addObject:@"async"];}
void StartupFixtureAfter(dispatch_time_t time,dispatch_queue_t queue,dispatch_block_t block) {CHECK(time==12345&&queue==dispatch_get_main_queue());pendingAfter=[block copy];[events addObject:@"after"];}
dispatch_time_t StartupFixtureTime(dispatch_time_t when,int64_t delta) {CHECK(when==DISPATCH_TIME_NOW);delayedDelta=delta;return 12345;}
@implementation UIView
- (instancetype)init {return [self initWithFrame:CGRectZero];}
- (instancetype)initWithFrame:(CGRect)frame {if((self=[super init])){_frame=frame;_bounds=CGRectMake(0,0,frame.size.width,frame.size.height);_layer=[CALayer new];_subviews=[NSMutableArray new];}return self;}
- (void)addSubview:(UIView *)view {[_subviews addObject:view];[events addObject:@"addView"];}
- (BOOL)_mapkit_isDarkModeEnabled {darkQueries++;return darkMode;}
@end
@implementation UIVisualEffectView @end
@implementation UIColor
+ (instancetype)blackColor {return black;}
@end
@implementation UIImage @end
@implementation UIViewController
- (instancetype)init {if((self=[super init]))_view=[[UIView alloc]initWithFrame:CGRectMake(9,11,641.5,923.25)];return self;}
- (UIView *)view {viewReads++;return _view;}
- (void)viewDidLoad {[events addObject:@"viewOrig"];}
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion {CHECK(animated&&completion==nil);presentedController=controller;presentationCalls++;}
@end
@implementation UIWindow @end
@implementation UIAction
+ (instancetype)actionWithHandler:(void (^)(UIAction *))handler {UIAction *action=[UIAction new];action.handler=handler;return action;}
@end
@implementation UIButton
+ (instancetype)buttonWithType:(NSInteger)type {CHECK(type==0);return [self new];}
- (void)addAction:(UIAction *)action forControlEvents:(NSUInteger)eventsValue {CHECK(eventsValue==64);self.action=action;}
@end
@implementation UIApplication
+ (instancetype)sharedApplication {return [self new];}
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {openedURL=url;openedOptions=options;openCompletion=[completion copy];[events addObject:@"open"];}
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard {pasteboardReads++;return [self new];}
- (NSString *)string {return clipboard;}
- (void)setString:(NSString *)string {clipboard=string;[events addObject:@"clipboardSet"];}
@end
@implementation AVAudioSession
+ (instancetype)sharedInstance {return [self new];}
- (BOOL)setCategory:(NSString *)category withOptions:(NSUInteger)options error:(NSError **)error {CHECK(category==AVAudioSessionCategoryPlayback&&options==2&&error==NULL);[events addObject:@"category"];return NO;}
- (BOOL)setActive:(BOOL)active error:(NSError **)error {CHECK(active&&error==NULL);[events addObject:@"activate"];return NO;}
- (BOOL)setActive:(BOOL)active withOptions:(NSUInteger)options error:(NSError **)error {CHECK(!active&&options==1&&error==NULL);[events addObject:@"deactivate"];return NO;}
@end
@implementation AVPlayer
+ (instancetype)playerWithURL:(NSURL *)url {playerURL=url;lastPlayer=[AVPlayer new];lastPlayer.currentItem=[NSObject new];return lastPlayer;}
- (void)play {playCalls++;[events addObject:@"play"];}
- (void)pause {pauseCalls++;[events addObject:@"pause"];}
@end
@implementation AVPlayerLayer
+ (instancetype)playerLayerWithPlayer:(AVPlayer *)player {lastLayer=[AVPlayerLayer new];lastLayer.player=player;return lastLayer;}
@end
@implementation YTPMedia
+ (UIColor *)adaptiveBackgroundColor {return adaptive;}
@end
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults {defaultsInstances++;return [YTLUserDefaults new];}
- (BOOL)boolForKey:(NSString *)key {[preferenceReads addObject:key];return [preferences[key]boolValue];}
- (NSInteger)integerForKey:(NSString *)key {[preferenceReads addObject:key];return [preferences[key]integerValue];}
- (id)objectForKey:(NSString *)key {[preferenceReads addObject:key];return preferences[key];}
- (NSString *)sbPrivateUserID {privateCalls++;[events addObject:@"private"];return generatedPrivate;}
- (NSString *)sbPublicUserID:(NSString *)value {publicCalls++;publicInput=value;[events addObject:@"public"];return generatedPublic;}
- (void)setObject:(id)value forKey:(NSString *)key {[defaultWrites addObject:@[key,value?:NSNull.null]];if(value)preferences[key]=value;else[preferences removeObjectForKey:key];[events addObject:[@"write:" stringByAppendingString:key]];}
- (void)setInteger:(NSInteger)value forKey:(NSString *)key {[self setObject:@(value) forKey:key];}
- (BOOL)synchronize {synchronizations++;[events addObject:@"sync"];return NO;}

@end
@implementation YTAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {launchArguments=@[application?:NSNull.null,options?:NSNull.null];[events addObject:@"launchOrig"];return launchResult;}
- (void)appDidBecomeActive {activeCalls++;[events addObject:@"activeOrig"];}
@end
@implementation YTStartupAnimationViewController
- (void)playLottieAnimation {originalPlayCalls++;[events addObject:@"playOrig"];}
- (void)forceDismissStartupAnimationAnimated:(BOOL)animated {CHECK(animated);dismissCalls++;[events addObject:@"dismiss"];}
- (void)dealloc {deallocCalls++;[events addObject:@"deallocOrig"];}
@end
@implementation QTMIcon
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color {receivedImageName=name;receivedImageColor=color;[events addObject:@"imageOrig"];return originalImage;}
@end
@implementation ToastWindow @end
@implementation ToastView
+ (ToastWindow *)toastWindow {return toastWindow;}
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration actionTitle:(NSString *)title actionCompletion:(dispatch_block_t)completion {toastText=text;toastTitle=title;toastDuration=duration;toastAction=[completion copy];toastCalls++;}
@end
@implementation WelcomeVC @end
@implementation YTPDB
+ (NSArray *)supportedLanguages {NSUInteger index=languageCalls++;NSUInteger count=languageCounts[MIN(index,languageCounts.count-1)].unsignedIntegerValue;NSMutableArray *languages=[NSMutableArray new];for(NSUInteger i=0;i<count;i++)[languages addObject:NSNull.null];return languages;}
+ (NSUInteger)indexOfPreferredLanguage {NSUInteger index=preferredCalls++;return preferredIndices[MIN(index,preferredIndices.count-1)].unsignedIntegerValue;}
@end
static void Reset(void) {
    pendingAsync=pendingAfter=transactionCompletion=toastAction=nil;openCompletion=nil;lastPlayer=nil;lastLayer=nil;presentedController=nil;launchArguments=nil;playerURL=openedURL=nil;openedOptions=nil;receivedImageName=nil;receivedImageColor=nil;
    events=[NSMutableArray new];pathsChecked=[NSMutableArray new];pathsRemoved=[NSMutableArray new];observerTokens=[NSMutableArray new];removedTokens=[NSMutableArray new];searchDirectories=[NSMutableArray new];preferenceReads=[NSMutableArray new];preferences=[NSMutableDictionary new];files=[NSMutableSet new];
    documentPath=@"/synthetic/Documents";cachePath=@"/synthetic/Caches";temporaryPath=@"/synthetic/tmp/";clipboard=nil;launchResult=NO;darkMode=NO;playCalls=pauseCalls=dismissCalls=originalPlayCalls=darkQueries=viewReads=activeCalls=toastCalls=pasteboardReads=presentationCalls=0;
    defaultsInstances=privateCalls=publicCalls=synchronizations=languageCalls=preferredCalls=0;generatedPrivate=@"private-fixture";generatedPublic=@"public-fixture";publicInput=nil;languageCounts=@[@3,@3];preferredIndices=@[@1,@2];defaultWrites=[NSMutableArray new];
    black=[UIColor new];adaptive=[UIColor new];originalImage=[UIImage new];originalImage.accessibilityIdentifier=@"previous";toastWindow=[ToastWindow new];toastWindow.rootViewController=[UIViewController new];
}
static YTStartupAnimationViewController *StartVideo(void) {
    preferences[@"startupAnimation"]=@3;[files addObject:[documentPath stringByAppendingPathComponent:@"startup_animation.mp4"]];YTStartupAnimationViewController *controller=[YTStartupAnimationViewController new];[controller playLottieAnimation];return controller;
}
int main(void) { @autoreleasepool {
    Reset();IMP launch=class_getMethodImplementation([YTAppDelegate class],@selector(application:didFinishLaunchingWithOptions:)),active=class_getMethodImplementation([YTAppDelegate class],@selector(appDidBecomeActive)),image=class_getMethodImplementation(object_getClass([QTMIcon class]),@selector(imageWithName:color:));YTLInstallStartupLifecycleEarlyHooks();CHECK(launch!=class_getMethodImplementation([YTAppDelegate class],@selector(application:didFinishLaunchingWithOptions:)));CHECK(active==class_getMethodImplementation([YTAppDelegate class],@selector(appDidBecomeActive)));CHECK(image==class_getMethodImplementation(object_getClass([QTMIcon class]),@selector(imageWithName:color:)));
    YTAppDelegate *delegate=[YTAppDelegate new];UIApplication *application=[UIApplication new];NSDictionary *options=@{@"value":@9};
    for(int enable=0;enable<2;enable++)for(int result=0;result<2;result++){Reset();preferences[@"autoClearCache"]=@(enable);launchResult=result;CHECK([delegate application:application didFinishLaunchingWithOptions:options]==result);CHECK([launchArguments isEqual:@[application,options]]);CHECK([events isEqual:enable?@[@"async",@"launchOrig"]:@[@"launchOrig"]]);CHECK(pathsRemoved.count==0);if(enable){cachePath=@"/synthetic/changed-cache";pendingAsync();CHECK([pathsRemoved isEqual:@[cachePath,temporaryPath]]);CHECK([searchDirectories isEqual:@[@(NSCachesDirectory)]]);}}
    for(int enable=0;enable<2;enable++)for(int dark=0;dark<2;dark++){@autoreleasepool{Reset();preferences[@"oledTheme"]=@(enable);darkMode=dark;YTStartupAnimationViewController *controller=[YTStartupAnimationViewController new];UIColor *initial=[UIColor new];controller.view.backgroundColor=initial;viewReads=0;[controller viewDidLoad];CHECK([events[0]isEqual:@"viewOrig"]);CHECK(darkQueries==(enable?1:0));CHECK(viewReads==(enable?(dark?2:1):0));CHECK(controller.view.backgroundColor==(enable&&dark?black:initial));}}
    for(NSNumber *mode in @[@0,@1,@2,@4,@(-1),@(INT64_MAX)]){@autoreleasepool{Reset();preferences[@"startupAnimation"]=mode;[[YTStartupAnimationViewController new]playLottieAnimation];CHECK(originalPlayCalls==1&&pathsChecked.count==0&&searchDirectories.count==0);}}
    @autoreleasepool{Reset();preferences[@"startupAnimation"]=@3;[[YTStartupAnimationViewController new]playLottieAnimation];CHECK(originalPlayCalls==1);CHECK([pathsChecked isEqual:@[@"/synthetic/Documents/startup_animation.mp4",@"/synthetic/Documents/startup_animation.mov"]]);}
    @autoreleasepool{Reset();preferences[@"startupAnimation"]=@3;documentPath=nil;[[YTStartupAnimationViewController new]playLottieAnimation];CHECK(originalPlayCalls==1&&[pathsChecked isEqual:@[NSNull.null,NSNull.null]]);}
    @autoreleasepool{Reset();preferences[@"startupAnimation"]=@3;[files addObject:@"/synthetic/Documents/startup_animation.mov"];YTStartupAnimationViewController *controller=[YTStartupAnimationViewController new];[controller playLottieAnimation];CHECK([playerURL.path isEqual:@"/synthetic/Documents/startup_animation.mov"]&&pathsChecked.count==2&&originalPlayCalls==0);}
    for(int route=0;route<3;route++){@autoreleasepool{Reset();YTStartupAnimationViewController *controller=StartVideo();[files addObject:@"/synthetic/Documents/startup_animation.mov"];CHECK(pathsChecked.count==1&&[playerURL.path hasSuffix:@".mp4"]);CHECK(playCalls==1&&pauseCalls==0&&originalPlayCalls==0);UIView *cover=controller.view.subviews.firstObject;CHECK(cover.backgroundColor==adaptive&&cover.autoresizingMask==18);CHECK(CGRectEqualToRect(cover.frame,controller.view.bounds));CHECK(lastLayer.player==lastPlayer&&lastLayer.opacity==1&&[lastLayer.videoGravity isEqual:AVLayerVideoGravityResizeAspectFill]);CHECK(CGRectEqualToRect(lastLayer.frame,controller.view.bounds));CHECK(controller.view.layer.sublayers.firstObject==lastLayer);CHECK(observerTokens.count==2&&[objc_getAssociatedObject(controller,@selector(playLottieAnimation))isEqual:observerTokens]);StartupToken *end=observerTokens[0],*background=observerTokens[1];CHECK([end.name isEqual:AVPlayerItemDidPlayToEndTimeNotification]&&end.object==lastPlayer.currentItem);CHECK([background.name isEqual:UIApplicationDidEnterBackgroundNotification]&&background.object==nil);UIButton *button=(id)cover.subviews.firstObject;CHECK(button.autoresizingMask==18&&CGRectEqualToRect(button.frame,cover.bounds));[events removeAllObjects];if(route==0)end.block(nil);else if(route==1)background.block(nil);else button.action.handler(button.action);CHECK([removedTokens isEqual:observerTokens]);CHECK(pauseCalls==(route==0?0:1)&&lastLayer.opacity==0&&dismissCalls==0&&transactionCompletion!=nil);NSMutableArray *expected=[NSMutableArray arrayWithArray:@[@"removeObserver",@"removeObserver"]];if(route!=0)[expected addObject:@"pause"];[expected addObjectsFromArray:@[@"deactivate",@"transactionBegin",@"duration",@"transactionCompletion",@"opacity:0",@"transactionCommit"]];CHECK([events isEqual:expected]);transactionCompletion();CHECK(dismissCalls==1&&[[events subarrayWithRange:NSMakeRange(events.count-2,2)]isEqual:@[@"removeLayer",@"dismiss"]]);}}
    Reset();__weak YTStartupAnimationViewController *weakController;NSUInteger before=deallocCalls;@autoreleasepool{YTStartupAnimationViewController *controller=StartVideo();weakController=controller;}CHECK(weakController==nil&&deallocCalls==before+1);CHECK([removedTokens isEqual:observerTokens]);CHECK([events.lastObject isEqual:@"deallocOrig"]);
    Reset();YTLInstallStartupLifecycleMainHooks();CHECK(active!=class_getMethodImplementation([YTAppDelegate class],@selector(appDidBecomeActive)));CHECK(image!=class_getMethodImplementation(object_getClass([QTMIcon class]),@selector(imageWithName:color:)));
    for(id value in @[@"other",@"youtube_outline/moon_z_24pt",NSNull.null]){Reset();NSString *name=value==NSNull.null?nil:value;UIColor *color=[UIColor new];CHECK([QTMIcon imageWithName:name color:color]==originalImage);CHECK(receivedImageName==name&&receivedImageColor==color);CHECK([name isEqual:@"youtube_outline/moon_z_24pt"]?[originalImage.accessibilityIdentifier isEqual:@"previous"]:originalImage.accessibilityIdentifier==name);}
    Reset();originalImage=nil;CHECK([QTMIcon imageWithName:@"other" color:nil]==nil);
    Reset();clipboard=@"https://youtube.com/watch?v=x";[delegate appDidBecomeActive];CHECK(activeCalls==1&&pasteboardReads==0&&toastCalls==0);
    for(id value in @[NSNull.null,@"",@"unrelated",@"https://YOUTUBE.COM/watch?v=x"]){Reset();preferences[@"autoCheckCb"]=@YES;clipboard=value==NSNull.null?nil:value;[delegate appDidBecomeActive];CHECK(activeCalls==1&&toastCalls==0&&pasteboardReads==1);}
    for(NSString *url in @[@"https://youtube.com/watch?v=x",@"http://youtu.be/x",@"https://youtube-nocookie.com/embed/x",@"prefix youtube.com suffix",@"youtube.com.evil.invalid/path"]){Reset();preferences[@"autoCheckCb"]=@YES;clipboard=url;[delegate appDidBecomeActive];CHECK(toastCalls==1&&toastDuration==10);CHECK([toastText isEqual:@"localized:LinkDetected"]&&[toastTitle isEqual:@"localized:Open"]&&openedURL==nil);clipboard=@"changed";toastAction();NSString *stripped=[url stringByReplacingOccurrencesOfString:@"^https?://" withString:@"" options:NSRegularExpressionSearch range:NSMakeRange(0,url.length)];NSURL *expectedURL=[NSURL URLWithString:[@"vnd.youtube://" stringByAppendingString:stripped]];CHECK((!openedURL&&!expectedURL)||[openedURL isEqual:expectedURL]);CHECK(openedOptions.count==0&&openCompletion!=nil);openCompletion(NO);CHECK([clipboard isEqual:@"changed"]);openCompletion(YES);CHECK(clipboard==nil);}
    Reset();preferences[@"hasShownWelcome"]=@NO;YTLScheduleWelcome();CHECK(delayedDelta==2000000000LL&&pendingAfter!=nil&&presentationCalls==0&&preferenceReads.count==0);preferences[@"hasShownWelcome"]=@YES;pendingAfter();CHECK(presentationCalls==0);preferences[@"hasShownWelcome"]=@NO;pendingAfter();CHECK(presentationCalls==1&&[presentedController isKindOfClass:[WelcomeVC class]]&&presentedController.modalPresentationStyle==2&&presentedController.modalInPresentation);CHECK([preferences[@"hasShownWelcome"]isEqual:@NO]);
    Reset();YTLFinalizePrimaryStartup();CHECK(defaultsInstances==1&&privateCalls==1&&publicCalls==1&&publicInput==generatedPrivate&&synchronizations==1);CHECK([defaultWrites isEqual:@[@[@"sbPrivateUserID",generatedPrivate],@[@"sbPublicUserID",generatedPublic]]]);CHECK([events isEqual:@[@"private",@"public",@"write:sbPrivateUserID",@"write:sbPublicUserID",@"sync"]]);CHECK(languageCalls==2&&preferredCalls==0);YTLFinalizePrimaryStartup();CHECK(privateCalls==1&&publicCalls==1&&synchronizations==1&&defaultWrites.count==2);
    for(id existing in @[@"",@"existing",@42]){Reset();preferences[@"sbPrivateUserID"]=existing;YTLFinalizePrimaryStartup();CHECK(privateCalls==0&&publicCalls==0&&synchronizations==0&&defaultWrites.count==0);CHECK(preferences[@"sbPublicUserID"]==nil);}
    NSArray *indices=@[@(-1),@0,@2,@3,@(INT64_MAX),@(INT64_MIN)];for(NSNumber *track in indices)for(NSNumber *caption in indices){Reset();preferences[@"sbPrivateUserID"]=@"existing";preferences[@"customTrack"]=track;preferences[@"customCaption"]=caption;YTLFinalizePrimaryStartup();BOOL badTrack=track.longLongValue<0||track.longLongValue>=3,badCaption=caption.longLongValue<0||caption.longLongValue>=3;CHECK(preferredCalls==(NSUInteger)badTrack+(NSUInteger)badCaption&&languageCalls==2&&defaultsInstances==1);CHECK([preferences[@"customTrack"]isEqual:badTrack?@1:track]);CHECK([preferences[@"customCaption"]isEqual:badCaption?(badTrack?@2:@1):caption]);CHECK(defaultWrites.count==(NSUInteger)badTrack+(NSUInteger)badCaption);}
    Reset();preferences[@"sbPrivateUserID"]=@"existing";languageCounts=@[@0,@1];preferredIndices=@[@77];YTLFinalizePrimaryStartup();CHECK([preferences[@"customTrack"]isEqual:@77]&&preferences[@"customCaption"]==nil&&preferredCalls==1&&languageCalls==2);
    Reset();generatedPrivate=generatedPublic=nil;YTLFinalizePrimaryStartup();CHECK(privateCalls==1&&publicCalls==1&&publicInput==nil&&synchronizations==1);CHECK([defaultWrites isEqual:@[@[@"sbPrivateUserID",NSNull.null],@[@"sbPublicUserID",NSNull.null]]]);
    NSLog(@"StartupLifecycle: %lu actual Logos runtime checks passed",(unsigned long)checks);
}return 0;}
