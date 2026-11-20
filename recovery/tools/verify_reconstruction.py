#!/usr/bin/env python3
"""Compile restored Objective-C, execute isolated tests, and compare method ABIs.

This does not install or load the original tweak. All outputs and tool caches
are directed to .recovery-work within this repository.
"""
import json
import os
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]


def main():
    work = REPO / '.recovery-work/verification'
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for key, name in [('TMPDIR', 'tmp'), ('CLANG_MODULE_CACHE_PATH', 'module-cache'),
                      ('HOME', 'home'), ('CFFIXED_USER_HOME', 'home')]:
        directory = work / name
        directory.mkdir(exist_ok=True)
        env[key] = str(directory)

    def run(command):
        print('+ ' + ' '.join(map(str, command)), flush=True)
        subprocess.run(list(map(str, command)), cwd=REPO, env=env, check=True)

    sdk = subprocess.check_output(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'],
                                  text=True, env=env).strip()
    sources = [REPO / 'Recovered' / (name + '.m') for name in
               ['SBSegment', 'SBPlayerDecorationData', 'RPCMedia', 'DVNCell', 'DVNSection']]
    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-I', str(REPO / 'Recovered')]
    for arch in ['arm64', 'arm64e']:
        run(['xcrun', 'clang', *flags, '-target', f'{arch}-apple-ios14.0', '-isysroot', sdk,
             '-fsyntax-only', *sources])
    executable, metadata = work / 'test-models', work / 'models-runtime.json'
    run(['xcrun', 'clang', *flags, '-framework', 'Foundation', *sources,
         REPO / 'recovery/tests/test_models.m', REPO / 'recovery/tests/test_settings_models.m', '-o', executable])
    run([executable, metadata])
    expected = {c['name']: c for c in json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text())}
    count = 0
    for actual in json.loads(metadata.read_text()):
        def signatures(cls):
            return {(m['kind'], m['selector']): m['encoding'] for m in cls['methods']}
        original, restored = signatures(expected[actual['name']]), signatures(actual)
        if original != restored:
            raise AssertionError(f'{actual["name"]} method ABI mismatch: '
                                 f'missing={original.keys() - restored.keys()}, '
                                 f'extra={restored.keys() - original.keys()}, '
                                 f'types={[(k, original[k], restored[k]) for k in original.keys() & restored.keys() if original[k] != restored[k]]}')
        count += len(restored)
        print(f'{actual["name"]}: {len(restored)} method encodings match the binary exactly.')
    report = {'model_method_abi_count': count, 'model_runtime_tests': 'passed',
              'ios_syntax_architectures': ['arm64', 'arm64e'], 'original_binary_executed': False}
    (work / 'results.json').write_text(json.dumps(report, indent=2) + '\n')
    print(f'Verified {count} recovered model method encodings and runtime behavior.')


if __name__ == '__main__':
    main()
