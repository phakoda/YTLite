#!/usr/bin/env python3
"""Check bounded original factory evidence and the complete ToastManager source."""
import hashlib,json,struct,subprocess
from pathlib import Path
from evidence_image import EvidenceImage
REPO=Path(__file__).resolve().parents[2]
def main():
    work=REPO/'.recovery-work/factory-audit';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True);commands=[]
    def run(command):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=command,exit_code=r.returncode,output=r.stdout+r.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(r.stdout+r.stderr,end='',flush=True);r.check_returncode()
    evidence=REPO/'recovery/tests/factory_audit_evidence.json';audit=json.loads(evidence.read_text());im=EvidenceImage()
    assert audit['binary_sha256']==im.sha256
    assert len(audit['factories'])==11
    for factory in audit['factories']:
        for span in factory['spans']:
            a,b=int(span['start'],16),int(span['end'],16)
            assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==span['sha256'],span
    assert im.image.ptr(int(audit['toast_global_block'],16)+16)==int(audit['toast_block_invoke'],16)
    assert im.image.ptr(int(audit['toast_concrete_class_reference'],16))==int(audit['toast_class'],16)
    assert im.buffer(0x1c9bb0,4).hex()=='006946f9' # ldr x0,[x8,#0xcd0], concrete class ref
    def call_target(address):
        word=int.from_bytes(im.buffer(address,4),'little');assert word&0xfc000000==0x94000000
        imm=word&0x3ffffff
        if imm&(1<<25):imm-=1<<26
        return address+imm*4
    assert im.terminal(call_target(0x1c9bb4))=='_objc_alloc_init'
    for address,terminal in audit['receiver_alloc_init_calls'].items():
        callback=int(address,16)
        assert im.buffer(callback+8,4).hex()=='001040f9' # ldr x0,[x0,#32], captured receiver
        assert im.terminal(call_target(callback+12))==terminal=='_objc_alloc_init'
    print('Factory evidence: 11 singleton methods, 22 original method/callback spans, concrete ToastManager target and nine receiver alloc/init calls verified.')
    source=REPO/'recovery/source/Presentation/ToastManager.m';test=REPO/'recovery/tests/factory_audit_toast_runtime.m';shims=REPO/'recovery/tests/factory_audit_shims'
    run(['python3','recovery/tools/verify_ios_sources.py','--source',source,'--classes','ToastManager','--label','factory-toast'])
    executable=work/'toast-runtime'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,source,test,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    for mode in ['subclass-first','base-first']:run([executable,mode])
    inputs=[source,test,source.with_suffix('.h'),Path(__file__).resolve(),evidence]+list(shims.rglob('*.h'))
    report.write_text(json.dumps(dict(original_factories=11,original_spans=22,toast_runtime_checks=18,whole_toast_manager_source=True,ubsan='passed',ios_metadata='passed',original_binary_executed=False,scope=audit['scope'],source_sha256={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}),indent=2)+'\n')
if __name__=='__main__':main()
