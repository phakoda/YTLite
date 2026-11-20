# Presentation dependency reconstruction

## Scope and status

This directory contains the ten presentation classes required by Downloads and
the playback controls. `../Helpers/YTLHelper.m` contains the accompanying
download/media orchestrator. These are ARC Objective-C implementations, not the
exported decompiler C and not production mock classes.

The complete supplied selector surface is retained: ToastView 47, ToastWindow 9,
ToastManager 15, PlayerToast 16, CustomHUD 9, BlurButton 3,
DVNImageViewController 18, DVNSheetPresenter 3, PseudoDetentController 13, and
PseudoDetentTransitioningDelegate 6. Counts include compiler-generated accessors
and ARC destructors where present. With YTLHelper's 22 methods, the owned scope
is **161 original methods in 11 classes**. No unresolved selector was removed to
make the count or compilation pass.

`manifest.json` records source hashes, original class metadata, generated-object
hashes, and final compiler/runtime report locations. The manifests must be read
with the limitations below; matching method encodings is not a claim that the
original obfuscated instruction stream has been reproduced.

## Evidence and validation boundaries

Primary evidence is `recovery/evidence/arm-classes.json` for selectors and exact
method/property encodings, `recovery/evidence/ivars.json` for ivar order/types/
offsets and instance size, the corresponding `recovery/classes/*.c`, and the
individual `recovery/decompiled/<address>.c` files for callback bodies.

The original read-only image is `.recovery-work/arm/YTLite.dylib`, SHA-256:

```
bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca
```

`tools/verify_presentation_evidence.py` verifies that image hash, maps its segment
bytes, and overlays `decoded-bytes.tsv` **in memory** before reading CFStrings.
It handles UTF-16 CFStrings instead of treating their initializers as byte
strings. Bounded assembly requests verify every original instruction word
against `.recovery-work/arm/application.asm` and print an instruction SHA-256.
It neither executes the image nor examines/audits its function-start table.
The previously blocked whole metadata/function-start audit was not repeated.

`tools/verify_presentation_sources.py` is an independent compiler-output check:
it compiles only these owned sources with ARC, blocks, `-Wall -Wextra -Werror`,
SDK 26.2, and targets `arm64-apple-ios14.0` and `arm64e-apple-ios14.0`. It emits
real Mach-O object files and separately compares the compiler's LLVM Objective-C
method/property/ivar records with the supplied class metadata. All 161 methods,
33 property records, 60 ivars, and eleven instance sizes match on both targets.
This is an audit of newly compiled source metadata, not of original binary
function starts.

## Reconstructed behavior

### ToastView, ToastManager, ToastWindow

ToastManager retains active toasts, prevents duplicate registration, unregisters
completed presentations, and synchronously enumerates its live collection under
the collection lock when layout changes. Registration and removal keep that
lock through their update call. Construction and registration precede queued
message display. See `ToastManager.provenance.md` for the original call sequence.
ToastView has a copied FIFO command queue and the recovered `_isAnimating` gate.
Show/hide commands preserve distinct progress, status, wait, plain-text,
countdown, titled-action, icon-action, and donation-reminder flows. The queue's
anonymous blocks execute the actual setup, transition, callback installation,
delayed dismissal, and queue-continuation work. Stop/action completion blocks
remain owned until replaced or their toast is released; cleanup does not clear
the completion property. Commands and countdown callbacks strongly capture the
toast. A delayed hide can affect a later presentation because the original has
no generation check.

The shared window consumes its once token even if no scene is available. It
selects the first active scene, otherwise rereads the scene collection and takes
its first object. The queued window action calls `makeKeyAndVisible`.
The shared window uses a transparent root controller, four edge constraints,
and a level of `UIWindowLevelAlert - 1`. It cannot take the application key
window or control status-bar appearance/orientation. Both the public and private
key-window selectors and the runtime status-bar alias are present.

