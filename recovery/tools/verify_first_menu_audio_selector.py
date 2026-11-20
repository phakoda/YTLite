#!/usr/bin/env python3
"""Check first-package audio-selector evidence and run the actual reconstructed methods."""
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
WORK=REPO/'.recovery-work/first-menu-audio-selector'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-menu-audio-selector-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/DownloadMenuHelper.m'
    source_files=[source,source.parent/'YTPMedia.m',REPO/'recovery/source/Runtime/YTLFeaturePolicy.m',
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_menu_audio_selector_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    boundary=REPO/'recovery/tests/first_menu_audio_selector_boundary.h'
    paths=[boundary,*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.audio-selector.provenance.md'),Path(__file__).resolve(),
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
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x107844','--stop-address=0x108c58',original_path]).stdout
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
    for item in expected['cstrings']:
        address=int(item['address'],16);value=item['value'].encode()+b'\0'
        buffers.update(range(address,address+len(value)))
        assert bytes(writes.get(p,binary[image.off(p)]) for p in range(address,address+len(value)))==value
    assert set(writes)<=buffers,('Unexpected constant write',set(writes)-buffers)
    verify_selector_loads(image,expected)
    traps=[]
    for span in expected['spans']:
        for a in range(int(span['start'],16),int(span['end'],16),4):
            word=image.u32(image.off(a))
            if word&0xffe0001f==0xd4000001:traps.append({'address':hex(a),'word':hex(word)})
    assert traps==expected['excluded_instructions'] and len(traps)==3
    cache=expected['class_cache']
    def page_base(address):
        word=image.u32(image.off(address));assert word&0x9f000000==0x90000000
        immediate=((word>>5)&0x7ffff)*4+((word>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        return (address&~0xfff)+(immediate<<12)
    for page_key,op_key,word in [('page','load',0xf940191a),('store_page','store',0xf9001900),
                               ('shared_page','shared_load',0xf9401b97),('shared_page','shared_store',0xf9001b80)]:
        op=image.u32(image.off(int(cache[op_key],16)));assert op==word
        assert page_base(int(cache[page_key],16))+((op>>10)&0xfff)*8==int(cache['address'],16)
    block=expected['comparator_block'];assert image.ptr(int(block['address'],16)+16)==int(block['invoke'],16)
    descriptor=expected['selection_descriptor'];address=int(descriptor['address'],16)
    assert image.ptr(address+8)==descriptor['size']
    assert image.ptr(address+16)==int(descriptor['copy'],16) and image.ptr(address+24)==int(descriptor['dispose'],16)
    assert expected['selection_invoke']=='0x108c48'
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
    for stub,name in [(0xb97224,'_objc_msgSend'),(0xb97200,'_objc_getClass'),(0xb964f8,'_NSClassFromString')]:
        adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
        raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==name
    original=next(c for c in image.classes() if c['name']=='DownloadMenuHelper')
    assert len(expected['method_contracts'])==1
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-include',boundary,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    output=run([executable]).stdout;(WORK/'runtime.log').write_text(output)
    assert output=='PASS First_menu_audio_selector: 119 assertions, 0 failures\n',output
    text=source.read_text()
    a=text.index('- (void)showAudioTrackSelector:');b=text.index('- (BOOL)hasCaptions:',a)
    body=text[a:b];mutations={}
    lookup='if (!actionClass) actionClass =';assert text.count(lookup)==1
    mutations['uncached-class']=text.replace(lookup,'actionClass =')
    resolve='        Class<YTPDownloadsAction> actionClass = YTPMenuActions();'
    title='actionWithTitle:[[format audioTrack] displayName]'
    assert body.count(resolve)==1 and body.count(title)==1
    late=body.replace(resolve,'        NSString *label = [[format audioTrack] displayName];\n'+resolve).replace(title,'actionWithTitle:label')
    mutations['late-class']=text[:a]+late+text[b:]
    assert body.count('imageWithName:@"localization"')==1
    mutations['music-icon']=text[:a]+body.replace('imageWithName:@"localization"','imageWithName:@"music"')+text[b:]
    assert body.count('if (!filtered.count)')==1
    mutations['no-fallback']=text[:a]+body.replace('if (!filtered.count)','if (NO)')+text[b:]
    compare='return [[[a audioTrack] displayName] compare:[[b audioTrack] displayName]];';assert body.count(compare)==1
    normalized=body.replace(compare,'NSComparisonResult result = [[[a audioTrack] displayName] compare:[[b audioTrack] displayName]]; return result < 0 ? -1 : result > 0 ? 1 : 0;')
    mutations['normalized-comparison']=text[:a]+normalized+text[b:]
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
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'methods':26,'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-methods.asm']
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':119,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Audio selector two-pass filtering, signed name comparison, action-class caching and lookup order, icon name, sheet presentation and deferred format selection',
        'limits':['Three system traps in the method and block copy/dispose helpers remain omitted.',
            'Host Foundation and synthetic app boundaries; original dylib is never executed.',
            'Exact ARC temporary lifetimes, concurrent class-cache access, OS sorting implementation and on-device behavior are not established.',
            'Shared action-class caching is restored in this source module. Class-object retain/autorelease timing and unrelated callers are outside this audit.']},indent=2)+'\n')
    print('First-package audio-selector: 119 actual-source checks; 5 mutations rejected; 26 method encodings match both architectures.')


if __name__=='__main__':main()
