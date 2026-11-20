#!/usr/bin/env python3
"""Read-only ARM64 evidence annotator for Settings recovery.

Linear data flow is a reading aid, NOT proof of reachability. Indirect branch
edges are reported separately from the verified closed-CFG evidence. The
original image is parsed as bytes and is never loaded or executed.
"""
from __future__ import annotations
import argparse, bisect, hashlib, json, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

class Image:
    def __init__(self):
        self.data = bytearray((ROOT/'.recovery-work/arm/YTLite.dylib').read_bytes())
        if hashlib.sha256(self.data).hexdigest() != 'bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca':
            raise ValueError('Evidence binary hash mismatch')
        self.function_starts=set(); self.calls=[]; self.blocks={}; self.block_candidates={}
        self.segments=[]; self.sections=[]; self.symbols={}; self.binds={}; self.names={}
        self.fixups={}; self.methods={}; self.ivars=json.loads((ROOT/'recovery/evidence/ivars.json').read_text())
        self.branches={int(e['address'],16): e for e in json.loads((ROOT/'.recovery-work/analysis-v2/evidence/branches.json').read_text())}
        self.strings={int(e['address'],16):e['value'] for e in json.loads((ROOT/'recovery/evidence/decoded-strings.json').read_text())}
        self.cfstrings={int(e['address'],16):e['value'] for e in json.loads((ROOT/'recovery/evidence/arm-cfstrings.json').read_text())}
        ncmds=struct.unpack_from('<I',self.data,16)[0]; pos=32; cmds=[]
        for _ in range(ncmds):
            cmd,size=struct.unpack_from('<II',self.data,pos); cmds.append((cmd,pos))
            if cmd==0x19:
                _,_,name,addr,vsize,off,fsize,_,_,nsects,_=struct.unpack_from('<II16sQQQQiiII',self.data,pos)
                self.segments.append((addr,vsize,off,fsize,name.rstrip(b'\0').decode()))
                for i in range(nsects):
                    sn,sg,sa,sz,so,al,ro,nr,fl,r1,r2,r3=struct.unpack_from('<16s16sQQIIIIIIII',self.data,pos+72+i*80)
                    self.sections.append((sa,sz,so,fl,r1,r2,sn.rstrip(b'\0').decode()))
            pos+=size
        for cmd,pos in cmds:
            if cmd==0x26:
                at,size=struct.unpack_from('<II',self.data,pos+8);end=at+size;a=0
                while at<end:
                    delta=0;shift=0
                    while True:
                        b=self.data[at];at+=1;delta|=(b&127)<<shift;shift+=7
                        if b<128:break
                    if delta==0:break
                    a+=delta;self.function_starts.add(a)
        syms=[]; indirect=[]
        for cmd,pos in cmds:
            if cmd==2:
                _,_,off,count,stroff,strsize=struct.unpack_from('<IIIIII',self.data,pos)
                for i in range(count):
                    ix,ty,sc,de,val=struct.unpack_from('<IBBHQ',self.data,off+16*i)
                    end=self.data.find(0,stroff+ix)
                    name=bytes(self.data[stroff+ix:end]).decode(errors='replace'); syms.append(name)
                    if val: self.symbols[val & 0xffffffffffff]=name
            if cmd==0xb:
                off,count=struct.unpack_from('<II',self.data,pos+56)
                indirect=list(struct.unpack_from('<'+'I'*count,self.data,off))
        for sa,sz,so,fl,r1,r2,sn in self.sections:
            kind=fl&255
            if kind in (6,7,8):
                stride=r2 if kind==8 else 8
                for i in range(sz//stride):
                    j=r1+i
                    if j<len(indirect) and indirect[j]<len(syms):
                        name=syms[indirect[j]]
                        (self.symbols if kind==8 else self.binds)[sa+i*stride]=name
        for cmd,pos in cmds:
            if cmd in (0x22,0x80000022):
                for rel in (16,24,32):
                    off,size=struct.unpack_from('<II',self.data,pos+rel)
                    self.bind_stream(off,size)
        for cmd,pos in cmds:
            if cmd==0x80000034:
                off,size=struct.unpack_from('<II',self.data,pos+8)
                version,starts,imports,strings,count,fmt,sfmt=struct.unpack_from('<7I',self.data,off)
                imported=[]
                for i in range(count):
                    if fmt in (1,2):
                        v=struct.unpack_from('<I',self.data,off+imports+i*(4 if fmt==1 else 8))[0];ix=v>>9
                    else:
                        v=struct.unpack_from('<Q',self.data,off+imports+i*16)[0];ix=v>>32
                    j=off+strings+ix;e=self.data.find(0,j);imported.append(bytes(self.data[j:e]).decode())
                nseg=struct.unpack_from('<I',self.data,off+starts)[0]
                for i in range(nseg):
                    rel=struct.unpack_from('<I',self.data,off+starts+4+i*4)[0]
                    if not rel:continue
                    at=off+starts+rel
                    sz,page,form,segaddr,maxvalid,npages=struct.unpack_from('<IHHQIH',self.data,at)
                    if form not in (2,6):raise ValueError('Unsupported chained pointer format '+str(form))
                    for j in range(npages):
                        initial=struct.unpack_from('<H',self.data,at+22+j*2)[0]
                        if initial==0xffff:continue
                        initial_values=[initial]
                        if initial&0x8000:
                            k=initial&0x7fff;initial_values=[]
                            while True:
                                extra=struct.unpack_from('<H',self.data,at+22+k*2)[0];initial_values.append(extra&0x7fff);k+=1
                                if extra&0x8000:break
                        for initial in initial_values:
                            a=segaddr+j*page+initial
                            while True:
                                raw=int.from_bytes(self.bytes(a,8),'little');nxt=(raw>>51)&0xfff
                                if raw>>63:
                                    name=imported[raw&0xffffff];self.binds[a]=name;self.fixups[a]=name
                                else:self.fixups[a]=(raw&0xfffffffff)|(((raw>>36)&0xff)<<56)
                                if nxt==0:break
                                a+=nxt*4
        # Apply only the supplied static byte-decoding evidence, never code.
        for line in (ROOT/'recovery/evidence/decoded-bytes.tsv').read_text().splitlines()[1:]:
            a,b,*_=line.split('\t'); off=self.offset(int(a,16))
            if off is not None:self.data[off]=int(b,16)
        for cl in json.loads((ROOT/'recovery/evidence/arm-classes.json').read_text()):
            self.names[int(cl['address'],16)]=cl['name']+'.class'
            for m in cl['methods']:
                a=int(m['address'],16); self.methods[a]=(cl['name'],m)
                self.names[a]=m['kind']+'['+cl['name']+' '+m['selector']+']'
        for a,n in self.symbols.items():
            if not n.startswith('<redacted'):self.names.setdefault(a,n)
        self.name_cache={};self.call_cache={}
        # NSStrings may live in initialized __data and contain UTF-16.
        for a,n in self.binds.items():
            if n=='___CFConstantStringClassReference':
                ptr=self.uint(a+16);length=self.uint(a+24);flags=self.uint(a+8,4)
                if isinstance(ptr,int) and isinstance(length,int) and isinstance(flags,int) and length<1000000:
                    wide=bool(flags&16)
                    try:self.cfstrings[a]=self.bytes(ptr,length*(2 if wide else 1)).decode('utf-16-le' if wide else 'utf-8')
                    except UnicodeError:pass

    def offset(self,a):
        for va,sz,off,fs,_ in self.segments:
            if va<=a<va+fs:return off+a-va
        return None
    def bytes(self,a,n):
        off=self.offset(a)
        return bytes(self.data[off:off+n]) if off is not None else b''
    def uint(self,a,n=8):
        if n==8 and a in self.fixups:return self.fixups[a]
        b=self.bytes(a,n)
        return int.from_bytes(b,'little') if len(b)==n else None
    def bind_stream(self,off,size):
        end=off+size;addr=0;symbol='';seg=0
        def leb(signed=False):
            nonlocal off
            value=0;shift=0
            while off<end:
                b=self.data[off];off+=1;value|=(b&127)<<shift;shift+=7
                if not b&128:break
            if signed and b&64:value-=1<<shift
            return value
        while off<end:
            byte=self.data[off];off+=1;op=byte&240;imm=byte&15
            if op==0:continue
            if op in (0x10,0x30,0x50):continue
            if op in (0x20,0x60):leb(op==0x60)
            elif op==0x40:
                e=self.data.find(0,off);symbol=bytes(self.data[off:e]).decode();off=e+1
            elif op==0x70:seg=imm;addr=self.segments[seg][0]+leb()
            elif op==0x80:addr+=leb()
            elif op==0x90:self.binds[addr]=symbol;addr+=8
            elif op==0xa0:self.binds[addr]=symbol;addr+=8+leb()
            elif op==0xb0:self.binds[addr]=symbol;addr+=8+imm*8
            elif op==0xc0:
                count=leb();skip=leb()
                for _ in range(count):self.binds[addr]=symbol;addr+=8+skip
            else:break
    def cstring(self,a):
        if a in self.strings:return self.strings[a]
        off=self.offset(a)
        if off is None:return None
        end=self.data.find(0,off,min(off+1024,len(self.data)))
        if end<0 or end==off:return None
        try:s=bytes(self.data[off:end]).decode('utf-8')
        except UnicodeError:return None
        return s if all(c.isprintable() or c in '\n\r\t' for c in s) else None
    def describe(self,v):
        if v is None:return '?'
        if not isinstance(v,int):return str(v)
        if v in self.name_cache:return self.name_cache[v]
        text=self.names.get(v)
        if not text and v in self.binds and v not in self.cfstrings:text='&'+self.binds[v]
        if not text and v in self.cfstrings:text='@'+json.dumps(self.cfstrings[v],ensure_ascii=False)
        if not text:
            isa=self.uint(v);p=self.uint(v+16);n=self.uint(v+24)
            if isa is not None and isinstance(p,int) and isinstance(n,int) and n<65536 and (self.binds.get(v)=='___CFConstantStringClassReference' or any(sa<=v<sa+sz and sn=='__cfstring' for sa,sz,so,fl,r1,r2,sn in self.sections)):
                s=self.cstring(p)
                if s is not None:text='@'+json.dumps(s,ensure_ascii=False)
        if not text:
            s=self.cstring(v)
            if s is not None:text=json.dumps(s,ensure_ascii=False)
        if not text:text=hex(v) if abs(v)>20 else str(v)
        self.name_cache[v]=text
        return text
    def target(self,a,depth=0):
        if a in self.call_cache:return self.call_cache[a]
        name=self.names.get(a)
        if name:return name
        if depth<5:
            words=[self.uint(a+i*4,4) for i in range(5)]
            if words[0] is not None:
                w=words[0]
                if w&0x9f00001f==0x90000010 and words[1] is not None and words[1]&0xffc003ff==0xf9400210:
                    imm=((w>>5)&0x7ffff)*4+((w>>29)&3);imm=imm-(1<<21) if imm&(1<<20) else imm
                    ptr=(a&~4095)+(imm<<12)+((words[1]>>10)&0xfff)*8
                    if ptr in self.binds:
                        self.call_cache[a]=self.binds[ptr];return self.binds[ptr]
                for i,w in enumerate(words[:3]):
                    if w is not None and w&0xfc000000 in (0x94000000,0x14000000):
                        d=w&0x3ffffff;d=d-(1<<26) if d&(1<<25) else d
                        found=self.target(a+i*4+d*4,depth+1)
                        if found.startswith('_'):
                            self.call_cache[a]=found;return found
        return hex(a)

LINE=re.compile(r'^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+([.\w]+)\s*(.*)$')
def annotate(image,start,end,all_lines=False):
    regs={'x0':'self','x2':'arg2','x3':'arg3','x4':'arg4','sp':0x700000000000,'xzr':0,'wzr':0};stack={}
    def reg(r):return regs.get('x'+r[1:] if r.startswith('w') else r)
    def put(r,v):
        if r.startswith('w') and isinstance(v,int):v &= 0xffffffff
        regs['x'+r[1:] if r.startswith('w') else r]=v
    def val(x):
        x=x.strip()
        if x.startswith('#'):
            try:return int(x[1:],0)
            except ValueError:
                try:return float(x[1:])
                except ValueError:return None
        return reg(x)
    def add(a,b):
        if isinstance(a,(int,float)) and isinstance(b,(int,float)):return a+b
        if a is not None and b==0:return a
        if a is not None and b is not None:return f'({a}+{b})'
        return None
    def address(operand):
        parts=operand.strip('[]!').split(',');base=reg(parts[0].strip());off=val(parts[1]) if len(parts)>1 else 0
        if len(parts)>2 and isinstance(off,int):
            shift=re.search(r'#(\d+)',parts[2]);off<<=int(shift[1]) if shift else 0
        return add(base,off)
    def load(addr,width):
        if isinstance(addr,int) and addr in stack:return stack[addr]
        if isinstance(addr,int):
            if addr in image.binds:return image.binds[addr]
            return image.uint(addr,width)
        return f'*{addr}' if addr is not None else None
    with (ROOT/'.recovery-work/arm/application.asm').open() as f:
        for line in f:
            match=LINE.match(line)
            if not match:continue
            a=int(match[1],16)
            if a<start:continue
            if a>=end:break
            op=match[3];args=match[4].split(';')[0].split(' <')[0].strip();parts=[p.strip() for p in re.split(r',\s*(?![^\[]*\])',args)];note='';show=False
            if a in image.function_starts:
                regs={'x0':'self' if a in image.methods else 'block', 'x1':'arg1','x2':'arg2','x3':'arg3','x4':'arg4','x5':'arg5','x6':'arg6','x7':'arg7','d0':'fp0','d1':'fp1','d2':'fp2','d3':'fp3','sp':0x700000000000,'xzr':0,'wzr':0};stack={}
                print('\n// '+image.names.get(a,'Function '+hex(a)))
            try:
                if op in ('adrp','adr'):put(parts[0],int(parts[1],16))
                elif op in ('mov','fmov'):
                    v=val(parts[1])
                    if op=='fmov' and isinstance(v,int) and parts[0][0] in ('d','s') and parts[1][0] in ('x','w'):
                        width=8 if parts[0][0]=='d' else 4
                        v=struct.unpack('<d' if width==8 else '<f',(v & ((1<<(width*8))-1)).to_bytes(width,'little'))[0]
                    put(parts[0],v)
                elif op=='movk':
                    shift=int(parts[2].split('#')[1]) if len(parts)>2 else 0
                    old=reg(parts[0]);put(parts[0],(old&~(0xffff<<shift)) | (val(parts[1])<<shift) if isinstance(old,int) else None)
                elif op in ('add','sub'):
                    b=val(parts[2]); b=-b if op=='sub' and isinstance(b,int) else b
                    put(parts[0],add(val(parts[1]),b))
                elif op.startswith(('ldr','ldur')):
                    width={'w':4,'s':4,'b':1,'h':2,'q':16}.get(parts[0][0],8);ad=address(parts[1]);v=load(ad,width)
                    if parts[0].startswith(('d','s')) and isinstance(v,int):v=struct.unpack('<d' if width==8 else '<f',v.to_bytes(width,'little'))[0]
                    put(parts[0],v)
                    if isinstance(ad,int) and ad<0x700000000000:
                        note=parts[0]+'='+image.describe(v);show=bool(v is not None and not isinstance(v,int) or image.describe(v).startswith(('@','"')))
                elif op in ('ldp','stp'):
                    ad=address(parts[2]);width=16 if parts[0].startswith('q') else 8
                    if op=='ldp':put(parts[0],load(ad,width));put(parts[1],load(add(ad,width),width))
                    else:stack[ad]=reg(parts[0]);stack[add(ad,width)]=reg(parts[1])
                elif op.startswith(('str','stur')):
                    ad=address(parts[1]);stack[ad]=reg(parts[0])
                    v=reg(parts[0]);
                    if isinstance(v,int) and start<=v<end:note=f'capture/invoke {hex(v)} at {ad}';show=True
                elif op in ('eor','and','orr'):
                    v,w=val(parts[1]),val(parts[2]);put(parts[0],(v^w if op=='eor' else v&w if op=='and' else v|w) if isinstance(v,int) and isinstance(w,int) else None)
                elif op=='neg':
                    v=val(parts[1]);put(parts[0],-v if isinstance(v,int) else None)
                elif op in ('bl','blr'):
                    target=int(parts[0],16) if op=='bl' else reg(parts[0]);name=image.target(target) if isinstance(target,int) else image.describe(target)
                    for at,invoke in stack.items():
                        if not isinstance(at,int) or not isinstance(invoke,int) or invoke not in image.function_starts:continue
                        header=stack.get(at-16);flags=stack.get(at-8);descriptor=stack.get(at+8)
                        if isinstance(flags,float):flags=struct.unpack('<Q',struct.pack('<d',flags))[0]
                        image.block_candidates[invoke]={'at':at,'header':header,'flags':flags,'descriptor':descriptor}
                        if header not in ('__NSConcreteStackBlock','__NSConcreteGlobalBlock') or not isinstance(flags,int) or not isinstance(descriptor,int):continue
                        if not flags&0x40000000:continue
                        sigptr=image.uint(descriptor+(32 if flags&0x02000000 else 16))
                        signature=image.cstring(sigptr) if isinstance(sigptr,int) else None
                        image.blocks[invoke]={'invoke':hex(invoke),'descriptor':hex(descriptor),'flags':hex(flags),'signature':signature,'size':image.uint(descriptor+8)}
                    if name=='_objc_msgSend':
                        selector=reg('x1'); selector=image.cstring(selector) if isinstance(selector,int) else selector
                        call={'address':hex(a),'selector':selector,'args':[reg('x'+str(i)) for i in range(8)],'floats':[reg('d'+str(i)) for i in range(4)]}
                        def word(at):
                            if at in stack:return stack[at]
                            if at-8 in stack and isinstance(stack[at-8],int) and stack[at-8]>>64:return stack[at-8]>>64
                            return image.uint(at) if isinstance(at,int) and at<0x700000000000 else None
                        if selector=='arrayWithObjects:count:' and isinstance(reg('x2'),int) and isinstance(reg('x3'),int) and 0<=reg('x3')<1000:
                            call['elements']=[word(reg('x2')+i*8) for i in range(reg('x3'))]
                        if selector=='dictionaryWithObjects:forKeys:count:' and all(isinstance(reg('x'+str(i)),int) for i in (2,3,4)) and 0<=reg('x4')<1000:
                            call['values']=[word(reg('x2')+i*8) for i in range(reg('x4'))]
                            call['keys']=[word(reg('x3')+i*8) for i in range(reg('x4'))]
                        image.calls.append(call)
                    keep=name in ('_objc_retain','_objc_retainAutoreleasedReturnValue','_objc_autoreleaseReturnValue','_objc_unsafeClaimAutoreleasedReturnValue','_objc_retainAutoreleaseReturnValue','_objc_retainAutorelease','_objc_retainBlock')
                    release=name in ('_objc_release','_objc_storeStrong','_objc_destroyWeak')
                    if not keep and not release:
                        note=name+' | '+', '.join(f'x{i}={image.describe(reg("x"+str(i)))}' for i in range(8))
                        fps=[f'd{i}={reg("d"+str(i))}' for i in range(4) if reg('d'+str(i)) is not None]
                        if fps:note+=' | '+', '.join(fps)
                        show=True
                    if not keep:
                        result=f'r@{a:x}'
                        if name in ('_objc_alloc','_objc_alloc_init','_objc_getClass'):result=f'{name[6:]}({image.describe(reg("x0"))})'
                        for i in range(19):regs.pop('x'+str(i),None)
                        for i in range(8):regs.pop('d'+str(i),None)
                        regs['x0']=result
                elif op in ('cmp','cmn','fcmp','tst'):
                    note=', '.join(image.describe(val(p)) for p in parts);show=True
                elif op in ('csel','csinc','cset','fcsel','csetm'):
                    put(parts[0],None)
                elif op not in ('b','br','ret','nop','svc') and not op.startswith(('b.','cb','tb')):
                    if parts:put(parts[0],None)
            except (ValueError,TypeError,IndexError,OverflowError,struct.error):
                if parts:put(parts[0],None)
            if a in image.branches:
                b=image.branches[a];note+=' CFG '+b.get('condition','')+' -> '+','.join(b.get('targets',[]));show=True
            elif op=='br':note+=' UNRESOLVED INDIRECT';show=True
            elif op in ('b','ret') or op.startswith(('b.','cb','tb')):show=True
            if all_lines or show:print(f'{a:08x}: {op:10} {args:48}'+(' // '+note if note else ''))

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('start',type=lambda v:int(v,0));p.add_argument('end',type=lambda v:int(v,0));p.add_argument('--all',action='store_true');p.add_argument('--data',action='store_true');a=p.parse_args();im=Image()
    if a.data:
        for x in range(a.start,a.end,8):
            value=im.uint(x);b=im.bytes(x,8);print(hex(x),hex(value) if value is not None else '-',im.describe(value),struct.unpack('<d',b)[0] if len(b)==8 else '')
    else:annotate(im,a.start,a.end,a.all)
