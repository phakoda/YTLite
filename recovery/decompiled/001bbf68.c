/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbf68. setupInterfaceWithText:progress:withStop:isStatus:isSuccess:withWait: */

/* Function Stack Size: 0x2c bytes */

void ToastView::setupInterfaceWithText_progress_withStop_isStatus_isSuccess_withWait_
               (ID param_1,SEL param_2,ID param_3,float param_4,bool param_5,bool param_6,
               bool param_7,bool param_8)

{
  undefined **ppuVar1;
  char cVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  double dVar18;
  double dVar19;
  double in_d2;
  undefined8 auStack_170 [2];
  undefined8 auStack_160 [2];
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined1 auStack_130 [16];
  undefined8 auStack_120 [2];
  undefined1 auStack_110 [16];
  undefined8 *puStack_100;
  undefined8 *puStack_f8;
  bool local_f0;
  bool bStack_ec;
  undefined1 *puStack_e8;
  bool local_dc;
  undefined8 *puStack_d8;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  puVar4 = PTR_ToastManager_0114ecd0;
  puVar3 = PTR_s_sharedManager_0114c320;
  puStack_e8 = (undefined1 *)&puStack_100;
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011b3ff0;
  local_8c = (uint)(DAT_01227af4 == 0);
  local_a0 = &PTR_LAB_011b4010;
  ppuStack_98 = &PTR_LAB_011b39f0;
  local_b8 = &PTR_LAB_011b39f0;
  ppuStack_b0 = &PTR_LAB_011b39f0;
  local_c0 = &PTR_LAB_011b4038;
  local_d0 = &PTR_LAB_011b39f0;
  DAT_01227af4 = 1;
  puStack_d8 = &uStack_150;
  puStack_f8 = auStack_160;
  puStack_100 = auStack_170;
  local_f0 = param_6;
  bStack_ec = param_5;
  local_dc = param_7;
  _objc_retain(param_3);
  _objc_msgSend(puVar4,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_registerToast__0114dd20,param_1);
  _objc_release(uVar8);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                PTR_s_setProgress_animated__0114dd28,0);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),PTR_s_setText__0114b388,param_3);
  _objc_release(param_3);
  puVar3 = PTR_s_setAlpha__0114b698;
  uVar8 = 0x3ff0000000000000;
  if (local_f0 == 0) {
    uVar8 = 0;
  }
  lVar14 = (long)_toastIcon;
  _objc_msgSend(uVar8,*(undefined8 *)(param_1 + lVar14),PTR_s_setAlpha__0114b698);
  uVar8 = 0x3ff0000000000000;
  if (bStack_ec == 0) {
    uVar8 = 0;
  }
  lVar16 = (long)_toastButton;
  _objc_msgSend(uVar8,*(undefined8 *)(param_1 + lVar16),puVar3);
  puVar3 = PTR_s_setHidden__0114bfc0;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),PTR_s_setHidden__0114bfc0,param_8);
  lVar16 = (long)_activityIndicator;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),puVar3,param_8 ^ 1);
  ppuVar1 = &PTR____CFConstantStringClassReference_011b3350;
  if (local_dc == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011b3310;
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,ppuVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),PTR_s_setImage__0114b8f8,uVar8);
  _objc_release(uVar8);
  ppuVar1 = &PTR_s_startAnimating_0114b0b0;
  if (param_8 == 0) {
    ppuVar1 = &PTR_s_stopAnimating_0114da48;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),*ppuVar1);
  lVar14 = (long)_sourceView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),PTR_s_addSubview__0114b0a8,param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),PTR_s_bringSubviewToFront__0114b7e8,param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),PTR_s_frame_0114c8b0);
  cVar2 = *(char *)(param_1 + (long)_isiPad);
  iVar7 = FUN_001c4c7c(param_1,PTR_s_isLandscape_0114dd30);
  dVar18 = DAT_00c4c2e0;
  if (iVar7 == 0) {
    dVar18 = 0.5;
  }
  dVar19 = 0.5;
  if (iVar7 == 0) {
    dVar19 = DAT_00c4c3b8;
  }
  if (cVar2 != '\0') {
    dVar19 = dVar18;
  }
  _objc_msgSend(0,param_1,PTR_s_calculateToastParametersWithKeyb_0114dd38,auStack_110,auStack_120,
                auStack_130);
  puVar3 = PTR_s_topAnchor_0114b598;
  _objc_msgSend(param_1,PTR_s_topAnchor_0114b598);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_constraintEqualToAnchor_constant_0114b630;
  _objc_msgSend(auStack_120[0],uVar8,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar16 = (long)_topConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar16);
  *(undefined8 *)(param_1 + lVar16) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = PTR_s_bottomAnchor_0114b5b0;
  _objc_msgSend(param_1,PTR_s_bottomAnchor_0114b5b0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(-*(double *)(puStack_e8 + -0x10),uVar8,puVar4,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar17 = (long)_bottomConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar17);
  *(undefined8 *)(param_1 + lVar17) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = PTR_s_centerXAnchor_0114b628;
  _objc_msgSend(param_1,PTR_s_centerXAnchor_0114b628);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_constraintEqualToAnchor__0114b5a0,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar13 = (long)_centerXConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar13);
  *(undefined8 *)(param_1 + lVar13) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(param_1,PTR_s_widthAnchor_0114b648);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(in_d2 * dVar19,uVar8,PTR_s_constraintEqualToConstant__0114b640);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar14 = (long)_widthConstraint;
  uVar10 = *(undefined8 *)(param_1 + lVar14);
  *(undefined8 *)(param_1 + lVar14) = uVar9;
  _objc_release(uVar10);
  _objc_release(uVar8);
  _objc_msgSend(param_1,PTR_s_heightAnchor_0114b638);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c358,uVar8,PTR_s_constraintGreaterThanOrEqualToCo_0114dd40);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar15 = (long)_heightConstraint;
  uVar10 = *(undefined8 *)(param_1 + lVar15);
  *(undefined8 *)(param_1 + lVar15) = uVar9;
  _objc_release(uVar10);
  _objc_release(uVar8);
  puVar5 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar3 = PTR_s_arrayWithObjects_count__0114b600;
  uStack_150 = *(undefined8 *)(param_1 + lVar13);
  uStack_148 = *(undefined8 *)(param_1 + lVar14);
  uStack_140 = *(undefined8 *)(param_1 + lVar15);
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,puStack_d8
                ,3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_activateConstraints__0114b650;
  _objc_msgSend(puVar5,PTR_s_activateConstraints__0114b650,uVar8);
  _objc_release(uVar8);
  iStack_a4 = FUN_001c4ea4(param_1,PTR_s_isPinnedTop_0114dd48);
  puVar5 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  if (iStack_a4 == 0) {
    uVar8 = *(undefined8 *)(param_1 + lVar17);
    puVar11 = puStack_100;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + lVar16);
    puVar11 = puStack_f8;
  }
  *puVar11 = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar3,puVar11,1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar8);
  _objc_release(uVar8);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  puVar3 = PTR_s_initWithTarget_action__0114c530;
  uVar8 = _objc_msgSend(uVar8,PTR_s_initWithTarget_action__0114c530,param_1,PTR_s_handleTap_0114ae40
                       );
  puVar4 = PTR_s_addGestureRecognizer__0114c540;
  _objc_msgSend(param_1,PTR_s_addGestureRecognizer__0114c540,uVar8);
  bVar6 = *(char *)(param_1 + (long)_ignoresPanGesture) == '\0';
  uStack_c4 = (uint)bVar6;
  if (bVar6) {
    uVar9 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
    uVar9 = _objc_msgSend(uVar9,puVar3,param_1,PTR_s_handlePanGesture__0114dd50);
    _objc_msgSend(param_1,puVar4,uVar9);
    _objc_release(uVar9);
  }
  _objc_msgSend(param_1,PTR_s_setupObservers_0114dd58);
  _objc_release(uVar8);
  CallSupervisor(0xdc6c);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


