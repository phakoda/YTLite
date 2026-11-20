/* Decompiled from supplied 5.2.2 arm package. VA 0x103a28. getAudioFormatsArray: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::getAudioFormatsArray_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  long lVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  long lVar12;
  long lVar13;
  undefined1 auStack_220 [128];
  undefined8 uStack_1a0;
  long lStack_198;
  long *plStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  long lStack_160;
  ID IStack_158;
  undefined *puStack_150;
  undefined1 *puStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined4 uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  int iStack_fc;
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
  local_78 = &PTR__objc_msgSend_0118a2f8;
  local_7c = (uint)(DAT_01227188 == 0);
  local_90 = &PTR__objc_msgSend_0118a318;
  local_a0 = &PTR_LAB_0118a330;
  local_b0 = &PTR_LAB_0118a348;
  local_c0 = &PTR_LAB_0118a360;
  local_88 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e0 = &PTR__objc_msgSend_0118a388;
  local_f8 = &PTR_LAB_0118a3a8;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118a3c8;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118a3e0;
  local_130 = &PTR_LAB_011882f0;
  DAT_01227188 = 1;
  puStack_148 = auStack_220;
  uVar4 = _objc_retain(param_3);
  puVar11 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_94 = FUN_00112660(uVar4,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0);
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar10 = local_90[uStack_94] + (int)-(uRam000000000118a328 ^ 0x403a1f5a);
  if (uStack_94 == 0) {
    uStack_a4 = FUN_00112598(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    uVar4 = 0;
    puVar10 = local_a0[uStack_a4] + (int)-(uRam000000000118a340 ^ 0x9ffb4893);
    puVar11 = puVar2;
    if (uStack_a4 == 0) goto LAB_00104038;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  uVar4 = 0;
  uStack_b4 = (uint)(lVar5 == 0);
  puVar10 = local_b0[uStack_b4] + (int)-(uRam000000000118a358 ^ 0x218e395d);
  if (lVar5 != 0) {
    lStack_160 = lVar5;
    IStack_158 = param_3;
    _objc_msgSend(lVar5,PTR_s_playerData_0114c7d0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_streamingData_0114cfd8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_adaptiveFormatsArray_0114cff0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    uStack_140 = _objc_retainAutoreleasedReturnValue();
    lStack_198 = 0;
    uStack_1a0 = 0;
    uStack_188 = 0;
    plStack_190 = (long *)0x0;
    uStack_178 = 0;
    uStack_180 = 0;
    uStack_168 = 0;
    uStack_170 = 0;
    uVar4 = _objc_retain(uVar7);
    puStack_150 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    uStack_138 = uVar7;
    lVar5 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1a0,
                          puStack_148,0x10);
    uVar6 = uStack_138;
    puVar2 = PTR_s_mimeType_0114cf48;
    puVar11 = PTR_s_addObject__0114b3a0;
    puVar1 = PTR_s_hasPrefix__0114aea0;
    uStack_c4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lVar13 = *plStack_190;
      lVar12 = 0;
      lVar9 = *plStack_190;
      while( true ) {
        uStack_e4 = (uint)(lVar9 == lVar13);
        if (lVar9 != lVar13) {
          _objc_enumerationMutation(uStack_138);
        }
        uVar6 = *(undefined8 *)(lStack_198 + lVar12 * 8);
        _objc_msgSend(uVar6,puVar2);
        uVar4 = _objc_retainAutoreleasedReturnValue();
        iVar3 = FUN_00112550(uVar4,puVar1,&PTR____CFConstantStringClassReference_01186ec0);
        _objc_release(uVar4);
        iStack_fc = iVar3;
        if (iVar3 != 0) {
          _objc_msgSend(uStack_140,puVar11,uVar6);
        }
        if (lVar5 + -1 == lVar12) break;
        uStack_114 = 0;
        lVar12 = lVar12 + 1;
        lVar9 = *plStack_190;
      }
      uStack_114 = 1;
      lVar5 = _objc_msgSend(uStack_138,puStack_150,&uStack_1a0,puStack_148,0x10);
      uStack_124 = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x00103e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar8 = (*(code *)(local_120[uStack_124] + (int)-(uRam000000000118a3f0 ^ 0x7054ba00)))();
      return IVar8;
    }
    _objc_release(uStack_138);
    uVar7 = uStack_140;
    _objc_msgSend(uStack_140,PTR_s_sortUsingComparator__0114d008,
                  &PTR___NSConcreteGlobalBlock_010622d0);
    uVar4 = _objc_msgSend(uVar7,PTR_s_copy_0114b058);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(lStack_160);
    puVar10 = &stack0xffffffffffffffa8;
    param_3 = IStack_158;
  }
LAB_00104038:
  _objc_release(puVar10,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
    return IVar8;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


