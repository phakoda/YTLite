#!/usr/bin/env python3
"""Build browsable recovered interfaces, hook mapping and class implementation evidence."""
import argparse
import csv
import json
from pathlib import Path
import re
import subprocess
import struct
from inventory import MachO


def types(encoding):
    result=[];i=0
    simple={'v':'void','B':'BOOL','c':'signed char','C':'unsigned char','s':'short','S':'unsigned short',
            'i':'int','I':'unsigned int','l':'long','L':'unsigned long','q':'long long','Q':'unsigned long long',
            'f':'float','d':'double','#':'Class',':':'SEL','*':'char *','?':'void'}
    def one():
        nonlocal i
        while encoding[i] in 'rnNoORV': i+=1
        c=encoding[i];i+=1
        if c=='^': return one()+' *'
        if c=='@':
            if i<len(encoding) and encoding[i]=='?': i+=1
            elif i<len(encoding) and encoding[i]=='"':
                end=encoding.index('"',i+1);name=encoding[i+1:end];i=end+1
                return name+' *'
            return 'id'
        if c=='{':
            start=i;depth=1
            while depth:
                if encoding[i]=='{':depth+=1
                elif encoding[i]=='}':depth-=1
                i+=1
            return encoding[start:i-1].split('=')[0]
        if c in simple:return simple[c]
        raise ValueError('Unrecognized type '+encoding)
    while i<len(encoding):
        if encoding[i].isdigit():i+=1;continue
        result.append(one())
    return result


