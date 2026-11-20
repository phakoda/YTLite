#!/usr/bin/env python3
"""Verify focused first-package helper evidence against current source tests."""
import hashlib
import argparse
import json
from pathlib import Path
import re
import struct
import subprocess
from compare_supplied_packages import archive_files
from decode_strings import decode
from inventory import MachO
from verify_selector_loads import verify_selector_loads

REPO = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    group=parser.add_mutually_exclusive_group()
    group.add_argument('--state',action='store_true',help='Verify first-package Wi-Fi flags and helper ivar teardown.')
    group.add_argument('--imageflow',action='store_true',help='Verify first-package image download callbacks and feedback.')
    group.add_argument('--mediaflow',action='store_true',help='Verify first-package media routing and callback ownership.')
    group.add_argument('--assets',action='store_true',help='Verify first-package asset loading and image rendering.')
    group.add_argument('--ordering',action='store_true',help='Verify progress receiver reads and image-copy call order.')
    group.add_argument('--paths',action='store_true',help='Verify conversion cleanup URLs and nil result forwarding.')
    group.add_argument('--finish',action='store_true',help='Verify output preparation and conversion handoff.')
    group.add_argument('--start',action='store_true',help='Verify download creation, initial state and stop callbacks.')
    group.add_argument('--terminal',action='store_true',help='Verify failure reporting and cleanup call order.')
    group.add_argument('--init',action='store_true',help='Verify helper initialization order and allocation dispatch.')
    group.add_argument('--conversion',action='store_true',help='Verify the separate conversion capture/cleanup audit.')
    group.add_argument('--buttons',action='store_true',help='Verify button factory dispatch and feedback ordering.')
    args=parser.parse_args()
    suffix=next((name for name in ('state','imageflow','mediaflow','assets','ordering','paths','finish','start','terminal','init','buttons','conversion')
                 if getattr(args,name)), 'progress')
    expected_count,start,end,scope={
        'state':(269,'0x22f8b8','0x22f94c','Wi-Fi predicate for created references and helper object-ivar release order; null-reference guard differs'),
        'imageflow':(166,'0x2302b0','0x2311f0','Image URL and callback branches, raw Photos data, feedback localization and error ownership'),
        'mediaflow':(124,'0x22d744','0x22ef58','Photos routing, nil framework results, main-queue completion and media callback captures'),
        'assets':(212,'0x22ef58','0x2315d8','Asset loader allocation, bundle and result forwarding; image rendering callbacks and geometry'),
        'ordering':(44,'0x22b770','0x230f88','Progress receiver/phase reads before localization and image-copy ordering'),
        'paths':(326,'0x22c17c','0x22d4cc','Conversion root/ID timing, URL factories, nil forwarding and move-error selection'),
        'finish':(51,'0x22bbb4','0x22c17c','Independent output roots and URLs, separate removal managers and conversion state timing'),
        'start':(487,'0x22ac34','0x22b770','Download creation, audio phase snapshots, state selection and stop callbacks'),
        'terminal':(38,'0x22d4cc','0x22e364','Failure reporting and cleanup Foundation calls; original system traps excluded'),
        'init':(28,'0x22aa5c','0x22ac34','Helper toast allocation dispatch, initialization order and factory result storage'),
        'buttons':(43,'0x22f94c','0x2302b0','Button factory dispatch, original icon branch and separate feedback getters'),
        'conversion':(56,'0x22bbb4','0x22d4cc','Conversion callback captures, cleanup state and file-manager ordering'),
        'progress':(1228,'0x22b1c0','0x22bbb4','Download percentage arithmetic and audio-phase toast selector/animation'),
    }[suffix]
    work=REPO/f'.recovery-work/helper-{suffix}';work.mkdir(exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    evidence=REPO/f'recovery/evidence/first-helper-{suffix}-fidelity.json'
    expected=json.loads(evidence.read_text())
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest=next(x for x in json.loads((REPO/'recovery/evidence/packages.json').read_text()) if x['package']==package.name)
    assert sha(package)==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']==expected['binary_sha256']
    image=MachO(binary)
    path=work/'original.dylib';path.write_bytes(binary)
    assembly=subprocess.run(['xcrun','llvm-objdump','--disassemble','--start-address='+start,
        '--stop-address='+end,str(path)],capture_output=True,text=True,check=True,timeout=90).stdout
    _,writes,_=decode(binary,assembly)
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    for item in expected['strings']:
        a=int(item['address'],16);p=image.ptr(a+16);n=struct.unpack_from('<Q',binary,image.off(a+24))[0]
        assert bytes(writes.get(x,binary[image.off(x)]) for x in range(p,p+n)).decode()==item['value']
    for item in expected['branches']:
        t,k,x=[int(item[name],16) for name in ['table','key','xor']]
        delta=(-(image.u32(image.off(k))^x))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert [hex(image.ptr(t+i*8)+delta) for i in range(2)]==item['targets']
    for item in expected['selectors']:
        assert image.string(image.ptr(int(item['reference'],16)))==item['name']
    verify_selector_loads(image,expected)
    original=next(c for c in image.classes() if c['name']=='YTLHelper')
    if 'ivar_offsets' in expected:
        ro=image.ptr(int(original['address'],16)+32)&~7
        ivars=image.ptr(ro+48)
        stride,count=struct.unpack_from('<II',binary,image.off(ivars))
        offsets={image.string(image.ptr(ivars+8+i*stride+8)):
                 image.u32(image.off(image.ptr(ivars+8+i*stride))) for i in range(count)}
        assert offsets==expected['ivar_offsets']
    if 'method_contracts' in expected:
        for contract in expected['method_contracts']:
            matches=[m for m in original['methods'] if m['kind']==contract['kind'] and m['selector']==contract['selector']]
            assert len(matches)==1 and matches[0]['address']==contract['address'],contract
    else:
        expected_methods=expected.get('methods',{'downloadProgress:':'0x22b770',
            'downloadAudioWithUrl:fileName:videoID:audioSize:duration:':'0x22b1c0'})
        for name,address in expected_methods.items():
            matches=[m for m in original['methods'] if m['selector']==name]
            assert len(matches)==1 and matches[0]['address']==address,(name,address)
    shared=REPO/'.recovery-work/presentation-helpers'
    runtime_path=shared/'runtime-verification.json';runtime=json.loads(runtime_path.read_text())
    metadata_path=shared/'source-verification.json';metadata=json.loads(metadata_path.read_text())
    assert runtime['passed'] and runtime['runtime_returncode']==0 and metadata['passed']
    inputs=dict(runtime['sources']);inputs.update(runtime['fixture_support_inputs'])
    for p,h in inputs.items():assert sha(REPO/p)==h,('Stale runtime input',p)
    rows=[c for c in metadata['classes'] if c['class']=='YTLHelper']
    assert {c['architecture'] for c in rows}=={'arm64','arm64e'}
    for row in rows:assert row['method_count']==22 and not row['differences'] and sha(REPO/row['source'])==row['source_sha256']
    log=shared/'native/runtime.log'
    count=int(re.search(r'PASS Helper_first_package_'+suffix+r': (\d+) assertions',log.read_text())[1])
    assert count==expected_count,(count,expected_count)
    related_checks={}
    related={
        'assets':('rendering_geometry','Helper_rendering_fidelity',31),
        'mediaflow':('media_presentation','Helper_media_presentation_fidelity',22),
        'imageflow':('image_url_and_routing','Helper_image_fidelity',27),
    }
    if suffix in related:
        name,label,expected_related=related[suffix]
        related_count=int(re.search(r'PASS '+label+r': (\d+) assertions',log.read_text())[1])
        assert related_count==expected_related
        related_checks[name]=related_count
    paths=[evidence,Path(__file__).resolve(),runtime_path,metadata_path,log,
        REPO/f'recovery/source/Helpers/YTLHelper.{suffix}.provenance.md']
    paths += [REPO/'recovery/tools'/name for name in ['compare_supplied_packages.py','decode_strings.py','inventory.py','verify_selector_loads.py']]
    inputs.update({str(p.relative_to(REPO)):sha(p) for p in paths})
    report.write_text(json.dumps({'passed':True,'runtime_assertions':count,'related_runtime_assertions':related_checks,'inputs':inputs,
        'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'original_binary_executed':False,'scope':scope,
        'limits':['Synthetic host boundaries; other helper behavior and device integration remain unverified.']},indent=2)+'\n')
    print(f'First-package helper {suffix}: {count} actual-source checks; original evidence verified.')


if __name__=='__main__':main()
