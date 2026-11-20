GeneralInterface reconstructs 26 assigned registrations from the supplied 5.2.2 arm package, 24 replacements and two added accessors. It includes all seven assigned registrations from registrar `0x4cf00` and nineteen from `0x53fac`. The separate settings registrar `0x11bec` and ELMTouch compatibility registrar `0xc554` remain in their owning modules.

The manifest pins each original function range and SHA-256, five nested callbacks, the private guide mutator, property registration instructions, 91 decoded branch tables, original constants and block descriptors. The input dylib SHA-256 is `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. Instruction hashes always use the supplied image, never the synthetic analysis image.

`python3 recovery/tools/verify_general_interface.py` regenerates Logos with the pinned internal generator, compiles for arm64 iOS 13, checks every method and block LLVM signature, then runs actual generated hook bodies under UBSan against local doubles. The fixture currently passes 3,337 checks. It links the real recovered YTPDB localized label arrays. UIKit presentation, downloads, video opening, timers, preferences and host original IMPs use doubles. No supplied dylib, real YouTube runtime, network request or external URL opening is executed.

Registration and ABI evidence

- The complete registration table appears below and in the machine-readable manifest. Object arguments remain pointer-width values through original forwarding. Typed protocols describe selectors used by the reconstructed code, without asserting erased protobuf class identities.
- `setOrientation:animated:` forwards a signed 64-bit orientation in x2 and BOOL in w3. The delayed block takes only its block pointer. Its 300,000,000 ns delay and main queue match `0x4ead4`; callback `0xbcc04` calls `updateAllToasts`.
- `setWasPinnedTop:`, `setFullscreen:`, `viewDidDisappear:` and `setHintsDisabled:` consume BOOL. Hints and keyboard getters return BOOL. `allowedFullScreenOrientations` returns a 64-bit mask, corroborated by `vendor/YouTubeHeader/YTWatchViewController.h`. Idiom returns a signed 64-bit enum and deliberately reads the preference twice on the nonzero branch.
- `sizeForElement:` returns a two-double CGSize. Original `0xb89d8/0xb89dc` save d0/d1 from the original IMP into d8/d9; `0xb8a6c/0xb8a70` restore both. The old truncated pseudocode's zero second lane was incorrect. The fixture forwards an element by identity and verifies width 123.25 and height -987.5.
- Guide predicate descriptor `0x10620b0` encodes `B32@?0@"YTIPivotBarSupportedRenderers"8Q16^B24`. The predicates receive block, renderer, NSUInteger index, BOOL stop pointer and return BOOL; unused index and stop remain untouched.
- Orientation descriptor `0x10613e0` and dismissal descriptor `0x1061420` encode `v8@?0`. Speed callback `0xc9ad4` presents the canonical speed controller from capture offset 0x20. Quality callback `0xc9b24` sends `didPressVideoQuality:nil` to its capture. Completion blocks run after dismissal and retain the captured parent.
- Original `0x62124..0x62180` gets YTMultiSizeViewController, assembles the three attributes T=`@"YTLHelper"`, &=empty, N=empty and calls class_addProperty with count 3 at `0x6217c`. Getter `0x48284` and setter `0x48290` use associated objects; setter policy is 1. The installer adds actual property metadata. Runtime tests compare `property_getAttributes` to `T@"YTLHelper",&,N` and verify strong retention and release. A private unique address replaces the packaged getter-IMP key.

Resolved behavior

The toast hooks forward first, then update the canonical ToastManager state. Interstitial presentation suppression has no preference gate and does not call a suppressed completion. Comment panels are identified by either of the two exact host classes plus a panel identifier containing `comment-item-section`; load and disappearance post height 90 and 0 after forwarding. Interstitial load dismisses without animation.

Navigation button hiding preserves prior hidden state when preferences turn off. Voice search uses the main bundle's `search.voice.access` localization. Search suggestions are suppressed only by `noSearchHistory`. The premium early-access entry is an unconditional no-op. The hints getter never calls its original. The setter combines the incoming value with `noHints`; portrait fullscreen returns mask 0x1a when enabled. URL unwrapping requires a host containing `youtube.com`, path `/redirect`, and the first `q` query item with a nonnil value yielding a URL. Substring host matching is intentional, including lookalike hosts. Options and completion are forwarded by identity.

ASCollectionView examines the first yoga child below the element's node, only for `id.video.scrollable_action_bar`. It returns zero for the four enabled identifier matches. Localized Thanks, Clip, Report, Hype and StopAds filtering requires more than one yoga child and an actual ASTextNode. Every unmatched path forwards the original CGSize. Tests cover each member of all five recovered label arrays, both preference states, count-one exclusion, wrong node types and nonmatching collection identifiers.

ELMTouch follows the packaged branch order. Shorts conversion checks all three identifier substrings, walks the first-subnode chain for at most ten edges, and stops at the first primary image even if video ID extraction fails. Offline buttons use the exact metadata-provider KVC chain and intercept even with a nil player. Download list rows scan image nodes for the arrow icon and require an available sleep-timer player. Speed selection examines only the first image node, obtains parentResponder twice on success, dismisses the delegate, and presents the speed popup in its completion. Classic quality requires the overflow identifier prefix, a `\d+p` label match, the preference, action-sheet and bottom-sheet classes, and an overlay-controller parent. It dismisses that parent and invokes quality in the completion. Each successful interception returns without its original; all other paths forward.

The private `GeneralMutateGuide`, original `0xcd138..0xcf174`, runs before each of five response originals. It mutates each pivot items array in place. Missing activeTabs leaves a nonempty array alone; an empty activeTabs removes all entries; an already empty pivot array remains empty even when custom tabs are configured. Removal accepts normal identifiers or icon-only fallback. Ten known custom browse IDs construct missing renderers through the canonical YTIPivotBarRenderer method, exact icon codes and bundle localization. Existing custom tabs keep their position. Other entries reorder an existing match; FEuploads uses its icon-only identifier. Missing entries still consume their active index. Duplicate builtin identifiers therefore can move the same first match again. Both predicate bodies and every wrapper run in the fixture, including before-original snapshots and completion identity.

Branch reconstruction

The initially available exports stopped inside ELMTouch and ASCollectionView. An isolated Ghidra project and analysis-only branch islands expanded their original function boundaries, including `0x79304..0x7cca4` and `0xb6228..0xb8a9c`. Forty-three manually recorded tables resolve the missing computed branches, including `0xb7e70` and navigation layout branch `0x6f934`. Each record stores the original indirect branch, table, key, XOR constant, condition spill/load and both decoded targets. The verifier recomputes each signed table offset from original initialized bytes and checks the original instruction span. The other 48 tables cover already expanded branches. Original-byte facts are durable in the manifest; `.recovery-work/general-interface-analysis` and `.recovery-work/general-interface-decompiled` are inspection artifacts.

Integration and limits

Add GeneralInterface.x to the recovered build and call `YTLInstallGeneralInterfaceEarlyHooks` and `YTLInstallGeneralInterfaceHooks` at the corresponding original registration phases. There is no constructor. Parent integration owns duplicate removal and cross-module hook chaining. Guide construction depends on the already recovered YTIPivotBarRenderer category method in NavigationChrome. Other helpers use canonical implementations already in the build. No new shared production global is introduced.

The packaged anti-debug supervisor calls are omitted; the manifest records all 17 original SVC words and immediates in this module's function ranges. Constant decryption and opaque dispatch machinery are replaced with decoded values and ordinary control flow. Functional branch decisions, preferences, messages and callbacks are retained. Current feature-policy helpers still implement the repo's local preference policy; historical account policy belongs to the separate parent fidelity audit. Host object semantic types erased by compilation remain documented protocol/id boundaries. This fixture proves the reconstructed behavior against controlled boundaries, not device rendering or compatibility with every YouTube version.

| Registrar | Class | Selector | Implementation | Operation |
| --- | --- | --- | --- | --- |
| `0004cf00` | YTToastOffsetController | `update` | `0x0004e934` | replace |
| `0004cf00` | YTToastOffsetController | `setWasPinnedTop:` | `0x0004e9e4` | replace |
| `0004cf00` | YTWatchViewController | `setFullscreen:` | `0x0004ea5c` | replace |
| `0004cf00` | UIDevice | `setOrientation:animated:` | `0x0004ead4` | replace |
| `0004cf00` | UIViewController | `presentViewController:animated:completion:` | `0x0004eb2c` | replace |
| `0004cf00` | UIViewController | `viewDidLoad` | `0x0004ee9c` | replace |
| `0004cf00` | UIViewController | `viewDidDisappear:` | `0x0004fc10` | replace |
| `00053fac` | YTMultiSizeViewController | `helper` | `0x00048284` | add |
| `00053fac` | YTMultiSizeViewController | `setHelper:` | `0x00048290` | add |
| `00053fac` | YTSettingsSectionItemManager | `updatePremiumEarlyAccessSectionWithEntry:` | `0x0006e654` | replace |
| `00053fac` | YTRightNavigationButtons | `layoutSubviews` | `0x0006ee24` | replace |
| `00053fac` | YTSearchViewController | `viewDidLoad` | `0x0006fbb0` | replace |
| `00053fac` | YTSearchViewController | `setSuggestions:` | `0x0006ff6c` | replace |
| `00053fac` | ELMTouchCommandPropertiesHandler | `handleTap` | `0x00079304` | replace |
| `00053fac` | YTWatchViewController | `allowedFullScreenOrientations` | `0x0008fc60` | replace |
| `00053fac` | YTUserDefaults | `areHintsDisabled` | `0x000984b8` | replace |
| `00053fac` | YTUserDefaults | `setHintsDisabled:` | `0x000985b0` | replace |
| `00053fac` | ASCollectionView | `sizeForElement:` | `0x000b6228` | replace |
| `00053fac` | YTGuideServiceCoordinator | `handleResponse:withCompletion:` | `0x000b9a58` | replace |
| `00053fac` | YTGuideServiceCoordinator | `handleResponse:error:completion:` | `0x000b9ac4` | replace |
| `00053fac` | YTAppGuideServiceCoordinator | `handleResponse:error:completion:` | `0x000b9b6c` | replace |
| `00053fac` | YTGuideServiceCoordinatorImpl | `handleResponse:error:completion:` | `0x000b9c14` | replace |
| `00053fac` | YTGuideServiceCoordinatorImpl | `handleLegacyResponse:error:completion:` | `0x000b9cbc` | replace |
| `00053fac` | UIDevice | `userInterfaceIdiom` | `0x000bad20` | replace |
| `00053fac` | UIKeyboardImpl | `floatingForced` | `0x000baee4` | replace |
| `00053fac` | UIApplication | `openURL:options:completionHandler:` | `0x000bb0e0` | replace |
