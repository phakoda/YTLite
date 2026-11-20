#!/usr/bin/env python3
"""Compare all eighteen original DVNCell factories with actual compiled source."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode=True
from inventory import MachO
from compare_supplied_packages import archive_files,method_spans
from first_model_accessor_contracts import ivars
from first_cell_factory_contracts import trace_factory
from first_cell_factory_llvm import verify_factory_llvm
from verify_ios_sources import extract_metadata
REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-cell-factories'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    package_index=REPO/'recovery/evidence/packages.json';record=next(p for p in json.loads(package_index.read_text()) if p['package']==package.name)
    assert digest(package)==record['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence=REPO/'recovery/evidence/first-cell-factories-fidelity.json';expected=json.loads(evidence.read_text())
    assert hashlib.sha256(binary).hexdigest()==record['binary_sha256']==expected['binary_sha256']
    image=MachO(binary);classes=image.classes();cls=next(c for c in classes if c['name']=='DVNCell');spans=method_spans(image,classes)
    property_types={}
    for prop in cls['properties']:
        attrs=prop['attributes'].split(',')
        if 'R' not in attrs:property_types['set'+prop['name'][0].upper()+prop['name'][1:]+':']=attrs[0][1:]
    rows=[];intervals=set()
    for method in cls['methods']:
        if method['kind']!='+':continue
        span=spans['+[DVNCell '+method['selector']+']'];a,z=int(span['start'],16),int(span['end'],16)
        contract=trace_factory(image,method,z,int(cls['address'],16),property_types)
        rows.append(dict(method=method,span=span,contract=contract));intervals.add((a,z))
        for wrapper in contract['wrappers']:
            a=int(wrapper['address'],16);intervals.add((a,a+len(wrapper['words'])*4))
    # JSON normalization only converts tuples to arrays; every event and address
    # still must equal the separately saved original contract.
    assert json.loads(json.dumps(rows))==expected['factories'] and len(rows)==18
    assert [r['method'] for r in rows]==expected['method_contracts']
    checked_spans=[dict(start=hex(a),end=hex(z),sha256=hashlib.sha256(binary[image.off(a):image.off(a)+z-a]).hexdigest()) for a,z in sorted(intervals)]
    assert checked_spans==expected['spans']
    source=REPO/'recovery/source/Models/DVNCell.m';fixture=REPO/'recovery/tests/first_cell_factories_runtime.m'
    paths=[source,source.with_suffix('.h'),fixture,source.with_suffix('.factories.provenance.md'),package_index,evidence,Path(__file__).resolve(),
           *[REPO/'recovery/tools'/n for n in ['inventory.py','compare_supplied_packages.py','first_model_accessor_contracts.py','first_cell_factory_contracts.py','first_cell_factory_llvm.py','verify_ios_sources.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in paths};commands=[];env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    def run(command,success=True):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,text=True,capture_output=True,timeout=90)
        commands.append(dict(command=command,exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr));(WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if success and r.returncode:raise RuntimeError(r.stdout+r.stderr)
        return r
    flags=['-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror']
    def host(path,output):run(['xcrun','--sdk','macosx','clang',*flags,'-I',source.parent,'-framework','Foundation',path,fixture,'-o',output])
    executable=WORK/'runtime';host(source,executable);r=run([executable,evidence]);assert r.stdout=='PASS First_cell_factories: 1408 assertions, 0 failures\n';(WORK/'runtime.log').write_text(r.stdout)
    current=source.read_text();mutations={}
    def change(name,old,new,count=1):assert current.count(old)==count,(name,current.count(old));mutations[name]=current.replace(old,new)
    change('wrong-controller-type','cell.type = 4;','cell.type = 8;')
    change('wrong-controller-title','cell.controllerModel = model; cell.title = title;','cell.controllerModel = model; cell.title = subtitle;')
    change('narrow-type','cell.type = type;','cell.type = (int)type;',6)
    change('narrow-double','cell.minimumValue = minimum;','cell.minimumValue = (float)minimum;',3)
    change('wrong-handler','cell.handler = handler; cell.type = 5;','cell.selfHandler = handler; cell.type = 5;')
    change('wrong-image-field','cell.image = image;','cell.icon = image;')
    change('dynamic-construction','[[DVNCell alloc] init]','[[self alloc] init]',17)
    change('no-initialization','[[DVNCell alloc] init]','[DVNCell alloc]',17)
    change('discard-result','return cell;','return nil;',17)
    change('forward-concrete-class','return [self sliderCellWithMinimum:','return [DVNCell sliderCellWithMinimum:')
    change('forward-wrong-format','divider:divider format:0 key:key','divider:divider format:1 key:key')
    change('forward-wrong-double','return [self sliderCellWithMinimum:minimum','return [self sliderCellWithMinimum:maximum')
    change('late-controller-model','cell.controllerModel = model; cell.title = title; cell.subtitle = subtitle;','cell.title = title; cell.subtitle = subtitle; cell.controllerModel = model;')
    rejected={}
    for name,text in mutations.items():
        path=WORK/(name+'.m');path.write_text(text);output=WORK/(name+'-runtime');host(path,output);r=run([output,evidence],success=False)
        assert r.returncode==1 and 'FAIL ' in r.stderr and 'failures' in r.stdout,(name,r.returncode,r.stdout,r.stderr)
        rejected[name]=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr,source_sha256=digest(path),executable_sha256=digest(output))
    sdk=run(['xcrun','--sdk','iphoneos','--show-sdk-path']).stdout.strip();metadata={};artifacts=[executable,WORK/'runtime.log',WORK/'commands.json']
    for arch in ['arm64','arm64e']:
        ir=WORK/(arch+'.ll');obj=WORK/(arch+'.o');target=arch+'-apple-ios14.0'
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target',target,'-isysroot',sdk,'-S','-emit-llvm',source,'-o',ir]);text=ir.read_text();normalized={}
        for row in rows:
            method=row['method'];normalized[method['selector']]=verify_factory_llvm(text,method,row['contract'])
            definition=next(l for l in text.splitlines() if l.startswith('define internal ') and '+[DVNCell '+method['selector']+']' in l)
            altered=text.replace(definition,definition+'\n  call void @unexpected_effect()')
            try:verify_factory_llvm(altered,method,row['contract'])
            except AssertionError:pass
            else:raise AssertionError(('Extra effect accepted',arch,method['selector']))
        emitted=extract_metadata('\n'.join(l for l in text.splitlines() if 'section "llvm.ptrauth"' not in l))['DVNCell']
        assert emitted['methods']=={m['kind']+m['selector']:m['encoding'] for m in cls['methods']}
        assert emitted['properties']=={p['name']:p['attributes'] for p in cls['properties']} and emitted['ivars']==ivars(image,cls)
        normalized_path=WORK/(arch+'-factory-bodies.json');normalized_path.write_text(json.dumps(normalized,indent=2)+'\n')
        run(['xcrun','--sdk','iphoneos','clang','-O2','-target',target,'-isysroot',sdk,'-c',ir,'-o',obj]);artifacts.extend([ir,obj,normalized_path])
        metadata[arch]=dict(methods=83,properties=32,ivars=32,complete_factory_bodies=18,extra_effects_rejected=18,ir_sha256=digest(ir),object_sha256=digest(obj))
    for path,value in inputs.items():assert digest(REPO/path)==value
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in artifacts})
    report_path.write_text(json.dumps(dict(passed=True,first_package_sha256=record['sha256'],first_binary_sha256=record['binary_sha256'],runtime_assertions=1408,negative_checks=rejected,metadata=metadata,inputs=inputs,original_binary_executed=False,
        scope='All eighteen DVNCell factory bodies: argument data flow, constants, retain/release order, concrete construction, nil/replacement results and subclass forwarding',
        limits=['Runtime checks substitute the initializer and setter receiver; real initialization, storage and destruction have separate focused reports.','Numeric patterns and synthetic object/block identities cover the reviewed ABI; callback blocks are never invoked.','Host runtime checks and cross-compiled body equivalence do not establish live-device behavior.']),indent=2)+'\n')
    print('First-package cell factories: 1408 assertions, thirteen regressions rejected, eighteen complete bodies checked on both iOS architectures.')


if __name__=='__main__':main()
