# Normal menu construction recovery

The target is the first supplied `iphoneos-arm64e` package. Its normal menu is
`+showDownloadSheet:withSender:` at `0xf7c6c..0xf9c78`. This audit supplements the
[audio callback audit](DownloadMenuHelper.audio.provenance.md). It does not add a
new method to the audit index or establish complete menu parity.

The reconstruction now reads title through `playerData` and `videoDetails` at
`0xf8be4`, `0xf8c04` and `0xf8c1c`, then author through a fresh chain at
`0xf8c4c`, `0xf8c60` and `0xf8c78`. Both values are read before shortening.
Author is shortened first, using the unsigned 30-unit comparison at `0xf8cac`;
title follows with the 200-unit comparison at `0xf8d5c`. Both append the decoded
ellipsis at `0x1185b30`. The old reconstruction reused one details object and
shortened title before reading author.

The first binary reads sheet cache `0x1227020` at `0xf8e98`, resolves an empty
cache at `0xf8ed8` and stores it at `0xf8edc`. It reads resource cache `0x1227028`
at `0xf8f40`, resolves it at `0xf8f88` and stores it at `0xf8f8c`. The reconstruction
now uses the shared cached sheet and chevron helpers already recovered for other
menus. Failed lookups still retry. The unused uncached chevron helper was removed.
The action cache remains `0x1227030`; the audio action reads it at `0xf9750`.

Video availability uses the first live-playback read at `0xf8fe0`. After the
navigation actions, a fresh `playerData` call at `0xf96c0` precedes the second
live-playback read at `0xf96d4`, which controls audio availability. Caption
availability calls `hasCaptions:` at `0xf951c`. The five navigation callbacks at
`0xf9c78`, `0xf9cb8`, `0xf9cf8`, `0xf9d38` and `0xf9d78` load helper, player and
sender from offsets 32, 40 and 48 and forward to their respective sheet methods.

## Verification

Run `python3 recovery/tools/verify_first_menu_normal_construction.py`.

The verifier checks the original archive and binary hashes, two byte spans,
38 adjacent selector loads, 403 direct call targets, 14 decoded strings, three
class names, ten branch tables, three cache references and 16 instruction words.
The decoded constant writes must stay within the reviewed string buffers.
The supplied binary is parsed as data and never loaded or executed.

The fixture invokes the actual reconstructed menu with synthetic host boundaries.
It checks metadata getter order using a title getter that changes the details
object, cache retries and reuse, header and presenter selection, action order and
icons, retained navigation arguments after releasing the sheet, all combinations
of changing live state and caption availability, 49 metadata length pairs, and
nil metadata, helper, response and player results. Before the source correction,
789 assertions produced two failures: metadata order and successful cache reuse.
The corrected source passes all 789 assertions.

Eight independently compiled regressions must fail: reused metadata, title-first
shortening, uncached sheets, uncached resources, unconditional video, unconditional
audio, missing captions and an incorrect navigation sender. All 26 compiled menu
method encodings are compared with the original on arm64 and arm64e. The separate
176-assertion audio suite remains required for its deferred callbacks.

Six original system traps in the pinned spans remain omitted. Temporary object
lifetimes, native appearance and device integration are not established by this
fixture. Dynamic local class lookup for ToastView and the local preference policy
remain documented differences. Build success and these focused checks do not
prove parity with the supplied package.
