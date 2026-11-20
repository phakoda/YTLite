// Decompiled implementation evidence for PseudoDetentController. Not compilable source.

// -[PseudoDetentController initWithPresentedViewController:presentingViewController:], 0x1f0df0
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
  IVar2 = _objc_msgSendSuper2(&local_60,@selector(initWithPresentedViewController:presentingViewController:));
  local_4c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIView_0114ec30);
    uVar3 = _objc_msgSend(*(undefined8 *)PTR__CGRectZero_01060260,
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 8),
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 0x10),
                          *(undefined8 *)(PTR__CGRectZero_01060260 + 0x18),uVar3,
                          @selector(initWithFrame:));
    _objc_msgSend(IVar2,@selector(setDimmingView:),uVar3);
    _objc_release(uVar3);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x3fe0000000000000,uVar3,@selector(colorWithAlphaComponent:));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(dimmingView);
    _objc_msgSend(IVar2,@selector(dimmingView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setBackgroundColor:),uVar4);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(IVar2,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,uVar3,@selector(setAlpha:));
    _objc_release(uVar3);
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
    uVar3 = _objc_msgSend(uVar3,@selector(initWithTarget:action:),IVar2,
                          @selector(dismissController));
    _objc_msgSend(IVar2,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(addGestureRecognizer:),uVar3);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  return IVar2;
}



// -[PseudoDetentController dismissController], 0x1f0fec
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f0fec. dismissController */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::dismissController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,@selector(presentedViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(dismissViewControllerAnimated:completion:),1,0);
  _objc_release(uVar1);
  CallSupervisor(0xd1bb);
  return;
}



// -[PseudoDetentController frameOfPresentedViewInContainerView], 0x1f1050
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1050. frameOfPresentedViewInContainerView */

/* Function Stack Size: 0x10 bytes */

CGRect PseudoDetentController::frameOfPresentedViewInContainerView(ID param_1,SEL param_2)

{
  undefined1 auVar1 [32];
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  double dVar5;
  undefined8 in_d2;
  double in_d3;
  
  _objc_msgSend(param_1,@selector(containerView));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(bounds));
  _objc_release(uVar3);
  dVar5 = (double)_objc_msgSend(param_1,@selector(customHeight));
  puVar2 = @selector(heightCalculator);
  _objc_msgSend(param_1,@selector(heightCalculator));
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011bd630)[lVar4 == 0] + (int)-(DAT_011bd640 ^ 0x7820fee0),param_1,puVar2
                 );
    lVar4 = _objc_retainAutoreleasedReturnValue();
    dVar5 = (double)(**(code **)(lVar4 + 0x10))(in_d2,in_d3);
    _objc_release(lVar4);
  }
  auVar1._16_8_ = dVar5;
  auVar1._8_8_ = in_d2;
  auVar1._0_8_ = in_d3 - dVar5;
  auVar1._24_8_ = 0;
  return (CGRect)(auVar1 << 0x40);
}



// -[PseudoDetentController containerViewWillLayoutSubviews], 0x1f118c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f118c. containerViewWillLayoutSubviews */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::containerViewWillLayoutSubviews(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  ID local_50;
  undefined *puStack_48;
  
  puStack_48 = PTR_PseudoDetentController_0114f128;
  local_50 = param_1;
  _objc_msgSendSuper2(&local_50,@selector(containerViewWillLayoutSubviews));
  uVar2 = _objc_msgSend(param_1,@selector(frameOfPresentedViewInContainerView));
  _objc_msgSend(param_1,@selector(presentedView));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,in_d1,in_d2,in_d3,uVar1,@selector(setFrame:));
  _objc_release(uVar1);
  CallSupervisor(0xeef);
  return;
}



