#!/usr/bin/env python3
"""Conservative, control-flow-aware ARM64 constant branch recovery.

The original file is only read. New patches are accepted only in functions whose
reachable indirect branches have a closed, stable control-flow graph. Joins keep
only facts equal on every incoming path; calls clobber caller-saved registers.
Existing recovery transforms are retained unchanged in the combined report.
"""
import argparse
from collections import deque
from dataclasses import dataclass, field
import json
from pathlib import Path
import re
import struct
from inventory import MachO
from unflatten import Choice, unary, binary

REPO = Path(__file__).resolve().parents[2]
CONDITIONS = ['eq', 'ne', 'hs', 'lo', 'mi', 'pl', 'vs', 'vc',
              'hi', 'ls', 'ge', 'lt', 'gt', 'le', 'al', 'nv']


@dataclass(frozen=True)
class StackAddress:
    offset: int


@dataclass(frozen=True)
class SymbolicWord:
    origin: tuple
    shift: int = 0
    mask: int = (1 << 64) - 1


def normalize_word(word):
    if not word.mask: return 0
    if word.mask & (word.mask - 1) == 0:
        bit = word.mask.bit_length() - 1
        return Choice('bit|' + repr(word.origin) + '|' + str(word.shift + bit), None, 0, word.mask)
    return word


@dataclass
class State:
    registers: dict = field(default_factory=dict)
    stack: dict = field(default_factory=dict)
    flags: object = None
    escaped_floor: object = None

    def clone(self):
        return State(self.registers.copy(), self.stack.copy(), self.flags, self.escaped_floor)

    def join(self, other):
        floors = [value for value in [self.escaped_floor, other.escaped_floor] if value is not None]
        return State({k: v for k, v in self.registers.items() if other.registers.get(k) == v},
                     {k: v for k, v in self.stack.items() if other.stack.get(k) == v},
                     self.flags if self.flags == other.flags else None, min(floors) if floors else None)


@dataclass(frozen=True)
class Instruction:
    address: int
    word: int
    op: str
    operands: str


def parse_assembly(text):
    instructions = {}
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\w+(?:\.\w+)?)\s*(.*)', line)
        if match:
            address, word, op, operands = match.groups()
            address = int(address, 16)
            instructions[address] = Instruction(address, int(word, 16), op, operands.split(';')[0].strip())
    return instructions


def register_key(register):
    return 'x' + register[1:] if re.fullmatch('[wx][0-9]+', register) else register


