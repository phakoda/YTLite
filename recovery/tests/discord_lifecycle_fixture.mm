#import "../source/Hooks/DiscordLifecycleHost.h"
#import "../source/Discord/YTPDiscordRPC.h"
#import "../source/Models/RPCMedia.h"
#import "../source/Downloads/YTPMedia.h"
#import "../../Utils/YTLUserDefaults.h"
#import <objc/message.h>
#include <math.h>
static NSMutableArray *events;
static NSUInteger checks,originalCalls,gateCalls,parentReads,timeReads;
static BOOL enabled,failMediaFactory;
static __weak id lastSelf,argument1,argument2,argument3,factoryPlayer;
static SEL lastSelector;
static double sought,toleranceBefore,toleranceAfter;
static uintptr_t integral;
static RPCMedia *factoryMedia;
static YTPDiscordRPC *presence;
static UIImage *adaptive;
#define CHECK(c) do {checks++;if(!(c)){fprintf(stderr,"FAIL line %d: %s; events=%s\n",__LINE__,#c,events.description.UTF8String);exit(1);}}while(0)
static void Event(NSString *event){[events addObject:event];}
static void Original(id object,SEL selector) {originalCalls++;lastSelf=object;lastSelector=selector;Event(@"original");}
static void Reset(void) {[events removeAllObjects];originalCalls=gateCalls=parentReads=timeReads=0;lastSelf=nil;lastSelector=NULL;argument1=argument2=argument3=nil;integral=0;}
static BOOL SameDouble(double a,double b) {return memcmp(&a,&b,sizeof a)==0;}
@implementation UIImage @end
@implementation UIView @end
@implementation UIViewController
- (UIViewController *)parentViewController {parentReads++;Event(@"parent");return _parentViewController;}
@end
@implementation UIButton
- (void)setImage:(UIImage *)image forState:(NSUInteger)state {self.fixtureImage=image;self.fixtureState=state;Event(@"image");}
@end
@interface YTInlineMutedPlaybackWatchViewController:UIViewController @end
@implementation YTInlineMutedPlaybackWatchViewController @end
@interface YTShortsPlayerViewController:UIViewController @end
@implementation YTShortsPlayerViewController @end
@interface FixtureShortsSubclass:YTShortsPlayerViewController @end
@implementation FixtureShortsSubclass @end
@interface FixtureTime:NSObject<YTLDiscordPlaybackTime>
@property double value;
@end
@implementation FixtureTime
- (double)time {timeReads++;Event(@"readTime");return self.value;}
@end
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults {CHECK(NO);return nil;}
+ (BOOL)boolForKey:(NSString *)key {CHECK([key isEqual:@"discordRPC"]);gateCalls++;Event(@"gate");return enabled;}
+ (void)setBool:(BOOL)value forKey:(NSString *)key {CHECK([key isEqual:@"discordRPC"]);enabled=value;Event(@"preference");}
@end
@implementation RPCMedia
+ (instancetype)mediaWithPlayer:(id)player {factoryPlayer=player;Event(@"factory");return failMediaFactory?nil:factoryMedia;}
- (void)setCurrentTime:(double)value {_currentTime=value;Event(@"currentTime");}
- (void)setIsPaused:(BOOL)value {_isPaused=value;Event(@"paused");}
@end
@implementation YTPDiscordRPC
+ (instancetype)sharedPresence {Event(@"shared");return presence;}
- (void)setMedia:(RPCMedia *)media {_media=media;Event(@"media");}
- (void)startIfPossible {Event(@"start");}
- (void)updateTime {Event(@"updateTime");}
- (void)updateState {Event(@"updateState");}
- (void)clearPlayback {Event(@"clear");}
@end
@implementation YTPMedia
+ (UIImage *)adaptiveDiscord {Event(enabled?@"adaptiveOn":@"adaptiveOff");return adaptive;}
@end
@implementation YTPlayerViewController
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {argument1=controller;argument2=video;argument3=data;Original(self,_cmd);}
- (void)seekToTime:(double)time {sought=time;Original(self,_cmd);}
- (void)seekToTime:(double)time seekSource:(YTLDiscordForwardedInteger)source {sought=time;integral=source;Original(self,_cmd);}
- (void)seekToTime:(double)time toleranceBefore:(double)before toleranceAfter:(double)after seekSource:(YTLDiscordForwardedInteger)source {sought=time;toleranceBefore=before;toleranceAfter=after;integral=source;Original(self,_cmd);}
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time {argument1=video;argument2=time;Original(self,_cmd);}
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time {argument1=video;argument2=time;Original(self,_cmd);}
@end
@implementation YTWatchPlaybackController
- (void)playbackControllerDidPlay {Original(self,_cmd);}
- (void)playbackControllerDidPause {Original(self,_cmd);}
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLDiscordForwardedInteger)value {integral=value;Original(self,_cmd);}
- (void)clearPlaybackController {Original(self,_cmd);}
@end
static UIViewController *ancestor;
@implementation YTMainAppControlsOverlayView
- (UIViewController *)_viewControllerForAncestor {Event(@"ancestor");return ancestor;}
@end
static void CheckOriginal(id object,SEL selector) {CHECK(originalCalls==1);CHECK(lastSelf==object&&lastSelector==selector);}
static void TestActivation(void) {
    YTPlayerViewController *player=[YTPlayerViewController new];NSObject *controller=[NSObject new],*video=[NSObject new],*data=[NSObject new];
    NSArray *parents=@[NSNull.null,[UIViewController new],[YTInlineMutedPlaybackWatchViewController new],[YTShortsPlayerViewController new],[FixtureShortsSubclass new]];
    for(NSUInteger i=0;i<parents.count;i++)for(NSNumber *gate in @[@NO,@YES]) {
        enabled=gate.boolValue;player.parentViewController=i?parents[i]:nil;factoryMedia.isPaused=YES;
        Reset();[player playbackController:controller didActivateVideo:video withPlaybackData:data];
        CheckOriginal(player,@selector(playbackController:didActivateVideo:withPlaybackData:));CHECK(argument1==controller&&argument2==video&&argument3==data);CHECK(gateCalls==0);
        if(i<2){CHECK([events isEqual:(@[@"original",@"parent",@"parent",@"shared",@"factory",@"media",@"paused",@"start"])]);CHECK(presence.media==factoryMedia&&factoryPlayer==player&&!factoryMedia.isPaused);}
        else CHECK([events isEqual:(i==2?@[@"original",@"parent"]:@[@"original",@"parent",@"parent"])]);
    }
    player.parentViewController=nil;failMediaFactory=YES;Reset();[player playbackController:nil didActivateVideo:nil withPlaybackData:nil];CHECK(presence.media==nil);CHECK([events isEqual:(@[@"original",@"parent",@"parent",@"shared",@"factory",@"media",@"start"])]);failMediaFactory=NO;presence.media=factoryMedia;
}
static void TestSeeks(void) {
    YTPlayerViewController *player=[YTPlayerViewController new];NSArray *parents=@[NSNull.null,[UIViewController new],[YTInlineMutedPlaybackWatchViewController new],[YTShortsPlayerViewController new]];
    SEL selectors[]={@selector(seekToTime:),@selector(seekToTime:seekSource:),@selector(seekToTime:toleranceBefore:toleranceAfter:seekSource:)};
    double times[]={-0.0,-7.25,1.0/3.0,INFINITY,NAN,9007199254740991.0};
    for(NSUInteger method=0;method<3;method++)for(NSUInteger parent=0;parent<4;parent++)for(NSNumber *gate in @[@NO,@YES])for(NSUInteger t=0;t<6;t++) {
        player.parentViewController=parent?parents[parent]:nil;enabled=gate.boolValue;factoryMedia.currentTime=314;Reset();
        double time=times[t];uintptr_t source=UINTPTR_MAX-(uintptr_t)t;
        if(method==0)[player seekToTime:time];else if(method==1)[player seekToTime:time seekSource:source];else [player seekToTime:time toleranceBefore:-0.0 toleranceAfter:9007199254740991.0 seekSource:source];
        CheckOriginal(player,selectors[method]);CHECK(SameDouble(sought,time));if(method>0)CHECK(integral==source);if(method==2){CHECK(SameDouble(toleranceBefore,-0.0));CHECK(toleranceAfter==9007199254740991.0);}
        if(parent<2&&enabled){CHECK(SameDouble(factoryMedia.currentTime,time));CHECK([events isEqual:(@[@"original",@"parent",@"parent",@"gate",@"shared",@"currentTime",@"updateTime"])]);}
        else {CHECK(factoryMedia.currentTime==314);CHECK([events isEqual:(parent==2?@[@"original",@"parent"]:parent==3?@[@"original",@"parent",@"parent"]:@[@"original",@"parent",@"parent",@"gate"])]);}
        CHECK(gateCalls==(parent<2?1u:0u));
    }
    player.parentViewController=nil;enabled=YES;presence.media=nil;Reset();[player seekToTime:20];CHECK([events isEqual:(@[@"original",@"parent",@"parent",@"gate",@"shared",@"updateTime"])]);presence.media=factoryMedia;
}
static void TestTime(void) {
    YTPlayerViewController *player=[YTPlayerViewController new];player.parentViewController=[YTShortsPlayerViewController new];NSObject *video=[NSObject new];FixtureTime *time=[FixtureTime new];time.value=234.125;
    SEL methods[]={@selector(singleVideo:currentVideoTimeDidChange:),@selector(potentiallyMutatedSingleVideo:currentVideoTimeDidChange:)};
    for(NSUInteger i=0;i<2;i++)for(NSNumber *gate in @[@NO,@YES])for(NSNumber *nilTime in @[@NO,@YES]) {
        enabled=gate.boolValue;factoryMedia.currentTime=19;Reset();id value=nilTime.boolValue?nil:time;
        ((void(*)(id,SEL,id,id))objc_msgSend)(player,methods[i],video,value);CheckOriginal(player,methods[i]);CHECK(argument1==video&&argument2==value);CHECK(parentReads==0&&gateCalls==1);
        if(enabled){CHECK(factoryMedia.currentTime==(nilTime.boolValue?0:234.125));CHECK(timeReads==(nilTime.boolValue?0u:1u));CHECK([events isEqual:(nilTime.boolValue?@[@"original",@"gate",@"shared",@"currentTime"]:@[@"original",@"gate",@"shared",@"readTime",@"currentTime"])]);}
        else{CHECK(factoryMedia.currentTime==19&&timeReads==0);CHECK([events isEqual:(@[@"original",@"gate"])]);}
    }
}
static void TestWatch(void) {
    YTWatchPlaybackController *watch=[YTWatchPlaybackController new];SEL methods[]={@selector(playbackControllerDidPlay),@selector(playbackControllerDidPause),@selector(playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:),@selector(clearPlaybackController)};
    for(NSUInteger i=0;i<4;i++)for(NSNumber *gate in @[@NO,@YES]){
        enabled=gate.boolValue;factoryMedia.isPaused=i==0;Reset();
        if(i==2)((void(*)(id,SEL,uintptr_t))objc_msgSend)(watch,methods[i],UINTPTR_MAX);else ((void(*)(id,SEL))objc_msgSend)(watch,methods[i]);
        CheckOriginal(watch,methods[i]);CHECK(gateCalls==1);if(i==2)CHECK(integral==UINTPTR_MAX);
        if(enabled){CHECK([events isEqual:(i<2?@[@"gate",@"shared",@"paused",@"updateState",@"original"]:@[@"gate",@"shared",@"clear",@"original"])]);if(i<2)CHECK(factoryMedia.isPaused==(i==1));}
        else CHECK([events isEqual:(@[@"gate",@"original"])]);
    }
    presence.media=nil;enabled=YES;Reset();[watch playbackControllerDidPause];CHECK([events isEqual:(@[@"gate",@"shared",@"updateState",@"original"])]);presence.media=factoryMedia;
}
static void TestTap(void) {
    YTMainAppControlsOverlayView *view=[YTMainAppControlsOverlayView new];UIButton *button=[UIButton new];ancestor=[UIViewController new];UIViewController *player=[YTPlayerViewController new];ancestor.parentViewController=player;
    for(NSNumber *gate in @[@NO,@YES]){
        enabled=gate.boolValue;factoryMedia.isPaused=YES;Reset();[view handleYTLDiscordTap:button];CHECK(enabled!=gate.boolValue);CHECK(originalCalls==0&&gateCalls==1);CHECK(button.fixtureImage==adaptive&&button.fixtureState==0);
        if(gate.boolValue)CHECK([events isEqual:(@[@"gate",@"preference",@"shared",@"clear",@"adaptiveOff",@"image"])]);
        else{CHECK(factoryPlayer==player&&presence.media==factoryMedia);CHECK(factoryMedia.isPaused);CHECK([events isEqual:(@[@"gate",@"preference",@"shared",@"ancestor",@"parent",@"factory",@"media",@"start",@"adaptiveOn",@"image"])]);}
    }
    enabled=NO;ancestor=nil;failMediaFactory=YES;Reset();[view handleYTLDiscordTap:nil];CHECK(factoryPlayer==nil&&presence.media==nil&&enabled);CHECK([events isEqual:(@[@"gate",@"preference",@"shared",@"ancestor",@"factory",@"media",@"start",@"adaptiveOn"])]);failMediaFactory=NO;
}
int main(void) {@autoreleasepool {
    events=[NSMutableArray new];presence=[YTPDiscordRPC new];factoryMedia=[RPCMedia new];presence.media=factoryMedia;adaptive=[UIImage new];
    CHECK(![YTMainAppControlsOverlayView instancesRespondToSelector:@selector(handleYTLDiscordTap:)]);
    YTLInstallDiscordLifecycleHooks();CHECK([YTMainAppControlsOverlayView instancesRespondToSelector:@selector(handleYTLDiscordTap:)]);
    TestActivation();TestSeeks();TestTime();TestWatch();TestTap();
    printf("Discord lifecycle: %lu actual Logos/runtime assertions passed across 11 registrations\n",(unsigned long)checks);
}return 0;}
