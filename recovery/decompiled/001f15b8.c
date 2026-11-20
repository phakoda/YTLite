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
  
  _objc_msgSend(param_1,PTR_s_presentedViewController_0114e1e8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_transitionCoordinator_0114e220);
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
  FUN_001f1ec8(uVar2,PTR_s_animateAlongsideTransition_compl_0114e228,&puStack_58,&local_80);
  _objc_release(uVar2);
  CallSupervisor(0xb01);
  return;
}


