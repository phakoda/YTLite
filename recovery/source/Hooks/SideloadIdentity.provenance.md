# SideloadIdentity recovery

The module implements 18 ordinary local metadata, own-keychain-group and sign-in lifecycle callbacks from initializer `0x151a0`. The baseline `hooks.json` omitted all 23 direct registrations because its initializer decompilation stopped at an obfuscated branch. The supplemental original-instruction parser recovers all 23 call sites; three belong to SideloadCompatibility and two app-origin checks remain excluded. No authentication, attestation, origin-verification decision or permission-check callback is implemented here.

`YTLInstallSideloadIdentityHooks()` installs one named Logos group. There is no constructor and no new property. Parent integration owns startup scheduling, the three existing compatibility hooks, the deferred metadata group and the shared first-time global.

## Original registrations

| Class | Selector | Replacement | Original registration call |
| --- | --- | --- | --- |
| `YTVersionUtils` | `+appName` | `0x17114` | `0x16d48` |
| `YTVersionUtils` | `+appID` | `0x1720c` | `0x16d68` |
| `GCKBUtils` | `+appIdentifier` | `0x173dc` | `0x16d94` |
| `OGLBundle` | `+shortAppName` | `0x175ac` | `0x16dc0` |
| `GVROverlayView` | `+appName` | `0x176ac` | `0x16de8` |
| `OGLPhenotypeFlagServiceImpl` | `-bundleId` | `0x177ac` | `0x16e10` |
| `SSOConfiguration` | `-initWithClientID:supportedAccountServices:` | `0x17998` | `0x16e90` |
| `NSBundle` | `-bundleIdentifier` | `0x17e70` | `0x16ebc` |
| `NSBundle` | `-objectForInfoDictionaryKey:` | `0x1824c` | `0x16edc` |
| `SSOKeychainHelper` | `+accessGroup` | `0x1890c` | `0x16f10` |
| `SSOKeychainHelper` | `+sharedAccessGroup` | `0x18910` | `0x16f34` |
| `SSOKeychainCore` | `+accessGroup` | `0x18914` | `0x16f60` |
| `SSOKeychainCore` | `+sharedAccessGroup` | `0x18918` | `0x16f7c` |
| `SSOFolsomKeychainUtils` | `+sharedAccessGroup` | `0x1891c` | `0x16fa4` |
| `GNPEncryptionConfiguration` | `+keychainAccessGroup` | `0x18920` | `0x16fd0` |
| `YTFirstTimeSignInViewController` | `-viewDidAppear:` | `0x18e2c` | `0x17074` |
| `YTFirstTimeSignInViewController` | `-viewDidDisappear:` | `0x18fbc` | `0x17098` |
| `YTInlineSignInViewController` | `-viewDidDisappear:` | `0x19458` | `0x170bc` |

All evidence comes from the supplied arm package's ARM64 image, SHA-256 `bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca`. The adjacent manifest pins all 18 function bodies and helper `0x1bdc0`, 2,542 original instruction words, 25 CFStrings, three C strings, every external wrapper and six keychain wrapper chains. Nineteen recorded branches and seven separately decoded tables account for all indirect branches in those functions. The verifier checks original bytes before compiling or running the recovered source.

## Behavior and branch evidence

The first six getters return `YouTube` or `com.google.ios.youtube` without forwarding. `SSOConfiguration` forwards both initializer arguments and edits `_shortAppName` and `_applicationIdentifier` on the returned object using KVC, returning that same object. The original does not guard failed KVC or a nil result; the fixture covers both. This changes local configuration metadata, not an authentication result.

`NSBundle.bundleIdentifier` reads `NSThread.callStackReturnAddresses[2]` without a length guard, passes its full 64-bit `longLongValue` to `dladdr`, and initializes all four `Dl_info` fields to zero. The table at `0x18118` sends successful lookup to `0x1811c` and failure to original forwarding at `0x181f0`. A successful caller-image path with the main bundle path as a string prefix returns the canonical identifier. Other paths return the original result. There is no receiver-is-main-bundle condition or path-component boundary check. The companion metadata-key getter substitutes three explicit keys and forwards every other key, including nil.

