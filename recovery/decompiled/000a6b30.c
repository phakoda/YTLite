/* Decompiled from supplied 5.2.2 arm package. VA 0xa6b30. FUN_000a6b30 */

void FUN_000a6b30(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puVar5;
  undefined1 auStack_5a0 [192];
  undefined1 auStack_4e0 [176];
  undefined1 auStack_430 [128];
  undefined1 auStack_3b0 [136];
  undefined1 *puStack_328;
  undefined1 *puStack_308;
  undefined1 *puStack_300;
  undefined1 *puStack_2e0;
  undefined **local_2d0;
  undefined **ppuStack_2c8;
  undefined **local_2b8;
  undefined **ppuStack_2b0;
  undefined **local_2a0;
  undefined **local_298;
  undefined **ppuStack_290;
  undefined **local_280;
  undefined **local_270;
  undefined **local_268;
  undefined **ppuStack_260;
  undefined **local_250;
  undefined **local_240;
  undefined **local_230;
  undefined **ppuStack_228;
  undefined **local_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b0;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01180a10;
  local_7c = (uint)(DAT_01226e14 == 0);
  local_90 = &PTR_LAB_01180a30;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a8 = &PTR_LAB_01180a50;
  ppuStack_a0 = &PTR_LAB_01175340;
  local_c0 = &PTR_LAB_01180a70;
  ppuStack_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR__objc_msgSend_01180a90;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_e8 = &PTR__objc_msgSend_01180aa8;
  local_100 = &PTR_LAB_01180ac8;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_110 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR_LAB_01180af0;
  local_130 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_01180b10;
  local_148 = &PTR_LAB_01180b28;
  local_160 = &PTR_LAB_01180b48;
  local_170 = &PTR__objc_msgSend_01180b60;
  local_180 = &PTR__objc_msgSend_01180b78;
  local_158 = &PTR_LAB_01175340;
  local_190 = &PTR_LAB_01180b90;
  local_1a8 = &PTR_LAB_01175340;
  ppuStack_1a0 = &PTR_LAB_01175340;
  local_1b0 = &PTR_LAB_01180bb8;
  local_1c8 = &PTR_LAB_01180bd8;
  ppuStack_1c0 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_01180bf0;
  local_1e8 = &PTR_LAB_01180c08;
  local_1f8 = &PTR__objc_msgSend_01180c20;
  local_210 = &PTR_LAB_01175340;
  ppuStack_208 = &PTR_LAB_01175340;
  local_218 = &PTR_LAB_01180c48;
  local_230 = &PTR_LAB_01180c68;
  ppuStack_228 = &PTR_LAB_01175340;
  local_240 = &PTR_LAB_01180c80;
  local_250 = &PTR_LAB_01180c98;
  local_268 = &PTR_LAB_01175340;
  ppuStack_260 = &PTR_LAB_01175340;
  local_270 = &PTR__objc_msgSend_01180cc0;
  local_280 = &PTR__objc_msgSend_01180cd8;
  local_298 = &PTR_LAB_01175340;
  ppuStack_290 = &PTR_LAB_01175340;
  local_2a0 = &PTR_LAB_01180d00;
  local_2b8 = &PTR_LAB_01180d20;
  ppuStack_2b0 = &PTR_LAB_01175340;
  local_2d0 = &PTR_LAB_01175340;
  ppuStack_2c8 = &PTR_LAB_01175340;
  DAT_01226e14 = 1;
  puStack_2e0 = auStack_3b0;
  puStack_300 = auStack_430;
  puStack_328 = auStack_5a0;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(DAT_01226908 == 0);
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_01180a40 ^ 0x56cb3cab),
                                  s_YTWatchViewController_0116d720);
  }
  lVar4 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  uStack_ac = FUN_000e6f78(uVar3,PTR_s_isKindOfClass__0114ad70,lVar4);
  puVar1 = PTR_s_activeVideo_0114c788;
  puVar5 = local_a8[uStack_ac] + (int)-(DAT_01180a60 ^ 0xc53b702a);
  if (uStack_ac != 0) {
    _objc_msgSend(param_1,PTR_s_activeVideo_0114c788);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    puVar5 = local_c0[uStack_c4] + (int)-(uRam0000000001180a80 ^ 0xd0dadd2);
    if (lVar4 != 0) {
      puStack_308 = auStack_4e0;
      uVar2 = FUN_000e6a98(param_1,PTR_s_isMDXActive_0114cb78);
      _objc_release(lVar4);
      _objc_release(uVar3);
      uStack_dc = uVar2;
      if (uVar2 == 0) {
        _objc_msgSend(local_d8[uVar2] + (int)-(DAT_01180aa0 ^ 0xefbdff5f),param_1,puVar1);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,PTR_s_selectableVideoFormats_0114cbd8);
        lVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_release();
        _objc_release(uVar3);
        uStack_ec = (uint)(lVar4 == 0);
                    /* WARNING: Could not recover jumptable at 0x000a7b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_e8[uStack_ec] + (int)-(DAT_01180ab8 ^ 0x7a37a251)))();
        return;
      }
      goto LAB_000a80a0;
    }
  }
  _objc_release(puVar5,uVar3);
LAB_000a80a0:
  CallSupervisor(0x79d);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


