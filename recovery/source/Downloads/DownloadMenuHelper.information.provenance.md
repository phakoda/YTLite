# Information menu and copying

This recovery targets `showInformationSheet:withSender:` at `0xfe428` in the
first supplied arm64e package. Its channel, title, description, timestamp and
transcript action callbacks begin at `0xffa64`, `0xffd88`, `0x1000cc`, `0x10040c`
and `0x100a34` respectively.

Run `python3 recovery/tools/verify_first_menu_information.py` to read the original
bytes as data and compile and execute the recovered source with synthetic
boundaries. The supplied package is never installed or executed by this audit.

## Recovered behavior

The response getter uses the modern selector when supported, otherwise the
legacy selector. A supported modern getter returning nil does not fall back.
Without a response, the method returns before any sheet construction.

Four separate player-data/video-details lookup chains retrieve title, author,
short description and the description-presence flag in that order. Only then is
the author shortened to 30 UTF-16 code units and the title to 200, each with an
ellipsis when its length exceeds the limit. These are UTF-16 indices and can
split a surrogate pair. Unshortened objects are retained rather than copied;
changes to those objects before selection remain visible.

The sheet uses the shared class cache at `0x1227020`. Actions use the shared
cache at `0x1227030`, resolving their class before label localization. Failed
lookups are retried; successful results are reused, including across the
information and thumbnail menus. Actions have style zero and the copy icon.
Their label keys and order are CopyChannelName, CopyTitle, optional
CopyDescription, CopyTimestampedLink, and optional CopyTranscript.

Description availability follows the captured presence flag, even when the
captured description is nil. Transcript availability reads the active video's
complete caption-array count after creating the timestamp action. Any nonzero
full-width count enables it. It does not apply the download-caption filter or
read `addAutoCaps`, so automatic and translated captions remain usable for
transcripts.

Copy callbacks first get the general pasteboard and assign the captured value,
including nil. They then resolve the legacy-toast class through the shared
`0x1227038` cache, allocate without init, localize Copied and send showMessage:.
A missing toast class leaves the copy intact and is retried next time.

Timestamp copying reads the player's current media time, rounds to signed
64-bit seconds, then reads the current video ID and formats
`https://www.youtube.com/watch?v=%@&t=%lds`. The original FCVTAS instruction rounds
half values away from zero, saturates infinities/out-of-range inputs and maps NaN
to zero. The existing llround expression produces those results on the tested
ARM64 host. A nil ID is formatted as `(null)`. Transcript selection forwards the
captured player and sender to showTranscriptSheet:withSender: without copying or
legacy-toast feedback.

## Evidence and verification

The manifest pins the method/callback spans, call wrappers and one-object block
copy/dispose helper; 12 decoded CFStrings and six class C strings; 47 adjacent
selector loads; 416 direct calls; 22 initialization/selection/cache tables; and
cache and numeric instruction words. Six system-trap instructions are omitted,
including one in the block copy helper. The separate three-object transcript
block's copy/dispose helper is outside this manifest's spans.

The runtime fixture executes 2,036 assertions. It covers distinct metadata
objects, getter and shortening order, all combinations of eight author/title
lengths, mutable values, a UTF-16 boundary, nil metadata and response paths,
missing/successful class caches, label keys, description flags, five caption
counts including values beyond 32 bits, automatic captions with the download
preference disabled, copy feedback construction, deferred transcript arguments
and 13 timestamp values including nonfinite inputs. Pasteboard setter internals
belong to the synthetic boundary; the fixture records the assigned object's
identity before the shim copies it.

Eleven compiled regressions must fail. All 26 class method encodings must match
for both iOS arm64 and arm64e. The recovered sheet presentation still resolves
ToastView dynamically where the original uses a direct class reference. Complete
temporary-object lifetime, every original user of shared caches, real pasteboard
and toast behavior, and device validation remain outside these checks. This is
not a claim of full package parity.