The six keychain getters at `0x1890c` through `0x18920` are four-byte tail wrappers. Their distinct wrapper chains all end at helper `0x1bdc0`. It asks Security for generic-password attributes using account `bundleSeedID`, an empty service and `kSecReturnAttributes = kCFBooleanTrue`. It does not supply an access-group override or secret value. The process can discover only its own authorized namespace. If `SecItemCopyMatching` returns `errSecItemNotFound`, it tries `SecItemAdd` with the same query. An add failure returns nil. Every other copy status reaches the result's `kSecAttrAccessGroup` lookup, even another copy error. This unusual branch and the original unreleased retained attribute dictionary are preserved. Test-created results are reclaimed only by the fixture after assertions.

`YTFirstTimeSignInViewController.viewDidAppear:` forwards first, then checks `isYTPFirstTime`. If set, it clears the flag and calls the existing bundle-info installer. Original table `0x18f78` leads to clear/install at `0x18f7c` or return at `0x18fb0`. The tail registration at `0x18fac` is an additional registration absent from `hooks.json`; it selects the existing `NSBundle.infoDictionary` replacement `0x148c8` and original slot `0x191b7c0`. Its descriptor is retained in `registration-resolutions.json`. It is an alternative activation path, not another unconditional startup hook.

Both disappearance callbacks forward the original animated argument before evaluating the flag. The first-time controller shows a `YTAlertView.dialog` when the flag is clear. The inline sign-in controller first requires the current device class to have the ivar `doc_symbolName`, reads the current device a second time, and requires the returned symbol to begin with `mac` as well as the clear flag. The two missing decompiler tables at `0x19940` and `0x199d4` were decoded from original data and instructions. The dialog uses title `YouTube Plus`, the `LoginInfo` localization from `ytl_defaultBundle`, and an `OK` button with nil action, then `show`. Both paths share the alert-class cache, matching the original zero-filled global at `0x1225b28`.

## Scheduling

The original `0x151a0` initializer evaluates both the process entitlement's application identifier and the main bundle's `CFBundleIdentifier`. It skips direct compatibility registration only when they equal `EQHXZ8M8AV.com.google.ios.youtube` and `com.google.ios.youtube`, respectively. It combines the evaluated booleans with `and w8,w24,w22` at `0x16ce8`; table `0x16d14` selects install at `0x16d18` or cleanup at `0x170cc`. There is no receipt predicate.

After direct registration, `0x170c8` calls the `_ptnRegisterBlock` wrapper with block `0x1061450`, invoke `0x19b24`. That block contains six ordinary metadata registrations already owned by SideloadCompatibility and 18 security callbacks retained only as exclusions. Parent owns the historical deferred-queue timing and local subset scheduling. Regrouping the 18 callbacks before the existing three changes call order across different classes; no class-selector overlap occurs between those two direct groups.

The raw initial byte of `isYTPFirstTime` at `0x1153530` is one. A later runtime store at `0x179bfc` appears in the decoded constant overlay as zero, so that overlay cannot establish global initial state. The parent owns the canonical `YES` definition. This module declares no shared production definition.

## Verification and limits

Run `python3 recovery/tools/verify_sideload_identity.py`. It generates the real Logos methods, compiles all 18 callbacks for iOS ARM64 and compares every argument/result signature, then executes those same methods under UBSan using the Objective-C runtime and Foundation collections. All 1,335 assertions pass. Coverage includes literal getters, initializer object identity and exceptions, caller-path branches and short-stack failure, metadata forwarding, six keychain wrappers across copy/add statuses with query and output-pointer identity, all lifecycle original-first flag changes and both animated values, device ivar absence, device rereads and dialog arguments/order.

Security, loader and bundle boundaries are intercepted. The fixture sends no external requests, performs no real keychain operation and never executes the packaged dylib. Dynamic behavior in a live YouTube host remains untested. Lost symbol spelling and private object subtype names cannot be recovered from the ABI alone. Literal constants replace their initialization obfuscation; the two post-operation anti-debug supervisor calls at `0x19440` and `0x19b0c` are deliberately omitted and pinned separately in the manifest.

Rerun the independent inventory checks with `python3 recovery/tools/verify_sideload_supplemental_registrations.py` and `python3 recovery/tools/verify_registration_resolutions.py`.
