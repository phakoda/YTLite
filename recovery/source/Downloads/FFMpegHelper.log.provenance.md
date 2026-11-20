# FFmpeg log cleaning

`getCleanLog:` now joins the filtered lines before obtaining the whitespace
character set. Each pass that removes a trailing period fetches a fresh set
after constructing the substring. The previous source obtained one set before
joining and reused it for every trim.

## First-package evidence

The method spans `0x1f8a7c..0x1f9184`; its wrappers occupy
`0x1fd40c..0x1fd6ac`. The evidence manifest pins both ranges, fourteen adjacent
selector loads, 88 direct calls, three strings, nine branch tables and sixteen
instructions. Wrapper inspection confirms message sends and the fast-enumeration
mutation handler. The reviewed strings are the empty string, newline and period.

The method requests `newlineCharacterSet`, splits the supplied log and creates
the mutable output array. Fast enumeration compares each line with the empty
string first. A nonempty line is compared with the previous accepted line; a
different line is appended before replacing that previous value. Empty and
duplicate lines preserve the previous accepted object. The initial previous
value is nil, and it survives enumeration batch boundaries.

The join call at `0x1f8f3c` precedes the initial whitespace factory at
`0x1f8f60` and trim at `0x1f8f84`. A trailing period enters the loop, which reads
length at `0x1f90cc`, removes one UTF-16 unit at `0x1f90dc`, fetches the character
set at `0x1f9100` and trims at `0x1f911c`. The suffix check at `0x1f914c` determines
whether to repeat. Only after the loop does the method select the general
pasteboard at `0x1f9000` and forward the final object to `setString:`.

## Verification

Run `python3 recovery/tools/verify_first_ffmpeg_log.py`.

The verifier checks archive and binary hashes and the reviewed static evidence.
It decodes the constants and rejects writes outside their buffers. The supplied
binary is parsed as data and never loaded or executed.

The fixture exercises the actual reconstructed method. It passes 648 real
Foundation string cases whose outputs are independently generated in Python.
Cases include empty input, whitespace, consecutive and nonconsecutive duplicate
lines, periods separated by whitespace, Unicode text and enumeration batches up
to 257 lines. A traced synthetic fixture checks argument identity, comparison
order, previous-line selection, changed character-set results and nil returns
from splitting, mutable-array creation, joining, trimming, substring creation,
character-set factories and pasteboard selection. The pasteboard is a test
object; the host clipboard is never accessed.

The original source failed 872 assertions in this fixture. The corrected source
passes 2,055. Eleven compiled regressions must fail: early and cached character
sets, retained empty lines, identity-only duplicate comparisons, previous-line
reset on empties, a wrong separator, missing initial trimming, removal of only
one period, missing loop trimming, early pasteboard selection and a missing
pasteboard write. The verifier also compiles the source for arm64 and arm64e
and checks all twelve class method encodings. Its generated report records the
results and input hashes; the report must pass before this method is indexed.

One original system trap remains omitted. Exact temporary object lifetimes,
concurrent collection mutation and device pasteboard behavior remain unverified.
The synthetic trim object accepts nil character sets to expose argument
forwarding; this does not claim that native NSString trimming accepts nil.
Only this named method is added to the focused audit, not the full class.
