#import "../source/Hooks/PlaybackOptionsHost.h"
#import "../source/Hooks/FeedNodesHelpers.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>
#import <objc/message.h>
#include <math.h>
#include <initializer_list>
static NSUInteger checks,originals,confirms,qualityInits,qualityDeaths,ownerDeaths,snapCalls,speedCalls;
static NSMutableDictionary *prefs;
static NSMutableArray *reads,*events;
static BOOL resultBool=YES,flag,restrictedAvailable=YES;
static double zoomValue,currentZoom;
static NSUInteger sectionsValue,panDelegateReads,exitGestureReads;
static id lastObject,lastSecond,videoValue,restrictedResult,qualityInput,expectedDelegate;
static CGContextRef lastContext;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static void orig(){originals++;[events addObject:@"orig"];}
BOOL ytpBool(NSString*k){[reads addObject:k];[events addObject:k];return[prefs[k]boolValue];}
NSInteger ytpInt(NSString*k){[reads addObject:k];[events addObject:k];return[prefs[k]integerValue];}
static void reset(){[prefs removeAllObjects];[reads removeAllObjects];[events removeAllObjects];originals=0;flag=YES;lastObject=nil;lastSecond=nil;resultBool=YES;panDelegateReads=exitGestureReads=0;}
@implementation UIView
- (instancetype)init{if((self=[super init])){_alpha=1;_subviews=@[];}return self;}
- (void)setHidden:(BOOL)value{orig();_hidden=value;flag=value;}
- (void)layoutSubviews{orig();}
- (void)didMoveToWindow{orig();}
@end
@implementation UIColor { CGColorRef _CGColor; }
+ (BOOL)supportsSecureCoding{return YES;}
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b{if((self=[super init]))_CGColor=CGColorCreateGenericRGB(r,g,b,1);return self;}
- (CGColorRef)CGColor{return _CGColor;}
- (void)encodeWithCoder:(NSCoder*)c{const CGFloat*p=CGColorGetComponents(_CGColor);[c encodeDouble:p[0]forKey:@"r"];[c encodeDouble:p[1]forKey:@"g"];[c encodeDouble:p[2]forKey:@"b"];}
- (instancetype)initWithCoder:(NSCoder*)c{return[self initWithRed:[c decodeDoubleForKey:@"r"] green:[c decodeDoubleForKey:@"g"] blue:[c decodeDoubleForKey:@"b"]];}
- (void)dealloc{CGColorRelease(_CGColor);}
@end
@implementation UIImage
- (NSString*)description{return _text;}
@end
@implementation UIButton @end
@implementation UIGestureRecognizer
- (CGPoint)locationInView:(UIView*)v{CHECK(v==expectedDelegate);return _point;}
@end
@implementation UILongPressGestureRecognizer @end
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults*d;if(!d)d=[[self alloc]initWithSuiteName:@"PlaybackOptionsFixture-unused"];return d;}
- (id)objectForKey:(NSString*)k{[reads addObject:k];return prefs[k];}
- (float)floatForKey:(NSString*)k{[reads addObject:k];return[prefs[k]floatValue];}
@end
@implementation YTPSpeedMaster
+ (instancetype)sharedMaster{static YTPSpeedMaster*m;if(!m)m=[self new];return m;}
- (void)manageSpeedMaster:(UILongPressGestureRecognizer*)g playerOverlayVC:(id)v{speedCalls++;lastObject=g;lastSecond=v;}
@end
@implementation YTVideoQualitySwitchRedesignedController { id _video; }
- (instancetype)initWithServiceRegistryScope:(id)s parentResponder:(id)p{CHECK(!s&&!p);qualityInits++;return[super init];}
- (BOOL)respondsToSelector:(SEL)s{if(sel_isEqual(s,@selector(addRestrictedFormats:)))return restrictedAvailable;return[super respondsToSelector:s];}
- (NSArray*)addRestrictedFormats:(NSArray*)a{CHECK(_video==videoValue);qualityInput=a;return restrictedResult;}
- (void)dealloc{qualityDeaths++;}
@end
@implementation YTVideoQualitySwitchOriginalController
- (void)setUserSelectableFormats:(NSArray*)a{orig();lastObject=a;}
- (void)dealloc{CHECK([self redesignedController]==nil);ownerDeaths++;}
@end
#pragma clang diagnostic pop
@interface QualityOwner:YTVideoQualitySwitchOriginalController { @public id _video; } @end
@implementation QualityOwner @end
@implementation YTWatchNextResultsViewController
- (void)setVisibleSections:(NSUInteger)v{orig();sectionsValue=v;}
@end
@implementation YTFullscreenEngagementOverlayView
- (void)setExpanded:(BOOL)v{orig();flag=v;}
@end
@implementation YTPlaylistVideoCell
- (void)setCanReorder:(BOOL)v{orig();flag=v;}
@end
@implementation YTVideoFreeZoomOverlayController
- (double)videoZoomFactor{return currentZoom;}
- (void)freeZoomViewDidZoom:(double)z isTwoFingerZoom:(BOOL)b{orig();zoomValue=z;flag=b;}
@end
@interface ZoomOwner:YTVideoFreeZoomOverlayController { @public double _snappedZoomFactor; } @end
@implementation ZoomOwner @end
@implementation YTWatchCinematicContainerController
- (BOOL)isCinematicLightingAvailable{orig();return resultBool;}
@end
@implementation YTCreatorEndscreenView @end
@implementation YTFullscreenActionsView
- (BOOL)enabled{orig();return resultBool;}
- (void)setEnabled:(BOOL)v{orig();flag=v;}
@end
@interface ActionsOwner:YTFullscreenActionsView { @public UIView *_elementView; } @end
@implementation ActionsOwner @end
@implementation YTFullscreenEngagementOverlayController
- (void)setRelatedVideosVisible:(BOOL)v{orig();flag=v;}
@end
@implementation YTAnnotationsViewController
- (void)loadFeaturedChannelWatermark{orig();}
@end
@implementation YTWatchFloatingMiniplayerViewController
- (void)updateMiniBarPlayerStateFromRenderer{orig();}
@end
@implementation YTPlaybackConfig
- (void)setStartPlayback:(BOOL)v{orig();flag=v;}
@end
@implementation YTPlayabilityResolutionUserActionUIController
- (void)showConfirmAlert{orig();}
- (void)confirmAlertDidPressConfirm{confirms++;}
@end
@implementation YTSegmentableInlinePlayerBarView
- (void)setEnableSnapToChapter:(BOOL)v{snapCalls++;flag=v;[events addObject:@"snap"];}
@end
@implementation YTBrandGradientImageProcessor
- (void)willDrawInContext:(CGContextRef)c drawParameters:(id<YTLPlaybackOptionsDrawParameters>)p{orig();lastContext=c;lastObject=p;}
@end
@interface DrawParameters:NSObject<YTLPlaybackOptionsDrawParameters>
@property CGRect drawRect;
@end
@implementation DrawParameters @end
@interface YTMainAppVideoPlayerOverlayView:UIView<YTLPlaybackOptionsOverlay>
@property(strong) id<YTLPlaybackOptionsControls> controlsOverlayView;
@end
@implementation YTMainAppVideoPlayerOverlayView @end
@interface Controls:NSObject<YTLPlaybackOptionsControls>
@property BOOL isOverlayVisible;
@property(strong) UIView *ytlButtons,*speedControls;
@end
@implementation Controls @end
@implementation YTVerticalPanGestureRecognier
- (UIView*)verticalPanGestureRecognizerDelegate{panDelegateReads++;return expectedDelegate;}
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer*)g{orig();lastObject=g;return resultBool;}
@end
static UIGestureRecognizer *exitGesture;
@implementation YTExitFullscreenController
- (UIGestureRecognizer*)fullscreenExitGestureRecognizer{exitGestureReads++;return exitGesture;}
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer*)g{orig();lastObject=g;return resultBool;}
@end
@interface Icon:NSObject<YTLPlaybackOptionsIcon>
@property unsigned int iconType;
@end
@implementation Icon @end
@interface Renderer:NSObject<YTLPlaybackOptionsRenderer>
@property(strong) id<YTLPlaybackOptionsIcon> icon;
@end
@implementation Renderer @end
@implementation YTMenuItemVisibilityHandler
- (BOOL)shouldShowServiceItemRenderer:(id<YTLPlaybackOptionsRenderer>)r{orig();lastObject=r;return resultBool;}
@end
@interface Action:NSObject<YTLPlaybackOptionsAction>
@property(strong) UIImage *iconImage;
@property(strong) UIButton *button;
@end
@implementation Action @end
@implementation YTDefaultSheetController
- (void)addAction:(id<YTLPlaybackOptionsAction>)a{orig();lastObject=a;}
@end
@implementation YTYouThereController
- (BOOL)shouldShowYouTherePrompt{orig();return YES;}
@end
@implementation YTSpeedmasterController
- (void)speedmasterDidLongPressWithRecognizer:(UILongPressGestureRecognizer*)g{orig();lastObject=g;}
@end
@interface SpeedOwner:YTSpeedmasterController { @public id _delegate; } @end
@implementation SpeedOwner @end
@interface YTMainAppVideoPlayerOverlayViewController:NSObject @end
@implementation YTMainAppVideoPlayerOverlayViewController @end
static NSUInteger hudDeaths;
@implementation YTHUDMessageView
- (instancetype)initWithMessage:(id)m dismissHandler:(id)h{if((self=[super init])){orig();lastObject=m;lastSecond=h;}return self;}
- (void)dealloc{hudDeaths++;}
@end
@interface Node:NSObject<YTLPlaybackOptionsNode>
@property(copy) NSArray<id<YTLPlaybackOptionsNode>> *subnodes;
@property(strong) NSURL *URL;
@end
@implementation Node @end
@interface ASNetworkImageNode:Node @end
@implementation ASNetworkImageNode @end
@interface NodeView:UIView
@property(strong) id<YTLPlaybackOptionsNode> keepalive_node;
@end
@implementation NodeView @end

