/* Decompiled from supplied 5.2.2 arm package. VA 0x80a50. FUN_00080a50 */

void FUN_00080a50(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c38 = 1;
  (*DAT_01226308)(param_1);
  uVar1 = FUN_000dda18(&PTR____CFConstantStringClassReference_01166ac0);
                    /* WARNING: Could not recover jumptable at 0x00081154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117cf18)[uVar1 & 0xffffffff] + (int)-(DAT_0117cf28 ^ 0x272c11af)))();
  return;
}


