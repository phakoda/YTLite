/* Decompiled from supplied 5.2.2 arm package. VA 0x7ed60. FUN_0007ed60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007ed60(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c10 = 1;
  uVar1 = FUN_000dd118(&PTR____CFConstantStringClassReference_01166380);
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd13c((&PTR_LAB_0117cc50)[uVar1] + (int)-(DAT_0117cc60 ^ 0x318955a3),
                           &PTR____CFConstantStringClassReference_01166340), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007f04c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262d0)(param_1,param_2);
    return uVar3;
  }
  return 2;
}