def declaration(method):
    ts=types(method['encoding']);sel=method['selector']
    if sel=='.cxx_destruct':return None
    ret=ts[0];args=ts[3:]
    if not args:return f'{method["kind"]} ({ret}){sel};'
    labels=sel.split(':')[:-1]
    assert len(labels)==len(args),(sel,ts)
    return f'{method["kind"]} ({ret})'+ ' '.join(f'{label}:({t})arg{i+1}' for i,(label,t) in enumerate(zip(labels,args)))+';'


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path)
    p.add_argument('--root',type=Path,default=Path('recovery'));a=p.parse_args();root=a.root
    m=MachO(a.binary.read_bytes());ev=root/'evidence'
    nm=subprocess.check_output(['nm',str(a.binary)],text=True)
    named={name:'0x'+addr for addr,name in re.findall(r'^([0-9a-f]+) [tT] (\S+)$',nm,re.M)}
    stubs={}
    start,size,_=m.sections['__stubs']
    for addr in range(start,start+size,12):
        adrp,ldr,br=struct.unpack_from('<III',m.data,m.off(addr))
        if adrp&0x9f000000!=0x90000000 or ldr&0xffc00000!=0xf9400000:continue
        imm=((adrp>>5)&0x7ffff)<<2|((adrp>>29)&3)
        if imm&(1<<20):imm-=1<<21
        pointer=(addr&~4095)+(imm<<12)+(((ldr>>10)&4095)*8)
        raw=struct.unpack_from('<Q',m.data,m.off(pointer))[0]
        if raw>>63:stubs[addr]=m.imports[raw&0xffffff]
    def terminal(addr):
        seen=set()
        while addr not in seen:
            if addr in stubs:return stubs[addr]
            seen.add(addr)
            try:words=struct.unpack_from('<6I',m.data,m.off(addr))
            except ValueError:return None
            if words[0]!=0xa9bf7bfd or words[1]&0xfc000000!=0x94000000:return None
            if words[2:4]!=(0xa8c17bfd,0xd65f03c0) and words[2:5]!=(0x12000000,0xa8c17bfd,0xd65f03c0):return None
            delta=words[1]&0x3ffffff
            if delta&(1<<25):delta-=1<<26
            addr=addr+4+delta*4
        return None
    classes=json.loads((ev/'arm-classes.json').read_text())
    strings={int(x['address'],16):x['value'] for x in json.loads((ev/'decoded-strings.json').read_text())}
    methods={int(f['address'],16):(c['name'],f) for c in classes for f in c['methods']}
    def readable(code):
        def cf(match):
            addr=int(match[1],16)
            try:
                value=m.cfstring(addr,strings)
                if '\0' not in value:
                    return '@'+json.dumps(value,ensure_ascii=False)
            except (ValueError, UnicodeError, struct.error):pass
            return match[0]
        code=re.sub(r'&PTR____CFConstantStringClassReference_([0-9a-fA-F]{8,16})',cf,code)
        def selector(match):
            try:return '@selector('+m.string(m.ptr(int(match[1],16)))+')'
            except ValueError:return match[0]
        return re.sub(r'PTR_s_\w+?_([0-9a-fA-F]{8,16})\b',selector,code)
    def string(expr):
        mt=re.search(r'_([0-9a-fA-F]{8,16})$',expr.strip().lstrip('&'))
        if not mt:return None
        addr=int(mt[1],16)
        if addr in strings:return strings[addr]
        try:
            if expr.startswith('PTR_s_'):return m.string(m.ptr(addr))
            return m.string(addr)
        except ValueError:return None
    recovered=root/'interfaces';recovered.mkdir(exist_ok=True)
    header=['// Recovered from Objective-C runtime metadata in the supplied 5.2.2 package.',
            '// Block signatures, generics and nullability are absent from method encodings.',
            '// id represents an opaque object or block where metadata has no further type.',
            '#pragma once','#import <UIKit/UIKit.h>','#import <AVFoundation/AVFoundation.h>','']
    header.append('@class '+', '.join(c['name'] for c in classes)+';\n')
    pending=list(classes);done=set()
    while pending:
        c=next(c for c in pending if c['superclass'] in done or c['superclass'] not in {x['name'] for x in pending})
        pending.remove(c);done.add(c['name'])
        header.append(f'@interface {c["name"]} : {c["superclass"] or "NSObject"}')
        for method in c['methods']:
            d=declaration(method)
            if d:header.extend([f'// {method["address"]}; {method["encoding"]}',d])
        header.extend(['@end',''])
    (recovered/'RecoveredInterfaces.h').write_text('\n'.join(header))
    hooks=[]
    valid_files={row['file'] for row in csv.DictReader((root/'decompiled/index.tsv').open(),delimiter='\t') if row['status']=='ok'}
    for f in sorted((root/'decompiled').glob('*.c')):
        if f.name not in valid_files: continue
        code=f.read_text();variables={};aliases={};last_class=None
        # Read complete statements because the decompiler wraps long hook calls.
        for statement in code.split(';'):
            match=re.search(r'(?:(\w+) = )?_objc_getClass\(([^)]+)\)\s*$',statement)
            if match:
                name=string(match[2])
                last_class=(name,'-') if name else None
                if match[1]:variables[match[1]]=last_class or (None,'?')
            match=re.search(r'(\w+) = _object_getClass\((\w*)\)\s*$',statement)
            if match:
                source=variables.get(match[2]) if match[2] else last_class
                variables[match[1]]=(source[0],'+') if source else (None,'?')
            match=re.search(r'(\w+) = _sel_registerName\(([^)]+)\)\s*$',statement)
            if match:
                value=string(match[2])
                if value is not None:aliases[match[1]]=value
            match=re.search(r'(\w+) = (?:\([^)]*\)\s*)?([\w&]+)\s*$',statement)
            if match:
                value=aliases.get(match[2],string(match[2]))
                if value is not None:aliases[match[1]]=value
            match=re.search(r'(_MSHookMessageEx|_class_addMethod|(?:thunk_)?FUN_[0-9a-f]+)\((.*?)\)\s*$',statement,re.S)
            if not match:continue
            function=match[1]
            api=terminal(int(function.rsplit('_',1)[1],16)) if 'FUN_' in function else function
            if api not in ['_MSHookMessageEx','_class_addMethod']:continue
            args=[x.strip() for x in match[2].split(',')]
            if len(args) not in [3,4]:continue
            cls,kind=variables.get(args[0],(None,'?'))
            selector=aliases.get(args[1],string(args[1]));imp=re.search(r'_([0-9a-fA-F]{8,16})$',args[2])
            orig=re.search(r'(?:_|0x)([0-9a-fA-F]{6,16})$',args[3]) if api=='_MSHookMessageEx' and len(args)==4 else None
            implementation='0x'+imp[1] if imp else named.get(args[2],args[2])
            hooks.append(dict(class_name=cls,kind=kind,selector=selector,implementation=implementation,operation='replace' if api=='_MSHookMessageEx' else 'add',
                              original_pointer=('0x'+orig[1] if orig else args[3]) if api=='_MSHookMessageEx' else None,registration=f.stem,
                              complete=bool(cls and selector and implementation.startswith('0x'))))
    (ev/'hooks.json').write_text(json.dumps(hooks,ensure_ascii=False,indent=2)+'\n')
    byclass={}
    for hook in hooks:
        if hook['complete']:byclass.setdefault(hook['class_name'],[]).append(hook)
    hookdir=root/'hooks';hookdir.mkdir(exist_ok=True)
    for old in hookdir.glob('*.c'):
        if old.stem not in byclass:old.unlink()
    for cls,items in byclass.items():
        lines=[f'// Decompiled hook evidence for {cls}. This is not compilable Logos source.\n']
        for item in items:
            path=root/'decompiled'/f'{int(item["implementation"],16):08x}.c'
            lines.append(f'// {item["kind"]}[{cls} {item["selector"]}], original IMP slot {item["original_pointer"]}')
            lines.append(readable(path.read_text()) if path.name in valid_files else '// Implementation not yet decompiled. See hooks.json.\n')
        (hookdir/f'{cls}.c').write_text('\n'.join(lines))
    classdir=root/'classes';classdir.mkdir(exist_ok=True)
    for c in classes:
        lines=[f'// Decompiled implementation evidence for {c["name"]}. Not compilable source.\n']
        for method in c['methods']:
            address=int(method['address'],16);path=root/'decompiled'/f'{address:08x}.c'
            lines.append(f'// {method["kind"]}[{c["name"]} {method["selector"]}], {method["address"]}')
            lines.append(readable(path.read_text()) if path.name in valid_files else '// No decompiler export; consult metadata and original binary.\n')
        (classdir/f'{c["name"]}.c').write_text('\n'.join(lines))
    print(f'Generated {len(classes)} class interfaces; mapped {sum(x["complete"] for x in hooks)}/{len(hooks)} hook registrations')


if __name__=='__main__':main()
