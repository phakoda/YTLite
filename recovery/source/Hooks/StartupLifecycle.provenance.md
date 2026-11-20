# StartupLifecycle recovery

The six assigned hooks, ordinary welcome scheduling, and the primary initializer's local defaults tail are reconstructed in `StartupLifecycle.x`. Original registration records remain unchanged in the manifest. Constructors are not emitted; the parent owns installation order and removal of superseded root code.

| Registrar | Target / selector | Replacement |
| --- | --- | --- |
| `0x4cf00` | YTAppDelegate `application:didFinishLaunchingWithOptions:` | `0x51d7c` |
| `0x4cf00` | YTStartupAnimationViewController `viewDidLoad` | `0x52438` |
| `0x4cf00` | YTStartupAnimationViewController `playLottieAnimation` | `0x526dc` |
| `0x4cf00` | YTStartupAnimationViewController `dealloc` | `0x53748` |
| `0x53fac` | QTMIcon class `imageWithName:color:` | `0x65fbc` |
| `0x53fac` | YTAppDelegate `appDidBecomeActive` | `0xbb9ec` |

Call `YTLInstallStartupLifecycleEarlyHooks()` at the early registration stage and `YTLInstallStartupLifecycleMainHooks()` at the primary stage. Call `YTLScheduleWelcome()` at original constructor `0x44488`'s position, between Sponsor and early hooks. Call `YTLFinalizePrimaryStartup()` after all primary hook installers, corresponding to the ordinary tail at `0x65d08`–`0x65fbc` inside `0x53fac`.

## Launch and startup playback

Launch reads the instance defaults `autoClearCache`. When enabled, it queues the global callback `0xbcc68` on the default global queue before forwarding the original launch call and preserving its BOOL result. The callback looks up the first caches directory, asks the default file manager to remove it, then separately asks the default manager to remove `NSTemporaryDirectory()`. Both error pointers are null and results are ignored. Paths are looked up when the asynchronous callback runs.

`viewDidLoad` forwards first, reads instance defaults `oledTheme`, and only when enabled queries `self.view._mapkit_isDarkModeEnabled`. A true result causes another view lookup and a black background. No theme substitution runs otherwise.

`playLottieAnimation` reads the full-width `startupAnimation` integer. Only value 3 selects a local video. It searches the first documents directory for `startup_animation.mp4`, then `startup_animation.mov`, taking the first existing path. Other modes or no path forward the original exactly once.

The custom path creates a covering view in the startup view's bounds, uses canonical `YTPMedia.adaptiveBackgroundColor`, sets autoresizing mask 18, and adds it as a subview. The shared audio session receives playback category with option 2 (duck others), followed by active YES; errors are ignored. An `AVPlayer` plays the local URL. Its layer is added to the startup view's layer, with the startup bounds, aspect-fill gravity, and initial opacity zero. Playback starts before a CATransaction changes opacity to one with duration 0.2 seconds.

A shared finish block (`0xbecf0`) deactivates audio with option 1, starts a 0.2-second fade to zero, and schedules completion `0xbee20`. Completion removes the player layer and calls `forceDismissStartupAnimationAnimated:YES`. The covering view is not explicitly removed by this code.

Two observer tokens are added in order to a mutable array: player-item-ended for the current item and app-entered-background for nil object, both on the main operation queue. The array is associated with the controller under selector `playLottieAnimation`, using retain-nonatomic policy. A full-cover custom button with the same autoresizing mask receives a UIAction for touch-up-inside.

End notification (`0xbee78`) removes each observer and calls finish. Background notification (`0xbf1b0`) and button action (`0xbf4b8`) remove each observer, pause the player, then call finish. Deallocation removes observers from the associated array before forwarding original deallocation. Tokens are neither cleared from the array nor disassociated early; repeated cleanup remains possible.

Capture ownership follows original block descriptors and copy/dispose helpers. Finish and transaction-completion blocks strongly capture the layer and hold an unsafe-unretained controller pointer. The package's copy helper `0x150e8` retains only offset 32; offset 40 contains the raw controller. End notification captures the observer array strongly and finish as a copied block. Background and button callbacks additionally capture the player strongly. No weak-controller or strong-controller substitute is introduced. The runtime fixture proves the controller can deallocate while the captured callbacks remain alive; it does not invoke the resulting raw pointer after deallocation.

