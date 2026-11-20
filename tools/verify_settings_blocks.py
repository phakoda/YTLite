#!/usr/bin/env python3
"""Read original stack/global block descriptors, never execute original code."""
import argparse, contextlib, io, json, re, sys
sys.dont_write_bytecode = True
from verify_settings_inspect import Image, annotate, ROOT
from verify_settings_metadata import NAMES

# Explicit user-requested local-fork delta, not missing reconstruction: the
# account provider, login/manage handler and logout confirmation were removed.
REMOVED_ACCOUNT_BLOCKS = {'0x178208', '0x17959c', '0x179c58'}

def extract():
    image = Image()
    classes = json.loads((ROOT / 'recovery/evidence/arm-classes.json').read_text())
    starts = sorted(image.function_starts)
    owners = {}
    for cls in classes:
        if cls['name'] not in NAMES:
            continue
        methods = sorted(int(m['address'], 16) for m in cls['methods'])
        end = next(a for a in starts if a > methods[-1])
        owners[cls['name']] = (methods[0], end)
        with contextlib.redirect_stdout(io.StringIO()):
            annotate(image, methods[0], end)
    for at, symbol in image.binds.items():
        if symbol != '__NSConcreteGlobalBlock':
            continue
        invoke = image.uint(at + 16)
        descriptor = image.uint(at + 24)
        flags = image.uint(at + 8)
        if not all(isinstance(v, int) for v in (invoke, descriptor, flags)):
            continue
        if not any(lo <= invoke < hi for lo, hi in owners.values()):
            continue
        sigptr = image.uint(descriptor + (32 if flags & 0x02000000 else 16))
        image.blocks[invoke] = {
            'invoke': hex(invoke), 'literal': hex(at),
            'descriptor': hex(descriptor), 'flags': hex(flags),
            'signature': image.cstring(sigptr) if isinstance(sigptr, int) else None,
            'size': image.uint(descriptor + 8),
        }
    result = []
    for invoke, block in sorted(image.blocks.items()):
        block['class'] = next((name for name, (lo, hi) in owners.items() if lo <= invoke < hi), None)
        if block['class']:
            result.append(block)
    return result

if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--audit-compiled',action='store_true')
    args=parser.parse_args()
    result = extract()
    (ROOT / '.recovery-work/settings/original-blocks.json').write_text(json.dumps(result, indent=2) + '\n')
    for block in result:
        print(block['class'], block['invoke'], block['signature'])
    print(len(result), 'original block signatures recovered')

    if args.audit_compiled:
        from verify_settings_metadata import decode
        signatures={}
        for name in NAMES:
            ir=(ROOT/'.recovery-work/settings'/(name+'.ll')).read_text()
            signatures[name]={decode(m[1]) for m in re.finditer(r'\bc"((?:\\[0-9A-Fa-f]{2}|[^"\\])*)"',ir)}
        errors=[]
        for block in result:
            if block['invoke'] in REMOVED_ACCOUNT_BLOCKS:
                continue
            if block['signature'] not in signatures[block['class']]:
                errors.append(f"{block['class']} {block['invoke']}: compiled signature missing {block['signature']}")
        for error in errors:print('FAIL:',error)
        if errors:raise SystemExit(1)
        print(f'Compiled block ABI: {len(result) - len(REMOVED_ACCOUNT_BLOCKS)} retained original signatures represented; '
              f'{len(REMOVED_ACCOUNT_BLOCKS)} account callbacks intentionally removed.')
