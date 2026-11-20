#!/usr/bin/env python3
"""Audit a Ghidra image against original ARM64 code and recorded patches."""
import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
from evidence_image import EvidenceImage, REPO


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--patches', type=Path, default=REPO / '.recovery-work/analysis-v4/evidence/branches.json')
    parser.add_argument('--project', type=Path, default=REPO / '.recovery-work/analysis-v2/ghidra')
    args = parser.parse_args()
    image = EvidenceImage()
    work = REPO / '.recovery-work/analysis-image-audit'; work.mkdir(parents=True, exist_ok=True)
    for path in (args.patches.resolve(), args.project.resolve()): path.relative_to(REPO)
    overrides = {}
    for entry in json.loads(args.patches.read_text()):
        base = int(entry['address'], 16)
        for index, word in enumerate(entry['replacement']): overrides[base + index * 4] = word
    for entry in json.loads((REPO / 'recovery/evidence/initializers.json').read_text()):
        overrides[int(entry['address'], 16)] = entry['replacement']
    sections = []
    for name in ('__text', '__stubs'):
        address, size, offset = image.image.sections[name]
        sections.append({'name': name, 'address': hex(address), 'size': size, 'file_offset': offset})
    manifest = {'binary': str(image.binary_path), 'sha256': image.sha256, 'sections': sections,
                'overrides': [{'address': hex(address), 'word': word} for address, word in sorted(overrides.items())]}
    path = work / 'manifest.json'; path.write_text(json.dumps(manifest, indent=2) + '\n')
    report_path = work / 'analysis-image-audit.json'
    if report_path.exists(): report_path.unlink()
    env = os.environ.copy()
    for variable, name in (('HOME', 'home'), ('TMPDIR', 'tmp'), ('XDG_CONFIG_HOME', 'config'), ('XDG_CACHE_HOME', 'cache')):
        directory = work / name; directory.mkdir(exist_ok=True); env[variable] = str(directory)
    env['JAVA_TOOL_OPTIONS'] = env.get('JAVA_TOOL_OPTIONS', '') + ' -Duser.home=' + env['HOME'] + ' -Djava.io.tmpdir=' + env['TMPDIR']
    launcher = shutil.which('ghidraRun')
    if not launcher: raise RuntimeError('Ghidra not found')
    headless = Path(launcher).resolve().parents[1] / 'libexec/support/analyzeHeadless'
    command = list(map(str, [headless, args.project, 'YTLite', '-process', 'YTLite.dylib', '-noanalysis',
        '-readOnly', '-scriptPath', REPO / 'recovery/tools', '-log', work / 'ghidra.log', '-scriptlog', work / 'script.log',
        '-postScript', 'AuditAnalysisImage.java', path]))
    with (work / 'output.log').open('w') as stream:
        result = subprocess.run(command, cwd=REPO, env=env, stdout=stream, stderr=subprocess.STDOUT)
    result.check_returncode()
    log = (work / 'output.log').read_text(errors='replace')
    if 'REPORT SCRIPT ERROR' in log or 'Error running script:' in log or 'ERROR REPORT' in log:
        raise RuntimeError('Ghidra audit script failed; inspect output.log')
    if not report_path.exists(): raise RuntimeError('Audit script produced no report; inspect output.log')
    report = json.loads(report_path.read_text()); print(json.dumps(report, indent=2))
    if report['bytes_differing']: raise RuntimeError('Analysis image does not match; exports are untrusted until repaired')


if __name__ == '__main__': main()
