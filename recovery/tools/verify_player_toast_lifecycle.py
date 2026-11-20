#!/usr/bin/env python3
"""Verify PlayerToast lifecycle from original bytes and complete source in isolated UI doubles."""
import hashlib,json,os,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/player-toast-lifecycle';work.mkdir(parents=True,exist_ok=True);(work/'tmp').mkdir(exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True);commands=[];env=dict(os.environ,TMPDIR=str(work/'tmp'),UBSAN_OPTIONS='halt_on_error=1:print_stacktrace=0')
    def run(command):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=command,exit_code=r.returncode,output=r.stdout+r.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(r.stdout+r.stderr,end='',flush=True);r.check_returncode();return r.stdout+r.stderr
    evidence=REPO/'recovery/tests/player_toast_lifecycle_evidence.json';data=json.loads(evidence.read_text());im=EvidenceImage();assert im.sha256==data['binary_sha256']
    methods=next(c['methods'] for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()) if c['name']=='PlayerToast');assert data['methods']==methods and len(methods)==16
    for span in data['spans']:
        a,b=int(span['start'],16),int(span['end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256'],span
    for address,raw in dict(data['words'],**data['constants']).items():assert im.buffer(int(address,16),len(bytes.fromhex(raw))).hex()==raw,address
    for table in data['branch_tables']:
        d=(-(int.from_bytes(im.buffer(int(table['key'],16),4),'little')^int(table['xor'],16)))&0xffffffff
        if d>=0x80000000:d-=1<<32
        assert [hex(im.image.ptr(int(table['address'],16)+8*i)+d) for i in range(2)]==table['targets']
    print(f"PlayerToast original evidence: {len(data['spans'])} complete method/helper spans, {len(data['words'])} key instructions, two branch tables, five data records.")
    source=REPO/'recovery/source/Presentation/PlayerToast.m';test=REPO/'recovery/tests/player_toast_lifecycle_runtime.m';doubles=REPO/'recovery/tests/player_toast_lifecycle_doubles.m';redirects=REPO/'recovery/tests/player_toast_lifecycle_redirects.h';shims=REPO/'recovery/tests/player_toast_lifecycle_shims'
    run(['python3','recovery/tools/verify_ios_sources.py','--source',source,'--classes','PlayerToast','--label','player-toast-lifecycle'])
    executable=work/'runtime';run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,'-include',redirects,source,doubles,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    counts={}
    for mode in ['init','hide','show','source','progress','update']:
        output=run([executable,mode]);counts[mode]=int(re.search(r'PLAYER_TOAST_LIFECYCLE_PASS (\d+) assertions',output)[1])
    inputs=[source,source.with_suffix('.h'),test,doubles,redirects,REPO/'recovery/tests/player_toast_lifecycle_doubles.h',evidence,Path(__file__).resolve(),source.parent/'PresentationGeometry.h',source.parent/'PresentationHost.h',source.parent/'CustomHUD.h']+list(shims.rglob('*.h'))
    report.write_text(json.dumps(dict(runtime_assertions=sum(counts.values()),modes=counts,ios_metadata='passed',ubsan='passed',original_method_spans=len(data['spans']),original_binary_executed=False,whole_player_toast_source=True,scope=data['scope'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}),indent=2)+'\n')
if __name__=='__main__':main()
