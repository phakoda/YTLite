#!/usr/bin/env python3
"""Compile recovered Objective-C and audit emitted iOS metadata without loading it.

The LLVM metadata audit rejects missing/extra methods and changed ABI encodings.
UIKit superclass storage is runtime-rebased, so own ivars are compared by type,
size and relative layout, not by a hard-coded private UIKit instance size.
Compilation and metadata agreement do NOT establish UI behavior or bootstrap
equivalence; those require independent tests and analysis.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import struct
import subprocess

REPO = Path(__file__).resolve().parents[2]
REFERENCE = REPO / 'recovery/evidence'


def decode_llvm_string(value):
    raw = bytearray()
    index = 0
    while index < len(value):
        if value[index] == '\\':
            if not re.fullmatch('[0-9A-Fa-f]{2}', value[index + 1:index + 3]):
                raise ValueError('Unrecognized LLVM escape: ' + value[index:index + 3])
            raw.append(int(value[index + 1:index + 3], 16))
            index += 3
        else:
            raw.extend(value[index].encode('utf-8'))
            index += 1
    if not raw or raw[-1] != 0:
        raise ValueError('Metadata string lacks its terminal NUL')
    return raw[:-1].decode('utf-8')


def extract_metadata(text):
    strings = {}
    for match in re.finditer(r'^(@(?:"[^"\n]+"|[-.$\w]+)) = .*?\bc"((?:\\[0-9a-fA-F]{2}|[^"\n])*)"', text, re.M):
        try:
            strings[match[1]] = decode_llvm_string(match[2])
        except (ValueError, UnicodeDecodeError):
            # A non-text layout bitmap is not a method/property/ivar string.
            pass
    classes = {}
    for match in re.finditer(r'^@"OBJC_CLASS_\$_([^"\n]+)" = (?:dso_local )?global %struct\._class_t \{.*?ptr @"OBJC_CLASS_\$_([^"\n]+)"', text, re.M):
        name, superclass = match.groups()
        classes[name] = {'name': name, 'superclass': superclass, 'methods': {}, 'properties': {}, 'ivars': []}
    for match in re.finditer(r'^@"_OBJC_\$_(INSTANCE|CLASS)_METHODS_([^"\n]+)" = (.+)$', text, re.M):
        kind, name, declaration = match.groups()
        if name not in classes:
            raise ValueError('Method list has no class definition: ' + name)
        records = re.findall(r'%struct\._objc_method \{ ptr (@[-.$\w]+), ptr (@[-.$\w]+), ptr @"[^"\n]+" \}', declaration)
        count = re.search(r'i32 \d+, i32 (\d+),', declaration)
        if count is None or len(records) != int(count[1]):
            raise ValueError('Unrecognized method-list format: ' + name)
        for selector_ref, type_ref in records:
            selector, encoding = strings[selector_ref], strings[type_ref]
            identity = ('-' if kind == 'INSTANCE' else '+') + selector
            if identity in classes[name]['methods']:
                raise ValueError('Duplicate implementation: ' + name + ' ' + identity)
            classes[name]['methods'][identity] = encoding
    offsets = {match[1]: int(match[2]) for match in
               re.finditer(r'^@"(OBJC_IVAR_\$_[^"\n]+)" = (?:hidden )?(?:global|constant) i32 (\d+)', text, re.M)}
    for match in re.finditer(r'^@"_OBJC_\$_INSTANCE_VARIABLES_([^"\n]+)" = (.+)$', text, re.M):
        name, declaration = match.groups()
        records = re.findall(r'%struct\._ivar_t \{ ptr @"([^"\n]+)", ptr (@[-.$\w]+), ptr (@[-.$\w]+), i32 (\d+), i32 (\d+) \}', declaration)
        count = re.search(r'i32 \d+, i32 (\d+),', declaration)
        if count is None or len(records) != int(count[1]):
            raise ValueError('Unrecognized ivar-list format: ' + name)
        for offset_ref, name_ref, type_ref, alignment, size in records:
            classes[name]['ivars'].append({'name': strings[name_ref], 'encoding': strings[type_ref],
                                           'offset': offsets[offset_ref], 'size': int(size)})
    for match in re.finditer(r'^@"_OBJC_\$_PROP_LIST_([^"\n]+)" = (.+)$', text, re.M):
        name, declaration = match.groups()
        if name not in classes:
            continue  # Protocol/category metadata is not a class property list.
        records = re.findall(r'%struct\._prop_t \{ ptr (@[-.$\w]+), ptr (@[-.$\w]+) \}', declaration)
        count = re.search(r'i32 \d+, i32 (\d+),', declaration)
        if count is None or len(records) != int(count[1]):
            raise ValueError('Unrecognized property-list format: ' + name)
        classes[name]['properties'] = {strings[a]: strings[b] for a, b in records}
    return classes


def deployment_evidence(binary):
    data = binary.read_bytes()
    expected = next(item['binary_sha256'] for item in json.loads((REFERENCE / 'packages.json').read_text())
                    if item['package'].endswith('iphoneos-arm.deb'))
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError('Binary no longer matches its package hash')
    position = 32
    for _ in range(struct.unpack_from('<I', data, 16)[0]):
        command, size = struct.unpack_from('<II', data, position)
        if command == 0x32:
            platform, minimum, sdk, tools = struct.unpack_from('<IIII', data, position + 8)
            version = lambda value: f'{value >> 16}.{(value >> 8) & 255}.{value & 255}'
            return {'binary_sha256': expected, 'platform': platform,
                    'minimum_os': version(minimum), 'packaged_sdk': version(sdk)}
        position += size
    raise ValueError('Original LC_BUILD_VERSION not found')


def audit(actual, names):
    expected = {entry['name']: entry for entry in json.loads((REFERENCE / 'arm-classes.json').read_text())}
    expected_ivars = json.loads((REFERENCE / 'ivars.json').read_text())
    report = {}
    for name in names:
        if name not in expected or name not in actual:
            raise ValueError('Class missing from source or evidence: ' + name)
        original, restored = expected[name], actual[name]
        if original['superclass'] != restored['superclass']:
            raise ValueError(name + ': superclass mismatch')
        methods = {entry['kind'] + entry['selector']: entry['encoding'] for entry in original['methods']}
        if methods != restored['methods']:
            raise ValueError(f'{name}: methods missing={methods.keys() - restored["methods"].keys()}, '
                             f'extra={restored["methods"].keys() - methods.keys()}, '
                             f'types={[(key, value, restored["methods"].get(key)) for key, value in methods.items() if restored["methods"].get(key) != value]}')
        properties = {entry['name']: entry['attributes'] for entry in original['properties']}
        if properties != restored['properties']:
            raise ValueError(f'{name}: properties differ: expected {properties}, got {restored["properties"]}')
        def normalized(ivars):
            base = min((entry['offset'] for entry in ivars), default=0)
            return {entry['name']: (entry['encoding'], entry['size'], entry['offset'] - base) for entry in ivars}
        if normalized(expected_ivars[name]['ivars']) != normalized(restored['ivars']):
            raise ValueError(name + ': own ivar types, sizes or relative offsets differ')
        report[name] = {'methods': len(methods), 'properties': len(properties), 'ivars': len(restored['ivars'])}
        print(f'{name}: {len(methods)} exact method encodings, {len(properties)} properties, {len(restored["ivars"])} relative ivar layouts.', flush=True)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, action='append', required=True)
    parser.add_argument('--classes', nargs='+', required=True)
    parser.add_argument('--label', required=True)
    args = parser.parse_args()
    if not re.fullmatch('[a-zA-Z0-9_-]+', args.label):
        parser.error('label must contain only letters, digits, underscores or hyphens')
    sources = [path.resolve() for path in args.source]
    for source in sources:
        source.relative_to(REPO)  # Reject any source outside the authorized repo.
        if source.suffix != '.m' or not source.is_file():
            parser.error('Expected an existing reconstructed .m file: ' + str(source))
    work = REPO / '.recovery-work' / ('ios-audit-' + args.label)
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for variable, name in (('TMPDIR', 'tmp'), ('CLANG_MODULE_CACHE_PATH', 'module-cache')):
        directory = work / name
        directory.mkdir(exist_ok=True)
        env[variable] = str(directory)
    commands = []
    report_path = work / 'report.json'
    if report_path.exists():
        report_path.unlink()  # Never leave an old pass report after a new failure.

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, cwd=REPO, env=env, text=True,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        commands.append({'command': command, 'exit_code': result.returncode, 'output': result.stdout})
        (work / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        print(result.stdout, end='', flush=True)
        result.check_returncode()
        return result.stdout.strip()

    deployment = deployment_evidence(REPO / '.recovery-work/arm/YTLite.dylib')
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter',
             '-target', 'arm64-apple-ios' + deployment['minimum_os'], '-isysroot', sdk]
    classes, objects, dependencies = {}, [], set(sources)
    for index, source in enumerate(sources):
        stem = f'{index:02d}-{source.stem}'
        ir, obj, dependency = (work / (stem + extension) for extension in ('.ll', '.o', '.d'))
        run(['xcrun', '--sdk', 'iphoneos', 'clang', *flags, '-MMD', '-MF', dependency,
             '-S', '-emit-llvm', source, '-o', ir])
        found = extract_metadata(ir.read_text())
        if classes.keys() & found.keys():
            raise ValueError('Duplicate class implementations in selected source files: ' + str(classes.keys() & found.keys()))
        classes.update(found)
        # Compile the audited IR itself so the object cannot diverge from it.
        run(['xcrun', '--sdk', 'iphoneos', 'clang', '-target', 'arm64-apple-ios' + deployment['minimum_os'],
             '-isysroot', sdk, '-c', ir, '-o', obj])
        objects.append(obj)
        for name in shlex.split(dependency.read_text().replace('\\\n', ' ').split(':', 1)[1]):
            path = Path(name).resolve()
            if path.is_relative_to(REPO) and path.is_file():
                dependencies.add(path)
    counts = audit(classes, args.classes)
    archive = work / 'libRecovered.a'
    run(['xcrun', 'libtool', '-static', '-o', archive, *objects])
    dependencies.add(Path(__file__).resolve())
    report = {'classes': counts, 'original_deployment': deployment, 'compiled_sdk_path': sdk,
              'source_sha256': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest()
                                for path in sorted(dependencies)},
              'compile_and_metadata_audit': 'passed', 'ui_runtime_test': 'not performed',
              'youtube_or_bootstrap_integration': 'not established', 'svc_instrumentation': 'not established'}
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    print('iOS source/metadata audit passed:', report_path)


if __name__ == '__main__':
    main()
