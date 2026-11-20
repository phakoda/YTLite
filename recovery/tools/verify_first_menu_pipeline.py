#!/usr/bin/env python3
"""Verify first-package download handoff evidence and the corrected actual source."""
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
from verify_selector_loads import verify_selector_loads
from verify_ios_sources import extract_metadata
REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-menu-pipeline'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-menu-pipeline-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/DownloadMenuHelper.m'
    source_files=[source,source.parent/'YTPMedia.m',REPO/'recovery/source/Runtime/YTLFeaturePolicy.m',
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_menu_pipeline_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    paths=[*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.pipeline.provenance.md'),Path(__file__).resolve(),
        *[REPO/'recovery/tools'/name for name in ['compare_supplied_packages.py','inventory.py','decode_strings.py',
            'verify_selector_loads.py','verify_ios_sources.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in sorted(set(paths))}
    env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    commands=[]
    def run(command,success=True):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append({'command':command,'exit_code':r.returncode,'stdout':r.stdout,'stderr':r.stderr})
        (WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if success and r.returncode:raise RuntimeError(r.stdout+r.stderr)
        return r
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x1065cc','--stop-address=0x1069c0',original_path]).stdout
    (WORK/'original-method.asm').write_text(assembly);_,writes,_=decode(binary,assembly)
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    for item in expected['strings']:
        address=int(item['address'],16);pointer=image.ptr(address+16);length=image.ptr(address+24)
        assert bytes(writes.get(p,binary[image.off(p)]) for p in range(pointer,pointer+length)).decode()==item['value']
    verify_selector_loads(image,expected)
    for item in expected['branches']:
        table,key,xor=[int(item[k],16) for k in ['table','key','xor']]
        delta=(-(image.u32(image.off(key))^xor))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert [hex(image.ptr(table+8*i)+delta) for i in range(2)]==item['targets']
    for item in expected['calls']:
        address=int(item['address'],16);word=image.u32(image.off(address));assert word&0xfc000000==0x94000000
        delta=word&0x3ffffff
        if delta&(1<<25):delta-=1<<26
        assert address+delta*4==int(item['target'],16)
    # Check that the last allocation wrapper really resolves to objc_alloc_init.
    stub=0xb97158;adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
    assert adrp&0x9f000000==0x90000000 and ldr&0xffc00000==0xf9400000
    immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
    if immediate&(1<<20):immediate-=1<<21
    pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
    raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
    assert raw>>63 and image.imports[raw&0xffffff]=='_objc_alloc_init'
    for item in expected['excluded_instructions']:
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    original=next(c for c in image.classes() if c['name']=='DownloadMenuHelper')
    assert len(expected['method_contracts'])==1 and expected['method_contracts'][0] in original['methods']
    executable=WORK/'runtime';flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    output=run([executable]).stdout;(WORK/'runtime.log').write_text(output)
    match=re.fullmatch(r'PASS First_menu_pipeline: (\d+) assertions\s*',output)
    assert match and int(match[1])==298,output
    mutation=WORK/'former-new.m';changed='[root setHelper:(id)[[NSClassFromString(@"YTLHelper") alloc] init]];'
    text=source.read_text();start=text.index('- (void)downloadVideoWithUrl:');end=text.index('- (void)getThumbnail:',start)
    body=text[start:end];assert body.count(changed)==1
    mutation.write_text(text[:start]+body.replace(changed,'[root setHelper:(id)[NSClassFromString(@"YTLHelper") new]];')+text[end:])
    mutant_executable=WORK/'former-new-runtime';compile_host([mutation,*source_files[1:]],mutant_executable)
    rejected=run([mutant_executable],success=False)
    assert rejected.returncode==1 and 'new,' in rejected.stderr and 'first-package handoff sequence' in rejected.stderr
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={}
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir])
        text='\n'.join(line for line in ir.read_text().splitlines() if 'section "llvm.ptrauth"' not in line)
        emitted=extract_metadata(text)['DownloadMenuHelper']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        run(['xcrun','--sdk','iphoneos','clang','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'methods':26,'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-method.asm',mutation,mutant_executable]
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':298,'former_new_negative_check':'rejected','metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Video handoff helper allocation/init, root getter dispatch, nil results, argument identity/width and thumbnail preference timing',
        'limits':['System trap omitted.','Other 25 menu methods and callbacks not covered here.',
            'Synthetic host and downstream downloader; thumbnail fetching and device integration not exercised.',
            'Exact temporary retain/release timing not verified; local preference policy remains a documented difference.']},indent=2)+'\n')
    print('First-package menu pipeline: 298 actual-source checks; former new call rejected; 26 method encodings match both architectures.')


if __name__=='__main__':main()
