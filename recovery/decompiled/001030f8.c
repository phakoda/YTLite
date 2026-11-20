/* Decompiled from supplied 5.2.2 arm package. VA 0x1030f8. getVideoFormatsArray:isShorts: */

/* Function Stack Size: 0x1c bytes */

ID DownloadMenuHelper::getVideoFormatsArray_isShorts_
             (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  ID IVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_2b0 [128];
  undefined8 uStack_230;
  undefined8 *puStack_228;
  long *plStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  long lStack_1e8;
  ID IStack_1e0;
  undefined *puStack_1d8;
  undefined1 *puStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  uint local_1b4;
  undefined8 uStack_1b0;
  long lStack_1a8;
  undefined8 uStack_1a0;
  ID local_198;
  long lStack_190;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined *puStack_178;
  undefined **local_170;
  undefined **ppuStack_168;
  uint uStack_15c;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118a198;
  local_7c = (uint)(DAT_01227180 == 0);
  local_90 = &PTR_LAB_0118a1b8;
  local_a0 = &PTR_LAB_0118a1d0;
  local_b0 = &PTR_LAB_0118a1e8;
  local_c0 = &PTR_LAB_0118a200;
  local_88 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118a228;
  local_f8 = &PTR_LAB_0118a248;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118a268;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118a280;
  local_138 = &PTR_LAB_0118a2a0;
  ppuStack_130 = &PTR_LAB_011882f0;
  local_148 = &PTR_LAB_0118a2b8;
  local_158 = &PTR_LAB_0118a2d0;
  local_170 = &PTR_LAB_011882f0;
  ppuStack_168 = &PTR_LAB_011882f0;
  DAT_01227180 = 1;
  puStack_1d0 = auStack_2b0;
  local_1b4 = param_4;
  local_198 = param_1;
  uVar6 = _objc_retain(param_3);
  puVar12 = PTR_s_playerResponse_0114c7c0;
  puVar2 = PTR_s_respondsToSelector__0114af58;
  uStack_94 = FUN_001124a8(uVar6,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0);
  puVar3 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar11 = local_90[uStack_94] + (int)-(uRam000000000118a1c8 ^ 0x3736dfb0);
  if (uStack_94 == 0) {
    uStack_a4 = FUN_001121d0(param_3,puVar2,PTR_s_contentPlayerResponse_0114c7c8);
    puVar11 = local_a0[uStack_a4] + (int)-(uRam000000000118a1e0 ^ 0x87398550);
    puVar12 = puVar3;
    if (uStack_a4 == 0) goto LAB_00103974;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lStack_1e8 = _objc_retainAutoreleasedReturnValue();
  uStack_b4 = (uint)(lStack_1e8 == 0);
  puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a1f8 ^ 0xa14bcfa7);
  if (lStack_1e8 != 0) {
    IStack_1e0 = param_3;
    _objc_msgSend(lStack_1e8,PTR_s_playerData_0114c7d0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_streamingData_0114cfd8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_adaptiveFormatsArray_0114cff0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar11 = PTR_s_array_0114c388;
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    uStack_1a0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,puVar11);
    uStack_1c0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,puVar11);
    uStack_1c8 = _objc_retainAutoreleasedReturnValue();
    puStack_228 = (undefined8 *)0x0;
    uStack_230 = 0;
    uStack_218 = 0;
    plStack_220 = (long *)0x0;
    uStack_208 = 0;
    uStack_210 = 0;
    uStack_1f8 = 0;
    uStack_200 = 0;
    uVar6 = _objc_retain(uVar8);
    puStack_1d8 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    uStack_1b0 = uVar8;
    lStack_190 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_230,
                               puStack_1d0,0x10);
    puVar2 = PTR_s_mimeType_0114cf48;
    puVar11 = PTR_s_hasPrefix__0114aea0;
    uStack_c4 = (uint)(lStack_190 == 0);
    if (lStack_190 == 0) {
      _objc_release(local_c0[uStack_c4] + (int)-(uRam000000000118a210 ^ 0xdbe65a5d),uStack_1b0);
      lVar9 = _objc_msgSend(uStack_1c0,PTR_s_count_0114b840);
      uStack_15c = local_1b4;
      if (lVar9 != 0) {
        uStack_15c = 1;
      }
                    /* WARNING: Could not recover jumptable at 0x00103900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar10 = (*(code *)(local_158[uStack_15c] + (int)-(uRam000000000118a2e0 ^ 0x3731106a)))();
      return IVar10;
    }
    lStack_1a8 = *plStack_220;
    puStack_188 = PTR_s_getResoForQuality__0114cff8;
    puStack_180 = PTR_s_qualityLabel_0114cb08;
    puStack_178 = PTR_s_addObject__0114b3a0;
    lStack_190 = lStack_190 + -1;
    bVar4 = *plStack_220 == lStack_1a8;
    uStack_e4 = (uint)bVar4;
    if (!bVar4) {
      _objc_enumerationMutation
                (local_e0[bVar4] + (int)-(uRam000000000118a238 ^ 0x78992f85),uStack_1b0);
    }
    uVar7 = *puStack_228;
    _objc_msgSend(uVar7,puStack_180);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar9 = _objc_msgSend(local_198,puStack_188,uVar6);
    _objc_release(uVar6);
    _objc_msgSend(uVar7,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_00112318(uVar6,puVar11,&PTR____CFConstantStringClassReference_01186e60);
    _objc_release(uVar6);
    _objc_msgSend(uVar7,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    FUN_00112360(uVar6,puVar11,&PTR____CFConstantStringClassReference_01186e20);
    _objc_release(uVar6);
    uVar1 = 0;
    if (0x8f < lVar9) {
      uVar1 = uVar5;
    }
    uStack_fc = 0;
    if (lVar9 < 0x439) {
      uStack_fc = uVar1;
    }
                    /* WARNING: Could not recover jumptable at 0x001036ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar10 = (*(code *)(local_f8[uStack_fc] + (int)-(DAT_0118a258 ^ 0xeb4326ee)))();
    return IVar10;
  }
  uStack_b4 = 1;
LAB_00103974:
  _objc_release(puVar11,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(0);
  return IVar10;
}


