#!/usr/bin/env python3
"""Report recovered coverage and hook differences against the checked-in backup."""
import csv
import json
from pathlib import Path
import re
import subprocess


def source_methods(text):
    text=re.sub(r'/\*.*?\*/','',text,flags=re.S)
    text=re.sub(r'^\s*//.*$','',text,flags=re.M)
    result=set();cls=None
    for mt in re.finditer(r'%hook\s+(\w+)|%end|^([+-])\s*\([^)]*\)([^{};]+)[{;]',text,re.M):
        if mt[1]:cls=mt[1]
        elif mt[0]=='%end':cls=None
        elif cls:
            labels=re.findall(r'(\w+)\s*:\s*\(',mt[3])
            selector=''.join(x+':' for x in labels) if labels else mt[3].strip()
            result.add((cls,mt[2],selector))
    return result


def main():
    root=Path(__file__).resolve().parents[1];repo=root.parent
    baseline_file=root/'evidence/baseline.json'
    if baseline_file.exists():baseline=json.loads(baseline_file.read_text())['commit']
    else:
        baseline=subprocess.check_output(['git','rev-parse','HEAD'],cwd=repo,text=True).strip()
        baseline_file.write_text(json.dumps({'commit':baseline},indent=2)+'\n')
    before=set()
    for name in subprocess.check_output(['git','ls-files','*.x'],cwd=repo,text=True).splitlines():
        before|=source_methods(subprocess.check_output(['git','show',f'{baseline}:{name}'],cwd=repo,text=True))
    hooks=json.loads((root/'evidence/hooks.json').read_text())
    delta={'baseline_commit':baseline,'baseline_hook_methods':len(before),'missing_from_backup':[],'present_in_backup':[],'unmapped':[]}
    for hook in hooks:
        if not hook['complete']:delta['unmapped'].append(hook)
        elif (hook['class_name'],hook['kind'],hook['selector']) in before:delta['present_in_backup'].append(hook)
        else:delta['missing_from_backup'].append(hook)
    (root/'evidence/hook-delta.json').write_text(json.dumps(delta,ensure_ascii=False,indent=2)+'\n')
    classes=json.loads((root/'evidence/arm-classes.json').read_text())
    owned=[c for c in classes if any(int(m['address'],16)<0x280000 for m in c['methods'])]
    rows=list(csv.DictReader((root/'decompiled/index.tsv').open(),delimiter='\t'))
    exports={int(r['address'],16):r for r in rows if r['status']=='ok'}
    warnings=[]
    for addr,r in exports.items():
        text=(root/'decompiled'/r['file']).read_text()
        if 'Could not recover jumptable' in text or 'Bad instruction' in text or 'unaff_' in text or 'in_x' in text:
            warnings.append(dict(address=hex(addr),name=r['name'],file=r['file']))
    coverage={'first_party_classes':len(owned),'first_party_methods':sum(len(c['methods']) for c in owned),
              'first_party_methods_without_exports':[m for c in owned for m in c['methods'] if int(m['address'],16) not in exports],
              'decompiled_functions':len(exports),'decompilation_failures':[r for r in rows if r['status']!='ok'],
              'hook_registration_records':len(hooks),'mapped_hook_registration_records':sum(h['complete'] for h in hooks),
              'mapped_hook_implementations_without_exports':[h for h in hooks if h['complete'] and int(h['implementation'],16) not in exports],
              'functions_with_analysis_warnings':warnings,
              'warning_note':'Includes expected indirect calls to original IMPs. Successful export is not proof of source equivalence.'}
    (root/'evidence/coverage.json').write_text(json.dumps(coverage,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({k:v for k,v in coverage.items() if k!='functions_with_analysis_warnings'},indent=2))
    print(f'Hook records absent from backup: {len(delta["missing_from_backup"])}; records present: {len(delta["present_in_backup"])}; unmapped: {len(delta["unmapped"])}')

if __name__=='__main__':main()
