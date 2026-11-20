/* Decompiled from supplied 5.2.2 arm package. VA 0x200164. decodeHTML��hars: */

/* Function Stack Size: 0x18 bytes */

ID SRTParser::decodeHTML__hars_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  ID IVar10;
  undefined *puVar11;
  long lVar12;
  undefined8 uVar13;
  undefined1 auStack_210 [128];
  undefined8 uStack_190;
  long lStack_188;
  long *plStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined *puStack_f0;
  undefined1 *puStack_e8;
  long lStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011c2a08;
  local_74 = (uint)(DAT_012280a8 == 0);
  local_88 = &PTR_LAB_011c2a28;
  local_80 = &PTR_LAB_011c25d0;
  local_a0 = &PTR_LAB_011c25d0;
  ppuStack_98 = &PTR_LAB_011c25d0;
  local_a8 = &PTR_LAB_011c2a50;
  local_c0 = &PTR_LAB_011c2a70;
  ppuStack_b8 = &PTR_LAB_011c25d0;
  local_d0 = &PTR_LAB_011c2a88;
  DAT_012280a8 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_stringWithString__0114e340);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuStack_150 = &PTR____CFConstantStringClassReference_011c24f0;
  ppuStack_148 = &PTR____CFConstantStringClassReference_011c25b0;
  ppuStack_120 = &PTR____CFConstantStringClassReference_011c2470;
  ppuStack_118 = &PTR____CFConstantStringClassReference_011c2530;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011c24b0;
  ppuStack_138 = &PTR____CFConstantStringClassReference_011c2570;
  ppuStack_110 = &PTR____CFConstantStringClassReference_011c2430;
  ppuStack_108 = &PTR____CFConstantStringClassReference_011c23f0;
  ppuStack_130 = &PTR____CFConstantStringClassReference_011c23b0;
  ppuStack_128 = &PTR____CFConstantStringClassReference_011c2330;
  ppuStack_100 = &PTR____CFConstantStringClassReference_011c2370;
  ppuStack_f8 = &PTR____CFConstantStringClassReference_011c22f0;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&ppuStack_120,&ppuStack_150,6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lStack_188 = 0;
  uStack_190 = 0;
  uStack_178 = 0;
  plStack_180 = (long *)0x0;
  uStack_168 = 0;
  uStack_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uVar7 = _objc_retain();
  puStack_f0 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_e8 = auStack_210;
  lVar8 = _objc_msgSend(uVar7,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_190,
                        auStack_210,0x10);
  uStack_8c = (uint)(lVar8 == 0);
  puVar11 = local_88[uStack_8c] + (int)-(uRam00000000011c2a38 ^ 0x7c41b8a0);
  if (lVar8 == 0) {
LAB_00200898:
    _objc_release(puVar11,uVar6);
    _objc_release(uVar6);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
    return IVar10;
  }
  lStack_e0 = *plStack_180;
LAB_00200710:
  puVar3 = PTR_s_replaceOccurrencesOfString_withS_0114e348;
  puVar2 = PTR_s_length_0114b438;
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  lVar12 = 0;
  uStack_ac = (uint)(*plStack_180 == lStack_e0);
  puVar11 = local_a8[uStack_ac] + (int)-(uRam00000000011c2a60 ^ 0x6b237451);
  if (*plStack_180 == lStack_e0) goto LAB_002007bc;
  do {
    _objc_enumerationMutation(puVar11,uVar6);
LAB_002007bc:
    do {
      uVar13 = *(undefined8 *)(lStack_188 + lVar12 * 8);
      _objc_msgSend(uVar6,puVar1,uVar13);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_msgSend(uVar5,puVar2);
      _objc_msgSend(uVar5,puVar3,uVar13,uVar7,0,0,uVar9);
      _objc_release(uVar7);
      bVar4 = lVar8 + -1 == lVar12;
      uStack_c4 = (uint)bVar4;
      if (bVar4) {
        lVar8 = _objc_msgSend(local_c0[uStack_c4] + (int)-(uRam00000000011c2a80 ^ 0x1a9a2be7),uVar6,
                              puStack_f0,&uStack_190,puStack_e8,0x10);
        uStack_d4 = (uint)(lVar8 == 0);
        puVar11 = local_d0[uStack_d4] + (int)-(uRam00000000011c2a98 ^ 0xbcc3d46b);
        if (lVar8 != 0) goto LAB_00200710;
        uStack_d4 = 1;
        goto LAB_00200898;
      }
      lVar12 = lVar12 + 1;
      uStack_ac = (uint)(*plStack_180 == lStack_e0);
      puVar11 = local_a8[uStack_ac] + (int)-(uRam00000000011c2a60 ^ 0x6b237451);
    } while (*plStack_180 == lStack_e0);
  } while( true );
}


