/* Decompiled from supplied 5.2.2 arm package. VA 0x83340. FUN_00083340 */

void FUN_00083340(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c4c = 1;
  (*DAT_01226320)(param_1);
  uVar1 = FUN_000de78c(&PTR____CFConstantStringClassReference_01167120);
                    /* WARNING: Could not recover jumptable at 0x00083d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d1d0)[uVar1 & 0xffffffff] + (int)-(DAT_0117d1e0 ^ 0x7b6f0894)))();
  return;
}


