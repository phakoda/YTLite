#!/usr/bin/env python3
"""Audit compiler-emitted arm64 Objective-C metadata against original evidence.

Inputs are LLVM IR emitted by Apple's compiler, not source-text declarations.
No original binary is loaded or executed. Output remains under the repository.
"""
from pathlib import Path
import argparse, json, re
ROOT = Path(__file__).resolve().parents[1]
NAMES = ['DVNTableViewController','YTPSettingsBuilder','DVNPickerView','YTPTableViewCell','TabbarVC','DVNSupportersVC']

def decode(value):
    return re.sub(r'\\([0-9A-Fa-f]{2})',lambda m:chr(int(m[1],16)),value).rstrip('\x00')

def audit(directory):
    classes = {c['name']:c for c in json.loads((ROOT/'recovery/evidence/arm-classes.json').read_text())}
    ivars = json.loads((ROOT/'recovery/evidence/ivars.json').read_text())
    results=[];errors=[]
    for name in NAMES:
        ir=(directory/(name+'.ll')).read_text()
        strings={m[1]:decode(m[2]) for m in re.finditer(r'^(@[^ ]+) = .*?\bc"((?:\\[0-9A-Fa-f]{2}|[^"\\])*)"',ir,re.M)}
        expected=classes[name]
        superline=next(l for l in ir.splitlines() if l.startswith('@\"OBJC_CLASS_$_'+name+'\" ='))
        supers=re.findall(r'ptr @\"OBJC_CLASS_\$_([^\"]+)\"',superline)
        if supers != [expected['superclass']]:errors.append(f'{name} superclass {supers} != {expected["superclass"]}')
        methods={};properties={};variables={}
        for kind,label in [('-','INSTANCE'),('+','CLASS')]:
            lines=[l for l in ir.splitlines() if l.startswith('@"_OBJC_$_'+label+'_METHODS_'+name+'" =')]
            for line in lines:
                for sel,ty in re.findall(r'%struct\._objc_method \{ ptr (@[\w.]+), ptr (@[\w.]+), ptr @',line):
                    methods[kind+strings[sel]]=strings[ty]
        for line in ir.splitlines():
            if line.startswith('@"_OBJC_$_PROP_LIST_'+name+'" ='):
                for prop,attr in re.findall(r'%struct\._prop_t \{ ptr (@[\w.]+), ptr (@[\w.]+) \}',line):properties[strings[prop]]=strings[attr]
            if line.startswith('@"_OBJC_$_INSTANCE_VARIABLES_'+name+'" ='):
                for var,ty,align,size in re.findall(r'%struct\._ivar_t \{ ptr @"[^"]+", ptr (@[\w.]+), ptr (@[\w.]+), i32 (\d+), i32 (\d+) \}',line):
                    varname=strings[var]
                    m=re.search(re.escape('@"OBJC_IVAR_$_'+name+'.'+varname+'"')+r' = .*?(?:global|constant) i\d+ (\d+)',ir)
                    variables[varname]={'encoding':strings[ty],'alignment':int(align),'size':int(size),'offset':int(m[1]) if m else None}
        expmethods={m['kind']+m['selector']:m['encoding'] for m in expected['methods']}
        expproperties={p['name']:p['attributes'] for p in expected['properties']}
        for label,actual,wanted in [('methods',methods,expmethods),('properties',properties,expproperties)]:
            for key in set(actual)|set(wanted):
                if actual.get(key)!=wanted.get(key):errors.append(f'{name} {label} {key}: {actual.get(key)!r} != {wanted.get(key)!r}')
        expivars={v['name']:v for v in ivars[name]['ivars']}
        for key in set(variables)|set(expivars):
            if key not in variables or key not in expivars:errors.append(f'{name} ivar set {key}');continue
            for field in ('encoding','offset','size','alignment'):
                if field in expivars[key] and variables[key][field]!=expivars[key][field]:errors.append(f'{name}.{key} {field}: {variables[key][field]!r} != {expivars[key][field]!r}')
        results.append({'class':name,'methods':len(methods),'properties':len(properties),'ivars':len(variables),'actual_ivars':variables})
    report={'classes':results,'method_count':sum(c['methods'] for c in results),'property_count':sum(c['properties'] for c in results),'ivar_count':sum(c['ivars'] for c in results),'errors':errors}
    (directory/'metadata-audit.json').write_text(json.dumps(report,indent=2)+'\n')
    for e in errors:print('FAIL:',e)
    print(f"Compiler metadata: {len(results)} classes, {report['method_count']} methods, {report['property_count']} properties, {report['ivar_count']} ivars; {len(errors)} differences.")
    return not errors

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--directory',type=Path,default=ROOT/'.recovery-work/settings');args=p.parse_args()
    d=args.directory.resolve();d.relative_to(ROOT.resolve())
    raise SystemExit(0 if audit(d) else 1)
