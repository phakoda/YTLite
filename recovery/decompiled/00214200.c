/* Decompiled from supplied 5.2.2 arm package. VA 0x214200. remainingSecondsForCurrentVideo */

/* Function Stack Size: 0x10 bytes */

double YTPSleepTimer::remainingSecondsForCurrentVideo(ID param_1,SEL param_2)

{
  long lVar1;
  uint uVar2;
  double dVar3;
  
  _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    dVar3 = (double)_objc_msgSend(lVar1,PTR_s_currentVideoTotalMediaTime_0114c9f8);
    _objc_msgSend(lVar1,PTR_s_currentVideoMediaTime_0114dab0);
    uVar2 = (uint)(ABS(dVar3) == INFINITY);
    if (NAN(ABS(dVar3))) {
      uVar2 = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00214300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    dVar3 = (double)(*(code *)((&PTR_LAB_011cc7d8)[uVar2] +
                              (int)-(uRam00000000011cc7e8 ^ 0xe9953813)))();
    return dVar3;
  }
  _objc_release((&PTR_LAB_011cc7c0)[lVar1 == 0] + (int)-(DAT_011cc7d0 ^ 0x47ef989d),0);
  return 0.0;
}


