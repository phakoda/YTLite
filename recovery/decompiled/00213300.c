/* Decompiled from supplied 5.2.2 arm package. VA 0x213300. startForEndOfVideo */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::startForEndOfVideo(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,PTR_s_cancel_0114df48);
    uVar1 = _DAT_00c4c4d0;
    *(undefined8 *)(param_1 + 0x28) = _UNK_00c4c4d8;
    *(undefined8 *)(param_1 + 0x20) = uVar1;
    _objc_msgSend(param_1,PTR_s_startTimer_0114e3f0);
  }
  _objc_release(lVar2);
  CallSupervisor(0x5adb);
  return;
}


