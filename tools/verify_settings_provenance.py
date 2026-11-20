#!/usr/bin/env python3
"""Generate/check Settings method and anonymous-block provenance.

The default validates the checked-in manifest. --write deliberately updates
ONLY the assigned recovery/source/Settings/provenance.json. No original code
is loaded or executed.
"""
from __future__ import annotations
import argparse, hashlib, json, re, sys
from pathlib import Path
from verify_settings_blocks import REMOVED_ACCOUNT_BLOCKS
sys.dont_write_bytecode=True
ROOT=Path(__file__).resolve().parents[1]
NAMES=['DVNTableViewController','YTPSettingsBuilder','DVNPickerView','YTPTableViewCell','TabbarVC','DVNSupportersVC']
HASH='bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca'

def build():
    classes={c['name']:c for c in json.loads((ROOT/'recovery/evidence/arm-classes.json').read_text())}
    ivars=json.loads((ROOT/'recovery/evidence/ivars.json').read_text())
    blocks=json.loads((ROOT/'.recovery-work/settings/original-blocks.json').read_text())
    methods=[];sources={};regions={}
    for name in NAMES:
        path=Path('recovery/source/Settings')/(name+'.m');source=(ROOT/path).read_text();sources[name]=source
        locations={}
        for match in re.finditer(r'^([+-])\s*\([^)]*\)\s*([\s\S]*?)\{',source,re.M):
            declaration=match[2];parts=re.findall(r'(\w+)\s*:',declaration)
            selector=''.join(p+':' for p in parts) if parts else re.match(r'\w+',declaration)[0]
            locations[match[1]+selector]=source[:match.start()].count('\n')+1
        for original in classes[name]['methods']:
            selector=original['selector'];key=original['kind']+selector
            generated=key not in locations
            if generated:
                properties={p['name'] for p in classes[name]['properties']}
                allowed=selector=='.cxx_destruct' or selector in properties or any(selector=='set'+p[0].upper()+p[1:]+':' for p in properties)
                if not allowed:raise ValueError(f'Original method missing explicit implementation: {name} {key}')
            implementation = 'ARC/declared-property synthesis' if generated else 'Objective-C method body'
            if name == 'YTPSettingsBuilder' and selector in ('rootTable', 'patreonSection:', 'patreonButtonCellWithType:model:'):
                implementation = 'Intentional local-fork change: no account UI or account-service calls'
            if name == 'YTPSettingsBuilder' and selector == 'rootTable':
                implementation += '; user-requested removal of the developer section'
            if name == 'YTPSettingsBuilder' and selector == 'creditsSection':
                implementation = 'Intentional local-fork change: user-requested removal of the Special thanks/supporters entry'
            methods.append({'class':name,**original,'source':str(path),'line':locations.get(key),
                            'implementation':implementation})
        regions[name]=sorted(classes[name]['methods'],key=lambda m:int(m['address'],16))
    mapped=[]
    for block in blocks:
        name=block['class'];invoke=int(block['invoke'],16)
        method=max((m for m in regions[name] if int(m['address'],16)<invoke),key=lambda m:int(m['address'],16))
        parent=next(m for m in methods if m['class']==name and m['selector']==method['selector'])
        if name=='YTPSettingsBuilder' and (0x16ebb4<=invoke<=0x170c98 or 0x172664<=invoke<=0x17419c):
            line=sources[name][:sources[name].index('static DVNCell *SettingsLink')].count('\n')+1
            implementation='SettingsLink C helper; each call constructs a fresh capturing no-argument block'
        else:
            line=parent['line'];implementation='inline callback in '+method['selector']
        if not block['signature']:raise ValueError('Unresolved block signature '+block['invoke'])
        if block['invoke'] in REMOVED_ACCOUNT_BLOCKS:
            implementation = 'Intentionally removed account callback; no compiled counterpart'
            line = None
        mapped.append({**block,'parent_selector':method['selector'],'source':parent['source'],'line':line,'implementation':implementation})
    return {'binary':'.recovery-work/arm/YTLite.dylib','sha256':HASH,
            'evidence':['recovery/evidence/arm-classes.json','recovery/evidence/ivars.json',
                        'recovery/evidence/decoded-strings.json','recovery/evidence/decoded-bytes.tsv',
                        '.recovery-work/analysis-v2/evidence/branches.json','.recovery-work/arm/application.asm','.recovery-work/arm/symbols.txt'],
            'class_counts':{name:len(classes[name]['methods']) for name in NAMES},
            'methods':methods,'blocks':mapped,
            'properties':{name:classes[name]['properties'] for name in NAMES},
            'ivars':{name:ivars[name] for name in NAMES},
            'integration_externs':[],
            'local_fork':{'requires_account':False,'removed_account_blocks':sorted(REMOVED_ACCOUNT_BLOCKS),
                          'developer_section_visible':False,'supporters_entry_visible':False}}

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--write',action='store_true');args=parser.parse_args()
    actual=hashlib.sha256((ROOT/'.recovery-work/arm/YTLite.dylib').read_bytes()).hexdigest()
    if actual!=HASH:raise SystemExit('Wrong evidence binary hash')
    manifest=build();path=ROOT/'recovery/source/Settings/provenance.json'
    if args.write:path.write_text(json.dumps(manifest,indent=2,ensure_ascii=False)+'\n')
    else:
        checked=json.loads(path.read_text())
        if checked!=manifest:raise SystemExit('Settings provenance is stale or differs from original evidence')
    if len(manifest['methods'])!=134 or len(manifest['blocks'])!=68:raise SystemExit('Unexpected original method/block coverage')
    print('Provenance: 134 method selectors; 65 retained and 3 intentionally removed account callbacks, all six classes mapped.')
