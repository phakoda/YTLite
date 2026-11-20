# Settings recovery — YTLite 5.2.2

## Scope and verified result

The six implementations in this directory reconstruct the assigned classes from the original image. They use the existing `recovery/source/Models/{DVNCell,DVNSection,DVNTableModel}` and `recovery/source/Support/YTPDB` implementations. They do not define replacement model classes, alter the shared storage-only `DVNStoredBlock` typedef, or depend on the legacy root-level recovered Settings files.

| Class | Original own methods | Implementation |
| --- | ---: | --- |
| `DVNTableViewController` | 73 | `DVNTableViewController.h/.m` |
| `YTPSettingsBuilder` | 29 | `YTPSettingsBuilder.h/.m` |
| `DVNPickerView` | 1 | `DVNPickerView.h/.m` |
| `YTPTableViewCell` | 2 | `YTPTableViewCell.h/.m` |
| `TabbarVC` | 24 | `TabbarVC.h/.m` |
| `DVNSupportersVC` | 5 | `DVNSupportersVC.h/.m` |
| **Total** | **134** | Includes original property accessors and ARC destructors |

The compiler-emitted arm64 Objective-C metadata matches all **134 selectors and exact encodings, 12 properties and attributes, 16 ivars and their encodings/offsets/sizes/alignments, and six superclasses**. Property totals include the original inherited-protocol property entries. Explicit method bodies and compiler-synthesized accessors/destructors are distinguished in `provenance.json`.

The verification suite currently passes **2,636 runtime assertions**, including the shared runtime metadata audit. It independently compares **174 ordered row factories** against arguments extracted from the original ARM64 instructions. It recovers **68 original anonymous-block descriptors** and checks that their exact extended signatures appear in the appropriate compiler-generated class translation units. Factored C helpers can represent several equivalent original blocks; the block count is not a claim that the new compiler emits 68 distinct functions.

## Evidence and reproducible verification

Original image: `.recovery-work/arm/YTLite.dylib`.

SHA-256: `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`.

Sources used are `recovery/classes/*.c`, individual `recovery/decompiled/*.c` functions, `recovery/evidence/arm-classes.json`, `ivars.json`, decoded strings/bytes, the verified image's `application.asm` and `symbols.txt`, and `.recovery-work/analysis-v2/evidence/branches.json`. The latter provides the expanded 3,203-edge evidence set. The dedicated inspector annotates linear data flow and reports known CFG edges; it does **not** claim to be a general CFG solver.

Run from the approved repository on its real Mac:

```sh
PYTHONDONTWRITEBYTECODE=1 python3 tools/verify_settings.py
```

The runner compiles every production `.m` with Apple's iPhoneOS SDK using:

```text
-fobjc-arc -fblocks -Wall -Wextra -Werror
-target arm64-apple-ios13.0 -isysroot <iphoneos SDK>
```

It emits LLVM IR for the metadata/signature audit, compiles all six production implementations again against dedicated host-only UIKit/WebKit recorders, and links the actual shared model/YTPDB implementations. Neither the original image nor a package containing it is executed or dynamically loaded. Original image access consists solely of byte parsing and static disassembly evidence.

Generated objects, IR, cache directories, temporary files, logs, fixtures, and reports remain under `.recovery-work/settings/`. The final reports are:

- `verification-summary.json` and `verification-commands.json`;
- `metadata-audit.json` and `original-blocks.json`;
- `original-rows.json` and `runtime.log`.

`tools/verify_settings_provenance.py` validates the checked-in method/block manifest against the evidence and current source locations. Its explicit `--write` mode regenerates only `recovery/source/Settings/provenance.json` after a source change. Normal verification does not rewrite production files.

## Recovered behavior and non-obvious distinctions

### Table controller

All thirteen original cell types are implemented: switches, full and compact segmented controls, menus, child controllers, actions, sliders, time pickers, color wells, steppers, text fields, text editors, and generic/detail rows. Rendering constructs a new cell using the model's reuse identifier rather than dequeuing one. Model image, icon, rendering-mode, custom tint, accessory, and subtitle-provider rules are retained.

`_cellsForSection:` evaluates `cellsProvider` afresh, including returning nil without falling back to stored cells. Recursive search and child-containment scans use stored model cells. Search excludes controller rows themselves while traversing searchable child models. Navigation searches live provider results first, then child containment. Section providers are therefore deliberately not flattened into cached placeholder rows.

