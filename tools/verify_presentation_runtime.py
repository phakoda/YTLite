#!/usr/bin/env python3
"""Execute the owned source implementations against repository-only host doubles.

All UI, Photos, networking, volume/brightness, preferences and converter/transport
boundaries are replaced in this executable only. Foundation filesystem operations
are exercised exclusively on synthetic text fixtures under the owned TMPDIR.
"""
from __future__ import annotations
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / ".recovery-work/presentation-helpers"


def support_input_hashes() -> dict:
    paths = [Path(__file__).resolve(), ROOT / 'recovery/tests/presentation_redirects.h',
             ROOT / 'recovery/tests/presentation_doubles.h', ROOT / 'recovery/tests/presentation_test_support.h']
    paths += sorted((ROOT / 'recovery/tests/presentation_shims').rglob('*.h'))
    paths += sorted((ROOT / 'recovery/source').rglob('*.h'))
    paths += sorted((ROOT / 'Utils').glob('*.h'))
    return {str(path.relative_to(ROOT)): hashlib.sha256(path.read_bytes()).hexdigest() for path in paths}


def changed_inputs(before: dict, after: dict) -> list:
    return sorted(path for path in before.keys() | after.keys() if before.get(path) != after.get(path))


def rounding_evidence() -> dict:
    sys.path.insert(0, str(ROOT / 'recovery/tools'))
    from evidence_image import EvidenceImage
    image = EvidenceImage()
    expected = {
        0x23c2a0: (0x1e600900, 'FMUL d0,d8,d0: multiply original value by 100.0'),
        0x23c2a4: (0x9e640018, 'FCVTAS x24,d0: nearest ties-away signed conversion'),
        0x23dd4c: (0x9e780003, 'FCVTZS x3,d0: separate subLabelForVal conversion still truncates'),
        0x23de6c: (0x1e624000, 'FCVT s0,d0: narrow speed to float before boxing'),
        0x23de74: (0xf9436501, 'LDR x1,[x8,#0x6c8]: numberWithFloat: selector'),
        0x23de78: (0x94000706, 'BL 0x23fa90: boxing call wrapper'),
        0x23de9c: (0xaa1403e3, 'MOV x3,x20: boxed object into wrapper argument'),
        0x23dea0: (0x94000707, 'BL 0x23fabc: format wrapper'),
        0x23fa84: (0x94256018, 'BL objc_msgSend: boxing leaf preserves s0'),
        0x23fa94: (0x97fffffb, 'BL 0x23fa80: boxing wrapper'),
        0x23fac0: (0x97fffff8, 'BL 0x23faa0: variadic adapter'),
        0x23faa8: (0xf90003e3, 'STR x3,[sp]: boxed object as Darwin variadic argument'),
        0x23faac: (0x9425600e, 'BL objc_msgSend: stringWithFormat:'),
    }
    result = {}
    for address, (word, meaning) in expected.items():
        offset = image.image.off(address)
        raw = image.image.data[offset:offset+4]
        if int.from_bytes(raw, 'little') != word:
            raise RuntimeError(f'Original rounding instruction differs at {address:#x}')
        result[hex(address)] = {'word':f'{word:08x}', 'meaning':meaning}
    selector = image.cstring(image.image.ptr(0x114c6c8))
    format_selector = image.cstring(image.image.ptr(0x114b378))
    format_string = image.cfstring(0x11d2690)
    offset = image.image.off(0x114eb00)
    binding = int.from_bytes(image.image.data[offset:offset+8], 'little')
    receiver = image.image.imports[binding & 0xffffff]
    key = int.from_bytes(image.buffer(0x11d2a40,4),'little') ^ 0x0c9c6a16
    if key >= 0x80000000: key -= 0x100000000
    branches = [image.image.ptr(0x11d2a30+i*8)-key for i in range(2)]
    if (selector,format_selector,format_string,receiver,branches) != (
            'numberWithFloat:','stringWithFormat:','%@×','_OBJC_CLASS_$_NSNumber',[0x23dd4c,0x23de64]):
        raise RuntimeError('Original speed-boxing references or style branch differ')
    speed_boxing = {'selector':selector, 'format_selector':format_selector,
                    'format':format_string, 'receiver':receiver,
                    'style_equals_one_targets':[hex(address) for address in branches]}
    return {'speed_boxing':speed_boxing,'sha256':image.sha256, 'raw_original_instructions':result,
            'oracle':'newly compiled native FCVTAS fixture; original dylib never executed'}


