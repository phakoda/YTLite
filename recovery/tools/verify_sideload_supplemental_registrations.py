#!/usr/bin/env python3
"""Read-only audit of every direct original registration in initializer 0x151a0."""
import hashlib
import json
import re
from evidence_image import EvidenceImage, REPO


def original_lines(image, start, end):
    rows = []
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s+(.*?)(?:\s*;.*)?$', line)
        if m and start <= int(m[1], 16) < end:
            address, word = int(m[1], 16), int(m[2], 16)
            assert image.image.u32(image.image.off(address)) == word
            rows.append((address, word, m[3].strip()))
    assert len(rows) == (end - start) // 4
    return rows


def recover_registrations(image):
    # This original interval is straight-line registration code: no conditional
    # transfers or Objective-C message sends. All calls resolve to three APIs.
    regs, result = {}, []
    for address, word, text in original_lines(image, 0x16d18, 0x170c0):
        op = text.split()[0]
        if op == 'adrp':
            m = re.match(r'adrp\s+(x\d+), 0x([0-9a-f]+)', text)
            regs[m[1]] = int(m[2], 16)
        elif op == 'add':
            m = re.match(r'add\s+(x\d+), (x\d+), #0x([0-9a-f]+)', text)
            assert m, text
            regs[m[1]] = regs[m[2]] + int(m[3], 16)
        elif op == 'mov':
            m = re.match(r'mov\s+(x\d+), (x\d+)', text)
            assert m, text
            regs[m[1]] = regs[m[2]]
        elif op == 'ldr':
            m = re.match(r'ldr\s+(x\d+), \[(x\d+), #0x([0-9a-f]+)\]', text)
            assert m, text
            regs[m[1]] = image.image.ptr(regs[m[2]] + int(m[3], 16))
        elif op == 'bl':
            m = re.match(r'bl\s+0x([0-9a-f]+)', text)
            target = int(m[1], 16)
            terminal = image.terminal(target)
            if terminal == '_objc_getClass':
                regs['x0'] = (image.cstring(regs['x0']), '-')
            elif terminal == '_object_getClass':
                regs['x0'] = (regs['x0'][0], '+')
            elif terminal == '_MSHookMessageEx':
                result.append(dict(class_name=regs['x0'][0], kind=regs['x0'][1], selector=image.cstring(regs['x1']), operation='replace', implementation=hex(regs['x2']), registration='000151a0', call_site=hex(address), call_instruction=f'{word:08x}', call_wrapper=hex(target), original_slot=hex(regs['x3'])))
            else:
                raise AssertionError((hex(address), terminal))
        else:
            raise AssertionError((hex(address), text))
    assert len(result) == 23
    return result


def main():
    image = EvidenceImage()
    manifest = json.loads((REPO / 'recovery/evidence/sideload-supplemental-registrations.json').read_text())
    assert manifest['binary_sha256'] == image.sha256
    recovered = recover_registrations(image)
    for parsed, expected in zip(recovered, manifest['registrations']):
        assert all(expected[k] == v for k, v in parsed.items()), (parsed, expected)
    assert len(manifest['registrations']) == 23
    for span in manifest['instruction_intervals']:
        start, end = int(span['start'], 16), int(span['end'], 16)
        raw = image.image.data[image.image.off(start):image.image.off(end)]
        assert hashlib.sha256(raw).hexdigest() == span['sha256']
        original_lines(image, start, end)
    predicate = manifest['initializer_predicate']
    for item in predicate['cfstrings']:
        assert image.cfstring(int(item['address'], 16)) == item['value']
    delta = -(image.image.u32(image.image.off(0x1155090)) ^ 0xd9374ce6)
    delta = (delta + (1 << 31)) % (1 << 32) - (1 << 31)
    assert [hex(image.image.ptr(0x1155080 + i * 8) + delta) for i in range(2)] == predicate['branch_targets_false_true']
    assert image.image.u32(image.image.off(0x16ce8)) == 0x0a160308
    assert image.image.ptr(0x1061450 + 16) == 0x19b24
    assert image.terminal(0x1cfe0) == '_ptnRegisterBlock'
    assert image.image.u32(image.image.off(0x170c8)) == 0x940017c6
    hooks = json.loads((REPO / 'recovery/evidence/hooks.json').read_text())
    assert not any(h['registration'] == '000151a0' for h in hooks)
    excluded = manifest['deferred_security_exclusions']
    assert len(excluded) == 18
    for entry in excluded:
        assert any(h == entry['original_inventory_row'] for h in hooks)
        assert entry['status'] == 'evidence-only-excluded'
    print('Verified 23 supplemental original registrations, initializer predicate and deferred block; 18 security records remain evidence-only. No packaged code executed.')


if __name__ == '__main__':
    main()
