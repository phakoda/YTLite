#!/usr/bin/env python3
"""Check selected source ownership and the actual linked artifact with exclusions visible."""
import hashlib
import json
from pathlib import Path
import re
import runpy
import subprocess

from evidence_image import REPO


def current_runtime_reports():
    """Reject stale evidence for the UI/helper gaps closed during fidelity review."""
    reports = {}
    for directory in ['speed-control-tests', 'speed-master-tests', 'speed-popup-tests',
                      'navigation-helpers-tests', 'translator-ui']:
        path = REPO / '.recovery-work' / directory / 'report.json'
        data = json.loads(path.read_text())
        inputs = data.get('inputs', data.get('source_sha256', {}))
        assert inputs, ('Missing runtime input hashes', path)
        for source, sha in inputs.items():
            assert hashlib.sha256((REPO / source).read_bytes()).hexdigest() == sha, ('Stale runtime evidence', source)
        assert data['runtime_assertions'] > 0, path
        reports[str(path.relative_to(REPO))] = {
            'sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
            'runtime_assertions': data['runtime_assertions'],
        }
    return reports


def current_corrected_module_reports():
    reports = {}
    for relative in ['settings/verification-summary.json', 'presentation-helpers/runtime-verification.json',
                     'factory-audit/report.json', 'media-picker-tests/report.json', 'sleep-timer-tests/report.json']:
        path = REPO / '.recovery-work' / relative
        data = json.loads(path.read_text())
        if relative.startswith('settings/'):
            inputs = dict(data['fixture_source_sha256'])
            inputs.update({f'recovery/source/Settings/{name}.m': sha
                           for name, sha in data['production_source_sha256'].items()})
            assert not data['metadata_differences'] and data['runtime_assertions'] > 0
        else:
            inputs = data.get('sources', data.get('source_sha256', {}))
        assert inputs, path
        assert data.get('passed', True), path
        for source, sha in inputs.items():
            assert hashlib.sha256((REPO / source).read_bytes()).hexdigest() == sha, ('Stale corrected-module report', source)
        reports[str(path.relative_to(REPO))] = hashlib.sha256(path.read_bytes()).hexdigest()
    return reports


def current_presentation_lifecycle_reports():
    reports = {}
    for directory in ['sheet-lifecycle', 'player-toast-lifecycle', 'toast-lifecycle',
                      'toast-manager-lifecycle', 'toast-construction', 'toast-geometry',
                      'toast-window', 'image-viewer-ui', 'helper-media', 'helper-rendering', 'helper-image',
                      'first-bundle', 'helper-progress', 'helper-conversion', 'helper-buttons', 'helper-init',
                      'helper-terminal', 'helper-start', 'helper-finish', 'helper-paths', 'helper-ordering', 'helper-assets',
                      'helper-mediaflow', 'helper-imageflow', 'helper-state',
                      'first-media-theme', 'first-media-icons', 'first-menu-pipeline', 'first-menu-audio', 'first-menu-parsers', 'first-menu-formats', 'first-menu-video-selection', 'first-menu-thumbnail', 'first-menu-storage', 'first-menu-audio-selector', 'first-menu-captions', 'first-menu-caption-flow', 'first-menu-images', 'first-menu-information', 'first-menu-external-player', 'first-menu-video-sheet', 'first-menu-shorts', 'first-menu-normal-construction', 'first-audio-manager', 'first-ffmpeg-construction', 'first-ffmpeg-progress', 'first-ffmpeg-log', 'first-ffmpeg-command', 'first-ffmpeg-lifecycle', 'first-model-accessors', 'first-cell-factory-order', 'first-cell-lifecycle', 'first-cell-factories']:
        path = REPO / '.recovery-work' / directory / 'report.json'
        data = json.loads(path.read_text())
        inputs = data.get('inputs', data.get('source_sha256', {}))
        assert inputs and data.get('passed', True), path
        for source, sha in inputs.items():
            assert hashlib.sha256((REPO / source).read_bytes()).hexdigest() == sha, ('Stale lifecycle report', source)
        checks = data.get('runtime_assertions', data.get('runtime_checks', 0))
        assert checks > 0, path
        reports[str(path.relative_to(REPO))] = {
            'sha256': hashlib.sha256(path.read_bytes()).hexdigest(), 'runtime_assertions': checks,
        }
    return reports


def current_roothide_package_report():
    path=REPO/'.recovery-work/roothide-package/report.json'
    data=json.loads(path.read_text())
    assert data['passed'] and data['inputs']
    for source,sha in data['inputs'].items():
        assert hashlib.sha256((REPO/source).read_bytes()).hexdigest()==sha,('Stale roothide package evidence',source)
    assert data['archive_paths_equal'] and data['runtime_sections_equal_to_built_artifact']
    assert data['regular_files']==18 and data['first_party_classes_with_equal_encodings']==51
    return {'report':str(path.relative_to(REPO)),'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),
            'package':data['package'],'package_sha256':data['package_sha256'],
            'scope':'Static archive and linkage verification; no device execution'}


