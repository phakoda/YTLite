/* Decompiled from supplied 5.2.2 arm package. VA 0x1aaba4. FUN_001aaba4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001aaba4(long param_1)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_pageStyle_0114c698);
  if (lVar1 == 1) {
    if (*(char *)(param_1 + 0x28) == '\0') {
      _objc_msgSend(_UNK_00c4c390,_UNK_00c4c390,_UNK_00c4c390,0x3ff0000000000000,
                    PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithRed_green_blue_alpha__0114c5f8
                   );
      _objc_retainAutoreleasedReturnValue();
    }
    else {
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
      _objc_retainAutoreleasedReturnValue();
    }
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


