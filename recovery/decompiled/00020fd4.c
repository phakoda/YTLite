/* Decompiled from supplied 5.2.2 arm package. VA 0x20fd4. FUN_00020fd4 */

void FUN_00020fd4(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225ce4 = 1;
  (*DAT_01225c40)(param_1);
  uVar1 = FUN_00022ec4(&PTR____CFConstantStringClassReference_01155e70);
                    /* WARNING: Could not recover jumptable at 0x00021300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156590)[uVar1 & 0xffffffff] + (int)-(DAT_011565a0 ^ 0x7d8bdef8)))();
  return;
}


