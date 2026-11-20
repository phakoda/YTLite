#!/usr/bin/env python3
"""Check manually identified playback branch tables against the untouched input.

These are data reads, not execution or patching. The Boolean expression selecting
an index is recorded separately from the ARM64 instructions that compute it.
The report supplements, and never replaces, the original decompiler evidence.
"""
import hashlib
import json
from pathlib import Path
import struct
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]

# (branch instruction, table address, XOR constant, manually reviewed predicate)
TABLES = [
    (0x19e3b8, 0x11ac968, 0xc2d88fb9, '_playedProgressRoundedCorners ivar is absent'),
    (0x19e7e0, 0x11ac9d0, 0x5f621512, 'category mode equals zero'),
    (0x19e984, 0x11ac9e8, 0xe31a5a0a, 'markerEnd > viewportLeft and markerStart < viewportRight'),
    (0x19ea58, 0x11aca00, 0x29e99a15, 'rounded-corner radius equals zero'),
    (0x19eaac, 0x11aca18, 0xba77943c, 'relativeRight < width - 0.5 and relativeLeft > 0.5'),
    (0x19ec4c, 0x11aca38, 0x175a0f40, 'UUID was already drawn in this call'),
    (0x19fa10, 0x11acc38, 0x50d0c7e1, 'category mode equals zero'),
    (0x19fb64, 0x11acc50, 0x4a447c5a, 'isnan(markerStart) or not markerWidth > zero'),
    (0x19fbdc, 0x11acc68, 0x0f8b69f4, 'markerWidth is not NaN'),
    (0x19fc10, 0x11acc80, 0x7d65a0dc, 'UUID has no cached layer'),
    (0x19f2e0, 0x11acae0, 0x243ae6a4, 'provided layer is nil'),
    (0x19f374, 0x11acb10, 0x5b69da35, 'bar view has no window'),
    (0x19f728, 0x11acbc0, 0x3a1e4520, 'no cached segments for video ID'),
    (0x19f790, 0x11acbd8, 0x131ec3b0, 'bar layer width is greater than zero'),
    (0x1a0890, 0x11acda8, 0x93440099, 'category mode equals zero'),
    (0x1a0b10, 0x11ace08, 0xc3ac6e6f, 'chapter view has no window'),
    (0x1a0b4c, 0x11ace20, 0x5034b7c0, 'chapter view bounds are empty'),
    (0x1a0b8c, 0x11ace38, 0x40125e3e, 'chapter frame x is not NaN'),
    (0x1a0c54, 0x11ace50, 0xa0ed0f7f, 'chapter frame y is not NaN'),
    (0x1a0d14, 0x11ace68, 0x38c184ab, 'chapter dimensions are valid and marker end is after left edge'),
    (0x1a0d4c, 0x11ace80, 0x69217a45, 'marker start is before right edge'),
    (0x1a0d94, 0x11ace98, 0x43290051, 'clipped marker width is not NaN'),
    (0x1a0dd4, 0x11aceb0, 0x5c6ae0e2, 'relative x is NaN or clipped width is not positive'),
    (0x1a0e2c, 0x11acec8, 0x1ce70932, 'UUID was already drawn in a chapter view'),
]


def main():
    path = REPO / '.recovery-work/arm/YTLite.dylib'
    data = path.read_bytes()
    expected = next(item for item in json.loads((REPO / 'recovery/evidence/packages.json').read_text())
                    if item['package'].endswith('iphoneos-arm.deb'))['binary_sha256']
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError('The analysis input no longer matches the supplied evidence.')
    macho = MachO(data)
    report = []
    for pc, table, key, predicate in TABLES:
        instruction = macho.u32(macho.off(pc))
        if instruction & 0xfffffc1f != 0xd61f0000:
            raise ValueError(f'{pc:#x} is not an indirect branch.')
        encoded_delta = macho.u32(macho.off(table + 16))
        delta = struct.unpack('<i', struct.pack('<I', encoded_delta ^ key))[0]
        targets = [macho.ptr(table + index * 8) - delta for index in range(2)]
        if not all(0x8000 <= target < 0x280000 and target % 4 == 0 for target in targets):
            raise ValueError(f'{pc:#x}: invalid candidate targets {targets}; do not use this table.')
        entry = {'branch': hex(pc), 'instruction': hex(instruction), 'table': hex(table),
                 'xor_key': hex(key), 'delta': delta, 'predicate': predicate,
                 'false_target': hex(targets[0]), 'true_target': hex(targets[1])}
        report.append(entry)
        print(f'{pc:#x}: false -> {targets[0]:#x}, true -> {targets[1]:#x}; {predicate}')
    output = REPO / '.recovery-work/playback-tests/branch-tables.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps({'binary_sha256': expected, 'branches': report}, indent=2) + '\n')


if __name__ == '__main__':
    main()
