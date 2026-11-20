# Standalone mobile-ffmpeg dependency recovery

The supplied tweak embeds mobile-ffmpeg 4.4 LTS with FFmpeg `v4.4-dev-416`. The official mobile-ffmpeg v4.4 source pins that precise FFmpeg revision. The dependency has been rebuilt from those sources. All 24 static archives pass an arm64 architecture check, define the required classes/constants, and link into an iOS 14 dylib without unresolved symbols. The seven bundled Objective-C classes also match all 74 packaged method encodings and 24 ivar layouts. The combined original tweak was never linked as a substitute.

Source pins:

- [mobile-ffmpeg v4.4](https://github.com/tanersener/mobile-ffmpeg/tree/55700fb8bb5ec3e4c7be57506349838387d04364), commit `55700fb8bb5ec3e4c7be57506349838387d04364`.
- [FFmpeg source fork](https://github.com/tanersener/FFmpeg/tree/d222da435e63a2665b85c0305ad2cf8a07b1af6d), commit `d222da435e63a2665b85c0305ad2cf8a07b1af6d`. This is the explicit v4.4-dev-416 pin in mobile-ffmpeg's `build/arch-common.sh`.
- [gas-preprocessor](https://github.com/libav/gas-preprocessor/tree/d09971fad329d32df19f5bbafe88cf2f0ed04ed7), last upstream commit before the packaged July 25, 2020 build. The exact assembler-helper revision used by that old build is not encoded in the binary; this pin is a reconstruction choice.

`tools/build_ffmpeg_recovery.py` records download SHA-256 pins and applies explicit portability patches. All HTTP and git downloads use the requested User-Agent. Upstream inherited-environment logging is removed. Autoconf receives an explicit build triplet so it does not try to execute iOS probe programs on an Apple Silicon Mac. CMake 4's compatibility floor is set for the old soxr source. The archive's pinned version replaces `git describe`, which would otherwise identify this enclosing YTLite repository. libsndfile is built/installed with `SUBDIRS=src` because its old `--disable-full-suite` still builds tests requiring unavailable GNU autogen; the actual sound-file library and codec support remain intact. `portability.patch` records these build-script changes.

The source selection retains the original iOS API, build scripts, licenses and dependencies needed for the audio-LTS configuration. Unused Android/tvOS examples, generated web documentation and unrelated codec source trees are omitted from the vendored checkout. Their unmodified upstream archive remains checksum-addressed by the restore script.

The configured codec capabilities are LAME, Vorbis, OpenCORE AMR-NB, Shine, Speex, WavPack, iLBC, Opus, soxr, TwoLAME and VisualOn AMR-WB encoding, plus zlib, bzip2, iconv, AudioToolbox and VideoToolbox. Vorbis's Ogg and TwoLAME's libsndfile build dependencies are retained. `provenance.json` records the original binary's complete configuration string.

The original used Xcode 7.3.1/iOS SDK 9.3 on July 25, 2020. This reconstruction uses the installed Xcode/iOS SDK. Exact binary identity, assembler output, SDK capabilities and old-device compatibility are not claimed. The verification found exactly the same set of 57 explicit enable/disable switches and all 16 required codec/system capability macros enabled. `build-report.json` records these checks, source/archive hashes, the SDK, and system link flags. Hardware behavior on a real iOS device and codec execution were not tested.

Run `python3 tools/build_ffmpeg_recovery.py` from the repository. It prepares pinned source, builds the arm64 audio-LTS configuration and copies real static archives into `recovery/dependencies/ffmpeg/ios-arm64/` after success. The build requires Xcode command-line tools, make, pkg-config, autoconf/automake and CMake. Use `python3 tools/build_ffmpeg_recovery.py --verify-only` to repeat architecture, symbol, feature and link checks without rebuilding. The link probe is never executed.

Include `recovery/dependencies/ffmpeg/link.mk` before consuming `YTLITE_FFMPEG_LDFLAGS` in the tweak Makefile. It supplies the real archives and the Apple/system frameworks verified by the probe. These files satisfy the standalone FFmpeg link dependency; installing or exercising the recovered tweak remains a separate integration check.

The upstream mobile-ffmpeg license is LGPLv3-or-later; its GPLv3 text is included because LGPLv3 incorporates it. Each bundled codec retains its own license files. This configuration does not enable mobile-ffmpeg's optional GPL codec set. Source, license and relinking obligations still apply when distributing a statically linked build.
