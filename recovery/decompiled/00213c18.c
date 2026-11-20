/* Decompiled from supplied 5.2.2 arm package. VA 0x213c18. stopWithFadeDuration:stopAfter: */

/* Function Stack Size: 0x20 bytes */

void YTPSleepTimer::stopWithFadeDuration_stopAfter_
               (ID param_1,SEL param_2,double param_3,double param_4)

{
  long lVar1;
  
  _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
  lVar1 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00213cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cc698)[lVar1 == 0] + (int)-(DAT_011cc6a8 ^ 0x1bae69cf)))();
  return;
}


