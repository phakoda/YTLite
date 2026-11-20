#!/usr/bin/env python3
"""Verify the seven original settings entry hooks and run their actual source."""
from logos_tool import logos_path
import hashlib
import json
import subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO


def main():
    work=REPO/'.recovery-work/settings-bridge-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/SettingsBridge.x';manifest_path=source.with_suffix('.manifest.json')
    manifest=json.loads(manifest_path.read_text());image=EvidenceImage();assert manifest['binary_sha256']==image.sha256
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['registration']=='00011bec']
    assert len(hooks)==len(manifest['registrations'])==7
    for original,row in zip(hooks,manifest['registrations']):
        assert all(row[k]==v for k,v in original.items())
        start,end=int(row['implementation'],16),int(row['instruction_end'],16)
        assert hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()==row['instruction_sha256']
    commands=[]
    def run(args,output=None):
        args=list(map(str,args));result=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        if output:output.write_text(result.stdout)
        log=result.stderr if output else result.stdout+result.stderr
        commands.append({'command':args,'returncode':result.returncode,'output':log});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(log,end='',flush=True);result.check_returncode()
    generated=work/'SettingsBridge.mm';llvm=work/'SettingsBridge.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    options=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-I',source.parent]
    run(['xcrun','--sdk','iphoneos','clang++',*options,'-target','arm64-apple-ios14.0','-S','-emit-llvm',generated,'-o',llvm])
    definitions=[line for line in llvm.read_text().splitlines() if line.startswith('define ') and ('_logos_method$' in line or '_logos_meta_method$' in line)]
    assert len(definitions)==7
    for row in hooks:
        stem='$'+row['class_name']+'$'+row['selector'].replace(':','$')+'P'
        matches=[line for line in definitions if stem in line];assert len(matches)==1,(stem,matches)
        line=matches[0];arguments=line.split('"(',1)[1].split(') #',1)[0]
        assert len(arguments.split(','))==2+row['selector'].count(':')
        if row['selector'] in ['setSelectedItem:','updateSectionForCategory:withEntry:']:
            assert 'i64 noundef %2' in arguments
        else:assert 'i64' not in arguments
        if row['selector'] in ['settingsCategoryOrder','orderedCategories']:assert line.startswith('define internal ptr ')
        else:assert line.startswith('define internal void ')
    fixture=REPO/'recovery/tests/settings_bridge_fixture.mm';redirects=REPO/'recovery/tests/settings_bridge_redirects.h';shims=REPO/'recovery/tests/settings_bridge_shims'
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang++',*options,'-Wno-incomplete-implementation','-Wno-objc-property-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,'-include',redirects,generated,fixture,'-framework','Foundation','-o',executable])
    run([executable])
    inputs=[source,source.with_name('SettingsBridgeHost.h'),manifest_path,fixture,redirects,*shims.rglob('*.h'),Path(__file__).resolve()]
    report.write_text(json.dumps({'registrations':7,'original_bytes':'verified','ios_callback_abi':'verified','actual_logos_runtime':'passed','original_binary_executed':False,'external_calls':'UIKit navigation, settings model and defaults boundaries intercepted; no device/UI/network side effects','inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')


if __name__=='__main__':main()
