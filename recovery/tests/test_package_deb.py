#!/usr/bin/env python3
"""Exercise the real package writer with permissions reported by ExFAT."""
import io
import os
from pathlib import Path
import stat
import subprocess
import sys
import tarfile
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]


def members(package, name):
    data = subprocess.check_output(['ar', '-p', str(package), name])
    with tarfile.open(fileobj=io.BytesIO(data)) as archive:
        return {entry.name.removeprefix('./'): (entry.mode,
                archive.extractfile(entry).read() if entry.isfile() else None)
                for entry in archive}


class PackageTests(unittest.TestCase):
    def test_writer_failure_keeps_existing_package(self):
        with tempfile.TemporaryDirectory(prefix='ytlite-package-test-', dir='/tmp') as directory:
            root = Path(directory)
            stage = root / 'stage'
            (stage / 'DEBIAN').mkdir(parents=True)
            (stage / 'DEBIAN/control').write_text('Package: invalid\n')
            output = root / 'package.deb'
            output.write_bytes(b'previous package')
            result = subprocess.run([sys.executable, str(ROOT / 'tools/package_deb.py'),
                '-b', str(stage), str(output)], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('missing a Version field', result.stderr)
            self.assertEqual(output.read_bytes(), b'previous package')

    def test_restrictive_stage_is_packaged_without_changing_source(self):
        with tempfile.TemporaryDirectory(prefix='ytlite-package-test-', dir='/tmp') as directory:
            root = Path(directory)
            stage = root / 'stage'
            control = stage / 'DEBIAN/control'
            control.parent.mkdir(parents=True, mode=0o700)
            control.write_text('Package: test.ytlite\nVersion: 1.0\nArchitecture: iphoneos-arm64e\n')
            library = stage / 'Library/MobileSubstrate/DynamicLibraries'
            library.mkdir(parents=True)
            (library / 'YTLite.dylib').write_bytes(b'fixture data, never loaded')
            (library / 'YTLite.plist').write_bytes(b'fixture filter')
            for path in stage.rglob('*'):
                path.chmod(0o700 if path.is_dir() else 0o755)
            before = {str(p.relative_to(stage)): (stat.S_IMODE(p.stat().st_mode),
                      p.read_bytes() if p.is_file() else None) for p in stage.rglob('*')}
            output = root / 'package.deb'
            original = subprocess.run(['perl', str(ROOT / 'vendor/theos/bin/dm.pl'),
                '-Zgzip', '-z1', '-b', str(stage), str(output)], capture_output=True, text=True)
            self.assertNotEqual(original.returncode, 0)
            self.assertIn('control directory has bad permissions 700', original.stderr)
            env = os.environ.copy()
            # The build wrapper sets TMPDIR inside the checkout. The package
            # copy must instead use the native temporary filesystem.
            env['TMPDIR'] = str(ROOT / '.recovery-work')
            result = subprocess.run([sys.executable, str(ROOT / 'tools/package_deb.py'),
                '-Zgzip', '-z1', '-b', str(stage), str(output)], env=env,
                capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertEqual(members(output, 'control.tar.gz')['control'], (0o644, control.read_bytes()))
            data = members(output, 'data.tar.gz')
            self.assertEqual(data['Library/MobileSubstrate/DynamicLibraries/YTLite.dylib'],
                             (0o755, b'fixture data, never loaded'))
            self.assertEqual(data['Library/MobileSubstrate/DynamicLibraries/YTLite.plist'],
                             (0o644, b'fixture filter'))
            self.assertTrue(all(mode == 0o755 for mode, content in data.values() if content is None))
            after = {str(p.relative_to(stage)): (stat.S_IMODE(p.stat().st_mode),
                     p.read_bytes() if p.is_file() else None) for p in stage.rglob('*')}
            self.assertEqual(before, after)


if __name__ == '__main__':
    unittest.main()
