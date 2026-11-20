# Download menu string parsers

Target: the first supplied `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`.
The package and binary hashes are checked by:

```sh
python3 recovery/tools/verify_first_menu_parsers.py
```

The verifier compiles the actual recovered menu source against synthetic app
boundaries and real Foundation. It never loads or executes the supplied dylib.

## Recovered behavior

`getResoForQuality:` at `0x104e10–0x104f2c` sends
`componentsSeparatedByString:@"p"`, `objectAtIndexedSubscript:0`, then
`integerValue`. It has no length guard. The preceding reconstruction split at
any nondecimal character and used `firstObject`, losing a leading sign or
space. The recovered source delegates numeric conversion to Foundation and
preserves the 64-bit signed result. Nil input returns zero through nil messages.

`detailForMimeType:` at `0x104924–0x104e10` searches for the first slash, takes
the substring after that range, then the first semicolon-separated component.
It next searches the original string for `codecs="`, takes the substring after
that range, the first quote-separated component, and its first period-separated
component. The case and spacing survive. The join format is `%@ • %@`.
A missing slash leaves the container nil but still performs codec extraction.
A missing codec marker returns nil. Empty extracted components are nonnil and
can appear in a label. The old reconstruction incorrectly retained closing
quotes, truncated containers at a second slash, and indexed beyond an array
for strings without a slash.

The two bodies and dispatch wrappers at `0x112494–0x112660` are pinned by hash.
Seven decoded CFStrings, five indirect branch tables, selector references and
direct call targets are checked against the original bytes. The five tables
cover two constant-initialization branches, separator/codec presence and the
final nonnil join. The format wrapper puts the container and codec in the
variadic argument slots. Constant initialization only writes these string
buffers and terminators. No system-trap instruction occurs in these bodies.

## Verification and limits

The fixture covers ordinary labels, signs, leading whitespace, full-width
integer bounds, multiple separators, missing markers, empty components,
unterminated codecs, nil inputs and dispatch order using selector-recording
objects. It checks 49 assertions. Independent mutations restore each old parser
or replace indexed quality access with `firstObject`; each must fail.
The broader downloads fixture now expects the first package's signed quality
conversion, closing-quote removal and nil result for malformed MIME strings. Its older expectations were
reconstruction errors, not evidence of an original exception.

These checks cover the two parsers. They do not establish format filtering,
track selection, menu rendering, callback ownership, Foundation implementation
identity across operating systems, or device behavior. In particular, the
whitespace vectors describe the host Foundation used for the test; the recovered
method itself delegates that conversion to `integerValue` on the device.
