#!/usr/bin/env python3
"""Reproduce analysis-only feed branches using the reviewed facts in FeedNodes.provenance.md.

This supplements the conservative analyzer; it does not relax its stack-alias rules.
It validates original bytes and retains both outcomes of every dynamic condition.
"""
import sys,struct,json
from dataclasses import replace
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent))
from evidence_image import EvidenceImage, REPO
from control_flow import parse_assembly,Analyzer,branch_patch
from unflatten import Choice
im=EvidenceImage();ins=parse_assembly((REPO/'.recovery-work/arm/application.asm').read_text())
for pc in range(0x9c084,0x9d4d4,4):
 assert ins[pc].word == struct.unpack_from('<I',im.image.data,im.image.off(pc))[0],hex(pc)
rows=[(0x9cbc0,0x117f848,0xbfb82ddb,'w0'),(0x9cdfc,0x117f8c8,0x22e01494,'eq'),(0x9d290,0x117f9e8,0x91088ca1,'eq'),(0x9ce68,0x117f8f0,0x2e5d8a75,'eq'),(0x9d034,0x117f968,0xaf1067c6,'w0'),(0x9d084,0x117f980,0xf1c8c4b2,'w0'),(0x9d0fc,0x117f998,0x10fd114c,'w22'),(0x9d15c,0x117f9b0,0x3ce9ff6f,'w0'),(0x9d1b0,0x117f9c8,0xc0554bdd,'eq'),(0x9d2f8,0x117fa10,0xf288247e,'eq')]
rows += [(0x9cef4,0x117f910,0xb998e823,'w25'),(0x9d3d0,0x117fa30,0x21c85934,'w25')]
rows += [(0x9cf28,0x117f930,0xbe233d89,'eq'),(0x9d404,0x117fa50,0x6f9b0351,'eq')]
rows += [(0x9cf68,0x117f8f0,0x2e5d8a75,'eq'),(0x9cfc0,0x117f948,0xb2ec2b5e,'eq'),(0x9d444,0x117fa10,0xf288247e,'eq'),(0x9d348,0x117fa68,0x9afcb4b9,'eq')]
facts={}
for pc,table,xor,cond in rows:
 key=struct.unpack('<I',im.buffer(table+16,4))[0]; delta=(-(key^xor))&0xffffffff;delta=delta-0x100000000 if delta&0x80000000 else delta
 targets=[im.image.ptr(table+8*i)+delta for i in range(2)]
 facts[pc-4]=(targets,cond)
class ManualFactsAnalyzer(Analyzer):
 def transfer(self,instruction,incoming):
  out=super().transfer(instruction,incoming)
  if instruction.address in facts:
   targets,cond=facts[instruction.address]
   if cond=='eq': assert out.flags is not None; out.registers['x8']=Choice('eq',out.flags,*targets)
   else:
    key='x'+cond[1:];out.registers[key]=Choice('manually-proven-'+cond,None,0,1);out.registers['x8']=Choice('manually-proven-'+cond,None,*targets)
  return out
a=ManualFactsAnalyzer(im.image,ins);b,r=a.analyze(0x9c084,0x9d4d4);print(r)
assert r['status']=='closed',r
for pc in r.get('unresolved_indirect_branches',[]):
 p=int(pc,16)
 for q in range(p-44,p+4,4):print(hex(q),ins[q].op,ins[q].operands)
if b:
 old=json.loads((REPO/'.recovery-work/analysis-v2/evidence/branches.json').read_text());existing={int(x['address'],16) for x in old};island=max(int(x['island'],16)+len(x['island_words'])*4 for x in old if 'island' in x)
 new=[]
 for instruction,target,state in b:
  patch=branch_patch(instruction,target,state,island)
  if patch and instruction.address not in existing:
   patch['function']='0x9c084';patch['analysis']='closed-flow-with-manually-verified-stack-table-facts';new.append(patch)
   if 'island' in patch:island+=len(patch['island_words'])*4
 output=REPO/'.recovery-work/feed-nodes-analysis/evidence';output.mkdir(parents=True,exist_ok=True)
 (output/'branches.json').write_text(json.dumps(old+new,indent=2)+'\n');print('new',len(new))
 report={'binary_sha256':im.sha256,'function':r,'reviewed_table_facts':[{'branch':hex(pc),'table':hex(table),'key':hex(table+16),'xor':hex(xor),'index':cond} for pc,table,xor,cond in rows],'additional':new}
 (output/'feed-branch-report.json').write_text(json.dumps(report,indent=2)+'\n')
