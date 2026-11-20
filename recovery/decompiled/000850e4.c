/* Decompiled from supplied 5.2.2 arm package. VA 0x850e4. FUN_000850e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000850e4(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c5c = 1;
  (*_DAT_01226338)(param_1);
  uVar1 = FUN_000dea7c(&PTR____CFConstantStringClassReference_011674d0);
                    /* WARNING: Could not recover jumptable at 0x000856a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__MSHookMessageEx_0117d488)[uVar1 & 0xffffffff] +
            (int)-(uRam000000000117d498 ^ 0xf4a0f45a)))();
  return;
}


