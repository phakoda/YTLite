# Shorts download menu

This recovery targets `+showDownloadSheetShorts:withSender:` at `0xf53fc` in the
first supplied arm64e package. Download selection is at `0xf72b8`, its storage
completion at `0xf7404`, image navigation at `0xf78ec`, information navigation
at `0xf792c`, regular-video opening at `0xf796c` and the auto-skip toggle at
`0xf7a5c`. Run `python3 recovery/tools/verify_first_menu_shorts.py` to check the
original bytes as data and execute the reconstructed entrypoint.

## Recovered behavior

The entrypoint allocates and initializes DownloadMenuHelper before choosing a
player response. It prefers playerResponse when supported, otherwise tries
contentPlayerResponse. A nil supported response stops construction without a
fallback. It reads videoID, then title and author through independent
playerData/videoDetails chains. Author is shortened first at 30 UTF-16 units,
then title at 200; longer values receive an ellipsis.

The method obtains Shorts video formats, audio formats, video index zero and
best audio in that order. Empty video arrays retain their index-zero exception;
a nil array returns nil. It reads the selected audioTrack and captures whether
one exists. Only the video content length supplies the displayed byte count and
storage check, with the full 64-bit value interpreted as signed.

The sheet uses the shared cache at `0x1227020`, displays author above title, and
shows the header divider. The chevron factory uses the UI-resource class cache
at `0x1227028` and enables right-to-left flipping. Every action uses the shared
action-class cache at `0x1227030`. Failed lookups retry; successful lookups remain
cached. Live playback omits the download action. The other actions are SaveImage,
CopyInformation, OpenAsRegularVideo and AutoSkipShorts, in that order. The first
three navigation actions share the same secondary chevron.

AutoSkipShorts resolves the action class, localizes its label and obtains the
fast-forward icon before reading shortsPlaybackIndex for its secondary image.
Only the full-width integer value one selects box_checkmark; all other values
select box_empty. Invoking the toggle reads the current preference again, then
gets the defaults object for writing zero if the value was one, otherwise one.
The current local ytpInt policy also obtains a defaults object internally; the
fixture distinguishes that internal read from the method's explicit writer
lookup. The historical preference authorization behavior remains excluded.

The download action checks storage directly without a hasContentLength guard.
Failure constructs a fresh error toast with the supplied message. Success uses
the captured track flag to choose audio-track selection or a direct download.
Both format the filename at completion from captured author/title objects and
use mp4. The selection route forwards captured player and sender; the direct
route forwards nil player and captions, while reading live format URLs, sizes
and duration. It does not add the best-audio size to the captured storage check.

Image and information actions forward the captured helper, player and sender.
Regular-video opening reads contentVideoID once as a nil check and reads it
again for the call. A nil first result stops; a nonnil first result followed by
a nil second result still invokes the opening helper with nil.

## Evidence and limits

The manifest pins the method, callbacks, capture helpers and dispatch wrappers
in two spans. It records 18 CFStrings, three class C strings, 49 adjacent selector
loads, 472 direct calls, 19 decoded branch tables, ten instruction words, three
class-cache access records and two capture descriptors. The download descriptor
at `0x10620d0` has size 113; the storage completion at `0x10620a0` has size 105.
Both use copy helper `0xf7810` and dispose helper `0xf788c`, retaining nine objects
at offsets 32 through 96. The download also captures video size at 104 and track
flag at 112; the storage completion captures the flag at 104. Seven original
system traps are omitted, including capture-helper traps.

The fixture runs the actual entrypoint with synthetic media and UIKit objects.
It checks metadata order and thresholds, menu order and icons, class cache
retry/persistence, live-video omission, captured values, both storage outcomes
and download routes, nil inputs, deferred navigation, two video-ID reads and
full-width preference comparisons. Eleven deliberately changed source variants
must fail; all 26 method encodings must match on iOS arm64 and arm64e.

This fixture does not establish real UIKit layout, host filtering, downstream
downloads, regular-video navigation, device integration or every temporary-object
release time. The local preference policy differs intentionally, and ToastView,
YTPPlayerHelper and YTLUserDefaults are still dynamically resolved where the
original has direct class references. No original code is executed. The audit
does not establish full package parity.
