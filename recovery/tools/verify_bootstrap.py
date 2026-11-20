#!/usr/bin/env python3
"""Offline tests of restored crypto and authorization; never accesses real keys."""
import base64
import hashlib
import json
import os
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[2]


def main():
    work = REPO / '.recovery-work/bootstrap-tests'
    work.mkdir(parents=True, exist_ok=True)
    env = os.environ.copy()
    for variable, name in (('TMPDIR', 'tmp'), ('HOME', 'home'), ('CFFIXED_USER_HOME', 'home'),
                           ('CLANG_MODULE_CACHE_PATH', 'module-cache'), ('SWIFT_MODULECACHE_PATH', 'swift-cache')):
        path = work / name; path.mkdir(exist_ok=True); env[variable] = str(path)
    logs = []
    report_path = work / 'report.json'
    if report_path.exists(): report_path.unlink()

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, cwd=REPO, env=env, text=True,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        logs.append({'command': command, 'exit_code': result.returncode, 'output': result.stdout})
        (work / 'commands.json').write_text(json.dumps(logs, indent=2) + '\n')
        print(result.stdout, end='', flush=True)
        result.check_returncode()
        return result.stdout.strip()

    run(['python3', REPO / 'recovery/tools/recover_bootstrap_constants.py'])
    constants = json.loads((REPO / 'recovery/evidence/bootstrap-constants.json').read_text())
    pepper = constants['pepper']
    derive = lambda password, salt: hashlib.pbkdf2_hmac('sha256',
        (('(null)' if password is None else password) + ':' + pepper).encode('utf-8'), salt, 10000, 32)
    salt, nonce = bytes(range(16)), bytes(range(32, 44))
    vendor = '00112233-4455-6677-8899-AABBCCDDEEFF'
    derivations = [{'password': text, 'salt': salt.hex(), 'key': derive(text, salt).hex()}
                   for text in ('', 'password', 'Unicode 🔥', None)]
    records = []
    for name, password, plaintext in [('token', 'fixture-device-id', b'fixture.jwt.value'),
                                      ('device-id', vendor, b'fixture-device-id'),
                                      ('unknown-device-id', 'unknown', b'fixture-device-id'),
                                      ('one-byte', '', b'x'), ('unicode', 'Unicode 🔥', 'héllo 😃'.encode()),
                                      ('empty', 'password', b''), ('invalid-utf8', 'password', bytes([0xff, 0xfe]))]:
        records.append({'name': name, 'password': password, 'salt': salt.hex(), 'nonce': nonce.hex(),
                        'key': derive(password, salt).hex(), 'plaintext_base64': base64.b64encode(plaintext).decode()})
    fixtures = work / 'fixtures-input.json'
    fixtures.write_text(json.dumps({'vendor': vendor, 'derivations': derivations, 'records': records}, ensure_ascii=False, indent=2) + '\n')
    swift = REPO / 'recovery/tests/bootstrap_vectors.swift'
    generator = work / 'fixture-generator'
    run(['xcrun', 'swiftc', '-module-cache-path', env['SWIFT_MODULECACHE_PATH'], swift, '-o', generator])
    run([generator, fixtures, work / 'fixtures.json'])
    source = REPO / 'recovery/source/Runtime/YTLBootstrapCrypto.m'
    dependencies = [REPO / 'recovery/source/Runtime/YTLFeaturePolicy.m',
                    REPO / 'Utils/YTLUserDefaults.m', REPO / 'recovery/source/Support/YTPDB.m',
                    REPO / 'recovery/source/YTLUserDefaults+RecoveredDefaults.m', REPO / 'recovery/tests/UIKitDoubles.m']
    flags = ['-fobjc-arc', '-fblocks', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter']
    host_object = work / 'bootstrap.host.o'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-DYTL_BOOTSTRAP_TESTING',
         '-DCCKeyDerivationPBKDF=YTLTestDeriveKey', '-DCCCryptorGCM=YTLTestCryptorGCM',
         '-DSecItemCopyMatching=YTLTestSecItemCopyMatching', '-DSecItemDelete=YTLTestSecItemDelete',
         '-DSecItemAdd=YTLTestSecItemAdd', '-Darc4random_buf=YTLTestArc4RandomBuf',
         '-c', source, '-o', host_object])
    executable = work / 'bootstrap-test'
    run(['xcrun', '--sdk', 'macosx', 'clang', *flags, '-I', REPO / 'recovery/tests/shims',
         '-framework', 'Foundation', '-framework', 'Security', host_object, *dependencies,
         REPO / 'recovery/tests/bootstrap.m', '-o', executable])
    run([executable, work / 'fixtures.json'])
    sdk = run(['xcrun', '--sdk', 'iphoneos', '--show-sdk-path'])
    obj = work / 'bootstrap.ios.o'
    run(['xcrun', '--sdk', 'iphoneos', 'clang', *flags, '-target', 'arm64-apple-ios14.0',
         '-isysroot', sdk, '-c', source, '-o', obj])
    symbols = run(['xcrun', 'nm', obj])
    if 'YTLBootstrapTestResetCache' in symbols or 'YTLTest' in symbols:
        raise ValueError('Test replacements leaked into the production object')
    inputs = [source, swift, REPO / 'recovery/tests/bootstrap.m', *dependencies, Path(__file__).resolve()]
    inputs += list((REPO / 'recovery/source/Runtime').glob('*.h')) + list((REPO / 'recovery/source/Runtime').glob('*.inc'))
    report = {'source_sha256': {str(path.relative_to(REPO)): hashlib.sha256(path.read_bytes()).hexdigest() for path in inputs},
              'crypto_vectors': 'Python hashlib PBKDF2; CryptoKit AES-GCM encryption',
              'historical_crypto_and_local_only_preference_tests': 'passed', 'ios_arm64_compile': 'passed',
              'feature_requires_sign_in': False, 'feature_honors_legacy_suspension': False,
              'real_keychain_access': 'not performed', 'server_authentication': 'not performed',
              'bootstrap_lifecycle_and_hook_integration': 'not established'}
    report_path.write_text(json.dumps(report, indent=2) + '\n')
    print('Historical crypto and unrestricted local preference reads passed offline tests and iOS compilation.')


if __name__ == '__main__':
    main()
