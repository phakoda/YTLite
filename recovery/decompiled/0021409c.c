/* Decompiled from supplied 5.2.2 arm package. VA 0x21409c. remainingSeconds */

/* Function Stack Size: 0x10 bytes */

double YTPSleepTimer::remainingSeconds(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  double dVar3;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 < 2) {
    dVar3 = 0.0;
    if (lVar2 == 1) {
      _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
      uVar1 = _objc_retainAutoreleasedReturnValue();
      dVar3 = (double)_objc_msgSend(uVar1,PTR_s_timeIntervalSince1970_0114b4d8);
      _objc_release(uVar1);
      dVar3 = *(double *)(param_1 + 0x38) - dVar3;
    }
  }
  else {
    dVar3 = 0.0;
    if (lVar2 == 2) {
      dVar3 = (double)_objc_msgSend(param_1,PTR_s_remainingSecondsForCurrentVideo_0114e3b8);
      return dVar3;
    }
  }
  return dVar3;
}


