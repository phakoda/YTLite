#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Hooks/SponsorPlaybackHost.h"
#import "../source/Playback/SBPlaybackController.h"
#import "../source/Playback/SBPlayerDecorator.h"
#import "../source/Runtime/YTLFeaturePolicy.h"

static NSUInteger checks, constructed, skipped, decorated;
static NSMutableArray<NSString *> *events;
static NSMutableDictionary<NSString *, NSNumber *> *preferences;
static NSArray *lastArguments;
static __weak id lastReceiver, lastConstructedPlayer, lastDecoratedPlayer, lastDecoratedVideo;
static SEL lastSelector;
static BOOL originalMakesAd;
#define CHECK(value) do { checks++; if (!(value)) { fprintf(stderr,"FAIL %d: %s\n",__LINE__,#value); exit(1); } } while (0)

BOOL ytpBool(NSString *key) { [events addObject:[@"gate:" stringByAppendingString:key]]; return [preferences[key] boolValue]; }
NSInteger ytpInt(NSString *key) { CHECK(NO); return 0; }
@interface YTPlayerViewController ()
@property(nonatomic) BOOL fixtureAd;
@property(nonatomic, strong) id fixtureParent;
@end
@implementation YTWatchViewController
@end
@interface WatchSubclass : YTWatchViewController
@end
@implementation WatchSubclass
@end
@implementation YTPlayerViewController
@dynamic sbPlaybackController;
- (BOOL)isPlayingAd { [events addObject:@"ad"]; return self.fixtureAd; }
- (id)parentViewController { [events addObject:@"parent"]; return self.fixtureParent; }
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {
    [events addObject:@"original"]; lastReceiver=self; lastSelector=_cmd;
    lastArguments=@[controller ?: NSNull.null,video ?: NSNull.null,data ?: NSNull.null];
    if (originalMakesAd) self.fixtureAd=YES;
}
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id)time {
    [events addObject:@"original"]; lastReceiver=self; lastSelector=_cmd;
    lastArguments=@[video ?: NSNull.null,time ?: NSNull.null];
}
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id)time {
    [events addObject:@"original"]; lastReceiver=self; lastSelector=_cmd;
    lastArguments=@[video ?: NSNull.null,time ?: NSNull.null];
}
@end
@implementation SBPlaybackController
- (instancetype)initWithPlayer:(YTPlayerViewController *)player {
    if ((self=[super init])) { constructed++; lastConstructedPlayer=player; [events addObject:@"construct"]; }
    return self;
}
- (void)skipSegmentIfNeeded { skipped++; [events addObject:@"skip"]; }
@end
@implementation SBPlayerDecorator
+ (void)addDurationWithoutSegments:(id)player videoController:(id)video {
    decorated++; lastDecoratedPlayer=player; lastDecoratedVideo=video; [events addObject:@"decorate"];
}
@end
static void reset(void) { [events removeAllObjects]; constructed=skipped=decorated=0; lastArguments=nil; lastReceiver=nil; lastSelector=NULL; }

