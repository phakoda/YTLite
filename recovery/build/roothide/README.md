# First-package build configuration

The project can now build a local reconstruction using the deployment layout
of `com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb`:

```sh
python3 tools/build_local.py package --scheme roothide
python3 recovery/tools/verify_roothide_package.py
```

Output is
`packages/roothide/com.dvntm.ytlite_5.2.2-local.2_iphoneos-arm64e.deb`.
This is reconstructed code with a local version label, not the original release.
Neither command installs a package or loads the original or rebuilt dylib.

The first archive has 18 regular files beneath `Library/`, including its bundle,
dylib and YouTube filter plist. Its Debian architecture field is
`iphoneos-arm64e`, but its Mach-O CPU type and subtype are generic arm64. The
project-specific Theos module in `../theos-modules/roothide/` reproduces that
layout and architecture field. It is not a general roothide SDK or runtime.

The first binary declares these dependencies:

| Import | Runtime library |
| --- | --- |
| `__Z6jbrootP8NSString` | `@loader_path/.jbroot/usr/lib/libroothide.dylib` |
| `_MSHookMessageEx` | `@loader_path/.jbroot/usr/lib/libsubstrate.dylib` |

The text-based linker declarations under `lib/` describe only those imports.
They contain no library implementation. The CydiaSubstrate header and module
map were copied unchanged from the local vendored Theos framework; the header
retains its copyright and redistribution notice. The framework's linker
declaration points to the first package's `libsubstrate.dylib` install name.
The installed environment must supply these libraries and the `.jbroot`
resolution mechanism. Device availability and loading have not been tested.

For this target, `NSBundle+YTLite.m` uses the direct NSString resolver. The
other target's `YTLRootPaths.c` compatibility implementation and automatic
libroot linkage are omitted. The default build retains its existing selection.
Objects and staging are isolated under `.theos/roothide/`, packages under
`packages/roothide/`, and build reports under `.recovery-work/build-roothide/`.
The build wrapper hashes the module, link declarations, framework header/module
map, filter plist, package adapter and Theos package writer as well as its
existing source/resource inputs.

The repository's ExFAT volume reports staging directories as `0700` even after
`chmod 0755`. Theos's Debian writer rejects that control-directory mode.
`tools/package_deb.py` copies the stage to `/tmp`, where Unix permissions work,
then runs the unchanged Theos writer. It sets directories and the dylib to
`0755`, and resources and the control file to `0644`. It copies the finished
archive back to the repository and removes the temporary copy. This applies
to the default package target too. The regression test exercises the actual
writer with restrictive modes, verifies archive contents and permissions,
and checks that a writer failure preserves an existing output.

The verifier reads both archives as data and checks all 18 regular-file paths,
CPU type/subtype, package identity/architecture/dependency fields, filter plist,
the two external library bindings, and all 51 first-party class method
encodings. It also checks that every packaged resource agrees with the current
layout source and that archive members have the intended permissions.
These normalized permissions differ from the original archive's mix of
`0755`/`0775` directories and `0644`/`0664` resource files.
Theos signs/strips the packaged aggregate again, so its file
hash differs from the thin build artifact; the verifier compares every
file-backed section's address, size and contents to establish their relationship.

The report is `.recovery-work/roothide-package/report.json`. It records the
13 locale files whose values differ from the original and the existing extra
`Reachability` class. Those locale changes are preserved. The local version and
depiction metadata also differ from the original control file. The codec is the
separately rebuilt dependency, and documented behavioral gaps remain.

Passing this check establishes archive construction and the listed static
contracts. It does not establish on-device loadability or full functional parity.
