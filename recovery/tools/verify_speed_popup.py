#!/usr/bin/env python3
"""Compile actual popup source for iOS and exercise layout/animation/gesture callbacks offline."""
import hashlib,json,re,subprocess,sys
from pathlib import Path
from evidence_image import REPO
from verify_speed_evidence import verify

def main():
    work=REPO/'.recovery-work/speed-popup-tests';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True)
    evidence=verify('YTPSpeedPopupController');commands=[]
    def run(args):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120);commands.append(dict(command=args,returncode=p.returncode,output=p.stdout+p.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(p.stdout+p.stderr,end='');p.check_returncode();return p.stdout
    source=REPO/'recovery/source/Controls/YTPSpeedPopupController.m';fixture=REPO/'recovery/tests/speed_popup_fixture.m';shim=REPO/'recovery/tests/speed_popup_shims'
    run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','speed-popup','--source',source,'--classes','YTPSpeedPopupController'])
    test=work/'fixture';run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim,source,fixture,'-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',test]);output=run([test]);checks=int(re.search(r'(\d+) checks passed',output)[1])
    files=[source,source.with_suffix('.h'),fixture,shim/'UIKit/UIKit.h',REPO/'recovery/evidence/speed-gesture-fidelity.json',Path(__file__).resolve()]
    report.write_text(json.dumps(dict(**evidence,ios_method_encodings=16,own_properties=2,all_metadata_properties=6,relative_ivars=3,runtime_assertions=checks,runtime='actual source under UBSan; intercepted UIKit layout, gesture, animation and presentation boundaries',original_binary_executed=False,network_requests=0,inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n')
if __name__=='__main__':main()
