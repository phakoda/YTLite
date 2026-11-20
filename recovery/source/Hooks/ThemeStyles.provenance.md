# ThemeStyles recovery

All 24 assigned registrations are reconstructed in `ThemeStyles.x`, with 19 replacements and five added methods. They belong to the deferred primary registrar at `0x53fac`. `YTLInstallThemeStylesHooks()` installs that group explicitly. There is no constructor; parent owns registration timing and removal of duplicate root hooks.

Evidence comes from the supplied arm package, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The manifest records every original registration, 57 complete callback/helper instruction intervals, 290 decoded string occurrences and 89 original branch records. These are original image addresses. The normalized decompiler output is a reading aid, not the authority for branch direction or argument widths.

| Class | Selector | Operation | Original callback |
| --- | --- | --- | --- |
| _ASDisplayView | `-didMoveToWindow` | replace | `0x00067fd4` |
| _ASDisplayView | `-setKeepalive_node:` | replace | `0x00068370` |
| _ASDisplayView | `-savePFP:` | add | `0x0006a920` |
| _ASDisplayView | `-postManager:` | add | `0x0006b2d0` |
| _ASDisplayView | `-commentManager:` | add | `0x0006cd2c` |
| UIImageView | `-setImage:` | replace | `0x00070584` |
| UIImageView | `-image` | replace | `0x00070f38` |
| YTColor | `+black0` | replace | `0x0007cca4` |
| YTColor | `+black1` | replace | `0x0007ce48` |
| YTColor | `+black2` | replace | `0x0007cff8` |
| YTColor | `+black3` | replace | `0x0007d1a4` |
| YTColor | `+black4` | replace | `0x0007d350` |
| YTColor | `+bgColorForPageStyle:` | add | `0x0007d4f8` |
| UIView | `-setBackgroundColor:` | replace | `0x0007d568` |
| GOODimmingBackgroundView | `-layoutSubviews` | replace | `0x0007d75c` |
| UIKeyboard | `-displayLayer:` | replace | `0x0007d9dc` |
| UIPredictionViewController | `-_currentTextSuggestions` | replace | `0x0007dc00` |
| UIKeyboardDockView | `-layoutSubviews` | replace | `0x0007e07c` |
| UIInputView | `-layoutSubviews` | replace | `0x0007e294` |
| UIKBVisualEffectView | `-layoutSubviews` | replace | `0x0007e818` |
| YCHLiveChatView | `-layoutSubviews` | replace | `0x000b2580` |
| YCHLiveChatView | `-didTapYtlButton:` | add | `0x000b3018` |
| NSParagraphStyle | `+defaultWritingDirectionForLanguage:` | replace | `0x000ba9bc` |
| NSParagraphStyle | `+_defaultWritingDirection` | replace | `0x000bab78` |

`YTColor` substitutes `blackPure` for black0 through black4 only under `oledTheme`. The added page-style helper uses label color with alpha 0.05 for zero and the exact double 0.10000000149011612 for every nonzero value. `UIView` passes colors through the canonical `YTPMedia.oledForColor:` when enabled. Dimming layout calls its original first, then uses black unless both OLED and the host's dark-mode test succeed; that branch uses white at alpha 0.2.

Keyboard callbacks share the recovered helper at `0xc9b60`. It prefers `_mapkit_isDarkModeEnabled` when the view responds, otherwise it reads the ancestor controller's trait collection. UIKeyboard and dock backgrounds become black or clear. Prediction updates both its view and the active keyboard before calling its original getter, preserving the original result. UIInputView applies the change only to emoji-search and Safari autofill subclasses. The visual-effect callback clears effects and sets black only in dark mode. Its light branch leaves those properties alone.

The image setter reads `logoIndex` separately for each of its three checks. Index 1 replaces the ordinary logo using `YTUIResources`, index 2 replaces the premium logo, and index 3 hides either matching logo through alpha. It forwards the final image and does not restore alpha later. The getter calls its original first; a matching muted-playback ancestor and Cairo thumb name permit the configured scrubber tint when `progressBarIndex` is nonzero. Paragraph-style overrides preserve both original 64-bit results when RTL suppression is disabled, including nil language forwarding.

