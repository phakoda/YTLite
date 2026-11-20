# DVNCell factories from the first package

All eighteen factories now have argument, ownership and return-flow checks
against `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`. The seven setter-order
corrections from the earlier factory audit were sufficient; this pass required
no further source changes.

Run `python3 recovery/tools/verify_first_cell_factories.py`. A strict decoder
traces every original instruction through the reviewed register moves, double
moves, constants, global loads, stack saves/restores and known runtime calls.
It models caller-clobbered registers and requires balanced object retains and
releases. Unknown instructions, calls, values or frame operations fail. The
manifest pins each named body and all traversed runtime wrappers. Both iOS
architecture builds must produce complete LLVM bodies with the same constructor,
argument, constant, setter, retain/release and return events. No extra operations
are accepted. All DVNCell method signatures and storage metadata also match.

Seventeen factories allocate DVNCell directly, retain object arguments before
initialization and release each after its setter. They pass through nil or
replacement initializer results. The short slider factory forwards through its
receiving class, preserving all doubles and the key while adding format zero.
The image factory uses selfHandler, and sets renderingMode to one. The decoded
contracts retain each factory's specific type constant and signed integer width.

The runtime fixture runs actual reconstructed factory methods. A replacement
initializer preserves consumed-receiver and retained-result conventions, drops
caller-owned argument references during construction, and returns nil or a
recorder. The recorder observes exact setter arguments without retaining them.
Argument destruction must follow the original release sequence. Cases exercise
ordinary and nil object arguments, stored blocks without invoking callbacks,
signed 64-bit values, double bit patterns, concrete allocation through an
inheriting subclass, and a subclass override of the slider forwarding target.
The suite passes 1,408 assertions; thirteen compiled regressions must fail
normally. Each compiled method also rejects an injected extra side effect.

Initializer, accessor and destructor behavior is covered separately. The host
recorder is a controlled boundary and does not reproduce YouTube or UIKit.
Device execution and the previously documented omitted system effects remain
outside this evidence. Complete DVNCell method coverage does not establish full
tweak parity.
