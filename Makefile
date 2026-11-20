ifeq ($(ROOTLESS),1)
THEOS_PACKAGE_SCHEME=rootless
else ifeq ($(ROOTHIDE),1)
THEOS_PACKAGE_SCHEME=roothide
override THEOS_MODULE_PATH := $(CURDIR)/recovery/build/theos-modules
_THEOS_RELATIVE_DATA_DIR := .theos/roothide
THEOS_PACKAGE_DIR_NAME := packages/roothide
endif

DEBUG=0
FINALPACKAGE=1
ARCHS = arm64
PACKAGE_VERSION = 5.2.2-local.3
# The packaged 5.2.2 image declares iOS 14. Use the installed Xcode SDK, not
# the unavailable 16.5 SDK named in the March 2024 source backup.
TARGET := iphone:clang:latest:14.0
THEOS ?= $(CURDIR)/vendor/theos
# Stage the archive on a filesystem that supports Debian's Unix permissions.
_THEOS_PLATFORM_DPKG_DEB = $(CURDIR)/tools/package_deb.py

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = YTLite
$(TWEAK_NAME)_FRAMEWORKS = UIKit Foundation SystemConfiguration Security AVFoundation AVKit Photos PhotosUI WebKit QuartzCore CoreGraphics UniformTypeIdentifiers MediaPlayer
$(TWEAK_NAME)_CFLAGS = -fobjc-arc -DTWEAK_VERSION=$(PACKAGE_VERSION) -I$(THEOS_PROJECT_DIR)/vendor/YouTubeHeader
ifeq ($(ROOTHIDE),1)
$(TWEAK_NAME)_CFLAGS += -DYTLITE_RESOURCE_ROOTHIDE=1
endif
$(TWEAK_NAME)_FILES = $(wildcard *.x Utils/*.m)

include recovery/source/recovered.mk
ifeq ($(ROOTHIDE),1)
# The first package uses the external NSString resolver directly.
YTLite_FILES := $(filter-out recovery/source/Runtime/YTLRootPaths.c,$(YTLite_FILES))
endif

# A standalone mobile-ffmpeg build is a real link dependency. Do not substitute
# the original combined YTLite binary or test doubles for these libraries.
include recovery/dependencies/ffmpeg/link.mk
YTLite_LDFLAGS += $(YTLITE_FFMPEG_LDFLAGS)

include $(THEOS_MAKE_PATH)/tweak.mk
