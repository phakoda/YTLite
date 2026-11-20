# Thumbnail actions and image viewer

This audit targets `showImagesSheet:withSender:` at `0xfd1d4` and action invokes
`0xfe1f0`, `0xfe238`, and `0xfe3e0` in the first supplied arm64e package.
Run `python3 recovery/tools/verify_first_menu_images.py` to verify the original
bytes as data and execute the reconstructed source with synthetic boundaries.

## Recovered behavior

The method selects `playerResponse` when supported, otherwise
`contentPlayerResponse`. A supported getter returning nil does not cause a
fallback. Without a response, it returns before constructing a sheet. It reads
player data, video details, thumbnail array, the last thumbnail, and its URL in
that order, converting the URL string once before building the sheet.

The sheet class uses the original cache at `0x1227020`. The three action factories
use the shared action-class cache at `0x1227030`, resolving the class before each
label's localization. An unresolved class is retried at its next use. Successful
lookups remain cached. A nil sheet still evaluates action arguments; a nil action
passed to a real sheet retains the host collection's behavior.

Actions appear in this order: DownloadThumbnail with image, ShowThumbnail with
show_image, and CopyThumbnail with image_library. Every action has style zero.
Download and copy forward the captured URL to `YTLHelper downloadImageFromURL:`
with YES and NO respectively. Changes to the player's thumbnail after menu
creation do not affect the actions. The three closures independently retain the
converted URL.

The viewer action allocates and initializes `DVNImageViewController`, then reads
data synchronously from the captured URL, passes the result to `UIImage`, and
sets the viewer's full image even when decoding returns nil. It allocates a
navigation controller around the viewer, sets modal presentation style 2, and
gets the shared application's delegate, window and root controller before an
animated presentation with nil completion. This uses the app root, while the
thumbnail action sheet itself presents from the toast root. Nil initializer
results are forwarded without invented guards.

## Evidence and verification

The manifest pins the method and callback bodies, their call wrappers, the shared
one-object block copy/dispose helper, six decoded CFStrings, two decoded class
C strings, eight initialization/response/cache branch tables, selector loads,
direct calls and cache load/store instructions. The block descriptor has size
40 and capture offset 32; its copy helper retains the URL and its disposal helper
releases it. Five original system traps are omitted, including one in the copy
helper.

The fixture executes 144 assertions covering response selection, class lookup
failure/retry, successful caching, lookup/localization order, action order and
icons, captured URL identity/lifetime, download flags, synchronous decoder
forwarding, nil data/image/initializer/thumbnail paths and presenter selection.
Eight compiled regressions must fail. All 26 class method encodings must match
on iOS arm64 and arm64e.

The original has direct helper, viewer and toast class references; the current
reconstruction still resolves these dynamically. The recovered sheet cache is
also used by the information and external-player menus, with cross-menu sharing
checked in their focused fixtures. Real image decoding, device presentation,
complete temporary-object release timing, and the helper's downstream download
or copy operations are outside this fixture. This audit does not establish full
package parity.
