/* Decompiled from supplied 5.2.2 arm package. VA 0x9d4d4. FUN_0009d4d4 */

void FUN_0009d4d4(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 auStack_7f0 [128];
  undefined1 auStack_770 [64];
  undefined1 auStack_730 [16];
  undefined1 auStack_720 [16];
  undefined1 auStack_710 [16];
  undefined1 auStack_700 [16];
  undefined1 auStack_6f0 [16];
  undefined1 auStack_6e0 [16];
  undefined1 auStack_6d0 [16];
  undefined1 auStack_6c0 [16];
  undefined1 auStack_6b0 [32];
  undefined1 auStack_690 [192];
  undefined1 auStack_5d0 [16];
  undefined1 auStack_5c0 [16];
  undefined1 auStack_5b0 [16];
  undefined1 auStack_5a0 [16];
  undefined1 auStack_590 [16];
  undefined1 auStack_580 [16];
  undefined1 auStack_570 [32];
  undefined1 auStack_550 [192];
  undefined1 auStack_490 [16];
  undefined1 auStack_480 [16];
  undefined1 auStack_470 [16];
  undefined1 auStack_460 [16];
  undefined1 auStack_450 [16];
  undefined1 auStack_440 [16];
  undefined1 auStack_430 [16];
  undefined1 auStack_420 [16];
  undefined1 auStack_410 [16];
  undefined1 auStack_400 [16];
  undefined1 auStack_3f0 [56];
  undefined1 *puStack_3b8;
  undefined1 *puStack_3a8;
  undefined1 *puStack_3a0;
  undefined1 *puStack_398;
  undefined1 *puStack_390;
  undefined1 *puStack_388;
  undefined1 *puStack_380;
  undefined1 *puStack_378;
  undefined1 *puStack_370;
  undefined1 *puStack_368;
  undefined1 *puStack_360;
  undefined1 *puStack_358;
  undefined1 *puStack_350;
  undefined1 *puStack_348;
  undefined1 *puStack_340;
  undefined1 *puStack_338;
  undefined1 *puStack_330;
  undefined1 *puStack_328;
  undefined1 *puStack_320;
  undefined1 *puStack_318;
  undefined1 *puStack_310;
  undefined1 *puStack_308;
  undefined1 *puStack_300;
  undefined1 *puStack_2f8;
  undefined1 *puStack_2f0;
  undefined1 *puStack_2e8;
  undefined1 *puStack_2e0;
  undefined1 *puStack_2d8;
  undefined1 *puStack_2d0;
  undefined1 *puStack_2c8;
  undefined8 local_2c0;
  undefined1 *puStack_2b8;
  undefined **local_2b0;
  undefined **local_2a0;
  undefined **local_298;
  undefined **ppuStack_290;
  undefined **local_280;
  undefined **local_270;
  undefined **ppuStack_268;
  undefined **local_258;
  undefined **ppuStack_250;
  undefined **local_240;
  undefined **local_238;
  undefined **ppuStack_230;
  undefined **local_220;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **ppuStack_1e0;
  undefined **local_1d0;
  undefined **ppuStack_1c8;
  undefined **local_1b8;
  undefined **local_1b0;
  undefined **local_1a8;
  undefined **local_198;
  undefined **local_188;
  uint uStack_17c;
  undefined **local_178;
  undefined **local_170;
  undefined **local_168;
  undefined **local_158;
  undefined **local_148;
  undefined **local_140;
  undefined **local_130;
  undefined **local_128;
  undefined **local_118;
  undefined **local_110;
  undefined **ppuStack_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  int iStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  puVar1 = PTR_s_description_0114af00;
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__ytpBool_0117fa90;
  local_7c = (uint)(DAT_01226dd8 == 0);
  local_a0 = &PTR_LAB_0117fac8;
  local_90 = &PTR_LAB_0117fab0;
  ppuStack_88 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  ppuStack_b0 = &PTR_LAB_01175340;
  local_c0 = &PTR_FUN_0117faf0;
  local_d8 = &PTR_LAB_0117fb10;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_0117fb28;
  local_f8 = &PTR_LAB_0117fb40;
  local_110 = &PTR_LAB_01175340;
  ppuStack_108 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_0117fb68;
  local_128 = &PTR_LAB_01175340;
  local_130 = &PTR__objc_msgSend_0117fb88;
  local_140 = &PTR_LAB_01175340;
  local_148 = &PTR_LAB_0117fba8;
  local_158 = &PTR_LAB_0117fbc0;
  local_168 = &PTR_LAB_01175340;
  local_170 = &PTR_LAB_01175340;
  local_178 = &PTR_LAB_0117fbe8;
  local_188 = &PTR_FUN_0117fc00;
  local_198 = &PTR_LAB_0117fc18;
  local_1a8 = &PTR_LAB_01175340;
  local_1b0 = &PTR_LAB_01175340;
  local_1b8 = &PTR__objc_msgSend_0117fc40;
  local_1d0 = &PTR_LAB_0117fc60;
  ppuStack_1c8 = &PTR_LAB_01175340;
  local_1e8 = &PTR_LAB_0117fc80;
  ppuStack_1e0 = &PTR_LAB_01175340;
  local_1f8 = &PTR__objc_msgSend_0117fc98;
  local_210 = &PTR_LAB_0117fcb8;
  ppuStack_208 = &PTR_LAB_01175340;
  local_220 = &PTR_LAB_0117fcd0;
  local_238 = &PTR_LAB_01175340;
  ppuStack_230 = &PTR_LAB_01175340;
  local_240 = &PTR__objc_msgSend_0117fcf8;
  local_258 = &PTR_LAB_0117fd18;
  ppuStack_250 = &PTR_LAB_01175340;
  local_270 = &PTR__objc_msgSend_0117fd38;
  ppuStack_268 = &PTR_LAB_01175340;
  local_280 = &PTR_LAB_0117fd50;
  local_298 = &PTR_LAB_01175340;
  ppuStack_290 = &PTR_LAB_01175340;
  local_2a0 = &PTR_LAB_0117fd78;
  local_2b0 = &PTR_LAB_01175340;
  DAT_01226dd8 = 1;
  puStack_2e0 = auStack_3f0;
  puStack_328 = auStack_400;
  puStack_330 = auStack_410;
  puStack_318 = auStack_420;
  puStack_320 = auStack_430;
  puStack_308 = auStack_440;
  puStack_310 = auStack_450;
  puStack_2f8 = auStack_460;
  puStack_300 = auStack_470;
  puStack_2e8 = auStack_480;
  puStack_2f0 = auStack_490;
  puStack_2c8 = auStack_550;
  puStack_378 = auStack_570;
  puStack_3a0 = auStack_580;
  puStack_3a8 = auStack_590;
  puStack_390 = auStack_5a0;
  puStack_398 = auStack_5b0;
  puStack_380 = auStack_5c0;
  puStack_388 = auStack_5d0;
  puStack_2d8 = auStack_690;
  puStack_368 = auStack_6c0;
  puStack_370 = auStack_6d0;
  puStack_358 = auStack_6e0;
  puStack_360 = auStack_6f0;
  puStack_348 = auStack_700;
  puStack_350 = auStack_710;
  puStack_338 = auStack_720;
  puStack_340 = auStack_730;
  puStack_2b8 = auStack_770;
  puStack_2d0 = auStack_7f0;
  local_2c0 = param_2;
  _objc_msgSend(param_1,PTR_s_description_0114af00);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_containsString__0114af08;
  uStack_94 = FUN_000e4eb4(uVar5,PTR_s_containsString__0114af08,
                           &PTR____CFConstantStringClassReference_0116c180);
  if (uStack_94 == 0) {
    _objc_release(uVar5);
  }
  else {
    iVar3 = FUN_000e4a64(local_90[uStack_94] + (int)-(DAT_0117fac0 ^ 0xf171750c),
                         &PTR____CFConstantStringClassReference_0116c340);
    _objc_release(uVar5);
    if (iVar3 != 0) {
      iStack_a4 = iVar3;
      (*DAT_012265f0)(param_1,local_2c0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_setYogaChildren__0114c0f0,*(undefined8 *)PTR____NSArray0___01060670)
      ;
      if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
        ___stack_chk_fail();
      }
      _objc_autoreleaseReturnValue(uVar5);
      return;
    }
    iStack_a4 = 0;
  }
  _objc_msgSend(param_1,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = FUN_000e4a40(uVar5,puVar2,&PTR____CFConstantStringClassReference_0116c2c0);
  if (uStack_c4 == 0) {
    puStack_3b8 = auStack_6b0;
    _objc_msgSend(param_1,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar4 = FUN_000e49b8(uVar6,puVar2,&PTR____CFConstantStringClassReference_0116c3c0);
    _objc_release(uVar6);
    _objc_release(uVar5);
    uStack_dc = uVar4;
    if (uVar4 == 0) {
      _objc_msgSend(local_d8[uVar4] + (int)-(DAT_0117fb20 ^ 0x2fa680c9),param_1,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uVar4 = FUN_000e4790(uVar5,puVar2,&PTR____CFConstantStringClassReference_0116c100);
      _objc_release(uVar5);
      uStack_17c = uVar4;
                    /* WARNING: Could not recover jumptable at 0x0009ea94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_178[uVar4] + (int)-(DAT_0117fbf8 ^ 0x97a56833)))();
      return;
    }
  }
  else {
    _objc_release(local_c0[uStack_c4] + (int)-(DAT_0117fb00 ^ 0x7b04594a),uVar5);
  }
  (*DAT_012265f0)(param_1,local_2c0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_yogaChildren_0114c570);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(uVar5,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar5);
  lVar7 = _objc_msgSend(uVar6,PTR_s_count_0114b840);
  uStack_ec = (uint)(lVar7 == 5);
                    /* WARNING: Could not recover jumptable at 0x0009ebb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_e8[uStack_ec] + (int)-(uRam000000000117fb38 ^ 0x3e324cb2)))();
  return;
}


