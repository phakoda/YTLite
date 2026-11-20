#!/usr/bin/env python3
"""Audit the selected tweak sources and their local include dependencies."""
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def build_inputs():
    selected = set()
    environment = dict(os.environ, THEOS=str(ROOT/'vendor/theos'), COLOR='0')
    for scheme in ([], ['ROOTHIDE=1']):
        output = subprocess.check_output(['make', '-s', '--no-print-directory',
            'print-ytlite-sources', '--eval=print-ytlite-sources:;@printf "%s\\n" $(YTLite_FILES)',
            *scheme], cwd=ROOT, env=environment, text=True)
        for line in output.splitlines():
            path = ROOT/line
            if path.is_file() and path.suffix in ('.x', '.m', '.c'):
                selected.add(path.resolve())
    assert selected, 'Make returned no source files'
    keep = set(selected)
    pending = list(selected)
    while pending:
        source = pending.pop()
        for include in re.findall(r'^\s*#\s*(?:import|include)\s*"([^"\n]+)"', source.read_text(), re.M):
            candidates = [source.parent/include, ROOT/include, ROOT/'vendor/YouTubeHeader'/include]
            target = next((p.resolve() for p in candidates if p.is_file()), None)
            if target is None:
                raise ValueError(f'Missing quoted include {include!r} in {source.relative_to(ROOT)}')
            if target.is_relative_to(ROOT) and target not in keep:
                keep.add(target)
                if target.suffix in ('.h', '.inc', '.m', '.c', '.x'):
                    pending.append(target)
    keep.add((ROOT/'recovery/source/recovered.mk').resolve())
    if (ROOT/'.git').exists():
        tracked = subprocess.check_output(['git', 'ls-files', '-z', 'recovery/source'], cwd=ROOT).split(b'\0')
    else:
        tracked = [os.fsencode(p.relative_to(ROOT)) for p in (ROOT/'recovery/source').rglob('*') if p.is_file()]
    unused = [os.fsdecode(p) for p in tracked if p and (ROOT/os.fsdecode(p)).exists() and (ROOT/os.fsdecode(p)).resolve() not in keep]
    return {'sources': sorted(str(p.relative_to(ROOT)) for p in selected),
            'inputs': sorted(str(p.relative_to(ROOT)) for p in keep), 'unused_source_files': unused}


if __name__ == '__main__':
    report = build_inputs()
    destination = ROOT/'.recovery-work/build-inputs.json'
    destination.parent.mkdir(exist_ok=True)
    destination.write_text(json.dumps(report, indent=2)+'\n')
    print(f"{len(report['sources'])} sources, {len(report['inputs'])} local inputs, {len(report['unused_source_files'])} unused source-tree files")
    print(destination)
