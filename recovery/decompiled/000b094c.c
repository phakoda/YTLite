/* Decompiled from supplied 5.2.2 arm package. VA 0xb094c. FUN_000b094c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000b094c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226e6c = 1;
  iVar1 = FUN_000e8420(&PTR____CFConstantStringClassReference_0116f9a0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000b0b44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012266e0)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


