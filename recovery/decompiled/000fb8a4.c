/* Decompiled from supplied 5.2.2 arm package. VA 0xfb8a4. showVideoSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showVideoSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_5d0 [128];
  undefined1 auStack_550 [64];
  undefined1 auStack_510 [32];
  undefined1 auStack_4f0 [160];
  undefined1 auStack_450 [128];
  undefined8 auStack_3d0 [8];
  long lStack_390;
  undefined1 *puStack_388;
  undefined1 *puStack_380;
  undefined *puStack_378;
  undefined8 uStack_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  undefined1 *puStack_358;
  undefined1 *puStack_350;
  ID IStack_348;
  undefined8 uStack_340;
  undefined1 *puStack_338;
  undefined *puStack_330;
  undefined *puStack_328;
  undefined *puStack_320;
  undefined *puStack_318;
  undefined *puStack_310;
  long lStack_300;
  uint uStack_2f4;
  undefined8 *puStack_2f0;
  undefined8 uStack_2e8;
  undefined8 uStack_2e0;
  undefined8 uStack_2d8;
  undefined8 uStack_2d0;
  ID IStack_2c8;
  long lStack_2c0;
  undefined *puStack_2b8;
  undefined *puStack_2b0;
  undefined *puStack_2a8;
  undefined *puStack_2a0;
  undefined *puStack_298;
  undefined *puStack_290;
  undefined *puStack_288;
  undefined *puStack_280;
  undefined *puStack_278;
  undefined *puStack_270;
  undefined *puStack_268;
  undefined *puStack_260;
  undefined *puStack_258;
  undefined *puStack_250;
  undefined *puStack_248;
  undefined8 uStack_240;
  undefined8 uStack_220;
  ID local_218;
  undefined *puStack_210;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **ppuStack_1d0;
  undefined **local_1c0;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **ppuStack_198;
  uint uStack_18c;
  undefined **local_188;
  undefined **local_178;
  undefined **local_168;
  undefined **local_160;
  undefined **local_150;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_01189960;
  local_8c = (uint)(DAT_01227120 == 0);
  local_a0 = &PTR_LAB_01189980;
  local_b0 = &PTR_LAB_01189998;
  local_c0 = &PTR_LAB_011899b0;
  local_d0 = &PTR_LAB_011899c8;
  local_e8 = &PTR_LAB_011899e8;
  local_98 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_011882f0;
  local_100 = &PTR_LAB_01189a08;
  ppuStack_f8 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_01189a30;
  local_130 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_01189a50;
  local_148 = &PTR_LAB_011882f0;
  local_150 = &PTR_LAB_01189a70;
  local_160 = &PTR_LAB_011882f0;
  local_168 = &PTR_LAB_01189a90;
  local_178 = &PTR_LAB_01189aa8;
  local_188 = &PTR_LAB_01189ac0;
  local_1a0 = &PTR_LAB_01189ae0;
  ppuStack_198 = &PTR_LAB_011882f0;
  local_1b8 = &PTR_LAB_011882f0;
  ppuStack_1b0 = &PTR_LAB_011882f0;
  local_1c0 = &PTR_LAB_01189b08;
  local_1d8 = &PTR_LAB_01189b28;
  ppuStack_1d0 = &PTR_LAB_011882f0;
  local_1e8 = &PTR_LAB_01189b40;
  local_1f8 = &PTR_LAB_011882f0;
  DAT_01227120 = 1;
  puStack_388 = auStack_450;
  puStack_350 = auStack_4f0;
  puStack_358 = auStack_510;
  puStack_338 = auStack_550;
  puStack_380 = auStack_5d0;
  local_218 = param_1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar12 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_a4 = FUN_0010ff38(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar11 = local_a0[uStack_a4] + (int)-(DAT_01189990 ^ 0x8f14101e);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_001103d4(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar11 = local_b0[uStack_b4] + (int)-(uRam00000000011899a8 ^ 0xe3b5511b);
    puVar12 = puVar2;
    if (uStack_b4 == 0) goto LAB_000fcdf8;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lStack_390 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = (uint)(lStack_390 == 0);
  puVar11 = local_c0[uStack_c4] + (int)-(uRam00000000011899c0 ^ 0xde087b55);
  if (lStack_390 != 0) {
    IStack_348 = param_4;
    puStack_2f0 = auStack_3d0;
    _objc_msgSend(lStack_390,PTR_s_videoID_0114c960);
    uStack_2d0 = _objc_retainAutoreleasedReturnValue();
    puVar11 = PTR_s_playerData_0114c7d0;
    _objc_msgSend(lStack_390,PTR_s_playerData_0114c7d0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_videoDetails_0114c7d8;
    _objc_msgSend(uVar5,PTR_s_videoDetails_0114c7d8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_author_0114c7e8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lStack_390,puVar11);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_title_0114c7f0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar11 = PTR_s_length_0114b438;
    uVar9 = _objc_msgSend(uVar7,PTR_s_length_0114b438);
    uStack_d4 = (uint)(0x1e < uVar9);
    if (0x1e < uVar9) {
      _objc_msgSend(local_d0[uStack_d4] + (int)-(uRam00000000011899d8 ^ 0xa0355e94),uVar7,
                    PTR_s_substringToIndex__0114ce80,0x1e);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_stringByAppendingString__0114b380,
                    &PTR____CFConstantStringClassReference_01185ef0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar7);
      _objc_release(uVar5);
      uVar7 = uVar6;
    }
    uStack_2d8 = uVar7;
    uVar9 = _objc_msgSend(uVar8,puVar11);
    puVar3 = puStack_2f0;
    uStack_ec = (uint)(200 < uVar9);
    uStack_2e0 = uVar8;
    if (200 < uVar9) {
      _objc_msgSend(local_e8[uStack_ec] + (int)-(uRam00000000011899f8 ^ 0x9524811c),uVar8,
                    PTR_s_substringToIndex__0114ce80,200);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,PTR_s_stringByAppendingString__0114b380,
                    &PTR____CFConstantStringClassReference_01185ef0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar7);
      uStack_2e0 = uVar5;
    }
    IVar4 = local_218;
    _objc_msgSend(local_218,PTR_s_getVideoFormatsArray_isShorts__0114ce88,param_3,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_getAudioFormatsArray__0114ce90,param_3);
    uStack_2e8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_getBestAudioFormat_playerVC__0114ce98,uStack_2e8,param_3);
    uStack_220 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_selectedAudioFormat_0114cbf0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_audioTrack_0114cbf8);
    lVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_2f4 = (uint)(lVar10 != 0);
    _objc_release();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    uStack_240 = _objc_retainAutoreleasedReturnValue();
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[3] = 0;
    puVar3[2] = 0;
    puVar3[5] = 0;
    puVar3[4] = 0;
    puVar3[7] = 0;
    puVar3[6] = 0;
    uVar5 = _objc_retain(uVar7);
    puStack_378 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    uStack_340 = uVar7;
    lStack_2c0 = _objc_msgSend(uVar5,PTR_s_countByEnumeratingWithState_obje_0114b4e8,puVar3,
                               puStack_388,0x10);
    uStack_104 = (uint)(lStack_2c0 == 0);
    IStack_2c8 = param_3;
    if (lStack_2c0 == 0) {
      _objc_release(local_100[uStack_104] + (int)-(uRam0000000001189a18 ^ 0x6a0a20ad),uStack_340);
      uStack_18c = (uint)(DAT_01227090 == 0);
                    /* WARNING: Could not recover jumptable at 0x000fcb58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_188[uStack_18c] + (int)-(uRam0000000001189ad0 ^ 0x113df662)))();
      return;
    }
    lStack_300 = *(long *)puVar3[2];
    uStack_360 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
    uStack_368 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
    uStack_370 = *(undefined8 *)PTR__NSBaselineOffsetAttributeName_01060350;
    puStack_250 = PTR_s_hasPrefix__0114aea0;
    puStack_248 = PTR_s_mimeType_0114cf48;
    puStack_260 = PTR_s_qualityLabel_0114cb08;
    puStack_258 = PTR_s_detailForMimeType__0114cf50;
    puStack_270 = PTR_s_stringFromByteCount_countStyle__0114cea8;
    puStack_268 = PTR_s_contentLength_0114cea0;
    puStack_280 = PTR_s_imageWithName__0114c5b0;
    puStack_278 = PTR_s_stringWithFormat__0114b378;
    puStack_210 = PTR_s_button_0114cc40;
    puStack_290 = PTR_s_currentAttributedTitle_0114cf68;
    puStack_288 = PTR_s_actionWithTitle_currentValue_ico_0114ced8;
    puStack_2a0 = PTR_s_string_0114b508;
    puStack_298 = PTR_s_mutableCopy_0114b010;
    puStack_318 = PTR_s_systemFontOfSize__0114b660;
    puStack_310 = PTR_s_redColor_0114b540;
    puStack_328 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
    puStack_320 = PTR_s_numberWithInt__0114b018;
    puStack_330 = PTR_s_setAttributes_range__0114cf78;
    puStack_2b0 = PTR_s_setAttributedTitle_forState__0114cf80;
    puStack_2a8 = PTR_s_rangeOfString_options__0114cf70;
    uStack_124 = (uint)(*(long *)puVar3[2] == lStack_300);
    lStack_2c0 = lStack_2c0 + -1;
    puStack_2b8 = PTR_s_addObject__0114b3a0;
                    /* WARNING: Could not recover jumptable at 0x000fc538. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_120[uStack_124] + (int)-(uRam0000000001189a40 ^ 0x6869cee7)))();
    return;
  }
  uStack_c4 = 1;
LAB_000fcdf8:
  _objc_release(puVar11,param_4);
  _objc_release(param_3);
  CallSupervisor(0x4c00);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


