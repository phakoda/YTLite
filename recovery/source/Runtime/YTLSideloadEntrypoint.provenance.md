# Sideload entrypoint

The original initializer at `0x151a0` reads `LSApplicationProxy.bundleProxyForCurrentProcess.entitlements[application-identifier]` and `NSBundle.mainBundle.infoDictionary[CFBundleIdentifier]`. It evaluates both comparisons. When both identify the original YouTube application, it returns without installing the local compatibility callbacks or queuing the later metadata callbacks. Every other result, including nil, takes the compatibility path. There is no receipt-file check.

`YTLPrepareSideloadCompatibility` reconstructs that predicate and installs the selected local callbacks. Its Boolean result tells the central entrypoint whether to install metadata hooks in the deferred phase, after Discord and before primary hooks. The original account-dependent queue is replaced by the existing local preference policy. Authentication, attestation, app-origin verification, and permission bypass callbacks remain excluded.

The direct registration audit recovers all 23 original initializer calls from original instructions. Two app-origin assertions are evidence-only exclusions. The selected callbacks are grouped into SideloadIdentity and SideloadCompatibility; this changes interleaving between different classes without changing overlapping method chains.

Run `python3 recovery/tools/verify_sideload_entrypoint.py`. It verifies the original predicate evidence, compiles for iOS arm64, then executes the actual predicate under UndefinedBehaviorSanitizer. Its 81 assertions cover 27 combinations of identity values, missing class, and missing proxy. The fixture checks both identity reads and installer order. All actual hook installations are intercepted.
