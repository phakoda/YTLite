/* Decompiled from supplied 5.2.2 arm package. VA 0x1db9c8. removeChannelWithLink: */

/* Function Stack Size: 0x18 bytes */

void SbWhitelistVC::removeChannelWithLink_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  long lVar12;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined *puStack_140;
  undefined1 *puStack_138;
  undefined *puStack_130;
  ID IStack_128;
  long lStack_120;
  ID local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011b93b8;
  local_7c = (uint)(DAT_01227de0 == 0);
  local_a0 = &PTR_LAB_011b93f0;
  local_90 = &PTR_LAB_011b93d8;
  ppuStack_88 = &PTR_LAB_011b8c20;
  local_b8 = &PTR_LAB_011b8c20;
  ppuStack_b0 = &PTR_LAB_011b8c20;
  local_c0 = &PTR_LAB_011b9418;
  local_d8 = &PTR_LAB_011b9438;
  ppuStack_d0 = &PTR_LAB_011b8c20;
  local_f0 = &PTR_LAB_011b9458;
  ppuStack_e8 = &PTR_LAB_011b8c20;
  local_100 = &PTR_LAB_011b9470;
  local_110 = &PTR_LAB_011b8c20;
  DAT_01227de0 = 1;
  local_118 = param_3;
  _objc_retain(param_3);
  puVar9 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_011b8c00);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lVar7 = _objc_msgSend(uVar6,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar6);
  _objc_release(uVar5);
  uStack_94 = (uint)(lVar7 == 0);
  if (lVar7 != 0) {
    uStack_158 = 0;
    uStack_160 = 0;
    uStack_148 = 0;
    uStack_150 = 0;
    lStack_178 = 0;
    uStack_180 = 0;
    uStack_168 = 0;
    plStack_170 = (long *)0x0;
    uVar5 = _objc_retain(local_90[uStack_94] + (int)-(DAT_011b93e8 ^ 0xeb9e3bd2),lVar7);
    puVar1 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar8 = _objc_msgSend(uVar5,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_180,
                          auStack_200,0x10);
    uStack_a4 = (uint)(lVar8 == 0);
    puVar10 = local_a0[uStack_a4] + (int)-(uRam00000000011b9400 ^ 0x3b4445c8);
    if (lVar8 != 0) {
      puStack_140 = puVar1;
      puStack_130 = puVar9;
      lStack_120 = *plStack_170;
      puStack_138 = auStack_200;
      IStack_128 = param_1;
LAB_001dbd2c:
      puVar2 = PTR_s_objectForKeyedSubscript__0114ae80;
      puVar1 = PTR_s_isEqualToString__0114ae48;
      lVar12 = 0;
      uStack_c4 = (uint)(*plStack_170 == lStack_120);
      puVar9 = local_c0[uStack_c4] + (int)-(uRam00000000011b9428 ^ 0x71e7450d);
      if (*plStack_170 == lStack_120) goto LAB_001dbd6c;
      do {
        _objc_enumerationMutation(puVar9,lVar7);
LAB_001dbd6c:
        do {
          uVar11 = *(undefined8 *)(lStack_178 + lVar12 * 8);
          _objc_msgSend(lVar7,puVar2,uVar11);
          uVar5 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar5,puVar2,&PTR____CFConstantStringClassReference_011b8bc0);
          uVar6 = _objc_retainAutoreleasedReturnValue();
          uVar4 = FUN_001de19c(uVar6,puVar1,local_118);
          _objc_release(uVar6);
          uStack_dc = uVar4;
          if (uVar4 != 0) {
            _objc_msgSend(lVar7,PTR_s_removeObjectForKey__0114c810,uVar11);
            _objc_release(uVar5);
            puVar10 = &stack0xffffffffffffffd0;
            param_1 = IStack_128;
            puVar9 = puStack_130;
            goto LAB_001dbf4c;
          }
          _objc_release(local_d8[uVar4] + (int)-(uRam00000000011b9448 ^ 0x69d4ae7e),uVar5);
          bVar3 = lVar8 + -1 == lVar12;
          uStack_f4 = (uint)bVar3;
          if (bVar3) {
            lVar8 = _objc_msgSend(lVar7,puStack_140,&uStack_180,puStack_138,0x10);
            uStack_104 = (uint)(lVar8 == 0);
            puVar10 = local_100[uStack_104] + (int)-(uRam00000000011b9480 ^ 0xd3f4b1ab);
            param_1 = IStack_128;
            puVar9 = puStack_130;
            if (lVar8 == 0) goto LAB_001dbf4c;
            goto LAB_001dbd2c;
          }
          lVar12 = lVar12 + 1;
          uStack_c4 = (uint)(*plStack_170 == lStack_120);
          puVar9 = local_c0[uStack_c4] + (int)-(uRam00000000011b9428 ^ 0x71e7450d);
        } while (*plStack_170 == lStack_120);
      } while( true );
    }
LAB_001dbf4c:
    _objc_release(puVar10,lVar7);
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar9);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setObject_forKey__0114c2b8,lVar7,
                  &PTR____CFConstantStringClassReference_011b8c00);
    _objc_release(uVar5);
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar9);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    FUN_001de114(uVar5,PTR_s_synchronize_0114c2c0);
    _objc_release(uVar5);
    _objc_msgSend(param_1,PTR_s_setupWhitelist_0114e050);
  }
  _objc_release(lVar7);
  _objc_release(local_118);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


