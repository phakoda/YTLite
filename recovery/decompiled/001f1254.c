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
  
  puVar2 = PTR_s_containerView_0114e1f0;
  _objc_msgSend(param_1,PTR_s_containerView_0114e1f0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
  puVar1 = PTR_s_dimmingView_0114e1d8;
  _objc_msgSend(param_1,PTR_s_dimmingView_0114e1d8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,in_d1,in_d2,in_d3,uVar5,PTR_s_setFrame__0114b570);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_addSubview__0114b0a8,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  puVar3 = PTR_s_presentedView_0114e218;
  _objc_msgSend(param_1,PTR_s_presentedView_0114e218);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_layer_0114ae60;
  _objc_msgSend(uVar4,PTR_s_layer_0114ae60);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_setCornerRadius__0114ae68;
  _objc_msgSend(0x402e000000000000,uVar5,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setMasksToBounds__0114ae70,1);
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
  _objc_msgSend(uVar5,PTR_s_setMaskedCorners__0114b690,3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,PTR_s_presentedViewController_0114e1e8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_transitionCoordinator_0114e220);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  local_88 = PTR___NSConcreteStackBlock_01060660;
  local_80 = DAT_00c4c228;
  local_78 = FUN_001f1554;
  puStack_70 = &DAT_01062f00;
  local_68 = param_1;
  FUN_001f1e20(uVar5,PTR_s_animateAlongsideTransition_compl_0114e228,&local_88,0);
  _objc_release(uVar5);
  CallSupervisor(0x8c85);
  return;
}


