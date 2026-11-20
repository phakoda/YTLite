# First-package helper media routing and ownership

This audit uses the first supplied
`com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`, with dylib SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
The inspected routing and callback captures agree with the current recovered
source. No production change was needed in this audit.

## Saving and Photos callbacks

`-saveMedia:` starts at `0x22d744`. It reads the URL extension at `0x22d844`
and compares it with the decoded `m4a` string at `0x22d864`. The branch at
`0x22d89c` selects Photos at `0x22d8a0` for false and sharing at `0x22d954`
for true. There is no case folding or nil-URL guard. A nil extension therefore
follows the Photos path.

The Photos library lookup at `0x22d8b0` precedes the transaction call at
`0x22d934`. The changes callback at `0x22d9a4` obtains a creation request at
`0x22d9c4` and adds resource type 2, the captured URL and nil options at
`0x22d9e8`. Neither method substitutes a fallback for a nil library or request.

The completion callback at `0x22d9fc` queues the callback at `0x22da84` onto
the main queue at `0x22da54`. It captures the success byte, helper and URL; the
NSError parameter is unused. Both paths through the string-initialization
scaffolding reach the same success table. The functional branch targets are
`0x22db44` for success and `0x22dc78` for failure. Success invokes cleanup at
`0x22db50`, default bundle lookup at `0x22db6c`, `Saved` localization at
`0x22db94`, and successful toast feedback at `0x22dbb8`. Failure invokes
sharing with the captured URL at `0x22dc88`.

`helper_mediaflow_runtime.m` executes the actual reconstructed method and
callbacks against synthetic Photos objects. It covers lowercase `m4a`, uppercase
`M4A`, a video extension, an empty extension, nil URLs, nil library/request
results, and both success values with or without an NSError. A synthetic resource
sink accepts nil URLs so their forwarding can be observed without submitting
anything to Photos. The fixture checks that result handling waits for exactly
one queued main callback and preserves cleanup/localization/feedback order.

## Sharing and action sheets

`-shareMedia:` at `0x22dcb8` allocates the activity controller at `0x22de34`
before creating its one-element URL array at `0x22de5c`. The array retains its
nil-element exception. It initializes with nil custom activities, excludes
AssignToContact and Print in that order, and installs its completion before
resolving `YTUIUtils` for the presenter.

The popover branch at `0x22dfa8` skips geometry on a nil first result. The
non-nil path obtains the presenter's view before the second popover getter,
then gets two separate screen/bounds results for width and height. It multiplies
width by 0.5, obtains the third popover for the rectangle, and the fourth for
arrow directions 15. It presents synchronously at `0x22e0f8`. The completion
at `0x22e16c` calls cleanup directly, independent of all completion arguments.

`-askForAction:` at `0x22e364` constructs the localized completion sheet at
`0x22eb3c`. It creates and adds SaveToPhotos first, using `save_photos`, then
Share, using the host share image. The action callbacks start at `0x22eee0`
and `0x22ef1c` and forward the captured helper and URL to saving and sharing.
The source view comes from the application delegate's window root, then its
pivot controller's view. Presentation uses that captured root synchronously at
`0x22ee74`.

The existing 22 media presentation checks now have direct first-package evidence
for their synchronous calls, nil behavior and distinct popover/screen getters.
The new fixture additionally checks action titles and verifies that each copied
action independently retains and forwards the helper and URL, including nil URL.

## Capture evidence and verification

The Photos changes descriptor at `0x10613d0` records a 40-byte block with one
strong capture. Its copy helper at `0x14b8c` retains the object at offset 32;
its dispose helper at `0x14bbc` releases it. The Photos completion descriptor
at `0x1063180`, queued result descriptor at `0x1062c70`, and action descriptor
at `0x1061c10` use the two-object copy helper at `0xc082c` and dispose helper
at `0xbe9f4`. These retain and release captures at offsets 32 and 40. The
queued result block has a byte at offset 48 for success.

Lifetime probes drop the original helper and URL owners, then the outer Photos
callback, and verify ownership passes to the queued callback. The ignored error
is not retained. After result handling, the helper and URL are released. Separate
action probes release the sheet owner and each action callback in turn to check
both independent captures. These checks prove ownership across the tested
boundaries, not identical instruction-by-instruction ARC release timing.

The new suite has 124 assertions. The related 22 presentation assertions are
reported separately and are not counted twice in the shared suite.
`first-helper-mediaflow-fidelity.json` pins 18 original byte intervals,
36 selectors, ten decoded strings, three functional branch tables, three method
addresses and the block descriptors and ownership helpers within those intervals.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --mediaflow
```

The original system-trap instructions in these methods, callbacks and ownership
helpers remain excluded. The fixture uses synthetic Photos, UIKit and host
objects; it performs no Photos authorization, real media import or device
presentation. No supplied binary is loaded or executed. This audit does not
establish whole-tweak parity or remove the separately documented download-path
validation differences.
