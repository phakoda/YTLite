# Compilable recovery sources only. Never include decompiler .c evidence or the
# independent root Recovered/ copies in this build. Expand after verification.
YTLite_FILES += \
    recovery/source/Models/DVNCell.m \
    recovery/source/Models/DVNSection.m \
    recovery/source/Models/DVNTableModel.m \
    recovery/source/Models/SBSegment.m \
    recovery/source/Models/SBPlayerDecorationData.m \
    recovery/source/Models/RPCMedia.m \
    recovery/source/Support/YTPDB.m \
    recovery/source/Support/Dvbug.m \
    recovery/source/Runtime/InitWorkaround.m \
    recovery/source/Runtime/YTLHookEntrypoints.m \
    recovery/source/Runtime/YTLFeaturePolicy.m \
    recovery/source/Runtime/YTLRootPaths.c \
    recovery/source/Subtitles/SRTParser.m \
    recovery/source/Subtitles/YTPTranslator.m \
    recovery/source/YTLUserDefaults+RecoveredDefaults.m
YTLite_FILES += \
    $(wildcard recovery/source/Downloads/*.m) \
    $(wildcard recovery/source/Settings/*.m) \
    $(wildcard recovery/source/Presentation/*.m) \
    $(wildcard recovery/source/Helpers/*.m) \
    $(wildcard recovery/source/Controls/*.m) \
    recovery/source/Media/DVNMediaPicker.m \
    recovery/source/SleepTimer/YTPSleepTimer.m \
    recovery/source/Whitelist/SbWhitelistVC.m \
    recovery/source/Welcome/WelcomeVC.m \
    recovery/source/Discord/YTPDiscordRPC.m \
    recovery/source/Playback/SBManager.m \
    recovery/source/Playback/SBPlaybackController.m \
    recovery/source/Playback/SBPlayerDecorator.m \
    recovery/source/Subtitles/TranslatorVC.m

YTLite_FILES += \
    recovery/source/Hooks/Configuration.x \
    recovery/source/Hooks/DiscordLifecycle.x \
    recovery/source/Hooks/SponsorPlayback.x \
    recovery/source/Hooks/PlayerBars.x \
    recovery/source/Hooks/PlayerLifecycle.x \
    recovery/source/Hooks/PlayerLifecycleHelpers.m \
    recovery/source/Hooks/ShortsPlayback.x \
    recovery/source/Hooks/SettingsBridge.x
YTLite_FILES += recovery/source/Hooks/PlayerControls.x

# Deliberately excluded: Playback/SRTParser.m (historical independent recovery;
# Subtitles/SRTParser.m is canonical), Recovered/ (superseded model copies),
# Runtime/YTLBootstrapCrypto.m (historical account code), all evidence and tests.

YTLite_FILES += recovery/source/Hooks/ShortsInterface.x recovery/source/Hooks/FeedNodes.x recovery/source/Hooks/FeedNodesHelpers.m

YTLite_FILES += recovery/source/Hooks/PlayerOverlay.x

YTLite_FILES += recovery/source/Hooks/ThemeStyles.x recovery/source/Hooks/NavigationChrome.x recovery/source/Hooks/ImageGestures.x

YTLite_FILES += recovery/source/Runtime/UIViewController+DVNPatreonContext.m

YTLite_FILES += recovery/source/Hooks/FeedFiltering.x recovery/source/Hooks/CompatibilityVersion.x

YTLite_FILES += recovery/source/Hooks/MediaPolicy.x recovery/source/Hooks/MediaServices.x recovery/source/Hooks/PlaybackOptions.x recovery/source/Hooks/NativeShare.x

YTLite_FILES += recovery/source/Hooks/RemoteControls.x

YTLite_FILES += recovery/source/Hooks/GeneralInterface.x

YTLite_FILES += recovery/source/Hooks/StartupLifecycle.x

YTLite_FILES += recovery/source/Hooks/SideloadIdentity.x recovery/source/Hooks/SideloadCompatibility.x recovery/source/Runtime/YTLSideloadEntrypoint.m
