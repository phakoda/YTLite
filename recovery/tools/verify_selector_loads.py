"""Tie selector evidence to adjacent ARM64 ADRP/LDR instructions in pinned spans."""


def verify_selector_loads(image, evidence):
    intervals=[(int(s['start'],16),int(s['end'],16)) for s in evidence['spans']]
    for item in evidence['selectors']:
        if 'load_instruction' not in item:
            assert not evidence.get('selector_loads_required',False),item
            continue
        page=int(item['page_instruction'],16)
        load=int(item['load_instruction'],16)
        assert load==page+4 and any(a<=page and load+4<=b for a,b in intervals),item
        adrp=image.u32(image.off(page));ldr=image.u32(image.off(load))
        assert adrp&0x9f000000==0x90000000 and ldr&0xffc00000==0xf9400000,item
        assert adrp&31==(ldr>>5)&31,item
        immediate=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
        if immediate&(1<<20):immediate-=1<<21
        reference=(page&~0xfff)+(immediate<<12)+(((ldr>>10)&0xfff)*8)
        assert reference==int(item['reference'],16),item
        assert image.string(image.ptr(reference))==item['name'],item
