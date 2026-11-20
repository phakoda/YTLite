# Reproduce the recovery

Run the following commands from the repository root. Generated evidence, interfaces, class views, hook views, and the defaults reconstruction are overwritten on rerun.

## Extract and verify all three packages

Use Python 3.12 or newer and Apple's command-line developer tools:

```sh
python3 recovery/tools/run.py \
  --packages /Users/moussah/Downloads \
  --work /tmp/ytlite-recovery-rerun
```

This command does not access the network or execute the dylib. It extracts package contents, checks method metadata against `nm`, decodes strings independently in all three binaries, and derives the analysis branch resolutions.

## Recreate the decompiler exports

Use Ghidra 12.0.4 with Java 21. Supply its installation directory if `ghidraRun` is not on your path:

```sh
python3 recovery/tools/run.py \
  --packages /Users/moussah/Downloads \
  --work /tmp/ytlite-recovery-rerun \
  --decompile \
  --ghidra /opt/homebrew/Cellar/ghidra/12.0.4/libexec
```

Keep the complete package set together. The detailed branch addresses and defaults reconstruction target the canonical `iphoneos-arm` package. The supplied package hashes are recorded in `evidence/packages.json`.

After the first export, rerun the same command once. The first pass maps hook registrations. The second pass can create functions at callback addresses that Ghidra initially treated as data. Then regenerate the coverage report:

```sh
python3 recovery/tools/report.py
```

The analysis transforms resolve call wrappers and constant branch tables. For Boolean-indexed branches, the generated analysis islands retain both destinations and test a register whose value is proven to be zero or one. For constant string initialization, the analysis copy receives the decoded bytes before following the initialized path. Every transform is recorded under `evidence/`.

## Verify the current reconstructed source

From the repository root, install the fixture preprocessor once:

```sh
git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' clone https://github.com/theos/logos.git vendor/recovery-logos
git -C vendor/recovery-logos checkout --detach 8cb2f6375c0a975a2b84c440f27f67282b0217b4
```

The hook fixtures resolve this pinned checkout through `logos_tool.py`. Run the
complete current-source list with `python3 recovery/tools/verify_reproduction.py`,
which preserves command exit codes and logs under `.recovery-work/reproduction/`.
Expected regression rejections are interpreted by each fixture, not by log text.
The underlying commands are:


