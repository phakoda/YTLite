#!/usr/bin/env python3
"""Verify actual TranslatorVC source with isolated UIKit, translation and queue boundaries."""
import hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/translator-ui';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True);commands=[]
    def run(args):
        args=list(map(str,args));r=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append({'command':args,'exit_code':r.returncode,'output':r.stdout+r.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(r.stdout+r.stderr,end='',flush=True);r.check_returncode()
    source=REPO/'recovery/source/Subtitles/TranslatorVC.m';test=REPO/'recovery/tests/translator_ui_runtime.m'
    evidence=REPO/'recovery/tests/translator_ui_evidence.json'
    data=json.loads(evidence.read_text());image=EvidenceImage()
    assert data['binary_sha256']==image.sha256
    packaged=next(c for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()) if c['name']=='TranslatorVC')
    assert data['methods']==packaged['methods'] and len(data['methods'])==15
    for span in data['spans']:
        a=int(span['start'],16);size=int(span['end'],16)-a
        assert hashlib.sha256(image.image.data[image.image.off(a):image.image.off(a)+size]).hexdigest()==span['sha256'],span
    for address,raw in data['data_bytes'].items():assert image.buffer(int(address,16),len(bytes.fromhex(raw))).hex()==raw,address
    for address,value in data['decoded_cstrings'].items():assert image.cstring(int(address,16))==value,address
    branches={b['address']:b for b in data['original_branch_records']}
    for address,branch in branches.items():
        original=b''.join(int(word,16).to_bytes(4,'little') for word in branch['original'])
        offset=image.image.off(int(address,16))
        assert image.image.data[offset:offset+len(original)]==original,address
    assert len(branches)==len(data['branch_tables'])==20
    for table in data['branch_tables']:
        delta=(-(int.from_bytes(image.buffer(int(table['key'],16),4),'little')^int(table['xor'],16)))&0xffffffff
        if delta>=0x80000000:delta-=0x100000000
        targets=[hex(image.image.ptr(int(table['table'],16)+8*i)+delta) for i in range(2)]
        assert targets==table['destinations'] and set(targets)==set(branches[table['branch']]['targets']),table
    print(f"Original evidence: {len(data['spans'])} method/callback spans, {len(data['data_bytes'])} data records, 20 branch tables, {len(data['decoded_cstrings'])} decoded strings.")
    run(['python3','recovery/tools/verify_ios_sources.py','--source',source,'--classes','TranslatorVC','--label','translator-ui'])
    executable=work/'runtime'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/translator_ui_shims','-include',REPO/'recovery/tests/translator_ui_redirects.h',source,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable])
    checks=int(re.search(r"TRANSLATOR_UI_RUNTIME_PASS (\d+) assertions",commands[-1]["output"])[1])
    inputs=[source,source.with_suffix('.h'),test,Path(__file__).resolve(),REPO/'recovery/tests/translator_ui_redirects.h',evidence]+list((REPO/'recovery/tests/translator_ui_shims').rglob('*.h'))
    report.write_text(json.dumps({'runtime_assertions':checks,'original_method_count':15,'original_spans':len(data['spans']),'original_branch_tables':20,'original_decoded_strings':len(data['decoded_cstrings']),'ios_metadata':'passed','real_source_runtime':'passed','ubsan':'passed','actual_device_ui':'not tested','original_binary_executed':False,'source_sha256':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs if p.exists()}},indent=2)+'\n')
if __name__=='__main__':main()
