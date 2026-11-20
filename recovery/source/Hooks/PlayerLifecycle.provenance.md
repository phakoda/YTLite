# Primary player lifecycle recovery

`PlayerLifecycle.x` reconstructs every `YTPlayerViewController` registration in the packaged primary registrar `0x53fac`: four replacements and six added methods. `PlayerLifecycleHelpers.m` also recovers both time helpers and the shared loop flag. There is no automatic constructor. Integration calls `YTLInstallPlayerLifecycleHooks()` in the original primary registration position and compiles the helpers once.

| Selector / helper | Packaged implementation | Kind |
| --- | --- | --- |
| playbackController:didActivateVideo:withPlaybackData: | 0xa36d0 | Replace |
| restoreLoopMode | 0xa4158 | Add |
| autoFullscreen | 0xa4a00 | Add |
| setAutoSpeed | 0xa4b94 | Add |
| selectCaptions | 0xa51f0 | Add |
| autoQuality | 0xa6b30 | Add |
| selectAudioTrack | 0xa8894 | Add |
| singleVideo:currentVideoTimeDidChange: | 0xa9c2c | Replace |
| potentiallyMutatedSingleVideo:currentVideoTimeDidChange: | 0xa9cd8 | Replace |
| dealloc | 0xa9d84 | Replace |
| addEndTime | 0x4b50c | Global function |
| autoSkipShortsLegacy | 0x4bf90 | Global function |

The canonical evidence is the ARM64 image extracted from the supplied `iphoneos-arm.deb`, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The manifest records the exact authoritative registrations, original IMP slots, complete original function-span hashes, constant strings, critical instruction words, and decoded branch tables. Expanded pseudocode under `.recovery-work/readable/analysis-v3/` was a navigation aid; instructions resolved its incomplete quality function and incorrect floating-point casts.

## Behavior supported by original bytes

Activation cancels the sleep timer and clears `canRememberLoopMode` before forwarding the original call. It schedules quality, fullscreen, speed, captions, audio, and loop restoration in that order, with 0.75-second delays except loop restoration at 3 seconds. Restoration sets loop mode on the matching overlay, enables local looping only for nonzero mode, and sets the flag even when neither matching host is present. Stores at `0xa3e8c` and `0xa49dc` identify its single-byte global at `0x191b7c9`.

The speed method requires a watch parent and uses the eleven packaged float values, without an index clamp. Captions require a watch parent, an active video, and no MDX session. Missing tracks retry after one second; an empty array does not retry. Original-caption selection uses the default audio identifier after replacing `.4` with the empty string; the empty CFString is verified at `0x113acf0`. Exact matches take precedence; permitted generated-caption suffix matches retain the last fallback. Custom language selection preserves the same distinction. Both host caption setter variants are supported, with source zero on the modern setter. A missing selected response getter result aborts selection.

Quality retries missing formats after three seconds. It uses the Wi-Fi or cellular preference, excludes labels containing `Premium` when choosing the highest format or nearest fallback, and retains the first resolution tie. Fourteen packaged choices include 240p and 144p. Mode zero (`Default`) follows the nearest-resolution path rather than returning early. The original array literal requires a nonnil highest label: empty formats, nonpositive resolutions, or Premium-only formats can raise. Invalid indexes can also raise. Those behaviors remain. Original instructions after `0xa7b28`, absent from the truncated pseudocode, establish the complete array, exact search, and nearest search. `0xa8350/0xa8354` perform signed 64-bit subtraction and conditional negation; unsigned arithmetic plus bit copies preserve register wrap without C signed-overflow undefined behavior.

Audio has no watch-parent gate. Missing audio formats retry after three seconds. Selection requires a current audio track, retains the last `.4` original track, and accepts custom identifiers containing the chosen language. The first matching `.3` or `.6` identifier ends the custom search. Other matches retain the last fallback; `.10` is suppressed when `ignoreAutoDub` is true. The new audio constraint preserves DRC, uses nil quality configuration and reason 2, and can carry a nil original track. Captions are reconsidered afterward when enabled, including when the constraint initializer is unavailable.

Both time callbacks forward original arguments first, then invoke end-time formatting and legacy Shorts advancement. End-time calculations use the canonical speed helper and FCVTAS at `0x4bba8/0x4bbc0`: nearest-second rounding with ties away from zero. The subtraction wraps at 64 bits before division by playback rate. The implementation preserves ARM saturation/NaN conversion behavior without undefined casts. Formatting uses `en_US_POSIX`, `HH:mm` or `h:mm a`; the player bar receives the end-time string, while the label appends and resizes only if its current text does not contain that string.

Shorts uses FRINTM at `0x4c6dc/0x4c6f0`, followed by FCMP and LT at `0x4c6f4/0x4c6f8`. Thus completion compares floored times and rejects unordered NaN comparisons. The legacy action is suppressed when `maybeLoopPlayback` exists, the advance selector is unavailable, or the optional engagement-panel ivar is true. The packaged invocation uses `performSelector:` with `reelContentViewRequestsAdvanceToNextVideo:` and supplies no object argument. That unusual call is preserved; tests intercept `performSelector:` and never invoke a real host action.

## ABI and verification

Run `python3 recovery/tools/verify_player_lifecycle.py`. It verifies all original spans and manifest constants, regenerates Logos with the pinned internal generator, compiles the actual production source against the iOS SDK with warnings treated as errors, audits all ten emitted callback signatures and both helper signatures, and runs the generated hook bodies plus helper implementation against isolated host doubles under UndefinedBehaviorSanitizer. The current fixture passes 1,246 assertions, including 64 activation gate combinations, delayed callback execution, original argument identity/order, all speed/quality choices, caption/audio precedence, unavailable host APIs, retries, loop behavior, rounding/floor distinctions, NaN/infinity paths, label updates, and deallocation order. The fixture uses real Foundation collection/string/date formatting; only the clock and external host/canonical-helper boundaries are substituted.

The ten callback ABI signatures carry only object pointers in their argument slots. `singleDimensionResolution` uses a 32-bit integer, matching the vendor header and original W-register comparison. Video constraint setting uses `int`, while its reason uses `NSInteger`, matching the available vendor declaration; the original constant is 2 in either width. Caption source is always zero, and audio reason is always 2, so the binary call sites do not establish their original enum typedef spelling. The typed declarations preserve those exact register values. Loop mode and preference indexes preserve 64-bit values.

This is reconstructed source, not recovered original formatting or local variable names. Dynamic class lookups replace obfuscated lazy class caches; compiled protection bookkeeping and branch-table obfuscation are omitted. Canonical recovered helpers are used. Preference calls currently link the project's shared feature policy; any historical account-based policy differences are owned by integration. No supplied binary was executed, no account/network service was contacted, and no real UIKit/YouTube runtime was driven. Device behavior remains untested. Other primary, SponsorBlock, and RPC hook layers remain separate; their constructor order and duplicate removal belong to the parent integration.
