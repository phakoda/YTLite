# First-package conversion callback state

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

`downloadDidFinish:fileName:` at `0x22bbb4` creates the cut-audio completion
at `0x22c17c` and merge completion at `0x22c8dc`. Each original block stores
the destination URL and helper at offsets `0x20` and `0x28`, seen in the STP
instructions at `0x22c03c` and `0x22c0f0`. Neither block captures a video ID.

After a successful move and media routing, or after reporting a move error,
the audio callback loads the helper from its block and reads the helper's
`_videoID` at `0x22c6ec`/`0x22c6f0`, then again at `0x22c79c`/`0x22c7a0`.
The video callback performs the corresponding read beginning at
`0x22d130`/`0x22d134` and repeats it for its four paths. Thus state changes
before completion or during synchronous media routing affect intermediate
cleanup, while the destination URL remains the one captured at scheduling.

The source previously copied `_videoID` when scheduling conversion. It now
passes the address of the captured helper's ivar to the synchronous C callback
helper. That address does not escape the call, and the callback retains the
helper. Cleanup reads the live ivar after media routing.

Both callbacks construct all intermediate URLs before the first cleanup
removal. Audio constructs two paths, and video constructs four. Each removal
calls `NSFileManager.defaultManager` again. The source now gathers the URLs
before removing them and performs those separate manager lookups. The repeated
`_a.ytpmap` removal in the video path remains intact.

The fixture in `helpers_runtime.m` replaces the file manager and converter
with test objects. It checks both conversion modes with success, move failure,
and converter error. It changes the helper ID after scheduling, again during
media routing, and again during the first removal. These checks distinguish
the captured destination from live cleanup state and prove that later removals
use the paths constructed before removal began. No new fixture moves or
deletes a real file.

The previous source failed `cleanup reads helper state after media routing`.
That report, log and source are retained in `.recovery-work/helper-conversion/`.
All 56 focused checks now pass in the shared actual-source runtime.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --conversion
```

The focused verifier checks original hashes, instruction spans, decoded cleanup
formats, selector references, error/move branch tables and the method address,
then checks current runtime and ABI evidence. Durable evidence is
`recovery/evidence/first-helper-conversion-fidelity.json`, and its report is
`.recovery-work/helper-conversion/report.json`.

The later [conversion-path audit](YTLHelper.paths.provenance.md) restores the
original string-formatting sequence, root-before-ID reads and nil-result
forwarding. This audit still does not establish complete conversion parity.
Path-component validation and local preference behavior remain documented
differences. Real file conversion, device behavior and remaining callback
lifetime details are unverified. No supplied binary is executed.
