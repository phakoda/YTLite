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
    work = REPO / '.recovery-work/shorts-interface-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/ShortsInterface.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    classes = set('YTReelWatchHeaderView YTReelWatchPlaybackOverlayView YTReelWatchPlaybackOverlayViewSub YTReelContentView YTReelHeaderView YTInlineMutedPlaybackShortsPlayerOverlayView YTReelInfinitePlaybackDataSource YTReelContentModel YTReelDataSource YTShortsStartupCoordinator YTReelWatchRootViewController'.split())
    hooks = [h for h in json.loads((REPO / 'recovery/evidence/hooks.json').read_text()) if h['class_name'] in classes]
    im = EvidenceImage()
    assert manifest['binary_sha256'] == im.sha256
    assert len(hooks) == len(manifest['registrations']) == 27
    for hook, entry in zip(hooks, manifest['registrations']):
        assert all(entry[key] == value for key, value in hook.items())
        start, end = int(entry['implementation'], 16), int(entry['instruction_end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == entry['instruction_sha256']
    for proof in manifest['additional_functions']:
        start, end = int(proof['start'], 16), int(proof['end'], 16)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == proof['sha256']
    for wrapper in manifest['gate_wrappers']:
        assert im.terminal(int(wrapper['address'], 16)) == wrapper['terminal']
    for constant in manifest['decoded_constants']:
        assert im.cstring(int(constant['address'], 16)) == constant['value']
    for table in manifest['manual_branch_tables']:
        delta = -(im.image.u32(im.image.off(int(table['offset'], 16))) ^ int(table['xor_key'], 16))
        delta = (delta + (1 << 31)) % (1 << 32) - (1 << 31)
        assert [hex(im.image.ptr(int(table['table'], 16) + i * 8) + delta) for i in range(2)] == table['targets']
    for block in manifest['blocks']:
        assert im.image.ptr(int(block['literal'], 16) + 16) == int(block['invoke'], 16)
    import struct
    for constant in manifest['double_constants']:
        assert struct.unpack_from('<d', im.image.data, im.image.off(int(constant['address'], 16)))[0] == constant['value']
    branches = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for branch in manifest['branch_evidence']:
        assert branches[branch['address']] == branch
        assert im.image.u32(im.image.off(int(branch['address'], 16))) == int(branch['original'][0], 16)
    wanted = {(h['class_name'], h['selector'], h['operation'], h['kind']) for h in hooks}
    found = set()
    for cls, body in re.findall(r'%hook (\w+)\n(.*?)%end', source.read_text(), re.S):
        for added, kind, declaration in re.findall(r'(?:(%new)\s*)?([+-]) \([^)]*\)([^\n{]+)\s*\{', body):
            parts = re.findall(r'(\w+)\s*:', declaration)
            selector = ''.join(p + ':' for p in parts) if parts else declaration.strip()
            found.add((cls, selector, 'add' if added else 'replace', kind))
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

    generated = work / 'ShortsInterface.mm'
    run(['perl', logos_path(), '-c', 'generator=internal', source], generated)
    llvm = work / 'ShortsInterface.ll'
    common = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-I', source.parent]
    run(['xcrun', '--sdk', 'iphoneos', 'clang++', *common, '-S', '-emit-llvm', '-target', 'arm64-apple-ios14.0', generated, '-o', llvm])
    signatures = [s for s in llvm.read_text().splitlines() if s.startswith('define ') and ('_logos_method$' in s or '_logos_meta_method$' in s) and '_block_invoke' not in s]
    assert len(signatures) == 27
    for hook in hooks:
        name = ('_logos_meta_method$YTLShortsInterface$' if hook['kind'] == '+' else '_logos_method$YTLShortsInterface$') + hook['class_name'] + '$' + hook['selector'].replace(':', '$') + 'P'
        matches = [s for s in signatures if name in s]
        assert len(matches) == 1, (name, matches)
        sig = matches[0]
        sel = hook['selector']
        assert sig.startswith('define internal ptr ' if sel in ('makeContentModelForEntry:', 'reels', 'evaluateResumeToShorts') else 'define internal void '), sig
        arguments = sig.split('"(', 1)[1].split(') #', 1)[0]
        types = ['ptr', 'ptr']
        if sel in ('makeContentModelForEntry:', 'setPlaybackView:', 'setActionBarElementRenderer:'):
            types += ['i64']
        elif sel == 'addView:toStackView:withSize:':
            types += ['ptr', 'ptr', '[2 x double]']
        elif sel == 'setTitleLabelVisible:animated:':
            types += ['i1', 'i1']
        elif sel == 'viewDidAppear:':
            types += ['i1']
        else:
            types += ['ptr'] * sel.count(':')
        actual = re.findall(r'(\[2 x double\]|ptr|i64|i1) (?:noundef )?(?:zeroext )?%\d+', arguments)
        assert actual == types, (sel, arguments, types)
    callbacks = [line for line in llvm.read_text().splitlines() if line.startswith('define ') and '_block_invoke' in line]
    assert len(callbacks) == 2
    predicate = next(line for line in callbacks if '$reels' in line)
    assert predicate.startswith('define internal zeroext i1 ') and '(ptr noundef %0, ptr noundef %1, i64 noundef %2, ptr noundef %3)' in predicate
    notification = next(line for line in callbacks if '$turnShortsOnlyModeOff$' in line)
    assert notification.startswith('define internal void ') and '(ptr noundef %0)' in notification
    fixture = REPO / 'recovery/tests/shorts_interface_fixture.mm'
    shim = REPO / 'recovery/tests/shorts_interface_shims'
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang++', *common, '-Wno-objc-property-no-attribute', '-fsanitize=undefined', '-fno-sanitize-recover=all', '-I', shim, '-include', REPO / 'recovery/tests/shorts_interface_redirects.h', generated, fixture, '-framework', 'Foundation', '-framework', 'CoreGraphics', '-framework', 'QuartzCore', '-o', executable])
    result = run([executable])
    checks = int(re.search(r'(\d+) actual-hook assertions passed', result)[1])
    files = [source, source.with_name('ShortsInterfaceHost.h'), source.with_suffix('.manifest.json'), fixture, shim / 'UIKit/UIKit.h', Path(__file__).resolve(), REPO / 'recovery/tests/shorts_interface_redirects.h']
    report.write_text(json.dumps(dict(registrations=27, replacements=22, added=5, runtime_assertions=checks, original_bytes='verified', ios_callback_signatures=signatures, ios_block_signatures=callbacks, runtime_tests='passed under UBSan', original_binary_executed=False, network_requests=0, limitations=manifest['limitations'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}), indent=2) + '\n')
    print('ShortsInterface: all 27 registrations, original-byte evidence and iOS callback ABI verified.')


if __name__ == '__main__':
    main()
