#!/usr/bin/env python3
"""Check original helper media evidence and current actual-source runtime proof."""
import hashlib
import json
import re
import struct
import argparse
from pathlib import Path
from evidence_image import EvidenceImage, REPO
from verify_selector_loads import verify_selector_loads


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    group = parser.add_mutually_exclusive_group()
    group.add_argument('--rendering', action='store_true', help='Verify the separate rendering audit.')
    group.add_argument('--image', action='store_true', help='Verify image URL and callback recovery.')
    args = parser.parse_args()
    suffix = 'image' if args.image else 'rendering' if args.rendering else 'media'
    expected_checks, runtime_label, fixture = {
        'image': (27, 'Helper_image_fidelity', 'helper_image_runtime.m'),
        'rendering': (31, 'Helper_rendering_fidelity', 'helper_render_runtime.m'),
        'media': (22, 'Helper_media_presentation_fidelity', 'helper_media_runtime.m'),
    }[suffix]
    work = REPO / f'.recovery-work/helper-{suffix}'
    work.mkdir(exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    evidence = REPO / f'recovery/evidence/helper-{suffix}-fidelity.json'
    data = json.loads(evidence.read_text())
    image = EvidenceImage()
    assert image.sha256 == data['binary_sha256']
    words = 0
    for span in data['spans']:
        start, end = int(span['start'], 16), int(span['end'], 16)
        raw = image.image.data[image.image.off(start):image.image.off(start) + end - start]
        assert hashlib.sha256(raw).hexdigest() == span['sha256'], span
        words += len(raw) // 4
    for branch in data['branches']:
        table, key_address, xor = [int(branch[k], 16) for k in ['table', 'key_address', 'xor']]
        key = struct.unpack('<I', image.buffer(key_address, 4))[0]
        delta = (-(key ^ xor)) & 0xffffffff
        if delta >= 2**31:
            delta -= 2**32
        assert [hex(image.image.ptr(table + i * 8) + delta) for i in range(2)] == branch['targets']
    for selector in data['selectors']:
        assert image.cstring(image.image.ptr(int(selector['reference'], 16))) == selector['name']
    verify_selector_loads(image.image,data)
    runtime_path = REPO / '.recovery-work/presentation-helpers/runtime-verification.json'
    runtime = json.loads(runtime_path.read_text())
    assert runtime['passed'] and runtime['runtime_returncode'] == 0
    inputs = dict(runtime['sources'])
    inputs.update(runtime['fixture_support_inputs'])
    assert f'recovery/tests/{fixture}' in inputs
    for path, sha in inputs.items():
        assert digest(REPO / path) == sha, ('Stale runtime input', path)
    log = REPO / '.recovery-work/presentation-helpers/native/runtime.log'
    match = re.search(r'PASS ' + runtime_label + r': (\d+) assertions', log.read_text())
    assert match and int(match[1]) >= expected_checks
    metadata_path = REPO / '.recovery-work/presentation-helpers/source-verification.json'
    metadata = json.loads(metadata_path.read_text())
    assert metadata['passed']
    classes = [row for row in metadata['classes'] if row['class'] == 'YTLHelper']
    assert {row['architecture'] for row in classes} == {'arm64', 'arm64e'}
    for row in classes:
        assert digest(REPO / row['source']) == row['source_sha256']
        assert row['method_count'] == 22 and not row['differences']
    for path in [evidence, Path(__file__).resolve(), runtime_path, metadata_path, log,
                 REPO / f'recovery/source/Helpers/YTLHelper.{suffix}.provenance.md']:
        inputs[str(path.relative_to(REPO))] = digest(path)
    for name in ['verify_selector_loads.py','evidence_image.py','inventory.py']:
        path=REPO/'recovery/tools'/name
        inputs[str(path.relative_to(REPO))]=digest(path)
    report.write_text(json.dumps({
        'passed': True, 'runtime_assertions': int(match[1]), 'original_words': words,
        'original_spans': len(data['spans']), 'functional_branch_tables': len(data['branches']),
        'scope': data['scope'], 'inputs': inputs, 'original_binary_executed': False,
        'limits': ['The shared runtime executes reconstructed source against synthetic framework boundaries.',
                   'Download file-component guards remain outside these helper presentation audits.',
                   'No device, live Photos or host application execution.'],
    }, indent=2) + '\n')
    print(f'Helper {suffix}: {match[1]} actual-source checks, {words} original words, both iOS ABIs current.')


if __name__ == '__main__':
    main()
