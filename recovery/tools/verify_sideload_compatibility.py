#!/usr/bin/env python3
"""Verify the explicitly bounded local compatibility subset, not the excluded registrar."""
from logos_tool import logos_path
import collections, hashlib, json, re, subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO
from verify_playerbar_hooks import source_registrations


def main():
    work = REPO / '.recovery-work/sideload-compatibility'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Hooks/SideloadCompatibility.x'
    manifest = json.loads(source.with_suffix('.manifest.json').read_text())
    inventory = json.loads((REPO / 'recovery/evidence/hooks.json').read_text())
    excluded = [h for h in inventory if h['registration'] == '00019b24' and h['class_name'] not in ('YTIIosPlayerConfig','NSMutableURLRequest','LSApplicationProxy','LSBundleProxy')]
    recorded = [{k:v for k,v in h.items() if k not in ('status','behavior_category')} for h in manifest['excluded_registrations']]
    assert excluded == recorded and len(excluded) == 14
    metadata = [h for h in inventory if h['registration'] == '00019b24' and h['class_name'] in ('NSMutableURLRequest','LSApplicationProxy','LSBundleProxy')]
    recovered = [{k:v for k,v in h.items() if k not in ('status','behavior_category','group')} for h in manifest['implemented_registrations'] if h['registration'] == '00019b24']
    assert metadata == recovered and len(metadata) == 6
    expected = collections.Counter((h['group'], h['class_name'], h['kind'], h['selector'], h['operation']) for h in manifest['implemented_registrations'])
    assert collections.Counter(source_registrations(source.read_text())) == expected
    assert '%ctor' not in source.read_text()
    image = EvidenceImage()
    assert image.sha256 == manifest['binary_sha256']
    for interval in manifest['instruction_intervals']:
        a,b = int(interval['start'],16),int(interval['end'],16)
        assert hashlib.sha256(image.image.data[image.image.off(a):image.image.off(b)]).hexdigest() == interval['sha256']
    for item in manifest['decoded_strings']:
        assert image.cstring(int(item['address'],16)) == item['value']
    for item in manifest['decoded_cfstrings']:
        assert image.cfstring(int(item['address'],16)) == item['value']
    commands = []
    def run(args):
        args = list(map(str,args))
        result = subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=args,exit_code=result.returncode,output=result.stdout+result.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode: print(result.stdout+result.stderr,end='')
        result.check_returncode()
        return result.stdout
    mm = work / 'SideloadCompatibility.mm'
    mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated = set(re.findall(r'_logos_(?:meta_)?method\$(YTL\w*Sideload\w*Compatibility)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()))
    assert generated == {(group,cls,sel.replace(':','$')) for group,cls,kind,sel,op in expected}
    llvm = work/'SideloadCompatibility-ios.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions = {m[1]:m[2] for m in re.finditer(r'^define internal [^\n]+ @"([^"\n]*_logos_(?:meta_)?method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M)}
    blocks = {name:args for name,args in definitions.items() if '_block_invoke' in name}
    definitions = {name:args for name,args in definitions.items() if '_block_invoke' not in name}
    assert len(definitions) == 9 and len(blocks) == 2
    appear = next(args for name,args in definitions.items() if '$viewDidAppear$' in name)
    assert 'i1 noundef zeroext' in appear
    container = next(args for name,args in definitions.items() if '$containerURL' in name)
    assert container.count('ptr noundef') == 3
    for name,args in definitions.items():
        if '$YTLSideloadMetadataCompatibility$' in name:
            assert args.count('ptr noundef') == 2
    for args in blocks.values():
        assert args.count('ptr noundef') == 1
    executable = work/'runtime'
    run(['xcrun','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/sideload_compatibility_shims','-I',source.parent,'-include',REPO/'recovery/tests/sideload_compatibility_redirects.h',mm,REPO/'recovery/tests/sideload_compatibility_runtime.mm','-framework','Foundation','-o',executable])
    run([executable])
    print(commands[-1]['output'],end='')
    inputs = [source,source.parent/'SideloadCompatibilityHost.h',REPO/'recovery/tests/sideload_compatibility_runtime.mm',REPO/'recovery/tests/sideload_compatibility_redirects.h',Path(__file__).resolve()] + list((REPO/'recovery/tests/sideload_compatibility_shims').rglob('*.h'))
    result = dict(status=manifest['status'],implemented_registration_count=9,excluded_registration_count=14,original_bytes='passed',ios_compile_and_llvm_widths='passed',real_logos_runtime='passed',ubsan='passed',original_binary_executed=False,limitations=manifest['limitations'],llvm_hook_signatures=definitions,source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs})
    report.write_text(json.dumps(result,indent=2)+'\n')
    print('Nine compatibility registrations verified; fourteen security-related records remain inventory-only.')

if __name__ == '__main__': main()
