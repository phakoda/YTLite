# Caption sheets and SRT sharing

This recovery targets the first supplied arm64e package. The four named methods
are `showTranscriptSheet:withSender:` at `0x1093ec`,
`showCaptionsSheet:withSender:` at `0x10a2d4`,
`getCaptionsUrlSheet:sender:completion:` at `0x10c030`, and
`shareSRT:sourceView:` at `0x10d350`.

Run `python3 recovery/tools/verify_first_menu_caption_flow.py` to inspect the
original bytes as data and compile and execute the reconstructed implementation.
The original package is never installed or executed by this verifier.

## Recovered behavior

Each caption action resolves `YTActionSheetAction` with `NSClassFromString`
before computing its title. These methods do not use the shared action-class
cache used by the audio selector. Transcript selection uses every caption;
the other two sheets forward the active caption array through
`captionsForDownloading:`. Missing player responses silently end caption sharing
and synchronously complete URL selection with nil. Transcripts do not require a
player response. Empty track lists still present empty sheets.

Action callbacks at `0x109d8c`, `0x10ae84`, and `0x10cc08` allocate and initialize
the toast, localize its parsing message, then allocate and initialize the parser.
The video ID is captured when building the sheet. Track URL and language are read
when the action runs, with URL read first. Parser construction must not call
`+new`, which a subclass or category can override independently.

Transcript completion at `0x10a078` prioritizes the error. Without an error, it
forwards even nil text to the pasteboard and updates the existing toast with the
localized `Copied` success message. It does not hide the toast or create a legacy
toast. Caption completion at `0x10b19c` also prioritizes the error; otherwise it
hides the toast before forwarding even a nil URL to `shareSRT:sourceView:`.
URL selection completion at `0x10cf20` instead prioritizes a nonnil URL, hiding
the toast before invoking the captured completion. Without a URL it reports the
error description or the literal `Error. Parser didn't returned any links`.

Sharing queues a block on the main queue. Its invoke at `0x10d40c` creates an
activity controller for the URL, excludes Assign to Contact followed by Print,
and asks `YTUIUtils` for `topViewControllerForPresenting`. If the first popover
lookup is nonnil, three further independent lookups set the original source
view, a rectangle of `(source.bounds.size.width - 5, 0, 1, 1)`, and the Up arrow.
Bounds are read before the lookup that receives the rectangle. Presentation is
animated with no completion. A nil URL fails during deferred array construction;
the recovered method does not invent an early return.

## Evidence and limits

The manifest pins four body/wrapper spans, 18 decoded strings, 94 adjacent
selector loads, 540 direct calls, seven semantic branch tables, the main queue
and activity imports, and seven geometry instruction words. It identifies ten
original system traps omitted from reconstruction. Initialization and enumeration
control flow is pinned and inspected, but not individually modeled in this test.
Block copy/dispose helpers are outside these spans.

Two fixtures exercise actual reconstructed source with host Foundation and
synthetic UIKit, player, parser, and toast boundaries. The sheets fixture checks
141 assertions, including all result/error combinations, deferred input reads,
constructor order, action-class timing, filtered inputs, and forwarding identity.
The sharing fixture checks 1,334 assertions over independent popover availability
and six source widths, plus nil inputs and queued source retention. Its synthetic
setters accept nonfinite rectangles; this does not establish UIKit behavior.
Nine compiled regressions must fail. Both iOS arm64 and arm64e builds must preserve
all 26 DownloadMenuHelper method encodings.

Shared recovered toast construction still resolves `ToastView` dynamically,
where the original references the class directly. Complete temporary-object
lifetime equivalence, parser networking and file output, real UIKit presentation,
and device validation remain unproved. These tests do not establish package
parity or the full behavior of the parser and toast implementations.
