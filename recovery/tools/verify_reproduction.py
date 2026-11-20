#!/usr/bin/env python3
"""Run the current-source command block in REPRODUCE.md, preserving each log.

Original extraction/decompiler commands are deliberately outside this runner.
Fixtures decide whether a rejected regression is expected; only the enclosing
command exit status determines success. Commands run sequentially because some
fixtures update shared reports.
"""
import datetime
import hashlib
import json
from pathlib import Path
import shlex
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def load_commands(document, root):
    text = document.read_text()
    start = "<!-- current-source-verification -->"
    end = "<!-- /current-source-verification -->"
    if text.count(start) != 1 or text.count(end) != 1:
        raise ValueError("Expected one marked current-source verification block")
    block = text.split(start, 1)[1].split(end, 1)[0].strip()
    if not block.startswith("```sh\n") or not block.endswith("\n```") or block.count("```") != 2:
        raise ValueError("Expected a single shell fence inside verification markers")
    commands = [shlex.split(line) for line in block[6:-4].splitlines() if line.strip()]
    if not commands:
        raise ValueError("Empty current-source verification list")
    for command in commands:
        if len(command) < 2 or command[0] != "python3" or not command[1].endswith(".py"):
            raise ValueError(f"Unsupported reproduction command: {command}")
        script = (root / command[1]).resolve()
        script.relative_to(root.resolve())
        if not script.is_file():
            raise ValueError(f"Missing reproduction script: {command[1]}")
    return commands


def main():
    document = ROOT / "recovery/REPRODUCE.md"
    commands = load_commands(document, ROOT)
    work = ROOT / ".recovery-work/reproduction"
    work.mkdir(parents=True, exist_ok=True)
    report_path = work / "report.json"
    report = {"started": datetime.datetime.now(datetime.timezone.utc).isoformat(),
              "document_sha256": hashlib.sha256(document.read_bytes()).hexdigest(),
              "runner_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
              "status": "running", "commands": [],
              "original_binary_executed": False, "device_validation": "not performed"}
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    for index, command in enumerate(commands, 1):
        log_path = work / f"{index:03d}-{Path(command[1]).stem}.log"
        print(f"[{index}/{len(commands)}] {shlex.join(command)}", flush=True)
        with log_path.open("w") as log:
            result = subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
        report["commands"].append({"command": command, "exit_code": result.returncode,
                                   "log": str(log_path.relative_to(ROOT)),
                                   "log_sha256": hashlib.sha256(log_path.read_bytes()).hexdigest()})
        report_path.write_text(json.dumps(report, indent=2) + "\n")
        print(f"  exit={result.returncode} log={log_path.relative_to(ROOT)}", flush=True)
    report["status"] = "failed" if any(c["exit_code"] for c in report["commands"]) else "passed"
    if hashlib.sha256(document.read_bytes()).hexdigest() != report["document_sha256"]:
        report.update(status="failed", error="Reproduction document changed during run")
    report["finished"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    print(f"{report['status']}: {report_path}", flush=True)
    return int(report["status"] != "passed")


if __name__ == "__main__":
    sys.exit(main())
