#!/usr/bin/env python3
"""Verify first-package resource categories using static evidence and fake boundaries."""
import hashlib
import json
import os
from pathlib import Path
import plistlib
import re
import struct
import subprocess
from compare_supplied_packages import archive_files
from decode_strings import decode
from inventory import MachO
from verify_objc_categories import extract_categories

REPO = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    work = REPO / '.recovery-work/first-bundle'
    work.mkdir(exist_ok=True)
    report = work / 'report.json'
    report.unlink(missing_ok=True)
    evidence = REPO / 'recovery/evidence/first-bundle-fidelity.json'
    expected = json.loads(evidence.read_text())
    package = Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest = next(x for x in json.loads((REPO/'recovery/evidence/packages.json').read_text()) if x['package']==package.name)
    assert sha(package)==manifest['sha256']
    files=archive_files(package,'data.tar')
    binary=next(data for name,data in files.items() if name.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==expected['binary_sha256']==manifest['binary_sha256']
    image=MachO(binary);binary_path=work/'original.dylib';binary_path.write_bytes(binary)
    commands=[];env=dict(os.environ)
    for key,name in [('TMPDIR','tmp'),('CFFIXED_USER_HOME','home'),('CLANG_MODULE_CACHE_PATH','cache')]:
        path=work/name;path.mkdir(exist_ok=True);env[key]=str(path)
    env['UBSAN_OPTIONS']='halt_on_error=1:print_stacktrace=0'
    def run(command):
        command=list(map(str,command));result=subprocess.run(command,cwd=REPO,env=env,capture_output=True,text=True,timeout=90)
        commands.append({'command':command,'exit_code':result.returncode,'output':result.stdout+result.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode:print(result.stdout+result.stderr)
        result.check_returncode();return result.stdout
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x234154','--stop-address=0x2352e4',binary_path])
    _,writes,_=decode(binary,assembly)
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    for item in expected['strings']:
        a=int(item['address'],16);p=image.ptr(a+16);n=struct.unpack_from('<Q',binary,image.off(a+24))[0]
        assert bytes(writes.get(x,binary[image.off(x)]) for x in range(p,p+n)).decode()==item['value']
    for item in expected['branches']:
        t,k,x=[int(item[key],16) for key in ['table','key','xor']]
        delta=(-(image.u32(image.off(k))^x))&0xffffffff
        if delta>=2**31:delta-=2**32
        assert list(map(hex,[image.ptr(t+i*8)+delta for i in range(2)]))==item['targets']
    assert '__Z6jbrootP8NSString' in image.imports
    source=REPO/'Utils/NSBundle+YTLite.m';localization=REPO/'Utils/NSString+YTLite.m'
    fixture=REPO/'recovery/tests/first_bundle_runtime.m';doubles=REPO/'recovery/tests/UIKitDoubles.m'
    headers=[REPO/'Utils/NSBundle+YTLite.h',REPO/'Utils/NSString+YTLite.h',REPO/'recovery/source/Runtime/YTLRootPaths.h',REPO/'recovery/tests/shims/UIKit/UIKit.h']
    category_fixture=REPO/'recovery/tests/first_category_runtime.m'
    helpers=[REPO/'recovery/tools'/name for name in ['compare_supplied_packages.py','decode_strings.py','inventory.py','verify_objc_categories.py']]
    inputs=[source,localization,fixture,category_fixture,doubles,*headers,*helpers,evidence,Path(__file__).resolve()]
    before={str(path.relative_to(REPO)):sha(path) for path in inputs}
    flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-DYTLITE_RESOURCE_ROOTHIDE=1']
    llvm=work/'bundle.ll';obj=work/'bundle.o'
    run(['xcrun','--sdk','iphoneos','clang',*flags,'-target','arm64-apple-ios14.0','-S','-emit-llvm',source,'-o',llvm])
    run(['xcrun','--sdk','iphoneos','clang','-target','arm64-apple-ios14.0','-c',llvm,'-o',obj])
    symbols=run(['xcrun','nm','-u',obj]).splitlines()
    assert '__Z6jbrootP8NSString' in symbols and '_YTLJailbreakPath' not in symbols
    categories=extract_categories(llvm.read_text());actual=categories[('NSBundle','YTLite')]
    a,n,_=image.sections['__objc_catlist'];original=None
    for p in range(a,a+n,8):
        category=image.ptr(p)
        if image.string(image.ptr(category))=='YTLite':
            methods=image.methods(image.ptr(category+16),'-')+image.methods(image.ptr(category+24),'+')
            original={m['kind']+m['selector']:m['encoding'] for m in methods}
            assert {m['kind']+m['selector']:m['address'] for m in methods}==expected['method_targets']['YTLite']
    assert actual==original and len(actual)==4
    localization_llvm=work/'localization.ll'
    run(['xcrun','--sdk','iphoneos','clang',*flags,'-target','arm64-apple-ios14.0','-S','-emit-llvm',localization,'-o',localization_llvm])
    localization_actual=extract_categories(localization_llvm.read_text())[('NSString','YTL')]
    localization_original=None
    for p in range(a,a+n,8):
        category=image.ptr(p)
        if image.string(image.ptr(category))=='YTL':
            methods=image.methods(image.ptr(category+16),'-')+image.methods(image.ptr(category+24),'+')
            localization_original={m['kind']+m['selector']:m['encoding'] for m in methods}
            assert {m['kind']+m['selector']:m['address'] for m in methods}==expected['method_targets']['YTL']
    assert localization_actual==localization_original and len(localization_actual)==1
    executable=work/'runtime'
    run(['xcrun','--sdk','macosx','clang',*flags,'-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/shims',source,localization,doubles,fixture,'-framework','Foundation','-o',executable])
    def bundle(path,identifier):
        resources=path/'Contents/Resources';(resources/'en.lproj').mkdir(parents=True,exist_ok=True)
        (path/'Contents/Info.plist').write_bytes(plistlib.dumps({'CFBundleIdentifier':identifier,'CFBundleName':identifier,'CFBundlePackageType':'BNDL','CFBundleDevelopmentRegion':'en'}))
        (resources/'en.lproj/Localizable.strings').write_text('"Translated" = "Fixture translation";\n"Empty" = "";\n')
        return resources
    counts={}
    for mode in ['bundled','installed','missing','invalid','null','long']:
        directory=work/'fixtures'/mode;directory.mkdir(parents=True,exist_ok=True)
        main=directory/'Main.bundle';resources=bundle(main,'recovery.first.'+mode);installed=directory/'Installed.bundle'
        if mode=='bundled':bundle(resources/'YTLite.bundle','recovery.first.embedded')
        elif mode=='installed':bundle(installed,'recovery.first.installed')
        elif mode=='invalid':installed.write_text('not a bundle directory')
        output=run([executable,main,installed,mode]);print(output,end='')
        counts[mode]=int(re.search(r'assertions passed: (\d+)',output)[1])
    category_executable=work/'categories'
    run(['xcrun','--sdk','macosx','clang',*flags,'-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/shims',source,localization,doubles,category_fixture,'-framework','Foundation','-o',category_executable])
    output=run([category_executable]);print(output,end='')
    counts['image-localization-boundaries']=int(re.search(r'assertions passed: (\d+)',output)[1])
    assert before=={str(path.relative_to(REPO)):sha(path) for path in inputs},'Inputs changed during verification'
    report.write_text(json.dumps({'passed':True,'runtime_assertions':sum(counts.values()),'modes':counts,
        'first_package_sha256':manifest['sha256'],'first_binary_sha256':expected['binary_sha256'],
        'original_category_encodings':original,'original_localization_encodings':localization_original,
        'compiled_external_symbol':'__Z6jbrootP8NSString','inputs':before,
        'original_binary_executed':False,'real_roothide_loaded':False,
        'limits':['Bundle/image/localization category checks only; full roothide packaging/linking and device execution remain unverified.']},indent=2)+'\n')
    print('First-package bundle/image/localization helpers and five iOS category encodings verified.')


if __name__=='__main__':main()
