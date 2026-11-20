/* Decompiled from supplied 5.2.2 arm package. VA 0xbab78. FUN_000bab78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000bab78(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226f08 = 1;
  iVar1 = FUN_000eb020(&PTR____CFConstantStringClassReference_011713f0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000bad08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226800)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


