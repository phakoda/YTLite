/* Decompiled from supplied 5.2.2 arm package. VA 0x1bc8e4. handlePanGesture: */

/* Function Stack Size: 0x18 bytes */

void ToastView::handlePanGesture_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined8 uVar13;
  double dVar14;
  double in_d1;
  double dVar15;
  undefined1 auStack_3c0 [128];
  undefined1 auStack_340 [128];
  undefined1 auStack_2c0 [128];
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined *puStack_1b8;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  ID IStack_170;
  undefined1 *puStack_168;
  ID IStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  int iStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint local_94;
  undefined **local_90;
  
  local_90 = &PTR_LAB_011b4058;
  local_94 = (uint)(DAT_01227af8 == 0);
  local_a8 = &PTR_LAB_011b4078;
  local_a0 = &PTR_LAB_011b39f0;
  local_c0 = &PTR_LAB_011b39f0;
  ppuStack_b8 = &PTR_LAB_011b39f0;
  local_c8 = &PTR_LAB_011b40a0;
  local_d8 = &PTR_LAB_011b40b8;
  local_f0 = &PTR_LAB_011b39f0;
  ppuStack_e8 = &PTR_LAB_011b39f0;
  local_100 = &PTR_LAB_011b40e8;
  ppuStack_f8 = &PTR_LAB_011b39f0;
  local_110 = &PTR_LAB_011b4100;
  local_120 = &PTR_LAB_011b4118;
  local_130 = &PTR_LAB_011b39f0;
  local_138 = &PTR_LAB_011b4138;
  local_148 = &PTR_LAB_011b39f0;
  local_150 = &PTR_LAB_011b39f0;
  local_158 = &PTR_LAB_011b39f0;
  DAT_01227af8 = 1;
  puStack_168 = auStack_340;
  _objc_retain(param_3);
  _objc_msgSend(param_1,PTR_s_superview_0114c820);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_translationInView__0114c898,uVar3);
  _objc_release(uVar3);
  iStack_ac = FUN_001c534c(param_1,PTR_s_isPinnedTop_0114dd48);
  puVar12 = PTR_s_state_0114c560;
  if (iStack_ac == 0) {
    dVar14 = 0.0;
    if (in_d1 <= 0.0) {
      dVar14 = in_d1;
    }
    dVar15 = -80.0;
    if (-80.0 <= dVar14) {
      dVar15 = dVar14;
    }
  }
  else {
    dVar15 = (double)NEON_fminnm(in_d1,0x4054000000000000);
  }
  lVar4 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  puVar11 = PTR_s_layer_0114ae60;
  uStack_cc = (uint)(lVar4 == 2);
  puVar10 = local_c8[uStack_cc] + (int)-(uRam00000000011b40b0 ^ 0xa9fca659);
  if (lVar4 == 2) {
    puStack_180 = puVar12;
    puStack_178 = auStack_3c0;
    IStack_160 = param_3;
    _objc_msgSend(param_1,PTR_s_layer_0114ae60);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_removeAllAnimations_0114dd60);
    _objc_release(uVar3);
    uVar3 = 0x3fd0000000000000;
    if (ABS(dVar15) <= 60.0) {
      uVar3 = 0x3ff0000000000000;
    }
    puStack_188 = PTR_s_animationWithKeyPath__0114d2f0;
    _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,PTR_s_animationWithKeyPath__0114d2f0,
                  &PTR____CFConstantStringClassReference_011b3580);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar12 = PTR__OBJC_CLASS___NSValue_0114ef60;
    IStack_170 = param_1;
    _objc_msgSend(param_1,puVar11);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_dc = (uint)(lVar4 == 0);
    if (lVar4 == 0) {
      uStack_1d8 = 0;
      uStack_1e0 = 0;
      uStack_1c8 = 0;
      uStack_1d0 = 0;
      uStack_1f8 = 0;
      uStack_200 = 0;
      uStack_1e8 = 0;
      uStack_1f0 = 0;
      uStack_218 = 0;
      uStack_220 = 0;
      uStack_208 = 0;
      uStack_210 = 0;
      uStack_238 = 0;
      uStack_240 = 0;
      uStack_228 = 0;
      uStack_230 = 0;
    }
    else {
      _objc_msgSend(&uStack_240,lVar4,PTR_s_transform_0114dd68);
    }
    puVar1 = PTR_s_valueWithCATransform3D__0114dd70;
    _objc_msgSend(puVar12,PTR_s_valueWithCATransform3D__0114dd70,&uStack_240);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_190 = PTR_s_setFromValue__0114d2f8;
    _objc_msgSend(uVar5,PTR_s_setFromValue__0114d2f8,uVar6);
    _objc_release(uVar6);
    _objc_release(lVar4);
    puVar12 = PTR__OBJC_CLASS___NSValue_0114ef60;
    _CATransform3DMakeTranslation(auStack_2c0,0,dVar15,0);
    _objc_msgSend(puVar12,puVar1,auStack_2c0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_198 = PTR_s_setToValue__0114d300;
    _objc_msgSend(uVar5,PTR_s_setToValue__0114d300,uVar6);
    _objc_release(uVar6);
    uVar6 = DAT_00c4c3c0;
    puStack_1a0 = PTR_s_setDuration__0114d318;
    _objc_msgSend(DAT_00c4c3c0,uVar5);
    uStack_1a8 = *(undefined8 *)PTR__kCAMediaTimingFunctionLinear_01060bd8;
    puStack_1b0 = PTR_s_functionWithName__0114dd78;
    _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_1b8 = PTR_s_setTimingFunction__0114dd80;
    _objc_msgSend(uVar5,PTR_s_setTimingFunction__0114dd80,uVar7);
    _objc_release(uVar7);
    puVar12 = PTR_s_setRemovedOnCompletion__0114dd88;
    _objc_msgSend(uVar5,PTR_s_setRemovedOnCompletion__0114dd88,0);
    puVar1 = PTR_s_setFillMode__0114dd90;
    uVar13 = *(undefined8 *)PTR__kCAFillModeForwards_01060bb8;
    _objc_msgSend(uVar5,PTR_s_setFillMode__0114dd90,uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,puStack_188,
                  &PTR____CFConstantStringClassReference_011b3540);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    param_1 = IStack_170;
    puVar2 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    _objc_msgSend(IStack_170,puVar11);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_opacity_0114dd98);
    _objc_msgSend(puVar2,PTR_s_numberWithFloat__0114c6c8);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_190,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_msgSend(uVar3,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_198,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(uVar6,uVar7,puStack_1a0);
    _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,puStack_1b0,uStack_1a8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_1b8,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(uVar7,puVar12,0);
    _objc_msgSend(uVar7,puVar1,uVar13);
    _objc_msgSend(param_1,puVar11);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar12 = PTR_s_addAnimation_forKey__0114d320;
    _objc_msgSend(uVar3,PTR_s_addAnimation_forKey__0114d320,uVar5,
                  &PTR____CFConstantStringClassReference_011b3500);
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar11);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,puVar12,uVar7,&PTR____CFConstantStringClassReference_011b3440);
    _objc_release(uVar3);
    _objc_release(uVar7);
    _objc_release(uVar5);
    puVar10 = &stack0xffffffffffffff80;
    puVar12 = puStack_180;
    param_3 = IStack_160;
  }
  lVar4 = _objc_msgSend(puVar10,param_3,puVar12);
  uStack_104 = (uint)(lVar4 == 3);
  puVar11 = local_100[uStack_104] + (int)-(uRam00000000011b40f8 ^ 0x4d75847f);
  if (lVar4 != 3) {
    lVar4 = _objc_msgSend(puVar11,param_3,puVar12);
    uStack_114 = (uint)(lVar4 == 4);
    puVar11 = local_110[uStack_114] + (int)-(uRam00000000011b4110 ^ 0x4b09c9e8);
    if (lVar4 != 4) {
      _objc_release(param_3);
      return;
    }
  }
  _objc_msgSend(puVar11,param_1,PTR_s_layer_0114ae60);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_removeAllAnimations_0114dd60);
  _objc_release(uVar3);
  uStack_124 = (uint)(60.0 < ABS(dVar15));
                    /* WARNING: Could not recover jumptable at 0x001bd53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_120[uStack_124] + (int)-(uRam00000000011b4128 ^ 0xebe10052)))();
  return;
}


