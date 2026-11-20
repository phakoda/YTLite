/* Decompiled from supplied 5.2.2 arm package. VA 0x1ab020. imageWithName: */

/* Function Stack Size: 0x18 bytes */

ID YTPMedia::imageWithName_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  puVar2 = PTR_YTPMedia_0114eae0;
  puVar1 = PTR_s_sharedMedia_0114ccd8;
  DAT_012279bc = 1;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001b74d4(uVar4,PTR_s_isCairo_0114dca8);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (iVar3 == 0) {
    _objc_msgSend(uVar4,PTR_s_imageWithName__0114c5b0,param_3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    IVar6 = param_3;
  }
  else {
    _objc_msgSend(param_3,PTR_s_stringByAppendingString__0114b380,
                  &PTR____CFConstantStringClassReference_011aed40);
    IVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    _objc_msgSend(uVar4,PTR_s_imageWithName__0114c5b0,IVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(IVar6);
  _objc_release(uVar4);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}


