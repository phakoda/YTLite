#!/usr/bin/env python3
"""Verify complete DVNCell accessor bodies against the first supplied package."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode=True
from compare_supplied_packages import archive_files, method_spans
from inventory import MachO
from first_model_accessor_contracts import ivars, original_contract, llvm_contract
from verify_ios_sources import extract_metadata

REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-model-accessors'


def digest(path): return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True)
    report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    package_index=REPO/'recovery/evidence/packages.json'
    package_record=next(p for p in json.loads(package_index.read_text()) if p['package']==package.name)
    assert digest(package)==package_record['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    manifest_path=REPO/'recovery/evidence/first-model-accessors-fidelity.json'
    expected=json.loads(manifest_path.read_text())
    assert hashlib.sha256(binary).hexdigest()==package_record['binary_sha256']==expected['binary_sha256']
    source=REPO/'recovery/source/Models/DVNCell.m';header=source.with_suffix('.h')
    fixture=REPO/'recovery/tests/first_model_accessors_runtime.m'
    paths=[source,header,fixture,package_index,manifest_path,source.with_suffix('.accessors.provenance.md'),Path(__file__).resolve(),
           *[REPO/'recovery/tools'/n for n in ['compare_supplied_packages.py','inventory.py','first_model_accessor_contracts.py','verify_ios_sources.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in paths}
    image=MachO(binary);classes=image.classes();cls=next(c for c in classes if c['name']=='DVNCell')
    assert expected['class_name']==cls['name']
    layout=ivars(image,cls);assert expected['ivars']==layout and expected['properties']==cls['properties']
    byivar={v['name']:v for v in layout};spans=method_spans(image,classes)
    rows=[];intervals=set()
    for prop in cls['properties']:
        name=prop['name'];attrs=prop['attributes'].split(',')
        getter=next((a[1:] for a in attrs if a.startswith('G')),name)
        setter=next((a[1:] for a in attrs if a.startswith('S')),'set'+name[0].upper()+name[1:]+':')
        field=byivar[next(a[1:] for a in attrs if a.startswith('V'))]
        methods=[m for m in cls['methods'] if m['kind']=='-' and (m['selector']==getter or ('R' not in attrs and m['selector']==setter))]
        assert len(methods)==(1 if 'R' in attrs else 2)
        for method in methods:
            span=spans['-[DVNCell '+method['selector']+']'];a,b=int(span['start'],16),int(span['end'],16)
            contract=original_contract(image,method,field,prop['attributes'],b)
            rows.append(dict(property=prop,ivar=field,method=method,contract=contract));intervals.add((a,b))
            for wrapper in contract['wrappers']:
                start=int(wrapper['address'],16);intervals.add((start,start+4*len(wrapper['words'])))
    assert rows==expected['accessors'] and len(rows)==63
    assert [r['method'] for r in rows]==expected['method_contracts']
    actual_spans=[dict(start=hex(a),end=hex(b),sha256=hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()) for a,b in sorted(intervals)]
    assert actual_spans==expected['spans'] and len(actual_spans)==75
    assert sum(len(r['contract']['omitted'])//6 for r in rows)==27
    env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    commands=[]
    def run(command,success=True):
        command=list(map(str,command));result=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append(dict(command=command,exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr))
        (WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if success and result.returncode:raise RuntimeError(result.stdout+result.stderr)
        return result
    flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def host(path,executable):
        mutant_flags=['-Wno-unused-property-ivar'] if path!=source else []
        run(['xcrun','--sdk','macosx','clang',*flags,*mutant_flags,'-framework','Foundation',path,fixture,'-o',executable])
    executable=WORK/'runtime';host(source,executable)
    result=run([executable,manifest_path]);assert result.stdout=='PASS First_model_accessors: 518 assertions, 0 failures\n'
    (WORK/'runtime.log').write_text(result.stdout)
    source_text=source.read_text();header_text=header.read_text();mutations={}
    def custom(name,property_name,body):
        injection='@implementation DVNCell\n@synthesize '+property_name+' = _'+property_name+';\n'+body+'\n'
        assert source_text.count('@implementation DVNCell')==1
        mutations[name]=(source_text.replace('@implementation DVNCell',injection),header_text)
    custom('wrong-object-getter','title','- (NSString *)title { return _subtitle; }')
    custom('wrong-readonly-getter','reuseIdentifier','- (NSString *)reuseIdentifier { return _title; }')
    custom('wrong-double-slot','minimumValue','- (void)setMinimumValue:(double)value { _maximumValue = value; }')
    custom('narrow-integer','sliderFormat','- (void)setSliderFormat:(NSInteger)value { _sliderFormat = (int)value; }')
    custom('narrow-double','dividerValue','- (void)setDividerValue:(double)value { _dividerValue = (float)value; }')
    custom('false-boolean','reloadsCell','- (void)setReloadsCell:(BOOL)value { (void)value; _reloadsCell = NO; }')
    custom('clear-before-replacement','title','- (void)setTitle:(NSString *)value { _title = nil; _title = value; }')
    custom('missing-copy','handler','- (void)setHandler:(DVNStoredBlock)value { (void)value; _handler = nil; }')
    for name,old,new in [
        ('strong-to-weak','@property(nonatomic, strong) NSString *title;','@property(nonatomic, weak) NSString *title;'),
        ('strong-to-copy','@property(nonatomic, strong) NSString *title;','@property(nonatomic, copy) NSString *title;'),
        ('weak-to-strong','@property(nonatomic, weak) UIView *sourceView;','@property(nonatomic, strong) UIView *sourceView;')]:
        assert header_text.count(old)==1;mutations[name]=(source_text,header_text.replace(old,new))
    rejected={}
    for name,(changed,changed_header) in mutations.items():
        directory=WORK/'mutants'/name;directory.mkdir(parents=True,exist_ok=True)
        mutation=directory/'DVNCell.m';mutation.write_text(changed)
        private_header=directory/'DVNCell.h';private_header.write_text(changed_header)
        mutant=directory/'runtime';host(mutation,mutant)
        result=run([mutant,manifest_path],success=False)
        assert result.returncode==1 and 'FAIL ' in result.stderr and 'failures' in result.stdout,(name,result.returncode,result.stdout,result.stderr)
        rejected[name]=dict(exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr,source_sha256=digest(mutation),header_sha256=digest(private_header),executable_sha256=digest(mutant))
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={};artifacts=[executable,WORK/'runtime.log',WORK/'commands.json']
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir])
        text=ir.read_text()
        emitted=extract_metadata('\n'.join(line for line in text.splitlines() if 'section "llvm.ptrauth"' not in line))['DVNCell']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in cls['methods']}
        assert emitted['properties']=={p['name']:p['attributes'] for p in cls['properties']}
        assert emitted['ivars']==layout
        normalized={}
        for row in rows:
            sel=row['method']['selector'];normalized[sel]=llvm_contract(text,'DVNCell',sel,row['contract'])
            # The matcher must reject an extra side effect in every complete body.
            definition=next(line for line in text.splitlines() if line.startswith('define internal ') and f'-[DVNCell {sel}]' in line)
            altered=text.replace(definition,definition+'\n  call void @unexpected_effect()')
            try:llvm_contract(altered,'DVNCell',sel,row['contract'])
            except AssertionError:pass
            else:raise AssertionError(('Unrecognized extra effect accepted',arch,sel))
        normalized_path=WORK/(arch+'-accessors.json');normalized_path.write_text(json.dumps(normalized,indent=2)+'\n')
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj])
        metadata[arch]=dict(methods=83,properties=32,ivars=32,complete_accessor_bodies=63,extra_effects_rejected=63,ir_sha256=digest(ir),object_sha256=digest(obj))
        artifacts.extend([ir,obj,normalized_path])
    for name,value in inputs.items():assert digest(REPO/name)==value,('Input changed during verification',name)
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps(dict(passed=True,first_package_sha256=package_record['sha256'],first_binary_sha256=expected['binary_sha256'],runtime_assertions=518,
        negative_checks=rejected,metadata=metadata,inputs=inputs,original_binary_executed=False,
        scope='All 63 DVNCell getters/setters: complete original body patterns, runtime helpers, exact slots, ownership and scalar storage',
        limits=['Twenty-seven original system traps are omitted and pinned separately.','Initialization, destruction, eighteen factories, callback invocation and device behavior are outside this accessor audit.','Runtime tests execute reconstructed code on macOS arm64; both iOS architectures have compiled body and metadata checks.','Strong assignment is checked at ARC ownership boundaries; compiler/runtime retain-call optimizations are not claimed identical.']),indent=2)+'\n')
    print('First-package DVNCell accessors: 518 assertions, eleven regressions rejected, all 63 bodies checked on both iOS architectures.')


if __name__=='__main__':main()
