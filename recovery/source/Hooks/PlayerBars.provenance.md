# Player-bar hook recovery

`PlayerBars.x` reconstructs all 33 assigned registration records across nine target classes: 29 replacements and four associated-object accessors. The seven repeated selectors remain in two distinct Logos groups so the later original IMP points to the earlier replacement.

The source exposes `YTLInstallPlayerBarsSponsorHooks()` for the 12 registrations at `0x1efd4`, and `YTLInstallPlayerBarsAppearanceHooks()` for the 21 registrations made by the deferred callback at `0x53fac`. It deliberately supplies no constructor. The parent must connect these functions to the recovered bootstrap at their respective registration points, retaining the deferred policy for the second group.

`PlayerBarsHost.h` declares only the narrow existing-host interfaces required by these callbacks. The recovered source calls canonical `SBPlayerDecorator`, `YTLUserDefaults`, `ytpBool`, and `ytpInt`. The policy functions remain authoritative; their current integration policy is not reimplemented or bypassed here.

## Exact registration coverage

| Registration site | Class | Selector | Operation | Replacement address |
| --- | --- | --- | --- | --- |
| `0x0001efd4` | `YTInlinePlayerBarContainerView` | `sbTimeString` | add | `0x0001dfc0` |
| `0x0001efd4` | `YTInlinePlayerBarContainerView` | `setSbTimeString:` | add | `0x0001dfcc` |
| `0x0001efd4` | `YTInlinePlayerBarContainerView` | `setPeekableViewVisible:` | replace | `0x00020fd4` |
| `0x0001efd4` | `YTPlayerBarRectangleDecorationView` | `applyGradientColorForRect:withOverallGradient:` | replace | `0x00021598` |
| `0x0001efd4` | `YTPlayerBarRectangleDecorationView` | `drawProgressRect:withColor:` | replace | `0x000215f0` |
| `0x0001efd4` | `YTPlayerBarRectangleDecorationView` | `isStateActive` | replace | `0x00021648` |
| `0x0001efd4` | `YTPlayerBarProgressDecorationView` | `applyGradientForRect:` | replace | `0x00021690` |
| `0x0001efd4` | `YTPlayerBarProgressDecorationView` | `drawProgressRect:withColor:` | replace | `0x000216e8` |
| `0x0001efd4` | `YTPlayerBarProgressDecorationView` | `isStateActive` | replace | `0x00021740` |
| `0x0001efd4` | `YTProgressView` | `setProgress:` | replace | `0x00021788` |
| `0x0001efd4` | `YTInlineMutedPlaybackScrubberView` | `setMediaTime:` | replace | `0x00022424` |
| `0x0001efd4` | `YTInlineMutedPlaybackScrubberView` | `addGradient` | replace | `0x0002246c` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `endTimeString` | add | `0x0004c9b4` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `setEndTimeString:` | add | `0x0004c9c0` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `setPlayerBarAlpha:` | replace | `0x0008e4e8` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `setFrame:` | replace | `0x0008e70c` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `quietProgressBarColor` | replace | `0x0008eaac` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `setPeekableViewVisible:` | replace | `0x0008ee8c` |
| `0x00053fac` | `YTInlinePlayerBarContainerView` | `didPressScrubber:` | replace | `0x0008f31c` |
| `0x00053fac` | `YTPlayerBarScrubberDotDecorationView` | `scrubberDot` | replace | `0x00090abc` |
| `0x00053fac` | `YTPlayerBarScrubberDotDecorationViewV1` | `scrubberDot` | replace | `0x00090e90` |
| `0x00053fac` | `YTPlayerBarRectangleDecorationView` | `applyGradientForRect:` | replace | `0x0009125c` |
| `0x00053fac` | `YTPlayerBarRectangleDecorationView` | `drawProgressRect:withColor:` | replace | `0x00092210` |
| `0x00053fac` | `YTPlayerBarRectangleDecorationView` | `applyGradientColorForRect:withOverallGradient:` | replace | `0x00092648` |
| `0x00053fac` | `YTPlayerBarProgressDecorationView` | `applyGradientForRect:` | replace | `0x00092d9c` |
| `0x00053fac` | `YTPlayerBarProgressDecorationView` | `drawProgressRect:withColor:` | replace | `0x00093d70` |
| `0x00053fac` | `YTPlayerBarProgressDecorationView` | `applyGradientColorForRect:withOverallGradient:` | replace | `0x00094198` |
| `0x00053fac` | `YTModularPlayerBarView` | `layoutSubviews` | replace | `0x000948e0` |
| `0x00053fac` | `YTInlineMutedPlaybackScrubberView` | `addGradient` | replace | `0x00094ef8` |
| `0x00053fac` | `YTInlineMutedPlaybackScrubberView` | `layoutSubviews` | replace | `0x00095104` |
| `0x00053fac` | `YTInlineMutedPlaybackScrubbingSlider` | `currentMinimumTrackImage` | replace | `0x00095b20` |
| `0x00053fac` | `YTProgressView` | `setProgressBarColor:` | replace | `0x000967dc` |
| `0x00053fac` | `YTProgressView` | `setProgress:` | replace | `0x00097274` |

