/* Decompiled from supplied 5.2.2 arm package. VA 0x214d78. playerSlimBar */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::playerSlimBar(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  undefined8 uVar8;
  
  DAT_0122819c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_delegate_0114b530);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,PTR_s_responderRoot_0114dc98);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_class_0114ae88);
  _NSStringFromClass();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_00219a0c(uVar4,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_011cb7e0);
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar8 = 0;
  }
  else {
    _objc_msgSend(uVar2,PTR_s_appView_0114e498);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_watchLayerView_0114e4a0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_watchCollectionView_0114e4b8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_slimStatusBarView_0114e4b0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar8);
  return IVar7;
}


