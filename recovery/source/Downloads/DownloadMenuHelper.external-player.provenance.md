# External-player menu

This audit targets `showExtPlayerSheet:withSender:` at `0x100a74` in the first
supplied arm64e package. Its system-player action is at `0x1018c8`, with playback
completion at `0x1019d4`. Infuse uses `0x1019e4` and completion `0x101da8`; VLC
uses `0x1021b0` and completion `0x102610`.
Run `python3 recovery/tools/verify_first_menu_external_player.py` to inspect the
original bytes as data and execute the reconstructed source with synthetic hosts.

## Recovered behavior

The playlist getter chain is active player, video data, playback data, video,
streaming data, then HLS master playlist URL. The actions capture that URL when
the sheet is created. They appear in system-player, Infuse, VLC order. The sheet
and action factories share caches at `0x1227020` and `0x1227030` with the recovered
image and information menus. Failed class lookups are retried; successful ones
persist. Action class resolution precedes label localization. Infuse and VLC
each read the resource bundle separately and use nil image traits.

The system action creates an AVPlayer from the captured URL, allocates and
initializes an AVPlayerViewController, assigns its player, pauses the host
player, then presents the controller. Playback starts in the presentation
completion. Nil factory or initializer results are forwarded. The completion
retains the AVPlayer independently of the controller's player property.

Infuse formats `infuse://x-callback-url/play?url=%@`; VLC formats
`vlc-x-callback://x-callback-url/stream?url=%@`. Both interpolate the captured
playlist before reading the shared application, convert the formatted string
to an NSURL, and call openURL with an empty options dictionary and a completion.
The code adds no nested-query escaping. A successful open pauses the host player.
A failed open uses the shared legacy-toast cache at `0x1227038`, allocates without
initializing, and sends the localized PlayerNotFound message. Information-menu
copy feedback shares this cache. Nil URL conversion is forwarded to the app;
even a nil app receiver still evaluates the URL argument.

## Evidence and verification

The manifest pins three binary spans: the method and callbacks, their wrappers,
and the shared one-object block copy/dispose helper. It also pins ten CFStrings,
four class C strings, 38 adjacent selector loads, 273 direct calls, 13 branch
tables, five instruction words, four cache access records, and two block
descriptors. The completion descriptors have size 40 and capture offset 32,
with copy helper `0x14b8c` and dispose helper `0x14bbc`. Seven original system
traps are omitted, including one in the copy helper.

The fixture checks class lookup order and caching, action order and icons,
playlist capture, presentation/completion order, captured AVPlayer lifetime,
URL formatting and dispatch order, nil paths, success/failure feedback and
cross-menu cache sharing. Its playlist-description object is a synthetic probe
for formatting order, not evidence that real NSURL objects are mutable. Nine
compiled regressions must fail; all 26 method encodings must match the original
on iOS arm64 and arm64e.

Actual playback, app URL-scheme availability, UIKit presentation and device
integration are unverified. The separate two-object helpers for the main action
closures and every temporary-object release are not fully audited here. The
reconstructed sheet presenter still resolves ToastView dynamically where the
original uses a direct class reference. This audit does not establish package
parity. The original binary is never executed.
