#!/usr/bin/env python3
"""Preprocess actual source and exercise recovered hooks with the Objective-C runtime."""
import argparse
from pathlib import Path
import subprocess
import tempfile

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--logos',type=Path,required=True);a=p.parse_args()
    repo=Path(__file__).resolve().parents[2];tools=Path(__file__).resolve().parent
    with tempfile.TemporaryDirectory(prefix='ytlite-source-verification-') as work:
        work=Path(work)
        for source in sorted(repo.glob('*.x')):
            with (work/(source.stem+'.mm')).open('w') as out:
                subprocess.run(['perl',str(a.logos),str(source)],stdout=out,check=True)
        source=(repo/'YTLite.x').read_text()
        hooks=source[source.index('%hook YTIPlayabilityStatus'):source.index('%hook YTIElementRenderer')]
        fixture=(tools/'verify_hooks.template.x').read_text().replace('/* RECOVERED_HOOKS */',hooks)
        (work/'hooks.x').write_text(fixture)
        with (work/'hooks.mm').open('w') as out:
            subprocess.run(['perl',str(a.logos),'-c','generator=internal',str(work/'hooks.x')],stdout=out,check=True)
        subprocess.run(['xcrun','clang++','-fobjc-arc','-fblocks','-framework','Foundation',str(work/'hooks.mm'),'-o',str(work/'hooks')],check=True)
        subprocess.run([str(work/'hooks')],check=True)
        # Preferences now depend on the recovered colors, tables and UIKit
        # picker boundary. verify_models.py owns their full runtime fixture.
    print('All four Logos source files preprocessed successfully.')

if __name__=='__main__':main()
