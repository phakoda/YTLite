/* Decompiled from supplied 5.2.2 arm package. VA 0x7f064. FUN_0007f064 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f064(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c14 = 1;
  uVar1 = FUN_000dd160(&PTR____CFConstantStringClassReference_01166440);
  if (uVar1 == 0) {
    iVar2 = FUN_000dd184((&PTR_LAB_0117cca8)[uVar1] + (int)-(DAT_0117ccb8 ^ 0x15bba134),
                         &PTR____CFConstantStringClassReference_01166400);
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262d8)(param_1,param_2,uVar3);
  CallSupervisor(0x251d);
  return ZEXT816(0x1f);
}