The hit-test implementation walks the hit view's ancestors. Fresh decoded
strings and guarded instructions identify ToastView, the host action/default/
bottom-sheet controllers, WelcomeVC, and YTTouchForwardingView. Bare window/root
backgrounds pass through. Earlier broad ContextMenu/UITransitionView name
guesses were removed; they were not supported by the recovered class body.

Toast geometry preserves the 45-point minimum height, 22.5-point corner radius,
1-point border, 24-point status/stop controls, 30-point activity indicator,
15-point bold monospaced-digit text, and 10-point action-stack spacing. The width
fractions are phone portrait .95 / landscape .5 and pad portrait .5 / landscape
.3. The keyboard, host-bottom-offset, good-height, safe-area, and stacked-toast
offset/scale formulas execute directly in `ToastView.m`. The geometry verifier
checks getter order and arithmetic against original instructions, including
empty-stack scaling and unordered floating-point comparisons. See
`ToastView.geometry.provenance.md`.

Countdown blocks run at 0.016 seconds in common run-loop modes and decrement by
`0.016 / duration`. The default plain/status duration is 2.5 seconds; the donation
reminder lasts 10 seconds. The stop button's long-press escape uses 3 seconds.
Pan clamping, the 60-point dismissal threshold, .25 dismissal opacity, tap-to-
rotate stack behavior, and the two-stage lift/return animation are implemented.

Selected original callback anchors include `001c0180`/`001c02b0` for progress
setup/completion, `001c05bc`/`001c0728` for status setup/delay, `001c0af0`/
`001c0bf4` for the wait presentation, `001c1864` for the persistent icon action,
and `001c269c`/`001c2ae0` for hide completion/queue continuation. Obfuscator return
values and `CallSupervisor` scaffolding around those bodies are not reproduced.

### PlayerToast and CustomHUD

PlayerToast preserves its singleton, compact/full constraint sets, styles,
label/image/progress switching, CALayer progress updates, presentation timing,
brightness lower-limit latch, and volume display registration/unregistration.
Compact/full height is 30/50 points; minimum width is 100/200; material corner
radius is 15/25; image size is 15/25; image-center leading offset is **20/35**.
Its shadow has radius 12, offset (0,2), and the raw float opacity **0.2**.

The percentage conversion in `updateToastText:value:` uses original `FCVTAS x24,d0` at `0x23c2a4` (`9e640018`), immediately after double multiplication by 100. It rounds to nearest with ties away from zero, saturates to signed 64-bit limits, and converts NaN to zero. The source applies `round` before the explicit saturating conversion. The separate conversion in `subLabelForVal:style:` remains truncating, as required by `FCVTZS x3,d0` at `0x23dd4c` (`9e780003`). Unrounded input still reaches the progress and event callbacks.

`tools/verify_presentation_runtime.py` pins those words directly in the raw original image. Its actual `PlayerToast` fixture compares label/icon arguments against newly compiled native FCVTAS for positive/negative ties, signed zero, NaN, infinities, signed-limit boundaries, and overflowing products. It verifies 0.125 → `13%` and -0.125 → `-13%`. The test failed on the previous truncating implementation (`.recovery-work/navigation-helpers-rounding-audit/presentation-red.txt`). The original image is never executed; the rounding fixture intercepts progress/event/icon boundaries to prevent UI and media side effects.


The speed-label boxing is resolved: the style-equals-one table entry leads to `0x23de64`. At `0x23de6c`, `FCVT s0,d0` narrows the input to float; `0x23de74` loads `numberWithFloat:` and `0x23de78` calls the NSNumber receiver. The returned object is retained in x20, copied to x3 at `0x23de9c`, and forwarded through `0x23fabc` to the adapter at `0x23faa0`. Its `STR x3,[sp]` at `0x23faa8` passes that object as the Darwin variadic argument to `NSString stringWithFormat:`. The verified UTF-16 format is `%@×`. The boxing wrappers at `0x23fa90` and `0x23fa80` only preserve the return address and call `objc_msgSend`; they do not transform the float. Thus the source now boxes `@((float)value)`, correcting the prior double box. No unknown formatter remains on this path.

