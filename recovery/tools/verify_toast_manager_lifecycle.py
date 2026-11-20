#!/usr/bin/env python3
"""Check original ToastManager operations and run the entire reconstructed source."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
from evidence_image import EvidenceImage, REPO

def main():
    image = EvidenceImage()
    work = REPO / '.recovery-work/toast-manager-lifecycle'
    work.mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    source = REPO / 'recovery/source/Presentation/ToastManager.m'
    fixture = REPO / 'recovery/tests/toast_manager_lifecycle_fixture.m'
    redirects = REPO / 'recovery/tests/toast_manager_lifecycle_redirects.h'
    shim = REPO / 'recovery/tests/factory_audit_shims'
    files=[source,source.with_suffix('.h'),fixture,redirects,Path(__file__).resolve(),*shim.rglob('*.h'),
           source.with_name('ToastView.h'),source.with_name('ToastWindow.h'),source.with_name('PresentationHost.h')]
    def hashes():return {str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    before=hashes()
    commands = []
    def run(args):
        args = list(map(str,args))
        result = subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        commands.append(dict(command=args,returncode=result.returncode,output=result.stdout+result.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(result.stdout+result.stderr,end='',flush=True)
        result.check_returncode()
    calls = {0x1c9cb8:'_objc_alloc_init',0x1c9d48:'_dispatch_async',
             0x1c9e20:'_objc_sync_enter',0x1c9e8c:'_objc_sync_exit',
             0x1c9f5c:'_objc_sync_enter',0x1c9f88:'_objc_sync_exit',
             0x1ca024:'_objc_sync_enter',0x1ca12c:'_objc_enumerationMutation',0x1ca1fc:'_objc_sync_exit'}
    for address, name in calls.items():
        word=image.image.u32(image.image.off(address))
        assert word & 0xfc000000 == 0x94000000
        delta=word & 0x3ffffff
        if delta & 0x2000000: delta-=0x4000000
        assert image.terminal(address+delta*4)==name
    assert image.image.u32(image.image.off(0x1c9d80))==0xa9420808
    original=next(c for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()) if c['name']=='ToastManager')
    spans=[]
    for start in sorted({int(m['address'],16) for m in original['methods']}|{0x1c9ba4,0x1c9d80}):
        end=min(a for a in image.image.function_starts if a>start)
        spans.append(dict(start=hex(start),end=hex(end),sha256=hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()))
    run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--source',source,'--classes','ToastManager','--label','toast-manager-lifecycle'])
    flags=['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim]
    ir=work/'source.ll'
    run(flags+['-include',redirects,'-S','-emit-llvm',source,'-o',ir])
    raw=ir.read_text()
    # Intercept only compiler-generated lock boundaries, leaving source logic intact.
    rewritten=raw.replace('@objc_sync_enter(', '@YTLManagerSyncEnter(').replace('@objc_sync_exit(', '@YTLManagerSyncExit(')
    assert raw != rewritten
    redirected=work/'source-lock-boundaries.ll'; redirected.write_text(rewritten)
    executable=work/'fixture'
    run(flags+[redirected,fixture,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable])
    checks=int(re.search(r'(\d+) checks passed',commands[-1]['output'])[1])
    assert hashes()==before, 'Inputs changed during verification; rerun after edits finish.'
    report.write_text(json.dumps(dict(runtime_assertions=checks,original_binary_executed=False,binary_sha256=image.sha256,
        original_spans=spans,original_calls={hex(a):n for a,n in calls.items()},
        whole_actual_source=True,ubsan='passed',ios_abi='all 15 methods, 4 properties and 4 relative ivars',
        boundaries='Synthetic ToastView/UI, captured main-queue blocks, compiler-generated lock calls redirected in emitted LLVM IR; no system runtime interposition.',
        source_sha256=before),indent=2)+'\n')

if __name__=='__main__':main()
