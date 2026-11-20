# Link declarations only. The installed environment supplies both libraries.
_YTL_ROOTHIDE_LINK_DIR := $(THEOS_PROJECT_DIR)/recovery/build/roothide/lib
_THEOS_INTERNAL_CFLAGS += -F$(_YTL_ROOTHIDE_LINK_DIR)
_THEOS_INTERNAL_LDFLAGS := -F$(_YTL_ROOTHIDE_LINK_DIR) -L$(_YTL_ROOTHIDE_LINK_DIR) $(filter-out -lroot -lroot_oldabi,$(_THEOS_INTERNAL_LDFLAGS)) -lroothide -framework CydiaSubstrate
