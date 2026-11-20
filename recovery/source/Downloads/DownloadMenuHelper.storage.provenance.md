# Storage-space check

This audit targets `checkSpaceAvailabilityForMedia:completion:` at `0x107364`
in the first supplied `iphoneos-arm64e` package. Run:

```sh
python3 recovery/tools/verify_first_menu_storage.py
```

The verifier parses the original dylib as data. It compiles and runs the actual
reconstructed source against controlled storage-controller and formatter calls.
It never loads or executes the original binary.

## Recovered behavior

The first package caches the class returned by `objc_getClass` for
`YTAutoOfflineController`. A nil result is retried on the next invocation. Once
resolved, the class is reused, but every invocation creates a fresh controller
with `alloc` and `init`. The controller stays alive through both formatter calls
and the synchronous completion, then is released before the method returns.
The preceding reconstruction used an uncached string lookup and `new`, and
released its temporary controller before formatting and completion.

The method reads free storage once, doubles the requested size with wrapping
64-bit arithmetic, and accepts only a strict signed comparison of doubled size
against free storage. Equality fails. It formats free bytes first and the wrapped
deficit second, both with the file byte-count style, even when space is sufficient.
Success calls completion with true and nil. Failure looks up `Error.NoSpace`,
formats the message with deficit then free space, and calls completion with false
and that message. Nil class, allocation and initialization results send the
storage getter to nil, yielding zero free bytes.

## Evidence and verification

The evidence manifest pins the method and wrapper bytes, five adjacent selector
loads, 37 direct calls, three branch tables, the class-cache address, the class
name and the localization key. Imported wrappers resolve to `objc_getClass`,
`objc_alloc_init` and `objc_msgSend`. The inspected method has no system-trap
instructions.

The fixture performs 1,286 checks. It covers signed 64-bit limits, overflow,
equality, negative and zero sizes, failed class lookup followed by success,
cached successful lookup, nil allocation and initialization, formatter order,
localization only on failure, synchronous completion and controller lifetime.
It changes the storage value during formatting to verify that the original getter
result is retained. Four isolated regressions must fail: `new` construction,
uncached class lookup, premature controller release and accepting equality.
The preceding source failed 507 checks in the initial fixture.

The class cache preserves the first package's unsynchronized lookup behavior;
concurrent initialization is not tested. Class-object retain/autorelease timing,
other temporary-object lifetimes, OS-specific formatter output and device behavior
remain unaudited. These scoped checks do not establish package parity.
