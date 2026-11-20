/* Decompiled from supplied 5.2.2 arm package. VA 0x2255cc. getPlayerIfAvailable */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::getPlayerIfAvailable(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_01228348 = 1;
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
  iVar1 = FUN_0022752c(uVar4,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_011ce910);
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    _objc_msgSend(uVar2,PTR_s_appView_0114e498);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_watchLayerView_0114e4a0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s__viewControllerForAncestor_0114ade0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_msgSend(uVar6,PTR_s_playerViewController_0114e4a8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar7 = _objc_autoreleaseReturnValue(uVar4);
  return IVar7;
}