Handlers have separate recovered invoke types. `handler` is `void (^)(void)`; `selfHandler` is `void (^)(DVNCell *)`; `handlerWithCompletion` accepts a no-argument completion; subtitle and option providers return `NSString *` and `NSArray *` respectively. Synchronous handlers take priority over completion handlers. Only the deferred row reload is marshalled to the main queue; completion-side accessory removal and whole-table reload preserve the original caller-queue behavior.

Editor validation is `NSString * (^)(NSString *)`, not a Boolean predicate. A non-nil replacement is stored and synchronized; nil rejects it. The editor indexes stored `section.cells` rather than calling the provider. Whitespace-only text fields are cleared using `whitespaceCharacterSet`, intentionally not the newline-inclusive character set. Menu actions preserve the first `indexOfObject:` result for duplicate titles, reset invalid persisted indices to zero, and retain the original exception on an empty menu array.

The controller uses inherited **instance** `NSUserDefaults` float APIs, which take/return `float`; these are not replaced by the unrelated double-width class convenience APIs. Slider quantization uses `FRINTA d8,d0` at `0x1219b4`: the double quotient rounds to nearest with ties away from zero, remains double for the multiplication, and narrows to float only at `0x1219c8`. It preserves the original value/divisor/multiplier getter order, including three separate divider reads. Footer measurement uses `FRINTP d0,d8` at `0x11c80c`, then floating addition of 10 at `0x11c814`: `ceil(height) + 10.0`. Neither path converts through an integer. Remaining FCVTZS conversions explicitly retain ARM64 NaN and saturation behavior. The initial picker clamp's `FCSEL LT` includes unordered operands; a plain ordered C `<` comparison would be different. Native-instruction fixture oracles cover these edge cases without executing original image bytes.

Split presentation replaces the ancestor's second controller only when that second controller already exists. Otherwise the original flat wrapper is pushed. Search-field corner resets, highlight timing, the animated thanks heart, bar-item block associations, renderer sizes, and control constraints are implemented. The original color-well fallback sends `performSelector:` with `invokeColorPicker:` and no explicit argument; that odd forwarding is retained rather than inventing an argument.

Controller ivars are private to the implementation extension. Exposing them in the public header changes the compiled initial ivar offsets of `TabbarVC`, even with non-fragile runtime adjustment. The metadata audit caught and verifies this distinction.

### Builder

All table, section, cell, provider, URL, validation, image-rendering, and completion construction is implemented. The raw factory fixtures cover downloading (11 rows), navigation bar (7), feed (9), player (82), shorts (33), interface (27), and RPC (5). They compare titles, subtitles, exact keys, cell types, option arrays, images, ranges, formats, and identifier-stamping paths. The one runtime-dependent extracted range, gesture-area maximum, is checked separately against both screen orientations and a square screen.

Additional fixtures exercise the full root hierarchy, all 28 SponsorBlock rows, the eight segment descriptors, both user-ID validators, account-state providers/actions, all contributor/library/developer link callbacks, preference import/export/reset, and donation/cache completions. Constructors using `sectionWithIdentifier:` followed by `addCells:` retain their distinct cell-title identifier stamping; factory-built sections retain section-identifier stamping.

The account provider leaves static cells empty and creates fresh rows according to the original exported authorization functions. It does not replace authentication or premium checks. Login starts the original row activity indicator and disables its source view; device management and logout forward to the original owner interfaces. The provider captures the builder/model strongly; `presenter` and each model's `selfViewController` remain weak as declared.

The public SponsorBlock ID accepts exactly 64 characters, while the private ID accepts more than 31; neither introduces a new hexadecimal validator. Nil/empty input regenerates through the original defaults helpers. The donation request, default links/addresses, array-only response overrides, per-action images, URL-open gating, and clipboard callbacks are retained. Developer image-cell callbacks consume a `DVNCell *` argument even when unused. Donation actions likewise take a `YTActionSheetAction *`; their extended original descriptors establish those otherwise invisible arguments.

Cache clearing retains the original behavior of removing each cache child and then the entire temporary directory, ignoring filesystem errors, and calling completion on the main queue. Cache sizing includes directory-entry sizes. These behaviors are **not** exercised against real preferences, real media, real cache locations, or the machine's actual temporary directory in the suite.

### Tab editor and remaining views

The tab editor preserves all fourteen literal identifiers, saved order, filtering of unknown/repeated identifiers against remaining tabs, the four section arrays, the three tab-bar switches, and exclusion of uploads from startup choices. Delete/insert limits compare for equality with one/six rather than adding stronger bounds. Startup replacement uses the first remaining tab even when that tab is uploads. The original editing-style fallback tests whether the inactive section's **index is nonzero**, not whether the selected row belongs to that section. New host-header construction for pivot refresh, reload ordering, haptics, cross-section move rejection, and standalone dismissal are retained.

