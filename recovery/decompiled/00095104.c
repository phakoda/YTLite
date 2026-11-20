/* Decompiled from supplied 5.2.2 arm package. VA 0x95104. FUN_00095104 */

void FUN_00095104(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226da0 = 1;
  (*DAT_01226580)(param_1);
  uVar1 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
  lVar2 = _class_getInstanceVariable(uVar1,s__progressBarGradient_0116a590);
                    /* WARNING: Could not recover jumptable at 0x00095820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ec60)[lVar2 == 0] + (int)-(DAT_0117ec70 ^ 0x696f03e4)))();
  return;
}


