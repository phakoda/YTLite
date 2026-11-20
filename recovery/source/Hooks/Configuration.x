#import "ConfigurationHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../../../Utils/YTLUserDefaults.h"

%group YTLConfigurationEarly
%hook YTColdConfig
- (BOOL)mainAppCoreClientIosEnableStartupAnimation {
    NSInteger animation = [[YTLUserDefaults standardUserDefaults] integerForKey:@"startupAnimation"];
    if (animation == 1 || animation == 4) return YES;
    if (animation == 2) return NO;
    return %orig;
}
%end
%end

%group YTLConfigurationMain
%hook YTColdConfig
- (BOOL)removeNextPaddleForSingletonVideos { return ytpBool(@"hidePrevNext") ? YES : %orig; }
- (BOOL)removePreviousPaddleForSingletonVideos { return ytpBool(@"hidePrevNext") ? YES : %orig; }
- (BOOL)replaceNextPaddleWithFastForwardButtonForSingletonVods { return ytpBool(@"replacePrevNext") ? YES : %orig; }
- (BOOL)replacePreviousPaddleWithRewindButtonForSingletonVods { return ytpBool(@"replacePrevNext") ? YES : %orig; }
- (BOOL)enableHideChipsInTheCommentsHeaderOnScrollIos { return ytpBool(@"stickSortComments") ? NO : %orig; }
- (BOOL)enableChipsInTheCommentsHeaderIos { return ytpBool(@"hideSortComments") ? NO : %orig; }
- (BOOL)shouldUseAppThemeSetting { return YES; }
- (BOOL)isLandscapeEngagementPanelSwipeRightToDismissEnabled { return YES; }
- (BOOL)enableSwipeToRemoveInPlaylistWatchEp { return YES; }
- (BOOL)enableLightThemeAmbientMode { return ytpBool(@"disableAmbientMode") ? NO : %orig; }
- (BOOL)iosAmbientModeExtendWidthInLandscape { return ytpBool(@"disableAmbientMode") ? NO : %orig; }
- (BOOL)iosEnableFullScreenAmbientMode { return ytpBool(@"disableAmbientMode") ? NO : %orig; }
- (BOOL)enableTurnOffCinematicForFrameWithBlackBars { return ytpBool(@"disableAmbientMode") ? YES : %orig; }
- (BOOL)queueClientGlobalConfigEnableFloatingPlaylistMinibar { return ytpBool(@"playlistOldMinibar") ? NO : %orig; }
- (BOOL)disablePlaybackLockScreenController { return ytpBool(@"ytlLockButton") ? NO : %orig; }
- (BOOL)iosEnableVideoPlayerScrubber { return ytpBool(@"shortsProgress"); }
- (BOOL)mobileShortsTabInlined { return ytpBool(@"shortsProgress"); }
- (BOOL)iosUseSystemVolumeControlInFullscreen { return ytpBool(@"stockVolumeHUD"); }
- (BOOL)enableYouthereCommandsOnIos { return NO; }
- (BOOL)cxClientEnableIosLocalNetworkPermissionWifiFixes { return YES; }
- (BOOL)cxClientEnableIosLocalNetworkPermissionUsingSockets { return NO; }
- (BOOL)cxClientEnableIosLocalNetworkPermissionReliabilityFixes { return YES; }
- (BOOL)iosPlayerClientSharedConfigPopulateSwAv1MediaCapabilities { return NO; }
- (BOOL)mediaEngineClientForceSoftwareDecoderOnDecoderRetry { return NO; }
%end

%hook YTIPlayerColdConfig
- (BOOL)iosDisablePlaybackLockScreenController { return ytpBool(@"ytlLockButton") ? NO : %orig; }
%end

%hook YTIMediaQualitySettingsHotConfig
%new
- (BOOL)enableQuickMenuVideoQualitySettings { return NO; }
%new
- (BOOL)omitAdvancedMenuOptionForAirPlay { return NO; }
%end

%hook YTHotConfig
- (BOOL)enablePlayerBarForVerticalVideoWhenControlsHiddenInFullscreen { return ytpBool(@"shortsProgress"); }
- (BOOL)isPromptForLocalNetworkPermissionsEnabled { return NO; }
- (BOOL)clientInfraClientConfigIosEnableFillingEncodedHacksInnertubeContext { return NO; }
- (BOOL)enableShortsVideoQualityPicker { return ytpBool(@"shortsForceQuality") ? NO : %orig; }
%end

%hook YTIHamplayerServerABRConfig
- (BOOL)skipFilterPreferredVideoFormats { return YES; }
- (BOOL)fallbackOnError { return YES; }
- (void)setFallbackOnError:(BOOL)value {
    %orig(YES);
}
- (BOOL)useReloadContextForFallback { return YES; }
- (void)setUseReloadContextForFallback:(BOOL)value {
    %orig(YES);
}
- (int)maxFallbackAttempts { return INT_MAX; }
%end

%end
void YTLInstallConfigurationEarlyHooks(void) { %init(YTLConfigurationEarly); }
void YTLInstallConfigurationHooks(void) { %init(YTLConfigurationMain); }
