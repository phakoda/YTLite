# First-package conversion paths and result forwarding

This audit extends the conversion-state audit with direct inspection of the
audio callback at `0x22c17c` and video callback at `0x22c8dc` in the first
supplied `iphoneos-arm64e.deb`. Its binary SHA-256 is
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

Audio cleanup looks up the temporary directory at `0x22c6d4` and `0x22c788`.
Each lookup precedes the current helper-ID read. The ID is passed twice to
`stringWithFormat:`, first with `%@/%@_a.m4a` and then `%@/%@_a.ytpmap`.
Each formatted component is appended to that lookup's root and converted with
`fileURLWithPath:`. Video cleanup repeats the same sequence four times,
beginning at `0x22d114`, with video, audio, audio-map and audio-map formats.
The repeated audio-map entry uses the same format string but performs fresh
root and ID reads, so its URL need not equal the preceding one.

The source previously read each ID before entering `YTLDownloadDirectory` and
used URL-based appending. It now reads the temporary directory first, then the
live ID, and uses the original string-formatting and URL-factory sequence.
It still builds all URLs before removing any intermediate. A fixed array of
four strong URL slots replaces the NSMutableArray so that nil factory results
can be preserved and forwarded individually, as in the original local values.

Both callbacks obtain a manager before branching on the converter error. With
an error, the original removes the supplied result at `0x22c570` or
`0x22cea8`, even if that result is nil, then shows the error's localized
description. With no converter error, it calls move at `0x22c5e8` or
`0x22cf24`, passing the original result, captured destination and an initially
nil error slot. It selects routing from that error slot, not the returned BOOL.
The reconstruction's result/destination guards skipped these calls and could
synthesize a different error. Those guards are removed. Path-component
validation remains before constructing cleanup paths.

`helper_conversion_paths_runtime.m` executes the actual scheduled callbacks in
326 assertions. Eight cases for each callback cover a successful move, a move
error, a false move result without an error, converter errors with nonnil and
nil results, a nil move source, a nil cleanup URL, and a nil captured destination.
The fixture captures the actual scheduled destination objects. It changes the
root and ID at each lookup, supplies distinct URL results and manager objects,
and verifies the complete operation order and object identity. No file-manager
double performs a real file operation. The prior source failed removal-result
identity; its source and failed report are retained under
`.recovery-work/helper-paths/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --paths
```

The focused verifier checks the first archive and binary hashes, original method
and callback/wrapper bytes, decoded path formats, error branch tables, selector
references and current runtime/ABI reports. Evidence is in
`recovery/evidence/first-helper-paths-fidelity.json`.

This does not establish full callback parity. The path guard and local preference
implementation still differ from the original, and the original system traps
remain excluded. Native filesystem error behavior, codec execution, arbitrary
ARC reentrancy and device behavior remain unverified. No original binary is
loaded or executed.
