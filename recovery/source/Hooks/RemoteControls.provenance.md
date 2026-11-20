# RemoteControls recovery

All three assigned registrations and the shared helper at `0xbc45c` are reconstructed in `RemoteControls.x`. The early installer registers `MPRemoteCommand.addTarget:action:` (`0x4e6fc`, original slot `0x1225f38`) and `MPNowPlayingInfoCenter.setNowPlayingInfo:` (`0x4e8fc`, slot `0x1225f40`) from registrar `0x4cf00`. The main installer registers `YTWatchController.handleRemoteControlEvent:withInterval:` (`0xaa244`, slot `0x1226668`) from registrar `0x53fac`. Both installers are exported without constructors; the parent owns original ordering.

`addTarget:action:` forwards first and obtains the shared command center. If self is its previous-track command and byte `0x1226848` is clear, it registers the same target and selector on the skip-backward command, then sets the byte. The next-track command similarly uses skip-forward and byte `0x1226849`. Both flags are process-wide, initially clear, and persist across command-center replacement. Registration is independent of skip preferences. The callback then updates command settings on every invocation, including nested skip registrations and unrelated commands.

Original branch `0x4e7f0` could not be expanded by the decompiler. Table `0x117a298`, constant `0x117a2a8`, XOR `0x17bee725` yields destinations `0x4e7f4` (register backward) and `0x4e830` (continue). Index is `(self != previousTrackCommand || backwardRegistered) & 1`. The forward table at `0x117a2b8` yields `0x4e894` and `0x4e8d0`, using the corresponding next-track predicate. Original byte stores at `0x4e82c` and `0x4e8cc` occur after the nested call returns. Reentrant fixtures prove this timing: a nested skip callback that registers the original track once more produces a second skip registration before either flag is set.

The shared helper obtains the shared command center and reads `rcSkipBackward` and `rcSkipForward` through two separate `YTLUserDefaults.standardUserDefaults` calls. It sets one-element preferred interval arrays using the class `floatForKey:` accessor for `rcSkipBackwardSec` and `rcSkipForwardSec`. Despite the selector spelling, that class accessor returns double; the original directly supplies `d0` to `NSNumber.numberWithDouble:`. It then sets skip-backward and skip-forward enabled states from those preferences, followed by previous-track and next-track enabled states with the respective inverses. There is no interval clamping or fallback. Negative values, signed zero, infinities, and NaN remain unchanged.

`setNowPlayingInfo:` forwards its exact dictionary argument before calling the same updater. Changes made by the original method are therefore visible to the subsequent preference reads.

The watch callback treats its event as signed 64-bit and its interval as double. Event 105 reads `ytpBool(rcSkipBackward)`; when true it forwards event 108 and the negated double from `rcSkipBackwardSec`. Event 104 similarly uses `ytpBool(rcSkipForward)` and the unchanged double from `rcSkipForwardSec`. Other events and disabled branches forward the incoming event and interval without conversion. The recovered branch table `0x11810a8` at both `0xaa334` and `0xaa7d0` splits on signed `event < 105`; subsequent exact equality checks reject other values. `0xaa3c4` uses `fneg d8,d0`, and `0xaa878` forwards the saved `d8` in `d0`.

The watch callback intentionally calls the canonical `ytpBool` boundary, whose current local preference implementation is parent-owned. The updater uses direct instance defaults, as the original does. The module introduces no activation, credential, network, or attestation logic.

There are no blocks or weak captures in these functions. The original retains its target for the duration of `addTarget:action:` but stores no target globally. The only behavioral globals are the two registration bytes; decoded-string initialization state and protection syscalls are omitted.

Run:

```sh
python3 recovery/tools/verify_remote_controls.py
```

The verifier checks exact registration coverage, six original instruction intervals, 14 decoded-string records, six existing branch records, and eight explicit original table calculations, including previously unresolved branches. Pinned Logos generates the actual source. The iOS arm64 LLVM audit verifies void hook returns, pointer arguments, the signed 64-bit event, double interval, and double negation.

The generated source runs under UndefinedBehaviorSanitizer with mocked MediaPlayer classes and synthetic preferences: 470 checks in each backward-first and forward-first process, plus 34 in each of two reentrant registration processes. Tests verify separate installation groups, exact target/selector forwarding, nested call order, flags surviving center replacement, fresh preferences, setter ordering, all Boolean combinations, precision beyond float, numeric edge cases, all event branches, unchanged NaN payload forwarding, and absence of retained global targets. No actual remote commands are registered. The package is inspected, never executed; live MediaPlayer and YouTube integration remain untested. No assigned callback behavior remains unresolved.
