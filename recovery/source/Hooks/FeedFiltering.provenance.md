# Feed filtering recovery

`FeedFiltering.x` reconstructs all 27 packaged replacements for the 14 assigned host classes, in the named `YTLFeedFiltering` group. Call `YTLInstallFeedFilteringHooks()` from the central registrar; the module has no constructor. No added methods or properties are required by these records. Root hook removal and registration timing belong to the parent integration.

The authority is the supplied arm package's `YTLite.dylib`, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The adjacent manifest pins original function ranges, instruction hashes, 87 decoded constant strings, block descriptors and ambiguous branch-table destinations. Decompiler text was used for navigation; original instructions resolve the missing section-filter branches. The supplied binary was read as data and never executed.

## Registrations

All records below are replacements from registrar `0x53fac`.

| Host | Selector | Implementation |
|---|---|---|
| YTWatchNextResponseViewController | `loadWithModel:` | `0x00067a34` |
| YTIElementRenderer | `elementData` | `0x00067c08` |
| YTInnerTubeCollectionViewController | `addSectionsFromArray:` | `0x0006df3c` |
| YTICommand | `yt_showEngagementPanelEndpoint` | `0x0006e028` |
| YTICommandWrapperPromoRenderer | `setHasPromoType:` | `0x0006e240` |
| YTICommandWrapperPromoRenderer | `setPromoType:` | `0x0006e278` |
| YTICommandWrapperPromoRenderer | `setHasPromoCommand:` | `0x0006e2b0` |
| YTICommandWrapperPromoRenderer | `setPromoCommand:` | `0x0006e2e8` |
| YTICommandWrapperPromoRenderer | `setHasWatchPageTriggerCondition:` | `0x0006e320` |
| YTICommandWrapperPromoRenderer | `setWatchPageTriggerCondition:` | `0x0006e358` |
| YTICommandWrapperPromoRenderer | `clientFrequencyCapConfigsArray` | `0x0006e390` |
| YTICommandWrapperPromoRenderer | `clientFrequencyCapConfigsArray_Count` | `0x0006e3a4` |
| YTIPromoMessageSupportedRenderers | `rendererOneOfCase` | `0x0006e3ac` |
| YTIPromoMessageSupportedRenderers | `setHasCommandWrapperPromoRenderer:` | `0x0006e3b4` |
| YTIPromoMessageSupportedRenderers | `setCommandWrapperPromoRenderer:` | `0x0006e3ec` |
| YTIPromoMessageSupportedRenderers | `setHasUpsellDialogRenderer:` | `0x0006e3fc` |
| YTIPromoMessageSupportedRenderers | `setUpsellDialogRenderer:` | `0x0006e434` |
| YTCommerceEventGroupHandler | `addEventHandlers` | `0x0006e53c` |
| YTInterstitialPromoEventGroupHandler | `addEventHandlers` | `0x0006e558` |
| YTPromosheetEventGroupHandler | `addEventHandlers` | `0x0006e574` |
| YTPromoThrottleController | `canShowThrottledPromo` | `0x0006e578` |
| YTPromoThrottleController | `canShowThrottledPromoWithFrequencyCap:` | `0x0006e580` |
| YTPromoThrottleController | `canShowThrottledPromoWithFrequencyCaps:` | `0x0006e588` |
| YTIShowFullscreenInterstitialCommand | `shouldThrottleInterstitial` | `0x0006e590` |
| YTSurveyController | `showSurveyWithRenderer:surveyParentResponder:` | `0x0006e658` |
| YTPersonalizedSuggestionsCacheProvider | `activeCache` | `0x00070184` |
| ELMComponent | `node` | `0x0009d4d4` |

## Recovered behavior

