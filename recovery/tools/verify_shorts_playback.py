#!/usr/bin/env python3
"""Check packaged registrations/bytes, emitted ARM64 ABI and actual Logos behavior."""
from logos_tool import logos_path
import hashlib
import json
import re
import subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO


def main():
    work = REPO / '.recovery-work/shorts-playback-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/ShortsPlayback.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    classes = {'YTReelPlayerViewController', 'YTReelPlayerViewControllerSub', 'YTShortsPlayerViewController'}
    hooks = [h for h in json.loads((REPO / 'recovery/evidence/hooks.json').read_text()) if h['class_name'] in classes]
    im = EvidenceImage()
    assert manifest['binary_sha256'] == im.sha256
    assert len(hooks) == len(manifest['registrations']) == 12
    for hook, entry in zip(hooks, manifest['registrations']):
        assert all(entry[key] == value for key, value in hook.items())
        start, end = int(entry['implementation'], 16), int(entry['instruction_end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == entry['instruction_sha256']
    for proof in manifest['instruction_proofs']:
        start, end = int(proof['start'], 16), int(proof['end'], 16)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == proof['sha256']
    for wrapper in manifest['gate_wrappers']:
        assert im.terminal(int(wrapper['address'], 16)) == wrapper['terminal']
    for constant in manifest['decoded_constants']:
        assert im.cstring(int(constant['address'], 16)) == constant['value']
    wanted = {(h['class_name'], h['selector'], h['operation']) for h in hooks}
    found = set()
    for cls, body in re.findall(r'%hook (\w+)\n(.*?)%end', source.read_text(), re.S):
        for added, declaration in re.findall(r'(?:(%new)\s*)?- \([^)]*\)([^\n{]+)\s*\{', body):
            parts = re.findall(r'(\w+)\s*:', declaration)
            selector = ''.join(p + ':' for p in parts) if parts else declaration.strip()
            found.add((cls, selector, 'add' if added else 'replace'))
    assert wanted == found, (wanted - found, found - wanted)
    assert '%ctor' not in source.read_text()
    commands = []

    def run(args, output=None):
        args = list(map(str, args))
        result = subprocess.run(args, cwd=REPO, capture_output=True, text=True, timeout=120)
        if output:
            output.write_text(result.stdout)
        text = result.stderr if output else result.stdout + result.stderr
        commands.append(dict(command=args, returncode=result.returncode, output=text))
        (work / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        print(text, end='')
        result.check_returncode()
        return result.stdout

    generated = work / 'ShortsPlayback.mm'
    run(['perl', logos_path(), '-c', 'generator=internal', source], generated)
    llvm = work / 'ShortsPlayback.ll'
    common = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-I', source.parent]
    run(['xcrun', '--sdk', 'iphoneos', 'clang++', *common, '-S', '-emit-llvm', '-target', 'arm64-apple-ios14.0', generated, '-o', llvm])
    signatures = [s for s in llvm.read_text().splitlines() if s.startswith('define ') and '_logos_method$' in s]
    assert len(signatures) == 12
    for hook in hooks:
        name = '_logos_method$YTLShortsPlayback$' + hook['class_name'] + '$' + hook['selector'].replace(':', '$') + 'P'
        matches = [s for s in signatures if name in s]
        assert len(matches) == 1, (name, matches)
        sig = matches[0]
        boolean = hook['selector'].startswith('should')
        assert sig.startswith('define internal zeroext i1 ' if boolean else 'define internal void ')
        arguments = sig.split('"(', 1)[1].split(') #', 1)[0]
        expected = 'ptr noundef %0, ptr noundef %1'
        for index in range(hook['selector'].count(':')):
            expected += ', i64 noundef %' + str(index + 2)
        assert arguments == expected, (hook['selector'], arguments)
    fixture = REPO / 'recovery/tests/shorts_playback_fixture.mm'
    shim = REPO / 'recovery/tests/shorts_playback_shims'
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang++', *common, '-fsanitize=undefined', '-fno-sanitize-recover=all', '-I', shim, generated, fixture, '-framework', 'Foundation', '-framework', 'CoreGraphics', '-o', executable])
    result = run([executable])
    checks = int(re.search(r'(\d+) actual-hook runtime assertions passed', result)[1])
    files = [source, source.with_name('ShortsPlaybackHost.h'), source.with_suffix('.manifest.json'), fixture, shim / 'UIKit/UIKit.h', Path(__file__).resolve()]
    report.write_text(json.dumps(dict(registrations=12, replacements=11, added=1, runtime_assertions=checks, original_bytes='verified', ios_callback_signatures=signatures, runtime_tests='passed under UBSan', original_binary_executed=False, network_requests=0, limitations=manifest['limitations'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}), indent=2) + '\n')
    print('ShortsPlayback: all 12 registrations, original-byte evidence and iOS callback ABI verified.')


if __name__ == '__main__':
    main()
