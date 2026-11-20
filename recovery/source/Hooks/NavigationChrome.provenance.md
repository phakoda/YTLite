# Navigation chrome recovery

`NavigationChrome.x` covers all 17 assigned `hooks.json` registrations and the separately installed renderer replacement. It includes all five context-menu block bodies. Complete original functions are pinned to arm-package SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca` in the adjacent manifest.

| Class | Selector | Implementation | Stage |
| --- | --- | --- | --- |
| YTHeaderView | stickyNavHeaderEnabled | 0x000506c4 | early |
| YTHeaderView | clipsToStatusArea | 0x000508c8 | early |
| YTChipCloudCell | framesForChipViewsWithWidth: | 0x00050ac4 | early |
| YTMySubsFilterHeaderView | setChipFilterView: | 0x00050dfc | early |
| YTHeaderContentComboView | enableSubheaderBarWithView: | 0x00050fe8 | early |
| YTHeaderContentComboView | setFeedHeaderScrollMode: | 0x000511ac | early |
| YTIPivotBarRenderer | backgroundStyle | 0x00051344 | early |
| YTPivotBarViewController | viewDidAppear: | 0x000514d8 | early |
| YTPivotBarViewController | isFrostedPivotBarPermitted | 0x00051be8 | early |
| YTPivotBarView | itemView1 | 0x00051fe8 | early |
| YTPivotBarView | contextMenuInteraction:configurationForMenuAtLocation: | 0x00052070 | early |
| YTWatchMiniBarViewController | updateMiniBarPlayerStateFromRenderer | 0x0008f914 | main |
| YTPlaylistMiniBarView | setFrame: | 0x000ab978 | main |
| YTPivotBarItemView | navigationButton | 0x000b8a9c | main |
| YTPivotBarItemView | setRenderer: | 0x000b9568 | main |
| YTPivotBarItemView | layoutSubviews | 0x000b97bc | main |
| YTAppViewController | showPivotBar | 0x000b9d64 | main |

The context-menu selector is added; the other 16 listed methods replace originals. No properties are added or replaced. The fixture compares actual runtime property lists before and after all installations.

## Installation timing

Three explicit installers preserve the original boundaries:

- `YTLInstallNavigationChromeEarlyHooks()` covers 11 registrations from `0x4cf00`. That registrar is entry 8 in `__init_offsets`, stored at `0xb98044`.
- `YTLInstallNavigationChromeHooks()` covers six registrations from the main registrar at `0x53fac`. This registrar is not itself an `__init_offsets` entry.
- `YTLInstallNavigationChromeRendererHook()` restores the manual registrar at `0x1b6d44`. It is entry 10 of the 12 original initializer offsets, at `0xb9804c`, after initializer `0xf0c4c` and before `0x24011c`.

The manual registrar resolves `YTPivotBarViewController` and `renderer`, returning without changes if either is absent. `method_setImplementation` installs replacement `0x1b7004` and saves the previous IMP in original slot `0x1227998`. Its replacement forwards the incoming self and selector, reads the returned object's description, sets canonical `YTPMedia.sharedMedia.cairo` to YES when it contains case-sensitive `_CAIRO`, and returns the original object. Nonmatching descriptions leave the prior flag untouched. It never resets the flag. The source uses a typed previous-IMP pointer and the same guarded runtime replacement. Call each installer once; the original manual registrar is not safe to install repeatedly onto its own replacement. There are no new constructors.

## Early preferences and startup

These early hooks retain direct `YTLUserDefaults` reads rather than routing all settings through feature policy. `stickyNavbar` forces sticky headers on and status clipping off. Disabled values forward the original result. `framesForChipViewsWithWidth:` returns nil for direct `noSubbar`, otherwise checks feature gate `hideInlineComment` and returns nil for that gate. Only when both are false does it forward width and return the original object. The two view setters skip their originals for direct `noSubbar`; `setFeedHeaderScrollMode:` always forwards, replacing its 32-bit mode with zero when that setting is on.

`backgroundStyle` returns 2 for direct `frostedPivot` and 1 otherwise, without an original call. `isFrostedPivotBarPermitted` returns the same preference's Boolean value directly.

`viewDidAppear:` forwards first. If shared `isTabSelected` is false and direct `shortsOnlyMode` is false, it calls both cache-reset methods, selects the `startupTab` object, then sets `isTabSelected` true. The second reset receives exactly one array element: `FElibrary, FEsubscriptions`. It is not two separate identifiers. Missing startup preference still calls the selection method with nil. Independently, another direct `shortsOnlyMode` read chooses `FEshorts` and hides the parent's pivot bar when enabled. Thus the two reads and their timing remain distinct. Parent integration owns the existing `BOOL isTabSelected = NO` definition; the original symbol address is `0x191b7c8`.

## Context menu and actions

`itemView1` forwards, constructs a new `UIContextMenuInteraction` with self as delegate, enables user interaction on the returned item and adds the interaction. It returns the same item. Every call adds an interaction; no duplicate guard is present. A nil item remains nil.

The added context-menu method ignores its interaction and location inputs and returns a configuration with nil identifier and preview provider. Its action provider at `0xbcd7c` creates a menu with two empty-titled child menus in order: `sb_menu`, then `tabs_menu`, both options 1. The first contains localized `SbWhitelist` with the SponsorBlock image. The second always contains `Tabbar` and `OpenLink`, then contains `SleepTimer` only when direct `ytlSleepTimerIndex` is 2 or 3. The sleep action is created before those preference tests even when omitted. A value of 2 short-circuits the second read; all other values read the setting twice.

The provider and sleep handler capture the pivot view at block offset 32 without retaining it. Their original flags are `0xc0000000`, with no copy/dispose helpers. The generated Logos implementation preserves that unsafe capture because hook self is unsafe-unretained. The fixture confirms that retaining the configuration does not retain its view; it never invokes that configuration after the view dies. The original descriptors at `0x1061ae0` and `0x1061aa0` identify the provider as `@"UIMenu"16@?0@"NSArray"8` and sleep handler as `v16@?0@"UIAction"8`.

The four actions retain their packaged behavior:

- Tabbar, callback `0xbd8e8`, initializes canonical `TabbarVC` with settings NO and embeds it in a page-sheet navigation controller. It allocates and initializes `YTDefaultTypeStyle` to check font selector availability. If present, it allocates a second style object without calling init and asks it for a 20-point bold font. It assigns that font and label color to navigation title attributes. It presents from the application delegate's window root, animated, with nil completion.
- OpenLink, callback `0xbde0c`, reads the pasteboard when invoked. A nonempty string is checked for the case-sensitive substrings `youtube.com`, `youtu.be`, and `youtube-nocookie.com`, in order. The first match strips only an anchored lowercase HTTP or HTTPS scheme using the `^https?://` regular expression, prepends `vnd.youtube://`, and calls `openURL:options:completionHandler:` with an empty options dictionary and nil completion. There is no host validation, normalization or failure UI beyond that original substring test. Tests use synthetic pasteboard strings and intercept URL opening.
- SleepTimer, callback `0xbe768`, obtains canonical shared timer, calls `itemView1` again, and passes that item to `showOptions:`. The repeated item lookup also adds another interaction through the recovered hook.
- SbWhitelist, callback `0xbe7e0`, initializes canonical `SbWhitelistVC` and presents it through the same navigation/font sequence as Tabbar.

