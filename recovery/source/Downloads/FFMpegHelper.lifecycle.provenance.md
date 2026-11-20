# FFmpeg helper lifecycle

The existing singleton, initializer and ARC destructor match the reviewed
first-package lifecycle contracts below. This audit adds evidence and regression
checks without changing those method bodies.

## First-package evidence

`sharedInstance` occupies `0x1f3a68..0x1f3b1c`, with its once invoke at
`0x1f3b1c..0x1f3b60`. Initialization occupies `0x1f3b60..0x1f3e30` and the
destructor `0x1fc630..0x1fc688`. The latter range is followed by the reviewed
dispatch and Objective-C wrappers through `0x1fc708`.

The singleton captures the receiving class at block offset 32, initializes an
instance of that class inside dispatch_once, and stores the result in the shared
slot at `0x1227f38`. The once token at `0x1227f40` remains complete even when
initialization returns nil. Subsequent receiving classes use the same slot.

Initialization invokes the superclass using the verified FFMpegHelper class
reference, then uses the returned object as self. Nil returns skip queue setup.
The successful path creates a queue with the exact label
`com.dvntm.ffmpeg.serialqueue` and nil attributes. It stores the queue at offset
8 before releasing the old value, then clears the processing byte at offset 40.
The statistics, toast and duration fields are not assigned by this initializer.

The destructor clears strong slots in toast, statistics, queue order, at offsets
24, 16 and 8. Each store clears its slot before releasing the previous object.
Two original system traps in the once invoke and destructor remain omitted.

## Verification

Run `python3 recovery/tools/verify_first_ffmpeg_lifecycle.py`.

The verifier pins the supplied archive and binary hashes, two spans containing
the named methods and wrappers, seventeen direct calls, seventeen instructions,
three branch tables, the superclass reference, one selector load and the decoded
queue label. It rejects constant writes outside the reviewed label buffer.
The supplied binary is parsed as data and never loaded or executed.

The fixture runs the actual reconstructed methods with a controlled NSObject
initializer and synthetic queue objects. It retains the real declared superclass
and method signatures. The replacement initializer preserves init's consumed
receiver and retained result conventions. Cases cover nil and replacement
superclass results, nonnil and nil queue creation, reinitialization, queue
replacement order, processing reset and preservation of unrelated fields.

Weak references check ownership. During child destruction, the fixture reads
raw pointer slots without retaining or messaging the owner being destroyed.
This checks that slots are cleared before release and that the toast, statistics
and queue are released in the original order.

Separate processes exercise base-class, subclass and nil-result singleton
initialization, including 32 rounds of calls through both classes. The four
processes pass 153 assertions. Eleven compiled regressions must fail: a wrong
queue label, concurrent attributes, missing or early processing reset, clearing
the old queue before creating its replacement, clearing unrelated statistics,
skipping superclass initialization, retrying the singleton, fixing its class,
and releasing statistics or the queue before the toast.

The verifier also compiles production source for arm64 and arm64e and compares
all twelve class method encodings. Native dispatch queue operation, concurrent
singleton access and device behavior remain unverified. This completes the
focused named-method catalogue for FFMpegHelper, not full behavioral or device
parity for the class or package.
