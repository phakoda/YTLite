#!/usr/bin/env python3
"""Audit NativeShare original evidence and execute the generated Logos implementation."""
from logos_tool import logos_path
import collections,hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_theme_styles import source_registrations

def main():
    work=REPO/'.recovery-work/native-share';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/NativeShare.x';manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    records=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['registration']=='000f0c4c']
    assert len(records)==2 and records==manifest['registrations']
    expected=collections.Counter(('YTLNativeShare',h['class_name'],h['kind'],h['selector'],h['operation']) for h in records)
    assert collections.Counter(source_registrations(source.read_text()))==expected
    assert '%ctor' not in source.read_text() and 'SPDX-License-Identifier: GPL-3.0-or-later' in source.read_text()
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256']
    for span in manifest['instruction_intervals']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256']
    for item in manifest['decoded_strings']:assert im.cstring(int(item['address'],16))==item['value']
    branches={b['address']:b for path in ['.recovery-work/analysis-v2/evidence/branches.json','recovery/evidence/branches.json'] for b in json.loads((REPO/path).read_text())}
    for b in manifest['original_branch_records']:
        assert branches[b['address']]==b
        assert int.from_bytes(im.buffer(int(b['address'],16),4),'little')==int(b['original'][0],16)
    for item in manifest['explicit_branch_audits']:
        delta=(-(int.from_bytes(im.buffer(int(item['constant'],16),4),'little')^int(item['xor'],16)))&0xffffffff
        if delta>=2**31:delta-=2**32
        targets=[hex(im.image.ptr(int(item['table'],16)+8*i)+delta) for i in range(2)]
        assert targets==item['targets'] and set(targets)==set(branches[item['branch']]['targets'])
    # Entry wrappers receive two pointer arguments unchanged, then normalize the helper's w0.
    for start in [0xf4aec,0xf4c38]:assert int.from_bytes(im.buffer(start+8,4),'little')==0x12000000
    # CGRect components: original source rect setter receives x=width*.5,y=height,w=0,h=0.
    for address,word in {0xf3ee0:0x1e604048,0xf3f10:0x1e604069,0xf3f1c:0x1e6c1000,0xf3f20:0x1e600908,0xf3f44:0x9e6703e2,0xf3f48:0x9e6703e3,0xf3f4c:0x1e604100,0xf3f50:0x1e604121}.items():assert int.from_bytes(im.buffer(address,4),'little')==word
    commands=[]
    def run(args):
        args=list(map(str,args));r=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=args,exit_code=r.returncode,output=r.stdout+r.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if r.returncode:print(r.stdout+r.stderr,end='')
        r.check_returncode();return r.stdout
    mm=work/'NativeShare.mm';mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(meta_)?method\$(YTLNativeShare)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()))
    assert generated=={('meta_' if kind=='+' else '',group,cls,sel.replace(':','$')) for group,cls,kind,sel,op in expected}
    llvm=work/'NativeShare-ios.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions={m[1]:m[2] for m in re.finditer(r'^define internal void @"([^"\n]*_logos_method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M)}
    assert len(definitions)==2
    for name,args in definitions.items():assert args.count('ptr noundef')==(4 if '$ELMPBShowActionSheetCommand$' in name else 6)
    helper=[line for line in llvm.read_text().splitlines() if line.startswith('define internal') and '@_ZL21YTLPresentNativeShare' in line]
    assert len(helper)==1 and 'i1 ' in helper[0] and helper[0].count('ptr noundef')==2
    assert re.search(r'@"objc_msgSend\$setSourceRect:"\(ptr noundef %\d+, ptr noundef undef, \[4 x double\]',llvm.read_text())
    executable=work/'runtime'
    run(['xcrun','clang++','-std=c++17','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/native_share_shims','-I',source.parent,'-include',REPO/'recovery/tests/native_share_redirects.h',mm,REPO/'recovery/tests/native_share_runtime.mm','-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable]);output=commands[-1]['output'];assert '396 actual Logos runtime checks passed' in output;print(output,end='')
    inputs=[source,source.parent/'NativeShareHost.h',source.with_suffix('.manifest.json'),REPO/'recovery/tests/native_share_redirects.h',REPO/'recovery/tests/native_share_runtime.mm',Path(__file__).resolve(),REPO/'recovery/tools/verify_theme_styles.py']+list((REPO/'recovery/tests/native_share_shims').rglob('*.h'))
    result=dict(registration_count=2,helper='0xf1fbc',original_byte_intervals=len(manifest['instruction_intervals']),decoded_strings=len(manifest['decoded_strings']),original_branches=len(manifest['original_branch_records']),explicit_branch_audits=len(manifest['explicit_branch_audits']),generated_callback_coverage='passed',ios_compile_and_llvm_widths='passed',real_logos_runtime_checks=396,ubsan='passed',original_binary_executed=False,limitations=manifest['limitations'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs},llvm_hook_signatures=definitions,llvm_helper_signature=helper[0])
    report.write_text(json.dumps(result,indent=2)+'\n');print('All 2 NativeShare registrations, shared helper, original-byte evidence and iOS ABI verified.')
if __name__=='__main__':main()
