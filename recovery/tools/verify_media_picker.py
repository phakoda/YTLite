#!/usr/bin/env python3
"""Verify recovered picker ABI and execute its real file operations in fixtures."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile

REPO = Path(__file__).resolve().parents[2]

def main():
    work = REPO / '.recovery-work/media-picker-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    sources = [REPO / 'recovery/source/Media/DVNMediaPicker.m', REPO / 'recovery/tests/media_picker.m']
    commands = []
    def run(command):
        result = subprocess.run(list(map(str, command)), cwd=REPO, text=True, capture_output=True, timeout=120)
        commands.append({'command': list(map(str, command)), 'exit_code': result.returncode, 'output': result.stdout + result.stderr})
        (work / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        print(result.stdout + result.stderr, end='', flush=True)
        result.check_returncode()
    run(['python3', 'recovery/tools/verify_module_manifest.py', 'recovery/source/Media/manifest.json'])
    run(['python3', 'recovery/tools/verify_ios_sources.py', '--source', sources[0], '--classes', 'DVNMediaPicker', '--label', 'media-picker'])
    executable = work / 'media-picker-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', '-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-fsanitize=undefined', '-fno-sanitize-recover=all',
         '-I', REPO / 'recovery/tests/media_shims', '-DNSTemporaryDirectory=YTLTestTemporaryDirectory',
         '-DNSSearchPathForDirectoriesInDomains=YTLTestSearchPath', '-framework', 'Foundation', '-framework', 'CoreMedia',
         '-framework', 'UniformTypeIdentifiers', *sources, '-o', executable])
    with tempfile.TemporaryDirectory(prefix='fixtures-', dir=work) as fixture:
        (Path(fixture) / 'tmp').mkdir()
        (Path(fixture) / 'Documents').mkdir()
        run([executable, fixture])
    inputs = sources + list((REPO / 'recovery/tests/media_shims').rglob('*.h')) + list((REPO / 'recovery/source/Media').glob('*.h')) + [Path(__file__).resolve()]
    report.write_text(json.dumps({'runtime_file_and_callback_tests': 'passed', 'ios_method_property_ivar_audit': 'passed',
        'device_photos_and_document_picker_ui': 'not tested', 'original_binary_executed': False,
        'source_sha256': {str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}}, indent=2) + '\n')

if __name__ == '__main__': main()
