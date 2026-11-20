# Parity with the first supplied package

The requested target is `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`.
Full parity has not been achieved. A successful build or matching Objective-C
method signatures does not establish it.

The direct package comparison is reproducible:

```sh
python3 recovery/tools/compare_supplied_packages.py
```

The tool reads the supplied archives and checks their hashes against the original
inventory. It parses the dylibs as data without loading or executing them. Results
are in `evidence/first-package-comparison.json`.

## What the first package establishes

All three dylibs have Mach-O CPU type `0x0100000c` and subtype `0`, generic
arm64. `iphoneos-arm64e` is the first package's Debian architecture field; its
dylib does not declare the arm64e CPU subtype. The current build's arm64 setting
therefore agrees with the first binary's declared CPU type. This does not prove
its deployment or functional compatibility.

All three have the same 58 class records and 938 named method signatures,
including seven bundled-library classes. The 51 first-party classes account for
864 methods. Resources match across the packages. This supports carrying over
the class-contract and resource findings, but says nothing about method bodies.

The first package has 53,024 `LC_FUNCTION_STARTS` entries; the other two each have
53,039. Each package has 12 initializer offsets. These counts include compiled
library and obfuscation code and are not counts of recovered source functions.

For the 864 first-party named method spans, comparing the original `iphoneos-arm`
binary with the first package yields:

| Raw span comparison | Methods |
| --- | ---: |
| Same bytes | 91 |
| Same length, different bytes | 415 |
| Different length | 358 |

A span ends at the next function-start entry. It does not include separately
compiled callbacks or callees. Different bytes can result from relocated
references, obfuscation or changed logic. Identical bytes can still reference
different data. These numbers are an audit inventory, not a parity percentage.

## Recovered deployment configuration

The first binary imports the C++ `jbroot(NSString *)` symbol and loads
`@loader_path/.jbroot/usr/lib/libroothide.dylib` and
`@loader_path/.jbroot/usr/lib/libsubstrate.dylib`.

The `iphoneos-arm` binary instead loads CydiaSubstrate from
`/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate`. Its import set
includes `dlopen`, `strlcat` and `strlcpy`, which are absent from the first binary.
The `iphoneos-arm64` variant loads CydiaSubstrate through `@rpath`.

The recovered `Runtime/YTLRootPaths.c` implements the `iphoneos-arm`
libroot compatibility path. `Utils/NSBundle+YTLite.m` now recovers the first
package's direct NSString resolver under `YTLITE_RESOURCE_ROOTHIDE`. The resource,
image and localization helpers pass 189 isolated checks and five first-package
category encodings. Direct first-package instruction inspection confirms the
image/localization call sequences and return selection; see
[resource provenance](source/Runtime/FirstPackageResources.provenance.md).
The root Makefile sets this define for `ROOTHIDE=1`. A project-specific Theos
module and text-based linker declarations now build the roothide archive from
the recovered source. Its 18 regular-file paths, CPU type/subtype, Debian
architecture, filter, two external runtime bindings and 51 first-party class
method contracts pass static verification. The packaged resource values agree
with the current source; 13 locale files retain existing differences from the
first archive. See [build configuration](build/roothide/README.md).
Device library availability, loading and execution remain unverified.

## Remaining work

The local settings UI intentionally omits the Developer section and the
Special thanks/supporters entry at the user's request. Their reconstructed
factory methods and binary evidence remain available, but the root settings
model no longer constructs those entries. This is a local UI change, not a
claim about the original 5.2.2 interface.

The [audit index](FIRST_PACKAGE_AUDIT_INDEX.md) maps current focused first-package
evidence to named methods and source owners. It currently catalogues all 22
`YTLHelper` methods, all 67 `YTPMedia` methods, all eight `AudioManager` methods
and all 26 download-menu methods
covering video handoff, normal audio actions, string parsing and format/track
selection, the video-quality and Shorts menus, caption handoff, caption filtering and titles, caption sheets and SRT sharing, thumbnail actions and writing, information copying, external-player actions, and storage-space checks. All twelve FFmpeg helper methods have focused lifecycle, conversion, progress, statistics, activation, logging, command and caption-language audits. The 63 DVNCell accessors now have complete storage-pattern checks and 518 runtime assertions, with eleven rejected regressions. Its initializer and destructor now have separate complete-body checks and 598 runtime assertions, with ten rejected regressions. A separate factory-order audit corrected seven setter sequences and passes 144 assertions across all eighteen entry points. The completed factory audit adds 1,408 assertions, thirteen rejected regressions and complete argument/ownership body checks on both iOS architectures. All 83 DVNCell named methods now have focused evidence. The other 646 first-party methods have reconstructed source but are not covered by this method-specific first-package catalogue. This count
is not a parity percentage; known helper differences, callbacks, registrations
and device behavior require separate assessment.

