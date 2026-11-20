#!/usr/bin/env python3
"""Fetch release evidence only when it matches the recorded supplied-package hashes.

All downloads and extraction output stay inside this repository. Nothing downloaded
by this script is executed or installed. Existing files are checked, never replaced.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]
RELEASE_API = 'https://api.github.com/repos/dayanch96/YTLite/releases/tags/v5.2.2'


def fetch(url, destination=None):
    # System curl uses the platform's trusted certificate store. In particular,
    # do not disable TLS verification to work around a Python CA installation.
    command = ['curl', '--fail', '--location', '--silent', '--show-error',
               '--proto', '=https', '--proto-redir', '=https', '--max-time', '180',
               '--user-agent', 'OpenAI File Downloader, XaiImageApiFetch/1.0', url]
    if destination is not None:
        subprocess.run(command + ['--output', str(destination)], check=True)
        return None
    return subprocess.check_output(command)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--destination', type=Path, default=REPO / '.recovery-work' / 'inputs')
    args = parser.parse_args()
    destination = args.destination.resolve()
    if not destination.is_relative_to(REPO):
        parser.error('The destination must be inside /YTLite.')
    expected = json.loads((REPO / 'recovery/evidence/packages.json').read_text())
    destination.mkdir(parents=True, exist_ok=True)
    release = json.loads(fetch(RELEASE_API))
    assets = {asset['name']: asset['browser_download_url'] for asset in release['assets']}
    for package in expected:
        name, digest = package['package'], package['sha256']
        target = destination / name
        if target.exists():
            actual = hashlib.sha256(target.read_bytes()).hexdigest()
            if actual != digest:
                raise RuntimeError(f'Existing input has an unexpected hash: {target}')
        else:
            url = assets[name]
            temporary = target.with_suffix(target.suffix + '.partial')
            if temporary.exists():
                raise RuntimeError(f'Review the previous incomplete download first: {temporary}')
            try:
                fetch(url, temporary)
                if hashlib.sha256(temporary.read_bytes()).hexdigest() != digest:
                    raise RuntimeError(f'Release asset does not match supplied evidence: {name}')
                temporary.rename(target)
            except Exception:
                temporary.unlink(missing_ok=True)
                raise
        print(f'{name}: verified {digest}', flush=True)
    (destination / 'release.json').write_text(json.dumps(release, indent=2) + '\n')


if __name__ == '__main__':
    main()
