#!/usr/bin/env python3
"""Original-byte and actual reconstructed-source sheet lifecycle verification."""
import hashlib,json,os,re,subprocess,sys
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/sheet-lifecycle';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    manifest=REPO/'recovery/source/Presentation/SheetLifecycle.evidence.json'
    evidence=json.loads(manifest.read_text());image=EvidenceImage();assert image.sha256==evidence['binary_sha256']
    original=json.loads((REPO/'recovery/evidence/arm-classes.json').read_text())
    names=[item['name']for item in evidence['classes']]
    assert [item for item in original if item['name']in names]==evidence['classes']
    for item in evidence['ranges']:
        a,b=int(item['start'],16),int(item['end'],16)
        assert hashlib.sha256(image.image.data[image.image.off(a):image.image.off(b)]).hexdigest()==item['sha256']
    for collection in ['instruction_words','raw_data']:
        for address,expected in evidence[collection].items():
            offset=image.image.off(int(address,16))
            assert image.image.data[offset:offset+len(expected)//2].hex()==expected
    for item in evidence['branch_tables']:
        delta=(-(int.from_bytes(image.buffer(int(item['key'],16),4),'little')^int(item['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=1<<32
        assert [hex(image.image.ptr(int(item['table'],16)+i*8)+delta)for i in range(2)]==item['targets_false_true']
    for address,expected in evidence['cstrings'].items():assert image.cstring(int(address,16))==expected
    for address,expected in evidence['cfstrings'].items():assert image.cfstring(int(address,16))==expected
    for address,expected in evidence['import_terminals'].items():assert image.terminal(int(address,16))==expected
    sources=[REPO/'recovery/source/Presentation'/f'{name}.m' for name in ['PseudoDetentController','PseudoDetentTransitioningDelegate','DVNSheetPresenter']]
    commands=[]
    env=dict(os.environ,UBSAN_OPTIONS='halt_on_error=1',CLANG_MODULE_CACHE_PATH=str(work/'module-cache'),TMPDIR=str(work))
    def run(args,label):
        p=subprocess.run(list(map(str,args)),cwd=REPO,env=env,capture_output=True,text=True,timeout=120)
        commands.append(dict(label=label,command=list(map(str,args)),returncode=p.returncode,output=p.stdout+p.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');(work/(label+'.log')).write_text(p.stdout+p.stderr)
        print(p.stdout+p.stderr,end='');p.check_returncode();assert 'implemented in both' not in p.stderr;return p.stdout
    # Only substitute the OS-availability boundary; the three method bodies and
    # callback bodies are otherwise byte-identical source text in the fixture.
    host=work/'DVNSheetPresenter.m';original=sources[2].read_text();needle='@available(iOS 15.0, *)'
    assert original.count(needle)==1
    host.write_text(original.replace(needle,'SheetNativeAvailable()'))
    fixture=REPO/'recovery/tests/sheet_lifecycle_fixture.m';shim=REPO/'recovery/tests/sheet_lifecycle_shims'
    test=work/'fixture'
    run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim,'-I',sources[2].parent,*sources[:2],host,fixture,'-framework','Foundation','-framework','CoreGraphics','-o',test],'compile')
    output=run([test],'runtime')
    args=[sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','sheet-lifecycle']
    for source in sources:args+=['--source',source]
    run(args+['--classes',*[source.stem for source in sources]],'ios-abi')
    ir=(REPO/'.recovery-work/ios-audit-sheet-lifecycle/00-PseudoDetentController.ll').read_text()
    signature=evidence['cstrings']['0xb9b4ba'].replace('"',r'\22')
    assert signature in ir and 'i64 256' in ir and '__copy_helper_block_e8_32s' in ir
    assert len(re.findall(r'store ptr @"__block_descriptor_40_e8_32s',ir))==3
    detent_ir=(REPO/'.recovery-work/ios-audit-sheet-lifecycle/02-DVNSheetPresenter.ll').read_text()
    assert evidence['cstrings']['0xb9b4a7'] in detent_ir
    assert '__block_descriptor_32_' in detent_ir and '__block_descriptor_40_' in detent_ir
    files=[manifest,REPO/'recovery/source/Presentation/SheetLifecycle.provenance.md',REPO/'recovery/source/Presentation/PresentationGeometry.h']+sources+[p.with_suffix('.h')for p in sources]+[fixture,Path(__file__).resolve()]+list(shim.rglob('*.h'))
    report.write_text(json.dumps(dict(passed=True,original_sha256=image.sha256,original_ranges=len(evidence['ranges']),original_methods=22,original_callbacks=6,branch_tables=7,compiled_block_ABI='three strong object captures and scalar/global CGSize calculators verified',runtime_checks=int(re.search(r'Sheet lifecycle: (\d+) checks',output)[1]),original_executed=False,availability_substitution={'from':needle,'to':'SheetNativeAvailable()'},inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n')
if __name__=='__main__':main()
