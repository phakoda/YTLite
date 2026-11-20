#import "../source/Hooks/ShortsInterfaceHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Controls/DVNLongPressDelegate.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Presentation/PlayerToast.h"
#import "../source/Presentation/ToastManager.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "../../Utils/YTLUserDefaults.h"
#import "shorts_interface_redirects.h"
#import <objc/runtime.h>
#import <objc/message.h>
BOOL isOverlayShown=YES;
static NSUInteger checks,originals,created,downloads,speedCalls,shows,hides,deallocs,parents,locationReads,presentationReads;
static NSMutableDictionary *prefs;
static NSMutableArray *events,*constraints,*gates;
static id parentObject,playerObject,originalModel,lastSender,lastPlayer,lastView,lastStack;
static NSArray *originalReels;
static uintptr_t lastSlot;
static CGSize lastSize;
static double resized,rate,delayed;
static BOOL factoryAvailable=YES,zone=YES,compact,lastAnimated,lastVisible;
static NSString *lastText,*lastSuccessText;
static dispatch_block_t queued;
static CGPoint testedPoint;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
BOOL ytpBool(NSString *key){[gates addObject:key];[events addObject:key];return [prefs[key] boolValue];}
NSInteger ytpInt(NSString *key){[gates addObject:key];[events addObject:key];return [prefs[key] integerValue];}
void ShortsFixtureAsync(dispatch_queue_t queue,dispatch_block_t block){CHECK(queue==dispatch_get_main_queue());queued=[block copy];[events addObject:@"queued"];}
@implementation NSLayoutConstraint
- (void)setActive:(BOOL)value{_active=value;if(value)[constraints addObject:self];}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor{NSLayoutConstraint*c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;return c;}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value{NSLayoutConstraint*c=[NSLayoutConstraint new];c.firstAnchor=self;c.constant=value;return c;}
@end
@implementation UIGestureRecognizer
- (instancetype)initWithTarget:(id)target action:(SEL)action{if((self=[super init])){_target=target;_action=action;}return self;}
- (CGPoint)locationInView:(id)view{locationReads++;return _location;}
@end
@implementation UILongPressGestureRecognizer @end
@implementation UIView
- (instancetype)init{if((self=[super init])){_subviews=[NSMutableArray new];_gestureRecognizers=[NSMutableArray new];_layer=[CALayer layer];}return self;}
- (void)addSubview:(UIView*)view{[_subviews addObject:view];}
- (UIView*)viewWithTag:(NSInteger)tag{for(UIView*v in _subviews){if(v.tag==tag)return v;UIView*r=[v viewWithTag:tag];if(r)return r;}return nil;}
- (void)addGestureRecognizer:(UIGestureRecognizer*)r{[_gestureRecognizers addObject:r];}
- (void)layoutSubviews{originals++;[events addObject:@"orig"];}
#define ANCHOR(name) - (NSLayoutAnchor*)name {NSLayoutAnchor*a=[NSLayoutAnchor new];a.owner=self;a.kind=@#name;return a;}
ANCHOR(topAnchor) ANCHOR(bottomAnchor) ANCHOR(leadingAnchor) ANCHOR(trailingAnchor) ANCHOR(centerXAnchor) ANCHOR(widthAnchor) ANCHOR(heightAnchor)
@end
@implementation UIViewController
- (void)viewDidAppear:(BOOL)animated{originals++;lastAnimated=animated;[events addObject:@"orig"];}
@end
@implementation UIWindow @end
@implementation UIApplication
+ (instancetype)sharedApplication{static UIApplication*a;if(!a)a=[self new];return a;}
@end
@implementation UIColor
+ (instancetype)blackColor{return [self new];}
+ (instancetype)whiteColor{return [self new];}
- (CGColorRef)CGColor{static CGColorRef c;if(!c)c=CGColorCreateGenericGray(0,1);return c;}
@end
@implementation UIImage @end
@implementation UIButton @end
@interface Feedback:NSObject @end
@implementation Feedback
- (void)setCustomTouchFeedbackColor:(UIColor*)color{CHECK(color!=nil);}
@end
static id iconRenderer;
@implementation YTQTMButton
- (id)touchFeedbackView{return [Feedback new];}
- (id<YTLShortsButtonRenderer>)buttonRenderer{return iconRenderer;}
@end
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLHelper
+ (UIImage*)resizeImage:(UIImage*)image toSize:(double)size{resized=size;return image;}
+ (UIButton*)createYTQTMButton:(id)target accessibilityLabel:(NSString*)text buttonLabel:(NSString*)label icon:(UIImage*)icon selector:(SEL)action{
    created++;CHECK([text isEqual:@"ShortsYTLButton"]&&label==nil&&icon!=nil);YTQTMButton*b=[YTQTMButton new];b.target=target;b.action=action;return b;
}
+ (UIButton*)createYTQTMButton:(id)target accessibilityLabel:(NSString*)text buttonLabel:(NSString*)label icon:(UIImage*)icon size:(CGSize)size selector:(SEL)action{
    UIButton*b=[self createYTQTMButton:target accessibilityLabel:text buttonLabel:label icon:icon selector:action];b.requestedSize=size;return b;
}
@end
@implementation YTPMedia
+ (UIImage*)ytPlusShorts{return [UIImage new];}
@end
@implementation DownloadMenuHelper
+ (void)showDownloadSheetShorts:(id)player withSender:(id)sender{downloads++;lastPlayer=player;lastSender=sender;}
@end
@implementation DVNLongPressDelegate
- (BOOL)isTouchInSpeedZone:(CGPoint)p{testedPoint=p;return zone;}
@end
@implementation YTPSpeedMaster
+ (void)setPlaybackRate:(double)value forPlayer:(id)player{speedCalls++;rate=value;lastPlayer=player;[events addObject:@"speed"];}
@end
@implementation PlayerToast
+ (instancetype)sharedToast{static PlayerToast*t;if(!t)t=[self new];return t;}
- (void)showPlayerToastWithText:(NSString*)text value:(double)value style:(long long)style isCompact:(BOOL)c{shows++;CHECK(style==1&&value==rate);lastText=text;compact=c;[events addObject:@"show"];}
- (void)hideToast{hides++;[events addObject:@"hide"];}
@end
@implementation ToastManager
+ (void)showMessageWithText:(NSString*)text isSuccess:(BOOL)success{CHECK(success);lastSuccessText=text;[events addObject:@"toast"];}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults*d;if(!d)d=[[self alloc]initWithSuiteName:@"ShortsInterfaceFixture-unused"];return d;}
- (void)setBool:(BOOL)value forKey:(NSString*)key{prefs[key]=@(value);[events addObject:@"write"];}
@end
@implementation NSBundle (YTLite)
+ (NSBundle*)ytl_defaultBundle{return [NSBundle mainBundle];}
@end
@implementation YTAssetLoader
- (instancetype)initWithBundle:(NSBundle*)bundle{CHECK(bundle!=nil);return [super init];}
- (UIImage*)imageNamed:(NSString*)name{CHECK([name isEqual:@"ytl_icon"]);return [UIImage new];}
@end
@implementation YTReelWatchPlaybackOverlayViewSub
- (id)parentResponder{parents++;return parentObject;}
@end
@implementation YTReelWatchPlaybackOverlayView
- (id)parentResponder{parents++;return parentObject;}
- (void)setActionBarElementRenderer:(uintptr_t)r{originals++;lastSlot=r;[events addObject:@"orig"];}
- (void)setReelLikeButton:(UIView*)b{originals++;lastView=b;[events addObject:@"orig"];}
@end
@implementation YTInlineMutedPlaybackShortsPlayerOverlayView
- (id)parentResponder{parents++;return parentObject;}
@end
@implementation YTReelContentModel
+ (id)makeContentModelForEntry:(uintptr_t)e{originals++;lastSlot=e;[events addObject:@"orig"];return originalModel;}
@end
@implementation YTReelDataSource
- (id)makeContentModelForEntry:(uintptr_t)e{originals++;lastSlot=e;[events addObject:@"orig"];return originalModel;}
@end
@implementation YTReelInfinitePlaybackDataSource
- (id)makeContentModelForEntry:(uintptr_t)e{originals++;lastSlot=e;[events addObject:@"orig"];return originalModel;}
- (BOOL)respondsToSelector:(SEL)s{if(s==@selector(makeContentModelForEntry:))return factoryAvailable;return [super respondsToSelector:s];}
- (NSArray*)reels{originals++;[events addObject:@"orig"];return originalReels;}
@end
@implementation YTShortsStartupCoordinator
- (id)evaluateResumeToShorts{originals++;return @"original";}
@end
@implementation YTReelHeaderView
- (void)setTitleLabelVisible:(BOOL)v animated:(BOOL)a{originals++;lastVisible=v;lastAnimated=a;}
- (void)addView:(UIView*)view toStackView:(id)stack withSize:(CGSize)size{originals++;lastView=view;lastStack=stack;lastSize=size;}
@end
@implementation YTReelWatchHeaderView
#define SETTER(name) - (void)name:(id)value{originals++;lastView=value;}
SETTER(setChannelBarElementRenderer) SETTER(setHeaderRenderer) SETTER(setShortsVideoTitleElementRenderer) SETTER(setSoundMetadataElementRenderer) SETTER(setActionElement) SETTER(setBadgeRenderer) SETTER(setMultiFormatLinkElementRenderer)
@end
static UIView *playbackOverlay;
@implementation YTReelContentView
- (void)setPlaybackView:(uintptr_t)v{originals++;lastSlot=v;[events addObject:@"orig"];}
- (UIView*)playbackOverlay{return playbackOverlay;}
- (id<YTLShortsPlayerProvider>)delegate{return playerObject;}
- (void)dealloc{deallocs++;[events addObject:@"dealloc"];}
@end
@implementation YTReelWatchRootViewController @end
#pragma clang diagnostic pop
@interface YTReelPlayerViewController:NSObject <YTLShortsPlayerProvider> @end
@implementation YTReelPlayerViewController
- (id)player{return @"player";}
@end
@interface YTPlayerViewController:NSObject @end
@implementation YTPlayerViewController @end
@interface Node:NSObject<YTLShortsNode>
@property NSArray *yogaChildren;
@property id<YTLShortsNode> controller;
@property NSString *key;
@end
@implementation Node @end
@interface Element:NSObject{@public id _rootNode;} @end
@implementation Element @end
@interface Overlay:UIView{@public id _elementView;} @end
@implementation Overlay @end
@interface NewOverlay:YTReelWatchPlaybackOverlayView{@public id _playerOverlayView,_actionBarComponentView,_actionBarView;} @end
@implementation NewOverlay @end
@interface SubOverlay:YTReelWatchPlaybackOverlayViewSub{@public id _playerOverlayView;} @end
@implementation SubOverlay @end
@interface Renderer:NSObject<YTLShortsButtonRenderer,YTLShortsIcon>
@property unsigned int iconType;
@end
@implementation Renderer
- (id<YTLShortsIcon>)icon{return self;}
@end
@interface Model:NSObject<YTLShortsModel,YTLShortsPresentation>
@property int videoType,type;
@property BOOL hasVideo,hasPresentation,hasPreview,hasLive,isLivePreviewVideo,isLiveVideo;
@end
@implementation Model
- (BOOL)respondsToSelector:(SEL)s{if(s==@selector(videoType))return _hasVideo;if(s==@selector(presentation))return _hasPresentation;if(s==@selector(livePreviewVideo))return _hasPreview;if(s==@selector(liveVideo))return _hasLive;return [super respondsToSelector:s];}
- (id<YTLShortsPresentation>)presentation{presentationReads++;return self;}
- (BOOL)livePreviewVideo{return NO;}
- (BOOL)liveVideo{return NO;}
@end
@interface AppRoot:UIViewController
@property NSUInteger hiddenCount;
@end
@implementation AppRoot
- (void)hidePivotBar{_hiddenCount++;}
- (void)performSelector:(SEL)s withObject:(id)o afterDelay:(NSTimeInterval)t{CHECK(s==@selector(showPivotBar)&&o==nil);delayed=t;[events addObject:@"delay"];}
@end
@interface AppDelegate:NSObject<UIApplicationDelegate>
@property UIWindow *window;
@end
@implementation AppDelegate @end
static void Reset(void){originals=created=downloads=speedCalls=shows=hides=deallocs=parents=locationReads=presentationReads=0;[prefs removeAllObjects];[events removeAllObjects];[constraints removeAllObjects];[gates removeAllObjects];parentObject=lastPlayer=lastSender=lastView=lastStack=originalModel=nil;queued=nil;lastSuccessText=nil;resized=rate=delayed=0;[PlayerToast sharedToast].alpha=0;zone=YES;factoryAvailable=YES;}
static void Buttons(void){
    for(id overlay in @[[NewOverlay new],[SubOverlay new]]){
        Reset();[overlay layoutSubviews];CHECK(originals==1&&created==0);
        prefs[@"downloadManager"]=@YES;[overlay layoutSubviews];CHECK(created==0);
        Overlay*p=[Overlay new];Element*e=[Element new];Node*root=[Node new],*first=[Node new],*wrong=[Node new],*match=[Node new];
        wrong.controller=wrong;wrong.key=@"wrong";match.controller=match;match.key=@"reel_player_overlay.reel_action_bar_key";first.yogaChildren=@[wrong,match,match];root.yogaChildren=@[first];e->_rootNode=root;p->_elementView=e;[overlay setValue:p forKey:@"_playerOverlayView"];
        [overlay layoutSubviews];CHECK(created==1&&resized==24&&constraints.count==2);CHECK([events.firstObject isEqual:@"orig"]);
        UIButton*b=(id)[overlay viewWithTag:999];CHECK(b.target==overlay&&b.action==@selector(didTapYtlButton:)&&CGSizeEqualToSize(b.requestedSize,CGSizeMake(64,60)));
        CHECK(b.layer.shadowOpacity==0.5f&&b.layer.shadowRadius==4&&CGSizeEqualToSize(b.layer.shadowOffset,CGSizeZero));
        CHECK([[(NSLayoutAnchor*)[constraints[0] firstAnchor] kind] isEqual:@"trailingAnchor"]);CHECK([[(NSLayoutAnchor*)[constraints[1] secondAnchor] kind] isEqual:@"topAnchor"]);
        [overlay layoutSubviews];CHECK(created==1);
        for(id parent in @[[NSObject new],[YTReelPlayerViewController new]]){parentObject=parent;NSUInteger old=downloads;[overlay didTapYtlButton:@"sender"];CHECK(downloads==old+([parent isKindOfClass:YTReelPlayerViewController.class]?1:0));}CHECK([lastPlayer isEqual:@"player"]&&[lastSender isEqual:@"sender"]);
    }
    Reset();NewOverlay*o=[NewOverlay new];o->_actionBarComponentView=[UIView new];o->_actionBarView=[UIView new];prefs[@"downloadManager"]=@YES;[o setActionBarElementRenderer:UINT64_C(0xfabcdef987654321)];CHECK(originals==1&&lastSlot==UINT64_C(0xfabcdef987654321)&&created==2&&constraints.count==8&&resized==32);CHECK([[(NSLayoutAnchor*)[constraints[3] secondAnchor] kind]isEqual:@"widthAnchor"]);
    [o setActionBarElementRenderer:7];CHECK(created==4); // No duplicate guard in setters.
    for(NSNumber*gate in @[@NO,@YES])for(NSNumber*hidden in @[@NO,@YES]){Reset();prefs[@"downloadManager"]=gate;UIView*b=[UIView new];b.hidden=hidden.boolValue;[o setReelLikeButton:b];CHECK(originals==1&&lastView==b&&created==(gate.boolValue&&!hidden.boolValue));}
    Reset();prefs[@"downloadManager"]=@YES;[o setReelLikeButton:nil];CHECK(originals==1&&!created);
    Reset();YTInlineMutedPlaybackShortsPlayerOverlayView*inlineView=[YTInlineMutedPlaybackShortsPlayerOverlayView new];prefs[@"downloadManager"]=@YES;parentObject=[NSObject new];[inlineView layoutSubviews];CHECK(!created);parentObject=[YTPlayerViewController new];[inlineView layoutSubviews];CHECK(created==1&&constraints.count==4&&resized==20);CHECK([constraints[2] constant]==32&&[constraints[3] constant]==32);[inlineView layoutSubviews];CHECK(created==2&&inlineView.subviews.count==1);[inlineView didTapYtlButton:@"inline"];CHECK(lastPlayer==parentObject&&[lastSender isEqual:@"inline"]);
}
static void Filtering(void){
    NSArray *factories=@[YTReelContentModel.class,[YTReelDataSource new],[YTReelInfinitePlaybackDataSource new]];
    for(id factory in factories)for(NSUInteger mask=0;mask<8;mask++)for(int kind=0;kind<9;kind++){
        Reset();prefs[@"noAds"]=@(mask&1);prefs[@"removeShortsPosts"]=@(mask&2);prefs[@"removeShortsLive"]=@(mask&4);
        Model*m=[Model new];BOOL removed=NO;
        if(kind<2){m.hasVideo=YES;m.videoType=kind?10:3;removed=(mask&(kind?2:1))!=0;}
        else if(kind<6){m.hasPresentation=YES;m.type=(int[]){4,5,3,7}[kind-2];removed=(mask&(kind==2?1:kind==3?2:4))!=0;}
        else if(kind==6){m.hasPreview=YES;m.isLivePreviewVideo=YES;removed=(mask&4)!=0;}
        else if(kind==7){m.hasLive=YES;m.isLiveVideo=YES;removed=(mask&4)!=0;}
        originalModel=m;id result=[factory makeContentModelForEntry:UINT64_C(0xf000012345678abc)];CHECK(result==(removed?nil:m)&&originals==1&&lastSlot==UINT64_C(0xf000012345678abc));CHECK([events.firstObject isEqual:@"orig"]);
    }
    Reset();Model*m=[Model new];m.isLiveVideo=YES;originalModel=m;prefs[@"removeShortsLive"]=@YES;CHECK([[factories lastObject]makeContentModelForEntry:1]==m&&gates.count==0); // is-prefixed selector alone does not activate check.
    m.hasPresentation=YES;m.type=7;CHECK([[factories lastObject]makeContentModelForEntry:2]==nil&&presentationReads==2);
    Reset();Model*ad=[Model new];ad.hasVideo=YES;ad.videoType=3;Model*post=[Model new];post.hasVideo=YES;post.videoType=10;NSObject*normal=[NSObject new];originalReels=@[ad,normal,post];prefs[@"noAds"]=@YES;YTReelInfinitePlaybackDataSource*d=[YTReelInfinitePlaybackDataSource new];CHECK([d reels]==originalReels&&gates.count==0);factoryAvailable=NO;CHECK([[d reels]isEqual:@[normal,post]]);prefs[@"removeShortsPosts"]=@YES;CHECK([[d reels]isEqual:@[normal]]);CHECK(originalReels.count==3);
    originalReels=@[];CHECK([d reels].count==0);originalReels=nil;CHECK([d reels]==nil);
    Reset();CHECK([[YTShortsStartupCoordinator new]evaluateResumeToShorts]==nil&&!originals&&gates.count==0);
}
static void Headers(void){
    YTReelHeaderView*h=[YTReelHeaderView new];for(NSNumber*gate in @[@NO,@YES])for(NSNumber*v in @[@NO,@YES])for(NSNumber*a in @[@NO,@YES]){Reset();prefs[@"hideShortsLogo"]=gate;[h setTitleLabelVisible:v.boolValue animated:a.boolValue];CHECK(originals==1&&lastVisible==(v.boolValue&&!gate.boolValue)&&lastAnimated==a.boolValue);}
    for(NSUInteger mask=0;mask<8;mask++)for(unsigned int code=1044;code<1049;code++){Reset();prefs[@"hideShortsSearch"]=@(mask&1);prefs[@"hideShortsCamera"]=@(mask&2);prefs[@"hideShortsMore"]=@(mask&4);Renderer*r=[Renderer new];r.iconType=code;iconRenderer=r;YTQTMButton*b=[YTQTMButton new];id stack=[NSObject new];CGSize size=CGSizeMake(1.123456789,1e100);[h addView:b toStackView:stack withSize:size];BOOL hidden=code>=1045&&code<=1047&&(mask&(1<<(code-1045)));CHECK(originals==!hidden&&gates.count==3);if(!hidden)CHECK(lastView==b&&lastStack==stack&&CGSizeEqualToSize(lastSize,size));}
    Reset();[h addView:[UIView new] toStackView:nil withSize:CGSizeZero];CHECK(originals==1&&gates.count==0);
    NSDictionary*cases=@{@"setChannelBarElementRenderer:":@"hideShortsChannelName",@"setHeaderRenderer:":@"hideShortsDescription",@"setShortsVideoTitleElementRenderer:":@"hideShortsDescription",@"setSoundMetadataElementRenderer:":@"hideShortsAudioTrack",@"setActionElement:":@"hideShortsPromoCards",@"setBadgeRenderer:":@"hideShortsThanks",@"setMultiFormatLinkElementRenderer:":@"hideShortsSource"};YTReelWatchHeaderView*watch=[YTReelWatchHeaderView new];for(NSString*s in cases)for(NSNumber*gate in @[@NO,@YES]){Reset();prefs[cases[s]]=gate;((void(*)(id,SEL,id))objc_msgSend)(watch,NSSelectorFromString(s),@"value");CHECK(originals==!gate.boolValue&&[gates isEqual:@[cases[s]]]);if(!gate.boolValue)CHECK([lastView isEqual:@"value"]);}
}
static void Gestures(void){
    playerObject=[YTReelPlayerViewController new];playbackOverlay=[UIView new];
    for(NSNumber*only in @[@NO,@YES])for(NSNumber*shown in @[@NO,@YES]){@autoreleasepool{Reset();prefs[@"shortsOnlyMode"]=only;prefs[@"shortsSpeedIndex"]=@(NSIntegerMax);isOverlayShown=shown.boolValue;YTReelContentView*v=[YTReelContentView new];[v setPlaybackView:UINT64_C(0xfedcba9876543210)];CHECK(originals==1&&lastSlot==UINT64_C(0xfedcba9876543210)&&playbackOverlay.alpha==shown.boolValue);CHECK(v.gestureRecognizers.count==(only.boolValue?2:1));UILongPressGestureRecognizer*speed=v.gestureRecognizers.lastObject;DVNLongPressDelegate*d=(id)speed.delegate;CHECK(d.view==v&&d.mode==NSIntegerMax&&speed.action==@selector(reelSpeedmaster:)&&speed.minimumPressDuration==0.3&&speed.numberOfTouchesRequired==1);CHECK(objc_getAssociatedObject(v,@selector(reelSpeedmaster:))==d);if(only.boolValue){UILongPressGestureRecognizer*g=v.gestureRecognizers[0];CHECK(g.action==@selector(turnShortsOnlyModeOff:)&&g.minimumPressDuration==0.5&&g.numberOfTouchesRequired==2);}[v setPlaybackView:1];CHECK(v.gestureRecognizers.count==(only.boolValue?4:2));}}
    YTReelContentView*v=[YTReelContentView new];UILongPressGestureRecognizer*g=[UILongPressGestureRecognizer new];DVNLongPressDelegate*d=[DVNLongPressDelegate new];g.delegate=d;g.location=CGPointMake(123.123456789,-91.25);
    for(NSNumber*allowed in @[@NO,@YES])for(NSNumber*state in @[@0,@1,@2,@3,@4,@5]){Reset();zone=allowed.boolValue;g.state=state.integerValue;[PlayerToast sharedToast].alpha=0.4;prefs[@"compactToast"]=@YES;[v reelSpeedmaster:g];BOOL began=state.intValue==1;BOOL ended=state.intValue==3||state.intValue==4;CHECK(locationReads==1&&CGPointEqualToPoint(testedPoint,g.location));CHECK(speedCalls==(allowed.boolValue&&(began||ended))&&hides==(allowed.boolValue&&ended));if(speedCalls)CHECK(rate==(began?2:1)&&compact&&[lastText isEqual:@"Toast.PlaybackSpeed"]&&[lastPlayer isEqual:@"player"]);}
    Reset();g.delegate=nil;[v reelSpeedmaster:g];CHECK(locationReads==1&&!speedCalls);g.delegate=d;g.state=3;BOOL threw=NO;@try{[v reelSpeedmaster:g];}@catch(NSException*e){threw=[e.name isEqual:@"YouTubePlusException"]&&[e.reason isEqual:@"Attempt to hide the toast outside of YouTube Plus detected."];}CHECK(threw&&!speedCalls&&!hides);
    AppDelegate*a=[AppDelegate new];a.window=[UIWindow new];AppRoot*root=[AppRoot new];a.window.rootViewController=root;[UIApplication sharedApplication].delegate=a;
    for(NSNumber*state in @[@0,@1,@2,@3,@4]){Reset();prefs[@"shortsOnlyMode"]=@YES;g.state=state.integerValue;[v turnShortsOnlyModeOff:g];BOOL began=state.intValue==1;CHECK([prefs[@"shortsOnlyMode"]boolValue]==!began&&!!queued==began&&delayed==(began?1:0));CHECK(lastSuccessText==nil);if(began){CHECK([events isEqual:@[@"write",@"queued",@"delay"]]);queued();CHECK([lastSuccessText isEqual:@"ShortsModeTurnedOff"]);}}
    [PlayerToast sharedToast].alpha=0;v=nil;
    for(NSNumber*alpha in @[@0,@0.5,@1]){Reset();[PlayerToast sharedToast].alpha=alpha.doubleValue;@autoreleasepool{YTReelContentView*dying=[YTReelContentView new];CHECK(dying!=nil);}CHECK(deallocs==1&&speedCalls==(alpha.doubleValue==1)&&hides==(alpha.doubleValue==1));if(speedCalls)CHECK([events isEqual:@[@"speed",@"compactToast",@"show",@"hide",@"dealloc"]]);}
    [PlayerToast sharedToast].alpha=0;
    YTReelWatchRootViewController*watch=[YTReelWatchRootViewController new];watch.navigationController=[UIViewController new];watch.navigationController.parentViewController=root;
    for(NSNumber*only in @[@NO,@YES]){Reset();prefs[@"shortsOnlyMode"]=only;NSUInteger before=root.hiddenCount;[watch viewDidAppear:only.boolValue];CHECK(originals==1&&lastAnimated==only.boolValue&&root.hiddenCount==before+only.boolValue&&[events.firstObject isEqual:@"orig"]);}
}
int main(void){@autoreleasepool{prefs=[NSMutableDictionary new];events=[NSMutableArray new];constraints=[NSMutableArray new];gates=[NSMutableArray new];CHECK(!class_getInstanceMethod(YTReelContentView.class,@selector(reelSpeedmaster:)));YTLInstallShortsInterfaceHooks();CHECK(class_getInstanceMethod(YTReelContentView.class,@selector(reelSpeedmaster:)));Buttons();Filtering();Headers();Gestures();printf("ShortsInterface: %lu actual-hook assertions passed across 27 registrations\n",(unsigned long)checks);}return 0;}
