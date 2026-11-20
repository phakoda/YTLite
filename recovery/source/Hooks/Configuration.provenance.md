# Configuration hooks

`Configuration.x` reconstructs 38 selected packaged registrations: 36 method replacements and two added methods. Four playback authentication/attestation callbacks are recorded as evidence-only exclusions. `Configuration.manifest.json` lists each original implementation, saved-IMP slot, registration function, registration operation, original instruction range and range hash.

The five host classes and registration counts are:

| Host class | Replaced | Added |
| --- | ---: | ---: |
| YTColdConfig | 25 | 0 |
| YTHotConfig | 4 | 0 |
| YTIMediaQualitySettingsHotConfig | 0 | 2 |
| YTIPlayerColdConfig | 1 | 0 |
| YTIHamplayerServerABRConfig | 6 | 0 |

Recovered behavior:

- Startup animation reads `integerForKey:` from the tweak defaults directly. Modes 1 and 4 return true, mode 2 returns false, and every other signed 64-bit value calls the saved original. In particular, mode 3 is not forced off.
- Next/previous paddle visibility and replacement gates force true. Sticky comment sorting, hidden comment sorting, ambient-mode display, floating playlist minibar, lock-screen-controller disable flags and Shorts quality-picker gates force false. `enableTurnOffCinematicForFrameWithBlackBars` instead forces true when ambient mode is disabled. When a gate is false, the original receiver and selector are forwarded exactly once.
- Both cold-config Shorts progress selectors, the hot-config vertical fullscreen progress selector and stock volume HUD return their preference gate directly. They never consult the original method.
- The unconditional flags preserve the packaged true/false values for theme selection, landscape swipe dismissal, playlist swipe removal, local-network permission configuration, software decoding, context population.
- Both media-quality settings methods are added with `%new`, returning false. Existing host implementations are therefore not replaced by these registrations.
- Adaptive-stream fallback getters return true; both fallback setters always forward true, regardless of the incoming value. `maxFallbackAttempts` returns exactly 2,147,483,647.

Evidence and ABI:

- All 38 selected original function ranges are pinned to the supplied binary SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. Normalized later exports under `.recovery-work/readable/analysis-v3/` were used to correct the older decompiler's apparent `void` return for direct preference hooks.
- Seventeen short wrapper chains in the manifest are resolved from original instruction templates to `_ytpBool` by `EvidenceImage.terminal`. Direct hooks end by tail-calling those wrappers; the wrappers preserve the gate's low-bit BOOL result.
- Startup instructions `0x522f0` through `0x52424` compare `x21` (64-bit) with 2, 4 and 1. The fallback at `0x523c8` loads original IMP slot `0x1225fd8`, restores self into `x0` and selector into `x1`, and branches to that IMP. The recovered branch-table destinations explain why only modes 1, 2 and 4 override it.
- At `0xb5710` and `0xb5750`, `mov w2,#1` supplies the saved setter implementations with true. Their original slots are `0x1226768` and `0x1226778`. `0xb5778` is `mov w0,#0x7fffffff`, followed by `ret`.
- The added functions at `0x9025c` and `0x90264` are `mov w0,#0; ret`. The final module uses BOOL getter ABI, BOOL setter arguments, and a 32-bit integer for the constant fallback limit. All emitted iOS LLVM signatures are checked, and the actual registered host fixture methods are checked at runtime.
- The available vendor headers expose these configuration classes only sparsely. The tweak does not contain the original host method metadata. The original signedness/spelling of `maxFallbackAttempts` cannot be distinguished from its constant return alone: signed/unsigned 32-bit declarations have the same observed register/value here. The reconstruction preserves that original register and positive value; it does not claim recovery of unavailable source spelling. No unresolved branch remains in the selected callbacks.

Integration differences:

- Use the canonical Runtime `ytpBool` function. Its current local preference policy differs from the packaged historical bootstrap/account policy; this module preserves each call site and preference key. The parent task owns that policy audit. Startup animation deliberately keeps its direct defaults read rather than calling `ytpInt`.
- Compiler/obfuscator string initialization, opaque branches and supervisor instructions are replaced by ordinary source. Production only declares host classes; it never implements substitute YouTube classes.
- This module is selected in `recovered.mk`. Its startup-animation hook installs during the early phase; the remaining hooks install during primary registration through `YTLHookEntrypoints.m`. It has no independent constructor.

Run `python3 recovery/tools/verify_configuration_hooks.py`. It verifies exact registration coverage/operations, all original function hashes and wrapper terminals, preprocesses the real module with pinned Logos, verifies its 38 iOS LLVM callback signatures, then compiles and executes the same generated code with undefined-behavior sanitization. All 880 assertions pass. Tests supply both original BOOL results and both gate states, verify the exact preference key and original self/selector/call count, exercise eleven startup values including 64-bit truncation traps, both setter inputs, unconditional results and newly added methods. Runtime doubles replace only host behavior and preference policy; actual Logos registration and method dispatch execute. No supplied binary is loaded, and there are no UI or network side effects. Device/YouTube integration remains outside this fixture.
