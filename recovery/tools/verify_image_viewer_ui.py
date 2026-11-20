#!/usr/bin/env python3
"""Check original image-viewer evidence and execute its whole source offline."""
import hashlib,json,os,re,struct,subprocess
from pathlib import Path
from evidence_image import EvidenceImage
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/image-viewer-ui';work.mkdir(parents=True,exist_ok=True);(work/'tmp').mkdir(exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True);commands=[]
    env=dict(os.environ,TMPDIR=str(work/'tmp'),UBSAN_OPTIONS='halt_on_error=1:print_stacktrace=0')
    def run(command):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append(dict(command=command,exit_code=r.returncode,output=r.stdout+r.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(r.stdout+r.stderr,end='',flush=True);r.check_returncode();return r.stdout+r.stderr
    evidence=REPO/'recovery/tests/image_viewer_ui_evidence.json';e=json.loads(evidence.read_text());im=EvidenceImage();assert im.sha256==e['binary_sha256']
    methods=next(c['methods'] for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()) if c['name']=='DVNImageViewController');assert e['methods']==methods and len(methods)==18
    for s in e['spans']:
        a,b=int(s['start'],16),int(s['end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(a)+b-a]).hexdigest()==s['sha256'],s
    for d in e['data']:
        a,n=int(d['address'],16),d['length'];assert im.image.data[im.image.off(a):im.image.off(a)+n].hex()==d['raw_hex'];assert im.buffer(a,n).hex()==d['decoded_hex']
    for s in e['selectors']:
        assert im.image.ptr(int(s['ref'],16))==int(s['target'],16);assert im.cstring(int(s['target'],16))==s['selector']
    for b in e['branches']:
        t,k,x=(int(b[f],16) for f in ('table','key_address','xor'));key=struct.unpack('<I',im.buffer(k,4))[0];assert key==int(b['key'],16);delta=(-(key^x))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert [hex(im.image.ptr(t+i*8)+delta) for i in range(2)]==b['targets_false_true']
    print(f"Image viewer original evidence: {len(e['spans'])} complete method/helper spans, 8 data records, 3 selectors, 4 branch tables.")
    source=REPO/'recovery/source/Presentation/DVNImageViewController.m';test=REPO/'recovery/tests/image_viewer_ui_runtime.m';doubles=REPO/'recovery/tests/image_viewer_ui_doubles.m';redirects=REPO/'recovery/tests/image_viewer_ui_redirects.h';shims=REPO/'recovery/tests/image_viewer_ui_shims'
    run(['python3','recovery/tools/verify_ios_sources.py','--source',source,'--classes','DVNImageViewController','--label','image-viewer-ui'])
    executable=work/'runtime';run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,'-include',redirects,source,doubles,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    counts={}
    for mode in ['menu','navbar','share','geometry','setup','base']:
        output=run([executable,mode]);counts[mode]=int(re.search(r'IMAGE_VIEWER_UI_PASS (\d+) assertions',output)[1])
    inputs=[source,source.with_suffix('.h'),test,doubles,redirects,REPO/'recovery/tests/image_viewer_ui_doubles.h',evidence,Path(__file__).resolve(),source.parent/'PresentationGeometry.h',source.parent/'PresentationHost.h',source.parent/'BlurButton.h']+sorted(shims.rglob('*.h'))
    report.write_text(json.dumps(dict(runtime_assertions=sum(counts.values()),modes=counts,ios_metadata='passed',ubsan='passed',original_method_spans=len(e['spans']),original_binary_executed=False,whole_image_viewer_source=True,scope=e['scope'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}),indent=2)+'\n')
if __name__=='__main__':main()
