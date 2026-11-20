#import "YTLHookEntrypoints.h"
#import "YTLSideloadEntrypoint.h"

// The packaged SponsorBlock registrar (0x1efd4) runs during image loading.
// Discord (0x8540) and primary playback (0x53fac) are registered through the
// historical block queue. Keep their relative order on the main queue under
// this fork's existing preference-only policy. StartupLifecycle owns the
// recovered welcome scheduling and primary defaults cleanup.
__attribute__((constructor)) static void YTLInitializeRecoveredTweak(void) {
    YTLInstallCompatibilityVersionHooks();
    YTLInstallSettingsBridgeHooks();
    BOOL sideloadCompatibility = YTLPrepareSideloadCompatibility();
    YTLInstallSponsorPlaybackHooks();
    YTLInstallPlayerBarsSponsorHooks();
    YTLScheduleWelcome();
    YTLInstallRemoteControlsEarlyHooks();
    YTLInstallGeneralInterfaceEarlyHooks();
    YTLInstallNavigationChromeEarlyHooks();
    YTLInstallStartupLifecycleEarlyHooks();
    YTLInstallConfigurationEarlyHooks();
    YTLInstallNativeShareHooks();
    YTLInstallNavigationChromeRendererHook();
    dispatch_async(dispatch_get_main_queue(), ^{
        YTLInstallDiscordLifecycleHooks();
        if (sideloadCompatibility) YTLInstallSideloadMetadataCompatibilityHooks();
        YTLInstallStartupLifecycleMainHooks();
        YTLInstallGeneralInterfaceHooks();
        YTLInstallMediaPolicyHooks();
        YTLInstallFeedFilteringHooks();
        YTLInstallThemeStylesHooks();
        YTLInstallMediaServicesHooks();
        YTLInstallPlaybackOptionsHooks();
        YTLInstallPlayerControlsHooks();
        YTLInstallPlayerOverlayHooks();
        YTLInstallShortsInterfaceHooks();
        YTLInstallConfigurationHooks();
        YTLInstallPlayerBarsAppearanceHooks();
        YTLInstallNavigationChromeHooks();
        YTLInstallFeedNodesHooks();
        YTLInstallShortsPlaybackHooks();
        YTLInstallPlayerLifecycleHooks();
        YTLInstallContentLayoutHooks();
        YTLInstallRemoteControlsMainHooks();
        YTLInstallImageGesturesHooks();
        YTLFinalizePrimaryStartup();
    });
}
