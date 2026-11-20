#!/usr/bin/env python3
"""Run actual constructor scheduling with isolated installer boundaries."""
import hashlib
import os
import json
import subprocess
from pathlib import Path
from evidence_image import REPO


def main():
    work=REPO/'.recovery-work/hook-entrypoints-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Runtime/YTLHookEntrypoints.m'
    fixture=REPO/'recovery/tests/hook_entrypoints_fixture.m'
    redirects=REPO/'recovery/tests/hook_entrypoints_redirects.h'
    commands=[]
    def run(args, environment=None):
        args=list(map(str,args));result=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=60,env=environment)
        commands.append({'command':args,'returncode':result.returncode,'output':result.stdout+result.stderr});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(result.stdout+result.stderr,end='',flush=True);result.check_returncode()
    options=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    run(['xcrun','--sdk','iphoneos','clang',*options,'-target','arm64-apple-ios14.0','-c',source,'-o',work/'entrypoints.o'])
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang',*options,'-fsanitize=undefined','-fno-sanitize-recover=all','-include',redirects,source,fixture,'-framework','Foundation','-o',executable])
    for enabled in ("0", "1"):
        run([executable], dict(os.environ, YTL_TEST_SIDELOAD=enabled))
    inputs=[source,source.with_suffix('.h'),fixture,redirects,Path(__file__).resolve()]
    report.write_text(json.dumps({'ios_compile':'passed','actual_constructor_and_block':'passed','installer_calls':'intercepted','original_binary_executed':False,
        'scope':'Verifies this local preference-policy registration schedule; does not prove the historical account bootstrap or YouTube integration.',
        'inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')


if __name__=='__main__':main()