def key(row):
    implementation = row['implementation']
    try:
        implementation = hex(int(implementation, 16))
    except ValueError:
        pass
    return (hex(int(row.get('registration', row.get('registrar')), 16)), implementation)


def main():
    report_path = REPO / 'recovery/evidence/integration-verification.json'
    report_path.unlink(missing_ok=True)
    hooks = json.loads((REPO / 'recovery/evidence/hook-source-inventory.json').read_text())
    calls = json.loads((REPO / 'recovery/evidence/registration-call-audit.json').read_text())
    classes = json.loads((REPO / 'recovery/evidence/source-inventory.json').read_text())
    categories = json.loads((REPO / 'recovery/evidence/category-source-inventory.json').read_text())
    assert categories['exact_categories'] == 3 and categories['packaged_category_methods'] == 6
    build = json.loads((REPO / '.recovery-work/build/latest-build.json').read_text())
    excluded = {key(row): row for row in hooks['explicit_exclusions']}
    assert len(excluded) == 20
    selected = []
    for row in hooks['registrations']:
        if row['reconstruction_module']:
            assert key(row) not in excluded
            assert row['module_selected_for_build'], row
            selected.append(row)
        else:
            assert key(row) in excluded, row
    for row in hooks['additional_registration_records'] + hooks['manual_registration_records']:
        assert row['module_selected_for_build'], row
        assert key(row) not in excluded
        selected.append(row)
    assert len(selected) == 446
    assert len(selected) + len(excluded) == calls['registration_call_sites'] == 466
    assert len({key(row) for row in selected}) == len(selected), 'Duplicate ownership claim'
    assert not hooks['still_unmapped_records']
    assert classes['classes_with_exact_method_sets_and_encodings'] == classes['packaged_first_party_classes'] == 51
    for path, sha in classes['source_sha256'].items():
        assert hashlib.sha256((REPO / path).read_bytes()).hexdigest() == sha, path
    for root in REPO.glob('*.x'):
        assert not re.search(r'^\s*%(hook|ctor)\b', root.read_text(), re.M), root
    assert build['status'] == 'passed'
    current_build_inputs = runpy.run_path(str(REPO / 'tools/build_local.py'))['input_hashes']()
    assert current_build_inputs == build['input_sha256'], 'Build inputs were changed, added or removed; rebuild.'
    for path, sha in build['input_sha256'].items():
        assert hashlib.sha256((REPO / path).read_bytes()).hexdigest() == sha, ('Stale build input', path)
    artifact = REPO / build['artifact']
    artifact_sha = hashlib.sha256(artifact.read_bytes()).hexdigest()
    assert artifact_sha == build['artifact_sha256']
    assert artifact_sha != hooks['binary_sha256']
    symbols = subprocess.check_output(['xcrun', 'nm', str(artifact)], text=True)
    defined = set(re.findall(r'^[0-9a-f]+ [tT] _(\w+)$', symbols, re.M))
    for module in hooks['modules']:
        source = (REPO / module['source']).read_text()
        assert not re.search(r'^\s*%ctor\b', source, re.M), module['source']
        for installer in re.findall(r'^void (YTLInstall\w+)\(', source, re.M):
            assert installer in defined, installer
    for name in ['YTLPrepareSideloadCompatibility', 'YTLScheduleWelcome', 'YTLFinalizePrimaryStartup']:
        assert name in defined, name
    runtime_reports = current_runtime_reports()
    report = {
        'selected_registration_records': len(selected),
        'evidence_only_excluded_records': len(excluded),
        'direct_registration_sites_accounted_for': calls['registration_call_sites'],
        'first_party_classes_with_exact_method_ABI': 51,
        'packaged_first_party_methods': sum(row['packaged_methods'] for row in classes['classes']),
        'category_evidence': 'recovery/evidence/category-source-inventory.json',
        'category_evidence_sha256': hashlib.sha256((REPO/'recovery/evidence/category-source-inventory.json').read_bytes()).hexdigest(),
        'artifact': build['artifact'], 'artifact_sha256': artifact_sha,
        'ui_helper_runtime_reports': runtime_reports,
        'corrected_module_runtime_reports': current_corrected_module_reports(),
        'presentation_lifecycle_runtime_reports': current_presentation_lifecycle_reports(),
        'roothide_package_report': current_roothide_package_report(),
        'original_binary_executed': False,
        'limits': ['Registration ownership and linking do not prove live YouTube behavior.',
                   'Historical account activation and integrity/bootstrap effects are omitted under the existing local preference policy.',
                   'Authentication, attestation, app-origin verification and permission bypass callbacks remain evidence-only.',
                   'UI/helper fixtures execute actual source with synthetic host objects; device UI and live YouTube integration remain untested.'],
    }
    report_path.write_text(json.dumps(report, indent=2)+'\n')
    print('Integration: 446 selected registration records + 20 explicit exclusions account for 466 original direct call sites; current source matches the linked artifact.')


if __name__ == '__main__':
    main()
