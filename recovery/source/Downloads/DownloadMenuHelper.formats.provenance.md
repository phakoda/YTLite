# Download menu format filtering and track selection

This audit targets the first supplied `iphoneos-arm64e` package. Run:

```sh
python3 recovery/tools/verify_first_menu_formats.py
```

The original archive and dylib are read as data. The verifier compiles the actual
recovered source against synthetic app objects and host Foundation. It does not
execute the original binary or perform downloads.

## Source corrections

Both `getVideoFormatsArray:isShorts:` at `0x102a00` and
`getAudioFormatsArray:` at `0x103338` read the response's player data, streaming
data and adaptive formats before creating working arrays. The old reconstruction
created arrays first. The fixture changes the host's formats property during the
first working-array factory call and verifies that the method retains the
previously read array reference. This restores reference timing, not a defensive
copy of the input contents.

The video filter's accepted MP4 path adds the format to the result and MP4 arrays,
then advances to the next item. The WebM insertion arms are mutually exclusive
with it. The previous independent `if` statements also inserted an accepted MP4
into the fallback array if the format's second MIME getter returned WebM. The
source now uses `else if`. Both MIME getters still run before these decisions.

## First-package behavior checked

The video filter accepts MP4 prefixes from 144 through 1080 inclusive. Normal
videos also accept WebM above 1080. WebM from 144 through 1080 is retained as a
fallback only when no accepted MP4 exists and the request is not for Shorts.
Shorts does not use WebM. Other MIME prefixes are rejected.

The audio filter accepts `audio/mp4` prefixes. Both methods return an immutable
copy sorted by signed 64-bit content length descending. Their comparator invokes
at `0x1032cc` and `0x103990` read the left length before the right length; equal
lengths return `+1`, not zero. The fixture invokes each comparator synchronously
within `sortUsingComparator:` and respects its noescape contract.

Response lookup uses `playerResponse` when supported, otherwise checks
`contentPlayerResponse`. A nil supported modern response does not trigger legacy
fallback. Nil responses return before working-array creation; nil player data
produces an empty copied result.

`getBestAudioFormat:playerVC:` at `0x1039fc` selects the first MP4 audio format
whose itag reads as 140 or, on the second read, 139. It reads `audioTrack` twice
when the first result is nonnil. A default second track returns the format
immediately. Otherwise it reads `isDrc` and, when true, `preferDrc`, then returns
the format regardless of the preference result. The fallback is the player's
active video's selected audio format's `formatStream`.

`getDefaultAudioTrack:` at `0x104218` returns the first default audio track.
`getEnglishAudioTrack:` at `0x10451c` returns the first `en.4` identifier prefix.
Each sends `itag` before returning the matching format but ignores its value;
neither method filters MIME or itag. These three selection bodies required no
source change for the inspected behavior.

## Evidence and limits

The evidence pins all five named bodies, both comparator invokes and their
wrapper range. It checks six initialized CFStrings, 46 adjacent selector loads,
16 filtering/selection branch tables, 312 direct calls and both comparator block
invoke pointers. Manual data-flow inspection ties the decoded decision tables
to the input comparisons and insertion targets. Remaining enumeration and
constant-initialization branches are pinned in the body hashes but are not
individually decoded by this focused verifier. No system trap occurs in these
five bodies.

The fixture runs 728 checks covering range boundaries, signed lengths, nonzero
ties, nil/legacy response paths, getter ordering, changing MIME/itag/track values,
DRC preference combinations and default/English selection. Six independent
mutations must fail. The previous source failed five fixture assertions.

Working arrays are instrumented at the Objective-C factory boundary; the
factory interception ends at the first format getter so Foundation's internal
string-parser arrays are unaffected. Real Foundation performs backing-array
sorting and copying. The prior parser audit covers the actual quality parser.
Exact temporary ARC release timing, concurrent input-array mutation, app/device
integration, and all other menu methods remain outside this audit. These checks
do not establish complete class or package parity.
