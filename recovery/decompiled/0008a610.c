/* Decompiled from supplied 5.2.2 arm package. VA 0x8a610. FUN_0008a610 */

void FUN_0008a610(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d0c = 1;
  (*DAT_01226488)(param_1);
  uVar1 = FUN_000df808(&PTR____CFConstantStringClassReference_01168570);
                    /* WARNING: Could not recover jumptable at 0x0008aa50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117dd90)[uVar1 & 0xffffffff] + (int)-(DAT_0117dda0 ^ 0xc563790b)))();
  return;
}


