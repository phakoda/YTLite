/* Decompiled from supplied 5.2.2 arm package. VA 0x23df50. setValue:forEventWithStyle: */

/* Function Stack Size: 0x20 bytes */

void PlayerToast::setValue_forEventWithStyle_
               (ID param_1,SEL param_2,double param_3,long_long param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((long)param_4 < 2) {
    if (param_4 == 0) {
      if (param_3 <= 0.0) {
                    /* WARNING: Could not recover jumptable at 0x0023e0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((&PTR_LAB_011d2ac0)[bRam0000000001228500] +
                  (int)-(uRam00000000011d2ad0 ^ 0x6e068310)))();
        return;
      }
      bRam0000000001228500 = 0;
      _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
      uVar1 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,uVar1,PTR_s_setBrightness__0114e8f8);
      _objc_release(uVar1);
    }
  }
  else if (param_4 == 2) {
    lVar2 = (long)_volumeHUD;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_addToController_0114e900);
    _objc_msgSend((float)param_3,*(undefined8 *)(param_1 + lVar2),PTR_s_setVolumeLevel__0114e908);
  }
  CallSupervisor(0xc13b);
  return;
}


