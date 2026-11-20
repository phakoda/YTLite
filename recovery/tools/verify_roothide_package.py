#!/usr/bin/env python3
"""Check the rebuilt roothide archive as data; never install or load its dylib."""
import hashlib
import io
import json
from pathlib import Path
import plistlib
import struct
import subprocess
import tarfile
from compare_supplied_packages import archive_files, dependencies, LIBRARY_CLASSES
from inventory import MachO

REPO=Path(__file__).resolve().parents[2]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def fields(data):
    return dict(line.split(': ',1) for line in data.decode().splitlines() if ': ' in line)


def plist(data):
    result=subprocess.run(['plutil','-convert','json','-o','-','--','-'],
        input=data,capture_output=True,check=True,timeout=30)
    return json.loads(result.stdout)


def sections(image):
    return {row['segment']+','+row['name']:{'address':row['address'],'size':row['size'],
        'sha256':sha(image.data[row['offset']:row['offset']+row['size']])}
        for row in image.section_records if not row['zerofill']}


def archive_permissions(package, prefix):
    members=subprocess.check_output(['ar','-t',str(package)],text=True).splitlines()
    member=next(name for name in members if name.startswith(prefix))
    data=subprocess.check_output(['ar','-p',str(package),member])
    with tarfile.open(fileobj=io.BytesIO(data),mode='r:*') as archive:
        result={}
        for entry in archive:
            assert entry.isdir() or entry.isfile(),('Unexpected archive member type',entry.name)
            mode=0o755 if entry.isdir() or entry.name.endswith('.dylib') else 0o644
            assert entry.mode==mode,('Incorrect archive permissions',entry.name,oct(entry.mode))
            result[entry.name.removeprefix('./')]={'mode':oct(entry.mode),'uid':entry.uid,'gid':entry.gid}
        return result


