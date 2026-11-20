# Downloads recovery — YTLite 5.2.2

## Scope and result

The seven actual Objective-C classes are implemented in this directory. Their
runtime surfaces match **141 methods, 20 property records, and 30 ivars** from
the verified arm binary. Methods include synthesized accessors and ARC-generated
`.cxx_destruct` methods where the original metadata has them. These are functional
reconstructions, not byte-identical recreations of obfuscation or anti-analysis
supervisor calls.

| Class | Original methods | Implementation |
| --- | ---: | --- |
| YTPMedia | 67 | All image/theme methods, Cairo version gating, dynamic colors, singleton |
| YTPDownloader | 16 | Resumable range transfer, file storage, binary map serialization/loading, progress/error/completion/cancellation |
| Downloader | 11 | Sequential range transfer, preallocation and concatenation, progress/error/completion/cancellation |
| AudioManager | 8 | Audio session setup, bundled sponsor audio player, play/stop, delegate and singleton |
| YTPAPIHelper | 1 | Actual channel browse POST request and one-NSURL completion extraction |
| FFMpegHelper | 12 | Actual library command invocation, conversion queues, progress/cancel/error callbacks, language mapping |
| DownloadMenuHelper | 26 | Formats, audio selection, space checks, download/caption/thumbnail pipelines, information/Shorts/external-player/share sheets |

`RecoveryManifest.json` records every original selector, encoding, address,
property and ivar, with exact line anchors in `recovery/classes/<Class>.c`.
Each `.m` also identifies relevant method and anonymous-block addresses.
There are no bundled FFmpeg class implementations in this directory.

## Evidence chain

The original is read as data only:

- `.recovery-work/arm/YTLite.dylib`
- SHA-256: `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`

Evidence includes `recovery/classes/*.c`, individual
`recovery/decompiled/<address>.c` functions, `recovery/interfaces/RecoveredInterfaces.h`,
`recovery/evidence/arm-classes.json`, `ivars.json`, decoded strings/bytes, and branch
records. Truncated pseudocode was checked against raw arm instructions and the
expanded `.recovery-work/analysis-v2/evidence/branches.json` branch targets.
The original dylib/debs were never executed.

Worker-local annotated instruction files are in `.recovery-work/downloads/`.
The principal continuation proofs are:

| Behavior | Original addresses | Worker-local evidence |
| --- | --- | --- |
| Legacy path creation and ceiling chunk count | `0x1cd1d0–0x1cd3a0`, `0x1cd9f8–0x1cdf18` | `chunk-round.asm.txt`, `downloader-path.asm.txt` |
| Legacy asynchronous chunk write/completion | `0x1ce018`, invoke `0x1ce0f4` | `recovery/decompiled/001ce0f4.c` |
| Channel response extraction | `0x1cb938–0x1cc980` | `api-callback.asm.txt`, `api-extract.asm.txt` |
| Resumable start/path/loaded-size sum | `0x1d01c0–0x1d0b6c`, `0x1d0d50–0x1d124c`, `0x1d2770–0x1d2a48` | `resume-start.asm.txt`, `resume-path.asm.txt`, `resume-sum.asm.txt` |
| Data callback map updates and progress | `0x1d3924–0x1d42d4`; log thunk `0x1d6104` | `resume-data.asm.txt`, `progress-log-thunk.asm.txt` |
| OLED shade comparison/dynamic colors | `0x1aacd4–0x1ab020` | `oled.asm.txt`; dynamic provider `001aaba4.c` |
| FFmpeg command cases | `0x1f5d58–0x1f7cd8` | `ffmpeg-command.asm.txt`, `ffmpeg-constants.asm.txt` |
| FFmpeg log cleanup/progress | `0x1f9148–0x1f9c44` | `ffmpeg-log-progress.asm.txt` |
| Formats and first-eligible audio selection | `0x1030f8–0x1048f4` | `menu-formats.asm.txt` |
| Default/English audio and MIME labels | `0x1048f4–0x1054dc` | `menu-default-audio.asm.txt`, `menu-mime-english.asm.txt` |
| Audio preference/caption/download forwarding | `0x1055f4–0x1066e4` | `menu-pipeline-select.asm.txt`, `menu-pipeline-continuation.asm.txt` |
| Thumbnail storage and space/track selector | `0x1077b0–0x109374` | `menu-thumbnail-end.asm.txt`, `menu-space-audio-sheet.asm.txt` |
| Caption filtering and failure completion rules | `0x10b9a4–0x10c14c`, `0x10d600–0x10da34` | `menu-captions-filter.asm.txt`, `menu-captions-error.asm.txt` |
| Shorts captured sizes, truncation, handlers | `0xf6b60–0xf8038` | `shorts-metadata.asm.txt`, `menu-shorts-handlers.asm.txt`, `menu-main-blocks.asm.txt` |
| Normal video action continuation | `0xfc4f0–0xfd8cc` | `menu-video-end.asm.txt` |
| Thumbnail UI actions (not channel-image actions) | `0xfe4bc–0xfeb1c` | `menu-channel-image.asm.txt` (historical filename only) |
| Information and external-player completions | `0x10015c–0x1030f8` | `menu-copy-blocks.asm.txt`, `menu-ext-completions.asm.txt` |

