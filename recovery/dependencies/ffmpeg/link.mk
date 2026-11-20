# Genuine mobile-ffmpeg 4.4 audio-LTS archives, built by tools/build_ffmpeg.py.
YTLITE_FFMPEG_RECOVERY_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/ios-arm64)
ifeq ($(wildcard $(YTLITE_FFMPEG_RECOVERY_DIR)/libmobileffmpeg.a),)
$(error Missing mobile-ffmpeg static archives; run python3 tools/build_ffmpeg.py)
endif
YTLITE_FFMPEG_LDFLAGS += $(wildcard $(YTLITE_FFMPEG_RECOVERY_DIR)/*.a) -lc++ -lz -lbz2 -liconv -framework Foundation -framework CoreFoundation -framework CoreMedia -framework CoreVideo -framework AudioToolbox -framework VideoToolbox -framework AVFoundation -framework Security
