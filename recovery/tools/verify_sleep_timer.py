#!/usr/bin/env python3
"""Audit all timer methods and run its source with deterministic host scheduling."""
import hashlib
import json
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]
def main():
    work = REPO / '.recovery-work/sleep-timer-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/SleepTimer/YTPSleepTimer.m'
    test = REPO / 'recovery/tests/sleep_timer.m'
    redirects = REPO / 'recovery/tests/sleep_redirects.h'
    commands = []
    def run(command):
        result = subprocess.run(list(map(str, command)), cwd=REPO, text=True, capture_output=True, timeout=120)
        commands.append({'command': list(map(str, command)), 'exit_code': result.returncode, 'output': result.stdout+result.stderr})
        (work / 'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        print(result.stdout+result.stderr, end='', flush=True)
        result.check_returncode()
    run(['python3', 'recovery/tools/verify_module_manifest.py', 'recovery/source/SleepTimer/manifest.json'])
    run(['python3', 'recovery/tools/verify_ios_sources.py', '--source', source, '--classes', 'YTPSleepTimer', '--label', 'sleep-timer'])
    executable = work / 'sleep-timer-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', '-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter',
         '-fsanitize=undefined', '-fno-sanitize-recover=all', '-I', REPO/'recovery/tests/sleep_shims', '-include', redirects,
         source, test, '-framework', 'Foundation', '-framework', 'CoreGraphics', '-o', executable])
    run([executable])
    inputs = [source, test, redirects, Path(__file__).resolve(), REPO/'recovery/source/Controls/ControlsNumbers.h'] + list((REPO/'recovery/source/SleepTimer').glob('*.h')) + list((REPO/'recovery/tests/sleep_shims').rglob('*.h'))
    report.write_text(json.dumps({'runtime_scheduler_and_host_tests': 'passed', 'ios_method_property_ivar_audit': 'passed',
        'undefined_behavior_sanitizer': 'passed', 'actual_youtube_and_device_ui': 'not tested', 'original_binary_executed': False,
        'source_sha256': {str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}}, indent=2)+'\n')
if __name__ == '__main__': main()
