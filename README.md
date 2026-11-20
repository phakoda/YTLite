# YTLite

A YouTube Plus fork for iOS, built from reconstructed 5.2.2 source. This fork uses local preferences and requires no subscription or account activation.

Open YouTube settings, then YouTube Plus to configure the tweak.

## What's included

- Video and audio downloads, thumbnails, and channel images.
- SponsorBlock, preferred quality, audio tracks, and captions.
- Playback speed that stays selected when you open another video. Remember playback speed is enabled by default. Choosing a default speed clears the previous remembered choice.
- Don't Eat My Content under Player settings. It keeps wide fullscreen videos clear of the notch and Dynamic Island while allowing intentional pinch-to-zoom.
- Native settings rows, switches, and text sizing, with search and preference import/export.
- No first-launch promotion or developer donation prompts.

Temporary hold-to-speed gestures return to the previous speed unless Preserve Speed is enabled.

## Build the tweak

The build targets arm64 devices running iOS 14 or later. It requires macOS, Xcode with the iOS SDK, Python 3.12 or newer, and a working Theos toolchain.

Restore the pinned build dependencies from the repository root:

```sh
git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' clone https://github.com/theos/theos.git vendor/theos
git -C vendor/theos checkout --detach 5280bd038207e14f8bd76f5417aa2fe641c03228
git -C vendor/theos -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' submodule update --init --recursive
git -C vendor/theos/vendor/logos checkout --detach a62370066a97e36d59b200a9fa10c5091f5e8972

git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' clone https://github.com/PoomSmart/YouTubeHeader.git vendor/YouTubeHeader
git -C vendor/YouTubeHeader checkout --detach 340680d7e6023c051f912f884bc1879b84aca7c6
```

Build a Debian package:

```sh
python3 tools/build_local.py package
```

The package goes into `packages/`. The build log and input hashes go into `.recovery-work/build/`. For a roothide package, use `python3 tools/build_local.py package --scheme roothide`.

The repository includes the standalone FFmpeg archives used by the build. To rebuild them, follow the [FFmpeg dependency notes](recovery/dependencies/ffmpeg/README.md). The original combined tweak binary is not a link dependency.

## Inject a decrypted YouTube IPA

Supply your own decrypted IPA. Keep the input and output paths different. The injector refuses to overwrite an existing output.

Restore the pinned Cyan checkout once:

```sh
mkdir -p .recovery-work/ipa-tools
git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' clone https://github.com/asdfzxcvbn/pyzule-rw.git .recovery-work/ipa-tools/pyzule-rw
git -C .recovery-work/ipa-tools/pyzule-rw checkout --detach 740d3716dcd98c20c000f12cdb88f1f0b2a533a4
```

Build the current source, then inject it:

```sh
python3 tools/build_local.py all
python3 tools/inject_local_ipa.py YouTube-Decrypted.ipa packages/YouTube-YTLite.ipa
```

The script embeds `YTLite.dylib`, its resource bundle, and the hook runtime. It checks that YouTube's code and data sections are unchanged, that all other original files are preserved, and that the injected resources match the local build. The verification report sits beside the output IPA with an `.injection.json` extension.

Sign the output IPA with your usual device provisioning before installation. Injection does not provide a signing identity or provisioning profile. Local IPA files and build outputs are excluded from Git.

## Verification and compatibility

YouTube 21.46.3 has passed archive and injection verification with this fork. That verifies the package structure, not playback inside the app. Real YouTube device testing remains outstanding. A newer YouTube release can change the private methods these hooks depend on.

Run the current playback regression checks:

```sh
python3 tools/verify_local_features.py
```

The playback suite needs the original-package analysis inputs described in [recovery reproduction](recovery/REPRODUCE.md). Historical parity fixtures compare against the supplied packages, including behavior this fork has intentionally changed.

The UIKit fixture runs the production settings table and content-layout hooks against synthetic YouTube objects. It checks row alignment, switch saving, native speed capture, and notch-safe rendering. Restore its pinned Logos checkout, then pass an available simulator UUID:

```sh
git -c http.userAgent='OpenAI File Downloader, XaiImageApiFetch/1.0' clone https://github.com/theos/logos.git vendor/recovery-logos
git -C vendor/recovery-logos checkout --detach 8cb2f6375c0a975a2b84c440f27f67282b0217b4
python3 tools/verify_settings_simulator.py YOUR_SIMULATOR_UUID
```

Use `--appearance dark` or `--content-size accessibility-extra-extra-extra-large` to check other display settings. Reports and screenshots go into `.recovery-work/settings-preview/`.

## Source and credits

The selected tweak sources are listed in [recovered.mk](recovery/source/recovered.mk). [The recovery notes](recovery/README.md) document the reconstruction, evidence, and known differences from the original packages. Decompiled exports are evidence, not buildable source.

Don't Eat My Content is adapted from [Foxster's tweak](https://github.com/therealFoxster/DontEatMyContent). Its [MIT license](recovery/dependencies/DontEatMyContent/LICENSE.md) is also included in the resource bundle. FFmpeg and the bundled codecs retain their own licenses in the dependency source tree.

The [GitHub Actions workflows](.github/workflows/) assemble IPAs from prebuilt tweak packages. They do not compile this reconstructed source. Use the local build and injection commands above to include changes made in this checkout.
