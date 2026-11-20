# Release takeover review

Scope: `/Volumes/Untitled/projects/YTLite`. Read-only review of recovery documentation and existing release evidence, followed by this note. No build, verifier, install, device connection, original-binary execution, network request, or source change was performed. Review ended at the user's instruction to write the collected findings and leave unresolved items explicit.

## Assessment

The existing evidence supports a reconstructed roothide archive with the first supplied package's layout and selected static contracts. It does not establish current source-to-package freshness, on-device loadability, or complete functional parity. Normal-target deployment and the release workflow were not inspected sufficiently to approve them. Recorded verification results below are historical evidence read during this audit, not newly rerun checks.

Recovery documentation was read before release evidence: [README](../README.md), [reproduction guide](../REPRODUCE.md), [first-package audit index](../FIRST_PACKAGE_AUDIT_INDEX.md), [parity report](../FIRST_PACKAGE_PARITY.md), and [roothide build note](../build/roothide/README.md). Some long tool output was truncated; this note only relies on visible findings.

## Supplied packages and architecture

The following SHA-256 values are recorded in [packages.json](../evidence/packages.json). They were not recomputed against the supplied archives in this audit.

| Supplied filename | Recorded archive SHA-256 | Deployment described by existing evidence |
| --- | --- | --- |
| `com.dvntm.ytlite_5.2.2_iphoneos-arm.deb` | `132db2162a7a5163c36a9c6ce5637f45139c035279bacd36e8d3b97feba4ebc7` | Files under `Library/`; CydiaSubstrate framework at `/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate` |
| `com.dvntm.ytlite_5.2.2_iphoneos-arm64.deb` | `22b67e9681e13e961ccaf284de5a8fe2558f3df83079330e08206cfe89e737f3` | Files under `var/jb/Library/`; CydiaSubstrate through `@rpath` |
| `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb` | `6a782d174644ec49fb0f0404022b183355bac8f10aa2f6270d117fab4096b889` | First-package target; files under `Library/`; loader-relative roothide/substrate libraries |

All three original dylibs are documented as Mach-O CPU type `0x0100000c`, subtype `0`: generic arm64. The Debian `iphoneos-arm64e` label therefore does not establish an arm64e Mach-O slice. All three have 58 class records and 938 named method signatures, including seven bundled-library classes; 51 first-party classes account for 864 methods. These metadata matches do not establish equal method behavior. References: [parity report, “What the first package establishes” and “Recovered deployment configuration”](../FIRST_PACKAGE_PARITY.md), [package inventory](../evidence/packages.json).

The reproduction guide names `/Users/moussah/Downloads` as the supplied-package directory. Current existence and hashes of those three original archive paths were not checked. Do not treat the documented input directory as verified current availability. No supplied original package was found or sought by a broad filesystem search during this audit.

## Normal versus roothide deployment

The parity report describes `recovery/source/Runtime/YTLRootPaths.c` as the normal `iphoneos-arm` libroot compatibility implementation. It describes `Utils/NSBundle+YTLite.m` as selecting the direct NSString resolver under `YTLITE_RESOURCE_ROOTHIDE`, enabled by `ROOTHIDE=1` in the root Makefile. These are documentation findings; the corresponding source and Makefile logic were not independently inspected in this bounded pass.

The roothide build note records a project-specific Theos module and text-based linker declarations. The declarations provide import descriptions only, not runtime implementations. The installed environment must provide both libraries and `.jbroot` resolution:

| Imported symbol | Required library install name |
| --- | --- |
| `__Z6jbrootP8NSString` | `@loader_path/.jbroot/usr/lib/libroothide.dylib` |
| `_MSHookMessageEx` | `@loader_path/.jbroot/usr/lib/libsubstrate.dylib` |

For roothide, the documented build omits the normal compatibility implementation and automatic libroot linkage. Objects/staging use `.theos/roothide/`, packages use `packages/roothide/`, and build reports use `.recovery-work/build-roothide/`. The `iphoneos-arm64` supplied rootless variant is a separate deployment layout; this audit did not establish a current reconstructed release target for it. Reference: [roothide build configuration](../build/roothide/README.md).

## Existing output and release metadata

The local filesystem listing confirmed this archive exists:

`packages/roothide/com.dvntm.ytlite_5.2.2-local.1_iphoneos-arm64e.deb`

Its listed size was 6,576,454 bytes, with a September 10 16:14 modification time. This was the only `.deb` observed in the bounded `packages/` listing. No normal-target archive was observed there.

The existing [roothide package report](../../.recovery-work/roothide-package/report.json) records:

- Archive SHA-256: `1448215f192993098f525085c06c8efd0d1632bc6d8de924bb0fa1870e569bf4`. This hash was not recomputed.
- Packaged dylib SHA-256: `dbc426f4cfd3861a814a90f35b310a1f1298f690bf8519fcec41db45edb518b5`.
- Equal archive paths, with 18 regular files, and matching file-backed runtime sections against its recorded thin build artifact. The note explains that packaging signs/strips again, so whole-file hashes differ.
- `Package: com.dvntm.ytlite`, `Name: YTLite`, `Version: 5.2.2-local.1`, `Architecture: iphoneos-arm64e`, `Depends: mobilesubstrate`, and `Installed-Size: 16328`.
- Author/maintainer `dvntm`; description `Lightweight YouTube Enhancer`; section `Tweaks`.
- Icon metadata `https://raw.githubusercontent.com/dayanch96/icons/main/ytlite.png` and Sileo depiction `https://raw.githubusercontent.com/dayanch96/icons/main/ytlite.json`. These URLs were not fetched.
- Matching method encodings for 51 first-party classes and one extra class, `Reachability`.
- `original_binary_executed: false`, `installed: false`, and device validation “not performed.”

