# CompatibilityVersion recovery

All seven replacement registrations from initializer `0xc554` are reconstructed in `CompatibilityVersion.x`. The exported `YTLInstallCompatibilityVersionHooks()` contains the original version gate and installs the entire group. There is no constructor; the parent owns initializer ordering and duplicate removal.

The installer reads `CFBundleShortVersionString` through `-[NSBundle objectForInfoDictionaryKey:]` on the real main bundle, then compares it with `20.21.6` using `NSNumericSearch`. Installation occurs only for `NSOrderedAscending`. A nil version does not install; an empty string does. `20.9.99` installs and `20.100.1` does not. `20.21.06` compares equal and does not install. These behaviors are retained without an added once guard.

| Target | Selector | Replacement | Behavior |
| --- | --- | --- | --- |
| YTIIcon instance | `iconType` | `0xd264` | Seven sequential original calls and icon remappings; eighth original call when none matches. |
| QTMIcon class | `imageWithName:color:` | `0xd508` | Replace the moon resource with the canonical bundle image tinted with the supplied color; otherwise forward. |
| YTELMResourceLoader instance | `imageWithName:color:bundleId:` | `0xd890` | Eight exact image-name substitutions; forward color and bundle ID unchanged. |
| YTWatchFloatingMiniplayerWithControlsOverlayView instance | `layoutSubviews` | `0xf74c` | Forward first, then set corner radius 12 and masks-to-bounds. |
| YTVersionUtils class | `appVersion` | `0xf7e0` | Return `20.21.6` without forwarding. |
| YTSettingsCell instance | `setDetailText:` | `0xf8d8` | Replace the spoofed version text with the main bundle's actual info-dictionary version, then forward. |
| ELMTouchCommandPropertiesHandler instance | `handleTap` | `0xfc90` | Recover sleep-timer and video-opening actions; forward unmatched taps. |

The original inventory has a missing class and unknown method kind for `0xd264`. The original initializer decodes `YTIIcon` and registers against the class directly, without `object_getClass`. The manifest preserves the original row unchanged, supplies a separate resolved row, and identifies source ownership. `YTIIcon.iconType` is a 32-bit enum in the host declarations and uses `w0` in the packaged callback; the recovered method returns `int`, verified as `i32` in generated iOS LLVM.

## Branch fidelity

The icon method independently calls its original IMP for each comparison: `1154 → 65`, `1155 → 66`, `1157 → 776`, `1161 → 734`, `1162 → 44`, `1160 → 60`, `1156 → 355`. The comparisons must not cache one original result. At branch sites `0xd320`, `0xd368`, `0xd3b0`, `0xd3f8`, `0xd440`, `0xd488`, and `0xd4d0`, the verified original tables send false to the next call and true to the common return at `0xd4f4`. Tables begin at `0x1152910` and advance by 24 bytes. The manifest records each table, XOR constant, predicate, destination pair, and return value.

The expanded tap export truncated at `0x10d58`. Original bytes establish the missing overflow-menu path:

- Table `0x1152c00` at `0x10d58` sends a matching `ASNetworkImageNode` to `0x10d5c`; false goes to `0x10e20`.
- The callback reads the first subnode again, then compares its image accessibility identifier to `ytp_moon_image`. Table `0x1152c18` sends true to `0x10f80` and false to `0x10e18`.
- The closest view controller is tested against `YTActionSheetDialogViewController`. Table `0x1152c30` sends true to `0x10ff4` to dismiss it, and false directly to `0x11028`. Both paths then show the shared sleep timer's options with nil and suppress original forwarding.

The first subnode access remains unchecked: an empty subnodes array raises as in the package. The matching node and controller getters are intentionally read again where the original does so.

For `eml.vwc`, the yoga parent must be `YTVideoWithContextNode`, its parent responder must be `YTCellController`, and the entry description must contain `https://i.ytimg.com/vi/`. The callback passes the description to `YTPPlayerHelper.getVideoID:`, then forwards that result and the tap handler to `openVideoWithID:handler:`. A nil parsed ID is still forwarded. This path suppresses the original. Missing `_controller`, unrelated nodes, nonmatching images, and failed video predicates forward exactly once.

## Boundaries and validation

Canonical recovered helpers supply `YTPSleepTimer`, `YTPPlayerHelper`, and `NSBundle(YTLite)`. The exact category selector `imageWithName:tintColor:` was recovered separately at `0x235644`; its implementation is covered by the parent-owned bundle verifier. The host header declares only the external classes and selectors used by these callbacks.

Run:

```sh
python3 recovery/tools/verify_compatibility_version.py
```

The verifier checks all seven original registration rows and resolved source registrations; the verified original image hash; eight complete instruction intervals; 60 decoded-string records; 20 branch records; and ten explicit table calculations. Pinned Logos generates the actual implementation, which compiles for iOS arm64. LLVM signatures verify the 32-bit icon result and pointer argument counts. A macOS fixture executes that same generated source with isolated UIKit, bundle, and helper interception under UndefinedBehaviorSanitizer. There are 172 runtime checks for each enabled suite and eight separate-process version-gate cases, including equality, numeric ordering, nil, empty, and leading-zero values. The verifier records commands, input hashes, ABI signatures, and case results in `.recovery-work/compatibility-version/`.

The supplied dylib was inspected, never executed. Fixtures exercise recovered behavior with synthetic objects; they do not prove behavior inside a live YouTube process. Obfuscation bookkeeping, decoded-string initialization, and protection syscalls are omitted. No callback behavior remains unresolved in this module; integration and real-device validation belong to the parent task.
