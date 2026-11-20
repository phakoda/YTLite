/* Decompiled from supplied 5.2.2 arm package. VA 0x8659c. FUN_0008659c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008659c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c6c = 1;
  iVar1 = FUN_000df0ec(&PTR____CFConstantStringClassReference_01167680);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226350)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


