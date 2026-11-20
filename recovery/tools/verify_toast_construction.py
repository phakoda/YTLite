#!/usr/bin/env python3
"""Run actual ToastView startup, queue and reusable UI setup with synthetic UIKit."""
import argparse, hashlib, json, os, re, subprocess, sys
from pathlib import Path
from evidence_image import EvidenceImage, REPO

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--before',action='store_true',help='Exercise retained preceding source for regression evidence')
    parser.add_argument('--mode',choices=['active','fallback','empty','background','notifications','configure'])
    args=parser.parse_args()
    image=EvidenceImage();work=REPO/'.recovery-work/toast-construction';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';commands=[]
    if not args.before:report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Presentation/ToastView.m'
    compiled=work/'before-ToastView.m' if args.before else source
    fixture=REPO/'recovery/tests/toast_construction_fixture.m'
    doubles=REPO/'recovery/tests/presentation_doubles.m'
    shim=REPO/'recovery/tests/presentation_shims'
    redirects=REPO/'recovery/tests/toast_construction_redirects.h'
    manager=source.with_name('ToastManager.m')
    files=[source,source.with_suffix('.h'),manager,manager.with_suffix('.h'),fixture,redirects,doubles,doubles.with_suffix('.h'),Path(__file__).resolve(),
           source.with_name('ToastWindow.h'),source.with_name('PresentationHost.h'),source.with_name('PresentationGeometry.h'),REPO/'recovery/tests/presentation_redirects.h',*shim.rglob('*.h')]
    def hashes():return {str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    before=hashes()
    env=os.environ.copy();tmp=REPO/'.recovery-work/presentation-helpers/toast-construction/tmp';tmp.mkdir(parents=True,exist_ok=True);env['TMPDIR']=str(tmp)
    def run(command):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,capture_output=True,text=True,timeout=120)
        commands.append(dict(command=command,returncode=r.returncode,output=r.stdout+r.stderr))
        (work/(f'red-{args.mode or "initial"}-commands.json' if args.before else 'commands.json')).write_text(json.dumps(commands,indent=2)+'\n')
        print(r.stdout+r.stderr,end='',flush=True);r.check_returncode()
    if not args.before:run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--source',source,'--classes','ToastView','--label','toast-construction'])
    assert image.image.ptr(0x1062a00+16)==0x1b9e8c
    assert image.image.ptr(0x1062a20+16)==0x1ba69c
    spans=[]
    for start in [0x1b9d50,0x1b9e04,0x1b9e8c,0x1ba69c,0x1ba6d8,0x1bbd94,0x1bbe2c,0x1bbf68,0x1bfcdc,
                  0x1bf368,0x1bf6d4,0x1bfa0c,0x1bfba0,0x1bfc9c,0x1bee14,0x1befa0,0x1bf098,0x1bf1f4,0x1bf2e4]:
        end=min(a for a in image.image.function_starts if a>start)
        spans.append(dict(start=hex(start),end=hex(end),sha256=hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()))
    executable=work/('before-fixture' if args.before else 'fixture')
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation',
         '-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim,'-I',source.parent,'-include',redirects,
         compiled,manager,doubles,fixture,'-framework','Foundation','-framework','CoreGraphics','-framework','SystemConfiguration','-o',executable])
    count=0
    for mode in ([args.mode] if args.mode else ['active','fallback','empty','background','notifications','configure']):
        run([executable,mode]);count+=int(re.search(r'(\d+) checks passed',commands[-1]['output'])[1])
    if args.before:return
    assert hashes()==before, 'Inputs changed during verification; rerun after edits finish.'
    report.write_text(json.dumps(dict(runtime_assertions=count,whole_actual_source=True,ubsan='passed',original_binary_executed=False,
        binary_sha256=image.sha256,original_spans=spans,limits='Synthetic UIKit, scene and event-loop boundaries; no device UI or original binary execution.',
        source_sha256=before),indent=2)+'\n')

if __name__=='__main__':main()
