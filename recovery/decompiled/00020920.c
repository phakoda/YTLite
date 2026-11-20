/* Decompiled from supplied 5.2.2 arm package. VA 0x20920. FUN_00020920 */

void FUN_00020920(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_01225cdc = 1;
  _objc_retain(param_3);
  (*pcRam0000000001225c30)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_00022df8(&PTR____CFConstantStringClassReference_01155ca0);
                    /* WARNING: Could not recover jumptable at 0x00020b94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011564e0)[uVar1 & 0xffffffff] + (int)-(uRam00000000011564f0 ^ 0x56491f80)))()
  ;
  return;
}


