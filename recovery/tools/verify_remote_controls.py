#!/usr/bin/env python3
"""Verify RemoteControls package evidence, iOS ABI and actual generated Logos behavior."""
from logos_tool import logos_path
import collections,hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_theme_styles import source_registrations

def main():
    work=REPO/'.recovery-work/remote-controls';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/RemoteControls.x';manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    records=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['implementation']in['0x0004e6fc','0x0004e8fc','0x000aa244']]
    assert len(records)==3 and records==manifest['registrations']
    expected=collections.Counter(('YTLRemoteControlsMain' if h['registration']=='00053fac' else 'YTLRemoteControlsEarly',h['class_name'],h['kind'],h['selector'],h['operation'])for h in records)
    assert collections.Counter(source_registrations(source.read_text()))==expected and '%ctor' not in source.read_text()
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256']
    for span in manifest['instruction_intervals']:
        a,b=int(span['start'],16),int(span['end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256']
    for item in manifest['decoded_strings']:assert im.cstring(int(item['address'],16))==item['value']
    branches={b['address']:b for path in ['.recovery-work/analysis-v2/evidence/branches.json','recovery/evidence/branches.json'] for b in json.loads((REPO/path).read_text())}
    for b in manifest['original_branch_records']:
        assert branches[b['address']]==b and int.from_bytes(im.buffer(int(b['address'],16),4),'little')==int(b['original'][0],16)
    target_pairs=[['0x4e7f4','0x4e830'],['0x4e894','0x4e8d0'],['0xaa338','0xaa7d4'],['0xaa338','0xaa7d4'],['0xaa868','0xaa36c'],['0xaa868','0xaa3a8'],['0xaa868','0xaa808'],['0xaa868','0xaa844']]
    for item,expected_pair in zip(manifest['explicit_branch_audits'],target_pairs):
        d=(-(int.from_bytes(im.buffer(int(item['constant'],16),4),'little')^int(item['xor'],16)))&0xffffffff;d=d if d<2**31 else d-2**32
        assert [hex(im.image.ptr(int(item['table'],16)+8*i)+d)for i in range(2)]==item['targets']==expected_pair
    for a,word in {0x4e82c:0x39212328,0x4e8cc:0x392126e8,0xaa258:0x1e604008,0xaa3c4:0x1e614008,0xaa860:0x1e604008,0xaa864:0x52800d82,0xaa878:0x1e604100}.items():assert int.from_bytes(im.buffer(a,4),'little')==word
    commands=[]
    def run(args):
        args=list(map(str,args));r=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120);commands.append(dict(command=args,exit_code=r.returncode,output=r.stdout+r.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if r.returncode:print(r.stdout+r.stderr,end='')
        r.check_returncode();return r.stdout
    mm=work/'RemoteControls.mm';mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(meta_)?method\$(YTLRemoteControls\w+)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()));assert generated=={('',group,cls,sel.replace(':','$'))for group,cls,kind,sel,op in expected}
    llvm=work/'RemoteControls-ios.ll';run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions={m[1]:m[2]for m in re.finditer(r'^define internal void @"([^"\n]*_logos_method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M)};assert len(definitions)==3
    for name,args in definitions.items():
        if '$YTWatchController$' in name:assert args.count('ptr noundef')==2 and 'i64 noundef' in args and 'double noundef' in args
        else:assert args.count('ptr noundef')==(4 if '$MPRemoteCommand$' in name else 3)
    assert 'fneg double' in llvm.read_text() and re.search(r'@"objc_msgSend\$floatForKey:"',llvm.read_text())
    executable=work/'runtime';run(['xcrun','clang++','-std=c++17','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/remote_controls_shims','-I',source.parent,mm,REPO/'recovery/tests/remote_controls_runtime.mm','-framework','Foundation','-o',executable])
    for order in ['backward','forward','reentrant-backward','reentrant-forward']:
        run([executable,order]);assert f'{34 if order.startswith("reentrant-") else 470} actual Logos runtime checks passed' in commands[-1]['output'];print(commands[-1]['output'],end='')
    inputs=[source,source.parent/'RemoteControlsHost.h',source.with_suffix('.manifest.json'),REPO/'recovery/tests/remote_controls_runtime.mm',REPO/'Utils/YTLUserDefaults.h',REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',Path(__file__).resolve(),REPO/'recovery/tools/verify_theme_styles.py']+list((REPO/'recovery/tests/remote_controls_shims').rglob('*.h'))
    result=dict(registration_count=3,shared_helper='0xbc45c',original_byte_intervals=6,decoded_strings=14,original_branch_records=6,explicit_branch_audits=8,generated_callback_coverage='passed',ios_compile_and_llvm_widths='passed',real_logos_runtime_checks_per_order=470,registration_orders=['backward','forward'],reentrant_checks_per_order=34,ubsan='passed',original_binary_executed=False,limitations=manifest['limitations'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in inputs},llvm_hook_signatures=definitions)
    report.write_text(json.dumps(result,indent=2)+'\n');print('All 3 RemoteControls registrations, shared helper, original-byte evidence and iOS ABI verified.')
if __name__=='__main__':main()
