#!/usr/bin/env python3
"""Read-only evidence decoder for the Downloads recovery; does not load executable code."""
import argparse, hashlib, json, re, sys
from pathlib import Path
sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'recovery/tools'))
from inventory import MachO

def image():
    data = (ROOT / '.recovery-work/arm/YTLite.dylib').read_bytes()
    assert hashlib.sha256(data).hexdigest() == 'bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca'
    return MachO(data)

def decode(macho, address):
    overlay = {}
    for line in (ROOT / 'recovery/evidence/decoded-bytes.tsv').read_text().splitlines()[1:]:
        at, value, _ = line.split('\t')
        overlay[int(at, 16)] = int(value, 16)
    wide = bool(macho.ptr(address + 8) & 0x10)
    pointer, length = macho.ptr(address + 16), macho.ptr(address + 24)
    if length > 100000: raise ValueError('Not a plausible CFString')
    value = bytes(overlay[p] if p in overlay else macho.data[macho.off(p)]
                  for p in range(pointer, pointer + length * (2 if wide else 1)))
    return value.decode('utf-16-le' if wide else 'utf-8')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('addresses', nargs='*', type=lambda x: int(x, 0))
    args = parser.parse_args()
    macho = image()
    for address in args.addresses:
        print(hex(address), json.dumps(decode(macho, address), ensure_ascii=False))
