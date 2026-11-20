"""Locate the pinned Logos used by recovery fixtures without temporary paths."""
from pathlib import Path
import subprocess

REVISION = "8cb2f6375c0a975a2b84c440f27f67282b0217b4"
ROOT = Path(__file__).resolve().parents[2]


def logos_path():
    checkout = ROOT / "vendor/recovery-logos"
    script = checkout / "bin/logos.pl"
    if not script.is_file():
        raise RuntimeError("Missing pinned Logos. Follow recovery/REPRODUCE.md setup.")
    revision = subprocess.check_output(
        ["git", "-C", str(checkout), "rev-parse", "HEAD"], text=True).strip()
    if revision != REVISION:
        raise RuntimeError(f"Recovery Logos must be {REVISION}; found {revision}")
    return str(script)
