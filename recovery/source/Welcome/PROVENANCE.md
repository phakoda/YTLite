# WelcomeVC recovery

`WelcomeVC.m` reconstructs all 13 packaged methods, including the ARC-generated destructor. Its 4 protocol properties, both own ivars and method encodings match the iOS binary. The class includes the complete welcome table, header and footer, both buttons, six support actions, image rendering and temporary alert animation.

| Packaged address | Implementation |
| --- | --- |
| `0x3c314` | `viewDidLoad`: translucent navigation bar; inset-grouped table; light backdrop; 230-point logo header; four localized feature rows; dark footer; Continue and contact buttons |
| `0x3f84c` | `thanksButtonTapped`: set `hasShownWelcome`, then dismiss animated |
| `0x3fa3c` | `contactsButtonTapped:`: Twitter application/website fallback for tag 0, support sheet for tag 1, no action for other tags |
| `0x4167c`, `0x41984`, `0x41cbc`, `0x4299c` | Patreon, GitHub Sponsors, Buy Me a Coffee and Boosty action callbacks |
| `0x42024`, `0x424b0` | Copy the exact packaged TRC20/BEP20 addresses; show localized Copied with a checkmark |
| `0x42c68` | Load images from `ytl_defaultBundle` with nil trait collection |
| `0x42d00`–`0x4343c` | Six table delegate/data-source methods: automatic height, one section, row count, no separators, reusable subtitle cells, no highlight |
| `0x43444` | Alert layout, medium haptic, prominent blur, 150-point square and two spring animations |
| `0x43ea0`, `0x43f1c`, `0x44024`, `0x44170` | Alert entrance, schedule exit after 2 seconds, shrink/fade/move down, remove; completion flags are intentionally ignored |
| `0x441a8`, `0x4427c` | 40-by-40 renderer and actual layer-drawing callback with a white aspect-fit system image |
| `0x44448` | Release `_settingsData` and `_tableView` through ARC |
| `0x4477c` | Shared layout helper: application delegate window's safe-area **top > 20** |

Original-byte evidence:

- `manifest.json` pins the supplied ARM image SHA-256, all method addresses, complete instruction spans for this class/callback range and the helper, plus ten floating-point constants read with `EvidenceImage`.
- The three layout queries call wrappers `0x458f8`, `0x45fbc`, `0x46400`, all reaching `0x4477c`. At `0x447ec`, `fmov d8,d0` preserves the first `safeAreaInsets` component. At `0x44808`–`0x44810`, `20.0`, `fcmp` and signed `gt` establish the strict top-inset threshold. It is not a test of the bottom inset, device idiom or key window.
- Constants at `0xc4c278`/`280`/`288`/`290` are 230/140/130/170. The complementary non-tall content inset is 100; the Continue bottom offsets are -20/-60. Width is 300 at `0xc4c238`. Background opacity is 0.6, footer/description opacity 0.8, Continue background opacity 0.15, alert size 150 and entrance scale 1.2.
- Global support blocks at `0x1061860`, `0x1061880`, `0x10618a0`, `0x10618f0` point to `0x4167c`, `0x41984`, `0x41cbc`, `0x4299c`. The two captured-self callbacks are constructed directly in `contactsButtonTapped:`.
- Decompiler exports were read from `.recovery-work/analysis-v3/decompiled/` through the normalized readable exports. Metadata and source artifacts under `recovery/evidence/` remain unchanged.

Preserved unusual behavior:

- The feature array is populated at the end of `viewDidLoad`; the binary does not call `reloadData` there.
- Footer decoration disables interaction; the working buttons are siblings on the root view.
- The table always reports four rows after loading, even if asked for another section. A cell request outside section zero returns the allocated/reused cell without reconfiguration.
- The temporary alert continues its exit/removal even when UIKit passes `finished == NO` to either completion.
- Continue does not synchronize defaults or perform navigation beyond dismissal.

Reconstruction differences: compiler/obfuscator control-flow tables, string initialization scaffolding, retain/release wrappers and supervisor instructions are replaced by ordinary Objective-C/ARC. Host class resolution uses typed `NSClassFromString` protocols at call time instead of process-global cached `_objc_getClass` pointers; these classes are implemented by YouTube, not this module. Original source formatting and local variable names cannot be recovered from compiled code. No behavior is intentionally omitted and no unresolved semantic branch remains within this class.

Run `python3 recovery/tools/verify_welcome.py`. It verifies the original-byte manifest and complete iOS ABI, then executes 649 checks against the actual implementation. Fixtures cover three safe-area inputs (0, 20, 20.5), the view hierarchy and layout, four rows including reuse/out-of-section handling, both Twitter branches, all six support callbacks, defaults writes, image renderer callbacks, both stages of the alert animation and interrupted-completion behavior. Foundation collections, URLs and a unique defaults suite are real; UIKit, YouTube sheets/actions, pasteboard, haptics, image rendering and URL opening are isolated test doubles. No supplied binary is executed and no external URL is opened. Device rendering and YouTube integration are not established by these host tests.
