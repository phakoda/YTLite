/* Decompiled from supplied 5.2.2 arm package. VA 0x7f940. FUN_0007f940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007f940(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c20 = 1;
  uVar1 = FUN_000dd238(&PTR____CFConstantStringClassReference_01166680);
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd25c((&PTR_LAB_0117cd68)[uVar1] + (int)-(uRam000000000117cd78 ^ 0xbbc1046),
                           &PTR____CFConstantStringClassReference_01166640), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007fc28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262f0)(param_1,param_2);
    return uVar3;
  }
  return 2;
}


