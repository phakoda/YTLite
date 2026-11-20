#!/usr/bin/env python3
"""Check first-package caption flows and run actual reconstructed methods with synthetic boundaries."""
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
WORK=REPO/'.recovery-work/first-menu-caption-flow'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence_path=REPO/'recovery/evidence/first-menu-caption-flow-fidelity.json'
    expected=json.loads(evidence_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary);image=MachO(binary)
    source=REPO/'recovery/source/Downloads/DownloadMenuHelper.m'
    source_files=[source,source.parent/'YTPMedia.m',REPO/'recovery/source/Runtime/YTLFeaturePolicy.m',
        REPO/'recovery/tests/downloads_doubles.m',REPO/'recovery/tests/first_menu_caption_sheets_runtime.m']
    shims=REPO/'recovery/tests/downloads_shims'
    share_fixture=REPO/'recovery/tests/first_menu_caption_share_runtime.m'
    boundary=REPO/'recovery/tests/first_menu_caption_flow_boundary.h'
    paths=[share_fixture,boundary,*source_files,*source.parent.glob('*.h'),*shims.rglob('*.h'),REPO/'recovery/tests/downloads_doubles.h',
        REPO/'recovery/source/Subtitles/SRTParser.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',
        manifest_path,evidence_path,source.with_suffix('.caption-flow.provenance.md'),Path(__file__).resolve(),
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
    assembly='\n'.join(run(['xcrun','llvm-objdump','--disassemble','--start-address='+hex(a),'--stop-address='+hex(b),original_path]).stdout
                       for a,b in [(0x1093ec,0x10b290),(0x10c030,0x10d7dc)])
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
    traps=[]
    for span in expected['spans']:
        for address in range(int(span['start'],16),int(span['end'],16),4):
            word=image.u32(image.off(address))
            if word&0xffe0001f==0xd4000001:traps.append((hex(address),hex(word)))
    assert traps==[(item['address'],item['word']) for item in expected['excluded_instructions']]
    assert len(traps)==10
    for item in expected['instructions']:
        assert image.u32(image.off(int(item['address'],16)))==int(item['word'],16)
    for item in expected['imports']:
        raw=struct.unpack_from('<Q',binary,image.off(int(item['reference'],16)))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==item['name']
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
    for stub,name in [(0xb97224,'_objc_msgSend'),(0xb97158,'_objc_alloc_init'),(0xb9714c,'_objc_alloc'),(0xb964f8,'_NSClassFromString'),(0xb96bac,'_dispatch_async')]:
        adrp=image.u32(image.off(stub));ldr=image.u32(image.off(stub+4))
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        pointer=(stub&~0xfff)+(immediate<<12)+((ldr>>10)&0xfff)*8
        raw=struct.unpack_from('<Q',binary,image.off(pointer))[0]
        assert raw>>63 and image.imports[raw&0xffffff]==name
    original=next(c for c in image.classes() if c['name']=='DownloadMenuHelper')
    assert len(expected['method_contracts'])==4
    for method in expected['method_contracts']:assert method in original['methods']
    executable=WORK/'runtime';flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def compile_host(sources,output):
        run(['xcrun','--sdk','macosx','clang',*flags,'-include',boundary,'-I',shims,'-I',source.parent,
             '-framework','Foundation','-framework','CoreGraphics',*sources,'-o',output])
    runtime={};artifacts=[]
    for label,fixture,count in [('sheets',source_files[-1],141),('share',share_fixture,1334)]:
        executable=WORK/(label+'-runtime');compile_host([*source_files[:-1],fixture],executable)
        output=run([executable]).stdout;log=WORK/(label+'-runtime.log');log.write_text(output)
        assert output==f'PASS First_menu_caption_{label}: {count} assertions, 0 failures\n',output
        runtime[label]={'assertions':count,'output':output};artifacts.extend([executable,log])
    original_text=source.read_text();mutations={}
    def change(name,old,new,fixture,count=1):
        assert original_text.count(old)==count,(name,original_text.count(old))
        mutations[name]=(original_text.replace(old,new),fixture)
    change('parser-new','[[SRTParser alloc] init]','[SRTParser new]',source_files[-1],3)
    change('cached-action-class','(Class)NSClassFromString(@"YTActionSheetAction")','YTPMenuActions()',source_files[-1],3)
    change('transcript-result-first','if (error) [toast showMessageWithText:error.localizedDescription isSuccess:NO];\n                else {\n                    [UIPasteboard',
        'if (!text) [toast showMessageWithText:error.localizedDescription isSuccess:NO];\n                else {\n                    [UIPasteboard',source_files[-1])
    change('caption-result-first','if (error) [toast showMessageWithText:error.localizedDescription isSuccess:NO];\n                else { [toast hide]; [self shareSRT:',
        'if (!url) [toast showMessageWithText:error.localizedDescription isSuccess:NO];\n                else { [toast hide]; [self shareSRT:',source_files[-1])
    change('transcript-hides','[UIPasteboard generalPasteboard].string = text;','[toast hide]; [UIPasteboard generalPasteboard].string = text;',source_files[-1])
    change('toast-root-presenter','[(Class<YTPDownloadsResources>)NSClassFromString(@"YTUIUtils") topViewControllerForPresenting]',
        'YTPMenuAppRoot()',share_fixture)
    change('no-activity-exclusions','controller.excludedActivityTypes = @[UIActivityTypeAssignToContact, UIActivityTypePrint];',
        'controller.excludedActivityTypes = nil;',share_fixture)
    change('clamped-source-rect','CGRectMake(width - 5, 0, 1, 1)','CGRectMake(MAX(width - 5, 0), 0, 1, 1)',share_fixture)
    a=original_text.index('- (void)shareSRT:');b=original_text.index('- (void)showImagesSheet:',a)
    body=original_text[a:b];assert body.count('controller.popoverPresentationController')==4
    cached=body.replace('        if (controller.popoverPresentationController)',
        '        UIPopoverPresentationController *popover = controller.popoverPresentationController;\n        if (popover)')
    cached=cached.replace('controller.popoverPresentationController.source','popover.source').replace('controller.popoverPresentationController.permitted','popover.permitted')
    mutations['cached-popover']=(original_text[:a]+cached+original_text[b:],share_fixture)
    rejected={}
    for name,(changed,fixture) in mutations.items():
        mutation=WORK/(name+'.m');mutation.write_text(changed);mutant_executable=WORK/(name+'-runtime')
        compile_host([mutation,*source_files[1:-1],fixture],mutant_executable)
        result=run([mutant_executable],success=False)
        assert result.returncode==1 and 'FAIL ' in result.stderr and 'failures' in result.stdout,(name,result.returncode,result.stdout,result.stderr)
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
    artifacts.extend([WORK/'commands.json',WORK/'original-methods.asm'])
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps({'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'runtime_assertions':1475,'runtime':runtime,'negative_checks':rejected,'metadata':metadata,'inputs':inputs,'original_binary_executed':False,
        'scope':'Caption sheets, parser completion and SRT sharing: constructors, class lookup, deferred arguments, error priority, presenter and popover call order',
        'limits':['Host Foundation and synthetic app boundaries; original dylib is never executed.',
            'Real UIKit presentation, parser networking/file output, all temporary-object lifetimes and live-device behavior are unverified.',
            'Seven semantic branch tables are decoded. Initialization and enumeration paths are byte-pinned but not individually modeled.',
            'Ten original system traps are omitted. ToastView construction uses a dynamic class lookup in recovered shared code.']},indent=2)+'\n')
    print('First-package caption flow: 1475 actual-source checks; 9 mutations rejected; 26 method encodings match both architectures.')



if __name__=='__main__':main()
