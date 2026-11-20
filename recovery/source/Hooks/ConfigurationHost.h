#pragma once
#import <Foundation/Foundation.h>
#include <limits.h>


@interface YTColdConfig : NSObject
- (BOOL)mainAppCoreClientIosEnableStartupAnimation;
- (BOOL)removeNextPaddleForSingletonVideos;
- (BOOL)removePreviousPaddleForSingletonVideos;
- (BOOL)replaceNextPaddleWithFastForwardButtonForSingletonVods;
- (BOOL)replacePreviousPaddleWithRewindButtonForSingletonVods;
- (BOOL)enableHideChipsInTheCommentsHeaderOnScrollIos;
- (BOOL)enableChipsInTheCommentsHeaderIos;
- (BOOL)shouldUseAppThemeSetting;
- (BOOL)isLandscapeEngagementPanelSwipeRightToDismissEnabled;
- (BOOL)enableSwipeToRemoveInPlaylistWatchEp;
- (BOOL)enableLightThemeAmbientMode;
- (BOOL)iosAmbientModeExtendWidthInLandscape;
- (BOOL)iosEnableFullScreenAmbientMode;
- (BOOL)enableTurnOffCinematicForFrameWithBlackBars;
- (BOOL)queueClientGlobalConfigEnableFloatingPlaylistMinibar;
- (BOOL)disablePlaybackLockScreenController;
- (BOOL)iosEnableVideoPlayerScrubber;
- (BOOL)mobileShortsTabInlined;
- (BOOL)iosUseSystemVolumeControlInFullscreen;
- (BOOL)enableYouthereCommandsOnIos;
- (BOOL)cxClientEnableIosLocalNetworkPermissionWifiFixes;
- (BOOL)cxClientEnableIosLocalNetworkPermissionUsingSockets;
- (BOOL)cxClientEnableIosLocalNetworkPermissionReliabilityFixes;
- (BOOL)iosPlayerClientSharedConfigPopulateSwAv1MediaCapabilities;
- (BOOL)mediaEngineClientForceSoftwareDecoderOnDecoderRetry;
@end

@interface YTIPlayerColdConfig : NSObject
- (BOOL)iosDisablePlaybackLockScreenController;
@end

@interface YTIMediaQualitySettingsHotConfig : NSObject
- (BOOL)enableQuickMenuVideoQualitySettings;
- (BOOL)omitAdvancedMenuOptionForAirPlay;
@end

@interface YTHotConfig : NSObject
- (BOOL)enablePlayerBarForVerticalVideoWhenControlsHiddenInFullscreen;
- (BOOL)isPromptForLocalNetworkPermissionsEnabled;
- (BOOL)clientInfraClientConfigIosEnableFillingEncodedHacksInnertubeContext;
- (BOOL)enableShortsVideoQualityPicker;
@end

@interface YTIHamplayerServerABRConfig : NSObject
- (BOOL)skipFilterPreferredVideoFormats;
- (BOOL)fallbackOnError;
- (void)setFallbackOnError:(BOOL)value;
- (BOOL)useReloadContextForFallback;
- (void)setUseReloadContextForFallback:(BOOL)value;
- (int)maxFallbackAttempts;
@end


FOUNDATION_EXPORT void YTLInstallConfigurationEarlyHooks(void);
FOUNDATION_EXPORT void YTLInstallConfigurationHooks(void);
