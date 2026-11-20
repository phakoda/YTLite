#!/usr/bin/env python3
"""Compile the selected recovery sources and report remaining packaged methods.

This is an implementation/ABI inventory, not proof of runtime behavior or hook
integration. It ignores decompiler exports and superseded independent copies.
"""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import re
import subprocess
from verify_ios_sources import extract_metadata

REPO = Path(__file__).resolve().parents[2]
LIBRARY_CLASSES = {'ArchDetect','AtomicLong','FFmpegExecution','MobileFFmpeg','CallbackData','MobileFFmpegConfig','Statistics'}

def main():
    make = (REPO/'recovery/source/recovered.mk').read_text()
    sources = set((REPO/'Utils').glob('*.m'))
    for pattern in re.findall(r'recovery/source/[\w+./*]+\.m', make):
        sources.update(REPO.glob(pattern))
    work = REPO/'.recovery-work/source-inventory'
    work.mkdir(parents=True, exist_ok=True)
    target = REPO/'recovery/evidence/source-inventory.json'
    target.unlink(missing_ok=True)
    inputs = sources | set(REPO.glob('*.h')) | set((REPO/'Utils').glob('*.h')) | set((REPO/'recovery/source').rglob('*.h'))
    def hashes():
        return {str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(inputs)}
    before = hashes()
    sdk = subprocess.check_output(['xcrun','--sdk','iphoneos','--show-sdk-path'],text=True).strip()
    def compile_source(source):
        ir = work/('-'.join(source.relative_to(REPO).parts)+'.ll')
        command = ['xcrun','--sdk','iphoneos','clang','-fobjc-arc','-fblocks','-target','arm64-apple-ios14.0','-isysroot',sdk,
                   '-S','-emit-llvm',str(source),'-o',str(ir)]
        result = subprocess.run(command,cwd=REPO,capture_output=True,text=True,timeout=60)
        ir.with_suffix('.log').write_text(result.stdout+result.stderr)
        result.check_returncode()
        return source, extract_metadata(ir.read_text())
    classes, owners = {}, {}
    with ThreadPoolExecutor(max_workers=4) as executor:
        for source, found in executor.map(compile_source, sorted(sources)):
            for name, data in found.items():
                if name in classes: raise ValueError('Duplicate class: '+name)
                classes[name] = data
                owners[name] = str(source.relative_to(REPO))
    reports = []
    for original in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()):
        name = original['name']
        if name in LIBRARY_CLASSES: continue
        expected = {m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        actual = classes.get(name,{}).get('methods',{})
        reports.append({'class':name,'source':owners.get(name),'packaged_methods':len(expected),'compiled_methods':len(actual),
            'missing_methods':sorted(expected.keys()-actual.keys()),'additional_methods':sorted(actual.keys()-expected.keys()),
            'changed_encodings':{k:{'packaged':expected[k],'compiled':actual[k]} for k in expected.keys()&actual.keys() if expected[k]!=actual[k]}})
    exact = [r for r in reports if r['source'] and not r['missing_methods'] and not r['additional_methods'] and not r['changed_encodings']]
    report = {'scope':'Selected Objective-C build sources; method coverage/ABI only. Does not establish hook integration or runtime behavior.',
              'selected_source_files':len(sources),'packaged_first_party_classes':len(reports),'classes_with_compiled_implementations':sum(bool(r['source']) for r in reports),
              'classes_with_exact_method_sets_and_encodings':len(exact),'classes':reports,
              'source_sha256':before,
              'excluded_library_classes':sorted(LIBRARY_CLASSES),'full_tweak_link':'not performed by this inventory'}
    assert hashes() == before, 'Source/header inputs changed during compilation; rerun after edits finish.'
    target.write_text(json.dumps(report,indent=2)+'\n')
    print(f'{len(sources)} Objective-C source files compiled for iOS arm64.')
    print(f'{report["classes_with_compiled_implementations"]}/{len(reports)} first-party classes have implementations; {len(exact)} match all packaged method signatures.')
    for row in reports:
        if not row['source']: print('Missing class:',row['class'])
        elif row not in exact: print('Method differences:',row['class'],'missing=',row['missing_methods'],'extra=',row['additional_methods'],'encoding=',row['changed_encodings'])
    print('Inventory:',target)

if __name__ == '__main__': main()
