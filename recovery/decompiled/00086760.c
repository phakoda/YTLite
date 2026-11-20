/* Decompiled from supplied 5.2.2 arm package. VA 0x86760. FUN_00086760 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086760(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c70 = 1;
  iVar1 = FUN_000df110(&PTR____CFConstantStringClassReference_011676e0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226358)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


