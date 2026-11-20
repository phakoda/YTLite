/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1f7c. presentationControllerForPresentedViewController:presentingViewController:sourceViewController: */

/* Function Stack Size: 0x28 bytes */

ID PseudoDetentTransitioningDelegate::
   presentationControllerForPresentedViewController_presentingViewController_sourceViewController_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  puVar1 = PTR_PseudoDetentController_0114efe0;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithPresentedViewController__0114e1c8,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_msgSend(param_1,PTR_s_customHeight_0114e1f8);
  _objc_msgSend(uVar2,PTR_s_setCustomHeight__0114e230);
  _objc_msgSend(param_1,PTR_s_heightCalculator_0114e200);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setHeightCalculator__0114e1b0,uVar3);
  _objc_release(uVar3);
  IVar4 = _objc_autoreleaseReturnValue(uVar2);
  return IVar4;
}


