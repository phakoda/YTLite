#!/usr/bin/env python3
"""Run local-fork regression checks against the actual playback/layout helpers."""
from pathlib import Path
import subprocess
ROOT = Path(__file__).resolve().parents[1]
work = ROOT / '.recovery-work/local-features'
work.mkdir(parents=True, exist_ok=True)
output = work/'preferences'
subprocess.run(['xcrun','--sdk','macosx','clang','-fobjc-arc','-fblocks','-Wall','-Wextra','-Werror',
                '-fsanitize=undefined',str(ROOT/'recovery/tests/playback_preferences.m'),
                '-framework','Foundation','-o',str(output)],check=True)
subprocess.run([output],check=True)
# Source wiring checks complement the runtime tests; they do not replace device UI validation.
startup = (ROOT/'recovery/source/Hooks/StartupLifecycle.x').read_text().split('void YTLScheduleWelcome(void) {')[1].split('// Ordinary defaults tail')[0]
assert 'presentViewController:' not in startup
for path in [ROOT/'control',ROOT/'Resources/depiction.json',*list((ROOT/'recovery/source').rglob('*.m')),*list((ROOT/'recovery/source').rglob('*.x'))]:
    assert 'dayanch96' not in path.read_text().lower(), path
print('Local feature regressions and promotion checks passed')
