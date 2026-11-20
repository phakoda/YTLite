#import "RemoteControlsHost.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import <objc/runtime.h>
#include <stdint.h>
#include <initializer_list>
#include <string.h>
#include <math.h>
static NSUInteger checks;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static NSMutableArray<NSString *> *events;
static NSMutableArray *registrations;
static MPRemoteCommandCenter *center;
static BOOL backward,forward,policyBackward,policyForward;
static double backwardSeconds,forwardSeconds,receivedInterval;
static NSInteger receivedEvent;
static NSUInteger defaultsReads,boolReads,floatReads,policyReads,watchCalls,sharedReads;
static NSDictionary *receivedInfo;
static __weak id observedTarget;
static BOOL mutateAfterOriginal,reenterRegistration,reentered;
static NSString *Name(MPRemoteCommand *command);
@interface MPRemoteCommand ()
@property(nonatomic,copy) NSString *fixtureName;
@end
@implementation MPRemoteCommand
- (void)addTarget:(id)target action:(SEL)action {
    [events addObject:[@"orig:" stringByAppendingString:Name(self)]];
    [registrations addObject:@{ @"command":self,@"target":target?:NSNull.null,@"action":NSStringFromSelector(action)?:@"nil" }];
    CHECK(!observedTarget||observedTarget==target);
    if(reenterRegistration&&!reentered&&([Name(self)isEqual:@"backward"]||[Name(self)isEqual:@"forward"])) { reentered=YES;MPRemoteCommand *track=[Name(self)isEqual:@"backward"]?center.previousTrackCommand:center.nextTrackCommand;[track addTarget:target action:action]; }
}
- (void)setEnabled:(BOOL)enabled { _enabled=enabled;[events addObject:[NSString stringWithFormat:@"enabled:%@:%d",Name(self),enabled]]; }
@end
@implementation MPSkipIntervalCommand
- (void)setPreferredIntervals:(NSArray<NSNumber *> *)intervals { _preferredIntervals=[intervals copy];[events addObject:[@"interval:" stringByAppendingString:Name(self)]]; }
@end
@implementation MPRemoteCommandCenter
+ (instancetype)sharedCommandCenter { sharedReads++;return center; }
@end
@implementation MPNowPlayingInfoCenter
- (void)setNowPlayingInfo:(NSDictionary *)info { receivedInfo=info;[events addObject:@"infoOrig"];if(mutateAfterOriginal){backward=!backward;forward=!forward;} }
@end
@implementation YTWatchController
- (void)handleRemoteControlEvent:(NSInteger)event withInterval:(double)interval { receivedEvent=event;receivedInterval=interval;watchCalls++;[events addObject:@"watchOrig"]; }
@end
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults { defaultsReads++;return [YTLUserDefaults new]; }
- (BOOL)boolForKey:(NSString *)key { boolReads++;[events addObject:[@"bool:" stringByAppendingString:key]];CHECK([key isEqual:@"rcSkipBackward"]||[key isEqual:@"rcSkipForward"]);return [key isEqual:@"rcSkipBackward"]?backward:forward; }
+ (double)floatForKey:(NSString *)key { floatReads++;[events addObject:[@"double:" stringByAppendingString:key]];CHECK([key isEqual:@"rcSkipBackwardSec"]||[key isEqual:@"rcSkipForwardSec"]);return [key isEqual:@"rcSkipBackwardSec"]?backwardSeconds:forwardSeconds; }
@end
BOOL ytpBool(NSString *key) { policyReads++;[events addObject:[@"policy:" stringByAppendingString:key]];CHECK([key isEqual:@"rcSkipBackward"]||[key isEqual:@"rcSkipForward"]);return [key isEqual:@"rcSkipBackward"]?policyBackward:policyForward; }
NSInteger ytpInt(NSString *key) { CHECK(NO);return 0; }
static NSString *Name(MPRemoteCommand *command) { return command.fixtureName; }
static MPRemoteCommand *Command(NSString *name,BOOL skip) { MPRemoteCommand *command=skip?[MPSkipIntervalCommand new]:[MPRemoteCommand new];command.fixtureName=name;return command; }
static void NewCenter(void) { center=[MPRemoteCommandCenter new];center.previousTrackCommand=Command(@"previous",NO);center.nextTrackCommand=Command(@"next",NO);center.skipBackwardCommand=(id)Command(@"backward",YES);center.skipForwardCommand=(id)Command(@"forward",YES); }
static void Reset(void) { events=[NSMutableArray new];registrations=[NSMutableArray new];defaultsReads=boolReads=floatReads=policyReads=watchCalls=sharedReads=0;receivedInfo=nil;mutateAfterOriginal=NO;observedTarget=nil; }
static BOOL SameDouble(double a,double b) { return memcmp(&a,&b,sizeof(double))==0; }
static NSArray *UpdateEvents(void) { return @[@"bool:rcSkipBackward",@"bool:rcSkipForward",@"double:rcSkipBackwardSec",@"interval:backward",@"double:rcSkipForwardSec",@"interval:forward",[NSString stringWithFormat:@"enabled:backward:%d",backward],[NSString stringWithFormat:@"enabled:forward:%d",forward],[NSString stringWithFormat:@"enabled:previous:%d",!backward],[NSString stringWithFormat:@"enabled:next:%d",!forward]]; }
static void CheckUpdate(NSUInteger updates) { CHECK(defaultsReads==updates*2&&boolReads==updates*2&&floatReads==updates*2&&policyReads==0);CHECK(center.skipBackwardCommand.preferredIntervals.count==1&&center.skipForwardCommand.preferredIntervals.count==1);CHECK(SameDouble(center.skipBackwardCommand.preferredIntervals[0].doubleValue,backwardSeconds));CHECK(SameDouble(center.skipForwardCommand.preferredIntervals[0].doubleValue,forwardSeconds));CHECK(center.skipBackwardCommand.enabled==backward&&center.skipForwardCommand.enabled==forward);CHECK(center.previousTrackCommand.enabled==!backward&&center.nextTrackCommand.enabled==!forward); }
int main(int argc,const char **argv) { @autoreleasepool {
    CHECK(argc==2);Reset();NewCenter();backward=YES;forward=NO;backwardSeconds=12.1234567890123;forwardSeconds=24.9876543210987;policyBackward=policyForward=NO;
    IMP add=class_getMethodImplementation([MPRemoteCommand class],@selector(addTarget:action:)),info=class_getMethodImplementation([MPNowPlayingInfoCenter class],@selector(setNowPlayingInfo:)),watch=class_getMethodImplementation([YTWatchController class],@selector(handleRemoteControlEvent:withInterval:));
    YTLInstallRemoteControlsEarlyHooks();CHECK(add!=class_getMethodImplementation([MPRemoteCommand class],@selector(addTarget:action:)));CHECK(info!=class_getMethodImplementation([MPNowPlayingInfoCenter class],@selector(setNowPlayingInfo:)));CHECK(watch==class_getMethodImplementation([YTWatchController class],@selector(handleRemoteControlEvent:withInterval:)));CHECK(events.count==0&&sharedReads==0);
    BOOL backwardsFirst=strcmp(argv[1],"backward")==0;id target=[NSObject new];SEL action=@selector(description);
    if(strncmp(argv[1],"reentrant-",10)==0) {
        reenterRegistration=YES;MPRemoteCommand *track=strstr(argv[1],"backward")?center.previousTrackCommand:center.nextTrackCommand;MPRemoteCommand *skip=track==center.previousTrackCommand?center.skipBackwardCommand:center.skipForwardCommand;
        [track addTarget:target action:action];CHECK(reentered&&registrations.count==4);CHECK(registrations[0][@"command"]==track&&registrations[1][@"command"]==skip&&registrations[2][@"command"]==track&&registrations[3][@"command"]==skip);CheckUpdate(4);CHECK(sharedReads==8);
        NSLog(@"RemoteControls %@: %lu actual Logos runtime checks passed",[NSString stringWithUTF8String:argv[1]],(unsigned long)checks);return 0;
    }
    for(NSUInteger i=0;i<2;i++) {
        Reset();BOOL isBack=(i==0)==backwardsFirst;MPRemoteCommand *command=isBack?center.previousTrackCommand:center.nextTrackCommand;MPRemoteCommand *skip=isBack?center.skipBackwardCommand:center.skipForwardCommand;
        [command addTarget:target action:action];CHECK(registrations.count==2);CHECK(registrations[0][@"command"]==command&&registrations[1][@"command"]==skip);CHECK(registrations[0][@"target"]==target&&registrations[1][@"target"]==target);CHECK([registrations[1][@"action"]isEqual:NSStringFromSelector(action)]);CHECK([events[0]isEqual:[@"orig:" stringByAppendingString:Name(command)]]&&[events[1]isEqual:[@"orig:" stringByAppendingString:Name(skip)]]);
        NSMutableArray *expected=[NSMutableArray arrayWithArray:@[events[0],events[1]]];[expected addObjectsFromArray:UpdateEvents()];[expected addObjectsFromArray:UpdateEvents()];CHECK([events isEqual:expected]);CheckUpdate(2);CHECK(sharedReads==4);
    }
    for(MPRemoteCommand *command in @[center.previousTrackCommand,center.nextTrackCommand,center.skipBackwardCommand,center.skipForwardCommand,Command(@"other",NO)]) { Reset();[command addTarget:nil action:NULL];CHECK(registrations.count==1&&registrations[0][@"target"]==NSNull.null&&[registrations[0][@"action"]isEqual:@"nil"]);CheckUpdate(1); }
    NewCenter();Reset();[center.previousTrackCommand addTarget:target action:action];CHECK(registrations.count==1);CheckUpdate(1);
    Reset();[center.nextTrackCommand addTarget:target action:action];CHECK(registrations.count==1);CheckUpdate(1);
    for(int b=0;b<2;b++)for(int f=0;f<2;f++){Reset();backward=b;forward=f;NSDictionary *infoValue=@{@"arbitrary":@1};[[MPNowPlayingInfoCenter new]setNowPlayingInfo:infoValue];CHECK(receivedInfo==infoValue&&[events[0]isEqual:@"infoOrig"]);NSMutableArray *expected=[NSMutableArray arrayWithObject:@"infoOrig"];[expected addObjectsFromArray:UpdateEvents()];CHECK([events isEqual:expected]);CheckUpdate(1);CHECK(sharedReads==1);}
    Reset();mutateAfterOriginal=YES;[[MPNowPlayingInfoCenter new]setNowPlayingInfo:nil];CHECK(receivedInfo==nil);CheckUpdate(1);
    double special[]={-0.0,-9.5,INFINITY,-INFINITY,NAN};for(double value:special){Reset();backwardSeconds=value;forwardSeconds=value;[[MPNowPlayingInfoCenter new]setNowPlayingInfo:nil];CHECK(isnan(value)?isnan(center.skipBackwardCommand.preferredIntervals[0].doubleValue):SameDouble(center.skipBackwardCommand.preferredIntervals[0].doubleValue,value));CHECK(isnan(value)?isnan(center.skipForwardCommand.preferredIntervals[0].doubleValue):SameDouble(center.skipForwardCommand.preferredIntervals[0].doubleValue,value));}
    Reset();YTLInstallRemoteControlsMainHooks();CHECK(watch!=class_getMethodImplementation([YTWatchController class],@selector(handleRemoteControlEvent:withInterval:)));CHECK(events.count==0);
    YTWatchController *controller=[YTWatchController new];NSInteger values[]={INT64_MIN,-1,0,103,104,105,106,108,INT64_MAX};double incoming=31.98765432109876;backwardSeconds=7.1234567890123;forwardSeconds=9.9876543210987;
    for(int b=0;b<2;b++)for(int f=0;f<2;f++)for(NSInteger event:values){Reset();policyBackward=b;policyForward=f;[controller handleRemoteControlEvent:event withInterval:incoming];BOOL changed=(event==105&&b)||(event==104&&f);CHECK(watchCalls==1&&receivedEvent==(changed?108:event));CHECK(SameDouble(receivedInterval,changed?(event==105?-backwardSeconds:forwardSeconds):incoming));CHECK(policyReads==((event==104||event==105)?1:0));CHECK(floatReads==(changed?1:0)&&defaultsReads==0);CHECK([events.lastObject isEqual:@"watchOrig"]);}
    for(double value:special)for(NSInteger event:{(NSInteger)104,(NSInteger)105}){Reset();policyBackward=policyForward=YES;backwardSeconds=forwardSeconds=value;[controller handleRemoteControlEvent:event withInterval:999];double expected=event==105?-value:value;CHECK(receivedEvent==108&&watchCalls==1);CHECK(isnan(expected)?isnan(receivedInterval):SameDouble(receivedInterval,expected));}
    Reset();policyBackward=policyForward=NO;uint64_t nanBits=0x7ff8000000001357ULL;double payload;memcpy(&payload,&nanBits,8);[controller handleRemoteControlEvent:105 withInterval:payload];CHECK(SameDouble(receivedInterval,payload)&&receivedEvent==105);
    // The recovered hooks keep no target global; mock records are the only retained ownership.
    Reset();__weak NSObject *weakTarget;@autoreleasepool{NSObject *ephemeral=[NSObject new];weakTarget=ephemeral;observedTarget=ephemeral;[center.previousTrackCommand addTarget:ephemeral action:action];[registrations removeAllObjects];}CHECK(weakTarget==nil);observedTarget=nil;
    NSLog(@"RemoteControls %@: %lu actual Logos runtime checks passed",[NSString stringWithUTF8String:argv[1]],(unsigned long)checks);
}return 0;}
