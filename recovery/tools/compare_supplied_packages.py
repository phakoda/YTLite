#!/usr/bin/env python3
"""Compare supplied package bytes and named method spans without loading a dylib."""
import argparse
from bisect import bisect_right
from collections import Counter
import hashlib
import io
import json
from pathlib import Path
import struct
import subprocess
import tarfile
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]
LIBRARY_CLASSES = {'ArchDetect', 'AtomicLong', 'FFmpegExecution', 'MobileFFmpeg',
                   'CallbackData', 'MobileFFmpegConfig', 'Statistics'}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def archive_files(package, prefix):
    members = subprocess.check_output(['ar', '-t', str(package)], text=True).splitlines()
    member = next(name for name in members if name.startswith(prefix))
    data = subprocess.check_output(['ar', '-p', str(package), member])
    with tarfile.open(fileobj=io.BytesIO(data), mode='r:*') as archive:
        return {entry.name.removeprefix('./'): archive.extractfile(entry).read()
                for entry in archive if entry.isfile()}


def dependencies(data):
    result = []
    offset = 32
    for _ in range(struct.unpack_from('<I', data, 16)[0]):
        command, length = struct.unpack_from('<II', data, offset)
        if command in {0xc, 0x80000018, 0x8000001f, 0x80000023}:
            start = offset + struct.unpack_from('<I', data, offset + 8)[0]
            result.append({'command': hex(command), 'name': data[start:data.index(0, start)].decode()})
        offset += length
    return result


def metadata(classes):
    return {row['name']: {
        'superclass': row['superclass'], 'properties': row['properties'],
        'methods': {m['kind'] + m['selector']: m['encoding'] for m in row['methods']},
    } for row in classes}


def method_spans(image, classes):
    starts = sorted(image.function_starts)
    text, length, _ = image.sections['__text']
    result = {}
    for row in classes:
        for method in row['methods']:
            start = int(method['address'], 16)
            assert start in image.function_starts, ('Missing method boundary', row['name'], method)
            index = bisect_right(starts, start)
            end = starts[index] if index < len(starts) else text + length
            assert text <= start < end <= text + length
            raw = image.data[image.off(start):image.off(start) + end - start]
            key = f"{method['kind']}[{row['name']} {method['selector']}]"
            assert key not in result
            result[key] = {'class': row['name'], 'start': hex(start), 'end': hex(end),
                           'size': len(raw), 'sha256': sha(raw)}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--packages', type=Path, default=Path('/Users/moussah/Downloads'))
    args = parser.parse_args()
    expected_path = REPO / 'recovery/evidence/packages.json'
    expected = {row['package']: row for row in json.loads(expected_path.read_text())}
    packages, methods, classes = {}, {}, {}
    for tag in ['arm64e', 'arm', 'arm64']:
        path = args.packages / f'com.dvntm.ytlite_5.2.2_iphoneos-{tag}.deb'
        package_sha = sha(path.read_bytes())
        assert package_sha == expected[path.name]['sha256'], ('Changed supplied package', path)
        files = archive_files(path, 'data.tar')
        binary_name = next(name for name in files if name.endswith('/YTLite.dylib'))
        binary = files[binary_name]
        assert sha(binary) == expected[path.name]['binary_sha256']
        image = MachO(binary)
        classes[tag] = metadata(image.classes())
        methods[tag] = method_spans(image, image.classes())
        resources = {name.split('YTLite.bundle/', 1)[1]: sha(value)
                     for name, value in files.items() if 'YTLite.bundle/' in name}
        control = archive_files(path, 'control.tar')
        fields = dict(line.split(': ', 1) for line in control.get('control', b'').decode().splitlines()
                      if ': ' in line and not line.startswith(' '))
        cpu, subtype = struct.unpack_from('<II', binary, 4)
        init_data = image.section('__init_offsets')
        packages[tag] = {
            'package': str(path), 'package_sha256': package_sha,
            'binary_path_in_package': binary_name, 'binary_sha256': sha(binary),
            'mach_cpu_type': cpu, 'mach_cpu_subtype': subtype,
            'debian_architecture': fields.get('Architecture'),
            'depends': fields.get('Depends'),
            'function_start_count': len(image.function_starts),
            'initializer_offsets': [hex(value[0]) for value in struct.iter_unpack('<I', init_data)],
            'load_dependencies': dependencies(binary), 'imports': sorted(image.imports),
            'class_count': len(classes[tag]), 'named_method_count': len(methods[tag]),
            'resources': resources,
        }
    comparisons = {}
    for tag in ['arm', 'arm64']:
        assert methods[tag].keys() == methods['arm64e'].keys()
        rows = []
        for name, target in methods['arm64e'].items():
            other = methods[tag][name]
            status = ('same_raw_bytes' if other['sha256'] == target['sha256'] else
                      'different_length' if other['size'] != target['size'] else
                      'same_length_different_raw_bytes')
            rows.append({'method': name, 'first_party': target['class'] not in LIBRARY_CLASSES,
                         'status': status, 'arm64e': target, tag: other})
        comparisons[tag] = {
            'class_metadata_equal': classes[tag] == classes['arm64e'],
            'resource_files_equal': packages[tag]['resources'] == packages['arm64e']['resources'],
            'all_methods': dict(Counter(row['status'] for row in rows)),
            'first_party_methods': dict(Counter(row['status'] for row in rows if row['first_party'])),
            'imports_only_in_arm64e': sorted(set(packages['arm64e']['imports']) - set(packages[tag]['imports'])),
            'imports_only_in_other': sorted(set(packages[tag]['imports']) - set(packages['arm64e']['imports'])),
            'methods': rows,
        }
    report = {
        'target': 'arm64e', 'packages': packages, 'comparisons_to_first_package': comparisons,
        'source_inputs': {str(p.relative_to(REPO)): sha(p.read_bytes()) for p in
                          [Path(__file__).resolve(), REPO / 'recovery/tools/inventory.py', expected_path]},
        'original_binary_executed': False,
        'limits': [
            'Comparison is between supplied binaries, not proof of reconstructed-source parity.',
            'Named method spans stop at the next LC_FUNCTION_STARTS entry. Separate callbacks and callees are not covered by equal method bytes.',
            'Different raw bytes can reflect address relocation or code changes; this report does not infer which.',
            'Equal raw instruction bytes can refer to different data or callees and do not independently prove behavior.',
            'Same class metadata and resources do not prove equivalent registration, initialization or runtime behavior.',
        ],
    }
    destination = REPO / 'recovery/evidence/first-package-comparison.json'
    destination.write_text(json.dumps(report, indent=2) + '\n')
    for tag, comparison in comparisons.items():
        print(tag, 'vs first arm64e:', comparison['first_party_methods'],
              'metadata equal:', comparison['class_metadata_equal'],
              'resources equal:', comparison['resource_files_equal'])
    print('All supplied binaries are data only; no dylib loaded or executed.')


if __name__ == '__main__':
    main()
