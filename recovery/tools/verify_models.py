#!/usr/bin/env python3
"""Compile the actual reconstructed models, check their ABI, and run host tests.

All generated files and compiler scratch/cache directories stay in /YTLite.
The macOS executable uses Foundation host doubles; it is not a YouTube test.
The iOS compilation produces a static library, not an installable tweak.
"""
import hashlib
import json
import os
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]
SOURCES = [REPO / 'recovery/source/Models' / (name + '.m') for name in
           ('SBSegment', 'SBPlayerDecorationData', 'DVNCell', 'RPCMedia', 'DVNSection', 'DVNTableModel')]
SOURCES += [REPO / 'recovery/source/Support/YTPDB.m']
SOURCES += [REPO / 'Utils/YTLUserDefaults.m', REPO / 'recovery/source/YTLUserDefaults+RecoveredDefaults.m']


def main():
    work = REPO / '.recovery-work/source-tests'
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for name, relative in (('TMPDIR', 'tmp'), ('CLANG_MODULE_CACHE_PATH', 'module-cache'),
                           ('HOME', 'home'), ('CFFIXED_USER_HOME', 'home')):
        directory = work / relative
        directory.mkdir(exist_ok=True)
        env[name] = str(directory)
    runs = []
    def public_id(text):
        value = text.encode('utf-8')
        for _ in range(5000):
            value = hashlib.sha256(value).digest()
        return value.hex()
    random_bytes = [(index * 17) % 256 for index in range(36)]
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'
    private = ''.join(alphabet[value % 62] for value in random_bytes)
    vectors = {'random_bytes': random_bytes, 'private_id': private, 'private_public_id': public_id(private),
               'hash_vectors': [{'input': text, 'public_id': public_id(text)}
                                for text in ('', 'a', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789', 'Unicode 🔥')]}
    (work / 'preference-vectors.json').write_text(json.dumps(vectors, ensure_ascii=False, indent=2) + '\n')

    def run(command):
        result = subprocess.run([str(item) for item in command], cwd=REPO, env=env,
                                text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        runs.append({'command': [str(item) for item in command],
                     'exit_code': result.returncode, 'output': result.stdout})
        print(result.stdout, end='', flush=True)
        (work / 'models-test-log.json').write_text(json.dumps(runs, indent=2) + '\n')
        result.check_returncode()
        return result.stdout.strip()

    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter']
    executable = work / 'models-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-framework', 'Foundation', '-framework', 'Security',
         '-DSecRandomCopyBytes=YTLTestSecRandomCopyBytes',
         '-I', REPO / 'recovery/tests/shims',
         *SOURCES, REPO / 'recovery/tests/UIKitDoubles.m', REPO / 'recovery/tests/tables.m',
         REPO / 'recovery/tests/models.m', REPO / 'recovery/tests/preferences.m', '-o', executable])
    run([executable, REPO / 'recovery/evidence/arm-classes.json', work])
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    objects = []
    for source in SOURCES:
        obj = work / (source.stem + '.ios.o')
        run(['xcrun', '--sdk', 'iphoneos', 'clang', *flags, '-target', 'arm64-apple-ios13.0',
             '-isysroot', sdk, '-c', source, '-o', obj])
        objects.append(obj)
    library = work / 'libYTLiteRecoveredModels.a'
    run(['xcrun', 'libtool', '-static', '-o', library, *objects])
    report = {'models': [source.stem for source in SOURCES],
              'source_sha256': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest()
                                for path in SOURCES + [REPO / 'recovery/tests/models.m']},
              'host_runtime_test': 'passed', 'exact_metadata_check': 'passed',
              'ios_arm64_compile_and_archive': 'passed', 'youtube_device_test': 'not performed'}
    (work / 'models-test-report.json').write_text(json.dumps(report, indent=2) + '\n')
    print('Reconstructed models passed Foundation tests and iOS arm64 compilation/archive.')


if __name__ == '__main__':
    main()
