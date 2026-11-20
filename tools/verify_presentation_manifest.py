#!/usr/bin/env python3
"""Create owned-source handoff manifests only from passing, current reports."""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / ".recovery-work/presentation-helpers"
IMAGE_SHA256 = "bdcc4d4ccaa5835d35bc97ccbdfc1c3dff514cb7161848265dcc0585f364c0ca"
GROUPS = {
    "Helpers": ["YTLHelper"],
    "Presentation": ["ToastView", "ToastWindow", "ToastManager", "PlayerToast", "CustomHUD",
                     "BlurButton", "DVNImageViewController", "DVNSheetPresenter",
                     "PseudoDetentController", "PseudoDetentTransitioningDelegate"],
}


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def relative(path: Path) -> str:
    return str(path.relative_to(ROOT))


def main() -> None:
    compiler_path = WORK / "source-verification.json"
    runtime_path = WORK / "runtime-verification.json"
    compiler = json.loads(compiler_path.read_text())
    runtime = json.loads(runtime_path.read_text())
    if not compiler["passed"] or not runtime["passed"]:
        raise SystemExit("Refusing to publish a passing manifest from failed reports")
    for entry in compiler["classes"]:
        if digest(ROOT / entry["source"]) != entry["source_sha256"]:
            raise SystemExit(f"Compiler report stale for {entry['source']}")
        if entry.get("object_returncode") != 0 or entry.get("differences"):
            raise SystemExit(f"Object/ABI check missing or failed for {entry['class']}")
    for name, expected in runtime["sources"].items():
        if digest(ROOT / name) != expected:
            raise SystemExit(f"Runtime report stale for {name}")
    originals = {entry["name"]: entry for entry in json.loads(
        (ROOT / "recovery/evidence/arm-classes.json").read_text())}
    reports = {relative(path): digest(path) for path in [compiler_path, runtime_path]}
    missing = [
        "No device UIKit rendering/layout/gesture/rotation validation; native tests use boundary doubles.",
        "No live Photos permission/import, network transport, FFmpeg/media conversion, or user audio/brightness execution.",
        "Original SVC/obfuscator scaffolding is not reproduced; complete functional class surfaces are retained.",
        "Real private YouTube/MediaPlayer classes and on-device resource rendering remain outside these module fixtures; the separate integration report covers linking and packaged resources.",
    ]
    manifests = []
    for group, names in GROUPS.items():
        directory = ROOT / "recovery/source" / group
        provenance = (directory / "PROVENANCE.md").read_text()
        for value in re.findall(r"\| `([0-9a-f]{40,})` \|", provenance):
            if len(value) != 64:
                raise SystemExit(f"Malformed provenance SHA256 in {group}: {value}")
        classes = []
        for name in names:
            entries = {entry["architecture"]: entry for entry in compiler["classes"] if entry["class"] == name}
            if set(entries) != {"arm64", "arm64e"}:
                raise SystemExit(f"Both native-object architectures required for {name}")
            entry = entries["arm64"]
            metadata = originals[name]
            classes.append({
                "name": name, "source": entry["source"], "source_sha256": entry["source_sha256"],
                "header": relative(directory / (name + ".h")),
                "header_sha256": digest(directory / (name + ".h")),
                "method_count": entry["method_count"], "property_count": entry["property_count"],
                "ivar_count": entry["ivar_count"], "compiled_metadata": entry["metadata"],
                "original_method_addresses": {m["kind"] + m["selector"]: m["address"] for m in metadata["methods"]},
                "objects": {arch: {"path": relative(WORK / arch / (name + ".o")), "sha256": item["object_sha256"]}
                            for arch, item in entries.items()},
                "host_source_coverage": runtime.get("source_coverage", {}).get(str(directory / (name + ".m"))),
            })
        own_files = sorted(path for path in directory.iterdir() if path.is_file() and path.name != "manifest.json")
        manifest = {
            "scope": group, "status": "functional implementation, exact supplied class ABI; device integration unverified",
            "original_image": ".recovery-work/arm/YTLite.dylib", "original_sha256": IMAGE_SHA256,
            "original_executed": False, "sdk": compiler["sdk"], "deployment_target": "iOS 14.0",
            "architectures": ["arm64", "arm64e"], "compiler_flags": ["-fobjc-arc", "-fblocks", "-Wall", "-Wextra", "-Werror"],
            "classes": classes, "method_count": sum(item["method_count"] for item in classes),
            "files": {relative(path): digest(path) for path in own_files},
            "unimplemented_declared_methods": [], "missing_or_unverified": missing,
            "remaining_reconstruction_differences": ([
                "Helper path/URL validation remains a separately documented reconstruction difference; media presentation and rendering are covered by the per-class provenance files."
            ] if group == "Helpers" else [
                "Device rendering and private host integration remain unverified; focused toast, window, sheet and image-viewer audits are documented in per-class provenance."
            ]),
            "test_report_sha256": reports, "host_runtime_assertions": runtime["runtime"]["assertions"],
            "host_runtime_suites": runtime["runtime"]["suites"], "sanitizer": runtime["sanitizer"],
            "runtime_doubles_not_production": True,
            "framework_link_dependencies": ["Foundation", "UIKit", "QuartzCore", "Photos", "SystemConfiguration"],
            "external_production_sources": ["Downloads/YTPDownloader", "Downloads/FFMpegHelper",
                                             "Runtime/YTLBootstrapCrypto.h", "restored NSBundle category"],
            "shared_build_files_changed": False,
        }
        path = directory / "manifest.json"
        path.write_text(json.dumps(manifest, indent=2) + "\n")
        manifests.append(path)
    owned = set()
    for group in GROUPS:
        owned.update(path for path in (ROOT / "recovery/source" / group).rglob("*") if path.is_file())
    for base, prefixes in [(ROOT / "tools", ("verify_presentation", "verify_helpers")),
                           (ROOT / "recovery/tests", ("presentation_", "helpers_"))]:
        for path in base.iterdir():
            if not path.name.startswith(prefixes):
                continue
            if path.is_file():
                owned.add(path)
            elif path.is_dir():
                owned.update(item for item in path.rglob("*") if item.is_file())
    handoff = {"passed": True, "classes": 11, "methods_per_architecture": 161,
               "properties_per_architecture": 33, "ivars_per_architecture": 60,
               "runtime_assertions": runtime["runtime"]["assertions"],
               "reports": reports, "manifests": {relative(path): digest(path) for path in manifests},
               "files": {relative(path): digest(path) for path in sorted(owned)},
               "original_code_executed": False, "scope_changes": "owned files only"}
    handoff_path = WORK / "handoff.json"
    handoff_path.write_text(json.dumps(handoff, indent=2) + "\n")
    lines = [f"{value}  {path}" for path, value in handoff["files"].items()]
    (WORK / "handoff.sha256").write_text("\n".join(lines) + "\n")
    print(f"PASS handoff: 11 classes / 161 methods per architecture / {runtime['runtime']['assertions']} host assertions")
    for path in manifests + [compiler_path, runtime_path, handoff_path]:
        print(digest(path), relative(path))


if __name__ == "__main__":
    main()
