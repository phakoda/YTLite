#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <objc/message.h>

static BOOL noAds, background;
static BOOL ytlBool(NSString *key) { return [key isEqual:@"noAds"] ? noAds : background; }
static id decorated, auxiliary;
static BOOL auxiliaryFlag;
static int decorationCalls, adCalls;

@interface RecoveryOriginal : NSObject
- (BOOL)isPlayableInBackground;
- (BOOL)playableInBackground;
- (BOOL)isBackgroundEnabled;
- (BOOL)shouldBlockUpgradeDialog;
- (BOOL)isMonetized;
- (id)playerAdsArray;
- (id)adSlotsArray;
- (id)auxiliaryUi;
- (void)setHasAuxiliaryUi:(BOOL)value;
- (void)setAuxiliaryUi:(id)value;
- (BOOL)enableSkippableAd;
+ (id)spamSignalsDictionary;
+ (id)spamSignalsDictionaryWithoutIDFA;
- (void)decorateContext:(id)context;
- (id)createAdsPlaybackCoordinator;
- (void)adPlaying:(id)ad;
@end
@implementation RecoveryOriginal
- (BOOL)isPlayableInBackground { return YES; }
- (BOOL)playableInBackground { return YES; }
- (BOOL)isBackgroundEnabled { return YES; }
- (BOOL)shouldBlockUpgradeDialog { return NO; }
- (BOOL)isMonetized { return NO; }
- (id)playerAdsArray { return @[@"original"]; }
- (id)adSlotsArray { return @[@"original"]; }
- (id)auxiliaryUi { return @"original"; }
- (void)setHasAuxiliaryUi:(BOOL)value { auxiliaryFlag = value; }
- (void)setAuxiliaryUi:(id)value { auxiliary = value; }
- (BOOL)enableSkippableAd { return NO; }
+ (id)spamSignalsDictionary { return @{@"original": @YES}; }
+ (id)spamSignalsDictionaryWithoutIDFA { return @{@"original": @YES}; }
- (void)decorateContext:(id)context { decorated = context; decorationCalls++; }
- (id)createAdsPlaybackCoordinator { return @"original"; }
- (void)adPlaying:(id)ad { adCalls++; }
@end

#define MOCK_CLASS(NAME) @interface NAME : RecoveryOriginal @end @implementation NAME @end
MOCK_CLASS(YTIPlayabilityStatus)
MOCK_CLASS(MLVideo)
MOCK_CLASS(YTIBackgroundOfflineSettingCategoryEntryRenderer)
MOCK_CLASS(YTGlobalConfig)
MOCK_CLASS(YTIPlayerResponse)
MOCK_CLASS(YTIClientMdxGlobalConfig)
MOCK_CLASS(YTAdShieldUtils)
MOCK_CLASS(YTDataUtils)
MOCK_CLASS(YTAdsInnerTubeContextDecorator)
MOCK_CLASS(YTAccountScopedAdsInnerTubeContextDecorator)
MOCK_CLASS(YTLocalPlaybackController)
MOCK_CLASS(MDXSession)

/* RECOVERED_HOOKS */

int main(void) {
    @autoreleasepool {
        YTIPlayerResponse *response = [YTIPlayerResponse new];
        for (int enabled = 0; enabled < 2; enabled++) {
            noAds = enabled; background = enabled;
            NSCAssert([[YTIBackgroundOfflineSettingCategoryEntryRenderer new] isBackgroundEnabled] == enabled, @"Background flag");
            NSCAssert(!response.isMonetized, @"Disabled ad blocking must preserve original NO");
            NSArray *ads = response.playerAdsArray;
            NSCAssert(ads.count == (enabled ? 0 : 1), @"Ad array forwarding");
            NSCAssert([response.adSlotsArray count] == (enabled ? 0 : 1), @"Ad slot forwarding");
            if (enabled) NSCAssert([ads isKindOfClass:NSMutableArray.class], @"Mutable empty array");
            NSCAssert([[YTGlobalConfig new] shouldBlockUpgradeDialog] == enabled, @"Upgrade dialog flag");
            NSCAssert([[YTIClientMdxGlobalConfig new] enableSkippableAd] == enabled, @"Skippable ad flag");
            NSCAssert([YTDataUtils.spamSignalsDictionary count] == (enabled ? 0 : 1), @"Spam dictionary forwarding");
            NSCAssert([YTAdShieldUtils.spamSignalsDictionaryWithoutIDFA count] == (enabled ? 0 : 1), @"AdShield dictionary forwarding");
            NSCAssert(response.auxiliaryUi == nil, @"Auxiliary UI removed");
            [response setHasAuxiliaryUi:YES]; [response setAuxiliaryUi:@"test"];
            NSCAssert(!auxiliaryFlag && auxiliary == nil, @"Auxiliary setters pass empty values");
            for (Class cls in @[YTAdsInnerTubeContextDecorator.class, YTAccountScopedAdsInnerTubeContextDecorator.class]) {
                int calls = decorationCalls;
                [[cls new] decorateContext:@"context"];
                NSCAssert(decorationCalls == calls + 1, @"Decorator original always runs");
                NSCAssert(enabled ? decorated == nil : [decorated isEqual:@"context"], @"Decorator argument");
            }
            NSCAssert(enabled ? [[YTLocalPlaybackController new] createAdsPlaybackCoordinator] == nil : [[[YTLocalPlaybackController new] createAdsPlaybackCoordinator] isEqual:@"original"], @"Coordinator forwarding");
            int calls = adCalls;
            [[MDXSession new] adPlaying:@"ad"];
            NSCAssert(adCalls == calls + (enabled ? 0 : 1), @"MDX event forwarding");
        }
        puts("Recovered hooks passed with real Objective-C method replacement on mock host classes.");
    }
}
