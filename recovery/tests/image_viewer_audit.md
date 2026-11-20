# DVNImageViewController ordinary UI fidelity audit

This is a read-only comparison of the recovered source against the supplied ARM
package. No production or shared test files were changed. The original dylib was
not executed. This pass did not inspect authentication, permission enforcement,
or filesystem validation. The Photos, pasteboard, and presentation calls below
are ordinary UI call boundaries; subsequent tests must intercept them.

The evidence JSON pins 13 complete original method/callback/helper spans, eight
data records, three selectors, four resolved branch tables, and the four source
files as they existed at audit time. Binary SHA-256:
`bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`.
This is evidence for specific discrepancies, not a claim that the entire class
has received behavioral runtime proof.

## Confirmed differences

| Area | Packaged behavior | Current reconstruction |
| --- | --- | --- |
| All three menu handlers | Strong controller capture at block offset 32 | Shared weak capture, promoted on invocation |
| Save handler | Haptic, one `fullImage` getter, unconditional Photos call with that result | Nil guard and a second getter when nonnil |
| Share method | Allocates activity controller, obtains `self.fullImage`, constructs one-element array without a nil guard | Returns for nil `_fullImage`; uses ivar directly |
| Aspect geometry | Two image/size getter pairs, then division and axis selection without dimension validation | One getter pair; nonpositive width/height sets zero insets and returns |
| Popover | Checks first popover result; only when nonnil obtains view/screen and sets anchor | Shared helper obtains view/screen even for nil popover |
| Close button action | Passes `closeButtonTapped:` despite the class declaring only `closeButtonTapped` | Passes the no-colon selector |

### Menu ownership and nil image behavior

`setupNavbar` stores self directly into three stack blocks at `0x22031c`,
`0x2203fc`, and `0x2204d0`. The invokes are copy `0x2206f8`, share `0x220798`,
and save `0x2207ec`. Each uses descriptor `0x1061780`: reserved 0, size 40,
copy helper `0x150e8`, dispose helper `0x15118`, signature `0xb9b0ec`.
The copy helper loads `[source + 32]` at `0x150f0` and calls `_objc_retain`
at `0x150f4`; dispose loads `[block + 32]` at `0x15120` and calls
`_objc_release` at `0x15124`. There is no weak indirection.

Copy invokes `hapticFeedback`, reads `fullImage` once, then obtains the general
pasteboard and sets its image (`0x220714`, `0x220724`, `0x220744`, `0x220760`).
Share invokes haptic then `share` (`0x2207b4`, `0x2207c4`). Save invokes haptic,
reads `fullImage` exactly once, and forwards that result unconditionally with
three null completion arguments (`0x220808`, `0x220818`, `0x220834`). The
original does not protect these calls from a nil image. This does not establish
what a particular UIKit/Photos release does with nil; only forwarding is proven.

`share` allocates at `0x221778`, reads `self.fullImage` at `0x22178c`, and calls
`arrayWithObjects:count:` with count 1 at `0x2217bc`. No intervening image test
exists. An offline Foundation test can observe the nil-element exception and a
subclass getter returning an image different from the ivar.

### Geometry and retained predicates

`adjustScrollViewInsets` reads image/size for width at `0x22138c`/`0x2213a8`
and again for height at `0x2213c0`/`0x2213d4`. It divides width by height at
`0x2213f0`, reads frame once, divides frame width by the aspect at `0x2213f8`,
and computes aspect times frame height at `0x2213fc`. No nonpositive/zero/nil
guard exists. The original `FCMP` + `FCSEL HI` / `CSEL HI` (`0x221400` through
`0x221418`) selects horizontal for greater **or unordered**, vertical otherwise.
Selector refs `0x114e6c8` and `0x114e6c0` confirm the axis mapping. The current
finite axis predicate is consistent; the added dimension guard is not. Nil
image size or zero dimensions can therefore propagate NaNs instead of forcing
zero insets. This audit does not assert that UIKit accepts those values.

The horizontal/vertical correction when fitted size is smaller than viewport
is genuine: `FCMP frameDimension, fittedDimension` + `CSET GT` at `0x2214bc`
and `0x2215d0`. Tables resolve to skip/correct at
`0x2214fc`/`0x221500` and `0x221610`/`0x221614`. The current helper has the
same ordinary finite formula, but caches the first frame dimension. The
original calls `frame` again on the correction branch (`0x221508`, `0x22161c`)
and uses the new value. A changing frame getter distinguishes the sources.

