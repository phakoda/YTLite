/* Decompiled from supplied 5.2.2 arm package. VA 0x21320c. startForSeconds: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::startForSeconds_(ID param_1,SEL param_2,double param_3)

{
  undefined8 uVar1;
  double dVar2;
  
  if (0.0 < param_3) {
    _objc_msgSend(param_1,PTR_s_cancel_0114df48);
    uVar1 = _DAT_00c4c4c0;
    *(undefined8 *)(param_1 + 0x28) = _UNK_00c4c4c8;
    *(undefined8 *)(param_1 + 0x20) = uVar1;
    _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    dVar2 = (double)_objc_msgSend(uVar1,PTR_s_timeIntervalSince1970_0114b4d8);
    *(double *)(param_1 + 0x38) = dVar2 + param_3;
    _objc_release(uVar1);
    _objc_msgSend(param_1,PTR_s_startTimer_0114e3f0);
  }
  CallSupervisor(0x7171);
  return;
}


