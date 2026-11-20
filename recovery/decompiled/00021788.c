/* Decompiled from supplied 5.2.2 arm package. VA 0x21788. FUN_00021788 */

void FUN_00021788(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225d00 = 1;
  (*pcRam0000000001225c78)(param_1);
  uVar1 = FUN_00023208(&PTR____CFConstantStringClassReference_01156080);
                    /* WARNING: Could not recover jumptable at 0x000220f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156618)[uVar1 & 0xffffffff] + (int)-(uRam0000000001156628 ^ 0x72f3198e)))()
  ;
  return;
}


