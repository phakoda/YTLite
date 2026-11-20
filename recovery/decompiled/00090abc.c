/* Decompiled from supplied 5.2.2 arm package. VA 0x90abc. FUN_00090abc */

void FUN_00090abc(void)

{
  long lVar1;
  
  DAT_01226d78 = 1;
  (*DAT_01226530)();
  lVar1 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00090d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e6a0)[lVar1 == 0] + (int)-(DAT_0117e6b0 ^ 0xa0d2fc5)))();
  return;
}


