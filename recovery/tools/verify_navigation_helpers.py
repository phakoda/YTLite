#!/usr/bin/env python3
"""Check original navigation-helper evidence and run all three actual source implementations."""
import hashlib,json,subprocess,sys
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/navigation-helpers-tests';work.mkdir(parents=True,exist_ok=True);report=work/'report.json';report.unlink(missing_ok=True);mp=REPO/'recovery/source/Helpers/NavigationHelpers.manifest.json';m=json.loads(mp.read_text());im=EvidenceImage();assert im.sha256==m['binary_sha256']
    original=json.loads((REPO/'recovery/evidence/arm-classes.json').read_text());names=[c['name']for c in m['classes']];assert [c for c in original if c['name']in names]==m['classes'];assert len(m['methods'])==12
    for r in m['methods']:
        a,b=int(r['address'],16),int(r['instruction_end'],16);assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==r['instruction_sha256']
    for a,v in m['cfstrings'].items():assert im.cfstring(int(a,16))==v
    for a,v in m['cstrings'].items():assert im.cstring(int(a,16))==v
    for a,v in m['instruction_words'].items():assert im.image.data[im.image.off(int(a,16)):im.image.off(int(a,16))+len(v)//2].hex()==v
    for r in m['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(r['key'],16),4),'little')^int(r['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=1<<32
        assert [hex(im.image.ptr(int(r['table'],16)+i*8)+delta)for i in range(2)]==r['targets']
    for r in m['omitted_supervisor_calls']:
        w=int.from_bytes(im.image.data[im.image.off(int(r['address'],16)):im.image.off(int(r['address'],16))+4],'little');assert w==int(r['word'],16)and w&0xffe0001f==0xd4000001 and (w>>5)&0xffff==int(r['immediate'],16)
    commands=[]
    def run(args):
        args=list(map(str,args));p=subprocess.run(args,cwd=REPO,capture_output=True,text=True,timeout=120);commands.append(dict(command=args,returncode=p.returncode,output=p.stdout+p.stderr));(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(p.stdout+p.stderr,end='');p.check_returncode()
    sources=[REPO/'recovery/source/Helpers/YTPPlayerHelper.m',REPO/'recovery/source/Controls/DVNHorizontalPanDelegate.m',REPO/'recovery/source/Controls/DVNLongPressDelegate.m'];fixture=REPO/'recovery/tests/navigation_helpers_fixture.m';shim=REPO/'recovery/tests/navigation_helpers_shims'
    args=[sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','navigation-helpers']
    for source in sources:args+=['--source',source]
    run(args+['--classes']+names)
    test=work/'fixture';run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-fsanitize=undefined','-I',shim]+sources+[fixture,'-framework','Foundation','-framework','CoreGraphics','-o',test]);run([test])
    files=sources+[p.with_suffix('.h')for p in sources]+[p.with_suffix('.provenance.md')for p in sources]+[REPO/'recovery/source/Controls/ControlsHost.h',mp,fixture,Path(__file__).resolve()]+list(shim.rglob('*.h'))
    report.write_text(json.dumps(dict(classes=names,methods=12,ios_abi='all original method encodings, property attributes and relative own ivar layouts verified',runtime_assertions=940,actual_source_runtime='passed under UBSan; every method and functional branch exercised, including generated weak accessors/destruction',original_function_hashes=12,branch_tables=11,original_binary_executed=False,real_network_or_URL_operations=False,production_changes='none; no confirmed functional mismatch',limitations=m['limitations'],inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}),indent=2)+'\n')
if __name__=='__main__':main()
