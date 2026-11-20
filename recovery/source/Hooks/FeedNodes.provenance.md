# Feed-node recovery

`FeedNodes.x` reconstructs all seven `ASDisplayNode` registrations in the primary registrar at `0x53fac`. `FeedNodesHelpers.m` reconstructs `getAdString` at `0x482c8`, `isShorts` at `0x4a3a8`, and `innertubeName` at `0x4c9f8`. The manifest pins each complete original function to the canonical package SHA-256.

The original registrar adds retained, nonatomic `NSString *copiedComment` and `NSURL *copiedURL` properties to `ASDisplayNode`. The backup attached them to `ELMContainerNode`. The reconstructed properties belong to the packaged superclass, with no backing ivars. Accessors at `0x4ce78`, `0x4ce84`, `0x4cebc` and `0x4cec8` use associated objects. The runtime fixture verifies exact metadata, identity, retention, mutation visibility and clearing.

## Yoga children

`setYogaChildren:` at `0x9a4bc` forwards the input unchanged unless its controller is an `ELMNodeController` whose owning component description contains `shorts_action_bar.eml` or `reel_action_bar.eml`. The initializer block at `0xcafec` creates a weak-key, strong-value `NSMapTable` once. Its global block literal is at `0x1061fe0`, and the original map storage is at `0x1225f30`.

The method restores cached children missing from the current input by comparing accessibility identifiers. It caches an immutable copy before filtering. The predicate at `0xcb028` consults the six original hide-button preferences. The original receives an immutable filtered copy. Nil identifiers do not compare equal, so a cached node with a nil identifier can be appended again. This behavior is retained and tested. The dealloc replacement at `0x9c03c` removes the receiver from the map before forwarding.

## Capturing text

`setFrame:` at `0x9c084` forwards the original CGRect first. With `commentManager`, an `ASTextNode` whose KVC `_accessibilityIdentifier` equals `id.comment.content.label` supplies its attributed text's string to the first supernode whose description contains `id.ui.comment_cell`. With `postManager`, an `ELMExpandableTextNode` whose current text node is an `ASTextNode` supplies text to the first supernode matching `id.ui.backstage.original_post`. Both paths check selector availability and nonnil attributed text. Empty strings are retained as valid text. No match or nil text leaves existing copied text untouched.

The initial decompiler export stopped at the comment-manager branch and omitted these loops. `recover_feed_node_branches.py` supplements the conservative control-flow analyzer with 18 manually reviewed stack-table facts. It verifies every original instruction word, decodes the table offset as signed `-(key XOR constant)`, retains both Boolean outcomes, and writes analysis-only branch islands. The completed graph has 1,300 reachable instructions and 23 resolved indirect branches within original function bounds `0x9c084` through `0x9d4d4`.

The stack table pointers are initialized at `0x9c0f0` through `0x9c208`. The analyzer conservatively loses these facts after fast-enumeration calls; the table slots are distinct from the enumeration-state/output buffers. Reviewed flag conditions include the enumeration counts at `0x9cdcc`, `0x9cf8c`, `0x9d260`, and `0x9d314`; mutation comparisons at `0x9ce40`, `0x9cf3c`, `0x9d2d0`, and `0x9d418`; and end-of-batch comparisons before `0x9cf28` and `0x9d404`. Other reviewed conditions preserve the preference/class/selector result in w0, w22 or w25 until the indexed branch. The generated report records each table, key, XOR constant and condition. This is a reviewed reconstruction aid, not a claim that all stack-alias facts were proved automatically.

`repair_decompilation.py --project-root` supports an isolated copy of the existing Ghidra project. The recovered full export is under `.recovery-work/feed-nodes-decompiled/`. Neither this process nor the fixtures execute or modify the supplied binary.

## Helpers and validation

The ad helper preserves the order of all 23 substrings, including `grid_ads` preceding `grid_ads_image_layout`. The Shorts helper preserves the literal `history*` exclusion and the subscription-feed exception. The name helper uses the original first-match regular expression and UTF-16 ranges.

Run `python3 recovery/tools/verify_feed_nodes.py` for the original-byte checks, iOS compilation/signature audit and 1,318 actual runtime checks under UBSan. The fixture exercises all 64 hide-button combinations for both action-bar descriptions, restoring cached buttons, replacing nodes with the same identifier, weak-key cleanup, CGRect forwarding, both text paths, absent selectors, nil and empty text, and helper branches. Foundation operations are real; YouTube node classes are synthetic. Device layout and the real host's private contracts remain unverified.

Run `python3 recovery/tools/recover_feed_node_branches.py` to regenerate the additional analysis evidence. Its reviewed facts apply only to the pinned package, not arbitrary binaries. The local feature-policy implementation remains an explicit integration difference from the original account-gated policy.