static void simpleTests(){
    for(int g=0;g<2;g++)for(int v=0;v<2;v++){
        reset();prefs[@"endScreenCards"]=@(g);[[YTCreatorEndscreenView new]setHidden:v];CHECK(originals==1&&flag==(v||g));
        reset();prefs[@"noFullscreenActions"]=@(g);YTFullscreenActionsView*a=[YTFullscreenActionsView new];[a setEnabled:v];CHECK(originals==1&&flag==(v&&!g));CHECK([a enabled]==!g&&originals==1);
        reset();prefs[@"noRelatedVids"]=@(g);[[YTFullscreenEngagementOverlayController new]setRelatedVideosVisible:v];CHECK(originals==1&&flag==(v&&!g));
        reset();prefs[@"disableAutoplay"]=@(g);[[YTPlaybackConfig new]setStartPlayback:v];CHECK(originals==1&&flag==(v&&!g));
        reset();prefs[@"disableAmbientMode"]=@(g);resultBool=v;CHECK([[YTWatchCinematicContainerController new]isCinematicLightingAvailable]==(v&&!g));CHECK(originals==!g);
        reset();[[YTPlaylistVideoCell new]setCanReorder:v];CHECK(flag&&originals==1);
    }
    for(int g=0;g<2;g++){
        reset();prefs[@"noRelatedWatchNexts"]=@(g);NSUInteger wide=UINT64_C(0xfedcba9876543210);[[YTWatchNextResultsViewController new]setVisibleSections:wide];CHECK(sectionsValue==(g?1:wide)&&originals==1);
        reset();prefs[@"noWatermarks"]=@(g);[[YTAnnotationsViewController new]loadFeaturedChannelWatermark];CHECK(originals==!g);
        reset();prefs[@"miniplayer"]=@(g);[[YTWatchFloatingMiniplayerViewController new]updateMiniBarPlayerStateFromRenderer];CHECK(originals==!g);
        reset();confirms=0;prefs[@"noContentWarning"]=@(g);[[YTPlayabilityResolutionUserActionUIController new]showConfirmAlert];CHECK(originals==!g&&confirms==(NSUInteger)g);
        reset();snapCalls=0;prefs[@"dontSnapToChapter"]=@(g);[[YTSegmentableInlinePlayerBarView new]didMoveToWindow];CHECK(originals==1&&snapCalls==(NSUInteger)g);CHECK([events.firstObject isEqual:@"orig"]);if(g)CHECK(!flag&&[events.lastObject isEqual:@"snap"]);
        reset();prefs[@"noHudMsgs"]=@(g);id m=[NSObject new],h=[NSObject new];NSUInteger before=hudDeaths;@autoreleasepool{YTHUDMessageView*v=[[YTHUDMessageView alloc]initWithMessage:m dismissHandler:h];CHECK((v==nil)==g&&originals==!g);if(!g)CHECK(lastObject==m&&lastSecond==h);}CHECK(hudDeaths==before+1);
    }
    reset();CHECK(![[YTYouThereController new]shouldShowYouTherePrompt]&&originals==0);
}
static void zoomTests(){
    ZoomOwner*z=[ZoomOwner new];z->_snappedZoomFactor=2;
    struct C{double current,input,output;} cases[]={{1,1.5,1.5},{1,3,2},{2,2,1},{3,2,1},{3,.5,.5},{2,1,1},{0,3,3},{-1,4,4},{1,NAN,NAN},{NAN,2,2},{1,INFINITY,2}};
    for(auto c:cases)for(int gate=0;gate<2;gate++)for(int finger=0;finger<2;finger++){
        reset();prefs[@"noFreeZoom"]=@(gate);currentZoom=c.current;[z freeZoomViewDidZoom:c.input isTwoFingerZoom:finger];double expected=gate?c.output:c.input;CHECK((isnan(expected)?isnan(zoomValue):zoomValue==expected)&&originals==1&&flag==finger);
    }
    reset();prefs[@"noFreeZoom"]=@YES;[[YTVideoFreeZoomOverlayController new]freeZoomViewDidZoom:5 isTwoFingerZoom:NO];CHECK(zoomValue==5&&reads.count==0);
}
static void qualityTests(){
    reset();qualityInits=qualityDeaths=ownerDeaths=0;videoValue=[NSObject new];NSArray*input=@[@"original"];restrictedResult=@[@"restricted",@"original"];
    __weak id weakController;
    @autoreleasepool{
        QualityOwner*q=[QualityOwner new];q->_video=videoValue;CHECK([q redesignedController]==nil);[q setUserSelectableFormats:input];CHECK(qualityInits==1&&lastObject==restrictedResult&&qualityInput==input);weakController=[q redesignedController];CHECK(weakController!=nil);
        [q setUserSelectableFormats:input];CHECK(qualityInits==1&&originals==2);
        restrictedAvailable=NO;[q setUserSelectableFormats:input];CHECK(lastObject==input&&originals==3);restrictedAvailable=YES;
        [q setRedesignedController:nil];CHECK([q redesignedController]==nil);
    }
    CHECK(weakController==nil&&qualityDeaths==1&&ownerDeaths==1);
    @autoreleasepool{QualityOwner*q=[QualityOwner new];q->_video=videoValue;[q setUserSelectableFormats:input];weakController=[q redesignedController];}
    CHECK(weakController==nil&&qualityDeaths==2&&ownerDeaths==2);
    @autoreleasepool{BOOL threw=NO;@try{[[YTVideoQualitySwitchOriginalController new]setUserSelectableFormats:input];}@catch(NSException*e){threw=[e.name isEqual:NSUndefinedKeyException];}CHECK(threw);}
}
static void overlayTests(){
    YTFullscreenEngagementOverlayView*v=[YTFullscreenEngagementOverlayView new];YTMainAppVideoPlayerOverlayView*parent=[YTMainAppVideoPlayerOverlayView new];Controls*c=[Controls new];c.ytlButtons=[UIView new];c.speedControls=[UIView new];parent.controlsOverlayView=c;v.superview=parent;
    for(int mask=0;mask<32;mask++)for(int expanded=0;expanded<2;expanded++)for(int visible=0;visible<2;visible++){
        reset();prefs[@"downloadManager"]=@((mask&1)!=0);prefs[@"ytlButtonIndex"]=@((mask&2)?2:0);prefs[@"ytlMuteButton"]=@((mask&4)!=0);prefs[@"ytlLockButton"]=@((mask&8)!=0);prefs[@"speedControls"]=@((mask&16)!=0);c.isOverlayVisible=visible;c.ytlButtons.alpha=.75;c.speedControls.alpha=.25;[v setExpanded:expanded];BOOL buttons=((mask&1)&&(mask&2))||(mask&4)||(mask&8);CHECK(c.ytlButtons.alpha==(buttons?(expanded?0:visible):.75));CHECK(c.speedControls.alpha==((mask&16)?(expanded?0:visible):.25));CHECK(originals==1&&flag==expanded&&[events.firstObject isEqual:@"orig"]);
    }
    reset();v.superview=[UIView new];[v setExpanded:YES];CHECK(reads.count==0&&originals==1);
}
static void gestureTests(){
    YTMainAppVideoPlayerOverlayView*view=[YTMainAppVideoPlayerOverlayView new];view.bounds=CGRectMake(15,20,100,200);expectedDelegate=view;UIGestureRecognizer*g=[UIGestureRecognizer new];g.view=view;exitGesture=g;
    NSArray*owners=@[[YTVerticalPanGestureRecognier new],[YTExitFullscreenController new]];
    for(id owner in owners)for(int left=0;left<2;left++)for(int right=0;right<2;right++)for(double x:{-1.,0.,9.99,10.,10.01,50.,89.99,90.,90.01,100.,101.,(double)NAN}){
        reset();prefs[@"gestWideness"]=@10;prefs[@"leftGestureIndex"]=@(left);prefs[@"rightGestureIndex"]=@(right);g.point=CGPointMake(x,999);BOOL blocked=(left&&x<=10)||(right&&x>=90);CHECK([owner gestureRecognizerShouldBegin:g]==!blocked);CHECK(originals==!blocked);CHECK([owner isKindOfClass:[YTExitFullscreenController class]]?exitGestureReads==1:panDelegateReads==2);if(!blocked)CHECK(lastObject==g);
    }
    for(id owner in owners){reset();prefs[@"gestWideness"]=@60;prefs[@"leftGestureIndex"]=@1;prefs[@"rightGestureIndex"]=@1;g.point=CGPointMake(50,0);CHECK(![owner gestureRecognizerShouldBegin:g]);CHECK([reads containsObject:@"leftGestureIndex"]&&[reads containsObject:@"rightGestureIndex"]);}
    expectedDelegate=[UIView new];g.view=expectedDelegate;for(id owner in owners){reset();resultBool=NO;CHECK(![owner gestureRecognizerShouldBegin:g]&&originals==1&&reads.count==0);}
}
static void layoutTests(){
    ActionsOwner*a=[ActionsOwner new];a->_elementView=[UIView new];NodeView*v=[NodeView new];Node*root=[Node new],*tail=[Node new];ASNetworkImageNode*image=[ASNetworkImageNode new];v.keepalive_node=root;a->_elementView.subviews=@[[UIView new],v];root.subnodes=@[[Node new],tail];tail.subnodes=@[image];
    for(int gate=0;gate<2;gate++)for(int url=0;url<2;url++){reset();prefs[@"noMoreVideos"]=@(gate);image.URL=[NSURL URLWithString:url?@"https://i.ytimg.com/vi/id/file":@"https://invalid.example/image"];v.alpha=.75;[a layoutSubviews];CHECK(v.alpha==((gate&&url)?0:.75)&&originals==1);CHECK([events.firstObject isEqual:@"orig"]);}
    reset();prefs[@"noMoreVideos"]=@YES;root.subnodes=@[tail];v.alpha=.75;[a layoutSubviews];CHECK(v.alpha==.75);root.subnodes=@[[Node new],tail,[Node new]];[a layoutSubviews];CHECK(v.alpha==.75);root.subnodes=@[[Node new],tail];tail.subnodes=@[[Node new]];[a layoutSubviews];CHECK(v.alpha==.75);a->_elementView.subviews=@[v];[a layoutSubviews];CHECK(v.alpha==.75);[[YTFullscreenActionsView new]layoutSubviews];CHECK(originals==5);
}
static UIImage*imageNamed(NSString*name){UIImage*i=[UIImage new];i.text=[NSString stringWithFormat:@"<UIImage (Innertube-Resources: %@)>",name];return i;}
static void menuTests(){
    Renderer*r=[Renderer new];Icon*i=[Icon new];r.icon=i;
    for(int gate=0;gate<2;gate++)for(unsigned code:{0u,250u,251u,252u,0xffffffffu}){reset();prefs[@"removePlayNext"]=@(gate);i.iconType=code;BOOL blocked=gate&&code==251;CHECK([[YTMenuItemVisibilityHandler new]shouldShowServiceItemRenderer:r]==!blocked&&originals==!blocked);}
    NSArray *icons=@[@"yt_outline_download_24pt",@"yt_outline_clock_24pt",@"youtube_outline/bookmark_24pt",@"yt_outline_share_24pt",@"yt_outline_slash_circle_left_24pt",@"youtube_outline/person_circle_slash_24pt",@"yt_outline_flag_24pt",@"yt_outline_message_bubble_alert_24pt",@"yt_outline_list_queue_next_24pt",@"yt_outline_youtube_shorts_plus_24pt",@"yt_outline_youtube_music_24pt",@"youtube_outline_experimental/download_24pt",@"youtube_outline_experimental/clock_24pt",@"youtube_outline_experimental/bookmark_24pt",@"youtube_outline_experimental/share_24pt",@"youtube_outline_experimental/circle_slash_24pt",@"youtube_outline_experimental/person_circle_slash_24pt",@"youtube_outline_experimental/flag_24pt",@"youtube_outline_experimental/alert_bubble_24pt",@"youtube_outline_experimental/queue_next_24pt",@"youtube_outline_experimental/remix_24pt",@"youtube_outline_experimental/youtube_music_24pt"];
    NSArray *keys=@[@"removeDownloadMenu",@"removeWatchLaterMenu",@"removeSaveToPlaylistMenu",@"removeShareMenu",@"removeNotInterestedMenu",@"removeDontRecommendMenu",@"removeReportMenu",@"removeFeedbackMenu",@"removePlayNext",@"removeRemixMenu",@"removeYTMMenu",@"removeDownloadMenu",@"removeWatchLaterMenu",@"removeSaveToPlaylistMenu",@"removeShareMenu",@"removeNotInterestedMenu",@"removeDontRecommendMenu",@"removeReportMenu",@"removeFeedbackMenu",@"removePlayNext",@"removeRemixMenu",@"removeYTMMenu"];
    YTDefaultSheetController*sheet=[YTDefaultSheetController new];
    for(NSUInteger n=0;n<icons.count;n++)for(int gate=0;gate<2;gate++)for(int fallback=0;fallback<2;fallback++){
        reset();prefs[keys[n]]=@(gate);Action*a=[Action new];if(fallback){a.iconImage=[UIImage new];a.iconImage.text=@"unmatched";a.button=[UIButton new];a.button.currentImage=imageNamed(icons[n]);}else a.iconImage=imageNamed(icons[n]);[sheet addAction:a];CHECK(originals==!gate);CHECK(reads.count==22);CHECK([reads isEqual:keys]);if(!gate)CHECK(lastObject==a);
    }
    reset();Action*a=[Action new];a.iconImage=imageNamed(@"unlisted");[sheet addAction:a];CHECK(originals==1);a.iconImage=nil;[sheet addAction:a];CHECK(originals==2);
    reset();prefs[keys[0]]=@YES;a.iconImage=imageNamed(@"unlisted");a.button=[UIButton new];a.button.currentImage=imageNamed(icons[0]);[sheet addAction:a];CHECK(originals==1);
}
static void speedTests(){
    SpeedOwner*owner=[SpeedOwner new];UILongPressGestureRecognizer*g=[UILongPressGestureRecognizer new];
    for(int mode:{0,1,2,-1,INT_MAX})for(int kind=0;kind<2;kind++){
        reset();speedCalls=0;prefs[@"speedIndex"]=@(mode);owner->_delegate=kind?[YTMainAppVideoPlayerOverlayViewController new]:[NSObject new];[owner speedmasterDidLongPressWithRecognizer:g];CHECK(originals==(mode==1));CHECK(speedCalls==((mode!=0&&mode!=1&&kind)?1:0));CHECK(reads.count==(mode==0?1:2));if(mode==1||speedCalls)CHECK(lastObject==g);if(speedCalls)CHECK(lastSecond==owner->_delegate);
    }
    reset();prefs[@"speedIndex"]=@2;BOOL threw=NO;@try{[[YTSpeedmasterController new]speedmasterDidLongPressWithRecognizer:g];}@catch(NSException*e){threw=[e.name isEqual:NSUndefinedKeyException];}CHECK(threw);
}
static NSData*archive(id object){NSError*e;NSData*d=[NSKeyedArchiver archivedDataWithRootObject:object requiringSecureCoding:YES error:&e];CHECK(d&&!e);return d;}
static void gradientTests(){
    NSData*red=archive([[UIColor alloc]initWithRed:1 green:0 blue:0]),*blue=archive([[UIColor alloc]initWithRed:0 green:0 blue:1]),*empty=archive(nil);
    unsigned char pixels[100*100*4];const unsigned char *sample=pixels+36000;CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();CGContextRef c=CGBitmapContextCreate(pixels,100,100,8,400,space,kCGImageAlphaPremultipliedLast|kCGBitmapByteOrder32Big);CHECK(c!=NULL);CGColorSpaceRelease(space);
    DrawParameters*p=[DrawParameters new];YTBrandGradientImageProcessor*processor=[YTBrandGradientImageProcessor new];
    for(int mode:{0,1,2,3})for(int square=0;square<2;square++){
        reset();memset(pixels,0,sizeof pixels);prefs[@"progressMainColor"]=red;prefs[@"progressGradientColor"]=blue;prefs[@"progressBarIndex"]=@(mode);p.drawRect=square?CGRectMake(0,0,50,50):CGRectMake(0,0,100,10);[processor willDrawInContext:c drawParameters:p];CGContextFlush(c);BOOL forward=square||(mode!=1&&mode!=2);CHECK(originals==forward);if(forward)CHECK(lastContext==c&&lastObject==p);else if(mode==1)CHECK(sample[0]>250&&sample[2]<2&&sample[3]>250);else{CHECK(sample[0]>240&&sample[2]<15);CHECK(sample[99*4]<15&&sample[99*4+2]>240);}CHECK(CGRectEqualToRect(CGContextGetClipBoundingBox(c),CGRectMake(0,0,100,100)));
        CHECK([reads[0]isEqual:@"progressMainColor"]&&[reads[1]isEqual:@"progressGradientColor"]);CHECK(reads.count==(square?2:mode==1?3:4));
    }
    reset();prefs[@"progressMainColor"]=red;prefs[@"progressGradientColor"]=empty;prefs[@"progressBarIndex"]=@2;p.drawRect=CGRectMake(0,0,100,10);[processor willDrawInContext:c drawParameters:p];CHECK(originals==1);
    for(CGRect r:{CGRectMake(0,0,30,30),CGRectMake(0,0,31,31),CGRectMake(0,0,31,32),CGRectMake(0,0,31.1,32)}){reset();prefs[@"progressMainColor"]=red;prefs[@"progressGradientColor"]=blue;prefs[@"progressBarIndex"]=@1;p.drawRect=r;[processor willDrawInContext:c drawParameters:p];CHECK(originals==(r.size.height>30&&fabs(r.size.width-r.size.height)<1));}
    reset();memset(pixels,0,sizeof pixels);prefs[@"progressMainColor"]=red;prefs[@"progressGradientColor"]=blue;prefs[@"progressBarIndex"]=@2;p.drawRect=CGRectMake(0,0,100,10);CGContextSaveGState(c);CGContextClipToRect(c,CGRectMake(40,0,20,10));[processor willDrawInContext:c drawParameters:p];CHECK(sample[39*4+3]==0&&sample[60*4+3]==0);CHECK(sample[40*4]>130&&sample[40*4]<170&&sample[40*4+2]>80);CHECK(CGRectEqualToRect(CGContextGetClipBoundingBox(c),CGRectMake(40,0,20,10)));CGContextRestoreGState(c);CGContextRelease(c);
}
int main(){@autoreleasepool{
    prefs=[NSMutableDictionary new];reads=[NSMutableArray new];events=[NSMutableArray new];
    unsigned before=0,after=0;objc_property_t*props=class_copyPropertyList([YTVideoQualitySwitchOriginalController class],&before);free(props);
    YTLInstallPlaybackOptionsHooks();props=class_copyPropertyList([YTVideoQualitySwitchOriginalController class],&after);free(props);CHECK(before==0&&after==1);CHECK(strcmp(property_getAttributes(class_getProperty([YTVideoQualitySwitchOriginalController class],"redesignedController")),"T@\"YTVideoQualitySwitchRedesignedController\",&,N")==0);
    simpleTests();zoomTests();qualityTests();overlayTests();gestureTests();layoutTests();menuTests();speedTests();gradientTests();
    printf("%lu actual-hook assertions passed; original image never executed; zero network requests.\n",(unsigned long)checks);
}return 0;}
