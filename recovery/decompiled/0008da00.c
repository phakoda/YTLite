/* Decompiled from supplied 5.2.2 arm package. VA 0x8da00. FUN_0008da00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008da00(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d30 = 1;
  (*_DAT_012264b0)(param_1);
  uVar1 = FUN_000e0624(&PTR____CFConstantStringClassReference_01168fd0);
                    /* WARNING: Could not recover jumptable at 0x0008dfa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e1b8)[uVar1 & 0xffffffff] + (int)-(uRam000000000117e1c8 ^ 0x25564ece)))()
  ;
  return;
}


