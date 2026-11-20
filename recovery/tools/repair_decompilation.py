#!/usr/bin/env python3
"""Repair analysis-only function/island ownership and export separate pseudocode."""
from bisect import bisect_right
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
from inventory import MachO

REPO = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--label', default='analysis-v3')
    parser.add_argument('--branch-evidence', type=Path)
    parser.add_argument('--project-root', type=Path, help='Use an isolated copy of an existing analysis project')
    parser.add_argument('--range', dest='address_range', nargs=2, type=lambda text: int(text, 16))
    args = parser.parse_args()
    if not args.label.replace('-', '').replace('_', '').isalnum():
        parser.error('Invalid output label')
    project_root = args.project_root.resolve() if args.project_root else REPO / '.recovery-work/analysis-v2'
    project_root.relative_to(REPO)
    output = REPO / '.recovery-work' / args.label
    output.mkdir(parents=True, exist_ok=True)
    evidence = output / 'evidence'
    evidence.mkdir(exist_ok=True)
    for name in ('arm-classes.json', 'hooks.json'):
        shutil.copyfile(REPO / 'recovery/evidence' / name, evidence / name)
    binary = REPO / '.recovery-work/arm/YTLite.dylib'
    data = binary.read_bytes()
    expected = next(item['binary_sha256'] for item in json.loads((REPO / 'recovery/evidence/packages.json').read_text())
                    if item['package'].endswith('iphoneos-arm.deb'))
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError('Input binary hash changed')
    image = MachO(data)
    starts = sorted(image.function_starts)
    functions = {start: {'start': hex(start), 'end': hex(starts[index + 1]), 'islands': []}
                 for index, start in enumerate(starts[:-1]) if 0x8000 <= start < 0x280000}
    islands = []
    branch_evidence = args.branch_evidence.resolve() if args.branch_evidence else project_root / 'evidence'
    branch_evidence.relative_to(REPO)
    patches = json.loads((branch_evidence / 'branches.json').read_text())
    for patch in patches:
        if 'island' not in patch:
            continue
        address = int(patch['address'], 16)
        owner = starts[bisect_right(starts, address) - 1]
        island = {'start': patch['island'], 'bytes': len(patch['island_words']) * 4, 'original_branch': patch['address']}
        if owner not in functions:
            raise ValueError('Synthetic branch island belongs outside the first-party analysis range')
        functions[owner]['islands'].append(island)
        islands.append((int(island['start'], 16), int(island['start'], 16) + island['bytes']))
    islands.sort()
    if any(previous[1] > current[0] for previous, current in zip(islands, islands[1:])):
        raise ValueError('Synthetic branch island ranges overlap')
    (output / 'function-layout.json').write_text(json.dumps({'binary_sha256': expected, 'functions': list(functions.values())}, indent=2) + '\n')
    launcher = shutil.which('ghidraRun')
    if not launcher:
        raise RuntimeError('Ghidra is not installed')
    headless = Path(launcher).resolve().parents[1] / 'libexec/support/analyzeHeadless'
    env = os.environ.copy()
    for variable, name in (('HOME', 'home'), ('TMPDIR', 'tmp'), ('XDG_CONFIG_HOME', 'config'), ('XDG_CACHE_HOME', 'cache')):
        path = output / name; path.mkdir(exist_ok=True); env[variable] = str(path)
    env['JAVA_TOOL_OPTIONS'] = env.get('JAVA_TOOL_OPTIONS', '') + ' -Duser.home=' + env['HOME'] + ' -Djava.io.tmpdir=' + env['TMPDIR']
    commands = []
    base = [headless, project_root / 'ghidra', 'YTLite', '-process', 'YTLite.dylib', '-noanalysis',
            '-scriptPath', REPO / 'recovery/tools', '-max-cpu', '2', '-log', output / 'ghidra.log', '-scriptlog', output / 'scripts.log']
    steps = []
    if args.branch_evidence:
        for name in ('arm-classes.json', 'hooks.json', 'initializers.json', 'decoded-bytes.tsv', 'decoded-strings.json'):
            source = REPO / 'recovery/evidence' / name
            destination = branch_evidence / name
            if source != destination: shutil.copyfile(source, destination)
        steps.append(('Improve.java', [branch_evidence], 'improve.log'))
    steps.append(('FixAnalysisBodies.java', [output], 'repair.log'))
    export_args = [output / 'decompiled'] + ([hex(value) for value in args.address_range] if args.address_range else [])
    steps.append(('Recover.java', export_args, 'export.log'))
    for script, script_args, log_name in steps:
        command = list(map(str, [*base, '-postScript', script, *script_args]))
        print('Analysis-only step:', script, flush=True)
        with (output / log_name).open('w') as log:
            result = subprocess.run(command, cwd=REPO, env=env, stdout=log, stderr=subprocess.STDOUT)
        commands.append({'command': command, 'exit_code': result.returncode, 'log': log_name})
        (output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        result.check_returncode()
        text = (output / log_name).read_text(errors='replace')
        if 'REPORT SCRIPT ERROR' in text or 'Error running script:' in text:
            raise RuntimeError('Ghidra script failed; read ' + str(output / log_name))
        print('\n'.join(text.splitlines()[-10:]), flush=True)
    if hashlib.sha256(binary.read_bytes()).hexdigest() != expected:
        raise ValueError('Original binary unexpectedly changed')
    print('Repaired pseudocode exports:', output / 'decompiled')


if __name__ == '__main__':
    main()
