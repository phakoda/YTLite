#!/usr/bin/env python3
"""Pin packaged interface evidence and execute the reconstructed Logos hooks without host side effects."""
from logos_tool import logos_path
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    source=REPO/'recovery/source/Hooks/GeneralInterface.x';mp=source.with_suffix('.manifest.json');m=json.loads(mp.read_text());work=REPO/'.recovery-work/general-interface-tests';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    im=EvidenceImage();assert im.sha256==m['binary_sha256']
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text())if h['class_name']in m['classes'] and (h['class_name']not in ['YTSettingsSectionItemManager','ELMTouchCommandPropertiesHandler']or h['registration']=='00053fac')]
    assert len(hooks)==len(m['registrations'])==26
    for h,r in zip(hooks,m['registrations']):assert all(r[k]==v for k,v in h.items())
    def span(r):
        a,b=int(r['implementation'],16),int(r['instruction_end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==r['instruction_sha256']
    for r in m['registrations']+m['callbacks']+m['helpers']+[m['property_registrar']]:span(r)
    for addr,expected in m['cfstrings'].items():assert im.cfstring(int(addr,16))==expected
    for addr,expected in m['cstrings'].items():assert im.cstring(int(addr,16))==expected
    literals={json.loads('"'+s+'"')for s in re.findall(r'@"((?:[^"\\]|\\.)*)"',source.read_text())};assert literals<=set(m['cfstrings'].values())|set(m['cstrings'].values())
    for addr,expected in m['instruction_words'].items():assert im.buffer(int(addr,16),len(expected)//2).hex()==expected
    for r in m['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(r['key'],16),4),'little')^int(r['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=0x100000000
        assert [hex(im.image.ptr(int(r['table'],16)+i*8)+delta)for i in range(2)]==r['targets']
        if 'instruction_span'in r:
            span(r['instruction_span']);branch=int(r['branch'],16);word=int.from_bytes(im.buffer(branch,4),'little');assert word&0xfffffc1f==0xd61f0000
            assert all(int(r['instruction_span']['implementation'],16)<=int(r[k],16)<=branch for k in ['spill','load'])
    for r in m['omitted_supervisor_calls']:
        word=int.from_bytes(im.buffer(int(r['address'],16),4),'little');assert word==int(r['word'],16) and word&0xffe0001f==0xd4000001;assert (word>>5)&0xffff==int(r['immediate'],16)
    for r in m['block_signatures']:
        descriptor=int(r['descriptor'],16);assert im.image.ptr(descriptor+8)==r['size'];assert im.image.ptr(descriptor+r['signature_offset'])==int(r['signature_address'],16);assert im.cstring(int(r['signature_address'],16))==r['signature']
    found=set()
    for cls,body in re.findall(r'%hook (\w+)\n(.*?)%end',source.read_text(),re.S):
        for added,return_type,signature in re.findall(r'(?:(%new)\s*)?- \(([^)]+)\)([^\n{]+)\s*\{',body):
            parts=re.findall(r'(\w+):',signature);selector=''.join(s+':'for s in parts)if parts else signature.strip();found.add((cls,selector,'add'if added else'replace'))
    assert found=={(h['class_name'],h['selector'],h['operation'])for h in hooks};assert '%ctor'not in source.read_text()
    commands=[]
    def run(args,stdout=None):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        if stdout:stdout.write_text(p.stdout)
        commands.append(dict(command=args,returncode=p.returncode,output=p.stderr if stdout else p.stdout+p.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(p.stderr if stdout else p.stdout+p.stderr,end='');p.check_returncode()
    generated=work/'GeneralInterface.mm';llvm=work/'GeneralInterface.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-S','-emit-llvm','-target','arm64-apple-ios13.0','-I',source.parent,generated,'-o',llvm])
    external_classes=set(re.findall(r'@"OBJC_CLASS_\$_(\w+)" = external',llvm.read_text()));assert not external_classes.intersection(m['classes']+['ASImageNode','ASTextNode','YTIPivotBarRenderer','YTMainAppVideoPlayerOverlayViewController','YTActionSheetDialogViewController','YTBottomSheetController'])
    signatures=[s for s in llvm.read_text().splitlines()if s.startswith('define ')and'_logos_method$'in s and'block_invoke'not in s];assert len(signatures)==26
    for h in m['registrations']:
        cls=h['class_name'];name='_logos_method$'+h['group']+'$'+cls+'$'+h['selector'].replace(':','$')+'P'+str(len(cls));matches=[s for s in signatures if name in s];assert len(matches)==1,(name,matches);sig=matches[0]
        assert re.match(r'define internal (?:noundef )?(?:zeroext )?'+re.escape(h['llvm_return'])+r' ',sig),sig
        args=sig.split('"(',1)[1].split(') #',1)[0].split(', ');assert[a.split()[0]for a in args]==h['llvm_arguments'],sig
    blocks=[s for s in llvm.read_text().splitlines()if s.startswith('define internal ')and'block_invoke'in s];assert len(blocks)==5
    for sig in blocks:
        args=re.search(r'block_invoke[^ (]*\((.*?)\) #',sig)[1].split(', ');expected=['ptr','ptr','i64','ptr']if 'GeneralMutateGuide'in sig else['ptr'];assert [a.split()[0]for a in args]==expected,sig
        assert sig.startswith('define internal zeroext i1 ')if 'GeneralMutateGuide'in sig else sig.startswith('define internal void ')
    test=work/'fixture';fixture=REPO/'recovery/tests/general_interface_fixture.mm';shim=REPO/'recovery/tests/general_interface_shims';db=REPO/'recovery/source/Support/YTPDB.m'
    run(['xcrun','--sdk','macosx','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-I',source.parent,'-I',shim,generated,fixture,db,'-framework','Foundation','-framework','CoreGraphics','-o',test]);run([test])
    files=[source,source.with_name('GeneralInterfaceHost.h'),source.with_suffix('.provenance.md'),mp,fixture,db,Path(__file__).resolve()]+list(shim.rglob('*.h'))
    report.write_text(json.dumps(dict(registrations=26,replacements=24,additions=2,callbacks=5,private_helpers=1,property_metadata='helper: T@"YTLHelper",&,N; actual runtime attribute and retention checked',ios_abi='26 method signatures and five block signatures verified; CGSize both lanes preserved',branch_tables=len(m['branch_tables']),manual_branch_tables=43,actual_runtime='passed under UBSan; all actual generated hook bodies exercised',original_bytes='verified',supplied_binary_executed=False,installers=['YTLInstallGeneralInterfaceEarlyHooks','YTLInstallGeneralInterfaceHooks'],limitations=m['limitations'],inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n');print('General interface: 26 registrations, 5 callbacks, 1 private helper and property metadata verified.')
if __name__=='__main__':main()
