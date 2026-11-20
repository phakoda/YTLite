/* Decompiled from supplied 5.2.2 arm package. VA 0x1956f8. skipSegmentIfNeeded */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::skipSegmentIfNeeded(ID param_1,SEL param_2)

{
  double dVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined1 extraout_b0;
  undefined1 extraout_b0_00;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 auStack_300 [128];
  undefined8 uStack_280;
  undefined8 *puStack_278;
  long *plStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined **ppuStack_230;
  undefined **ppuStack_228;
  undefined **ppuStack_220;
  undefined **ppuStack_218;
  undefined **ppuStack_210;
  undefined **ppuStack_208;
  undefined1 *puStack_200;
  undefined *puStack_1f8;
  undefined *puStack_1f0;
  undefined *puStack_1e8;
  undefined *puStack_1e0;
  undefined *puStack_1d8;
  undefined8 uStack_1d0;
  undefined *puStack_1c8;
  undefined *puStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined *puStack_1a8;
  long lStack_1a0;
  ID local_198;
  undefined **local_190;
  undefined **local_180;
  uint uStack_174;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_148;
  undefined **ppuStack_140;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **ppuStack_118;
  uint uStack_10c;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011aab78;
  local_8c = (uint)(DAT_01227838 == 0);
  local_a0 = &PTR_LAB_011aab98;
  local_b0 = &PTR_LAB_011aabb0;
  local_98 = &PTR__objc_msgSend_011aa770;
  local_c8 = &PTR__objc_msgSend_011aa770;
  ppuStack_c0 = &PTR__objc_msgSend_011aa770;
  local_d0 = &PTR_LAB_011aabd8;
  local_e8 = &PTR_LAB_011aabf8;
  ppuStack_e0 = &PTR__objc_msgSend_011aa770;
  local_f8 = &PTR_LAB_011aac10;
  local_108 = &PTR_LAB_011aac28;
  local_120 = &PTR_LAB_011aac48;
  ppuStack_118 = &PTR__objc_msgSend_011aa770;
  local_130 = &PTR_LAB_011aac60;
  local_148 = &PTR_LAB_011aac80;
  ppuStack_140 = &PTR__objc_msgSend_011aa770;
  local_158 = &PTR_LAB_011aac98;
  local_170 = &PTR_LAB_011aacb8;
  ppuStack_168 = &PTR__objc_msgSend_011aa770;
  local_180 = &PTR_LAB_011aacd0;
  local_190 = &PTR__objc_msgSend_011aa770;
  DAT_01227838 = 1;
  local_198 = param_1;
  iStack_a4 = FUN_00198c7c(param_1,PTR_s_shouldCheckSponsorBlock_0114dab8);
  if (iStack_a4 != 0) {
    ppuStack_240 = &PTR____CFConstantStringClassReference_011a9fd0;
    ppuStack_238 = &PTR____CFConstantStringClassReference_011aa090;
    ppuStack_230 = &PTR____CFConstantStringClassReference_011aa010;
    ppuStack_228 = &PTR____CFConstantStringClassReference_011a9f10;
    ppuStack_220 = &PTR____CFConstantStringClassReference_011a9f90;
    ppuStack_218 = &PTR____CFConstantStringClassReference_011a9ed0;
    ppuStack_210 = &PTR____CFConstantStringClassReference_011a9e90;
    ppuStack_208 = &PTR____CFConstantStringClassReference_011a9f50;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &ppuStack_240,8);
    uStack_1d0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_SBManager_0114eee8,PTR_s_sharedManager_0114c320);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_segments_0114dac0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_objectForKey__0114b238,*(undefined8 *)(local_198 + 0x10));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_release(uVar7);
    uStack_258 = 0;
    uStack_260 = 0;
    uStack_248 = 0;
    uStack_250 = 0;
    puStack_278 = (undefined8 *)0x0;
    uStack_280 = 0;
    uStack_268 = 0;
    plStack_270 = (long *)0x0;
    uVar7 = _objc_retain(uVar9);
    puStack_1f8 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    uStack_1b8 = uVar9;
    lVar10 = _objc_msgSend(uVar7,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_280,
                           auStack_300,0x10);
    uVar7 = uStack_1b8;
    puVar3 = PTR_s_uuid_0114dac8;
    puVar2 = PTR_s_containsObject__0114c848;
    uStack_b4 = (uint)(lVar10 == 0);
    if (lVar10 != 0) {
      lStack_1a0 = *plStack_270;
      puStack_1b0 = PTR_s_isEqualToString__0114ae48;
      puStack_1a8 = PTR_s_category_0114dad0;
      puStack_1c8 = PTR_s_start_0114b410;
      puStack_1c0 = PTR_s_currentVideoMediaTime_0114dab0;
      puStack_1e8 = PTR_s_segmentMeetsMinimumDuration__0114dae8;
      puStack_1e0 = PTR_s_end_0114dae0;
      puStack_1f0 = PTR_s_handleSkipSegment__0114daf0;
      puStack_1d8 = PTR_s_handleHighlightSegment__0114dad8;
      bVar5 = *plStack_270 == lStack_1a0;
      uStack_d4 = (uint)bVar5;
      puStack_200 = auStack_300;
      if (!bVar5) {
        _objc_enumerationMutation
                  (local_d0[bVar5] + (int)-(uRam00000000011aabe8 ^ 0x461c5bce),uStack_1b8);
      }
      uVar9 = *puStack_278;
      uVar8 = *(undefined8 *)(local_198 + 0x18);
      _objc_msgSend(uVar9,puVar3);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198f1c(uVar8,puVar2,uVar7);
      _objc_release(uVar7);
      puVar3 = puStack_1a8;
      uStack_ec = uVar6;
      if (uVar6 != 0) {
        uStack_174 = (uint)(lVar10 == 1);
                    /* WARNING: Could not recover jumptable at 0x00196370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_170[uStack_174] + (int)-(DAT_011aacc8 ^ 0xbc3db93e)))();
        return;
      }
      _objc_msgSend(local_e8[uVar6] + (int)-(uRam00000000011aac08 ^ 0xde812d4c),uVar9,puStack_1a8);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198cc4(uVar7,puStack_1b0,&PTR____CFConstantStringClassReference_011aa050);
      _objc_release(uVar7);
      uStack_fc = uVar6;
      if (uVar6 != 0) {
        uVar7 = _objc_loadWeakRetained(local_198 + 8);
        _objc_msgSend(uVar7,puStack_1c0);
        dVar1 = (double)CONCAT17(extraout_var_11,
                                 CONCAT16(extraout_var_09,
                                          CONCAT15(extraout_var_07,
                                                   CONCAT14(extraout_var_05,
                                                            CONCAT13(extraout_var_03,
                                                                     CONCAT12(extraout_var_01,
                                                                              CONCAT11(extraout_var,
                                                                                       extraout_b0))
                                                                    )))));
        _objc_msgSend(uVar9,puStack_1c8);
        bVar5 = false;
        bVar4 = true;
        if (!NAN(dVar1) &&
            !NAN((double)CONCAT17(extraout_var_12,
                                  CONCAT16(extraout_var_10,
                                           CONCAT15(extraout_var_08,
                                                    CONCAT14(extraout_var_06,
                                                             CONCAT13(extraout_var_04,
                                                                      CONCAT12(extraout_var_02,
                                                                               CONCAT11(
                                                  extraout_var_00,extraout_b0_00))))))))) {
          bVar5 = dVar1 == (double)CONCAT17(extraout_var_12,
                                            CONCAT16(extraout_var_10,
                                                     CONCAT15(extraout_var_08,
                                                              CONCAT14(extraout_var_06,
                                                                       CONCAT13(extraout_var_04,
                                                                                CONCAT12(
                                                  extraout_var_02,
                                                  CONCAT11(extraout_var_00,extraout_b0_00)))))));
          bVar4 = (double)CONCAT17(extraout_var_12,
                                   CONCAT16(extraout_var_10,
                                            CONCAT15(extraout_var_08,
                                                     CONCAT14(extraout_var_06,
                                                              CONCAT13(extraout_var_04,
                                                                       CONCAT12(extraout_var_02,
                                                                                CONCAT11(
                                                  extraout_var_00,extraout_b0_00))))))) <= dVar1;
        }
        _objc_release(uVar7);
        uStack_10c = (uint)(bVar4 && !bVar5);
                    /* WARNING: Could not recover jumptable at 0x001962f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_108[uStack_10c] + (int)-(uRam00000000011aac38 ^ 0x1db31cdc)))();
        return;
      }
      _objc_msgSend(local_f8[uVar6] + (int)-(uRam00000000011aac20 ^ 0xeb074805),uVar9,puVar3);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198d0c(uStack_1d0,puVar2,uVar7);
      _objc_release(uVar7);
      uStack_124 = uVar6;
                    /* WARNING: Could not recover jumptable at 0x00196138. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_120[uVar6] + (int)-(uRam00000000011aac58 ^ 0x885dbcda)))();
      return;
    }
    _objc_release(local_b0[uStack_b4] + (int)-(uRam00000000011aabc0 ^ 0xf43bb043),uStack_1b8);
    _objc_release(uVar7);
    _objc_release(uStack_1d0);
  }
  CallSupervisor(0x23fc);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


