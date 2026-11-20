/* Decompiled from supplied 5.2.2 arm package. VA 0x6e65c. FUN_0006e65c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0006e65c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226b58 = 1;
  iVar1 = FUN_000d8a04(&PTR____CFConstantStringClassReference_01163340);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0006e7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012261b8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


