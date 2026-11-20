/* Decompiled from supplied 5.2.2 arm package. VA 0x20c50. FUN_00020c50 */

void FUN_00020c50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_01225ce0 = 1;
  _objc_retain(param_3);
  (*pcRam0000000001225c38)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_00022e1c(&PTR____CFConstantStringClassReference_01155d60);
                    /* WARNING: Could not recover jumptable at 0x00020f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156538)[uVar1 & 0xffffffff] + (int)-(uRam0000000001156548 ^ 0xea2bba1b)))()
  ;
  return;
}


