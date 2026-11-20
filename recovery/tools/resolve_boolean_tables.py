#!/usr/bin/env python3
"""Recover both targets of an encoded boolean-indexed branch table.

This resolves destinations only; callers must independently prove the table
index is a boolean and recover what each state means. Never force a flag true.
"""
import argparse
import json
from pathlib import Path
import struct
from evidence_image import EvidenceImage, REPO


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('tables', nargs='+', help='TABLE_ADDRESS:XOR_KEY in hexadecimal')
    args = parser.parse_args()
    image = EvidenceImage()
    recovered = {}
    for value in args.tables:
        address, key = (int(part, 16) for part in value.split(':'))
        encoded = image.image.u32(image.image.off(address + 16))
        delta = struct.unpack('<i', struct.pack('<I', encoded ^ key))[0]
        targets = [image.image.ptr(address + index * 8) - delta for index in (0, 1)]
        for target in targets:
            if not 0x8000 <= target < 0x280000 or target % 4:
                raise ValueError(f'Implausible destination {target:#x} for table {address:#x}')
        recovered[hex(address)] = {'table': hex(address), 'xor_key': hex(key), 'encoded_delta': hex(encoded),
                                  'signed_delta': delta, 'targets': [hex(target) for target in targets]}
        print(f'{address:#x}: index 0 -> {targets[0]:#x}; index 1 -> {targets[1]:#x}')
    path = REPO / '.recovery-work/analysis/boolean-tables.json'
    path.parent.mkdir(parents=True, exist_ok=True)
    report = json.loads(path.read_text()) if path.exists() else {'binary_sha256': image.sha256, 'tables': {}}
    if report['binary_sha256'] != image.sha256:
        raise ValueError('Existing branch-table report describes a different binary')
    report['tables'].update(recovered)
    path.write_text(json.dumps(report, indent=2) + '\n')


if __name__ == '__main__': main()
