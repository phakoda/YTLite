# DownloadMenuHelper audio actions, first-package audit

The audio menu now uses the first package's allocation and evaluation order.
Both top-level menu constructors and the shared toast factory send `alloc` and
`init`, and the audio storage callback does the same for `YTLHelper`. Each audio
handoff formats its filename after reading the root's current helper and
constructing the format URL. It also does so in the delayed track-selection
callback. Localized errors create their toast before looking up the message.

Previously these constructors sent `new`. The audio storage callback also built
one filename before choosing a track, so the delayed selector reused that early
string. Localized error text was resolved before toast construction. The new
fixture distinguishes these behaviors by recording calls and changing the
captured title/author objects during URL evaluation.

## Original evidence

The principal method is `+showDownloadSheet:withSender:` at `0xf7c6c..0xf9c78`.
The audio action is `0xf9db8..0xfa118`, storage completion is
`0xfa118..0xfad5c`, and track-selection completion is `0xfad5c..0xfb020`.
The evidence file pins these bodies, 14 constructor sites across the class and
their `objc_alloc_init` wrappers: 46 spans, 85 adjacent selector loads and five
decoded string records. Class-reference loads and each wrapper call target are
checked against the first binary. The constructor survey also supports the
shared toast change and the Shorts menu constructor change; it does not claim
full first-package coverage of their other paths.

`YTLHelper` allocation is at `0xfa580`. The no-track path reads `helper` before
`URL`, constructs the URL, and only then formats the name at `0xfab14`.
The default, best, English and explicit-selection paths use the same order;
the delayed selector's formatting call is `0xfaeac`. Both filename constants
at `0x1185ca0` and `0x1185cf0` decode to `%@ - %@`.

When an audio track is present, the storage callback independently reads
`ytlAudioIndex` four times. A changing preference can therefore start more than
one branch. A missing default track causes no URL or filename construction.
A missing English track reports its error before the fourth preference read.
A nil selected track does nothing. Nil helper receivers still evaluate their
arguments. Sizes and durations retain all 64 bits.

The missing-size error allocates the toast at `0xf9f7c`, gets the bundle at
`0xf9f94`, localizes at `0xf9fbc`, then displays the failure. The English error
uses the same order at `0xfab98`, `0xfabb0`, `0xfabd8` and `0xfabfc`.
Four system-trap instructions in the pinned principal bodies remain omitted.
The snapshot/callback audit does not restore or validate those effects.

## Verification

Run:

```sh
python3 recovery/tools/verify_first_menu_audio.py
python3 recovery/tools/verify_first_menu_pipeline.py
python3 recovery/tools/verify_downloads.py
```

The actual menu, media utility and local preference policy pass 176 focused
assertions. The suite covers normal action order and sender, deferred storage
and track selection, every track preference, changing preferences, error paths,
filename timing, nil receivers/selections and wide integer arguments.

The verifier rejects five isolated regressions: menu `new`, audio-helper `new`,
shared-toast `new`, filename formatting before the URL, and localization before
toast creation. It also compares all 26 compiled menu method encodings directly
with the first package on arm64 and arm64e. Those ABI results do not establish
behavior of the other menu methods.

UIKit, formats, format-selection helpers, storage checks and downstream downloads
are synthetic boundaries. The fixture invokes the real menu's action blocks;
it does not execute packaged code, fetch URLs or download media. Exact block
ownership, native appearance, the remaining menu paths and device integration
remain unverified here. Local preference-policy differences remain documented.
