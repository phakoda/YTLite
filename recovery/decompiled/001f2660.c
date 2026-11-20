/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2660. getVideoID: */

/* Function Stack Size: 0x18 bytes */

ID YTPPlayerHelper::getVideoID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  ID IVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  
  DAT_01227f98 = 1;
  _objc_retain(param_3);
  puVar2 = PTR_s_class_0114ae88;
  uVar9 = 0;
  if (param_3 != 0) {
    uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_class_0114ae88);
    puVar1 = PTR_s_isKindOfClass__0114ad70;
    uVar3 = FUN_001f3c98(param_3,PTR_s_isKindOfClass__0114ad70,uVar9);
    if (uVar3 == 0) {
      uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2);
      iVar4 = FUN_001f3b70(param_3,puVar1,uVar9);
      uVar9 = 0;
      if (iVar4 == 0) goto LAB_001f29f8;
      _objc_msgSend(param_3,PTR_s_absoluteString_0114c580);
      IVar8 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      _objc_retain((&PTR_LAB_011bdb88)[uVar3] + (int)-(uRam00000000011bdb98 ^ 0x60f62f76),param_3);
      IVar8 = param_3;
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSRegularExpression_0114ecb8,
                  PTR_s_regularExpressionWithPattern_opt_0114b9d0,
                  &PTR____CFConstantStringClassReference_011bd7f0,0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar9 = _objc_msgSend(IVar8,PTR_s_length_0114b438);
    _objc_msgSend(uVar5,PTR_s_firstMatchInString_options_range_0114b9d8,IVar8,0,0,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_msgSend(uVar6,PTR_s_numberOfRanges_0114b9e0);
    if (uVar7 < 2) {
      uVar9 = 0;
    }
    else {
      auVar10 = _objc_msgSend(uVar6,PTR_s_rangeAtIndex__0114b9e8,1);
      _objc_msgSend(IVar8,PTR_s_substringWithRange__0114b6f0,auVar10._0_8_,auVar10._8_8_);
      uVar9 = _objc_retainAutoreleasedReturnValue();
    }
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(IVar8);
  }
LAB_001f29f8:
  _objc_release(param_3);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar9);
  return IVar8;
}


