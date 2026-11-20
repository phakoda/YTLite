#!/usr/bin/env python3
"""Verify FeedFiltering against supplied bytes and execute the actual generated Logos callbacks."""
from logos_tool import logos_path
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    source=REPO/'recovery/source/Hooks/FeedFiltering.x';manifest_path=source.with_suffix('.manifest.json');manifest=json.loads(manifest_path.read_text());work=REPO/'.recovery-work/feed-filtering-tests';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256'];hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text())if h['class_name']in manifest['classes']];assert len(hooks)==len(manifest['registrations'])==27
    for h,r in zip(hooks,manifest['registrations']):assert all(r[k]==v for k,v in h.items())
    for r in manifest['registrations']+manifest['callbacks']+manifest['helpers']:
        a,b=int(r['implementation'],16),int(r['instruction_end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==r['instruction_sha256']
    for addr,expected in manifest['cfstrings'].items():assert im.cfstring(int(addr,16))==expected
    assert set(re.findall(r'@"([^"\\]*)"',source.read_text()))<=set(manifest['cfstrings'].values())
    for addr,expected in manifest['instruction_words'].items():assert im.buffer(int(addr,16),len(expected)//2).hex()==expected
    for r in manifest['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(r['key'],16),4),'little')^int(r['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=0x100000000
        assert [hex(im.image.ptr(int(r['table'],16)+i*8)+delta)for i in range(2)]==r['targets']
    for r in manifest['block_signatures']:
        descriptor=int(r['descriptor'],16);assert im.image.ptr(descriptor+8)==r['size'];assert im.image.ptr(descriptor+16)==int(r['signature_address'],16);assert im.cstring(int(r['signature_address'],16))==r['signature']
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
    generated=work/'FeedFiltering.mm';llvm=work/'FeedFiltering.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-S','-emit-llvm','-target','arm64-apple-ios13.0','-I',source.parent,generated,'-o',llvm])
    signatures=[s for s in llvm.read_text().splitlines()if s.startswith('define ')and'_logos_method$'in s and'block_invoke'not in s];assert len(signatures)==27
    for h in manifest['registrations']:
        cls=h['class_name'];name='_logos_method$YTLFeedFiltering$'+cls+'$'+h['selector'].replace(':','$')+'P'+str(len(cls));matches=[s for s in signatures if name in s];assert len(matches)==1,(name,matches);sig=matches[0]
        assert re.match(r'define internal (?:noundef )?(?:zeroext )?'+h['llvm_return']+r' ',sig),sig
        args=sig.split('"(',1)[1].split(') #',1)[0].split(', ');assert[a.split()[0]for a in args]==h['llvm_arguments'],sig
    blocks=[s for s in llvm.read_text().splitlines()if s.startswith('define internal ')and'block_invoke'in s];assert len(blocks)==5
    assert sum(s.startswith('define internal zeroext i1 ')for s in blocks)==4;assert sum(s.startswith('define internal void ')for s in blocks)==1
    for sig in blocks:
        args=re.search(r'block_invoke[^ (]*\((.*?)\) #',sig)[1].split(', ');assert [a.split()[0]for a in args]==['ptr','ptr','i64','ptr'],sig
    test=work/'fixture';helper=source.with_name('FeedNodesHelpers.m');fixture=REPO/'recovery/tests/feed_filtering_fixture.mm'
    run(['xcrun','--sdk','macosx','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-I',source.parent,generated,fixture,helper,'-framework','Foundation','-o',test]);run([test,manifest_path])
    files=[source,source.with_name('FeedFilteringHost.h'),manifest_path,fixture,helper,helper.with_suffix('.h'),Path(__file__).resolve()]
    report.write_text(json.dumps(dict(registrations=27,replacements=27,callbacks=5,property_metadata='no changes; before/after runtime property counts checked',ios_abi='27 callback signatures, 5 blocks; see manifest for erased protobuf argument ambiguity',actual_runtime='passed under UBSan; original forwarding, shared helper behavior and Foundation array mutations executed',original_bytes='verified',supplied_binary_executed=False,installer='YTLInstallFeedFilteringHooks',limitations=manifest['limitations'],inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n');print('Feed filtering: 27 registrations and five nested callbacks verified.')
if __name__=='__main__':main()
