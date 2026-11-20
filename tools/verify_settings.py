#!/usr/bin/env python3
"""Compile and verify the six recovered Settings classes on the approved Mac.

Runs ONLY newly compiled fixture code. Never loads or executes original dylibs.
Every generated file, cache, log and fixture filesystem stays in this repo.
"""
from __future__ import annotations
import hashlib, json, os, re, subprocess, sys
from pathlib import Path
sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT/'.recovery-work/settings'
CLASSES = ['DVNTableViewController','YTPSettingsBuilder','DVNPickerView','YTPTableViewCell','TabbarVC','DVNSupportersVC']
HASH = 'bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca'


def rounding_evidence() -> dict:
    # Read packaged instruction bytes directly; decoded string overlays are not code evidence.
    sys.path.insert(0, str(ROOT/'recovery/tools'))
    from evidence_image import EvidenceImage
    image = EvidenceImage()
    expected = {
        0x11c80c: (0x1e64c100, 'FRINTP d0,d8: ceiling of measured double height'),
        0x11c810: (0x1e649001, 'FMOV d1,#10.0'),
        0x11c814: (0x1e612808, 'FADD d8,d0,d1: double padding addition'),
        0x1219a0: (0x1e22c008, 'FCVT d8,s0: widen slider float'),
        0x1219b0: (0x1e601900, 'FDIV d0,d8,d0: double quotient'),
        0x1219b4: (0x1e664008, 'FRINTA d8,d0: nearest ties away, remains double'),
        0x1219c4: (0x1e680800, 'FMUL d0,d0,d8: multiply freshly read divider'),
        0x1219c8: (0x1e624000, 'FCVT s0,d0: narrow final product to float'),
    }
    result = {}
    for address, (word, meaning) in expected.items():
        offset = image.image.off(address)
        raw = image.image.data[offset:offset+4]
        if int.from_bytes(raw, 'little') != word:
            raise RuntimeError(f'Original rounding instruction differs at {address:#x}')
        result[hex(address)] = {'word':f'{word:08x}', 'meaning':meaning}
    return {'sha256':image.sha256, 'raw_original_instructions':result,
            'oracle':'newly compiled native FRINTP/FRINTA fixtures; original dylib never executed'}


