/* Decompiled from supplied 5.2.2 arm package. VA 0x1b49a8. copy */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::copy(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  ID IVar4;
  
  DAT_01227a80 = 1;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001b8eb4(uVar3,PTR_s_isCairo_0114dca8);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011b15c0;
  if (iVar2 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011b1580;
  }
  _objc_msgSend(uVar3,PTR_s_imageWithName__0114c5b0,ppuVar1);
  IVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  return IVar4;
}


