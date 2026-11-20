#import "../source/Helpers/YTPPlayerHelper.h"
#import "../source/Controls/DVNHorizontalPanDelegate.h"
#import "../source/Controls/DVNLongPressDelegate.h"
#import <objc/runtime.h>
#import <math.h>
static NSUInteger checks;static NSMutableArray *events,*opens,*commands,*sends;static id commandResult,eventResult;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String);exit(1);}}while(0)
static id N(id value){return value?:NSNull.null;}
@implementation UIView
- (id)_viewControllerForAncestor{[events addObject:@"ancestor"];NSUInteger i=self.ancestorReads++;return self.ancestors.count?self.ancestors[MIN(i,self.ancestors.count-1)]:nil;}
@end
@implementation UIViewController @end
@implementation UIGestureRecognizer @end
@implementation UIPanGestureRecognizer
- (CGPoint)velocityInView:(UIView *)view{[events addObject:@"velocity"];self.velocityReads++;self.velocityView=view;return self.velocity;}
@end
@implementation UITouch
- (CGPoint)locationInView:(UIView *)view{self.reads++;self.locationView=view;return self.point;}
@end
@implementation UIApplication
+ (instancetype)sharedApplication{static id app;if(!app)app=[self new];return app;}
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion{[opens addObject:@[N(url),N(options),N(completion)]];[events addObject:@"openURL"];}
@end
@interface NavObject:NSObject
@property(nonatomic,strong) id node,elementEntry;
@property(nonatomic,strong) UIView *view;
@property(nonatomic,strong) NSArray *parents;
@property(nonatomic) NSUInteger parentReads;
@end
@implementation NavObject
- (id)parentResponder{[events addObject:@"parentResponder"];NSUInteger i=self.parentReads++;return self.parents.count?self.parents[MIN(i,self.parents.count-1)]:nil;}
@end
@interface YTElementsCellController:NavObject @end
@implementation YTElementsCellController @end
@interface YTElementsCellSubclass:YTElementsCellController @end
@implementation YTElementsCellSubclass @end
@interface NavMissingContext:NSObject
@property(nonatomic,strong) NavObject *controller;
@end
@implementation NavMissingContext
- (id)valueForKey:(NSString *)key{[events addObject:key];return[super valueForKey:key];}
@end
@interface NavWithContext:NavMissingContext
@property(nonatomic,strong) NavObject *context;
@end
@implementation NavWithContext @end
@interface NavInheritedContext:NavWithContext @end
@implementation NavInheritedContext @end
@interface YTICommand:NSObject
+ (id)watchNavigationEndpointWithVideoID:(id)videoID;
@end
@implementation YTICommand
+ (id)watchNavigationEndpointWithVideoID:(id)videoID{[commands addObject:N(videoID)];[events addObject:@"command"];return commandResult;}
@end
@interface YTCommandResponderEvent:NSObject
@property(nonatomic,strong) NSArray *arguments;
+ (id)eventWithCommand:(id)command fromView:(UIView *)view entry:(id)entry sendClick:(BOOL)click firstResponder:(id)responder;
- (void)send;
@end
@implementation YTCommandResponderEvent
+ (id)eventWithCommand:(id)command fromView:(UIView *)view entry:(id)entry sendClick:(BOOL)click firstResponder:(id)responder{[events addObject:@"event"];YTCommandResponderEvent *e=eventResult;e.arguments=@[N(command),N(view),N(entry),@(click),N(responder)];return e;}
- (void)send{[events addObject:@"send"];[sends addObject:self.arguments];}
@end
@interface NavZoom:NSObject
@property(nonatomic) double minFreeZoomFactor,videoZoomFactor;
@property(nonatomic) BOOL isSnappedToFillByDefault;
@property(nonatomic) NSUInteger minimumReads,currentReads,snappedReads;
@end
@implementation NavZoom
- (double)minFreeZoomFactor{self.minimumReads++;return _minFreeZoomFactor;}
- (double)videoZoomFactor{self.currentReads++;return _videoZoomFactor;}
- (BOOL)isSnappedToFillByDefault{self.snappedReads++;return _isSnappedToFillByDefault;}
@end
@interface YTMainAppVideoPlayerOverlayViewController:NSObject
@property(nonatomic,strong) NavZoom *videoFreeZoomOverlayController;
@property(nonatomic) BOOL lacksZoom;
@property(nonatomic) NSUInteger zoomReads;
@end
@implementation YTMainAppVideoPlayerOverlayViewController
- (BOOL)respondsToSelector:(SEL)selector{if(selector==@selector(videoFreeZoomOverlayController)&&self.lacksZoom)return NO;return[super respondsToSelector:selector];}
- (NavZoom *)videoFreeZoomOverlayController{self.zoomReads++;return _videoFreeZoomOverlayController;}
@end
@interface NavDynamicLong:DVNLongPressDelegate
@property(nonatomic,strong) NSArray *modeResults,*viewResults;
@property(nonatomic) NSUInteger modeReads,viewReads;
@end
@implementation NavDynamicLong
- (NSInteger)mode{NSUInteger i=self.modeReads++;return self.modeResults.count?[self.modeResults[MIN(i,self.modeResults.count-1)]integerValue]:[super mode];}
- (UIView *)view{NSUInteger i=self.viewReads++;id v=self.viewResults.count?self.viewResults[MIN(i,self.viewResults.count-1)]:[super view];return v==NSNull.null?nil:v;}
@end
@interface NavCaptureLong:DVNLongPressDelegate
@property(nonatomic) CGPoint captured;
@property(nonatomic) NSUInteger calls;
@property(nonatomic) BOOL result;
@end
@implementation NavCaptureLong
- (BOOL)isTouchInSpeedZone:(CGPoint)p{self.captured=p;self.calls++;return self.result;}
@end
static void Reset(void){[events removeAllObjects];[opens removeAllObjects];[commands removeAllObjects];[sends removeAllObjects];commandResult=nil;eventResult=[YTCommandResponderEvent new];}
static void TestParsing(void){
 NSArray *strings=@[@"https://i.ytimg.com/vi/abc123/default.jpg",@"/vi/first//vi/second/",@"prefix/vi/a b/suffix",@"/vi/你好/thumb",@"/vi//",@"/vi/abc",@"https://youtube.com/watch?v=abc",@"/vi_webp/abc/file",@"",@"/VI/abc/",@"x/vi/a?b#c/y",@"/vi/a%2Fb/file"];
 NSArray *expected=@[@"abc123",@"first",@"a b",@"你好",NSNull.null,NSNull.null,NSNull.null,NSNull.null,NSNull.null,NSNull.null,@"a?b#c",@"a%2Fb"];
 for(NSUInteger i=0;i<strings.count;i++){CHECK([N([YTPPlayerHelper getVideoID:strings[i]])isEqual:expected[i]]);CHECK([N([YTPPlayerHelper getVideoID:[strings[i]mutableCopy]])isEqual:expected[i]]);}
 CHECK([[YTPPlayerHelper getVideoID:[NSURL URLWithString:@"https://i.ytimg.com/vi/abc/default.jpg"]]isEqual:@"abc"]);CHECK([YTPPlayerHelper getVideoID:nil]==nil);for(id value in @[@7,@[],@{},[NSObject new]])CHECK([YTPPlayerHelper getVideoID:value]==nil);
}
static void TestFallback(void){
 NSArray *values=@[@"abc",@"a/b",@"",@"[",[NSURL URLWithString:@"https://example.invalid/path"],@7,@{},NSNull.null];
 NSArray *expected=@[@"vnd.youtube://abc",@"vnd.youtube://a/b",NSNull.null,NSNull.null,@"vnd.youtube://https://example.invalid/path",NSNull.null,NSNull.null,NSNull.null];
 for(NSUInteger i=0;i<values.count;i++){Reset();id value=values[i]==NSNull.null?nil:values[i];[YTPPlayerHelper openVideoWithID:value];BOOL called=i==0||i==1||i==3||i==4;CHECK(opens.count==called);if(called){id url=opens[0][0];CHECK([N([(url==NSNull.null?nil:url) absoluteString])isEqual:expected[i]]);CHECK([opens[0][1]isEqual:@{}]);CHECK(opens[0][2]==NSNull.null);}CHECK(!commands.count&&!sends.count);}
}
static NavMissingContext *Handler(Class cls,NavObject *context,NavObject *node){NavMissingContext *h=[cls new];NavObject *controller=[NavObject new];controller.node=node;h.controller=controller;if([h isKindOfClass:[NavWithContext class]])((NavWithContext *)h).context=context;return h;}
static void TestCommandRoutes(void){
 NavObject *node=[NavObject new];node.view=[UIView new];YTElementsCellController *parent=[YTElementsCellController new];parent.elementEntry=[NSObject new];NavObject *context=[NavObject new];context.parents=@[parent];
 for(Class cls in @[[NavMissingContext class],[NavWithContext class],[NavInheritedContext class]])for(NSNumber *valid in @[@NO,@YES])for(NSNumber *command in @[@NO,@YES]){Reset();context.parentReads=0;context.parents=valid.boolValue?@[parent]:@[[NSObject new]];NavMissingContext *h=Handler(cls,context,node);if(command.boolValue)commandResult=[NSObject new];[YTPPlayerHelper openVideoWithID:@"vid" handler:h];BOOL checked=cls!=[NavMissingContext class],route=checked&&valid.boolValue&&command.boolValue;CHECK(opens.count==!route);CHECK(sends.count==route);CHECK(commands.count==(checked&&valid.boolValue));CHECK(context.parentReads==(checked?(valid.boolValue?2:1):0));CHECK([events.firstObject isEqual:@"_controller"]);if(route){CHECK([sends[0]isEqual:@[commandResult,node.view,parent.elementEntry,@NO,parent]]);CHECK([events isEqual:@[@"_controller",@"_context",@"parentResponder",@"parentResponder",@"command",@"event",@"send"]]);}else CHECK(opens[0][2]==NSNull.null);}
 // The second parent is used without repeating its class test.
 Reset();NavObject *second=[NavObject new];second.elementEntry=@"second";context.parentReads=0;context.parents=@[parent,second];commandResult=[NSObject new];NavMissingContext *h=Handler([NavWithContext class],context,node);[YTPPlayerHelper openVideoWithID:@{ @"opaque":@1 } handler:h];CHECK([commands[0]isEqual:@{ @"opaque":@1 }]);CHECK(sends[0][2]==second.elementEntry&&sends[0][4]==second);
 Reset();commandResult=[NSObject new];eventResult=nil;context.parents=@[parent];context.parentReads=0;h=Handler([NavWithContext class],context,node);[YTPPlayerHelper openVideoWithID:nil handler:h];CHECK(commands.count==1&&commands[0]==NSNull.null);CHECK(!sends.count&&!opens.count);CHECK([events.lastObject isEqual:@"event"]);
 Reset();[YTPPlayerHelper openVideoWithID:@"vid" handler:nil];CHECK(opens.count==1);Reset();BOOL raised=NO;@try{[YTPPlayerHelper openVideoWithID:@"vid" handler:[NSObject new]];}@catch(NSException *e){raised=[e.name isEqual:NSUndefinedKeyException];}CHECK(raised&&!opens.count);
 for(NSNumber *valid in @[@NO,@YES])for(NSNumber *hasController in @[@NO,@YES])for(NSNumber *hasEvent in @[@NO,@YES]){Reset();UIViewController *vc=hasController.boolValue?[UIViewController new]:nil;vc.view=[UIView new];if(valid.boolValue)commandResult=[NSObject new];if(!hasEvent.boolValue)eventResult=nil;id videoID=@"vid";[YTPPlayerHelper openVideoWithID:videoID viewController:vc];CHECK(commands.count==1&&commands[0]==videoID);CHECK(opens.count==!valid.boolValue);CHECK(sends.count==(valid.boolValue&&hasEvent.boolValue));if(sends.count)CHECK([sends[0]isEqual:@[commandResult,N(vc.view),N(vc),@NO,N(vc)]]);}
}
static void TestHorizontal(void){
 DVNHorizontalPanDelegate *delegate=[DVNHorizontalPanDelegate new];NSArray *velocities=@[@[@2,@1,@YES],@[@-2,@1,@YES],@[@2,@-1,@YES],@[@1,@2,@NO],@[@1,@1,@NO],@[@0,@0,@NO],@[@0,@-0.0,@NO],@[@(INFINITY),@3,@YES],@[@3,@(INFINITY),@NO],@[@(INFINITY),@(INFINITY),@NO],@[@(NAN),@0,@NO],@[@0,@(NAN),@NO]];
 for(NSArray *v in velocities)for(NSUInteger mode=0;mode<7;mode++){Reset();UIView *view=[UIView new];UIPanGestureRecognizer *pan=[UIPanGestureRecognizer new];pan.view=view;pan.velocity=CGPointMake([v[0]doubleValue],[v[1]doubleValue]);YTMainAppVideoPlayerOverlayViewController *overlay=[YTMainAppVideoPlayerOverlayViewController new];NavZoom *zoom=[NavZoom new];zoom.minFreeZoomFactor=1;zoom.videoZoomFactor=2;zoom.isSnappedToFillByDefault=YES;overlay.videoFreeZoomOverlayController=zoom;
 switch(mode){case 0:view.ancestors=@[[NSObject new]];break;case 1:view.ancestors=@[overlay];overlay.lacksZoom=YES;break;case 2:view.ancestors=@[overlay];break;case 3:view.ancestors=@[overlay];zoom.videoZoomFactor=1;break;case 4:view.ancestors=@[overlay];zoom.isSnappedToFillByDefault=NO;break;case 5:view.ancestors=@[overlay];zoom.minFreeZoomFactor=NAN;break;default:view.ancestors=@[overlay,[NSObject new]];break;}
 BOOL expected=mode==2?NO:[v[2]boolValue];CHECK([delegate gestureRecognizerShouldBegin:pan]==expected);CHECK(view.ancestorReads==(mode?2:1));CHECK(pan.velocityReads==(mode!=2));if(mode!=2)CHECK(pan.velocityView==view);CHECK(zoom.snappedReads==((mode==2||mode==4)?1:0));if(mode>=2&&mode<=5)CHECK(zoom.minimumReads==1&&zoom.currentReads==1);}
 Reset();UIPanGestureRecognizer *pan=[UIPanGestureRecognizer new];pan.velocity=CGPointMake(5,1);CHECK([delegate gestureRecognizerShouldBegin:pan]);CHECK(pan.velocityView==nil&&pan.velocityReads==1);CHECK(![delegate gestureRecognizerShouldBegin:nil]);
}
static void TestLongPress(void){
 DVNLongPressDelegate *d=[DVNLongPressDelegate new];CHECK(d.mode==0&&d.view==nil);CHECK(strcmp(property_getAttributes(class_getProperty([DVNLongPressDelegate class],"view")),"T@\"UIView\",W,N,V_view")==0);CHECK(strcmp(property_getAttributes(class_getProperty([DVNLongPressDelegate class],"mode")),"Tq,N,V_mode")==0);
 UIView *view=[UIView new];view.bounds=CGRectMake(500,700,300,20);d.view=view;
 NSArray *positions=@[@[@-1,@YES,@NO,@YES],@[@0,@YES,@NO,@YES],@[@100,@YES,@NO,@YES],@[@100.0001,@NO,@NO,@NO],@[@199.9999,@NO,@NO,@NO],@[@200,@NO,@YES,@YES],@[@301,@NO,@YES,@YES],@[@(NAN),@NO,@NO,@NO],@[@(INFINITY),@NO,@YES,@YES],@[@(-INFINITY),@YES,@NO,@YES]];
 for(NSNumber *mode in @[@0,@1,@2,@3,@4,@-1,@0x100000001LL,@(NSIntegerMax),@(NSIntegerMin)]){d.mode=mode.integerValue;CHECK(d.mode==mode.integerValue);for(NSArray *p in positions)for(NSNumber *y in @[@0,@10000,@(NAN)]){BOOL expected=mode.integerValue>=1&&mode.integerValue<=3?[p[(NSUInteger)mode.integerValue]boolValue]:NO;CHECK([d isTouchInSpeedZone:CGPointMake([p[0]doubleValue],y.doubleValue)]==expected);}}
 NSArray *widthCases=@[@[@0,@0,@YES,@YES,@YES],@[@-300,@-150,@YES,@YES,@YES],@[@(NAN),@0,@NO,@NO,@NO],@[@(INFINITY),@5,@YES,@NO,@YES]];
 for(NSArray *r in widthCases){view.bounds=CGRectMake(1,2,[r[0]doubleValue],20);for(NSInteger mode=1;mode<=3;mode++){d.mode=mode;CHECK([d isTouchInSpeedZone:CGPointMake([r[1]doubleValue],999)]==[r[(NSUInteger)mode+1]boolValue]);}}
 d.view=nil;d.mode=3;CHECK(![d isTouchInSpeedZone:CGPointZero]);__weak UIView *weakView;@autoreleasepool{UIView *owned=[UIView new];weakView=owned;d.view=owned;CHECK(d.view==owned);}CHECK(weakView==nil&&d.view==nil);CHECK(![d isTouchInSpeedZone:CGPointZero]);
 __weak DVNLongPressDelegate *weakDelegate;@autoreleasepool{DVNLongPressDelegate *owned=[DVNLongPressDelegate new];weakDelegate=owned;owned.view=view;CHECK(owned.view==view);}CHECK(weakDelegate==nil);CHECK(view!=nil);
 NavDynamicLong *dynamic=[NavDynamicLong new];view.bounds=CGRectMake(0,0,300,10);dynamic.modeResults=@[@1,@2];dynamic.viewResults=@[view];CHECK([dynamic isTouchInSpeedZone:CGPointMake(250,0)]);CHECK(dynamic.modeReads==2&&dynamic.viewReads==2);dynamic.modeReads=0;dynamic.viewReads=0;dynamic.modeResults=@[@0];CHECK(![dynamic isTouchInSpeedZone:CGPointZero]);CHECK(dynamic.modeReads==1&&!dynamic.viewReads);dynamic.modeResults=@[@2];dynamic.modeReads=0;dynamic.viewResults=@[view,NSNull.null];CHECK([dynamic isTouchInSpeedZone:CGPointZero]);CHECK(dynamic.viewReads==2&&dynamic.modeReads==2);
 NavCaptureLong *capture=[NavCaptureLong new];capture.view=view;UITouch *touch=[UITouch new];touch.point=CGPointMake(123.25,-765.5);for(NSNumber *result in @[@NO,@YES]){capture.result=result.boolValue;CHECK([capture gestureRecognizer:nil shouldReceiveTouch:touch]==result.boolValue);CHECK(touch.locationView==view);CHECK(CGPointEqualToPoint(capture.captured,touch.point));}CHECK(touch.reads==2&&capture.calls==2);capture.view=nil;capture.result=YES;CHECK([capture gestureRecognizer:[UIGestureRecognizer new] shouldReceiveTouch:touch]);CHECK(touch.locationView==nil&&CGPointEqualToPoint(capture.captured,touch.point));
}
int main(void){@autoreleasepool{events=[NSMutableArray new];opens=[NSMutableArray new];commands=[NSMutableArray new];sends=[NSMutableArray new];TestParsing();TestFallback();TestCommandRoutes();TestHorizontal();TestLongPress();printf("Navigation helpers actual source: %lu checks passed\n",(unsigned long)checks);}return 0;}
