# YTLHelper reconstruction

## Complete class surface and ownership

`YTLHelper.h/.m` implements the supplied 22-method class, including its ARC
destructor, conforming to the actual `Downloads/DownloaderDelegate.h`. Its
thirteen ivars, their order/encodings/offsets, class instance size, method
encodings, and protocol-derived property records are compared directly with
`arm-classes.json` and `ivars.json` by
`tools/verify_presentation_sources.py`. Both arm64 and arm64e iOS 14 targets
compile strictly against SDK 26.2 and match the supplied metadata.

The main evidence range is the class beginning at `22b24c` and ending with its
ARC destructor at `231d78`, plus separately exported anonymous callback bodies.
`recovery/classes/YTLHelper.c` is evidence only, not a build input. The source
imports the actual `Downloads/YTPDownloader.h` and `Downloads/FFMpegHelper.h`.
No production downloader, Photos, media codec, application preference, or host
UI mock is supplied in this directory.

Original read-only image SHA-256:

```
bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca
```

`tools/verify_presentation_evidence.py` hash-checks that image and applies the
provided decoded-byte initializer in memory before interpreting its strings.
Selected original instructions are checked word-for-word. It does not execute
the image, load a deb, or audit the original function-start table.

## Transport, conversion and callbacks

The title sanitizer removes the original `/\\?*|"<>` characters and joins the
remaining components with the **empty string**, not an underscore. Intermediate
transport filenames are based on the video ID: `id_v.mp4` and `id_a.m4a` beneath
the operation's temporary `id` directory. Final names use the sanitized title
and requested video extension, or `.m4a` for audio.

Duration is **ceiling(milliseconds / 1000)** after conversion to double. Fresh
instructions show `UCVTF`, floating division, then `FCVTPU` in both entry paths.
The decompiler's apparent truncating integer conversion was not retained.

Video download starts the video phase with its own advertised unsigned size,
then stores the completed video URL and invokes the existing audio phase using
the recovered all-nil/zero sentinel arguments. Those sentinel arguments do not
erase the previously captured audio URL, size, title, ID, captions or duration.
A standalone audio job initializes that same second-phase state. Each phase has
a fresh real YTPDownloader with the helper as delegate.

Progress callbacks retain the original float progress scalar and construct the
phase-specific localized percentage label. Stop completion cancels the current
downloader. The copied stop block intentionally retains the helper while an
operation is active, so replacement of the application root's helper does not
drop an earlier job. Original toast cleanup preserves that callback. The host
test checks this retention and explicitly clears the callback during fixture
teardown; production cleanup does not break the operation-retention cycle.

Audio completion invokes the actual FFMpegHelper `cutAudio:duration:completion:`;
video completion invokes `mergeVideo:withAudio:captions:duration:completion:`.
The callback arguments are a resulting URL and NSError. The original input
URLs, captions URL, and ceiling duration are forwarded; no fake file is reported
as a successfully converted production asset.

Converter errors remove the returned partial output URL and report the error.
Successful results are moved to the final title-based URL. Move failures report
the recovered `Error.PathIssue` feedback. Audio always opens sharing. Video
uses `postDownloadIndex`: 0 saves, 1 shares, and other values ask. The preference
is read through `ytpInt`, declared in `Runtime/YTLBootstrapCrypto.h`.
The selected build's existing `YTLFeaturePolicy.m` reads local preferences
directly. Historical account/bootstrap behavior is a documented build difference.

Intermediate cleanup preserves the actual call sites: video cleanup requests
`_v.mp4`, `_a.m4a`, `_a.ytpmap`, `_a.ytpmap`. The repeated audio map rather than a
video map is present in the verified original instructions. Terminal cleanup
removes the owned per-video directory, including remaining sidecars.

## Actual media and presentation operations

`saveMedia:` routes `.m4a` files directly to sharing. Video saving uses a real
PHPhotoLibrary change transaction and PHAssetCreationRequest video resource
with the completed file URL. Photos success dispatches to main, cleans the
operation directory, and reports `Saved`. **Photos failure falls back to the
share controller without destroying the output.**

`shareMedia:` presents a real UIActivityViewController with the file URL,
excludes AssignToContact and Print, and anchors its popover to the presenter's
view at the screen's horizontal midpoint and bottom edge. Its activity
completion cleans the operation directory on both success and cancellation.
The focused media audit restored synchronous presentation, four popover getter
calls, separate screen width/height reads and original nil handling. See
`YTLHelper.media.provenance.md` for the instruction anchors and regression proof.

`askForAction:` synchronously constructs the actual host sheet and save/share actions with
copied URL/helper captures. The source anchor is the application's root pivot
view, and the presentation remains through the original host controller API.
`HelpersHost.h` contains declarations only, not implementations of those host
classes.

