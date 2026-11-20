/* Decompiled from supplied 5.2.2 arm package. VA 0x194a04. requestSbSegments */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::requestSbSegments(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = _objc_loadWeakRetained(param_1 + 8);
  _objc_msgSend(uVar1,PTR_s_contentVideoID_0114cef0);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00194a94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011aaa38)[lVar2 == 0] + (int)-(DAT_011aaa48 ^ 0x1e2e3322)))();
  return;
}


