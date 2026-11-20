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
  _objc_msgSendSuper2(&local_50,PTR_s_containerViewWillLayoutSubviews_0114e208);
  uVar2 = _objc_msgSend(param_1,PTR_s_frameOfPresentedViewInContainerV_0114e210);
  _objc_msgSend(param_1,PTR_s_presentedView_0114e218);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,in_d1,in_d2,in_d3,uVar1,PTR_s_setFrame__0114b570);
  _objc_release(uVar1);
  CallSupervisor(0xeef);
  return;
}


