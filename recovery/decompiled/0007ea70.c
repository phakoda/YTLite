/* Decompiled from supplied 5.2.2 arm package. VA 0x7ea70. FUN_0007ea70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007ea70(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c0c = 1;
  uVar1 = FUN_000dd0f4(&PTR____CFConstantStringClassReference_011662c0);
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd0d0((&PTR_LAB_0117cbf8)[uVar1] + (int)-(uRam000000000117cc08 ^ 0xafc24f26),
                           &PTR____CFConstantStringClassReference_01166280), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007ed48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262c8)(param_1,param_2);
    return uVar3;
  }
  return 2;
}


