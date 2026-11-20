#!/usr/bin/env python3
"""Independent row fixtures extracted from original ARM64 call arguments.

This uses linear static data flow only on straight-line factory sequences;
provider/loop bodies are tested separately. Unresolved values are explicit and
never substituted with guessed settings values. Original bytes are never run.
"""
import contextlib, io, json, re, sys
from pathlib import Path
sys.dont_write_bytecode=True
from verify_settings_inspect import Image, annotate, ROOT

METHODS={'downloadingTable':(0x13aa40,0x13e384),'navbarTable':(0x13e384,0x13fec0),'feedTable':(0x13fec0,0x14218c),
         'playerTable':(0x14218c,0x156a98),'shortsTable':(0x156a98,0x15f514),'interfaceTable':(0x15f514,0x166620),
         'rpcTable':(0x16a3d4,0x16bb48)}

def extract():
    image=Image();result={}
    for method,(start,end) in METHODS.items():
        image.calls=[]
        with contextlib.redirect_stdout(io.StringIO()):annotate(image,start,end)
        calls={int(c['address'],16):c for c in image.calls}
        def value(v,depth=0):
            if depth>20:return {'unresolved':'depth'}
            if isinstance(v,int):
                if v in image.cfstrings:return image.cfstrings[v]
                return v
            if not isinstance(v,str):return {'unresolved':v}
            match=re.fullmatch(r'r@([0-9a-f]+)',v)
            if match:
                call=calls.get(int(match[1],16))
                if call:
                    sel=call['selector'];args=call['args']
                    if sel=='ytl_localized':return {'localized':value(args[0],depth+1)}
                    if sel=='arrayWithObjects:count:' and 'elements' in call:return [value(x,depth+1) for x in call['elements']]
                    if sel=='supportedLanguages':return {'host':'supportedLanguages'}
                    if sel=='imageWithName:':return {'image':value(args[2],depth+1)}
            return {'unresolved':v}
        rows=[]
        for call in image.calls:
            sel=call['selector'] or ''
            if sel.startswith(('cellWith','sliderCellWith','timePickerWith','textFieldCellWith','stepperCellWith')):
                names=sel.rstrip(':').split(':');args=call['args'];floats=call['floats'];obj=2;fp=0;values={}
                # Scalar floating-point arguments have their independent register bank.
                for n in names:
                    key=n.split('With',1)[-1] if 'With' in n else n
                    key=key[0].lower()+key[1:]
                    if key in ('minimum','maximum','divider','step'):
                        values[key]=floats[fp];fp+=1
                    else:
                        values[key]=value(args[obj]);obj+=1
                rows.append({'address':call['address'],'factory':sel,'values':values})
        result[method]=rows
    return result

if __name__=='__main__':
    result=extract();destination=ROOT/'.recovery-work/settings/original-rows.json'
    destination.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    for method,rows in result.items():
        missing=[r['address'] for r in rows if 'unresolved' in json.dumps(r['values'])]
        print(method,len(rows),'unresolved',missing)
