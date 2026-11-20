#!/usr/bin/env python3
"""Audit every assigned registration and execute the actual generated PlayerBars hooks."""
from logos_tool import logos_path
import collections,hashlib,json,re,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
NAMES='YTInlinePlayerBarContainerView YTPlayerBarRectangleDecorationView YTPlayerBarProgressDecorationView YTPlayerBarScrubberDotDecorationView YTPlayerBarScrubberDotDecorationViewV1 YTModularPlayerBarView YTProgressView YTInlineMutedPlaybackScrubberView YTInlineMutedPlaybackScrubbingSlider'.split()
GROUPS={'0001efd4':'YTLPlayerBarsSponsor','00053fac':'YTLPlayerBarsAppearance'}
def registrations():
    return [h for h in json.loads((REPO/'recovery/evidence/hooks.json').read_text()) if h['class_name'] in NAMES]
def identity(h):
    return GROUPS[h['registration']],h['class_name'],h['kind'],h['selector'],h['operation']
def source_registrations(text):
    group=target=None
    found=[]
    for line in text.splitlines():
        line=line.strip()
        if line.startswith('%group '):group=line.split()[1]
        elif line.startswith('%hook '):target=line.split()[1]
        elif line=='%end':
            if target:target=None
            else:group=None
        elif line.startswith('%property '):
            match=re.search(r'(\w+);$',line)
            if not match or not group or not target:raise ValueError('Unrecognized property: '+line)
            name=match[1]
            found.extend([(group,target,'-',name,'add'),(group,target,'-','set'+name[0].upper()+name[1:]+':','add')])
        elif re.match(r'^[+-]\s*\(',line):
            if not group or not target:raise ValueError('Hook method outside group: '+line)
            words=re.findall(r'(\w+)\s*:',line)
            selector=''.join(w+':' for w in words) if words else re.search(r'\)\s*(\w+)\s*\{',line)[1]
            found.append((group,target,line[0],selector,'replace'))
    return found

def main():
    work=REPO/'.recovery-work/playerbar-hooks';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Hooks/PlayerBars.x'
    manifest=json.loads((source.parent/'PlayerBars.manifest.json').read_text())
    records=registrations()
    if records!=manifest['registrations']:raise ValueError('Registration manifest differs from authoritative hook inventory')
    expected=collections.Counter(map(identity,records));actual=collections.Counter(source_registrations(source.read_text()))
    if expected!=actual:raise ValueError(f'Registrations mismatch: missing {expected-actual}; extra {actual-expected}')
    image=EvidenceImage()
    if manifest['binary_sha256']!=image.sha256:raise ValueError('Binary differs from manifest')
    for span in manifest['instruction_intervals']:
        a,b=int(span['start'],16),int(span['end'],16)
        data=image.image.data[image.image.off(a):image.image.off(b)]
        if hashlib.sha256(data).hexdigest()!=span['sha256']:raise ValueError('Original bytes differ: '+str(span))
    for string in manifest['decoded_strings']:
        if image.cstring(int(string['address'],16))!=string['value']:raise ValueError('Decoded string differs: '+str(string))
    commands=[]
    def run(args):
        result=subprocess.run(list(map(str,args)),cwd=REPO,text=True,capture_output=True,timeout=120)
        commands.append({'command':list(map(str,args)),'exit_code':result.returncode,'output':result.stdout+result.stderr})
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode:print(result.stdout+result.stderr,end='')
        result.check_returncode()
        return result.stdout
    logos=Path(logos_path())
    mm=work/'PlayerBars.mm';mm.write_text(run(['perl',logos,'-c','generator=internal',source]))
    generated=set(re.findall(r'_logos_(?:method|property)\$(YTLPlayerBars\w+)\$(\w+)\$([\w$]+)\s*\(',mm.read_text()))
    expected_generated={(group,cls,(selector.rstrip(':') if op=='add' else selector.replace(':','$'))) for group,cls,kind,selector,op in expected}
    if generated!=expected_generated:raise ValueError('Generated hook callback coverage differs')
    llvm=work/'PlayerBars-ios.ll'
    run(['xcrun','--sdk','iphoneos','clang++','-fobjc-arc','-fblocks','-target','arm64-apple-ios13.0','-I',source.parent,'-S','-emit-llvm','-o',llvm,mm])
    # Unlike runtime headers, LLVM verifies concrete emitted function argument widths.
    definitions={m[1]:m[2] for m in re.finditer(r'^define internal [^\n]+ @"([^"\n]*_logos_(?:method|property)\$[^"\n]+)"\(([^\n]+)\)',llvm.read_text(),re.M)}
    if len(definitions)!=33:raise ValueError('Expected 33 emitted hook bodies')
    for name,args in definitions.items():
        if any(x in name for x in ('$applyGradientColorForRect$','$applyGradientForRect$','$drawProgressRect$','$setFrame$')) and '[4 x double]' not in args:
            raise ValueError('CGRect ABI changed: '+name)
        if any(x in name for x in ('$setPlayerBarAlpha$','$setProgress$','$setMediaTime$')) and 'double' not in args:
            raise ValueError('Full-width scalar forwarding changed: '+name)
        if '$setPeekableViewVisible$' in name and 'i1 noundef zeroext' not in args:
            raise ValueError('BOOL input ABI changed: '+name)
    executable=work/'runtime'
    run(['xcrun','clang++','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-Wno-vla-cxx-extension','-Wno-unguarded-availability-new','-fsanitize=undefined','-fno-sanitize-recover=all','-I',REPO/'recovery/tests/playerbar_hooks_shims','-I',source.parent,mm,REPO/'recovery/tests/playerbar_hooks_runtime.mm','-framework','Foundation','-framework','CoreGraphics','-framework','QuartzCore','-o',executable])
    run([executable])
    print(commands[-1]['output'],end='')
    inputs=[source,source.parent/'PlayerBarsHost.h',REPO/'recovery/tests/playerbar_hooks_runtime.mm',Path(__file__).resolve()]+list((REPO/'recovery/tests/playerbar_hooks_shims').rglob('*.h'))
    result={'registration_count':len(records),'registration_sites':dict(collections.Counter(h['registration'] for h in records)),
        'original_byte_manifest':'passed','generated_callback_coverage':'passed','ios_compile_and_llvm_widths':'passed','real_logos_runtime':'passed','ubsan':'passed',
        'limitations':manifest['limitations'],'original_binary_executed':False,
        'source_sha256':{str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs},'llvm_hook_signatures':definitions}
    report.write_text(json.dumps(result,indent=2)+'\n')
    print(f'{len(records)} exact registrations, original instruction intervals, decoded strings and iOS compilation verified.')
if __name__=='__main__':main()
