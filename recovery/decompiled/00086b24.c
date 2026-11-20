/* Decompiled from supplied 5.2.2 arm package. VA 0x86b24. FUN_00086b24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086b24(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c78 = 1;
  iVar1 = FUN_000df158(&PTR____CFConstantStringClassReference_011677a0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226368)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


