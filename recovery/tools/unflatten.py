#!/usr/bin/env python3
"""Resolve constant indirect ARM64 branches in an analysis copy only.

An unknown condition keeps both destinations. Patches preserve the original
condition and are emitted only when its flags have not subsequently changed.
"""
import argparse
from dataclasses import dataclass
import json
from pathlib import Path
import re
import struct
from inventory import MachO

@dataclass(frozen=True)
class Choice:
    condition: str
    flags: int
    false: int
    true: int

def unary(v, fn):
    return Choice(v.condition,v.flags,fn(v.false),fn(v.true)) if isinstance(v,Choice) else fn(v)

def binary(a,b,fn):
    if isinstance(a,Choice) and isinstance(b,Choice):
        if (a.condition,a.flags)!=(b.condition,b.flags): raise ValueError('different conditions')
        return Choice(a.condition,a.flags,fn(a.false,b.false),fn(a.true,b.true))
    if isinstance(a,Choice): return unary(a,lambda x:fn(x,b))
    return unary(b,lambda x:fn(a,x))

def recover(data, assembly):
    m=MachO(data); regs={}; stack={}; unstable_stack=set(); flags=None; patches=[]; previous=None
    conds=['eq','ne','hs','lo','mi','pl','vs','vc','hi','ls','ge','lt','gt','le','al','nv']
    def k(r): return 'x'+r[1:] if re.fullmatch('[wx][0-9]+',r) else r
    def v(r):
        r=r.strip()
        if r in ['xzr','wzr']: return 0
        if r.startswith('#'): return int(r[1:],0)
        return regs[k(r)]
    def put(r,x): regs[k(r)]=unary(x,lambda y:y&((1<<(32 if r.startswith('w') else 64))-1))
    def load(addr,size):
        if not isinstance(addr,int): return unary(addr,lambda a:load(a,size))
        value=int.from_bytes(data[m.off(addr):m.off(addr)+size],'little')
        if size==8 and value & 0xfff0000000000000: value &= (1<<36)-1
        return value
    def branch(pc,target):
        delta=target-pc
        if delta%4 or not -(1<<27)<=delta<(1<<27): raise ValueError('branch range')
        return 0x14000000|((delta//4)&0x3ffffff)
    def mem(parts):
        s=','.join(parts)
        match=re.search(r'\[(\w+)(?:,\s*([^,\]]+))?(?:,\s*([^\]]+))?\]',s)
        if not match: raise ValueError('memory operand')
        base,index,extend=match.groups()
        if base in ['sp','x29']: return ('stack',base,v(index) if index else 0)
        offset=v(index) if index else 0
        if extend:
            ext=extend.split(); shift=int(ext[1][1:],0) if len(ext)>1 else 0
            if ext[0]=='sxtw': offset=unary(offset,lambda x:(x&0x7fffffff)-(x&0x80000000))
            elif ext[0]=='uxtw': offset=unary(offset,lambda x:x&0xffffffff)
            elif ext[0]!='lsl': raise ValueError('extend')
            offset=unary(offset,lambda x:x<<shift)
        return binary(v(base),offset,lambda a,b:a+b)
    for line in assembly.splitlines():
        mt=re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\w+(?:\.\w+)?)\s*(.*)',line)
        if not mt: continue
        pc,word,op,operands=mt.groups();pc=int(pc,16);word=int(word,16)
        if pc in m.function_starts:
            regs.clear();stack.clear();unstable_stack.clear();flags=None
        parts=[p.strip() for p in operands.split(';')[0].split(',')];dest=parts[0]
        try:
            if op=='br':
                target=v(dest)
                if isinstance(target,int):
                    if 0x8000<=target<0x280000:
                        patches.append(dict(address=hex(pc),original=[hex(word)],replacement=[hex(branch(pc,target))],targets=[hex(target)]))
                elif (target.flags==flags and target.condition in conds) or target.condition.startswith('reg:'):
                    if all(0x8000<=t<0x280000 and t%4==0 for t in [target.true,target.false]):
                        # An analysis-only branch island preserves every preceding
                        # instruction and both outcomes. B instructions retain NZCV.
                        island=0x4000000+len(patches)*12
                        if target.condition.startswith('reg:'):
                            candidates=[int(r[1:]) for r,value in regs.items() if isinstance(value,Choice) and value.condition==target.condition and value.flags==target.flags and value.false==0 and value.true==1]
                            if not candidates: raise ValueError('Boolean source register no longer available')
                            first=0x35000040|min(candidates)
                        else:first=0x54000040|conds.index(target.condition)
                        patches.append(dict(address=hex(pc),original=[hex(word)],replacement=[hex(branch(pc,island))],
                                            island=hex(island),island_words=[hex(first),hex(branch(island+4,target.false)),hex(branch(island+8,target.true))],
                                            condition=target.condition,flags_at=hex(target.flags),targets=[hex(target.false),hex(target.true)]))
                regs.clear();flags=None
            elif op=='bl':
                # AAPCS64 preserves x19-x28 and this frame's local stack slots.
                regs={r:x for r,x in regs.items() if r.startswith('x') and int(r[1:])>=19}
                flags=None
                callee=int(parts[0].split()[0],16)
                off=m.off(callee)
                words=struct.unpack_from('<5I',data,off)
                if words[0]==0xa9bf7bfd and words[1]&0xfc000000==0x94000000 and words[2:]==(0x12000000,0xa8c17bfd,0xd65f03c0):
                    regs['x0']=Choice('reg:w0',pc,0,1)
            elif op in ['blr','ret']:
                regs.clear();stack.clear();unstable_stack.clear();flags=None
            elif op=='b' or op.startswith('b.'):
                regs.clear();flags=None
            elif op in ['cmp','cmn','tst','ccmp','fcmp']:
                flags=pc
            elif op in ['adrp','adr']: put(dest,int(parts[1],16))
            elif op=='mov': put(dest,v(parts[1]))
            elif op=='movk':
                shift=int(parts[2].split('#')[1],0) if len(parts)>2 else 0
                put(dest,unary(v(dest),lambda x:(x&~(0xffff<<shift))|(v(parts[1])<<shift)))
            elif op in ['cset','csetm']:
                put(dest,Choice(parts[1],flags,0,1 if op=='cset' else -1))
            elif op=='csel':
                a,b=v(parts[1]),v(parts[2])
                if not isinstance(a,int) or not isinstance(b,int): raise ValueError('nested choice')
                put(dest,Choice(parts[3],flags,b,a))
            elif op in ['add','sub','eor','orr','and']:
                a,b=v(parts[1]),v(parts[2])
                if len(parts)>3:
                    ext=parts[3].split();shift=int(ext[1][1:],0) if len(ext)>1 else 0
                    if ext[0]=='sxtw': b=unary(b,lambda x:(x&0x7fffffff)-(x&0x80000000))
                    elif ext[0]=='uxtw': b=unary(b,lambda x:x&0xffffffff)
                    elif ext[0]!='lsl': raise ValueError('extend')
                    b=unary(b,lambda x:x<<shift)
                put(dest,binary(a,b,{'add':lambda a,b:a+b,'sub':lambda a,b:a-b,'eor':lambda a,b:a^b,'orr':lambda a,b:a|b,'and':lambda a,b:a&b}[op]))
            elif op=='neg': put(dest,unary(v(parts[1]),lambda x:-x))
            elif op in ['stp','ldp']:
                addr=mem(parts[2:])
                if not isinstance(addr,tuple):raise ValueError('non-stack pair')
                width=8 if dest.startswith('x') else 4
                for i,reg in enumerate(parts[:2]):
                    slot=(addr[0],addr[1],addr[2]+i*width)
                    if op=='ldp':
                        if slot in stack:put(reg,stack[slot])
                        else:regs.pop(k(reg),None)
                    else:
                        try:value=v(reg)
                        except KeyError:
                            stack.pop(slot,None);continue
                        if slot in stack and stack[slot]!=value:
                            unstable_stack.add(slot);stack.pop(slot,None)
                        elif slot not in unstable_stack:stack[slot]=value
            elif op in ['ldr','ldur','ldrb','ldrh','str','stur']:
                addr=mem(parts[1:])
                if op in ['str','stur']:
                    if isinstance(addr,tuple):
                        value=v(dest)
                        if addr in stack and stack[addr]!=value:
                            unstable_stack.add(addr);stack.pop(addr,None)
                        elif addr not in unstable_stack:stack[addr]=value
                elif isinstance(addr,tuple): put(dest,stack[addr])
                else: put(dest,load(addr,1 if op=='ldrb' else 2 if op=='ldrh' else 8 if dest.startswith('x') else 4))
            elif re.fullmatch('[wx][0-9]+',dest) and not op.startswith('st'):
                regs.pop(k(dest),None)
                if op.endswith('s'): flags=pc
        except (KeyError,ValueError,IndexError,TypeError):
            if not op.startswith('st'): regs.pop(k(dest),None)
        previous=(pc,word,op)
    return patches

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary',type=Path);p.add_argument('assembly',type=Path)
    p.add_argument('--output',type=Path,default=Path('recovery/evidence/branches.json'))
    a=p.parse_args();patches=recover(a.binary.read_bytes(),a.assembly.read_text())
    a.output.write_text(json.dumps(patches,indent=2)+'\n')
    print(f'Resolved {len(patches)} indirect branches, {sum("condition" in x for x in patches)} conditional')
    instructions={}
    for line in a.assembly.read_text().splitlines():
        mt=re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(\w+(?:\.\w+)?)\s*(.*)',line)
        if mt: instructions[int(mt[1],16)]=(mt[2],mt[3])
    provenance={int(line.split('\t')[2],16) for line in a.output.with_name('decoded-bytes.tsv').read_text().splitlines()[1:]}
    initializers=[]
    for patch in patches:
        if patch.get('condition')!='eq': continue
        pc=int(patch['address'],16); false,true=map(lambda x:int(x,16),patch['targets'])
        flag=int(patch['flags_at'],16)
        if true!=pc+4 or false<=true or instructions.get(flag-4,('',''))[0]!='ldar': continue
        valid=True
        for addr in range(true,false,4):
            op,args=instructions.get(addr,('missing',''))
            if op.startswith('st'):
                if '[sp' in args or '[x29' in args: continue
                if addr not in provenance: valid=False;break
            elif op in ['br','blr','b','bl','ret','svc','missing'] or op.startswith('b.'):
                valid=False;break
        if valid:
            initializers.append(dict(address=patch['address'],target=hex(false),
                                     replacement=hex(0x14000000|(((false-pc)//4)&0x3ffffff)),
                                     decoded_block=[hex(true),hex(false)],
                                     reason='All non-stack stores evaluated to constant bytes; analyze the already-initialized path.'))
    a.output.with_name('initializers.json').write_text(json.dumps(initializers,indent=2)+'\n')
    print(f'Validated {len(initializers)} constant byte initializers for analysis after initialization')

if __name__=='__main__': main()
