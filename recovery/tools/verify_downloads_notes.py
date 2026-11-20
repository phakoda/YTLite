#!/usr/bin/env python3
"""Derive compact, address-preserving review notes; never execute binary code.
These notes are an index, not a decompiler/CFG proof. Consult the complete original
C and address-preserving assembly for branches, register flow, and ownership.
"""
import argparse, json, re, sys
from pathlib import Path
sys.dont_write_bytecode = True
from verify_downloads_evidence import ROOT, image, decode

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('kind', choices=['c','asm'])
p.add_argument('inputs', nargs='+')
a = p.parse_args()
m = image()
strings = {}
def cf(address):
    if address not in strings:
        try:
            flags = m.ptr(address + 8)
            if flags not in (0x7c8, 0x7d0): return None
            strings[address] = decode(m, address)
        except (ValueError, IndexError, UnicodeError): return None
    return strings[address]
for name in a.inputs:
    if a.kind == 'c':
        path = ROOT / ('recovery/decompiled/' + name + '.c' if re.fullmatch('[0-9a-f]{8}',name) else 'recovery/classes/' + name + '.c')
        if not path.exists():
            print('No separate decompiler function:', name)
            continue
        lines = path.read_text().splitlines()
        out = ['SOURCE: '+str(path.relative_to(ROOT)), 'INDEX ONLY: byte initializers, local declarations, and standalone ARC releases omitted.']
        for n,line in enumerate(lines,1):
            t=line.strip()
            if (re.match(r'(undefined\w*|uint|ulong|bool|code|ID|SEL|long|int|float|double)\b',t) and t.endswith(';') and '=' not in t) or not t: continue
            if ('&PTR_LAB_' in t or '&PTR_numberOfSections' in t) and re.fullmatch(r'\w+ = [^;]+;',t): continue
            if re.match(r'(s_.*\[.*\]|s_.*\._.*|unique0x.*) = ',t): continue
            if t.startswith('_objc_release(') or t.startswith('CallSupervisor('): continue
            line = re.sub(r'&PTR____CFConstantStringClassReference_([0-9a-f]+)',
                lambda x: '@'+json.dumps(cf(int(x[1],16)),ensure_ascii=False)+'/*'+x[1]+'*/' if cf(int(x[1],16)) is not None else x[0],line)
            line = re.sub(r'PTR_s_\w+_([0-9a-f]{8})',lambda x:'@selector('+m.string(m.ptr(int(x[1],16)))+')',line)
            out.append(f'{n}: {line}')
        dest=ROOT/'.recovery-work/downloads'/('notes-'+name+'.txt')
    else:
        path=ROOT/'.recovery-work/downloads'/name
        lines=path.read_text().splitlines(); selected=set()
        for i,line in enumerate(lines):
            event=(re.search(r'\t(?:bl|blr|br|ret|b\.|cb|tb)',line) and not any(x in line for x in ('_objc_release','_objc_retain','_objc_autorelease')))
            if event or line.startswith('Function'):
                selected.update(range(max(0,i-7),min(len(lines),i+5)))
        out=['SOURCE: '+str(path.relative_to(ROOT)),'INDEX ONLY: selected instruction windows; use complete assembly for flow.']
        previous=-1
        for i in sorted(selected):
            if i>previous+1:out.append('... omitted instructions ...')
            out.append(lines[i]);previous=i
        candidates={int(x,16) for x in re.findall(r'0x(11[0-9a-f]{5})\b', '\n'.join(lines))}
        for x in sorted(candidates):
            value=cf(x)
            if value is not None:out.append(f'CF {x:#x}: '+json.dumps(value,ensure_ascii=False))
        dest=path.with_name('notes-'+path.name)
    dest.write_text('\n'.join(out)+'\n')
    print(dest.relative_to(ROOT),len(out),'lines')
