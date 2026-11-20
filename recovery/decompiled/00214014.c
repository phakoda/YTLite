/* Decompiled from supplied 5.2.2 arm package. VA 0x214014. cancelIfPlayerClosed */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cancelIfPlayerClosed(ID param_1,SEL param_2)

{
  if (*(long *)(param_1 + 0x20) == 2) {
    _objc_msgSend(param_1,PTR_s_cancel_0114df48);
  }
  CallSupervisor(0xbdf1);
  return;
}


