/* Decompiled from supplied 5.2.2 arm package. VA 0xa0670. FUN_000a0670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000a0670(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226de4 = 1;
  (*_DAT_01226608)(param_1);
  uVar1 = FUN_000e5178(&PTR____CFConstantStringClassReference_0116c800);
                    /* WARNING: Could not recover jumptable at 0x000a1000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117fed0)[uVar1 & 0xffffffff] + (int)-(uRam000000000117fee0 ^ 0x74185b84)))()
  ;
  return;
}


