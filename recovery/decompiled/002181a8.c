/* Decompiled from supplied 5.2.2 arm package. VA 0x2181a8. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cleanup(ID param_1,SEL param_2)

{
  long lVar1;
  long lVar2;
  
  _objc_msgSend(param_1,PTR_s_globalSlimBar_0114e4d8);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_playerSlimBar_0114e4d0);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    _objc_msgSend((&PTR__objc_msgSend_011ccdd0)[lVar1 == 0] + (int)-(DAT_011ccde0 ^ 0x131129e6),
                  lVar1,PTR_s_setDisplayed__0114e4f0,0);
    _objc_msgSend(lVar1,PTR_s_setDismissing__0114e4f8,1);
    _objc_msgSend(param_1,PTR_s_globalSlimBarVisibilityChange_0114e520);
    _objc_msgSend(param_1,PTR_s_removeTapHandlerOnBar__0114e550,lVar1);
                    /* WARNING: Could not recover jumptable at 0x002182dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011ccdf0)[lVar2 == 0] + (int)-(uRam00000000011cce00 ^ 0xc481dff0)))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0021830c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011ccdf0)[lVar2 == 0] + (int)-(uRam00000000011cce00 ^ 0xc481dff0)))();
  return;
}