- `loadWithModel:` removes matching commands from the existing mutable executor array before original forwarding. A matching outer command clears `onUiReady`. Helper `0xbf774` checks `noAds`, selector availability and the exact engagement identifier tag `PAproduct_list`. Its global predicate is `0xbf76c`; `0xd7104` masks the helper result to BOOL through thunk `0xd70f4`.
- `elementData` caches the first non-nil original value from a description containing `cell_divider`. It retries while the cached value is nil, shares the cache across renderer instances, and substitutes it for compatible ad renderers. **This callback has no `noAds` gate.** The module owns the retained cache corresponding to original `0x1226828`.
- `addSectionsFromArray:` copies the top-level input, runs predicate `0xc375c`, removes matching indexes and forwards an immutable copy. Item sections first test ad compatibility and then ad text in the second element (when present) and first element. A detected second-element ad removes the whole section; the third element is not inspected. Both `getAdString` and the following `ytpBool` call execute before combining their results, preserving the original gate-call order.
- Section filtering covers community posts, home-only horizontal/live feeds, mixes, inline comments, guidelines, topic chips, Playables and Shorts. Community feed descriptions containing `FEpost_home` are exempt from the community-post rule. Live section removal requires the radar identifier, one of three live-image/header identifiers, the home feed identifier, and its preference. Topic-chip removal excludes `video_lockup` and `shorts_video` descriptions.
- Shelf predicate `0xc73e0` mutates `content.horizontalListRenderer.itemsArray` in place, before the outer shelf Shorts test. Its horizontal, live and mix rules are intentionally broader than the item-section rules: they do not require the home identifier, live-image qualifiers or mix markers respectively. Empty shelves are not automatically removed. `getAdString` and `isShorts` come from the parent's canonical `FeedNodesHelpers.m`; the fixture links and executes that implementation.
- The engagement endpoint getter always calls its original, then returns nil for descriptions containing `mealbar_promo`. Promo setters always forward zero/nil; cap arrays are fresh mutable empty arrays; cap counts and oneof cases are zero. Event registration and surveys are suppressed. Promo-throttle callbacks return NO. `shouldThrottleInterstitial` sets `throttledAfterRecentSignIn=YES` only on existing modal rules and then returns the original result, rather than the backup's constant YES.
- `ELMComponent.node` removes product-sticker children only under `shortsNoProducts`. Action bars map five original child objects to their individual preferences. Paused-state carousels map three or four children to their original order. Each mapping snapshots objects before `removeObject:`, preserving equality-based removal of duplicate objects, and always writes back a copied array even for unexpected child counts. Ordinary node branches return the exact original node.
- Metapanel predicate `0xcb100` checks controller-child descriptions in order: description, comment composer, source and audio. The first matching kind returns its own gate even when disabled. It then recognizes a one-child suggested action or a two-child title/avatar structure. Enumeration callback `0xcc664` copies every index not selected by that predicate, preserving order and duplicates.

## Original branch and block proof

The decompiler terminates the section body at indirect jumps. Original decoded two-entry tables resolve these four consequential destinations:

| Table | False destination | True destination | Meaning |
|---|---|---|---|
| `0x1182e80` | `0xc676c` | `0xc73a4` | Compatibility ad present: return YES before description filtering. |
| `0x1182e98` | `0xc67d0` | `0xc6968` | Contents count greater than one: inspect element at index 1. |
| `0x1182eb8` | `0xc6a4c` | `0xc73a4` | Second-element ad and `noAds`: remove whole section. |
| `0x1182ed0` | `0xc6ab8` | `0xc7394` | First-element ad and `noAds`: remove whole section. |

Every table's key, XOR constant and resulting original addresses is independently checked by the verifier. Full function hashes also cover all other branch instructions. The audit excerpts are `.recovery-work/feed-filtering-000ADDRESS.txt` and can be regenerated with `inspect_binary.py START END --all`.

All five Foundation callbacks retain the original physical ABI: block pointer, object pointer, 64-bit `NSUInteger`, `BOOL *`; four return BOOL and enumeration returns void. Packaged descriptors identify `YTICommand`, `YTIItemSectionRenderer`, `YTIHorizontalListSupportedRenderers` and `ASDisplayNode` argument objects. Reconstructed source uses id/protocol boundaries instead of imposing unverified complete host class layouts; object-class annotation strings consequently differ while pointer lanes match.

## Validation and limits

Run `python3 recovery/tools/verify_feed_filtering.py` from the repository root. It pins all 27 authoritative records, hashes original bytes and constants, checks the original descriptors and four branch tables, generates actual internal-Logos code, compiles that code for arm64 iOS 13, and compares all 27 method and five block LLVM signatures. The Foundation runtime fixture executes the generated hooks under UBSan, captures original calls/arguments, and checks all 27 installed IMP changes and preserved method encodings/property counts. Its 1,175 assertions cover preference combinations, exemptions, input-copy behavior, in-place shelf mutation, canonical Shorts subscription/history exceptions, cache lifetime, product commands and all action/carousel masks. No UIKit, account, network or packaged-code execution occurs.

Some erased protobuf types cannot be inferred from replacement instructions alone: `promoType` and `watchPageTriggerCondition` use `int32_t` enum declarations; the count uses `NSUInteger` and oneof uses `uint32_t`, following Objective-C protobuf conventions. Their original semantic type/signedness is not independently proved by available vendor headers. These replacements ignore incoming values and pass/return zero, whose register representation is compatible with the plausible object/32-bit/64-bit alternatives. The manifest reports this limit rather than claiming exact host metadata recovery.

The original commerce and interstitial event callbacks (`0x6e53c`, `0x6e558`) and metapanel enumeration (`0xcc664`) include anti-debug SVC side effects. Those effects are omitted; the event-suppression and array-copy behavior is retained. Their original instruction bytes remain recorded. Obfuscated string initialization, opaque arithmetic and class-name caches are replaced with ordinary Objective-C constants and class references. Existing `ytpBool` local preference policy is used at every recovered gate; historical account-policy fidelity is parent-owned. The result is a behavior reconstruction with these explicit differences, not a claim to recover original formatting or local variable names.