The audio-manager recovery restores URL construction before player allocation.
Its 643 checks cover error propagation, nil results, singleton initialization,
fresh player reads during playback and stopping, and strong player ownership;
ten compiled regressions fail. See
[audio-manager provenance](source/Downloads/AudioManager.provenance.md).

The thumbnail-menu audit restores cached sheet lookup, action-class lookup before
localization, and viewer `alloc`/`init` construction. Its 144 checks cover missing
classes, nil results, URL retention, download/copy flags and presenter selection;
eight compiled regressions fail. See
[thumbnail-menu provenance](source/Downloads/DownloadMenuHelper.images.provenance.md).
The information-menu recovery restores transcript availability for any caption
track, the original title/description label keys, separate metadata reads and
shortening order, and cached copy-feedback construction. Its 2,036 checks cover
those paths and timestamp formatting; eleven compiled regressions fail. See
[information-menu provenance](source/Downloads/DownloadMenuHelper.information.provenance.md).
The external-player recovery restores shared sheet and error-toast caches,
system-player construction, and the original URL-formatting/application-lookup
order for Infuse and VLC. Its 184 checks cover deferred playback, captured inputs,
nil results and open-success/failure callbacks; nine compiled regressions fail.
See [external-player provenance](source/Downloads/DownloadMenuHelper.external-player.provenance.md).
The video-quality menu recovery restores independent metadata reads, filename
formatting after storage completes, action-title formatting after class lookup,
the attributed label's mutableCopy result and shared sheet lookup. Its 1,250
checks cover callback routing, captured inputs, 64-bit size overflow, nil results
and label styling; eleven compiled regressions fail. See
[video-quality provenance](source/Downloads/DownloadMenuHelper.video-sheet.provenance.md).
The Shorts recovery restores separate metadata reads and shortening order,
shared sheet/resource caches, the regular-video action's chevron and auto-skip
evaluation order. Its 887 checks cover menu construction, captured download
inputs, storage outcomes, navigation and full-width preference values; eleven
compiled regressions fail. See
[Shorts provenance](source/Downloads/DownloadMenuHelper.shorts.provenance.md).

The normal menu now also restores separate metadata reads, author-first
shortening and shared sheet/resource caches. Its 789 construction checks cover
navigation captures, independent live-playback decisions and caption availability;
eight compiled regressions fail. See
[normal-menu provenance](source/Downloads/DownloadMenuHelper.normal-construction.provenance.md).
All 26 menu methods having a focused audit does not establish complete menu
parity. These fixtures use synthetic host boundaries; native appearance,
temporary object lifetimes and actual device behavior remain unverified.

The caption-flow audit restores parser construction, the separate completion
rules for transcript copying, caption sharing and URL selection, and the original
SRT presenter and popover configuration. Its 1,475 checks cover deferred input
reads, result/error combinations and presentation call order; nine compiled
regressions fail the fixtures. See
[caption-flow provenance](source/Downloads/DownloadMenuHelper.caption-flow.provenance.md).

The caption-helper audit confirms the current availability, download-filtering
and title methods against first-package instructions. Its 195 checks cover
independent identifier reads, preference timing, full-width counts, returned
array identity and label localization; five independent regressions fail the
fixture. See [caption-helper provenance](source/Downloads/DownloadMenuHelper.captions.provenance.md).

The audio-track selector audit restores the localization icon and cached action
class lookup before label evaluation. Its 119 checks cover two-pass filtering,
name comparison, action creation, presentation and deferred selection; five
independent regressions fail the fixture. See
[audio-track selector provenance](source/Downloads/DownloadMenuHelper.audio-selector.provenance.md).

