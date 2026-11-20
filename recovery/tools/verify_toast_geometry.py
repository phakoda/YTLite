#!/usr/bin/env python3
"""Verify original toast geometry bytes and whole-source arithmetic/getter order."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
from evidence_image import EvidenceImage, REPO


def main():
    im = EvidenceImage()
    path = REPO / 'recovery/evidence/toast-geometry-fidelity.json'
    evidence = json.loads(path.read_text())
    assert evidence['binary_sha256'] == im.sha256
    ranges = []
    for f in evidence['functions']:
        start, end = int(f['start'], 16), int(f['end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == f['sha256']
        ranges.append((start, end))
    words, indirect = 0, set()
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s+(.*)', line)
        if m and any(a <= int(m[1], 16) < b for a, b in ranges):
            address = int(m[1], 16)
            assert im.image.u32(im.image.off(address)) == int(m[2], 16)
            words += 1
            if m[3].startswith('br\t'):
                indirect.add(address)
    assert words == sum((b-a)//4 for a, b in ranges)
    original = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for b in evidence['branches']:
        assert b == original[b['address']]
    assert indirect == {int(b['address'], 16) for b in evidence['branches']}
    for item in evidence['critical_instructions'] + evidence['omitted_supervisor_calls']:
        assert im.image.u32(im.image.off(int(item['address'], 16))) == int(item['word'], 16)
    for item in evidence['numeric_constants']:
        off = im.image.off(int(item['address'], 16))
        assert im.image.data[off:off+8].hex() == item['raw']
    work = REPO / '.recovery-work/toast-geometry'
    (work / 'tmp').mkdir(parents=True, exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    commands = []
    env = dict(os.environ, TMPDIR=str(work / 'tmp'))

    def run(args, red=False):
        p = subprocess.run(list(map(str, args)), cwd=REPO, env=env, capture_output=True, text=True, timeout=120)
        commands.append(dict(command=list(map(str, args)), returncode=p.returncode, output=p.stdout+p.stderr))
        (work / 'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if red:
            assert p.returncode == 1 and 'FAIL ' in p.stderr, p.stdout+p.stderr
        else:
            print(p.stdout+p.stderr, end='')
            p.check_returncode()
        return p.stdout+p.stderr

    source = REPO / 'recovery/source/Presentation/ToastView.m'
    header = source.with_name('PresentationGeometry.h')
    fixture = REPO / 'recovery/tests/toast_geometry_fixture.m'
    doubles = REPO / 'recovery/tests/toast_geometry_doubles.m'
    shims = REPO / 'recovery/tests/toast_geometry_shims'
    redirects = REPO / 'recovery/tests/toast_geometry_redirects.h'
    run([sys.executable, REPO / 'recovery/tools/verify_ios_sources.py', '--label', 'toast-geometry', '--source', source, '--classes', 'ToastView'])

    flags = ['xcrun', '--sdk', 'macosx', 'clang', '-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror',
             '-Wno-incomplete-implementation', '-Wno-unused-parameter', '-fsanitize=undefined', '-fno-sanitize-recover=all',
             '-I', shims, '-I', source.parent, '-include', redirects]
    objects = []
    for unit in (doubles, fixture):
        obj = work / (unit.stem+'.o')
        run(flags + ['-c', unit, '-o', obj])
        objects.append(obj)

    def compile(input_source, output):
        run(flags + [input_source, *objects, '-framework', 'Foundation', '-framework', 'CoreGraphics', '-o', output])

    executable = work / 'fixture'
    compile(source, executable)
    output = run([executable])
    assertions = int(re.search(r'(\d+) checks passed', output)[1])
    text = source.read_text()
    mutations = {
        'cached_bottom_getter': ('double secondBottom = self.bottomOffset;', 'double secondBottom = firstBottom;'),
        'empty_list_skips_scale': ('if (count == 1) return;', 'if (count <= 1) return;'),
        'nan_good_height_pseudocode': ('if (!(goodHeight > 0)) adjustment = 0;', 'if (goodHeight <= 0) adjustment = 0;'),
        'reassociated_sum': ('(gap + (secondBottom + adjustment)) + 15', '((gap + secondBottom) + adjustment) + 15'),
        'added_collection_lock': ('NSUInteger index = [toasts indexOfObject:self];', 'NSUInteger index; @synchronized (toasts) { index = [toasts indexOfObject:self]; }'),
        'adjustment_after_second_getter': ('double secondBottom = self.bottomOffset;', 'double secondBottom = self.bottomOffset; adjustment = _goodHeight > 0 ? _goodHeight - 30 : 0;'),
        'scale_unwritten_at_second_getter': ('*scale = 1;\n    *top = safeTop + 15;', '*scale = -999;\n    *top = safeTop + 15;'),
        'layout_width_read_after_calculation': ('width:width animationDuration:0.5', 'width:((void)width, _sourceView.frame.size.width * YTLToastWidthFraction(_isiPad, self.isLandscape)) animationDuration:0.5'),
    }
    red_results = []
    for name, (old, new) in mutations.items():
        assert old in text
        mutant = work / (name+'.m')
        mutant.write_text(text.replace(old, new, 1))
        binary = work / name
        compile(mutant, binary)
        red_results.append(dict(name=name, output=run([binary], red=True).strip()))
    files = [source, source.with_suffix('.h'), header, source.with_name('ToastView.geometry.provenance.md'), fixture,
             doubles, doubles.with_suffix('.h'), redirects, path, Path(__file__).resolve()] + list(shims.rglob('*.h'))
    result = dict(binary_sha256=im.sha256, original_words=words, original_functions=len(ranges), indirect_branches=len(indirect),
                  runtime_assertions=assertions, regression_mutations_rejected=red_results,
                  oracle='Newly compiled native ARM64 FCMP/CSET GT, FCSEL GT, and separate FADD operations; raw original words pinned independently.',
                  limits=evidence['limits'], inputs={str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files})
    report.write_text(json.dumps(result, indent=2)+'\n')
    print(f'Original {words} words and {len(indirect)} indirect branches; {len(red_results)} regression mutations rejected.')


if __name__ == '__main__':
    main()
