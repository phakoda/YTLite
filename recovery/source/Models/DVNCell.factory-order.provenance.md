# DVNCell factory setter order

The first package calls `setType:` before `setKey:` in the image-index,
title-index, slider, text-field, time-picker and stepper factories. The recovered
source previously reversed those messages. The image/handler factory also calls
`setRenderingMode:` immediately after `setImage:`, before `setAccessoryIcon:`
and `setType:`. Seven source sequences now follow that order.

This can affect setter overrides and observers even when final stored values
agree. The runtime fixture wraps the actual reconstructed setters, records their
calls and then invokes the original implementations. It checks all eighteen
factory entry points through the concrete class and an inheriting subclass,
with ordinary and nil object arguments. The original seven discrepancies caused
32 failures among 144 assertions; the forwarding slider entry point observes the
same affected slider implementation. The corrected source passes all 144.
Seven privately compiled regressions restore the old orders or change factories
to allocate their receiving subclass. Each must fail normally.

Run `python3 recovery/tools/verify_first_cell_factory_order.py`. The verifier
checks the first archive hash and complete factory span hashes, independently
enumerates the original selector loads, resolves message-send wrappers, and
checks the reviewed straight-line control flow. The short slider entry point
preserves its receiver and forwards to the format-taking factory with format
zero. This is a dispatch-order check, not a complete semantic reconstruction of
all factory arguments, ownership or initializer behavior. Keep the remaining
factory/lifecycle audit open and do not add these factories to the full accessor
body count.
