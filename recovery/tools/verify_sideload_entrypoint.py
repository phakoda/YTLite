#!/usr/bin/env python3
"""Test actual identity predicate and installer ordering without installing hooks."""
import hashlib
import json
import subprocess
from pathlib import Path
from evidence_image import REPO


def main():
    work = REPO / '.recovery-work/sideload-entrypoint-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Runtime/YTLSideloadEntrypoint.m'
    fixture = REPO / 'recovery/tests/sideload_entrypoint_fixture.m'
    redirects = REPO / 'recovery/tests/sideload_entrypoint_redirects.h'
    commands = []
    def run(args):
        args = list(map(str, args))
        result = subprocess.run(args, cwd=REPO, text=True, capture_output=True, timeout=90)
        commands.append({'command':args, 'returncode':result.returncode, 'output':result.stdout+result.stderr})
        (work / 'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        print(result.stdout+result.stderr, end='', flush=True)
        result.check_returncode()
    run(['python3', 'recovery/tools/verify_sideload_supplemental_registrations.py'])
    opts = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror']
    run(['xcrun', '--sdk', 'iphoneos', 'clang', *opts, '-target', 'arm64-apple-ios14.0', '-c', source, '-o', work/'entrypoint.o'])
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *opts, '-fsanitize=undefined', '-fno-sanitize-recover=all', '-include', redirects, source, fixture, '-framework', 'Foundation', '-o', executable])
    run([executable])
    inputs = [source, source.with_suffix('.h'), fixture, redirects, Path(__file__).resolve()]
    report.write_text(json.dumps({'ios_compile':'passed', 'actual_source_runtime':'passed',
        'original_binary_executed':False, 'scope':'Original identity predicate and local installer order. Hook installation is intercepted; historical account queue and excluded security callbacks are not reproduced.',
        'inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}}, indent=2)+'\n')


if __name__ == '__main__':
    main()
