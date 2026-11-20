# YTPMedia icon factories, first-package audit

All 59 named icon factories in the current source match the inspected first
package's asset selection and call sequence. No production change was needed.
Together with the separate theme audit, all 67 named `YTPMedia` methods now have
focused first-package evidence. The theme setter's omitted system trap and
unverified device behavior still prevent a claim of full class parity.

## Original instruction comparison

`first_media_icon_contracts.py` reads the first dylib as data and recognizes four
factory forms. The original entry ranges run from `+historyTab` at `0x1aab50`
through `+empty` at `0x1b5d50`, ending at `0x1b5e88`.

| Form | Methods | Inspected reference | Behavior |
| --- | ---: | --- | --- |
| Cairo pair | 55 | `+historyTab`, `0x1aab50` | Reads the base `YTPMedia` singleton's Cairo flag, then obtains the bundle and selects a constant asset name. |
| Retained Cairo pair | 1 | `+copy`, `0x1b4330` | Same selection; returns a retained object through Objective-C's copy method family. |
| White-tinted pair | 1 | `+ytPlusShorts`, `0x1af928` | Obtains the bundle, requests white, then forwards the selected asset name and tint. |
| Fixed asset | 2 | `+x_prefs`, `0x1b3c18` | `x_prefs` and `empty` perform no singleton or Cairo read. |

The reader verifies original instruction words, decodes each literal-init branch
and checks its two targets and complete register flow. Every decoded byte store
is resolved and confined to the selected literal buffers. The initialization
blocks contain only the allowed literal-decoding instructions; both paths join at the flag store before the
factory calls. Tail comparisons preserve register operands, class/selector
reference addresses, comparison condition and return sequence. Only the two
asset-address loads and resolved call destinations are substituted with named
entries for comparison. Unrecognized wrappers or differing tails fail the run.

Imported call stubs are resolved from the first binary's binding records. The
wrapper bodies must match the inspected stack/call/optional-BOOL-mask/return
sequence, including two low-bit masks around `isCairo`. The committed evidence
pins all 59 named bodies and 466 wrapper bodies, plus the decoded names, init
branch records and four inspected tail templates. Expected names are never read
from the reconstructed `.m` file or the other supplied packages.

Notable selections include `sleep` for Cairo `moon`, `ytl_outline` for normal
`ytPlus`, and `ytl_icon` for normal `ytPlusShorts`. The `copy` tail ends in `ret`,
while the other three forms tail-call `objc_autoreleaseReturnValue`. ARC gives
the recovered `+copy` method its retained return convention automatically.

## Actual-source checks

Run:

```sh
python3 recovery/tools/verify_first_media.py
python3 recovery/tools/verify_first_media_icons.py
python3 recovery/tools/first_package_audit_inventory.py
```

The icon suite executes the actual `YTPMedia.m` and passes 5,458 assertions across
948 factory invocations. Each factory runs with both Cairo flags and through the
base class and a subclass. Cases cover bundle-time Cairo changes, nil images and
nil bundles. The tinted factory also forwards a nil white-color result. Tests
check the exact event sequence, selected name, result identity, tint identity and
release after the caller and autorelease pool finish. The `copy` invocation uses
a constant selector so the test caller follows its retained return convention.

The icon verifier also checks that the separate theme report's source and support
inputs are current before reusing its 67-method ABI comparison for arm64 and
arm64e. No source change occurred between those compilations and this audit.

All 115 distinct requested asset names are present in the restored catalog.
The verifier checks that its bytes match the first package and reads its entries
with `assetutil`.

UIKit and asset loading are synthetic boundaries. This verifies factory routing,
not image appearance, catalog rendering or a live YouTube installation. The
original dylib is never executed, and this audit makes no claim about omitted
system traps, preference policy or other classes.
