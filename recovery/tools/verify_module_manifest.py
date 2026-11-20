#!/usr/bin/env python3
"""Check a reconstructed module's recorded intervals against the original package."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from evidence_image import EvidenceImage, REPO

def verify(path):
    manifest = json.loads(path.read_text())
    image = EvidenceImage()
    if manifest['binary_sha256'] != image.sha256:
        raise ValueError('Manifest uses a different original binary')
    metadata = json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text())
    matches = [c['name'] for c in metadata if c['methods'] == manifest['methods']]
    if len(matches) != 1:
        raise ValueError('Manifest no longer matches exactly one packaged class method list')
    for span in manifest['instruction_intervals']:
        start, end = int(span['start'], 16), int(span['end'], 16)
        if end <= start:
            raise ValueError('Invalid instruction interval')
        data = image.image.data[image.image.off(start):image.image.off(end)]
        if hashlib.sha256(data).hexdigest() != span['sha256']:
            raise ValueError('Instruction interval differs: ' + str(span))
    for address, constant in manifest.get('constants', {}).items():
        if image.buffer(int(address, 16), 8).hex() != constant['hex']:
            raise ValueError('Constant differs: ' + address)
    for table in manifest.get('branch_tables', []):
        key = struct.unpack('<I', image.buffer(int(table['key'], 16), 4))[0]
        delta = (-(key ^ int(table['xor'], 16))) & 0xffffffff
        if delta >= 0x80000000: delta -= 0x100000000
        targets = [hex(image.image.ptr(int(table['table'], 16) + index*8) + delta) for index in range(2)]
        if targets != table['destinations']:
            raise ValueError('Decoded branch destinations differ: ' + str(table))
    print(matches[0] + ': original-byte intervals, constants, branch tables and method addresses verified.')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    verify(parser.parse_args().manifest)
