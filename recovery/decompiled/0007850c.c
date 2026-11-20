/* Decompiled from supplied 5.2.2 arm package. VA 0x7850c. FUN_0007850c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007850c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226bc8 = 1;
  iVar1 = FUN_000dbce0(&PTR____CFConstantStringClassReference_01164fb0);
  if (iVar1 == 0) {
    (*_DAT_01226248)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,PTR_s_setValue_forKey__0114b208,0,
                  &PTR____CFConstantStringClassReference_01164f70);
    uVar2 = 0;
  }
  _objc_autoreleaseReturnValue(uVar2);
  return;
}


