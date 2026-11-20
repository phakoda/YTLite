# First-package helper initialization

The first supplied `iphoneos-arm64e.deb` contains `-[YTLHelper init]` at
`0x22aa5c`. This audit uses binary SHA-256
`59b0ddc0c8ca14863d20b0005c0c48e062e81a0df6611e213a3a66fa2b796023`.

The method calls super's initializer at `0x22ab94`. The decoded nil-result
branch selects `0x22abd0` for a nonnil result and `0x22ac20` for nil.
On the nonnil path, `0x22abd8` calls `objc_alloc_init` on `ToastView` through
the wrappers at `0x23166c` and `0x23165c`. It stores the returned object in
the toast ivar at `0x22abe0`, then calls the character-set factory at
`0x22ac04` with the eight-character string `/\?*|"<>`. It stores that
result at `0x22ac14`. Neither factory result controls another branch.

The recovered source previously created the character set first, then sent
`new` to `ToastView`. It now creates and stores `[[ToastView alloc] init]`
before constructing the character set. The super-initialization guard remains.

`helper_init_runtime.m` executes the actual helper initializer with replaced
toast and character-set factories. Its 28 assertions check construction order,
storage before the next factory call, the original string, result identity,
and absence of `new` dispatch. Four cases cover every combination of nil and
nonnil factory results. The previous source failed with the observed event
sequence `characters, toast`; the corrected source passes. The previous
source and failed report are retained in `.recovery-work/helper-init/before-*`.

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py --init
```

The focused verifier checks the first archive and binary hashes, raw method
and wrapper bytes, the decoded string, selector references, nil-super branch
table, and current actual-source runtime and ABI reports. Evidence is stored
in `recovery/evidence/first-helper-init-fidelity.json`.

The runtime fixture replaces toast initialization and therefore does not prove
native toast behavior. The nil-super branch is checked statically, not induced
by modifying NSObject in the test process. No original executable is loaded.
This audit establishes only the initializer behavior described above.