<!-- current-source-verification -->
```sh
python3 recovery/tests/test_reproduction_runner.py
python3 recovery/tests/test_package_deb.py
python3 recovery/tools/source_inventory.py
python3 recovery/tools/compare_supplied_packages.py
python3 recovery/tools/verify_first_bundle.py
python3 recovery/tools/verify_media_picker.py
python3 recovery/tools/verify_sleep_timer.py
python3 recovery/tools/hook_inventory.py
python3 recovery/tools/verify_bundles.py
python3 recovery/tools/verify_objc_categories.py
python3 recovery/tools/verify_packaged_resources.py
python3 tools/verify_settings.py
python3 recovery/tools/verify_configuration_hooks.py
python3 recovery/tools/verify_bootstrap_helpers.py
python3 recovery/tools/verify_speed_master.py
python3 recovery/tools/verify_speed_control.py
python3 recovery/tools/verify_speed_popup.py
python3 recovery/tools/verify_navigation_helpers.py
python3 recovery/tools/verify_translator_ui.py
python3 recovery/tools/verify_factory_audit.py
python3 recovery/tools/verify_toast_manager_lifecycle.py
python3 recovery/tools/verify_toast_construction.py
python3 recovery/tools/verify_toast_lifecycle.py
python3 recovery/tools/verify_player_toast_lifecycle.py
python3 recovery/tools/verify_sheet_lifecycle.py
python3 recovery/tools/verify_toast_geometry.py
python3 recovery/tools/verify_toast_window.py
python3 recovery/tools/verify_image_viewer_ui.py
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_first_helper_progress.py
python3 recovery/tools/verify_first_helper_progress.py --conversion
python3 recovery/tools/verify_first_helper_progress.py --buttons
python3 recovery/tools/verify_first_helper_progress.py --init
python3 recovery/tools/verify_first_helper_progress.py --terminal
python3 recovery/tools/verify_first_helper_progress.py --start
python3 recovery/tools/verify_first_helper_progress.py --finish
python3 recovery/tools/verify_first_helper_progress.py --paths
python3 recovery/tools/verify_first_helper_progress.py --ordering
python3 recovery/tools/verify_first_helper_progress.py --assets
python3 recovery/tools/verify_first_helper_progress.py --mediaflow
python3 recovery/tools/verify_first_helper_progress.py --imageflow
python3 recovery/tools/verify_first_helper_progress.py --state
python3 recovery/tools/verify_first_media.py
python3 recovery/tools/verify_first_media_icons.py
python3 recovery/tools/verify_first_audio_manager.py
python3 recovery/tools/verify_first_menu_pipeline.py
python3 recovery/tools/verify_first_menu_audio.py
python3 recovery/tools/verify_first_menu_parsers.py
python3 recovery/tools/verify_first_menu_formats.py
python3 recovery/tools/verify_first_menu_video_selection.py
python3 recovery/tools/verify_first_menu_thumbnail.py
python3 recovery/tools/verify_first_menu_storage.py
python3 recovery/tools/verify_first_menu_audio_selector.py
python3 recovery/tools/verify_first_menu_captions.py
python3 recovery/tools/verify_first_menu_caption_flow.py
python3 recovery/tools/verify_first_menu_images.py
python3 recovery/tools/verify_first_menu_information.py
python3 recovery/tools/verify_first_menu_external_player.py
python3 recovery/tools/verify_first_menu_video_sheet.py
python3 recovery/tools/verify_first_menu_shorts.py
python3 recovery/tools/verify_first_menu_normal_construction.py
python3 recovery/tools/verify_first_ffmpeg_construction.py
python3 recovery/tools/verify_first_ffmpeg_progress.py
python3 recovery/tools/verify_first_ffmpeg_log.py
python3 recovery/tools/verify_first_ffmpeg_command.py
python3 recovery/tools/verify_first_ffmpeg_lifecycle.py
python3 recovery/tools/verify_first_model_accessors.py
python3 recovery/tools/verify_first_cell_lifecycle.py
python3 recovery/tools/verify_first_cell_factory_order.py
python3 recovery/tools/verify_first_cell_factories.py
python3 recovery/tools/first_package_audit_inventory.py
python3 tools/build_local.py package --scheme roothide
python3 recovery/tools/verify_roothide_package.py
python3 recovery/tools/verify_helper_media.py
python3 recovery/tools/verify_helper_media.py --rendering
python3 recovery/tools/verify_helper_media.py --image
python3 recovery/tools/verify_settings_bridge.py
python3 recovery/tools/verify_player_controls.py
python3 recovery/tools/verify_player_lifecycle.py
python3 recovery/tools/verify_discord_lifecycle.py
python3 recovery/tools/verify_playerbar_hooks.py
python3 recovery/tools/verify_sponsor_playback.py
python3 recovery/tools/verify_shorts_playback.py
python3 recovery/tools/verify_player_overlay.py
python3 recovery/tools/verify_shorts_interface.py
python3 recovery/tools/verify_feed_nodes.py
python3 recovery/tools/verify_feed_filtering.py
python3 recovery/tools/verify_image_gestures.py
python3 recovery/tools/verify_theme_styles.py
python3 recovery/tools/verify_navigation_chrome.py
python3 recovery/tools/verify_compatibility_version.py
python3 recovery/tools/verify_media_policy.py
python3 recovery/tools/verify_media_services.py
python3 recovery/tools/verify_playback_options.py
python3 recovery/tools/verify_native_share.py
python3 recovery/tools/verify_remote_controls.py
python3 recovery/tools/verify_general_interface.py
python3 recovery/tools/verify_startup_lifecycle.py
python3 recovery/tools/verify_sideload_compatibility.py
python3 recovery/tools/verify_sideload_identity.py
python3 recovery/tools/verify_sideload_entrypoint.py
python3 recovery/tools/verify_registration_calls.py
python3 recovery/tools/verify_registration_resolutions.py
python3 recovery/tools/verify_hook_entrypoints.py
python3 tools/build_ffmpeg_recovery.py --verify-only
python3 tools/build_local.py all
python3 recovery/tools/verify_recovery_integration.py
```
<!-- /current-source-verification -->

The inventory compiles the selected Objective-C source and compares method sets and encodings against the package. The module suites additionally check original-byte evidence and execute the implementations with isolated host boundaries. They store commands, reports and source hashes under `.recovery-work/`.

The full build now links with the genuine standalone MobileFFmpeg dependency rebuilt from pinned source. `tools/build_ffmpeg_recovery.py` documents and performs that dependency build; `--verify-only` checks the existing output. Linking and host fixtures do not establish on-device behavior. The selected sources are listed in `recovery/source/recovered.mk`; do not compile decompiler `.c` exports or duplicate historical reconstructions.

Package creation uses `tools/package_deb.py` to copy the stage to `/tmp` before
running Theos's Debian writer. This supports ExFAT checkouts that cannot retain
Unix directory modes. The final archive stays under `packages/`; temporary
files are removed after packaging. See [package construction and permissions](build/roothide/README.md).

Other focused verification runners cover models/preferences (`recovery/tools/verify_models.py`), subtitles (`verify_subtitles.py`), playback (`verify_playback.py`), downloads (`verify_downloads.py`), settings (`tools/verify_settings.py`) and presentation/helpers (`tools/verify_presentation_runtime.py`). Their module provenance files describe fixture boundaries and limitations. Historical reports should be checked against current source hashes before relying on them.

The existing hook fixture uses the pinned Logos revision that accepts the backup's compact `%orig(...)` syntax:

```sh
git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' \
  clone https://github.com/theos/logos.git vendor/recovery-logos
git -C vendor/recovery-logos checkout --detach 8cb2f6375c0a975a2b84c440f27f67282b0217b4
python3 recovery/tools/verify_source.py --logos vendor/recovery-logos/bin/logos.pl
```

This fixture preprocesses the four Logos files and executes the recovered background/ad hook region on mock classes through the real Objective-C runtime. Preference tests now live in `verify_models.py`, which supplies their recovered helper and UIKit dependencies.

When regenerating binary-analysis output, use a separate output directory through `run.py --output`. The original generator can replace generated defaults files; keep the hand-reconstructed `source/` tree intact. The later focused analysis helpers (`readable_exports.py`, `inspect_binary.py`, `verify_module_manifest.py`) read the verified image at `.recovery-work/arm/YTLite.dylib`. They never execute it.
