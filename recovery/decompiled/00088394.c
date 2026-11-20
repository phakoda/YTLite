/* Decompiled from supplied 5.2.2 arm package. VA 0x88394. FUN_00088394 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00088394(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cd0 = 1;
  iVar1 = FUN_000df32c(&PTR____CFConstantStringClassReference_01167d80);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00088590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226418)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


