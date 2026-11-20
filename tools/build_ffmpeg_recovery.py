#!/usr/bin/env python3
"""Restore and build the exact upstream mobile-ffmpeg/FFmpeg source revisions.

The iOS arm64 audio-LTS feature set matches the supplied binary. The compiler,
SDK and build date differ from its 2020 build and binary identity is not claimed.
"""
import argparse
import ast
import hashlib
import json
import os
import re
from pathlib import Path
import shutil
import shlex
import subprocess
import sys
import tarfile
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
VENDOR = ROOT/'vendor/mobile-ffmpeg-recovery'
WORK = ROOT/'.recovery-work/ffmpeg-dependency'
USER_AGENT = 'OpenAI File Downloader, XaiImageApiFetch/1.0'
SOURCES = {
    'mobile-ffmpeg': ('https://codeload.github.com/tanersener/mobile-ffmpeg/tar.gz/55700fb8bb5ec3e4c7be57506349838387d04364', '08a89a6197ff1bc222ae4487aa531433a36f6ace50e4b57c54e279a529bc9c3b'),
    'ffmpeg': ('https://codeload.github.com/tanersener/FFmpeg/tar.gz/d222da435e63a2665b85c0305ad2cf8a07b1af6d', 'f8c7e55aa54f2468749dbeb820e13b821d6a38d8c8ca671a8baa139577082196'),
    'gas-preprocessor': ('https://raw.githubusercontent.com/libav/gas-preprocessor/d09971fad329d32df19f5bbafe88cf2f0ed04ed7/gas-preprocessor.pl', '78ad06351ac8be513fb6e6291d9bb8f667899625c2649093e3b08f59fae950a2'),
}
AUDIO = ['lame','libvorbis','opencore-amr','shine','speex','wavpack','libilbc','opus','soxr','twolame','vo-amrwbenc']
BUILTIN = ['ios-zlib','ios-audiotoolbox','ios-bzip2','ios-videotoolbox','ios-libiconv']
OPTIONS = ['--lts','--force'] + ['--disable-'+a for a in ['armv7','armv7s','arm64e','i386','x86-64','x86-64-mac-catalyst']] + ['--enable-'+lib for lib in AUDIO+BUILTIN]

def obtain(name):
    url, expected = SOURCES[name]
    output = WORK/(name+('.pl' if name == 'gas-preprocessor' else '.tar.gz'))
    if not output.exists():
        request = urllib.request.Request(url, headers={'User-Agent':USER_AGENT})
        with urllib.request.urlopen(request, timeout=120) as response, output.open('wb') as stream:
            shutil.copyfileobj(response, stream)
    if hashlib.sha256(output.read_bytes()).hexdigest() != expected:
        raise ValueError('Download hash mismatch: '+name)
    return output

def extract(archive, destination):
    destination.mkdir(parents=True, exist_ok=True)
    with tarfile.open(archive) as contents:
        for member in contents.getmembers():
            components = Path(member.name).parts
            if len(components) <= 1: continue
            relative = Path(*components[1:])
            if relative.is_absolute() or '..' in relative.parts:
                raise ValueError('Unsafe archive path')
            if member.islnk(): raise ValueError('Unexpected source archive hard link: '+member.name)
            if member.issym():
                link = Path(member.linkname)
                if link.is_absolute() or '..' in link.parts:
                    raise ValueError('Unsafe source archive link: '+member.name)
            member.name = str(relative)
            contents.extract(member, destination)

def patch(path, old, new):
    text = path.read_text()
    if new in text: return
    if old not in text: raise ValueError('Patch context missing: '+str(path))
    path.write_text(text.replace(old,new))

