# Player overlay recovery

`PlayerOverlay.x` reconstructs all 38 primary-registrar hooks for the six assigned classes: 25 replacements and 13 added methods. It also registers both inline audio-controller properties and implements the captured color-animation block. `YTLInstallPlayerOverlayHooks()` installs the named group without an automatic constructor.

| Class | Registrations | Packaged implementations |
| --- | --- | --- |
| YTInlineMutedPlaybackPlayerOverlayView | 5 | 0x7ea70–0x7f64c |
| YTInlineMutedPlaybackPlayerOverlayViewController | 6 | 0x7f940–0x7ffbc |
| YTInlineMutedPlaybackAudioIconViewController | 6 | 0x4b440–0x4b490, 0x80a50, 0x81bd4 |
| YTInlineMutedPlaybackAudioIconView | 1 | 0x81c68 |
| YTMainAppVideoPlayerOverlayView | 6 | 0x885a8–0x88f60 |
| YTMainAppVideoPlayerOverlayViewController | 14 | 0x891dc–0x8c228 |

The authoritative registrations, selector spellings, original IMP slots, full function-span hashes, constants, and critical instructions are recorded in `PlayerOverlay.manifest.json`. Evidence comes from the ARM64 dylib extracted from the supplied ARM package, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. Normalized pseudocode was used for navigation; original instructions resolve floating-point operations, struct results, metadata, and the end of the finger-pan function. Its real boundary is `0x8d64c`: the decompiler's apparent continuation into `noFullscreenActions` belongs to the next function and is excluded.

## Packaged behavior retained

Inline audio and scrubbing styles become 2 when either `downloadManager` or `sponsorBlock` is enabled. All three style setters preserve the original call and substitute 2 under that same short-circuit gate. Promotion-card suppression omits the original paid-content setters.

The inline player receives a one-finger pan recognizer with itself as delegate. Its begin predicate compares the absolute horizontal and vertical velocity; simultaneous recognition returns true. Feed seeking requires the preference, a player parent of the expected class, and the seek selector. Begin stores the initial media time per controller. Changed events use that stored time, or current media time when begin was missed; the total duration rounds to the nearest integer with ties away from zero. Sensitivity is read as a float and divided by 10. Method zero scales displacement by rounded duration/view width; other methods use the sensitivity-adjusted displacement directly. The original association is retained and is not cleared at gesture end.

The inline audio-controller adds `ytlButton` and `ytlIcon` using retain-nonatomic associations. Registrar calls `0x63e28` and `0x63ed8` install exactly `T@"YTQTMButton",&,N` and `T@"UIView",&,N`. Declaration-only categories prevent fixtures from providing the metadata themselves. Tests verify absence before installation, exact attributes afterward, retention, clearing, and object isolation.

The download button uses YTAssetLoader with the recovered bundle, `ytl_icon` resized to 24, the localized accessibility label, and the canonical button helper. Its background starts at black alpha 0.6. When the host audio overlay exists, eight constraints place it beside that overlay, with a distinct RTL trailing constraint. The corner radius derives from the host frame height. The tapped action forwards the controller's parent responder and sender to DownloadMenuHelper.

`updateColors` forwards first and, when enabled and the host audio overlay exists, queues a duration-0.8, zero-delay animation with options `0x10000` (curve ease-in). Block `0xc9c70`, descriptor `v8@?0`, copies the current background to the recovered container. A nil background adds black shadow, opacity 0.5, offset (0,1), radius 4 to the button. Later nonnil backgrounds do not remove that shadow. The fixture executes the actual captured block after changing the captured view's color.

Main-overlay view hooks preserve background-gradient forwarding, autonav/watermark suppression, and the speed-index replacement of the host pan recognizer by a 0.3-second long press. Speedmaster actions forward the recognizer and overlay delegate to canonical YTPSpeedMaster.

Main-controller hooks preserve promotion and product-overlay filtering, speed labels, double-tap restrictions, timestamp copying after original pause, and loop-mode persistence after original forwarding when external `canRememberLoopMode` is true. Timestamp conversion uses FCVTZS at `0x8aa64`, which truncates toward zero. Added gestures are a two-finger tap, a one-finger brightness/volume pan delegated to the controller, and a one-finger horizontal pan delegated to a retained canonical DVNHorizontalPanDelegate.

The controller's vertical-pan begin predicate accepts only UIPanGestureRecognizer instances and checks enabled left/right regions using the float `gestWideness` preference. Overlapping regions preserve both enabled checks. The two-finger tap toggles playback only under `twoFingerTap`.

Main horizontal seeking requires all three fine-scrubber selectors. Begin notifies the scrubber; changed events round current and maximum times before applying sensitivity. Current-time label text includes hours when needed, sizes to fit, and restores its parent's opacity. End and cancellation call the end selector with source 25. The packaged FCVTAS operations are at `0x8bdf0`, `0x8be58`, and feed equivalent `0x80888`; the label's integer conversion is FCVTZS at `0x8bf98`. Both seeking paths preserve FCSEL/GT then FMAXNM behavior: unordered arithmetic ultimately clamps to zero. The reconstruction avoids undefined out-of-range C casts while preserving ARM saturation and NaN conversion.

Finger-pan state is shared across controller instances in the original image: mode at `0x115cd20`, starting brightness at `0x115cd28`, and starting volume at `0x115cd30`, all initially -1. The module preserves that shared state privately. Begin chooses left, right, or inactive mode; reads UIScreen brightness and host LDVideoAdBlock's float systemVolume; and presents the canonical PlayerToast for positive modes. Initial percentage uses FCVTAS at `0x8d258`. Changed events use vertical displacement and fused multiply-add, with exact multipliers 0.005 for brightness and 0.008 for volume, then the packaged clamp. Updates go through PlayerToast. End/cancellation resets all shared state and either hides the toast or throws the exact packaged YouTubePlusException if its alpha is zero. The fixture tests both branches, including shared state across two overlay instances.

## Validation and integration

Run `python3 recovery/tools/verify_player_overlay.py`. The verifier checks every manifest byte span and constant, regenerates actual Logos output with the pinned internal generator, compiles production source against the iOS SDK with warnings treated as errors, and audits all 38 callback signatures and the animation block signature. The generated hooks execute against isolated host boundaries under UndefinedBehaviorSanitizer. The current fixture passes 600 assertions spanning every registration, metadata, original forwarding, gesture construction/actions/states, float and integer boundaries, layouts, queued animation, and exception behavior.

Compile `PlayerOverlay.x` once and call its installer in the original primary registration order. `canRememberLoopMode` remains externally defined by PlayerLifecycleHelpers; this module only reads it. No assigned packaged callback accesses `isOverlayShown`, so no visibility-state behavior is invented. The gesture scalars remain module-private shared state. Canonical helper implementations remain external and are substituted only in tests. No supplied binary, real UI, pasteboard, settings persistence, or network service was driven.

Recovery preserves behavior, not original source names or formatting. Obfuscation, protection bookkeeping, and lazy runtime-class caches are omitted. Private host declarations describe only the used surface. Style indexes and loop mode preserve 64-bit register width; their original enum typedef spellings are unavailable. The constant fine-scrubber source 25 does not establish the host typedef independently. BOOL spellings follow existing declarations and packaged zero/one usage. Device validation and cross-layer constructor ordering remain integration work.
