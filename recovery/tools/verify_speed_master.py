#!/usr/bin/env python3
"""Verify raw pending-rate initializer and actual YTPSpeedMaster first-use behavior."""
import hashlib,json,subprocess,sys,re
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_speed_evidence import verify

def main():
    work=REPO/'.recovery-work/speed-master-tests';work.mkdir(exist_ok=True,parents=True);report=work/'report.json';report.unlink(missing_ok=True);im=EvidenceImage();evidence=verify('YTPSpeedMaster')
    assert im.image.u32(im.image.off(0x223924))==0xf9401000  # captured receiver at block +0x20
    assert im.image.u32(im.image.off(0x223928))==0x94000c52
    assert im.terminal(0x226a70)=='_objc_alloc_init'
    raw=im.image.data[im.image.off(0x11ce3e0):im.image.off(0x11ce3e0)+8];assert raw.hex()=='000000000000f03f'
    load=im.image.data[im.image.off(0x2268f8):im.image.off(0x226908)];assert load.hex()=='487d009008810f9108fddfc80801679e'
    source=REPO/'recovery/source/Controls/YTPSpeedMaster.m';fixture=REPO/'recovery/tests/speed_master_fixture.m';shim=REPO/'recovery/tests/speed_master_shims';commands=[]
    def run(args):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120);commands.append(dict(command=args,returncode=p.returncode,output=p.stdout+p.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(p.stdout+p.stderr,end='');p.check_returncode();return p.stdout
    run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','speed-master','--source',source,'--classes','YTPSpeedMaster'])
    test=work/'fixture';run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-Wno-unused-parameter','-fsanitize=undefined','-I',shim,source,fixture,'-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',test]);output=run([test]);checks=int(re.search(r'(\d+) checks passed',output)[1])
    files=[source,source.with_suffix('.h'),source.with_suffix('.provenance.md'),source.with_name('ControlsHost.h'),source.with_name('ControlsNumbers.h'),fixture,REPO/'recovery/evidence/speed-gesture-fidelity.json',Path(__file__).resolve()]+list(shim.rglob('*.h'))
    report.write_text(json.dumps(dict(**evidence,runtime_assertions=checks,singleton_factory={'block':'0x22391c','receiver_load':'0x223924','call':'0x223928','terminal':'_objc_alloc_init','runtime':'subclass-first, +new override not invoked, init exactly once, shared identity across subclass and base'},raw_initial_global={'address':'0x11ce3e0','raw_bytes':raw.hex(),'type':'double','value':1.0,'uses_decoded_overlay':False},original_load={'address':'0x2268f8','bytes':load.hex(),'operations':'ADRP 0x11ce000; ADD 0x3e0; LDAR x8; FMOV d8,x8'},ios_method_metadata='all 12 YTPSpeedMaster methods verified',actual_source_runtime='Actual source passed under UBSan; rate model first-use and gesture rounding, state transitions, preference rereads and deferred reset capture.',inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n')
if __name__=='__main__':main()
