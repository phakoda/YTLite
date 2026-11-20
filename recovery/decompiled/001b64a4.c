/* Decompiled from supplied 5.2.2 arm package. VA 0x1b64a4. adaptiveDiscord */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::adaptiveDiscord(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_01227aac = 1;
  iVar3 = FUN_001b9424(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_011b1ee0);
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_001b946c(uVar5,PTR_s_isCairo_0114dca8);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011b1ea0;
  if (iVar3 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011b1e60;
  }
  ppuVar2 = &PTR____CFConstantStringClassReference_011b1e20;
  if (iVar3 == 0) {
    ppuVar2 = &PTR____CFConstantStringClassReference_011b1de0;
  }
  if (iVar4 == 0) {
    ppuVar2 = ppuVar1;
  }
  _objc_msgSend(uVar5,PTR_s_imageWithName__0114c5b0,ppuVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  IVar7 = _objc_autoreleaseReturnValue(uVar6);
  return IVar7;
}


