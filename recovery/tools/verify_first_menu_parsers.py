#!/usr/bin/env python3
"""Check first-package parser evidence and run the actual reconstructed methods."""
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
WORK=REPO/'.recovery-work/first-menu-parsers'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-menu-parsers-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/DownloadMenuHelper.m'
    source_files=[source,source.parent/'YTPMedia.m',REPO/'recovery/source/Runtime/YTLFeaturePolicy.m',
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_menu_parsers_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    paths=[*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.parsers.provenance.md'),Path(__file__).resolve(),
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
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x104924','--stop-address=0x104f2c',original_path]).stdout
    (WORK/'original-methods.asm').write_text(assembly);_,writes,_=decode(binary,assembly)
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    buffers=set()
    for item in expected['strings']:
        address=int(item['address'],16);pointer=image.ptr(address+16);length=image.ptr(address+24)
        width=2 if image.ptr(address+8)&0x10 else 1
        buffers.update(range(pointer,pointer+(length+1)*width))
        value=bytes(writes.get(p,binary[image.off(p)]) for p in range(pointer,pointer+length*width))
        assert value.decode('utf-16-le' if width==2 else 'utf-8')==item['value']
    assert set(writes)<=buffers,('Unexpected constant write',set(writes)-buffers)
    verify_selector_loads(image,expected)
    for item in expected['reused_page_selectors']:
        page,load=int(item['page_instruction'],16),int(item['load_instruction'],16)
        assert 0x104924<=page<load<0x104e10
        adrp=image.u32(image.off(page));ldr=image.u32(image.off(load))
        assert adrp&0x9f000000==0x90000000 and ldr&0xffc00000==0xf9400000 and adrp&31==(ldr>>5)&31
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        reference=(page&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
        assert reference==int(item['reference'],16) and image.string(image.ptr(reference))==item['name']
    indirect=[]
    for a in range(0x104924,0x104f2c,4):
        word=image.u32(image.off(a));assert word&0xffe0001f!=0xd4000001,('Unexpected system trap',hex(a))
        if word&0xfffffc1f==0xd61f0000:indirect.append(hex(a))
    assert indirect==[item['address'] for item in expected['branches']]
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
    stub=0xb97224;adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
    immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
    if immediate&(1<<20):immediate-=1<<21
    pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
    raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
    assert raw>>63 and image.imports[raw&0xffffff]=='_objc_msgSend'
    original=next(c for c in image.classes() if c['name']=='DownloadMenuHelper')
    assert len(expected['method_contracts'])==2
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    output=run([executable]).stdout;(WORK/'runtime.log').write_text(output)
    assert output=='PASS First_menu_parsers: 49 assertions, 0 failures\n',output
    text=source.read_text()
    quality='return [[quality componentsSeparatedByString:@"p"][0] integerValue];'
    former_quality='''if (!quality.length) return 0;
    return [[[quality componentsSeparatedByCharactersInSet:[[NSCharacterSet decimalDigitCharacterSet] invertedSet]] firstObject] integerValue];'''
    assert text.count(quality)==1
    start=text.index('- (NSString *)detailForMimeType:');end=text.index('// First package 0x104e10:',start)
    former_mime=r'''- (NSString *)detailForMimeType:(NSString *)mimeType {
    NSString *container = [[[mimeType componentsSeparatedByString:@";"] firstObject] componentsSeparatedByString:@"/"][1];
    NSArray *parts = [mimeType componentsSeparatedByString:@"codecs=\""];
    if (parts.count == 1) return nil;
    NSString *codec = [[parts objectAtIndexedSubscript:1] componentsSeparatedByString:@"."].firstObject;
    return container && codec ? [NSString stringWithFormat:@"%@ • %@", container, codec] : nil;
}
'''
    mutations={'former-quality':text.replace(quality,former_quality),'former-mime':text[:start]+former_mime+text[end:],
        'quality-first-object':text.replace(quality,'return [[[quality componentsSeparatedByString:@"p"] firstObject] integerValue];')}
    rejected={}
    for name,changed in mutations.items():
        mutation=WORK/(name+'.m');mutation.write_text(changed);mutant_executable=WORK/(name+'-runtime')
        compile_host([mutation,*source_files[1:]],mutant_executable)
        result=run([mutant_executable],success=False)
        assert result.returncode==1 and 'FAIL ' in result.stderr and 'failures' in result.stdout
        rejected[name]={'exit_code':result.returncode,'stdout':result.stdout,'stderr':result.stderr,
                        'source_sha256':digest(mutation),'executable_sha256':digest(mutant_executable)}
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
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-methods.asm']
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':49,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Quality-label literal delimiter, indexed access and signed conversion; MIME range extraction, quote removal, nil results and selector ordering',
        'limits':['Other menu methods, filters and callbacks are outside this audit.',
            'Host Foundation and synthetic app boundaries; original dylib is never executed.',
            'Exact ARC temporary lifetime, OS Foundation implementation identity and on-device behavior are not established.']},indent=2)+'\n')
    print('First-package menu parsers: 49 actual-source checks; 3 mutations rejected; 26 method encodings match both architectures.')


if __name__=='__main__':main()
