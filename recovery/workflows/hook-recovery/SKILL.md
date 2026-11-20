---
name: ytlite-hook-recovery
description: Reconstruct assigned YTLite hook registrations and callback bodies from packaged evidence.
---

# Hook recovery

Read the class-recovery contract at `../class-recovery/SKILL.md` for original-image helpers, provenance, fidelity, external boundaries and shared-write rules. This phase owns only the assigned hook module and its unique fixtures.

1. Enumerate every registration for assigned target classes from `recovery/evidence/hooks.json`. Cover existing backup signatures too: presence does not establish matching behavior. Report every assigned registration's implementation address and whether it is replaced or added.
2. Expand relevant individual functions with `readable_exports.py ADDRESS...`. Resolve string constants, preference gates, original-IMP calls, block callbacks, widths and all branch destinations against original instructions. For host ABI, inspect available `vendor/YouTubeHeader/` declarations and the replacement's actual use of argument/result registers. Mark unresolved types rather than guessing.
3. Write a standalone Logos `.x` module under the assigned `recovery/source/Hooks/` path. Use canonical recovered helper classes and Runtime feature functions when appropriate. Existing local preference-only policy is an integration difference owned by the parent: preserve the gate's call and document it. Minimal host declarations belong in a uniquely named adjacent header; production must use the real host runtime classes. The parent integrates the module and resolves duplicates in root `.x` files. Do not edit root `.x`, Makefiles or shared reports.
4. Verify with pinned Logos `/tmp/ytlite-recovery/logos/bin/logos.pl`, compile generated Objective-C++ for iOS, then execute the actual hook bodies using a fixture like `recovery/tools/verify_hooks.template.x`. Test enabled/disabled branches and original forwarding, field/value widths, conditional arguments, added methods and callbacks. A source-presence or mirrored-value test alone is insufficient.
5. Deliver a manifest for every assigned registration, all original-byte evidence needed for ambiguous branches, passing rerunnable fixture(s), and a concise parent integration note. Identify behavior that could not be proved explicitly. Do not claim complete module recovery while registrations remain omitted.
