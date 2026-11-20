#!/usr/bin/env python3
"""Verify first-package YTPMedia theme evidence and execute reconstructed source."""
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
sys.dont_write_bytecode=True
from compare_supplied_packages import archive_files
from decode_strings import decode
from inventory import MachO
from verify_ios_sources import extract_metadata
from verify_selector_loads import verify_selector_loads

REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-media-theme'
EVIDENCE=REPO/'recovery/evidence/first-media-theme-fidelity.json'
SOURCE=REPO/'recovery/source/Downloads/YTPMedia.m'
FIXTURE=REPO/'recovery/tests/first_media_runtime.m'
SHIMS=REPO/'recovery/tests/first_media_shims'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def check_evidence(binary,expected,assembly):
    image=MachO(binary)
    assert hashlib.sha256(binary).hexdigest()==expected['binary_sha256']
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256'],span
    _,writes,_=decode(binary,assembly)
    for item in expected['strings']:
        address=int(item['address'],16);pointer=image.ptr(address+16);length=image.ptr(address+24)
        assert bytes(writes.get(p,binary[image.off(p)]) for p in range(pointer,pointer+length)).decode()==item['value'],item
    for item in expected['constants']:
        assert struct.unpack_from('<d',binary,image.off(int(item['address'],16)))[0]==item['double'],item
    for item in expected['branches']:
        table,key,xor=[int(item[k],16) for k in ('table','key','xor')]
        delta=(-(image.u32(image.off(key))^xor))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert [hex(image.ptr(table+8*i)+delta) for i in range(2)]==item['targets'],item
    verify_selector_loads(image,expected)
    for item in expected['excluded_instructions']:
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16),item
    original=next(c for c in image.classes() if c['name']=='YTPMedia')
    for method in expected['method_contracts']:
        assert method in original['methods'],method
    assert len(expected['method_contracts'])==8
    return original


def main():
    WORK.mkdir(parents=True,exist_ok=True)
    report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for name,b in archive_files(package,'data.tar').items() if name.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary)
    input_paths=[SOURCE,SOURCE.with_suffix('.h'),SOURCE.parent/'DownloadsHost.h',
        REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',FIXTURE,*SHIMS.rglob('*.h'),
        EVIDENCE,manifest_path,SOURCE.with_suffix('.theme.provenance.md'),Path(__file__).resolve(),
        *[REPO/'recovery/tools'/n for n in ['compare_supplied_packages.py','decode_strings.py','inventory.py',
            'verify_ios_sources.py','verify_selector_loads.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in sorted(input_paths)}
    env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    commands=[]
    def run(command):
        command=list(map(str,command))
        result=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append({'command':command,'exit_code':result.returncode,'stdout':result.stdout,'stderr':result.stderr})
        (WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode:raise RuntimeError(result.stdout+result.stderr)
        return result.stdout
    assembly=''
    for a,b in [('0x1aa098','0x1aab50'),('0x1b5e88','0x1b6728')]:
        assembly+=run(['xcrun','llvm-objdump','--disassemble','--start-address='+a,'--stop-address='+b,original_path])
    (WORK/'original-theme.asm').write_text(assembly)
    expected=json.loads(EVIDENCE.read_text());original=check_evidence(binary,expected,assembly)
    executable=WORK/'runtime'
    flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    run(['xcrun','--sdk','macosx','clang',*flags,'-I',SHIMS,'-framework','Foundation','-framework','CoreGraphics',
         SOURCE,FIXTURE,'-o',executable])
    output=run([executable]);(WORK/'runtime.log').write_text(output)
    count=int(re.fullmatch(r'PASS First_media_theme: (\d+) assertions\s*',output)[1])
    assert count==423,count
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).strip()
    metadata={}
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o')
        target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',SOURCE,'-o',ir])
        # Pointer-authentication constants are indirection records, not method lists.
        # Filter only those declarations for this older metadata reader. Compile
        # and hash the original, unmodified arm64e IR below.
        metadata_text='\n'.join(line for line in ir.read_text().splitlines()
                                if 'section "llvm.ptrauth"' not in line)
        emitted=extract_metadata(metadata_text)['YTPMedia']
        wanted={m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        assert emitted['methods']==wanted,(arch,'method encodings')
        run(['xcrun','--sdk','iphoneos','clang','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'method_count':len(wanted),'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-theme.asm']
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report={'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':count,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Eight YTPMedia methods: singleton, page style, dynamic theme colors, version gate and generic/Discord asset selection',
        'limits':['Setter system trap omitted.','Other 59 icon factories not covered by this behavioral audit.',
                  'Synthetic UIKit, bundle and preference boundaries; actual device and local preference policy remain unverified.']}
    report_path.write_text(json.dumps(report,indent=2)+'\n')
    print(f'First-package YTPMedia theme: {count} actual-source checks; 67 method encodings match on both architectures.')


if __name__=='__main__':main()
