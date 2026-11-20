# YTPSleepTimer recovery

`YTPSleepTimer.m` restores all 37 packaged methods, including the ARC destructor, and preserves seven ivars. It is included in `recovered.mk`. YouTube's button creation, settings selection and player-lifecycle hooks still need integration; compiling this class alone does not make the timer reachable in the app.

Recovered behavior includes:

- A shared timer, six duration presets, a time-of-day picker, and an end-of-video mode. Both modes select style zero, which updates the player and global status bars.
- A serial dispatch timer firing every second with 100 ms leeway. End-of-video time uses `max(total - current, 0) / playbackRate`. Invalid duration/current-time values return zero; invalid or nonpositive playback rates use one.
- Fading starts when remaining time reaches ten seconds. Values at or below 1.2 seconds stop immediately. Values between 1.2 and five schedule a one-second fade and stop. Larger values fade for five seconds and stop after `remaining - 1` seconds.
- Eleven volume callbacks, from one through zero. Cancellation clears the timer, prevents pending volume/stop callbacks from acting while it remains cleared, hides the bars and restores player volume to one. End-of-video mode cancels when the player closes; a fixed deadline survives it.
- Attributed status labels with a 14-by-14 moon attachment, tap actions, player/global visibility callbacks, pause dispatch and the stopped dialog.

Original behavior retained for review:

- Stopping with no available status bars returns without canceling the timer or pausing playback.
- Tap installation allocates a new recognizer even if the private ivar already contains one. Cleanup clears the ivar without removing recognizers from the view.
- Delayed callbacks test whether a timer exists, rather than identifying the originating timer. Cancellation followed immediately by a restart can therefore admit callbacks from the previous timer.
- A selected time of day that has passed adds exactly 86,400 seconds, rather than one calendar day across daylight-saving transitions.
- Obfuscator supervisor calls are excluded. No account/bootstrap behavior is added.

`manifest.json` pins the original binary hash, method addresses, floating-point constants, instruction intervals and both decoded branch tables in the remaining-time calculation. The decompiler's unresolved tail at `0x214300` was reconstructed from the original instructions through `0x2143d4`.

Run `python3 recovery/tools/verify_sleep_timer.py`. It audits all 37 iOS method encodings and seven ivar layouts, then executes 208 assertions with undefined-behavior sanitization. Dispatch sources and their cancellation checks are real; scheduling is captured so callback ordering and fade values can be tested deterministically. UIKit, YouTube objects, images and dialogs are host doubles. Actual device presentation, audio fading and lifecycle integration remain untested.

The factory fidelity audit corrected `sharedTimer` to use `[[self alloc] init]`. Original block `0x2114b8` loads its captured receiver at `0x2114c0` and calls `_objc_alloc_init` at `0x2114c4`, through thunk `0x218488`. It never dispatches `+new`. The whole-source fixture now calls through a subclass first, whose `+new` and `-init` counters distinguish the paths, and confirms the instance stays shared across subsequent base-class and other-subclass calls. The pre-fix source failed the `+new` counter assertion. Original factory hashes and target evidence are in `recovery/tests/factory_audit_evidence.json`.
