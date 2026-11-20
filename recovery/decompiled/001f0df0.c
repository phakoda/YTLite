/* Decompiled from supplied 5.2.2 arm package. VA 0x1f0df0. initWithPresentedViewController:presentingViewController: */

/* Function Stack Size: 0x20 bytes */

ID PseudoDetentController::initWithPresentedViewController_presentingViewController_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID local_60;
  undefined *puStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011bd610;
  puStack_58 = PTR_PseudoDetentController_0114f128;
  local_60 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_60,PTR_s_initWithPresentedViewController__0114e1c8);
  local_4c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIView_0114ec30);
    uVar3 = _objc_msgSend(*(undefined8 *)PTR__CGRectZero_01060260,
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 8),
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 0x10),
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 0x18),uVar3,
                          PTR_s_initWithFrame__0114b770);
    _objc_msgSend(IVar2,PTR_s_setDimmingView__0114e1d0,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x3fe0000000000000,uVar3,PTR_s_colorWithAlphaComponent__0114b548);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_dimmingView_0114e1d8;
    _objc_msgSend(IVar2,PTR_s_dimmingView_0114e1d8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setBackgroundColor__0114b550,uVar4);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(IVar2,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,uVar3,PTR_s_setAlpha__0114b698);
    _objc_release(uVar3);
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
    uVar3 = _objc_msgSend(uVar3,PTR_s_initWithTarget_action__0114c530,IVar2,
                          PTR_s_dismissController_0114e1e0);
    _objc_msgSend(IVar2,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_addGestureRecognizer__0114c540,uVar3);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  return IVar2;
}