def direct_branch(pc, target):
    distance = target - pc
    if distance % 4 or not -(1 << 27) <= distance < (1 << 27):
        raise ValueError('ARM64 direct branch is out of range')
    return 0x14000000 | ((distance // 4) & 0x3ffffff)


class Analyzer:
    def __init__(self, macho, instructions):
        self.macho = macho
        self.instructions = instructions
        self.bool_wrappers = set()
        for address in macho.function_starts:
            try:
                words = struct.unpack_from('<5I', macho.data, macho.off(address))
            except (ValueError, struct.error):
                continue
            if (words[0] == 0xa9bf7bfd and words[1] & 0xfc000000 == 0x94000000
                    and words[2:] == (0x12000000, 0xa8c17bfd, 0xd65f03c0)):
                self.bool_wrappers.add(address)

    def load(self, address, width):
        if isinstance(address, Choice):
            return unary(address, lambda value: self.load(value, width))
        if not isinstance(address, int):
            raise ValueError('Not a constant memory address')
        if width == 8 and address in self.macho.chained_pointers:
            result = self.macho.chained_pointers[address]
            if result is None:
                raise ValueError('Imported runtime address is unknown')
            return result
        offset = self.macho.off(address)
        return int.from_bytes(self.macho.data[offset:offset + width], 'little')

    def transfer(self, instruction, incoming):
        state = incoming.clone()
        regs, stack = state.registers, state.stack
        pc, op = instruction.address, instruction.op
        parts = [part.strip() for part in instruction.operands.split(',')]
        destination = parts[0] if parts else ''

        def value(token):
            token = token.strip()
            if token in ['xzr', 'wzr']: return 0
            if token.startswith('#'): return int(token[1:], 0)
            key = register_key(token)
            if key not in regs:
                regs[key] = SymbolicWord((pc, key))
            result = regs[key]
            if token.startswith('w'):
                if isinstance(result, SymbolicWord):
                    result = normalize_word(SymbolicWord(result.origin, result.shift, result.mask & 0xffffffff))
                elif not isinstance(result, StackAddress):
                    result = unary(result, lambda n: n & 0xffffffff)
            return result

        def put(register, result):
            if register in ['xzr', 'wzr']: return
            if isinstance(result, SymbolicWord):
                result = normalize_word(SymbolicWord(result.origin, result.shift,
                    result.mask & ((1 << (32 if register.startswith('w') else 64)) - 1)))
            elif not isinstance(result, StackAddress):
                width = 32 if register.startswith('w') else 64
                result = unary(result, lambda number: number & ((1 << width) - 1))
            regs[register_key(register)] = result

        def add(left, right):
            if isinstance(left, StackAddress) and isinstance(right, int):
                return StackAddress(left.offset + right)
            return binary(left, right, lambda a, b: a + b)

        def memory(text):
            match = re.search(r'\[(\w+)(?:,\s*([^,\]]+))?(?:,\s*([^\]]+))?\](!)?(?:,\s*(#[^,]+))?', text)
            if not match: raise ValueError('Unsupported memory operand')
            base, index, extension, pre, post = match.groups()
            offset = value(index) if index else 0
            if extension:
                mode = extension.split()
                shift = int(mode[1][1:], 0) if len(mode) > 1 else 0
                if mode[0] == 'sxtw': offset = unary(offset, lambda n: (n & 0x7fffffff) - (n & 0x80000000))
                elif mode[0] == 'uxtw': offset = unary(offset, lambda n: n & 0xffffffff)
                elif mode[0] != 'lsl': raise ValueError('Unsupported index extension')
                offset = unary(offset, lambda n: n << shift)
            address = add(value(base), offset)
            if pre: put(base, address)
            if post: put(base, add(value(base), value(post)))
            return address

        def read(address, width):
            if isinstance(address, StackAddress):
                slot_width, result = stack[address.offset]
                if slot_width < width: raise ValueError('Stack read exceeds known store')
                if isinstance(result, (StackAddress, SymbolicWord)):
                    if isinstance(result, SymbolicWord):
                        return normalize_word(SymbolicWord(result.origin, result.shift, result.mask & ((1 << (width * 8)) - 1)))
                    if width != 8: raise ValueError('Narrow stack pointer load')
                    return result
                return unary(result, lambda number: number & ((1 << (8 * width)) - 1))
            return self.load(address, width)

        def write(address, width, result):
            if not isinstance(address, StackAddress): return
            for offset, (size, _) in list(stack.items()):
                if offset < address.offset + width and address.offset < offset + size:
                    del stack[offset]
            if result is not None:
                stack[address.offset] = (width, result)

        try:
            if op in ['adrp', 'adr']:
                put(destination, int(parts[1].split()[0], 16))
            elif op in ['mov', 'movz', 'movn']:
                result = value(parts[1])
                if len(parts) > 2:
                    result = unary(result, lambda n: n << int(parts[2].split('#')[1], 0))
                if op == 'movn': result = unary(result, lambda n: ~n)
                put(destination, result)
            elif op == 'movk':
                shift = int(parts[2].split('#')[1], 0) if len(parts) > 2 else 0
                put(destination, unary(value(destination), lambda n: (n & ~(0xffff << shift)) | (value(parts[1]) << shift)))
            elif op in ['cmp', 'cmn', 'tst', 'ccmp', 'ccmn', 'fcmp', 'fcmpe', 'fccmp', 'fccmpe']:
                state.flags = pc
            elif op in ['cset', 'csetm']:
                put(destination, Choice(parts[1], state.flags, 0, 1 if op == 'cset' else -1))
            elif op == 'csel':
                true, false = value(parts[1]), value(parts[2])
                def is_boolean(v):
                    return (v in [0, 1] if isinstance(v, int) else
                            isinstance(v, Choice) and v.false in [0, 1] and v.true in [0, 1])
                if isinstance(true, int) and isinstance(false, int):
                    put(destination, Choice(parts[3], state.flags, false, true))
                elif is_boolean(true) and is_boolean(false):
                    # Collapse a compound Boolean expression to a fresh Boolean.
                    # It can only be tested through its live register/stack value,
                    # not through flags belonging to one of its subexpressions.
                    put(destination, Choice('value:' + hex(pc), None, 0, 1))
                else: raise ValueError('Unbounded conditional select')
            elif op in ['add', 'sub', 'adds', 'subs', 'eor', 'orr', 'and', 'ands', 'bic', 'orn']:
                left, right = value(parts[1]), value(parts[2])
                if len(parts) > 3:
                    extension = parts[3].split()
                    shift = int(extension[1][1:], 0) if len(extension) > 1 else 0
                    if extension[0] == 'sxtw': right = unary(right, lambda n: (n & 0x7fffffff) - (n & 0x80000000))
                    elif extension[0] == 'uxtw': right = unary(right, lambda n: n & 0xffffffff)
                    elif extension[0] != 'lsl': raise ValueError('Unsupported arithmetic extension')
                    right = unary(right, lambda n: n << shift)
                if op in ['and', 'ands'] and isinstance(left, SymbolicWord) and isinstance(right, int):
                    result = normalize_word(SymbolicWord(left.origin, left.shift, left.mask & right))
                elif op in ['and', 'ands'] and isinstance(right, SymbolicWord) and isinstance(left, int):
                    result = normalize_word(SymbolicWord(right.origin, right.shift, right.mask & left))
                elif op in ['add', 'adds']: result = add(left, right)
                elif op in ['sub', 'subs'] and isinstance(left, StackAddress) and isinstance(right, int):
                    result = StackAddress(left.offset - right)
                else:
                    function = {'sub': lambda a, b: a - b, 'subs': lambda a, b: a - b,
                                'eor': lambda a, b: a ^ b, 'orr': lambda a, b: a | b,
                                'and': lambda a, b: a & b, 'ands': lambda a, b: a & b,
                                'bic': lambda a, b: a & ~b, 'orn': lambda a, b: a | ~b}[op]
                    result = binary(left, right, function)
                put(destination, result)
                if op in ['adds', 'subs', 'ands']: state.flags = pc
            elif op in ['neg', 'mvn']:
                put(destination, unary(value(parts[1]), (lambda n: -n) if op == 'neg' else (lambda n: ~n)))
            elif op in ['lsl', 'lsr', 'asr']:
                shift = value(parts[2]); width = 32 if destination.startswith('w') else 64
                source = value(parts[1])
                if isinstance(source, SymbolicWord) and op == 'lsr':
                    put(destination, normalize_word(SymbolicWord(source.origin, source.shift + shift, source.mask >> shift)))
                else:
                    if op == 'asr': source = unary(source, lambda n: (n & ((1 << (width - 1)) - 1)) - (n & (1 << (width - 1))))
                    put(destination, unary(source, (lambda n: n << shift) if op == 'lsl' else (lambda n: n >> shift)))
            elif op in ['sxtw', 'uxtw']:
                put(destination, unary(value(parts[1]), (lambda n: (n & 0x7fffffff) - (n & 0x80000000)) if op == 'sxtw' else (lambda n: n & 0xffffffff)))
            elif op in ['ldp', 'stp']:
                width = 8 if destination.startswith(('x', 'd')) else 16 if destination.startswith('q') else 4
                address = memory(','.join(parts[2:]))
                for index, register in enumerate(parts[:2]):
                    current = add(address, width * index)
                    if op == 'stp':
                        write(current, width, regs.get(register_key(register)))
                    else:
                        try: put(register, read(current, width))
                        except (KeyError, ValueError): regs.pop(register_key(register), None)
            elif op in ['ldr', 'ldur', 'ldrb', 'ldurb', 'ldrh', 'ldurh', 'ldrsw', 'ldursw',
                        'str', 'stur', 'strb', 'sturb', 'strh', 'sturh']:
                width = (1 if op.endswith('b') else 2 if op.endswith('h') else
                         4 if op.endswith('sw') else 8 if destination.startswith(('x', 'd')) else
                         16 if destination.startswith('q') else 4)
                address = memory(','.join(parts[1:]))
                if op.startswith('st'):
                    write(address, width, 0 if destination in ['xzr', 'wzr'] else regs.get(register_key(destination)))
                else:
                    result = read(address, width)
                    if op.endswith('sw'): result = unary(result, lambda n: (n & 0x7fffffff) - (n & 0x80000000))
                    put(destination, result)
            elif op in ['bl', 'blr', 'svc']:
                escaped = [result.offset for key, result in regs.items()
                           if key in ['x' + str(i) for i in range(8)] and isinstance(result, StackAddress)]
                if state.escaped_floor is not None: escaped.append(state.escaped_floor)
                if escaped:
                    # A callee can write an out parameter or an aggregate reached
                    # through a local pointer. Never retain facts for that region
                    # merely because the ABI preserves the stack pointer.
                    state.escaped_floor = min(escaped)
                    state.stack = {offset: slot for offset, slot in stack.items()
                                   if offset + slot[0] <= state.escaped_floor}
                state.registers = {key: result for key, result in regs.items()
                                   if key == 'sp' or (key.startswith('x') and key[1:].isdigit() and 19 <= int(key[1:]) <= 29)}
                state.registers['x0'] = SymbolicWord((pc, 'return'))
                state.flags = None
                if op == 'bl' and int(parts[0].split()[0], 16) in self.bool_wrappers:
                    state.registers['x0'] = Choice('reg:w0', pc, 0, 1)
            elif op in ['br', 'b', 'ret', 'cbz', 'cbnz', 'tbz', 'tbnz', 'nop'] or op.startswith('b.'):
                pass
            else:
                if re.fullmatch('[wxdsq][0-9]+', destination) and not op.startswith('st'):
                    regs[register_key(destination)] = SymbolicWord((pc, register_key(destination)))
                # Atomic/acquire loads and unknown arithmetic are not guessed.
                if op.endswith('s') or op in ['msr']: state.flags = None
        except (KeyError, ValueError, IndexError, TypeError, struct.error):
            if not op.startswith('st'):
                regs[register_key(destination)] = SymbolicWord((pc, register_key(destination)))
            if op in ['adds', 'subs', 'ands']: state.flags = pc
        return state

    def analyze(self, start, end):
        incoming = {start: State({'sp': StackAddress(0)})}
        queue, queued = deque([start]), {start}
        edges = {}
        iterations = 0
        while queue:
            pc = queue.popleft(); queued.discard(pc)
            instruction = self.instructions.get(pc)
            if instruction is None: continue
            iterations += 1
            if iterations > (end - start) * 100:
                return None, {'start': hex(start), 'status': 'iteration-limit'}
            outgoing = self.transfer(instruction, incoming[pc])
            operands = [part.strip() for part in instruction.operands.split(',')]
            op = instruction.op
            successors = set()
            if op == 'br':
                target = outgoing.registers.get(register_key(operands[0]))
                if isinstance(target, Choice): successors.update([target.false, target.true])
                elif isinstance(target, int): successors.add(target)
                # Keep every discovered edge if later incoming facts weaken.
                successors.update(edges.get(pc, set()))
            elif op == 'b': successors.add(int(operands[0].split()[0], 16))
            elif op.startswith('b.'):
                successors.update([pc + 4, int(operands[0].split()[0], 16)])
            elif op in ['cbz', 'cbnz', 'tbz', 'tbnz']:
                successors.update([pc + 4, int(operands[-1].split()[0], 16)])
            elif op not in ['ret', 'brk', 'udf']: successors.add(pc + 4)
            edges[pc] = successors
            for target in successors:
                if not isinstance(target, int) or target % 4 or not start <= target < end: continue
                joined = incoming[target].join(outgoing) if target in incoming else outgoing.clone()
                if target not in incoming or joined != incoming[target]:
                    incoming[target] = joined
                    if target not in queued: queue.append(target); queued.add(target)
        branches, unresolved = [], []
        for pc, state in incoming.items():
            instruction = self.instructions.get(pc)
            if not instruction or instruction.op != 'br': continue
            target = state.registers.get(register_key(instruction.operands))
            targets = ([target.false, target.true] if isinstance(target, Choice) else
                       [target] if isinstance(target, int) else [])
            if (not targets or set(targets) != edges[pc]
                    or not all(isinstance(t, int) and t % 4 == 0 and t in self.instructions for t in targets)):
                unresolved.append(hex(pc))
                continue
            branches.append((instruction, target, state))
        report = {'start': hex(start), 'end': hex(end), 'reachable_instructions': len(incoming),
                  'iterations': iterations, 'resolved_indirect_branches': len(branches),
                  'unresolved_indirect_branches': unresolved,
                  'status': 'closed' if not unresolved else 'incomplete'}
        self.last_states = incoming
        return branches if not unresolved else None, report


def branch_patch(instruction, target, state, island):
    record = {'address': hex(instruction.address), 'original': [hex(instruction.word)],
              'analysis': 'closed-control-flow-fixed-point'}
    if isinstance(target, int):
        return {**record, 'replacement': [hex(direct_branch(instruction.address, target))], 'targets': [hex(target)]}
    if target.flags is not None and target.flags == state.flags and target.condition in CONDITIONS:
        first = 0x54000040 | CONDITIONS.index(target.condition)
        condition = target.condition
    else:
        if target.condition.startswith('bit|'):
            _, origin, bit_text = target.condition.split('|')
            bit = int(bit_text)
            for key, word in state.registers.items():
                if (re.fullmatch('x[0-9]+', key) and isinstance(word, SymbolicWord)
                        and repr(word.origin) == origin and word.shift == 0 and word.mask & (1 << bit)):
                    first = 0x37000040 | ((bit & 32) << 26) | ((bit & 31) << 19) | int(key[1:])
                    return {**record, 'replacement': [hex(direct_branch(instruction.address, island))],
                            'island': hex(island), 'island_words': [hex(first),
                                hex(direct_branch(island + 4, target.false)), hex(direct_branch(island + 8, target.true))],
                            'condition': 'bit:' + key + ':' + str(bit), 'flags_at': None,
                            'targets': [hex(target.false), hex(target.true)]}
        candidates = [(int(key[1:]), value) for key, value in state.registers.items()
                      if re.fullmatch('x[0-9]+', key) and isinstance(value, Choice)
                      and value.condition == target.condition and value.flags == target.flags
                      and (value.false, value.true) in [(0, 1), (1, 0)]]
        if not candidates:
            sp = state.registers.get('sp')
            if not isinstance(sp, StackAddress): return None
            slots = [(offset, width, value) for offset, (width, value) in state.stack.items()
                     if isinstance(value, Choice) and value.condition == target.condition
                     and value.flags == target.flags and (value.false, value.true) in [(0, 1), (1, 0)]
                     and width >= 4 and 0 <= offset - sp.offset + 16 < 16384
                     and (offset - sp.offset + 16) % 4 == 0]
            if not slots: return None
            offset, _, value = min(slots)
            register = int(instruction.operands[1:])
            load_offset = offset - sp.offset + 16
            # Preserve the scratch register, SP, NZCV, and both branch outcomes.
            words = [0xf81f0fe0 | register,  # str xN,[sp,#-16]!
                     0xb94003e0 | ((load_offset // 4) << 10) | register,
                     (0x35000060 if value.true == 1 else 0x34000060) | register,
                     0xf84107e0 | register,  # ldr xN,[sp],#16
                     direct_branch(island + 16, target.false),
                     0xf84107e0 | register,
                     direct_branch(island + 24, target.true)]
            return {**record, 'replacement': [hex(direct_branch(instruction.address, island))],
                    'island': hex(island), 'island_words': [hex(word) for word in words],
                    'condition': 'stack-bool:' + str(offset - sp.offset), 'flags_at': None,
                    'targets': [hex(target.false), hex(target.true)]}
        register, value = min(candidates, key=lambda item: item[0])
        first = (0x35000040 if value.true == 1 else 0x34000040) | register
        condition = ('reg:w' + str(register))
    return {**record, 'replacement': [hex(direct_branch(instruction.address, island))],
            'island': hex(island),
            'island_words': [hex(first), hex(direct_branch(island + 4, target.false)), hex(direct_branch(island + 8, target.true))],
            'condition': condition, 'flags_at': hex(target.flags) if target.flags is not None else None,
            'targets': [hex(target.false), hex(target.true)]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, default=REPO / '.recovery-work/arm/YTLite.dylib')
    parser.add_argument('--assembly', type=Path, default=REPO / '.recovery-work/arm/application.asm')
    parser.add_argument('--output', type=Path, default=REPO / '.recovery-work/analysis-v2/evidence')
    parser.add_argument('--functions', nargs='*', type=lambda value: int(value, 16))
    args = parser.parse_args()
    if not args.output.resolve().is_relative_to(REPO): parser.error('Output must stay inside /YTLite.')
    macho = MachO(args.binary.read_bytes())
    instructions = parse_assembly(args.assembly.read_text())
    analyzer = Analyzer(macho, instructions)
    old = json.loads((REPO / 'recovery/evidence/branches.json').read_text())
    existing = {int(record['address'], 16): record for record in old}
    island = max([0x4000000] + [int(record['island'], 16) + 12 for record in old if 'island' in record])
    starts = sorted(macho.function_starts)
    reports, additional, conflicts = [], [], []
    for index, start in enumerate(starts):
        if start not in instructions or start >= 0x280000: continue
        if args.functions and start not in args.functions: continue
        end = starts[index + 1] if index + 1 < len(starts) else 0x280000
        if not any(instructions.get(pc) and instructions[pc].op == 'br' for pc in range(start, end, 4)): continue
        branches, report = analyzer.analyze(start, end)
        reports.append(report)
        if branches is None: continue
        for instruction, target, state in branches:
            patch = branch_patch(instruction, target, state, island)
            if patch is None: continue
            patch['function'] = hex(start)
            if instruction.address in existing:
                if set(existing[instruction.address]['targets']) != set(patch['targets']):
                    conflicts.append({'old': existing[instruction.address], 'new': patch})
                continue
            additional.append(patch)
            if 'island' in patch: island += 4 * len(patch['island_words'])
        if len(reports) % 100 == 0:
            print(f'Analyzed {len(reports)} branch-bearing functions; {len(additional)} additional verified resolutions.', flush=True)
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / 'control-flow-report.json').write_text(json.dumps({'functions': reports, 'additional': additional, 'conflicts': conflicts}, indent=2) + '\n')
    if conflicts:
        raise RuntimeError(f'{len(conflicts)} disagreements with old evidence; no combined patches written.')
    combined = sorted(old + additional, key=lambda record: int(record['address'], 16))
    (args.output / 'branches.json').write_text(json.dumps(combined, indent=2) + '\n')
    print(f'{len(reports)} functions analyzed; {sum(r["status"] == "closed" for r in reports)} closed; '
          f'{len(additional)} additional branches; {len(combined)} combined; no original bytes modified.')


if __name__ == '__main__':
    main()
