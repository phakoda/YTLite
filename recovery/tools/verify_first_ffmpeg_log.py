#!/usr/bin/env python3
"""Check first-package FFmpeg log cleaning evidence and run reconstructed methods."""
import itertools
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
WORK=REPO/'.recovery-work/first-ffmpeg-log'


def log_vectors():
    inputs=[None,'','a','...',' a... ','a\nb\na','a\n\na','a\r\na','a\v a','a\f b','\u00a0q...\u00a0','😀...','e\u0301...','a…','a。','a.\n . \t.  ']
    inputs += ['\n'.join(parts) for parts in itertools.product(['','a','b','a.',' '], repeat=4)]
    inputs += ['\r\n'.join(str(i%7) for i in range(n))+'... ' for n in [15,16,17,31,32,33,257]]
    outputs=[]
    for text in inputs:
     lines=re.split('[\n\r\v\f\x85\u2028\u2029]',text or '')
     nonempty=[x for x in lines if x]
     kept=[x for i,x in enumerate(nonempty) if i==0 or x!=nonempty[i-1]]
     joined='\n'.join(kept).strip(' \t\n\r\v\f\x85\u00a0\u2028\u2029')
     # Count only ASCII periods in the trailing whitespace/period suffix.
     suffix=re.search(r'[. \t\n\r\v\f\x85\u00a0\u2028\u2029]*$',joined)[0]
     clean=joined[:-len(suffix)] if suffix else joined
     outputs.append(dict(input=text,output=clean,whites=1+suffix.count('.')))
    return outputs


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-ffmpeg-log-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/FFMpegHelper.m'
    source_files=[source,
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_ffmpeg_log_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    boundary=REPO/'recovery/tests/downloads_presentation_declarations.h'
    paths=[boundary,REPO/'recovery/tests/downloads_presentation_declarations.h',REPO/'recovery/source/Presentation/ToastView.h',*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.log.provenance.md'),Path(__file__).resolve(),
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
    assembly=''
    for span in expected['spans'][:1]:
        assembly+=run(['xcrun','llvm-objdump','--disassemble','--start-address='+span['start'],'--stop-address='+span['end'],original_path]).stdout
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
    for item in expected.get('cstrings',[]):
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
    assert traps==[{k:item[k] for k in ('address','word')} for item in expected['excluded_instructions']] and len(traps)==1
    def page_base(address):
        word=image.u32(image.off(address));assert word&0x9f000000==0x90000000
        immediate=((word>>5)&0x7ffff)*4+((word>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        return (address&~0xfff)+(immediate<<12)
    for cache in expected.get('class_caches',[]):
        base=page_base(int(cache['page'],16))
        for item in cache['operations']:
            word=image.u32(image.off(int(item['address'],16)));assert word==int(item['word'],16)
            assert base+((word>>10)&0xfff)*8==int(cache['address'],16)
    original_classes={c['name']:int(c['address'],16) for c in image.classes()}
    for constructor in expected.get('constructors',[]):
        page=int(constructor['page'],16);load=int(constructor['load'],16)
        assert load==page+4
        adrp=image.u32(image.off(page));ldr=image.u32(image.off(load))
        assert ldr&0xffc00000==0xf9400000 and adrp&31==(ldr>>5)&31 and ldr&31==0
        reference=page_base(page)+((ldr>>10)&0xfff)*8
        assert image.ptr(reference)==original_classes[constructor['class_name']]
    for item in expected.get('double_constants',[]):
        assert struct.unpack_from('<d',binary,image.off(int(item['address'],16)))[0]==item['value']
    for item in expected.get('data_constants',[]):
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    for item in expected['instructions']:
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    for descriptor in expected.get('capture_descriptors',[]):
        address=int(descriptor['address'],16)
        assert image.ptr(address+8)==descriptor['size']
        assert image.ptr(address+16)==int(descriptor['copy'],16) and image.ptr(address+24)==int(descriptor['dispose'],16)
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
    for stub,name in [(0xb97224,'_objc_msgSend'),(0xb971d0,'_objc_enumerationMutation')]:
        adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
        raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==name
    for item in expected['imports']:
        raw=struct.unpack_from('<Q',binary,image.off(int(item['reference'],16)))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==item['name']
    original=next(c for c in image.classes() if c['name']=='FFMpegHelper')
    assert len(expected['method_contracts'])==1
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-include',boundary,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    vectors_path=WORK/'vectors.json'
    vectors_path.write_text(json.dumps(log_vectors(),ensure_ascii=False)+'\n')
    output=run([executable,vectors_path]).stdout
    assert output=='PASS First_ffmpeg_log: 2055 assertions, 0 failures\n',output
    (WORK/'runtime.log').write_text(output)
    current=source.read_text();mutations={}
    def change(name,old,new,count=1):
        assert current.count(old)==count,(name,current.count(old))
        mutations[name]=current.replace(old,new)
    initial='NSString *clean = [[filtered componentsJoinedByString:@"\\n"]\n        stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];'
    loop='clean = [[clean substringToIndex:clean.length - 1]\n            stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];'
    change('early-character-set',initial,'NSCharacterSet *early = [NSCharacterSet whitespaceAndNewlineCharacterSet];\n    NSString *clean = [[filtered componentsJoinedByString:@"\\n"] stringByTrimmingCharactersInSet:early];')
    assert current.count(initial)==1 and current.count(loop)==1
    mutations['cached-character-set']=current.replace(initial,'NSString *joined = [filtered componentsJoinedByString:@"\\n"];\n    NSCharacterSet *cached = [NSCharacterSet whitespaceAndNewlineCharacterSet];\n    NSString *clean = [joined stringByTrimmingCharactersInSet:cached];').replace(loop,'clean = [[clean substringToIndex:clean.length - 1] stringByTrimmingCharactersInSet:cached];')
    change('keep-empty-lines','![line isEqualToString:@""] && ','')
    change('identity-duplicates','![line isEqualToString:previous]','line != previous')
    change('reset-previous-on-empty','for (NSString *line in lines) {','for (NSString *line in lines) {\n        if ([line isEqualToString:@""]) previous = nil;')
    change('wrong-separator','[filtered componentsJoinedByString:@"\\n"]','[filtered componentsJoinedByString:@","]')
    change('no-initial-trim',initial,'NSString *clean = [filtered componentsJoinedByString:@"\\n"];')
    change('single-period','while ([clean hasSuffix:@"."])','if ([clean hasSuffix:@"."])')
    change('no-loop-trim',loop,'clean = [clean substringToIndex:clean.length - 1];')
    old='- (void)getCleanLog:(NSString *)log {'
    assert current.count(old)==1
    mutations['early-pasteboard']=current.replace(old,old+'\n    UIPasteboard *earlyBoard = [UIPasteboard generalPasteboard];').replace('[UIPasteboard generalPasteboard].string = clean;','earlyBoard.string = clean;')
    change('skip-pasteboard','[UIPasteboard generalPasteboard].string = clean;','(void)clean;')
    rejected={}
    for name,changed in mutations.items():
        mutation=WORK/(name+'.m');mutation.write_text(changed);mutant_executable=WORK/(name+'-runtime')
        compile_host([mutation,*source_files[1:]],mutant_executable)
        result=run([mutant_executable,vectors_path],success=False)
        assert result.returncode==1 and 'FAIL ' in result.stderr and 'failures' in result.stdout,(name,result.returncode,result.stdout,result.stderr)
        rejected[name]={'exit_code':result.returncode,'stdout':result.stdout,'stderr':result.stderr,
                        'source_sha256':digest(mutation),'executable_sha256':digest(mutant_executable)}
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={}
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir])
        text='\n'.join(line for line in ir.read_text().splitlines() if 'section "llvm.ptrauth"' not in line)
        emitted=extract_metadata(text)['FFMpegHelper']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'methods':12,'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-methods.asm',vectors_path]
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':2055,'output_vectors':len(log_vectors()),'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'FFmpeg getCleanLog filtering, joining, repeated trimming, factory order and pasteboard forwarding',
        'limits':['Synthetic Foundation and pasteboard boundaries plus real Foundation string/vector cases.',
            'One original system trap is omitted. Exact temporary object lifetimes, concurrent mutation and device pasteboard behavior remain unverified.']},indent=2)+'\n')
    print('First-package FFmpeg log cleaning: 2055 assertions, eleven regressions rejected, twelve method encodings on both architectures.')



if __name__=='__main__':main()
