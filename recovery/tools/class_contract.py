#!/usr/bin/env python3
"""Print exact packaged method/property/ivar contracts for named classes."""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('classes', nargs='+')
    args = parser.parse_args()
    classes = {entry['name']: entry for entry in json.loads((ROOT / 'evidence/arm-classes.json').read_text())}
    ivars = json.loads((ROOT / 'evidence/ivars.json').read_text())
    for name in args.classes:
        if name not in classes:
            parser.error(f'No packaged class named {name}')
        entry = classes[name]
        print(f"\n{name} : {entry['superclass']} ({len(entry['methods'])} methods)")
        for method in entry['methods']:
            print(f"  {method['address']:>10} {method['kind']} {method['selector']} | {method['encoding']}")
        print('  PROPERTIES')
        for prop in entry['properties']:
            print(f"    {prop['name']}: {prop['attributes']}")
        print(f"  IVARS (packaged instance size {ivars[name]['instance_size']})")
        for ivar in ivars[name]['ivars']:
            print(f"    {ivar['offset']:#04x} {ivar['name']} : {ivar['encoding']} ({ivar['size']} bytes)")


if __name__ == '__main__':
    main()