The local version and depiction metadata differ from the original according to the build note. The precise original depiction value was not established here. This output is labeled as a local reconstruction, not an unchanged 5.2.2 release.

The report contains input hashes, including `.recovery-work/build-roothide/latest-build.json`. This audit did not compare that input map with the current tree or recompute the archive hash. Guessed filenames `build-report.json` and `package-report.json` were absent from `.recovery-work/build-roothide/`; their absence is not a build failure because the recorded build manifest uses `latest-build.json`.

## Resources and concrete locale differences

The package inventory and recovery docs record equal resource files across all three supplied packages after accounting for installation prefixes. The bundle contains `Assets.car`, `Info.plist`, `SponsorAudio.m4a`, and 13 localized `Localizable.strings` files. The recovery README reports 161 deployed asset names. No fresh asset-catalog inspection was performed.

The roothide verifier's recorded scope includes semantic resource agreement with the current layout at verification time. It records preserved differences from the original in all 13 locales. Raw source and packaged plist/string hashes can differ because packaging changes serialization; raw hash inequality alone is not a semantic mismatch. References: [deployed-resource evidence](../evidence/deployed-resources.json), [roothide report](../../.recovery-work/roothide-package/report.json), [build note](../build/roothide/README.md).

The following key differences were visible in the report output. For longer changed-key arrays, only the first two names were displayed; those rows explicitly retain that limitation.

| Locale | Added keys | Removed keys | Changed values |
| --- | --- | --- | --- |
| ar | None | None | `FeaturesNotActivated` |
| en | None | None | `FeaturesNotActivated` |
| es | None | None | 3 keys; visible names: `Account`, `FeaturesNotActivated` |
| fr | None | None | `FeaturesNotActivated` |
| it | None | None | `FeaturesNotActivated` |
| ja | None | None | `FeaturesNotActivated` |
| ko | None | None | `FeaturesNotActivated` |
| pl | `NoMoreVideosButton`, `NoMoreVideosButtonDesc` | None | `FeaturesNotActivated` |
| ru | None | None | 5 keys; visible names: `Account`, `FeaturesNotActivated` |
| tr | `LogIn` | `LogШn` | 4 keys; visible names: `Account`, `FeaturesNotActivated` |
| vi | `NoMoreVideosButton`, `NoMoreVideosButtonDesc` | None | 3 keys; visible names: `Account`, `FeaturesNotActivated` |
| zh-Hans | None | None | 3 keys; visible names: `Account`, `FeaturesNotActivated` |
| zh-Hant | None | None | `Account`, `LogIn` |

These existing edits were preserved. Their translation quality, format placeholders, runtime fallback behavior, and current consistency with the packaged archive remain unchecked.

## Security/account exclusions and parity limits

The recovery README documents 446 selected registration records and 20 evidence-only exclusions covering authentication, attestation, app-origin verification and permission bypass behavior. Historical account activation, integrity/bootstrap effects, obfuscator effects and anti-debug effects remain omitted under the existing policy. This review did not inspect or restore excluded implementations. Locale references to account-related keys do not change those exclusions.

The existing first-package method catalogue covers 218 of 864 named first-party methods; the remaining 646 are outside that focused catalogue. These counts are audit coverage, not a parity percentage. The source uses a separately rebuilt FFmpeg dependency with documented SDK/dependency-version differences. Synthetic fixtures and metadata matching do not establish behavior inside YouTube. References: [recovery README](../README.md), [first-package parity report](../FIRST_PACKAGE_PARITY.md), [audit index](../FIRST_PACKAGE_AUDIT_INDEX.md).

## Residual blockers and unresolved items

1. **Artifact freshness is unverified.** A local roothide archive and a report exist, but their hashes and recorded source inputs were not compared with the current tree. Existing pass results cannot certify today's source.
2. **Normal/rootless release output is unresolved.** No normal archive appeared in the bounded package listing; current architecture selection, staging and package identity for the normal and rootless targets were not independently audited.
3. **Device access evidence is unresolved.** Local device-tool availability was not checked before the user directed completion. There is no finding about installed device tools, pairing, connected devices or reachable devices. No device enumeration, connection or installation was attempted. Historical reports explicitly claim no device validation.
4. **Roothide runtime availability remains a deployment blocker.** Link declarations cannot demonstrate installed `libroothide`, `libsubstrate`, `.jbroot` resolution, or successful loading.
5. **Supplied archive paths need verification.** `/Users/moussah/Downloads` is documented, but current original archive availability and hashes remain unverified.
6. **Release metadata/workflows need direct review.** Root `control`, Makefile, filter plist, `Resources/depiction.json`, and `.github/workflows/` were not read directly in this pass. Package-report metadata cannot establish what a future workflow will publish. No deployment or release automation was invoked.
7. **Resource parity is intentionally incomplete.** Thirteen locale files have recorded semantic differences. Full changed-key/value review and current package-to-layout consistency remain unresolved.
8. **Complete functional parity is not established.** Exclusions, rebuilt codec differences, the extra class, partial method-specific evidence and absent device validation remain material limitations. Excluded security/account behavior is outside the restoration scope.

## Changes made by this audit

Only `recovery/notes/takeover-release-review.md` was written. The initial Git status already contained numerous modified tracked files and untracked recovery/tool/vendor directories; those pre-existing changes are not attributable to this audit. Source, shared evidence, archives and build outputs were not modified. No new verification suite was run.
