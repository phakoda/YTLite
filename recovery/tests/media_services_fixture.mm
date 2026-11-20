#import "../source/Hooks/MediaServicesHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
static NSUInteger checks,calls,captions;
static id lastArgument,lastReceiver;
static SEL lastSelector;
static BOOL originalBool,lastBool;
static NSString *endpointURL;
static uintptr_t lastConstraint;
static NSMutableDictionary *prefs;
static NSMutableArray *events;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
BOOL ytpBool(NSString *key) {[events addObject:key];return [prefs[key] boolValue];}
NSInteger ytpInt(NSString *key) {return [prefs[key] integerValue];}
static void original(id receiver,SEL selector) {calls++;lastReceiver=receiver;lastSelector=selector;[events addObject:@"original"];}
@implementation MDXPlaybackRouteButtonController
- (BOOL)isPersistentCastIconEnabled {original(self,_cmd);return originalBool;}
- (void)updateRouteButton:(id)button {original(self,_cmd);lastArgument=button;}
- (void)updateAllRouteButtons {original(self,_cmd);}
@end
@implementation YTSettings
- (void)setDisableMDXDeviceDiscovery:(BOOL)disabled {original(self,_cmd);lastBool=disabled;}
- (BOOL)areHintsDisabled {original(self,_cmd);return originalBool;}
- (void)setHintsDisabled:(BOOL)disabled {original(self,_cmd);lastBool=disabled;}
@end
@implementation _UIConcretePasteboard
- (void)setString:(NSString *)string {original(self,_cmd);lastArgument=string;}
@end
@implementation YTIIosSystemShareEndpoint
- (NSString *)shareURL {original(self,_cmd);return endpointURL;}
@end
@implementation YTSingleVideoController
- (void)setAudioFormatConstraint:(uintptr_t)value {original(self,_cmd);lastConstraint=value;}
@end
@implementation YTWatchFlowController
- (BOOL)shouldExitFullScreenOnFinish {original(self,_cmd);return originalBool;}
@end
@interface CaptionFixture : NSObject <YTLMediaServicesCaptions> @end
@implementation CaptionFixture
- (void)selectCaptions {captions++;[events addObject:@"captions"];}
@end
@interface PlayerViewFixture : NSObject <YTLMediaServicesPlayerView>
@property(nonatomic,strong) id<YTLMediaServicesCaptions> ancestor;
@end
@implementation PlayerViewFixture
- (id<YTLMediaServicesCaptions>)_viewControllerForAncestor {return self.ancestor;}
@end
@interface VideoWithView : YTSingleVideoController
@property(nonatomic,strong) PlayerViewFixture *playerView;
@end
@implementation VideoWithView @end
int main(void) {@autoreleasepool {
    prefs=[NSMutableDictionary dictionary];events=[NSMutableArray array];YTLInstallMediaServicesHooks();
    MDXPlaybackRouteButtonController *route=[MDXPlaybackRouteButtonController new];YTSettings *settings=[YTSettings new];YTWatchFlowController *flow=[YTWatchFlowController new];id button=[NSObject new];
    for(NSUInteger mask=0;mask<16;mask++) {
        prefs[@"noCast"]=@(mask&1);prefs[@"noHints"]=@((mask>>1)&1);prefs[@"exitFullscreen"]=@((mask>>2)&1);originalBool=(mask&8)!=0;
        NSUInteger before=calls;CHECK([route isPersistentCastIconEnabled]==(!(mask&1)&&originalBool));CHECK(calls==before+!(mask&1));
        before=calls;[route updateRouteButton:button];CHECK(calls==before+!(mask&1));if(!(mask&1)){CHECK(lastReceiver==route);CHECK(lastArgument==button);CHECK(lastSelector==@selector(updateRouteButton:));}
        before=calls;[route updateAllRouteButtons];CHECK(calls==before+!(mask&1));
        before=calls;CHECK([settings areHintsDisabled]==(BOOL)((mask>>1)&1));CHECK(calls==before);
        CHECK([flow shouldExitFullScreenOnFinish]==(BOOL)((mask>>2)&1));CHECK(calls==before);
        for(NSNumber *flag in @[@NO,@YES]) {
            [settings setDisableMDXDeviceDiscovery:flag.boolValue];CHECK(lastBool==((mask&1)||flag.boolValue));CHECK(lastSelector==@selector(setDisableMDXDeviceDiscovery:));
            [settings setHintsDisabled:flag.boolValue];CHECK(lastBool==((mask&2)||flag.boolValue));CHECK(lastSelector==@selector(setHintsDisabled:));
        }
    }
    NSArray *cases=@[
        @[@"",@""],@[@"plain text",@"plain text"],@[@"https://example.invalid/path",@"https://example.invalid/path"],
        @[@"https://example.invalid/path?v=abc&si=x&keep=yes#fragment",@"https://example.invalid/path?v=abc#fragment"],
        @[@"https://example.invalid/path?si=x&v=abc",@"https://example.invalid/path"],
        @[@"https://example.invalid/path?x=1&is=&pp=2&y=3",@"https://example.invalid/path?x=1"],
        @[@"https://example.invalid/path?pp&v=abc#f",@"https://example.invalid/path#f"],
        @[@"https://example.invalid/path?SI=x&v=abc",@"https://example.invalid/path?SI=x&v=abc"],
        @[@"https://example.invalid/path?v=abc&%73i=x&tail=1",@"https://example.invalid/path?v=abc"],
        @[@"https://example.invalid/path?v=a%26b&si=x",@"https://example.invalid/path?v=a%26b"],
        @[@"http://[",@"http://["]
    ];
    _UIConcretePasteboard *paste=[_UIConcretePasteboard new];YTIIosSystemShareEndpoint *endpoint=[YTIIosSystemShareEndpoint new];
    for(NSNumber *enabled in @[@NO,@YES]) {
        prefs[@"noShareChunk"]=enabled;
        for(NSArray *pair in cases) {
            NSString *input=[pair[0] mutableCopy];NSString *expected=enabled.boolValue?pair[1]:pair[0];
            [events removeAllObjects];NSUInteger before=calls;[paste setString:input];CHECK(calls==before+1);CHECK([lastArgument isEqual:expected]);CHECK([events isEqual:@[@"noShareChunk",@"original"]]);
            if(!enabled.boolValue || [pair[0] isEqual:pair[1]])CHECK(lastArgument==input);
            endpointURL=input;[events removeAllObjects];before=calls;NSString *result=[endpoint shareURL];CHECK(calls==before+1);CHECK([result isEqual:expected]);CHECK([events isEqual:@[@"noShareChunk",@"original"]]);if(!enabled.boolValue || [pair[0] isEqual:pair[1]])CHECK(result==input);
        }
        [paste setString:nil];CHECK(lastArgument==nil);endpointURL=nil;CHECK([endpoint shareURL]==nil);
    }
    VideoWithView *with=[VideoWithView new];with.playerView=[PlayerViewFixture new];with.playerView.ancestor=[CaptionFixture new];
    for(YTSingleVideoController *video in @[[YTSingleVideoController new],[VideoWithView new],with]) {
        [events removeAllObjects];NSUInteger before=captions;uintptr_t bits=UINT64_C(0xfedcba9876543210);[video setAudioFormatConstraint:bits];CHECK(lastConstraint==bits);CHECK(lastReceiver==video);CHECK(captions==before+(video==with));CHECK([events.firstObject isEqual:@"original"]);if(video==with)CHECK([events.lastObject isEqual:@"captions"]);
    }
    printf("PASS: %lu actual MediaServices checks\n",(unsigned long)checks);
}return 0;}
