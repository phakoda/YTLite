#import "../source/Hooks/PlayerOverlayHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Runtime/YTLHookEntrypoints.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Controls/DVNHorizontalPanDelegate.h"
#import "../source/Presentation/PlayerToast.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
#import <objc/message.h>
#include <math.h>
static NSUInteger checks,originalCalls,seekCalls,startCalls,endCalls,downloadCalls,manageCalls,toggleCalls,toastShows,toastUpdates,toastHides;
static NSMutableArray *events,*reads,*constraints,*buttons,*pendingAnimations;
static NSMutableDictionary *prefs,*storage;
static __weak id lastSelf,arg1,arg2,lastPlayer,lastSender;
static SEL lastSelector;
static NSInteger originalStyle=0x123456789,lastInteger;
static BOOL originalBool=YES,lastBool,lastGradient,rtl,seekAvailable=YES;
static double mediaTime=10.2,totalTime=100.7,maximumTime=100.7,playbackRate=1,seekValue,toastValue;
static float systemVolume=.42;
static NSInteger toastStyle;
static BOOL toastCompact;
static NSString *toastText;
static id returnObject,overlayDelegate,parentResponder,iconController;
static UIView *audioIcon,*soundIcon;
static NSUInteger scrubberAPIs=15;
BOOL canRememberLoopMode;
BOOL isOverlayShown=YES;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String);exit(1);}}while(0)
static void Event(NSString *value){[events addObject:value];}
static void Original(id self,SEL cmd){originalCalls++;lastSelf=self;lastSelector=cmd;Event(@"original");}
BOOL ytpBool(NSString *key){[reads addObject:key];return [prefs[key]boolValue];}
NSInteger ytpInt(NSString *key){[reads addObject:key];return [prefs[key]integerValue];}
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
@implementation UITapGestureRecognizer @end
@implementation UIPanGestureRecognizer
- (CGPoint)locationInView:(UIView *)view{return self.location;}
- (CGPoint)translationInView:(UIView *)view{return self.translation;}
- (CGPoint)velocityInView:(UIView *)view{return self.velocity;}
@end
@implementation UIView
- (instancetype)init{if((self=[super init])){self.alpha=1;self.subviews=[NSMutableArray new];self.gestureRecognizers=[NSMutableArray new];self.layer=[CALayer layer];self.bounds=CGRectMake(0,0,200,400);self.frame=self.bounds;}return self;}
- (void)addSubview:(UIView *)view{[self.subviews addObject:view];view.superview=self;}
- (UIView *)viewWithTag:(NSInteger)value{for(UIView *view in self.subviews){if(view.tag==value)return view;UIView *match=[view viewWithTag:value];if(match)return match;}return nil;}
- (UIView *)safeAreaLayoutGuide{return self;}
- (NSLayoutAnchor *)anchor:(NSString *)kind{NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.kind=kind;return a;}
- (NSLayoutAnchor *)topAnchor{return [self anchor:@"top"];}
- (NSLayoutAnchor *)bottomAnchor{return [self anchor:@"bottom"];}
- (NSLayoutAnchor *)leadingAnchor{return [self anchor:@"leading"];}
- (NSLayoutAnchor *)trailingAnchor{return [self anchor:@"trailing"];}
- (NSLayoutAnchor *)centerYAnchor{return [self anchor:@"centerY"];}
- (NSLayoutAnchor *)centerXAnchor{return [self anchor:@"centerX"];}
- (NSLayoutAnchor *)widthAnchor{return [self anchor:@"width"];}
- (NSLayoutAnchor *)heightAnchor{return [self anchor:@"height"];}
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer{[self.gestureRecognizers addObject:recognizer];}
- (void)layoutIfNeeded{self.layoutCount++;Event(@"layout");}
- (void)layoutSubviews{}
+ (void)animateWithDuration:(double)duration delay:(double)delay options:(NSUInteger)options animations:(dispatch_block_t)animations completion:(void (^)(BOOL))completion {CHECK(duration==.8&&delay==0&&options==0x10000&&completion==nil);[pendingAnimations addObject:[animations copy]];Event(@"animate");}
@end
@implementation UIViewController
- (instancetype)init{if((self=[super init]))self.view=[UIView new];return self;}
- (void)viewDidLoad{}
@end
@implementation UIWindow @end
@implementation UIVisualEffectView @end
@implementation UIStackView
- (instancetype)init{if((self=[super init]))self.arrangedSubviews=[NSMutableArray new];return self;}
- (instancetype)initWithArrangedSubviews:(NSArray *)views{if((self=[self init]))for(UIView *v in views)[self addArrangedSubview:v];return self;}
- (void)addArrangedSubview:(UIView *)view{[self.arrangedSubviews addObject:view];[self addSubview:view];}
@end
@implementation UIColor
+ (instancetype)blackColor{return [self new];}
- (CGColorRef)CGColor{static CGColorRef c;static dispatch_once_t once;dispatch_once(&once,^{c=CGColorCreateGenericGray(0,1);});return c;}
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
@implementation UILabel
- (void)sizeToFit{self.fits++;Event(@"fit");}
@end
@implementation UIScreen
+ (instancetype)mainScreen{static UIScreen *s;static dispatch_once_t once;dispatch_once(&once,^{s=[self new];s.brightness=.25;});return s;}
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard{static UIPasteboard *p;static dispatch_once_t once;dispatch_once(&once,^{p=[self new];});return p;}
@end
@interface FixtureBundle:NSBundle @end
@implementation FixtureBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table{CHECK(value==nil&&table==nil);return key;}
@end
@implementation NSBundle (YTLite)
+ (NSBundle *)ytl_defaultBundle{static FixtureBundle *b;static dispatch_once_t once;dispatch_once(&once,^{b=[FixtureBundle new];});return b;}
@end
@implementation YTLHelper
+ (UIImage *)resizeImage:(UIImage *)image toSize:(double)size{CHECK(size==24&&[image.name isEqual:@"ytl_icon"]);return image;}
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibility buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector{CHECK([accessibility isEqual:@"YTLButton"]&&label==nil&&[icon.name isEqual:@"ytl_icon"]);UIButton *b=[UIButton new];b.target=target;b.action=selector;b.image=icon;[buttons addObject:b];return b;}
@end
@implementation YTPSpeedMaster
+ (instancetype)sharedMaster{static YTPSpeedMaster *m;static dispatch_once_t once;dispatch_once(&once,^{m=[self new];});return m;}
- (void)manageSpeedMaster:(UILongPressGestureRecognizer *)gesture playerOverlayVC:(id)controller{manageCalls++;lastSender=gesture;lastPlayer=controller;}
@end
@implementation DVNHorizontalPanDelegate @end
@implementation DownloadMenuHelper
+ (void)showDownloadSheet:(id)player withSender:(id)sender{downloadCalls++;lastPlayer=player;lastSender=sender;}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults *d;static dispatch_once_t once;dispatch_once(&once,^{d=[[self alloc]initWithSuiteName:@"PlayerOverlayFixtureUnused"];});return d;}
- (float)floatForKey:(NSString *)key{[reads addObject:key];return [prefs[key]floatValue];}
- (void)setInteger:(NSInteger)value forKey:(NSString *)key{storage[key]=@(value);Event(@"persist");}
@end
@implementation PlayerToast
+ (instancetype)sharedToast{static PlayerToast *t;static dispatch_once_t once;dispatch_once(&once,^{t=[self new];});return t;}
- (void)showPlayerToastWithText:(NSString *)text value:(double)value style:(long long)style isCompact:(BOOL)compact{toastShows++;toastText=text;toastValue=value;toastStyle=style;toastCompact=compact;self.alpha=1;Event(@"toastShow");}
- (void)updateToastText:(NSString *)text value:(double)value{toastUpdates++;toastText=text;toastValue=value;Event(@"toastUpdate");}
- (void)hideToast{toastHides++;self.alpha=0;Event(@"toastHide");}
@end
@interface LDVideoAdBlock:NSObject<YTLOverlayVolume> @end
@implementation LDVideoAdBlock
- (float)systemVolume{return systemVolume;}
@end
@interface YTAssetLoader:NSObject<YTLOverlayAssetLoader> @end
@implementation YTAssetLoader
- (instancetype)initWithBundle:(NSBundle *)bundle{CHECK(bundle==NSBundle.ytl_defaultBundle);return [super init];}
- (UIImage *)imageNamed:(NSString *)name{CHECK([name isEqual:@"ytl_icon"]);return [UIImage systemImageNamed:name];}
@end
@interface YTPlayerViewController:UIViewController<YTLOverlayPlayer> @end
@implementation YTPlayerViewController
- (BOOL)respondsToSelector:(SEL)selector{if(selector==@selector(seekToTime:))return seekAvailable;return [super respondsToSelector:selector];}
- (void)seekToTime:(double)value{seekCalls++;seekValue=value;lastPlayer=self;Event(@"seek");}
@end
@interface FixtureScrubber:NSObject<YTLOverlayScrubber>
@property(strong) UILabel *label;
@end
@implementation FixtureScrubber
- (BOOL)respondsToSelector:(SEL)selector{NSArray *names=@[@"fineScrubberDidStartSeeking",@"fineScrubberDidSeekToTime:",@"fineScrubberDidEndSeekingWithSeekSource:",@"currentTimeLabel"];NSUInteger i=[names indexOfObject:NSStringFromSelector(selector)];if(i!=NSNotFound)return (scrubberAPIs&(1u<<i))!=0;return [super respondsToSelector:selector];}
- (void)fineScrubberDidStartSeeking{startCalls++;Event(@"start");}
- (void)fineScrubberDidSeekToTime:(double)value{seekCalls++;seekValue=value;Event(@"seek");}
- (void)fineScrubberDidEndSeekingWithSeekSource:(NSInteger)source{CHECK(source==25);endCalls++;Event(@"end");}
- (UILabel *)currentTimeLabel{return self.label;}
@end
@interface FixtureBarController:NSObject<YTLOverlayBarController>
@property(strong) FixtureScrubber *bar;
@end
@implementation FixtureBarController
- (id<YTLOverlayScrubber>)playerBar{return self.bar;}
@end
static FixtureBarController *barController;
@interface FixtureOverlay:NSObject<YTLOverlayIdentifier>
@property(copy) NSString *overlayIdentifier;
@end
@implementation FixtureOverlay @end
@implementation YTInlineMutedPlaybackPlayerOverlayView
- (NSInteger)audioControlUIStyle{Original(self,_cmd);return originalStyle;}
- (NSInteger)scrubbingUIStyle{Original(self,_cmd);return originalStyle;}
- (void)updateAudioControlUIStyle:(NSInteger)style{Original(self,_cmd);lastInteger=style;}
- (void)resetWithAudioControlUIStyle:(NSInteger)style{Original(self,_cmd);lastInteger=style;}
- (void)setAudioControlUIStyle:(NSInteger)style{Original(self,_cmd);lastInteger=style;}
@end
@implementation YTInlineMutedPlaybackPlayerOverlayViewController
- (NSInteger)scrubbingUIStyle{Original(self,_cmd);return originalStyle;}
- (void)setPaidContentWithPlayerData:(id)data{Original(self,_cmd);arg1=data;}
- (void)viewDidLoad{Original(self,_cmd);}
- (double)totalTime{return totalTime;}
- (double)mediaTime{return mediaTime;}
@end
@implementation YTInlineMutedPlaybackAudioIconViewController
- (void)viewDidLoad{Original(self,_cmd);}
- (id)parentResponder{return parentResponder;}
@end
@implementation YTInlineMutedPlaybackAudioIconView
- (void)updateColors{Original(self,_cmd);}
- (id)valueForKey:(NSString *)key{if([key isEqual:@"_audioIconWithOverlayView"])return audioIcon;CHECK([key isEqual:@"_audioSoundIconImageView"]);return soundIcon;}
- (YTInlineMutedPlaybackAudioIconViewController *)_viewControllerForAncestor{return iconController;}
- (BOOL)goo_shouldRelayoutSubviewsForRTL{return rtl;}
@end
@implementation YTMainAppVideoPlayerOverlayView
- (void)setBackgroundVisible:(BOOL)visible isGradientBackground:(BOOL)gradient{Original(self,_cmd);lastBool=visible;lastGradient=gradient;}
- (id)autonavPreviewView{Original(self,_cmd);return returnObject;}
- (BOOL)isWatermarkEnabled{Original(self,_cmd);return originalBool;}
- (id)featuredChannelWatermarkImageView{Original(self,_cmd);return returnObject;}
- (void)setSeekAnywherePanGestureRecognizer:(UIGestureRecognizer *)recognizer{Original(self,_cmd);arg1=recognizer;}
- (id)delegate{return overlayDelegate;}
@end
@implementation YTMainAppVideoPlayerOverlayViewController
- (BOOL)shouldShowAutonavEndscreen{Original(self,_cmd);return originalBool;}
- (void)setFeaturedChannelWatermarkImageView:(id)view{Original(self,_cmd);arg1=view;}
- (void)setPaidContentWithPlayerData:(id)data{Original(self,_cmd);arg1=data;}
- (void)playerOverlayProvider:(id)provider didInsertPlayerOverlay:(id<YTLOverlayIdentifier>)overlay{Original(self,_cmd);arg1=provider;arg2=overlay;}
- (NSString *)selectedVarispeedLabelText{Original(self,_cmd);return returnObject;}
- (BOOL)allowDoubleTapToSeekGestureRecognizer{Original(self,_cmd);return originalBool;}
- (BOOL)allowTwoFingerDoubleTapGestureRecognizer{Original(self,_cmd);return originalBool;}
- (void)didPressPause:(id)sender{Original(self,_cmd);arg1=sender;}
- (void)setLoopMode:(NSInteger)mode{Original(self,_cmd);lastInteger=mode;}
- (double)currentPlaybackRate{return playbackRate;}
- (double)mediaTime{return mediaTime;}
- (double)maximumSeekableTime{return maximumTime;}
- (NSString *)videoID{return @"video-id";}
- (void)didTogglePlayPause{toggleCalls++;}
- (id<YTLOverlayBarController>)playerBarController{return barController;}
- (void)viewDidLoad{Original(self,_cmd);}
@end
static void Reset(void){[events removeAllObjects];[reads removeAllObjects];originalCalls=seekCalls=startCalls=endCalls=downloadCalls=manageCalls=toggleCalls=toastShows=toastUpdates=toastHides=0;lastSelf=arg1=arg2=lastPlayer=lastSender=nil;[pendingAnimations removeAllObjects];}
static void Baseline(void){[prefs removeAllObjects];[storage removeAllObjects];[buttons removeAllObjects];[constraints removeAllObjects];originalBool=YES;originalStyle=0x123456789;mediaTime=10.2;totalTime=maximumTime=100.7;playbackRate=1;seekAvailable=YES;scrubberAPIs=15;returnObject=@"original";overlayDelegate=[NSObject new];parentResponder=[NSObject new];audioIcon=[UIView new];soundIcon=[UIView new];audioIcon.frame=CGRectMake(0,0,32,40);barController=[FixtureBarController new];barController.bar=[FixtureScrubber new];barController.bar.label=[UILabel new];UIView *labelParent=[UIView new];[labelParent addSubview:barController.bar.label];objc_setAssociatedObject(barController,@selector(description),labelParent,OBJC_ASSOCIATION_RETAIN_NONATOMIC);UIScreen.mainScreen.brightness=.25;systemVolume=.42;[PlayerToast sharedToast].alpha=1;canRememberLoopMode=NO;Reset();}
static void TestStyles(void){Baseline();YTInlineMutedPlaybackPlayerOverlayView *v=[YTInlineMutedPlaybackPlayerOverlayView new];YTInlineMutedPlaybackPlayerOverlayViewController *c=[YTInlineMutedPlaybackPlayerOverlayViewController new];NSArray *getters=@[@"audioControlUIStyle",@"scrubbingUIStyle"];NSArray *setters=@[@"updateAudioControlUIStyle:",@"resetWithAudioControlUIStyle:",@"setAudioControlUIStyle:"];
for(NSUInteger mask=0;mask<4;mask++){prefs[@"downloadManager"]=@((mask&1)!=0);prefs[@"sponsorBlock"]=@((mask&2)!=0);for(NSString *name in getters){Reset();SEL sel=NSSelectorFromString(name);NSInteger result=((NSInteger(*)(id,SEL))objc_msgSend)(v,sel);CHECK(result==(mask?2:originalStyle)&&originalCalls==!mask);if(!mask)CHECK(lastSelf==v&&lastSelector==sel);CHECK([reads containsObject:@"sponsorBlock"]==!(mask&1));}Reset();CHECK([c scrubbingUIStyle]==(mask?2:originalStyle)&&originalCalls==!mask);
for(NSString *name in setters)for(NSNumber *value in @[@(-3),@0,@1,@(NSIntegerMax)]){Reset();SEL sel=NSSelectorFromString(name);((void(*)(id,SEL,NSInteger))objc_msgSend)(v,sel,value.integerValue);CHECK(originalCalls==1&&lastSelf==v&&lastSelector==sel&&lastInteger==(mask?2:value.integerValue));}}
}
static void TestGates(void){Baseline();YTMainAppVideoPlayerOverlayView *v=[YTMainAppVideoPlayerOverlayView new];YTMainAppVideoPlayerOverlayViewController *c=[YTMainAppVideoPlayerOverlayViewController new];YTInlineMutedPlaybackPlayerOverlayViewController *i=[YTInlineMutedPlaybackPlayerOverlayViewController new];NSObject *object=[NSObject new];NSArray *boolCases=@[@[v,@"isWatermarkEnabled",@"noWatermarks"],@[c,@"shouldShowAutonavEndscreen",@"autonavEndScreenCards"],@[c,@"allowDoubleTapToSeekGestureRecognizer",@"noDoubleTapToSeek"],@[c,@"allowTwoFingerDoubleTapGestureRecognizer",@"noTwoFingerSnapToChapter"]];
for(NSArray *test in boolCases)for(NSNumber *gate in @[@NO,@YES])for(NSNumber *base in @[@NO,@YES]){prefs[test[2]]=gate;originalBool=base.boolValue;Reset();SEL sel=NSSelectorFromString(test[1]);BOOL result=((BOOL(*)(id,SEL))objc_msgSend)(test[0],sel);CHECK(result==(!gate.boolValue&&base.boolValue)&&originalCalls==!gate.boolValue);if(originalCalls)CHECK(lastSelf==test[0]&&lastSelector==sel);}
for(NSArray *test in @[@[v,@"autonavPreviewView",@"autonavEndScreenCards"],@[v,@"featuredChannelWatermarkImageView",@"noWatermarks"]])for(NSNumber *gate in @[@NO,@YES]){prefs[test[2]]=gate;Reset();SEL sel=NSSelectorFromString(test[1]);id result=((id(*)(id,SEL))objc_msgSend)(test[0],sel);CHECK(result==(gate.boolValue?nil:returnObject)&&originalCalls==!gate.boolValue);}
for(NSArray *test in @[@[c,@"setFeaturedChannelWatermarkImageView:",@"noWatermarks"],@[c,@"setPaidContentWithPlayerData:",@"noPromotionCards"],@[i,@"setPaidContentWithPlayerData:",@"noPromotionCards"]])for(NSNumber *gate in @[@NO,@YES]){prefs[test[2]]=gate;Reset();SEL sel=NSSelectorFromString(test[1]);((void(*)(id,SEL,id))objc_msgSend)(test[0],sel,object);CHECK(originalCalls==!gate.boolValue);if(originalCalls)CHECK(arg1==object&&lastSelf==test[0]&&lastSelector==sel);}
for(NSUInteger mask=0;mask<8;mask++){prefs[@"noDarkBg"]=@((mask&1)!=0);Reset();[v setBackgroundVisible:(mask&2)!=0 isGradientBackground:(mask&4)!=0];CHECK(originalCalls==1&&lastBool==((mask&2)&&!(mask&1))&&lastGradient==((mask&4)!=0)&&lastSelector==@selector(setBackgroundVisible:isGradientBackground:));}
for(NSString *identifier in @[@"player_overlay_paid_content",@"player_overlay_product_in_video",@"other"])for(NSUInteger mask=0;mask<4;mask++){prefs[@"noPromotionCards"]=@((mask&1)!=0);prefs[@"noAds"]=@((mask&2)!=0);FixtureOverlay *o=[FixtureOverlay new];o.overlayIdentifier=identifier;Reset();[c playerOverlayProvider:object didInsertPlayerOverlay:o];BOOL suppressed=([identifier isEqual:@"player_overlay_paid_content"]&&(mask&1))||([identifier isEqual:@"player_overlay_product_in_video"]&&(mask&2));CHECK(originalCalls==!suppressed);if(!suppressed)CHECK(arg1==object&&arg2==o);}
for(NSNumber *r in @[@1,@1.125,@0,@(-2),@(NAN),@(INFINITY)]){playbackRate=r.doubleValue;Reset();NSString *text=[c selectedVarispeedLabelText];CHECK(originalCalls==(playbackRate==1));CHECK([text isEqual:playbackRate==1?returnObject:[NSString stringWithFormat:@"%@x",@(playbackRate).stringValue]]);}
for(NSNumber *mode in @[@(-1),@0,@1,@(NSIntegerMax)])for(NSNumber *remember in @[@NO,@YES]){[storage removeAllObjects];canRememberLoopMode=remember.boolValue;Reset();[c setLoopMode:mode.integerValue];CHECK(originalCalls==1&&lastInteger==mode.integerValue);CHECK(remember.boolValue?[storage[@"loopMode"]isEqual:mode]:storage[@"loopMode"]==nil);if(remember.boolValue)CHECK([events isEqual:@[@"original",@"persist"]]);}
for(NSNumber *time in @[@1.9,@(-1.9),@(NAN),@(INFINITY),@(-INFINITY)]){mediaTime=time.doubleValue;prefs[@"copyWithTimestamp"]=@YES;Reset();[c didPressPause:object];long sec=isnan(mediaTime)?0:isinf(mediaTime)?(mediaTime>0?LONG_MAX:LONG_MIN):(long)mediaTime;CHECK(originalCalls==1&&arg1==object&&[UIPasteboard.generalPasteboard.string isEqual:[NSString stringWithFormat:@"https://www.youtube.com/watch?v=video-id&t=%lds",sec]]);}prefs[@"copyWithTimestamp"]=@NO;UIPasteboard.generalPasteboard.string=@"unchanged";[c didPressPause:nil];CHECK([UIPasteboard.generalPasteboard.string isEqual:@"unchanged"]);
}
static void Fire(UIGestureRecognizer *gesture){((void(*)(id,SEL,id))objc_msgSend)(gesture.target,gesture.action,gesture);}
static void TestGestures(void){Baseline();YTMainAppVideoPlayerOverlayViewController *c=[YTMainAppVideoPlayerOverlayViewController new];[c viewDidLoad];CHECK(originalCalls==1&&[events[0]isEqual:@"original"]&&c.view.gestureRecognizers.count==3);UITapGestureRecognizer *tap=c.view.gestureRecognizers[0];UIPanGestureRecognizer *finger=c.view.gestureRecognizers[1],*horizontal=c.view.gestureRecognizers[2];CHECK(tap.target==c&&tap.numberOfTouchesRequired==2&&tap.action==@selector(handleTwoFingerTap:));CHECK(finger.target==c&&finger.action==@selector(handleFingerPan:)&&finger.delegate==c&&finger.minimumNumberOfTouches==1&&finger.maximumNumberOfTouches==1);CHECK(horizontal.action==@selector(handleHorizontalPan:)&&[horizontal.delegate isKindOfClass:DVNHorizontalPanDelegate.class]&&horizontal.minimumNumberOfTouches==1&&horizontal.maximumNumberOfTouches==1);CHECK(objc_getAssociatedObject(c,@selector(handleHorizontalPan:))==horizontal.delegate);
for(NSNumber *gate in @[@NO,@YES]){prefs[@"twoFingerTap"]=gate;Reset();Fire(tap);CHECK(toggleCalls==gate.boolValue);}
YTInlineMutedPlaybackPlayerOverlayViewController *inlineVC=[YTInlineMutedPlaybackPlayerOverlayViewController new];Reset();[inlineVC viewDidLoad];CHECK(originalCalls==1&&inlineVC.view.gestureRecognizers.count==1);UIPanGestureRecognizer *pan=inlineVC.view.gestureRecognizers[0];CHECK(pan.delegate==inlineVC&&pan.action==@selector(handleHorizontalPan:)&&pan.minimumNumberOfTouches==1&&pan.maximumNumberOfTouches==1);
double velocities[][2]={{5,2},{-5,2},{2,2},{0,3},{NAN,1}};for(NSUInteger j=0;j<5;j++){pan.velocity=CGPointMake(velocities[j][0],velocities[j][1]);CHECK([inlineVC gestureRecognizerShouldBegin:pan]==(fabs(pan.velocity.x)>fabs(pan.velocity.y)));}CHECK([inlineVC gestureRecognizer:pan shouldRecognizeSimultaneouslyWithGestureRecognizer:tap]);
for(NSNumber *edge in @[@0,@20,@150,@(-1),@(NAN)])for(NSNumber *x in @[@(-1),@0,@20,@100,@180,@200,@201,@(NAN)])for(NSUInteger mask=0;mask<4;mask++){prefs[@"gestWideness"]=edge;prefs[@"leftGestureIndex"]=@((mask&1)!=0);prefs[@"rightGestureIndex"]=@((mask&2)!=0);finger.location=CGPointMake(x.doubleValue,0);BOOL expected=(x.doubleValue<=edge.floatValue&&(mask&1))||(x.doubleValue>=200-edge.floatValue&&(mask&2));CHECK([c gestureRecognizerShouldBegin:finger]==expected);}CHECK(![c gestureRecognizerShouldBegin:tap]);
YTMainAppVideoPlayerOverlayView *v=[YTMainAppVideoPlayerOverlayView new];for(NSNumber *mode in @[@0,@1,@(-1)]){prefs[@"speedIndex"]=mode;[v.gestureRecognizers removeAllObjects];Reset();[v setSeekAnywherePanGestureRecognizer:pan];CHECK(originalCalls==(mode.integerValue==0)&&v.gestureRecognizers.count==(mode.integerValue!=0));if(originalCalls)CHECK(arg1==pan);else{UILongPressGestureRecognizer *g=v.gestureRecognizers[0];CHECK(g.minimumPressDuration==.3&&g.target==v&&g.action==@selector(speedmasterYtLite:));Fire(g);CHECK(manageCalls==1&&lastSender==g&&lastPlayer==overlayDelegate);}}
}
static void TestInlineSeek(void){Baseline();prefs[@"seekAnywhereFeed"]=@YES;prefs[@"seekSensitivity"]=@10;YTInlineMutedPlaybackPlayerOverlayViewController *c=[YTInlineMutedPlaybackPlayerOverlayViewController new];YTPlayerViewController *player=[YTPlayerViewController new];c.parentViewController=player;UIPanGestureRecognizer *g=[UIPanGestureRecognizer new];g.state=1;[c handleHorizontalPan:g];CHECK(seekCalls==0);mediaTime=80;g.state=2;g.translation=CGPointMake(20,999);[c handleHorizontalPan:g];CHECK(seekCalls==1&&fabs(seekValue-20.3)<1e-12&&lastPlayer==player);prefs[@"seekMethodIndex"]=@1;Reset();[c handleHorizontalPan:g];CHECK(fabs(seekValue-30.2)<1e-12);
for(NSNumber *x in @[@(-1000),@1000,@(NAN)]){g.translation=CGPointMake(x.doubleValue,0);Reset();[c handleHorizontalPan:g];CHECK(seekValue==([x isEqual:@1000]?101:0));}
YTInlineMutedPlaybackPlayerOverlayViewController *other=[YTInlineMutedPlaybackPlayerOverlayViewController new];other.parentViewController=player;mediaTime=4.7;g.translation=CGPointZero;Reset();[other handleHorizontalPan:g];CHECK(seekValue==4.7);g.state=1;mediaTime=1.25;[c handleHorizontalPan:g];g.state=2;[c handleHorizontalPan:g];CHECK(seekValue==1.25);
for(NSNumber *state in @[@0,@3,@4,@5]){g.state=state.integerValue;Reset();[c handleHorizontalPan:g];CHECK(seekCalls==0);}g.state=2;prefs[@"seekAnywhereFeed"]=@NO;Reset();[c handleHorizontalPan:g];CHECK(seekCalls==0);prefs[@"seekAnywhereFeed"]=@YES;c.parentViewController=[UIViewController new];[c handleHorizontalPan:g];CHECK(seekCalls==0);c.parentViewController=player;seekAvailable=NO;[c handleHorizontalPan:g];CHECK(seekCalls==0);
}
static void TestMainSeek(void){Baseline();prefs[@"seekAnywhere"]=@YES;prefs[@"seekSensitivity"]=@10;YTMainAppVideoPlayerOverlayViewController *c=[YTMainAppVideoPlayerOverlayViewController new];UIPanGestureRecognizer *g=[UIPanGestureRecognizer new];g.state=1;[c handleHorizontalPan:g];CHECK(startCalls==1&&seekCalls==0);mediaTime=20.7;g.state=2;g.translation=CGPointMake(20,0);Reset();[c handleHorizontalPan:g];CHECK(fabs(seekValue-31.1)<1e-12&&[barController.bar.label.text isEqual:@"0:31"]&&barController.bar.label.fits==1&&barController.bar.label.superview.alpha==1);
prefs[@"seekMethodIndex"]=@1;g.translation=CGPointZero;for(NSNumber *time in @[@0,@59.9,@60,@3599.2,@3600,@3661.2,@7322.3]){mediaTime=time.doubleValue;maximumTime=10000;Reset();[c handleHorizontalPan:g];long value=lround(time.doubleValue);NSString *expected=value<3600?[NSString stringWithFormat:@"%ld:%02ld",value/60,value%60]:[NSString stringWithFormat:@"%ld:%02ld:%02ld",value/3600,(value%3600)/60,value%60];CHECK(seekValue==value&&[barController.bar.label.text isEqual:expected]);}
for(NSUInteger mask=0;mask<16;mask++){scrubberAPIs=mask;Reset();[c handleHorizontalPan:g];CHECK(seekCalls==((mask&7)==7));if((mask&7)==7)CHECK([events containsObject:@"fit"]==((mask&8)!=0));}scrubberAPIs=15;
for(NSNumber *state in @[@0,@3,@4,@5]){g.state=state.integerValue;Reset();[c handleHorizontalPan:g];CHECK(endCalls==(state.integerValue==3||state.integerValue==4)&&seekCalls==0);}
g.state=2;mediaTime=NAN;maximumTime=100;g.translation=CGPointMake(NAN,0);Reset();[c handleHorizontalPan:g];CHECK(seekValue==0);prefs[@"seekAnywhere"]=@NO;Reset();[c handleHorizontalPan:g];CHECK(seekCalls==0&&[reads isEqual:@[@"seekAnywhere"]]);
}
static void TestFingerPan(void){Baseline();prefs[@"gestWideness"]=@20;YTMainAppVideoPlayerOverlayViewController *c=[YTMainAppVideoPlayerOverlayViewController new];UIPanGestureRecognizer *g=[UIPanGestureRecognizer new];for(NSNumber *mode in @[@(-1),@0,@1,@2,@3])for(NSNumber *side in @[@0,@200]){prefs[@"leftGestureIndex"]=prefs[@"rightGestureIndex"]=mode;prefs[@"compactToast"]=@YES;g.state=1;g.location=CGPointMake(side.doubleValue,50);Reset();[c handleFingerPan:g];CHECK(toastShows==(mode.integerValue>0));if(toastShows)CHECK(toastValue==(mode.integerValue==1?25:42)&&toastStyle==(mode.integerValue==2?2:0)&&toastCompact&&[toastText isEqual:mode.integerValue==1?@"Toast.Brightness":@"Toast.Volume"]);g.state=2;g.translation=CGPointMake(100,-20);Reset();[c handleFingerPan:g];CHECK(toastUpdates==(mode.integerValue>0));if(toastUpdates)CHECK(fabs(toastValue-(mode.integerValue==1?.35:(double)systemVolume+.16))<1e-12);g.state=3;[PlayerToast sharedToast].alpha=1;Reset();[c handleFingerPan:g];CHECK(toastHides==1);g.state=2;Reset();[c handleFingerPan:g];CHECK(toastUpdates==0);}
prefs[@"leftGestureIndex"]=@1;g.state=1;g.location=CGPointZero;[c handleFingerPan:g];for(NSNumber *y in @[@(-1000),@1000,@(NAN)]){g.state=2;g.translation=CGPointMake(0,y.doubleValue);Reset();[c handleFingerPan:g];CHECK(toastUpdates==1&&toastValue==([y isEqual:@(-1000)]?1:0));}
for(NSNumber *state in @[@3,@4]){g.state=state.integerValue;[PlayerToast sharedToast].alpha=0;BOOL raised=NO;@try{[c handleFingerPan:g];}@catch(NSException *e){raised=[e.name isEqual:@"YouTubePlusException"]&&[e.reason isEqual:@"Attempt to hide the toast outside of YouTube Plus detected. Please don't do that."];}CHECK(raised);}
g.state=1;g.location=CGPointMake(100,0);Reset();[c handleFingerPan:g];CHECK(toastShows==0);g.state=2;[c handleFingerPan:g];CHECK(toastUpdates==0);
// State is shared across overlay instances in the original image.
YTMainAppVideoPlayerOverlayViewController *other=[YTMainAppVideoPlayerOverlayViewController new];g.state=1;g.location=CGPointZero;UIScreen.mainScreen.brightness=.125;[c handleFingerPan:g];CHECK(toastValue==13);g.state=2;g.translation=CGPointMake(0,-10);Reset();[other handleFingerPan:g];CHECK(toastUpdates==1&&toastValue==fma(10,.005,.125));g.state=4;[PlayerToast sharedToast].alpha=1;[other handleFingerPan:g];
}
static void Anchor(NSLayoutConstraint *c,id first,NSString *kind,id second,NSString *secondKind,double constant){CHECK([(NSLayoutAnchor *)c.firstAnchor owner]==first&&[[(NSLayoutAnchor *)c.firstAnchor kind]isEqual:kind]);CHECK([(NSLayoutAnchor *)c.secondAnchor owner]==second&&[[(NSLayoutAnchor *)c.secondAnchor kind]isEqual:secondKind]&&c.constant==constant&&c.active);}
static void TestIcon(void){for(NSUInteger mask=0;mask<8;mask++){Baseline();prefs[@"downloadManager"]=@((mask&1)!=0);if(!(mask&2))audioIcon=nil;rtl=(mask&4)!=0;YTInlineMutedPlaybackAudioIconViewController *c=[YTInlineMutedPlaybackAudioIconViewController new];YTInlineMutedPlaybackAudioIconView *v=[YTInlineMutedPlaybackAudioIconView new];c.view=v;iconController=c;[c viewDidLoad];CHECK(originalCalls==1&&[events[0]isEqual:@"original"]);CHECK((c.ytlButton!=nil)==((mask&1)!=0));if(!(mask&1))continue;CHECK(c.ytlIcon.backgroundColor.alpha==.6&&c.ytlIcon.clipsToBounds&&!c.ytlIcon.translatesAutoresizingMaskIntoConstraints);CHECK(c.ytlButton.target==c&&c.ytlButton.action==@selector(handleYTLIconTap:));CHECK(constraints.count==((mask&2)?8:0));if(mask&2){CHECK(c.ytlIcon.layer.cornerRadius==20&&[v.subviews containsObject:c.ytlIcon]&&[c.ytlIcon.subviews containsObject:c.ytlButton]);Anchor(constraints[0],c.ytlIcon,@"trailing",rtl?v:audioIcon,rtl?@"trailing":@"leading",rtl?0:-10);Anchor(constraints[1],c.ytlIcon,@"centerY",audioIcon,@"centerY",0);Anchor(constraints[2],c.ytlIcon,@"width",audioIcon,@"width",0);Anchor(constraints[3],c.ytlIcon,@"height",audioIcon,@"height",0);Anchor(constraints[4],c.ytlButton,@"centerX",c.ytlIcon,@"centerX",0);Anchor(constraints[5],c.ytlButton,@"centerY",c.ytlIcon,@"centerY",0);Anchor(constraints[6],c.ytlButton,@"width",soundIcon,@"width",0);Anchor(constraints[7],c.ytlButton,@"height",soundIcon,@"height",0);}((void(*)(id,SEL,id))objc_msgSend)(c,c.ytlButton.action,c.ytlButton);CHECK(downloadCalls==1&&lastSender==c.ytlButton&&lastPlayer==parentResponder);
Reset();[v updateColors];CHECK(originalCalls==1&&pendingAnimations.count==((mask&2)?1:0));if(mask&2){UIColor *color=[UIColor new];audioIcon.backgroundColor=color;((dispatch_block_t)pendingAnimations[0])();CHECK(c.ytlIcon.backgroundColor==color);audioIcon.backgroundColor=nil;((dispatch_block_t)pendingAnimations[0])();CHECK(c.ytlIcon.backgroundColor==nil&&c.ytlButton.layer.shadowOpacity==.5f&&CGSizeEqualToSize(c.ytlButton.layer.shadowOffset,CGSizeMake(0,1))&&c.ytlButton.layer.shadowRadius==4&&CGColorEqualToColor(c.ytlButton.layer.shadowColor,UIColor.blackColor.CGColor));audioIcon.backgroundColor=color;((dispatch_block_t)pendingAnimations[0])();CHECK(c.ytlButton.layer.shadowOpacity==.5f);}}
}
static void Metadata(BOOL installed){Class c=YTInlineMutedPlaybackAudioIconViewController.class;unsigned int count=0;objc_property_t *props=class_copyPropertyList(c,&count);free(props);CHECK(count==(installed?2:0));for(NSString *name in @[@"ytlButton",@"ytlIcon"]){objc_property_t p=class_getProperty(c,name.UTF8String);if(!installed)CHECK(p==NULL);else CHECK(strcmp(property_getAttributes(p),[name isEqual:@"ytlButton"]?"T@\"YTQTMButton\",&,N":"T@\"UIView\",&,N")==0);}}
static void TestAssociations(void){YTInlineMutedPlaybackAudioIconViewController *a=[YTInlineMutedPlaybackAudioIconViewController new],*b=[YTInlineMutedPlaybackAudioIconViewController new];__weak id weak;@autoreleasepool{UIButton *button=[UIButton new];weak=button;a.ytlButton=button;CHECK(a.ytlButton==button&&b.ytlButton==nil&&a.ytlIcon==nil);}CHECK(weak!=nil);a.ytlButton=nil;CHECK(weak==nil);@autoreleasepool{UIView *view=[UIView new];weak=view;a.ytlIcon=view;CHECK(a.ytlIcon==view&&b.ytlIcon==nil);}CHECK(weak!=nil);a.ytlIcon=nil;CHECK(weak==nil);}
int main(void){@autoreleasepool{events=[NSMutableArray new];reads=[NSMutableArray new];constraints=[NSMutableArray new];buttons=[NSMutableArray new];pendingAnimations=[NSMutableArray new];prefs=[NSMutableDictionary new];storage=[NSMutableDictionary new];Metadata(NO);YTLInstallPlayerOverlayHooks();Metadata(YES);TestAssociations();TestStyles();TestGates();TestGestures();TestInlineSeek();TestMainSeek();TestFingerPan();TestIcon();printf("PASS: %lu actual PlayerOverlay checks\n",(unsigned long)checks);}return 0;}
