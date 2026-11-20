#!/usr/bin/env python3
"""Run the actual local-fork Theos build with repository-scoped outputs/logs."""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

from verify_build_inputs import build_inputs

ROOT = Path(__file__).resolve().parents[1]


def input_hashes():
    files = {ROOT/'Makefile', ROOT/'control', ROOT/'recovery/source/recovered.mk',
             ROOT/'recovery/dependencies/ffmpeg/link.mk', ROOT/'tools/package_deb.py',
             ROOT/'vendor/theos/bin/dm.pl', Path(__file__).resolve()}
    for root in (ROOT, ROOT/'Utils'):
        files.update(p for p in root.iterdir() if p.is_file() and p.suffix in ('.x', '.m', '.h', '.plist'))
    files.update(ROOT/p for p in build_inputs()['inputs'])
    files.add(ROOT/'tools/verify_build_inputs.py')
    files.update((ROOT/'recovery/dependencies/ffmpeg/ios-arm64').glob('*.a'))
    files.update(p for p in (ROOT/'layout').rglob('*') if p.is_file())
    files.update(p for p in (ROOT/'recovery/build').rglob('*') if p.is_file() and p.suffix in ('.mk', '.tbd', '.h', '.modulemap'))
    return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest()
            for p in sorted(files)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('target', choices=('all', 'package'), nargs='?', default='all')
    parser.add_argument('--scheme', choices=('default', 'roothide'), default='default')
    args = parser.parse_args()
    work = ROOT / ('.recovery-work/build-roothide' if args.scheme=='roothide' else '.recovery-work/build')
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    # Clang module caches embed absolute paths and cannot survive a checkout move.
    cache_folder = 'cache-' + hashlib.sha256(str(ROOT).encode()).hexdigest()[:16]
    for name, folder in [('CFFIXED_USER_HOME', 'home'),
                         ('TMPDIR', 'tmp'), ('CLANG_MODULE_CACHE_PATH', cache_folder),
                         ('XDG_CONFIG_HOME', 'home')]:
        path = work / folder
        path.mkdir(exist_ok=True)
        env[name] = str(path)
    env['THEOS'] = str(ROOT / 'vendor/theos')
    env['PYTHONDONTWRITEBYTECODE'] = '1'
    log_path = work / 'latest-build.log'
    report_path = work / 'latest-build.json'
    command = ['make', '-j2', 'COLOR=0', args.target]
    # GNU Make 4.4 defaults to named FIFOs, unsupported on some external volumes.
    make_version = subprocess.check_output(['make', '--version'], text=True).splitlines()[0]
    if make_version.startswith('GNU Make '):
        version = tuple(int(part) for part in make_version.split()[2].split('.')[:2])
        if version >= (4, 4):
            command.insert(1, '--jobserver-style=pipe')
    data_dir = ROOT / '.theos'
    if args.scheme=='roothide':
        command += ['ROOTHIDE=1', 'ROOTLESS=0']
        data_dir = data_dir/'roothide'
    report = {'started': datetime.datetime.now(datetime.timezone.utc).isoformat(),
              'command': command, 'cwd': str(ROOT), 'status': 'running', 'scheme':args.scheme,
              'original_binary_executed': False, 'device_validation': 'not performed'}
    report['input_sha256'] = input_hashes()
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    try:
        with log_path.open('w') as log:
            result = subprocess.run(command, cwd=ROOT, env=env, stdout=log, stderr=subprocess.STDOUT)
        report['exit_code'] = result.returncode
        report['status'] = 'passed' if result.returncode == 0 else 'failed'
        after = input_hashes()
        if after != report['input_sha256']:
            report.update(status='failed', exit_code=1, error='Source inputs changed during the build; rerun after edits finish.')
        if report['status'] == 'passed':
            artifact = data_dir/'obj/arm64/YTLite.dylib'
            report['artifact'] = str(artifact.relative_to(ROOT))
            report['artifact_sha256'] = hashlib.sha256(artifact.read_bytes()).hexdigest()
            if args.target=='package':
                package = ROOT/(data_dir/'last_package').read_text().strip()
                report['package'] = str(package.relative_to(ROOT))
                report['package_sha256'] = hashlib.sha256(package.read_bytes()).hexdigest()
    except Exception as error:
        report.update(status='failed', error=str(error), exit_code=1)
    finally:
        report_path.write_text(json.dumps(report, indent=2) + '\n')
    print('\n'.join(log_path.read_text(errors='replace').splitlines()[-100:]))
    print('Build report:', report_path.relative_to(ROOT))
    return report['exit_code']


if __name__ == '__main__':
    sys.exit(main())
