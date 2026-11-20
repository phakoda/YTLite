#!/usr/bin/env python3
"""Verify four extracted records' original identities and existing source ownership.

This is a static original-byte/metadata audit. It does not replace the owners'
actual runtime verifiers or claim subclass initialization equivalence.
"""
import hashlib
import json
import re
from evidence_image import EvidenceImage, REPO
from verify_sideload_supplemental_registrations import original_lines


def main():
    image = EvidenceImage()
    manifest = json.loads((REPO / 'recovery/evidence/registration-resolutions.json').read_text())
    hooks = json.loads((REPO / 'recovery/evidence/hooks.json').read_text())
    assert manifest['binary_sha256'] == image.sha256
    assert len(manifest['resolutions']) == 4
    for row in manifest['resolutions']:
        assert row['original_inventory_row'] in hooks
        assert (REPO / row['source_owner']).is_file()
        assert image.image.u32(image.image.off(int(row['call_site'], 16))) == int(row['call_instruction'], 16)
        assert image.terminal(int(row['call_wrapper'], 16)) == row['registration_api']
    for span in manifest['instruction_intervals']:
        start, end = int(span['start'], 16), int(span['end'], 16)
        assert end == min(a for a in image.image.function_starts if a > start)
        assert hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest() == span['sha256']
        original_lines(image, start, end)
    for constant in manifest['decoded_constants']:
        assert image.cstring(int(constant['address'], 16)) == constant['value']
    classes = json.loads((REPO / 'recovery/evidence/arm-classes.json').read_text())
    toast = next(c for c in classes if c['name'] == 'ToastWindow')
    for method in manifest['toast_method_metadata']:
        assert method in toast['methods']
    selectors = {m['selector']: m for m in toast['methods']}
    assert '_canAffectStatusBarAppearance' not in selectors
    assert selectors['_canBecomeKeyWindow']['address'] == '0x1c8cd4'
    assert image.cstring(image.image.ptr(0x114ded8)) == 'shouldAffectStatusBarAppearance'
    assert image.cstring(image.image.ptr(0x114dee0)) == 'canBecomeKeyWindow'
    assert image.cfstring(0x11b4950) == '_%@'
    assert image.image.u32(image.image.off(0x18de0)) == 0x3914c11f
    assert image.image.data[image.image.off(0x1153530)] == 1
    assert image.image.u32(image.image.off(0x179bfc)) == 0x3900011f
    for row in manifest['additional_registrations']:
        assert image.image.u32(image.image.off(int(row['call_site'], 16))) == int(row['call_instruction'], 16)
        assert image.terminal(int(row['call_wrapper'], 16)) == row['registration_api']
    assert image.image.u32(image.image.off(0x18f7c)) == 0x3914c11f
    # Recover the complete argument descriptor at the supplemental tail call.
    # This interval only prepares four registration arguments and restores SP/LR.
    regs = {}
    for address, word, instruction in original_lines(image, 0x18f80, 0x18fb0):
        if instruction.startswith('adrp'):
            m = re.match(r'adrp\s+(x\d+), 0x([0-9a-f]+)', instruction)
            regs[m[1]] = int(m[2], 16)
        elif instruction.startswith('add\tx'):
            m = re.match(r'add\s+(x\d+), (x\d+), #0x([0-9a-f]+)', instruction)
            regs[m[1]] = regs[m[2]] + int(m[3], 16)
        elif instruction.startswith('ldr'):
            m = re.match(r'ldr\s+(x\d+), \[(x\d+), #0x([0-9a-f]+)\]', instruction)
            regs[m[1]] = image.image.ptr(regs[m[2]] + int(m[3], 16))
        elif address == 0x18f88:
            assert image.terminal(0x1d3a0) == '_objc_getClass'
            regs['x0'] = image.cstring(regs['x0'])
        elif address == 0x18fac:
            row = manifest['additional_registrations'][0]
            assert regs['x0'] == row['class_name'] == 'NSBundle'
            assert image.cstring(regs['x1']) == row['selector'] == 'infoDictionary'
            assert regs['x2'] == int(row['implementation'], 16) == 0x148c8
            assert regs['x3'] == int(row['original_slot'], 16) == 0x191b7c0
        else:
            assert address in (0x18fa4, 0x18fa8), (hex(address), instruction)
    toast_source = (REPO / 'recovery/source/Presentation/ToastWindow.m').read_text()
    for selector in ['_canAffectStatusBarAppearance', '_canBecomeKeyWindow']:
        assert f'class_addMethod(self, NSSelectorFromString(@"{selector}")' in toast_source
    assert 'class_getInstanceMethod(self, @selector(shouldAffectStatusBarAppearance))' in toast_source
    assert 'class_getInstanceMethod(self, @selector(canBecomeKeyWindow))' in toast_source
    assert '- (BOOL)_canBecomeKeyWindow { return NO; }' in toast_source
    assert 'self != ToastWindow.class' not in toast_source
    assert 'self == ToastWindow.class' not in toast_source
    workaround = (REPO / 'recovery/source/Runtime/InitWorkaround.m').read_text()
    assert 'NSDictionary *replaceInfoDict(NSBundle *bundle, SEL selector)' in workaround
    assert '[orig_infoDictionary(bundle, selector) mutableCopy]' in workaround
    assert '[bundle isEqual:NSBundle.mainBundle]' in workaround
    assert 'info[@"CFBundleIdentifier"] = @"com.google.ios.youtube"' in workaround
    assert 'MSHookMessageEx(NSBundle.class, @selector(infoDictionary), (IMP)replaceInfoDict, (IMP *)&orig_infoDictionary)' in workaround
    assert '2 * NSEC_PER_SEC' in workaround
    inline = (REPO / 'recovery/source/Hooks/SideloadCompatibility.x').read_text()
    assert 'if (isYTPFirstTime)' in inline and 'isYTPFirstTime = NO;' in inline and 'YTLInstallBundleInfoHook();' in inline
    identity = (REPO / 'recovery/source/Hooks/SideloadIdentity.x').read_text()
    assert 'if (isYTPFirstTime)' in identity and 'isYTPFirstTime = NO;' in identity and 'YTLInstallBundleInfoHook();' in identity
    print('Verified four original registration resolutions: ToastWindow alias and duplicate-add attempt, plus three bundle-info paths sharing one existing replacement (two extracted and one supplemental). Static ownership audit; actual owner runtime coverage is recorded separately.')


if __name__ == '__main__':
    main()
