# FFmpeg conversion setup and callbacks

This recovery restores direct `ToastView` allocation and initialization for the
waiting and progress views in video merging and audio cutting. It also restores
three separate file-manager lookups during merge preparation. The previous source
located ToastView by name and sent `new`, and reused one file manager.

## First-package evidence

The named methods are `mergeVideo:withAudio:captions:duration:completion:` at
`0x1f3f20` and `cutAudio:duration:completion:` at `0x1f7644`. Four pinned ranges
cover their bodies, callbacks and wrappers: `0x1f3f20..0x1f56b4`,
`0x1f7644..0x1f8a60`, `0x1fc748..0x1fcd0c`, and `0x1fcf74..0x1fd40c`.

The four original ToastView class loads and allocation/initialization calls are:

| View | Class load | Allocation and initialization |
| --- | --- | --- |
| Merge waiting | `0x1f3f88` | `0x1f3f8c` |
| Merge progress | `0x1f4df0` | `0x1f4df4` |
| Cut waiting | `0x1f7690` | `0x1f7694` |
| Cut progress | `0x1f7ea8` | `0x1f7eac` |

The source now imports the real presentation header and references that class
directly. Host tests use separate declaration-only UIKit types to parse the
header; production does not include those test declarations.

Merge preparation fetches file managers at `0x1f4a18`, `0x1f4a50` and `0x1f4a80`
for JPEG removal, output removal and the WebP existence check. Each manager is
looked up before evaluating its operation's arguments. Removal errors are ignored.
A present WebP is converted on the preparation queue; its return code is ignored.
The merge command is then constructed, the log delegate installed, and execution
dispatched globally. Cutting removes its output and installs the delegate during
preparation, but formats the audio command inside the global callback.

Both methods construct a waiting toast immediately. When already processing,
they enqueue its localized notice on main. Their serial preparation callbacks
set processing true, store the full signed 64-bit duration, clear statistics and
reset library statistics before enqueueing progress presentation on main.
Presentation activates delegates, hides the waiting toast, constructs and stores
the progress toast, then localizes and displays zero progress with cancellation.
Cancellation forwards to `MobileFFmpeg cancel`.

Execution queues terminal handling on main. The terminal callback reads the
helper's current toast, hides it and clears processing before handling the result.
Success forwards the captured output URL. Cancellation returns `ErrDomain`, code
zero, with the localized `Cancelled` description. Other failures pass the library
log to `getCleanLog:` before returning the localized `Error.Clipboard` description.
The original success and cancellation globals contain 0 and 255.

## Verification

Run `python3 recovery/tools/verify_first_ffmpeg_construction.py`.

The verifier checks the first supplied archive and binary hashes, all four spans,
60 adjacent selector loads, 401 direct calls, 16 decoded strings, 16 branch tables,
16 instruction words, four original class references and two return-code globals.
The decoded writes must stay within reviewed constant buffers. The original
binary is parsed as data and never executed.

The actual reconstructed methods pass 1,787 checks using controlled queues and
synthetic URL, file-manager, library and presentation objects. Cases cover both
methods, initial processing state, thumbnail presence, success, cancellation and
other signed return codes, full-width durations, nil toast initialization and
nil file managers. Queue jobs run separately to verify deferred state changes,
operation order, callback arguments, cancellation forwarding and waiting-toast
retention and release. The initial baseline failed 127 assertions across the two
known behavior differences; the corrected source passes them.

Twelve independently compiled regressions must fail: `new`, dynamic toast lookup,
a cached file manager, narrowed duration, uncleared statistics, missing waiting
notices, skipped thumbnail conversion, missing cancellation, missing error-log
handling, early processing reset, the wrong cancellation code and the wrong merge
output name. Compilation checks all twelve class method encodings on arm64 and
arm64e. Only the two named conversion methods are added to the focused audit index.

Merge-command generation, clean-log internals and activation are mocked boundaries
in this fixture. It does not establish their fidelity, native queue interleavings,
complete temporary object lifetimes, media conversion or device behavior. Sixteen
original system traps in these ranges remain omitted. This is a scoped recovery
and does not establish complete class or package parity.