def main():
    work=REPO/'.recovery-work/roothide-package';work.mkdir(exist_ok=True)
    report=work/'report.json';report.unlink(missing_ok=True)
    build_path=REPO/'.recovery-work/build-roothide/latest-build.json'
    build=json.loads(build_path.read_text())
    assert build['status']=='passed' and build['scheme']=='roothide' and 'package' in build
    inputs=dict(build['input_sha256'])
    for name,digest in inputs.items():assert sha((REPO/name).read_bytes())==digest,('Stale build input',name)
    package=REPO/build['package'];artifact=REPO/build['artifact']
    assert sha(package.read_bytes())==build['package_sha256']
    assert sha(artifact.read_bytes())==build['artifact_sha256']
    permissions={prefix:archive_permissions(package,prefix) for prefix in ['control.tar','data.tar']}
    original=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    inventory_path=REPO/'recovery/evidence/packages.json'
    manifest=next(x for x in json.loads(inventory_path.read_text()) if x['package']==original.name)
    assert sha(original.read_bytes())==manifest['sha256']
    old=archive_files(original,'data.tar');new=archive_files(package,'data.tar')
    assert old.keys()==new.keys() and len(new)==18,'Archive layout differs from first supplied package'
    binary_name='Library/MobileSubstrate/DynamicLibraries/YTLite.dylib'
    assert sha(old[binary_name])==manifest['binary_sha256']
    old_image=MachO(old[binary_name]);new_image=MachO(new[binary_name]);built_image=MachO(artifact.read_bytes())
    cpu=lambda data:struct.unpack_from('<II',data,4)
    assert cpu(new_image.data)==cpu(old_image.data)==(0x100000c,0)
    # Packaging strips/signs the aggregate artifact again. Its section contents
    # and addresses must still be those of the successful compiled binary.
    assert sections(new_image)==sections(built_image)
    wanted={'@loader_path/.jbroot/usr/lib/libroothide.dylib',
            '@loader_path/.jbroot/usr/lib/libsubstrate.dylib'}
    old_dependencies={x['name'] for x in dependencies(old_image.data)}
    new_dependencies={x['name'] for x in dependencies(new_image.data)}
    assert wanted <= old_dependencies and wanted <= new_dependencies
    assert not any('CydiaSubstrate.framework' in x or x.startswith('/var/jb') for x in new_dependencies)
    assert {'__Z6jbrootP8NSString','_MSHookMessageEx'} <= set(new_image.imports)
    payload=work/'packaged.dylib';payload.write_bytes(new_image.data)
    undefined=subprocess.run(['xcrun','nm','-m','-u',str(payload)],capture_output=True,text=True,check=True,timeout=30).stdout
    bindings={}
    for symbol,library in [('__Z6jbrootP8NSString','libroothide'),('_MSHookMessageEx','libsubstrate')]:
        rows=[row.strip() for row in undefined.splitlines() if symbol+' ' in row]
        assert len(rows)==1 and '(from '+library+')' in rows[0]
        bindings[symbol]=rows[0]
    control=fields(archive_files(package,'control.tar')['control'])
    old_control=fields(archive_files(original,'control.tar')['control'])
    for key in ['Package','Name','Architecture','Depends']:assert control[key]==old_control[key],key
    assert control['Version'].startswith('5.2.2-local.'),'Reconstruction must retain its local version label'
    filter_name=binary_name.replace('.dylib','.plist')
    assert plistlib.loads(new[filter_name])==plistlib.loads(old[filter_name])==plistlib.loads((REPO/'YTLite.plist').read_bytes())
    resources={};differences={}
    for name,data in new.items():
        if 'YTLite.bundle/' not in name:continue
        source=(REPO/'layout'/name).read_bytes()
        if name.endswith(('.strings','.plist')):
            current,packaged,previous=map(plist,[source,data,old[name]])
            assert current==packaged,('Packaged resource differs from source',name)
            if previous!=packaged:
                differences[name]={'added':sorted(packaged.keys()-previous.keys()),
                    'removed':sorted(previous.keys()-packaged.keys()),
                    'changed':sorted(k for k in packaged.keys()&previous.keys() if packaged[k]!=previous[k])}
        else:assert data==source==old[name],('Resource bytes differ',name)
        resources[name]=sha(data)
    expected_classes={c['name']:c for c in old_image.classes() if c['name'] not in LIBRARY_CLASSES}
    actual_classes={c['name']:c for c in new_image.classes()}
    for name,row in expected_classes.items():
        expected={(m['kind'],m['selector']):m['encoding'] for m in row['methods']}
        actual={(m['kind'],m['selector']):m['encoding'] for m in actual_classes[name]['methods']}
        assert expected==actual,('First-package class encodings differ',name)
    for p in [build_path,package,artifact,inventory_path,Path(__file__).resolve(),
              REPO/'recovery/tools/compare_supplied_packages.py',REPO/'recovery/tools/inventory.py']:
        inputs[str(p.relative_to(REPO))]=sha(p.read_bytes())
    report.write_text(json.dumps({'passed':True,'inputs':inputs,'package':build['package'],
        'package_sha256':build['package_sha256'],'packaged_binary_sha256':sha(new_image.data),
        'first_package_sha256':manifest['sha256'],'archive_paths_equal':True,'regular_files':len(new),
        'archive_permissions':permissions,
        'runtime_sections_equal_to_built_artifact':True,'external_bindings':bindings,
        'control':control,'resources':resources,'preserved_locale_differences':differences,
        'first_party_classes_with_equal_encodings':len(expected_classes),
        'extra_classes':sorted(actual_classes.keys()-{c['name'] for c in old_image.classes()}),
        'original_binary_executed':False,'installed':False,'device_validation':'not performed',
        'limits':['This proves the archive layout, selected external bindings, resource packaging and class encodings only.',
                  'Reconstructed behavior, rebuilt codec library and preserved local locale changes still prevent a full parity claim.']},indent=2)+'\n')
    print(f'Roothide archive verified: {len(new)} paths, {len(expected_classes)} class contracts, both external runtime bindings.')
    print(f'Preserved locale differences in {len(differences)} files; no device execution.')
    print('Verified archive modes: directories/dylib 0755, resources/control 0644.')


if __name__=='__main__':main()
