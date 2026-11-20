/* Decompiled from supplied 5.2.2 arm package. VA 0x7f34c. FUN_0007f34c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f34c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01226c18 = 1;
  uVar1 = FUN_000dd1a8(&PTR____CFConstantStringClassReference_01166500);
  if (uVar1 == 0) {
    iVar2 = FUN_000dd1cc((&PTR_LAB_0117cce8)[uVar1] + (int)-(uRam000000000117ccf8 ^ 0x73a6d9f),
                         &PTR____CFConstantStringClassReference_011664c0);
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262e0)(param_1,param_2,uVar3);
  CallSupervisor(0x5bd);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


