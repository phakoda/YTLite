#!/usr/bin/env python3
"""Regression tests for static recovery machinery; no original code is executed."""
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from inventory import MachO
from control_flow import (Analyzer, Choice, Instruction, StackAddress, State,
                          SymbolicWord, branch_patch, normalize_word)


def test_image():
    # Two segments intentionally use the same section name.
    image = bytearray(0x1000)
    struct.pack_into('<8I', image, 0, 0xfeedfacf, 0x100000c, 0, 6, 2, 304, 0, 0)
    for index, (segment, address, offset) in enumerate([('__TEXT', 0x1000, 0x400), ('__DATA_CONST', 0x2000, 0x600)]):
        command = 32 + index * 152
        struct.pack_into('<II16sQQQQiiII', image, command, 0x19, 152, segment.encode(),
                         address, 0x200, offset, 0x200, 3, 3, 1, 0)
        struct.pack_into('<16s16sQQIIIIIIII', image, command + 72, b'__const', segment.encode(),
                         address, 0x200, offset, 3, 0, 0, 0, 0, 0, 0)
    struct.pack_into('<d', image, 0x400, 0.819)
    struct.pack_into('<d', image, 0x600, 0.376)
    return image


class InventoryTests(unittest.TestCase):
    def test_duplicate_section_names_keep_distinct_addresses(self):
        macho = MachO(bytes(test_image()))
        self.assertEqual(macho.off(0x1000), 0x400)
        self.assertEqual(macho.off(0x2000), 0x600)
        self.assertEqual(struct.unpack_from('<d', macho.data, macho.off(0x1000))[0], 0.819)
        self.assertEqual(len(macho.section_records), 2)

    def test_utf16_constant_string_counts_code_units(self):
        image = test_image()
        value = 'A💜Я'
        payload = value.encode('utf-16-le')
        struct.pack_into('<QQQQ', image, 0x420, 0, 0x7d0, 0x1080, len(payload) // 2)
        image[0x480:0x480 + len(payload)] = payload
        macho = MachO(bytes(image))
        self.assertEqual(macho.cfstring(0x1020), value)

    def test_runtime_decoded_constant_string(self):
        image = test_image()
        struct.pack_into('<QQQQ', image, 0x420, 0, 0x7c8, 0x1080, 5)
        macho = MachO(bytes(image))
        self.assertEqual(macho.cfstring(0x1020, {0x1080: 'hello'}), 'hello')
        with self.assertRaises(ValueError): macho.cfstring(0x1020, {0x1080: 'bad'})


class FlowTests(unittest.TestCase):
    def setUp(self):
        self.analyzer = Analyzer(MachO(bytes(test_image())), {})

    def step(self, state, address, op, operands):
        return self.analyzer.transfer(Instruction(address, 0, op, operands), state)

    def test_callee_saved_constant_survives_jump_and_call(self):
        state = State({'sp': StackAddress(0), 'x23': 0x2000, 'x8': 0x1000}, flags=0x8000)
        state = self.step(state, 0x8004, 'br', 'x8')
        self.assertEqual(state.registers['x23'], 0x2000)
        state = self.step(state, 0x8008, 'bl', '0x9000')
        self.assertEqual(state.registers['x23'], 0x2000)
        self.assertNotIn('x8', state.registers)
        self.assertIsNone(state.flags)

    def test_joins_do_not_select_one_path(self):
        left = State({'x19': 4, 'x20': 7, 'sp': StackAddress(0)}, {8: (8, 0x1000)})
        right = State({'x19': 5, 'x20': 7, 'sp': StackAddress(0)}, {8: (8, 0x2000)})
        joined = left.join(right)
        self.assertNotIn('x19', joined.registers)
        self.assertEqual(joined.registers['x20'], 7)
        self.assertNotIn(8, joined.stack)

    def test_unknown_overlapping_store_invalidates_previous_value(self):
        state = State({'sp': StackAddress(0)}, {16: (8, 0x12345678)})
        state = self.step(state, 0x8000, 'str', 'w0, [sp, #20]')
        self.assertNotIn(16, state.stack)

    def test_stack_aliases_through_frame_pointer(self):
        state = State({'sp': StackAddress(-64), 'x29': StackAddress(-16), 'x8': 0x2000})
        state = self.step(state, 0x8000, 'str', 'x8, [sp, #16]')
        state = self.step(state, 0x8004, 'ldur', 'x9, [x29, #-32]')
        self.assertEqual(state.registers['x9'], 0x2000)

    def test_out_parameter_invalidates_escaped_stack_region(self):
        state = State({'sp': StackAddress(-64), 'x2': StackAddress(-16)},
                      {-48: (8, 0x2000), -16: (1, 0)})
        state = self.step(state, 0x8000, 'bl', '0x9000')
        self.assertNotIn(-16, state.stack)
        self.assertEqual(state.stack[-48], (8, 0x2000))

    def test_32_bit_reads_discard_high_bits(self):
        state = State({'x19': 0x100000003})
        state = self.step(state, 0x8000, 'mov', 'w8, w19')
        self.assertEqual(state.registers['x8'], 3)

    def test_sign_bit_extractions_share_a_predicate(self):
        word = SymbolicWord((0x8000, 'x19'))
        state = State({'x19': word})
        state = self.step(state, 0x8004, 'lsr', 'x8, x19, #63')
        state = self.step(state, 0x8008, 'lsr', 'x9, x19, #60')
        state = self.step(state, 0x800c, 'and', 'x9, x9, #8')
        self.assertEqual(state.registers['x8'].condition, state.registers['x9'].condition)
        self.assertEqual((state.registers['x8'].false, state.registers['x8'].true), (0, 1))
        self.assertEqual((state.registers['x9'].false, state.registers['x9'].true), (0, 8))

    def test_compound_boolean_requires_its_own_value(self):
        state = State({'x24': Choice('reg:w0', 0x7000, 0, 1)}, flags=0x8000)
        state = self.step(state, 0x8004, 'csel', 'w8, wzr, w24, eq')
        result = state.registers['x8']
        self.assertEqual((result.false, result.true), (0, 1))
        self.assertNotEqual(result.condition, 'eq')
        self.assertIsNone(result.flags)

    def test_stale_flags_cannot_select_branch(self):
        target = Choice('eq', 0x8000, 0x8100, 0x8200)
        state = State({'x8': target}, flags=0x8010)
        self.assertIsNone(branch_patch(Instruction(0x8014, 0xd61f0100, 'br', 'x8'), target, state, 0x4000000))

    def test_stack_boolean_island_preserves_scratch_register(self):
        boolean = Choice('value:0x8000', None, 0, 1)
        target = Choice(boolean.condition, None, 0x8100, 0x8200)
        state = State({'sp': StackAddress(-64), 'x8': target}, {-32: (4, boolean)})
        patch = branch_patch(Instruction(0x8014, 0xd61f0100, 'br', 'x8'), target, state, 0x4000000)
        self.assertEqual(patch['condition'], 'stack-bool:32')
        self.assertEqual(patch['island_words'][0], hex(0xf81f0fe8))
        self.assertEqual(patch['island_words'][3], hex(0xf84107e8))
        self.assertEqual(patch['island_words'][5], hex(0xf84107e8))
        self.assertEqual(len(patch['island_words']), 7)


if __name__ == '__main__':
    unittest.main(verbosity=2)
