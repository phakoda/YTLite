#!/usr/bin/env python3
"""Build the production settings table into a UIKit simulator fixture, and run it.

Pass a simulator UUID. Leaves the fixture open for manual light/dark/Dynamic Type
inspection. Report and screenshots live under .recovery-work/settings-preview.
"""
import argparse,json,plistlib,subprocess,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser(description=__doc__);p.add_argument('device');p.add_argument('--appearance',choices=['light','dark'],default='light');p.add_argument('--content-size',default='large');a=p.parse_args()
work=ROOT/'.recovery-work/settings-preview';app=work/'SettingsPreview.app';app.mkdir(parents=True,exist_ok=True)
identifier='com.phakoda.YTLite.SettingsPreview'
with (app/'Info.plist').open('wb') as f:
    plistlib.dump(dict(CFBundleIdentifier=identifier,CFBundleName='Settings Preview',CFBundleExecutable='SettingsPreview',CFBundlePackageType='APPL',CFBundleVersion='1',CFBundleShortVersionString='1.0',MinimumOSVersion='14.0',LSRequiresIPhoneOS=True,UILaunchScreen={},UIDeviceFamily=[1,2]),f)
sdk=subprocess.check_output(['xcrun','--sdk','iphonesimulator','--show-sdk-path'],text=True).strip()
generated=work/'ContentLayout.m'
logos=ROOT/'vendor/recovery-logos/bin/logos.pl'
with generated.open('w') as out:
    subprocess.run(['perl',str(logos),'-c','generator=internal',str(ROOT/'recovery/source/Hooks/ContentLayout.x')],stdout=out,check=True)
sources=[str(generated),'recovery/tests/content_layout_host.m','recovery/tests/settings_preview.m','recovery/source/Settings/DVNTableViewController.m','recovery/source/Settings/YTPTableViewCell.m','recovery/source/Settings/DVNPickerView.m',*[f'recovery/source/Models/{name}.m' for name in ['DVNCell','DVNSection','DVNTableModel']]]
subprocess.run(['xcrun','clang','-isysroot',sdk,'-target','arm64-apple-ios14.0-simulator','-fobjc-arc','-fblocks','-I',str(ROOT/'recovery/source/Hooks'),'-Werror','-Wno-deprecated-declarations',*sources,'-framework','UIKit','-framework','Foundation','-framework','QuartzCore','-framework','CoreGraphics','-o',str(app/'SettingsPreview')],cwd=ROOT,check=True)
subprocess.run(['codesign','--force','--sign','-',str(app)],check=True)
subprocess.run(['xcrun','simctl','boot',a.device],capture_output=True)
subprocess.run(['xcrun','simctl','bootstatus',a.device,'-b'],check=True)
subprocess.run(['xcrun','simctl','ui',a.device,'appearance',a.appearance],check=True)
subprocess.run(['xcrun','simctl','ui',a.device,'content_size',a.content_size],check=True)
subprocess.run(['xcrun','simctl','install',a.device,str(app)],check=True)
subprocess.run(['xcrun','simctl','terminate',a.device,identifier],capture_output=True)
container=Path(subprocess.check_output(['xcrun','simctl','get_app_container',a.device,identifier,'data'],text=True).strip())
report=container/'Documents/layout-report.json'
report.unlink(missing_ok=True)
subprocess.run(['xcrun','simctl','launch',a.device,identifier],check=True)
for attempt in range(20):
    if report.exists(): break
    time.sleep(0.5)
data=json.loads(report.read_text());(work/'layout-report.json').write_text(json.dumps(data,indent=2)+'\n');print(data)
subprocess.run(['xcrun','simctl','io',a.device,'screenshot',str(work/f'settings-{a.appearance}-{a.content_size}.png')],check=True)
assert not data['errors'],data
print('Actual UIKit layout and switch-row interaction passed:',work)
