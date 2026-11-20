# Download progress in the first package

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.
It corrects two differences in `YTLHelper.m`.

`downloadProgress:` starts at `0x22b770`. At `0x22bb1c` it loads the binary32
constant 100, multiplies in an S register at `0x22bb24`, then converts that
rounded result to double at `0x22bb28` for the variadic formatter. The recovered
source previously converted progress to double before multiplying. It now uses
`(double)(progress * 100.0f)`. This changes visible labels near rounding
boundaries: one fixture previously produced `DownloadingVideo: 1%` where the
original arithmetic produces `DownloadingVideo: 2%`. The unscaled input float
still goes to `updateText:progress:` at `0x22bb68`.

`downloadAudioWithUrl:fileName:videoID:audioSize:duration:` starts at `0x22b1c0`.
The branch table at `0x11d13f8`, selected from `_isAudioOnly`, sends standalone
audio to `0x22b614` and the second phase of a video download to `0x22b668`.
Standalone audio displays stoppable progress. The second phase sends
`updateText:progress:animated:` with float zero and `animated:NO` at `0x22b680`.
The previous reconstruction used `updateText:progress:`, whose implementation
animates. The source now uses the original three-argument selector.

The actual-source fixture in `helpers_runtime.m` uses an independently compiled
FMUL S / FCVT D oracle and tests the adjacent binary32 values around every
half-percent boundary from 0.5% through 99.5%, for both video and audio labels.
It also tests signed zero, negative and above-range values, infinities, and NaN,
and records the exact toast selector and animation argument for the audio phase
transition. All downloader calls use synthetic URLs and transport doubles.

The 1,228 checks failed against the previous source, first on percentage
rounding and then, after that correction, on the animated phase reset. The two
failure logs and the original source snapshot are retained under
`.recovery-work/helper-progress/before-*`. The corrected shared runtime passes.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py
```

The focused verifier checks the supplied archive and binary hashes, original
method addresses, raw instruction spans, decoded constant strings, selector
references and branch tables before accepting current-source runtime and ABI
reports. Evidence is in `recovery/evidence/first-helper-progress-fidelity.json`.
Its report is `.recovery-work/helper-progress/report.json`.

This does not establish complete download-method parity. Path-validation
differences, other state/lifetime ordering, and real device behavior remain
outside this audit. Original integrity/obfuscation effects are not implemented
or executed.
