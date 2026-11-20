# First-package progress and image-copy ordering

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

`downloadProgress:` reads the toast at `0x22bab4` and phase flag at
`0x22bac0`, then gets the bundle and localized label at `0x22bad4` and
`0x22bb0c`. It formats the percentage at `0x22bb44` and sends the update
to the earlier toast at `0x22bb68`. The reconstruction previously formatted a
local string before reading the toast. It now puts the formatting expression
inside the update message, evaluating the toast receiver first. The existing
single-precision percentage multiplication remains unchanged.

The original copy-image callback at `0x230d8c` creates an image from captured
data at `0x230e94`, obtains the pasteboard at `0x230eb4`, assigns the image
at `0x230ed0`, and presents localized success at `0x230f48`. It still assigns
the image and reports success if image construction returns nil. The network
completion queues this callback on the main queue at `0x230858` when data is
nonnil and the download flag is false. The current source's property-assignment
expression already matches this order; no copy-image source change was needed.

`helper_ordering_runtime.m` executes actual source in 44 assertions. Its progress
cases change the toast and phase during either bundle lookup or localization,
for each original phase and both nil and nonnil original toast receivers. It
checks receiver selection, message order, original phase text and the unchanged
float argument. The copy cases record image decoding, pasteboard lookup,
assignment and success feedback for nonnil and nil image-factory results. They
also check that the queued callback contains both decoding and assignment.
All pasteboard and network objects are synthetic.

The prior source failed `progress uses receiver read before bundle and
localization`. Its source and failed report are preserved under
`.recovery-work/helper-ordering/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --ordering
```

The focused verifier checks the first archive and binary hashes, progress,
network-completion and copy-callback instruction spans, call wrappers, decoded
labels and format strings, data/download branch tables, selector references,
and current runtime and ABI reports. Evidence is in
`recovery/evidence/first-helper-ordering-fidelity.json`.

The percentage arithmetic and broader image callback suites remain separate.
These checks do not prove native UIKit behavior, arbitrary ARC reentrancy, or
whole-helper parity. Original system traps remain excluded. No original binary,
real network request or system pasteboard operation is executed.
