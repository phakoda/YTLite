# Helper rendering fidelity

The class and instance `resizeImage:toSize:` methods at `0x231b28` and
`0x22f724` pass the requested square dimensions directly to
`UIGraphicsImageRenderer`. Their original methods have no finite or positive-size
guard. The instance renderer callback at `0x22f804` tints the aspect-fit image;
the class callback at `0x231c08` does not.

`genImageFromLayer:backgroundColor:completionHandler:` at `0x231990` reads
`frame` three times. The call at `0x2319e8` supplies the context dimensions.
The calls at `0x231a3c` and `0x231a4c` supply fill width and height separately.
It sets the fill color, fills, renders, retrieves the image and ends the context
without additional geometry or null-context guards. The nil-completion branch
at `0x231ad0` is genuine and remains after rendering.

`recovery/evidence/helper-rendering-fidelity.json` pins five complete original
intervals, the completion branch table and selector references. The actual-source
fixture returns a test image from the synthetic renderer for zero, negative,
NaN, infinite and ordinary dimensions. This checks forwarding without allocating
an invalid bitmap or making a claim about UIKit accepting those dimensions.

A layer double returns a different frame on each read. The test checks the
first frame's image size and examines pixels of the bounded Core Graphics bitmap
to verify that the fill uses the second width and third height. It also checks
rendering before synchronous completion and rendering with a nil completion.

The preceding implementation fails the renderer-forwarding test. The source,
failed report and output are retained under `.recovery-work/helper-rendering/before-*`.
Run the shared runtime and iOS ABI checks, then verify the pinned evidence:

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_helper_media.py --rendering
```

The fixture executes reconstructed source with synthetic UIKit objects and a
bounded local bitmap. It never loads the packaged dylib. Actual device rendering,
invalid UIKit input behavior and live host integration remain untested.
