"""Trace only the reviewed straight-line ARM64 DVNCell factory instruction set.

This reads bytes as data. Unknown instructions, calls, register values or frame
operations fail; it is not an emulator and never executes the supplied dylib.
"""
import re
from first_model_accessor_contracts import target,runtime_symbol


def trace_factory(image,method,end,cell_class,property_types):
    start=int(method['address'],16)
    types=[t for t,_ in re.findall(r'(@\?|@|:|q|d|B|v)(\d+)',method['encoding'])][3:]
    assert len(types)==method['selector'].count(':')
    x={i:('incoming-x',i) for i in range(31)};d={i:('incoming-d',i) for i in range(32)}
    incoming_x=x.copy();incoming_d=d.copy();x[0]=('receiver',);x[1]=('method',method['selector'])
    xi,di=2,0
    for index,typ in enumerate(types,2):
        value=('argument',index,typ)
        if typ=='d':d[di]=value;di+=1
        else:assert xi<8;x[xi]=value;xi+=1
    stack={};sp=0;events=[];calls=[];wrappers={};selectors=[];held={};returned=False
    def clobber():
        for i in range(19):x[i]=('clobbered',)
        for i in range(8):d[i]=('clobbered',)
    for pc in range(start,end,4):
        w=image.u32(image.off(pc));rd=w&31;rn=(w>>5)&31
        if w&0x3a000000==0x28000000:
            vector=bool(w&(1<<26));regs=d if vector else x
            assert (w>>30)&3==(1 if vector else 2) and rn==31
            load=bool(w&(1<<22));mode=(w>>23)&3;assert mode in (1,2,3)
            rt2=(w>>10)&31;imm=(w>>15)&127
            if imm&64:imm-=128
            imm*=8
            if mode==3:assert not load;sp+=imm
            address=sp+(imm if mode==2 else 0)
            for off,reg in [(0,rd),(8,rt2)]:
                assert (8<=reg<=15) if vector else (19<=reg<=30)
                slot=address+off
                if load:
                    saved=stack.pop(slot);assert saved[:2]==(vector,reg);regs[reg]=saved[2]
                else:assert slot not in stack;stack[slot]=(vector,reg,regs[reg])
            if mode==1:assert load;sp+=imm
        elif w&0xffe0ffe0==0xaa0003e0:
            source=(w>>16)&31;assert source!=31;x[rd]=x[source]
        elif w&0xfffffc00==0x1e604000:d[rd]=d[rn]
        elif w&0x7fe00000==0x52800000:
            assert (w>>21)&3==0;x[rd]=('constant',(w>>5)&0xffff)
        elif w&0xffc003ff==0x910003fd:
            assert (w>>22)&1==0;x[29]=('frame',sp+((w>>10)&0xfff))
        elif w&0x9f000000==0x90000000:
            delta=((w>>5)&0x7ffff)*4+((w>>29)&3)
            if delta&(1<<20):delta-=1<<21
            x[rd]=('page',(pc&~0xfff)+(delta<<12))
        elif w&0xffc00000==0xf9400000:
            assert x[rn][0]=='page';reference=x[rn][1]+((w>>10)&0xfff)*8
            pointer=image.ptr(reference)
            if pointer==cell_class:x[rd]=('class','DVNCell')
            else:
                assert rd==1;name=image.string(pointer);assert name.startswith('set') or name=='sliderCellWithMinimum:maximum:divider:format:key:'
                x[rd]=('selector',name);selectors.append(dict(address=hex(pc),reference=hex(reference),name=name))
        elif w&0x7c000000==0x14000000:
            link=bool(w&(1<<31));destination=target(pc,w);local_wrappers={};name=runtime_symbol(image,destination,local_wrappers);wrappers.update(local_wrappers)
            calls.append(dict(address=hex(pc),target=hex(destination),symbol=name))
            if name=='_objc_retain':
                assert link and x[0][0]=='argument' and x[0][2].startswith('@');value=x[0]
                held[value]=held.get(value,0)+1;events.append(('retain',value));clobber();x[0]=value
            elif name=='_objc_release':
                assert link and x[0][0]=='argument' and held.get(x[0],0)>0
                held[x[0]]-=1;events.append(('release',x[0]));clobber()
            elif name=='_objc_alloc_init':
                assert link and x[0]==('class','DVNCell');events.append(('construct','DVNCell'));clobber();x[0]=('constructed',)
            elif name=='_objc_msgSend':
                assert x[1][0]=='selector';selector=x[1][1]
                if link:
                    assert x[0]==('constructed',);typ=property_types[selector];value=d[0] if typ=='d' else x[2]
                    assert value[0] in ('constant','argument')
                    if value[0]=='argument':
                        assert value[2]==typ or (typ.startswith('@') and value[2].startswith('@'))
                        if typ.startswith('@'):assert held.get(value,0)>0
                    events.append(('set',selector,value));clobber()
                else:
                    assert method['selector']=='sliderCellWithMinimum:maximum:divider:key:' and selector=='sliderCellWithMinimum:maximum:divider:format:key:'
                    assert x[0]==('receiver',) and x[2]==('constant',0)
                    events.append(('forward',selector,(d[0],d[1],d[2],x[2],x[3])));returned=True
            elif name=='_objc_autoreleaseReturnValue':
                assert not link and x[0]==('constructed',);events.append(('return',x[0]));returned=True
            else:raise AssertionError(('Unexpected factory call',hex(pc),name))
            if not link:assert pc==end-4
        else:raise AssertionError(('Unknown factory instruction',hex(pc),hex(w)))
    assert returned and sp==0 and not stack and all(n==0 for n in held.values())
    assert all(x[i]==incoming_x[i] for i in range(19,31))
    assert all(d[i]==incoming_d[i] for i in range(8,16))
    return dict(arguments=types,events=events,calls=calls,selectors=selectors,
                wrappers=[dict(address=hex(a),words=list(map(hex,words))) for a,words in sorted(wrappers.items())])
