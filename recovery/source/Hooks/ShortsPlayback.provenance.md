# Shorts playback recovery

`ShortsPlayback.x` reconstructs all 12 registrations for the three assigned host classes. The manifest pins complete function ranges to the supplied arm-package image with SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The source was recovered from the expanded per-function exports, decoded constant writes and original ARM64 instructions. Decompiled argument types were not treated as authoritative.

| Host class | Selector | Implementation | Operation |
| --- | --- | --- | --- |
| YTReelPlayerViewController | playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback: | 0x9fcb4 | Replace |
| YTReelPlayerViewController | maybeLoopPlayback | 0x9ffd0 | Replace |
| YTReelPlayerViewController | playbackControllerDidActivateVideo:withPlayerResponse: | 0xa0670 | Replace |
| YTReelPlayerViewController | autoQuality | 0xa1240 | Add |
| YTReelPlayerViewController | shouldEnablePlayerBar | 0xa2e8c | Replace |
| YTReelPlayerViewController | shouldAlwaysEnablePlayerBar | 0xa2ff0 | Replace |
| YTReelPlayerViewController | shouldEnablePlayerBarOnlyOnPause | 0xa3154 | Replace |
| YTReelPlayerViewControllerSub | shouldEnablePlayerBar | 0xb00b0 | Replace |
| YTReelPlayerViewControllerSub | shouldAlwaysEnablePlayerBar | 0xb0224 | Replace |
| YTReelPlayerViewControllerSub | shouldEnablePlayerBarOnlyOnPause | 0xb0384 | Replace |
| YTShortsPlayerViewController | shouldAlwaysEnablePlayerBar | 0xb0500 | Replace |
| YTShortsPlayerViewController | shouldEnablePlayerBarOnlyOnPause | 0xb0654 | Replace |

All registrations originate at `0x53fac`. Original-IMP slots are recorded in the manifest. No anonymous callbacks, blocks, dispatch calls or delays occur in these 12 bodies. Activation calls `autoQuality` synchronously.

## Playback and activation

The finish hook checks whether `maybeLoopPlayback` exists. When available, it forwards to the original first and then pauses for `shortsPlaybackIndex == 2`. The preference read is after the original, so an original implementation that changes the preference affects the pause decision. When the selector is unavailable, mode 2 suppresses the original; other modes forward.

The loop hook advances only for mode 1 and an available `reelContentViewRequestsAdvanceToNextVideo:` selector. An existing `_isEngagementPanelVisible` ivar with a true KVC value forces the original loop behavior. A missing ivar or false value allows advance. The packaged advance at `0xa0654` is explicitly `performSelector:`, without a sender argument. The source preserves that call. Tests intercept `performSelector:` itself rather than invoking a host method with an unspecified argument.

Activation forwards the original before any gates. The original call at `0xa0fc8` loads slot `0x1226608`; the prologue and initialization instructions preserve incoming x1, x2 and x3. With `restrictShortsPortion`, the hook reads `parentResponder`, checks its class against dynamically cached `YTReelWatchRootViewController`, then reads the parent again. If that object's class has `_isInfinitePlaybackMode`, KVC sets it to `@NO`. It calls `autoQuality` when either quality index is nonzero, short-circuiting the cellular preference read when the WiFi preference is nonzero. This trigger uses both settings even if the current network selects the other setting.

The packaged finish hook saves and forwards all 64 bits of x2. The activation hook preserves all of x2 and x3. No authoritative host declarations for those arguments were found in the backup or packaged metadata. `YTLShortsForwardedArgument` therefore preserves raw slots as `uintptr_t`, with no narrowing or added ARC object ownership. This establishes machine-call compatibility, not the lost source-level Objective-C argument encodings. None of these replacements adds a new method encoding for the forwarded selectors.

## Quality selection

The method exits for a nil quality controller, a controller class without `_sortedSelectableFormats`, or an empty formats array. It obtains the preference index from `shortsWiFiQualityIndex` or `shortsCellQualityIndex` using canonical `YTLHelper.isConnectedToWiFi`.

