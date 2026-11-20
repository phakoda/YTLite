/* Decompiled from supplied 5.2.2 arm package. VA 0x213ac8. stopWithFadeIfNeeded: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::stopWithFadeIfNeeded_(ID param_1,SEL param_2,double param_3)

{
  if (*(char *)(param_1 + 0x30) == '\0') {
    *(undefined1 *)(param_1 + 0x30) = 1;
    if (DAT_00c4c2a0 < param_3) {
      if (param_3 < 5.0) {
        _objc_msgSend(0x3ff0000000000000,0x3ff0000000000000,param_1,
                      PTR_s_stopWithFadeDuration_stopAfter__0114e428);
      }
      else {
        _objc_msgSend(0x4014000000000000,param_3 + -1.0,param_1,
                      PTR_s_stopWithFadeDuration_stopAfter__0114e428);
      }
    }
    else {
      _objc_msgSend(param_1,PTR_s_stop_0114dfb8);
    }
  }
  CallSupervisor(0x5f01);
  return;
}


