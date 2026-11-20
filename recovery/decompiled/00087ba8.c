/* Decompiled from supplied 5.2.2 arm package. VA 0x87ba8. FUN_00087ba8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087ba8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ca4 = 1;
  iVar1 = FUN_000df278(&PTR____CFConstantStringClassReference_01167b80);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263c0)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


