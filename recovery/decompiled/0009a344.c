/* Decompiled from supplied 5.2.2 arm package. VA 0x9a344. FUN_0009a344 */

void FUN_0009a344(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_000e3c5c(param_1,PTR_s_respondsToSelector__0114af58,
                       PTR_s_makeContentModelForEntry__0114c0c0);
  (*DAT_012265d0)(param_1,param_2);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0009a3e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f5e0)[uVar1 & 0xffffffff] + (int)-(DAT_0117f5f0 ^ 0x82c6dee4)))();
  return;
}


