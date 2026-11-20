#!/usr/bin/env python3
"""Extract a hash-verified analysis input, recover ivars, and disassemble it.

The package and extracted Mach-O are data, never executable inputs. Output is
confined to this repository. The original recovery exports are not overwritten.
"""
import argparse
import hashlib
import io
import json
from pathlib import Path
import struct
import subprocess
import tarfile
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--variant', choices=['arm', 'arm64', 'arm64e'], default='arm')
    args = parser.parse_args()
    manifest = next(p for p in json.loads((REPO / 'recovery/evidence/packages.json').read_text())
                    if p['package'].endswith(f'iphoneos-{args.variant}.deb'))
    package = REPO / '.recovery-work/inputs' / manifest['package']
    if hashlib.sha256(package.read_bytes()).hexdigest() != manifest['sha256']:
        raise RuntimeError('Package hash does not match the supplied evidence.')
    member = next(n for n in subprocess.check_output(['ar', '-t', str(package)], text=True).splitlines()
                  if n.startswith('data.tar'))
    payload = subprocess.check_output(['ar', '-p', str(package), member])
    with tarfile.open(fileobj=io.BytesIO(payload), mode='r:*') as archive:
        binary_member = next(n for n in archive if n.isfile() and n.name.endswith('/YTLite.dylib'))
        data = archive.extractfile(binary_member).read()
    if hashlib.sha256(data).hexdigest() != manifest['binary_sha256']:
        raise RuntimeError('Extracted binary hash does not match the supplied evidence.')
    work = REPO / '.recovery-work' / args.variant
    work.mkdir(parents=True, exist_ok=True)
    binary = work / 'YTLite.dylib'
    if binary.exists() and binary.read_bytes() != data:
        raise RuntimeError('Refusing to replace a different existing analysis input.')
    binary.write_bytes(data)
    binary.chmod(0o600)
    macho = MachO(data)
    layout = []
    for section in macho.section_records:
        contents = (bytes(section['size']) if section['zerofill'] else
                    data[section['offset']:section['offset'] + section['size']])
        layout.append({**section, 'sha256': hashlib.sha256(contents).hexdigest()})
    (REPO / f'recovery/evidence/{args.variant}-section-layout.json').write_text(json.dumps(layout, indent=2) + '\n')
    classes = macho.classes()
    expected = json.loads((REPO / f'recovery/evidence/{args.variant}-classes.json').read_text())
    if classes != expected:
        raise RuntimeError('Class metadata differs from the original recovery.')
    ivars = {}
    for cls in classes:
        ro = macho.ptr(int(cls['address'], 16) + 32) & ~7
        ivar_list = macho.ptr(ro + 48)
        entries = []
        if ivar_list:
            stride, count = struct.unpack_from('<II', data, macho.off(ivar_list))
            for index in range(count):
                address = ivar_list + 8 + stride * index
                offset_pointer = macho.ptr(address)
                entries.append({
                    'name': macho.string(macho.ptr(address + 8)),
                    'encoding': macho.string(macho.ptr(address + 16)),
                    'offset': macho.u32(macho.off(offset_pointer)),
                    'size': macho.u32(macho.off(address + 28)),
                    'metadata_address': hex(address),
                })
        ivars[cls['name']] = {'instance_size': macho.u32(macho.off(ro + 8)), 'ivars': entries}
    (REPO / 'recovery/evidence/ivars.json').write_text(json.dumps(ivars, indent=2) + '\n')
    assembly = work / 'application.asm'
    with assembly.open('w') as output:
        subprocess.run(['xcrun', 'llvm-objdump', '--disassemble', '--start-address=0x8000',
                        '--stop-address=0x280000', str(binary)], stdout=output, check=True)
    with (work / 'symbols.txt').open('w') as output:
        subprocess.run(['nm', '-an', str(binary)], stdout=output, check=True)
    print(f'Verified binary, {sum(len(c["ivars"]) for c in ivars.values())} ivars, and disassembly: {work}')


if __name__ == '__main__':
    main()
