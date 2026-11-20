/* Decompiled from supplied 5.2.2 arm package. VA 0x2151c8. playerSlimBarVisibilityChange */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::playerSlimBarVisibilityChange(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012281a4 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_delegate_0114b530);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar4,PTR_s_responderRoot_0114dc98);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_class_0114ae88);
  _NSStringFromClass();
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00219b9c(uVar5,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_011cb860);
  _objc_release(uVar5);
  if (iVar2 != 0) {
    _objc_msgSend(uVar3,PTR_s_appView_0114e498);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_watchLayerView_0114e4a0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_watchViewController_0114e4c8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar1 = PTR_s_slimStatusBarDisplayStatusDidCha_0114e4c0;
    iVar2 = FUN_00219c24(uVar7,PTR_s_respondsToSelector__0114af58,
                         PTR_s_slimStatusBarDisplayStatusDidCha_0114e4c0);
    if (iVar2 != 0) {
      _objc_msgSend(uVar7,PTR_s_performSelector__0114b268,puVar1);
    }
    _objc_release(uVar7);
  }
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0x93e7);
  return;
}