The storage-space audit restores cached class lookup, `alloc`/`init` construction
and controller lifetime through completion. Its 1,286 checks cover wrapping
arithmetic, strict space comparison, formatting order and nil controller paths;
four independent regressions fail the fixture. See
[storage provenance](source/Downloads/DownloadMenuHelper.storage.provenance.md).

The thumbnail audit restores early video-ID lookup, temporary-path and manager
ordering, and writing through a file URL. It removes the invented video-parent
creation. Its 147 checks cover failure paths and a real successful file write;
four independent regressions fail the fixture. See
[thumbnail provenance](source/Downloads/DownloadMenuHelper.thumbnail.provenance.md).

The video-selection audit restores title-before-author metadata reads and the
second details lookup in the caption branch. Its 150 checks cover deferred
audio/caption callbacks, nil selections and current format properties; four
independent regressions fail the fixture. See
[video-selection provenance](source/Downloads/DownloadMenuHelper.video-selection.provenance.md).

The format-selection audit restores available-format lookup before working-array
creation and the exclusive accepted-MP4 path. Its 728 checks also cover signed
comparators, response selection and best/default/English audio-track behavior;
six independent regressions fail the fixture. See
[format-selection provenance](source/Downloads/DownloadMenuHelper.formats.provenance.md).

The string parser audit restores the literal `p` split and indexed quality
conversion, plus MIME range extraction and quote removal. Its 49 checks include
malformed strings, signed values, nil inputs and selector order; three isolated
regressions fail the fixture. See
[parser provenance](source/Downloads/DownloadMenuHelper.parsers.provenance.md).

The normal audio-action audit restores constructor dispatch, filename formatting
after URL creation, and toast creation before localization. Its 176 checks cover
deferred callbacks, track preferences and errors; five reverted behaviors fail
the fixture. The constructor survey also verifies the shared toast factory and
Shorts menu creation. See
[audio action provenance](source/Downloads/DownloadMenuHelper.audio.provenance.md).

The menu handoff audit restores helper creation with `alloc` and `init` instead
of `new`. Its 298 checks distinguish those calls and verify the current root
helper, nil results, full-width arguments and thumbnail preference timing. The
former implementation fails the same fixture. See
[handoff provenance](source/Downloads/DownloadMenuHelper.pipeline.provenance.md).

The media theme audit adds 423 checks for singleton construction, root lookup,
version comparison, dynamic colors and generic/Discord asset selection. The
inspected source paths match; the setter's system trap remains omitted. Its
verifier also checks all 67 class method encodings against the first binary on
both architectures. See [theme provenance](source/Downloads/YTPMedia.theme.provenance.md).
A separate audit now covers all 59 icon factories with 5,458 checks for asset
selection, Cairo snapshots, nil forwarding, tint and return ownership. All 115
requested asset names exist in the restored first-package catalog. See
[icon provenance](source/Downloads/YTPMedia.icons.provenance.md).

The helper state audit adds 269 checks for Wi-Fi flags and object-ivar teardown.
The normal predicate and destruction order match; reachability creation failure
retains a guard absent from the original. See
[state and teardown provenance](source/Helpers/YTLHelper.state.provenance.md).

The image-download audit confirms the first package's URL/response branches and
feedback callbacks. Its 166 new checks distinguish localized Photos formats
from literal network-error formats and verify raw-data/error ownership. The
existing 27 URL/routing checks now have first-package evidence. Selector checks
are tied to original load instructions; see
[image callback provenance](source/Helpers/YTLHelper.imageflow.provenance.md).

The direct media routing audit confirms the current save/share/action-sheet
sequences and callback ownership. Its 124 new checks cover Photos routing, nil
framework results, queued completion and independent action captures; the
existing 22 presentation checks now also have first-package evidence. See
[media routing provenance](source/Helpers/YTLHelper.mediaflow.provenance.md).

The direct asset/rendering audit confirms the current source call sequences for
six helper methods, including both class and instance resizing. Its 212 new
checks cover asset-loader allocation and bundle order, replacement initialization
results, template conversion, tint and nil results. The existing 31 geometry
checks now also have pinned first-package evidence. No production change was
needed for those paths; see [asset and rendering provenance](source/Helpers/YTLHelper.assets.provenance.md).