The original calls `UIAction.actionWithHandler:` and `UIButton.addAction:forControlEvents:` without an availability guard. They require iOS 14; the iOS 13 compile emits the corresponding availability warnings. This reconstruction preserves the original behavior instead of inventing an earlier-iOS fallback.

## Icons and clipboard action

The primary QTMIcon hook checks for exact name `youtube_outline/moon_z_24pt`, forwards the original class method, and assigns the requested image name to the returned image's accessibility identifier only for non-moon names. Nil names are forwarded and clear an existing identifier; nil images remain nil. This hook chains with CompatibilityVersion's separate earlier QTMIcon hook; the parent owns registration order.

App activation forwards first, then reads instance defaults `autoCheckCb`. Enabled calls read the current clipboard string and require nonzero length. The first case-sensitive substring match from `youtube.com`, `youtu.be`, `youtube-nocookie.com` creates a toast using localized `LinkDetected` and `Open`, duration 10 seconds, and a captured action. These are substring checks, not URL host validation, and this quirk is retained.

The toast action (`0xcf4fc`) strongly captures the original clipboard string. It removes an initial lowercase HTTP or HTTPS scheme with regex `^https?://`, prefixes `vnd.youtube://`, creates an NSURL, and opens it with an empty options dictionary and a global Boolean completion. It still passes nil if URL creation fails. Completion `0xcf860` clears the current clipboard only on success; it does not compare the current clipboard with the captured string. Original table `0x1183d40` maps false to `0xcf8e8` (return) and true to `0xcf8b0` (clear). No URL is opened by verification.

## Ordinary constructor side effects

`YTLScheduleWelcome()` reconstructs constructor `0x44488`: schedule callback `0x444d4` after two seconds on the main queue. The callback reads `hasShownWelcome` at execution time. When false, it creates canonical `WelcomeVC`, sets form-sheet presentation and modal-in-presentation YES, and presents from `ToastView.toastWindow.rootViewController` animated with nil completion. It does not set the welcome preference itself.

`YTLFinalizePrimaryStartup()` reuses one defaults instance. If `objectForKey:sbPrivateUserID` is nil, it calls the canonical private-ID helper, derives the public ID with `sbPublicUserID:`, writes both results, and synchronizes. Any existing object, including an empty string, suppresses both writes and synchronization; a missing public ID alone is not repaired. Nil helper results are forwarded to the setters without new guards.

It then independently compares `customTrack` and `customCaption` against fresh `YTPDB.supportedLanguages.count` results. ARM64 `LO` establishes unsigned comparison. Out-of-range values, including negative signed integers, are replaced by a fresh `YTPDB.indexOfPreferredLanguage` result for each invalid preference. There is no second bounds check, clamping, or final synchronize. Original unresolved table `0x117aa00` maps a false unsigned comparison to `0x65ea4` (write preferred track), true to `0x65ec8` (continue). The caption table is likewise included in the manifest.

Two constructor paths remain excluded by the assigned ordinary-local scope. The two-second callback from `0x37ed4` (`0x37f20`) enters device-derived activation-token comparison and blocking bootstrap UI after loaded-tweak checks. The five-second callback `0x539fc` from `0x4cf00` is an activation-status reminder using `dvnCheck`/`dvnLocked`. Neither is replaced with an invented local branch. Historical `ptnRegisterBlock` routing remains parent-owned.

## Verification

Run:

```sh
python3 recovery/tools/verify_startup_lifecycle.py
```

The verifier compares all six source registrations, 23 original instruction intervals, 62 decoded strings, 50 branch records, 33 independently calculated branch tables, block descriptors/invokes/copy/dispose pointers, and the original double animation constant. Pinned Logos generates the actual source; iOS LLVM verifies hook signatures, BOOL launch result, object image result, float layer opacity, and nine generated blocks. The fixture runs that same generated code under UndefinedBehaviorSanitizer.

Its 387 checks cover the six hooks, all three playback finish routes, observer and capture lifetime, file preference modes and order, asynchronous cache work, OLED predicates, icon forwarding, clipboard capture and completion, welcome scheduling, and defaults ID/language cleanup including integer extrema and separately changing language counts. Every file removal, dispatch, audio, video, notification, clipboard, URL and presentation boundary is intercepted. The supplied binary is inspected, never executed. Protection syscalls, decoded-string initialization and obfuscation bookkeeping are omitted. All assigned ordinary behavior is recovered; account/bootstrap exclusions and live-device validation remain explicit limits.
