#!/usr/bin/env python3
"""Verify original registrations and execute unmodified Logos hook callbacks."""
from logos_tool import logos_path
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/configuration-hooks-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/Configuration.x'
    manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    casespath=REPO/'recovery/tests/configuration_hooks_cases.json';cases=json.loads(casespath.read_text())
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['class_name'] in cases]
    im=EvidenceImage();assert manifest['binary_sha256']==im.sha256
    assert len(hooks)==len(manifest['registrations'])==38
    for h,entry in zip(hooks,manifest['registrations']):
        assert all(entry[k]==v for k,v in h.items())
        start,end=int(entry['implementation'],16),int(entry['instruction_end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest()==entry['instruction_sha256']
    for wrapper in manifest['gate_wrappers']:
        assert im.terminal(int(wrapper['address'],16))==wrapper['terminal']=='_ytpBool'
    wanted={(h['class_name'],h['selector'],h['operation']) for h in hooks}
    found=set()
    for cls,body in re.findall(r'%hook (\w+)\n(.*?)%end',source.read_text(),re.S):
        for added,ret,name,arg in re.findall(r'(?:(%new)\s*)?- \((\w+)\)(\w+)(:\([^)]*\)\w+)?\s*\{',body):
            found.add((cls,name+(':' if arg else ''),'add' if added else 'replace'))
    assert found==wanted,(found-wanted,wanted-found)
    assert {(c,s) for c,m in cases.items() for s in m}=={(h['class_name'],h['selector']) for h in hooks}
    commands=[]
    def run(args,stdout=None):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        if stdout is not None:stdout.write_text(p.stdout)
        commands.append({'command':args,'returncode':p.returncode,'output':p.stderr if stdout else p.stdout+p.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(p.stderr if stdout else p.stdout+p.stderr,end='');p.check_returncode()
    generated=work/'Configuration.mm'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    llvm=work/'Configuration.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-S','-emit-llvm','-target','arm64-apple-ios13.0','-I',source.parent,generated,'-o',llvm])
    signatures=[line for line in llvm.read_text().splitlines() if line.startswith('define ') and '_logos_method$' in line]
    assert len(signatures)==38
    for h in hooks:
        group='YTLConfigurationEarly' if h['registration']=='0004cf00' else 'YTLConfigurationMain'
        name='_logos_method$'+group+'$'+h['class_name']+'$'+h['selector'].replace(':','$')+'P'
        matches=[s for s in signatures if name in s];assert len(matches)==1,(name,matches)
        sig=matches[0];args=sig.split('"(',1)[1].split(') #',1)[0]
        if h['selector'].endswith(':'):
            assert sig.startswith('define internal void ');assert args.count('ptr ')==2 and 'i1 noundef zeroext %2' in args
        else:
            assert sig.startswith('define internal i32 ' if h['selector']=='maxFallbackAttempts' else 'define internal zeroext i1 ')
            assert args=='ptr noundef %0, ptr noundef %1'
    implementations=[]
    for cls,methods in cases.items():
        implementations.append('@implementation '+cls)
        for sel,rule in methods.items():
            if rule[0]=='added':continue
            if rule[0]=='setter':implementations.append('- (void)'+sel+'(BOOL)value {OriginalSetter(self,_cmd,value);}')
            elif rule[0]=='int':implementations.append('- (int)'+sel+' {return OriginalInt(self,_cmd);}')
            else:implementations.append('- (BOOL)'+sel+' {return OriginalBool(self,_cmd);}')
        implementations.append('@end')
    fixture=work/'fixture.mm';fixture.write_text((REPO/'recovery/tests/configuration_hooks_fixture.mm').read_text().replace('// HOST_IMPLEMENTATIONS','\n'.join(implementations)))
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-I',source.parent,'-I',REPO/'recovery/tests','-framework','Foundation',generated,fixture,'-o',executable])
    run([executable,casespath])
    files=[source,source.with_name('ConfigurationHost.h'),source.with_suffix('.manifest.json'),REPO/'recovery/tests/configuration_hooks_fixture.mm',casespath,Path(__file__).resolve()]
    report.write_text(json.dumps({'registrations':38,'replacements':36,'added':2,'original_bytes':'verified','ios_callback_abi':'verified','runtime_tests':'passed','original_binary_executed':False,'known_type_limit':'Host Objective-C metadata was not packaged: maxFallbackAttempts original signedness cannot be distinguished at the constant 0x7fffffff; emitted w0 and positive value are preserved.','inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}},indent=2)+'\n')
    print('Configuration: all 38 selected packaged registrations, original-byte hashes and iOS callback signatures verified.')
if __name__=='__main__':main()
