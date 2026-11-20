# Speed popup fidelity audit

All 16 packaged method records are present in `YTPSpeedPopupController.m`. The iOS audit verifies their exact encodings, both owned properties and three relative ivar layouts. `verify_speed_popup.py` executes the actual source against isolated UIKit boundaries, including all four animation callbacks, layout constraints, gesture transitions and strong property ownership. Its 255 assertions pass under UBSan.

Evidence comes from the supplied ARM64 image with SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. `recovery/evidence/speed-gesture-fidelity.json` pins all 16 method functions and four anonymous callbacks, totaling 1,507 original instruction words. The read-only evidence verifier checks those complete function hashes, six recorded indirect branches, two separately decoded branch tables, numeric constants, decoded strings and wrapper targets.

## Corrections proved by original instructions

The factory at `0x235b74` loads the concrete `YTPSpeedPopupController` class rather than allocating the message receiver. The subclass-factory regression failed with `[self new]` and passes with the concrete class.

`isiPad` at `0x236660` reads `currentDevice` again for each model test. It first checks the initial device idiom, then optionally asks a second device for an `iPad` model substring, and finally asks a fresh device for the exclusionary `iPhone` substring. The former cached-device source failed the read-count fixture. The new fixture checks every idiom/model combination and a device sequence that changes between reads.

`calculateWidth` at `0x236564` takes the first screen read's width and the second screen read's height. `FCMP d8,d9` and `FCSEL ... MI` at `0x2365ec..0x2365f0` choose width only when width is less than height. The prior reversed comparison agreed for finite sizes but differed for NaN. Source and tests now preserve the exact selection, then apply 0.5 for iPad or 0.95 otherwise.

The dismissal thresholds in the old reconstructed `handlePan:` were reversed by a decompiler register mistake. Original instruction `0x236cdc` saves translation.y in d8; `0x236e0c` saves velocity.y in d9. The comparisons at `0x236e20` and `0x236e30` therefore mean translation.y > 120 points or velocity.y > 600 points/second. The table at `0x236e60` selects spring-back at `0x236e64` or dismissal at `0x23704c`. Dismissal stores d9 into `_dismissVelocity` at `0x237054`. The corrected independent threshold matrix failed against the prior reversed condition and passes after the fix.

## Layout and callbacks

`viewDidLoad`, original `0x235d64`, forwards to super, assigns a black background at alpha 0.1, adds a delegated dismiss tap recognizer to the root view, and creates the canonical speed-control view. Its grabber uses label color at alpha 0.3, radius 2.5 and disabled autoresizing translation. Seven constraints specify grabber top 8, centered X, width 36 and height 5; the speed view is horizontally centered, uses `calculateWidth`, and starts at its height plus 20 below the root safe-area bottom. Its pan recognizer belongs to the speed view. The fixture checks each anchor's identity and constant; the control view itself is an explicit host boundary owned and tested separately by the parent.

`viewDidAppear:`, `0x235c0c`, forwards animated to super, sets the bottom constant, then schedules duration 0.4, delay 0, damping 0.8, initial velocity 0.5, ease-out, with no completion. Callback `0x235d04` reads the controller's current view and lays it out. The fixture swaps that view before invoking the retained callback to prove its capture semantics.

`dismiss`, `0x236a38`, sets bottom to speed-view height plus 50, then schedules duration 0.3, delay 0, damping 1, initial velocity `_dismissVelocity / 1000`, ease-in. Callback `0x236b84` clears the current root background and lays it out. Completion `0x236c30` dismisses without animation or another completion, regardless of the animation's finished flag.

Changed pan gestures use root-view coordinates even though the recognizer belongs to the speed view. Positive displacement moves directly; upward displacement uses 0.15 resistance through the original fused multiply-add at `0x236f34`. A non-notched -2.66-point regression proves the single-rounding result; the previous separated multiplication/addition differed by one ULP and failed that test. Source now calls `fma` explicitly. Background alpha falls from 0.1 to zero over 200 downward points. Original `FMAXNM` at `0x236f90` treats NaN as zero for the alpha clamp; the existing `fmax` source already matched and is retained. Ended and cancelled states both use the corrected dismissal test. Other states do nothing after reading translation. Spring-back restores bottom and schedules duration 0.3, damping 0.7, velocity 0.5 and ease-out; callback `0x2370a4` restores black alpha 0.1 and lays out. The fixture checks threshold equality, both ending states, other states, positive/negative/NaN displacement and deferred callback effects.

`gestureRecognizer:shouldReceiveTouch:`, `0x23719c`, admits only touch.view identical to the root view, preserving touches within controls. `hasNotch`, `0x236994`, uses the application delegate's window top safe-area inset strictly greater than 20. `bottomConstant`, `0x236634`, returns zero with a notch and -10 otherwise.

## Rerun and limits

Run `python3 recovery/tools/verify_speed_popup.py`. It performs the byte audit, iOS metadata audit and actual-source runtime fixture. No UIKit app, playback session or network service is invoked. The fixture captures animation scheduling and executes callbacks explicitly; it does not establish visual rendering or animation interpolation on a device. Post-operation supervisor calls remain omitted and individually pinned in the evidence. There is no new installer or startup change. The parent owns shared source lists and the canonical `YTPSpeedControlView` implementation.
