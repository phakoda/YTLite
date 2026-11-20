#!/usr/bin/env python3
"""Inventory recovered registrations without treating an old selector as proof.

Each original registrar/implementation pair is a distinct record. This preserves
stacked hooks that would disappear in a class/selector-only coverage report.
Module manifests establish declared coverage and pinned evidence, not behavior.
Their module-specific runtime verifiers remain required.
"""
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re
import struct

from evidence_image import EvidenceImage, REPO
from report import source_methods


def address(value):
    if value is None:
        return None
    try:
        return hex(int(value, 16))
    except ValueError:
        return value


def identity(record):
    return (address(record['registration']), address(record['implementation']),
            record['class_name'], record['kind'], record['selector'], record['operation'])


def main():
    image = EvidenceImage()
    hooks = json.loads((REPO / 'recovery/evidence/hooks.json').read_text())
    originals = {identity(row): row for row in hooks}
    assert len(originals) == len(hooks), 'Duplicate evidence records need explicit identifiers'
    manifests = sorted((REPO / 'recovery/source/Hooks').glob('*.manifest.json'))
    claims = {}
    modules = []
    additional = []
    exclusions = []
    resolutions = {}
    manual = []
    owner_resolution_path = REPO / 'recovery/evidence/registration-resolutions.json'
    if owner_resolution_path.is_file():
        from verify_registration_resolutions import main as verify_owner_resolutions
        verify_owner_resolutions()
        owner_manifest = json.loads(owner_resolution_path.read_text())
        assert owner_manifest['binary_sha256'] == image.sha256
        for resolution in owner_manifest['resolutions']:
            key = identity(resolution['original_inventory_row'])
            assert key in originals and key not in claims
            claims[key] = resolution['source_owner']
            resolutions[key] = resolution
        additional.extend(dict(row, reconstruction_module=row['source_owner'])
                          for row in owner_manifest['additional_registrations'])
    supplemental_path = REPO / 'recovery/evidence/sideload-supplemental-registrations.json'
    if supplemental_path.is_file():
        from verify_sideload_supplemental_registrations import main as verify_supplemental
        verify_supplemental()
        supplemental = json.loads(supplemental_path.read_text())
        exclusions.extend(dict(row, manifest=str(supplemental_path.relative_to(REPO)))
                          for row in supplemental['registrations']
                          if row['status'] == 'evidence-only-excluded')
    for path in manifests:
        manifest = json.loads(path.read_text())
        assert manifest['binary_sha256'] == image.sha256, path
        source = path.with_name(path.name.removesuffix('.manifest.json') + '.x')
        assert source.is_file(), source
        rows = manifest.get('registrations', manifest.get('implemented_registrations'))
        assert rows is not None, ('Manifest has no registration inventory', path)
        for span in manifest.get('instruction_intervals', []):
            start, end = int(span['start'], 16), int(span['end'], 16)
            raw = image.image.data[image.image.off(start):image.image.off(end)]
            assert hashlib.sha256(raw).hexdigest() == span['sha256'], (path, span)
        for resolution in manifest.get('resolutions', []):
            original = resolution['original_inventory_row']
            key = identity(original)
            assert key in originals and not originals[key]['complete'], (path, resolution)
            assert address(resolution['implementation']) == address(original['implementation'])
            assert key not in resolutions
            resolutions[key] = dict(resolution)
        if 'manual_registration' in manifest:
            registration = manifest['manual_registration']
            spans = {int(span['start'], 16): span for span in manifest['additional_functions']}
            for field in ('registrar', 'implementation'):
                span = spans[int(registration[field], 16)]
                start, end = int(span['start'], 16), int(span['end'], 16)
                raw = image.image.data[image.image.off(start):image.image.off(end)]
                assert hashlib.sha256(raw).hexdigest() == span['sha256']
            initializer = registration['initializer']
            assert struct.unpack('<I', image.buffer(int(initializer['entry'], 16), 4))[0] == int(registration['registrar'], 16)
            manual.append(dict(registration, reconstruction_module=str(source.relative_to(REPO))))
        for row in rows:
            key = identity(row)
            if key not in originals:
                # Later instruction audits can recover registrations missed by
                # the original truncated decompiler export. Keep them visible
                # without changing the denominator of that historical report.
                assert row.get('call_site') and row.get('original_slot'), (path, key)
                additional.append(dict(row, reconstruction_module=str(source.relative_to(REPO))))
                continue
            assert key not in claims, ('Two modules claim a registration', path, claims.get(key), key)
            assert address(row.get('original_pointer')) == address(originals[key].get('original_pointer')), key
            if 'instruction_sha256' in row:
                start, end = int(row['implementation'], 16), int(row['instruction_end'], 16)
                assert end > start
                raw = image.image.data[image.image.off(start):image.image.off(end)]
                assert hashlib.sha256(raw).hexdigest() == row['instruction_sha256'], key
            claims[key] = str(source.relative_to(REPO))
        exclusions.extend(dict(row, manifest=str(path.relative_to(REPO))) for row in manifest.get('excluded_registrations', []))
        modules.append({'source': str(source.relative_to(REPO)), 'manifest': str(path.relative_to(REPO)),
                        'declared_registrations': len(rows), 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                        'manifest_sha256': hashlib.sha256(path.read_bytes()).hexdigest()})

    selected = list(REPO.glob('*.x'))
    make = (REPO / 'recovery/source/recovered.mk').read_text()
    for pattern in re.findall(r'recovery/source/[\w+./*]+\.(?:x|m)', make):
        selected.extend(REPO.glob(pattern))
    selected = sorted(set(selected))
    selected_paths = {str(path.relative_to(REPO)) for path in selected}
    owners = defaultdict(list)
    for path in selected:
        for signature in source_methods(path.read_text()):
            owners[signature].append(str(path.relative_to(REPO)))
    rows = []
    for hook in hooks:
        row = dict(hook)
        row['reconstruction_module'] = claims.get(identity(hook))
        resolution = resolutions.get(identity(hook))
        if resolution:
            row['resolved_target'] = resolution
        row['selected_sources_with_signature'] = owners.get(((resolution or hook)['class_name'], (resolution or hook)['kind'], (resolution or {}).get('selector', hook['selector'])), [])
        row['module_selected_for_build'] = row['reconstruction_module'] in selected_paths
        rows.append(row)
    for row in additional + manual:
        row['module_selected_for_build'] = row['reconstruction_module'] in selected_paths
    repeated = defaultdict(list)
    for row in hooks:
        if row['complete']:
            repeated[(row['class_name'], row['kind'], row['selector'])].append(row)
    init_bytes = image.image.section('__init_offsets')
    initializers = list(struct.unpack('<' + 'I' * (len(init_bytes) // 4), init_bytes))
    init_rows = []
    for start in initializers:
        end = min(a for a in image.image.function_starts if a > start)
        raw = image.image.data[image.image.off(start):image.image.off(end)]
        init_rows.append({'address': hex(start), 'instruction_end': hex(end), 'instruction_sha256': hashlib.sha256(raw).hexdigest()})
    report = {
        'binary_sha256': image.sha256,
        'scope': 'Static registration evidence and declared module coverage. Signatures do not prove callback bodies, runtime behavior, registration timing or final integration.',
        'registration_records': len(rows),
        'records_claimed_by_reconstruction_manifests': len(claims),
        'records_without_reconstruction_manifest': len(rows) - len(claims),
        'unmapped_records': [r for r in rows if not r['complete']],
        'additional_registration_records': additional,
        'manual_registration_records': manual,
        'resolved_extracted_records': [r for r in rows if 'resolved_target' in r],
        'still_unmapped_records': [r for r in rows if not r['complete'] and 'resolved_target' not in r],
        'explicit_exclusions': exclusions,
        'modules': modules,
        'registrations': rows,
        'layered_signatures': [group for group in repeated.values() if len(group) > 1],
        'packaged_initializer_order': init_rows,
        'initializer_section_sha256': hashlib.sha256(init_bytes).hexdigest(),
        'inventory_limits': [
            'The two originally unresolved class_addMethod records resolve to ToastWindow initialize: an alias and a duplicate-add attempt, not two new external callbacks.',
            'The YTPivotBarViewController renderer method_setImplementation at 0x1b6d44 is outside the original MSHookMessageEx/class_addMethod inventory.',
            'Three NSBundle infoDictionary registration paths share the same replacement; one was missed by the historical extractor. Counting records is not counting unique runtime installations.',
            'The independent direct-call audit finds 466 original B/BL registration sites. The historical extractor contains 441; the remaining 25 are tracked as supplemental or manual records.',
            'Per-module runtime checks and final registration timing are not performed by this inventory.'
        ],
    }
    target = REPO / 'recovery/evidence/hook-source-inventory.json'
    target.write_text(json.dumps(report, indent=2) + '\n')
    print(f'{len(claims)}/{len(rows)} extracted registration records have reconstruction manifests.')
    print(f'{len(report["layered_signatures"])} repeated class/selector signatures retained as distinct registrations.')
    print('Inventory:', target)


if __name__ == '__main__':
    main()
