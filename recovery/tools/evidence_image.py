"""Read-only helpers for verified Mach-O bytes and recovered constant writes."""
import hashlib
import json
from pathlib import Path
import re
import struct
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]


class EvidenceImage:
    def __init__(self):
        self.evidence = REPO / 'recovery/evidence'
        self.binary_path = REPO / '.recovery-work/arm/YTLite.dylib'
        data = self.binary_path.read_bytes()
        self.sha256 = hashlib.sha256(data).hexdigest()
        expected = next(item['binary_sha256'] for item in json.loads((self.evidence / 'packages.json').read_text())
                        if item['package'].endswith('iphoneos-arm.deb'))
        if self.sha256 != expected:
            raise ValueError('Binary differs from its supplied-package SHA-256')
        self.image = MachO(data)
        self.bytes = {}
        self.byte_instructions = {}
        for line in (self.evidence / 'decoded-bytes.tsv').read_text().splitlines()[1:]:
            address, byte, instruction = line.split('\t')
            address, byte = int(address, 16), int(byte, 16)
            if address in self.bytes and self.bytes[address] != byte:
                raise ValueError(f'Conflicting recovered constant writes at {address:#x}')
            self.bytes[address] = byte
            self.byte_instructions.setdefault(address, []).append(int(instruction, 16))
        self.symbols = {}
        for line in (REPO / '.recovery-work/arm/symbols.txt').read_text().splitlines():
            match = re.match(r'([0-9a-f]{16})\s+\w\s+(.+)', line)
            if match and not match[2].startswith('<redacted'):
                self.symbols[int(match[1], 16)] = match[2]
        self.import_stubs = {}
        start, size, _ = self.image.sections['__stubs']
        for address in range(start, start + size, 12):
            adrp, load, branch = struct.unpack_from('<III', data, self.image.off(address))
            if adrp & 0x9f000000 != 0x90000000 or load & 0xffc00000 != 0xf9400000:
                continue
            immediate = ((adrp >> 5) & 0x7ffff) << 2 | ((adrp >> 29) & 3)
            if immediate & (1 << 20): immediate -= 1 << 21
            pointer = (address & ~4095) + (immediate << 12) + (((load >> 10) & 4095) * 8)
            raw = struct.unpack_from('<Q', data, self.image.off(pointer))[0]
            if raw >> 63:
                self.import_stubs[address] = self.image.imports[raw & 0xffffff]

    def buffer(self, address, length):
        if length < 0 or length > 1000000:
            raise ValueError('Implausible constant buffer length')
        return bytes(self.bytes[p] if p in self.bytes else self.image.data[self.image.off(p)]
                     for p in range(address, address + length))

    def cfstring(self, address):
        pointer = self.image.ptr(address + 16)
        length = struct.unpack_from('<Q', self.image.data, self.image.off(address + 24))[0]
        wide = bool(self.image.u32(self.image.off(address + 8)) & 0x10)
        return self.buffer(pointer, length * (2 if wide else 1)).decode('utf-16-le' if wide else 'utf-8')

    def cstring(self, address, limit=16384):
        raw = bytearray()
        for pointer in range(address, address + limit):
            value = self.buffer(pointer, 1)[0]
            if value == 0:
                return raw.decode('utf-8')
            raw.append(value)
        raise ValueError(f'No terminator in recovered C string at {address:#x}')

    def terminal(self, address):
        """Resolve only exact wrapper templates; report the original address too."""
        visited = set()
        while address not in visited:
            if address in self.import_stubs:
                return self.import_stubs[address]
            if address in self.symbols:
                return self.symbols[address]
            visited.add(address)
            try:
                words = struct.unpack_from('<6I', self.image.data, self.image.off(address))
            except (ValueError, struct.error):
                return None
            if words[0] & 0xfc000000 == 0x14000000:
                delta = words[0] & 0x3ffffff
                if delta & (1 << 25): delta -= 1 << 26
                address += delta * 4
                continue
            if words[0] != 0xa9bf7bfd or words[1] & 0xfc000000 != 0x94000000:
                return None
            if words[2:4] != (0xa8c17bfd, 0xd65f03c0) and words[2:5] != (0x12000000, 0xa8c17bfd, 0xd65f03c0):
                return None
            delta = words[1] & 0x3ffffff
            if delta & (1 << 25): delta -= 1 << 26
            address += 4 + delta * 4
        return None
