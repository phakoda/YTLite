#!/usr/bin/env python3
"""Compile only owned Helpers/Presentation sources and compare emitted ObjC ABI.

This checks compiler-generated method/property/ivar records against the supplied
class metadata. It does not read or audit original binary function starts.
Every compiler output, temporary file, and configured cache stays inside the repo.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
WORK = ROOT / ".recovery-work/presentation-helpers"
CLASSES = {
    "YTLHelper": "Helpers", "ToastView": "Presentation", "ToastWindow": "Presentation",
    "ToastManager": "Presentation", "PlayerToast": "Presentation", "CustomHUD": "Presentation",
    "BlurButton": "Presentation", "DVNImageViewController": "Presentation",
    "DVNSheetPresenter": "Presentation", "PseudoDetentController": "Presentation",
    "PseudoDetentTransitioningDelegate": "Presentation",
}
IDENTIFIER = r'(?:"(?:[^"\\]|\\[0-9A-Fa-f]{2})*"|[-a-zA-Z$._0-9]+)'


def environment() -> dict[str, str]:
    env = dict(os.environ)
    for key, directory in {
        "CFFIXED_USER_HOME": "home", "TMPDIR": "tmp",
        "XDG_CACHE_HOME": "cache", "CLANG_MODULE_CACHE_PATH": "cache/clang",
    }.items():
        path = WORK / directory
        path.mkdir(parents=True, exist_ok=True)
        env[key] = str(path)
    env["PYTHONDONTWRITEBYTECODE"] = "1"
    return env


def run(command: list[str], env: dict[str, str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, check=False)


def decode_llvm(value: str) -> str:
    # LLVM c"" escapes are bytes, not Python escape sequences.
    output = bytearray()
    index = 0
    while index < len(value):
        if value[index] == "\\":
            output.append(int(value[index + 1:index + 3], 16))
            index += 3
        else:
            output += value[index].encode()
            index += 1
    return bytes(output).rstrip(b"\0").decode("utf-8")


def emitted_metadata(text: str, name: str) -> dict:
    strings = {match[1]: decode_llvm(match[2]) for match in re.finditer(
        rf'^@({IDENTIFIER}) = .*?\bc"((?:[^"\\]|\\[0-9A-Fa-f]{{2}})*)"', text, re.MULTILINE)}

    def table(symbol: str) -> str:
        match = re.search(r'^@"' + re.escape(symbol) + r'" = (.*)$', text, re.MULTILINE)
        return match[1] if match else ""

    methods = {}
    for prefix, kind in (("CLASS", "+"), ("INSTANCE", "-")):
        content = table(f"_OBJC_$_{prefix}_METHODS_{name}")
        for match in re.finditer(rf'%struct\._objc_method\s*\{{\s*ptr @({IDENTIFIER}),\s*ptr @({IDENTIFIER}),', content):
            methods[kind + strings[match[1]]] = strings[match[2]]
    properties = {}
    for match in re.finditer(rf'%struct\._prop_t\s*\{{\s*ptr @({IDENTIFIER}),\s*ptr @({IDENTIFIER})\s*\}}',
                             table(f"_OBJC_$_PROP_LIST_{name}")):
        properties[strings[match[1]]] = strings[match[2]]
    ivars = {}
    for match in re.finditer(rf'%struct\._ivar_t\s*\{{\s*ptr @({IDENTIFIER}),\s*ptr @({IDENTIFIER}),\s*ptr @({IDENTIFIER}),\s*i32 (\d+),\s*i32 (\d+)\s*\}}',
                             table(f"_OBJC_$_INSTANCE_VARIABLES_{name}")):
        offset = re.search(r'^@' + re.escape(match[1]) + r' = .*?i(?:32|64) (\d+)', text, re.MULTILINE)
        if not offset:
            raise ValueError(f"Missing emitted offset {match[1]}")
        ivars[strings[match[2]]] = {"encoding": strings[match[3]], "offset": int(offset[1]), "size": int(match[5])}
    record = table(f"_OBJC_CLASS_RO_$_{name}")
    size = re.search(r'\{ i32 \d+, i32 \d+, i32 (\d+)', record)
    if not methods or not size:
        raise ValueError(f"Missing generated class metadata for {name}")
    return {"methods": methods, "properties": properties, "ivars": ivars, "instance_size": int(size[1])}


def difference(expected: dict, actual: dict) -> dict:
    return {key: {"expected": expected.get(key), "actual": actual.get(key)}
            for key in sorted(expected.keys() | actual.keys()) if expected.get(key) != actual.get(key)}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--arch", choices=["arm64", "arm64e"], action="append")
    parser.add_argument("--class", choices=sorted(CLASSES), dest="classes", action="append")
    args = parser.parse_args()
    env = environment()
    sdk_result = run(["xcrun", "--sdk", "iphoneos", "--show-sdk-path"], env)
    if sdk_result.returncode:
        print(sdk_result.stderr, file=sys.stderr)
        return sdk_result.returncode
    sdk = sdk_result.stdout.strip()
    version = run(["xcrun", "--sdk", "iphoneos", "--show-sdk-version"], env).stdout.strip()
    expected_classes = {item["name"]: item for item in json.loads((ROOT / "recovery/evidence/arm-classes.json").read_text())}
    expected_ivars = json.loads((ROOT / "recovery/evidence/ivars.json").read_text())
    report = {"sdk": version, "target_minimum": "iOS 14.0", "original_code_executed": False,
              "scope": "owned-source compiler metadata, not original function starts", "classes": []}
    failed = False
    for architecture in args.arch or ["arm64", "arm64e"]:
        directory = WORK / architecture
        directory.mkdir(parents=True, exist_ok=True)
        for name in args.classes or CLASSES:
            source = ROOT / "recovery/source" / CLASSES[name] / (name + ".m")
            ir = directory / (name + ".ll")
            command = ["xcrun", "--sdk", "iphoneos", "clang", "-target", f"{architecture}-apple-ios14.0",
                       "-isysroot", sdk, "-fobjc-arc", "-fblocks", "-Wall", "-Wextra", "-Werror",
                       "-S", "-emit-llvm", str(source), "-o", str(ir)]
            result = run(command, env)
            (directory / (name + ".log")).write_text(result.stdout + result.stderr)
            entry = {"class": name, "architecture": architecture, "source": str(source.relative_to(ROOT)),
                     "source_sha256": hashlib.sha256(source.read_bytes()).hexdigest(),
                     "compile_returncode": result.returncode, "command": command}
            report["classes"].append(entry)
            if result.returncode:
                failed = True
                print(f"FAIL {architecture} {name}: compiler\n{result.stderr}")
                continue
            object_path = directory / (name + ".o")
            object_command = ["xcrun", "--sdk", "iphoneos", "clang", "-target", f"{architecture}-apple-ios14.0",
                              "-isysroot", sdk, "-fobjc-arc", "-fblocks", "-Wall", "-Wextra", "-Werror",
                              "-c", str(source), "-o", str(object_path)]
            object_result = run(object_command, env)
            (directory / (name + ".object.log")).write_text(object_result.stdout + object_result.stderr)
            entry["object_command"] = object_command
            entry["object_returncode"] = object_result.returncode
            if object_result.returncode:
                failed = True
                print(f"FAIL {architecture} {name}: native object compiler\n{object_result.stderr}")
                continue
            entry["object_sha256"] = hashlib.sha256(object_path.read_bytes()).hexdigest()
            actual = emitted_metadata(ir.read_text(), name)
            cls = expected_classes[name]
            expected = {"methods": {item["kind"] + item["selector"]: item["encoding"] for item in cls["methods"]},
                        "properties": {item["name"]: item["attributes"] for item in cls["properties"]},
                        "ivars": {item["name"]: {key: item[key] for key in ("encoding", "offset", "size")}
                                  for item in expected_ivars[name]["ivars"]},
                        "instance_size": expected_ivars[name]["instance_size"]}
            delta = {key: difference(expected[key], actual[key]) for key in ("methods", "properties", "ivars")}
            if expected["instance_size"] != actual["instance_size"]:
                delta["instance_size"] = {"expected": expected["instance_size"], "actual": actual["instance_size"]}
            delta = {key: value for key, value in delta.items() if value}
            entry.update({"method_count": len(actual["methods"]), "property_count": len(actual["properties"]),
                          "ivar_count": len(actual["ivars"]), "metadata": actual, "differences": delta})
            failed |= bool(delta)
            print(f"{'FAIL' if delta else 'PASS'} {architecture} {name}: "
                  f"{len(actual['methods'])} methods, {len(actual['properties'])} properties, {len(actual['ivars'])} ivars")
            if delta:
                print(json.dumps(delta, indent=2))
    report["passed"] = not failed
    path = WORK / "source-verification.json"
    path.write_text(json.dumps(report, indent=2) + "\n")
    print(f"Report: {path.relative_to(ROOT)}")
    return int(failed)


if __name__ == "__main__":
    raise SystemExit(main())
