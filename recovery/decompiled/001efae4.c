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
  
  puVar1 = PTR_s_childViewControllers_0114e180;
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
  _objc_msgSend(uVar3,PTR_s_firstObject_0114b748);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_011bd2d0);
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
    _objc_msgSend(uVar3,PTR_s_setHeightCalculator__0114e1b0,&puStack_e0);
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,4);
    _objc_msgSend(param_3,PTR_s_setTransitioningDelegate__0114e1b8,uVar3);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  PTR_s_setPreferredContentSize__0114e1c0);
  }
  else {
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,1);
    _objc_msgSend(param_3,PTR_s_sheetPresentationController_0114e188);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar7 + 20.0,PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0,
                  PTR_s__detentWithIdentifier_constant__0114e190,
                  &PTR____CFConstantStringClassReference_011bd290);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    auStack_b0[0] = uVar4;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  auStack_b0,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setDetents__0114e198,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(uVar3,PTR_s_setPrefersGrabberVisible__0114e1a0,1);
    _objc_msgSend(0x402e000000000000,uVar3,PTR_s_setPreferredCornerRadius__0114e1a8);
  }
  _objc_msgSend(param_4,PTR_s_presentViewController_animated_c_0114b298,param_3,1,0);
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


