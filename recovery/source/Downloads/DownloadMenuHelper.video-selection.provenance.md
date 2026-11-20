# Video audio selection and caption handoff

Target: the first supplied `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`.
Run the reproducible static and actual-source checks with:

```sh
python3 recovery/tools/verify_first_menu_video_selection.py
```

## Recovered change

The caption branch of `downloadVideoWithFormat:withAudioFormats:fileName:extension:videoID:playerVC:sender:`
reads `response.playerData.videoDetails.title` at `0x105d80–0x105db4`, then
fetches player data and video details again for `author` at
`0x105ddc–0x105e08`. It retains the returned title rather than copying it.
The previous reconstruction reused one details object and read author first.
The source now follows the original order and repeated getters. A fixture changes
video details during title access to distinguish the two implementations, and
another mutates the returned title during author access to distinguish retention
from copying. The resulting filename is `author - title`.

## Inspected control flow

The primary method starts at `0x104f2c`, reads the supported player response and
returns when it is nil. It captures the response and arguments and reads
`ytlAudioIndex` once. Values 0, 1 and 2 select default, best and English audio;
3 opens the deferred selector. Other values do not start a download.
Missing English audio sets the localized error before invoking the shared
continuation. Error handling returns before reading the caption preference.

The continuation at `0x1058dc` first checks its captured error. Otherwise it reads
`downloadWithCaps` and, only when enabled, checks `hasCaptions:`. The caption path
recomputes the filename and lowercases the extension. The direct path keeps the
supplied filename and extension and reads the current video/audio URLs, content
lengths and video duration. The deferred audio callback at `0x106030` replaces
the shared audio selection only for nonnil results, then invokes the continuation.
An initial nil selection proceeds with nil audio; a later nil selection preserves
the previous selection.

The caption-handoff method at `0x10618c` passes a retained completion to
`getCaptionsUrlSheet:sender:completion:`. Its callback at `0x10631c` returns for a
nil caption URL. A nonnil result reads the current video/audio URL properties,
video content length, audio content length and video duration, then forwards the
caption URL and original arguments. This handoff required no source correction.

## Verification and limits

The verifier pins the two named bodies, their continuations/copy/dispose helpers
and the wrapper interval. It checks four initialized CFStrings, 29 adjacent
selector loads, 11 decision tables and 290 direct calls against the first dylib.
Thirteen original system-trap instructions in these spans remain omitted.
Their omission is a known fidelity limit, not a passing behavior check.

The actual-source fixture runs 150 checks covering preference values, caption
branches, deferred callbacks, repeated nil selections, changing metadata and URL
properties, 64-bit sizes/duration, nil responses and missing audio. Four isolated
mutations must fail. The prior implementation failed the two title/author lookup
checks before the retention case was added.

The fixture keeps strong references to inputs and manually invokes retained
callbacks. It therefore checks deferred dispatch and shared selection behavior,
not complete block-capture lifetime or exact ARC release timing. Localization
rendering, real caption fetching, downstream downloads and device integration
are not exercised. The existing menu audio and pipeline audits cover their own
constructor and downstream-handoff behavior. Local preference policy and omitted
system effects remain documented differences; full package parity is unproven.
