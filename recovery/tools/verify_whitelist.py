#!/usr/bin/env python3
"""Verify SbWhitelistVC against original bytes, iOS metadata and real-source runtime tests."""
import hashlib,json,subprocess
from pathlib import Path
from evidence_image import EvidenceImage
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/whitelist'
    work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    commands=[]
    def run(args):
        result=subprocess.run(list(map(str,args)),cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append({'command':list(map(str,args)),'exit_code':result.returncode,'output':result.stdout+result.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(result.stdout+result.stderr,end='',flush=True);result.check_returncode()
    source=REPO/'recovery/source/Whitelist/SbWhitelistVC.m';test=REPO/'recovery/tests/whitelist_runtime.m'
    run(['python3','recovery/tools/verify_module_manifest.py','recovery/source/Whitelist/manifest.json'])
    image=EvidenceImage()
    manifest=json.loads((REPO/'recovery/source/Whitelist/manifest.json').read_text())
    for address,value in manifest['decoded_strings'].items():
        if image.cfstring(int(address,16))!=value: raise ValueError('Decoded string changed: '+address)
    print(f"{len(manifest['decoded_strings'])} original decoded strings verified.")
    run(['python3','recovery/tools/verify_ios_sources.py','--source',source,'--classes','SbWhitelistVC','--label','whitelist'])
    executable=work/'runtime'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/whitelist_shims',source,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable])
    inputs=[source,test,Path(__file__).resolve()]+list((REPO/'recovery/source/Whitelist').glob('*.h'))+list((REPO/'recovery/tests/whitelist_shims').rglob('*.h'))
    report.write_text(json.dumps({'original_byte_manifest':'passed','ios_metadata':'passed','real_source_runtime':'passed','ubsan':'passed','actual_device_ui':'not tested','original_binary_executed':False,'source_sha256':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')
if __name__=='__main__':main()
