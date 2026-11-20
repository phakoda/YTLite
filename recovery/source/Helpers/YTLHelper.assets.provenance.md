# First-package helper assets and rendering

This audit compares the actual reconstructed source with the first supplied
`com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`. Its dylib SHA-256 is
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
The source already matches the inspected calls and branches; this audit adds
direct first-package evidence and runtime coverage without changing production
behavior.

## Asset loaders

`+YTImageNamed:` at `0x22f4c0` decodes `YTAssetLoader`, resolves the class at
`0x22f620`, allocates it at `0x22f624`, obtains `NSBundle.mainBundle` at
`0x22f63c`, initializes at `0x22f65c`, and sends `imageNamed:` to the initializer's
result at `0x22f67c`. `+YTLImageNamed:` at `0x22f6b4` follows the same sequence
with resolution at `0x22f824`, allocation at `0x22f828`, `ytl_defaultBundle` at
`0x22f840`, initialization at `0x22f860`, and lookup at `0x22f880`.
Neither sequence branches on the name, allocation, bundle, initializer or image
result. Bundle lookup still occurs when allocation returns nil.

The synthetic host fixture exercises both factories with an ordinary input,
nil name, nil bundle, nil allocation, nil initializer, nil image and a replacement
instance returned by initialization. It records call order and checks object
identity at each boundary. Its test-only allocation override belongs to
`YTAssetLoader`; it does not replace the inherited `NSObject` implementation.
Class resolution occurs through the actual source's `NSClassFromString` call.
The host class is present in this fixture; an absent host class is not simulated.

## Image callbacks

Instance `-resizeImage:toSize:` at `0x22ef58` allocates and initializes a square
renderer, then invokes the callback at `0x22f038`. That callback creates a square
container and an image view, sets aspect-fit mode 1 and clipping, obtains
`labelColor`, applies alpha `0.699999988079071`, assigns the container bounds to
the image-view frame, inserts the view, and draws the container layer using the
renderer context. The alpha's original double is stored at `0xb9aa30`.

Class `+resizeImage:toSize:` at `0x231388` invokes its callback at `0x231468`.
It follows the same drawing sequence without tinting. Both methods return the
renderer result directly. The verifier qualifies method records by class or
instance kind so these two identically named selectors cannot overwrite one
another during verification.

`-imageNamed:` at `0x22f20c` uses a 24-by-24 renderer. Its callback at `0x22f300`
loads the captured name from `ytl_defaultBundle` with nil traits at `0x22f36c`,
then creates and draws the aspect-fit, clipped image view without tinting.
After rendering returns, `0x22f2b8` sends `imageWithRenderingMode:` with value 2
to that result. It forwards the template conversion result, including nil.

The new tests execute all three actual source callbacks through a bounded
synthetic renderer. They inspect image-view state before insertion, the populated
container layer at rendering, dimensions and result identity. Cases include nil
input images, nil renderer results, nil template results and nil names. The new
loader and callback suite contains 212 assertions.

## Layer geometry

`+genImageFromLayer:backgroundColor:completionHandler:` at `0x2311f0` reads
the first frame at `0x231248`, starts the context at `0x23125c` with opaque false
and scale zero, and obtains the context at `0x231260`. After setting fill color,
separate frame reads at `0x23129c` and `0x2312ac` supply fill width and height.
It fills at `0x2312c0`, renders at `0x2312d4`, retrieves the image at `0x2312e0`,
and ends the context at `0x2312f0`. The decoded completion branch at `0x231330`
selects invocation at `0x231334` or cleanup at `0x231344` for a nil block.

The existing 31 rendering assertions now also have direct first-package
instruction evidence. They verify dimension forwarding for zero, negative,
non-finite and ordinary sizes at the synthetic boundary, plus three distinct
frame reads and a bounded bitmap's fill dimensions. These 31 assertions are
reported separately from the 212 new checks and are not counted twice in the
shared suite.

## Verification and limits

`recovery/evidence/first-helper-assets-fidelity.json` pins twelve raw byte
intervals, both decoded class strings, 23 selector references, the completion
branch table and six class/instance-qualified methods. The verifier checks the
supplied archive's hash, these original bytes, and current source, fixture,
runtime and ABI report hashes.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --assets
```

The original system traps at `0x22f1f4`, `0x22f4a8`, `0x231368` and `0x2315c0`
remain excluded. This audit does not establish their behavior or exact ARC
release timing. UIKit, the host asset loader and bundle lookup are synthetic
boundaries; device rendering, appearance propagation and missing-class behavior
remain unverified. No supplied dylib is loaded or executed.
