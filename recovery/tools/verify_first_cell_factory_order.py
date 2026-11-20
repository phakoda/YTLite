#!/usr/bin/env python3
"""Check first-package DVNCell factory setter order; not a complete factory audit."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode=True
from inventory import MachO
from compare_supplied_packages import archive_files,method_spans
from first_model_accessor_contracts import target,runtime_symbol
from verify_selector_loads import verify_selector_loads
REPO=Path(__file__).resolve().parents[2]
WORK=REPO/'.recovery-work/first-cell-factory-order'


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    WORK.mkdir(parents=True,exist_ok=True);report_path=WORK/'report.json';report_path.unlink(missing_ok=True)
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    packages=REPO/'recovery/evidence/packages.json';record=next(r for r in json.loads(packages.read_text()) if r['package']==package.name)
    assert digest(package)==record['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    evidence=REPO/'recovery/evidence/first-cell-factory-order.json';expected=json.loads(evidence.read_text())
    assert hashlib.sha256(binary).hexdigest()==record['binary_sha256']==expected['binary_sha256']
    image=MachO(binary);classes=image.classes();cls=next(c for c in classes if c['name']=='DVNCell');spans=method_spans(image,classes)
    original_methods=[m for m in cls['methods'] if m['kind']=='+'];assert [r['method'] for r in expected['factories']]==original_methods and len(original_methods)==18
    for span in expected['spans']:
        a,b=int(span['start'],16),int(span['end'],16)
        assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
    verify_selector_loads(image,expected)
    assert expected['selectors']==[s for row in expected['factories'] for s in row['selectors']]
    for row in expected['factories']:
        method=row['method'];span=spans['+[DVNCell '+method['selector']+']'];a,z=int(span['start'],16),int(span['end'],16)
        assert any(int(s['start'],16)==a and int(s['end'],16)==z for s in expected['spans'])
        # Independently enumerate all selector loads, rejecting control transfers
        # that would invalidate the reviewed straight-line setter sequence.
        selectors=[]
        for p in range(a,z,4):
            word=image.u32(image.off(p))
            assert word&0xff000010!=0x54000000 and word&0x7e000000 not in (0x34000000,0x36000000)
            assert word&0xfffffc1f not in (0xd61f0000,0xd63f0000)
            if word&0xfc000000==0x14000000:assert p==z-4
            if p+4>=z:continue
            adrp,ldr=word,image.u32(image.off(p+4))
            if adrp&0x9f000000!=0x90000000 or ldr&0xffc0001f!=0xf9400001 or adrp&31!=(ldr>>5)&31:continue
            delta=((adrp>>5)&0x7ffff)*4+((adrp>>29)&3)
            if delta&(1<<20):delta-=1<<21
            reference=(p&~0xfff)+(delta<<12)+((ldr>>10)&0xfff)*8
            name=image.string(image.ptr(reference));selectors.append((p,name))
        if row['selectors']:
            assert selectors==[(int(s['page_instruction'],16),s['name']) for s in row['selectors']]
            for item in row['selectors']:
                call=int(item['call'],16);assert int(item['load_instruction'],16)<call<z
                assert image.u32(image.off(call))&0xfc000000==0x94000000
                destination=target(call,image.u32(image.off(call)));assert destination==int(item['target'],16)
                wrappers={};assert runtime_symbol(image,destination,wrappers)=='_objc_msgSend'
                for address,words in wrappers.items():
                    assert any(int(s['start'],16)==address and int(s['end'],16)==address+len(words)*4 for s in expected['spans'])
        else:
            assert method['selector']=='sliderCellWithMinimum:maximum:divider:key:' and z-a==20
            assert selectors==[(a+4,'sliderCellWithMinimum:maximum:divider:format:key:')]
            assert image.u32(image.off(a))==0xaa0203e3 and image.u32(image.off(a+12))==0xd2800002
            wrappers={};assert runtime_symbol(image,target(a+16,image.u32(image.off(a+16))),wrappers)=='_objc_msgSend'
    source=REPO/'recovery/source/Models/DVNCell.m';header=source.with_suffix('.h');fixture=REPO/'recovery/tests/first_cell_factory_order_runtime.m'
    paths=[source,header,fixture,source.with_suffix('.factory-order.provenance.md'),packages,evidence,Path(__file__).resolve(),
           *[REPO/'recovery/tools'/n for n in ['inventory.py','compare_supplied_packages.py','first_model_accessor_contracts.py','verify_selector_loads.py']]]
    inputs={str(p.relative_to(REPO)):digest(p) for p in paths};env=os.environ.copy()
    for key,name in [('TMPDIR','tmp'),('CLANG_MODULE_CACHE_PATH','cache'),('CFFIXED_USER_HOME','preferences')]:
        directory=WORK/name;directory.mkdir(exist_ok=True);env[key]=str(directory)
    commands=[]
    def run(command,success=True):
        command=list(map(str,command));r=subprocess.run(command,cwd=REPO,env=env,capture_output=True,text=True,timeout=90)
        commands.append(dict(command=command,exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr));(WORK/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if success and r.returncode:raise RuntimeError(r.stdout+r.stderr)
        return r
    def host(path,output):run(['xcrun','--sdk','macosx','clang','-O2','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-I',source.parent,'-framework','Foundation',path,fixture,'-o',output])
    executable=WORK/'runtime';host(source,executable);r=run([executable,evidence]);assert r.stdout=='PASS First_cell_factory_order: 144 assertions, 0 failures\n';(WORK/'runtime.log').write_text(r.stdout)
    text=source.read_text();mutations={}
    # Each old order is restored separately; both index factories share one edit.
    for number in [2,6,10,7,9]:
        old=f'cell.type = {number}; cell.key = key;';assert text.count(old)==(2 if number==2 else 1)
        mutations['key-before-type-'+str(number)]=text.replace(old,f'cell.key = key; cell.type = {number};')
    old='cell.title = title; cell.subtitle = subtitle; cell.image = image; cell.renderingMode = 1;\n    cell.accessoryIcon = accessoryIcon; cell.type = type; cell.selfHandler = handler;'
    assert text.count(old)==1
    mutations['late-rendering-mode']=text.replace(old,'cell.title = title; cell.subtitle = subtitle; cell.image = image; cell.accessoryIcon = accessoryIcon;\n    cell.type = type; cell.renderingMode = 1; cell.selfHandler = handler;')
    mutations['dynamic-construction']=text.replace('[[DVNCell alloc] init]','[[self alloc] init]')
    rejected={}
    for name,changed in mutations.items():
        path=WORK/(name+'.m');path.write_text(changed);output=WORK/(name+'-runtime');host(path,output);r=run([output,evidence],success=False)
        assert r.returncode==1 and 'FAIL ' in r.stderr and 'failures' in r.stdout
        rejected[name]=dict(stdout=r.stdout,stderr=r.stderr,source_sha256=digest(path),executable_sha256=digest(output))
    for path,value in inputs.items():assert digest(REPO/path)==value
    inputs.update({str(p.relative_to(REPO)):digest(p) for p in [executable,WORK/'runtime.log',WORK/'commands.json']})
    report_path.write_text(json.dumps(dict(passed=True,first_package_sha256=record['sha256'],first_binary_sha256=record['binary_sha256'],runtime_assertions=144,negative_checks=rejected,inputs=inputs,original_binary_executed=False,
        scope='Setter dispatch order across all eighteen DVNCell factory entry points and concrete result class for ordinary and nil inputs',
        limits=['This focused order check does not audit all factory argument values, ownership timing, nil/replacement initializer results or initializer/destructor behavior.','A forwarding factory is checked through its concrete implementation; arbitrary subclass overrides need separate tests.','The original binary remains static data; no device behavior is established.']),indent=2)+'\n')
    print('First-package cell factory order: 144 assertions, seven regressions rejected; seven source sequences corrected.')


if __name__=='__main__':main()