## Original-byte findings

The binary SHA-256 is `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. `PlayerBars.manifest.json` records the exact authoritative hook records, hashes of all 33 implementation intervals plus the `configureMutedPlayerBar` helper at `0x1e004`, and 77 decoded strings with their original write instructions. `verify_playerbar_hooks.py` checks these against the immutable image and decoder evidence.

- SponsorBlock duration text appends ` (%@)` after the original peek callback. Later end-time text appends ` • %@` after the earlier callback completes. Each avoids an append only when the current text already contains the stored string; nil labels retain normal Objective-C nil-message behavior. The associated strings use retain-nonatomic storage, preserving identity of mutable string inputs.
- Rectangle and progress drawing callbacks invoke the original draw before decorating it. The `isStateActive` callbacks decorate first and return the original BOOL. Custom-color drawing replaces the color argument before passing through these original chains. Muted `addGradient` calls neither the original nor the earlier SponsorBlock callback when the progress style is nonzero.
- `configureMutedPlayerBar` requires SponsorBlock/feed settings and the exact ancestor/parent/responder class chain, followed by existence of `_playingProgress`. Original instructions `0x1eec8–0x1ef84` prove that availability of `segmentablePlayerBarEnabled` chooses the segmentable branch. At `0x1ef44`, its result is discarded: there is no test or branch before `segmentablePlayerBar` and `drawSegmentableSegments:playerBar:playerVC:`. Both YES and NO therefore select that branch.
- The mini-player path passes its `_playerViewController` ivar when the ancestor is a supported mini-player class. A supported class without that ivar skips drawing. An unrelated ancestor still calls `drawSegments:layer:playerVC:` with a nil player.
- Original frame instructions `0x8e730–0x8e73c` preserve the incoming CGRect in four double registers. `0x8e92c` and `0x8e958` obtain screen width/height; `0x8e964–0x8e970` checks whether the supplied width exceeds the shorter screen side. With `noFullscreenActions`, `0x8ea04` reads the superview's bottom inset (d2), `0x8ea30` its height (d3), and `0x8ea3c–0x8ea48` computes `height - bottomInset - frameHeight - 10`. The other frame components are preserved.
- Tap-to-seek uses the gesture's x coordinate, the host's scrub fraction and total media duration. `0x8f6f0–0x8f728` passes CGPoint.x in d0, saves the scrub result in d8, multiplies two doubles, and forwards the result to `seekToTime:` after the original gesture callback.
- Brand gradients and ordinary progress gradients reuse the first layer named `ytpGradient`; they set three colors `[main, main, end]`, locations `[0, 0.75, 1]`, horizontal endpoints and masksToBounds. Mode 1 substitutes main for end. Mode 2 requires both colors. Other nonzero modes can reach the color literal with nil end and raise; this quirk is preserved and tested. Neither a disabled mode nor a later missing color removes existing layers.
- The overall-gradient and `_progressBarGradient` paths use two colors: main/main for mode 1, main/end for mode 2. Other modes do not change the colors. Color blobs are retrieved before either blob is unarchived, matching the packaged operation order. Progress inside `YTVideoThumbnailView` skips the added gradient-view behavior, after the original callback chain runs.

## Verification

```sh
python3 recovery/tools/verify_playerbar_hooks.py
```

The verifier compares exact registration multisets from the source and `hooks.json`, including both occurrences of each duplicate, and checks all generated callback definitions. It preprocesses the actual source with pinned Logos, compiles the generated Objective-C++ against the iOS SDK, inspects all 33 LLVM callback signatures, then executes the actual generated hooks with synthetic YouTube/UIKit classes and real Foundation, secure archive/unarchive, CoreGraphics colors and QuartzCore layers. No network requests or original dylib execution are involved.

The fixture passes 230 checks with UndefinedBehaviorSanitizer. Tests cover both installation stages, original-call order, all preference modes, nil values and missing ivars, ancestor branches, associated-object identity, label append suppression, frame geometry, tap seeking, original color and image returns, gradient installation/reuse, two- and three-stop gradients, disabled/missing colors, invalid-mode exceptions, and 64-bit scalar payload preservation including low-32-bit float payloads, signed zero and NaN payloads. Reports and generated artifacts are in `.recovery-work/playerbar-hooks/`.

## Remaining limits

The supplied tweak image does not contain the original host method declarations for `YTProgressView setProgress:` or `YTInlineMutedPlaybackScrubberView setMediaTime:`. Their replacement bodies forward input registers untouched before doing their work, and the vendored headers do not declare the methods. This evidence cannot distinguish the original source spelling `float` from `double` for those three registration records. The recovered wrappers forward the full 64-bit FP scalar payload; the fixture proves bit preservation, but does not establish the missing host source type. Other object argument subclass names are narrow behavioral declarations, not a recovered complete private framework header.

Real installed YouTube and on-device UIKit display remain untested. Compiler obfuscation, opaque string initialization, and injected supervisor-call instrumentation are not reproduced as source. Shared bootstrap ordering, duplicate removal from root `.x` files, source-list integration and the canonical runtime policy are owned by the parent.
