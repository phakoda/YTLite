#!/usr/bin/env python3
"""Audit original direct B/BL registration calls independently of decompiler text."""
from bisect import bisect_right
from collections import Counter
from functools import lru_cache
import hashlib
import json
import struct

from evidence_image import EvidenceImage, REPO

APIS = {'_MSHookMessageEx': 'replace', '_class_addMethod': 'add',
        '_method_setImplementation': 'manual-replace'}


def main():
    image = EvidenceImage()
    starts = sorted(image.image.function_starts)
    base, size, _ = image.image.sections['__text']
    data = image.image.data[image.image.off(base):image.image.off(base) + size]
    terminal = lru_cache(None)(image.terminal)
    calls = []
    for index, (word,) in enumerate(struct.iter_unpack('<I', data)):
        opcode = word & 0xfc000000
        if opcode not in (0x14000000, 0x94000000):
            continue
        address = base + index * 4
        delta = word & 0x3ffffff
        if delta & (1 << 25):
            delta -= 1 << 26
        target = address + 4 * delta
        api = terminal(target)
        if api not in APIS:
            continue
        owner = starts[bisect_right(starts, address) - 1]
        # Exact forwarding wrappers implement an API call; they do not create
        # a second registration for each caller of that wrapper.
        if terminal(owner) == api:
            continue
        calls.append({'call_site': hex(address), 'instruction': f'{word:08x}',
                      'transfer': 'B' if opcode == 0x14000000 else 'BL',
                      'wrapper': hex(target), 'registration': hex(owner),
                      'api': api, 'operation': APIS[api]})
    counts = Counter((int(row['registration'], 16), row['operation']) for row in calls)
    old = json.loads((REPO / 'recovery/evidence/hooks.json').read_text())
    expected = Counter((int(row['registration'], 16), row['operation']) for row in old)
    # Later original-word audits recover registrations omitted by truncated
    # exports. Keep the historical 441-record extractor report immutable.
    expected[(0x151a0, 'replace')] = 23
    expected[(0x18e2c, 'replace')] = 1
    expected[(0x1b6d44, 'manual-replace')] = 1
    assert counts == expected, {'unexpected': list((counts - expected).items()),
                                'missing': list((expected - counts).items())}
    assert len(calls) == 466
    assert next(row for row in calls if row['call_site'] == '0x12654')['transfer'] == 'B'
    assert next(row for row in calls if row['call_site'] == '0x18fac')['transfer'] == 'B'
    report = {
        'binary_sha256': image.sha256,
        'text_sha256': hashlib.sha256(data).hexdigest(),
        'scope': 'All aligned direct B/BL transfers in original __text through exact recognized wrappers to three Objective-C registration APIs.',
        'limits': 'This is static call-site coverage, not proof of execution, argument correctness or arbitrary indirect registration targets. Module evidence separately resolves callback arguments and behavior.',
        'historical_records': len(old),
        'registration_call_sites': len(calls),
        'counts': [{'registration': hex(owner), 'operation': operation, 'count': count}
                   for (owner, operation), count in sorted(counts.items())],
        'calls': calls,
        'original_binary_executed': False,
    }
    (REPO / 'recovery/evidence/registration-call-audit.json').write_text(json.dumps(report, indent=2) + '\n')
    print('Registration audit: 466 original direct call sites accounted for, including two tail calls and 25 records beyond the historical extractor.')


if __name__ == '__main__':
    main()
