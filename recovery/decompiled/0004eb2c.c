/* Decompiled from supplied 5.2.2 arm package. VA 0x4eb2c. FUN_0004eb2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004eb2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a18 = 1;
  _objc_retain(param_3);
  _objc_retain(param_5);
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_0115e430);
  iVar1 = FUN_000d0f54(param_3,PTR_s_isKindOfClass__0114ad70,uVar2);
  if (iVar1 == 0) {
    (*_DAT_01225f68)(param_1,param_2,param_3,param_4,param_5);
  }
  _objc_release(param_5);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


