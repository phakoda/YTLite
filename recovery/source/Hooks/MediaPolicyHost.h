#pragma once
#import <Foundation/Foundation.h>
#include <stdint.h>
FOUNDATION_EXPORT void YTLInstallMediaPolicyHooks(void);
@interface YTIPlayabilityStatus:NSObject
- (BOOL)isPlayableInBackground;
@end
@interface MLVideo:NSObject
- (BOOL)playableInBackground;
@end
@interface YTIBackgroundOfflineSettingCategoryEntryRenderer:NSObject
- (BOOL)isBackgroundEnabled;
@end
@interface YTGlobalConfig:NSObject
- (BOOL)shouldBlockUpgradeDialog;
@end
@interface YTIPlayerResponse:NSObject
- (BOOL)isMonetized;
- (NSMutableArray *)playerAdsArray;
- (NSMutableArray *)adSlotsArray;
- (id)auxiliaryUi;
- (void)setHasAuxiliaryUi:(BOOL)value;
- (void)setAuxiliaryUi:(id)value;
@end
@interface YTIClientMdxGlobalConfig:NSObject
- (BOOL)enableSkippableAd;
@end
@interface YTAdShieldUtils:NSObject
+ (NSDictionary *)spamSignalsDictionary;
+ (NSDictionary *)spamSignalsDictionaryWithoutIDFA;
@end
@interface YTDataUtils:NSObject
+ (NSDictionary *)spamSignalsDictionary;
+ (NSDictionary *)spamSignalsDictionaryWithoutIDFA;
@end
@interface YTAdsInnerTubeContextDecorator:NSObject
- (void)decorateContext:(id)context;
@end
@interface YTAccountScopedAdsInnerTubeContextDecorator:NSObject
- (void)decorateContext:(id)context;
@end
@interface YTLocalPlaybackController:NSObject
- (id)createAdsPlaybackCoordinator;
@end
@interface MDXSession:NSObject
- (void)adPlaying:(id)ad;
@end
@interface YTIAuxiliaryUi:NSObject
- (void)setHasMessageRenderers:(BOOL)value;
- (void)setMessageRenderers:(id)value;
@end
@interface YTITriggerConditions:NSObject
- (BOOL)hasPlayerCueRangeSet;
- (NSUInteger)validAdsStatesArray_Count;
@end
@interface YTIVideoPlaybackRelativePosition:NSObject
// The packaged replacement establishes a 64-bit integer result of zero.
// Its private protobuf signedness cannot be recovered from that constant alone.
- (int64_t)streamTimeMs;
- (BOOL)hasStreamTimeMs;
@end
@interface YTICoWatchability:NSObject
// Original code writes the 32-bit enum slot; its generated enum name is unknown.
- (int32_t)type;
- (void)setType:(int32_t)value;
@end
