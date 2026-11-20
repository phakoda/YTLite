#!/usr/bin/env python3
"""Verify original floating instructions and execute the whole speed-control view."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

from evidence_image import EvidenceImage, REPO


def main():
    image=EvidenceImage()
    work=REPO/'.recovery-work/speed-control-tests'
    work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json'
    report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Controls/YTPSpeedControlView.m'
    fixture=REPO/'recovery/tests/speed_control_fixture.m'
    shim=REPO/'recovery/tests/speed_control_shims'
    # Unlike the older decompiler's integer casts, these original opcodes
    # distinguish FRINTA from FCVTZS and preserve FCSEL operand order.
    instructions={0x238368:0xf00078a8,0x23836c:0xf9401900,0x239b24:0x1e211800,0x239b28:0x1e264000,0x239b2c:0x1e200828,
                  0x239c20:0x1f002140,0x239c34:0x1e264000,
                  0x239ce4:0x1e202100,0x239ce8:0x1e284c00,0x239cf0:0x1e264000,
                  0x239d98:0x1e202100,0x239d9c:0x1e204d00,0x239da4:0x1e264000,
                  0x239a34:0x1e200900,0x239a38:0x9e380002}
    for address,word in instructions.items():
        assert image.image.u32(image.image.off(address))==word,hex(address)
    original=next(c for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text()) if c['name']=='YTPSpeedControlView')
    spans=[]
    for start in sorted({int(m['address'],16) for m in original['methods']}|{0x239344}):
        end=min(a for a in image.image.function_starts if a>start)
        spans.append({'start':hex(start),'end':hex(end),'sha256':hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()})
    assert image.image.ptr(0x1063290+16)==0x239344
    assert image.cfstring(0x11d2150)=='%.2fx'
    commands=[]
    def run(args):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        commands.append({'command':args,'returncode':p.returncode,'output':p.stdout+p.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(p.stdout+p.stderr,end='',flush=True);p.check_returncode()
    run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','speed-control','--source',source,'--classes','YTPSpeedControlView'])
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim,source,fixture,'-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',executable])
    run([executable])
    checks = int(re.search(r'(\d+) actual-source assertions passed', commands[-1]['output'])[1])
    files=[source,source.with_suffix('.h'),source.with_name('ControlsNumbers.h'),fixture,Path(__file__).resolve(),*shim.rglob('*.h')]
    result={'binary_sha256':image.sha256,'original_instruction_intervals':spans,'critical_instructions':{hex(a):f'{w:08x}' for a,w in instructions.items()},
            'actual_source_runtime':'passed under UBSan','runtime_assertions':checks,'ios_method_metadata':'all 12 methods and relative ivar layouts verified',
            'arithmetic_oracles':'Isolated newly compiled ARM64 arithmetic instructions; no packaged code is loaded or executed.',
            'ui_boundary':'Synthetic UIKit objects retain action targets weakly and record forwarded slider values without claiming UIKit clamping semantics; CoreGraphics draws the actual thumb block.',
            'original_binary_executed':False,'inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}}
    report.write_text(json.dumps(result,indent=2)+'\n')


if __name__=='__main__':main()
