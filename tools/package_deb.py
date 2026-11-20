#!/usr/bin/env python3
"""Package YTLite on a native temporary filesystem, including ExFAT checkouts."""
import argparse
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('-Z', default='gzip', dest='compression')
    parser.add_argument('-z', default='9', dest='level')
    parser.add_argument('-b', required=True, action='store_true')
    parser.add_argument('stage', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    # build_local.py keeps compiler TMPDIR in the checkout. ExFAT cannot store
    # the Unix modes required by Debian, so do not inherit that directory here.
    with tempfile.TemporaryDirectory(prefix='ytlite-package-', dir='/tmp') as directory:
        work = Path(directory)
        stage = work / 'stage'
        shutil.copytree(args.stage, stage, symlinks=True, copy_function=shutil.copyfile)
        scripts = {'preinst', 'postinst', 'prerm', 'postrm', 'extrainst_'}
        for path in [stage, *stage.rglob('*')]:
            if path.is_symlink():
                continue
            executable = path.suffix == '.dylib' or (path.parent.name == 'DEBIAN' and path.name in scripts)
            path.chmod(0o755 if path.is_dir() or executable else 0o644)
        package = work / 'package.deb'
        result = subprocess.run(['perl', str(ROOT / 'vendor/theos/bin/dm.pl'),
            '-Z' + args.compression, '-z' + args.level, '-b', str(stage), str(package)])
        if result.returncode:
            return result.returncode
        shutil.copyfile(package, args.output)
    return 0


if __name__ == '__main__':
    sys.exit(main())
