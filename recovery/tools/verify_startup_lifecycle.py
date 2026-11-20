#!/usr/bin/env python3
"""Verify StartupLifecycle original evidence and execute generated Logos with intercepted effects."""
from logos_tool import logos_path
import collections,hashlib,json,re,struct,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_theme_styles import source_registrations

def main():
    work=REPO/'.recovery-work/startup-lifecycle';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/StartupLifecycle.x';manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    addresses={0x51d7c,0x52438,0x526dc,0x53748,0x65fbc,0xbb9ec}
    records=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text())if h['implementation']in{f'0x{a:08x}'for a in addresses}];assert len(records)==6 and records==manifest['registrations']
    expected=collections.Counter(('YTLStartupLifecycleMain'if h['registration']=='00053fac'else'YTLStartupLifecycleEarly',h['class_name'],h['kind'],h['selector'],h['operation'])for h in records)
    assert collections.Counter(source_registrations(source.read_text()))==expected and '%ctor' not in source.read_text()
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256']
    for span in manifest['instruction_intervals']:
        a,b=int(span['start'],16),int(span['end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256']
    for item in manifest['decoded_strings']:assert im.cstring(int(item['address'],16))==item['value']
    branches={b['address']:b for path in ['.recovery-work/analysis-v2/evidence/branches.json','recovery/evidence/branches.json']for b in json.loads((REPO/path).read_text())}
    for b in manifest['original_branch_records']:assert branches[b['address']]==b and int.from_bytes(im.buffer(int(b['address'],16),4),'little')==int(b['original'][0],16)
    for item in manifest['explicit_branch_audits']:
        d=(-(int.from_bytes(im.buffer(int(item['constant'],16),4),'little')^int(item['xor'],16)))&0xffffffff;d=d if d<2**31 else d-2**32
        assert [hex(im.image.ptr(int(item['table'],16)+8*i)+d)for i in range(2)]==item['targets']
    for item in manifest['block_metadata']:
        if 'invoke'in item:assert hex(im.image.ptr(int(item['address'],16)+16))==item['invoke']
        else:
            a=int(item['descriptor'],16);assert im.image.ptr(a+8)==item['size'] and hex(im.image.ptr(a+16))==item['copy'] and hex(im.image.ptr(a+24))==item['dispose']
    for item in manifest['constants']:assert struct.unpack('<d',im.buffer(int(item['address'],16),8))[0]==item['value']==0.2
    # Both language checks use unsigned LO; nil clipboard-open failure skips clearing.
    assert int.from_bytes(im.buffer(0x65e64,4),'little')==0x1a9f27f7
    assert int.from_bytes(im.buffer(0x65f04,4),'little')==0x1a9f27f4
    completion=next(x for x in manifest['explicit_branch_audits']if x['branch']=='0xcf8ac');assert completion['targets']==['0xcf8e8','0xcf8b0']
    commands=[]
    def run(args):
        args=list(map(str,args));r=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120);commands.append(dict(command=args,exit_code=r.returncode,output=r.stdout+r.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if r.returncode:print(r.stdout+r.stderr,end='')
        r.check_returncode();return r.stdout
    mm=work/'StartupLifecycle.mm';mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(meta_)?method\$(YTLStartupLifecycle\w+)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()));assert generated=={('meta_'if kind=='+'else'',group,cls,sel.replace(':','$'))for group,cls,kind,sel,op in expected}
    llvm=work/'StartupLifecycle-ios.ll';run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions={m[1]:m[2]for m in re.finditer(r'^define internal [^\n]+ @"([^"\n]*_logos_(?:meta_)?method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M)if '_block_invoke'not in m[1]};assert len(definitions)==6
    for name,args in definitions.items():assert args.count('ptr noundef')==(4 if '$application$'in name or '$QTMIcon$'in name else 2)
    for line in llvm.read_text().splitlines():
        if line.startswith('define internal')and '_block_invoke'not in line:
            if '$application$'in line:assert line.startswith('define internal zeroext i1 ')
            if '$QTMIcon$'in line:assert line.startswith('define internal ptr ')
    block_definitions=[line for line in llvm.read_text().splitlines()if line.startswith('define internal void')and '_block_invoke' in line];assert len(block_definitions)==9
    assert re.search(r'@"objc_msgSend\$setOpacity:"\([^\n]*float noundef',llvm.read_text())
    assert 'objc.storeWeak'not in llvm.read_text() and 'objc.initWeak'not in llvm.read_text()
    executable=work/'runtime';run(['xcrun','clang++','-std=c++17','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/startup_lifecycle_shims','-I',source.parent,'-include',REPO/'recovery/tests/startup_lifecycle_redirects.h',mm,REPO/'recovery/tests/startup_lifecycle_runtime.mm','-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',executable]);run([executable]);assert '387 actual Logos runtime checks passed'in commands[-1]['output'];print(commands[-1]['output'],end='')
    inputs=[source,source.parent/'StartupLifecycleHost.h',source.with_suffix('.manifest.json'),REPO/'recovery/tests/startup_lifecycle_runtime.mm',REPO/'recovery/tests/startup_lifecycle_redirects.h',REPO/'Utils/YTLUserDefaults.h',REPO/'Utils/NSBundle+YTLite.h',REPO/'recovery/source/Support/YTPDB.h',REPO/'recovery/source/Downloads/YTPMedia.h',REPO/'recovery/source/Presentation/ToastView.h',REPO/'recovery/source/Welcome/WelcomeVC.h',Path(__file__).resolve(),REPO/'recovery/tools/verify_theme_styles.py']+list((REPO/'recovery/tests/startup_lifecycle_shims').rglob('*.h'))
    result=dict(registration_count=6,original_byte_intervals=len(manifest['instruction_intervals']),decoded_strings=len(manifest['decoded_strings']),original_branch_records=len(manifest['original_branch_records']),explicit_branch_audits=len(manifest['explicit_branch_audits']),generated_callback_coverage='passed',ios_compile_and_llvm_widths='passed',block_invokes=9,real_logos_runtime_checks=387,ubsan='passed',original_binary_executed=False,constructor_scope=manifest['constructor_scope'],limitations=manifest['limitations'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in inputs},llvm_hook_signatures=definitions)
    report.write_text(json.dumps(result,indent=2)+'\n');print('All 6 StartupLifecycle hooks, ordinary welcome/defaults side effects, original evidence and iOS ABI verified.')
if __name__=='__main__':main()
