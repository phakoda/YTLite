#!/usr/bin/env python3
"""Evaluate constant ARM64 byte-decryption sequences without executing the dylib.

Only writes whose address and value are known constants are retained. Unknown
instructions invalidate their destination; calls and branches reset registers.
The output records every recovered byte's instruction address for auditing.
"""
import argparse
import json
from pathlib import Path
import re
import struct
from inventory import MachO


def decode(binary, assembly):
    macho = MachO(binary)
    registers = {}
    stack = {}
    writes = {}
    provenance = {}
    def key(s): return 'x'+s[1:] if re.fullmatch('[wx][0-9]+', s) else s
    def val(s):
        s = s.strip()
        if s in ['wzr','xzr']: return 0
        if s.startswith('#'): return int(s[1:], 0)
        return registers[key(s)]
    def setreg(s, v): registers[key(s)] = v & ((1 << (32 if s.startswith('w') else 64))-1)
    for line in assembly.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(\w+(?:\.\w+)?)\s*(.*)', line)
        if not match: continue
        pc, op, operands = match.groups()
        pc = int(pc,16)
        if pc in macho.function_starts: registers.clear();stack.clear()
        operands = operands.split(';')[0].strip()
        parts = [p.strip() for p in operands.split(',')]
        dest = parts[0]
        try:
            if op in ['bl','blr','br','ret','b'] or op.startswith('b.'):
                registers.clear()
                stack.clear()
            elif op == 'adrp' or op == 'adr': setreg(dest, int(parts[1],16))
            elif op == 'mov': setreg(dest, val(parts[1]))
            elif op == 'movk':
                shift = int(parts[2].split('#')[1],0) if len(parts)>2 else 0
                setreg(dest, (val(dest) & ~(0xffff << shift)) | (val(parts[1]) << shift))
            elif op in ['add','sub','eor','orr','and']:
                a,b = val(parts[1]),val(parts[2])
                if len(parts)>3:
                    if parts[3].startswith('lsl #'): b <<= int(parts[3].split('#')[1],0)
                    else: raise KeyError('unsupported shift')
                setreg(dest, {'add':lambda:a+b, 'sub':lambda:a-b, 'eor':lambda:a^b, 'orr':lambda:a|b, 'and':lambda:a&b}[op]())
            elif op == 'neg': setreg(dest,-val(parts[1]))
            elif op == 'mvn': setreg(dest,~val(parts[1]))
            elif op in ['ldrb','ldrh','ldr','ldur','strb','strh','str','stur']:
                spill = re.search(r'\[(sp|x29)(?:,\s*(#-?(?:0x[0-9a-f]+|[0-9]+)))?\]$', operands)
                if spill:
                    location=(spill[1],val(spill[2]) if spill[2] else 0)
                    if op.startswith('st'): stack[location]=val(dest)
                    else: setreg(dest,stack[location])
                    continue
                mem = re.search(r'\[([xw][0-9]+)(?:,\s*(#-?(?:0x[0-9a-f]+|[0-9]+)))?\]$', operands)
                if not mem: raise KeyError('nonconstant address')
                addr=val(mem[1])+(val(mem[2]) if mem[2] else 0)
                off=macho.off(addr)
                width=1 if op.endswith('b') else 2 if op.endswith('h') else 8 if dest.startswith('x') else 4
                if op.startswith('st'):
                    value=val(dest)
                    for i in range(width):
                        writes[addr+i]=(value>>(i*8))&255
                        provenance[addr+i]=pc
                else:
                    value=int.from_bytes(bytes(writes.get(addr+i,binary[off+i]) for i in range(width)),'little')
                    # 64-bit address loads may carry Mach-O chained rebase bits.
                    if width==8 and value >> 48: value &= (1<<36)-1
                    setreg(dest,value)
            elif re.fullmatch('[wx][0-9]+',dest) and op not in ['cmp','cmn','tst','str','stur','stp','stlr']:
                registers.pop(key(dest),None)
        except (KeyError,ValueError,IndexError):
            if not op.startswith('st'): registers.pop(key(dest),None)
    strings=[]
    addresses=sorted(writes)
    i=0
    while i<len(addresses):
        start=addresses[i]; buf=bytearray(); sources=[]; pos=start
        while pos in writes:
            byte=writes[pos]; sources.append(hex(provenance[pos])); pos+=1
            if byte==0: break
            buf.append(byte)
        if buf and writes.get(pos-1)==0:
            try:
                text=buf.decode('utf-8')
                if all(c.isprintable() or c in '\n\r\t' for c in text):
                    strings.append(dict(address=hex(start),value=text,instructions=sources))
            except UnicodeDecodeError: pass
        while i<len(addresses) and addresses[i]<pos: i+=1
    return strings,writes,provenance


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary',type=Path);p.add_argument('assembly',type=Path)
    p.add_argument('--output',type=Path,default=Path('recovery/evidence'))
    a=p.parse_args()
    strings,writes,provenance=decode(a.binary.read_bytes(),a.assembly.read_text())
    a.output.mkdir(parents=True,exist_ok=True)
    (a.output/'decoded-strings.json').write_text(json.dumps(strings,ensure_ascii=False,indent=2)+'\n')
    (a.output/'decoded-bytes.tsv').write_text('address\tbyte\tinstruction\n'+''.join(f'{p:x}\t{v:02x}\t{provenance[p]:x}\n' for p,v in sorted(writes.items())))
    print(f'Recovered {len(strings)} terminated UTF-8 strings from {len(writes)} constant byte writes')


if __name__=='__main__': main()
