/* Decompiled from supplied 5.2.2 arm package. VA 0x8c228. FUN_0008c228 */

undefined1  [16]
FUN_0008c228(undefined1 param_1 [16],double param_2,double param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6)

{
  double *pdVar1;
  undefined *puVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  undefined **ppuVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  undefined1 auVar13 [16];
  
  DAT_01226d24 = 1;
  uVar4 = _objc_retain(param_6);
  puVar2 = PTR_s_state_0114c560;
  lVar5 = _objc_msgSend(uVar4,PTR_s_state_0114c560);
  puVar9 = PTR_s_view_0114b090;
  if (lVar5 != 1) goto LAB_0008d2d8;
  _objc_msgSend((&PTR_LAB_0117e030)[lVar5 == 1] + (int)-(DAT_0117e040 ^ 0x4acf68ef),param_4,
                PTR_s_view_0114b090);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  dVar12 = (double)_objc_msgSend(param_6,PTR_s_locationInView__0114c978,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar9);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  fVar10 = (float)_objc_msgSend(uVar4,PTR_s_floatForKey__0114c308,
                                &PTR____CFConstantStringClassReference_01168d60);
  dVar11 = (double)fVar10;
  _objc_release(uVar4);
  puVar9 = (&PTR_LAB_0117e048)[dVar11 < dVar12] + (int)-(DAT_0117e058 ^ 0x3534a782);
  ppuVar6 = &PTR____CFConstantStringClassReference_01168d20;
  if (dVar11 < dVar12) {
    bVar3 = dVar12 < param_3 - dVar11;
    puVar9 = (&PTR_LAB_0117e060)[bVar3] + (int)-(uRam000000000117e070 ^ 0x51fc75e);
    ppuVar6 = &PTR____CFConstantStringClassReference_01168ce0;
    if (!bVar3) goto LAB_0008d0b8;
    lRam000000000115cd20 = -1;
  }
  else {
LAB_0008d0b8:
    lRam000000000115cd20 = _ytpInt(puVar9,ppuVar6);
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  DAT_0115cd28 = (double)_objc_msgSend(uVar4,PTR_s_brightness_0114c9b0);
  _objc_release(uVar4);
  if (DAT_012268d0 == 0) {
    DAT_012268d0 = _objc_getClass((&PTR_LAB_0117e080)[DAT_012268d0 == 0] +
                                  (int)-(DAT_0117e090 ^ 0x374cc5eb),s_LDVideoAdBlock_01168a20);
  }
  uVar4 = _objc_retainAutorelease();
  uVar4 = _objc_msgSend(uVar4,PTR_s_new_0114b030);
  fVar10 = (float)_objc_msgSend(uVar4,PTR_s_systemVolume_0114c9b8);
  DAT_0115cd30 = (double)fVar10;
  _objc_release(uVar4);
  lVar5 = lRam000000000115cd20;
  if (0 < lRam000000000115cd20) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    ppuVar6 = &PTR____CFConstantStringClassReference_01168c60;
    if (lVar5 != 1) {
      ppuVar6 = &PTR____CFConstantStringClassReference_01168c20;
    }
    _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,ppuVar6,0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    bVar3 = lRam000000000115cd20 == 2;
    pdVar1 = &DAT_0115cd28;
    if (lRam000000000115cd20 != 1) {
      pdVar1 = &DAT_0115cd30;
    }
    dVar12 = *pdVar1;
    param_2 = 100.0;
    _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar7 = FUN_000e03f8(&PTR____CFConstantStringClassReference_01168ba0);
    _objc_msgSend((double)(long)(dVar12 * 100.0),uVar4,
                  PTR_s_showPlayerToastWithText_value_st_0114c9c8,uVar8,(ulong)bVar3 << 1,uVar7);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
LAB_0008d2d8:
  lVar5 = _objc_msgSend(param_6,puVar2);
  bVar3 = lVar5 != 2;
  if ((!bVar3 && lRam000000000115cd20 != 0) && (bVar3 || -1 < lRam000000000115cd20)) {
    _objc_msgSend((&PTR_LAB_0117e0c0)
                  [(!bVar3 && lRam000000000115cd20 != 0) && (bVar3 || -1 < lRam000000000115cd20)] +
                  (int)-(DAT_0117e0d0 ^ 0x5607fa93),param_4,PTR_s_view_0114b090);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_6,PTR_s_translationInView__0114c898,uVar4);
    _objc_release(uVar4);
    if (lRam000000000115cd20 == 1) {
      dVar11 = DAT_0115cd28 + DAT_00c4c310 * -param_2;
      dVar12 = 1.0;
      if (dVar11 <= 1.0) {
        dVar12 = dVar11;
      }
      if (dVar12 <= 0.0) {
        dVar12 = 0.0;
      }
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_01168c60,0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      dVar11 = DAT_0115cd30 + DAT_00c4c318 * -param_2;
      dVar12 = 1.0;
      if (dVar11 <= 1.0) {
        dVar12 = dVar11;
      }
      if (dVar12 <= 0.0) {
        dVar12 = 0.0;
      }
      _objc_msgSend();
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_01168c20,0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
    }
    _objc_release(uVar4);
    _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar12,uVar4,PTR_s_updateToastText_value__0114c9d0,uVar8);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
  lVar5 = _objc_msgSend(param_6,puVar2);
  if (lVar5 != 3) {
    lVar5 = _objc_msgSend((&PTR_LAB_0117e108)[lVar5 == 3] + (int)-(DAT_0117e118 ^ 0xd0719b5e),
                          param_6,puVar2);
    if (lVar5 != 4) {
      _objc_release((&PTR_LAB_0117e120)[lVar5 == 4] + (int)-(uRam000000000117e130 ^ 0x25e75bfe),
                    param_6);
      CallSupervisor(0x60f8);
      auVar13._8_8_ = 0x1f;
      auVar13._0_8_ = 0x1a;
      return auVar13;
    }
  }
  lRam000000000115cd20 = 0xffffffffffffffff;
  DAT_0115cd28 = -1.0;
  DAT_0115cd30 = -1.0;
  _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  dVar12 = (double)_objc_msgSend(uVar4,PTR_s_alpha_0114c9d8);
  _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x0008d59c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar13 = (*(code *)((&PTR_LAB_0117e138)[dVar12 == 0.0] + (int)-(uRam000000000117e148 ^ 0x1475e04)
                      ))();
  return auVar13;
}


