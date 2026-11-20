#!/usr/bin/env python3
"""Reproduce recovery from the three local packages. No network or dylib execution."""
import argparse
from collections import Counter
import hashlib
import io
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
from inventory import MachO


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--packages',type=Path,required=True,help='Directory containing the supplied .deb files')
    parser.add_argument('--work',type=Path,required=True,help='Separate directory for binaries, assembly and Ghidra project')
    parser.add_argument('--output',type=Path,default=Path(__file__).resolve().parents[1])
    parser.add_argument('--decompile',action='store_true',help='Run Ghidra after metadata and string recovery')
    parser.add_argument('--ghidra',type=Path,help='Ghidra libexec directory containing support/analyzeHeadless')
    a=parser.parse_args();a.packages=a.packages.resolve();a.output=a.output.resolve();a.work=a.work.resolve();a.work.mkdir(parents=True,exist_ok=True)
    scripts=Path(__file__).resolve().parent
    packages=[a.packages/f'com.dvntm.ytlite_5.2.2_iphoneos-{tag}.deb' for tag in ['arm','arm64','arm64e']]
    for p in packages:
        if not p.is_file():raise FileNotFoundError(p)
    def run(args,log=None):
        if log:
            with log.open('w') as stream:subprocess.run(list(map(str,args)),check=True,stdout=stream,stderr=subprocess.STDOUT,cwd=a.work)
            if 'REPORT SCRIPT ERROR' in log.read_text():raise RuntimeError('Ghidra script failed; see '+str(log))
        else:subprocess.run(list(map(str,args)),check=True)
    run([sys.executable,scripts/'inventory.py',*packages,'--output',a.output/'evidence'])
    variants={};paths={};class_tables={}
    for tag,p in zip(['arm','arm64','arm64e'],packages):
        directory=a.work/tag;directory.mkdir(exist_ok=True)
        member=next(x for x in subprocess.check_output(['ar','-t',str(p)],text=True).splitlines() if x.startswith('data.tar'))
        archive=subprocess.check_output(['ar','-p',str(p),member])
        with tarfile.open(fileobj=io.BytesIO(archive),mode='r:*') as tf:
            binary_member=next(x for x in tf if x.isfile() and x.name.endswith('/YTLite.dylib'))
            data=tf.extractfile(binary_member).read()
        binary=directory/'YTLite.dylib';binary.write_bytes(data);paths[tag]=binary
        assembly=directory/'application.asm'
        run(['xcrun','llvm-objdump','--disassemble','--start-address=0x8000','--stop-address=0x280000',binary],assembly)
        evidence=a.output/'evidence' if tag=='arm' else directory/'evidence'
        run([sys.executable,scripts/'decode_strings.py',binary,assembly,'--output',evidence])
        variants[tag]=Counter(x['value'] for x in json.loads((evidence/'decoded-strings.json').read_text()))
        # Independently compare raw metadata parsing with Apple's nm output.
        classes=MachO(data).classes()
        class_tables[tag]=[{k:([{mk:mv for mk,mv in method.items() if mk!='address'} for method in value] if k=='methods' else value) for k,value in cls.items() if k!='address'} for cls in classes]
        expected={f'{method["kind"]}[{cls["name"]} {method["selector"]}]':int(method['address'],16) for cls in classes for method in cls['methods']}
        nm=subprocess.check_output(['nm',str(binary)],text=True)
        actual={}
        for line in nm.splitlines():
            fields=line.split(' ',2)
            if len(fields)==3 and fields[2] in expected:actual[fields[2]]=int(fields[0],16)
        assert actual==expected,tag+' method metadata disagrees with nm'
        (a.output/'evidence'/f'{tag}-named-methods.tsv').write_text('address\tmethod\n'+''.join(f'{addr:x}\t{name}\n' for name,addr in sorted(expected.items())))
    assert variants['arm']==variants['arm64']==variants['arm64e'],'Decoded string multisets differ'
    assert class_tables['arm']==class_tables['arm64']==class_tables['arm64e'],'Objective-C class metadata differs'
    run([sys.executable,scripts/'unflatten.py',paths['arm'],a.work/'arm/application.asm','--output',a.output/'evidence/branches.json'])
    comparison={'decoded_strings_per_package':sum(variants['arm'].values()),'decoded_string_multisets_equal':True,
                'all_three_method_tables_match_nm':True,'class_metadata_equal_across_packages':True,'method_count_per_package':len(expected),
                'packages_unmodified':{p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in packages}}
    (a.output/'evidence/cross-package-verification.json').write_text(json.dumps(comparison,indent=2)+'\n')
    if a.decompile:
        ghidra=a.ghidra
        if ghidra is None:
            executable=shutil.which('ghidraRun')
            if not executable:raise RuntimeError('Supply --ghidra /path/to/ghidra')
            ghidra=Path(executable).resolve().parents[1]/'libexec'
        project=a.work/'ghidra';project.mkdir(exist_ok=True)
        base=[ghidra/'support/analyzeHeadless',project,'YTLite','-scriptPath',scripts,'-max-cpu','4']
        if (project/'YTLite.gpr').exists():
            run([*base,'-process','YTLite.dylib','-noanalysis','-postScript','Improve.java',a.output/'evidence'],a.work/'improve.log')
        else:
            run([*base,'-import',paths['arm'],'-analysisTimeoutPerFile','900','-postScript','Improve.java',a.output/'evidence'],a.work/'import.log')
        run([*base,'-process','YTLite.dylib','-noanalysis','-postScript','Recover.java',a.output/'decompiled'],a.work/'export.log')
        run([sys.executable,scripts/'organize.py',paths['arm'],'--root',a.output])
        run([sys.executable,scripts/'recover_defaults.py',paths['arm'],'--root',a.output])
    print('Package, method-table and decoded-string verification passed.')

if __name__=='__main__':main()
