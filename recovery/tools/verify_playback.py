#!/usr/bin/env python3
"""Build and test recovered playback code, with source/ABI provenance.

Only reconstructed Objective-C is executed. The original packages remain data.
HTTP is replaced by a test fixture. Outputs, preferences, temporary subtitle
files, and compiler caches are confined to this repository.
"""
import hashlib
import json
import os
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]
SOURCES = [REPO / 'recovery/source/Playback' / (name + '.m')
           for name in ['SRTParser', 'SBManager', 'SBPlaybackController', 'SBPlayerDecorator']]
DEPENDENCIES = [REPO / 'recovery/source/Models/SBSegment.m',
                REPO / 'recovery/source/Models/SBPlayerDecorationData.m']


def main():
    work = REPO / '.recovery-work/playback-tests'
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for key, name in [('TMPDIR', 'tmp'), ('HOME', 'home'), ('CFFIXED_USER_HOME', 'home'),
                      ('CLANG_MODULE_CACHE_PATH', 'module-cache')]:
        directory = work / name
        directory.mkdir(exist_ok=True)
        env[key] = str(directory)
    runs = []

    def run(command):
        command = list(map(str, command))
        print('+ ' + ' '.join(command), flush=True)
        result = subprocess.run(command, cwd=REPO, env=env, text=True,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        runs.append({'command': command, 'exit_code': result.returncode, 'output': result.stdout})
        (work / 'commands.json').write_text(json.dumps(runs, indent=2) + '\n')
        print(result.stdout, end='', flush=True)
        result.check_returncode()
        return result.stdout.strip()

    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror']
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    for arch in ['arm64', 'arm64e']:
        objects = []
        for source in SOURCES + DEPENDENCIES:
            obj = work / (source.stem + '.' + arch + '.o')
            run(['xcrun', 'clang', *flags, '-target', arch + '-apple-ios14.0',
                 '-isysroot', sdk, '-c', source, '-o', obj])
            objects.append(obj)
        run(['xcrun', 'libtool', '-static', '-o', work / ('libRecoveredPlayback.' + arch + '.a'), *objects])
    executable, metadata_path = work / 'playback-runtime', work / 'runtime.json'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-framework', 'Foundation',
         '-framework', 'CoreGraphics', '-framework', 'QuartzCore',
         '-I', REPO / 'recovery/tests/playback-shims',
         '-Ddispatch_after=YTLPlaybackTestDispatchAfter',
         *SOURCES, *DEPENDENCIES, REPO / 'recovery/tests/playback_runtime.m',
         REPO / 'recovery/tests/sb_playback_runtime.m', REPO / 'recovery/tests/sb_drawing_runtime.m',
         REPO / 'recovery/tests/playback_ui_doubles.m', '-o', executable])
    run([executable, metadata_path])
    expected = {cls['name']: cls for cls in json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text())}
    expected_ivars = json.loads((REPO / 'recovery/evidence/ivars.json').read_text())
    result = json.loads(metadata_path.read_text())
    method_count, ivar_count = 0, 0
    for actual in result['classes']:
        name = actual['name']
        def signatures(cls):
            return {(method['kind'], method['selector']): method['encoding'] for method in cls['methods']}
        original, restored = signatures(expected[name]), signatures(actual)
        if original != restored:
            raise AssertionError(f'{name} method ABI mismatch: missing={original.keys() - restored.keys()}; '
                                 f'extra={restored.keys() - original.keys()}; '
                                 f'types={[(key, original[key], restored[key]) for key in original.keys() & restored.keys() if original[key] != restored[key]]}')
        original_ivars = {(item['name'], item['offset'], item['encoding']) for item in expected_ivars[name]['ivars']}
        actual_ivars = {(item['name'], item['offset'], item['encoding']) for item in actual['ivars']}
        if original_ivars != actual_ivars:
            raise AssertionError(f'{name} ivar mismatch: missing={original_ivars - actual_ivars}; extra={actual_ivars - original_ivars}')
        method_count += len(restored)
        ivar_count += len(actual_ivars)
        print(f'{name}: {len(restored)} method encodings and {len(actual_ivars)} ivar layouts match exactly.')
    report = {'methods': method_count, 'ivars': ivar_count, 'runtime_assertions': result['assertions'],
              'ios_architectures': ['arm64', 'arm64e'], 'host_tests': 'passed',
              'network_requests_issued': False, 'original_tweak_executed': False,
              'drawing_validation': 'geometry, real CALayer ownership, and UIKit message arguments; not on-device pixels',
              'sources': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest()
                          for path in SOURCES + DEPENDENCIES}}
    (work / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(f'Playback verified: {method_count} method ABIs, {ivar_count} ivars, isolated runtime behavior.')


if __name__ == '__main__':
    main()