// -[PseudoDetentController presentationTransitionWillBegin], 0x1f1254
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1254. presentationTransitionWillBegin */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::presentationTransitionWillBegin(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined *local_88;
  undefined8 local_80;
  code *local_78;
  undefined *puStack_70;
  ID local_68;
  
  puVar2 = @selector(containerView);
  _objc_msgSend(param_1,@selector(containerView));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(uVar4,@selector(bounds));
  puVar1 = @selector(dimmingView);
  _objc_msgSend(param_1,@selector(dimmingView));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,in_d1,in_d2,in_d3,uVar5,@selector(setFrame:));
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(addSubview:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  puVar3 = @selector(presentedView);
  _objc_msgSend(param_1,@selector(presentedView));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(layer);
  _objc_msgSend(uVar4,@selector(layer));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(setCornerRadius:);
  _objc_msgSend(0x402e000000000000,uVar5,@selector(setCornerRadius:));
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setMasksToBounds:),1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x402e000000000000,uVar5,puVar2);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setMaskedCorners:),3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,@selector(presentedViewController));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(transitionCoordinator));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  local_88 = PTR___NSConcreteStackBlock_01060660;
  local_80 = DAT_00c4c228;
  local_78 = FUN_001f1554;
  puStack_70 = &DAT_01062f00;
  local_68 = param_1;
  FUN_001f1e20(uVar5,@selector(animateAlongsideTransition:completion:),&local_88,0);
  _objc_release(uVar5);
  CallSupervisor(0x8c85);
  return;
}



// -[PseudoDetentController dismissalTransitionWillBegin], 0x1f15b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f15b8. dismissalTransitionWillBegin */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::dismissalTransitionWillBegin(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  ID local_60;
  undefined *puStack_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  ID local_38;
  
  _objc_msgSend(param_1,@selector(presentedViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(transitionCoordinator));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  puStack_58 = PTR___NSConcreteStackBlock_01060660;
  local_50 = DAT_00c4c228;
  local_48 = FUN_001f1698;
  puStack_40 = &DAT_01062f00;
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001f16e0;
  puStack_68 = &DAT_01062f00;
  local_60 = param_1;
  local_38 = param_1;
  FUN_001f1ec8(uVar2,@selector(animateAlongsideTransition:completion:),&puStack_58,&local_80);
  _objc_release(uVar2);
  CallSupervisor(0xb01);
  return;
}



// -[PseudoDetentController heightCalculator], 0x1f1740
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1740. heightCalculator */

/* Function Stack Size: 0x10 bytes */

ID PseudoDetentController::heightCalculator(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_heightCalculator);
}



// -[PseudoDetentController setHeightCalculator:], 0x1f1750
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1750. setHeightCalculator: */

/* Function Stack Size: 0x18 bytes */

void PseudoDetentController::setHeightCalculator_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0xc9f7);
  return;
}



// -[PseudoDetentController customHeight], 0x1f1784
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1784. customHeight */

/* Function Stack Size: 0x10 bytes */

double PseudoDetentController::customHeight(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + (long)_customHeight);
}



// -[PseudoDetentController setCustomHeight:], 0x1f1794
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1794. setCustomHeight: */

/* Function Stack Size: 0x18 bytes */

void PseudoDetentController::setCustomHeight_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + (long)_customHeight) = param_3;
  return;
}



// -[PseudoDetentController dimmingView], 0x1f17a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f17a4. dimmingView */

/* Function Stack Size: 0x10 bytes */

ID PseudoDetentController::dimmingView(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_dimmingView);
}



// -[PseudoDetentController setDimmingView:], 0x1f17b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f17b4. setDimmingView: */

/* Function Stack Size: 0x18 bytes */

void PseudoDetentController::setDimmingView_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_dimmingView,param_3);
  CallSupervisor(0x26d9);
  return;
}



// -[PseudoDetentController .cxx_destruct], 0x1f17f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f17f0. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_dimmingView,0);
  _objc_storeStrong(param_1 + (long)_heightCalculator,0);
  CallSupervisor(0xea83);
  return;
}