def main() -> int:
    os.chdir(ROOT)
    for name in ['tmp','module-cache','cache','test-home','fixture-fs']:
        (WORK/name).mkdir(parents=True,exist_ok=True)
    binary=ROOT/'.recovery-work/arm/YTLite.dylib'
    actual=hashlib.sha256(binary.read_bytes()).hexdigest()
    if actual!=HASH:
        raise RuntimeError(f'Wrong original evidence hash: {actual}')
    env=dict(os.environ,TMPDIR=str(WORK/'tmp'),TMP=str(WORK/'tmp'),TEMP=str(WORK/'tmp'),
             CLANG_MODULE_CACHE_PATH=str(WORK/'module-cache'),XDG_CACHE_HOME=str(WORK/'cache'),
             PYTHONDONTWRITEBYTECODE='1')
    rounding = rounding_evidence()
    commands=[]
    def run(args: list[str],label: str,extra_env: dict[str,str]|None=None) -> str:
        argv=[str(a) for a in args]
        process=subprocess.run(argv,cwd=ROOT,env=env| (extra_env or {}),text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        text=process.stdout
        (WORK/(label+'.log')).write_text(text)
        commands.append({'label':label,'argv':argv,'exit_code':process.returncode})
        (WORK/'verification-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if process.returncode:
            print(text,end='');raise RuntimeError(f'{label} failed with exit status {process.returncode}')
        return text
    if run(['uname','-s'],'platform').strip()!='Darwin':raise RuntimeError('Requires approved real Mac with Apple SDKs')
    ios=run(['xcrun','--sdk','iphoneos','--show-sdk-path'],'iphoneos-sdk').strip()
    mac=run(['xcrun','--sdk','macosx','--show-sdk-path'],'macos-sdk').strip()
    common=['xcrun','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror',
            '-fmodules-cache-path='+str(WORK/'module-cache')]
    iosflags=common+['-target','arm64-apple-ios13.0','-isysroot',ios]
    hostflags=common+['-target','arm64-apple-macos13.0','-isysroot',mac,'-I'+str(ROOT/'recovery/tests/settings_shims')]
    redirects=['-include',str(ROOT/'recovery/tests/settings_fixture_redirects.h')]
    objects=[]
    for cls in CLASSES:
        source=ROOT/'recovery/source/Settings'/f'{cls}.m'
        run(iosflags+['-c',str(source),'-o',str(WORK/f'{cls}.o')],f'ios-{cls}')
        run(iosflags+['-S','-emit-llvm',str(source),'-o',str(WORK/f'{cls}.ll')],f'ir-{cls}')
        output=WORK/f'host-{cls}.o'
        run(hostflags+redirects+['-c',str(source),'-o',str(output)],f'host-{cls}')
        objects.append(str(output))
    print('Strict iOS arm64 compilation: all six classes passed.')
    for tool,label in [('verify_settings_metadata.py','metadata'),('verify_settings_rows.py','rows'),('verify_settings_blocks.py','blocks')]:
        output=run([sys.executable,'-B',str(ROOT/'tools'/tool)]+(['--audit-compiled'] if label=='blocks' else []),label)
        print(output,end='')
    print(run([sys.executable,'-B',str(ROOT/'tools/verify_settings_provenance.py')],'provenance'),end='')
    shared=['recovery/source/Models/DVNCell.m','recovery/source/Models/DVNSection.m',
            'recovery/source/Models/DVNTableModel.m','recovery/source/Support/YTPDB.m','recovery/tests/MetadataAudit.m']
    owned=['settings_ui_doubles','settings_fixture_hosts','settings_runtime','settings_controller_fixture','settings_views_fixture']
    for relative in shared+[f'recovery/tests/{name}.m' for name in owned]:
        source=ROOT/relative;output=WORK/f'fixture-{source.stem}.o'
        run(hostflags+redirects+['-c',str(source),'-o',str(output)],f'fixture-{source.stem}')
        objects.append(str(output))
    runtime=WORK/'settings-runtime'
    run(hostflags+['-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore']+objects+['-o',str(runtime)],'host-link')
    text=run([str(runtime),str(WORK/'fixture-fs'),str(WORK/'original-rows.json'),str(ROOT/'recovery/evidence/arm-classes.json')],
             'runtime',{'CFFIXED_USER_HOME':str(WORK/'test-home')})
    print(text,end='')
    if 'implemented in both' in text:raise RuntimeError('Duplicate fixture runtime class names')
    match=re.search(r'Settings runtime: (\d+) assertions passed',text)
    if not match:raise RuntimeError('Missing runtime assertion result')
    audit=json.loads((WORK/'metadata-audit.json').read_text())
    rows=json.loads((WORK/'original-rows.json').read_text());blocks=json.loads((WORK/'original-blocks.json').read_text())
    report={'rounding_evidence':rounding,'evidence_sha256':actual,'ios_compile_classes':CLASSES,'methods':audit['method_count'],
            'properties':audit['property_count'],'ivars':audit['ivar_count'],'metadata_differences':audit['errors'],
            'original_row_fixtures':sum(len(v) for v in rows.values()),'original_block_signatures':len(blocks),
            'compiled_retained_block_signatures_match':True,'method_and_block_provenance_verified':True,
            'intentionally_removed_account_callbacks':3,'requires_account':False,
            'runtime_assertions':int(match[1]),
            'fixture_source_sha256':{str(path.relative_to(ROOT)):hashlib.sha256(path.read_bytes()).hexdigest()
                for path in sorted((ROOT/'recovery/tests').glob('settings*.*')) if path.is_file()},'fixture_only_redirects':['NSUserDefaults frontend and instances','NSURLSession',
                'UIApplication URL opens','UIPasteboard','cache paths','temporary path','dispatch queues'],
            'unverified_integration':['real YouTube host messaging and UIKit visual presentation',
                'localization/media resources and preferences implementations'],
            'production_source_sha256':{cls:hashlib.sha256((ROOT/'recovery/source/Settings'/f'{cls}.m').read_bytes()).hexdigest() for cls in CLASSES}}
    (WORK/'verification-summary.json').write_text(json.dumps(report,indent=2)+'\n')
    print('Verification summary:',WORK/'verification-summary.json')
    return 0

if __name__=='__main__':
    try:raise SystemExit(main())
    except (OSError,ValueError,RuntimeError,subprocess.SubprocessError) as error:
        print(f'Verification failed: {error}',file=sys.stderr);raise SystemExit(1)