The added actual-source fixture failed before this correction: `1.234567890123×` differed from the float-boxed `1.234568×`. It tests positive/negative fractions, float halfway values (1.0000000596046448 → `1×`), 16777217 narrowing to float 16777216 before Foundation formats it, signed zero, NaN, infinities, float overflow and underflow. Expected values use a newly compiled native FCVT instruction followed by the evidenced NSNumber and NSString APIs. Reports and red/green logs are in `.recovery-work/navigation-helpers-rounding-audit/player-format*`. Formatting still comes from the host Foundation implementation, as it does in the original; this does not promise identical Foundation formatting across different OS versions.

Decoded image names are `sun.min`, `sun.mid`, `sun.max`, `speed.slow`,
`speed.reg`, `speed.fast`, `vol.off`, `vol.low`, `vol.mid`, and `vol.max`.
The original gaps between 33.3/33.4 and 66.6/66.7 are retained rather than silently
interpolated. Speed-icon selection uses `roundf((float)(value * 10)) / 10`, with
the recovered 1.01 upper comparison. Style 1 is display-only here; the gesture/
player owner changes playback speed. Styles 0 and 2 perform real UIScreen and
MPVolumeController operations in production.

CustomHUD forwards float volume and audio-category access to the real private
MPVolumeController and registers itself with MPVolumeHUDController. Those
classes are dynamically looked up, not implemented or mocked in production.
The optional MPVolumeDisplaying protocol properties remain in the property
metadata without inventing additional original instance methods.

### BlurButton and DVNImageViewController

BlurButton's public factory is:

```objc
+ (instancetype)createButtonWithImage:(UIImage *)image
                               target:(id)target
                               action:(SEL)action
                                 menu:(UIMenu *)menu;
```

It creates a 28-by-28 button, a non-interactive style-16 blurred background with
radius 14, and an 18-by-18 image view. It either installs the target/action or
uses a primary-action UIMenu. Highlighting calls the superclass and changes the
image opacity to .25/1. This is the API communicated to the controls owner.

DVNImageViewController implements the transparent blurred viewer, navbar, three
real save/share/copy menu actions, strong menu captures, scroll delegate, 1-to-3
zoom range, double-tap zoom rectangle, content centering, and horizontal/vertical
inset formulas. The view uses real UIKit image saving, pasteboard and activity
presentation in production. The host tests replace those boundaries; they do
not touch the Photos library or system pasteboard. Original zero-dimension and
NaN arithmetic is preserved. The navbar's original `closeButtonTapped:` selector
also remains, although the class implements `closeButtonTapped` without a colon.
The focused UI verifier records that mismatch instead of silently repairing it.
See `DVNImageViewController.ui.provenance.md`.

### Sheet presenter and transition classes

The recovered section calculator is `25 + 40 * sectionCount + 50 * rowCount`;
the custom-height wrapper adds 20. The other wrappers preserve half-height and
explicit-height presentation. On iOS 15+, the original constant-height private
detent selector is used with identifier `dvntm`, a grabber and 15-point corner
radius. Only the OS availability check selects the iOS 14 custom presentation
path; there is no additional selector-availability fallback.

The height block receives `CGSize` and returns `CGFloat`; the recovered invokes
consume width/height in floating-point registers. Landscape uses the full
container height; portrait uses half or the captured explicit/custom height.
The transitioning delegate remains alive through the presentation call and is
then released. The original has no associated-object retention. Its height
block does not capture the presented controller.
PseudoDetentController owns a black-.5 dimming view, tap-to-dismiss gesture,
bottom-aligned frame, top-only rounded corners, transition callbacks, and
container-layout updates. Transition callbacks strongly retain their controller.
Nil coordinators receive normal nil messaging, and dismissal completion removes
the dimming view even for a cancelled transition. See `SheetLifecycle.provenance.md`.

