# Audio-track selector

This audit targets `showAudioTrackSelector:sender:playerVC:completion:` at
`0x107844` in the first supplied `iphoneos-arm64e` package. Run:

```sh
python3 recovery/tools/verify_first_menu_audio_selector.py
```

The original binary is parsed as data and never executed. The fixture compiles
the actual recovered source with controlled class lookup, action/sheet factories
and image lookup. Foundation performs the ordinary array filtering and sorting.

## Recovered behavior

The method collects formats whose 32-bit `itag` is 140 and whose `isDrc` is false.
Only when this list is empty does it enumerate the original input again, selecting
itag 140 formats whose newly read `isDrc` is true. Other itags short-circuit the
DRC getter. There is no MIME filter. Duplicate objects stay in the result.

The comparator at `0x108b60` reads the left audio track and display name, then the
right audio track and display name, and returns the full signed result of
`compare:`. The left name is retained, not copied, while the right name is read.
A nil left track ultimately sends `compare:` to nil. The source already agrees
with these filtering and comparison operations.

Each sorted format becomes an action with its track display name, the
`localization` image, style zero and a deferred handler. The preceding source
requested `music`; the decoded CFString at `0x1187770` establishes the correction.
The action class is resolved before either label getter. A shared cache at
`0x1227030` calls `objc_getClass("YTActionSheetAction")` only while nil. The normal
menu method also reads and writes this same address at `0xf9038` and `0xf90bc`.
The reconstruction's common action-class helper now caches successful lookups,
and the selector resolves that helper before its label and image arguments.

After creating the actions, the method resolves `YTDefaultSheetController` with
`NSClassFromString`, localizes `SelectAudioTrack`, creates a sheet with nil
submessage/delegate/parent, adds the actions, assigns the sender and presents
from the toast window's root with animation and nil completion. Even an empty
input presents an empty sheet. The `playerVC` argument is unused.

The selection callback at `0x108c48` forwards the captured format to the captured
completion. The descriptor at `0x1062350` uses copy/dispose helpers at `0xbe9a4`
and `0xbe9f4`; their object ownership operations retain the format and copy the
completion, then release both. The fixture confirms that a selected format lives
through deferred invocation after the input list leaves scope.

## Evidence and verification

The manifest pins the method, comparator, callback, call wrappers, shared-cache
instructions and block copy/dispose helpers. It checks three decoded CFStrings,
one decoded class-name string, 26 adjacent selector loads and seven decision
tables. Direct call targets, cache addresses, the comparator pointer and the
selection descriptor are checked against the original package bytes.

The fixture performs 119 checks and rejects five isolated regressions: uncached
class lookup, reading the label before resolving the class, the music icon,
skipping fallback and normalizing the comparator result to minus one/zero/one.
The full preceding source fails 34 checks in the same fixture; its early lookup
failures prevent some later checks from running. Tests cover changing getter
values between passes, lookup failure and retry, cached success, sorted callback
identity, repeated callbacks, duplicate formats, nil tracks and nil senders.

The original system traps at `0x108b1c`, `0xbe9e4` and `0xbea28` remain omitted.
The fixture uses the host's Foundation sort, not the device's implementation.
Concurrent lookup, class-object retain/autorelease timing, other temporary-object
lifetimes, and unrelated consumers of the action-class helper remain unaudited.
Toast class lookup still uses the reconstruction's dynamic helper. Resource
rendering and device presentation are outside this fixture. These differences
and limits prevent a claim of full package parity.