`downloadImageFromURL:download:` rewrites the suffix starting with `c-fcrop` to
`nd-v1`, starts a real URL-session task, and preserves the data/error callback
branches. With `download:NO`, data is decoded to UIImage and copied to the
pasteboard on main; it does **not** open an image viewer. With `download:YES`,
the original raw data is submitted as a Photos image resource. Success and
failure feedback is dispatched to main. Downloads' separate image-viewer path
uses the reconstructed `Presentation/DVNImageViewController` directly.
The image audit restored separate contains/range checks and the original nil
session input path. See `YTLHelper.image.provenance.md` for callback evidence and
the synthetic URL-session tests.

Rendering methods use real UIGraphics renderers/contexts and CALayer drawing.
The instance resize variant applies the recovered label-color alpha
`0.699999988079071`; the class resize variant does not tint. Both preserve
aspect-fit drawing inside the requested square. The instance named action image
is rendered at 24-by-24 and returned in template mode. Host/tweak named image
lookups use the real YTAssetLoader with the respective bundle. Layer-image
completion is synchronous and receives the rendered UIImage.
The rendering audit restored direct dimension forwarding and three separate
layer-frame reads. See `YTLHelper.rendering.provenance.md` for the original
instructions and bitmap fixture. Invalid dimensions are observed at a synthetic
renderer boundary without allocating an invalid bitmap.

The host-button factories preserve a 40-by-40 default or explicit CGSize,
accessibility text, image-versus-title handling, target/selector callback,
white tint and the host's new touch feedback. Overlay buttons are 24-by-36,
template-rendered, and expand circular white feedback by 6 points horizontally.
Wi-Fi detection retains the original reachable/non-WWAN bitmask contract and
does not silently add a different connectivity policy.

## Tests, commands and explicit missing bits

The final reports are:

* `.recovery-work/presentation-helpers/source-verification.json`
* `.recovery-work/presentation-helpers/runtime-verification.json`
* `.recovery-work/presentation-helpers/native/runtime.log`
* `.recovery-work/presentation-helpers/native/coverage.json`

Run the owned tools with `python3 -B tools/verify_presentation_sources.py` and
`python3 -B tools/verify_presentation_runtime.py`. Both runners place compiler
`CFFIXED_USER_HOME`, temporary files, module caches, generated objects, native executables,
profiles, and reports under `.recovery-work/presentation-helpers/`.

The native suite compiles this actual implementation with test-only transport,
converter, UI, Photos, URL-session, bundle/preferences and volume/brightness
boundaries. Filesystem transformations use synthetic text bytes, not real media,
under the owned fixture directory. No original dylib or deb is executed.
The suite covers both download phases, filename/duration transformations,
progress/error/stop callbacks, converter error/move-error/success branches,
Save/Share/Ask and unknown-preference routing, Photos success/failure, share
cancellation cleanup, image-copy/photo-save/error callbacks, rendering call
contracts, button dimensions/feedback, and the Wi-Fi flags.

Explicit limitations/differences:

* The original SVC/obfuscation machinery is not reconstructed. The functional
  operations and complete class ABI are; the original instruction stream is not.
* File-component validation rejects invalid directory IDs/extensions before
  invoking a transport or removing a directory. These checks are
  reconstruction additions, not claims about original malformed-input behavior.
* Real Photos permission prompts/import, ffmpeg conversion, remote transfer,
  UIKit pixels/layout/gesture timing, host sheet integration, and actual device
  audio/brightness behavior were **not** exercised. Their production calls are
  implemented, but the native results establish host-boundary behavior only.
* No shared Makefile or other worker's code was changed, and no production mock
  classes were added to force a full-tweak link. Header declarations in older
  root `Recovered/` copies or Downloads compatibility headers must not be
  imported alongside duplicate canonical interfaces in one translation unit.

No declared YTLHelper method is intentionally unimplemented. Remaining device/
host integration and original-obfuscator equivalence are recorded as unverified,
not hidden by deleting selectors.

## Selected guarded original instruction intervals

| Interval | Verified instruction SHA-256 |
| --- | --- |
| `22b6d4..22b7b4` title/duration preparation | `76e76171346bde6c9d9b7e1fd4b325b39bd5962eac7c7fe3316d5670ac627e82` |
| `22bcd4..22bcf4` audio duration rounding | `81ae8d82f059bb6916ff467fa90913c51e7773dcd287dee0568934ba58530066` |
| `22c7f4..22c974` converter dispatch | `97d596c2df687add7c44aeda924ba25cf2320158756d690709728d4d2288f4e4` |
| `22cd30..22d0b4` audio conversion completion | `70e8a4ffddfd5d31b66b811de7cd3fe757011d12ea028d337193db77d540c27b` |
| `22d66c..22dcbc` video routing/sidecars | `80fc821959dda4df047903c176834a9925881424538ae407a662274545f86586` |
| `22e338..22e3d0` Photos success | `b598ab3dd95655dc8a08a5f8553828570bf7e46acadac25ef3ea383c0911bf65` |
| `22e468..22e4ac` Photos failure share fallback | `ce120074cb4a93a94e2381b26ca50bf3f964303ea45e3cbd37ca29c4b5cec343` |