## Host tests and what they do not prove

Run `python3 -B tools/verify_presentation_runtime.py`. It compiles the **actual
eleven production implementations** into a native test executable with
UndefinedBehaviorSanitizer and source-coverage instrumentation. UIKit, Core
Animation, Photos, networking, stock HUD, localization, and transport/converter
boundaries are replaced by files under `recovery/tests/presentation_*` and
`helpers_*` only. The production source has no test switches or mock host class
implementations. Downloads' separately recovered implementations are not
replaced in the production build; the helper tests double only their external
callback boundaries.

The fixture suite exercises state transitions, queue ordering, timer completion,
callback capture lifetimes, weak delegates/menu handlers, scene/key-window
behavior, recorded constraints, image zoom/insets, section/row heights,
brightness/volume forwarding, and media pipelines. It does **not** run a UIKit
layout solver or a real device animation/window server. Pixel-perfect UIKit
rendering, physical gesture delivery, actual Photos permission prompts, private
host behavior, audio output, and device rotation integration remain untested.

The first host attempt exposed Foundation's process-specific temporary-directory
resolution and macOS' transitively loaded Core Animation class names before any
fixture file writes. The final harness explicitly redirects the temp-directory
boundary, uses uniquely named animation/layout doubles, and supplies a fixture
bundle so no user localization/preferences store is consulted by these sources.

## Explicit differences and remaining uncertainty

* The original obfuscation, opaque branching scaffolding and SVC instructions are
  not reproduced. The code reconstructs the visible functional operations; it
  does not claim instruction equivalence or bypass the Runtime preference gates.
* The focused toast and sheet lifecycle audits removed added generation guards,
  weak timer/transition captures, absent-scene retry, persistent sheet-delegate
  retention and cancellation/nil-coordinator fallbacks where original evidence
  contradicted them. `PlayerToast.lifecycle.provenance.md` also records its
  original source-window reads and floating-point progress clamping. Subsequent
  image-viewer, geometry and window audits restored strong menu captures,
  original arithmetic and getter order, ancestor traversal and application-window
  lookup. Their separate provenance files and regression fixtures describe the
  tested scope; none establishes device rendering or live host behavior.
* Private YouTube and MediaPlayer classes and the bundle category are genuine
  runtime dependencies. Their availability cannot be proved by a host double.
  There is no production mock class to force a full-tweak link. The shared build
  system and other workers' files were not changed.

## Selected guarded instruction records

| Original interval | Verified instruction SHA-256 |
| --- | --- |
| `1c8690..1c87f8` ToastWindow ancestors | `a08fde73b28cf9df9d0cafd5a6715f0e66cd88662e0f7b335da7b91309625a67` |
| `1c87f8..1c8b10` ToastWindow allowlist/root exclusion | `11f00d6bddab54e01457026113d70992969b535afa69e321ec599feb991b63af` |
| `1ef820..1ef91c` sheet calculator prefix | `e676477438b364b3d1f72ca096295b364b1386a8899e39911ad1e419ee4823d7` |
| `1ef91c..1efae4` sheet calculator row loop | `59c0d2594f3c8ca6b04e9d91a3ba0f73f5b829399b303d820833200400299689` |
| `23d334..23d460` player speed threshold | `d080b17c29af7a7dd573f52bf9a366e5cc94c196745ba8984585d9a64113f946` |
| `23da54..23dc30` player volume thresholds | `f06f8a85cabf3d52cfc6f941a5e9d11288f21c61254866eb138b8a088d51729b` |
| `23c774..23c7cc` player hide completion | `94eddae8359d316b2ce88b8db729433c7a498b7ac0a31490e6846f475ddf25dd` |
| `23e0ec..23e19c` brightness lower-limit latch | `1cb8c52e354f9fe805c44cf9bf035edc6ed3068baf20f649b7ac9b8319785561` |
