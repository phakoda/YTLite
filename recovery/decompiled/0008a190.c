/* Decompiled from supplied 5.2.2 arm package. VA 0x8a190. FUN_0008a190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008a190(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d04 = 1;
  iVar1 = FUN_000df714(&PTR____CFConstantStringClassReference_011683d0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008a380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226478)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


