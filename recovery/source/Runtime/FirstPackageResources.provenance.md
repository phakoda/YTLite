# First-package resource categories

The `iphoneos-arm64e` package's `NSBundle(YTLite)` category implements
`ytl_defaultBundle` at `0x234154`. Its once callback starts at `0x2341dc`.
The source now selects this package's resource resolver when
`YTLITE_RESOURCE_ROOTHIDE` is defined. The Makefile sets that define for
`ROOTHIDE=1`. The project now supplies the required package module and linker
declarations; see [roothide build configuration](../../build/roothide/README.md)
for the separate archive verification and remaining device limitations.

The callback reads the embedded bundle path, then unconditionally calls
`jbroot(NSString *)` at `0x234bd4`. It retains the returned NSString and selects
the embedded path when nonnil. The call is not skipped when an embedded bundle
exists. The existence check at `0x234c20` determines whether to construct a bundle
or use the main bundle and show the original warning. If an existing path fails
`bundleWithPath:`, the result remains nil without another fallback. The once
token preserves that result.

The direct resolver returns an NSString. No C-string conversion or 1,024-byte
buffer appears in this package's lookup. The other package's libroot-based
implementation remains selected for the default build.

The Objective-C declaration uses the exact imported linker name
`__Z6jbrootP8NSString`. It declares an external runtime dependency and supplies
no implementation. The verifier checks the compiled iOS object's undefined
symbol and absence of `YTLJailbreakPath` in this configuration.

`verify_first_bundle.py` reads the first archive directly, verifies its hash,
checks the original instruction spans and branch tables, and decodes the relevant
constant strings from original instructions. It compiles the actual category
with a synthetic resolver and runs six separate processes covering embedded,
installed, missing, invalid, nil and 1,401-character paths. Five emitted category
method encodings and their original implementation addresses are checked against
the first binary's category metadata.

## Image helpers and localization

The first package implements `imageWithName:` at `0x234d60`,
`originalImageWithName:` at `0x234dc8`, and `imageWithName:tintColor:` at
`0x234de4`. Their inspected instructions match the existing recovered source:
the load receives the caller's name, receiving bundle, and nil traits. The
template helper applies mode 2, while the original helper returns the load
result directly. The tint helper dynamically calls `imageWithName:`, then
`imageWithTintColor:`, then rendering mode 1. It formats `ytp_%@_image` and
sets the final image's accessibility identifier. The format string is decoded
from the first binary at `0x11d1cb0`. The string initialization branch table at
`0x11d1d90` and message-send wrappers through `0x2352e4` are pinned in evidence.

There is no image-result guard before formatting at `0x234fe4`. Thus a missing
intermediate image still causes the name's description to be evaluated. The
independent `first_category_runtime.m` fixture checks this with four distinct
image objects, nil at each stage, an observable name description, and a bundle
override. It also checks nil/empty-name and nil-tint forwarding at a synthetic
UIKit boundary. Those checks do not assert UIKit's own response to such inputs.

The `NSString(YTL)` method at `0x210b88` sends `localizedStringForKey:value:table:`
with the original key and nil value/table, then reads the result's length once.
The 64-bit compare and CSEL at `0x210bf8`/`0x210bfc` return the original key for
zero length and preserve the translation's identity otherwise. The fixture
checks zero, one, and maximum unsigned length, nil translation, and nil bundle.

The six resource processes retain their 109 checks. The additional category
process passes 80 checks, giving 189 in total. This audit found no source change
necessary in these four image/localization methods; it adds first-package
implementation evidence beyond their previously verified method encodings.

```sh
python3 recovery/tools/verify_first_bundle.py
```

The report is `.recovery-work/first-bundle/report.json`; durable instruction
evidence is `recovery/evidence/first-bundle-fidelity.json`. No supplied binary or
real libroothide implementation is loaded. The isolated category checks do not
prove complete roothide linking, packaging or device behavior.
