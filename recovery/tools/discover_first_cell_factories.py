#!/usr/bin/env python3
"""Save original factory data flow for the pending compiled-source audit."""
import hashlib
import json
from pathlib import Path
from inventory import MachO
from compare_supplied_packages import archive_files,method_spans
from first_cell_factory_contracts import trace_factory
REPO=Path(__file__).resolve().parents[2]


def main():
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest=next(p for p in json.loads((REPO/'recovery/evidence/packages.json').read_text()) if p['package']==package.name)
    assert hashlib.sha256(package.read_bytes()).hexdigest()==manifest['sha256']
    binary=next(b for n,b in archive_files(package,'data.tar').items() if n.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']
    image=MachO(binary);classes=image.classes();cls=next(c for c in classes if c['name']=='DVNCell');spans=method_spans(image,classes)
    property_types={}
    for prop in cls['properties']:
        attrs=prop['attributes'].split(',')
        if 'R' not in attrs:property_types['set'+prop['name'][0].upper()+prop['name'][1:]+':']=attrs[0][1:]
    rows=[]
    for method in cls['methods']:
        if method['kind']!='+':continue
        span=spans['+[DVNCell '+method['selector']+']']
        contract=trace_factory(image,method,int(span['end'],16),int(cls['address'],16),property_types)
        rows.append(dict(method=method,span=span,contract=contract))
    assert len(rows)==18
    output=REPO/'.recovery-work/first-cell-factories/candidates.json';output.parent.mkdir(parents=True,exist_ok=True)
    paths=[Path(__file__).resolve(),REPO/'recovery/tools/first_cell_factory_contracts.py',REPO/'recovery/tools/first_model_accessor_contracts.py',REPO/'recovery/tools/inventory.py',REPO/'recovery/tools/compare_supplied_packages.py',REPO/'recovery/evidence/packages.json']
    output.write_text(json.dumps(dict(first_package_sha256=manifest['sha256'],first_binary_sha256=manifest['binary_sha256'],factories=rows,
        inputs={str(p.relative_to(REPO)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
        scope='Original-only factory argument and retain/release discovery; compiled-source runtime comparison pending',original_binary_executed=False),indent=2)+'\n')
    print('Traced all instructions in eighteen original DVNCell factories. Saved argument, setter and retain/release events; compiled-source comparison remains pending.')


if __name__=='__main__':main()