The picker resizes every immediate subview's x origin and width, preserving y/height and leaving grandchildren untouched. The custom table cell uses the original selection border and deselection animation, selection-background colors, fade KVC, and screen-scale-dependent fonts. The supporters controller is the original WKWebView-based implementation, with its exact request, safe-area constraints, activity delegates, and accumulating error labels.

## Fixture isolation and coverage boundary

Dedicated test files are `recovery/tests/settings_runtime.m`, `settings_controller_fixture.m`, `settings_views_fixture.m`, `settings_ui_doubles.m`, `settings_fixture_hosts.h/.m`, `settings_fixture_redirects.h`, and `settings_shims/`. They do not alter shared shims or build files.

The test defaults object is an `NSObject`-backed dictionary: no `NSUserDefaults` instance is initialized. Clipboard and application URL operations are in-memory recorders. A fixture session records network tasks and accepts manually supplied responses; it performs no network request. Dispatch is an explicit FIFO fixture queue. Both filesystem-path APIs used by cache methods are redirected to a dedicated repository fixture directory before those methods execute. Host-only NSLayout names are prefixed to avoid collisions with macOS CoreAutoLayout.

The suite demonstrates recovered model/controller logic, API arguments and widths, callback ordering, metadata, and selected ARC lifetime behavior. It is **not** an iOS device UI test and does not establish pixel-perfect rendering, real YouTube wrapper presentation, live authentication, or successful integration of the complete tweak. No full-repository build or Makefile modification is part of this worker's scope.

## Integration dependencies

Compile the six `.m` files in this directory once and use the canonical shared Models/YTPDB sources. Required Apple frameworks include UIKit, Foundation, QuartzCore, CoreGraphics, and WebKit. `SettingsContracts.h` provides narrow declarations, not replacement implementations.

The surrounding recovered implementation/host must supply:

1. The existing `YTLUserDefaults` implementation, `NSString`'s `ytl_localized`, `NSBundle`'s `ytl_defaultBundle`/`originalImageWithName:`, and `YTPMedia`'s `adaptiveBackgroundColor`/`imageWithName:`.
2. Original YouTube controls and presentation classes: `ABCSwitch`, `YTQTMButton`, `YTAlertView`, `YTHeaderContentComboViewController`, `YTWrapperFlatViewController`, `YTWrapperSplitViewController`, `YTDefaultSheetController`, and `YTActionSheetAction`; plus `ToastManager` and `DVNMediaPicker` from their recovered owners.
3. The original exported C interfaces: `BOOL dvnCheck(void)` (0x2368c), `BOOL dvnLocked(void)` (0x23680), `void DVNPatreonLogin(UIViewController *)` (0x23ef0), `void DVNPatreonOpenDevices(UIViewController *)` (0x264c4), and `void DVNPatreonLogout(void)` (0x23b64).

These are explicit link/runtime dependencies, not stubbed production behavior. Existing iOS-version-sensitive host messaging, including menu and color-well selectors, is retained rather than introducing fallback UI. Integration should not include both these classes and root legacy recovered copies.

### Rounding correction and regression evidence

The prior recovered footer and slider implementations incorrectly introduced truncating integer conversions. Original raw instruction words, pinned by `tools/verify_settings.py`, establish `0x11c80c=1e64c100` (FRINTP), `0x11c814=1e612808` (FADD), and `0x1219b4=1e664008` (FRINTA), together with the surrounding widening/division/multiplication/narrowing instructions. Earlier footer comments cited three unrelated instruction addresses as conversion evidence; those comments have been removed.

The added actual-source tests failed first on the old footer, then on the old slider after only the footer was corrected. Logs are `.recovery-work/navigation-helpers-rounding-audit/settings-red-footer.txt` and `settings-red-slider.txt`. A 13.9-point measured footer now returns 24, and a 0.375 slider with a 0.25 divider returns 0.5. The native instruction oracles test positive and negative ties, signed zero, NaN, infinities, values beyond signed-integer range, float extremes, changing divider getters, and zero/negative/unordered gates. The footer tests preserve floating overflow and non-finite results; slider tests compare both the control value and the stored float. Existing picker clamp and truncating integer tests remain intact. These tests cover numerical source behavior, not real UIKit measurement or UISlider clamping.
