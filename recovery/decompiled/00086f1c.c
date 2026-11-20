/* Decompiled from supplied 5.2.2 arm package. VA 0x86f1c. FUN_00086f1c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086f1c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c80 = 1;
  iVar1 = FUN_000df1a0(&PTR____CFConstantStringClassReference_011678a0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226378)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


