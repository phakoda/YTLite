#!/usr/bin/env python3
"""Index current focused first-package evidence without treating it as parity."""
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path

from compare_supplied_packages import archive_files, method_spans, LIBRARY_CLASSES
from inventory import MachO

REPO=Path(__file__).resolve().parents[2]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def current_inputs(inputs):
    assert inputs
    for name,value in inputs.items():
        assert digest(REPO/name)==value,('Stale audit input',name)


def main():
    package=Path('/Users/moussah/Downloads/com.dvntm.ytlite_5.2.2_iphoneos-arm64e.deb')
    manifest_path=REPO/'recovery/evidence/packages.json'
    manifest=next(x for x in json.loads(manifest_path.read_text()) if x['package']==package.name)
    assert digest(package)==manifest['sha256']
    binary=next(b for name,b in archive_files(package,'data.tar').items() if name.endswith('/YTLite.dylib'))
    assert hashlib.sha256(binary).hexdigest()==manifest['binary_sha256']
    image=MachO(binary);classes=image.classes();spans=method_spans(image,classes)
    source_path=REPO/'recovery/evidence/source-inventory.json'
    sources=json.loads(source_path.read_text());current_inputs(sources['source_sha256'])
    owners={r['class']:r['source'] for r in sources['classes']}
    comparison_path=REPO/'recovery/evidence/first-package-comparison.json'
    comparison=json.loads(comparison_path.read_text());current_inputs(comparison['source_inputs'])
    assert comparison['packages']['arm64e']['binary_sha256']==manifest['binary_sha256']
    compared={r['method']:r for r in comparison['comparisons_to_first_package']['arm']['methods']}
    inputs={str(p.relative_to(REPO)):digest(p) for p in [Path(__file__).resolve(),manifest_path,source_path,comparison_path,
        REPO/'recovery/tools/inventory.py',REPO/'recovery/tools/compare_supplied_packages.py']}
    covered=defaultdict(list)
    # These are the method-specific first-package reports currently supported by
    # the verifier. Resource/category audits and other-package tests are separate.
    audits=[('YTLHelper',path,REPO/('.recovery-work/helper-'+
        path.name.removeprefix('first-helper-').removesuffix('-fidelity.json')+'/report.json'))
        for path in sorted((REPO/'recovery/evidence').glob('first-helper-*-fidelity.json'))]
    audits.append(('YTPMedia',REPO/'recovery/evidence/first-media-theme-fidelity.json',
                   REPO/'.recovery-work/first-media-theme/report.json'))
    audits.append(('YTPMedia',REPO/'recovery/evidence/first-media-icons-fidelity.json',
                   REPO/'.recovery-work/first-media-icons/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-pipeline-fidelity.json',
                   REPO/'.recovery-work/first-menu-pipeline/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-audio-fidelity.json',
                   REPO/'.recovery-work/first-menu-audio/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-parsers-fidelity.json',
                   REPO/'.recovery-work/first-menu-parsers/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-formats-fidelity.json',
                   REPO/'.recovery-work/first-menu-formats/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-video-selection-fidelity.json',
                   REPO/'.recovery-work/first-menu-video-selection/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-thumbnail-fidelity.json',
                   REPO/'.recovery-work/first-menu-thumbnail/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-storage-fidelity.json',
                   REPO/'.recovery-work/first-menu-storage/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-audio-selector-fidelity.json',
                   REPO/'.recovery-work/first-menu-audio-selector/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-captions-fidelity.json',
                   REPO/'.recovery-work/first-menu-captions/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-caption-flow-fidelity.json',
                   REPO/'.recovery-work/first-menu-caption-flow/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-images-fidelity.json',
                   REPO/'.recovery-work/first-menu-images/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-information-fidelity.json',
                   REPO/'.recovery-work/first-menu-information/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-external-player-fidelity.json',
                   REPO/'.recovery-work/first-menu-external-player/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-video-sheet-fidelity.json',
                   REPO/'.recovery-work/first-menu-video-sheet/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-shorts-fidelity.json',
                   REPO/'.recovery-work/first-menu-shorts/report.json'))
    audits.append(('DownloadMenuHelper',REPO/'recovery/evidence/first-menu-normal-construction-fidelity.json',
                   REPO/'.recovery-work/first-menu-normal-construction/report.json'))
    audits.append(('AudioManager',REPO/'recovery/evidence/first-audio-manager-fidelity.json',
                   REPO/'.recovery-work/first-audio-manager/report.json'))
    audits.append(('FFMpegHelper',REPO/'recovery/evidence/first-ffmpeg-construction-fidelity.json',
                   REPO/'.recovery-work/first-ffmpeg-construction/report.json'))
    audits.append(('FFMpegHelper',REPO/'recovery/evidence/first-ffmpeg-progress-fidelity.json',
                   REPO/'.recovery-work/first-ffmpeg-progress/report.json'))
    audits.append(('FFMpegHelper',REPO/'recovery/evidence/first-ffmpeg-log-fidelity.json',
                   REPO/'.recovery-work/first-ffmpeg-log/report.json'))
    audits.append(('FFMpegHelper',REPO/'recovery/evidence/first-ffmpeg-command-fidelity.json',
                   REPO/'.recovery-work/first-ffmpeg-command/report.json'))
    audits.append(('FFMpegHelper',REPO/'recovery/evidence/first-ffmpeg-lifecycle-fidelity.json',
                   REPO/'.recovery-work/first-ffmpeg-lifecycle/report.json'))
    audits.append(('DVNCell',REPO/'recovery/evidence/first-model-accessors-fidelity.json',
                   REPO/'.recovery-work/first-model-accessors/report.json'))
    audits.append(('DVNCell',REPO/'recovery/evidence/first-cell-lifecycle-fidelity.json',
                   REPO/'.recovery-work/first-cell-lifecycle/report.json'))
    audits.append(('DVNCell',REPO/'recovery/evidence/first-cell-factories-fidelity.json',
                   REPO/'.recovery-work/first-cell-factories/report.json'))
    for class_name,evidence_path,report_path in audits:
        original=next(c for c in classes if c['name']==class_name)
        evidence=json.loads(evidence_path.read_text());report=json.loads(report_path.read_text())
        assert report['passed'] and report['first_binary_sha256']==evidence['binary_sha256']==manifest['binary_sha256']
        current_inputs(report['inputs'])
        assert report['inputs'][str(evidence_path.relative_to(REPO))]==digest(evidence_path)
        inputs.update(report['inputs']);inputs[str(report_path.relative_to(REPO))]=digest(report_path)
        intervals=[]
        for span in evidence['spans']:
            a,b=int(span['start'],16),int(span['end'],16)
            assert hashlib.sha256(binary[image.off(a):image.off(a)+b-a]).hexdigest()==span['sha256']
            intervals.append((a,b))
        contexts=evidence.get('method_contracts')
        if contexts is None:
            named=evidence.get('methods',{'downloadProgress:':'0x22b770',
                'downloadAudioWithUrl:fileName:videoID:audioSize:duration:':'0x22b1c0'})
            contexts=[]
            for selector,address in named.items():
                matches=[m for m in original['methods'] if m['selector']==selector and m['address']==address]
                assert len(matches)==1,(selector,address)
                contexts.append(matches[0])
        for method in contexts:
            assert any(all(m[k]==method[k] for k in ('kind','selector','address'))
                       for m in original['methods']),(class_name,method)
            key=f"{method['kind']}[{class_name} {method['selector']}]"
            entry=spans[key];a,b=int(entry['start'],16),int(entry['end'],16)
            assert entry['start']==method['address']
            # Callback-only intervals do not count as coverage of the named body.
            if not any(start<=a and b<=end for start,end in intervals):continue
            covered[key].append({'evidence':str(evidence_path.relative_to(REPO)),
                'report':str(report_path.relative_to(REPO)),'scope':report['scope']})
    rows=[]
    for cls in sorted(classes,key=lambda c:c['name']):
        if cls['name'] in LIBRARY_CLASSES:continue
        methods=[]
        for method in cls['methods']:
            key=f"{method['kind']}[{cls['name']} {method['selector']}]"
            assert compared[key]['arm64e']==spans[key]
            methods.append({'method':method['kind']+method['selector'],'address':method['address'],
                'comparison_with_arm':compared[key]['status'],'focused_audits':covered[key]})
        rows.append({'class':cls['name'],'source':owners[cls['name']],
            'named_methods':len(methods),'with_current_focused_evidence':sum(bool(m['focused_audits']) for m in methods),
            'raw_comparison':dict(Counter(m['comparison_with_arm'] for m in methods)),'methods':methods})
    total=sum(r['named_methods'] for r in rows)
    focused=sum(r['with_current_focused_evidence'] for r in rows)
    assert sources['classes_with_compiled_implementations']==sources['classes_with_exact_method_sets_and_encodings']==len(rows)
    limits=[
        'Focused evidence indexes pinned named-method bytes and current scoped tests. It does not prove all behavior of any method or class.',
        'Uncatalogued methods may have reconstructed source and other-package runtime tests; absence from this index is not evidence that source is missing or wrong.',
        'Category/resource audits, anonymous callbacks, registrations, initializers and live-device behavior are not counted as named methods here.',
        'Raw byte or length differences are investigation cues, not semantic differences or a parity percentage.',
        'Known source differences and excluded behavior remain in FIRST_PACKAGE_PARITY.md and per-method provenance.',
    ]
    report={'first_package_sha256':manifest['sha256'],'first_binary_sha256':manifest['binary_sha256'],
        'first_party_classes':len(rows),'named_methods':total,'with_current_focused_evidence':focused,
        'not_catalogued':total-focused,'classes':rows,'inputs':inputs,'limits':limits,'original_binary_executed':False}
    output=REPO/'recovery/evidence/first-package-audit-inventory.json'
    output.write_text(json.dumps(report,indent=2)+'\n')
    lines=['# First-package audit index','',f'{focused} of {total} first-party named methods have current focused first-package evidence catalogued here.',
        f'This is an evidence index, not a parity score. All {len(rows)} first-party classes already have reconstructed implementations.',
        '', 'Run `python3 recovery/tools/first_package_audit_inventory.py` to check input hashes and regenerate this index.',
        '', '| Class | Named methods | With focused evidence | Different raw length from arm |', '| --- | ---: | ---: | ---: |']
    for row in rows:
        lines.append(f"| [{row['class']}](../{row['source']}) | {row['named_methods']} | {row['with_current_focused_evidence']} | {row['raw_comparison'].get('different_length',0)} |")
    lines+=['','## Interpretation','']+[f'- {limit}' for limit in limits]
    (REPO/'recovery/FIRST_PACKAGE_AUDIT_INDEX.md').write_text('\n'.join(lines)+'\n')
    print(f'First-package audit index: {focused}/{total} named methods have current focused evidence; {len(rows)} first-party classes indexed.')


if __name__=='__main__':main()
