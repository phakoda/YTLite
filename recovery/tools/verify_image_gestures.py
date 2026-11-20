#!/usr/bin/env python3
"""Verify recovered image gesture callbacks and execute their actual Logos source."""
from logos_tool import logos_path
import hashlib,json,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/image-gestures-tests';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/ImageGestures.x';manifest_path=source.with_suffix('.manifest.json')
    manifest=json.loads(manifest_path.read_text());image=EvidenceImage();assert manifest['binary_sha256']==image.sha256
    hooks=[h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['class_name'] in ['YTPlayerView','YTImageZoomNode']];assert len(hooks)==len(manifest['registrations'])==2
    for original,row in zip(hooks,manifest['registrations']):assert all(row[k]==v for k,v in original.items())
    for row in manifest['registrations']+manifest['helpers']:
        start,end=int(row.get('implementation',row.get('address')),16),int(row['instruction_end'],16)
        assert hashlib.sha256(image.image.data[image.image.off(start):image.image.off(end)]).hexdigest()==row['instruction_sha256']
    commands=[]
    def run(args,output=None):
        args=list(map(str,args));result=subprocess.run(args,cwd=REPO,text=True,capture_output=True,timeout=120)
        if output:output.write_text(result.stdout)
        log=result.stderr if output else result.stdout+result.stderr
        commands.append({'command':args,'returncode':result.returncode,'output':log});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        print(log,end='',flush=True);result.check_returncode()
    generated=work/'ImageGestures.mm';llvm=work/'ImageGestures.ll'
    run(['perl',logos_path(),'-c','generator=internal',source],generated)
    options=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-vla-cxx-extension','-I',source.parent]
    run(['xcrun','--sdk','iphoneos','clang++',*options,'-target','arm64-apple-ios14.0','-S','-emit-llvm',generated,'-o',llvm])
    definitions=[line for line in llvm.read_text().splitlines() if line.startswith('define ') and ('_logos_method$' in line or '_logos_property$' in line) and '_block_invoke' not in line]
    assert len(definitions)==2
    for row in hooks:
        stem='$'+row['class_name']+'$'+row['selector'].replace(':','$')+'P'
        matches=[line for line in definitions if stem in line];assert len(matches)==1,(stem,matches)
        if row['class_name']=='YTPlayerView':assert matches[0].startswith('define internal void ')
        else:assert 'zeroext i1' in matches[0]
    blocks=[line for line in llvm.read_text().splitlines() if line.startswith('define ') and '_block_invoke' in line]
    assert len(blocks)==2 and all('(ptr noundef %0)' in line for line in blocks)
    fixture=REPO/'recovery/tests/image_gestures_fixture.mm';shims=REPO/'recovery/tests/image_gestures_shims';executable=work/'test'
    run(['xcrun','--sdk','macosx','clang++',*options,'-Wno-incomplete-implementation','-Wno-objc-property-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,generated,fixture,'-framework','Foundation','-framework','CoreGraphics','-o',executable])
    run([executable])
    inputs=[source,source.with_name('ImageGesturesHost.h'),manifest_path,fixture,*shims.rglob('*.h'),Path(__file__).resolve()]
    report.write_text(json.dumps({'registrations':2,'original_bytes':'verified','ios_callback_abi':'verified','actual_logos_runtime':'passed','original_binary_executed':False,'inputs':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}},indent=2)+'\n')
if __name__=='__main__':main()
