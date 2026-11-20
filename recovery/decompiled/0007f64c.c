/* Decompiled from supplied 5.2.2 arm package. VA 0x7f64c. FUN_0007f64c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f64c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c1c = 1;
  uVar1 = FUN_000dd214(&PTR____CFConstantStringClassReference_011665c0);
  if (uVar1 == 0) {
    iVar2 = FUN_000dd1f0((&PTR__MSHookMessageEx_0117cd28)[uVar1] + (int)-(DAT_0117cd38 ^ 0x8e269bb7)
                         ,&PTR____CFConstantStringClassReference_01166580);
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262e8)(param_1,param_2,uVar3);
  CallSupervisor(0xb392);
  return ZEXT816(0x1f);
}


