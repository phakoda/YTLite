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
    work = REPO / '.recovery-work/navigation-chrome-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/NavigationChrome.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    classes = set('YTPivotBarItemView YTPivotBarViewController YTPivotBarView YTIPivotBarRenderer YTHeaderView YTHeaderContentComboView YTAppViewController YTMySubsFilterHeaderView YTChipCloudCell YTPlaylistMiniBarView YTWatchMiniBarViewController'.split())
    hooks = [h for h in json.loads((REPO / 'recovery/evidence/hooks.json').read_text()) if h['class_name'] in classes]
    im = EvidenceImage()
    assert manifest['binary_sha256'] == im.sha256
    assert len(hooks) == len(manifest['registrations']) == 17
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
    branches = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for branch in manifest['branch_evidence']:
        assert branches[branch['address']] == branch
        assert im.image.u32(im.image.off(int(branch['address'], 16))) == int(branch['original'][0], 16)
    initializer = manifest['manual_registration']['initializer']
    assert im.image.u32(im.image.off(int(initializer['entry'], 16))) == int(initializer['value'], 16)
    assert im.image.u32(im.image.off(0xb98044)) == 0x4cf00
    assert manifest['added_properties'] == []
    assert im.image.u32(im.image.off(0xc4c230)) == 0xc0000000
    for block in manifest['stack_blocks']:
        assert im.cstring(im.image.ptr(int(block['descriptor'], 16) + 16)) == block['signature']
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

    generated = work / 'NavigationChrome.mm'
    run(['perl', logos_path(), '-c', 'generator=internal', source], generated)
    llvm = work / 'NavigationChrome.ll'
    common = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-I', source.parent]
    run(['xcrun', '--sdk', 'iphoneos', 'clang++', *common, '-S', '-emit-llvm', '-target', 'arm64-apple-ios14.0', generated, '-o', llvm])
    signatures = [s for s in llvm.read_text().splitlines() if s.startswith('define ') and ('_logos_method$' in s or '_logos_meta_method$' in s) and '_block_invoke' not in s]
    assert len(signatures) == 17
    for hook in hooks:
        group = 'YTLNavigationChromeEarly' if hook['registration'] == '0004cf00' else 'YTLNavigationChrome'
        name = '_logos_method$' + group + '$' + hook['class_name'] + '$' + hook['selector'].replace(':', '$') + 'P'
        matches = [s for s in signatures if name in s]
        assert len(matches) == 1, (name, matches)
        sig = matches[0]
        sel = hook['selector']
        result_type = ('zeroext i1' if sel in ('stickyNavHeaderEnabled', 'clipsToStatusArea', 'isFrostedPivotBarPermitted') else 'i32' if sel == 'backgroundStyle' else 'ptr' if sel in ('framesForChipViewsWithWidth:', 'itemView1', 'contextMenuInteraction:configurationForMenuAtLocation:', 'navigationButton') else 'void')
        assert sig.startswith('define internal ' + result_type + ' '), sig
        arguments = sig.split('"(', 1)[1].split(') #', 1)[0]
        additions = {'framesForChipViewsWithWidth:': ['double'], 'setFeedHeaderScrollMode:': ['i32'], 'viewDidAppear:': ['i1'], 'contextMenuInteraction:configurationForMenuAtLocation:': ['ptr', '[2 x double]'], 'setFrame:': ['[4 x double]'], 'setRenderer:': ['i64']}
        expected = ['ptr', 'ptr'] + additions.get(sel, ['ptr'] * sel.count(':'))
        actual = re.findall(r'(\[[24] x double\]|ptr|double|i64|i32|i1) (?:noundef )?(?:zeroext )?%\d+', arguments)
        assert actual == expected, (sel, arguments, expected)
    callbacks = [line for line in llvm.read_text().splitlines() if line.startswith('define ') and '_block_invoke' in line]
    assert len(callbacks) == 5
    assert sum(line.startswith('define internal ptr ') for line in callbacks) == 1
    assert sum(line.startswith('define internal void ') for line in callbacks) == 4
    for line in callbacks:
        assert '(ptr noundef %0, ptr noundef %1)' in line
    assert llvm.read_text().count('store i32 -1073741824,') == 2  # Both self captures lack copy/dispose retain operations.
    manual = next(line for line in llvm.read_text().splitlines() if line.startswith('define internal ptr @_ZL18NavigationRenderer'))
    assert '(ptr noundef %0, ptr noundef %1)' in manual
    fixture = REPO / 'recovery/tests/navigation_chrome_fixture.mm'
    shim = REPO / 'recovery/tests/navigation_chrome_shims'
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang++', *common, '-Wno-objc-property-no-attribute', '-fsanitize=undefined', '-fno-sanitize-recover=all', '-I', shim, '-include', REPO / 'recovery/tests/navigation_chrome_redirects.h', generated, fixture, '-framework', 'Foundation', '-framework', 'CoreGraphics', '-framework', 'QuartzCore', '-o', executable])
    result = run([executable])
    checks = int(re.search(r'(\d+) actual-hook assertions passed', result)[1])
    files = [source, source.with_name('NavigationChromeHost.h'), source.with_suffix('.manifest.json'), fixture, shim / 'UIKit/UIKit.h', Path(__file__).resolve(), REPO / 'recovery/tests/navigation_chrome_redirects.h']
    report.write_text(json.dumps(dict(registrations=17, replacements=16, added=1, manual_replacements=1, property_registration_changes=0, runtime_assertions=checks, original_bytes='verified', ios_callback_signatures=signatures, ios_block_signatures=callbacks, ios_manual_signature=manual, runtime_tests='passed under UBSan', original_binary_executed=False, network_requests=0, limitations=manifest['limitations'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}), indent=2) + '\n')
    print('NavigationChrome: all 17 registrations and manual replacement, original-byte evidence and iOS callback ABI verified.')


if __name__ == '__main__':
    main()
