# First-package download completion handoff

This audit covers `downloadDidFinish:fileName:` at `0x22bbb4` in the first
supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

The first output starts with `NSTemporaryDirectory` at `0x22bdb8`, then reads
the current ID, title and format at `0x22bdd4`/`0x22bdd8`. It formats
`%@/%@.%@`, appends that string as a path component, and calls
`fileURLWithPath:` at `0x22be38`. The audio output performs another temporary
directory lookup at `0x22be64`, reads ID and title again at `0x22be78`, formats
`%@/%@.m4a`, and creates its URL at `0x22bec0`.

Only after both URLs exist does the method obtain a file manager at
`0x22befc` and remove the video output at `0x22bf20`. It obtains the manager
again at `0x22bf34` and removes the audio output at `0x22bf50`. Both calls
pass a null error pointer and ignore the result.

The recovered source previously cached one directory URL and file manager.
It now restores the separate root lookups, current state reads, formatted
paths, `fileURLWithPath:` calls and manager lookups. It still creates both
outputs before either removal.

The phase flag is read after both removals at `0x22bf5c`. An unfinished video
phase stores the incoming URL and invokes audio start with five nil/zero
arguments. A finished phase hides the toast at `0x22bfa4`, reads the audio-only
flag at `0x22bfa8`, then obtains the shared converter at `0x22bfc4`. That earlier
flag selects cut or merge. Duration, and the merge's video/caption URLs, are
read after the converter lookup. The current source already matches those
decision points. The incoming filename argument is unused.

`helper_finish_runtime.m` executes the actual method in 51 focused assertions.
It changes the temporary root, ID and title independently for each URL and
supplies distinct URL results and manager objects. It changes the phase during
the second removal, changes audio-only state during toast hiding and converter
lookup, and changes converter arguments during that lookup. The cases cover
audio-phase continuation, audio cutting and video merging. All removal methods
are synthetic and return failure; no real files are removed. The prior source
failed to forward the original URL-factory results. Its source and failure
report are retained in `.recovery-work/helper-finish/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --finish
```

The verifier checks the first archive and binary hashes, method and wrapper
bytes, decoded path formats, both phase-selection tables, selector references,
and current runtime and ABI reports. Evidence is in
`recovery/evidence/first-helper-finish-fidelity.json`. The separate conversion
audit continues to check captured destination URLs and live cleanup IDs.

The method retains its nil-input guard and validates each ID before constructing
a path. Those guards are absent from the original. The system trap at
`0x22c158` remains excluded from recovered executable source. The fixture uses
synthetic boundaries and does not prove real conversion, filesystem or device
behavior. No original binary is loaded or executed.
