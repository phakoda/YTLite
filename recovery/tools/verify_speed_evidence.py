#!/usr/bin/env python3
"""Read-only original-byte audit shared by the two assigned speed classes."""
import hashlib,json,re
from evidence_image import EvidenceImage,REPO

def verify(name):
    im=EvidenceImage();manifest=json.loads((REPO/'recovery/evidence/speed-gesture-fidelity.json').read_text());assert manifest['binary_sha256']==im.sha256
    evidence=manifest['classes'][name];original=next(c for c in json.loads((REPO/'recovery/evidence/arm-classes.json').read_text())if c['name']==name)
    for key in ['methods','properties']:assert evidence[key]==original[key]
    ranges=[]
    for f in evidence['functions']:
        a,b=int(f['start'],16),int(f['end'],16);assert b==min(x for x in im.image.function_starts if x>a)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==f['sha256'];ranges.append((a,b))
    words=0;indirect=set()
    for line in (REPO/'.recovery-work/arm/application.asm').read_text().splitlines():
        m=re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s+(.*)',line)
        if m and any(a<=int(m[1],16)<b for a,b in ranges):
            a=int(m[1],16);assert im.image.u32(im.image.off(a))==int(m[2],16);words+=1
            if m[3].startswith('br\t'):indirect.add(a)
    assert words==sum((b-a)//4 for a,b in ranges)
    original_branches={b['address']:b for b in json.loads((REPO/'recovery/evidence/branches.json').read_text())}
    for branch in evidence['branches']:assert original_branches[branch['address']]==branch
    for table in evidence['manual_tables']:
        delta=-(im.image.u32(im.image.off(int(table['offset'],16)))^int(table['xor'],16));delta=(delta+(1<<31))%(1<<32)-(1<<31)
        assert [hex(im.image.ptr(int(table['table'],16)+i*8)+delta)for i in range(2)]==table['targets_false_true']
    assert indirect=={int(b['address'],16)for b in evidence['branches']+evidence['manual_tables']}
    for item in evidence['wrappers']:assert im.terminal(int(item['address'],16))==item['terminal']
    for item in evidence['cfstrings']:assert im.cfstring(int(item['address'],16))==item['value']
    for item in evidence['omitted_supervisor_calls']:
        w=im.image.u32(im.image.off(int(item['address'],16)));assert w==int(item['word'],16)and w&0xffe0001f==0xd4000001
    for item in manifest['numeric_constants']:
        off=im.image.off(int(item['address'],16));assert im.image.data[off:off+8].hex()==item['raw']
    for item in manifest['critical_instructions']:assert im.image.u32(im.image.off(int(item['address'],16)))==int(item['word'],16)
    return dict(binary_sha256=im.sha256,original_words=words,original_functions=len(ranges),recorded_branches=len(evidence['branches']),manual_tables=len(evidence['manual_tables']),omitted_supervisor_calls=evidence['omitted_supervisor_calls'],limitations=manifest['limits'])
if __name__=='__main__':
    for name in ['YTPSpeedMaster','YTPSpeedPopupController']:print(name,verify(name))
