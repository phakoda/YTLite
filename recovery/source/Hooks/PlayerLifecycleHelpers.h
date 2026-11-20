#pragma once
#import "PlayerLifecycleHost.h"
FOUNDATION_EXPORT BOOL canRememberLoopMode;
FOUNDATION_EXPORT void addEndTime(YTPlayerViewController *player, id<YTLPlayerVideo> video, id<YTLPlayerTime> time);
FOUNDATION_EXPORT void autoSkipShortsLegacy(YTPlayerViewController *player, id<YTLPlayerVideo> video, id<YTLPlayerTime> time);
