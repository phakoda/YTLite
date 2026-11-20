#import "MediaPolicyHost.h"
#import "../Runtime/YTLFeaturePolicy.h"

%group YTLMediaPolicy
%hook YTIPlayabilityStatus
- (BOOL)isPlayableInBackground { return ytpBool(@"backgroundPlayback"); }
%end
%hook MLVideo
- (BOOL)playableInBackground { return ytpBool(@"backgroundPlayback"); }
%end
%hook YTIBackgroundOfflineSettingCategoryEntryRenderer
- (BOOL)isBackgroundEnabled { return ytpBool(@"backgroundPlayback"); }
%end
%hook YTGlobalConfig
- (BOOL)shouldBlockUpgradeDialog { return ytpBool(@"noAds") ? YES : %orig; }
%end
%hook YTIPlayerResponse
- (BOOL)isMonetized { return ytpBool(@"noAds") ? NO : %orig; }
- (NSMutableArray *)playerAdsArray { return ytpBool(@"noAds") ? [NSMutableArray array] : %orig; }
- (NSMutableArray *)adSlotsArray { return ytpBool(@"noAds") ? [NSMutableArray array] : %orig; }
- (id)auxiliaryUi { return nil; }
- (void)setHasAuxiliaryUi:(BOOL)value { %orig(NO); }
- (void)setAuxiliaryUi:(id)value { %orig(nil); }
%end
%hook YTIClientMdxGlobalConfig
- (BOOL)enableSkippableAd { return ytpBool(@"noAds") ? YES : %orig; }
%end
%hook YTAdShieldUtils
+ (NSDictionary *)spamSignalsDictionary { return ytpBool(@"noAds") ? @{} : %orig; }
+ (NSDictionary *)spamSignalsDictionaryWithoutIDFA { return ytpBool(@"noAds") ? @{} : %orig; }
%end
%hook YTDataUtils
+ (NSDictionary *)spamSignalsDictionary { return ytpBool(@"noAds") ? @{} : %orig; }
+ (NSDictionary *)spamSignalsDictionaryWithoutIDFA { return ytpBool(@"noAds") ? @{} : %orig; }
%end
%hook YTAdsInnerTubeContextDecorator
- (void)decorateContext:(id)context { %orig(ytpBool(@"noAds") ? nil : context); }
%end
%hook YTAccountScopedAdsInnerTubeContextDecorator
- (void)decorateContext:(id)context { %orig(ytpBool(@"noAds") ? nil : context); }
%end
%hook YTLocalPlaybackController
- (id)createAdsPlaybackCoordinator { return ytpBool(@"noAds") ? nil : %orig; }
%end
%hook MDXSession
- (void)adPlaying:(id)ad { if (!ytpBool(@"noAds")) %orig; }
%end
%hook YTIAuxiliaryUi
- (void)setHasMessageRenderers:(BOOL)value { %orig(NO); }
- (void)setMessageRenderers:(id)value { %orig(nil); }
%end
%hook YTITriggerConditions
- (BOOL)hasPlayerCueRangeSet { return NO; }
- (NSUInteger)validAdsStatesArray_Count { return 0; }
%end
%hook YTIVideoPlaybackRelativePosition
- (int64_t)streamTimeMs { return 0; }
- (BOOL)hasStreamTimeMs { return NO; }
%end
%hook YTICoWatchability
- (int32_t)type { return 2; }
- (void)setType:(int32_t)value { %orig(2); }
%end
%end
void YTLInstallMediaPolicyHooks(void) { %init(YTLMediaPolicy); }
