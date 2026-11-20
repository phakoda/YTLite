#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Presentation/PlayerToast.h"
#import "../source/Presentation/ToastView.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSString+YTLite.h"
#include <math.h>
static NSUInteger checks;static NSMutableArray *scheduled,*notices,*events,*adjustValues;
static NSMutableDictionary *preferences;
static NSString *toastText,*actionTitle,*messageText;
static double toastValue,toastDuration;
static NSInteger toastStyle;
static BOOL toastCompact;
static dispatch_block_t resetAction;

#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
@implementation UIView @end
@implementation UIVisualEffectView @end
@implementation UIApplication
+ (instancetype)sharedApplication{static id app;if(!app)app=[self new];return app;}
@end
@implementation UILongPressGestureRecognizer
- (NSInteger)state{_stateReads++;if(_states.count){NSInteger s=[_states[0]integerValue];[_states removeObjectAtIndex:0];return s;}return _state;}
- (CGPoint)locationInView:(UIView *)v{CHECK(v==self.view);_locationReads++;return _point;}
@end
@implementation PlayerToast
+ (instancetype)sharedToast{static id t;if(!t)t=[self new];return t;}
- (void)showPlayerToastWithText:(NSString*)t value:(double)v style:(long long)s isCompact:(BOOL)c{toastText=t;toastValue=v;toastStyle=s;toastCompact=c;[events addObject:@"show"];}
- (void)updateToastText:(NSString*)t value:(double)v{toastText=t;toastValue=v;[events addObject:@"update"];}
- (void)hideToast{[events addObject:@"hide"];}
@end
@implementation ToastView
- (void)showProgressiveToastWithText:(NSString*)t duration:(double)d actionTitle:(NSString*)a actionCompletion:(dispatch_block_t)c{messageText=t;toastDuration=d;actionTitle=a;resetAction=[c copy];[events addObject:@"progressive"];}
@end
@implementation NSString (SpeedFixtureLocalization)
- (NSString*)ytl_localized{return[self isEqual:@"SpeedPreserved"]?@"Preserved %@":[@"localized:" stringByAppendingString:self];}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{return nil;}
+ (NSInteger)integerForKey:(NSString*)k{return[preferences[k]integerValue];}
+ (double)floatForKey:(NSString*)k{return[preferences[k]doubleValue];}
+ (BOOL)boolForKey:(NSString*)k{if([k isEqual:@"adjustByFinger"]&&adjustValues.count){BOOL v=[adjustValues[0]boolValue];[adjustValues removeObjectAtIndex:0];return v;}return[preferences[k]boolValue];}
@end
@interface YTActivePlaybackRateModel:NSObject
@property float rate;
- (instancetype)initWithRate:(float)rate;
@end
@implementation YTActivePlaybackRateModel
- (instancetype)initWithRate:(float)rate{self=[super init];if(self)_rate=rate;return self;}
@end
@interface SpeedVideo:NSObject
@property(strong) YTActivePlaybackRateModel *activePlaybackRateModel;
@end
@implementation SpeedVideo @end
@interface SpeedNativeVideo:SpeedVideo
@property float playbackRate;
@end
@implementation SpeedNativeVideo @end
@interface SpeedPlayer:NSObject
@property(strong) SpeedVideo *activeVideo;
@end
@implementation SpeedPlayer @end
@implementation YTPSpeedMaster (FixtureScheduling)
+ (void)performSelector:(SEL)selector withObject:(id)object afterDelay:(NSTimeInterval)delay{CHECK(selector==@selector(_applyPendingRateForPlayer:));CHECK(delay==0.05);[scheduled addObject:object];}
@end
static SpeedPlayer *Player(BOOL native){SpeedPlayer *p=[SpeedPlayer new];p.activeVideo=native?[SpeedNativeVideo new]:[SpeedVideo new];return p;}
@interface GestureMaster:YTPSpeedMaster
@property double rate;
@property(strong) NSMutableArray *assigned;
@end
@implementation GestureMaster
- (double)currentPlaybackRate{return (double)(float)_rate;}
- (void)setPlaybackRate:(double)rate{_rate=rate;[_assigned addObject:@(rate)];[events addObject:@"rate"];}
@end
static void configure(GestureMaster*m,NSInteger index,double preference){preferences[@"speedIndex"]=@(index);preferences[@"playbackRate"]=@(preference);preferences[@"adjustByFinger"]=@YES;preferences[@"preserveSpeed"]=@NO;preferences[@"compactToast"]=@YES;[events removeAllObjects];[m.assigned removeAllObjects];[adjustValues removeAllObjects];}
static UILongPressGestureRecognizer *gesture(NSInteger state,double y){UILongPressGestureRecognizer*g=[UILongPressGestureRecognizer new];g.state=state;g.point=CGPointMake(11,y);g.view=[UIView new];return g;}
static void arrayTests(void){YTPSpeedMaster*m=[YTPSpeedMaster new];[m setValue:@0 forKey:@"speedIndex"];NSArray*a=[m speedArray];CHECK(a.count==196&&[a isKindOfClass:NSMutableArray.class]);for(NSUInteger i=0;i<a.count;i++)CHECK([a[i]doubleValue]==(25.0+5.0*i)/100.0);[m setValue:@2 forKey:@"speedIndex"];a=[m speedArray];CHECK([a isEqual:@[@0.25,@0.5,@0.75,@1.0,@1.25,@1.5,@1.75,@2.0,@3.0,@4.0,@5.0]]);[m setValue:a forKey:@"speedArray"];CHECK([m nearestIndexForRate:1.125]==3);CHECK([m nearestIndexForRate:NAN]==2);[m setValue:@[@1,@(NAN),@2] forKey:@"speedArray"];CHECK([m nearestIndexForRate:1.8]==2);[m setValue:@[]forKey:@"speedArray"];CHECK([m nearestIndexForRate:1]==2);}
static void gestureTests(void){GestureMaster*m=[GestureMaster new];m.assigned=[NSMutableArray new];id owner=[NSObject new];
 for(NSInteger mode=0;mode<3;mode+=2){configure(m,mode,1.25);m.rate=0.75;UILongPressGestureRecognizer*g=gesture(1,100);[m manageSpeedMaster:g playerOverlayVC:owner];CHECK(m.rate==1.25&&[m.assigned isEqual:@[@1.25]]);CHECK(toastValue==1.25&&toastStyle==1&&toastCompact&&[toastText isEqual:@"localized:Toast.PlaybackSpeed"]);CHECK([events isEqual:@[@"rate",@"show"]]&&g.stateReads==1&&g.locationReads==1);CHECK([m valueForKey:@"controller"]==owner);CHECK([[m valueForKey:@"gestureBaseRate"]doubleValue]==1.25&&[[m valueForKey:@"rateBeforeSpeedmaster"]doubleValue]==0.75);
 NSArray*translations= mode==2 ? @[@25,@24.99,@(-8.34),@(-8.32),@10000,@(-10000),@(INFINITY),@(-INFINITY),@(NAN)] : @[@2.5,@2.51,@(-2.5),@39.99,@40,@(-40),@10000,@(-10000),@(NAN)];
 NSArray*expected= mode==2 ? @[@1.5,@1.25,@1,@1.25,@5,@0.25,@0.25,@0.25,@1.25] : @[@1.25,@1.3,@1.25,@1.65,@3.25,@0.25,@10,@0.25,@0.25];
 for(NSUInteger i=0;i<translations.count;i++){[events removeAllObjects];[m.assigned removeAllObjects];g=gesture(2,100-[translations[i]doubleValue]);[m manageSpeedMaster:g playerOverlayVC:owner];CHECK(fabs(m.rate-[expected[i]doubleValue])<1e-12);CHECK(m.assigned.count==1&&[events isEqual:@[@"rate",@"update"]]);CHECK(toastValue==(double)(float)m.rate);}
 [events removeAllObjects];[m manageSpeedMaster:gesture(3,0) playerOverlayVC:owner];CHECK(m.rate==0.75&&[events isEqual:@[@"rate",@"update",@"hide"]]&&toastValue==0.75);
 }
 // A changing preference activates the original second changed-state branch.
 configure(m,2,1.25);m.rate=1;[m manageSpeedMaster:gesture(1,100)playerOverlayVC:owner];[events removeAllObjects];[adjustValues addObjectsFromArray:@[@NO,@YES]];UILongPressGestureRecognizer*g=gesture(2,80);[m manageSpeedMaster:g playerOverlayVC:owner];CHECK(m.rate==1.25&&g.stateReads==3&&[events isEqual:@[@"rate",@"update"]]);
 for(NSInteger state=0;state<=5;state++){if(state==1||state==3)continue;configure(m,2,1.25);preferences[@"adjustByFinger"]=@NO;[m manageSpeedMaster:gesture(state,20)playerOverlayVC:owner];CHECK(events.count==0);}
 configure(m,2,1.25);m.rate=0.75;[m manageSpeedMaster:gesture(1,100)playerOverlayVC:owner];preferences[@"preserveSpeed"]=@YES;[events removeAllObjects];[m manageSpeedMaster:gesture(3,0)playerOverlayVC:owner];CHECK([events isEqual:@[@"progressive",@"hide"]]);CHECK([messageText isEqual:@"Preserved 1.25×"]&&[actionTitle isEqual:@"localized:ResetSpeed"]&&toastDuration==5&&resetAction);
 dispatch_block_t oldAction=[resetAction copy];m.rate=2;[m manageSpeedMaster:gesture(1,100)playerOverlayVC:owner];m.rate=4;oldAction();CHECK(m.rate==2);resetAction=nil;
}
static NSUInteger singletonNewCalls,singletonInitCalls;
@interface SingletonFirstSubclass:YTPSpeedMaster @end
@implementation SingletonFirstSubclass
+ (instancetype)new{singletonNewCalls++;return[super new];}
- (instancetype)init{self=[super init];if(self)singletonInitCalls++;return self;}
@end
static void singletonTests(void){
 CHECK(singletonNewCalls==0&&singletonInitCalls==0);
 YTPSpeedMaster*first=[SingletonFirstSubclass sharedMaster];
 CHECK(first.class==SingletonFirstSubclass.class);
 CHECK(singletonNewCalls==0);
 CHECK(singletonInitCalls==1);
 CHECK([YTPSpeedMaster sharedMaster]==first);
 CHECK([SingletonFirstSubclass sharedMaster]==first);
 CHECK(singletonNewCalls==0&&singletonInitCalls==1);
}
int main(void){@autoreleasepool{
 singletonTests();
 scheduled=[NSMutableArray new];notices=[NSMutableArray new];events=[NSMutableArray new];adjustValues=[NSMutableArray new];preferences=[NSMutableDictionary new];id observer=[[NSNotificationCenter defaultCenter]addObserverForName:@"YTPSpeedDidChange" object:nil queue:nil usingBlock:^(NSNotification *n){[notices addObject:n.object];}];
 // This is deliberately the first rate operation in the process.
 SpeedPlayer *first=Player(NO);[YTPSpeedMaster _applyPendingRateForPlayer:first];CHECK(first.activeVideo.activePlaybackRateModel.rate==1.0f);CHECK([notices isEqual:@[@1.0]]);CHECK(!scheduled.count);
 [YTPSpeedMaster setPlaybackRate:9.0 forPlayer:nil];SpeedPlayer *afterNil=Player(NO);[YTPSpeedMaster _applyPendingRateForPlayer:afterNil];CHECK(afterNil.activeVideo.activePlaybackRateModel.rate==1.0f);CHECK(!scheduled.count);
 SpeedPlayer *native=Player(YES);[YTPSpeedMaster setPlaybackRate:1.23456789 forPlayer:native];CHECK(((SpeedNativeVideo *)native.activeVideo).playbackRate==(float)1.23456789);CHECK([notices.lastObject doubleValue]==1.23456789);CHECK(!scheduled.count);[YTPSpeedMaster _applyPendingRateForPlayer:first];CHECK(first.activeVideo.activePlaybackRateModel.rate==1.0f);
 SpeedPlayer *a=Player(NO),*b=Player(NO);[YTPSpeedMaster setPlaybackRate:2.125 forPlayer:a];CHECK(!a.activeVideo.activePlaybackRateModel);[YTPSpeedMaster setPlaybackRate:3.123456789 forPlayer:b];CHECK(!b.activeVideo.activePlaybackRateModel);CHECK([scheduled isEqual:@[a,b]]);
 for(SpeedPlayer *player in scheduled){[YTPSpeedMaster _applyPendingRateForPlayer:player];CHECK(player.activeVideo.activePlaybackRateModel.rate==(float)3.123456789);CHECK([notices.lastObject doubleValue]==3.123456789);}
 [YTPSpeedMaster setPlaybackRate:4.0 forPlayer:native];[YTPSpeedMaster _applyPendingRateForPlayer:first];CHECK(first.activeVideo.activePlaybackRateModel.rate==(float)3.123456789);CHECK([notices.lastObject doubleValue]==3.123456789);
 arrayTests();gestureTests();[[NSNotificationCenter defaultCenter]removeObserver:observer];printf("SpeedMaster actual source: %lu checks passed\n",(unsigned long)checks);
}return 0;}
