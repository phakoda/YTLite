/* Decompiled from supplied 5.2.2 arm package. VA 0x86d08. FUN_00086d08 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086d08(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c7c = 1;
  iVar1 = FUN_000df17c(&PTR____CFConstantStringClassReference_01167820);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086f04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226370)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


