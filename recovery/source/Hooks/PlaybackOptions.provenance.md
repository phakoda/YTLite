# PlaybackOptions recovery

All 27 assigned registrations are recovered: 25 replacements and two added accessor methods, all in registrar `0x53fac`. `YTLInstallPlaybackOptionsHooks()` installs the named Logos group and adds the original `redesignedController` property. There is no constructor. The parent should call this installer at the main registrar phase and remove the matching backup hooks.

Source evidence is the supplied arm package's canonical ARM64 image, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The adjacent manifest pins complete function boundaries/hashes, all registrations, 76 decoded constants, 52 feature/association wrappers, 44 recorded branches, 15 independently decoded branch tables, and the property registrar instruction range. `verify_playback_options.py` checks 10,155 assembly words against original image bytes before compiling or executing the recovered source.

| Class | Selector | Implementation | Operation |
| --- | --- | --- | --- |
| `YTWatchNextResultsViewController` | `setVisibleSections:` | `0x00070368` | replace |
| `YTFullscreenEngagementOverlayView` | `setExpanded:` | `0x0007884c` | replace |
| `YTPlaylistVideoCell` | `setCanReorder:` | `0x00086010` | replace |
| `YTVideoFreeZoomOverlayController` | `freeZoomViewDidZoom:isTwoFingerZoom:` | `0x00086048` | replace |
| `YTWatchCinematicContainerController` | `isCinematicLightingAvailable` | `0x00088394` | replace |
| `YTCreatorEndscreenView` | `setHidden:` | `0x0008901c` | replace |
| `YTFullscreenActionsView` | `enabled` | `0x0008d64c` | replace |
| `YTFullscreenActionsView` | `setEnabled:` | `0x0008d800` | replace |
| `YTFullscreenActionsView` | `layoutSubviews` | `0x0008da00` | replace |
| `YTFullscreenEngagementOverlayController` | `setRelatedVideosVisible:` | `0x0008e340` | replace |
| `YTAnnotationsViewController` | `loadFeaturedChannelWatermark` | `0x0008f754` | replace |
| `YTWatchFloatingMiniplayerViewController` | `updateMiniBarPlayerStateFromRenderer` | `0x0008fab8` | replace |
| `YTPlaybackConfig` | `setStartPlayback:` | `0x0008fe74` | replace |
| `YTPlayabilityResolutionUserActionUIController` | `showConfirmAlert` | `0x00090048` | replace |
| `YTVideoQualitySwitchOriginalController` | `redesignedController` | `0x0004b4c8` | add |
| `YTVideoQualitySwitchOriginalController` | `setRedesignedController:` | `0x0004b4d4` | add |
| `YTVideoQualitySwitchOriginalController` | `setUserSelectableFormats:` | `0x0009026c` | replace |
| `YTVideoQualitySwitchOriginalController` | `dealloc` | `0x00090850` | replace |
| `YTSegmentableInlinePlayerBarView` | `didMoveToWindow` | `0x000908ac` | replace |
| `YTBrandGradientImageProcessor` | `willDrawInContext:drawParameters:` | `0x00095f00` | replace |
| `YTVerticalPanGestureRecognier` | `gestureRecognizerShouldBegin:` | `0x000aa890` | replace |
| `YTExitFullscreenController` | `gestureRecognizerShouldBegin:` | `0x000ab118` | replace |
| `YTMenuItemVisibilityHandler` | `shouldShowServiceItemRenderer:` | `0x000ab9bc` | replace |
| `YTDefaultSheetController` | `addAction:` | `0x000abc38` | replace |
| `YTYouThereController` | `shouldShowYouTherePrompt` | `0x000b07cc` | replace |
| `YTSpeedmasterController` | `speedmasterDidLongPressWithRecognizer:` | `0x000ba188` | replace |
| `YTHUDMessageView` | `initWithMessage:dismissHandler:` | `0x000ba7d4` | replace |

## Decisions established from original instructions

