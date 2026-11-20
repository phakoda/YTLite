# FFmpeg command generation and caption languages

Caption-language lookup now explicitly constructs its dictionary on every call
with a non-nil URL. The recovered mapping already matched all 80 original pairs.
However, the current compiler converted the dictionary literal into an
NSConstantDictionary and omitted the original factory call. Explicit key and
value arrays restore that call and its replacement/nil-result behavior.

## First-package evidence

The named methods are command generation at `0x1f56b4..0x1f7644` and
`codeForCaps:` at `0x1f9574..0x1fc630`. Their wrappers occupy
`0x1fcd6c..0x1fcf74` and `0x1fd798..0x1fd818`. The evidence pins all four spans,
156 decoded strings, twelve adjacent selector loads, 83 direct calls, six branch
tables and sixteen instruction words. These ranges contain no system traps.

Command generation selects a file manager before reading the caption path at
`0x1f73b0` and testing its existence. It selects a separate manager before the
thumbnail path at `0x1f740c` and its existence test. Both results are retained
across the later calls. The four format records are:

| Present inputs | Format record | Format call |
| --- | --- | --- |
| Neither optional input | `0x11be690` | `0x1f75e8` |
| Thumbnail | `0x11be6d0` | `0x1f75c4` |
| Captions | `0x11be710` | `0x1f7550` |
| Both | `0x11be750` | `0x1f74c4` |

The argument registers and wrapper stack stores establish video, audio,
optional captions, optional thumbnail, signed 64-bit duration, optional caption
language and output order. Caption language is requested once on each branch
with captions and never on the others. The formats preserve the original stream
maps, codecs, metadata, dispositions and URL interpolation without quoting.

Caption-language lookup returns nil for a nil URL through the branch at
`0x1fbef8`. Otherwise it reads the last path component, strips one extension,
constructs the dictionary and performs one subscript lookup. At `0x1fc5c4`, a nil
lookup selects the original stripped-code object as the return value.

`first_ffmpeg_language_table.py` decodes every instruction in the straight-line
constant-address stores at `0x1fbf38..0x1fc578`. It accepts only the reviewed
ADRP, ADD, STP and STR forms, rejects unknown instructions, requires exactly one
write to each of 80 key and 80 value slots, and checks the dictionary call's
array argument registers and count. The resulting ordered pairs are compared
with the manifest and the actual source factory arguments.

## Verification

Run `python3 recovery/tools/verify_first_ffmpeg_command.py`.

The verifier checks the archive and binary hashes, decoded writes, original
spans, table construction and call/branch evidence. Its fixture runs the actual
reconstructed methods against synthetic file managers, URLs, formatting and
dictionary objects. It exercises 928 command cases across optional-input flags,
all nil-URL combinations, signed duration boundaries, nil managers, nil paths,
nil language and nil formatting results. Expected commands come from the first
package's verified format strings and reviewed argument order.

All 80 language pairs also run through the actual method and constructor.
Additional cases check native filename handling, unknown code object identity,
case sensitivity, missing path components, nil stripped codes, nil dictionary
creation, nil lookup and an arbitrary returned object. Synthetic lookup accepts
a nil key so forwarding is observable; this does not claim that a native
NSDictionary lookup accepts nil. No file existence query or media conversion
reaches the host filesystem or FFmpeg library.

The source baseline failed 87 assertions because its dictionary factory was
omitted. The corrected fixture passes 8,313 assertions. Twelve separately
compiled regressions must fail: a constant dictionary literal, a wrong mapping,
79 table entries, no nil-URL return, no unknown-code fallback, normalized code
case, a cached manager, an early caption path, narrowed duration, a wrong stream
map, swapped video/audio arguments and skipped caption-language lookup.

The verifier compiles for arm64 and arm64e, checks all twelve class method
encodings and verifies that the emitted caption method contains the 80-entry
dictionary factory call. Exact temporary object lifetimes and device library
behavior remain unverified. These two methods are added to the focused audit
only after the verifier succeeds; this does not establish full class parity.
