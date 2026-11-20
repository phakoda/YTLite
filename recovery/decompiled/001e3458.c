/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3458. menuButtonWithTitle:array: */

/* Function Stack Size: 0x20 bytes */

ID TranslatorVC::menuButtonWithTitle_array_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ID IVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ID IVar12;
  undefined *puVar13;
  long lVar14;
  undefined *puStack_230;
  undefined8 uStack_228;
  code *pcStack_220;
  undefined *puStack_218;
  ID IStack_210;
  long lStack_208;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  ID IStack_138;
  undefined *puStack_130;
  undefined1 *puStack_128;
  long lStack_120;
  long lStack_118;
  undefined8 uStack_110;
  ID local_108;
  undefined *puStack_100;
  ID local_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011ba880;
  local_8c = (uint)(DAT_01227e48 == 0);
  local_a0 = &PTR_LAB_011ba8a0;
  local_98 = &PTR_LAB_011ba600;
  local_b8 = &PTR_LAB_011ba600;
  ppuStack_b0 = &PTR_LAB_011ba600;
  local_c0 = &PTR_LAB_011ba8c8;
  local_d8 = &PTR_LAB_011ba8e8;
  ppuStack_d0 = &PTR_LAB_011ba600;
  local_e8 = &PTR_LAB_011ba900;
  DAT_01227e48 = 1;
  IStack_138 = param_3;
  local_108 = param_1;
  local_f8 = param_4;
  _objc_retain(param_3);
  IVar4 = local_f8;
  _objc_retain(local_f8);
  _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,PTR_s_buttonWithType__0114b6a0,1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPDB_0114ecc0,PTR_s_supportedLanguages_0114c2c8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  IVar12 = local_108;
  lStack_118 = (long)_langIndex;
  _objc_msgSend(uVar8,PTR_s_objectAtIndexedSubscript__0114aeb0,
                *(undefined8 *)(local_108 + lStack_118));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_setTitle_forState__0114b6a8,uVar9,0);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(0x402c000000000000,IVar12,PTR_s_systemImage_withSize__0114d640,
                &PTR____CFConstantStringClassReference_011ba4d0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_setImage_forState__0114adf0,uVar8,0);
  _objc_release(uVar8);
  iVar6 = FUN_001e6088(IVar12,PTR_s_isRTL_0114d648);
  uVar8 = 3;
  if (iVar6 == 0) {
    uVar8 = 4;
  }
  _objc_msgSend(uVar7,PTR_s_setSemanticContentAttribute__0114b730,uVar8);
  _objc_msgSend(0x402a000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                PTR_s_systemFontOfSize__0114b660);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_titleLabel_0114b6d8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_setFont__0114b5e8,uVar8);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(IVar12,PTR_s_view_0114b090);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_tintColor_0114d1b8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_setTitleColor_forState__0114b6b0,uVar9,0);
  _objc_release(uVar9);
  _objc_release(uVar8);
  uStack_140 = uVar7;
  _objc_msgSend(uVar7,PTR_s_sizeToFit_0114b390);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  uStack_110 = _objc_retainAutoreleasedReturnValue();
  lStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  plStack_170 = (long *)0x0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  uVar8 = _objc_retain(IVar4);
  puStack_130 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_128 = auStack_200;
  lVar10 = _objc_msgSend(uVar8,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_180,
                         auStack_200,0x10);
  IVar12 = local_108;
  uVar8 = DAT_00c4c228;
  uStack_a4 = (uint)(lVar10 == 0);
  puVar13 = local_a0[uStack_a4] + (int)-(DAT_011ba8b0 ^ 0xec9b3caa);
  if (lVar10 == 0) {
LAB_001e3b48:
    IVar4 = local_f8;
    _objc_release(puVar13,local_f8);
    uVar7 = uStack_110;
    IVar12 = IStack_138;
    _objc_msgSend(PTR__OBJC_CLASS___UIMenu_0114ed00,PTR_s_menuWithTitle_children__0114c3e8,
                  IStack_138,uStack_110);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar8 = uStack_140;
    _objc_msgSend(uStack_140,PTR_s_setMenu__0114d658,uVar9);
    _objc_release(uVar9);
    _objc_msgSend(uVar8,PTR_s_setShowsMenuAsPrimaryAction__0114d660,1);
    _objc_release(uVar7);
    _objc_release(IVar4);
    _objc_release(IVar12);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar12 = _objc_autoreleaseReturnValue(uVar8);
    return IVar12;
  }
  lStack_120 = *plStack_170;
LAB_001e3958:
  puVar3 = PTR_s_setState__0114d650;
  puVar2 = PTR_s_actionWithTitle_image_identifier_0114c3b8;
  puVar1 = PTR_s_addObject__0114b3a0;
  lVar14 = 0;
  puStack_100 = PTR_s_indexOfObject__0114b020;
  uStack_c4 = (uint)(*plStack_170 == lStack_120);
  puVar13 = local_c0[uStack_c4] + (int)-(uRam00000000011ba8d8 ^ 0x2bb8da07);
  if (*plStack_170 == lStack_120) goto LAB_001e39c8;
  do {
    _objc_enumerationMutation(puVar13,local_f8);
LAB_001e39c8:
    do {
      uVar7 = *(undefined8 *)(lStack_178 + lVar14 * 8);
      lVar11 = _objc_msgSend(local_f8,puStack_100,uVar7);
      puStack_230 = PTR___NSConcreteStackBlock_01060660;
      uStack_228 = uVar8;
      pcStack_220 = FUN_001e3c1c;
      puStack_218 = &UNK_01062e20;
      IStack_210 = IVar12;
      lStack_208 = lVar11;
      _objc_msgSend(PTR__OBJC_CLASS___UIAction_0114ec40,puVar2,uVar7,0,0,&puStack_230);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar3,lVar11 == *(long *)(IVar12 + lStack_118));
      _objc_msgSend(uStack_110,puVar1,uVar7);
      _objc_release(uVar7);
      bVar5 = lVar10 + -1 == lVar14;
      uStack_dc = (uint)bVar5;
      if (bVar5) {
        lVar10 = _objc_msgSend(local_f8,puStack_130,&uStack_180,puStack_128,0x10);
        uStack_ec = (uint)(lVar10 == 0);
        puVar13 = local_e8[uStack_ec] + (int)-(uRam00000000011ba910 ^ 0x27262d9f);
        if (lVar10 != 0) goto LAB_001e3958;
        uStack_ec = 1;
        goto LAB_001e3b48;
      }
      lVar14 = lVar14 + 1;
      uStack_c4 = (uint)(*plStack_170 == lStack_120);
      puVar13 = local_c0[uStack_c4] + (int)-(uRam00000000011ba8d8 ^ 0x2bb8da07);
    } while (*plStack_170 == lStack_120);
  } while( true );
}