- Watch-next sections forward the complete incoming 64-bit slot unless `noRelatedWatchNexts` is enabled, when the original receives 1. The host enum name is not established. Playlist reordering always forwards YES.
- Engagement expansion forwards first. Only a `YTMainAppVideoPlayerOverlayView` superview supplies controls. YTL buttons change alpha when `(downloadManager && ytlButtonIndex != 0) || ytlMuteButton || ytlLockButton`; speed controls use their separate gate. Expansion yields zero alpha; collapse converts `isOverlayVisible` to alpha. The tables at `0x117c238` through `0x117c2e8` establish short-circuit order and both expansion branches.
- Zoom tests for the `_snappedZoomFactor` ivar before reading `noFreeZoom`. For factors above 1, it forwards 1 when current zoom is already beyond the snapped value; otherwise, if multiplying would cross the snapped value, it forwards snapped/current. Factors at or below 1 and NaN pass through. Original `double` and two-finger BOOL arguments retain their ABI. The additional unresolved decompiler jump at `0x8650c` resolves to `0x86510` or `0x86550`.
- Cinematic lighting, end cards, fullscreen actions, related videos, watermarks, minibar updates, initial playback, confirmation alerts, and chapter snapping preserve their separate gates and forwarding order. Fullscreen actions' `enabled` getter does not call its original. End cards OR the incoming hidden flag with the gate. Chapter snapping forwards `didMoveToWindow` first. Content warnings invoke `confirmAlertDidPressConfirm` instead of the original alert only when enabled.
- Fullscreen action layout forwards first, checks `_elementView`, requires at least two subviews, selects index 1, and requires exactly two root subnodes. The last child's last child must be an `ASNetworkImageNode` with an absolute URL containing `i.ytimg.com/vi/`. It sets that view's alpha to zero and has no restoration path.
- The quality controller is lazily allocated with nil registry scope and parent responder, retained by its new associated property, and receives the owner's `_video` through unguarded KVC. `addRestrictedFormats:` runs only if supported; its result is forwarded. Without that selector the original input is forwarded. The dealloc hook clears the property before forwarding. The original registrar at `0x64b38` adds `T@"YTVideoQualitySwitchRedesignedController",&,N`; accessors at `0x4b4c8`/`0x4b4d4` use retain-nonatomic policy. The reconstructed private association key is a static address rather than the original getter address; this preserves private storage and ownership behavior.
- Progress drawing obtains both archived colors before inspecting the clipped drawing rectangle. Rectangles higher than 30 and within 1 point of square use original drawing. Mode 1 fills the intersection with the main color. Mode 2 with a non-nil gradient color saves state, clips to the intersection, and draws a two-color horizontal gradient over the full requested rectangle, using locations 0 and 1 and options 0. Other modes or a missing second color forward. The implementation retains the original unguarded main-color assumptions. The square jump at `0x96504` resolves to original `0x96594` only when true; gradient coordinates, clip restoration, and the floating-point locations at `0xc4c340` are checked.
- The vertical recognizer reads its delegate again after the class test; the exit recognizer reuses its first resolved view. Both pan recognizers apply only to `YTMainAppVideoPlayerOverlayView`. They read the gesture location in that view, bounds width, and the instance defaults `floatForKey:` value for `gestWideness`. Left mode is consulted at `x <= edge`, right mode at `x >= width-edge`; either nonzero mode rejects. Both gates are evaluated when edge regions overlap. ARM64 HI/LT unordered behavior means NaN coordinates activate neither side. Other hosts and unblocked coordinates forward the original return value.
- Service renderer filtering rejects icon type 251 only with `removePlayNext`. Sheet actions evaluate all 22 icon-to-preference entries in original order. Their image descriptions go through the canonical recovered `innertubeName`; an existing button supplies the fallback current image only if the first extracted name is empty. Only a true mapped preference skips original insertion.
- You-there prompts always return NO. Speedmaster mode 0 does nothing, mode 1 forwards, and other modes read `_delegate` by unguarded KVC and dispatch to canonical `YTPSpeedMaster` only for the expected overlay controller class. The mode preference is read twice on nonzero paths, as in the image. Hidden HUD initialization returns nil and consumes the allocated receiver; ordinary initialization forwards both objects unchanged.

## Verification and integration

Run `python3 recovery/tools/verify_playback_options.py` from the repository. The current report is `.recovery-work/playback-options-tests/report.json`: all 27 hook signatures compile with the real iOS SDK for arm64/iOS 14 under warnings-as-errors. The actual Logos bodies run on macOS under UBSan with 1,383 assertions, including all 22 sheet mappings and fallback paths, all expansion gate combinations, gesture edge and overlap cases, zoom limits and nonfinite values, 64-bit forwarding, original ordering, KVC failure behavior, quality-controller retain/dealloc behavior, added property metadata, and actual Foundation archival plus CoreGraphics solid/gradient pixels and clipping. Tests compile the canonical `FeedNodesHelpers.m`, not a replacement parser. No packaged dylib is executed and no network requests occur.

The fixture supplies host UIKit/YouTube instances and intercepts the `YTPSpeedMaster` boundary. It cannot prove device-specific YouTube UI appearance. Concrete types for the opaque HUD objects and the watch-next enum remain unspecified; their used ABI and forwarding are verified. No hook registration or branch remains omitted.

Production needs the canonical `FeedNodesHelpers.m` (`innertubeName`), `YTPSpeedMaster.m`, `YTLFeaturePolicy`, `YTLUserDefaults`, UIKit and CoreGraphics. No new shared global is defined. The parent-owned `ytpBool`/`ytpInt` local preference policy remains an integration difference from the packaged account-gated feature helpers.
