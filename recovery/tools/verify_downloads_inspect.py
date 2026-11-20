#!/usr/bin/env python3
"""Use the repository's read-only binary annotator with worker-local output paths."""
import sys
from pathlib import Path
root = Path(__file__).resolve().parents[2]
sys.dont_write_bytecode = True
sys.path.insert(0, str(root / 'recovery/tools'))
source = (root / 'recovery/tools/inspect_binary.py').read_text()
source = source.replace("REPO / '.recovery-work/analysis'", "REPO / '.recovery-work/downloads/assembly'")
exec(compile(source, str(root / 'recovery/tools/inspect_binary.py'), 'exec'), {'__name__': '__main__', '__file__': str(root / 'recovery/tools/inspect_binary.py')})
