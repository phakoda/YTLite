/* Decompiled from supplied 5.2.2 arm package. VA 0x735a0. FUN_000735a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000735a0(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226b90 = 1;
  (*_DAT_01226228)(param_1);
  uVar1 = FUN_000dab14(&PTR____CFConstantStringClassReference_01164550);
                    /* WARNING: Could not recover jumptable at 0x000740c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117bb70)[uVar1 & 0xffffffff] + (int)-(uRam000000000117bb80 ^ 0xb5a961d1)))()
  ;
  return;
}


