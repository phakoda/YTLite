#!/usr/bin/env python3
"""Audit original Objective-C category metadata, which class-only inventory excludes."""
import hashlib,json,re,struct,subprocess
from pathlib import Path
from evidence_image import EvidenceImage,REPO
from verify_ios_sources import decode_llvm_string
SOURCES={('NSBundle','YTLite'):'Utils/NSBundle+YTLite.m',('NSString','YTL'):'Utils/NSString+YTLite.m',('UIViewController','DVNPatreonContext'):'recovery/source/Runtime/UIViewController+DVNPatreonContext.m'}

def extract_categories(text):
    strings={}
    for m in re.finditer(r'^(@(?:"[^"\n]+"|[-.$\w]+)) = .*?\bc"((?:\\[0-9a-fA-F]{2}|[^"\n])*)"',text,re.M):
        try:strings[m[1]]=decode_llvm_string(m[2])
        except (ValueError,UnicodeDecodeError):pass
    output={}
    for m in re.finditer(r'^@"_OBJC_\$_CATEGORY_(INSTANCE|CLASS)_METHODS_([^"\n]+)_\$_([^"\n]+)" = (.+)$',text,re.M):
        kind,cls,category,decl=m.groups();methods=output.setdefault((cls,category),{})
        records=re.findall(r'%struct\._objc_method \{ ptr (@[-.$\w]+), ptr (@[-.$\w]+), ptr @"[^"\n]+" \}',decl)
        count=re.search(r'i32 \d+, i32 (\d+),',decl);assert count and len(records)==int(count[1])
        for name,encoding in records:methods[('+' if kind=='CLASS' else '-')+strings[name]]=strings[encoding]
    return output

def main():
    image=EvidenceImage();m=image.image;original=[];starts=sorted(m.function_starts)
    for section in ['__objc_catlist','__objc_nlcatlist']:
        if section not in m.sections:continue
        address,size,_=m.sections[section]
        for pointer in range(address,address+size,8):
            category=m.ptr(pointer);raw=struct.unpack_from('<Q',m.data,m.off(category+8))[0]
            cls=m.imports[raw&0xffffff].removeprefix('_OBJC_CLASS_$_') if raw>>63 else m.string(m.ptr((m.ptr(m.ptr(category+8)+32)&~7)+24))
            name=m.string(m.ptr(category));methods=m.methods(m.ptr(category+16),'-')+m.methods(m.ptr(category+24),'+')
            for method in methods:
                start=int(method['address'],16);end=starts[starts.index(start)+1];method.update(instruction_end=hex(end),instruction_sha256=hashlib.sha256(m.data[m.off(start):m.off(end)]).hexdigest())
            original.append({'class':cls,'category':name,'address':hex(category),'methods':methods})
    assert len(original)==3 and sum(len(c['methods']) for c in original)==6
    work=REPO/'.recovery-work/category-tests';work.mkdir(parents=True,exist_ok=True);report=REPO/'recovery/evidence/category-source-inventory.json';report.unlink(missing_ok=True);commands=[]
    def run(args):
        result=subprocess.run(list(map(str,args)),cwd=REPO,text=True,capture_output=True,timeout=120);commands.append({'command':list(map(str,args)),'exit_code':result.returncode,'output':result.stdout+result.stderr});(work/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');print(result.stdout+result.stderr,end='');result.check_returncode()
    flags=['-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror','-Wno-unused-parameter']
    for item in original:
        key=(item['class'],item['category']);source=REPO/SOURCES[key];llvm=work/(item['class']+'.ll')
        run(['xcrun','--sdk','iphoneos','clang',*flags,'-target','arm64-apple-ios14.0','-S','-emit-llvm',source,'-o',llvm])
        actual=extract_categories(llvm.read_text())[key];expected={method['kind']+method['selector']:method['encoding'] for method in item['methods']};assert actual==expected,{'category':key,'expected':expected,'actual':actual}
        item.update(source=SOURCES[key],source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),compiled_methods=actual)
    bundle_report=json.loads((REPO/'.recovery-work/bundle-tests/report.json').read_text());assert bundle_report['runtime_tests']=='passed'
    for path,digest in bundle_report['source_sha256'].items():assert hashlib.sha256((REPO/path).read_bytes()).hexdigest()==digest,('stale bundle runtime evidence',path)
    source=REPO/SOURCES[('UIViewController','DVNPatreonContext')];fixture=REPO/'recovery/tests/category_anchor_fixture.m';shims=REPO/'recovery/tests/category_anchor_shims';exe=work/'anchor'
    run(['xcrun','--sdk','macosx','clang',*flags,'-fsanitize=undefined','-fno-sanitize-recover=all','-I',shims,source,fixture,'-framework','Foundation','-o',exe]);run([exe])
    report.write_text(json.dumps({'binary_sha256':image.sha256,'categories':original,'exact_categories':3,'packaged_category_methods':6,'runtime':'bundle/localization tests with current source hashes; actual anchor fixture','class_only_inventory_excludes_these_methods':True,'original_binary_executed':False},indent=2)+'\n')
    print('PASS: all 3 packaged categories and 6 iOS method encodings match')
if __name__=='__main__':main()
