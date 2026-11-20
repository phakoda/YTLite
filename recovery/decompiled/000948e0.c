/* Decompiled from supplied 5.2.2 arm package. VA 0x948e0. FUN_000948e0 */

void FUN_000948e0(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226d98 = 1;
  (*DAT_01226570)(param_1);
  uVar1 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
  lVar2 = _class_getInstanceVariable(uVar1,s__scrubberCircle_0116a31d);
                    /* WARNING: Could not recover jumptable at 0x00094dac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ebc0)[lVar2 == 0] + (int)-(DAT_0117ebd0 ^ 0x267d5490)))();
  return;
}