int main(void) { @autoreleasepool {
    events=[NSMutableArray new]; preferences=[NSMutableDictionary new];
    CHECK(class_getInstanceMethod(YTPlayerViewController.class,@selector(sbPlaybackController))==NULL);
    YTLInstallSponsorPlaybackHooks();
    objc_property_t property=class_getProperty(YTPlayerViewController.class,"sbPlaybackController");
    CHECK(property!=NULL); NSString *attributes=@(property_getAttributes(property));
    CHECK([attributes containsString:@"T@\"SBPlaybackController\""]); CHECK([attributes containsString:@",&"]);
    YTPlayerViewController *player=[YTPlayerViewController new], *other=[YTPlayerViewController new];
    __weak SBPlaybackController *weakController;
    @autoreleasepool { SBPlaybackController *c=[[SBPlaybackController alloc]initWithPlayer:player]; weakController=c; player.sbPlaybackController=c; }
    @autoreleasepool {
        CHECK(weakController!=nil); CHECK(player.sbPlaybackController==weakController); CHECK(other.sbPlaybackController==nil);
        player.sbPlaybackController=nil;
    }
    CHECK(weakController==nil);
    id controller=[NSObject new], video=[NSObject new], data=[NSObject new], time=[NSObject new];
    for (NSNumber *ad in @[@NO,@YES]) for (NSNumber *enabled in @[@NO,@YES]) for (NSNumber *feed in @[@NO,@YES]) {
        for (id parent in @[NSNull.null,[NSObject new],[YTWatchViewController new],[WatchSubclass new]]) {
            player.fixtureAd=ad.boolValue; player.fixtureParent=parent==NSNull.null?nil:parent;
            preferences[@"sponsorBlock"]=enabled; preferences[@"sbFeedPlayer"]=feed;
            SBPlaybackController *old=[[SBPlaybackController alloc]initWithPlayer:player]; player.sbPlaybackController=old;
            reset(); [player playbackController:controller didActivateVideo:video withPlaybackData:data];
            BOOL shouldConstruct=!ad.boolValue && enabled.boolValue && (feed.boolValue || [parent isKindOfClass:YTWatchViewController.class]);
            CHECK(constructed==(NSUInteger)shouldConstruct); CHECK(lastReceiver==player);
            CHECK(lastSelector==@selector(playbackController:didActivateVideo:withPlaybackData:));
            CHECK(([lastArguments isEqual:@[controller,video,data]]));
            CHECK(shouldConstruct ? player.sbPlaybackController!=old : player.sbPlaybackController==old);
            if (shouldConstruct) CHECK(lastConstructedPlayer==player);
            NSMutableArray *expected=[NSMutableArray arrayWithObjects:@"original",@"ad",nil];
            if (!ad.boolValue) { [expected addObject:@"gate:sponsorBlock"]; if (enabled.boolValue) { [expected addObject:@"gate:sbFeedPlayer"]; if (!feed.boolValue) [expected addObject:@"parent"]; } }
            if (shouldConstruct) [expected addObject:@"construct"];
            CHECK([events isEqual:expected]);
        }
    }
    // The eligibility check uses the state after the original activation.
    preferences[@"sponsorBlock"]=@YES; preferences[@"sbFeedPlayer"]=@YES;
    player.fixtureAd=NO; originalMakesAd=YES; reset();
    [player playbackController:nil didActivateVideo:nil withPlaybackData:nil];
    CHECK(constructed==0); CHECK(([events isEqual:@[@"original",@"ad"]]));
    CHECK(([lastArguments isEqual:@[NSNull.null,NSNull.null,NSNull.null]])); originalMakesAd=NO;
    for (NSNumber *mutated in @[@NO,@YES]) for (NSNumber *enabled in @[@NO,@YES]) for (NSNumber *duration in @[@NO,@YES]) for (NSNumber *hasController in @[@NO,@YES]) {
        preferences[@"sponsorBlock"]=enabled;
        // Distinct packaged keys must not be accidentally unified.
        preferences[@"sbDuration"]=mutated.boolValue?@(!duration.boolValue):duration;
        preferences[@"sbDurationLabel"]=mutated.boolValue?duration:@(!duration.boolValue);
        player.sbPlaybackController=hasController.boolValue?[[SBPlaybackController alloc]initWithPlayer:player]:nil;
        reset();
        if (mutated.boolValue) [player potentiallyMutatedSingleVideo:video currentVideoTimeDidChange:time];
        else [player singleVideo:video currentVideoTimeDidChange:time];
        CHECK(lastReceiver==player); CHECK(([lastArguments isEqual:@[video,time]]));
        CHECK(lastSelector==(mutated.boolValue?@selector(potentiallyMutatedSingleVideo:currentVideoTimeDidChange:):@selector(singleVideo:currentVideoTimeDidChange:)));
        CHECK(skipped==(NSUInteger)(enabled.boolValue&&hasController.boolValue));
        CHECK(decorated==(NSUInteger)(enabled.boolValue&&duration.boolValue));
        if (decorated) { CHECK(lastDecoratedPlayer==player); CHECK(lastDecoratedVideo==video); }
        NSMutableArray *expected=[NSMutableArray arrayWithObjects:@"original",@"gate:sponsorBlock",nil];
        if (enabled.boolValue) { if (hasController.boolValue) [expected addObject:@"skip"]; [expected addObject:mutated.boolValue?@"gate:sbDurationLabel":@"gate:sbDuration"]; if (duration.boolValue) [expected addObject:@"decorate"]; }
        CHECK([events isEqual:expected]);
    }
    printf("Sponsor playback: %lu actual Logos/runtime assertions passed\n",(unsigned long)checks);
} return 0; }
