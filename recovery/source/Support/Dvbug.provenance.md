# Dvbug

All eight class methods are reconstructed from the supplied arm package, pinned by `Dvbug.manifest.json`. Method encodings match the packaged metadata exactly. The integer methods both return `long long` and load eight bytes, despite one method's `Int` name. The BOOL methods load or store one byte.

`instanceForObject:name:` checks for a missing object or empty name, checks whether the ivar exists, then uses KVC. That distinction matters because KVC may invoke an accessor or box a scalar. `observeIvar:name:` and `getObservedIvar:name:` use `object_getIvar` instead. The object setter uses `object_setIvar`. Missing ivars return nil or zero, or leave the object unchanged. The diagnostic strings are retained.

The integer loads use `memcpy` to express the original eight-byte memory read without an aliasing or alignment assumption. Compiler-generated wrappers, string decoding and opaque control flow are omitted. No source identifier spelling beyond packaged method metadata is claimed.

Run `python3 recovery/tools/verify_bootstrap_helpers.py`. It checks original instruction hashes, exact iOS method encodings, and actual Objective-C implementations under UBSan. Fixtures distinguish KVC from direct ivar reads, exercise signed 64-bit values, verify missing ivars and check that BOOL writes preserve adjacent bytes. The supplied binary is never loaded.
