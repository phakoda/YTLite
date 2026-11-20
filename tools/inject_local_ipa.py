#!/usr/bin/env python3
"""Embed the verified local YTLite build into a supplied decrypted YouTube IPA."""
import argparse
import copy
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import plistlib
import shutil
import stat
import struct
import subprocess
import sys
import tempfile
import zipfile

from build_local import input_hashes

ROOT = Path(__file__).resolve().parents[1]
CYAN_REVISION = '740d3716dcd98c20c000f12cdb88f1f0b2a533a4'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def macho(data):
    """Read arm64 load commands and hash file-backed sections without loading code."""
    assert data[:4] == bytes.fromhex('cffaedfe'), 'Expected a thin 64-bit Mach-O'
    assert struct.unpack_from('<I', data, 4)[0] == 0x100000c, 'Expected arm64'
    count = struct.unpack_from('<I', data, 16)[0]
    result = {'libraries': [], 'rpaths': [], 'cryptids': [], 'sections': {}}
    offset = 32
    for _ in range(count):
        cmd, size = struct.unpack_from('<II', data, offset)
        assert size >= 8 and offset + size <= len(data)
        if cmd in [0xc, 0x80000018, 0x8000001f, 0x8000001c]:
            start = offset + struct.unpack_from('<I', data, offset + 8)[0]
            name = data[start:data.index(0, start, offset + size)].decode()
            result['rpaths' if cmd == 0x8000001c else 'libraries'].append(name)
        elif cmd in [0x21, 0x2c]:
            result['cryptids'].append(struct.unpack_from('<I', data, offset + 16)[0])
        elif cmd == 0x19:
            nsects = struct.unpack_from('<I', data, offset + 64)[0]
            for index in range(nsects):
                pos = offset + 72 + index * 80
                section = data[pos:pos + 16].split(b'\0')[0].decode()
                segment = data[pos + 16:pos + 32].split(b'\0')[0].decode()
                address, length, start = struct.unpack_from('<QQI', data, pos + 32)
                flags = struct.unpack_from('<I', data, pos + 64)[0]
                if flags & 0xff not in [1, 12, 18]:
                    assert start + length <= len(data)
                    result['sections'][segment + ',' + section] = {
                        'address': address, 'size': length, 'sha256': sha(data[start:start + length])}
        offset += size
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('ipa', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--cyan', type=Path, default=ROOT / '.recovery-work/ipa-tools/pyzule-rw')
    args = parser.parse_args()
    assert args.ipa.resolve() != args.output.resolve() and not args.output.exists(), 'Use a new output path'
    build = json.loads((ROOT / '.recovery-work/build/latest-build.json').read_text())
    assert build['status'] == 'passed' and build['input_sha256'] == input_hashes(), 'Rebuild current source first'
    dylib = ROOT / build['artifact']
    assert sha(dylib.read_bytes()) == build['artifact_sha256']
    assert subprocess.check_output(['git', '-C', str(args.cyan), 'rev-parse', 'HEAD'], text=True).strip() == CYAN_REVISION
    original_sha = sha(args.ipa.read_bytes())
    work = ROOT / '.recovery-work/ipa-injection'
    work.mkdir(parents=True, exist_ok=True)
    log_path = work / 'latest.log'
    with zipfile.ZipFile(args.ipa) as original, tempfile.TemporaryDirectory(prefix='ytlite-ipa-', dir='/tmp') as directory:
        names = original.namelist()
        assert len(names) == len(set(names)), 'Duplicate ZIP entries'
        for entry in original.infolist():
            path = PurePosixPath(entry.filename)
            assert not path.is_absolute() and '..' not in path.parts and not stat.S_ISLNK(entry.external_attr >> 16), entry.filename
        app_plists = [n for n in names if n.startswith('Payload/') and n.count('/') == 2 and n.endswith('.app/Info.plist')]
        assert len(app_plists) == 1
        info = plistlib.loads(original.read(app_plists[0]))
        assert info['CFBundleIdentifier'] == 'com.google.ios.youtube'
        app = app_plists[0].rsplit('/', 1)[0]
        executable = app + '/' + info['CFBundleExecutable']
        old_main = macho(original.read(executable))
        assert old_main['cryptids'] and not any(old_main['cryptids']), 'The supplied main executable must already be decrypted'
        assert app + '/Frameworks/YTLite.dylib' not in names, 'YTLite is already present'
        temp = Path(directory)
        native_tools = temp / 'cyan-source'
        # Checkout on a native filesystem to restore Git's Unix modes when the
        # persistent tool checkout lives on ExFAT.
        subprocess.run(['git', 'clone', '--quiet', '--no-hardlinks', str(args.cyan.resolve()), str(native_tools)], check=True)
        bundle = temp / 'YTLite.bundle'
        source_bundle = ROOT / 'layout/Library/Application Support/YTLite.bundle'
        shutil.copytree(source_bundle, bundle, ignore=shutil.ignore_patterns('.*'))
        for path in [bundle, *bundle.rglob('*')]:
            path.chmod(0o755 if path.is_dir() else 0o644)
        native_dylib = temp / 'YTLite.dylib'
        shutil.copyfile(dylib, native_dylib)
        native_dylib.chmod(0o755)
        generated = temp / 'injected.ipa'
        command = [sys.executable, '-m', 'cyan', '-i', str(args.ipa.resolve()), '-o', str(generated),
                   '-f', str(native_dylib), str(bundle)]
        env = os.environ.copy()
        env.update(PYTHONPATH=str(native_tools), TMPDIR='/tmp', PYTHONDONTWRITEBYTECODE='1')
        with log_path.open('w') as log:
            subprocess.run(command, cwd=ROOT, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
        # Cyan emits Payload only. Preserve original archive metadata/artwork too.
        with zipfile.ZipFile(generated, 'a') as output:
            present = set(output.namelist())
            for entry in original.infolist():
                if not entry.filename.startswith('Payload/') and entry.filename not in present:
                    output.writestr(copy.copy(entry), original.read(entry))
        with zipfile.ZipFile(generated) as output:
            assert output.testzip() is None, 'ZIP integrity failed'
            new_main = macho(output.read(executable))
            assert new_main['sections'] == old_main['sections'], 'App code/data sections changed'
            assert new_main['libraries'] == old_main['libraries'] + ['@rpath/YTLite.dylib']
            assert '@executable_path/Frameworks' in new_main['rpaths']
            tweak_name = app + '/Frameworks/YTLite.dylib'
            embedded = macho(output.read(tweak_name))
            old_tweak = macho(dylib.read_bytes())
            assert embedded['sections'] == old_tweak['sections'], 'Tweak code/data sections changed'
            expected_libraries = [lib.replace('/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate',
                                  '@rpath/CydiaSubstrate.framework/CydiaSubstrate') for lib in old_tweak['libraries']]
            assert embedded['libraries'] == expected_libraries
            framework = 'Frameworks/CydiaSubstrate.framework/'
            runtime_name = app + '/' + framework + 'CydiaSubstrate'
            runtime_source = native_tools / 'cyan/extras/CydiaSubstrate.framework/CydiaSubstrate'
            assert output.read(runtime_name) == runtime_source.read_bytes()
            assert '/usr/lib/swift' in macho(output.read(runtime_name))['rpaths']
            resources = {}
            for path in bundle.rglob('*'):
                if path.is_file():
                    name = app + '/YTLite.bundle/' + path.relative_to(bundle).as_posix()
                    assert output.read(name) == path.read_bytes(), name
                    resources[name] = sha(path.read_bytes())
            for entry in original.infolist():
                if not entry.is_dir() and entry.filename != executable:
                    assert output.read(entry.filename) == original.read(entry), ('Changed original file', entry.filename)
            new_entries = set(output.namelist()) - set(names)
            # The source ZIP omits directory records; zip adds those records
            # when repacking the same original files.
            added = sorted(n for n in new_entries if not output.getinfo(n).is_dir())
            unexpected = [n for n in added if not (n.startswith((app + '/YTLite.bundle/', app + '/' + framework)) or
                          n in [tweak_name, app + '/cyan.entitlements'])]
            assert not unexpected, unexpected[:20]
            for entry in output.infolist():
                if entry.filename in new_entries:
                    mode = stat.S_IMODE(entry.external_attr >> 16)
                    assert mode & 0o444 == 0o444 and (not entry.is_dir() or mode & 0o111 == 0o111), (entry.filename, oct(mode))
            report = {'passed': True, 'input': str(args.ipa.resolve()), 'input_sha256': original_sha,
                      'output': str(args.output.resolve()), 'output_sha256': sha(generated.read_bytes()),
                      'bundle_id': info['CFBundleIdentifier'], 'youtube_version': info['CFBundleShortVersionString'],
                      'build_dylib_sha256': build['artifact_sha256'], 'embedded_dylib_sha256': sha(output.read(tweak_name)),
                      'cyan_repository': 'https://github.com/asdfzxcvbn/pyzule-rw', 'cyan_revision': CYAN_REVISION,
                      'hook_runtime_sha256': sha(output.read(runtime_name)), 'resources': resources,
                      'added_files': added, 'added_directory_records': len(new_entries) - len(added),
                      'app_and_tweak_file_backed_sections_unchanged': True,
                      'original_files_except_main_executable_unchanged': True, 'device_validation': 'not performed',
                      'signing': 'Requires normal device signing/provisioning before installation',
                      'script_sha256': sha(Path(__file__).read_bytes()), 'log_sha256': sha(log_path.read_bytes())}
        assert sha(args.ipa.read_bytes()) == original_sha, 'Input IPA changed'
        args.output.parent.mkdir(parents=True, exist_ok=True)
        with args.output.open('xb') as destination, generated.open('rb') as source:
            shutil.copyfileobj(source, destination)
        assert sha(args.output.read_bytes()) == report['output_sha256']
        (work / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
        args.output.with_suffix('.injection.json').write_text(json.dumps(report, indent=2) + '\n')
    print(log_path.read_text())
    print('Verified IPA:', args.output)
    print('Verification report:', work / 'report.json')


if __name__ == '__main__':
    main()
