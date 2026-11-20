# Shorts interface recovery

`ShortsInterface.x` reconstructs all 27 registrations for the assigned 11 classes, plus the shared button helper and both referenced block bodies. The original arm-package image SHA-256 is `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The manifest pins every complete original function, 66 decoded constants, 49 gate wrappers and 65 recovered branch records. Three branches unresolved in the pseudocode were resolved directly from the original encoded jump tables.

| Class | Selector | Implementation | Operation |
| --- | --- | --- | --- |
| YTReelWatchPlaybackOverlayViewSub | -layoutSubviews | 0x0008210c | replace |
| YTReelWatchPlaybackOverlayViewSub | -didTapYtlButton: | 0x00082fb0 | add |
| YTReelWatchPlaybackOverlayView | -layoutSubviews | 0x00083340 | replace |
| YTReelWatchPlaybackOverlayView | -setActionBarElementRenderer: | 0x0008429c | replace |
| YTReelWatchPlaybackOverlayView | -setReelLikeButton: | 0x00084ae4 | replace |
| YTReelWatchPlaybackOverlayView | -didTapYtlButton: | 0x00084d50 | add |
| YTInlineMutedPlaybackShortsPlayerOverlayView | -layoutSubviews | 0x000850e4 | replace |
| YTInlineMutedPlaybackShortsPlayerOverlayView | -didTapYtlButton: | 0x00085cd0 | add |
| YTReelContentModel | +makeContentModelForEntry: | 0x00098710 | replace |
| YTReelDataSource | -makeContentModelForEntry: | 0x00099070 | replace |
| YTReelInfinitePlaybackDataSource | -makeContentModelForEntry: | 0x000999d8 | replace |
| YTReelInfinitePlaybackDataSource | -reels | 0x0009a344 | replace |
| YTShortsStartupCoordinator | -evaluateResumeToShorts | 0x000b0b5c | replace |
| YTReelHeaderView | -setTitleLabelVisible:animated: | 0x000b0b64 | replace |
| YTReelHeaderView | -addView:toStackView:withSize: | 0x000b0d2c | replace |
| YTReelWatchHeaderView | -setChannelBarElementRenderer: | 0x000b1574 | replace |
| YTReelWatchHeaderView | -setHeaderRenderer: | 0x000b17e4 | replace |
| YTReelWatchHeaderView | -setShortsVideoTitleElementRenderer: | 0x000b1a40 | replace |
| YTReelWatchHeaderView | -setSoundMetadataElementRenderer: | 0x000b1c98 | replace |
| YTReelWatchHeaderView | -setActionElement: | 0x000b1edc | replace |
| YTReelWatchHeaderView | -setBadgeRenderer: | 0x000b2140 | replace |
| YTReelWatchHeaderView | -setMultiFormatLinkElementRenderer: | 0x000b2364 | replace |
| YTReelContentView | -setPlaybackView: | 0x000b3ef0 | replace |
| YTReelContentView | -reelSpeedmaster: | 0x000b43a8 | add |
| YTReelContentView | -dealloc | 0x000b4f94 | replace |
| YTReelContentView | -turnShortsOnlyModeOff: | 0x000b5410 | add |
| YTReelWatchRootViewController | -viewDidAppear: | 0x000b9f60 | replace |

All 27 registrations originate at `0x53fac`. The source contains 22 replacements and five added methods. It uses the named `YTLShortsInterface` group, exposes `YTLInstallShortsInterfaceHooks()`, and has no constructor.

## Download controls

The two reel overlay layouts forward the original before reading `downloadManager`. A descendant tagged 999 suppresses further insertion. They require `_playerOverlayView`, its `_elementView`, and the element's `_rootNode` ivars, checking each object's actual class before KVC. Only the first root yoga child is inspected. Within that child's yoga children, the first node whose controller key equals `reel_player_overlay.reel_action_bar_key` causes one button to be added relative to `_playerOverlayView`.

`setActionBarElementRenderer:` forwards first and separately checks `_actionBarComponentView` and `_actionBarView`. Every nonnil reference can add a button; this setter has no tag deduplication. `setReelLikeButton:` also forwards first. With downloads enabled, it reads `isHidden` even for a nil argument, then adds only for a nonnil visible button. Table `0x117d3d0`, XOR-offset storage `0x117d3e0`, selects disabled exit `0x84d1c` or enabled test `0x84cc8`. Table `0x117d3e8`, offset `0x117d3f8`, selects insertion `0x84d0c` only for the false hidden/nil result. These setter replacements do not reproduce the backup's `hideShortsLike` gate, which is absent from this packaged body.

The shared helper at `0xc9f04` creates a button with canonical `YTPMedia.ytPlusShorts`, localized `ShortsYTLButton`, no visible text, size 64 by 60, action `didTapYtlButton:` and tag 999. Both variants have black shadow color, opacity 0.5, zero offset, radius 4 and white custom touch feedback. The layout variant resizes its image to 24 and adds only trailing-to-trailing and bottom-to-top constraints. The setter variant resizes to 32, aligns center X and bottom to the reference's top, and constrains both width and height to the reference's width. The original table at `0x11835b8` with offset `0x11835c8` selects false branch `0xca37c` and true branch `0xca470`. The false branch deliberately has no extra width/height constraints.

The inline overlay first requires downloads and a `YTPlayerViewController` parent. It obtains `ytl_icon` from `YTAssetLoader` initialized with the canonical bundle, resizes to 20, creates and styles the button, and only then checks for tag 999. Thus repeated layouts still create an unused button. A new button gets leading/top alignment and width/height constants 32.

Both reel download actions check the parent's class, read `parentResponder` again and pass its `player` to canonical `DownloadMenuHelper.showDownloadSheetShorts:withSender:`. The inline action passes the parent itself. None of the three added actions checks the download preference. Fixtures intercept the download boundary; they perform no downloads or service requests.

## Model filtering

The class method on `YTReelContentModel` and both data-source methods call their original first, then filter that returned object. The fallback predicate at `0xca6ac` applies the same decisions in the same order:

- When `videoType` exists, `noAds` removes type 3, then `removeShortsPosts` removes type 10.
- When `presentation` exists, `noAds` removes presentation type 4, then `removeShortsPosts` removes type 5, then `removeShortsLive` removes type 3 or 7. The type-7 test reads `presentation` again.
- Availability of `livePreviewVideo` permits a `removeShortsLive` check followed by **`isLivePreviewVideo`**. Availability and invocation selectors differ in the original.
- Availability of `liveVideo` similarly permits the **`isLiveVideo`** check.

Gates are read at each original position and short-circuit in that order. No selector support means no corresponding preference read. Integer type comparisons preserve the observed 32-bit return width.

`reels` checks support for `makeContentModelForEntry:` before forwarding the original. If supported, it returns the original array unchanged. Otherwise it makes a mutable copy, obtains matching indexes with the global predicate, removes those indexes when nonempty, and returns an immutable copy. The original collection is not mutated. The block literal at `0x1061fc0` points to `0xca6ac`; the unused index and stop parameters retain the Foundation predicate ABI.

`evaluateResumeToShorts` returns nil unconditionally. Its complete packaged body at `0xb0b5c` is a zero return, with no preference or original call. This differs from the backup's `resumeShorts` conditional.

## Header visibility

`setTitleLabelVisible:animated:` forwards the requested visibility masked by the inverse of `hideShortsLogo`; animation is unchanged. The original w-register mask and the backup BOOL declarations agree. `addView:toStackView:withSize:` only filters instances of dynamically resolved `YTQTMButton`. It evaluates all three gates into a dictionary, mapping icon 1045 to `hideShortsSearch`, 1046 to `hideShortsCamera`, and 1047 to `hideShortsMore`. Other icons and non-button views forward unchanged. The prologue at `0xb0d50` and `0xb0d54` saves d1 and d0, proving that the CGSize is two doubles despite the decompiler's misplaced integer arguments. Both scalars and object arguments are preserved.

The seven watch-header setters suppress their original only for the corresponding gate. Channel bar uses `hideShortsChannelName`; header and title use `hideShortsDescription`; sound uses `hideShortsAudioTrack`; action uses `hideShortsPromoCards`; badge uses `hideShortsThanks`; multi-format link uses `hideShortsSource`. Suppression skips the original rather than calling it with nil.

## Gestures and navigation

`setPlaybackView:` forwards first, then assigns overlay alpha from shared `isOverlayShown`. With `shortsOnlyMode`, it appends a two-touch, 0.5-second gesture targeting `turnShortsOnlyModeOff:`. Independently, it always creates a `DVNLongPressDelegate`, assigns self as its weak view and the full `shortsSpeedIndex` as its mode, and appends a one-touch gesture targeting `reelSpeedmaster:`. The speed gesture duration is the original double 0.3 at `0xc4c2e0`. The delegate is retained using associated-object key `@selector(reelSpeedmaster:)` and policy 1. Repeated assignments append gestures and replace the retained delegate; no deduplication was added.

`reelSpeedmaster:` reads the gesture delegate and computes the location in self even when the delegate is nil. It requires that delegate's `isTouchInSpeedZone:` to pass. It then obtains `[self.delegate player]`. State began sets rate 2 and shows `Toast.PlaybackSpeed`, value 2, style 1, with the current `compactToast` gate. Ended or cancelled first reads the shared toast's alpha. Exactly zero throws `YouTubePlusException` with reason `Attempt to hide the toast outside of YouTube Plus detected.` Otherwise it resets rate to 1, shows the same toast with value 1, and hides it. The state checks are separate calls and remain in original order. Other states do nothing after obtaining the player. The decompiler's apparent fallthrough into dealloc after the exception is not executable control flow; the throw is nonreturning and `0xb4f94` is a separate original function boundary.

The dealloc replacement restores rate 1, shows the value-1 toast and hides it only when toast alpha is exactly 1. It then forwards deallocation in every case. Partial alpha values do not restore speed here.

`turnShortsOnlyModeOff:` acts only on began. It writes false to canonical `YTLUserDefaults`, queues a main-thread block to show localized `ShortsModeTurnedOff` through `ToastManager` with success true, and obtains the application's window/root controller immediately. It schedules `showPivotBar` on that root with nil object after 1.0 seconds. The block literal `0x1062090` points to `0xccee4`; it has no captures. The fixture records the queue and delay, then invokes the queued source block itself to prove deferred execution.

The root controller's `viewDidAppear:` forwards with the incoming animation flag, then hides its navigation controller parent's pivot bar when `shortsOnlyMode` is enabled.

## Verification and integration

Run `python3 recovery/tools/verify_shorts_interface.py` from the repository root. It checks original hashes, constants, branch records, encoded table targets and block references. Pinned Logos produces the implementation compiled against real iOS UIKit. LLVM inspection checks every one of the 27 method callbacks and both block ABIs. The generated implementation then executes on macOS against synthetic host objects and actual Foundation/QuartzCore operations under UBSan. The fixture currently passes 679 assertions. It exercises each registration, both gate outcomes, original forwarding, full raw argument slots, CGSize precision, button constraints and duplication, all model categories, missing selector availability, gesture states, exceptions, deallocation and deferred actions. Reports and exact commands are written under `.recovery-work/shorts-interface-tests/`.

Add this source to the production list and call `YTLInstallShortsInterfaceHooks()` once. Parent integration owns duplicate root registrations and the single exported `BOOL isOverlayShown = YES` definition. This module declares that global and only reads it. Its original byte is `0x115cd38`; writers are the pinch callbacks at `0xccdbc` and `0xcce50`, and `YTAppViewController.showPivotBar` at `0xb9d64`.

The original source-level types for the forwarded factory entry, action renderer and playback view are unavailable. Their original replacements preserve x2 without inspecting or retaining it. The header therefore uses `uintptr_t` to preserve the full register and avoid adding ARC ownership. This proves the machine argument path, not the missing host method encoding. Host classes remain declarations in production. Device YouTube interaction has not been tested. Canonical `YTLFeaturePolicy` is parent-owned and retains the documented local-policy difference from the packaged bootstrap/licensing behavior. Obfuscation and injected supervisor-call instrumentation are omitted.
