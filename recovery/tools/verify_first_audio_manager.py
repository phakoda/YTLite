#!/usr/bin/env python3
"""Check first-package normal_construction evidence and run reconstructed methods."""
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
WORK=REPO/'.recovery-work/first-audio-manager'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-audio-manager-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/AudioManager.m'
    source_files=[source,
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_audio_manager_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    boundary=REPO/'recovery/tests/first_audio_manager_boundary.h'
    paths=[boundary,*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.provenance.md'),Path(__file__).resolve(),
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
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x1ce700','--stop-address=0x1cf6e8',original_path]).stdout
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
    assert traps==[{k:item[k] for k in ('address','word')} for item in expected['excluded_instructions']] and len(traps)==2
    def page_base(address):
        word=image.u32(image.off(address));assert word&0x9f000000==0x90000000
        immediate=((word>>5)&0x7ffff)*4+((word>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        return (address&~0xfff)+(immediate<<12)
    for cache in expected['class_caches']:
        base=page_base(int(cache['page'],16))
        for item in cache['operations']:
            word=image.u32(image.off(int(item['address'],16)));assert word==int(item['word'],16)
            assert base+((word>>10)&0xfff)*8==int(cache['address'],16)
    for item in expected['instructions']:
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    for descriptor in expected['capture_descriptors']:
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
    for stub,name in [(0xb97224,'_objc_msgSend'),(0xb97158,'_objc_alloc_init'),(0xb9714c,'_objc_alloc'),(0xb97230,'_objc_msgSendSuper2'),(0xb96504,'_NSLog'),(0xb96c0c,'_dispatch_once'),(0xb9729c,'_objc_storeStrong')]:
        adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
        raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==name
    for item in expected['imports']:
        raw=struct.unpack_from('<Q',binary,image.off(int(item['reference'],16)))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==item['name']
    original=next(c for c in image.classes() if c['name']=='AudioManager')
    assert len(expected['method_contracts'])==8
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-include',boundary,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    compile_host(source_files,executable)
    scenarios=[([],551),(['singleton'],31),(['nil-singleton'],30),(['subclass-singleton'],31)]
    output=''
    for arguments,count in scenarios:
        got=run([executable,*arguments]).stdout
        assert got==f'PASS First_audio_manager: {count} assertions, 0 failures\n',got
        output+=got
    (WORK/'runtime.log').write_text(output)
    current=source.read_text();mutations={}
    def change(name,old,new,count=1):
        assert current.count(old)==count,(name,current.count(old))
        mutations[name]=current.replace(old,new)
    change('early-allocation','NSURL *url = [NSURL fileURLWithPath:path];\n        self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];',
        'self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:[NSURL fileURLWithPath:path] error:&error];')
    change('clear-category-error','self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];',
        'error = nil;\n        self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];')
    change('category-failure-returns','if (error) NSLog(@"DVN --- Unable to set category: %@", error.localizedDescription);',
        'if (error) return nil;')
    change('direct-player-ivar','self.audioPlayer = [[AVAudioPlayer alloc]', '_audioPlayer = [[AVAudioPlayer alloc]')
    change('cached-init-player','self.audioPlayer.delegate = self;\n        [self.audioPlayer prepareToPlay];',
        'AVAudioPlayer *player = self.audioPlayer; player.delegate = self; [player prepareToPlay];')
    change('cached-play-player','if (![self.audioPlayer isPlaying]) [self.audioPlayer play];',
        'AVAudioPlayer *player = self.audioPlayer; if (![player isPlaying]) [player play];')
    change('cached-stop-player','if ([self.audioPlayer isPlaying]) {\n        [self.audioPlayer stop];\n        self.audioPlayer.currentTime = 0.0;\n    }',
        'AVAudioPlayer *player = self.audioPlayer; if ([player isPlaying]) { [player stop]; player.currentTime = 0.0; }')
    change('always-rewind','        self.audioPlayer.currentTime = 0.0;\n    }',
        '    }\n    self.audioPlayer.currentTime = 0.0;')
    change('finish-stops-player','(void)player; (void)flag;', '(void)player; (void)flag; [self.audioPlayer stop];')
    change('singleton-retries','static dispatch_once_t once;\n    dispatch_once(&once, ^{ instance = [[self alloc] init]; });',
        'instance = [[self alloc] init];')
    rejected={}
    for name,changed in mutations.items():
        mutation=WORK/(name+'.m');mutation.write_text(changed);mutant_executable=WORK/(name+'-runtime')
        compile_host([mutation,*source_files[1:]],mutant_executable)
        args=['nil-singleton'] if name=='singleton-retries' else []
        result=run([mutant_executable,*args],success=False)
        assert result.returncode==1 and 'FAIL ' in result.stderr and 'failures' in result.stdout,(name,result.returncode,result.stdout,result.stderr)
        rejected[name]={'exit_code':result.returncode,'stdout':result.stdout,'stderr':result.stderr,
                        'source_sha256':digest(mutation),'executable_sha256':digest(mutant_executable)}
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={}
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir])
        text='\n'.join(line for line in ir.read_text().splitlines() if 'section "llvm.ptrauth"' not in line)
        emitted=extract_metadata(text)['AudioManager']
        assert emitted['properties']['audioPlayer']==expected['properties'][0]['attributes']
        assert emitted['ivars']==[{'name':'_audioPlayer','encoding':'@\"AVAudioPlayer\"','offset':8,'size':8}],emitted['ivars']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in original['methods']}
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]={'methods':8,'ir_sha256':digest(ir),'object_sha256':digest(obj)}
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    artifacts=[executable,WORK/'runtime.log',WORK/'commands.json',WORK/'original-methods.asm']
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':643,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Audio initialization, NSError propagation, singleton receiving class and nil-result caching, fresh player reads during play/stop, strong property ownership',
        'limits':['Host Foundation with synthetic AVFoundation and bundle/URL factories; no actual audio playback.',
            'Two original system traps are omitted. Exact temporary ownership and superclass-init failure are not tested.',
            'Native audio-session interaction, concurrent playback and device behavior remain unverified.']},indent=2)+'\n')
    print('First-package audio manager: 643 assertions, ten regressions rejected, eight method encodings on both architectures.')


if __name__=='__main__':main()
