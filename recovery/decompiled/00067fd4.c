/* Decompiled from supplied 5.2.2 arm package. VA 0x67fd4. recovered_hook_00067fd4 */

void recovered_hook_00067fd4(undefined8 param_1)

{
  ulong uVar1;
  
  uRam0000000001226ac4 = 1;
  (*DAT_012260a8)(param_1);
  uVar1 = FUN_000d7228(&PTR____CFConstantStringClassReference_011620c0);
                    /* WARNING: Could not recover jumptable at 0x000682c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117af48)[uVar1 & 0xffffffff] + (int)-(DAT_0117af58 ^ 0x83adb2f9)))();
  return;
}


