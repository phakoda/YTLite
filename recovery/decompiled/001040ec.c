/* Decompiled from supplied 5.2.2 arm package. VA 0x1040ec. getBestAudioFormat:playerVC: */

/* Function Stack Size: 0x20 bytes */

ID DownloadMenuHelper::getBestAudioFormat_playerVC_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ID IVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStack_270 [128];
  undefined8 uStack_1f0;
  undefined8 *puStack_1e8;
  long *plStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined1 *puStack_1a8;
  ID IStack_1a0;
  ID IStack_198;
  long lStack_190;
  undefined **local_188;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_168;
  uint uStack_15c;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118a400;
  local_7c = (uint)(DAT_01227190 == 0);
  local_90 = &PTR_LAB_0118a420;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118a448;
  local_c8 = &PTR_LAB_0118a468;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118a480;
  local_e8 = &PTR_LAB_0118a498;
  local_f8 = &PTR_LAB_0118a4b0;
  local_108 = &PTR_LAB_0118a4c8;
  local_118 = &PTR_LAB_0118a4e0;
  local_128 = &PTR_LAB_0118a4f8;
  local_138 = &PTR_LAB_0118a510;
  local_148 = &PTR_LAB_0118a528;
  local_158 = &PTR_LAB_0118a540;
  local_168 = &PTR_LAB_0118a558;
  local_180 = &PTR_LAB_011882f0;
  ppuStack_178 = &PTR_LAB_011882f0;
  local_188 = &PTR_LAB_011882f0;
  DAT_01227190 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  puStack_1e8 = (undefined8 *)0x0;
  uStack_1f0 = 0;
  uStack_1d8 = 0;
  plStack_1e0 = (long *)0x0;
  uVar7 = _objc_retain(param_3);
  puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar8 = _objc_msgSend(uVar7,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1f0,
                        auStack_270,0x10);
  puVar4 = PTR_s_itag_0114d010;
  puVar3 = PTR_s_mimeType_0114cf48;
  puVar1 = PTR_s_hasPrefix__0114aea0;
  uStack_94 = (uint)(lVar8 == 0);
  if (lVar8 == 0) {
    _objc_release(local_90[uStack_94] + (int)-(DAT_0118a430 ^ 0xd570ae18),param_3);
    _objc_msgSend(param_4,PTR_s_activeVideo_0114c788);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_selectedAudioFormat_0114cbf0);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,PTR_s_formatStream_0114d028);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar7);
    _objc_release(param_4);
    _objc_release(param_3);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar9 = _objc_autoreleaseReturnValue(uVar10);
    return IVar9;
  }
  puStack_1b0 = puVar2;
  lStack_190 = *plStack_1e0;
  uStack_b4 = (uint)(*plStack_1e0 == lStack_190);
  puStack_1a8 = auStack_270;
  IStack_1a0 = param_4;
  IStack_198 = param_3;
  if (*plStack_1e0 != lStack_190) {
    _objc_enumerationMutation(local_b0[uStack_b4] + (int)-(DAT_0118a458 ^ 0xf8b4dcea),param_3);
  }
  uVar11 = *puStack_1e8;
  _objc_msgSend(uVar11,puVar3);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_0011294c(uVar7,puVar1,&PTR____CFConstantStringClassReference_01186f70);
  _objc_release(uVar7);
  uStack_cc = uVar5;
  if (uVar5 != 0) {
    iVar6 = _objc_msgSend(local_c8[uVar5] + (int)-(uRam000000000118a478 ^ 0x642d41d0),uVar11,puVar4)
    ;
    uStack_dc = (uint)(iVar6 == 0x8c);
    if (iVar6 == 0x8c) {
      _objc_msgSend(uVar11,PTR_s_audioTrack_0114cbf8);
      lVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
      uStack_ec = (uint)(lVar8 == 0);
                    /* WARNING: Could not recover jumptable at 0x001046f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar9 = (*(code *)(local_e8[uStack_ec] + (int)-(DAT_0118a4a8 ^ 0xfaa25672)))();
      return IVar9;
    }
    iVar6 = _objc_msgSend(local_d8[uStack_dc] + (int)-(uRam000000000118a490 ^ 0xff062e83),uVar11,
                          puVar4);
    uStack_11c = (uint)(iVar6 == 0x8b);
                    /* WARNING: Could not recover jumptable at 0x00104548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar9 = (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000118a4f0 ^ 0x895ad973)))();
    return IVar9;
  }
  uStack_15c = (uint)(lVar8 == 1);
                    /* WARNING: Could not recover jumptable at 0x0010457c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar9 = (*(code *)(local_158[uStack_15c] + (int)-(uRam000000000118a550 ^ 0xf54c3168)))();
  return IVar9;
}


