#!/usr/bin/env python3
"""Check packaged primary player registrations and run actual Logos code on isolated hosts."""
from logos_tool import logos_path
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/player-lifecycle-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/PlayerLifecycle.x';manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text())if h['registration']=='00053fac' and h['class_name']=='YTPlayerViewController']
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256'];assert len(hooks)==len(manifest['registrations'])==10
    for h,record in zip(hooks,manifest['registrations']):
        assert all(record[k]==v for k,v in h.items())
        a,b=int(record['implementation'],16),int(record['instruction_end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==record['instruction_sha256']
    for record in manifest['helpers']:
        a,b=int(record['implementation'],16),int(record['instruction_end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==record['instruction_sha256']
    for address,expected in manifest['instruction_words'].items():assert im.buffer(int(address,16),4).hex()==expected
    for address,expected in manifest['cfstrings'].items():assert im.cfstring(int(address,16))==expected
    for record in manifest['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(record['key'],16),4),'little')^int(record['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=0x100000000
        assert [hex(im.image.ptr(int(record['table'],16)+i*8)+delta)for i in range(2)]==record['targets']
    found=set()
    for cls,body in re.findall(r'%hook (\w+)\n(.*?)%end',source.read_text(),re.S):
        for added,signature in re.findall(r'(?:(%new)\s*)?- \(void\)([^\n{]+)\s*\{',body):
            parts=re.findall(r'(\w+):',signature);selector=''.join(s+':' for s in parts) if parts else signature.strip()
            found.add((cls,selector,'add' if added else 'replace'))
    wanted={(h['class_name'],h['selector'],h['operation'])for h in hooks};assert found==wanted,(found-wanted,wanted-found)
    assert '%ctor' not in source.read_text();assert '%group YTLPlayerLifecycle' in source.read_text()
    commands=[]
    def run(args,stdout=None):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        if stdout is not None:stdout.write_text(p.stdout)
        commands.append({'command':args,'returncode':p.returncode,'output':p.stderr if stdout else p.stdout+p.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(p.stderr if stdout else p.stdout+p.stderr,end='');p.check_returncode()
    generated=work/'PlayerLifecycle.mm'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    llvm=work/'PlayerLifecycle.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-S','-emit-llvm','-target','arm64-apple-ios13.0','-I',source.parent,generated,'-o',llvm])
    signatures=[s for s in llvm.read_text().splitlines()if s.startswith('define ')and '_logos_method$'in s];assert len(signatures)==10
    for h in manifest['registrations']:
        name='_logos_method$YTLPlayerLifecycle$'+h['class_name']+'$'+h['selector'].replace(':','$')+'P'
        matches=[s for s in signatures if name in s];assert len(matches)==1,(name,matches)
        sig=matches[0];assert sig.startswith('define internal void ')
        args=sig.split('"(',1)[1].split(') #',1)[0].split(', ')
        assert [a.split()[0]for a in args]==h['llvm_arguments'],sig
    helper=source.with_name('PlayerLifecycleHelpers.m')
    run(['xcrun','--sdk','iphoneos','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-S','-emit-llvm','-target','arm64-apple-ios13.0',helper,'-o',work/'PlayerLifecycleHelpers.ll'])
    for name in ('addEndTime','autoSkipShortsLegacy'):
        matches=[line for line in (work/'PlayerLifecycleHelpers.ll').read_text().splitlines() if line.startswith('define void @'+name+'(')]
        assert len(matches)==1 and matches[0].count('ptr noundef')==3,matches
    executable=work/'test' 
    run(['xcrun','--sdk','macosx','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-I',source.parent,'-I',REPO/'recovery/tests/player_lifecycle_shims','-include',REPO/'recovery/tests/player_lifecycle_redirect.h','-framework','Foundation','-framework','CoreGraphics',generated,helper,REPO/'recovery/tests/player_lifecycle_fixture.mm','-o',executable])
    run([executable])
    files=[helper,source.with_name('PlayerLifecycleHelpers.h'),REPO/'recovery/tests/player_lifecycle_redirect.h',source,source.with_name('PlayerLifecycleHost.h'),source.with_suffix('.manifest.json'),REPO/'recovery/tests/player_lifecycle_fixture.mm',Path(__file__).resolve()]+list((REPO/'recovery/tests/player_lifecycle_shims').rglob('*.h'))
    report.write_text(json.dumps({'registrations':10,'replacements':4,'added':6,'source_byte_ranges':'verified','ios_callback_register_widths':'verified','actual_logos_runtime':'passed','original_binary_executed':False,'installer':'YTLInstallPlayerLifecycleHooks','host_metadata_limitation':'Caption source is always zero; audio constraint reason is always 2. These constants do not establish the original host enum spelling. Runtime callback arguments are all object pointers.','inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}},indent=2)+'\n')
    print('Player lifecycle: 10 original registrations and iOS callback register signatures verified.')
if __name__=='__main__':main()
