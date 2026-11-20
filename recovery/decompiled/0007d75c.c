/* Decompiled from supplied 5.2.2 arm package. VA 0x7d75c. FUN_0007d75c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007d75c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226bf4 = 1;
  (*_DAT_01226298)(param_1);
  uVar1 = FUN_000dcb6c(&PTR____CFConstantStringClassReference_01165f10);
                    /* WARNING: Could not recover jumptable at 0x0007d8d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117c9c0)[uVar1 & 0xffffffff] + (int)-(DAT_0117c9d0 ^ 0x1cd78b8c)))();
  return;
}