def main() -> int:
    rounding = rounding_evidence()
    env = dict(os.environ)
    for key, directory in {
        "CFFIXED_USER_HOME": "home", "TMPDIR": "tmp",
        "XDG_CACHE_HOME": "cache", "CLANG_MODULE_CACHE_PATH": "cache/clang",
    }.items():
        path = WORK / directory
        path.mkdir(parents=True, exist_ok=True)
        env[key] = str(path)
    env["PYTHONDONTWRITEBYTECODE"] = "1"
    env["UBSAN_OPTIONS"] = "halt_on_error=1:print_stacktrace=0"
    directory = WORK / "native"
    directory.mkdir(parents=True, exist_ok=True)
    executable = directory / "presentation_runtime"
    env["LLVM_PROFILE_FILE"] = str(directory / "runtime.profraw")
    sources = [ROOT / "recovery/source/Helpers/YTLHelper.m"] + sorted(
        (ROOT / "recovery/source/Presentation").glob("*.m")) + [
        ROOT / "recovery/tests" / name for name in (
            "presentation_doubles.m", "helpers_dependency_doubles.m",
            "presentation_runtime.m", "helpers_runtime.m", "helper_media_runtime.m",
            "helper_render_runtime.m", "helper_image_runtime.m", "helper_button_runtime.m", "helper_init_runtime.m",
            "helper_terminal_runtime.m", "helper_start_runtime.m", "helper_finish_runtime.m",
            "helper_conversion_paths_runtime.m", "helper_ordering_runtime.m", "helper_assets_runtime.m",
            "helper_mediaflow_runtime.m", "helper_image_feedback_runtime.m", "helper_state_runtime.m")]
    presenter_source = ROOT / 'recovery/source/Presentation/DVNSheetPresenter.m'
    generated_directory = directory / 'availability-boundary'
    generated_directory.mkdir(exist_ok=True)
    generated_presenter = generated_directory / presenter_source.name
    needle = '@available(iOS 15.0, *)'
    original_presenter = presenter_source.read_text()
    if original_presenter.count(needle) != 1:
        raise RuntimeError('Sheet OS-availability fixture boundary changed')
    generated_presenter.write_text('#line 1 "' + str(presenter_source) + '"\n' +
                                  original_presenter.replace(needle, 'PresentationSheetNativeAvailable()'))
    transforms = [{'source':str(presenter_source.relative_to(ROOT)),
                   'generated':str(generated_presenter.relative_to(ROOT)),
                   'source_sha256':hashlib.sha256(presenter_source.read_bytes()).hexdigest(),
                   'generated_sha256':hashlib.sha256(generated_presenter.read_bytes()).hexdigest(),
                   'from':needle,'to':'PresentationSheetNativeAvailable()',
                   'line_mapping':'#line 1 maps diagnostics; report explicitly maps LLVM coverage from generated file to canonical source',
                   'scope':'OS-version boundary only; all method/callback bodies remain actual source'}]
    compile_sources = [generated_presenter if path == presenter_source else path for path in sources]
    command = ["xcrun", "--sdk", "macosx", "clang", "-fobjc-arc", "-fblocks",
               "-Wall", "-Wextra", "-Werror", "-fsanitize=undefined", "-fno-sanitize-recover=all",
               "-fprofile-instr-generate", "-fcoverage-mapping",
               "-I" + str(ROOT / "recovery/tests/presentation_shims"), "-include",
               str(ROOT / "recovery/tests/presentation_redirects.h"),
               "-I" + str(presenter_source.parent), *map(str, compile_sources),
               "-framework", "Foundation", "-framework", "CoreGraphics", "-o", str(executable)]
    source_hashes = {str(path.relative_to(ROOT)):hashlib.sha256(path.read_bytes()).hexdigest() for path in sources}
    support_hashes = support_input_hashes()
    compiled = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, check=False)
    changed_sources = [str(path.relative_to(ROOT)) for path in sources
                       if hashlib.sha256(path.read_bytes()).hexdigest() != source_hashes[str(path.relative_to(ROOT))]]
    changed_sources += changed_inputs(support_hashes, support_input_hashes())
    (directory / "compile.log").write_text(compiled.stdout + compiled.stderr)
    report = {"test_only_source_transforms":transforms,
              "lifecycle_expectation_evidence": {
                  "sheets":"recovery/source/Presentation/SheetLifecycle.provenance.md; verify_sheet_lifecycle.py: original strong captures, nil-coordinator messaging, unconditional completion removal, local delegate lifetime",
                  "player_hide":"recovery/source/Presentation/PlayerToast.lifecycle.provenance.md; hide completion0x23c724 finished branch0x23c770 -> remove0x23c784 without generation gate",
                  "toast_queue":"recovery/tests/toast_construction_fixture.m: synchronous queue and setup reuse; cleanup0x1bfcdc retains completion",
                  "toast_timer":"recovery/source/Presentation/ToastView.lifecycle.provenance.md and recovery/evidence/toast-lifecycle-fidelity.json; original0x1c1d18/0x1c1e4c: run-loop-owned strong-capture timer; hide-delay0x1c28e0/0x1c2944 directly hides current toast",
                  "teardown":"helpers_runtime.m clears preserved callback only after asserting original retention; queued ownership probe clears unexecuted queue only after asserting capture"},"rounding_evidence":rounding,"command": command, "compile_returncode": compiled.returncode,
              "scope": "11 actual source classes; external UI/media/network/transport test doubles",
              "sanitizer": "UndefinedBehaviorSanitizer", "original_code_executed": False,
              "sources": source_hashes,"changed_during_compile":changed_sources,
              "fixture_support_inputs": support_hashes}
    if compiled.returncode or changed_sources:
        print(compiled.stdout + compiled.stderr, file=sys.stderr)
        if changed_sources:print("Source changed during compile: " + ", ".join(changed_sources),file=sys.stderr)
        report["passed"] = False
        (WORK / "runtime-verification.json").write_text(json.dumps(report, indent=2) + "\n")
        return compiled.returncode or 1
    completed = subprocess.run([str(executable)], cwd=ROOT, env=env, capture_output=True, text=True, check=False)
    (directory / "runtime.log").write_text(completed.stdout + completed.stderr)
    print(completed.stdout, end="")
    if completed.stderr:
        print(completed.stderr, file=sys.stderr, end="")
    report["runtime_returncode"] = completed.returncode
    report["passed"] = completed.returncode == 0
    result = WORK / "tmp/runtime-report.json"
    if completed.returncode == 0 and result.exists():
        report["runtime"] = json.loads(result.read_text())
        # This is coverage of this newly compiled fixture executable only. It
        # neither reads nor audits original dylib function-start metadata.
        profile = directory / "runtime.profdata"
        merged = subprocess.run(["xcrun", "llvm-profdata", "merge", "-sparse",
                                 env["LLVM_PROFILE_FILE"], "-o", str(profile)],
                                cwd=ROOT, env=env, capture_output=True, text=True, check=False)
        report["profile_merge_returncode"] = merged.returncode
        if merged.returncode == 0:
            coverage = subprocess.run(["xcrun", "llvm-cov", "export", str(executable),
                                       "-instr-profile=" + str(profile)],
                                      cwd=ROOT, env=env, capture_output=True, text=True, check=False)
            report["coverage_export_returncode"] = coverage.returncode
            if coverage.returncode == 0:
                (directory / "coverage.json").write_text(coverage.stdout)
                data = json.loads(coverage.stdout)
                owned = {str(path.resolve()) for path in sources if "/source/" in str(path)}
                coverage_mapping = {str(generated_presenter.resolve()):str(presenter_source.resolve())}
                report["coverage_source_mapping"] = coverage_mapping
                report["source_coverage"] = {
                    coverage_mapping.get(item["filename"],item["filename"]):item["summary"]
                    for datum in data["data"] for item in datum["files"]
                    if coverage_mapping.get(item["filename"],item["filename"]) in owned}
    changed_during_run = [str(path.relative_to(ROOT)) for path in sources
                          if hashlib.sha256(path.read_bytes()).hexdigest() != source_hashes[str(path.relative_to(ROOT))]]
    changed_during_run += changed_inputs(support_hashes, support_input_hashes())
    report["changed_during_run"] = changed_during_run
    if changed_during_run:
        report["passed"] = False
        print("Source changed during runtime: " + ", ".join(changed_during_run),file=sys.stderr)
    (WORK / "runtime-verification.json").write_text(json.dumps(report, indent=2) + "\n")
    print("Report: .recovery-work/presentation-helpers/runtime-verification.json")
    return completed.returncode or (1 if changed_during_run else 0)


if __name__ == "__main__":
    raise SystemExit(main())
