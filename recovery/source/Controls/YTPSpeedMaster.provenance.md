# Speed master fidelity audit

All twelve packaged method records remain implemented. The iOS audit verifies exact method encodings and ten relative ivar layouts. `verify_speed_master.py` executes the actual source under UBSan with intercepted playback objects, toast presentation and deferred scheduling; 329 assertions pass. This includes the previous pending-rate first-use regression and the newly audited gesture flow.

The supplied ARM64 image is pinned to SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. `recovery/evidence/speed-gesture-fidelity.json` records all twelve method bodies and singleton/reset callbacks `0x22391c` and `0x225090`, totaling 3,190 original words. The verifier checks every word against the original image, complete function hashes, 26 recorded indirect branches, three separately decoded tables, numeric constants, decoded CFStrings and imported wrapper targets.

## Singleton allocation dispatch

The original once callback `0x22391c` loads its captured class receiver from block offset +0x20 at `0x223924`, original word `f9401000`, then calls wrapper `0x226a70` at `0x223928`, word `94000c52`. The verified wrapper resolves to `_objc_alloc_init`. It does not send `+new`. Source now uses `[[self alloc] init]` inside the existing `dispatch_once`, preserving the captured receiver class.

A subclass-first regression runs before any singleton request in the actual-source fixture. Its subclass overrides `+new` and counts `-init`. Before the fix, verification failed at `singletonNewCalls==0`; the command output is retained in `.recovery-work/speed-master-tests/singleton-subclass-red.json`. After the fix, the subclass singleton is created without invoking its `+new`, init runs exactly once, and subsequent subclass/base requests return that same object. The seven new assertions pass alongside all existing gesture and pending-rate checks. The verifier explicitly pins the two original instructions and wrapper terminal, in addition to the complete function hashes.

## Rounding and comparison corrections

The decompiler's integer-looking casts concealed distinct ARM64 floating-point operations. These corrections are based on original instructions, not inferred from the prior source.

| Original instruction | Operation | Recovered behavior |
| --- | --- | --- |
| `0x2251c0`, `1e664000` | FRINTA d0 | Dense speed-array values round accumulated rate × 100 to nearest integer, ties away, then divide by 100. |
| `0x224c60`, `1f410800` | FMADD d0 | Continuous finger movement uses one fused multiply-add with the base rate. |
| `0x224c80`, `1e664000` | FRINTA d0 | Continuous movement rounds rate / step to nearest integer, ties away, then multiplies by step. |
| `0x224f9c`, `9e640017` | FCVTAS x23,d0 | Primary preset movement rounds its index delta to nearest integer, ties away. |
| `0x224ce8`, `9e780017` | FCVTZS x23,d0 | The second preference-recheck branch truncates its index delta toward zero. |

The previous source truncated the first, third and fourth operations. The independent dense-array test failed on its decimal sequence before the corrections. It now checks all 196 returned rates. Finger tests cover asymmetric primary preset thresholds, positive and negative continuous displacement, the 40-point sensitivity transition, clamping, NaN/infinite values and the distinct truncating fallback branch. `YTLControlsInt64` is unchanged and supplies ARM64 zero-for-NaN/saturating conversion semantics after primary rounding. Original integer addition wraps before signed clamping; the tests cover overflowing positive/negative index deltas.

Continuous clamping at `0x224c68..0x224c74` compares maximum against rate, then minimum against rate, selecting with MI. An unordered computed rate consequently becomes minimum 0.25. The prior reversed comparison selected maximum. The source now follows the original operand order and uses explicit `fma` to preserve the fused operation.

`nearestIndexForRate:`, `0x22545c`, reads every candidate through floatValue, compares absolute distance against the best distance and updates only on MI at `0x225558..0x225560`. Source now uses `candidate < distance`; NaN candidates are ignored, a NaN target retains the default index 2, and finite ties keep the first candidate. The prior negated less-or-equal expression incorrectly selected NaNs.

## Gesture states and capture behavior

`manageSpeedMaster:playerOverlayVC:`, original `0x223960`, refreshes controller ownership, speed mode/array, minimum 0.25, maximum 5 or 10 and step 0.05 for every event. It localizes `Toast.PlaybackSpeed` and reads the preferred playback rate before dispatching on gesture state.

Began captures the gesture-view location and current owner playback rate, computes the preferred rate's nearest index, records the preferred base rate, sets it, and shows PlayerToast with style 1 and the compact preference. Changed plus adjustByFinger uses vertical displacement from the captured starting point. Preset mode multiplies upward displacement by 0.02 and downward displacement by 0.06, then uses FCVTAS and clamping. Continuous mode uses sensitivity 0.01 inside an absolute 40-point displacement and 0.05 outside, followed by fused computation, clamping and rounded quantization. The toast reads back current playback rate after setting.

The original has a second state and adjustByFinger evaluation after the first gate fails. That path divides displacement by 30, truncates with FCVTZS and updates the preset index. It can be reached if the preference changes between reads. The runtime fixture supplies a false-then-true preference sequence, checks the state-read count and verifies the 20-point displacement does not round up.

Only ended performs the restore/preserve flow. Cancelled, failed and possible states do not restore or hide the toast. Without preserveSpeed, ended restores the captured rate and updates then hides PlayerToast. With preservation it formats the current rate after narrowing to float, displays a five-second progressive toast with localized `SpeedPreserved` and `ResetSpeed`, then hides PlayerToast. Block `0x225090` captures the master, not a numeric snapshot. When invoked later it reads `_rateBeforeSpeedmaster` from that master. The fixture begins another gesture before invoking the old reset action and verifies the newer captured rate is used.

The packaged ended-state alpha check throws a local anti-tamper exception if another view hid the toast. Its branch at `0x224a44` is retained in evidence. The existing local policy intentionally omits that exception, so the recovered source's normal completion is not claimed to match this exceptional branch. All post-operation supervisor calls remain omitted and are pinned separately.

## Pending rate and existing playback helpers

The pending playback-rate global at original address `0x11ce3e0` starts at double 1.0; its raw bytes are `00 00 00 00 00 00 f0 3f`. These bytes come directly from the packaged image. The decoded-byte overlay may include later runtime stores and is not used for initial-state evidence.

`_applyPendingRateForPlayer:`, `0x2265dc`, reads that global at `0x2268f8..0x226908` and narrows to float for the host model at `0x226938`, while its notification preserves the double. The first fixture operation applies the pending rate before any setter, preserving the prior regression test. Nil-player and native-rate setters leave the pending value unchanged; two deferred targets receive the latest shared value. Instance rate methods use the gesture's controller parent, while class lookup uses the canonical player helper. Model construction, delayed scheduling and notifications remain in their existing source paths.

Run `python3 recovery/tools/verify_speed_master.py`. Host playback, toast UI and scheduling use explicit fixture boundaries; no YouTube runtime or network service is loaded. Gesture tests execute the real manager and numeric helpers, with a subclass intercepting rate reads/writes to expose their ordering and values. This verifies controller state and callback behavior, not device rendering. The popup has a separate actual-source fixture; the parent owns `YTPSpeedControlView`, shared numeric helpers and integration files.
