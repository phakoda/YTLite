# Bounded factory allocation audit

The audit searched `recovery/source` and `Utils` Objective-C source for factories allocating `self` with `alloc` or `new`, then checked 11 first-party singleton methods against the supplied package. This is an allocation-target and dispatch audit, not a complete behavior audit of those classes. It found one wrong concrete target and three incorrect `+new` dispatches. The parent and Discord worker independently own the speed control-view and speed popup factory corrections; those are outside these 11 records. `Reachability` is third-party source and has no matching class in the supplied first-party class inventory, so this audit makes no claim about its two receiver-allocating factories.

The immutable evidence is `factory_audit_evidence.json`: original binary SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`, method/callback addresses and SHA-256 for all 22 original instruction spans. Run `python3 recovery/tools/verify_factory_audit.py` to recheck the bytes and the corrected complete `ToastManager` implementation.

| Class factory | Method | Once callback | Original allocation | Finding |
| --- | --- | --- | --- | --- |
| `SBManager sharedManager` | `0x199848` | `0x1998fc` | Captured receiver, alloc/init | Target and dispatch already match. |
| `DVNMediaPicker sharedPicker` | `0x1a31a0` | `0x1a3254` | Captured receiver, alloc/init | Changed `self new` to `[[self alloc] init]`. |
| `YTPMedia sharedMedia` | `0x1aa774` | `0x1aa828` | Captured receiver, alloc/init | Target and dispatch already match. |
| `ToastManager sharedManager` | `0x1c9b1c` | `0x1c9ba4` | Concrete `ToastManager`, alloc/init | Changed receiver allocation to concrete allocation. |
| `AudioManager sharedInstance` | `0x1ced8c` | `0x1cee40` | Captured receiver, alloc/init | Target and dispatch already match. |
| `YTLUserDefaults standardUserDefaults` | `0x1e677c` | `0x1e6830` | Captured receiver, alloc then suite initializer | Target and dispatch already match. |
| `FFMpegHelper sharedInstance` | `0x1f4150` | `0x1f4204` | Captured receiver, alloc/init | Target and dispatch already match. |
| `YTPSleepTimer sharedTimer` | `0x211404` | `0x2114b8` | Captured receiver, alloc/init | Changed `self new` to `[[self alloc] init]`. |
| `YTPDiscordRPC sharedPresence` | `0x21b498` | `0x21b54c` | Captured receiver, alloc/init | Target and dispatch already match. |
| `YTPSpeedMaster sharedMaster` | `0x223868` | `0x22391c` | Captured receiver, alloc/init | Confirmed `self new` mismatch; correction and whole-source regression delegated to Discord worker. |
| `PlayerToast sharedToast` | `0x23b468` | `0x23b51c` | Captured receiver, alloc/init | Target and dispatch already match. |

All nine ordinary receiver/alloc-init callbacks have original word `0xf9401000` at entry+8, loading the captured class from block offset 32. The following BL at entry+12 resolves through original wrapper instructions to `_objc_alloc_init`. This matters when a subclass overrides `+new`: the source expression `[self new]` invokes that override, whereas the packaged call dispatches allocation and initialization directly. This is an observed method-dispatch difference, not a preference for one source spelling.

`ToastManager` instead loads its class reference at `0x1c9bb0` and calls alloc/init at `0x1c9bb4`. Its global block's invoke pointer and concrete class reference are checked separately. The receiver-based `YTLUserDefaults` callback uses `objc_alloc` followed by `initWithSuiteName:` and `registerDefaults`; it correctly retains this distinct initialization sequence.

An initial scratch probe extracted the exact four factory methods into an allocation-only host executable. It demonstrated the subclass differences but was only preliminary. The committed regressions execute the complete production source files:

- `verify_factory_audit.py`: complete `ToastManager.m`, 18 assertions across separate subclass-first and base-first processes, with zero subclass allocation/initialization calls and stable shared identity.
- `verify_media_picker.py`: complete `DVNMediaPicker.m`, 94 assertions, including a subclass-first factory call that must bypass overridden `+new`, initialize once and remain shared with base/other subclasses.
- `verify_sleep_timer.py`: complete `YTPSleepTimer.m`, 208 assertions, including the same receiver-dispatch regression and the existing timer behavior suite.

All three factory regressions failed with the previous source and passed after correction. All three focused runs also pass their iOS metadata audits and UndefinedBehaviorSanitizer. The media fixture confines file operations to synthetic temporary files; all picker, toast, player and dialog operations use host doubles. The original dylib is never executed. Results for the separately owned `YTPSpeedMaster` correction belong to that module's verifier.
