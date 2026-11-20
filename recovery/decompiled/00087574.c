/* Decompiled from supplied 5.2.2 arm package. VA 0x87574. FUN_00087574 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087574(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c98 = 1;
  iVar1 = FUN_000df20c(&PTR____CFConstantStringClassReference_01167a20);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008776c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263a8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


