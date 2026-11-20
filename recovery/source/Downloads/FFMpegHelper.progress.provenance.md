# FFmpeg progress and statistics callbacks

The recovery reads the progress toast before localization and formatting, as the
first package does. It also preserves the original integer conversion when a
zero duration produces infinite progress, without an undefined C cast.

## First-package evidence

The reviewed methods are `statisticsCallback:` at `0x1f3e30`, `logCallback:::` at
`0x1f8a60`, `setActive` at `0x1f9184`, and `updateProgressDialog` at `0x1f91e4`.
The queued statistics callback begins at `0x1f3ed0`. Five pinned spans include
these bodies and their message wrappers. The verifier checks the supplied archive
and binary hashes, span bytes, decoded strings, selector references, call targets,
branch tables, instruction words and the double constant 1000.

Statistics delivery captures the helper and the supplied statistics separately,
then enqueues work on main. The queued callback stores the captured statistics
strongly before invoking progress. A nil argument clears statistics when that job
runs. Activation synchronously installs the log delegate before the statistics
delegate. The log callback contains no application operation.

Progress exits for nil statistics or a signed 32-bit time no greater than zero.
It reads duration after `getTime` returns. Both divisions use double precision:
time divided by 1000, then divided by the signed 64-bit duration. The toast load at
`0x1f9488` precedes bundle lookup at `0x1f94a4`, localization at `0x1f94cc`, and
formatting at `0x1f9504`. The update at `0x1f9528` uses that earlier receiver.

Percentage conversion uses `fcvtzs w4, d0` at `0x1f94e8` after multiplication by
100. Positive time and a nonzero integer duration keep this value within int32
range. Zero duration yields positive infinity, which this instruction converts
to INT_MAX. The source explicitly handles that upper bound. Progress itself
narrows to float at `0x1f9514` and can remain infinite. The recovered code does
not clamp the displayed progress ratio or replace zero duration.

## Verification

Run `python3 recovery/tools/verify_first_ffmpeg_progress.py`.

The fixture runs the actual reconstructed methods with controlled queues and
synthetic statistics, toast, localization and FFmpeg delegate boundaries. Its
2,818 assertions include 156 boundary time/duration pairs and 512 deterministic
pairs, receiver changes during localization, state changes during `getTime`, nil
statistics and localization results, queued object identity, ownership across
queue execution, delegate order and the empty log callback. An independent
numeric oracle executes a newly compiled scalar FCVTZS instruction on synthetic
values. No code from the supplied binary is loaded or executed.

The source baseline failed 12 assertions because it read the toast after
localization. The corrected fixture passed manually before verifier integration.
The verifier requires thirteen separately compiled regressions to fail, including
late receiver selection, undefined percentage conversion, narrowed duration,
float intermediate arithmetic, wrong time gates, premature statistics writes,
dropped nil delivery, reversed delegate order and a wrong dispatch queue.
The undefined conversion must fail the float-cast-overflow sanitizer; the other
variants must report assertion failures. It also compares all twelve method
encodings when compiling for arm64 and arm64e. The generated report records the
results and input hashes; this document alone is not proof of a passing run.

Five original system traps remain omitted. Exact temporary receiver ownership,
native queue interleavings, actual media conversion and device rendering remain
unverified. Four named methods are eligible for the focused audit index after
the verifier succeeds. This scope does not establish full FFmpeg or package parity.
