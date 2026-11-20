# Caption availability, filtering and labels

This audit targets three methods in the first supplied `iphoneos-arm64e` package:
`hasCaptions:` at `0x108c58`, `captionsForDownloading:` at `0x10b290`, and
`titleForCaption:` at `0x10ba6c`. Their current source agrees with the inspected
selection logic and call order, so this audit requires no production change.

Run:

```sh
python3 recovery/tools/verify_first_menu_captions.py
```

The original binary is parsed as data and never executed. The fixture compiles
and runs the actual recovered methods with synthetic player, caption and
preference objects, using the host Foundation implementation.

## First-package behavior

`hasCaptions:` fetches the active video's caption array before reading
`addAutoCaps`. When enabled, it returns whether the array's full-width count is
nonzero, without reading identifiers. Otherwise it returns true at the first
track whose independently read `VSSID` values do not start with `t.`, `a.` or
`ta.`, tested in that order with short-circuiting. Nil identifiers behave like
original captions because sending `hasPrefix:` to nil yields false. Nil or empty
arrays yield false.

`captionsForDownloading:` first constructs a mutable array and scans every
input caption with the same three-step predicate. Only after filtering does it
read `addAutoCaps`. If enabled, it returns the input array itself, including an
empty array or nil. Otherwise it returns the mutable working array if nonempty,
or nil if no caption qualified. Qualifying duplicates retain their input order.

`titleForCaption:` checks `t.` first and, when that fails, reads `VSSID` again
for `ta.`. A matching track gets its display name followed by the localized
`Translated` or `TranslatedAutoGen` label, using `%@ (%@)`. The display-name
getter runs before localization, and the name object is retained rather than
copied across that lookup. Other tracks return the display-name object itself.
An ordinary `a.` automatic caption has no added title suffix.

## Evidence and verification

The evidence manifest pins all three bodies and their inspected wrappers,
13 decoded CFStrings, adjacent selector loads, direct call targets and 14
initialization/selection branch tables. The inspected bodies and wrappers
contain no system-trap instructions. Enumeration control flow is inspected and
pinned by body hashes, but its individual tables are not all modeled by this
verifier.

The fixture runs 195 checks across nil, empty, original, translated, automatic,
case-sensitive and whitespace-prefixed identifiers. It checks separate getter
reads, preference changes during identifier access, track-list replacement during
preference access, full-width count handling, returned-array identity and
mutability, duplicates, early availability return, mutable display names and
nil caption/name handling.

Five independent regressions must fail: caching the identifier, reading the
filter preference too early, copying the original array, truncating the count,
and using the wrong translated-automatic label.

These checks cover the three methods' selection and forwarding behavior.
Temporary-object release timing, concurrent input mutation, device Foundation
behavior, caption-sheet presentation, parser completion and file sharing remain
outside this audit. This is not a claim of full package parity.
