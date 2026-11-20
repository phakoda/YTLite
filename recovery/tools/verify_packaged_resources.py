#!/usr/bin/env python3
"""Compare deployed resources with all package variants; optionally restore assets."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

from evidence_image import REPO


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def plist(path):
    return json.loads(subprocess.check_output(
        ['plutil', '-convert', 'json', '-o', '-', str(path)], text=True))


def asset_names(path):
    rows = json.loads(subprocess.check_output(['assetutil', '--info', str(path)], text=True))
    return sorted({row['Name'] for row in rows if row.get('Name')
                   and not row['Name'].startswith('ZZZZPackedAsset-')})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--restore-assets', action='store_true')
    args = parser.parse_args()
    packaged = REPO / 'recovery/resources/arm/YTLite.bundle'
    deployed = REPO / 'layout/Library/Application Support/YTLite.bundle'
    work = REPO / '.recovery-work/resource-audit'
    work.mkdir(parents=True, exist_ok=True)
    assets = packaged / 'Assets.car'
    variants = {}
    for variant in ('arm', 'arm64', 'arm64e'):
        root = REPO / 'recovery/resources' / variant / 'YTLite.bundle'
        variants[variant] = {str(p.relative_to(root)): digest(p)
                             for p in sorted(root.rglob('*')) if p.is_file()}
        assert variants[variant] == variants['arm'], 'Package resource variants differ'
    if args.restore_assets and digest(assets) != digest(deployed / 'Assets.car'):
        backup = work / ('Assets-before-' + digest(deployed / 'Assets.car') + '.car')
        if not backup.exists():
            shutil.copyfile(deployed / 'Assets.car', backup)
        shutil.copyfile(assets, deployed / 'Assets.car')
    assert digest(assets) == digest(deployed / 'Assets.car'), 'Run with --restore-assets to restore the packaged catalog'
    assert digest(packaged / 'SponsorAudio.m4a') == digest(deployed / 'SponsorAudio.m4a')
    assert plist(packaged / 'Info.plist') == plist(deployed / 'Info.plist')
    locale_differences = {}
    for path in sorted(packaged.rglob('*.strings')):
        relative = path.relative_to(packaged)
        original, current = plist(path), plist(deployed / relative)
        locale_differences[str(relative)] = {
            key: {'package': original.get(key), 'working_copy': current.get(key)}
            for key in sorted(original.keys() | current.keys())
            if original.get(key) != current.get(key)
        }
    report = {
        'package_resource_variants': variants,
        'deployed_assets_sha256': digest(deployed / 'Assets.car'),
        'asset_names': asset_names(assets),
        'audio': 'exact packaged bytes',
        'bundle_metadata': 'equal property list values',
        'locale_policy': 'Preserve existing working-copy locale edits; record differences without overwriting.',
        'locale_differences': locale_differences,
        'deployed_files': {str(p.relative_to(deployed)): digest(p)
                           for p in sorted(deployed.rglob('*')) if p.is_file()},
        'original_binary_executed': False,
    }
    (REPO / 'recovery/evidence/deployed-resources.json').write_text(
        json.dumps(report, indent=2, ensure_ascii=False) + '\n')
    print(f"Resources: all three packages agree; {len(report['asset_names'])} packaged asset names deployed; existing locales preserved.")


if __name__ == '__main__':
    main()
