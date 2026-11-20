/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1b4c. loadChunkMap */

/* Function Stack Size: 0x10 bytes */

bool YTPDownloader::loadChunkMap(ID param_1,SEL param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  ID IVar6;
  bool bVar7;
  bool bVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  int iVar16;
  undefined1 auStack_2b0 [128];
  undefined8 uStack_230;
  undefined8 uStack_228;
  long *plStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 auStack_1f0 [2];
  undefined8 auStack_1e0 [3];
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  long lStack_1b8;
  undefined *puStack_1b0;
  long lStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  int iStack_184;
  undefined8 *puStack_180;
  undefined8 *puStack_178;
  undefined1 *puStack_170;
  undefined8 uStack_168;
  ID IStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_140;
  undefined **local_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011b7770;
  local_7c = (uint)(DAT_01227d78 == 0);
  local_90 = &PTR_LAB_011b7790;
  local_a0 = &PTR_LAB_011b77a8;
  local_88 = &PTR__objc_msgSend_011b7210;
  local_b8 = &PTR_LAB_011b77c8;
  ppuStack_b0 = &PTR__objc_msgSend_011b7210;
  local_d0 = &PTR_LAB_011b77e8;
  ppuStack_c8 = &PTR__objc_msgSend_011b7210;
  local_e8 = &PTR_LAB_011b7808;
  ppuStack_e0 = &PTR__objc_msgSend_011b7210;
  local_f8 = &PTR_LAB_011b7820;
  local_110 = &PTR__objc_msgSend_011b7210;
  ppuStack_108 = &PTR__objc_msgSend_011b7210;
  local_118 = &PTR_LAB_011b7848;
  local_128 = &PTR__objc_msgSend_011b7210;
  local_130 = &PTR_LAB_011b7868;
  local_140 = &PTR_LAB_011b7880;
  local_150 = &PTR__objc_msgSend_011b7210;
  local_158 = &PTR__objc_msgSend_011b7210;
  DAT_01227d78 = 1;
  puStack_178 = auStack_1e0;
  puStack_180 = auStack_1f0;
  puStack_170 = auStack_2b0;
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfFile__0114b750,
                *(undefined8 *)(param_1 + 0x58));
  lVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
    bVar8 = 0;
  }
  else {
    uVar10 = _objc_retainAutorelease(local_90[uStack_94] + (int)-(DAT_011b77a0 ^ 0xa03db4e7),lVar9);
    lVar11 = _objc_msgSend(uVar10,PTR_s_bytes_0114b440);
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithBytes_length__0114b448,lVar11,0x20
                 );
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_hashForFile_fileSize__0114e000,*(undefined8 *)(param_1 + 0x20),
                  *(undefined8 *)(param_1 + 0x30));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uStack_a4 = FUN_001d5a50(uVar10,PTR_s_isEqualToData__0114e018,uVar12);
    if (uStack_a4 == 0) {
      _NSLog(local_a0[uStack_a4] + (int)-(uRam00000000011b77b8 ^ 0x1147c12b),
             &PTR____CFConstantStringClassReference_011b6b00);
      _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
      bVar8 = 0;
    }
    else {
      iVar16 = *(int *)(lVar11 + 0x20);
      uStack_1c8 = uVar12;
      uStack_1c0 = uVar10;
      lStack_1b8 = lVar9;
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,PTR_s_dictionary_0114c7f8);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + 0x40);
      *(undefined8 *)(param_1 + 0x40) = uVar10;
      IStack_160 = param_1;
      _objc_release(uVar12);
      puVar5 = puStack_180;
      puVar4 = PTR_s_numberWithUnsignedInt__0114cc58;
      uStack_bc = (uint)(iVar16 == 0);
      iStack_184 = iVar16;
      if (iVar16 == 0) {
LAB_001d2770:
        *(undefined8 *)(IStack_160 + 0x38) = 0;
        uStack_228 = 0;
        uStack_230 = 0;
        uStack_218 = 0;
        plStack_220 = (long *)0x0;
        uStack_208 = 0;
        uStack_210 = 0;
        uStack_1f8 = 0;
        uStack_200 = 0;
        _objc_msgSend(*(undefined8 *)(IStack_160 + 0x40),PTR_s_allValues_0114e028);
        uStack_168 = _objc_retainAutoreleasedReturnValue();
        puStack_178 = (undefined8 *)PTR_s_countByEnumeratingWithState_obje_0114b4e8;
        lVar9 = _objc_msgSend(uStack_168,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_230
                              ,puStack_170,0x10);
        uStack_fc = (uint)(lVar9 == 0);
        if (lVar9 != 0) {
          uStack_11c = (uint)(*plStack_220 == *plStack_220);
                    /* WARNING: Could not recover jumptable at 0x001d2874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          bVar8 = (*(code *)(local_118[uStack_11c] + (int)-(uRam00000000011b7858 ^ 0x57dd7b65)))();
          return bVar8;
        }
        _objc_release(uStack_168);
        bVar8 = 1;
        lVar9 = lStack_1b8;
        uVar10 = uStack_1c0;
        uVar12 = uStack_1c8;
      }
      else {
        iVar16 = 0;
        puStack_190 = PTR_s_numberWithUnsignedInt__0114cc58;
        puStack_198 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
        puStack_1a0 = PTR_s_numberWithUnsignedLongLong__0114e020;
        lVar9 = 0x24;
        puStack_1b0 = PTR_s_setObject_forKeyedSubscript__0114b068;
        lStack_1a8 = lVar11;
        while( true ) {
          IVar6 = IStack_160;
          puVar1 = (undefined8 *)(lVar11 + lVar9);
          uVar2 = *(uint *)((long)puVar1 + 0xc);
          uVar3 = (ulong)uVar2;
          bVar7 = *(ulong *)(IStack_160 + 0x48) < uVar3;
          uStack_d4 = (uint)(bVar7 || uVar2 < *(uint *)(puVar1 + 1));
          if (bVar7 || uVar2 < *(uint *)(puVar1 + 1)) break;
          uStack_168 = *puVar1;
          *puVar5 = &PTR____CFConstantStringClassReference_011b6a40;
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4);
          uVar10 = _objc_retainAutoreleasedReturnValue();
          puVar1 = puStack_178;
          *puStack_178 = uVar10;
          puVar5[1] = &PTR____CFConstantStringClassReference_011b6ac0;
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4,uVar3);
          uVar12 = _objc_retainAutoreleasedReturnValue();
          puVar1[1] = uVar12;
          _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puStack_198,puVar1,puVar5,2);
          uVar13 = _objc_retainAutoreleasedReturnValue();
          uVar15 = *(undefined8 *)(IVar6 + 0x40);
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puStack_1a0,uStack_168);
          uVar14 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar15,puStack_1b0,uVar13,uVar14);
          _objc_release(uVar14);
          _objc_release(uVar13);
          _objc_release(uVar12);
          lVar11 = lStack_1a8;
          _objc_release(uVar10);
          iVar16 = iVar16 + 1;
          uStack_ec = (uint)(iVar16 == iStack_184);
          if (iVar16 == iStack_184) goto LAB_001d2770;
          lVar9 = lVar9 + 0x10;
        }
        _NSLog(&PTR____CFConstantStringClassReference_011b6a80);
        _objc_msgSend(IVar6,PTR_s_cleanup_0114de90);
        bVar8 = 0;
        lVar9 = lStack_1b8;
        uVar10 = uStack_1c0;
        uVar12 = uStack_1c8;
      }
    }
    _objc_release(uVar12);
    _objc_release(uVar10);
  }
  _objc_release(lVar9);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return bVar8;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


