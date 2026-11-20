"""Strictly recognize reviewed DVNCell accessor bodies and compiled LLVM forms."""
import re
import struct


def ivars(image,cls):
    ro=image.ptr(int(cls['address'],16)+32)&~7;table=image.ptr(ro+48)
    stride,count=struct.unpack_from('<II',image.data,image.off(table));assert stride==32
    result=[]
    for index in range(count):
        a=table+8+index*stride
        result.append(dict(name=image.string(image.ptr(a+8)),encoding=image.string(image.ptr(a+16)),
            offset=image.u32(image.off(image.ptr(a))),size=image.u32(image.off(a+28))))
    return result


def target(address,word):
    assert word&0x7c000000==0x14000000
    delta=word&0x3ffffff
    if delta&(1<<25):delta-=1<<26
    return address+delta*4


def runtime_symbol(image,address,wrappers):
    words=[image.u32(image.off(address+i*4)) for i in range(4)]
    if words[0]==0xa9bf7bfd and words[1]&0xfc000000==0x94000000 and words[2:]==[0xa8c17bfd,0xd65f03c0]:
        assert address not in wrappers
        wrappers[address]=words
        return runtime_symbol(image,target(address+4,words[1]),wrappers)
    adrp,ldr,branch=words[:3]
    assert adrp&0x9f00001f==0x90000010 and ldr&0xffc003ff==0xf9400210 and branch==0xd61f0200,('Unknown runtime stub',hex(address),list(map(hex,words)))
    delta=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
    if delta&(1<<20):delta-=1<<21
    reference=(address&~0xfff)+(delta<<12)+((ldr>>10)&0xfff)*8
    raw=struct.unpack_from('<Q',image.data,image.off(reference))[0]
    assert raw>>63
    return image.imports[raw&0xffffff]


def original_contract(image,method,ivar,attributes,end):
    start=int(method['address'],16);pairs=[(a,image.u32(image.off(a))) for a in range(start,end,4)]
    omitted=[];svc=[i for i,(_,w) in enumerate(pairs) if w&0xffe0001f==0xd4000001]
    assert len(svc)<=1
    if svc:
        i=svc[0];assert i>=5
        setup=pairs[i-5:i];values={}
        for a,w in setup:
            assert w&0x7fe00000==0x52800000,('Unknown trap preparation',hex(a),hex(w))
            reg=w&31;assert reg not in values;values[reg]=(w>>5)&0xffff
        assert values in ({0:31,1:0,2:0,3:0,16:26},{0:26,1:31,2:0,3:0,16:0})
        omitted=pairs[i-5:i+1];pairs=pairs[:i-5]+pairs[i+1:]
    words=[w for _,w in pairs];offset=ivar['offset'];kind=ivar['encoding'];setter=method['selector'].endswith(':');wrappers={};calls=[]
    def call(i,name,link):
        a,w=pairs[i];assert w&0xfc000000==(0x94000000 if link else 0x14000000)
        addr=target(a,w);assert runtime_symbol(image,addr,wrappers)==name
        calls.append(dict(address=hex(a),target=hex(addr),symbol=name))
    framed=words[:2]==[0xa9bf7bfd,0x910003fd]
    if not setter and 'W' in attributes.split(','):
        assert words[:3]==[0xa9bf7bfd,0x910003fd,0x91000000+(offset<<10)] and words[4]==0xa8c17bfd and len(words)==6
        call(3,'_objc_loadWeakRetained',True);call(5,'_objc_autoreleaseReturnValue',False);contract='weak-get'
    elif not setter:
        opcode=0xfd400000 if kind=='d' else 0x39400000 if kind=='B' else 0xf9400000
        scale=1 if kind=='B' else 8;assert offset%scale==0
        assert words==[opcode+((offset//scale)<<10),0xd65f03c0];contract='load'
    elif kind in ('d','q','B'):
        opcode=0xfd000000 if kind=='d' else 0x39000002 if kind=='B' else 0xf9000002
        scale=1 if kind=='B' else 8;assert offset%scale==0
        assert words==[opcode+((offset//scale)<<10),0xd65f03c0];contract='store'
    elif 'C' in attributes.split(','):
        mov=0x52800003+(offset<<5)
        if framed:
            assert len(words)==6 and words[2]==mov and words[4:]==[0xa8c17bfd,0xd65f03c0];call(3,'_objc_setProperty_nonatomic_copy',True)
        else:
            assert len(words)==2 and words[0]==mov;call(1,'_objc_setProperty_nonatomic_copy',False)
        contract='copy-set'
    else:
        name='_objc_storeWeak' if 'W' in attributes.split(',') else '_objc_storeStrong'
        core=[0xaa0203e1,0x91000000+(offset<<10)]
        if framed:
            assert len(words)==7 and words[2:4]==core and words[5:]==[0xa8c17bfd,0xd65f03c0];call(4,name,True)
        else:
            assert len(words)==3 and words[:2]==core;call(2,name,False)
        contract='weak-set' if 'W' in attributes.split(',') else 'strong-set'
    return dict(operation=contract,offset=offset,type=kind,omitted=[dict(address=hex(a),word=hex(w)) for a,w in omitted],
        calls=calls,wrappers=[dict(address=hex(a),words=list(map(hex,ws))) for a,ws in sorted(wrappers.items())])


def llvm_contract(text,class_name,selector,contract):
    definition=next(line for line in text.splitlines() if line.startswith('define internal ') and f'-[{class_name} {selector}]' in line)
    body=text[text.index(definition):].split('\n}',1)[0].split('\n')[1:]
    lines=[]
    for line in body:
        line=line.strip().split(', !')[0]
        line=re.sub(r' #\d+','',line)
        line=re.sub(r'\b(?:noundef|nonnull) ','',line)
        if line:lines.append(line)
    off=contract['offset'];op=contract['operation'];typ=contract['type'];expected=[]
    gep=lambda name:f'{name} = getelementptr inbounds i8, ptr %0, i64 {off}'
    t='double' if typ=='d' else 'i64' if typ=='q' else 'ptr'
    if op=='load':
        if typ=='B':expected=[gep('%3'),'%4 = load i8, ptr %3, align 1','%5 = trunc nuw i8 %4 to i1','ret i1 %5']
        else:expected=[gep('%3'),f'%4 = load {t}, ptr %3, align 8',f'ret {t} %4']
    elif op=='store':
        if typ=='B':expected=['%4 = zext i1 %2 to i8',gep('%5'),'store i8 %4, ptr %5, align 1','ret void']
        else:expected=[gep('%4'),f'store {t} %2, ptr %4, align 8','ret void']
    elif op=='strong-set':expected=[gep('%4'),'%5 = tail call ptr @llvm.objc.retain(ptr %2)','%6 = load ptr, ptr %4, align 8','store ptr %2, ptr %4, align 8','tail call void @llvm.objc.release(ptr %6)','ret void']
    elif op=='weak-get':expected=[gep('%3'),'%4 = tail call ptr @llvm.objc.loadWeakRetained(ptr %3)','%5 = tail call ptr @llvm.objc.autoreleaseReturnValue(ptr %4)','ret ptr %4']
    elif op=='weak-set':expected=[gep('%4'),'%5 = tail call ptr @llvm.objc.storeWeak(ptr %4, ptr %2)','ret void']
    elif op=='copy-set':expected=[f'tail call void @objc_setProperty_nonatomic_copy(ptr %0, ptr %1, ptr %2, i64 {off})','ret void']
    else:raise AssertionError(op)
    assert lines==expected,(selector,lines,expected)
    return lines
