#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import "../source/Hooks/ShortsPlaybackHost.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#include <limits.h>
static NSUInteger checks,originalFinish,originalLoop,originalActivation,originalBars,pauses,advances,qualityReads,selections,wifiReads,defaultInits,specificInits;
static YTLShortsForwardedArgument forwardedFinish,forwardedController,forwardedResponse;
static BOOL maybeAvailable=YES,advanceAvailable=YES,wifi=YES,constraintAvailable=YES,mutateModeOnFinish;
static id parentObject,qualityObject,lastController,lastConstraint,lastFormats;
static NSMutableDictionary *preferences;
static NSMutableArray *events,*gateKeys;
#define CHECK(c) do {checks++;if(!(c)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#c);exit(1);}}while(0)
BOOL ytpBool(NSString *key) {[events addObject:key];[gateKeys addObject:key];return [preferences[key] boolValue];}
NSInteger ytpInt(NSString *key) {[events addObject:key];[gateKeys addObject:key];return [preferences[key] integerValue];}
@implementation UIViewController @end
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLHelper
+ (BOOL)isConnectedToWiFi {wifiReads++;return wifi;}
@end
@implementation YTReelPlayerViewController
- (BOOL)respondsToSelector:(SEL)sel {
    if(sel==@selector(maybeLoopPlayback))return maybeAvailable;
    if(sel==@selector(reelContentViewRequestsAdvanceToNextVideo:))return advanceAvailable;
    return [super respondsToSelector:sel];
}
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLShortsForwardedArgument)value {
    originalFinish++;forwardedFinish=value;[events addObject:@"originalFinish"];
    if(mutateModeOnFinish)preferences[@"shortsPlaybackIndex"]=@2;
}
- (void)maybeLoopPlayback {originalLoop++;[events addObject:@"originalLoop"];}
- (void)playbackControllerDidActivateVideo:(YTLShortsForwardedArgument)controller withPlayerResponse:(YTLShortsForwardedArgument)response {
    originalActivation++;forwardedController=controller;forwardedResponse=response;[events addObject:@"originalActivation"];
}
- (void)pause {pauses++;[events addObject:@"pause"];}
- (id)performSelector:(SEL)selector {
    CHECK(selector==@selector(reelContentViewRequestsAdvanceToNextVideo:));advances++;[events addObject:@"performSelector"];return nil;
}
- (id)parentResponder {return parentObject;}
- (id<YTLShortsQualityController>)videoQualityController {qualityReads++;return qualityObject;}
- (void)videoQualitySwitchController:(id)controller didSelectFormatConstraint:(id)constraint forSelectableVideoFormats:(NSArray *)formats {
    selections++;lastController=controller;lastConstraint=constraint;lastFormats=formats;[events addObject:@"selection"];
}
- (BOOL)shouldEnablePlayerBar {originalBars++;return YES;}
- (BOOL)shouldAlwaysEnablePlayerBar {originalBars++;return YES;}
- (BOOL)shouldEnablePlayerBarOnlyOnPause {originalBars++;return YES;}
@end
@implementation YTReelPlayerViewControllerSub
- (BOOL)shouldEnablePlayerBar {originalBars++;return YES;}
- (BOOL)shouldAlwaysEnablePlayerBar {originalBars++;return YES;}
- (BOOL)shouldEnablePlayerBarOnlyOnPause {originalBars++;return YES;}
@end
@implementation YTShortsPlayerViewController
- (BOOL)shouldAlwaysEnablePlayerBar {originalBars++;return YES;}
- (BOOL)shouldEnablePlayerBarOnlyOnPause {originalBars++;return YES;}
@end
#pragma clang diagnostic pop
@interface EngagedReel : YTReelPlayerViewController { @public BOOL _isEngagementPanelVisible; } @end
@implementation EngagedReel @end
@interface YTReelWatchRootViewController : NSObject @end
@implementation YTReelWatchRootViewController @end
@interface InfiniteRoot : YTReelWatchRootViewController { @public BOOL _isInfinitePlaybackMode; } @end
@implementation InfiniteRoot @end
@interface UnrelatedInfiniteRoot : NSObject { @public BOOL _isInfinitePlaybackMode; } @end
@implementation UnrelatedInfiniteRoot @end
@interface QualityController : NSObject { @public NSArray *_sortedSelectableFormats; } @end
@implementation QualityController @end
@interface Format : NSObject <YTLShortsSelectableFormat>
@property(nonatomic) int singleDimensionResolution;
@property(nonatomic,copy) NSString *qualityLabel;
@end
@implementation Format @end
@interface MLQuickMenuVideoQualitySettingFormatConstraint : NSObject <YTLShortsConstraint>
@property(nonatomic) int setting;
@property(nonatomic) NSInteger reason;
@property(nonatomic,copy) NSString *label;
@end
@implementation MLQuickMenuVideoQualitySettingFormatConstraint
- (instancetype)init {self=[super init];if(self)defaultInits++;return self;}
- (BOOL)respondsToSelector:(SEL)sel {
    if(sel==@selector(initWithVideoQualitySetting:formatSelectionReason:qualityLabel:))return constraintAvailable;
    return [super respondsToSelector:sel];
}
- (instancetype)initWithVideoQualitySetting:(int)setting formatSelectionReason:(NSInteger)reason qualityLabel:(NSString *)label {
    if((self=[super init])) {specificInits++;_setting=setting;_reason=reason;_label=[label copy];} return self;
}
@end
static Format *F(int resolution,NSString *label) {Format *f=[Format new];f.singleDimensionResolution=resolution;f.qualityLabel=label;return f;}
static void Reset(void) {
    originalFinish=originalLoop=originalActivation=originalBars=pauses=advances=qualityReads=selections=wifiReads=defaultInits=specificInits=0;
    forwardedFinish=forwardedController=forwardedResponse=0;maybeAvailable=advanceAvailable=wifi=constraintAvailable=YES;mutateModeOnFinish=NO;
    parentObject=qualityObject=lastController=lastConstraint=lastFormats=nil;[preferences removeAllObjects];[events removeAllObjects];[gateKeys removeAllObjects];
}
static void Formats(NSArray *formats) {QualityController *controller=[QualityController new];controller->_sortedSelectableFormats=formats;qualityObject=controller;}
static NSString *Chosen(void) {return [(MLQuickMenuVideoQualitySettingFormatConstraint *)lastConstraint label];}
static void FinishTests(void) {
    YTReelPlayerViewController *player=[YTReelPlayerViewController new];
    for(NSNumber *available in @[@NO,@YES])for(NSNumber *mode in @[@(NSIntegerMin),@(-1),@0,@1,@2,@3,@(0x100000002ULL),@(NSIntegerMax)]) {
        Reset();maybeAvailable=available.boolValue;preferences[@"shortsPlaybackIndex"]=mode;
        uintptr_t value=UINT64_C(0xfedcba9876543210);[player playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:value];
        BOOL forwarded=available.boolValue||mode.integerValue!=2;
        CHECK(originalFinish==(NSUInteger)forwarded);CHECK(pauses==(NSUInteger)(available.boolValue&&mode.integerValue==2));
        if(forwarded)CHECK(forwardedFinish==value);
        CHECK(gateKeys.count==1&&[gateKeys[0]isEqual:@"shortsPlaybackIndex"]);
        CHECK([events.firstObject isEqual:available.boolValue?@"originalFinish":@"shortsPlaybackIndex"]);
    }
    Reset();preferences[@"shortsPlaybackIndex"]=@0;mutateModeOnFinish=YES;
    [player playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:9];
    CHECK((pauses==1&&[events isEqual:@[@"originalFinish",@"shortsPlaybackIndex",@"pause"]]));
}
static void LoopTests(void) {
    NSArray *players=@[[YTReelPlayerViewController new],[EngagedReel new]];
    for(YTReelPlayerViewController *player in players)for(NSNumber *visible in @[@NO,@YES])for(NSNumber *available in @[@NO,@YES])for(NSNumber *mode in @[@0,@1,@2,@(0x100000001ULL)]) {
        Reset();advanceAvailable=available.boolValue;preferences[@"shortsPlaybackIndex"]=mode;
        BOOL hasIvar=[player isKindOfClass:EngagedReel.class];if(hasIvar)((EngagedReel *)player)->_isEngagementPanelVisible=visible.boolValue;
        [player maybeLoopPlayback];
        BOOL advance=mode.integerValue==1&&available.boolValue&&!(hasIvar&&visible.boolValue);
        CHECK(advances==(NSUInteger)advance);CHECK(originalLoop==(NSUInteger)!advance);CHECK(pauses==0&&selections==0);
        CHECK(gateKeys.count==1&&[gateKeys[0]isEqual:@"shortsPlaybackIndex"]);
    }
}
static void ActivationTests(void) {
    YTReelPlayerViewController *player=[YTReelPlayerViewController new];
    for(NSNumber *restrict in @[@NO,@YES])for(NSNumber *wireless in @[@0,@1])for(NSNumber *cell in @[@0,@2]) {
        Reset();InfiniteRoot *root=[InfiniteRoot new];root->_isInfinitePlaybackMode=YES;parentObject=root;
        preferences[@"restrictShortsPortion"]=restrict;preferences[@"shortsWiFiQualityIndex"]=wireless;preferences[@"shortsCellQualityIndex"]=cell;
        [player playbackControllerDidActivateVideo:UINT64_C(0xf0000000abcdef12) withPlayerResponse:UINT64_C(0xe000000076543210)];
        CHECK(originalActivation==1&&forwardedController==UINT64_C(0xf0000000abcdef12)&&forwardedResponse==UINT64_C(0xe000000076543210));
        CHECK([events.firstObject isEqual:@"originalActivation"]);CHECK(root->_isInfinitePlaybackMode==!restrict.boolValue);
        CHECK(qualityReads==(NSUInteger)(wireless.integerValue||cell.integerValue));
        CHECK([gateKeys containsObject:@"shortsCellQualityIndex"]==!wireless.boolValue);
    }
    Reset();preferences[@"restrictShortsPortion"]=@YES;
    parentObject=[YTReelWatchRootViewController new];[player playbackControllerDidActivateVideo:1 withPlayerResponse:2];CHECK(originalActivation==1);
    UnrelatedInfiniteRoot *unrelated=[UnrelatedInfiniteRoot new];unrelated->_isInfinitePlaybackMode=YES;parentObject=unrelated;
    [player playbackControllerDidActivateVideo:1 withPlayerResponse:2];CHECK(unrelated->_isInfinitePlaybackMode);
    parentObject=nil;[player playbackControllerDidActivateVideo:1 withPlayerResponse:2];CHECK(originalActivation==3);
    Reset();preferences[@"shortsWiFiQualityIndex"]=@0;preferences[@"shortsCellQualityIndex"]=@3;wifi=YES;Formats(@[F(1080,@"1080p"),F(240,@"240p")]);
    [player playbackControllerDidActivateVideo:1 withPlayerResponse:2];
    CHECK(selections==1&&[Chosen()isEqual:@"240p"]);CHECK([events.lastObject isEqual:@"selection"]); // Immediate fallback for selected Default on WiFi.
}
static void CheckSelection(YTReelPlayerViewController *player,NSArray *formats,NSInteger index,NSString *expected) {
    Reset();Formats(formats);preferences[@"shortsWiFiQualityIndex"]=@(index);[player autoQuality];
    CHECK(selections==1&&[Chosen()isEqual:expected]);CHECK(lastController==qualityObject&&lastFormats==formats);
    MLQuickMenuVideoQualitySettingFormatConstraint *constraint=lastConstraint;
    CHECK(constraint.setting==3&&constraint.reason==2);CHECK(defaultInits==1&&specificInits==1&&wifiReads==1);
    CHECK([gateKeys isEqual:@[@"shortsWiFiQualityIndex"]]);
}
static void QualityTests(void) {
    YTReelPlayerViewController *player=[YTReelPlayerViewController new];
    Reset();[player autoQuality];CHECK(!selections&&!wifiReads&&qualityReads==1);
    Reset();qualityObject=[NSObject new];[player autoQuality];CHECK(!selections&&!wifiReads&&qualityReads==2);
    Reset();Formats(@[]);[player autoQuality];CHECK(!selections&&!wifiReads&&qualityReads==3);
    NSArray *all=@[F(2160,@"2160p Premium"),F(1080,@"1080p60"),F(1080,@"1080p"),F(720,@"720p60"),F(720,@"720p"),F(480,@"480p"),F(360,@"360p"),F(240,@"240p"),F(144,@"144p")];
    NSArray *expected=@[@"144p",@"1080p60",@"1080p60",@"1080p",@"720p60",@"720p",@"480p",@"360p",@"240p",@"144p"];
    for(NSUInteger index=0;index<expected.count;index++)CheckSelection(player,all,index,expected[index]);
    CheckSelection(player,@[F(2160,@"2160p Premium"),F(720,@"720p60"),F(720,@"720p"),F(1080,@"1080p premium")],1,@"1080p premium"); // Case-sensitive exclusion.
    CheckSelection(player,@[F(720,@"720p60"),F(720,@"720p"),F(240,@"240p")],1,@"720p60"); // Equal-resolution first wins.
    CheckSelection(player,@[F(720,@"720p60"),F(720,@"720p"),F(240,@"240p")],3,@"720p60"); // Missing 1080p, closest label first wins.
    CheckSelection(player,@[F(360,@"360p"),F(720,@"720p"),F(600,@"600p")],6,@"360p"); // Equidistant lower first; no sorted-order assumption.
    CheckSelection(player,@[F(600,@"600p"),F(360,@"360p"),F(720,@"720p")],6,@"600p"); // First candidate wins equal distances.
    CheckSelection(player,@[F(2000,@"nonsense"),F(10,@"720p60"),F(20,@"360p")],3,@"720p60"); // Fallback parses labels, not dimensions.
    CheckSelection(player,@[F(1000,@"720p30p60"),F(360,@"360p"),F(2000,@"Premium")],5,@"360p");
    CheckSelection(player,@[F(1000,@"nonsense"),F(2000,@"720p Premium")],3,@"1080p"); // No parseable ordinary formats preserves requested label.
    CheckSelection(player,@[F(2000,@"Premium")],1,@"144p"); // Default highest when every candidate excluded.
    CheckSelection(player,@[F(2000,@"Premium"),F(1,@"Default")],0,@"Default"); // Exact label wins without fallback parsing.
    CheckSelection(player,@[F(2000,@"Premium"),F(1,@"-9223372036854775808p"),F(144,@"144p")],0,@"-9223372036854775808p"); // Signed wrapped ARM distance.
    Reset();wifi=NO;Formats(all);preferences[@"shortsWiFiQualityIndex"]=@2;preferences[@"shortsCellQualityIndex"]=@7;
    [player autoQuality];CHECK([Chosen()isEqual:@"360p"]&&[gateKeys isEqual:@[@"shortsCellQualityIndex"]]);
    Reset();constraintAvailable=NO;Formats(all);preferences[@"shortsWiFiQualityIndex"]=@1;[player autoQuality];CHECK(defaultInits==1&&specificInits==0&&selections==0);
    for(NSNumber *index in @[@(-1),@10,@(0x100000001ULL)]) {
        Reset();Formats(all);preferences[@"shortsWiFiQualityIndex"]=index;BOOL raised=NO;
        @try {[player autoQuality];} @catch(NSException *exception) {raised=[exception.name isEqual:NSRangeException];}
        CHECK(raised&&selections==0);
    }
}
static void Bars(void) {
    NSArray *objects=@[[YTReelPlayerViewController new],[YTReelPlayerViewControllerSub new],[YTShortsPlayerViewController new]];
    for(id object in objects)for(NSNumber *enabled in @[@NO,@YES]) {
        Reset();preferences[@"shortsProgress"]=enabled;
        NSArray *selectors=[object isKindOfClass:YTShortsPlayerViewController.class]?@[@"shouldAlwaysEnablePlayerBar",@"shouldEnablePlayerBarOnlyOnPause"]:@[@"shouldEnablePlayerBar",@"shouldAlwaysEnablePlayerBar",@"shouldEnablePlayerBarOnlyOnPause"];
        for(NSString *name in selectors) {
            SEL sel=NSSelectorFromString(name);BOOL value=((BOOL(*)(id,SEL))objc_msgSend)(object,sel);
            CHECK(value==([name isEqual:@"shouldEnablePlayerBarOnlyOnPause"]?!enabled.boolValue:enabled.boolValue));
            CHECK(originalBars==0&&[gateKeys.lastObject isEqual:@"shortsProgress"]);
        }
    }
}
int main(void) {@autoreleasepool {
    preferences=[NSMutableDictionary new];events=[NSMutableArray new];gateKeys=[NSMutableArray new];
    CHECK(class_getInstanceMethod(YTReelPlayerViewController.class,@selector(autoQuality))==NULL);
    YTLInstallShortsPlaybackHooks();CHECK(class_getInstanceMethod(YTReelPlayerViewController.class,@selector(autoQuality))!=NULL);
    FinishTests();LoopTests();ActivationTests();QualityTests();Bars();
    printf("ShortsPlayback: %lu actual-hook runtime assertions passed across 12 registrations\n",(unsigned long)checks);
}return 0;}
