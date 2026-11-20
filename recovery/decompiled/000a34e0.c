/* Decompiled from supplied 5.2.2 arm package. VA 0xa34e0. FUN_000a34e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000a34e0(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  
  DAT_01226dfc = 1;
  uVar1 = FUN_000e5944(&PTR____CFConstantStringClassReference_0116cf50);
  (*_DAT_01226630)(param_1,param_2);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x000a3690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01180330)[uVar1 & 0xffffffff] + (int)-(uRam0000000001180340 ^ 0x821228de)))()
  ;
  return;
}


