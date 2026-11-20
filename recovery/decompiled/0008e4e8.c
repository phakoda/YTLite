/* Decompiled from supplied 5.2.2 arm package. VA 0x8e4e8. FUN_0008e4e8 */

undefined1  [16] FUN_0008e4e8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d38 = 1;
  iVar1 = FUN_000e089c(&PTR____CFConstantStringClassReference_011690b0);
  uVar2 = 0x3ff0000000000000;
  if (iVar1 == 0) {
    uVar2 = param_1;
  }
  (*DAT_012264c0)(uVar2,param_2,param_3);
  CallSupervisor(0x89db);
  return ZEXT816(0x1f);
}


