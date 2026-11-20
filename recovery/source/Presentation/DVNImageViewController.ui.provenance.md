# DVNImageViewController UI fidelity

The whole production class now restores the ordinary UI differences established
in `recovery/tests/image_viewer_audit.md`. That audit remains a dated comparison
against the preceding source; its "current reconstruction" column describes
the pre-fix snapshot, not this implementation.

Three menu blocks capture the controller strongly, using original invokes
`0x2206f8`, `0x220798`, and `0x2207ec`. Descriptor `0x1061780` has size 40 and
retain/release helpers `0x150e8`/`0x15118`, with self at offset 32. Copy/save
read the current image once after haptic feedback. Save forwards nil unchanged
to the Photos boundary; share obtains `self.fullImage` after allocating the
activity controller and constructs the original one-element array. The original
can therefore fail at Foundation array construction for nil rather than return.

Aspect geometry (`0x221358`) reads image/size separately for width and height,
without rejecting zero, negative, or nil dimensions. It preserves horizontal
selection for unordered comparison. Horizontal/vertical helpers (`0x221458`,
`0x22156c`) read frame again only on the smaller-image correction branch.
Double tap (`0x221160`) reuses the second maximum-scale result, obtained before
bounds, for both dimensions. Layout (`0x221058`) retains the supported strictly
negative clamp, including preservation of NaN and negative zero.

Share (`0x221730`) retains the original popover predicate. The nonnil path reads
popover four times total, reads screen/bounds twice for width then height, and
sets source view, `(width / 2, height, 0, 0)`, and arrows 15. The nil path skips
view/screen access and still presents. The shared generic anchoring helper is
unchanged; this method expresses its own original sequence.

Navbar setup (`0x21fae4`) repeats navigation lookups, constructs both items and
all menu actions before assigning left then right. It preserves the packaged
`closeButtonTapped:` target selector, loaded at `0x22021c`. The packaged class
declares only `closeButtonTapped` (`0x2216d8`, `v16@0:8`). No extra method was
invented to repair this mismatch. The local warning suppression is scoped to
that expression. The fixture proves a normal receiver rejects the colon
selector while direct invocation of the declared method performs haptic and
dismissal. A host superclass/category could affect dispatch; that is outside
this class's recovered contract.

Viewer setup (`0x220864`) restores effect-before-view construction, concrete
scroll/image alloc-init, maximum-before-minimum zoom setters, autoresizing flag
before image content mode, getter-based image assignment, and immediate
activation of each of the eight constraints in original order. The existing
medium haptic helper matches `0x221680` and remains canonical.

## Verification

Run `python3 recovery/tools/verify_image_viewer_ui.py` from the repository root.
The verifier pins all 18 packaged methods plus three action invokes and two
capture helpers (23 spans), eight data records, three selector strings, and
four resolved branch tables. Its evidence is
`recovery/tests/image_viewer_ui_evidence.json`; the report is
`.recovery-work/image-viewer-ui/report.json`.

The independent fixture compiles the whole actual `DVNImageViewController.m`,
with unique copied and extended UIKit doubles. It passes **150 assertions** in
six fresh process modes: menu 24, navbar 12, share 16, geometry 38, setup 49,
base methods/ownership 11. The original five regression modes all failed on
pre-fix source; their outputs are in `.recovery-work/image-viewer-ui/red.json`.
The iOS compiler confirms all 18 method encodings, five metadata properties,
and three relative ivar layouts. The runtime executable uses UBSan.

The fixture checks each retained menu handler separately, the original menu
ownership cycle, strong image property and all three ivar releases, nil and
nonnil save/copy, getter-based sharing, the nil-array exception, changing
popover/screen/image/frame/zoom getters, supported predicates and NaN/-0
behavior, exact constraint relationships and activation order, haptic calls,
and direct/target-action close behavior. It executes no real Photos,
pasteboard, network, URL, or presentation operation. It does not load the
supplied dylib. UIKit acceptance of nil/NaN arguments and on-device rendering
are not established by these boundary tests.

## Shared integration needed

No shared fixtures, manifests, headers, or build files were edited. The shared
presentation test still expects a zero horizontal inset for a zero-size image;
the original now yields NaN on left/right and zero on top/bottom. Its old weak
menu expectation must also be replaced with original strong ownership (clear
the navbar item for fixture teardown, then release the externally retained
menu). Shared presentation provenance should retire the weak-menu and geometry
guard additions and link this result. Hashes/inventories should be refreshed by
their owner after those shared test edits.
