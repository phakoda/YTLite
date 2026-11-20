#!/usr/bin/env python3
"""Bounded, read-only evidence queries for the presentation/helper reconstruction.

Never loads the dylib. Checks its hash before applying the supplied decoded-byte
initializer in memory. Assembly excerpts must match every original instruction
word; no function-start audit or speculative export-map matching is performed.
"""
from __future__ import annotations
import argparse
import hashlib
from pathlib import Path
import re
import struct

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = "bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca"


class Evidence:
    def __init__(self) -> None:
        self.original = (ROOT / ".recovery-work/arm/YTLite.dylib").read_bytes()
        if hashlib.sha256(self.original).hexdigest() != EXPECTED:
            raise ValueError("Original image SHA256 mismatch")
        if self.original[:4] != b"\xcf\xfa\xed\xfe":
            raise ValueError("Expected little-endian 64-bit thin Mach-O")
        self.segments = []
        position = 32
        for _ in range(struct.unpack_from("<I", self.original, 16)[0]):
            command, size = struct.unpack_from("<II", self.original, position)
            if size < 8:
                raise ValueError("Invalid load-command size")
            if command == 0x19:
                address, virtual_size, offset, file_size = struct.unpack_from(
                    "<QQQQ", self.original, position + 24)
                self.segments.append((address, virtual_size, offset, file_size))
            position += size
        self.decoded = bytearray(self.original)
        for row in (ROOT / "recovery/evidence/decoded-bytes.tsv").read_text().splitlines()[1:]:
            address, byte, *_ = row.split("\t")
            offset = self.offset(int(address, 16))
            if offset is not None:
                self.decoded[offset] = int(byte, 16)

    def offset(self, address: int):
        for start, _, offset, size in self.segments:
            if start <= address < start + size:
                return offset + address - start
        return None

    def read(self, address: int, size: int, original: bool = False) -> bytes:
        offset = self.offset(address)
        end = self.offset(address + size - 1) if size else offset
        if offset is None or end != offset + size - 1:
            raise ValueError(f"Unmapped range {address:#x}+{size:#x}")
        return bytes((self.original if original else self.decoded)[offset:offset + size])

    def integer(self, address: int, size: int = 8) -> int:
        return int.from_bytes(self.read(address, size), "little")

    def pointer(self, address: int) -> int:
        value = self.integer(address)
        if value & (1 << 63):
            raise ValueError(f"Imported/bound pointer at {address:#x}, not an image address")
        # This arm image uses DYLD_CHAINED_PTR_64 / 64_OFFSET. Its image base is 0.
        return (value & 0xfffffffff) | (((value >> 36) & 0xff) << 56)

    def string(self, address: int) -> str:
        result = bytearray()
        for index in range(8192):
            byte = self.read(address + index, 1)
            if byte == b"\0":
                return result.decode("utf-8")
            result += byte
        raise ValueError("Unterminated/oversized string")

    def constant_string(self, address: int) -> str:
        flags = self.integer(address + 8, 4)
        start, length = self.pointer(address + 16), self.integer(address + 24)
        if length > 65536:
            raise ValueError("Oversized CFString")
        wide = bool(flags & 16)
        return self.read(start, length * (2 if wide else 1)).decode("utf-16-le" if wide else "utf-8")

    def descriptor(self, address: int, copy_dispose: bool = True) -> dict:
        signature_at = address + (32 if copy_dispose else 16)
        return {"descriptor": hex(address), "size": self.integer(address + 8),
                "signature": self.string(self.pointer(signature_at))}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    number = lambda value: int(value, 0)
    for option in ("double", "u64", "pointer", "string", "cfstring", "descriptor", "global-block"):
        parser.add_argument("--" + option, type=number, action="append", default=[])
    parser.add_argument("--range", nargs=2, type=number)
    args = parser.parse_args()
    image = Evidence()
    print("image_sha256", EXPECTED)
    for address in args.double:
        print(hex(address), "double", struct.unpack("<d", image.read(address, 8))[0])
    for address in args.u64:
        print(hex(address), "u64", hex(image.integer(address)))
    for address in args.pointer:
        print(hex(address), "pointer", hex(image.pointer(address)))
    for address in args.string:
        print(hex(address), "string", repr(image.string(address)))
    for address in args.cfstring:
        print(hex(address), "CFString", repr(image.constant_string(address)))
    for address in args.descriptor:
        print(image.descriptor(address))
    for address in args.global_block:
        flags = image.integer(address + 8, 4)
        descriptor = image.pointer(address + 24)
        print("global_block", hex(address), "invoke", hex(image.pointer(address + 16)),
              image.descriptor(descriptor, bool(flags & 0x02000000)))
    if args.range:
        start, end = args.range
        if not 0 < end - start <= 0x10000 or start % 4 or end % 4:
            raise ValueError("Assembly queries must be aligned, positive, and at most 64 KiB")
        pattern = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$")
        words = []
        lines = []
        for line in (ROOT / ".recovery-work/arm/application.asm").open():
            match = pattern.match(line)
            if not match:
                continue
            address = int(match[1], 16)
            if not start <= address < end:
                continue
            word = int(match[2], 16).to_bytes(4, "little")
            if image.read(address, 4, original=True) != word:
                raise ValueError(f"Stale assembly at {address:#x}")
            words.append(word)
            lines.append(line.rstrip())
        if len(words) != (end - start) // 4:
            raise ValueError("Requested assembly interval has gaps")
        print("asm_sha256", hashlib.sha256(b"".join(words)).hexdigest())
        print("\n".join(lines))


if __name__ == "__main__":
    main()
