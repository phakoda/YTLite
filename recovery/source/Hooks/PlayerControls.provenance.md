# Primary player controls

`PlayerControls.x` reconstructs all 47 `YTMainAppControlsOverlayView` registrations from primary registrar `0x53fac`: 30 property accessors, ten action methods, and seven replacements. The RPC registrar's `handleYTLDiscordTap:` stays in `DiscordLifecycle.x`. The module also registers the 15 packaged properties and implements all three SponsorBlock callbacks. Integration calls `YTLInstallPlayerControlsHooks()`; there is no constructor and no additional global dependency.

## Original evidence

The source image is the supplied ARM package's ARM64 dylib, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. `PlayerControls.manifest.json` lists every authoritative registration and original IMP slot, hashes complete original function spans, and records the three callback spans. It also verifies decoded CFStrings, literal floating-point data, critical instruction words, speed branch tables, block descriptors, and the original property registrar region. Expanded pseudocode is reference material; original instructions resolve widths, constants, metadata, and unordered floating-point comparisons.

| Method group | Implementations |
| --- | --- |
| Fifteen property getter/setter pairs | 0x4b06c through 0x4b408 |
| initWithDelegate:, layoutSubviews | 0x71838, 0x735a0 |
| speedValueMinus:, speedValuePlus:, resetSpeedValue: | 0x74860, 0x749a0, 0x74ae0 |
| speedDidChange:, showSpeedControl: | 0x74c3c, 0x74e0c |
| Download, mute, lock, sleep, SponsorBlock taps | 0x75074, 0x754cc, 0x759c4, 0x75e88, 0x75f14 |
| Autoplay renderer, captions availability, overlay visibility | 0x775a8, 0x77788, 0x778f0 |
| playbackRouteButton, dealloc | 0x7850c, 0x787dc |
| Whitelist action, image completion, queued toast | 0xc8ed8, 0xc95d4, 0xc98f4 |

Property calls at `0x62cd0` through `0x636c0` prove 15 `class_addProperty` registrations. Each has precisely three attributes, `T`, `&`, and `N`, with no backing ivar attribute. Stack properties use `@"UIStackView"`, nine button properties use `@"YTQTMButton"`, and the four constraints use `@"NSLayoutConstraint"`. Static source declarations expose the compatible UIButton interface; the installed runtime metadata preserves the packaged YTQTMButton spelling. Each associated-object getter has a unique key and each setter uses policy 1, retain nonatomic. The reconstruction uses unique static keys instead of original getter code addresses.

The property declarations are in a declaration-only category so fixture compilation cannot prepopulate the runtime metadata. Tests assert zero own properties before installation and exactly 15 afterward, comparing every `property_getAttributes` string. Accessor tests independently prove retention, clearing, per-object isolation, and independent keys. This metadata check was added after review identified that the initial accessor tests did not cover `class_addProperty`.

## Behavior

Initialization forwards the original delegate and constructs controls on the returned object. The vertical speed stack contains plus, value, minus; uses a 20-point corner radius, tag 999, centered Y and safe-area leading +10 constraints. The long press lasts 0.4 seconds. The background alpha literal at `0xc4c308` is the float-expanded double `0.30000001192092896`. The horizontal tag-998 stack contains mute, lock, sleep, Discord, SponsorBlock, and download buttons, in that order. It is attached only with a top-controls container and no existing tag-998 view. Normal constraints align below and trailing to that container; portrait-fullscreen constraints align top to top and trailing to leading minus 10.

Layout preserves original forwarding, title opacity, preference evaluation, button visibility, and stack visibility based on its nonhidden arranged views. Sleep modes 1 and 3 display its button. SponsorBlock requires both `sponsorBlock` and `sbPlayerButton`; download requires `downloadManager` and a nonzero `ytlButtonIndex`. Constraint switching requires both host fullscreen and orientation selectors; only fullscreen orientations 1 or 2 use the fullscreen pair. Unsupported host selectors leave the constraints alone.

Speed step actions reset auto-hide through the event delegate, obtain the player through the ancestor controller, and route changes through canonical YTPSpeedMaster. Arithmetic adds/subtracts 0.25 in double precision, narrows to float, then widens to double. FCMP/HI at `0x74904` and FCMP/LT at `0x74a44` both take the unordered NaN branch; those branches remain, along with unclamped rates near the limits. Reset instead sets the event delegate's rate directly to 1 and changes the title. Notifications format the supplied float value. Long-press presentation requires state 1 and the speed-controls preference.

Download, mute, lock, and SponsorBlock actions prefer an ancestor of the expected overlay-controller class and otherwise use the event delegate. Mute toggles the active video's state and updates the tapped button's icon. Lock requests fullscreen and activates lock mode only when the lock controller exists. Sleep forwards the tapped source to the canonical timer.

SponsorBlock requires a player of the expected class and a nonnil selected response API result. It constructs the sheet from author/title, shows its header divider, obtains and flips the chevron image even though that image is not attached to an action, and selects the add/remove label and checkbox icon. Its action captures the current whitelist snapshot, channel ID, author, and membership boolean. Removal persists immediately. Addition records name, channel link, and timestamp, fetches the channel image URL, conditionally reads image data, stores the entry, persists the whitelist, and queues the success toast on the main queue. The action descriptor is `v16@?0@"YTActionSheetAction"8`; the image completion is `v16@?0@"NSURL"8`; the global toast is `v8@?0`. All three emitted block signatures preserve these argument counts, and tests execute the actual bodies, including nil URL and missing image data.

Overlay visibility changes the button-stack alpha only for the packaged download/mute/lock gates; sleep, Discord, and SponsorBlock alone do not trigger that alpha update. Speed visibility also refreshes its title. Original forwarding occurs before optional pause/play. Autoplay suppression omits the original setter; captions suppression forwards false; cast suppression clears the host's `_playbackRouteButton` and returns nil. Deallocation removes the notification observer before original deallocation.

## Verification and limits

Run `python3 recovery/tools/verify_player_controls.py`. It verifies all recorded original byte spans and constants, regenerates actual Logos code with the pinned internal generator, compiles against the iOS SDK with warnings treated as errors, audits all 47 callback signatures and three block signatures, and executes the generated hooks under UndefinedBehaviorSanitizer. The current fixture passes 2,299 assertions, including exact property metadata, button/gesture contracts, 256 layout preference combinations, orientation and host-availability paths, original argument identity/order, float boundaries, all action bodies, asynchronous completions, persistence, and observer cleanup.

Foundation strings, dictionaries, predicates, and notification delivery are real. UIKit, helper services, image reads, queued dispatch, defaults persistence, and presentation are isolated doubles. No supplied binary was executed and no UI action or network request reached the host. The manifest's full-image hash and function hashes establish the original evidence source; the runtime fixture validates reconstructed behavior rather than executing the protected binary.

Compiled protection bookkeeping, obfuscation, and lazy class caches are not reproduced. Canonical recovered helpers are used; any historical differences in shared preference policy belong to parent integration. The BOOL host setters match the backup declarations, original W-register uses, and zero/one semantics, but packaged call sites alone do not provide the original host header typedef spellings. The exact original formatting and local names cannot be recovered. Real YouTube/UIKit behavior on a device remains untested. The parent controls primary/RPC registration order and duplicate removal.