def prepare():
    WORK.mkdir(parents=True, exist_ok=True)
    if not (VENDOR/'ios.sh').exists():
        extract(obtain('mobile-ffmpeg'), VENDOR)
        keep = set(AUDIO+['libogg','libsndfile','ffmpeg'])
        for path in (VENDOR/'src').iterdir():
            if path.is_dir() and path.name not in keep: shutil.rmtree(path)
        for name in ['android','tvos','docs','ios/test-app']:
            path = VENDOR/name
            if path.exists(): shutil.rmtree(path)
    if not (VENDOR/'src/ffmpeg/configure').exists(): extract(obtain('ffmpeg'), VENDOR/'src/ffmpeg')
    patch(VENDOR/'src/.gitignore','/ffmpeg/','!/ffmpeg/')
    gas = VENDOR/'.tmp/gas-preprocessor.pl'
    if not gas.exists(): gas.parent.mkdir(parents=True, exist_ok=True); shutil.copyfile(obtain('gas-preprocessor'),gas)
    gas.chmod(0o755)
    patch(VENDOR/'ios.sh', 'BUILD_VERSION=$(git describe --tags 2>>"${BASEDIR}/build.log")', 'BUILD_VERSION="v4.4-source-55700fb8bb5ec3e4c7be57506349838387d04364"')
    patch(VENDOR/'build/arch-common.sh', '(git ', "(git -c http.userAgent='"+USER_AGENT+"' ")
    patch(VENDOR/'build/arch-common.sh', '(curl --fail', "(curl --user-agent '"+USER_AGENT+"' --fail")
    patch(VENDOR/'build/main-ios.sh', '                env 1>>${BASEDIR}/build.log 2>&1', '                # Recovery: omit inherited environment values from build logs.')
    for source in (VENDOR/'build').glob('ios-*.sh'):
        if '--host=${BUILD_HOST}' in source.read_text():
            patch(source,'--host=${BUILD_HOST}', '--build=arm-apple-darwin --host=${BUILD_HOST}')
    patch(VENDOR/'build/ios-libsndfile.sh', 'make -j$(get_cpu_count) || exit 1', 'make SUBDIRS=src -j$(get_cpu_count) || exit 1')
    patch(VENDOR/'build/ios-libsndfile.sh', 'make install || exit 1', 'make SUBDIRS=src install || exit 1')
    patch(VENDOR/'build/ios-soxr.sh', 'cmake -Wno-dev \\\n', 'cmake -Wno-dev -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \\\n')

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prepare-only', action='store_true')
    parser.add_argument('--verify-only', action='store_true', help='Verify and copy an already finished upstream build')
    args = parser.parse_args()
    prepare()
    if args.prepare_only: return
    environment = {key:os.environ[key] for key in ['PATH','HOME','TMPDIR','DEVELOPER_DIR','LANG','LC_ALL','SHELL'] if key in os.environ}
    environment['GIT_CONFIG_COUNT']='1'; environment['GIT_CONFIG_KEY_0']='http.userAgent'; environment['GIT_CONFIG_VALUE_0']=USER_AGENT
    command = ['./ios.sh']+OPTIONS
    (WORK/'invocation.json').write_text(json.dumps({'command':command,'cwd':str(VENDOR),'source_pins':SOURCES,'user_agent':USER_AGENT},indent=2)+'\n')
    if not args.verify_only:
        result = subprocess.run(command, cwd=VENDOR, env=environment)
        if result.returncode: raise SystemExit(result.returncode)
    output = ROOT/'recovery/dependencies/ffmpeg/ios-arm64'
    output.mkdir(parents=True, exist_ok=True)
    archives = list((VENDOR/'prebuilt/ios-arm64').glob('*/lib/*.a'))
    if not any(p.name == 'libmobileffmpeg.a' for p in archives):
        raise RuntimeError('Upstream build has not produced libmobileffmpeg.a')
    for archive in archives: shutil.copy2(archive,output/archive.name)
    print('Copied',len(archives),'real static archives to',output)
    config_text = (VENDOR/'src/ffmpeg/config.h').read_text()
    config_line = next(line for line in config_text.splitlines() if line.startswith('#define FFMPEG_CONFIGURATION '))
    rebuilt_configuration = ast.literal_eval(config_line.removeprefix('#define FFMPEG_CONFIGURATION '))
    original = json.loads((ROOT/'recovery/dependencies/ffmpeg/provenance.json').read_text())['configuration_strings'][0]['value']
    switches = lambda text: {x for x in shlex.split(text) if x.startswith(('--enable-','--disable-'))}
    if switches(original) != switches(rebuilt_configuration):
        raise RuntimeError('Feature switches differ from packaged evidence')
    required_features = ['LIBMP3LAME','LIBVORBIS','LIBOPENCORE_AMRNB','LIBSHINE','LIBSPEEX','LIBWAVPACK','LIBILBC','LIBOPUS','LIBSOXR','LIBTWOLAME','LIBVO_AMRWBENC','ZLIB','AUDIOTOOLBOX','BZLIB','VIDEOTOOLBOX','ICONV']
    for feature in required_features:
        if '#define CONFIG_'+feature+' 1' not in config_text.splitlines():
            raise RuntimeError('Required packaged capability disabled: '+feature)
    sdk = subprocess.check_output(['xcrun','--sdk','iphoneos','--show-sdk-path'],text=True).strip()
    sys.path.insert(0, str(ROOT/'recovery/tools'))
    from verify_ios_sources import extract_metadata, audit
    metadata = {}
    build_date = re.search(r'-DMOBILE_FFMPEG_BUILD_DATE=(\d+)', rebuilt_configuration)[1]
    metadata_dir = WORK/'metadata'
    metadata_dir.mkdir(exist_ok=True)
    api_sources = []
    for name in ['ArchDetect','AtomicLong','FFmpegExecution','MobileFFmpeg','MobileFFmpegConfig','Statistics']:
        source = VENDOR/'ios/src'/(name+'.m')
        api_sources.append(source)
        ir = metadata_dir/(name+'.ll')
        command = ['xcrun','--sdk','iphoneos','clang','-target','arm64-apple-ios14.0','-isysroot',sdk,'-fobjc-arc',
                   '-DMOBILE_FFMPEG_ARM64','-DMOBILE_FFMPEG_LTS','-DMOBILE_FFMPEG_BUILD_DATE='+build_date,'-DIOS',
                   '-I',str(VENDOR/'ios'),'-I',str(VENDOR/'prebuilt/ios-arm64/ffmpeg/include'),'-S','-emit-llvm',str(source),'-o',str(ir)]
        compiled = subprocess.run(command,text=True,capture_output=True)
        (metadata_dir/(name+'.log')).write_text(compiled.stdout+compiled.stderr)
        compiled.check_returncode()
        metadata.update(extract_metadata(ir.read_text()))
    bundled_class_abi = audit(metadata,['ArchDetect','AtomicLong','FFmpegExecution','MobileFFmpeg','MobileFFmpegConfig','CallbackData','Statistics'])
    probe = WORK/'link-probe.m'
    probe.write_text('#import <Foundation/Foundation.h>\n#import "recovery/source/Downloads/FFMpegLibrary.h"\nint YTLFFmpegLinkProbe(void) { [MobileFFmpegConfig resetStatistics]; return [MobileFFmpeg execute:@"-version"] + RETURN_CODE_SUCCESS + RETURN_CODE_CANCEL; }\n')
    libraries = sorted(output.glob('*.a'))
    symbols = subprocess.check_output(['xcrun','nm','-gU',str(output/'libmobileffmpeg.a')],text=True)
    for library in libraries:
        arches = subprocess.check_output(['xcrun','lipo','-archs',str(library)],text=True).strip()
        if arches != 'arm64': raise RuntimeError('Unexpected archive architecture: '+str(library)+': '+arches)
    required = ['_OBJC_CLASS_$_MobileFFmpeg','_OBJC_CLASS_$_MobileFFmpegConfig','_RETURN_CODE_SUCCESS','_RETURN_CODE_CANCEL']
    found = {line.split()[-1] for line in symbols.splitlines() if line.split()}
    if not set(required).issubset(found): raise RuntimeError('Required real definitions missing: '+repr(set(required)-found))
    (WORK/'defined-mobile-symbols.txt').write_text(symbols)
    flags = ['-lc++','-lz','-lbz2','-liconv']
    frameworks = ['Foundation','CoreFoundation','CoreMedia','CoreVideo','AudioToolbox','VideoToolbox','AVFoundation','Security']
    for framework in frameworks: flags += ['-framework',framework]
    link = ['xcrun','--sdk','iphoneos','clang','-target','arm64-apple-ios14.0','-isysroot',sdk,'-dynamiclib','-fobjc-arc','-I',str(ROOT),str(probe)]+list(map(str,libraries))+flags+['-o',str(WORK/'libytlite_ffmpeg_link_probe.dylib')]
    linked = subprocess.run(link,text=True,capture_output=True)
    (WORK/'link-result.json').write_text(json.dumps({'command':link,'exit_code':linked.returncode,'output':linked.stdout+linked.stderr,'executed':False},indent=2)+'\n')
    print(linked.stdout+linked.stderr,end=''); linked.check_returncode()
    report = {'status':'built and iOS link verified','source_pins':SOURCES,'sdk':sdk,
              'binary_identity_to_original':False,'original_binary_executed':False,'probe_executed':False,'required_symbol_definitions':required,'all_archive_architectures':['arm64'],
              'archives':{str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in libraries},
              'bundled_class_abi':bundled_class_abi,
              'api_source_sha256':{str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in api_sources},
              'system_link_flags':flags,'matching_feature_switches':sorted(switches(original)),
              'verified_enabled_capabilities':required_features,'rebuilt_configuration':rebuilt_configuration}
    (ROOT/'recovery/dependencies/ffmpeg/build-report.json').write_text(json.dumps(report,indent=2)+'\n')
    print('Verified all real mobile-ffmpeg symbols link into an iOS arm64 dylib; probe was not executed.')

if __name__ == '__main__': main()
