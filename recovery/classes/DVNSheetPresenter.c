// Decompiled implementation evidence for DVNSheetPresenter. Not compilable source.

// +[DVNSheetPresenter presentCustomHeightViewController:fromViewController:], 0x1efae4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1efae4. presentCustomHeightViewController:fromViewController: */

/* Function Stack Size: 0x20 bytes */

void DVNSheetPresenter::presentCustomHeightViewController_fromViewController_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double dVar7;
  undefined *puStack_e0;
  undefined8 uStack_d8;
  code *pcStack_d0;
  undefined *puStack_c8;
  double dStack_c0;
  undefined8 auStack_b0 [2];
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  puVar1 = @selector(childViewControllers);
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011bd4d8;
  local_74 = (uint)(DAT_01227f00 == 0);
  local_88 = &PTR_LAB_011bd4f8;
  local_80 = &PTR_LAB_011bd390;
  local_a0 = &PTR_LAB_011bd390;
  ppuStack_98 = &PTR_LAB_011bd390;
  DAT_01227f00 = 1;
  _objc_retain(param_4);
  uVar3 = _objc_retain(param_3);
  _objc_msgSend(uVar3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(firstObject));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(valueForKey:),@"_sections");
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  dVar7 = (double)_calculateDetentHeight(uVar5);
  iVar2 = thunk_FUN_00b96438(2,0xf,0,0);
  uStack_8c = (uint)(iVar2 == 0);
  if (iVar2 == 0) {
    uVar3 = _objc_alloc_init(PTR_PseudoDetentTransitioningDelegate_0114efd8);
    puStack_e0 = PTR___NSConcreteStackBlock_01060660;
    uStack_d8 = DAT_00c4c230;
    pcStack_d0 = FUN_001eff74;
    puStack_c8 = &DAT_01062ea0;
    dStack_c0 = dVar7 + 20.0;
    _objc_msgSend(uVar3,@selector(setHeightCalculator:),&puStack_e0);
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),4);
    _objc_msgSend(param_3,@selector(setTransitioningDelegate:),uVar3);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  @selector(setPreferredContentSize:));
  }
  else {
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),1);
    _objc_msgSend(param_3,@selector(sheetPresentationController));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar7 + 20.0,PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0,
                  @selector(_detentWithIdentifier:constant:),
                  @"dvntm");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    auStack_b0[0] = uVar4;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  auStack_b0,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setDetents:),uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(uVar3,@selector(setPrefersGrabberVisible:),1);
    _objc_msgSend(0x402e000000000000,uVar3,@selector(setPreferredCornerRadius:));
  }
  _objc_msgSend(param_4,@selector(presentViewController:animated:completion:),param_3,1,0);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_release(uVar5);
  CallSupervisor(0xd2e9);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// +[DVNSheetPresenter presentHalfScreenViewController:fromViewController:], 0x1effd4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1effd4. presentHalfScreenViewController:fromViewController: */

/* Function Stack Size: 0x20 bytes */

void DVNSheetPresenter::presentHalfScreenViewController_fromViewController_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double in_d3;
  undefined8 auStack_90 [2];
  undefined **local_80;
  undefined **ppuStack_78;
  uint uStack_6c;
  undefined **local_68;
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011bd540;
  local_54 = (uint)(DAT_01227f08 == 0);
  local_68 = &PTR_LAB_011bd560;
  local_60 = &PTR_LAB_011bd390;
  local_80 = &PTR_LAB_011bd390;
  ppuStack_78 = &PTR_LAB_011bd390;
  DAT_01227f08 = 1;
  _objc_retain(param_4);
  _objc_retain(param_3);
  iVar2 = thunk_FUN_00b96438(2,0xf,0,0);
  uStack_6c = (uint)(iVar2 == 0);
  if (iVar2 == 0) {
    uVar3 = _objc_alloc_init(PTR_PseudoDetentTransitioningDelegate_0114efd8);
    _objc_msgSend(uVar3,@selector(setHeightCalculator:),&PTR___NSConcreteGlobalBlock_01062ee0);
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),4);
    _objc_msgSend(param_3,@selector(setTransitioningDelegate:),uVar3);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  @selector(setPreferredContentSize:));
    _objc_msgSend(param_4,@selector(presentViewController:animated:completion:),param_3,1,0);
  }
  else {
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),1);
    _objc_msgSend(param_3,@selector(sheetPresentationController));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0;
    _objc_msgSend(param_4,@selector(view));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(bounds));
    _objc_msgSend(in_d3 * 0.5,puVar1,@selector(_detentWithIdentifier:constant:),
                  @"dvntm");
    uVar5 = _objc_retainAutoreleasedReturnValue();
    auStack_90[0] = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  auStack_90,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setDetents:),uVar6);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_msgSend(uVar3,@selector(setPrefersGrabberVisible:),1);
    _objc_msgSend(0x402e000000000000,uVar3,@selector(setPreferredCornerRadius:));
    _objc_msgSend(param_4,@selector(presentViewController:animated:completion:),param_3,1,0);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar3);
  CallSupervisor(0x6da2);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// +[DVNSheetPresenter presentViewController:fromViewController:withHeight:], 0x1f0364
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f0364. presentViewController:fromViewController:withHeight: */

/* Function Stack Size: 0x28 bytes */

void DVNSheetPresenter::presentViewController_fromViewController_withHeight_
               (ID param_1,SEL param_2,ID param_3,ID param_4,double param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  double dStack_b0;
  undefined8 auStack_a0 [2];
  undefined **local_90;
  undefined **ppuStack_88;
  uint uStack_7c;
  undefined **local_78;
  undefined **local_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR_LAB_011bd588;
  local_64 = (uint)(DAT_01227f10 == 0);
  local_78 = &PTR_LAB_011bd5a8;
  local_70 = &PTR_LAB_011bd390;
  local_90 = &PTR_LAB_011bd390;
  ppuStack_88 = &PTR_LAB_011bd390;
  DAT_01227f10 = 1;
  _objc_retain(param_4);
  _objc_retain(param_3);
  iVar1 = thunk_FUN_00b96438(2,0xf,0,0);
  uStack_7c = (uint)(iVar1 == 0);
  if (iVar1 == 0) {
    uVar2 = _objc_alloc_init(PTR_PseudoDetentTransitioningDelegate_0114efd8);
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c230;
    pcStack_c0 = FUN_001f06d0;
    puStack_b8 = &DAT_01062ea0;
    dStack_b0 = param_5;
    _objc_msgSend(uVar2,@selector(setHeightCalculator:),&puStack_d0);
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),4);
    _objc_msgSend(param_3,@selector(setTransitioningDelegate:),uVar2);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  @selector(setPreferredContentSize:));
  }
  else {
    _objc_msgSend(param_3,@selector(setModalPresentationStyle:),1);
    _objc_msgSend(param_3,@selector(sheetPresentationController));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_5,PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0,
                  @selector(_detentWithIdentifier:constant:),
                  @"dvntm");
    uVar3 = _objc_retainAutoreleasedReturnValue();
    auStack_a0[0] = uVar3;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  auStack_a0,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(setDetents:),uVar4);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(uVar2,@selector(setPrefersGrabberVisible:),1);
    _objc_msgSend(0x402e000000000000,uVar2,@selector(setPreferredCornerRadius:));
  }
  _objc_msgSend(param_4,@selector(presentViewController:animated:completion:),param_3,1,0);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0xd6d5);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


