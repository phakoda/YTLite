// Decompiled implementation evidence for PseudoDetentTransitioningDelegate. Not compilable source.

// -[PseudoDetentTransitioningDelegate presentationControllerForPresentedViewController:presentingViewController:sourceViewController:], 0x1f1f7c
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
  uVar2 = _objc_msgSend(uVar2,@selector(initWithPresentedViewController:presentingViewController:),param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_msgSend(param_1,@selector(customHeight));
  _objc_msgSend(uVar2,@selector(setCustomHeight:));
  _objc_msgSend(param_1,@selector(heightCalculator));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setHeightCalculator:),uVar3);
  _objc_release(uVar3);
  IVar4 = _objc_autoreleaseReturnValue(uVar2);
  return IVar4;
}



// -[PseudoDetentTransitioningDelegate heightCalculator], 0x1f204c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f204c. heightCalculator */

/* Function Stack Size: 0x10 bytes */

ID PseudoDetentTransitioningDelegate::heightCalculator(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 8);
}



// -[PseudoDetentTransitioningDelegate setHeightCalculator:], 0x1f2054
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2054. setHeightCalculator: */

/* Function Stack Size: 0x18 bytes */

void PseudoDetentTransitioningDelegate::setHeightCalculator_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0xf64a);
  return;
}



// -[PseudoDetentTransitioningDelegate customHeight], 0x1f2084
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2084. customHeight */

/* Function Stack Size: 0x10 bytes */

double PseudoDetentTransitioningDelegate::customHeight(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x10);
}



// -[PseudoDetentTransitioningDelegate setCustomHeight:], 0x1f208c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f208c. setCustomHeight: */

/* Function Stack Size: 0x18 bytes */

void PseudoDetentTransitioningDelegate::setCustomHeight_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x10) = param_3;
  CallSupervisor(0xe11b);
  return;
}



// -[PseudoDetentTransitioningDelegate .cxx_destruct], 0x1f20ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f20ac. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentTransitioningDelegate::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x35b0);
  return;
}


