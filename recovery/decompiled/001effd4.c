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
    _objc_msgSend(uVar3,PTR_s_setHeightCalculator__0114e1b0,&PTR___NSConcreteGlobalBlock_01062ee0);
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,4);
    _objc_msgSend(param_3,PTR_s_setTransitioningDelegate__0114e1b8,uVar3);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  PTR_s_setPreferredContentSize__0114e1c0);
    _objc_msgSend(param_4,PTR_s_presentViewController_animated_c_0114b298,param_3,1,0);
  }
  else {
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,1);
    _objc_msgSend(param_3,PTR_s_sheetPresentationController_0114e188);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0;
    _objc_msgSend(param_4,PTR_s_view_0114b090);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
    _objc_msgSend(in_d3 * 0.5,puVar1,PTR_s__detentWithIdentifier_constant__0114e190,
                  &PTR____CFConstantStringClassReference_011bd320);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    auStack_90[0] = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  auStack_90,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setDetents__0114e198,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_msgSend(uVar3,PTR_s_setPrefersGrabberVisible__0114e1a0,1);
    _objc_msgSend(0x402e000000000000,uVar3,PTR_s_setPreferredCornerRadius__0114e1a8);
    _objc_msgSend(param_4,PTR_s_presentViewController_animated_c_0114b298,param_3,1,0);
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


