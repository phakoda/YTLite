# First-package image download and feedback

This audit uses the first supplied
`com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`, whose dylib SHA-256 is
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
The current reconstructed URL transformation and callbacks agree with the
inspected logic. No production change was needed.

## URL and response paths

`+downloadImageFromURL:download:` starts at `0x2302b0`. The absolute-string
read at `0x230454` precedes the `c-fcrop` contains test at `0x230474`. False
preserves the original URL object at `0x2304a4`. True reads the range at
`0x2304c8`; a missing range selects nil at `0x230584`. Otherwise it extracts
the suffix, replaces it with `nd-v1`, and calls `URLWithString:` at `0x230568`.
All paths reach shared-session lookup, task creation and resume at `0x230598`,
`0x2305e8` and `0x230600`.

The response callback at `0x23065c` tests data presence before the captured
download flag. Missing data queues network feedback at `0x230804`. Nonnil data,
including zero-length data, enters Photos immediately when download is true;
false queues copying at `0x230858`. The copy callback at `0x230d8c` is also
covered by the separate first-package ordering audit.

The Photos changes callback at `0x2308ac` obtains a creation request at
`0x2308cc` and forwards resource type 1, the original raw data and nil options
at `0x2308f0`. A nil creation-request result is not replaced with a fallback.

## Feedback and ownership

Photos completion at `0x230904` retains the supplied error and copies it with
the success byte into a main-queue callback at `0x23096c`. The queued callback
at `0x2309a8` selects success at `0x230bc8` or failure at `0x230c18`.
Success localizes `Saved` and does not read the error description. Failure
localizes the format `%@: %@`, independently obtains another bundle to localize
`Error`, then reads the captured error's description at `0x230cb8`. The final
toast receives the original success flag.

Network feedback at `0x230f88` instead uses a literal `%@: %@` format. It
localizes `Error` at `0x231130`, then reads the captured description at
`0x23114c`, and reports failure at `0x23119c`. Both failure paths preserve
normal Foundation formatting for a nil description.

The new 166-assertion fixture replaces localization with distinct bundle objects
and a positional format string. It changes the error description during prefix
localization, exposing premature description reads. It exercises both download
flags on network failure, Photos success/failure with nil or nonnil errors,
empty and nonempty raw data, nil creation requests and queued feedback timing.

The fixture also drops transport/input owners and observes weak references.
The Photos changes block retains raw data, while the Photos completion does not.
Queued network and Photos feedback retain their errors until completion,
including Photos success when the description is never accessed. The original
one-object descriptors at `0x10613d0` and `0x1061d30` use the retain/release
helpers at `0x14b8c` and `0x14bbc`. The Photos completion block at `0x10631e0`
has no captured input data. These probes test ownership across callback
boundaries, not exact ARC instruction timing.

## Evidence verification

`first-helper-imageflow-fidelity.json` pins twelve original intervals, eight
decoded strings, five functional branch tables, the method address and 21
selector references. Each selector is tied to its adjacent ADRP/LDR instruction
pair inside a pinned interval. The verifier decodes the original instruction
words to calculate the reference address before checking its selector name.

The older arm-package image evidence listed unrelated `player` and
`constraintEqualToAnchor:` selectors. Those checks did not substantiate the URL
replacement/factory calls. They are corrected to `stringByReplacingOccurrencesOfString:withString:`
at reference `0x114b2c0`, loaded at `0x230cc0`, and `URLWithString:` at reference
`0x114b3d0`, loaded at `0x230cf8`. Both now require instruction-pair verification.
A negative check substituting the former unrelated URL selector was rejected.
The original interval hashes are unchanged.

The existing 27 URL/routing assertions now also have direct first-package
evidence. They remain separate from the 166 new assertions and are not counted
twice in the shared suite.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --imageflow
python3 recovery/tools/verify_helper_media.py --image
```

Network, Photos, bundle and clipboard boundaries are synthetic. No supplied
dylib, real request, Photos import or system clipboard operation is executed.
Original system traps remain excluded. This audit does not establish native
framework behavior for invalid inputs or whole-tweak/device parity.
