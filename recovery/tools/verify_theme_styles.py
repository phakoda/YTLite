#!/usr/bin/env python3
"""Audit original registration/byte evidence and run generated ThemeStyles hooks."""
from logos_tool import logos_path
import collections,hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
NAMES='YTColor NSParagraphStyle UIImageView _ASDisplayView UIView GOODimmingBackgroundView UIKeyboard UIPredictionViewController UIKeyboardDockView UIInputView UIKBVisualEffectView YCHLiveChatView'.split()
def source_registrations(source):
    group=target=None;added=False;result=[]
    for line in source.splitlines():
        line=line.strip()
        if line.startswith('%group '):group=line.split()[1]
        elif line.startswith('%hook '):target=line.split()[1]
        elif line=='%new':added=True
        elif line=='%end':
            if target:target=None
            else:group=None
        elif re.match(r'^[+-]\s*\(',line):
            signature=line.split('{')[0]
            words=re.findall(r'(\w+)\s*:',signature)
            selector=''.join(w+':' for w in words) if words else re.search(r'\)\s*(\w+)\s*$',signature.strip())[1]
            result.append((group,target,line[0],selector,'add' if added else 'replace'));added=False
    return result

def main():
    work=REPO/'.recovery-work/theme-styles';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/ThemeStyles.x'
    manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    records=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['class_name'] in NAMES]
    assert records==manifest['registrations'] and len(records)==24
    expected=collections.Counter(('YTLThemeStyles',h['class_name'],h['kind'],h['selector'],h['operation']) for h in records)
    assert collections.Counter(source_registrations(source.read_text()))==expected
    assert '%ctor' not in source.read_text()
    im=EvidenceImage();assert im.sha256==manifest['binary_sha256']
    for span in manifest['instruction_intervals']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256']
    for item in manifest['decoded_strings']:assert im.cstring(int(item['address'],16))==item['value']
    branches=json.loads((REPO/'recovery/evidence/branches.json').read_text())
    assert all(record in branches for record in manifest['original_branch_records'])
    for item in manifest['explicit_branch_audits']:
        delta=(-(int.from_bytes(im.buffer(int(item['constant'],16),4),'little')^int(item['xor'],16)))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert [hex(im.image.ptr(int(item['table'],16)+8*i)+delta) for i in range(2)]==item['targets']
    commands=[]
    def run(args):
        args=list(map(str,args));r=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=args,exit_code=r.returncode,output=r.stdout+r.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if r.returncode:print(r.stdout+r.stderr,end='')
        r.check_returncode();return r.stdout
    mm=work/'ThemeStyles.mm';mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(meta_)?method\$(YTLThemeStyles)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()))
    assert generated=={('meta_' if kind=='+' else '',group,cls,sel.replace(':','$')) for group,cls,kind,sel,op in expected}
    llvm=work/'ThemeStyles-ios.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions={m[1]:m[2] for m in re.finditer(r'^define internal [^\n]+ @"([^"\n]*_logos_(?:meta_)?method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M) if '_block_invoke' not in m[1]}
    assert len(definitions)==24
    for name,args in definitions.items():
        if '$bgColorForPageStyle$' in name:assert 'i64 noundef' in args
        elif any(s in name for s in ('$setImage$','$setBackgroundColor$','$displayLayer$','$setKeepalive_node$','$savePFP$','$postManager$','$commentManager$','$didTapYtlButton$','$defaultWritingDirectionForLanguage$')):assert args.count('ptr noundef')==3
        else:assert args.count('ptr noundef')==2
    for line in llvm.read_text().splitlines():
        if line.startswith('define internal') and '_logos_meta_method$YTLThemeStyles$NSParagraphStyle$' in line:assert 'define internal i64' in line
    executable=work/'runtime'
    run(['xcrun','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/theme_styles_shims','-I',source.parent,'-include',REPO/'recovery/tests/theme_styles_redirects.h',mm,REPO/'recovery/tests/theme_styles_runtime.mm','-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',executable])
    run([executable]);print(commands[-1]['output'],end='')
    inputs=[source,source.parent/'ThemeStylesHost.h',source.with_suffix('.manifest.json'),REPO/'recovery/tests/theme_styles_redirects.h',REPO/'recovery/tests/theme_styles_runtime.mm',Path(__file__).resolve()]+list((REPO/'recovery/tests/theme_styles_shims').rglob('*.h'))
    result=dict(registration_count=24,original_byte_intervals=len(manifest['instruction_intervals']),decoded_strings=len(manifest['decoded_strings']),original_branches=len(manifest['original_branch_records']),generated_callback_coverage='passed',ios_compile_and_llvm_widths='passed',real_logos_runtime='passed',ubsan='passed',original_binary_executed=False,limitations=manifest['limitations'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs},llvm_hook_signatures=definitions)
    report.write_text(json.dumps(result,indent=2)+'\n')
    print('All 24 registrations, original-byte evidence and iOS ABI verified.')
if __name__=='__main__':main()
