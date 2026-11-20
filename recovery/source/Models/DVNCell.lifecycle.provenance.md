# DVNCell initialization and destruction

The first package initializes DVNCell at `0x18f228..0x18f304` and destroys its
stored references at `0x1908ec..0x190a30`. This audit required no production-source
changes. Run `python3 recovery/tools/verify_first_cell_lifecycle.py`.

Initialization sends `init` through NSObject using the DVNCell super reference.
The returned object becomes self. An encoded branch selects `0x18f2a4` for a
nonnil result and `0x18f2f0` for nil. Only the successful path sends `UUID` to
NSUUID and then `UUIDString` to that result. The returned string replaces offset
24 before the old identifier is released. The UUID receiver remains retained
through that replacement. Nil UUID and string results propagate as nil storage.
Other properties are not initialized or reset here.

Destruction clears 22 owned references in descending ivar layout order. Each
slot becomes nil before its old value is released. Between controllerModel and
tintColor, `objc_destroyWeak` removes the sourceView weak reference. One original
system trap after the final strong clear remains omitted. The verifier pins its
exact argument setup and opcode separately and never executes original code.

The verifier checks original method spans, every initializer instruction,
selector loads, runtime imports/wrappers, superclass and UUID references, and
the decoded branch targets. It recognizes the entire destructor sequence from
the independently read ivar layout. Both complete optimized LLVM bodies must
match the reviewed initializer and destruction operations on iOS arm64 and
arm64e. The 83 method encodings, 32 properties and 32 ivars must also match.

The Foundation fixture executes actual reconstructed source. Its NSObject init
replacement preserves consumed-receiver and retained-result conventions, and
only intercepts the targeted receiver. Cases cover ordinary and subclass
receivers, nil/replacement superclass results, nil UUID/string results, repeated
initialization, unrelated fields, release ordering and all 22 owned references.
Ten compiled regressions must fail normally. The checks do not establish device
behavior, factory semantics or internal weak-table state.
