# First-package download starts

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
Video start is at `0x22ac34`; audio start is at `0x22b1c0`.

Both methods allocate and initialize `YTPDownloader` through `objc_alloc_init`,
at `0x22afa8` and `0x22b50c`. They store the result, set its delegate to self,
and then call the transport method. The reconstruction previously sent `new`;
it now uses `[[YTPDownloader alloc] init]` in both methods.

Video start clears both phase flags, stores the audio URL, sanitizes the title
with the helper's character set, and records the ID, audio byte count, format,
duration and captions. The transport receives the incoming video URL and
unsigned video byte count, with filename `%@_v.mp4`. Audio start's comparisons
at `0x22b430` through `0x22b440` require all five incoming arguments to be
nonnil or nonzero before replacing its stored audio state. Otherwise it starts
the next phase using existing state. Both paths set `_isVideoDownloaded` true
and use `%@_a.m4a`. These state selections agree with the existing source for
the validated path components used in this fixture.

Duration conversion is unsigned integer to double, division by double 1000,
then unsigned conversion rounding toward positive infinity. The video sequence
is at `0x22af5c` through `0x22af6c`; audio uses `0x22b4e8` through `0x22b4f8`.
The current duration helper matches a newly compiled native oracle of these
operations, including inputs near 2^53 and the maximum unsigned 64-bit value.
The oracle executes no code from the original dylib.

After audio transport returns, the original reads the audio-only flag at
`0x22b590` and the toast at `0x22b59c`, before resolving the localized label.
It uses the earlier flag and toast for either stoppable progress or a
nonanimated progress reset. The reconstructed source previously localized the
label first. It now branches first and localizes within each message expression,
which evaluates the receiver before the label. This preserves the original
reads without adding an owning local toast variable.

The stop callbacks at `0x22b134` and `0x22b6e4` capture self, then read its
current downloader at invocation time. They cancel a nonnil downloader and do
not cache the instance created at download start. The source already matches
that object selection. Tests replace the downloader before invoking the copied
callback and also exercise a nil current downloader.

`helper_start_runtime.m` executes the actual source in 487 focused assertions.
It checks localization that changes both the phase flag and toast, all 32
present/missing audio-argument combinations, video state and transport argument
identity, delegation at transport entry, eleven video-duration boundaries, and
both stop callbacks. It instruments the synthetic downloader's `new` method to
detect the incorrect construction dispatch. The previous source failed the
localization-order regression; its source and failure report are retained in
`.recovery-work/helper-start/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --start
```

The verifier checks the first archive and binary hashes, method and wrapper
bytes, the duration divisor, argument and stop-callback branch tables, decoded
labels and formats, selector references, and current runtime and ABI reports.
Evidence is `recovery/evidence/first-helper-start-fidelity.json`.

Path validation and the guard against absent stored audio state remain documented
reconstruction differences. System traps at `0x22b110`, `0x22b1b0`, `0x22b6c0`
and `0x22b760` remain excluded from recovered executable source. Native transport,
UI integration, and arbitrary reentrancy during ARC ownership operations are
outside this fixture. No original binary is loaded or executed.
