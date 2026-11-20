# Video-quality menu

This recovery targets `showVideoSheet:withSender:` at `0xfb194`, its selection
action at `0xfc744` and storage completion at `0xfcaac` in the first supplied
arm64e package. Run `python3 recovery/tools/verify_first_menu_video_sheet.py`
to check original bytes as data and execute the reconstructed method.

## Recovered behavior

The method prefers playerResponse when supported and otherwise tries
contentPlayerResponse. A supported getter returning nil does not cause fallback.
It reads videoID first, then author and title through independent
playerData/videoDetails chains. Both strings are read before author is shortened
to 30 UTF-16 units and title to 200, with an ellipsis appended only when longer.
It retains the resulting strings and formats the filename in the storage
completion, preserving changes to captured mutable metadata until that point.

It requests regular video formats, audio formats and best audio in order, then
captures whether the active video's selected audio format has an audioTrack.
Each input video produces one action in the input order. Its MIME type is read
twice: first for the case-sensitive video/mp4 prefix, then for detail parsing.
The fallback detail is mp4 or webM. It reads qualityLabel, video size and best
audio size, formats their wrapping 64-bit sum as a signed file byte count, then
resolves the action class before formatting the action title. The action uses
the player icon and a nil accessibility identifier.

The button's current attributed title receives mutableCopy. That returned object
is used directly, including nil. The first case-insensitive match for the detail
string receives red foreground, font size 10 and baseline offset 5. Other text
keeps its attributes. The sheet is created only after actions have been built,
using the shared cache at `0x1227020`; actions use the shared cache at
`0x1227030`. Failed class lookups retry. The sheet receives the original sender
and presents from the toast window's root controller.

Selecting an action reads hasContentLength again. False constructs a fresh
ToastView with alloc/init and shows localized Error.TryLater with success NO.
True checks storage using the combined size captured when the sheet was built.
A failed storage completion shows the supplied message with success NO.

When storage is available, a captured audioTrack routes to the audio-selection
download method. Otherwise the completion reads downloadWithCaps, checks
hasCaptions only when enabled, and either requests the caption download or
downloads directly. All paths format the filename from captured author/title
and lowercase the captured extension in that completion. Direct downloads read
both URLs before filename formatting, then current video/audio sizes and video
duration; captions are nil and the captured player is forwarded. Metadata and
format objects remain captured while their getters' values can change.

## Evidence and limits

The manifest pins the method, callbacks, ten-object capture helpers and call
wrappers in two spans. It includes nine CFStrings, two class C strings, 64
adjacent selector loads, 427 direct calls, 24 decoded branch tables, ten
instruction words, two shared class-cache access records and three imported
attribute-name globals. The action block descriptor at `0x1062210` has size 121;
the storage completion at `0x10621e0` has size 113. Both use copy `0xfd0cc` and
dispose `0xfd150` for ten retained objects at offsets 32 through 104. The action
also captures size at offset 112 and the track flag at 120; the completion
captures the flag at 112. Five system traps are omitted, including traps in the
copy and dispose helpers.

The original reconstruction failed the new fixture before correction. The
fixture covers metadata reads and shortening, delayed formatting, shared cache
retry/persistence, captured flags and sizes, live format getters, every
storage/track/caption routing combination, nil label/copy/button results,
case-insensitive styling, overflow, input order and independent action captures.
Deliberately changed source variants must fail and all 26 method encodings must
match the first binary on iOS arm64 and arm64e.

The fixture uses synthetic YouTube objects, UIKit and media boundaries. It runs
Foundation formatting and attributed strings but does not establish real UIKit
layout, host format filtering, downstream downloads or device behavior. It does
not prove every temporary-object release time. ToastView still resolves
dynamically where the original uses a direct class reference. No original code
is executed, and this audit does not establish full package parity.
