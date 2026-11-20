/* Decompiled from supplied 5.2.2 arm package. VA 0xbfa94. FUN_000bfa94 */

void FUN_000bfa94(undefined8 param_1,undefined8 param_2)

{
  undefined **ppuVar1;
  long lVar2;
  
  lVar2 = _objc_msgSend(param_2,PTR_s_userInterfaceStyle_0114c550);
  ppuVar1 = &PTR_s_blackColor_0114c400;
  if (lVar2 != 2) {
    ppuVar1 = &PTR_s_whiteColor_0114b080;
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,*ppuVar1);
  _objc_retainAutoreleasedReturnValue();
  _objc_autoreleaseReturnValue();
  return;
}


