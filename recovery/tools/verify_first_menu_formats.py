#!/usr/bin/env python3
"""Check first-package format-selection evidence and run the actual reconstructed methods."""
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
WORK=REPO/'.recovery-work/first-menu-formats'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-menu-formats-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/DownloadMenuHelper.m'
    source_files=[source,source.parent/'YTPMedia.m',REPO/'recovery/source/Runtime/YTLFeaturePolicy.m',
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_menu_formats_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    paths=[*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.formats.provenance.md'),Path(__file__).resolve(),
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
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x102a00','--stop-address=0x104924',original_path]).stdout
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
    for a in range(0x102a00,0x104924,4):
        assert image.u32(image.off(a))&0xffe0001f!=0xd4000001,('Unexpected system trap',hex(a))
    assert expected['comparator_blocks']==[
        {'address':'0x1062260','invoke':'0x1032cc'},
        {'address':'0x1062280','invoke':'0x103990'}]
    for block in expected['comparator_blocks']:
        assert image.ptr(int(block['address'],16)+16)==int(block['invoke'],16)
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
    assert len(expected['method_contracts'])==5
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    output=run([executable]).stdout;(WORK/'runtime.log').write_text(output)
    assert output=='PASS First_menu_formats: 728 assertions, 0 failures\n',output
    text=source.read_text()
    snapshot='    NSArray *formats = [[[response playerData] streamingData] adaptiveFormatsArray];\n'
    mutations={}
    for name,begin,end in [
        ('late-video-formats','- (NSArray *)getVideoFormatsArray:','- (NSArray *)getAudioFormatsArray:'),
        ('late-audio-formats','- (NSArray *)getAudioFormatsArray:','- (id)getBestAudioFormat:')]:
        a=text.index(begin);b=text.index(end,a);body=text[a:b];assert body.count(snapshot)==1
        changed=body.replace(snapshot,'').replace('    for (YTPNode format in formats) {',snapshot+'    for (YTPNode format in formats) {',1)
        mutations[name]=text[:a]+changed+text[b:]
    a=text.index('- (NSArray *)getVideoFormatsArray:');b=text.index('- (NSArray *)getAudioFormatsArray:',a)
    body=text[a:b];assert body.count('else if (isWebM')==2
    mutations['mp4-fallthrough']=text[:a]+body.replace('else if (isWebM','if (isWebM')+text[b:]
    comparison='return (long long)[a contentLength] > (long long)[b contentLength] ? NSOrderedAscending : NSOrderedDescending;'
    assert text.count(comparison)==1
    mutations['unsigned-sort']=text.replace(comparison,comparison.replace('(long long)',''))
    mutations['zero-tie']=text.replace(comparison,'if ([a contentLength] == [b contentLength]) return NSOrderedSame;\n    '+comparison)
    drc='if ([format isDrc]) (void)ytpBool(@"preferDrc");';assert text.count(drc)==1
    mutations['drc-result-filter']=text.replace(drc,'if ([format isDrc] && !ytpBool(@"preferDrc")) continue;')
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
        'runtime_assertions':728,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Video/audio filtering, format reference timing, signed comparators, response compatibility and best/default/English track selection',
        'limits':['Other menu methods and callbacks are outside this audit. Enumeration/initialization branch tables are not individually decoded.',
            'Host Foundation and synthetic app boundaries; original dylib is never executed.',
            'Exact ARC temporary lifetime, OS Foundation implementation identity and on-device behavior are not established.']},indent=2)+'\n')
    print('First-package menu formats: 728 actual-source checks; 6 mutations rejected; 26 method encodings match both architectures.')


if __name__=='__main__':main()