The annotator is a **linear instruction index**, not a stand-alone CFG proof.
Its contextual labels must not replace checking register flow and recovered
branch targets. `verify_downloads_notes.py` likewise emits compact review indexes,
not replacement decompilation.

## Preserved behavior that is easy to accidentally change

### Network and storage

Both download engines create a default URL session whose delegate operation queue
is the main queue. Their range behavior differs: `Downloader` does not clamp the
last range; `YTPDownloader` does. Both use the original 5 MiB chunk size and exact
`Range: bytes=<start>-<end>` syntax. The legacy final callback runs in a global
queue and uses `URLWithString:` on the plain path, whereas the resumable callback
uses `fileURLWithPath:` on the delegate/caller queue. Weak delegates and signed
64-bit cumulative sizes/single-precision progress are retained.

The resumable path is `NSTemporaryDirectory()/videoID/fileName`. The map replaces
the filename extension with `.ytpmap`. Its little-endian wire format is:

```
32 bytes SHA256(UTF8(fileName + decimalUnsignedFileSize))
uint32 entryCount
entryCount records: uint64 offset, uint32 downloaded, uint32 full
```

Map keys are **data-callback offsets**, not rounded chunk boundaries. Completed
maps survive cleanup; incomplete maps are removed. Cleanup sets the map to nil,
and the original start/reuse path does not recreate it or reset the downloaded
counter. These defects were not silently repaired. The original map parser trusts
its encoded buffer length/count; the reconstruction retains that behavior and the
tests do not supply truncated buffers. Treat map inputs as trusted application
state until the integrator deliberately chooses a compatibility-breaking hardening
change. Paths and command strings are not additionally sanitized or quoted.

The channel helper preserves the complete legacy browse endpoint/key, WEB client
version `2.20240201.10.00`, POST JSON structure, `Content-Type: application/json`,
and `sources[1].url` avatar extraction. Its completion takes one NSURL, not image
bytes or an error pair. It does not add HTTP-status or source-count checks.

### Menu and preferences

Menu preference reads call the real shared `ytpBool`/`ytpInt` functions declared
in `../Runtime/YTLBootstrapCrypto.h`. This retains the shared authorization and
feature-suspension gates. Do not replace these with unconditional defaults reads.
Theme reads in `YTPMedia` intentionally use direct `YTLUserDefaults` class getters.
The Shorts toggle writes through `standardUserDefaults`, exactly as in the binary.

Video selection admits MP4 144p–1080p and normal-player WebM above 1080p. Low WebM
is fallback only when no MP4 exists and the player is not Shorts. Size sorting
returns descending even for equal sizes. The “best” audio routine returns the
first eligible MP4 itag 140 or 139; it does not make a second optimizing pass.
Its `preferDrc` result is discarded. Default/English helpers call but do not filter
by itag; English uses the `id_p` prefix `en.4`. Audio selector sheets prefer
non-DRC itag 140, falling back to DRC 140, and sort track display names.

The free-space predicate is strictly `2 * mediaSize < freeBytes`, not `<=`.
Shorts use video-only size for the shown size/space check while still forwarding
audio size to the download pipeline. Shorts index the first video format without
an empty-array guard. Title/author truncation uses 200/30 UTF-16 units plus an
ellipsis. Caption failure does not invoke the pending video completion; successful
captions do. The application root owns the freshly allocated YTLHelper; toast
sheets are presented from the distinct toast-window root. Nil and unsupported
player-response forwarding paths remain unchanged.

### FFmpeg and audio

