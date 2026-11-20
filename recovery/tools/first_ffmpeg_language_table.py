"""Decode the reviewed constant-address stores for the first caption dictionary."""
def language_table_addresses(image):
    registers={};arrays={19:{},20:{}}
    for address in range(0x1fbf38,0x1fc578,4):
        word=image.u32(image.off(address))
        if word&0x9f000000==0x90000000:
            register=word&31;assert register in (8,9,10)
            delta=((word>>5)&0x7ffff)*4+((word>>29)&3)
            if delta&(1<<20):delta-=1<<21
            registers[register]=(address&~0xfff)+(delta<<12)
        elif word&0xffc00000==0x91000000:
            target,source=word&31,(word>>5)&31
            assert target==source and target in registers
            registers[target]+=((word>>10)&0xfff)
        elif word&0xffc00000==0xa9000000:
            source,second,base=word&31,(word>>10)&31,(word>>5)&31
            offset=(word>>15)&0x7f
            if offset&64:offset-=128
            assert base in arrays and source in registers and second in registers
            for slot,reg in [(offset,source),(offset+1,second)]:
                assert 0<=slot<80 and slot not in arrays[base]
                arrays[base][slot]=registers[reg]
        elif word&0xffc00000==0xf9000000:
            source,base,slot=word&31,(word>>5)&31,(word>>10)&0xfff
            assert base in arrays and source in registers and 0<=slot<80 and slot not in arrays[base]
            arrays[base][slot]=registers[source]
        else:
            raise AssertionError(('Unreviewed dictionary instruction',hex(address),hex(word)))
    assert all(set(values)==set(range(80)) for values in arrays.values())
    # Reviewed call arguments x2=x19 objects, x3=x20 keys, x4=80.
    assert [image.u32(image.off(a)) for a in (0x1fc588,0x1fc58c,0x1fc590)]==[0xaa1303e2,0xaa1403e3,0x52800a04]
    return [(arrays[20][i],arrays[19][i]) for i in range(80)]
