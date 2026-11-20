#!/usr/bin/env python3
"""Check first-package DVNCell initialization and destruction against compiled source."""
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
sys.dont_write_bytecode=True
from inventory import MachO
from compare_supplied_packages import archive_files
from first_model_accessor_contracts import ivars,target,runtime_symbol
from verify_selector_loads import verify_selector_loads
from verify_ios_sources import extract_metadata
REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-cell-lifecycle'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def llvm_bodies(text,destruction):
    bodies={}
    for selector in ['init','.cxx_destruct']:
        definition=next(l for l in text.splitlines() if l.startswith('define internal ') and '-[DVNCell '+selector+']' in l)
        body=text[text.index(definition):].split('\n}',1)[0].splitlines()[1:]
        lines=[]
        for line in body:
            line=line.strip().split(', !')[0].split(';')[0].strip()
            line=re.sub(r' #\d+','',line);line=re.sub(r'\b(?:noundef|nonnull) ','',line)
            if line:lines.append(line)
        bodies[selector]=lines
    expected=[]
    for i,entry in enumerate(destruction,3):
        expected.append(f'%{i} = getelementptr inbounds i8, ptr %0, i64 {entry["offset"]}')
        call=f'tail call void @llvm.objc.destroyWeak(ptr %{i})' if entry['operation']=='weak' else f'tail call void @llvm.objc.storeStrong(ptr %{i}, ptr null)'
        expected.append(call)
    expected.append('ret void');assert bodies['.cxx_destruct']==expected
    expected_init='''%3 = alloca %struct._objc_super, align 8
store ptr %0, ptr %3, align 8
%4 = load ptr, ptr @"OBJC_CLASSLIST_SUP_REFS_$_", align 8
%5 = getelementptr inbounds i8, ptr %3, i64 8
store ptr %4, ptr %5, align 8
%6 = load ptr, ptr @OBJC_SELECTOR_REFERENCES_, align 8
%7 = call ptr @objc_msgSendSuper2(ptr %3, ptr %6)
%8 = icmp eq ptr %7, null
br i1 %8, label %15, label %9
9:
%10 = load ptr, ptr @"OBJC_CLASSLIST_REFERENCES_$_", align 8
%11 = call ptr @"objc_msgSend$UUID"(ptr %10, ptr undef) [ "clang.arc.attachedcall"(ptr @llvm.objc.retainAutoreleasedReturnValue) ]
call void (...) @llvm.objc.clang.arc.noop.use(ptr %11)
%12 = call ptr @"objc_msgSend$UUIDString"(ptr %11, ptr undef) [ "clang.arc.attachedcall"(ptr @llvm.objc.retainAutoreleasedReturnValue) ]
call void (...) @llvm.objc.clang.arc.noop.use(ptr %12)
%13 = getelementptr inbounds i8, ptr %7, i64 24
%14 = load ptr, ptr %13, align 8
store ptr %12, ptr %13, align 8
call void @llvm.objc.release(ptr %14)
call void @llvm.objc.release(ptr %11)
br label %15
15:
ret ptr %7'''.splitlines()
    assert bodies['init']==expected_init,('Unexpected initializer LLVM',bodies['init'])
    assert re.search(r'@"OBJC_CLASSLIST_SUP_REFS_\$_" = .*ptr @"OBJC_CLASS_\$_DVNCell"',text)
    assert re.search(r'@"OBJC_CLASSLIST_REFERENCES_\$_" = .*ptr @"OBJC_CLASS_\$_NSUUID"',text)
    selector=next(l for l in text.splitlines() if l.startswith('@OBJC_SELECTOR_REFERENCES_ = '))
    name=re.search(r'ptr (@OBJC_METH_VAR_NAME_[\w.]*)',selector)[1]
    assert next(l for l in text.splitlines() if l.startswith(name+' = ')).split(' c"',1)[1].startswith('init\\00"')
    return bodies


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    package_index=REPO/'recovery/evidence/packages.json';record=next(r for r in json.loads(package_index.read_text()) if r['package']==package.name)
    assert digest(package)==record['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence=REPO/'recovery/evidence/first-cell-lifecycle-fidelity.json';expected=json.loads(evidence.read_text())
    assert hashlib.sha256(binary).hexdigest()==record['binary_sha256']==expected['binary_sha256']
    image=MachO(binary);classes=image.classes();cls=next(c for c in classes if c['name']=='DVNCell')
    assert expected['method_contracts']==[m for m in cls['methods'] if m['kind']=='-' and m['selector'] in ('init','.cxx_destruct')]
    for span in expected['spans']:
        a,z=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+z-a]).hexdigest()==span['sha256']
    verify_selector_loads(image,expected)
    assert [s['name'] for s in expected['selectors']]==['init','UUID','UUIDString']
    for item in expected['calls']:
        address=int(item['address'],16);word=image.u32(image.off(address));assert word&0xfc000000==0x94000000
        destination=target(address,word);assert destination==int(item['target'],16)
        wrappers={};assert runtime_symbol(image,destination,wrappers)==item['symbol']
        for address,words in wrappers.items():
            assert any(int(s['start'],16)==address and int(s['end'],16)==address+len(words)*4 for s in expected['spans'])
    for item in expected['init_instructions']+expected['omitted']:assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    assert [int(i['address'],16) for i in expected['init_instructions']]==list(range(0x18f228,0x18f304,4))
    assert [int(i['word'],16) for i in expected['omitted']]==[0xd2800002,0xd28003e1,0xd2800003,0xd2800340,0xd2800010,0xd405eae1]
    branch=expected['branch'];table,key,xor=[int(branch[n],16) for n in ['table','key','xor']]
    assert table==0x11a9740 and key==0x11a9750 and xor==0xde8e1666
    delta=(-(image.u32(image.off(key))^xor))&0xffffffff
    if delta>=2**31:delta-=2**32
    assert [hex(image.ptr(table+8*i)+delta) for i in range(2)]==branch['targets']==['0x18f2a4','0x18f2f0']
    assert image.ptr(int(expected['super_reference']['address'],16))==int(cls['address'],16)
    reference=expected['uuid_reference'];raw=struct.unpack_from('<Q',binary,image.off(int(reference['address'],16)))[0]
    assert raw>>63 and image.imports[raw&0xffffff]==reference['symbol']=='_OBJC_CLASS_$_NSUUID'
    layout=ivars(image,cls);destruction=[dict(name=v['name'],offset=v['offset'],operation='weak' if v['name']=='_sourceView' else 'strong') for v in reversed(layout) if v['encoding'].startswith('@')]
    assert destruction==expected['destruction'] and len(destruction)==23
    # Recognize the entire destructor instruction sequence, including each
    # strong/weak runtime operation and the separately omitted system trap.
    cursor=0x1908ec
    for word in [0xa9be4ff4,0xa9017bfd,0x910043fd,0xaa0003f3]:assert image.u32(image.off(cursor))==word;cursor+=4
    for index,entry in enumerate(destruction):
        assert image.u32(image.off(cursor))==0x91000000+(entry['offset']<<10)+(0 if index==0 else 19<<5);cursor+=4
        if entry['operation']=='strong':assert image.u32(image.off(cursor))==0xd2800001;cursor+=4
        name='_objc_destroyWeak' if entry['operation']=='weak' else '_objc_storeStrong'
        word=image.u32(image.off(cursor));assert word&0xfc000000==0x94000000 and runtime_symbol(image,target(cursor,word),{})==name;cursor+=4
    assert cursor==0x190a0c;cursor+=24
    for word in [0xa9417bfd,0xa8c24ff4,0xd65f03c0]:assert image.u32(image.off(cursor))==word;cursor+=4
    assert cursor==0x190a30
    source=REPO/'recovery/source/Models/DVNCell.m';header=source.with_suffix('.h');fixture=REPO/'recovery/tests/first_cell_lifecycle_runtime.m'
    paths=[source,header,fixture,source.with_suffix('.lifecycle.provenance.md'),evidence,package_index,Path(__file__).resolve(),
           *[REPO/'recovery/tools'/n for n in ['inventory.py','compare_supplied_packages.py','first_model_accessor_contracts.py','verify_selector_loads.py','verify_ios_sources.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in paths};commands=[];env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    def run(command,success=True):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,capture_output=True,text=True,timeout=90)
        commands.append(dict(command=command,exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr));(WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if success and r.returncode:raise RuntimeError(r.stdout+r.stderr)
        return r
    flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def host(path,output):run(['xcrun','--sdk','macosx','clang',*flags,'-I',source.parent,'-framework','Foundation',path,fixture,'-o',output])
    executable=WORK/'runtime';host(source,executable);r=run([executable,evidence]);assert r.stdout=='PASS First_cell_lifecycle: 598 assertions, 0 failures\n';(WORK/'runtime.log').write_text(r.stdout)
    current=source.read_text();mutations={}
    def change(name,old,new):assert current.count(old)==1;mutations[name]=current.replace(old,new)
    change('no-super','    self = [super init];','')
    change('wrong-identifier-slot','if (self) _reuseIdentifier = [[NSUUID UUID] UUIDString];','if (self) _title = [[NSUUID UUID] UUIDString];')
    change('no-uuid','[[NSUUID UUID] UUIDString]','nil')
    change('uuid-constructor','[[NSUUID UUID] UUIDString]','[[[NSUUID alloc] init] UUIDString]')
    change('cached-identifier','if (self) _reuseIdentifier','if (self && !_reuseIdentifier) _reuseIdentifier')
    change('clear-before-uuid','if (self) _reuseIdentifier = [[NSUUID UUID] UUIDString];','if (self) { _reuseIdentifier = nil; _reuseIdentifier = [[NSUUID UUID] UUIDString]; }')
    change('change-unrelated-type','if (self) _reuseIdentifier = [[NSUUID UUID] UUIDString];','if (self) { _reuseIdentifier = [[NSUUID UUID] UUIDString]; _type = 0; }')
    before,after=current.rsplit('@end',1)
    for name,field in [('title-first','_title'),('handler-first','_handler'),('identifier-first','_identifier')]:mutations[name]=before+'- (void)dealloc { '+field+' = nil; }\n@end'+after
    rejected={}
    for name,text in mutations.items():
        path=WORK/(name+'.m');path.write_text(text);output=WORK/(name+'-runtime');host(path,output);r=run([output,evidence],success=False)
        assert r.returncode==1 and 'FAIL ' in r.stderr and 'failures' in r.stdout,(name,r.returncode,r.stdout,r.stderr)
        rejected[name]=dict(stdout=r.stdout,stderr=r.stderr,source_sha256=digest(path),executable_sha256=digest(output))
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={};artifacts=[executable,WORK/'runtime.log',WORK/'commands.json']
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target_arch=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target_arch,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir])
        text=ir.read_text();bodies=llvm_bodies(text,destruction)
        emitted=extract_metadata('\n'.join(l for l in text.splitlines() if 'section "llvm.ptrauth"' not in l))['DVNCell']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in cls['methods']}
        assert emitted['properties']=={p['name']:p['attributes'] for p in cls['properties']} and emitted['ivars']==layout
        normalized=WORK/(arch+'-lifecycle.json');normalized.write_text(json.dumps(bodies,indent=2)+'\n')
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target_arch,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]=dict(methods=83,properties=32,ivars=32,complete_lifecycle_bodies=2,ir_sha256=digest(ir),object_sha256=digest(obj));artifacts.extend([ir,obj,normalized])
    for path,value in inputs.items():assert digest(REPO/path)==value
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps(dict(passed=True,first_package_sha256=record['sha256'],first_binary_sha256=record['binary_sha256'],runtime_assertions=598,negative_checks=rejected,metadata=metadata,inputs=inputs,original_binary_executed=False,
        scope='DVNCell initializer nil/replacement superclass results, UUID messages and replacement ownership, plus all owned-field destructor ordering and weak cleanup',
        limits=['One original destructor system trap is omitted.','Superclass and UUID results are controlled in host tests with their original ownership conventions; actual device execution remains unverified.','Weak cleanup position is established by original and compiled bodies; host lifetime tests verify the referent survives destruction, without inspecting private weak-runtime tables.','Factory argument and ownership behavior remains a separate audit.']),indent=2)+'\n')
    print('First-package cell lifecycle: 598 assertions, ten regressions rejected, both complete bodies checked on both iOS architectures.')


if __name__=='__main__':main()
