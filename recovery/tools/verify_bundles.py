#!/usr/bin/env python3
"""Test libroot fallback and resource categories without loading a tweak/library."""
import hashlib
import json
import os
from pathlib import Path
import plistlib
import shutil
import subprocess

REPO = Path(__file__).resolve().parents[2]


def main():
    work = REPO / '.recovery-work/bundle-tests'
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for variable, name in (('TMPDIR', 'tmp'), ('CFFIXED_USER_HOME', 'home'), ('CLANG_MODULE_CACHE_PATH', 'module-cache')):
        path = work / name; path.mkdir(exist_ok=True); env[variable] = str(path)
    fixtures = work / 'fixtures'
    if fixtures.exists(): shutil.rmtree(fixtures)
    fixtures.mkdir()
    log = []
    report = work / 'report.json'
    if report.exists(): report.unlink()

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, cwd=REPO, env=env, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        log.append({'command': command, 'exit_code': result.returncode, 'output': result.stdout})
        (work / 'commands.json').write_text(json.dumps(log, indent=2) + '\n')
        print(result.stdout, end='', flush=True)
        result.check_returncode()
        return result.stdout.strip()

    def bundle(path, identifier):
        resources = path / 'Contents/Resources'
        (resources / 'en.lproj').mkdir(parents=True)
        (path / 'Contents/Info.plist').write_bytes(plistlib.dumps({'CFBundleIdentifier': identifier,
            'CFBundleName': identifier, 'CFBundlePackageType': 'BNDL', 'CFBundleDevelopmentRegion': 'en'}))
        (resources / 'en.lproj/Localizable.strings').write_text('"Translated" = "Fixture translation";\n"Empty" = "";\n')
        return resources

    root_source = REPO / 'recovery/source/Runtime/YTLRootPaths.c'
    flags = ['-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter']
    root_object = work / 'rootpaths.host.o'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-DYTL_TESTING',
         '-Ddlopen=YTLTestDlopen', '-Ddlsym=YTLTestDlsym', '-Daccess=YTLTestAccess', '-c', root_source, '-o', root_object])
    root_test = work / 'rootpaths-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, root_object, REPO / 'recovery/tests/rootpaths.c', '-o', root_test])
    for provider, marker in ((0, 0), (0, 1), (1, 0), (1, 1), (2, 1)):
        run([root_test, str(provider), str(marker)])
    categories = [REPO / 'Utils/NSBundle+YTLite.m', REPO / 'Utils/NSString+YTLite.m']
    executable = work / 'bundles-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-fobjc-arc', '-I', REPO / 'recovery/tests/shims',
         '-framework', 'Foundation', *categories, REPO / 'recovery/tests/UIKitDoubles.m', REPO / 'recovery/tests/bundles.m', '-o', executable])
    for mode in ('bundled', 'installed', 'missing', 'invalid', 'null'):
        directory = fixtures / mode; directory.mkdir()
        main = directory / 'Main.bundle'; resources = bundle(main, 'recovery.main.' + mode)
        installed = directory / 'Installed.bundle'
        if mode == 'bundled': bundle(resources / 'YTLite.bundle', 'recovery.embedded')
        elif mode == 'installed': bundle(installed, 'recovery.installed')
        elif mode == 'invalid': installed.write_text('not a bundle directory')
        run([executable, main, installed, mode])
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    for index, source in enumerate([root_source, *categories]):
        objc = ['-fobjc-arc'] if source.suffix == '.m' else []
        run(['xcrun', '--sdk', 'iphoneos', 'clang', *flags, *objc, '-target', 'arm64-apple-ios14.0', '-isysroot', sdk,
             '-S', '-emit-llvm', source, '-o', work / f'{index}-{source.stem}.ll'])
        run(['xcrun', '--sdk', 'iphoneos', 'clang', '-target', 'arm64-apple-ios14.0', '-isysroot', sdk,
             '-c', work / f'{index}-{source.stem}.ll', '-o', work / f'{index}-{source.stem}.o'])
    inputs = [root_source, *categories, REPO / 'recovery/tests/rootpaths.c', REPO / 'recovery/tests/bundles.m',
              REPO / 'recovery/tests/UIKitDoubles.m', REPO / 'recovery/tests/shims/UIKit/UIKit.h', Path(__file__).resolve()]
    report.write_text(json.dumps({'source_sha256': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest() for path in inputs},
        'runtime_tests': 'passed', 'ios_arm64_compile': 'passed', 'real_libroot_loaded': False,
        'ui_rendering_on_device': 'not tested', 'metadata_audit': 'not yet performed'}, indent=2) + '\n')
    print('Bundle categories and recovered root-path compatibility passed isolated tests and iOS compilation.')


if __name__ == '__main__': main()