The Tabbar/OpenLink/Whitelist global block literals are `0x1061a60`, `0x1061a80` and `0x1061ac0`. The verifier pins each invoke pointer. The presentation helper consolidates matching code while preserving the probe initialization and separate uninitialized font receiver.

## Main navigation and mini-bars

`updateMiniBarPlayerStateFromRenderer` skips the original when `miniplayer` is enabled. `YTPlaylistMiniBarView.setFrame:` is a pure original forwarder in the package, preserving all four CGRect doubles. No feature condition is added.

The navigation-button getter first saves the original button. It reads the ancestor controller's renderer description and assigns the Cairo property to the Boolean result of case-sensitive `_CAIRO` containment, including false. This differs deliberately from the manual renderer hook's set-only-true behavior.

It then checks the item's renderer icon type independently for all nine values, reading the renderer again each time. Values 876 through 884 map in order to history, watch later, posts, hype, music, live, gaming, sports and notifications. Each matching value loads canonical `YTPMedia` normal and selected images into button states 0 and 4. Other values leave its images alone. The first encrypted jump table at `0x1181eb0`, offset `0x1181ec0`, was resolved from original bytes to false target `0xb8de4` and true target `0xb8d70`; the following eight tests are pinned in recovered branch records. A switch that caches the first renderer value would lose the original repeated reads, so the source preserves separate tests.

`setRenderer:` forwards untouched first, gets `navigationButton`, then assigns `setSizeWithPaddingAndInsets:` from inverse `removeLabels`. It reads that gate again and, if true, obtains the button again and assigns an empty title for state 0. Both button accesses run the recovered getter. Layout forwards first and, with `removeIndicators`, reads `indicatorDot`; if nonnil it reads the dot again and sets alpha zero. Disabled indicators do not restore alpha.

`YTAppViewController.showPivotBar` runs the original only when feature gate `shortsOnlyMode` is false. After that original it sets parent-owned `isOverlayShown` true. Suppression leaves the shared flag unchanged. The original global byte is `0x115cd38`.

## Verification and remaining limits

Run `python3 recovery/tools/verify_navigation_chrome.py` from the repository root. It verifies 17 hook records, the manual initializer, complete byte hashes for 24 functions, 34 decoded constants, 21 wrapper targets, 42 branch records, the manual icon table, block pointers and descriptor signatures. All 5,073 original instruction words retained in `.recovery-work/navigation-chrome-tests/original.asm.txt` were matched against the immutable image during recovery.

Pinned Logos generates the actual implementation. An iOS compile with real UIKit verifies all 17 callback signatures, the manual renderer ABI, all five block ABIs and the two nonretaining capture flags. The macOS fixture executes the generated implementation under UBSan with real Foundation collections/regular expressions, synthetic UIKit/YouTube classes and intercepted pasteboard/URL boundaries. It currently passes 279 assertions, including every registration and action, font-selector availability, runtime property-list preservation, raw renderer argument forwarding, double/CGRect precision, first-selection state, original ordering, icon states, repeated gate reads, and missing-class/method guards in manual installation. No supplied dylib is executed and no real navigation, pasteboard access or web request is performed.

The original source type for the untouched `setRenderer:` argument is unavailable. `uintptr_t` preserves x2 without adding ARC ownership. The chip width is saved and restored as full d0 at `0x50adc`; the recovered double preserves those bits, but no original host declaration was found to distinguish float versus double source type. The scroll-mode and background-style paths are 32-bit; their original enum signedness is unavailable. UIKit establishes BOOL, CGPoint and CGRect contracts for the public framework callbacks. Runtime tests establish behavior with synthetic hosts, not installed-device compatibility.

Parent integration owns root duplicate removal, source-list changes, both shared globals and installer timing. Direct early defaults calls remain direct. The existing canonical feature-policy difference from packaged bootstrap/licensing logic applies only to this module's explicit `ytpBool` calls. Obfuscation and injected supervisor-call instrumentation are omitted.
