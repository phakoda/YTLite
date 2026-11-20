/* Decompiled from supplied 5.2.2 arm package. VA 0x908ac. FUN_000908ac */

void FUN_000908ac(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d74 = 1;
  (*DAT_01226528)(param_1);
  uVar1 = FUN_000e1068(&PTR____CFConstantStringClassReference_01169740);
                    /* WARNING: Could not recover jumptable at 0x00090a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e660)[uVar1 & 0xffffffff] + (int)-(DAT_0117e670 ^ 0x50ccb2d3)))();
  return;
}


