# Discord lifecycle hook recovery

`DiscordLifecycle.x` reconstructs all 11 registrations from registrar `0x8540`: ten replacements and one added tap method. The module uses a separate `YTLDiscordLifecycle` Logos group so its saved originals can compose with the SponsorBlock and primary player hooks. It has no automatic constructor. The parent must call `YTLInstallDiscordLifecycleHooks()` at the appropriate point in the central registration sequence.

| Class / method | Original implementation | Behavior and order |
| --- | --- | --- |
| YTPlayerViewController `playbackController:didActivateVideo:withPlaybackData:` | `0x8c38` | Original first; exclude inline-muted and Shorts parents; create media from self, mark unpaused, start if possible |
| YTPlayerViewController `seekToTime:` | `0x92b8` | Original first; parent exclusions; direct defaults gate; assign time, call updateTime |
| YTPlayerViewController `seekToTime:seekSource:` | `0x9a00` | Same sequence; preserve source argument |
| YTPlayerViewController `seekToTime:toleranceBefore:toleranceAfter:seekSource:` | `0xa14c` | Same sequence; preserve both tolerances and source |
| YTPlayerViewController `singleVideo:currentVideoTimeDidChange:` | `0xa89c` | Original first; defaults gate; shared presence, time object's `time`, assign currentTime |
| YTPlayerViewController `potentiallyMutatedSingleVideo:currentVideoTimeDidChange:` | `0xaafc` | Same sequence, with no parent filtering or updateTime call |
| YTWatchPlaybackController `playbackControllerDidPlay` | `0xad54` | Defaults gate; mark media unpaused, updateState; original last |
| YTWatchPlaybackController `playbackControllerDidPause` | `0xaf78` | Defaults gate; mark media paused, updateState; original last |
| YTWatchPlaybackController `playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:` | `0xb19c` | Defaults gate; clearPlayback; original last with transition argument unchanged |
| YTWatchPlaybackController `clearPlaybackController` | `0xb3a0` | Defaults gate; clearPlayback; original last |
| YTMainAppControlsOverlayView `handleYTLDiscordTap:` | `0xb598` | Added method: invert defaults flag; build/start media when enabling or clear when disabling; update sender's adaptive icon in normal state |

The tap's player is exactly `[self _viewControllerForAncestor].parentViewController`. It does not use the overlay's own parent, invoke the player exclusions, or force the media's paused flag. Its image comes from canonical `YTPMedia.adaptiveDiscord` after updating the preference. Unlike the seek/time/watch callbacks, video activation has no direct `discordRPC` preference check; `startIfPossible` remains responsible for its own policy.

Evidence:

- `DiscordLifecycle.manifest.json` records all original registrar records, saved IMP slots, function boundaries, SHA-256 hashes of original function bytes and emitted callback argument classes. The verified ARM package image hash is `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`.
- The original seek functions preserve `d0` into `d8` (`0x92d4`, `0x9a1c`, `0xa168`), restore it before calling the original (`0x982c`, `0x9f78`, `0xa6c8`) and later pass it to `setCurrentTime:`. The available vendor header also declares `seekToTime:` with `CGFloat`, which is double on ARM64. Source/tolerance arguments are not inspected or modified before the saved original call.
- Periodic time callbacks preserve and retain the object from `x3`. `0xaa74`–`0xaa84` sends `time` to that object and preserves the result from **d0**, establishing a double-valued getter rather than a scalar callback argument. `0xaa88`–`0xaab0` gets media and forwards the preserved double to `setCurrentTime:`. The shared-presence lookup happens before the time getter.
- The finish callback saves full `x2` to `x19` at `0xb1b0`, then restores full `x2` at `0xb36c` before calling the original at `0xb370`. Its value does not affect the clear operation.
- All feature checks are **class** calls `[YTLUserDefaults boolForKey:@"discordRPC"]`, not `ytpBool` or direct NSUserDefaults instance calls. The tap uses the corresponding class setter.
- No nested asynchronous blocks occur within these 11 callback bodies. The package's outer registration block is separate: initializer `0x850c` passes global block `0x1061400`, whose invoke is `0x8540`, to `ptnRegisterBlock`. The parent owns this historical registration policy and cross-group ordering.

Host ABI limits and reconstruction differences:

- Original YouTube method metadata is not included in the tweak. The seek-source and finish-transition arguments are only forwarded in an integer register; their original enum/integer/BOOL spelling and signedness cannot be recovered from these instructions. `YTLDiscordForwardedInteger` is a `uintptr_t` boundary type that preserves the entire original `x2` slot without a narrowing conversion. This is register-compatible forwarding, not a claim to have recovered unavailable host declarations. The tolerances retain their floating-point argument slots.
- Canonical `RPCMedia`, `YTPDiscordRPC`, `YTPMedia` and `YTLUserDefaults` are used. Class-name checks remain dynamic and perform two parent queries unless the inline-muted check succeeds, matching the packaged sequence.
- Obfuscator string initialization, opaque dispatch tables, explicit ARC retain/release scaffolding and supervisor instructions are replaced by ordinary Objective-C. No RPC behavior is otherwise intentionally omitted. Exact compiler-local variable names and formatting are unavailable.

Run `python3 recovery/tools/verify_discord_lifecycle.py`. It verifies all original-byte ranges, exact registration operations, and all 11 generated iOS LLVM callback signatures. It then executes the actual Logos output on host doubles under undefined-behavior sanitization. All 1,312 assertions pass. Tests check full event ordering, original self/selector/object/integer arguments, both gate states, nil/ordinary/inline-muted/Shorts/subclass parents, all three seek forms, negative zero/NaN/infinity/large fractional values, both tolerance arguments, periodic time objects, pause/play/finish/clear, nil media/factory results and both tap branches. The added tap is verified absent before installation and present afterward. Helper and UIKit classes are isolated doubles; no external RPC server, real pasteboard or UI is touched and the supplied binary is not loaded. Device RPC delivery and full cross-group registration order remain integration work.
