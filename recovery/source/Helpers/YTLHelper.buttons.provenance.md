# First-package button factories

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
It corrects three reconstruction differences in `YTLHelper.m`.

The default-size factory starts at `0x22f94c`. It sends `class` to its receiver
at `0x22f9ac`, then invokes the sized factory on that result at `0x22f9d8`,
forwarding the original objects and selector and a 40-by-40 size. The source
now uses `[[self class] createYTQTMButton:...]`. The previous direct `self`
dispatch skipped the class message. Tests cover a redirected class and a nil
class result.

The sized factory at `0x22fa24` calls the host's `iconButton`, sets its
accessibility label, enables touch feedback, then branches on the original
icon. It sets an image for normal state when nonnil, otherwise sets the title
and enables font-size adjustment. It applies white tint, disables autoresizing
mask translation, adds the target/action for event `0x40`, and activates the
width and height constraints in that order. Inspection confirms the existing
source's call sequence for this method.

The overlay factory at `0x22fdf8` constructs its host button directly, rather
than dispatching through the sized helper. It sets accessibility and enables
feedback before testing the original icon at `0x22ffd0`. A nonnil icon enters
template conversion at `0x230014`, then `setImage:forState:` at `0x230038`,
even if conversion returns nil. The reconstruction previously transformed the
icon before creating the button and allowed a nil conversion to take the title
branch. The source now preserves the original order and branch.

After applying the same common button settings and 24-by-36 constraints, the
overlay reads `touchFeedbackView` at `0x2301c8`, `0x2301f8`, and `0x23024c`.
It sends the circular flag to the first returned object, insets `(0,-6,0,-6)`
to the second, and white color to the third. The final color getter at
`0x230234` precedes the third feedback lookup. The source previously cached
one feedback object; it now performs the original three reads.

`helper_button_runtime.m` executes the actual source with a host button factory,
an image-conversion probe, and three distinct feedback objects. It covers nil
original icon, nil conversion output, successful conversion, avoidance of an
overridden sized helper, dispatch identity, and color/getter ordering. The
previous source failed the class-dispatch regression. The 43 focused checks now
pass; the previous source and failure report are in
`.recovery-work/helper-buttons/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --buttons
```

The focused verifier checks the first archive's hash, method addresses, raw
instruction spans and call wrappers, decoded host class names, selector
references, and both icon branch tables. It then accepts only current runtime
and ABI reports. Evidence is `recovery/evidence/first-helper-buttons-fidelity.json`;
the report is `.recovery-work/helper-buttons/report.json`.

The image-loader methods at `0x22f4c0` and `0x22f6b4` were also inspected. They
allocate the host loader before reading their respective bundle, initialize it
with that bundle, and forward the image name, consistent with existing source.
Those methods are outside the new focused verifier's scope. Device rendering
and the real private host classes remain untested. No original binary is run.
