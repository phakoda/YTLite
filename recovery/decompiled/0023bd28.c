/* Decompiled from supplied 5.2.2 arm package. VA 0x23bd28. showPlayerToastWithText:value:style:isCompact: */

/* Function Stack Size: 0x2c bytes */

void PlayerToast::showPlayerToastWithText_value_style_isCompact_
               (ID param_1,SEL param_2,ID param_3,double param_4,long_long param_5,bool param_6)

{
  ID IVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 uVar16;
  undefined *local_b0;
  undefined8 local_a8;
  code *local_a0;
  undefined *puStack_98;
  ID local_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  *(long_long *)(param_1 + (long)_style) = param_5;
  lVar15 = (long)_isCompact;
  *(char *)(param_1 + lVar15) = (char)param_6;
  puVar2 = PTR_s_imgForVal__0114e890;
  _objc_retain(param_3);
  _objc_msgSend(param_4,param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastImage),PTR_s_setImage__0114b8f8,uVar5);
  _objc_release(uVar5);
  puVar2 = PTR_s_setText__0114b388;
  IVar1 = param_3;
  if (*(char *)(param_1 + lVar15) != '\0') {
    IVar1 = 0;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),PTR_s_setText__0114b388,IVar1);
  _objc_release(param_3);
  _objc_msgSend(param_4,param_1,PTR_s_subLabelForVal_style__0114e898,param_5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar2,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_retainAutorelease();
  uVar6 = _objc_msgSend(uVar6,PTR_s_CGColor_0114c8c0);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_progressLayer),PTR_s_setBackgroundColor__0114b550,
                uVar6);
  _objc_release(uVar5);
  _objc_msgSend(param_1,PTR_s_prepareForPresentation_0114e8a0);
  _objc_msgSend(param_1,PTR_s_clearConstraints_0114e8a8);
  _objc_msgSend(param_1,PTR_s_setupConstraints_0114e8b0);
  _objc_msgSend(param_1,PTR_s_setupSubForStyle__0114e8b8,param_5);
  puVar3 = PTR_s_sourceView_0114d878;
  _objc_msgSend(param_1,PTR_s_sourceView_0114d878);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_addSubview__0114b0a8,param_1);
  _objc_release(uVar5);
  puVar2 = PTR_s_topAnchor_0114b598;
  lVar15 = (long)_activeConstraints;
  uVar14 = *(undefined8 *)(param_1 + lVar15);
  _objc_msgSend(param_1,PTR_s_topAnchor_0114b598);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_safeAreaLayoutGuide_0114c6d8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_0023ee84(param_1,PTR_s_isLandscape_0114dd30);
  uVar16 = 0x4014000000000000;
  if (iVar4 == 0) {
    uVar16 = 0x4034000000000000;
  }
  _objc_msgSend(uVar16,uVar5,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar8);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_centerXAnchor_0114b628;
  local_88 = uVar16;
  _objc_msgSend(param_1,PTR_s_centerXAnchor_0114b628);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar3);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_constraintEqualToAnchor__0114b5a0,uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  local_80 = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_88,
                2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,PTR_s_addObjectsFromArray__0114d000,uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar16);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20,PTR_s_activateConstraints__0114b650,
                *(undefined8 *)(param_1 + lVar15));
  local_b0 = PTR___NSConcreteStackBlock_01060660;
  local_a8 = DAT_00c4c228;
  local_a0 = FUN_0023c1a4;
  puStack_98 = &DAT_01061420;
  local_90 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0,PTR__OBJC_CLASS___UIView_0114ec30,
                PTR_s_animateWithDuration_delay_option_0114c8e8,0x20000,&local_b0,0);
  CallSupervisor(0x5a5c);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