`FFMpegHelper` passes the recovered command strings to actual `MobileFFmpeg`
entrypoints. Its serial queue serializes preparation, **not** global-queue FFmpeg
executions. Main-queue UI updates/completions, cancellation, return codes 0/255,
error domain `ErrDomain`/code 0, output filenames, thumbnail conversion, stream
maps/dispositions, milliseconds/progress conversions and all 80 language mappings
are retained. This directory supplies narrow library declarations only.

`AudioManager` configures playback/mix-with-others and loads `SponsorAudio.m4a`
from the shared bundle. A single NSError variable is reused for category/player
initialization. Its empty `audioPlayerDidFinishPlaying:successfully:` method and
FFMpegHelper's empty `logCallback:::` are proven empty original callbacks, not
substitutes for missing playback or conversion operations.

## Validation

Run inside the approved repository root:

```sh
export PYTHONDONTWRITEBYTECODE=1
export TMPDIR="$PWD/.recovery-work/downloads/tmp"
export CLANG_MODULE_CACHE_PATH="$PWD/.recovery-work/downloads/cache"
python3 recovery/tools/verify_downloads.py
```

The full runner verifies the original binary SHA-256, builds and executes only
the new host test program, and compiles/archives all seven actual source files
for **arm64 and arm64e, iOS 14.0**, with the real iPhoneOS SDK and
`-fobjc-arc -fblocks -Wall -Wextra -Werror`. All seven also passed the originally
requested strict arm64 iOS 13.0 compile; those objects are in
`.recovery-work/downloads/ios13-compat/`. Build commands, outputs, fixture paths,
and source/evidence hashes are recorded per run under
`.recovery-work/downloads/runs/`; `latest-run.txt` locates the latest run.

The runtime suite passes **632 behavioral assertions and 463 exact ABI assertions
(1,095 total)**. It checks all method/encoding/property/ivar sets, all 59 icon
choices in both modes, 80 caption-language mappings, real SHA-256/file/map
roundtrips, 64-bit wire/forwarded values, range requests, weak ownership,
progress/cancellation/error callbacks, API requests and responses, FFmpeg command
variants/main-queue completions, preference-gate forwarding, and menu,
caption, thumbnail and storage paths.

`downloads_doubles.*` and `downloads_shims/` are **test-only**. They isolate UIKit,
AVFoundation, YouTube/SRT/pipeline hosts, the FFmpeg library, URLSession transport,
and authorization boundaries. Foundation strings/JSON, filesystem operations,
SHA-256, Objective-C runtime/ARC, and dispatch execute for real. Host compilation
substitutes only the temporary-directory function so actual production storage
methods operate on repository fixtures. HOME, CFFIXED_USER_HOME, temporary/cache
paths, logs and generated files are directed inside this repository. There are
no writes to real preferences, the pasteboard, user downloads or device media.

Passing host tests is **not** proof of live YouTube/network behavior, actual
codec conversion, device playback, or complete app integration. Those operations
were not run here.

## Integration dependencies / remaining work outside this assignment

Link the actual bundled compatible mobile-ffmpeg library providing
`MobileFFmpeg`, `MobileFFmpegConfig`, `Statistics`, `RETURN_CODE_SUCCESS`, and
`RETURN_CODE_CANCEL`; do not link test doubles. Supply compatible standalone
FFmpeg components rather than the original combined application binary. The
produced static archives are integration components, not fully linked apps.
Required Apple APIs are in
Foundation, UIKit, AVFoundation, AVKit and the platform CommonCrypto library.

The shared app must supply the real NSBundle image/localization category and
resources, YTLUserDefaults, shared bootstrap gates, ToastView, YTLHelper's actual
video/audio/image pipelines, SRTDownloader, DVNImageViewController,
YTPPlayerHelper, and the narrow YouTube host selectors in `DownloadsMenuHost.h`.
Host class lookup deliberately uses NSClassFromString rather than invented
YouTube replacement classes. No shared build files, hooks or other owners' class
implementations were modified. The shared bootstrap `ytpInt` dependency was
requested from prime and is now present in the shared runtime implementation.

Remaining integration validation is on-device/live-service and actual-codec
validation with those dependencies. No method in the seven assigned classes is
left as a declaration-only recovery or fabricated no-op pipeline. Known original
unsafe/trust assumptions and race behavior above are retained rather than
claiming this is a hardened or behaviorally redesigned implementation.
