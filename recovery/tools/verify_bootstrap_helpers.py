#!/usr/bin/env python3
"""Verify Dvbug and InitWorkaround against original metadata and runtime fixtures."""
import hashlib
import json
from pathlib import Path
import subprocess
REPO=Path(__file__).resolve().parents[2]
def main():
    from evidence_image import EvidenceImage
    image=EvidenceImage()
    assert image.image.data[image.image.off(0x1153530)] == 1, "Read initial state from raw data, not runtime-write overlays"
    work=REPO/'.recovery-work/bootstrap-helpers-tests'; work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json'; report.unlink(missing_ok=True); commands=[]
    sources=[REPO/'recovery/source/Support/Dvbug.m',REPO/'recovery/source/Runtime/InitWorkaround.m']
    test=REPO/'recovery/tests/bootstrap_helpers.m'; redirects=REPO/'recovery/tests/bootstrap_helpers_redirects.h'
    def run(command):
        command=list(map(str,command));result=subprocess.run(command,cwd=REPO,capture_output=True,text=True,timeout=60)
        commands.append({'command':command,'exit_code':result.returncode,'output':result.stdout+result.stderr});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(result.stdout+result.stderr,end='',flush=True); result.check_returncode()
    for manifest in ['Support/Dvbug.manifest.json', 'Runtime/InitWorkaround.manifest.json']:
        run(['python3', 'recovery/tools/verify_module_manifest.py', 'recovery/source/' + manifest])
    run(['python3','recovery/tools/verify_ios_sources.py',*sum((['--source',s] for s in sources),[]),'--classes','Dvbug','InitWorkaround','--label','bootstrap-helpers'])
    executable=work/'bootstrap-helpers-test'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all',
         '-I',REPO/'recovery/tests/bootstrap_helpers_shims','-include',redirects,*sources,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable])
    inputs=sources+[s.with_suffix('.h') for s in sources]+[test,redirects,Path(__file__).resolve()]+list((REPO/'recovery/tests/bootstrap_helpers_shims').rglob('*.h'))
    report.write_text(json.dumps({'initial_first_time_flag':'raw-byte-1-and-actual-source-YES','ios_abi_audit':'passed','runtime_tests':'passed','ubsan':'passed','original_binary_executed':False,'real_hook_installation':'intercepted',
        'source_sha256':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')
if __name__=='__main__':main()
