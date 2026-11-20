#!/usr/bin/env python3
"""Verify supplemental SideloadIdentity registrations, original bytes and actual Logos bodies."""
from logos_tool import logos_path
import hashlib
import json
import re
import subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO
from verify_sideload_supplemental_registrations import recover_registrations


def main():
    work = REPO / '.recovery-work/sideload-identity-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/SideloadIdentity.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    im = EvidenceImage()
    assert manifest['binary_sha256'] == im.sha256
    all_direct = recover_registrations(im)
    other = {0x17988, 0x17990, 0x18924, 0x18b78, 0x18c88}
    hooks = [h for h in all_direct if int(h['implementation'], 16) not in other]
    assert len(hooks) == len(manifest['registrations']) == 18
    for hook, entry in zip(hooks, manifest['registrations']):
        assert all(entry[k] == v for k, v in hook.items())
        assert entry['complete'] and entry['group'] == 'YTLSideloadIdentity'
    ranges = []
    for entry in manifest['registrations'] + manifest['helpers']:
        start = int(entry.get('implementation', entry.get('address')), 16)
        end = int(entry['instruction_end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        raw = im.image.data[im.image.off(start):im.image.off(end)]
        assert hashlib.sha256(raw).hexdigest() == entry['instruction_sha256']
        ranges.append((start, end))
    rows = []
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s+(.*?)(?:\s*;.*)?$', line)
        if match and any(a <= int(match[1], 16) < b for a, b in ranges):
            address, word = int(match[1], 16), int(match[2], 16)
            assert im.image.u32(im.image.off(address)) == word
            rows.append((address, word, match[3].strip()))
    assert len(rows) == sum((b - a) // 4 for a, b in ranges)
    branches = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for branch in manifest['branch_evidence']:
        assert branches[branch['address']] == branch
        assert im.image.u32(im.image.off(int(branch['address'], 16))) == int(branch['original'][0], 16)
    for table in manifest['manual_branch_tables']:
        offset = im.image.u32(im.image.off(int(table['offset'], 16)))
        delta = -(offset ^ int(table['xor'], 16))
        delta = (delta + (1 << 31)) % (1 << 32) - (1 << 31)
        assert [hex(im.image.ptr(int(table['table'], 16) + i * 8) + delta) for i in range(2)] == table['targets_false_true']
    covered = {int(b['address'], 16) for b in manifest['branch_evidence'] + manifest['manual_branch_tables']}
    assert {a for a, _, t in rows if t.startswith('br\t')} == covered
    for wrapper in manifest['gate_wrappers']:
        assert im.terminal(int(wrapper['address'], 16)) == wrapper['terminal']
    for constant in manifest['decoded_cfstrings']:
        assert im.cfstring(int(constant['address'], 16)) == constant['value']
    for constant in manifest['decoded_cstrings']:
        assert im.cstring(int(constant['address'], 16)) == constant['value']
    for tail in manifest['keychain_tail_chains']:
        current = int(tail['implementation'], 16)
        for step in tail['chain']:
            address = int(step['address'], 16)
            assert address in (current, current + 4)
            if address != current:
                assert im.image.u32(im.image.off(current)) == 0xa9bf7bfd
                assert im.image.u32(im.image.off(current + 8)) == 0xa8c17bfd
                assert im.image.u32(im.image.off(current + 12)) == 0xd65f03c0
            word = im.image.u32(im.image.off(address))
            assert word == int(step['instruction'], 16)
            assert word & 0x7c000000 == 0x14000000
            delta = word & 0x3ffffff
            if delta & (1 << 25): delta -= 1 << 26
            current = address + delta * 4
            assert current == int(step['target'], 16)
        assert current == int(tail['terminal'], 16) == 0x1bdc0
    assert len(manifest['keychain_tail_chains']) == 6
    for call in manifest['omitted_supervisor_calls']:
        word = im.image.u32(im.image.off(int(call['address'], 16)))
        assert word == int(call['instruction'], 16)
        assert word & 0xffe0001f == 0xd4000001
    # Initial state must use raw image, never the decoded runtime-store overlay.
    assert im.image.data[im.image.off(0x1153530)] == 1
    assert any(s['zerofill'] and s['address'] <= 0x1225b28 < s['address'] + s['size'] for s in im.image.section_records)
    assert manifest['added_properties'] == []
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
        if output: output.write_text(result.stdout)
        text = result.stderr if output else result.stdout + result.stderr
        commands.append(dict(command=args, returncode=result.returncode, output=text))
        (work / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        print(text, end='')
        result.check_returncode()
        return result.stdout

    generated = work / 'SideloadIdentity.mm'
    run(['perl', logos_path(), '-c', 'generator=internal', source], generated)
    llvm = work / 'SideloadIdentity.ll'
    common = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-I', source.parent]
    run(['xcrun', '--sdk', 'iphoneos', 'clang++', *common, '-S', '-emit-llvm', '-target', 'arm64-apple-ios14.0', generated, '-o', llvm])
    signatures = [s for s in llvm.read_text().splitlines() if s.startswith('define ') and ('_logos_method$' in s or '_logos_meta_method$' in s) and '_block_invoke' not in s]
    assert len(signatures) == 18
    for hook in hooks:
        prefix = '_logos_meta_method$' if hook['kind'] == '+' else '_logos_method$'
        name = prefix + 'YTLSideloadIdentity$' + hook['class_name'] + '$' + hook['selector'].replace(':', '$') + 'P'
        matches = [s for s in signatures if name in s]
        assert len(matches) == 1, (name, matches)
        sig = matches[0]
        lifecycle = hook['selector'] in ('viewDidAppear:', 'viewDidDisappear:')
        assert sig.startswith('define internal ' + ('void' if lifecycle else 'ptr') + ' '), sig
        arguments = sig.split('"(', 1)[1].split(') #', 1)[0]
        expected = ['ptr', 'ptr'] + (['i1'] if lifecycle else ['ptr'] * hook['selector'].count(':'))
        actual = re.findall(r'(ptr|i64|i32|i1) (?:noundef )?(?:zeroext )?%\d+', arguments)
        assert actual == expected, (hook['selector'], arguments, expected)
    fixture = REPO / 'recovery/tests/sideload_identity_fixture.mm'
    redirects = REPO / 'recovery/tests/sideload_identity_redirects.h'
    shims = REPO / 'recovery/tests/sideload_identity_shims'
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang++', '-std=c++17', *common, '-I', shims, '-include', redirects, '-fsanitize=undefined', '-fno-sanitize-recover=all', generated, fixture, '-framework', 'Foundation', '-framework', 'Security', '-o', executable])
    result = run([executable])
    checks = int(re.search(r'(\d+) actual-hook assertions passed', result)[1])
    files = [source, source.with_name('SideloadIdentityHost.h'), source.with_suffix('.manifest.json'), fixture, redirects, shims / 'UIKit/UIKit.h', Path(__file__).resolve()]
    report.write_text(json.dumps(dict(registrations=18, replacements=18, added=0, class_methods=sum(h['kind'] == '+' for h in hooks), added_properties=[], runtime_assertions=checks, original_instruction_words=len(rows), original_function_hashes=len(ranges), original_bytes='verified', ios_callback_signatures=signatures, runtime_tests='passed under UBSan with actual Logos bodies and intercepted Security/loader calls', original_binary_executed=False, network_requests=0, actual_keychain_queries=0, omitted_supervisor_calls=manifest['omitted_supervisor_calls'], limitations=manifest['limitations'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}), indent=2) + '\n')
    print(f'SideloadIdentity: all 18 registrations, {len(rows)} original words and iOS callback ABI verified.')


if __name__ == '__main__':
    main()
