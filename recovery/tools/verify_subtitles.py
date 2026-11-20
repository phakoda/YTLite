#!/usr/bin/env python3
"""Test actual subtitle/translation source offline; compile it for iOS arm64."""
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

REPO = Path(__file__).resolve().parents[2]


def main():
    root = REPO / '.recovery-work/subtitle-tests'
    root.mkdir(parents=True, exist_ok=True)
    work = root / 'fixtures'
    if work.exists():
        shutil.rmtree(work)
    work.mkdir()
    env = os.environ.copy()
    for name, relative in (('TMPDIR', 'tmp'), ('CLANG_MODULE_CACHE_PATH', 'module-cache'),
                           ('HOME', 'home'), ('CFFIXED_USER_HOME', 'home')):
        directory = root / relative
        directory.mkdir(exist_ok=True)
        env[name] = str(directory)
    sources = [REPO / 'recovery/source/Subtitles' / (name + '.m') for name in ('SRTParser', 'YTPTranslator')]
    tests = [REPO / 'recovery/tests/subtitles.m', REPO / 'recovery/tests/MetadataAudit.m']
    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter']
    commands = []

    def run(command):
        command = [str(value) for value in command]
        result = subprocess.run(command, cwd=REPO, env=env, text=True,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        commands.append({'command': command, 'exit_code': result.returncode, 'output': result.stdout})
        (root / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        print(result.stdout, end='', flush=True)
        result.check_returncode()
        return result.stdout.strip()

    executable = root / 'subtitles-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-DNSTemporaryDirectory=YTLTestTemporaryDirectory',
         '-framework', 'Foundation', *sources, *tests, '-o', executable])
    run([executable, REPO / 'recovery/evidence', work])
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    objects = []
    for source in sources:
        obj = root / (source.stem + '.ios.o')
        run(['xcrun', '--sdk', 'iphoneos', 'clang', *flags, '-target', 'arm64-apple-ios13.0',
             '-isysroot', sdk, '-c', source, '-o', obj])
        objects.append(obj)
    run(['xcrun', 'libtool', '-static', '-o', root / 'libYTLiteRecoveredSubtitles.a', *objects])
    inputs = sources + list((REPO / 'recovery/source/Subtitles').glob('*.h')) + tests + [REPO / 'recovery/tests/MetadataAudit.h', Path(__file__).resolve()]
    report = {'source_sha256': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest() for path in inputs},
              'offline_runtime_tests': 'passed', 'exact_method_sets_and_ivar_layouts': 'passed',
              'ios_arm64_compile_and_archive': 'passed', 'real_network_and_device_tests': 'not performed',
              'packaged_svc_instrumentation': 'not integrated'}
    (root / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print('Subtitle and translation source passed offline runtime/ABI tests and iOS arm64 compilation.')


if __name__ == '__main__':
    main()
