# DVNMediaPicker recovery

`DVNMediaPicker.m` restores all nine packaged methods, including the ARC destructor. It is included in `recovered.mk`. The recovered settings builder already calls `sharedPicker` and `presentImagePickerForVC:` through class lookup.

The original Photos picker selects one **video**, despite its image-picker selector name. Its provider callback rejects durations greater than ten seconds. Accepted files are copied before the provider callback returns, then installed as `Documents/startup_animation.<extension>` on the main queue. Installation removes the previous `.mp4` and `.mov` animations, copies the selected file, and removes the input on success. Copy failure preserves the error toast and log behavior.

The document picker imports the original 30 media UTIs. Exactly one URL follows the startup-animation path; every other count opens the folder-import dialog. Imports keep existing destination files and report partial success on copy errors. Both import completion and cancellation remove temporary directories whose names begin with the application's inbox prefix. Single-animation installation removes only the exact inbox directory name.

`manifest.json` records the packaged method addresses, seven callback roles and hashes of original instruction intervals. The independent readable exports are in `.recovery-work/readable/analysis-v3/001a*.c`; original pseudocode remains in `recovery/classes/DVNMediaPicker.c` and `recovery/decompiled/`.

Reconstruction changes:

- Same-location guards prevent removing a temporary copy or startup animation that is itself the input.
- Folder names are resolved beneath Documents; paths or existing symlinks that escape it are rejected.
- The import action weakly captures its alert to avoid an ownership cycle.
- Obfuscator supervisor calls are excluded.

Run `python3 recovery/tools/verify_media_picker.py`. The checks compile the actual implementation for iOS, compare all method encodings, four inherited protocol properties and the controller ivar against the binary, then execute 94 assertions on macOS. File copies, collisions, removal and errors use real Foundation operations under temporary fixtures. UIKit, Photos picker results, media durations and toasts are test doubles. Actual device UI, Photos access and YouTube integration remain untested.

The factory fidelity audit corrected `sharedPicker` to use `[[self alloc] init]`. Original block `0x1a3254` loads the captured receiver at `0x1a325c` and calls `_objc_alloc_init` at `0x1a3260`, through thunk `0x1a9564`. It never dispatches `+new`. The whole-source fixture now calls through a subclass first, whose `+new` and `-init` counters distinguish the paths, and confirms one shared instance remains shared with both the base class and another subclass. The pre-fix source failed the `+new` counter assertion. The fixture also runs with UndefinedBehaviorSanitizer. Original factory hashes and target evidence are in `recovery/tests/factory_audit_evidence.json`.
