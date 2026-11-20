#!/usr/bin/env python3
"""Verify packaged CompatibilityVersion evidence and execute generated Logos hooks."""
from logos_tool import logos_path
import collections,hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_theme_styles import source_registrations

def main():
    work=REPO/'.recovery-work/compatibility-version';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/CompatibilityVersion.x'
    manifest=json.loads(source.with_suffix('.manifest.json').read_text())
    records=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['registration']=='0000c554']
    assert len(records)==7 and records==manifest['registrations']
    resolved=[dict(h) for h in records];resolved[0].update(class_name='YTIIcon',kind='-',complete=True)
    assert resolved==manifest['resolved_registrations']
    assert manifest['resolutions'][0]['original_inventory_row']==records[0]
    assert manifest['resolutions'][0]['source_owner']==str(source.relative_to(REPO))
    expected=collections.Counter(('YTLCompatibilityVersion',h['class_name'],h['kind'],h['selector'],h['operation']) for h in resolved)
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
    mm=work/'CompatibilityVersion.mm';mm.write_text(run(['perl',logos_path(),'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(meta_)?method\$(YTLCompatibilityVersion)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()))
    assert generated=={('meta_' if kind=='+' else '',group,cls,sel.replace(':','$')) for group,cls,kind,sel,op in expected}
    llvm=work/'CompatibilityVersion-ios.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    definitions={m[1]:m[2] for m in re.finditer(r'^define internal [^\n]+ @"([^"\n]*_logos_(?:meta_)?method\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M) if '_block_invoke' not in m[1]}
    assert len(definitions)==7
    for name,args in definitions.items():
        count=5 if '$YTELMResourceLoader$' in name else 4 if '$QTMIcon$' in name else 3 if '$YTSettingsCell$' in name else 2
        assert args.count('ptr noundef')==count,(name,args)
    icon_lines=[line for line in llvm.read_text().splitlines() if line.startswith('define internal') and '_logos_method$YTLCompatibilityVersion$YTIIcon$' in line]
    assert len(icon_lines)==1 and re.match(r'define internal (?:noundef )?i32 ',icon_lines[0])
    executable=work/'runtime'
    run(['xcrun','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/compatibility_version_shims','-I',source.parent,'-include',REPO/'recovery/tests/compatibility_version_redirects.h',mm,REPO/'recovery/tests/compatibility_version_runtime.mm','-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',executable])
    cases=[]
    for version,enabled in [('20.21.5',True),('nil',False),('20.21.6',False),('20.21.7',False),('20.100.1',False),('20.9.99',True),('20.21.06',False),('',True)]:
        run([executable,version,'yes' if enabled else 'no'])
        output=commands[-1]['output'];count=int(re.search(r'(\d+) (?:real Logos runtime )?checks passed',output)[1]);assert count==(172 if enabled else 11)
        cases.append(dict(version=version,installed=enabled,checks=count));print(output,end='')
    inputs=[source,source.parent/'CompatibilityVersionHost.h',source.with_suffix('.manifest.json'),REPO/'recovery/tests/compatibility_version_redirects.h',REPO/'recovery/tests/compatibility_version_runtime.mm',REPO/'Utils/NSBundle+YTLite.h',Path(__file__).resolve(),REPO/'recovery/tools/verify_theme_styles.py']+list((REPO/'recovery/tests/compatibility_version_shims').rglob('*.h'))
    result=dict(registration_count=7,resolved_registrations=resolved,original_byte_intervals=len(manifest['instruction_intervals']),decoded_strings=len(manifest['decoded_strings']),original_branches=len(manifest['original_branch_records']),explicit_branch_audits=len(manifest['explicit_branch_audits']),generated_callback_coverage='passed',ios_compile_and_llvm_widths='passed',real_logos_runtime='passed',ubsan='passed',version_gate_cases=cases,original_binary_executed=False,limitations=manifest['limitations'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs},llvm_hook_signatures=definitions)
    report.write_text(json.dumps(result,indent=2)+'\n')
    print('All 7 registrations, original-byte evidence, 8 version gates and iOS ABI verified.')
if __name__=='__main__':main()
