#!/usr/bin/env python3
"""Recover the packaged key-derivation pepper and its byte-level provenance."""
import json
import re
import struct
from evidence_image import EvidenceImage, REPO


def recover_pepper_bytes(image):
    """Evaluate only the verified, straight-line initializer branch as data.

    The general string pass clears registers at BR and therefore missed the
    x8 destination pointer carried into this block. Explicitly retain the two
    dominating pointer instructions and follow ONLY this known branch body.
    Every disassembled instruction word is checked against the original file.
    """
    instructions = {}
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)', line)
        if match and 0x27b40 <= int(match[1], 16) < 0x27ee4:
            pc, word = int(match[1], 16), int(match[2], 16)
            if struct.unpack_from('<I', image.image.data, image.image.off(pc))[0] != word:
                raise ValueError(f'Disassembly word differs from original bytes at {pc:#x}')
            instructions[pc] = (match[3], match[4].split(';')[0].strip(), word)
    registers, traces, writes = {}, {}, {}
    key = lambda name: 'x' + name[1:] if re.fullmatch('[wx][0-9]+', name) else name

    def value(name):
        return int(name[1:], 0) if name.startswith('#') else registers[key(name)]

    def provenance(name):
        return set() if name.startswith('#') else traces[key(name)]

    for pc in range(0x27b40, 0x27ee4, 4):
        op, operands, word = instructions[pc]
        parts = [part.strip() for part in operands.split(',')]
        destination = key(parts[0])
        if pc == 0x27b48:
            if word != 0xd61f0140:
                raise ValueError('Expected the independently resolved branch into the initializer')
            continue
        trace = {pc}
        if op == 'adrp':
            result = int(parts[1], 16)
        elif op == 'add':
            result = value(parts[1]) + value(parts[2])
            trace |= provenance(parts[1]) | provenance(parts[2])
        elif op == 'mov':
            result = value(parts[1]); trace |= provenance(parts[1])
        elif op == 'eor':
            result = value(parts[1]) ^ value(parts[2])
            trace |= provenance(parts[1]) | provenance(parts[2])
        elif op in ('ldrb', 'strb'):
            match = re.search(r'\[(x\d+)(?:,\s*(#(?:0x[0-9a-f]+|\d+)))?\]$', operands)
            if not match:
                raise ValueError(f'Unexpected initializer memory operand: {pc:#x} {operands}')
            address = value(match[1]) + (value(match[2]) if match[2] else 0)
            trace |= provenance(match[1])
            if op == 'ldrb':
                if not 0x1157340 <= address < 0x1157380:
                    raise ValueError('Initializer load leaves the 64-byte encoded buffer')
                result = image.buffer(address, 1)[0]
            else:
                if not 0x1157380 <= address < 0x11573c0 or address in writes:
                    raise ValueError('Initializer store leaves or overwrites its 64-byte destination')
                trace |= provenance(parts[0])
                source = address - 64
                result = value(parts[0]) & 255
                writes[address] = {'address': hex(address), 'source_address': hex(source),
                                   'source_value': image.buffer(source, 1)[0], 'initialized_value': result,
                                   'first_xor': image.buffer(source, 1)[0] ^ result,
                                   'store_instruction': hex(pc),
                                   'instructions': [hex(instruction) for instruction in sorted(trace)]}
                continue
        else:
            raise ValueError(f'Unexpected operation in constant initializer: {pc:#x} {op}')
        registers[destination] = result & ((1 << (32 if parts[0].startswith('w') else 64)) - 1)
        traces[destination] = trace
    if set(writes) != set(range(0x1157380, 0x11573c0)):
        raise ValueError('The verified initializer did not produce all 64 bytes')
    # Verify the second-stage SIMD operations and loop stride/bound, rather
    # than deriving their meaning from the incomplete decompiler export.
    second_stage = {0x27efc: 0x3cff6901, 0x27f00: 0x381f013f,
                    0x27f04: 0x4f05e4a0, 0x27f08: 0x6e201c21, 0x27f0c: 0x3cbf6a61,
                    0x27f10: 0x9100414b, 0x27f14: 0xf100c15f,
                    0x27f48: 0x3ceb6901, 0x27f4c: 0x6e201c21, 0x27f50: 0x3cab6a61,
                    0x27f54: 0xf100c17f, 0x27f58: 0x9100416b}
    for pc, expected in second_stage.items():
        if struct.unpack_from('<I', image.image.data, image.image.off(pc))[0] != expected:
            raise ValueError(f'Second-stage XOR instruction changed at {pc:#x}')
    return [writes[address] for address in sorted(writes)], second_stage


def main():
    image = EvidenceImage()
    # Initializer 0x27ac0 first decodes 64 bytes into 0x1157380. Its NEON loop
    # at 0x27efc..0x27f7c XORs each byte with 0xa5 before initWithUTF8String:.
    provenance, second_stage = recover_pepper_bytes(image)
    intermediate = bytes(entry['initialized_value'] for entry in provenance)
    pepper = bytes(value ^ 0xa5 for value in intermediate).decode('ascii')
    if not re.fullmatch('[0-9a-fA-F]{64}', pepper):
        raise ValueError('Recovered pepper is not the expected 64 hexadecimal characters')
    password_format = image.cfstring(0x1157320)
    record = {'binary_sha256': image.sha256, 'initializer': '0x27ac0',
              'initialized_buffer': '0x1157380', 'length': 64, 'second_xor': '0xa5',
              'pepper': pepper, 'password_format': password_format,
              'key_derivation': {'function': '0x27838', 'algorithm': 'PBKDF2-HMAC-SHA256', 'rounds': 10000, 'key_bytes': 32},
              'byte_provenance': provenance,
              'second_stage_instructions': {hex(pc): hex(word) for pc, word in second_stage.items()}}
    root = REPO / 'recovery/source/Runtime'
    root.mkdir(parents=True, exist_ok=True)
    source = '// Generated by recover_bootstrap_constants.py from verified initialized bytes.\n'
    source += 'static NSString *const YTLBootstrapPepper = @' + json.dumps(pepper) + ';\n'
    source += 'static NSString *const YTLBootstrapPasswordFormat = @' + json.dumps(password_format) + ';\n'
    (root / 'YTLBootstrapConstants.inc').write_text(source)
    (REPO / 'recovery/evidence/bootstrap-constants.json').write_text(json.dumps(record, indent=2) + '\n')
    print('Recovered 64-byte packaged pepper, format', repr(password_format), 'and PBKDF2 parameters with instruction provenance.')


if __name__ == '__main__':
    main()
