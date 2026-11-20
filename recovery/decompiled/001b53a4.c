/* Decompiled from supplied 5.2.2 arm package. VA 0x1b53a4. music */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::music(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  DAT_01227a90 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b90d4(uVar3,PTR_s_isCairo_0114dca8);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011b18b0;
  if (iVar2 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011b1870;
  }
  _objc_msgSend(uVar3,PTR_s_imageWithName__0114c5b0,ppuVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}


