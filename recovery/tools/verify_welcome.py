#!/usr/bin/env python3
"""Audit WelcomeVC iOS ABI and execute its callbacks against isolated UI doubles."""
import hashlib,json,subprocess
from pathlib import Path
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/welcome-tests';work.mkdir(exist_ok=True,parents=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    calls=[]
    def run(args):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120)
        calls.append({'command':args,'returncode':p.returncode,'output':p.stdout+p.stderr});(work/'commands.json').write_text(json.dumps(calls,indent=2)+'\n');print(p.stdout+p.stderr,end='');p.check_returncode()
    run(['python3','recovery/tools/verify_module_manifest.py','recovery/source/Welcome/manifest.json'])
    run(['python3','recovery/tools/verify_ios_sources.py','--source','recovery/source/Welcome/WelcomeVC.m','--classes','WelcomeVC','--label','welcome'])
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-Wno-objc-protocol-method-implementation','-I','recovery/tests/welcome_shims','-framework','Foundation','-framework','CoreGraphics','recovery/source/Welcome/WelcomeVC.m','recovery/tests/welcome.m','-o',executable])
    run([executable])
    inputs=list((REPO/'recovery/source/Welcome').glob('*.[hm]'))+list((REPO/'recovery/tests/welcome_shims').rglob('*.h'))+[REPO/'recovery/tests/welcome.m',Path(__file__).resolve()]
    report.write_text(json.dumps({'ios_abi':'passed','runtime':'passed','original_binary_executed':False,'device_ui':'not exercised','inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')
if __name__=='__main__':main()
