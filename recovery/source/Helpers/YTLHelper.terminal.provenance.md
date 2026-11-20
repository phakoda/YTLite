# First-package failure reporting and cleanup

This audit uses the first supplied `iphoneos-arm64e.deb`, binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

`downloadDidFailureWithError:` starts at `0x22d4cc`. Its nil-error branch
at `0x22d678` and signed 64-bit code comparison at `0x22d68c` skip reporting
for nil or code -999. There is no error-domain comparison. Other codes enter
the log call at `0x22d6cc`, using `YTPlus --- %@`. The method reads the toast
ivar at `0x22d6d0`, obtains the localized description at `0x22d6e0`, and sends
that description with false success at `0x22d704`. The existing source matches
this order and these conditions.

`cleanup` starts at `0x22e1a4`. It calls `NSTemporaryDirectory` at `0x22e260`
before reading the download ID at `0x22e278`. It formats that ID with `%@`,
appends the resulting path component, and calls `fileURLWithPath:` at
`0x22e2cc`. It then gets the default file manager at `0x22e304` and sends
`removeItemAtURL:error:` at `0x22e324`, passing the URL result and a null error
pointer. It does not clear the ID or branch on the URL or removal result.

The previous reconstruction passed the ID into `YTLDownloadDirectory` before
looking up the temporary directory. That helper also used explicit directory
flags and URL-based path appending. Cleanup now reads the ID after the temporary
directory call and uses the original string formatting, path appending and
`fileURLWithPath:` sequence. Other callers of `YTLDownloadDirectory` are unchanged.

The 38 assertions in `helper_terminal_runtime.m` execute the actual helper.
An NSError subclass checks nil and cancellation branches, a different domain,
a 64-bit code that shares cancellation's low 32 bits, and nil description
forwarding. It replaces the toast during log formatting and description lookup
to verify when the receiver is read. A temporary-directory string probe changes
the download ID at that boundary. A URL factory and file-manager double verify
the path, selector, call order, result identity and nil results. The fake manager
returns failure without touching files. The prior source failed because it
skipped `fileURLWithPath:`; its source and report are retained under
`.recovery-work/helper-terminal/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --terminal
```

The focused verifier checks the first archive and binary hashes, method and
wrapper bytes, both error branches, decoded strings, selector references, and
current runtime and ABI reports. Evidence is in
`recovery/evidence/first-helper-terminal-fidelity.json`.

This is not whole-method parity. Cleanup retains the documented single-path-
component validation absent from the original. System-trap instructions at
`0x22d72c` and `0x22e34c` remain excluded from recovered executable source and
are not exercised. The fixture uses synthetic log, toast, temporary-directory,
URL and file-manager boundaries. Device behavior is unverified; no original
binary is loaded or executed.
