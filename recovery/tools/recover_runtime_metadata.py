#!/usr/bin/env python3
"""Recover category, initializer, load-command and block contracts as data only."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]
EVIDENCE = REPO / 'recovery/evidence'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--block', action='append', type=lambda value: int(value, 0), default=[])
    parser.add_argument('--pointer', action='append', type=lambda value: int(value, 0), default=[])
    parser.add_argument('--quiet', action='store_true', help='Print only requested block/pointer results.')
    args = parser.parse_args()
    data = (REPO / '.recovery-work/arm/YTLite.dylib').read_bytes()
    expected = next(item['binary_sha256'] for item in json.loads((EVIDENCE / 'packages.json').read_text())
                    if item['package'].endswith('iphoneos-arm.deb'))
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError('Original binary hash differs from supplied package')
    macho = MachO(data)

    def class_name(address):
        raw = struct.unpack_from('<Q', data, macho.off(address))[0]
        if raw >> 63:
            return macho.imports[raw & 0xffffff].removeprefix('_OBJC_CLASS_$_')
        cls = macho.ptr(address)
        return macho.string(macho.ptr((macho.ptr(cls + 32) & ~7) + 24)) if cls else None

    def properties(pointer):
        if not pointer:
            return []
        stride, count = struct.unpack_from('<II', data, macho.off(pointer))
        if stride != 16 or count > 10000:
            raise ValueError('Unexpected property-list layout')
        return [{'name': macho.string(macho.ptr(pointer + 8 + index * stride)),
                 'attributes': macho.string(macho.ptr(pointer + 16 + index * stride))} for index in range(count)]

    categories = []
    for section in ('__objc_catlist', '__objc_nlcatlist'):
        if section not in macho.sections:
            continue
        start, size, _ = macho.sections[section]
        for slot in range(start, start + size, 8):
            address = macho.ptr(slot)
            categories.append({'address': hex(address), 'list': section,
                               'name': macho.string(macho.ptr(address)), 'class': class_name(address + 8),
                               'methods': macho.methods(macho.ptr(address + 16), '-') + macho.methods(macho.ptr(address + 24), '+'),
                               'instance_properties': properties(macho.ptr(address + 40)),
                               'class_properties': properties(macho.ptr(address + 48))})
    initializers = []
    if '__init_offsets' in macho.sections:
        start, size, _ = macho.sections['__init_offsets']
        for slot in range(start, start + size, 4):
            initializers.append({'slot': hex(slot), 'address': hex(macho.u32(macho.off(slot))), 'format': 'image-relative-offset'})
    if '__mod_init_func' in macho.sections:
        start, size, _ = macho.sections['__mod_init_func']
        for slot in range(start, start + size, 8):
            initializers.append({'slot': hex(slot), 'address': hex(macho.ptr(slot)), 'format': 'pointer'})
    loads = []
    position = 32
    for _ in range(struct.unpack_from('<I', data, 16)[0]):
        command, size = struct.unpack_from('<II', data, position)
        if command in (0xc, 0xd, 0x80000018, 0x8000001f, 0x80000023):
            offset, timestamp, current, compatibility = struct.unpack_from('<IIII', data, position + 8)
            name = data[position + offset:position + size].split(b'\0')[0].decode('utf-8')
            loads.append({'command': hex(command), 'name': name, 'current_version': current, 'compatibility_version': compatibility})
        position += size
    report = {'binary_sha256': expected, 'categories': categories, 'initializers': initializers, 'dylib_commands': loads}
    (EVIDENCE / 'runtime-metadata.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    if not args.quiet:
        print(json.dumps(report, ensure_ascii=False, indent=2))
    for address in args.pointer:
        print(f'Pointer at {address:#x}: {macho.ptr(address):#x}')
    blocks = []
    for address in args.block:
        flags = macho.u32(macho.off(address + 8))
        descriptor = macho.ptr(address + 24)
        block = {'address': hex(address), 'flags': hex(flags), 'invoke': hex(macho.ptr(address + 16)),
                 'descriptor': hex(descriptor), 'size': struct.unpack_from('<Q', data, macho.off(descriptor + 8))[0]}
        cursor = descriptor + 16
        if flags & (1 << 25):
            block['copy'] = hex(macho.ptr(cursor)); block['dispose'] = hex(macho.ptr(cursor + 8)); cursor += 16
        if flags & (1 << 30):
            block['signature'] = macho.string(macho.ptr(cursor))
        blocks.append(block)
        print('Block:', json.dumps(block, ensure_ascii=False))
    if blocks:
        path = REPO / '.recovery-work/analysis/block-contracts.json'
        path.parent.mkdir(parents=True, exist_ok=True)
        previous = json.loads(path.read_text()) if path.exists() else {}
        previous.update({block['address']: block for block in blocks})
        path.write_text(json.dumps(previous, ensure_ascii=False, indent=2) + '\n')


if __name__ == '__main__':
    main()
