# Sideload compatibility recovery

This is a partial module. It reconstructs nine compatibility registrations and two nested UI completion blocks. Fourteen assigned security-related registrations remain inventory-only. The full initializer decision tree is not implemented.

The source evidence is the arm slice from the supplied 5.2.2 package, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The adjacent manifest records original instruction interval hashes, decoded strings, exact inventory records for the six metadata callbacks, and supplemental registration records for the three local callbacks. The inventory export stops before those three calls, so their registration evidence comes from original instructions at `0x16fd4` through `0x17050`. Original callback pointers, selector loads, original-IMP slots and call instructions agree with those records.

| Class | Selector | Callback | Registration |
| --- | --- | --- | --- |
| NSFileManager | `-containerURLForSecurityApplicationGroupIdentifier:` | `00018924` | `00016ff8` |
| SFAuthenticationViewController | `-viewDidAppear:` | `00018b78` | `00017024` |
| YTInlineSignInController | `-didTapShowAddAccount` | `00018c88` | `0001704c` |
| NSMutableURLRequest | `+ak_clientInfoHeader` | `0x0001ad14` | `00019b24` |
| NSMutableURLRequest | `-allHTTPHeaderFields` | `0x0001b16c` | `00019b24` |
| LSApplicationProxy | `-teamID` | `0x0001b564` | `00019b24` |
| LSApplicationProxy | `-appIDPrefix` | `0x0001b688` | `00019b24` |
| LSApplicationProxy | `-applicationIdentifier` | `0x0001b7b0` | `00019b24` |
| LSBundleProxy | `-bundleIdentifier` | `0x0001ba30` | `00019b24` |

The file-manager callback returns the last Documents URL with the fixed `AppGroup` component for every non-nil group identifier. It ignores the identifier contents. A nil identifier forwards to the original IMP. No directory is created and no access outside the application's own Documents directory is requested.

The authentication view callback calls the original appearance method before reading `isYTPFirstTime`. When set, it presents the canonical `InitWorkaround`. Its completion dismisses the host and supplies another completion block. Only that dismissal completion runs the optional remote dismissal notification and displays the localized retry dialog. The presenter does not clear the shared flag. The inline sign-in callback clears the flag before calling the canonical bundle-info installer, then forwards to its original IMP.

Original completion entrypoints are `0x1c080` and `0x1c0f8`; both capture the host at block offset `0x20`. The optional remote notification uses `performSelector:` with `remoteViewControllerWillDismiss:` and no supplied argument at `0x1c440` through `0x1c450`. This is an original call-site quirk. A valid argument cannot be inferred. The fixture uses an unsafe, unread parameter solely to observe that the dispatch occurs; it does not establish that an arbitrary host implementation can safely consume the missing argument.

The two header callbacks copy the original dictionary, replace occurrences of the running bundle identifier inside the relevant header if present, and return an immutable copy. Unrelated headers remain intact. The two application/bundle identifier callbacks transform the original result. The signing metadata getters return the original package's fixed strings without forwarding. These six callbacks contain metadata transformations; their bodies do not demonstrate authorization decisions. The separate installer preserves that distinction.

Production declarations use UIKit's `UIViewController` and Foundation's actual classes. The appearance argument is UIKit `BOOL`, passed as an iOS `i1` value. Header, path and identifier values are Objective-C pointers; the metadata callbacks have no explicit arguments. Both nested completions return void and receive a single block pointer. The verifier checks emitted iOS LLVM widths and executes the generated Logos bodies on macOS with isolated fixture class names.

Run `python3 recovery/tools/verify_sideload_compatibility.py`. It validates original-byte hashes, decoded strings, source/Logos callback coverage, iOS compilation and LLVM signatures, then executes the generated callbacks under UndefinedBehaviorSanitizer. Fixtures cover original forwarding, nil and empty data, both first-time branches, post-original flag evaluation, nested completion ordering, the optional remote notification, metadata copy behavior, repeated identifier occurrences and fixed metadata getters. Framework hooks target unique fixture classes. No supplied binary, network operation, keychain request or entitlement query is executed. Existing `InitWorkaround` and bundle installer behavior belongs to their separately verified production module; this fixture observes those boundaries.

For integration, compile `SideloadCompatibility.x` with the existing `Runtime/InitWorkaround.m` and bundle category. `YTLInstallLocalSideloadCompatibilityHooks()` installs the three callbacks originally registered by initializer `0x151a0`. `YTLInstallSideloadMetadataCompatibilityHooks()` installs the six metadata callbacks originally registered in `0x19b24`. Both are explicit installers, with no constructor. Parent owns routing and removal of duplicate hooks in root files. This source does not establish when the historical initializer's conditions permit registration, nor provide a replacement entitlement or security gate.

The following fourteen assigned callbacks remain inventory-only. Their executable bodies are omitted because they alter playback authentication/attestation enforcement or the reported authorization of local-network access. This is an explicit recovery boundary, not an unresolved decompiler guess.

| Class | Selector | Callback | Behavioral area |
| --- | --- | --- | --- |
| YTIIosPlayerAttestationConfig | `-iosguardEnable` | `0x0001bcb8` | playback authentication and attestation handling |
| YTIIosPlayerAttestationConfig | `-hasIosguardEnable` | `0x0001bcc0` | playback authentication and attestation handling |
| YTIHeartbeatAttestationConfig | `-requiresAttestation` | `0x0001bcc8` | playback authentication and attestation handling |
| YTIHeartbeatAttestationConfig | `-hasRequiresAttestation` | `0x0001bcd0` | playback authentication and attestation handling |
| YTIHeartbeatResponse | `-stopHeartbeat` | `0x0001bcf8` | playback authentication and attestation handling |
| YTIHeartbeatResponse | `-hasStopHeartbeat` | `0x0001bd00` | playback authentication and attestation handling |
| YTIHeartbeatResponse | `-authenticationMismatch` | `0x0001bd08` | playback authentication and attestation handling |
| YTIHeartbeatResponse | `-hasAuthenticationMismatch` | `0x0001bd10` | playback authentication and attestation handling |
| YTSingleVideoHeartbeatController | `-haltIfNeeded` | `0x0001bd18` | playback authentication and attestation handling |
| YTPlaybackHeartbeatController | `-haltPlaybackWithError:forHeartbeatController:` | `0x0001bd1c` | playback authentication and attestation handling |
| MDXLocalNetworkPermissions | `-lastKnownPermissionsStatus` | `0x0001bd20` | local network permission reporting |
| MDXLocalNetworkPermissions | `-isAuthorized` | `0x0001bd28` | local network permission reporting |
| MDXLocalNetworkPermissions | `-localNetworkPermissionCheckRequired` | `0x0001bd30` | local network permission reporting |
| MDXLocalNetworkPermissions | `-verifyAccessWithCompletion:` | `0x0001bd38` | local network permission reporting |

The four `YTIIosPlayerConfig` registrations in `0x19b24` belong to the Configuration assignment. They are outside this module, and no activation predicate for them is supplied here. Earlier initializer identity/keychain hooks, initializer activation decisions and later first-time sign-in view callbacks are not implemented by this module. Obfuscation bookkeeping, decode initialization and protection syscalls are omitted from the readable reconstruction.