Display-view movement calls the original before removing the ad metadata view. Node assignment calls its original, applies OLED conversion, checks the incoming node description and ancestor for subscribe-button hiding, then installs the first enabled matching long-press gesture. Gesture precedence is post, plain avatar, decorated avatar, comment. Reassignment can add another recognizer. The final OLED pass replaces an opaque grayscale background only for the open interval 0.1 < white < 0.13, using a dynamic black/white provider. The live-chat-text identifier receives a clear background under that same preference.

The profile action supports both ASNetworkImageNode and matching children beneath a decorated avatar's first child. It preserves the unchecked first-child index and visits every matching avatar child. The helper at `0xbfae8` replaces the size digits between `=s` and the following dash with `1024`, reads the image, then adds Save, Show and Copy actions. Save invokes the photo-album function and schedules the Saved toast; Show presents the recovered image viewer from the view's current node controller; Copy updates the pasteboard and schedules Copied.

Post and comment menus capture their text, layer and background when opened. Translation uses the recovered TranslatorVC and DVNSheetPresenter at height 520. The font probe uses an initialized YTDefaultTypeStyle instance, while the subsequent font call targets a separately allocated instance, matching the package. Post menus use the node's layer; comment menus use the view's layer. Both menus create their text actions even for nil text, and those actions then do nothing. Image capture calls canonical YTLHelper, photo completion schedules its success/error toast on the main queue, and copies likewise defer their toast. Action sheets use the canonical ToastView window's root controller and retain the source view.

A concrete decompiler discrepancy occurs at `0x6c42c`. The original table at `0x117b3f0`, with the decoded offset stored at `0x117b400`, selects `0x6c430` for a non-nil copiedURL and `0x6c470` for nil. Only the non-nil branch adds Save Current Image, Show Current Image and Copy Current Image. The pseudocode reverses this condition. The manifest includes the table calculation, and the verifier reruns it. Current-image preview replaces a crop suffix beginning with `c-fcrop` with `nd-v1`, then presents from the application window's root controller. Save and Copy Current Image call canonical YTLHelper with different download flags.

Live-chat layout calls its original, tests the ancestor's parent for YTLivePlayerViewController, creates and styles the button, then adds it only when the lightweight interactivity view exists and lacks tag 999. The helper still creates a button on repeated layouts. Constraints align center X and top, with width and height 40. Shadow opacity is float 0.5; offset and radius use CGFloat, with zero offset and radius 4. The added tap method checks the same hierarchy, reads activeVideoID twice when non-nil, and calls openURL only after canOpenURL succeeds.

## Verification and integration

Run `python3 recovery/tools/verify_theme_styles.py`. It compares exact class, selector, class/instance kind and add/replace operation against the registration inventory. It verifies original byte hashes and decoded strings, generates Logos code, compiles for arm64 iOS, audits emitted LLVM signatures and executes the generated bodies under UndefinedBehaviorSanitizer. The current fixture passes 327 checks. It covers every added/replaced method, preference branches, original forwarding and ordering, nil inputs, hierarchy predicates, image transformations, captured menu values, nested photo callbacks, failed photo writes and deferred toasts.

The iOS audit confirms 64-bit page-style input and paragraph-direction results, object-pointer arguments for gesture/layer/image/language selectors and correct class-method registration. UIKit scalar operations use their real imported declarations, including float shadow opacity, CGFloat alpha/radius and CGSize offsets. Private host classes use Logos class lookup. Production imports canonical recovered helpers; the fixture intercepts their calls rather than duplicating their implementations.

Compile `ThemeStyles.x` with the existing canonical Runtime feature policy, YTPMedia, YTLHelper, TranslatorVC, DVNImageViewController, DVNSheetPresenter, ToastView/ToastWindow/ToastManager and bundle/defaults implementations. No FeedNodes global is required. Parent should remove matching root hooks before installing this group, including the old UIImageView, _ASDisplayView and NSParagraphStyle blocks.

The supplied binary was not executed. Runtime verification uses intercepted UIKit objects and offline image data, photo-library, pasteboard, URL-opening and helper boundaries. It does not prove a live YouTube host's implementation or actual network/photo service behavior. Obfuscation bookkeeping, literal decoding and protection syscalls are omitted from the readable source. The canonical local preference policy is an integration difference from the packaged protected feature gate, owned by the parent.
