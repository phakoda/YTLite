# ToastWindow ordinary UI fidelity

This pass restores the packaged hit-test traversal and application-window lookup. All nine declared methods have source and actual-source fixture coverage. The supplied binary is never loaded or executed. `ToastWindow.lifecycle.evidence.json` pins the original SHA-256, all nine full method intervals, selected raw instruction words, 18 resolved branch tables, class metadata, decoded constant strings and imported call terminals. Raw method/table bytes come from `EvidenceImage.image.data`; decoded overlays are used only to resolve encoded branch keys and strings, never to infer global initial values.

## Method evidence

| Method | Original start | Verified behavior |
| --- | --- | --- |
| `hitTest:withEvent:` | `0x1c7e28` | Super receives the original point/event; walk every ancestor including the window; return the original hit only after the final root/self/exhaustion checks. |
| `initWithWindowScene:` | `0x1c8b10` | Call super, skip setters if nil, set alert level minus one in double precision, then clear background. |
| `canBecomeKeyWindow` | `0x1c8c00` | Return NO. |
| `makeKeyAndVisible` | `0x1c8c08` | Super first; resign only if the subsequent key-window getter is true. |
| `shouldAffectStatusBarAppearance` | `0x1c8cc4` | Return NO. |
| `_windowControlsStatusBarOrientation` | `0x1c8ccc` | Return NO. |
| `_canBecomeKeyWindow` | `0x1c8cd4` | Return NO. |
| `appKeyWindow` | `0x1c8cdc` | Enumerate `UIApplication.sharedApplication.windows`, returning the first key window, including self; nil when absent. |
| `+initialize` | `0x1c8fb4` | Add the two private aliases using the receiver class and source method's IMP/type. No receiver-class equality guard; existing own methods are not replaced. |

The original hit predicate checks ToastView first, then performs five separate `_viewControllerForAncestor` sends at `0x1c86e8`, `0x1c8744`, `0x1c87a4`, `0x1c8800`, and `0x1c8860`. Their class order is ActionSheet, DefaultSheet, ActionSheet again, BottomSheet, Welcome. The last predicate checks YTTouchForwardingView. The original retains earlier controller results through this short-circuit expression; source expresses it as one condition. There is no `respondsToSelector:` guard and no nil-class guard. Every failed iteration obtains `superview` at `0x1c8958`.

Eleven hit-test table pairs resolve each predicate, loop exit, and final rejection. The original-hit/self comparison at `0x1c89c0` skips the root getter only when they match. Otherwise the root-controller and view getters run at `0x1c8a68`/`0x1c8a80`, even for nil or an exhausted traversal. `CMP`/`CSINC` at `0x1c8a8c`/`0x1c8a90` select rejection for root equality or exhausted ancestry. Root/self rejection happens after the ancestry walk. A descendant can therefore be accepted by an allowed controller on the window itself.

The application lookup sends `sharedApplication` at `0x1c8d34`, `windows` at `0x1c8d4c`, and `isKeyWindow` at `0x1c8ee0`; the true table target `0x1c8f64` retains and returns that window. There is no connected-scene lookup, delegate fallback or self exclusion. Source suppresses only the modern SDK deprecation diagnostic for this historical API.

The two alias registrations are at `0x1c938c` and `0x1c9420`. The original prepares alias names using string components/formatting; source uses their exact resulting literals. Tests cover inherited initialization on children/grandchildren and preservation of an existing own alias.

## Verification and limits

Run `python3 recovery/tools/verify_toast_window.py`. It compiles the unmodified production `.m` with isolated UIKit/private-host identity doubles and real Foundation/Objective-C runtime under UBSan, compares emitted iOS method/property/ivar ABI, then compiles eight independent regressions. Each regression must fail runtime assertions: missing repeated predicate, omitted window ancestor, early hit rejection, cached controller, selector guard, self exclusion, scene/delegate fallback, and guarded subclass initialization.

The initial old source failed 49 of 146 checks; the corrected source passes all 146. Cases include changing controller results per read, unknown runtime classes, a getter that advertises no selector support, every allowed predicate, toast/forwarding descendants, root/self/nil handling, all bool methods, super init failure, key-state changes, first-key ordering and enumeration beyond 16 objects.

The fixture supplies UI objects and getter side effects; it does not prove rendering or private YouTube behavior on a device. ToastView is a boundary class identity, not its separately tested implementation. No production source transformation occurs. The original string-decoder, stack-protector and anti-debug syscall scaffolding is not reconstructed in this ordinary UI pass; authentication, permissions and security behavior are outside this assignment. The modern source remains readable Objective-C, not a byte-identical compilation.

Shared presentation fixtures need a `UIApplication.windows` boundary and an explicitly populated window list. They must allow self when it is the first key window. This pass changes no shared fixture, header, Makefile or manifest.
