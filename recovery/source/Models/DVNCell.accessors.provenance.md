# DVNCell accessor evidence from the first package

The 63 getters and setters for 32 properties match the storage behavior in
`com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`. The existing synthesized source
accessors required no changes in this audit.

Run `python3 recovery/tools/verify_first_model_accessors.py` from the repository.
It verifies the archive and binary hashes, derives the property/accessor mapping
again from the original metadata, and recognizes each complete named method.
The manifest pins 75 spans, including twelve runtime helper wrappers. Calls must
resolve through recognized ARM64 stubs to the expected Objective-C runtime import.

Object getters load their own eight-byte slot. Strong setters use
`objc_storeStrong`; weak accessors use `objc_loadWeakRetained`,
`objc_autoreleaseReturnValue` and `objc_storeWeak`. Copy setters call
`objc_setProperty_nonatomic_copy` with the exact ivar offset. Double, signed
64-bit integer and boolean accessors load or store their corresponding slots.
The verifier checks complete optimized LLVM bodies for all 63 accessors on both
iOS arm64 and arm64e, plus all 83 method encodings, 32 properties and 32 ivars.
It rejects an injected extra effect in every compiled accessor body.

The Foundation runtime fixture compiles and executes the actual reconstructed
DVNCell source. It checks identity, self-assignment, strong ownership, replacement
before release, clearing before release, weak zeroing, copy invocation and result
ownership, nil copy results, and real block capture lifetime without invoking
stored callbacks. Numeric checks include independently seeded slots, signed
64-bit boundaries, signed zero, infinities, NaN payloads and subnormal doubles.
Readonly reuseIdentifier is seeded through KVC; the fixture never calls init or
a factory. Eleven privately compiled regressions must fail normally rather than
crash, covering wrong getters/slots, numeric narrowing, lost copying, early
release and changed ownership attributes.

Twenty-seven original system traps and their exact five-instruction argument
setup sequences are recorded as omissions. The recognizer accepts only the two
observed argument patterns and never executes original machine code. These
omissions prevent exact whole-method behavioral parity. The initializer,
destructor and eighteen factories need their own first-package audits.
Callback prototypes and invocation behavior are not inferred from opaque block
storage encodings. Host tests and cross-compilation do not establish device
behavior or identical compiler/runtime retain-call optimizations.
