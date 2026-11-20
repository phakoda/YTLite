#!/usr/bin/env python3
"""Verify all primary player controls against packaged bytes and actual Logos bodies."""
from logos_tool import logos_path
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    source=REPO/'recovery/source/Hooks/PlayerControls.x';manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    work=REPO/'.recovery-work/player-controls-tests';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256']
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text())if h['class_name']=='YTMainAppControlsOverlayView' and h['registration']!='00008540']
    assert len(hooks)==len(manifest['registrations'])==47
    for expected,actual in zip(hooks,manifest['registrations']):assert all(actual[k]==v for k,v in expected.items())
    for record in manifest['registrations']+manifest['callbacks']:
        a,b=int(record['implementation'],16),int(record['instruction_end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==record['instruction_sha256']
    for address,expected in manifest['instruction_words'].items():assert im.buffer(int(address,16),4).hex()==expected
    for address,expected in manifest['constants'].items():assert im.buffer(int(address,16),len(expected)//2).hex()==expected
    for address,expected in manifest['cfstrings'].items():assert im.cfstring(int(address,16))==expected
    for r in manifest['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(r['key'],16),4),'little')^int(r['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=0x100000000
        assert [hex(im.image.ptr(int(r['table'],16)+i*8)+delta)for i in range(2)]==r['targets']
    for r in manifest['block_descriptors']:assert im.cstring(int(r['signature_address'],16))==r['signature']
    r=manifest['property_registrar_evidence'];a,b=int(r['start'],16),int(r['end'],16)
    assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==r['sha256']
    for address,expected in manifest['metadata_cstrings'].items():assert im.cstring(int(address,16))==expected
    assert len(manifest['property_metadata'])==15
    found=set()
    for added,return_type,signature in re.findall(r'(?:(%new)\s*)?- \(([^)]+)\)([^\n{]+)\s*\{',source.read_text()):
        parts=re.findall(r'(\w+):',signature);selector=''.join(s+':'for s in parts)if parts else signature.strip();found.add((selector,'add'if added else'replace'))
    assert found=={(h['selector'],h['operation'])for h in hooks}
    assert '%ctor'not in source.read_text()and'%group YTLPlayerControls'in source.read_text()
    commands=[]
    def run(args,stdout=None):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        if stdout:stdout.write_text(p.stdout)
        commands.append(dict(command=args,returncode=p.returncode,output=p.stderr if stdout else p.stdout+p.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(p.stderr if stdout else p.stdout+p.stderr,end='');p.check_returncode()
    generated=work/'PlayerControls.mm';llvm=work/'PlayerControls.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-S','-emit-llvm','-target','arm64-apple-ios13.0','-I',source.parent,generated,'-o',llvm])
    signatures=[s for s in llvm.read_text().splitlines()if s.startswith('define ')and'_logos_method$'in s and 'block_invoke'not in s];assert len(signatures)==47
    for h in manifest['registrations']:
        name='_logos_method$YTLPlayerControls$YTMainAppControlsOverlayView$'+h['selector'].replace(':','$')+'P28';matches=[s for s in signatures if name in s];assert len(matches)==1,(name,matches)
        sig=matches[0];assert re.match(r'define internal (?:noundef )?'+h['llvm_return']+r' ',sig),sig
        args=sig.split('"(',1)[1].split(') #',1)[0].split(', ');assert[a.split()[0]for a in args]==h['llvm_arguments'],sig
    blocks=[s for s in llvm.read_text().splitlines()if s.startswith('define internal void ')and'block_invoke'in s];assert len(blocks)==3
    assert sorted(s.split('"(',1)[1].split(') #',1)[0].count('ptr noundef')for s in blocks)==[1,2,2]
    test=work/'fixture'
    run(['xcrun','--sdk','macosx','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-I',source.parent,'-I',REPO/'recovery/tests/player_controls_shims','-include',REPO/'recovery/tests/player_controls_redirect.h',generated,REPO/'recovery/tests/player_controls_fixture.mm','-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',test]);run([test])
    files=[source,source.with_name('PlayerControlsHost.h'),source.with_suffix('.manifest.json'),REPO/'recovery/tests/player_controls_fixture.mm',REPO/'recovery/tests/player_controls_redirect.h',Path(__file__).resolve()]+list((REPO/'recovery/tests/player_controls_shims').rglob('*.h'))
    report.write_text(json.dumps(dict(registrations=47,additions=40,replacements=7,nested_callbacks=3,property_metadata='15 exact runtime property_getAttributes records verified',original_bytes='verified',ios_abi='47 callback signatures and 3 block signatures verified',runtime='passed under UBSan',supplied_binary_executed=False,host_ui_or_network_used=False,installer='YTLInstallPlayerControlsHooks',inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n')
    print('Player controls: 47 registrations, 15 retained properties and 3 nested callbacks verified.')
if __name__=='__main__':main()
