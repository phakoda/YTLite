#!/usr/bin/env python3
"""Verify original MediaPolicy bytes, emitted iOS ABI, and actual Logos runtime behavior."""
from logos_tool import logos_path
import hashlib
import json
import re
import subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO


def main():
    work = REPO / '.recovery-work/media-policy-tests'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/MediaPolicy.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    classes = set('YTIPlayabilityStatus MLVideo YTIBackgroundOfflineSettingCategoryEntryRenderer YTGlobalConfig YTIPlayerResponse YTIClientMdxGlobalConfig YTAdShieldUtils YTDataUtils YTAdsInnerTubeContextDecorator YTAccountScopedAdsInnerTubeContextDecorator YTLocalPlaybackController MDXSession YTIAuxiliaryUi YTITriggerConditions YTIVideoPlaybackRelativePosition YTICoWatchability'.split())
    hooks = [h for h in json.loads((REPO / 'recovery/evidence/hooks.json').read_text()) if h['class_name'] in classes]
    im = EvidenceImage()
    assert manifest['binary_sha256'] == im.sha256
    assert len(hooks) == len(manifest['registrations']) == 27
    ranges = []
    for hook, entry in zip(hooks, manifest['registrations']):
        assert all(entry[key] == value for key, value in hook.items())
        assert entry['registration'] == '00053fac'
        assert entry['operation'] == 'replace'
        start, end = int(entry['implementation'], 16), int(entry['instruction_end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == entry['instruction_sha256']
        ranges.append((start, end))
    for wrapper in manifest['gate_wrappers']:
        assert im.terminal(int(wrapper['address'], 16)) == wrapper['terminal']
    for constant in manifest['decoded_constants']:
        assert im.cstring(int(constant['address'], 16)) == constant['value']
    branches = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for branch in manifest['branch_evidence']:
        assert branches[branch['address']] == branch
        assert im.image.u32(im.image.off(int(branch['address'], 16))) == int(branch['original'][0], 16)
    for call in manifest['omitted_supervisor_calls']:
        word = im.image.u32(im.image.off(int(call['address'], 16)))
        assert word == int(call['instruction'], 16)
        assert word & 0xffe0001f == 0xd4000001
    # Full x0 for count/time, w0 for the protobuf BOOLs/enum; w2 enum setter.
    assert im.image.u32(im.image.off(0x6e4e4)) == 0xd2800000
    assert im.image.u32(im.image.off(0x6e4ec)) == 0xd2800000
    assert im.image.u32(im.image.off(0x6e4dc)) == 0x52800000
    assert im.image.u32(im.image.off(0x6e4f4)) == 0x52800000
    assert im.image.u32(im.image.off(0x6e4fc)) == 0x52800040
    assert im.image.u32(im.image.off(0x6e514)) == 0x52800042
    assert manifest['added_properties'] == []
    words = 0
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s', line)
        if match and any(a <= int(match[1], 16) < b for a, b in ranges):
            assert im.image.u32(im.image.off(int(match[1], 16))) == int(match[2], 16)
            words += 1
    assert words == sum((b - a) // 4 for a, b in ranges)
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

    generated = work / 'MediaPolicy.mm'
    run(['perl', logos_path(), '-c', 'generator=internal', source], generated)
    llvm = work / 'MediaPolicy.ll'
    common = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-I', source.parent]
    run(['xcrun', '--sdk', 'iphoneos', 'clang++', *common, '-S', '-emit-llvm', '-target', 'arm64-apple-ios14.0', generated, '-o', llvm])
    signatures = [s for s in llvm.read_text().splitlines() if s.startswith('define ') and ('_logos_method$' in s or '_logos_meta_method$' in s) and '_block_invoke' not in s]
    assert len(signatures) == 27
    returns_bool = {'isPlayableInBackground', 'playableInBackground', 'isBackgroundEnabled', 'shouldBlockUpgradeDialog', 'isMonetized', 'enableSkippableAd', 'hasPlayerCueRangeSet', 'hasStreamTimeMs'}
    returns_object = {'playerAdsArray', 'adSlotsArray', 'auxiliaryUi', 'spamSignalsDictionary', 'spamSignalsDictionaryWithoutIDFA', 'createAdsPlaybackCoordinator'}
    bool_arg = {'setHasAuxiliaryUi:', 'setHasMessageRenderers:'}
    for hook in hooks:
        prefix = '_logos_meta_method$' if hook['kind'] == '+' else '_logos_method$'
        name = prefix + 'YTLMediaPolicy$' + hook['class_name'] + '$' + hook['selector'].replace(':', '$') + 'P'
        matches = [s for s in signatures if name in s]
        assert len(matches) == 1, (name, matches)
        sig = matches[0]
        sel = hook['selector']
        result_type = 'zeroext i1' if sel in returns_bool else 'ptr' if sel in returns_object else 'i64' if sel in ('streamTimeMs', 'validAdsStatesArray_Count') else 'i32' if sel == 'type' else 'void'
        assert sig.startswith('define internal ' + result_type + ' '), sig
        arguments = sig.split('"(', 1)[1].split(') #', 1)[0]
        expected = ['ptr', 'ptr'] + (['i1'] if sel in bool_arg else ['i32'] if sel == 'setType:' else ['ptr'] * sel.count(':'))
        actual = re.findall(r'(ptr|i64|i32|i1) (?:noundef )?(?:zeroext )?%\d+', arguments)
        assert actual == expected, (sel, arguments, expected)
    assert not any(line.startswith('define ') and '_block_invoke' in line for line in llvm.read_text().splitlines())
    fixture = REPO / 'recovery/tests/media_policy_fixture.mm'
    executable = work / 'test'
    run(['xcrun', '--sdk', 'macosx', 'clang++', '-std=c++17', *common, '-fsanitize=undefined', '-fno-sanitize-recover=all', generated, fixture, '-framework', 'Foundation', '-o', executable])
    result = run([executable])
    checks = int(re.search(r'(\d+) actual-hook assertions passed', result)[1])
    files = [source, source.with_name('MediaPolicyHost.h'), source.with_suffix('.manifest.json'), fixture, Path(__file__).resolve()]
    report.write_text(json.dumps(dict(registrations=27, replacements=27, added=0, class_methods=4, added_properties=[], runtime_assertions=checks, original_instruction_words=words, original_function_hashes=27, original_bytes='verified', ios_callback_signatures=signatures, runtime_tests='passed under UBSan with real Foundation collections and Objective-C runtime', original_binary_executed=False, network_requests=0, omitted_supervisor_calls=manifest['omitted_supervisor_calls'], limitations=manifest['limitations'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}), indent=2) + '\n')
    print(f'MediaPolicy: all 27 registrations, {words} original words and iOS callback ABI verified.')


if __name__ == '__main__':
    main()
