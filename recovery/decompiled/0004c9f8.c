/* Decompiled from supplied 5.2.2 arm package. VA 0x4c9f8. _innertubeName */

void _innertubeName(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  undefined1 auVar5 [16];
  
  DAT_012269e8 = 1;
  _objc_retain(param_1);
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSRegularExpression_0114ecb8,
                  PTR_s_regularExpressionWithPattern_opt_0114b9d0,
                  &PTR____CFConstantStringClassReference_0115e040,0,0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    uVar2 = _objc_msgSend(param_1,PTR_s_length_0114b438);
    _objc_msgSend(uVar1,PTR_s_firstMatchInString_options_range_0114b9d8,param_1,0,0,uVar2);
    lVar3 = _objc_retainAutoreleasedReturnValue();
    uVar2 = 0;
    if (lVar3 != 0) {
      uVar4 = _objc_msgSend(lVar3,PTR_s_numberOfRanges_0114b9e0);
      uVar2 = 0;
      if (2 < uVar4) {
        auVar5 = _objc_msgSend(lVar3,PTR_s_rangeAtIndex__0114b9e8,2);
        _objc_msgSend(param_1,PTR_s_substringWithRange__0114b6f0,auVar5._0_8_,auVar5._8_8_);
        uVar2 = _objc_retainAutoreleasedReturnValue();
      }
    }
    _objc_release(lVar3);
    _objc_release(uVar1);
  }
  _objc_release(param_1);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


