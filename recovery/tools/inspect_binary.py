#!/usr/bin/env python3
"""Annotate an ARM64 address range without loading the Mach-O as executable code.

Annotations are a linear aid to manual review, not a control-flow proof. The
original instructions, binary hash and independently recovered branch targets
are retained. All paths are confined to this repository.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('start', type=lambda s: int(s, 0))
    parser.add_argument('end', type=lambda s: int(s, 0))
    parser.add_argument('--all', action='store_true', help='Include unannotated instructions.')
    parser.add_argument('--variant', choices=['arm', 'arm64', 'arm64e'], default='arm',
                        help='Select supplied-package evidence; arm64e uses .recovery-work/first-package.')
    parser.add_argument('--cfstrings', nargs='*', type=lambda s: int(s, 0), default=[],
                        help='Also decode these constant NSString records (including records in __data).')
    args = parser.parse_args()
    work = REPO / '.recovery-work' / ('first-package' if args.variant == 'arm64e' else args.variant)
    evidence = REPO / 'recovery/evidence' if args.variant == 'arm' else work / 'evidence'
    data = (work / 'YTLite.dylib').read_bytes()
    manifest = next(p for p in json.loads((REPO / 'recovery/evidence/packages.json').read_text())
                    if p['package'].endswith(f'iphoneos-{args.variant}.deb'))
    digest = hashlib.sha256(data).hexdigest()
    if digest != manifest['binary_sha256']:
        raise RuntimeError('Analysis binary no longer matches the evidence hash.')
    macho = MachO(data)
    labels = {}
    for line in (work / 'symbols.txt').read_text().splitlines():
        match = re.match(r'([0-9a-f]{16})\s+\w\s+(.+)', line)
        if match and not match[2].startswith('<redacted'):
            labels[int(match[1], 16)] = match[2]
    strings = {int(x['address'], 16): x['value'] for x in
               json.loads((evidence / 'decoded-strings.json').read_text())}
    initialized_bytes = {}
    for line in (evidence / 'decoded-bytes.tsv').read_text().splitlines()[1:]:
        address, byte, instruction = line.split('\t')
        address, byte = int(address, 16), int(byte, 16)
        if address in initialized_bytes and initialized_bytes[address] != byte:
            raise ValueError(f'Conflicting constant byte initializers at {address:#x}')
        initialized_bytes[address] = byte

    def cfstring(address):
        # The decoded string list is UTF-8 oriented. Wide CFString buffers can
        # still contain encrypted bytes in the original image; overlay byte
        # initializer evidence before decoding BOTH narrow and UTF-16 strings.
        wide = bool(macho.ptr(address + 8) & 0x10)
        pointer, length = macho.ptr(address + 16), macho.ptr(address + 24)
        if length > 100000:
            raise ValueError(f'Implausible CFString length at {address:#x}')
        raw = bytes(initialized_bytes[p] if p in initialized_bytes else data[macho.off(p)]
                    for p in range(pointer, pointer + length * (2 if wide else 1)))
        return raw.decode('utf-16-le' if wide else 'utf-8')

    for entry in json.loads((REPO / f'recovery/evidence/{args.variant}-cfstrings.json').read_text()):
        address = int(entry['address'], 16)
        labels[address] = '@' + json.dumps(cfstring(address), ensure_ascii=False)
    for source in ((REPO / 'recovery/classes').glob('*.c') if args.variant == 'arm' else []):
        for match in re.finditer(r'PTR____CFConstantStringClassReference_([0-9a-f]+)', source.read_text()):
            address = int(match[1], 16)
            if address not in labels:
                try:
                    labels[address] = '@' + json.dumps(cfstring(address), ensure_ascii=False)
                except (ValueError, UnicodeDecodeError, struct.error):
                    pass  # Never manufacture text for an unresolved byte initializer.
    for address in args.cfstrings:
        labels[address] = '@' + json.dumps(cfstring(address), ensure_ascii=False)
    for address, value in strings.items():
        labels[address] = json.dumps(value, ensure_ascii=False)
    for section in ('__objc_selrefs', '__objc_classrefs', '__got', '__la_symbol_ptr', '__nl_symbol_ptr'):
        if section not in macho.sections:
            continue
        start, size, _ = macho.sections[section]
        for address in range(start, start + size, 8):
            raw = struct.unpack_from('<Q', data, macho.off(address))[0]
            if raw >> 63:
                name = macho.imports[raw & 0xffffff]
            elif section == '__objc_selrefs':
                name = '@selector(' + macho.string(macho.ptr(address)) + ')'
            else:
                name = labels.get(macho.ptr(address))
            if name:
                labels[address] = 'ref:' + name
    instructions = {}
    assembly_bytes = (work / 'application.asm').read_bytes()
    for line in assembly_bytes.decode('utf-8').splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)', line)
        if match:
            address, word = int(match[1], 16), int(match[2], 16)
            # Pin each inspected instruction to the package bytes, not just to
            # a previously exported text file which another pass can replace.
            if args.start <= address < args.end:
                actual = struct.unpack_from('<I', data, macho.off(address))[0]
                if word != actual:
                    raise ValueError(f'Disassembly mismatch at {address:#x}: text={word:#x}, binary={actual:#x}')
            instructions[address] = (match[3], match[4], line.strip())
    # Resolve import stubs (ADRP/LDR/BR), including the chained import ordinal.
    stub_start, stub_size, _ = macho.sections['__stubs']
    for pc in range(stub_start, stub_start + stub_size, 12):
        a, b = struct.unpack_from('<II', data, macho.off(pc))
        if a & 0x9f000000 != 0x90000000 or b & 0xffc00000 != 0xf9400000:
            continue
        immediate = ((a >> 29) & 3) | (((a >> 5) & 0x7ffff) << 2)
        if immediate & (1 << 20):
            immediate -= 1 << 21
        pointer = (pc & ~0xfff) + (immediate << 12) + (((b >> 10) & 0xfff) << 3)
        if pointer in labels:
            labels[pc] = labels[pointer].removeprefix('ref:')

    def callee_name(pc, depth=0):
        if pc in labels:
            return labels[pc]
        if depth < 4 and pc in instructions:
            ops = [instructions.get(pc + i * 4, ('', '', '')) for i in range(6)]
            if ops[0][0] == 'b':
                return callee_name(int(ops[0][1].split()[0], 16), depth + 1)
            if ops[0][0] == 'stp' and ops[1][0] == 'bl' and any(op[0] == 'ret' for op in ops[2:]):
                return callee_name(int(ops[1][1].split()[0], 16), depth + 1) + ' [thunk]'
        return hex(pc)

    branch_path = evidence / 'branches.json'
    branches = {int(x['address'], 16): x for x in
                (json.loads(branch_path.read_text()) if branch_path.exists() else [])}
    combined = REPO / '.recovery-work/analysis-v2/evidence/branches.json'
    if args.variant == 'arm' and combined.exists():
        for entry in json.loads(combined.read_text()):
            address = int(entry['address'], 16)
            if address not in branches:
                actual = struct.unpack_from('<I', data, macho.off(address))[0]
                if actual != int(entry['original'][0], 16):
                    raise ValueError(f'Combined branch evidence does not match original bytes: {address:#x}')
                branches[address] = entry
    registers, stack = {}, {}

    def reg(name):
        return 'x' + name[1:] if re.fullmatch('[wx][0-9]+', name) else name

    def value(name):
        if name in ('wzr', 'xzr'):
            return 0
        if name.startswith('#'):
            return int(name[1:], 0)
        return registers[reg(name)]

    def display(item):
        return labels.get(item, hex(item)) if isinstance(item, int) else item

    output = [f'Binary SHA-256: {digest}',
              f'Disassembly SHA-256: {hashlib.sha256(assembly_bytes).hexdigest()}',
              'Every displayed instruction word was checked against the verified binary.',
              'Linear annotations only; verify data flow across branches separately.']
    output.extend(f'CFString {address:#x}: {labels[address]}' for address in args.cfstrings)
    for pc in sorted(instructions):
        if not args.start <= pc < args.end:
            continue
        op, operands, original = instructions[pc]
        parts = [p.strip() for p in operands.split(';')[0].split(',')]
        destination = reg(parts[0])
        note = ''
        if pc in macho.function_starts:
            registers.clear(); stack.clear()
            output.append('\n' + labels.get(pc, f'Function {pc:#x}'))
        try:
            if op in ('adr', 'adrp'):
                registers[destination] = int(parts[1], 16)
            elif op == 'mov':
                registers[destination] = value(parts[1])
            elif op == 'movk':
                shift = int(parts[2].split('#')[1], 0) if len(parts) > 2 else 0
                registers[destination] = (value(parts[0]) & ~(0xffff << shift)) | (value(parts[1]) << shift)
            elif op in ('add', 'sub', 'eor', 'and', 'orr'):
                a, b = value(parts[1]), value(parts[2])
                if len(parts) > 3:
                    extension = parts[3].split()
                    if extension[0] == 'sxtw':
                        b = (b & 0x7fffffff) - (b & 0x80000000)
                    elif extension[0] not in ('lsl', 'uxtw'):
                        raise ValueError('Unsupported extension')
                    if len(extension) > 1:
                        b <<= int(extension[1][1:], 0)
                result = {'add': lambda: a + b, 'sub': lambda: a - b,
                          'eor': lambda: a ^ b, 'and': lambda: a & b, 'orr': lambda: a | b}[op]()
                registers[destination] = result & ((1 << (32 if parts[0].startswith('w') else 64)) - 1)
            elif op in ('ldr', 'ldur', 'ldrb', 'str', 'stur'):
                match = re.search(r'\[(\w+)(?:,\s*(#[^,\]]+))?\]', operands)
                if not match:
                    raise ValueError('Indexed load')
                base, offset = match.groups()
                offset = int(offset[1:], 0) if offset else 0
                address = (base, offset) if base in ('sp', 'x29') else value(base) + offset
                if op in ('str', 'stur'):
                    if isinstance(address, tuple):
                        stack[address] = value(parts[0])
                elif isinstance(address, tuple):
                    registers[destination] = stack[address]
                elif parts[0].startswith('d'):
                    registers[destination] = struct.unpack_from('<d', data, macho.off(address))[0]
                    note = f'double {registers[destination]!r} from {address:#x}'
                else:
                    width = 1 if op == 'ldrb' else 8 if parts[0].startswith('x') else 4
                    raw = int.from_bytes(data[macho.off(address):macho.off(address) + width], 'little')
                    registers[destination] = labels[address][4:] if labels.get(address, '').startswith('ref:') else raw
                    if address in labels:
                        note = labels[address]
            elif op in ('bl', 'blr'):
                name = callee_name(int(parts[0].split()[0], 16)) if op == 'bl' else display(value(parts[0]))
                arguments = ', '.join(f'{r}={display(registers[r])}' for r in
                                      ('x0', 'x1', 'x2', 'x3', 'x4', 'd0', 'd1', 'd2', 'd3') if r in registers)
                note = name + (' | ' + arguments if arguments else '')
                old_x0 = registers.get('x0')
                registers = {r: val for r, val in registers.items()
                             if re.fullmatch('x(?:19|2[0-8])', r)}
                if name.startswith(('_objc_retain', '_objc_autorelease')) and old_x0 is not None:
                    registers['x0'] = old_x0
            elif re.fullmatch('[wx][0-9]+', parts[0]) and not op.startswith(('st', 'b', 'cmp', 'tst')):
                registers.pop(destination, None)
        except (KeyError, ValueError, TypeError, IndexError, struct.error):
            if not op.startswith('st'):
                registers.pop(destination, None)
        if pc in branches:
            patch = branches[pc]
            note += ' | recovered targets: ' + ', '.join(patch['targets'])
            if 'condition' in patch:
                note += ' condition=' + patch['condition']
        if note or args.all or op in ('ret', 'br', 'blr') or op.startswith(('cb', 'tb', 'b.')):
            output.append(original + ('  // ' + note if note else ''))
    text = '\n'.join(output) + '\n'
    output_directory = REPO / '.recovery-work/analysis' if args.variant == 'arm' else work / 'analysis'
    target = output_directory / f'{args.start:08x}-{args.end:08x}.txt'
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(text)
    print(text, end='')
    print(f'Analysis notes: {target}')


if __name__ == '__main__':
    main()
