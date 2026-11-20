/* Decompiled from supplied 5.2.2 arm package. VA 0x891dc. FUN_000891dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000891dc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cf0 = 1;
  iVar1 = FUN_000df524(&PTR____CFConstantStringClassReference_01168060);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008940c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226450)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


