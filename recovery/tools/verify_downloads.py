#!/usr/bin/env python3
"""Compile/test the seven actual reconstructed Downloads classes without loading the original binary.

The macOS harness doubles ONLY unavailable UIKit/AVFoundation, external FFmpeg,
YouTube/SRT/pipeline hosts, and NSURLSession transport. Foundation file operations,
SHA-256, strings, JSON, runtime metadata, ARC and dispatch remain real.
All compiler caches, temporary files, fixtures, logs and archives stay in /YTLite.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
WORK = ROOT / '.recovery-work/downloads'
NAMES = ('YTPMedia','YTPDownloader','Downloader','AudioManager','YTPAPIHelper','FFMpegHelper','DownloadMenuHelper')
SOURCES = [ROOT / 'recovery/source/Downloads' / (n + '.m') for n in NAMES]
POLICY = ROOT / 'recovery/source/Runtime/YTLFeaturePolicy.m'
TESTS = [ROOT / 'recovery/tests' / ('downloads_' + name + '.m') for name in ('doubles','metadata','runtime')]
FLAGS = ['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
ORIGINAL_SHA256 = 'bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca'


def vectors():
    # Goldens are read from original decompilation, never from the reconstructed .m files.
    original = (ROOT / 'recovery/classes/YTPMedia.c').read_text()
    methods = re.findall(r'// \+\[YTPMedia ([^\]]+)\], (0x[0-9a-f]+)\n(.*?)(?=\n// [+-]\[|\Z)', original, re.S)
    icons = []
    for selector, address, body in methods:
        if not 0x1ab254 <= int(address,16) <= 0x1b636c: continue
        values = list(dict.fromkeys(re.findall(r'@"([^"\n]*)"', body)))
        assert len(values) == (1 if selector in ('x_prefs','empty') else 2), (selector,values)
        icons.append({'selector':selector,'normal':values[-1],'cairo':values[0],'address':address})
    assert len(icons) == 59
    original = (ROOT / 'recovery/classes/FFMpegHelper.c').read_text()
    values = {int(offset,16):value for offset,value in re.findall(r'ppuStack_([0-9a-f]+) = @"([^"\n]*)";', original)}
    languages = [{'code':values[0x5a0-i*8], 'result':values[0x320-i*8]} for i in range(80)]
    hashes = [{'name':name,'size':size,'sha256':hashlib.sha256((name+str(size)).encode('utf-8')).hexdigest()}
              for name,size in [('',0),('file.mp4',0),('file.mp4',42),('resume.bin',6),('Música 🔥.m4a',2**32+17),('maximum.bin',2**64-1)]]
    return {'icons':icons,'languages':languages,'hashes':hashes}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--host-only', action='store_true')
    parser.add_argument('--ios-only', action='store_true')
    args = parser.parse_args()
    if args.host_only and args.ios_only: parser.error('choose only one mode')
    WORK.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for key,relative in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),
                         ('CFFIXED_USER_HOME','home'),('XDG_CACHE_HOME','cache')]:
        directory=WORK/relative;directory.mkdir(exist_ok=True);env[key]=str(directory)
    env['PYTHONDONTWRITEBYTECODE']='1'
    stamp=datetime.datetime.now().strftime('%Y%m%d-%H%M%S-%f')
    runroot=WORK/'runs'/stamp;runroot.mkdir(parents=True)
    log=[]
    def run(command):
        command=[str(x) for x in command]
        print('+ '+' '.join(command),flush=True)
        result=subprocess.run(command,cwd=ROOT,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,timeout=120)
        print(result.stdout,end='',flush=True)
        log.append({'command':command,'exit_code':result.returncode,'output':result.stdout})
        (runroot/'commands.json').write_text(json.dumps(log,indent=2)+'\n')
        (WORK/'latest-run.txt').write_text(str(runroot.relative_to(ROOT))+'\n')
        result.check_returncode()
        return result.stdout.strip()
    binary_hash=hashlib.sha256((ROOT/'.recovery-work/arm/YTLite.dylib').read_bytes()).hexdigest()
    if binary_hash != ORIGINAL_SHA256: raise RuntimeError('Original evidence binary SHA-256 changed')
    evidence_paths=[ROOT/'recovery/evidence/first-menu-thumbnail-fidelity.json',ROOT/'recovery/evidence/first-menu-parsers-fidelity.json',ROOT/'recovery/evidence/arm-classes.json',ROOT/'recovery/evidence/ivars.json',*[ROOT/'recovery/classes'/(n+'.c') for n in NAMES]]
    owned_inputs=sorted(set(SOURCES+TESTS+[POLICY,POLICY.with_suffix('.h'),ROOT/'recovery/source/Subtitles/SRTParser.h',ROOT/'recovery/source/Presentation/ToastView.h',ROOT/'recovery/tests/downloads_presentation_declarations.h']+list((ROOT/'recovery/source/Downloads').glob('*.h'))+list((ROOT/'recovery/tests/downloads_shims').rglob('*.h'))+[ROOT/'recovery/tests/downloads_doubles.h']))
    report={'original_binary_sha256':binary_hash,'evidence_sha256':{str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in evidence_paths},'classes':list(NAMES),'original_metadata_methods':141,'host_runtime':'not run','ios_arm64':'not run','ios_arm64e':'not run',
            'original_binary_executed':False,'real_network_exercised':False,'real_codec_exercised':False,
            'device_validation':'not performed','sources_sha256':{str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in owned_inputs}}
    try:
        if not args.ios_only:
            golden=runroot/'evidence-vectors.json';golden.write_text(json.dumps(vectors(),ensure_ascii=False,indent=2)+'\n')
            executable=runroot/'downloads-runtime'
            run(['xcrun','--sdk','macosx','clang',*FLAGS,'-include',ROOT/'recovery/tests/downloads_presentation_declarations.h','-I',ROOT/'recovery/tests/downloads_shims',
                 '-DNSTemporaryDirectory=DownloadsTestTemporaryDirectory','-framework','Foundation','-framework','CoreGraphics',
                 *SOURCES,POLICY,*TESTS,'-o',executable])
            output=run([executable,ROOT,runroot/'fixtures',golden])
            report['host_runtime']='passed';report['runtime_output']=output
            match=re.search(r'Downloads runtime: (\d+) behavioral assertions \+ (\d+) exact ABI assertions = (\d+) passed',output)
            if not match: raise RuntimeError('Missing runtime assertion summary')
            report['assertions']={'behavioral':int(match[1]),'exact_abi':int(match[2]),'total':int(match[3])}
        if not args.host_only:
            sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path'])
            for arch in ('arm64','arm64e'):
                objdir=runroot/arch;objdir.mkdir()
                objects=[]
                for source in SOURCES:
                    obj=objdir/(source.stem+'.o')
                    run(['xcrun','--sdk','iphoneos','clang',*FLAGS,'-target',arch+'-apple-ios14.0','-isysroot',sdk,'-c',source,'-o',obj])
                    objects.append(obj)
                archive=objdir/'libYTLiteRecoveredDownloads.a'
                run(['xcrun','libtool','-static','-o',archive,*objects])
                report['ios_'+arch]='compiled and archived'
    finally:
        (runroot/'report.json').write_text(json.dumps(report,indent=2)+'\n')
        (WORK/'latest-report.json').write_text(json.dumps(report,indent=2)+'\n')
    print('Downloads validation report: '+str((runroot/'report.json').relative_to(ROOT)))

if __name__=='__main__':
    main()
