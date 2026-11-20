# YTPMedia theme and state, first-package audit

The current implementation matches the inspected theme, version-gate and generic
asset-selection paths in the first supplied `iphoneos-arm64e.deb`. No production
change was needed. The setter's system-trap side effect remains omitted, and this
audit does not establish full class or package parity.

## Original evidence

`recovery/evidence/first-media-theme-fidelity.json` pins the first binary hash,
13 instruction spans, nine decoded strings, four double constants, 12 decoded
branch tables and 28 selector loads. The verifier extracts the supplied archive
as data, decodes string writes from fresh disassembly and checks each selector
reference against its adjacent ADRP/LDR instructions.

| Method | First-package entry | Relevant behavior |
| --- | --- | --- |
| `+sharedMedia` | `0x1aa098` | One shared slot; callback `0x1aa14c` allocates and initializes the first receiving class. |
| `+pageStyle` | `0x1aa174` | Retains one delegate; checks the first root's selector, then reads the root again. Missing support returns -1; a nil second root returns zero. |
| `+adaptiveBackgroundColor` | `0x1aa2f8` | Captures `oledTheme` once; callback `0x1aa4a4` reads the receiving class's current style. Style 1 selects black or gray 0.059; all other values select white. |
| `+oledForColor:` | `0x1aa5d4` | Style 1 and successful component extraction are required. Each RGB channel must differ from the same gray, 0.059 or 0.129, by strictly less than 0.001. Alpha must differ from 1 by strictly less than 0.001. Callback `0x1aa8cc` resolves black for style 1 and white otherwise. |
| `+imageWithName:` | `0x1aa920` | Reads the base class singleton and Cairo flag before bundle lookup. Appends `_cairo` after bundle lookup. Nil values are forwarded without fallback. |
| `+adaptiveDiscord` | `0x1b5e88` | Reads `discordRPC`, then Cairo, then the bundle. The two captured flags select the four decoded asset names. |
| `-setCairo:` | `0x1b63d8` | Reads the main bundle version and compares numerically to `20.12.4`. Exactly NSOrderedAscending disables Cairo. Nil version accepts the requested flag. |
| `-isCairo` | `0x1b6720` | Reads the byte at instance offset 8. |

The OLED comparisons use ARM floating-point MI conditions. NaN fails these
comparisons. The blue/alpha table at `0x11b2708` sends index zero to provider
construction and index one to the next-gray decision. The latter table at
`0x11b2720` sends index zero to passthrough and index one to the second gray.
This confirms both strict comparisons and termination after two grays.

The version setter compares the returned 64-bit value with -1 at `0x1b66e0`,
selects the stored byte at `0x1b66e4`, then performs the omitted system trap at
`0x1b6708`. The audit explicitly records this difference.

## Actual-source verification

Run:

```sh
python3 recovery/tools/verify_first_media.py
python3 recovery/tools/first_package_audit_inventory.py
```

`first_media_runtime.m` compiles with the actual `YTPMedia.m` and runs 423
assertions. Foundation strings, numeric comparison, object lifetimes, ARC and
dispatch_once are real. UIKit, preferences and bundle lookup use isolated test
doubles. Cases include concurrent singleton reads, subclass dispatch, changing
roots, preference capture, live theme resolution, every RGBA channel around both
gray thresholds, adjacent representable doubles, NaN/infinity, nil results and
state mutation during preference and bundle calls. A comparison-result probe
also distinguishes exactly -1 from other negative values.

The same verifier compiles the source for arm64 and arm64e and compares all 67
emitted method encodings directly with the first binary's metadata. This broader
ABI check does not extend behavioral evidence to the other 59 icon factories.
Input hashes are checked again after compilation and execution. A failed run
removes the preceding success report.

The original dylib is never executed. Native UIKit rendering, actual bundle
asset availability and live-device integration remain untested here. The
synthetic preferences bypass the repository's separately documented local
preference policy, so they cannot establish preference-policy parity.
