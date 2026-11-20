# MediaPolicy recovery

All 27 assigned hooks are recovered: 23 instance replacements and four class replacements, all registered by `0x53fac`. There are no added methods, properties, callbacks, or shared globals. `YTLInstallMediaPolicyHooks()` installs the named `YTLMediaPolicy` group and has no constructor.

The supplied arm package's canonical ARM64 image has SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The adjacent manifest pins each complete original function, its original IMP slot and registrar, 16 decoded constants, 16 feature wrappers, 27 original branch records, and eight intentionally omitted supervisor instructions. The verifier compares all 1,551 function instruction words against the image, including the register widths of the short protobuf replacements.

| Class | Selector | Implementation |
| --- | --- | --- |
| `YTIPlayabilityStatus` | `-isPlayableInBackground` | `0x000662c8` |
| `MLVideo` | `-playableInBackground` | `0x00066464` |
| `YTIBackgroundOfflineSettingCategoryEntryRenderer` | `-isBackgroundEnabled` | `0x00066600` |
| `YTGlobalConfig` | `-shouldBlockUpgradeDialog` | `0x000667a0` |
| `YTIPlayerResponse` | `-isMonetized` | `0x000668fc` |
| `YTIPlayerResponse` | `-playerAdsArray` | `0x00066a5c` |
| `YTIPlayerResponse` | `-adSlotsArray` | `0x00066bcc` |
| `YTIPlayerResponse` | `-auxiliaryUi` | `0x00066d40` |
| `YTIPlayerResponse` | `-setHasAuxiliaryUi:` | `0x00066d48` |
| `YTIPlayerResponse` | `-setAuxiliaryUi:` | `0x00066d80` |
| `YTIClientMdxGlobalConfig` | `-enableSkippableAd` | `0x00066db8` |
| `YTAdShieldUtils` | `+spamSignalsDictionary` | `0x00066f14` |
| `YTAdShieldUtils` | `+spamSignalsDictionaryWithoutIDFA` | `0x0006707c` |
| `YTDataUtils` | `+spamSignalsDictionary` | `0x000671e4` |
| `YTDataUtils` | `+spamSignalsDictionaryWithoutIDFA` | `0x00067350` |
| `YTAdsInnerTubeContextDecorator` | `-decorateContext:` | `0x000674bc` |
| `YTAccountScopedAdsInnerTubeContextDecorator` | `-decorateContext:` | `0x0006760c` |
| `YTLocalPlaybackController` | `-createAdsPlaybackCoordinator` | `0x0006775c` |
| `MDXSession` | `-adPlaying:` | `0x000678b4` |
| `YTIAuxiliaryUi` | `-setHasMessageRenderers:` | `0x0006e46c` |
| `YTIAuxiliaryUi` | `-setMessageRenderers:` | `0x0006e4a4` |
| `YTITriggerConditions` | `-hasPlayerCueRangeSet` | `0x0006e4dc` |
| `YTITriggerConditions` | `-validAdsStatesArray_Count` | `0x0006e4e4` |
| `YTIVideoPlaybackRelativePosition` | `-streamTimeMs` | `0x0006e4ec` |
| `YTIVideoPlaybackRelativePosition` | `-hasStreamTimeMs` | `0x0006e4f4` |
| `YTICoWatchability` | `-type` | `0x0006e4fc` |
| `YTICoWatchability` | `-setType:` | `0x0006e504` |

## Recovered behavior

The three background getters return `ytpBool(@"backgroundPlayback")` directly and never call their originals. `noAds` does not affect them. When `noAds` is enabled, upgrade-dialog blocking and skippable ads return YES; monetization returns NO. Otherwise those getters forward the original result.

`playerAdsArray` and `adSlotsArray` return a newly created mutable empty array on every enabled call. Disabled calls preserve the original object identity, including nil. All four class-level spam-signal getters return the immutable empty dictionary when enabled and the unchanged original object otherwise. They remain class hooks on the metaclass.

Both context decorators always call the original, passing nil when `noAds` is enabled and the incoming object otherwise. `createAdsPlaybackCoordinator` returns nil only when enabled. `MDXSession.adPlaying:` skips its original only when enabled; its argument is an object, evidenced by retain/release instructions, and remains opaque.

Auxiliary UI behavior is unconditional: `auxiliaryUi` returns nil; `setHasAuxiliaryUi:` and `setHasMessageRenderers:` forward NO; `setAuxiliaryUi:` and `setMessageRenderers:` forward nil. Trigger cue presence, valid ad-state count, stream time and stream-time presence return zero without original calls or feature reads. Co-watchability returns enum value 2 and its setter always forwards 2 regardless of input or preferences.

## ABI and reconstruction limits

`validAdsStatesArray_Count` at `0x6e4e4` and `streamTimeMs` at `0x6e4ec` use `mov x0, #0`, establishing a 64-bit integer result. The source uses `NSUInteger` for the count and `int64_t` for time. A zero-only replacement cannot prove the original protobuf field's signedness; both produce the established ABI and zero value. The BOOL presence getters use `w0`, and co-watchability uses `w0`/`w2` for its 32-bit enum value. Its private generated enum name is unavailable. Concrete protobuf/context/coordinator classes for opaque object slots are not invented.

The original image contains eight post-operation supervisor calls associated with anti-debug machinery. They are recorded with exact words/addresses in the manifest and deliberately excluded from functional source and runtime execution. One-time constant-decoding guards are also replaced by clear literals. Feature results and original forwarding before those instructions are preserved. The parent-owned local preference implementation of `ytpBool` remains the project's integration policy.

## Verification and integration

Run `python3 recovery/tools/verify_media_policy.py`. `.recovery-work/media-policy-tests/report.json` records 406 passing assertions under UBSan, all 27 real-SDK arm64/iOS 14 callback signatures, and all original byte checks. Tests execute generated Logos implementations and real Foundation collections: original receiver/selector/argument identity, gate order, fresh mutable arrays, immutable empty dictionaries, nil returns, suppressed calls, forced setter arguments at both preference values, extreme 32-bit enum inputs, and unchanged property lists. The fixture does not load or execute the packaged dylib or make network requests. It uses synthetic host implementations and therefore cannot establish on-device rendering or behavior outside these hooks.

The parent should add `MediaPolicy.x` to production sources, call `YTLInstallMediaPolicyHooks()` at the main registration phase, and remove matching root hooks. The only implementation dependency is canonical `YTLFeaturePolicy`/`ytpBool`; Foundation provides the collections and Objective-C runtime. No root files or shared build lists were changed by this module.
