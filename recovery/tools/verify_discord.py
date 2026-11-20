#!/usr/bin/env python3
"""Compile and exercise the actual Discord source with all NSURLSession calls intercepted."""
import hashlib
import json
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]

def main():
    work = REPO / '.recovery-work/discord-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Discord/YTPDiscordRPC.m'
    test = REPO / 'recovery/tests/discord.m'
    redirects = REPO / 'recovery/tests/discord_redirects.h'
    commands = []
    def run(command):
        result = subprocess.run(list(map(str, command)), cwd=REPO, text=True, capture_output=True, timeout=120)
        commands.append({'command': list(map(str, command)), 'exit_code': result.returncode, 'output': result.stdout+result.stderr})
        (work / 'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        print(result.stdout+result.stderr, end='', flush=True)
        result.check_returncode()
    run(['python3', 'recovery/tools/verify_module_manifest.py', 'recovery/source/Discord/manifest.json'])
    run(['python3', 'recovery/tools/verify_ios_sources.py', '--source', source, '--classes', 'YTPDiscordRPC', '--label', 'discord'])
    from evidence_image import EvidenceImage
    manifest = json.loads((REPO/'recovery/source/Discord/manifest.json').read_text())
    image = EvidenceImage()
    for address, value in manifest['verified_strings'].items():
        assert image.cfstring(int(address, 16)) == value, address
    executable = work / 'discord-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', '-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter',
         '-fsanitize=undefined', '-fno-sanitize-recover=all', '-I', REPO/'recovery/tests/discord_shims', '-include', redirects,
         source, REPO/'recovery/source/Models/RPCMedia.m', test, '-framework', 'Foundation', '-o', executable])
    run([executable])
    inputs = [source, test, redirects, Path(__file__).resolve(), REPO/'recovery/source/Models/RPCMedia.m'] + list((REPO/'recovery/source/Discord').glob('*.h')) + list((REPO/'recovery/tests/discord_shims').rglob('*.h'))
    report.write_text(json.dumps({'offline_runtime_tests':'passed', 'ios_method_property_ivar_audit':'passed',
        'undefined_behavior_sanitizer':'passed', 'actual_youtube_and_device_ui':'not tested',
        'real_network_requests':0, 'original_binary_executed':False,
        'source_sha256':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}}, indent=2)+'\n')

if __name__ == '__main__': main()
