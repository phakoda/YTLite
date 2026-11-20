#!/usr/bin/env python3
"""Re-export pseudocode with the additional branch evidence, inside /YTLite.

No package is executed, no original recovery evidence is overwritten, and a
separate Ghidra project, JVM home, caches, logs, and scratch stay in the repo.
New exports are still pseudocode, not a claim of behavioral correctness.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

REPO = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ghidra', type=Path, help='Installed Ghidra libexec directory; read-only tool dependency.')
    parser.add_argument('--export-only', action='store_true')
    args = parser.parse_args()
    root = REPO / '.recovery-work/analysis-v2'
    root.mkdir(parents=True, exist_ok=True)
    evidence = root / 'evidence'
    evidence.mkdir(exist_ok=True)
    binary = REPO / '.recovery-work/arm/YTLite.dylib'
    manifest = next(entry for entry in json.loads((REPO / 'recovery/evidence/packages.json').read_text())
                    if entry['package'].endswith('iphoneos-arm.deb'))
    if hashlib.sha256(binary.read_bytes()).hexdigest() != manifest['binary_sha256']:
        raise RuntimeError('Binary hash differs from the original supplied package.')
    if not (evidence / 'branches.json').is_file():
        raise RuntimeError('Run control_flow.py first; combined branch evidence is missing.')
    # Preserve the combined branch file and the original durable evidence.
    for name in ('arm-classes.json', 'hooks.json', 'initializers.json', 'decoded-bytes.tsv', 'decoded-strings.json'):
        shutil.copyfile(REPO / 'recovery/evidence' / name, evidence / name)
    env = os.environ.copy()
    for variable, relative in (('HOME', 'jvm-home'), ('TMPDIR', 'tmp'),
                               ('XDG_CONFIG_HOME', 'config'), ('XDG_CACHE_HOME', 'cache')):
        target = root / relative
        target.mkdir(exist_ok=True)
        env[variable] = str(target)
    # Appending these options last also overrides machine-wide JVM preferences.
    env['JAVA_TOOL_OPTIONS'] = (env.get('JAVA_TOOL_OPTIONS', '') +
                               ' -Duser.home=' + env['HOME'] + ' -Djava.io.tmpdir=' + env['TMPDIR'])
    ghidra = args.ghidra
    if ghidra is None:
        executable = shutil.which('ghidraRun')
        if executable is None:
            raise RuntimeError('Installed Ghidra was not found; supply --ghidra.')
        ghidra = Path(executable).resolve().parents[1] / 'libexec'
    headless = ghidra / 'support/analyzeHeadless'
    if not headless.is_file():
        raise RuntimeError(f'Installed headless launcher not found: {headless}')
    project = root / 'ghidra'
    project.mkdir(exist_ok=True)
    tools = REPO / 'recovery/tools'
    base = [headless, project, 'YTLite', '-scriptPath', tools, '-max-cpu', '2',
            '-log', root / 'ghidra.log', '-scriptlog', root / 'ghidra-scripts.log']
    commands = []

    def run(command, filename):
        command = [str(value) for value in command]
        print('Running ' + filename + ' (analysis only; original binary is not executed).', flush=True)
        with (root / filename).open('w') as stream:
            result = subprocess.run(command, env=env, cwd=root, stdout=stream, stderr=subprocess.STDOUT)
        commands.append({'command': command, 'exit_code': result.returncode, 'log': filename})
        (root / 'redecompile-commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        result.check_returncode()
        log = (root / filename).read_text(errors='replace')
        if 'REPORT SCRIPT ERROR' in log or 'Error running script:' in log:
            raise RuntimeError('Ghidra script failed; inspect ' + str(root / filename))
        print('\n'.join(log.splitlines()[-12:]), flush=True)

    if not args.export_only:
        if (project / 'YTLite.gpr').exists():
            run([*base, '-process', 'YTLite.dylib', '-noanalysis', '-postScript', 'Improve.java', evidence], 'improve.log')
        else:
            run([*base, '-import', binary, '-analysisTimeoutPerFile', '900', '-postScript', 'Improve.java', evidence], 'import.log')
    run([*base, '-process', 'YTLite.dylib', '-noanalysis', '-postScript', 'Recover.java', root / 'decompiled'], 'export.log')
    if hashlib.sha256(binary.read_bytes()).hexdigest() != manifest['binary_sha256']:
        raise RuntimeError('Original analysis input unexpectedly changed.')
    print('New pseudocode exports:', root / 'decompiled', flush=True)


if __name__ == '__main__':
    main()