The highest label starts as `144p`, with resolution 0. It changes only when a format's signed 32-bit `singleDimensionResolution` is strictly greater and its label does not contain case-sensitive `Premium`. Equal resolutions keep the first label. The selectable preference list is exactly:

`Default`, highest label, `1080p60`, `1080p`, `720p60`, `720p`, `480p`, `360p`, `240p`, `144p`.

The package directly indexes this array. Invalid indexes raise an array range exception; no bounds clamp was added. When the chosen label equals the highest label, it proceeds directly. Otherwise an exact label match wins. If absent, it searches non-Premium formats for the smallest absolute difference between the numeric prefixes of labels split by `p`. Candidate labels must split into exactly two parts. Resolution fields do not participate in this fallback. Equal distances keep the first candidate. With no candidate, the originally requested label remains.

This also preserves the packaged `Default` behavior. Its integer prefix parses as 0, so a direct mode-0 call ordinarily selects the lowest parseable label. The subtraction and conditional negate at `0xa2b38` and `0xa2b3c` wrap at 64 bits. The comparison at `0xa2b44` is signed and strict. `ShortsPlaybackDistance` reproduces those instructions using unsigned arithmetic and a byte copy, avoiding C signed-overflow undefined behavior.

The method dynamically resolves `MLQuickMenuVideoQualitySettingFormatConstraint`, performs `alloc` plus `init`, and checks for the longer initializer. If available, it reads the quality controller again, invokes that initializer on the already initialized instance with setting 3 and reason 2, and passes its returned object and the original formats array to `videoQualitySwitchController:didSelectFormatConstraint:forSelectableVideoFormats:`. There is no alternate constraint or selection when that initializer is unavailable. The argument loads and call are pinned at `0xa2dc0` through `0xa2e08`.

The signed `int` resolution and initializer setting, and `NSInteger` selection reason, agree with `vendor/YouTubeHeader/MLFormat.h` and `MLQuickMenuVideoQualitySettingFormatConstraint.h`. These headers corroborate the observed w-register and x-register use.

## Progress bars

All eight progress flags ignore their originals. `shouldEnablePlayerBar` and `shouldAlwaysEnablePlayerBar` return `ytpBool(@"shortsProgress")`; `shouldEnablePlayerBarOnlyOnPause` returns its negation. The subclass registrations are distinct, even when they have matching results.

## Verification and integration

Run from the repository root:

```sh
python3 recovery/tools/verify_shorts_playback.py
```

The verifier checks all 12 registration records, complete original function hashes, four instruction excerpts, four gate wrappers and 34 decoded constants. It processes the actual `.x` file with the pinned Logos tool, compiles it for iOS ARM64 using real UIKit, and checks all 12 emitted callback signatures. It then executes the generated callbacks against synthetic host objects and real Foundation operations on macOS under UBSan. The fixture currently passes 403 assertions covering mode and selector combinations, missing/inherited ivars, full-width original arguments, post-original preference reads, synchronous quality activation, every quality index, nearest-distance ties, malformed/Premium labels, integer edge cases, absent initializers and all eight bar flags. It also verifies that the added method appears only after explicit installation.

The report and commands are written to `.recovery-work/shorts-playback-tests/`. The fixture does not execute the supplied dylib or make network requests. Installed YouTube behavior and device playback have not been exercised.

Add `ShortsPlayback.x` to the production source list and call `YTLInstallShortsPlaybackHooks()` once from the shared installer. Remove overlapping backup registrations during integration. The module has no constructor and does not own `addEndTime`, `autoSkipShortsLegacy` or `canRememberLoopMode`. It depends on canonical `YTLHelper` and `YTLFeaturePolicy`. The shared policy's local preference behavior differs from the packaged bootstrap licensing policy; that integration choice remains parent-owned. Obfuscation scaffolding and injected supervisor-call instrumentation are not reproduced.
