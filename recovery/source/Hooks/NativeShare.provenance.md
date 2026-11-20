# NativeShare recovery

`NativeShare.x` reconstructs both replacement registrations installed by `0xf0c4c`, plus their shared parser/presentation helper at `0xf1fbc`. The exported `YTLInstallNativeShareHooks()` installs the group immediately, with no constructor or installation-time preference gate. The original GPL-3.0-or-later license header is retained. The parent owns replacement of the older root `YTNativeShare.x` implementation and initializer ordering.

| Target | Selector | Replacement | Original IMP slot |
| --- | --- | --- | --- |
| ELMPBShowActionSheetCommand | `executeWithCommandContext:handler:` | `0xf10e8` | `0x1227058` |
| YTShareEntityEndpointCommandHandler | `executeWithCommand:entry:fromView:sender:` | `0xf1890` | `0x1227060` |

Both callbacks allocate a fresh `NSUserDefaults` with suite `com.dvntm.ytlite` and read `nativeShare` each time. Disabled calls forward all original arguments without reading descriptions. Enabled calls search for the first match of `serialized_share_entity: "([^"]+)"`. The action-sheet callback searches its own description; the endpoint callback searches the command argument's description. There is no protobuf-extension traversal in these packaged callbacks.

If the action-sheet regex matches, it reads the supplied command context's `context` and checks whether that object responds to `fromView`. A positive check causes a second context read followed by `fromView`; otherwise the shared helper receives nil. The endpoint callback supplies its `fromView` argument directly. Both callbacks suppress forwarding only when the helper returns true. The original wrappers at `0xf4aec` and `0xf4c38` preserve the two pointer arguments and normalize the helper result with `AND w0, w0, #1`.

## Payload interpretation

The helper calls the host `GPBMessage.deserializeFromString:` and returns false for nil. It constructs `GPBUnknownFields` with `initFromMessage:`. A missing/nil fields object or zero count selects the description-regex fallback. A nonzero count selects structured fields even if no recognized field produces a URL; it does not then try the regex fallback.

Structured field priority is:

1. Field 8: require exactly one outer field, parse its `lengthDelimited` data with `GPBMessage.parseFromData:error:` and a null error pointer, construct nested `GPBUnknownFields`, and extract exactly one nested field 1 as `https://youtube.com/clip/%@`.
2. Field 3: `https://youtube.com/channel/%@`.
3. Field 6: `https://youtube.com/post/%@`.
4. Field 2: playlist identifier; append `&playnext=1` unless it starts with `PL` or `FL`, then prepend `https://youtube.com/playlist?list=`.
5. Field 1: `https://youtube.com/watch?v=%@`, or `https://youtube.com/shorts/%@` if field 10 has any entries.

Each identifier field requires exactly one entry and decodes its `lengthDelimited` data as UTF-8. Missing or duplicate fields advance to the next priority. A failed clip parse or invalid nested cardinality also advances. The original formats a nil UTF-8 result through `%@`, producing `(null)` in the URL; this behavior is retained. Empty UTF-8 identifiers are accepted in the structured path.

The fallback searches the message description independently with `\\b%ld: "([^"]+)"` for field numbers 3, 6, 2, then 1. It uses the first nonempty capture and the same channel/post/playlist/watch formats. It has no clip extraction and does not inspect field 10 for Shorts. The word boundary prevents field 13 from matching field 3. Multiple occurrences use the first match. No extra whitespace tolerance or escape decoding is added.

No exception handler is added. Nil descriptions still raise Foundation's invalid-argument exception during regex matching. Errors thrown by external host methods remain external behavior. The fixture exercises invalid UTF-8 and nil descriptions without executing the host parser.

## Presentation and original geometry

A recovered URL becomes the sole string item in a `UIActivityViewController`, with nil application activities. Excluded activity types are `UIActivityTypeAssignToContact` and `UIActivityTypePrint`, in that order. The presenter comes from `YTUIUtils.topViewControllerForPresenting`.

When a popover controller exists and a source view is supplied, the source view is set to that view, while the source rectangle is its bounds converted to the presenter's view. Although the coordinate spaces are unusual, the original uses precisely this combination. Without a source view, the source view becomes the presenter's view. The rectangle is `(screenWidth * 0.5, screenHeight, 0, 0)`: the code reads `UIScreen.mainScreen.bounds` twice, taking width from the first call and height from the second. Original instructions `0xf3ee0` and `0xf3f10` save `d2` and `d3`; `0xf3f20` halves only width; `0xf3f44`–`0xf3f50` supply two zero dimensions plus the saved origin values.

The controller is presented animated with a nil completion. There are no nested blocks. If the presenter is nil, the helper still returns true after creating the activity controller; the original callback remains suppressed. It does not wait for presentation completion or share success.

## Evidence and verification

Run:

```sh
python3 recovery/tools/verify_native_share.py
```

The manifest preserves the exact two registration records, nine original instruction intervals (including initializer, callbacks, shared helper, entry wrappers, and thin wrapper range), 16 decoded strings, and all 41 original branch records from the primary and second-pass analysis. Thirty-seven conditional branch-table destinations are independently recalculated from original pointers and XOR constants. Four remaining branches belong to decoded-string initialization. The verifier checks their instruction words and the complete function hashes as well.

The expanded helper's internal calls resolve to thin Objective-C call wrappers or variadic argument-placement wrappers, covered by the original interval `0xf48ac`–`0xf5b38`. Their high-level equivalents are ordinary typed Objective-C calls and Foundation formatting. No additional semantic helper or block was omitted.

Pinned Logos generates the actual implementation. An iOS arm64 compile verifies both callbacks return void with four and six pointer arguments including self and selector. The shared helper has two pointer arguments and a normalized Boolean result. The host `fields:` declaration uses `int32_t`; counts are compared in `x0`. The popover rectangle uses four double components, confirmed both in original `d0`–`d3` handling and the emitted LLVM call arguments.

A separate macOS fixture executes the generated Logos source under UndefinedBehaviorSanitizer. Its 396 checks cover registration, fresh preference reads, original argument identity, exact regex behavior, structured/fallback field priority, cardinality, clips, Shorts, playlists, malformed data, nil results/exceptions, excluded activity types, both popover paths, repeated context/screen reads, and forwarding suppression. Foundation regex, strings, UTF-8 decoding, arrays, and geometry are real; protobuf parsing, defaults, and UIKit presentation are intercepted with synthetic objects. No actual share, account request, or network operation runs.

The original dylib is inspected, not executed. Obfuscation bookkeeping, decoded-string initialization, and protection syscalls are omitted. No assigned callback behavior remains unresolved; compatibility with a live host parser and real device presentation remains untested. Reports, input hashes, generated source, LLVM, runtime executable, and command output are recorded under `.recovery-work/native-share/`.
