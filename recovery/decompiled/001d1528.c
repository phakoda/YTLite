/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1528. saveChunkMap */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::saveChunkMap(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  ID IVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined4 auStack_250 [4];
  undefined4 auStack_240 [4];
  undefined8 auStack_230 [2];
  undefined1 auStack_220 [128];
  undefined8 uStack_1a0;
  long lStack_198;
  long *plStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined4 auStack_160 [6];
  undefined8 uStack_148;
  undefined *puStack_140;
  undefined1 *puStack_138;
  undefined8 uStack_130;
  long lStack_128;
  undefined *puStack_120;
  undefined4 *puStack_118;
  undefined4 *puStack_110;
  undefined8 *puStack_108;
  undefined8 uStack_100;
  ID local_f8;
  long lStack_f0;
  undefined *puStack_e8;
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
  local_78 = &PTR_LAB_011b76d8;
  local_7c = (uint)(DAT_01227d74 == 0);
  local_90 = &PTR_LAB_011b76f8;
  local_88 = &PTR__objc_msgSend_011b7210;
  local_a8 = &PTR__objc_msgSend_011b7210;
  ppuStack_a0 = &PTR__objc_msgSend_011b7210;
  local_b0 = &PTR_LAB_011b7720;
  local_c8 = &PTR_LAB_011b7740;
  ppuStack_c0 = &PTR__objc_msgSend_011b7210;
  local_d8 = &PTR_LAB_011b7758;
  DAT_01227d74 = 1;
  puStack_108 = auStack_230;
  puStack_110 = auStack_240;
  puStack_118 = auStack_250;
  local_f8 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableData_0114eba0,PTR_s_data_0114dff8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  IVar7 = local_f8;
  _objc_msgSend(local_f8,PTR_s_hashForFile_fileSize__0114e000,*(undefined8 *)(local_f8 + 0x20),
                *(undefined8 *)(local_f8 + 0x30));
  uStack_148 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_appendData__0114b4b8);
  auStack_160[0] = _objc_msgSend(*(undefined8 *)(IVar7 + 0x40),PTR_s_count_0114b840);
  puStack_120 = PTR_s_appendBytes_length__0114b4b0;
  uStack_100 = uVar9;
  _objc_msgSend(uVar9,PTR_s_appendBytes_length__0114b4b0,auStack_160,4);
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  uStack_170 = 0;
  lStack_198 = 0;
  uStack_1a0 = 0;
  uStack_188 = 0;
  plStack_190 = (long *)0x0;
  uStack_130 = _objc_retain(*(undefined8 *)(IVar7 + 0x40));
  puStack_140 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_138 = auStack_220;
  lVar10 = _objc_msgSend(uStack_130,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1a0,
                         auStack_220,0x10);
  puVar6 = puStack_108;
  puVar5 = puStack_110;
  puVar4 = puStack_118;
  uStack_94 = (uint)(lVar10 == 0);
  if (lVar10 == 0) {
LAB_001d1abc:
    _objc_release(uStack_130);
    uVar9 = uStack_100;
    FUN_001d5788(uStack_100,PTR_s_writeToFile_atomically__0114b700,*(undefined8 *)(local_f8 + 0x58),
                 1);
    _objc_release(uStack_148);
    _objc_release(uVar9);
    CallSupervisor(0xaf21);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(0x1a,0x1f,0,0);
    }
    return;
  }
  lStack_128 = *plStack_190;
LAB_001d1874:
  puVar2 = PTR_s_unsignedIntValue_0114e010;
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  lVar11 = 0;
  lStack_f0 = lVar10 + -1;
  puStack_e8 = PTR_s_unsignedLongLongValue_0114e008;
  uStack_b4 = (uint)(*plStack_190 == lStack_128);
  if (*plStack_190 == lStack_128) goto LAB_001d18dc;
  do {
    _objc_enumerationMutation(uStack_130);
LAB_001d18dc:
    do {
      uVar12 = *(undefined8 *)(lStack_198 + lVar11 * 8);
      uVar9 = _objc_msgSend(uVar12,puStack_e8);
      *puVar6 = uVar9;
      _objc_msgSend(*(undefined8 *)(local_f8 + 0x40),puVar1,uVar12);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puVar1,&PTR____CFConstantStringClassReference_011b68e0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar8 = _objc_msgSend(uVar9,puVar2);
      _objc_release(uVar9);
      *puVar5 = uVar8;
      _objc_msgSend(uVar12,puVar1,&PTR____CFConstantStringClassReference_011b68a0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar8 = _objc_msgSend(uVar9,puVar2);
      _objc_release(uVar9);
      *puVar4 = uVar8;
      uVar9 = uStack_100;
      puVar3 = puStack_120;
      _objc_msgSend(uStack_100,puStack_120,puVar6,8);
      _objc_msgSend(uVar9,puVar3,puVar5,4);
      _objc_msgSend(uVar9,puVar3,puVar4,4);
      _objc_release(uVar12);
      uStack_cc = (uint)(lStack_f0 == lVar11);
      if (lStack_f0 == lVar11) {
        lVar10 = _objc_msgSend(uStack_130,puStack_140,&uStack_1a0,puStack_138,0x10);
        uStack_dc = (uint)(lVar10 == 0);
        if (lVar10 != 0) goto LAB_001d1874;
        uStack_dc = 1;
        goto LAB_001d1abc;
      }
      lVar11 = lVar11 + 1;
      uStack_b4 = (uint)(*plStack_190 == lStack_128);
    } while (*plStack_190 == lStack_128);
  } while( true );
}


