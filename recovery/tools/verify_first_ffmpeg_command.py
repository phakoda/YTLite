#!/usr/bin/env python3
"""Check first-package FFmpeg command and language evidence and run reconstructed methods."""
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
from first_ffmpeg_language_table import language_table_addresses
from verify_selector_loads import verify_selector_loads
from verify_ios_sources import extract_metadata
REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-ffmpeg-command'


def command_vectors(manifest):
    formats={int(x['address'],16):x['value'] for x in manifest['strings']}
    names=['v folder/%20".mp4',"a'with space.m4a",'EN.srt','#thumb.webp','o %@.mp4']
    commands=[]
    def add(flags,mask,duration,nil_managers=0,nil_language=False,nil_format=False,nil_paths=0):
        effective=flags&~nil_managers;caption=bool(effective&1);thumbnail=bool(effective&2)
        values=[None if mask&(1<<i) else v for i,v in enumerate(names)]
        args=values[:2]+([values[2]] if caption else [])+([values[3]] if thumbnail else [])+[duration]+([None if nil_language else 'eng'] if caption else [])+[values[4]]
        tokens=iter(args);f=formats[[0x11be690,0x11be710,0x11be6d0,0x11be750][effective]]
        def replace(match):
            value=next(tokens);return '(null)' if value is None else str(value)
        output=re.sub(r'%@|%ld',replace,f);assert next(tokens,'done')=='done'
        trace=['manager1']+([] if mask&4 else ['caps.path'])+([] if nil_managers&1 else ['exists1'])+['manager2']+([] if mask&8 else ['thumb.path'])+([] if nil_managers&2 else ['exists2'])+(['language'] if caption else [])+['format']
        commands.append(dict(nil_paths=nil_paths,exists=flags,nil_mask=mask,duration=duration,nil_managers=nil_managers,nil_language=nil_language,nil_format=nil_format,output=None if nil_format else output,trace=trace))
    for flags,mask,duration in itertools.product(range(4),range(32),[-(1<<63),-(1<<32)-1,-1,0,1,(1<<32)+1,(1<<63)-1]):add(flags,mask,duration)
    for flags,nm in itertools.product(range(4),range(1,4)):add(flags,0,12,nm)
    for flags in range(4):add(flags,0,99,nil_language=True);add(flags,0,99,nil_format=True)
    for flags,np in itertools.product(range(4),range(1,4)):add(flags,0,7,nil_paths=np)
    result=dict(languages=manifest['languages'],commands=commands)
    return result


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-ffmpeg-command-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/FFMpegHelper.m'
    source_files=[source,
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_ffmpeg_command_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    boundary=REPO/'recovery/tests/downloads_presentation_declarations.h'
    paths=[boundary,REPO/'recovery/tests/downloads_presentation_declarations.h',REPO/'recovery/source/Presentation/ToastView.h',*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.command.provenance.md'),Path(__file__).resolve(),
        *[REPO/'recovery/tools'/name for name in ['compare_supplied_packages.py','inventory.py','decode_strings.py',
            'verify_selector_loads.py','verify_ios_sources.py','first_ffmpeg_language_table.py']]]
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
    for span in expected['spans'][:2]:
        assembly+=run(['xcrun','llvm-objdump','--disassemble','--start-address='+span['start'],'--stop-address='+span['end'],original_path]).stdout
    (WORK/'original-methods.asm').write_text(assembly);_,writes,_=decode(binary,assembly)
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    buffers=set();decoded_strings={}
    for item in expected['strings']:
        address=int(item['address'],16);pointer=image.ptr(address+16);length=image.ptr(address+24)
        width=2 if image.ptr(address+8)&0x10 else 1
        buffers.update(range(pointer,pointer+(length+1)*width))
        value=bytes(writes.get(p,binary[image.off(p)]) for p in range(pointer,pointer+length*width))
        decoded_strings[address]=value.decode('utf-16-le' if width==2 else 'utf-8')
        assert decoded_strings[address]==item['value']
    for item in expected.get('cstrings',[]):
        address=int(item['address'],16);value=item['value'].encode()+b'\0'
        buffers.update(range(address,address+len(value)))
        assert bytes(writes.get(p,binary[image.off(p)]) for p in range(address,address+len(value)))==value
    assert set(writes)<=buffers,('Unexpected constant write',set(writes)-buffers)
    pairs=language_table_addresses(image)
    table=[dict(key_address=hex(k),value_address=hex(v),key=decoded_strings[k],value=decoded_strings[v]) for k,v in pairs]
    assert table==expected['languages'] and len(table)==80
    verify_selector_loads(image,expected)
    traps=[]
    for span in expected['spans']:
        for a in range(int(span['start'],16),int(span['end'],16),4):
            word=image.u32(image.off(a))
            if word&0xffe0001f==0xd4000001:traps.append({'address':hex(a),'word':hex(word)})
    assert traps==[{k:item[k] for k in ('address','word')} for item in expected['excluded_instructions']] and len(traps)==0
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
    for stub,name in [(0xb97224,'_objc_msgSend')]:
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
    assert len(expected['method_contracts'])==2
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-include',boundary,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    vectors_path=WORK/'vectors.json'
    vectors_path.write_text(json.dumps(command_vectors(expected),ensure_ascii=False)+'\n')
    output=run([executable,vectors_path]).stdout
    assert output=='PASS First_ffmpeg_command: 8313 assertions, 0 failures\n',output
    (WORK/'runtime.log').write_text(output)
    current=source.read_text();mutations={}
    def change(name,old,new,count=1):
        assert current.count(old)==count,(name,current.count(old))
        mutations[name]=current.replace(old,new)
    begin=current.index('    id const keys[] = {');end=current.index('    return codes[code]',begin)
    literal='    NSDictionary *codes = @{'+', '.join('@"'+p['key']+'": @"'+p['value']+'"' for p in expected['languages'])+'};\n'
    mutations['constant-dictionary']=current[:begin]+literal+current[end:]
    change('mapping-change','@"fra"','@"bad"',2)
    change('short-table','count:sizeof(keys) / sizeof(keys[0])','count:79')
    change('no-nil-url','if (!url) return nil;','')
    change('drop-fallback','return codes[code] ?: code;','return codes[code];')
    change('normalize-code','NSString *code = [[url lastPathComponent] stringByDeletingPathExtension];','NSString *code = [[[url lastPathComponent] stringByDeletingPathExtension] lowercaseString];')
    old='BOOL captions = [[NSFileManager defaultManager] fileExistsAtPath:captionsURL.path];\n    BOOL thumbnail = [[NSFileManager defaultManager] fileExistsAtPath:thumbnailURL.path];'
    change('cached-manager',old,'NSFileManager *manager = [NSFileManager defaultManager];\n    BOOL captions = [manager fileExistsAtPath:captionsURL.path];\n    BOOL thumbnail = [manager fileExistsAtPath:thumbnailURL.path];')
    change('early-caption-path','BOOL captions = [[NSFileManager defaultManager] fileExistsAtPath:captionsURL.path];','NSString *path = captionsURL.path;\n    BOOL captions = [[NSFileManager defaultManager] fileExistsAtPath:path];')
    # Restrict command mutations to this method; conversion callbacks share formats.
    start=current.index('- (NSString *)getCommandWithVideoURL:');stop=current.index('// First package 0x1f7644',start)
    command=current[start:stop]
    assert command.count('(long)duration')==4
    mutations['narrow-duration']=current[:start]+command.replace('(long)duration','(long)(int)duration')+current[stop:]
    assert command.count('-map 3')==1
    mutations['wrong-stream-map']=current[:start]+command.replace('-map 3','-map 4')+current[stop:]
    assert command.count('videoURL, audioURL,')==4
    mutations['swap-video-audio']=current[:start]+command.replace('videoURL, audioURL,','audioURL, videoURL,')+current[stop:]
    assert command.count('[self codeForCaps:captionsURL]')==2
    mutations['missing-caption-code']=current[:start]+command.replace('[self codeForCaps:captionsURL]','nil')+current[stop:]
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
        definition=next(line for line in text.splitlines() if line.startswith('define internal ptr') and 'codeForCaps:' in line)
        language_body=text[text.index(definition):].split('\n}',1)[0]
        assert 'objc_msgSend$dictionaryWithObjects:forKeys:count:' in language_body and 'i64 noundef 80' in language_body
        emitted=extract_metadata(text)['FFMpegHelper']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'methods':12,'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-methods.asm',vectors_path]
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':8313,'command_vectors':len(command_vectors(expected)['commands']),'language_pairs':80,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'FFmpeg command formats and argument order, independent file-manager lookups, caption table construction and lookup fallback',
        'limits':['Synthetic file managers, URLs, formatting and dictionary boundaries plus native filename cases.',
            'No media conversion or original binary execution. Exact temporary object lifetimes and device library behavior remain unverified.']},indent=2)+'\n')
    print('First-package FFmpeg command and language: 8313 assertions, twelve regressions rejected, twelve method encodings on both architectures.')



if __name__=='__main__':main()
