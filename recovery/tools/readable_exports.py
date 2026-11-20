#!/usr/bin/env python3
"""Expand verified strings/selectors in selected pseudocode without changing it."""
import argparse
import json
from pathlib import Path
import re
from evidence_image import EvidenceImage, REPO


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('addresses', nargs='*', type=lambda text: int(text, 16))
    parser.add_argument('--class', dest='classes', action='append', default=[])
    parser.add_argument('--range', dest='address_range', nargs=2, type=lambda text: int(text, 16),
                        metavar=('START', 'END'), help='Select available exports in a half-open hexadecimal range.')
    parser.add_argument('--source', type=Path, default=REPO / '.recovery-work/analysis-v3/decompiled')
    parser.add_argument('--show', action='store_true')
    args = parser.parse_args()
    source = args.source.resolve()
    source.relative_to(REPO)
    if not source.is_dir(): parser.error('Export directory does not exist: ' + str(source))
    evidence = EvidenceImage()
    metadata = {entry['name']: entry for entry in json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text())}
    names = {}
    for entry in metadata.values():
        for method in entry['methods']:
            names[int(method['address'], 16)] = f'{method["kind"]}[{entry["name"]} {method["selector"]}]'
    addresses = set(args.addresses)
    if args.address_range:
        start, end = args.address_range
        if end <= start: parser.error('Range end must be after its start')
        addresses.update(int(path.stem, 16) for path in source.glob('*.c')
                         if re.fullmatch('[0-9a-fA-F]{8,16}', path.stem) and start <= int(path.stem, 16) < end)
    for name in args.classes:
        if name not in metadata: parser.error('Unknown class: ' + name)
        addresses.update(int(method['address'], 16) for method in metadata[name]['methods'])
    if not addresses: parser.error('Specify hexadecimal function addresses or --class')
    output = REPO / '.recovery-work/readable' / source.parent.name
    output.mkdir(parents=True, exist_ok=True)
    expansions = {}

    def expand(code):
        def constant(match):
            address = int(match[1], 16)
            try:
                value = evidence.cfstring(address)
                if '\0' in value: return match[0]
                replacement = '@' + json.dumps(value, ensure_ascii=False)
                expansions[match[0]] = replacement
                return replacement
            except (ValueError, UnicodeError):
                return match[0]
        code = re.sub(r'&PTR____CFConstantStringClassReference_([0-9a-fA-F]{8,16})', constant, code)
        def selector(match):
            try:
                value = evidence.image.string(evidence.image.ptr(int(match[1], 16)))
                replacement = '@selector(' + value + ')'
                expansions[match[0]] = replacement
                return replacement
            except ValueError:
                return match[0]
        code = re.sub(r'PTR_s_\w+?_([0-9a-fA-F]{8,16})\b', selector, code)
        def cstring(match):
            try:
                replacement = json.dumps(evidence.cstring(int(match[1], 16)), ensure_ascii=False)
                expansions[match[0]] = replacement
                return replacement
            except (ValueError, UnicodeError):
                return match[0]
        code = re.sub(r'\bs_\w+?_([0-9a-fA-F]{8,16})\b', cstring, code)
        # Keep wrapper identities because a wrapper may mask a boolean return.
        def function(match):
            name = evidence.terminal(int(match[1], 16))
            if not name: return match[0]
            replacement = match[0] + ' /* ' + name + ' */'
            expansions[match[0]] = replacement
            return replacement
        return re.sub(r'\b(?:thunk_)?FUN_([0-9a-fA-F]{8,16})\b', function, code)

    for address in sorted(addresses):
        path = source / f'{address:08x}.c'
        if not path.is_file():
            raise FileNotFoundError('Requested function export not present: ' + str(path))
        text = '// PSEUDOCODE ONLY. Types, captures and control flow still require verification.\n'
        text += '// ' + names.get(address, evidence.symbols.get(address, hex(address))) + '\n'
        text += expand(path.read_text())
        (output / path.name).write_text(text)
        if args.show: print(text)
    for name in args.classes:
        paths = [output / f'{int(method["address"], 16):08x}.c' for method in metadata[name]['methods']]
        (output / (name + '.c')).write_text('\n'.join(path.read_text() for path in paths))
    if args.address_range:
        start, end = args.address_range
        paths = [output / f'{address:08x}.c' for address in sorted(addresses) if start <= address < end]
        (output / f'range-{start:08x}-{end:08x}.c').write_text('\n'.join(path.read_text() for path in paths))
    (output / 'last-expansions.json').write_text(json.dumps({'binary_sha256': evidence.sha256, 'expansions': expansions}, ensure_ascii=False, indent=2) + '\n')
    print(f'Expanded {len(addresses)} function exports into {output}; no original evidence was modified.')


if __name__ == '__main__':
    main()
