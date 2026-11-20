#!/usr/bin/env python3
"""Preserve both outcomes of explicitly identified bootstrap-state byte tables.

This analysis is conditional on the listed globals being Boolean state bytes.
That assumption is reported, not silently generalized to arbitrary byte loads.
Every new branch must still have a closed, fixed-point control-flow graph and
agree with the independently recovered destinations. No package is executed.
"""
import argparse
import json
from pathlib import Path
from control_flow import Analyzer, Choice, branch_patch, parse_assembly, direct_branch
from evidence_image import EvidenceImage, REPO


class StateAnalyzer(Analyzer):
    def __init__(self, image, instructions, booleans):
        super().__init__(image, instructions)
        self.booleans = booleans

    def load(self, address, width):
        if isinstance(address, int) and address in self.booleans and width == 1:
            return Choice('bootstrap-state:' + hex(address), None, 0, 1)
        return super().load(address, width)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--boolean', nargs='+', type=lambda text: int(text, 16),
                        default=[0x1225d11, 0x1225d12, 0x1225d20, 0x1225d58, 0x1225d80])
    parser.add_argument('--functions', nargs='*', type=lambda text: int(text, 16))
    args = parser.parse_args()
    image = EvidenceImage()
    instructions = parse_assembly((REPO / '.recovery-work/arm/application.asm').read_text())
    analyzer = StateAnalyzer(image.image, instructions, set(args.boolean))
    old = json.loads((REPO / '.recovery-work/analysis-v2/evidence/branches.json').read_text())
    existing = {int(record['address'], 16): record for record in old}
    island = max([0x4000000] + [int(record['island'], 16) + 4 * len(record['island_words'])
                               for record in old if 'island' in record])
    starts = sorted(image.image.function_starts)
    reports, additional, conflicts = [], [], []
    for index, start in enumerate(starts[:-1]):
        if args.functions and start not in args.functions: continue
        if not args.functions and not 0x23000 <= start < 0x33000: continue
        end = starts[index + 1]
        if not any(instructions.get(pc) and instructions[pc].op == 'br' for pc in range(start, end, 4)): continue
        branches, report = analyzer.analyze(start, end)
        reports.append(report)
        if branches is None: continue
        for instruction, target, state in branches:
            patch = branch_patch(instruction, target, state, island)
            if patch is None and isinstance(target, Choice) and target.false != target.true:
                # If the original target register is the only surviving value,
                # distinguish its two verified addresses without changing any
                # register, SP or NZCV. This is for image-base-zero analysis only.
                difference = target.false ^ target.true
                bit = (difference & -difference).bit_length() - 1
                register = int(instruction.operands[1:])
                branch_on_one = bool(target.true & (1 << bit))
                first = ((0x37000040 if branch_on_one else 0x36000040) |
                         ((bit & 32) << 26) | ((bit & 31) << 19) | register)
                patch = {'address': hex(instruction.address), 'original': [hex(instruction.word)],
                         'replacement': [hex(direct_branch(instruction.address, island))],
                         'island': hex(island), 'island_words': [hex(first),
                             hex(direct_branch(island + 4, target.false)), hex(direct_branch(island + 8, target.true))],
                         'condition': f'original-target-bit:x{register}:{bit}', 'flags_at': None,
                         'targets': [hex(target.false), hex(target.true)]}
            if patch is None: continue
            if instruction.address in existing:
                if set(existing[instruction.address]['targets']) != set(patch['targets']):
                    conflicts.append({'old': existing[instruction.address], 'new': patch})
                continue
            patch['function'] = hex(start)
            patch['analysis'] = 'closed-CFG-with-explicit-Boolean-state-contract'
            patch['state_contracts'] = [hex(address) for address in args.boolean]
            additional.append(patch)
            if 'island' in patch: island += 4 * len(patch['island_words'])
    if island > 0x4010000: raise ValueError('Analysis branch-island allocation exceeds reserved range')
    output = REPO / '.recovery-work/analysis-v4/evidence'
    output.mkdir(parents=True, exist_ok=True)
    report = {'binary_sha256': image.sha256, 'boolean_state_contracts': [hex(address) for address in args.boolean],
              'functions': reports, 'additional': additional, 'conflicts': conflicts}
    (output / 'state-flow-report.json').write_text(json.dumps(report, indent=2) + '\n')
    if conflicts: raise ValueError('State analysis disagrees with prior evidence; no combined output written')
    combined = sorted(old + additional, key=lambda record: int(record['address'], 16))
    (output / 'branches.json').write_text(json.dumps(combined, indent=2) + '\n')
    print(f'Closed {sum(entry["status"] == "closed" for entry in reports)} of {len(reports)} bootstrap functions; '
          f'{len(additional)} additional branches ({len(combined)} total), preserving both state outcomes.')


if __name__ == '__main__': main()
