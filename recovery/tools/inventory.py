#!/usr/bin/env python3
"""Reproduce package, string, symbol and Objective-C metadata recovery locally."""
import argparse
import hashlib
import io
import json
from pathlib import Path
import re
import struct
import subprocess
import tarfile


def sha(data):
    return hashlib.sha256(data).hexdigest()


class MachO:
    def __init__(self, data):
        self.data = data
        assert self.u32(0) == 0xFEEDFACF, 'Expected thin 64-bit Mach-O'
        self.sections = {}
        # Section names are only unique within a segment. In these packages,
        # __TEXT,__const and __DATA_CONST,__const both exist. Keep the legacy
        # name index for existing reports, but never use it for VA resolution.
        self.section_records = []
        self.zerofill = set()
        self.imports = []
        self.function_starts = set()
        self.chained_pointers = {}
        pos = 32
        for _ in range(self.u32(16)):
            cmd, size = struct.unpack_from('<II', data, pos)
            if cmd == 0x19:
                segment = data[pos+8:pos+24].split(b'\0')[0].decode()
                for i in range(self.u32(pos + 64)):
                    p = pos + 72 + i * 80
                    name = data[p:p+16].split(b'\0')[0].decode()
                    addr, length, off = struct.unpack_from('<QQI', data, p+32)
                    self.sections[name] = (addr, length, off)
                    zero = self.u32(p+64) & 0xff in [1,12,18]
                    self.section_records.append(dict(segment=segment, name=name,
                        address=addr, size=length, offset=off, zerofill=zero))
                    if zero: self.zerofill.add(name)
            elif cmd == 0x80000034:
                fixups=self.u32(pos+8)
                _,starts,imports,symbols,count,fmt,_=struct.unpack_from('<7I',data,fixups)
                assert fmt in [1,2,3], 'Unsupported chained imports format'
                for i in range(count):
                    p=fixups+imports+i*{1:4,2:8,3:16}[fmt]
                    nameoff=(struct.unpack_from('<Q',data,p)[0]>>32) if fmt==3 else (self.u32(p)>>9)
                    p=fixups+symbols+nameoff
                    self.imports.append(data[p:data.index(0,p)].decode())
                self._fixups_starts = fixups + starts
            elif cmd == 0x26:
                cursor=self.u32(pos+8);end=cursor+self.u32(pos+12);address=0
                while cursor<end:
                    delta=0;shift=0
                    while True:
                        byte=data[cursor];cursor+=1;delta|=(byte&127)<<shift;shift+=7
                        if byte<128:break
                    if delta==0:break
                    address+=delta;self.function_starts.add(address)
            pos += size
        if hasattr(self, '_fixups_starts'):
            starts = self._fixups_starts
            for index in range(self.u32(starts)):
                relative = self.u32(starts + 4 + index * 4)
                if relative == 0: continue
                record = starts + relative
                size, page_size, pointer_format, segment_offset, _, page_count = struct.unpack_from('<IHHQIH', data, record)
                if pointer_format not in [2, 6]:
                    raise ValueError('Unsupported chained pointer format: '+str(pointer_format))
                page_starts = struct.unpack_from('<' + 'H' * ((size - 22)//2), data, record + 22)
                for page in range(page_count):
                    start = page_starts[page]
                    if start == 0xffff: continue
                    chains = []
                    if start & 0x8000:
                        overflow = start & 0x7fff
                        while True:
                            entry = page_starts[overflow]
                            chains.append(entry & 0x7fff)
                            if entry & 0x8000: break
                            overflow += 1
                    else: chains.append(start)
                    for chain in chains:
                        address = segment_offset + page * page_size + chain
                        while True:
                            raw = struct.unpack_from('<Q', data, self.off(address))[0]
                            # None denotes an imported pointer, whose runtime address
                            # is deliberately not invented by the static analyzer.
                            self.chained_pointers[address] = (None if raw >> 63 else
                                (raw & ((1 << 36)-1)) | (((raw >> 36) & 255) << 56))
                            step = (raw >> 51) & 0xfff
                            if not step: break
                            address += step * 4

    def u32(self, p): return struct.unpack_from('<I', self.data, p)[0]
    def off(self, addr):
        for section in self.section_records:
            if section['address'] <= addr < section['address'] + section['size']:
                if section['zerofill']: raise ValueError('No file bytes for zero-fill '+hex(addr))
                return section['offset'] + addr - section['address']
        raise ValueError(hex(addr))
    def ptr(self, addr):
        # These images use DYLD_CHAINED_PTR_64: rebases store a 36-bit target.
        return struct.unpack_from('<Q', self.data, self.off(addr))[0] & ((1 << 36) - 1)
    def superclass(self, cls):
        raw=struct.unpack_from('<Q',self.data,self.off(cls+8))[0]
        if raw>>63: return self.imports[raw&0xffffff].removeprefix('_OBJC_CLASS_$_')
        if raw==0: return None
        parent=raw&((1<<36)-1)
        return self.string(self.ptr((self.ptr(parent+32)&~7)+24))
    def rel(self, addr): return addr + struct.unpack_from('<i', self.data, self.off(addr))[0]
    def string(self, addr):
        off = self.off(addr)
        return self.data[off:self.data.index(0, off)].decode('utf-8', errors='replace')
    def cfstring(self, addr, decoded=None):
        """Decode a known constant NSString structure, including UTF-16 literals."""
        flags = self.u32(self.off(addr + 8))
        pointer = self.ptr(addr + 16)
        length = struct.unpack_from('<Q', self.data, self.off(addr + 24))[0]
        if length > len(self.data): raise ValueError('Invalid constant-string length')
        wide = bool(flags & 0x10)
        if decoded and pointer in decoded:
            value = decoded[pointer]
            encoded = value.encode('utf-16-le' if wide else 'utf-8')
            if len(encoded) == length * (2 if wide else 1): return value
            raise ValueError('Decoded string length does not match constant metadata')
        off = self.off(pointer)
        return self.data[off:off + length * (2 if wide else 1)].decode('utf-16-le' if wide else 'utf-8')
    def section(self, name):
        _, size, off = self.sections[name]
        if name in self.zerofill: return bytes(size)
        return self.data[off:off+size]
    def methods(self, addr, kind):
        if not addr: return []
        flags, count = struct.unpack_from('<II', self.data, self.off(addr))
        result = []
        for i in range(count):
            p = addr + 8 + i * (flags & 0xffff)
            if flags & 0x80000000:
                sel = self.rel(p)
                if not flags & 0x40000000: sel = self.ptr(sel)
                types, imp = self.rel(p+4), self.rel(p+8)
            else:
                sel, types, imp = self.ptr(p), self.ptr(p+8), self.ptr(p+16)
            result.append(dict(kind=kind, selector=self.string(sel), encoding=self.string(types), address=hex(imp)))
        return result
    def classes(self):
        addr, size, _ = self.sections['__objc_classlist']
        result = []
        for p in range(addr, addr+size, 8):
            cls = self.ptr(p)
            ro = self.ptr(cls+32) & ~7
            meta = self.ptr(cls)
            mro = self.ptr(meta+32) & ~7
            props = self.ptr(ro+64)
            properties = []
            if props:
                stride, count = struct.unpack_from('<II', self.data, self.off(props))
                for i in range(count):
                    q = props+8+i*stride
                    properties.append(dict(name=self.string(self.ptr(q)), attributes=self.string(self.ptr(q+8))))
            result.append(dict(name=self.string(self.ptr(ro+24)), address=hex(cls), superclass=self.superclass(cls),
                               methods=self.methods(self.ptr(ro+32), '-') + self.methods(self.ptr(mro+32), '+'), properties=properties))
        return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('packages', nargs='+', type=Path)
    parser.add_argument('--output', type=Path, default=Path('recovery/evidence'))
    args = parser.parse_args()
    out = args.output
    out.mkdir(parents=True, exist_ok=True)
    manifests = []
    for package in sorted(args.packages):
        data = package.read_bytes()
        members = subprocess.check_output(['ar', '-t', str(package)], text=True).splitlines()
        payload = subprocess.check_output(['ar', '-p', str(package), next(m for m in members if m.startswith('data.tar'))])
        files = {}
        with tarfile.open(fileobj=io.BytesIO(payload), mode='r:*') as tf:
            for member in tf:
                if member.isfile(): files[member.name.lstrip('./')] = tf.extractfile(member).read()
        dylib_path = next(p for p in files if p.endswith('/YTLite.dylib'))
        macho = MachO(files[dylib_path])
        tag = package.stem.rsplit('iphoneos-', 1)[1]
        classes = macho.classes()
        (out/f'{tag}-classes.json').write_text(json.dumps(classes, indent=2)+'\n')
        for section in ['__cstring', '__objc_methname']:
            strings = sorted(set(s.decode('utf-8', errors='replace') for s in macho.section(section).split(b'\0') if s))
            (out/f'{tag}-{section.strip("_")}.json').write_text(json.dumps(strings, ensure_ascii=False, indent=2)+'\n')
        constants = []
        start, size, _ = macho.sections['__cfstring']
        for addr in range(start, start+size, 32):
            flags = macho.ptr(addr+8)
            pointer, length = macho.ptr(addr+16), macho.ptr(addr+24)
            off = macho.off(pointer)
            wide = bool(flags & 0x10)
            value = macho.data[off:off+length*(2 if wide else 1)].decode('utf-16-le' if wide else 'utf-8', errors='replace')
            constants.append(dict(address=hex(addr), value=value))
        (out/f'{tag}-cfstrings.json').write_text(json.dumps(constants, ensure_ascii=False, indent=2)+'\n')
        resources = out.parent/'resources'/tag
        for path, contents in files.items():
            if 'YTLite.bundle/' in path:
                dest = resources/'YTLite.bundle'/path.split('YTLite.bundle/',1)[1]
                dest.parent.mkdir(parents=True, exist_ok=True)
                dest.write_bytes(contents)
        manifests.append(dict(package=package.name, sha256=sha(data), binary_sha256=sha(files[dylib_path]),
                              sections={k:dict(address=hex(v[0]), size=v[1], sha256=sha(macho.section(k))) for k,v in macho.sections.items()},
                              files={p:dict(size=len(v), sha256=sha(v)) for p,v in files.items()},
                              class_count=len(classes), method_count=sum(len(c['methods']) for c in classes)))
    (out/'packages.json').write_text(json.dumps(manifests, indent=2)+'\n')
    print(json.dumps([{k:m[k] for k in ['package','class_count','method_count']} for m in manifests], indent=2))


if __name__ == '__main__': main()
