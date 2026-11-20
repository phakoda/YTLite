/* Decompiled from supplied 5.2.2 arm package. VA 0x2117cc. isRunning */

/* Function Stack Size: 0x10 bytes */

bool YTPSleepTimer::isRunning(ID param_1,SEL param_2)

{
  uint uVar1;
  long lVar2;
  
  if (*(dispatch_source_t *)(param_1 + 8) == (dispatch_source_t)0x0) {
    uVar1 = 0;
  }
  else {
    lVar2 = _dispatch_source_testcancel(*(dispatch_source_t *)(param_1 + 8));
    uVar1 = (uint)(lVar2 == 0);
  }
  return uVar1;
}


