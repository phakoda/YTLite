#import <objc/runtime.h>
#import <math.h>
#import "../source/Hooks/ImageGesturesHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
BOOL isOverlayShown=YES;
static NSUInteger checks,pinches,recognitions,shows,hides,animations;
static NSMutableDictionary *prefs;
static NSMutableArray *events;
static id sentGesture,sentOther;
static BOOL originalAnswer;
static NSTimeInterval duration;
static void(^pending)(void);
#define CHECK(v) do{checks++;if(!(v)){fprintf(stderr,"FAIL %d %s\n",__LINE__,#v);exit(1);}}while(0)
BOOL ytpBool(NSString *key){[events addObject:key];return [prefs[key] boolValue];}
NSInteger ytpInt(NSString *key){return [prefs[key] integerValue];}
@implementation UIView
+ (void)animateWithDuration:(NSTimeInterval)value animations:(void(^)(void))block {animations++;duration=value;pending=[block copy];[events addObject:@"animation"];}
@end
@implementation UIViewController @end
@implementation UIWindow @end
@implementation UIApplication
+ (UIApplication *)sharedApplication {static UIApplication *app;if(!app)app=[UIApplication new];return app;}
@end
@implementation UIGestureRecognizer @end
@implementation UIPinchGestureRecognizer @end
@implementation YTPlayerView
- (void)didPinch:(UIPinchGestureRecognizer *)gesture {pinches++;sentGesture=gesture;[events addObject:@"pinch original"];}
@end
@implementation YTShortsPlayerViewController @end
@implementation ASDisplayNode
- (void)setYogaChildren:(NSArray *)children {}
@end
@implementation ASDisplayNode (FixtureProperties)
- (NSURL *)copiedURL {return objc_getAssociatedObject(self,@selector(copiedURL));}
- (void)setCopiedURL:(NSURL *)url {objc_setAssociatedObject(self,@selector(copiedURL),url,OBJC_ASSOCIATION_RETAIN_NONATOMIC);[events addObject:@"copy URL"];}
@end
@implementation ASNetworkImageNode @end
@interface YTImageZoomNode ()
@property(nonatomic,strong) id didLoadImage;
@property(nonatomic) BOOL pretendNotNetwork;
@end
@implementation YTImageZoomNode
- (BOOL)isKindOfClass:(Class)cls {return cls==[ASNetworkImageNode class] && self.pretendNotNetwork?NO:[super isKindOfClass:cls];}
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)other {
    recognitions++;sentGesture=gesture;sentOther=other;[events addObject:@"recognizer original"];return originalAnswer;
}
@end
@interface RootFixture : UIViewController <YTLImageGestureRoot> @end
@implementation RootFixture
- (void)showPivotBar {shows++;[events addObject:@"show"];}
- (void)hidePivotBar {hides++;[events addObject:@"hide"];}
@end
@interface AppDelegateFixture : NSObject <UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window;
@end
@implementation AppDelegateFixture @end
@interface ShortsViewFixture : UIView <YTLImageGestureShortsView>
@property(nonatomic,strong) UIView *playbackOverlay;
@end
@implementation ShortsViewFixture @end
@interface NamedImageContainer : ASDisplayNode
@property(nonatomic,copy) NSString *label;
@end
@implementation NamedImageContainer
- (NSString *)description {return self.label;}
@end
@interface AlphaFixture : UIView
@property(nonatomic) CGFloat actual;
@end
@implementation AlphaFixture
- (void)setAlpha:(CGFloat)value { (void)value; }
- (CGFloat)alpha {return self.actual;}
@end
static void pinchChecks(void) {
    YTPlayerView *player=[YTPlayerView new];UIViewController *delegate=[UIViewController new];player.playerViewDelegate=delegate;
    YTShortsPlayerViewController *shorts=[YTShortsPlayerViewController new];ShortsViewFixture *view=[ShortsViewFixture new];view.playbackOverlay=[UIView new];shorts.view=view;
    AppDelegateFixture *app=[AppDelegateFixture new];app.window=[UIWindow new];app.window.rootViewController=[RootFixture new];UIApplication.sharedApplication.delegate=app;
    for(NSUInteger mask=0;mask<8;mask++)for(NSNumber *value in @[@0.5,@1.0,@2.0,@(NAN)]) {
        prefs[@"pinchToFullscreenShorts"]=@(mask&1);prefs[@"shortsOnlyMode"]=@((mask>>1)&1);delegate.parentViewController=mask&4?shorts:[UIViewController new];
        UIPinchGestureRecognizer *gesture=[UIPinchGestureRecognizer new];gesture.scale=value.doubleValue;pending=nil;[events removeAllObjects];
        NSUInteger p=pinches,a=animations,h=hides,s=shows;isOverlayShown=YES;view.playbackOverlay.alpha=0.4;
        [player didPinch:gesture];CHECK(pinches==p+1);CHECK(sentGesture==gesture);CHECK([events.firstObject isEqual:@"pinch original"]);
        BOOL active=(mask&1)&&(mask&4);CHECK(animations==a+active);
        if(active){CHECK(pending!=nil);CHECK(duration==0.3);CHECK(isOverlayShown);CHECK(view.playbackOverlay.alpha==0.4);pending();CHECK(view.playbackOverlay.alpha==(value.doubleValue>1?0:1));CHECK(isOverlayShown==(value.doubleValue<=1 || isnan(value.doubleValue)));}
        CHECK(hides==h+(active&&!(mask&2)&&value.doubleValue>1));CHECK(shows==s+(active&&!(mask&2)&&!(value.doubleValue>1)));
    }
    prefs[@"pinchToFullscreenShorts"]=@YES;delegate.parentViewController=shorts;view.playbackOverlay=nil;UIPinchGestureRecognizer *gesture=[UIPinchGestureRecognizer new];gesture.scale=0.5;
    [player didPinch:gesture];pending();CHECK(!isOverlayShown);
    AlphaFixture *alpha=[AlphaFixture new];alpha.actual=NAN;view.playbackOverlay=alpha;gesture.scale=2;[player didPinch:gesture];pending();CHECK(isOverlayShown);
}
static void imageChecks(void) {
    UIGestureRecognizer *one=[UIGestureRecognizer new],*two=[UIGestureRecognizer new];
    for(NSUInteger mask=0;mask<32;mask++)for(id loaded in @[[NSNull null],@NO,@YES]) {
        YTImageZoomNode *image=[YTImageZoomNode new];image.didLoadImage=loaded==[NSNull null]?nil:loaded;image.pretendNotNetwork=(mask&2)!=0;
        prefs[@"postManager"]=@(mask&1);image.URL=mask&4?[NSURL URLWithString:@"https://example.invalid/image"]:nil;
        NamedImageContainer *target=[NamedImageContainer new];target.label=mask&8?@"prefix id.ui.backstage.original_post suffix":@"unrelated";
        NSURL *old=[NSURL URLWithString:@"https://example.invalid/old"];target.copiedURL=old;image.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[image.supernodes addObject:target];originalAnswer=(mask&16)!=0;
        [events removeAllObjects];NSUInteger count=recognitions;BOOL answer=[image gestureRecognizer:one shouldRecognizeSimultaneouslyWithGestureRecognizer:two];
        CHECK(answer==originalAnswer);CHECK(recognitions==count+1);CHECK(sentGesture==one);CHECK(sentOther==two);CHECK([events.lastObject isEqual:@"recognizer original"]);
        BOOL matched=(mask&1)&&(mask&8)&&image.didLoadImage!=nil;
        CHECK(target.copiedURL==(matched?(image.pretendNotNetwork?nil:image.URL):old));
        CHECK([events containsObject:@"copy URL"]==matched);
    }
}
int main(void){@autoreleasepool {prefs=[NSMutableDictionary dictionary];events=[NSMutableArray array];YTLInstallImageGesturesHooks();pinchChecks();imageChecks();printf("PASS: %lu actual ImageGestures checks\n",(unsigned long)checks);}return 0;}
