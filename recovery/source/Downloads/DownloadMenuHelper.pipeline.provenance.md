# DownloadMenuHelper handoff, first-package audit

The recovered video handoff now creates `YTLHelper` with `alloc` followed by
`init`. It previously sent `new`, which can select a different class method.
The first binary calls `objc_alloc_init` at `0x106848`, through wrappers
`0x112df8` and `0x112de8`. The focused fixture reproduced the extra `new` call
before the fix and passes after this source change.

The audited method is
`-downloadVideoWithUrl:audioUrl:fileName:extension:videoID:videoSize:audioSize:duration:captions:playerVC:`
at `0x1065cc..0x1069c0`. The evidence JSON pins this body, its wrappers,
eight selector loads, two preference branches, the `embedThumbnails` string and
the allocation and argument-forwarding call targets.

The first binary resolves application, delegate, window and root in that order.
It allocates and initializes a helper even if the root is nil. It sends the
initialization result to the root's setter and obtains the download receiver
through a fresh `helper` getter. It forwards the original object arguments and
all 64 bits of video size, audio size and duration. After the download call, it
checks whether the player is nil. Only a nonnil player triggers the thumbnail
preference read; a true result then calls `getThumbnail:` on the original menu.

The two download wrappers at `0x112e70` and `0x112e48` copy 24 bytes of stack
arguments before forwarding them. This preserves audio size, duration and the
captions pointer in addition to the register arguments. The method ends with an
omitted system trap at `0x10699c`; that effect is not restored or claimed as
verified behavior.

## Verification

Run:

```sh
python3 recovery/tools/verify_first_menu_pipeline.py
python3 recovery/tools/verify_downloads.py
python3 tools/build_local.py all
python3 tools/build_local.py package --scheme roothide
```

The focused test compiles the actual menu, media utility and local preference
policy. UIKit, helper construction and the downstream downloader are synthetic
boundaries. All 298 assertions pass across 50 handoffs, covering a nil allocation,
a nil or replacement initialization result, missing application roots, a getter
that returns a different helper or nil, nil arguments, large unsigned values and
preference changes during the download call. Thumbnail handling is overridden
by the fixture, so it performs no network or file operations.

The verifier also compiles the menu for arm64 and arm64e and compares its 26
method encodings directly against the first package. These ABI checks do not
extend behavioral coverage to the other 25 methods or their callbacks. It reruns
the former `new` implementation in an isolated source copy and requires the
fixture to reject its call sequence.

The original dylib is read as data and never executed. Real YouTube loading,
thumbnail fetching, exact temporary retain/release timing and device behavior
remain unverified. The actual local preference policy remains a documented
difference from historical account-dependent behavior.
