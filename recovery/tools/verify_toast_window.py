#!/usr/bin/env python3
"""Pin packaged ToastWindow evidence and exercise actual recovered UI bodies."""
import hashlib,json,os,re,subprocess,sys
from pathlib import Path
from evidence_image import EvidenceImage,REPO

def main():
    work=REPO/'.recovery-work/toast-window';work.mkdir(parents=True,exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    source=REPO/'recovery/source/Presentation/ToastWindow.m'
    manifest=source.with_name('ToastWindow.lifecycle.evidence.json')
    provenance=source.with_name('ToastWindow.lifecycle.provenance.md')
    fixture=REPO/'recovery/tests/toast_window_fixture.m';shim=REPO/'recovery/tests/toast_window_shims'
    files=[source,source.with_suffix('.h'),source.with_name('ToastView.h'),source.with_name('PresentationHost.h'),manifest,provenance,fixture,Path(__file__).resolve(),*shim.rglob('*.h')]
    inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files}
    evidence=json.loads(manifest.read_text());im=EvidenceImage();assert im.sha256==evidence['binary_sha256']
    original=json.loads((REPO/'recovery/evidence/arm-classes.json').read_text());assert [c for c in original if c['name']=='ToastWindow']==evidence['classes']
    for item in evidence['ranges']:
        a,b=int(item['start'],16),int(item['end'],16)
        assert hashlib.sha256(im.image.data[im.image.off(a):im.image.off(b)]).hexdigest()==item['sha256']
    for collection in ['instruction_words','raw_data']:
        for address,expected in evidence[collection].items():
            offset=im.image.off(int(address,16));assert im.image.data[offset:offset+len(expected)//2].hex()==expected
    for item in evidence['branch_tables']:
        delta=(-(int.from_bytes(im.buffer(int(item['key'],16),4),'little')^int(item['xor'],16)))&0xffffffff
        if delta&0x80000000:delta-=1<<32
        assert [hex(im.image.ptr(int(item['table'],16)+i*8)+delta)for i in range(2)]==item['targets_false_true']
    for address,expected in evidence['cfstrings'].items():assert im.cfstring(int(address,16))==expected
    for address,expected in evidence['import_terminals'].items():assert im.terminal(int(address,16))==expected
    commands=[];env=dict(os.environ,UBSAN_OPTIONS='halt_on_error=1',CLANG_MODULE_CACHE_PATH=str(work/'module-cache'),TMPDIR=str(work))
    def run(args,label,red=False):
        p=subprocess.run(list(map(str,args)),cwd=REPO,env=env,capture_output=True,text=True,timeout=120)
        commands.append(dict(label=label,command=list(map(str,args)),returncode=p.returncode,output=p.stdout+p.stderr))
        (work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');(work/(label+'.log')).write_text(p.stdout+p.stderr)
        if red:assert p.returncode==1 and 'FAIL ' in p.stderr and 'runtime error:' not in p.stderr
        else:
            print(p.stdout+p.stderr,end='');p.check_returncode()
        assert 'implemented in both' not in p.stderr
        return p.stdout
    def compile(src,label):
        target=work/label
        run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter','-Wno-incomplete-implementation','-Wno-objc-property-implementation','-fsanitize=undefined','-fno-sanitize-recover=all','-I',shim,'-I',source.parent,src,fixture,'-framework','Foundation','-framework','CoreGraphics','-o',target],label+'-compile')
        return target
    output=run([compile(source,'fixture')],'runtime')
    run([sys.executable,REPO/'recovery/tools/verify_ios_sources.py','--label','toast-window','--source',source,'--classes','ToastWindow'],'ios-abi')
    text=source.read_text();action='            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"YTActionSheetDialogViewController")] ||\n'
    assert text.count(action)==2
    first=text.index(action);second=text.index(action,first+len(action))
    mutations={
        'missing-repeat':text[:second]+text[second+len(action):],
        'skip-window':text.replace('while (view) {','while (view && view != self) {'),
        'early-rejection':text.replace('UIView *view = hit;','if (!hit || hit == self || hit == self.rootViewController.view) return nil;\n    UIView *view = hit;'),
        'cached-controller':text.replace('while (view) {','while (view) {\n        UIViewController *controller = [view _viewControllerForAncestor];').replace('[[view _viewControllerForAncestor] isKindOfClass:','[controller isKindOfClass:'),
        'responds-guard':text.replace('[[view _viewControllerForAncestor] isKindOfClass:','[([view respondsToSelector:@selector(_viewControllerForAncestor)] ? [view _viewControllerForAncestor] : nil) isKindOfClass:'),
        'exclude-self':text.replace('if (window.isKeyWindow) return window;','if (window != self && window.isKeyWindow) return window;'),
        'scene-fallback':text[:text.index('- (UIWindow *)appKeyWindow')]+'''- (UIWindow *)appKeyWindow {
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class]) continue;
        for (UIWindow *window in ((UIWindowScene *)scene).windows)
            if (window != self && window.isKeyWindow) return window;
    }
    UIWindow *window = YTLPresentationAppWindow();
    return window != self && window.isKeyWindow ? window : nil;
}
@end
''',
        'initialize-self-guard':text.replace('+ (void)initialize {','+ (void)initialize {\n    if (self != ToastWindow.class) return;'),
    }
    red_results={}
    for label,mutant in mutations.items():
        assert mutant!=text;path=work/(label+'.m');path.write_text(mutant)
        result=run([compile(path,label)],label+'-red',True);red_results[label]=int(re.search(r'(\d+) failures',result)[1])
    assert inputs=={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest()for p in files},'Inputs changed during verification'
    report.write_text(json.dumps(dict(passed=True,original_sha256=im.sha256,original_methods=9,original_properties=0,original_own_ivars=0,original_ranges=len(evidence['ranges']),branch_tables=len(evidence['branch_tables']),runtime_checks=int(re.search(r'Toast window: (\d+) checks',output)[1]),red_mutations=red_results,original_executed=False,source_substitutions=[],limitations=['UIKit and private host classes are boundary doubles; supplied code is never executed.','String-decoder machinery, stack-protector scaffolding and anti-debug syscall are not reconstructed.'],inputs=inputs),indent=2)+'\n')
    print('ToastWindow original-byte, iOS ABI, runtime and eight regression mutations passed.')
if __name__=='__main__':main()
