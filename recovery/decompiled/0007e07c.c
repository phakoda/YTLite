/* Decompiled from supplied 5.2.2 arm package. VA 0x7e07c. FUN_0007e07c */

void FUN_0007e07c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c00 = 1;
  (*DAT_012262b0)(param_1);
  uVar1 = FUN_000dceec(&PTR____CFConstantStringClassReference_01166040);
                    /* WARNING: Could not recover jumptable at 0x0007e20c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117caf0)[uVar1 & 0xffffffff] + (int)-(DAT_0117cb00 ^ 0x1b0385ac)))();
  return;
}


