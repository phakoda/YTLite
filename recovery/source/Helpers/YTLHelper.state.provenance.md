# First-package helper flags and teardown

The target is the first supplied `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`,
with dylib SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

`+isConnectedToWiFi` at `0x22f8b8` clears a 16-byte socket address, then stores
length 16 and family 2. It creates reachability at `0x22f8ec`, reads flags at
`0x22f8f8`, and releases the reference at `0x22f918`. The two masks at
`0x22f904` and `0x22f908` intersect to `0x40002`. The conditional comparison
returns true only when the flags read succeeded, bit 1 is set and bit 18 is clear.

The new fixture executes the actual helper for every combination of the two
relevant bits and read-success flag. Other bits are independently set, all clear
or all set. Its 256 cases verify the predicate, and one additional assertion
checks the complete socket-address bytes at the synthetic framework boundary.
Reference creation succeeds in these cases. The original release call is checked
statically; the fixture does not separately instrument Core Foundation release.

The reconstruction retains an early return when reachability creation fails.
The original has no such guard: it calls GetFlags and CFRelease with the returned
reference. This remains a known difference. The existing shared test for failed
creation verifies the reconstruction's guard and is not evidence of original
failure-path parity.

The compiler-generated `-.cxx_destruct` at `0x2315d8` clears nine strong object
slots in this order:

| Offset | Ivar |
| --- | --- |
| `0x58` | `_captionsUrl` |
| `0x50` | `_audioUrl` |
| `0x48` | `_videoUrl` |
| `0x30` | `_format` |
| `0x28` | `_videoID` |
| `0x20` | `_title` |
| `0x18` | `_toastView` |
| `0x10` | `_downloader` |
| `0x08` | `_illegalChars` |

It uses eight objc_storeStrong calls followed by a tail call for the final slot.
The new runtime probe installs independently owned synthetic objects into these
ivars and records their destruction. Twelve assertions cover all populated,
alternating populated and all nil slots. Scalar ivars carry nonzero values and
are not treated as objects. Ownership and release order match the original.
No production change was needed for these paths.

`first-helper-state-fidelity.json` pins the two methods, framework-call wrappers,
ivar table and all 13 original ivar offsets. The verifier checks the supplied
package, raw intervals, parsed offsets and current runtime/ABI reports. The
focused fixture has 269 assertions.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --state
```

The supplied binary is parsed only. Reachability uses a synthetic framework
boundary, so this does not test actual network state or framework failure
behavior. The null-reference guard and the helper's other documented differences
prevent claiming full helper parity.
