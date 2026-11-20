#import "../source/Hooks/PlayerControlsHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Controls/YTPSpeedPopupController.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Downloads/YTPAPIHelper.h"
#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastWindow.h"
#import "../source/Presentation/ToastManager.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
#import <objc/message.h>
#include <math.h>
static NSUInteger checks,originalCalls,resets,rateSets,downloadCalls,popupCalls,sleepCalls,fetchCalls,dataCalls,toastCalls,pauses,plays,fullscreenCalls,deallocs;
static BOOL recordDealloc,topAvailable=YES,existingStack,fullscreenAPI=YES,orientationAPI=YES,fullscreen,responseAPI=YES,contentAPI,lockAvailable=YES,originalBoolean;
static NSInteger orientation;
static double rate=1;
static NSMutableArray *events,*buttons,*constraints,*queued,*reads;
static NSMutableDictionary *prefs,*storage;
static __weak id lastSelf,lastArgument,lastPlayer,lastSender;
static SEL lastSelector;
static void(^fetched)(NSURL *);
static NSData *imageData;
static NSURL *lastURL;
static NSString *fetchID,*toastText;
static id fixtureResponse,ancestor,delegateController;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String);exit(1);}}while(0)
static void Event(NSString *value){[events addObject:value];}
BOOL ytpBool(NSString *key){[reads addObject:key];return [prefs[key]boolValue];}
NSInteger ytpInt(NSString *key){[reads addObject:key];return [prefs[key]integerValue];}
void ControlsFixtureDispatch(dispatch_queue_t queue,dispatch_block_t block){CHECK(queue==dispatch_get_main_queue());[queued addObject:[block copy]];Event(@"queued");}
@implementation NSData (ControlsFixture)
+ (instancetype)controlsFixtureDataWithContentsOfURL:(NSURL *)url{dataCalls++;lastURL=url;return imageData;}
@end
@implementation NSLayoutConstraint
- (void)setActive:(BOOL)value{_active=value;Event(value?@"activate":@"deactivate");}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor{return [self constraintEqualToAnchor:anchor constant:0];}
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value{NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;c.constant=value;[constraints addObject:c];return c;}
@end
@implementation UIGestureRecognizer
- (instancetype)initWithTarget:(id)target action:(SEL)action{if((self=[super init])){self.target=target;self.action=action;}return self;}
@end
@implementation UILongPressGestureRecognizer @end
@implementation UIView
- (instancetype)init{if((self=[super init])){self.alpha=1;self.subviews=[NSMutableArray new];self.gestureRecognizers=[NSMutableArray new];self.layer=[CALayer layer];}return self;}
- (void)addSubview:(UIView *)view{[self.subviews addObject:view];}
- (UIView *)viewWithTag:(NSInteger)value{for(UIView *view in self.subviews){if(view.tag==value)return view;UIView *match=[view viewWithTag:value];if(match)return match;}return nil;}
- (UIView *)safeAreaLayoutGuide{return self;}
- (NSLayoutAnchor *)anchor:(NSString *)kind{NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.kind=kind;return a;}
- (NSLayoutAnchor *)topAnchor{return [self anchor:@"top"];}
- (NSLayoutAnchor *)bottomAnchor{return [self anchor:@"bottom"];}
- (NSLayoutAnchor *)leadingAnchor{return [self anchor:@"leading"];}
- (NSLayoutAnchor *)trailingAnchor{return [self anchor:@"trailing"];}
- (NSLayoutAnchor *)centerYAnchor{return [self anchor:@"centerY"];}
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer{[self.gestureRecognizers addObject:recognizer];}
- (void)layoutIfNeeded{self.layoutCount++;Event(@"layout");}
- (void)layoutSubviews{}
@end
@implementation UIViewController @end
@implementation UIWindow @end
@implementation UIVisualEffectView @end
@implementation UIStackView
- (instancetype)init{if((self=[super init]))self.arrangedSubviews=[NSMutableArray new];return self;}
- (instancetype)initWithArrangedSubviews:(NSArray *)views{if((self=[self init]))for(UIView *v in views)[self addArrangedSubview:v];return self;}
- (void)addArrangedSubview:(UIView *)view{[self.arrangedSubviews addObject:view];[self addSubview:view];}
@end
@implementation UIColor
+ (instancetype)blackColor{return [self new];}
- (instancetype)colorWithAlphaComponent:(CGFloat)value{UIColor *c=[UIColor new];c.alpha=value;return c;}
@end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name{UIImage *i=[self new];i.name=name;return i;}
- (void)setFlipsForRightToLeftLayoutDirection:(BOOL)value{self.flips=value;Event(@"flip");}
@end
@implementation UIButton
- (void)setTitle:(NSString *)title forState:(NSUInteger)state{CHECK(state==0);self.title=title;Event(@"title");}
- (void)setImage:(UIImage *)image forState:(NSUInteger)state{CHECK(state==0);self.image=image;Event(@"image");}
@end
@interface FixtureBundle:NSBundle @end
@implementation FixtureBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table{CHECK(value==nil&&table==nil);return key;}
@end
@implementation NSBundle (YTLite)
+ (NSBundle *)ytl_defaultBundle{static FixtureBundle *b;static dispatch_once_t once;dispatch_once(&once,^{b=[FixtureBundle new];});return b;}
@end
@implementation YTLHelper
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibility buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector{UIButton *b=[UIButton new];b.target=target;b.action=selector;b.accessibilityLabel=accessibility;b.title=label;b.image=icon;[buttons addObject:b];return b;}
+ (UIButton *)createOverlayButton:(id)target accessibilityLabel:(NSString *)accessibility buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector{UIButton *b=[self createYTQTMButton:target accessibilityLabel:accessibility buttonLabel:label icon:icon selector:selector];b.overlay=YES;return b;}
@end
@implementation YTPSpeedMaster
+ (double)currentPlaybackRate{return rate;}
+ (double)playbackRateForPlayer:(id)player{lastPlayer=player;return rate;}
+ (void)setPlaybackRate:(double)value forPlayer:(id)player{rateSets++;rate=value;lastPlayer=player;Event(@"rate");}
@end
@implementation YTPSpeedPopupController
+ (instancetype)speedController{return [self new];}
- (void)presentFromViewController:(UIViewController *)controller{popupCalls++;lastPlayer=controller;}
@end
@implementation DownloadMenuHelper
+ (void)showDownloadSheet:(id)player withSender:(id)sender{downloadCalls++;lastPlayer=player;lastSender=sender;}
@end
@implementation YTPSleepTimer
+ (instancetype)sharedTimer{static YTPSleepTimer *t;static dispatch_once_t once;dispatch_once(&once,^{t=[self new];});return t;}
- (void)showOptions:(UIView *)source{sleepCalls++;lastSender=source;}
@end
@implementation YTPMedia
+ (UIImage *)imageWithName:(NSString *)name{return [UIImage systemImageNamed:name];}
+ (UIImage *)ytPlus{return [self imageWithName:@"ytPlus"];}
+ (UIImage *)volumeOn{return [self imageWithName:@"volumeOn"];}
+ (UIImage *)volumeOff{return [self imageWithName:@"volumeOff"];}
+ (UIImage *)lock{return [self imageWithName:@"lock"];}
+ (UIImage *)sponsorblock{return [self imageWithName:@"sponsorblock"];}
+ (UIImage *)moon{return [self imageWithName:@"moon"];}
+ (UIImage *)adaptiveDiscord{return [self imageWithName:@"adaptiveDiscord"];}
@end
@implementation YTPAPIHelper
+ (void)fetchChannelImageWithChannelID:(NSString *)channelID completion:(void (^)(NSURL *))completion{fetchCalls++;fetchID=channelID;fetched=[completion copy];Event(@"fetch");}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults *d;static dispatch_once_t once;dispatch_once(&once,^{d=[[self alloc]initWithSuiteName:@"PlayerControlsFixtureUnused"] ;});return d;}
- (id)objectForKey:(NSString *)key{return storage[key];}
- (void)setObject:(id)value forKey:(NSString *)key{storage[key]=[value copy];Event(@"persist");}
@end
@implementation ToastView
+ (ToastWindow *)toastWindow{static ToastWindow *w;static dispatch_once_t once;dispatch_once(&once,^{w=[ToastWindow new];w.rootViewController=[UIViewController new];});return w;}
@end
@implementation ToastWindow @end
@implementation ToastManager
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success{CHECK(success);toastCalls++;toastText=text;}
@end
@interface FixtureVideo:NSObject<YTLControlsVideo>
@property BOOL muted;
@end
@implementation FixtureVideo
- (BOOL)isMuted{return self.muted;}
@end
@interface FixtureResponse:NSObject<YTLControlsResponse,YTLControlsPlayerData,YTLControlsVideoDetails>
@property(copy) NSString *channelId,*author,*title;
@end
@implementation FixtureResponse
- (id<YTLControlsPlayerData>)playerData{return self;}
- (id<YTLControlsVideoDetails>)videoDetails{return self;}
@end
@interface YTPlayerViewController:UIViewController<YTLControlsPlayer>
@property(strong) FixtureVideo *video;
@end
@implementation YTPlayerViewController
- (id<YTLControlsVideo>)activeVideo{return self.video;}
- (id<YTLControlsResponse>)playerResponse{CHECK(responseAPI);return fixtureResponse;}
- (id<YTLControlsResponse>)contentPlayerResponse{CHECK(contentAPI);return fixtureResponse;}
- (BOOL)respondsToSelector:(SEL)selector{if(selector==@selector(playerResponse))return responseAPI;if(selector==@selector(contentPlayerResponse))return contentAPI;return [super respondsToSelector:selector];}
- (void)pause{pauses++;Event(@"pause");}
- (void)play{plays++;Event(@"play");}
@end
@interface FixtureLock:NSObject<YTLControlsLock>
@property BOOL lockModeActive;
@end
@implementation FixtureLock @end
@interface FixtureController:UIViewController<YTLControlsController>
@property(strong) FixtureLock *lock;
@end
@implementation FixtureController
- (BOOL)respondsToSelector:(SEL)selector{if(selector==@selector(isFullscreen))return fullscreenAPI;if(selector==@selector(statusBarOrientation))return orientationAPI;return [super respondsToSelector:selector];}
- (void)resetAutoHideTimer{resets++;Event(@"reset");}
- (void)setPlaybackRate:(double)value{rateSets++;rate=value;Event(@"delegateRate");}
- (id<YTLControlsLock>)lockModeStateEntityController{return lockAvailable?self.lock:nil;}
- (void)lockModeDidRequestShowFullscreen{fullscreenCalls++;Event(@"fullscreen");}
- (BOOL)isFullscreen{return fullscreen;}
- (NSInteger)statusBarOrientation{return orientation;}
@end
@interface YTMainAppVideoPlayerOverlayViewController:FixtureController @end
@implementation YTMainAppVideoPlayerOverlayViewController @end
@interface FixtureHeader:NSObject<YTLControlsSheetHeader>
@property NSUInteger dividers;
@end
@implementation FixtureHeader
- (void)showHeaderDivider{self.dividers++;}
@end
@interface YTActionSheetAction:NSObject<YTLControlsAction>
@property(copy) NSString *title;
@property(strong) UIImage *icon,*secondary;
@property(copy) YTLControlsActionHandler handler;
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(YTLControlsActionHandler)handler{CHECK(identifier==nil);YTActionSheetAction *a=[self new];a.title=title;a.icon=icon;a.secondary=secondary;a.handler=handler;return a;}
@end
static UIImage *chevron;
@interface YTUIResources:NSObject<YTLControlsResources> @end
@implementation YTUIResources
+ (id<YTLControlsImage>)chevronRightImage{chevron=[UIImage new];return (id)chevron;}
@end
@interface YTDefaultSheetController:NSObject<YTLControlsSheet>
@property(copy) NSString *message,*subMessage;
@property(strong) NSMutableArray *actions;
@property(strong) FixtureHeader *header;
@property(weak) UIView *sourceView;
@property(weak) UIViewController *presenter;
@end
static YTDefaultSheetController *sheet;
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)responder{CHECK(delegate==nil&&responder==nil);sheet=[self new];sheet.message=message;sheet.subMessage=subMessage;sheet.actions=[NSMutableArray new];sheet.header=[FixtureHeader new];return sheet;}
- (id)valueForKey:(NSString *)key{CHECK([key isEqual:@"_headerView"]);return self.header;}
- (void)addAction:(id)action{[self.actions addObject:action];}
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion{CHECK(animated&&completion==nil);self.presenter=controller;}
@end
static UIView *top,*title;
static id route;
@implementation YTMainAppControlsOverlayView
- (instancetype)initWithDelegate:(id)delegate{if((self=[super init])){originalCalls++;lastSelf=self;lastArgument=delegate;lastSelector=_cmd;Event(@"originalInit");if(existingStack){UIView *v=[UIView new];v.tag=998;[self addSubview:v];}}return self;}
- (id<YTLControlsController>)eventsDelegate{return delegateController;}
- (UIViewController<YTLControlsController> *)_viewControllerForAncestor{return ancestor;}
- (UIView *)titleView{return title;}
- (UIView *)topControlsAccessibilityContainerView{return topAvailable?top:nil;}
- (void)layoutSubviews{originalCalls++;lastSelf=self;lastSelector=_cmd;Event(@"originalLayout");}
- (void)setAutoplaySwitchButtonRenderer:(id)renderer{originalCalls++;lastSelf=self;lastArgument=renderer;lastSelector=_cmd;Event(@"originalAutoplay");}
- (void)setClosedCaptionsOrSubtitlesButtonAvailable:(BOOL)available{originalCalls++;lastSelf=self;lastSelector=_cmd;originalBoolean=available;Event(@"originalCaptions");}
- (void)setOverlayVisible:(BOOL)visible{originalCalls++;lastSelf=self;lastSelector=_cmd;originalBoolean=visible;Event(@"originalVisible");}
- (id)playbackRouteButton{originalCalls++;lastSelf=self;lastSelector=_cmd;return route;}
- (void)setValue:(id)value forKey:(NSString *)key{CHECK(value==nil&&[key isEqual:@"_playbackRouteButton"]);route=nil;Event(@"clearRoute");}
- (void)dealloc{if(recordDealloc)deallocs++;}
@end
static void Reset(void){[events removeAllObjects];[reads removeAllObjects];originalCalls=resets=rateSets=downloadCalls=popupCalls=sleepCalls=fetchCalls=dataCalls=toastCalls=pauses=plays=fullscreenCalls=0;lastSelf=lastArgument=lastPlayer=lastSender=nil;sheet=nil;fetched=nil;[queued removeAllObjects];}
static void Baseline(void){[prefs removeAllObjects];[storage removeAllObjects];[buttons removeAllObjects];[constraints removeAllObjects];topAvailable=YES;existingStack=NO;fullscreenAPI=orientationAPI=YES;fullscreen=NO;orientation=0;responseAPI=YES;contentAPI=NO;lockAvailable=YES;rate=1;top=[UIView new];title=[UIView new];route=[NSObject new];YTPlayerViewController *player=[YTPlayerViewController new];player.video=[FixtureVideo new];FixtureController *controller=[YTMainAppVideoPlayerOverlayViewController new];controller.parentViewController=player;controller.lock=[FixtureLock new];ancestor=delegateController=controller;FixtureResponse *r=[FixtureResponse new];r.channelId=@"channel";r.author=@"Author";r.title=@"Video";fixtureResponse=r;imageData=nil;Reset();}
static YTMainAppControlsOverlayView *View(void){return [[YTMainAppControlsOverlayView alloc]initWithDelegate:delegateController];}
static void Tap(UIButton *button){((void(*)(id,SEL,id))objc_msgSend)(button.target,button.action,button);}
static void CheckAnchor(NSLayoutConstraint *c,id first,NSString *kind,id second,NSString *secondKind,double constant,BOOL active){CHECK([(NSLayoutAnchor *)c.firstAnchor owner]==first&&[[(NSLayoutAnchor *)c.firstAnchor kind]isEqual:kind]);CHECK([(NSLayoutAnchor *)c.secondAnchor owner]==second&&[[(NSLayoutAnchor *)c.secondAnchor kind]isEqual:secondKind]);CHECK(c.constant==constant&&c.active==active);}
static void TestConstruction(void){
    for(NSUInteger mask=0;mask<4;mask++){Baseline();topAvailable=(mask&1)!=0;existingStack=(mask&2)!=0;rate=1.375;YTMainAppControlsOverlayView *v=View();CHECK(originalCalls==1&&lastArgument==delegateController&&lastSelf==v&&lastSelector==@selector(initWithDelegate:));CHECK([events[0]isEqual:@"originalInit"]&&buttons.count==9);CHECK([v.speedValue.title isEqual:@"1.375×"]);CHECK([v.speedControls.arrangedSubviews isEqual:@[v.speedPlus,v.speedValue,v.speedMinus]]);CHECK(v.speedControls.axis==1&&v.speedControls.distribution==1&&v.speedControls.alignment==3&&v.speedControls.clipsToBounds&&v.speedControls.layer.cornerRadius==20&&v.speedControls.tag==999&&!v.speedControls.translatesAutoresizingMaskIntoConstraints);CHECK(v.speedControls.backgroundColor.alpha==(double)(float).3);CHECK(v.ytlButtons.axis==0&&v.ytlButtons.distribution==1&&v.ytlButtons.alignment==3&&v.ytlButtons.spacing==10&&v.ytlButtons.tag==998);CHECK(v.speedValue.gestureRecognizers.count==1);UILongPressGestureRecognizer *g=v.speedValue.gestureRecognizers[0];CHECK(g.minimumPressDuration==.4&&g.target==v&&g.action==@selector(showSpeedControl:));
        NSArray *labels=@[@"SpeedButton",@"SpeedButton",@"SpeedButton",@"YTLButton",@"YTLMuteButton",@"YTLLockButton",@"YTLSbButton",@"YTLSleepButton",@"YTLDiscordButton"];NSArray *icons=@[@"plus",@"minus",@"",@"ytPlus",@"volumeOn",@"lock",@"sponsorblock",@"moon",@"adaptiveDiscord"];NSArray *selectors=@[@"speedValuePlus:",@"speedValueMinus:",@"resetSpeedValue:",@"handleYTLIconTap:",@"handleYTLMuteTap:",@"handleYTLLockTap:",@"handleYTLSbTap:",@"handleYTLSleepTap:",@"handleYTLDiscordTap:"];
        for(NSUInteger i=0;i<9;i++){UIButton *b=buttons[i];CHECK(b.target==v&&b.action==NSSelectorFromString(selectors[i])&&[b.accessibilityLabel isEqual:labels[i]]&&b.overlay==(i>2));CHECK(i==2?b.image==nil:[b.image.name isEqual:icons[i]]);}
        CheckAnchor(constraints[0],v.speedControls,@"centerY",v,@"centerY",0,YES);CheckAnchor(constraints[1],v.speedControls,@"leading",v,@"leading",10,YES);
        BOOL added=topAvailable&&!existingStack;CHECK(v.ytlButtons.arrangedSubviews.count==(added?6:0));CHECK(constraints.count==(added?6:2));if(added){CHECK([v.ytlButtons.arrangedSubviews isEqual:@[v.ytlMuteButton,v.ytlLockButton,v.ytlSleepButton,v.ytlDiscordButton,v.ytlSbButton,v.ytlButton]]);CheckAnchor(v.ytlButtonsTopAnchor,v.ytlButtons,@"top",top,@"bottom",0,YES);CheckAnchor(v.ytlButtonsTrailingAnchor,v.ytlButtons,@"trailing",top,@"trailing",0,YES);CheckAnchor(v.ytlButtonsFSTopAnchor,v.ytlButtons,@"top",top,@"top",0,NO);CheckAnchor(v.ytlButtonsFSTrailingAnchor,v.ytlButtons,@"trailing",top,@"leading",-10,NO);}
    }
}
static void TestProperties(void){Baseline();YTMainAppControlsOverlayView *a=[YTMainAppControlsOverlayView new],*b=[YTMainAppControlsOverlayView new];NSArray *names=@[@"speedControls",@"ytlButtons",@"speedMinus",@"speedPlus",@"speedValue",@"ytlButton",@"ytlMuteButton",@"ytlLockButton",@"ytlSleepButton",@"ytlDiscordButton",@"ytlSbButton",@"ytlButtonsTopAnchor",@"ytlButtonsTrailingAnchor",@"ytlButtonsFSTopAnchor",@"ytlButtonsFSTrailingAnchor"];for(NSString *name in names){SEL getter=NSSelectorFromString(name);SEL setter=NSSelectorFromString([NSString stringWithFormat:@"set%@%@:",[[name substringToIndex:1]uppercaseString],[name substringFromIndex:1]]);__weak id weak;@autoreleasepool{id value=[NSObject new];weak=value;((void(*)(id,SEL,id))objc_msgSend)(a,setter,value);CHECK(((id(*)(id,SEL))objc_msgSend)(a,getter)==value&&((id(*)(id,SEL))objc_msgSend)(b,getter)==nil);}CHECK(weak!=nil);((void(*)(id,SEL,id))objc_msgSend)(a,setter,nil);CHECK(weak==nil);}}
static void TestLayout(void){Baseline();YTMainAppControlsOverlayView *v=View();for(NSUInteger mask=0;mask<256;mask++){prefs[@"hideOverlayTitle"]=@((mask&1)!=0);prefs[@"speedControls"]=@((mask&2)!=0);prefs[@"ytlMuteButton"]=@((mask&4)!=0);prefs[@"ytlLockButton"]=@((mask&8)!=0);prefs[@"ytlSleepTimerIndex"]=@((mask&16)?3:2);prefs[@"rpcOverlayButton"]=@((mask&32)!=0);prefs[@"sponsorBlock"]=prefs[@"sbPlayerButton"]=@((mask&64)!=0);prefs[@"downloadManager"]=@((mask&128)!=0);prefs[@"ytlButtonIndex"]=@1;title.alpha=.7;Reset();[v layoutSubviews];CHECK(originalCalls==1&&lastSelf==v&&lastSelector==@selector(layoutSubviews)&&[events[0]isEqual:@"originalLayout"]);CHECK(title.alpha==((mask&1)?0:.7)&&v.speedControls.hidden==!(mask&2));CHECK(v.ytlMuteButton.hidden==!(mask&4)&&v.ytlLockButton.hidden==!(mask&8)&&v.ytlSleepButton.hidden==!(mask&16)&&v.ytlDiscordButton.hidden==!(mask&32)&&v.ytlSbButton.hidden==!(mask&64)&&v.ytlButton.hidden==!(mask&128));CHECK(v.ytlButtons.hidden==!(mask&252));}
    for(NSNumber *mode in @[@0,@1,@2,@3,@4,@(-1)]){prefs[@"ytlSleepTimerIndex"]=mode;[v layoutSubviews];CHECK(v.ytlSleepButton.hidden==!(mode.integerValue==1||mode.integerValue==3));}
    for(NSUInteger mask=0;mask<4;mask++){prefs[@"sponsorBlock"]=@((mask&1)!=0);prefs[@"sbPlayerButton"]=@((mask&2)!=0);prefs[@"downloadManager"]=@((mask&1)!=0);prefs[@"ytlButtonIndex"]=@((mask&2)!=0);[v layoutSubviews];CHECK(v.ytlSbButton.hidden==(mask!=3)&&v.ytlButton.hidden==(mask!=3));}
    for(NSUInteger mask=0;mask<8;mask++)for(NSInteger value=0;value<5;value++){fullscreenAPI=(mask&1)!=0;orientationAPI=(mask&2)!=0;fullscreen=(mask&4)!=0;orientation=value;v.ytlButtonsTopAnchor.active=v.ytlButtonsTrailingAnchor.active=v.ytlButtonsFSTopAnchor.active=v.ytlButtonsFSTrailingAnchor.active=NO;NSUInteger layouts=v.layoutCount;[v layoutSubviews];BOOL valid=fullscreenAPI&&orientationAPI,portrait=fullscreen&&(value==1||value==2);CHECK(v.ytlButtonsTopAnchor.active==(valid&&!portrait)&&v.ytlButtonsTrailingAnchor.active==(valid&&!portrait)&&v.ytlButtonsFSTopAnchor.active==(valid&&portrait)&&v.ytlButtonsFSTrailingAnchor.active==(valid&&portrait));CHECK(v.layoutCount==layouts+valid);}
    topAvailable=NO;Reset();[v layoutSubviews];CHECK(reads.count==2);topAvailable=YES;[v.subviews removeObject:v.ytlButtons];Reset();[v layoutSubviews];CHECK(reads.count==2);
}
static void TestActions(void){Baseline();YTMainAppControlsOverlayView *v=View();id player=[ancestor parentViewController];double rates[]={.1,.25,.26,1.333333333,4.99,5,6,NAN,INFINITY,-INFINITY};for(NSUInteger i=0;i<10;i++){rate=rates[i];Reset();Tap(v.speedMinus);CHECK(resets==1&&rateSets==!(rates[i]<=.25)&&lastPlayer==player);if(rateSets)CHECK(isnan(rates[i])?isnan(rate):rate==(double)(float)(rates[i]-.25));rate=rates[i];Reset();Tap(v.speedPlus);CHECK(resets==1&&rateSets==!(rates[i]>=5)&&lastPlayer==player);if(rateSets)CHECK(isnan(rates[i])?isnan(rate):rate==(double)(float)(rates[i]+.25));}Reset();Tap(v.speedValue);CHECK(resets==1&&rateSets==1&&rate==1&&[v.speedValue.title isEqual:@"1×"]&&[events[0]isEqual:@"reset"]&&[events[1]isEqual:@"delegateRate"]);
    [NSNotificationCenter.defaultCenter postNotificationName:@"YTPSpeedDidChange" object:@1.7];CHECK([v.speedValue.title isEqual:[NSString stringWithFormat:@"%@×",@((float)1.7)]]);[v speedDidChange:[NSNotification notificationWithName:@"YTPSpeedDidChange" object:nil]];CHECK([v.speedValue.title isEqual:@"0×"]);
    UILongPressGestureRecognizer *g=v.speedValue.gestureRecognizers[0];for(NSInteger state=0;state<6;state++)for(NSNumber *enabled in @[@NO,@YES]){prefs[@"speedControls"]=enabled;g.state=state;Reset();((void(*)(id,SEL,id))objc_msgSend)(g.target,g.action,g);CHECK(popupCalls==(state==1&&enabled.boolValue));CHECK(reads.count==(state==1));if(popupCalls)CHECK(lastPlayer==ancestor);}
    for(NSNumber *fallback in @[@NO,@YES]){if(fallback.boolValue)ancestor=[UIViewController new];Reset();Tap(v.ytlButton);CHECK(downloadCalls==1&&lastPlayer==player&&lastSender==v.ytlButton);for(NSNumber *muted in @[@NO,@YES]){[(YTPlayerViewController *)player video].muted=muted.boolValue;Tap(v.ytlMuteButton);CHECK([(YTPlayerViewController *)player video].muted==!muted.boolValue&&[v.ytlMuteButton.image.name isEqual:muted.boolValue?@"volumeOn":@"volumeOff"]);}for(NSNumber *available in @[@NO,@YES]){lockAvailable=available.boolValue;[(FixtureController *)delegateController lock].lockModeActive=NO;Reset();Tap(v.ytlLockButton);CHECK(fullscreenCalls==available.boolValue&&[(FixtureController *)delegateController lock].lockModeActive==available.boolValue);}}
    Tap(v.ytlSleepButton);CHECK(sleepCalls==1&&lastSender==v.ytlSleepButton);
}
static void TestForwarding(void){Baseline();YTMainAppControlsOverlayView *v=View();NSObject *renderer=[NSObject new];for(NSNumber *hide in @[@NO,@YES]){prefs[@"hideAutoplay"]=hide;Reset();[v setAutoplaySwitchButtonRenderer:renderer];CHECK(originalCalls==!hide.boolValue);if(originalCalls)CHECK(lastSelf==v&&lastArgument==renderer&&lastSelector==@selector(setAutoplaySwitchButtonRenderer:));for(NSNumber *available in @[@NO,@YES]){prefs[@"hideSubs"]=hide;Reset();[v setClosedCaptionsOrSubtitlesButtonAvailable:available.boolValue];CHECK(originalCalls==1&&originalBoolean==(available.boolValue&&!hide.boolValue)&&lastSelector==@selector(setClosedCaptionsOrSubtitlesButtonAvailable:));CHECK([reads isEqual:@[@"hideSubs"]]);}}
    for(NSUInteger mask=0;mask<64;mask++)for(NSNumber *visible in @[@NO,@YES]){prefs[@"downloadManager"]=@((mask&1)!=0);prefs[@"ytlButtonIndex"]=@((mask&2)!=0);prefs[@"ytlMuteButton"]=@((mask&4)!=0);prefs[@"ytlLockButton"]=@((mask&8)!=0);prefs[@"speedControls"]=@((mask&16)!=0);prefs[@"pauseOnOverlay"]=@((mask&32)!=0);v.ytlButtons.alpha=v.speedControls.alpha=.33;rate=1.75;Reset();[v setOverlayVisible:visible.boolValue];BOOL buttonsVisible=(mask&3)==3||(mask&4)||(mask&8);CHECK(originalCalls==1&&originalBoolean==visible.boolValue&&lastSelf==v&&lastSelector==@selector(setOverlayVisible:));CHECK(v.ytlButtons.alpha==(buttonsVisible?(double)visible.boolValue:.33)&&v.speedControls.alpha==((mask&16)?(double)visible.boolValue:.33));CHECK(pauses==((mask&32)&&visible.boolValue)&&plays==((mask&32)&&!visible.boolValue));if(mask&16)CHECK([v.speedValue.title isEqual:@"1.75×"]&&[events indexOfObject:@"title"]<[events indexOfObject:@"originalVisible"]);if(mask&32)CHECK([events indexOfObject:@"originalVisible"]<[events indexOfObject:visible.boolValue?@"pause":@"play"]);}
    prefs[@"pauseOnOverlay"]=@YES;ancestor=[UIViewController new];Reset();[v setOverlayVisible:YES];CHECK(plays==0&&pauses==0&&originalCalls==1);
    for(NSNumber *hide in @[@NO,@YES]){prefs[@"noCast"]=hide;route=renderer;Reset();id result=[v playbackRouteButton];CHECK(originalCalls==!hide.boolValue&&result==(hide.boolValue?nil:renderer)&&route==(hide.boolValue?nil:renderer));}
}
static void TestWhitelist(void){
    for(NSUInteger variant=0;variant<6;variant++){Baseline();YTMainAppControlsOverlayView *v=View();BOOL listed=variant==0;if(listed)storage[@"sbWhitelist"]=@{@"channel":@{@"name":@"old"},@"other":@1};else if(variant==1)storage[@"sbWhitelist"]=@{@"other":@1};if(variant==2){responseAPI=NO;contentAPI=YES;}if(variant==3)ancestor=[UIViewController new];Reset();Tap(v.ytlSbButton);CHECK([sheet.message isEqual:@"Author"]&&[sheet.subMessage isEqual:@"Video"]&&sheet.header.dividers==1&&chevron.flips&&sheet.sourceView==v.ytlSbButton&&sheet.presenter==ToastView.toastWindow.rootViewController);CHECK(sheet.actions.count==1);YTActionSheetAction *action=sheet.actions[0];CHECK([action.title isEqual:listed?@"SbRemoveFromWhitelist":@"SbAddToWhitelist"]&&[action.icon.name isEqual:@"star_half"]&&[action.secondary.name isEqual:listed?@"box_checkmark":@"box_empty"]);CHECK(fetchCalls==0);action.handler(action);if(listed){CHECK(fetchCalls==0&&storage[@"sbWhitelist"][@"channel"]==nil&&[storage[@"sbWhitelist"][@"other"]isEqual:@1]&&queued.count==0);continue;}
        CHECK(fetchCalls==1&&[fetchID isEqual:@"channel"]&&storage[@"sbWhitelist"][@"channel"]==nil);NSURL *url=variant>=4?[NSURL URLWithString:@"https://fixture.invalid/image"]:nil;imageData=variant==5?[@"image" dataUsingEncoding:NSUTF8StringEncoding]:nil;double before=NSDate.date.timeIntervalSince1970;fetched(url);NSDictionary *entry=storage[@"sbWhitelist"][@"channel"];CHECK([entry[@"name"]isEqual:@"Author"]&&[entry[@"link"]isEqual:@"vnd.youtube://www.youtube.com/channel/channel"]&&[entry[@"date"]doubleValue]<=before&&[entry[@"date"]doubleValue]>before-5);CHECK(dataCalls==(url!=nil)&&entry[@"pfp"]==imageData);if(url)CHECK(lastURL==url);CHECK(queued.count==1&&toastCalls==0);((dispatch_block_t)queued[0])();CHECK(toastCalls==1&&[toastText isEqual:@"Sb.Whitelisted"]);if(variant==1)CHECK([storage[@"sbWhitelist"][@"other"]isEqual:@1]);
    }
    Baseline();YTMainAppControlsOverlayView *v=View();fixtureResponse=nil;Reset();Tap(v.ytlSbButton);CHECK(sheet==nil&&fetchCalls==0);fixtureResponse=[FixtureResponse new];responseAPI=contentAPI=NO;Tap(v.ytlSbButton);CHECK(sheet==nil);responseAPI=YES;[(FixtureController *)ancestor setParentViewController:[UIViewController new]];Tap(v.ytlSbButton);CHECK(sheet==nil);
}
static void TestDealloc(void){Baseline();[buttons removeAllObjects];recordDealloc=YES;__weak id weak;@autoreleasepool{YTMainAppControlsOverlayView *v=View();weak=v;[buttons removeAllObjects];[constraints removeAllObjects];CHECK(weak!=nil);}recordDealloc=NO;CHECK(weak==nil&&deallocs==1);[NSNotificationCenter.defaultCenter postNotificationName:@"YTPSpeedDidChange" object:@2];}
static void TestMetadata(BOOL installed) {
    NSArray *names=@[@"speedControls",@"ytlButtons",@"speedMinus",@"speedPlus",@"speedValue",@"ytlButton",@"ytlMuteButton",@"ytlLockButton",@"ytlSleepButton",@"ytlDiscordButton",@"ytlSbButton",@"ytlButtonsTopAnchor",@"ytlButtonsTrailingAnchor",@"ytlButtonsFSTopAnchor",@"ytlButtonsFSTrailingAnchor"];
    unsigned int count=0;objc_property_t *properties=class_copyPropertyList(YTMainAppControlsOverlayView.class,&count);free(properties);CHECK(count==(installed?15:0));
    for(NSUInteger i=0;i<names.count;i++) {
        objc_property_t property=class_getProperty(YTMainAppControlsOverlayView.class,[names[i]UTF8String]);
        if(!installed){CHECK(property==NULL);continue;}
        CHECK(property!=NULL);
        const char *expected=i<2?"T@\"UIStackView\",&,N":i<11?"T@\"YTQTMButton\",&,N":"T@\"NSLayoutConstraint\",&,N";
        CHECK(strcmp(property_getAttributes(property),expected)==0);
    }
}
int main(void){@autoreleasepool{events=[NSMutableArray new];buttons=[NSMutableArray new];constraints=[NSMutableArray new];queued=[NSMutableArray new];reads=[NSMutableArray new];prefs=[NSMutableDictionary new];storage=[NSMutableDictionary new];CHECK(!class_getInstanceMethod(YTMainAppControlsOverlayView.class,@selector(speedValuePlus:)));TestMetadata(NO);YTLInstallPlayerControlsHooks();TestMetadata(YES);CHECK(class_getInstanceMethod(YTMainAppControlsOverlayView.class,@selector(speedValuePlus:))!=NULL);TestConstruction();TestProperties();TestLayout();TestActions();TestForwarding();TestWhitelist();TestDealloc();printf("PASS: %lu actual PlayerControls checks\n",(unsigned long)checks);}return 0;}
