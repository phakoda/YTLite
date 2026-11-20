/* Decompiled from supplied 5.2.2 arm package. VA 0x84ae4. FUN_00084ae4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00084ae4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  
  DAT_01226c54 = 1;
  _objc_retain(param_3);
  (*_DAT_01226330)(param_1,param_2,param_3);
  uVar1 = FUN_000de8dc(&PTR____CFConstantStringClassReference_01167320);
                    /* WARNING: Could not recover jumptable at 0x00084cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d3d0)[uVar1 & 0xffffffff] + (int)-(uRam000000000117d3e0 ^ 0x7a6f9af0)))()
  ;
  return;
}