A direct audit of the first package corrected download percentage multiplication
to single precision and restored the nonanimated reset when switching from video
to audio. The focused actual-source suite passes 1,228 checks; see
[progress provenance](source/Helpers/YTLHelper.progress.provenance.md).
The conversion callback audit also restored live cleanup-ID reads after media
routing, construction of all cleanup URLs before removal, and fresh file-manager
lookups. Its 56 checks use a synthetic file manager; see
[conversion provenance](source/Helpers/YTLHelper.conversion.provenance.md).
The button audit restored the class-dispatch step, direct overlay construction,
original-icon branch and three feedback-object reads. Its 43 focused checks are
documented in [button provenance](source/Helpers/YTLHelper.buttons.provenance.md).
The initializer audit restores toast allocation and storage before character-set
creation, with 28 focused checks described in
[initializer provenance](source/Helpers/YTLHelper.init.provenance.md).
The failure/cleanup audit adds 38 checks, restores the cleanup ID-read timing
and URL-construction calls, and documents two excluded system-trap instructions;
see [failure and cleanup provenance](source/Helpers/YTLHelper.terminal.provenance.md).
The download-start audit restores downloader allocation and the audio flag/toast
reads before localization. Its 487 checks cover state selection, duration edges
and current-downloader stop callbacks; see
[download-start provenance](source/Helpers/YTLHelper.start.provenance.md).
The completion-handoff audit restores independent output roots, current ID/title
reads, URL factories and removal-manager lookups. Its 51 checks also verify phase
selection around removal, toast hiding and converter lookup; see
[completion-handoff provenance](source/Helpers/YTLHelper.finish.provenance.md).
The conversion-path audit restores root-before-ID reads, original URL factories
and nil-result forwarding with 326 checks; see
[conversion-path provenance](source/Helpers/YTLHelper.paths.provenance.md).
The receiver-order audit restores the progress toast read before localization
and verifies the first package's image-copy sequence in 44 checks; see
[progress and copy ordering](source/Helpers/YTLHelper.ordering.provenance.md).

FFmpeg conversion now uses direct ToastView allocation/initialization and fresh
file-manager lookups during merge preparation. Its 1,787 checks cover deferred
setup, queue order, waiting-toast ownership, cancellation and completion paths;
twelve compiled regressions fail. Device conversion remains unverified. See
[FFmpeg conversion provenance](source/Downloads/FFMpegHelper.construction.provenance.md).

FFmpeg progress now reads its toast receiver before localization and preserves
the original percentage conversion for zero duration. The progress, statistics,
activation and empty log callbacks pass 2,818 assertions; thirteen compiled
regressions fail. Queue capture ownership, signed numeric widths, receiver order
and delegate order have focused checks. Exact temporary receiver ownership,
native queue interleavings and device rendering remain unverified. See
[FFmpeg progress provenance](source/Downloads/FFMpegHelper.progress.provenance.md).

Log cleaning now joins lines before the initial whitespace-character-set lookup
and fetches a fresh set after each removed period. Its 2,055 assertions include
648 output cases, changed factory results, filtering order and nil forwarding;
eleven compiled regressions fail. See
[log-cleaning provenance](source/Downloads/FFMpegHelper.log.provenance.md).

Caption-language lookup now explicitly calls the dictionary factory. The prior
literal compiled into a constant dictionary and omitted that original operation.
The command/language audit checks all 80 ordered language pairs and 928 command
cases, with 8,313 assertions and twelve rejected regressions. The emitted iOS
method also retains the 80-entry factory call. See
[command and language provenance](source/Downloads/FFMpegHelper.command.provenance.md).

The FFmpeg lifecycle audit verifies superclass nil/replacement results, queue
replacement and processing-reset order, singleton receiving-class behavior and
strong-ivar destruction order. Four isolated process runs pass 153 assertions;
eleven compiled regressions fail. These contracts complete the focused named
method catalogue for this class. Native queue operation, concurrent singleton
access and device behavior remain unverified. See
[lifecycle provenance](source/Downloads/FFMpegHelper.lifecycle.provenance.md).

Parity requires checking the first package's implementation, initializer and
callback behavior, and verifying its deployment on a device.
The current reconstruction also retains documented download-path argument guards
and local preference-policy differences. Twenty authentication, attestation,
app-origin verification or permission-bypass registrations and historical
account/bootstrap effects remain excluded. On-device behavior remains untested.

`evidence/integration-verification.json` proves the documented selection and
current artifact linkage. It must not be interpreted as proof of first-package
parity.
