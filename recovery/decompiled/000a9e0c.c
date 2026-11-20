/* Decompiled from supplied 5.2.2 arm package. VA 0xa9e0c. FUN_000a9e0c */

void FUN_000a9e0c(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226e28 = 1;
  (*DAT_01226658)(param_1);
  uVar1 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
  lVar2 = _class_getInstanceVariable(uVar1,s__playerView_0116df24);
                    /* WARNING: Could not recover jumptable at 0x000aa064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181040)[lVar2 == 0] + (int)-(DAT_01181050 ^ 0xde2056e6)))();
  return;
}


