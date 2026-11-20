#!/usr/bin/env python3
"""Check five SponsorBlock player registrations and execute actual Logos bodies."""
from logos_tool import logos_path
import hashlib
import json
import subprocess
from pathlib import Path
from evidence_image import EvidenceImage, REPO


def main():
    work=REPO/'.recovery-work/sponsor-playback-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/SponsorPlayback.x'
    manifest=json.loads(source.with_suffix('.manifest.json').read_text());image=EvidenceImage()
    assert manifest['binary_sha256']==image.sha256
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['registration']=='0001efd4' and h['class_name']=='YTPlayerViewController']
    assert len(hooks)==len(manifest['registrations'])==5
    for original,row in zip(hooks,manifest['registrations']):
        assert all(row[k]==v for k,v in original.items())
        start,end=int(row['implementation'],16),int(row['instruction_end'],16)
        assert hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()==row['instruction_sha256']
    for row in manifest['gate_wrappers']:
        assert image.terminal(int(row['address'],16))==row['terminal']=='_ytpBool'
    commands=[]
    def run(args,output=None):
        args=list(map(str,args));result=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        if output:output.write_text(result.stdout)
        log=result.stderr if output else result.stdout+result.stderr
        commands.append({'command':args,'returncode':result.returncode,'output':log});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(log,end='',flush=True);result.check_returncode()
    generated=work/'SponsorPlayback.mm';llvm=work/'SponsorPlayback.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    # Pinned Logos emits a VLA for property type encodings.
    options=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-vla-cxx-extension','-I',source.parent]
    run(['xcrun','--sdk','iphoneos','clang++',*options,'-target','arm64-apple-ios14.0','-S','-emit-llvm',generated,'-o',llvm])
    definitions=[line for line in llvm.read_text().splitlines() if line.startswith('define ') and ('_logos_method$' in line or '_logos_property$' in line)]
    assert len(definitions)==5
    for row in hooks:
        selector=row['selector'].replace(':','$')
        property_method=row['selector'] in ['sbPlaybackController','setSbPlaybackController:']
        stem='$YTPlayerViewController$'+(selector.rstrip('$') if property_method else selector)
        matches=[line for line in definitions if stem+'P' in line]
        assert len(matches)==1,(selector,matches)
        line=matches[0];arguments=line.split('"(',1)[1].split(') #',1)[0]
        assert arguments.count('ptr noundef')==2+row['selector'].count(':')
        assert line.startswith('define internal ptr ' if row['selector']=='sbPlaybackController' else 'define internal void '),line
    executable=work/'test'
    run(['xcrun','--sdk','macosx','clang++',*options,'-Wno-incomplete-implementation','-fsanitize=undefined','-fno-sanitize-recover=all',generated,REPO/'recovery/tests/sponsor_playback_fixture.mm','-framework','Foundation','-o',executable])
    run([executable])
    inputs=[source,source.with_name('SponsorPlaybackHost.h'),source.with_suffix('.manifest.json'),REPO/'recovery/tests/sponsor_playback_fixture.mm',Path(__file__).resolve()]
    report.write_text(json.dumps({'registrations':5,'original_bytes':'verified','ios_callback_abi':'verified','actual_logos_runtime':'passed','original_binary_executed':False,'external_calls':'SBPlaybackController and SBPlayerDecorator intercepted at class boundaries; no network or UI', 'inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')


if __name__=='__main__':main()
