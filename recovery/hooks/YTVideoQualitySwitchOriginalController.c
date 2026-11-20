// Decompiled hook evidence for YTVideoQualitySwitchOriginalController. This is not compilable Logos source.

// -[YTVideoQualitySwitchOriginalController redesignedController], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b4c8. FUN_0004b4c8 */

void FUN_0004b4c8(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b4c8);
  return;
}



// -[YTVideoQualitySwitchOriginalController setRedesignedController:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b4d4. FUN_0004b4d4 */

undefined1  [16] FUN_0004b4d4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b4c8,param_3,1);
  CallSupervisor(0xa21f);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTVideoQualitySwitchOriginalController setUserSelectableFormats:], original IMP slot 0x01226518
/* Decompiled from supplied 5.2.2 arm package. VA 0x9026c. FUN_0009026c */

void FUN_0009026c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  DAT_01226d6c = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(redesignedController));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x00090650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e5d8)[lVar1 == 0] + (int)-(DAT_0117e5e8 ^ 0xde3fd549)))();
  return;
}



// -[YTVideoQualitySwitchOriginalController dealloc], original IMP slot 0x01226520
/* Decompiled from supplied 5.2.2 arm package. VA 0x90850. FUN_00090850 */

undefined1  [16] FUN_00090850(undefined8 param_1,undefined8 param_2)

{
  undefined1 auVar1 [16];
  
  _objc_msgSend(param_1,@selector(setRedesignedController:),0);
  (*DAT_01226520)(param_1,param_2);
  CallSupervisor(0xd373);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


