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
    _objc_msgSend(uVar2,PTR_s_setHeightCalculator__0114e1b0,&puStack_d0);
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,4);
    _objc_msgSend(param_3,PTR_s_setTransitioningDelegate__0114e1b8,uVar2);
    _objc_msgSend(*(undefined8 *)PTR__CGSizeZero_01060268,
                  *(undefined8 *)(PTR__CGSizeZero_01060268 + 8),param_3,
                  PTR_s_setPreferredContentSize__0114e1c0);
  }
  else {
    _objc_msgSend(param_3,PTR_s_setModalPresentationStyle__0114b958,1);
    _objc_msgSend(param_3,PTR_s_sheetPresentationController_0114e188);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_5,PTR__OBJC_CLASS___UISheetPresentationControllerDetent_0114efd0,
                  PTR_s__detentWithIdentifier_constant__0114e190,
                  &PTR____CFConstantStringClassReference_011bd370);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    auStack_a0[0] = uVar3;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  auStack_a0,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setDetents__0114e198,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(uVar2,PTR_s_setPrefersGrabberVisible__0114e1a0,1);
    _objc_msgSend(0x402e000000000000,uVar2,PTR_s_setPreferredCornerRadius__0114e1a8);
  }
  _objc_msgSend(param_4,PTR_s_presentViewController_animated_c_0114b298,param_3,1,0);
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


