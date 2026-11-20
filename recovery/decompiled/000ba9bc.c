/* Decompiled from supplied 5.2.2 arm package. VA 0xba9bc. FUN_000ba9bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000ba9bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226f04 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000eaffc(&PTR____CFConstantStringClassReference_01171390);
  if (iVar1 == 0) {
    uVar2 = (*_DAT_012267f8)(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0;
  }
  _objc_release(param_3);
  return uVar2;
}


