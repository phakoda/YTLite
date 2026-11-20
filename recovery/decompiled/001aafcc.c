/* Decompiled from supplied 5.2.2 arm package. VA 0x1aafcc. FUN_001aafcc */

void FUN_001aafcc(long param_1)

{
  undefined **ppuVar1;
  long lVar2;
  
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_pageStyle_0114c698);
  ppuVar1 = &PTR_s_blackColor_0114c400;
  if (lVar2 != 1) {
    ppuVar1 = &PTR_s_whiteColor_0114b080;
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,*ppuVar1);
  _objc_retainAutoreleasedReturnValue();
  _objc_autoreleaseReturnValue();
  return;
}


