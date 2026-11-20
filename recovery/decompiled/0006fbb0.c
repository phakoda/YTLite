/* Decompiled from supplied 5.2.2 arm package. VA 0x6fbb0. FUN_0006fbb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006fbb0(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226b74 = 1;
  (*_DAT_012261f0)(param_1);
  uVar1 = FUN_000d8d7c(&PTR____CFConstantStringClassReference_01163850);
                    /* WARNING: Could not recover jumptable at 0x0006fef8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117b880)[uVar1 & 0xffffffff] + (int)-(uRam000000000117b890 ^ 0xe12b782d)))()
  ;
  return;
}


