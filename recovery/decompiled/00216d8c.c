/* Decompiled from supplied 5.2.2 arm package. VA 0x216d8c. slimBarVisibilityChange: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::slimBarVisibilityChange_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  if (param_3 != 1) {
    _objc_msgSend(param_1,PTR_s_globalSlimBarVisibilityChange_0114e520);
  }
  _objc_msgSend(param_1,PTR_s_playerSlimBarVisibilityChange_0114e518);
  return;
}


