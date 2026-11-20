#!/usr/bin/env python3
"""Compare original ToastView bytes, emitted iOS ABI, and actual-source lifecycle execution."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

from evidence_image import EvidenceImage, REPO


def evidence():
    im = EvidenceImage()
    manifest = json.loads((REPO / 'recovery/evidence/toast-lifecycle-fidelity.json').read_text())
    assert manifest['binary_sha256'] == im.sha256
    original = next(c for c in json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text()) if c['name'] == 'ToastView')
    for key in ('methods', 'properties'):
        assert manifest[key] == original[key]
    ranges = []
    for f in manifest['functions'] + manifest['capture_helpers']:
        start, end = int(f['start'], 16), int(f['end'], 16)
        assert end == min(a for a in im.image.function_starts if a > start)
        assert hashlib.sha256(im.image.data[im.image.off(start):im.image.off(end)]).hexdigest() == f['sha256']
        ranges.append((start, end))
    words, indirect = 0, set()
    for line in (REPO / '.recovery-work/arm/application.asm').read_text().splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f]{8})\s+(.*)', line)
        if not m or not any(a <= int(m[1], 16) < b for a, b in ranges):
            continue
        address = int(m[1], 16)
        assert im.image.u32(im.image.off(address)) == int(m[2], 16)
        words += 1
        if m[3].startswith('br\t'):
            indirect.add(address)
    assert words == sum((b-a)//4 for a, b in ranges)
    original_branches = {b['address']: b for b in json.loads((REPO / 'recovery/evidence/branches.json').read_text())}
    for b in manifest['branches']:
        assert original_branches[b['address']] == b
    for t in manifest['manual_tables']:
        delta = -(im.image.u32(im.image.off(int(t['offset'], 16))) ^ int(t['xor'], 16))
        delta = (delta + (1 << 31)) % (1 << 32) - (1 << 31)
        assert [hex(im.image.ptr(int(t['table'], 16)+i*8)+delta) for i in range(2)] == t['targets_false_true']
    assert indirect == {int(b['address'], 16) for b in manifest['branches'] + manifest['manual_tables']}
    for t in manifest['wrappers']:
        assert im.terminal(int(t['address'], 16)) == t['terminal']
    for t in manifest['numeric_constants']:
        offset = im.image.off(int(t['address'], 16))
        assert im.image.data[offset:offset+8].hex() == t['raw']
    for t in manifest['critical_instructions'] + manifest['omitted_supervisor_calls']:
        assert im.image.u32(im.image.off(int(t['address'], 16))) == int(t['word'], 16)
    for t in manifest['global_blocks']:
        assert hex(im.image.ptr(int(t['address'], 16)+16)) == t['invoke']
    for t in manifest['capture_descriptors']:
        a = int(t['address'], 16)
        assert im.image.ptr(a+8) == t['size']
        assert hex(im.image.ptr(a+16)) == t['copy']
        assert hex(im.image.ptr(a+24)) == t['dispose']
    # All six copy helpers load the strong receiver at block +0x20 and retain it.
    for load in (0x150f0, 0xbf130, 0xbf474, 0xc0fb8, 0x1c15f8, 0x1c1f78):
        assert im.image.u32(im.image.off(load)) == 0xf9401020
        word = im.image.u32(im.image.off(load+4))
        assert word & 0xfc000000 == 0x94000000
        delta = word & 0x3ffffff
        if delta & (1 << 25):
            delta -= 1 << 26
        assert im.terminal(load+4+delta*4) == '_objc_retain'
    return dict(binary_sha256=im.sha256, original_words=words, lifecycle_functions=len(manifest['functions']),
                additional_capture_helpers=len(manifest['capture_helpers']), indirect_branches=len(indirect),
                capture_descriptors=len(manifest['capture_descriptors']), limits=manifest['limits'])


def main():
    result = evidence()
    work = REPO / '.recovery-work/toast-lifecycle'
    work.mkdir(parents=True, exist_ok=True)
    (work / 'tmp').mkdir(exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    env = dict(os.environ, TMPDIR=str(work / 'tmp'))
    commands = []

    def run(args, expected_success=True):
        args = list(map(str, args))
        p = subprocess.run(args, cwd=REPO, env=env, capture_output=True, text=True, timeout=120)
        commands.append(dict(command=args, returncode=p.returncode, output=p.stdout+p.stderr))
        (work / 'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if expected_success:
            print(p.stdout+p.stderr, end='')
            p.check_returncode()
        else:
            assert p.returncode == 1 and 'FAIL ' in p.stderr, (args, p.returncode, p.stdout, p.stderr)
        return p.stdout+p.stderr

    source = REPO / 'recovery/source/Presentation/ToastView.m'
    test = REPO / 'recovery/tests/toast_lifecycle_fixture.m'
    doubles = REPO / 'recovery/tests/toast_lifecycle_doubles.m'
    shim = REPO / 'recovery/tests/toast_lifecycle_shims'
    redirects = REPO / 'recovery/tests/toast_lifecycle_redirects.h'
    run([sys.executable, REPO / 'recovery/tools/verify_ios_sources.py', '--label', 'toast-lifecycle', '--source', source, '--classes', 'ToastView'])

    def compile_source(input_source, output):
        run(['xcrun', '--sdk', 'macosx', 'clang', '-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror',
             '-Wno-incomplete-implementation', '-Wno-unused-parameter', '-fsanitize=undefined', '-fno-sanitize-recover=all',
             '-I', shim, '-I', source.parent, '-include', redirects, input_source, doubles, test,
             '-framework', 'Foundation', '-framework', 'CoreGraphics', '-o', output])

    executable = work / 'fixture'
    compile_source(source, executable)
    output = run([executable])
    result['runtime_assertions'] = int(re.search(r'(\d+) checks passed', output)[1])
    text = source.read_text()
    mutations = {
        'delay_wrong_method': ('[self hideAnimatedWithCompletion:nil];', '[self hideWithCompletion:nil];'),
        'weak_command_capture': ('[self enqueueCommand:^{\n        ToastView *toast = self;', '__weak ToastView *weakSelf = self;\n    [self enqueueCommand:^{\n        ToastView *toast = weakSelf;'),
        'timer_nan_ordered_only': ('if (!(remaining <= 0))', 'if (remaining > 0)'),
        'timer_stored_in_ivar': ('[NSRunLoop.mainRunLoop addTimer:timer', '_progressTimer = timer;\n    [NSRunLoop.mainRunLoop addTimer:timer'),
        'immediate_resets_state': ('- (void)hideImmediately {', '- (void)hideImmediately {\n    _isAnimating = NO; self.alpha = 0;'),
        'completion_cleared_by_nil': ('if (completion) toast.completion = completion;', 'toast.completion = completion;'),
        'cancel_caches_getter': ('if (self.completion) self.completion();', 'dispatch_block_t completion = self.completion; if (completion) completion();'),
        'dealloc_invalidates_timer': ('- (void)dealloc {', '- (void)dealloc {\n    [_progressTimer invalidate];'),
        'width_read_before_calculation': (
            'double bottom, top, scale;\n            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];\n            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale\n                width:toast->_widthConstraint.constant',
            'double bottom, top, scale;\n            double priorWidth = toast->_widthConstraint.constant;\n            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];\n            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale\n                width:priorWidth'),
    }
    reds = []
    for name, (old, new) in mutations.items():
        assert old in text
        mutant = work / (name+'.m')
        mutant.write_text(text.replace(old, new, 1))
        binary = work / name
        compile_source(mutant, binary)
        reds.append(dict(name=name, output=run([binary], expected_success=False).strip()))
    result['reintroduced_previous_mismatches_rejected'] = reds
    files = [source, source.with_suffix('.h'), source.with_name('ToastView.lifecycle.provenance.md'),
             source.with_name('PresentationHost.h'), source.with_name('PresentationGeometry.h'), test, doubles, redirects,
             doubles.with_suffix('.h'), REPO / 'recovery/evidence/toast-lifecycle-fidelity.json', Path(__file__).resolve()]
    files += list(shim.rglob('*.h'))
    result['inputs'] = {str(p.relative_to(REPO)): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    report.write_text(json.dumps(result, indent=2)+'\n')
    print(f"Original {result['original_words']} words; {len(reds)} previous mismatch mutations rejected.")


if __name__ == '__main__':
    main()
