/* Decompiled from supplied 5.2.2 arm package. VA 0x1affe0. ytPlusShorts */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::ytPlusShorts(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01227a0c = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b7f74(uVar3,PTR_s_isCairo_0114dca8);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011b0100;
  if (iVar2 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011b00c0;
  }
  _objc_msgSend(uVar3,PTR_s_imageWithName_tintColor__0114ae58,ppuVar1,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}