Layout's nonnegative offset clamp is genuine. `0x221108` through `0x221118`
uses `FCSEL ... MI`: strictly negative becomes +0; zero (including -0) and
unordered pass through. The locally installed Foundation `MAX` macro uses
`a < b ? b : a`, so the present `MAX(offset, 0)` preserves these outcomes.
Do not replace this with `fmax` or a greater-than conditional. Content-size and
bounds getters are each called twice, which the current source also expresses.

Double tap's equality test is genuine (`0x2211c8` and table branch `0x221204`).
Equal selects minimum scale at `0x221208`; unequal, including unordered, selects
zoom rect at `0x221234`. There is no zero-maximum guard. The original obtains
the maximum once for comparison and once more after the gesture location,
**before** reading bounds; it uses that second maximum for both divisions
(`0x221260` through `0x22127c`). Current source reads bounds first, then reads
the maximum independently for width and height. Changing getters expose this
additional difference.

### Popover predicate and source evaluation

The branch at `0x2218b0`, table `0x11ce380`, key `0x11ce390`, xor
`0xca7c3174` resolves condition `popover == nil` to false `0x2218b4` (anchor)
and true `0x2219e8` (present directly). This is a supported nil guard.
On the anchor path there are four popover getters in total: predicate, source
view setter, source rect setter, arrow setter. Screen/bounds are each read twice;
the first supplies width and the second height (`0x221938`, `0x221964`). The
rectangle is `(width * 0.5, height, 0, 0)` and arrows 15. The current helper
caches one popover and one screen size. Exclusion order (assign-to-contact,
print), animated presentation, and nil completion match the package.

### Additional setup differences encountered within the UI audit

The original selector ref `0x114e610` points to string `0xf2c8d6`, exactly
`closeButtonTapped:`. It is loaded into the action argument at `0x22021c` and
forwarded at `0x22023c`. The packaged method inventory has only
`-closeButtonTapped` at `0x2216d8`, encoding `v16@0:8`. This mismatch is an
original selector quirk, not evidence for inventing a missing colon method.

Navbar retrieval repeats navigationController/navigationBar for the three bar
operations. The current source caches one bar. The original installs the left
item at `0x22063c`, after constructing both items and all actions; the current
source installs it before actions. Right item follows left in both versions.

`setupViewer` creates the blur effect before allocating its effect view. It
uses alloc/init for scroll view (`0x2209f0`) and image view (`0x220ae0`), sets
maximum before minimum zoom (`0x220a1c`, `0x220a30`), sets the image view's
translates-autoresizing flag before content mode, then obtains `self.fullImage`
and calls `setImage:` (`0x220b2c`, `0x220b4c`). Current source uses scroll-view
`new`, image-view `initWithImage:_fullImage`, and reverses those setup orders.
The eight equivalent anchor relationships are each activated immediately in
the original (`0x220c38`, `0x220ccc`, `0x220d60`, `0x220df4`, `0x220e74`,
`0x220eec`, `0x220f64`, `0x220fdc`); current source batches activation at end.
These are confirmed construction/observation differences, without a claim that
normal UIKit geometry differs when all getters are stable.

## Suggested subsequent proof

Execute the whole actual class with isolated UIKit doubles. Retain each menu
handler independently, release the caller's controller, invoke, then release
the handler and check deallocation. Intercept nil and nonnil save/copy calls;
exercise share's nil-array exception and overridden getter. Use alternating
image size/frame/maximum zoom/screen/popover getters to prove evaluation count
and order. Test aspect NaN/zero/negative values at mocked setters, supported
clamps and equality branches, nil/non-nil popover, exact close selector, and
sequential constraint activation. No real presentation or library writes are
needed. Production edits and these runtime regressions remain pending.

## Reproduce evidence checks

From the repository root, the scratch read-only validator is:
`python3 .recovery-work/image-viewer-audit/verify.py`.
To independently regenerate raw annotations, run
`python3 recovery/tools/inspect_binary.py START END --all` for each JSON span.
`python3 recovery/tools/class_contract.py DVNImageViewController` confirms the
18-method ABI inventory and the no-colon close method. No ABI rerun is required
for this read-only pass because no source was changed.
