/* Decompiled from supplied 5.2.2 arm package. VA 0x213fe0. cancel */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cancel(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,PTR_s_finishTimerAndCleanup_0114e440);
  CallSupervisor(0x4d02);
  return;
}


