/* Decompiled from supplied 5.2.2 arm package. VA 0x9026c. FUN_0009026c */

void FUN_0009026c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  DAT_01226d6c = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,PTR_s_redesignedController_0114c088);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x00090650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e5d8)[lVar1 == 0] + (int)-(DAT_0117e5e8 ^ 0xde3fd549)))();
  return;
}


