"""Recover the 59 first-package icon contracts from their static instructions.

This reader recognizes four inspected factory tails and their literal-init
branch. It rejects unfamiliar instructions instead of guessing their behavior.
It never reads reconstructed source and never executes packaged instructions.
"""
from bisect import bisect_right
import hashlib
import re
import struct
from compare_supplied_packages import method_spans
from decode_strings import decode
from inventory import MachO


def signed(value,bits):return value-(1<<bits) if value&(1<<(bits-1)) else value


def page(image,address):
    word=image.u32(image.off(address));assert word&0x9f000000==0x90000000,hex(address)
    delta=signed(((word>>5)&0x7ffff)*4+((word>>29)&3),21)<<12
    return (address&~0xfff)+delta,word&31


def address_pair(image,address):
    base,register=page(image,address);word=image.u32(image.off(address+4))
    assert word&0xffc00000==0x91000000 and word&31==register and (word>>5)&31==register,hex(address)
    return base+((word>>10)&0xfff),register


def contracts(binary,assembly):
    image=MachO(binary);starts=sorted(image.function_starts)
    classes=image.classes();media=next(c for c in classes if c['name']=='YTPMedia')
    spans=method_spans(image,[media]);instructions={}
    for match in re.finditer(r'^[ \t]*([0-9a-f]+):[ \t]+([0-9a-f]{8})[ \t]+(\S+)[ \t]*(.*?)$',assembly,re.M):
        address,word=int(match[1],16),int(match[2],16)
        assert image.u32(image.off(address))==word,('Assembly differs from original bytes',hex(address))
        operands=match[4].split(';')[0].split('<')[0].split('//')[0].strip()
        instructions[address]=(match[3],re.sub(r'\s+',' ',operands))
    _,writes,write_origins=decode(binary,assembly)
    def cfstring(address):
        pointer=image.ptr(address+16);length=image.ptr(address+24)
        assert 0<length<256
        return bytes(writes.get(p,binary[image.off(p)]) for p in range(pointer,pointer+length)).decode()
    # Decode imported stubs rather than relying on names from a separate export.
    imports={};start,size,_=image.sections['__stubs']
    for a in range(start,start+size,12):
        base,reg=page(image,a);load=image.u32(image.off(a+4))
        assert load&0xffc00000==0xf9400000 and (load>>5)&31==reg
        raw=struct.unpack_from('<Q',binary,image.off(base+((load>>10)&0xfff)*8))[0]
        if raw>>63:imports[a]=image.imports[raw&0xffffff]
    wrappers={}
    def call(address,depth=0):
        if address in imports:return imports[address],0
        assert depth<3 and address in starts,('Unknown call',hex(address))
        end=starts[bisect_right(starts,address)]
        words=list(struct.unpack_from('<'+'I'*((end-address)//4),binary,image.off(address)))
        assert words[0]==0xa9bf7bfd and words[-2:]==[0xa8c17bfd,0xd65f03c0],('Unknown wrapper',hex(address))
        assert words[1]&0xfc000000==0x94000000 and words[2:-2] in ([],[0x12000000]),hex(address)
        target=address+4+signed(words[1]&0x3ffffff,26)*4
        symbol,masks=call(target,depth+1)
        wrappers[address]={'start':hex(address),'end':hex(end),
            'sha256':hashlib.sha256(binary[image.off(address):image.off(address)+end-address]).hexdigest()}
        return symbol,masks+len(words[2:-2])
    records=[];templates={};initialization_templates={}
    for method in sorted(media['methods'],key=lambda m:int(m['address'],16)):
        a=int(method['address'],16)
        if not 0x1aab50<=a<0x1b5e88:continue
        span=spans[f"+[YTPMedia {method['selector']}]"];b=int(span['end'],16)
        assert all(p in instructions for p in range(a,b,4))
        branches=[p for p in range(a,b,4) if instructions[p][0]=='br']
        assert len(branches)==1
        branch=branches[0];ldar=branch-64
        assert image.u32(image.off(ldar))==0x88dffd09
        assert image.u32(image.off(ldar+4))==0x7100013f
        assert image.u32(image.off(ldar+8))==0x1a9f17e9
        table,reg=address_pair(image,ldar-20);assert reg==8
        flag,reg=address_pair(image,ldar-8);assert reg==8
        base,reg=page(image,ldar+24);load=image.u32(image.off(ldar+28))
        assert load&0xffc003ff==0xb940014a and reg==10
        key=base+((load>>10)&0xfff)*4
        lo=image.u32(image.off(ldar+32));hi=image.u32(image.off(ldar+36))
        assert lo&0xffe0001f==0x5280000b and hi&0xffe0001f==0x72a0000b
        xor=((lo>>5)&0xffff)|(((hi>>5)&0xffff)<<16)
        delta=signed((-(image.u32(image.off(key))^xor))&0xffffffff,32)
        targets=[image.ptr(table+8*i)+delta for i in range(2)]
        join=targets[0];assert targets[1]==branch+4 and branch+4<join<b
        assert image.u32(image.off(join))==0x52800029 and image.u32(image.off(join+4))==0x889ffd09
        allowed={'adrp','add','ldrb','mov','eor','strb','mvn'}
        assert all(instructions[p][0] in allowed for p in range(branch+4,join,4)),method
        assert not any(instructions[p][1].split(',')[0] in ('x8','w8') for p in range(branch+4,join,4)),method
        kind='fixed' if method['selector'] in ('x_prefs','empty') else 'tinted' if method['selector']=='ytPlusShorts' else 'owned_pair' if method['selector']=='copy' else 'pair'
        # Asset arguments sit immediately before the final comparison/call.
        if kind=='fixed':
            candidates=[p for p in range(join+8,b,4) if instructions[p][0]=='adrp' and instructions[p][1].startswith('x2,')]
            assert len(candidates)==1
            normal_at=candidates[0];normal,reg=address_pair(image,normal_at);assert reg==2
            cairo=normal;asset_pairs={normal_at:('normal',2)}
        else:
            selections=[p for p in range(join+8,b,4) if image.u32(image.off(p))==0x9a881122]
            assert len(selections)==1
            select=selections[0];assert image.u32(image.off(select-4))==0x7100029f
            normal_at,cairo_at=select-20,select-12
            normal,reg=address_pair(image,normal_at);assert reg==8
            cairo,reg=address_pair(image,cairo_at);assert reg==9
            asset_pairs={normal_at:('normal',8),cairo_at:('cairo',9)}
        # Check every decoded byte store belongs to the selected literal buffers.
        buffers=set()
        for literal in {normal,cairo}:
            pointer=image.ptr(literal+16);length=image.ptr(literal+24)
            buffers.update(range(pointer,pointer+length+1))
        body_stores={p for p in range(branch+4,join,4) if instructions[p][0]=='strb'}
        decoded_stores={pc for dest,pc in write_origins.items() if branch<pc<join}
        assert body_stores==decoded_stores,('Unresolved literal store',method['selector'])
        assert all(dest in buffers for dest,pc in write_origins.items() if branch<pc<join),method
        # Preserve the complete branch-setup register flow. Substitute only its
        # four independently decoded data addresses/immediates.
        init=[];p=a
        replacements={ldar-20:'table x8',ldar-8:'flag x8',ldar+24:'key w10',ldar+32:'xor w11'}
        while p<=branch:
            if p in replacements:init.append(replacements[p]);p+=8;continue
            op,operands=instructions[p];init.append(op+' '+operands);p+=4
        if kind not in initialization_templates:initialization_templates[kind]=init
        assert init==initialization_templates[kind],('Initializer register flow differs',method['selector'])
        canonical=[];calls=[];p=join+8
        while p<b:
            op,operands=instructions[p]
            if p in asset_pairs:
                label,reg=asset_pairs[p];canonical.append(f'asset x{reg}, {label}');p+=8;continue
            if op in ('b','bl'):
                word=image.u32(image.off(p));target=p+signed(word&0x3ffffff,26)*4
                symbol,masks=call(target)
                canonical.append(f'{op} {symbol} bool_masks={masks}')
                calls.append({'instruction':hex(p),'symbol':symbol,'bool_masks':masks})
            else:canonical.append(op+' '+operands)
            p+=4
        if kind not in templates:
            assert method['selector']=={'pair':'historyTab','fixed':'x_prefs','tinted':'ytPlusShorts','owned_pair':'copy'}[kind]
            templates[kind]=canonical
        assert canonical==templates[kind],('Factory tail differs from inspected template',method['selector'],canonical,templates[kind])
        records.append({'selector':method['selector'],'kind':kind,'address':method['address'],
            'normal':cfstring(normal),'cairo':cfstring(cairo),
            'normal_cfstring':hex(normal),'cairo_cfstring':hex(cairo),'calls':calls,
            'initializer':{'branch':hex(branch),'flag':hex(flag),'table':hex(table),'key':hex(key),
                'xor':hex(xor),'targets':list(map(hex,targets)),'tail_start':hex(join+8)}})
    assert len(records)==59 and sum(r['kind']=='pair' for r in records)==55
    named=[spans[f"+[YTPMedia {r['selector']}]"] for r in records]
    return {'class':'YTPMedia','binary_sha256':hashlib.sha256(binary).hexdigest(),
        'spans':named+sorted(wrappers.values(),key=lambda r:int(r['start'],16)),
        'method_contracts':[m for m in media['methods'] if 0x1aab50<=int(m['address'],16)<0x1b5e88],
        'templates':templates,'initialization_templates':initialization_templates,'icons':records}
