/* Decompiled from supplied 5.2.2 arm package. VA 0x1acd54. musicTab */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::musicTab(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_012279e0 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b799c(uVar3,PTR_s_isCairo_0114dca8);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011af580;
  if (iVar2 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011af540;
  }
  _objc_msgSend(uVar3,PTR_s_imageWithName__0114c5b0,ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}


