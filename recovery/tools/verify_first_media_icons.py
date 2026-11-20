#!/usr/bin/env python3
"""Check all first-package icon contracts and run the actual recovered factories."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
sys.dont_write_bytecode=True
from compare_supplied_packages import archive_files
from first_media_icon_contracts import contracts

REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-media-icons'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True)
    report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    manifest_path=REPO/'recovery/evidence/packages.json'
    evidence_path=REPO/'recovery/evidence/first-media-icons-fidelity.json'
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest=next(p for p in json.loads(manifest_path.read_text()) if p['package']==package.name)
    assert digest(package)==manifest['sha256']
    payload=archive_files(package,'data.tar')
    binary=next(b for name,b in payload.items() if name.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']
    original_path=WORK/'original.dylib';original_path.write_bytes(binary)
    source=REPO/'recovery/source/Downloads/YTPMedia.m'
    assets=REPO/'layout/Library/Application Support/YTLite.bundle/Assets.car'
    original_assets=next(b for name,b in payload.items() if name.endswith('/YTLite.bundle/Assets.car'))
    assert assets.read_bytes()==original_assets,'Current asset catalog differs from first package'
    fixture=REPO/'recovery/tests/first_media_icons_runtime.m'
    shims=REPO/'recovery/tests/first_media_shims'
    theme_path=REPO/'.recovery-work/first-media-theme/report.json'
    theme=json.loads(theme_path.read_text())
    assert theme['passed'] and theme['first_binary_sha256']==manifest['binary_sha256']
    assert set(theme['metadata'])=={'arm64','arm64e'}
    assert all(m['method_count']==67 for m in theme['metadata'].values())
    inputs=dict(theme['inputs'])
    for name,value in inputs.items():
        assert digest(REPO/name)==value,('Stale theme report input; rerun verify_first_media.py',name)
    paths=[manifest_path,evidence_path,assets,source,source.with_suffix('.h'),source.parent/'DownloadsHost.h',
        REPO/'recovery/source/Runtime/YTLFeaturePolicy.h',fixture,*shims.rglob('*.h'),
        theme_path,source.with_suffix('.icons.provenance.md'),Path(__file__).resolve(),
        *[REPO/'recovery/tools'/name for name in ['compare_supplied_packages.py','inventory.py',
            'decode_strings.py','first_media_icon_contracts.py']]]
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in paths})
    env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    commands=[]
    def run(command,expect_success=True):
        command=list(map(str,command));result=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append({'command':command,'exit_code':result.returncode,'stdout':result.stdout,'stderr':result.stderr})
        (WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if expect_success and result.returncode:raise RuntimeError(result.stdout+result.stderr)
        return result
    assembly=run(['xcrun','llvm-objdump','--disassemble','--start-address=0x1aab50',
                  '--stop-address=0x1b5e88',original_path]).stdout
    (WORK/'original-icons.asm').write_text(assembly)
    derived=contracts(binary,assembly);expected=json.loads(evidence_path.read_text())
    assert derived==expected,'First-package icon contracts changed'
    vectors=WORK/'contracts.json';vectors.write_text(json.dumps(derived,indent=2)+'\n')
    catalog=json.loads(run(['assetutil','--info',assets]).stdout)
    (WORK/'catalog.json').write_text(json.dumps(catalog,indent=2)+'\n')
    available={row['Name'] for row in catalog if row.get('Name') and not row['Name'].startswith('ZZZZPackedAsset-')}
    required={row[key] for row in derived['icons'] for key in ['normal','cairo']}
    assert required<=available,('Missing first-package icon assets',sorted(required-available))
    executable=WORK/'runtime'
    flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    run(['xcrun','--sdk','macosx','clang',*flags,'-I',shims,'-framework','Foundation','-framework','CoreGraphics',
         source,fixture,'-o',executable])
    output=run([executable,vectors]).stdout;(WORK/'runtime.log').write_text(output)
    match=re.fullmatch(r'PASS First_media_icons: (\d+) assertions\s*',output)
    assert match and int(match[1])==5458,output
    # Confirm the runtime oracle observes the selected name instead of merely
    # enumerating methods or accepting the generated list without comparison.
    wrong=json.loads(vectors.read_text());wrong['icons'][0]['normal']='incorrect-fixture-asset'
    negative=WORK/'incorrect-asset.json';negative.write_text(json.dumps(wrong)+'\n')
    rejected=run([executable,negative],expect_success=False)
    assert rejected.returncode==1 and 'historyTab first-package asset name' in rejected.stderr
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during audit',name)
    artifacts=[executable,vectors,WORK/'runtime.log',WORK/'commands.json',WORK/'original-icons.asm',WORK/'catalog.json']
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report={'passed':True,'first_package_sha256':manifest['sha256'],'first_binary_sha256':manifest['binary_sha256'],
        'runtime_assertions':int(match[1]),'factory_invocations':948,'named_factories':59,
        'incorrect_asset_negative_check':'rejected','requested_asset_names':len(required),
        'catalog_asset_names':len(available),'catalog_matches_first_package':True,'metadata_report':str(theme_path.relative_to(REPO)),
        'inputs':inputs,'original_binary_executed':False,
        'scope':'All 59 YTPMedia icon factories: original names, Cairo snapshots, class dispatch, nil forwarding, tint and return ownership',
        'limits':['Synthetic UIKit and asset lookup; native image appearance and device behavior untested.',
            'Theme setter system trap remains omitted; this does not establish full class or package parity.']}
    report_path.write_text(json.dumps(report,indent=2)+'\n')
    print(f'First-package YTPMedia icons: 59 factories, {match[1]} actual-source checks; incorrect asset rejected.')


if __name__=='__main__':main()
