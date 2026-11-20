/* Decompiled from supplied 5.2.2 arm package. VA 0x134788. segmentForItems: */

/* Function Stack Size: 0x18 bytes */

ID TabbarVC::segmentForItems_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  ID IVar11;
  undefined8 uVar12;
  undefined1 auStack_280 [128];
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 auStack_1c0 [2];
  undefined1 auStack_1b0 [16];
  undefined8 auStack_1a0 [2];
  undefined8 auStack_190 [3];
  undefined *puStack_178;
  undefined1 *puStack_170;
  undefined8 *puStack_168;
  undefined8 uStack_160;
  ID IStack_158;
  ID local_150;
  undefined *puStack_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined *puStack_130;
  undefined *puStack_128;
  long lStack_120;
  long lStack_118;
  undefined8 *puStack_110;
  undefined8 *puStack_108;
  undefined1 *puStack_100;
  undefined **local_f0;
  undefined **local_e0;
  undefined **ppuStack_d8;
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
  local_78 = &PTR_LAB_01190288;
  local_7c = (uint)(DAT_01227408 == 0);
  local_90 = &PTR_LAB_011902a8;
  local_88 = &PTR_LAB_0118faf0;
  local_a8 = &PTR_LAB_0118faf0;
  ppuStack_a0 = &PTR_LAB_0118faf0;
  local_b0 = &PTR_LAB_011902d0;
  local_c8 = &PTR_LAB_011902f0;
  ppuStack_c0 = &PTR_LAB_0118faf0;
  local_e0 = &PTR_LAB_01190310;
  ppuStack_d8 = &PTR_LAB_0118faf0;
  local_f0 = &PTR_LAB_01190328;
  DAT_01227408 = 1;
  puStack_100 = auStack_1b0;
  puStack_110 = auStack_1c0;
  puStack_168 = &uStack_200;
  puStack_170 = auStack_280;
  local_150 = param_3;
  puStack_108 = auStack_1a0;
  _objc_retain(param_3);
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UISegmentedControl_0114ee48);
  uVar6 = _objc_msgSend(uVar6,PTR_s_initWithItems__0114d590,
                        *(undefined8 *)PTR____NSArray0___01060670);
  _objc_msgSend(uVar6,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  uVar12 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
  auStack_1a0[0] = uVar12;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_tintColor_0114d1b8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
  auStack_190[0] = uVar8;
  IStack_158 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,auStack_190,auStack_1a0,1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_setTitleTextAttributes_forState__0114d6b8;
  _objc_msgSend(uVar6,PTR_s_setTitleTextAttributes_forState__0114d6b8,uVar9,4);
  _objc_release(uVar9);
  IVar11 = IStack_158;
  _objc_release(uVar8);
  _objc_release(uVar7);
  auStack_1c0[0] = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_100;
  puStack_108[-2] = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar5,puStack_110,1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uStack_160 = uVar6;
  _objc_msgSend(uVar6,puVar2,uVar8,0);
  puVar3 = puStack_168;
  _objc_release(uVar8);
  _objc_release(uVar7);
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_1e8 = 0;
  uStack_1f0 = 0;
  uVar6 = _objc_retain(param_3);
  puStack_178 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lStack_118 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,puVar3,
                             puStack_170,0x10);
  IVar4 = local_150;
  uStack_94 = (uint)(lStack_118 == 0);
  if (lStack_118 != 0) {
    lStack_120 = *(long *)puVar3[2];
    puStack_108 = (undefined8 *)PTR_s_filteredArrayUsingPredicate__0114c728;
    puStack_100 = PTR_s_predicateWithFormat__0114c720;
    puStack_110 = (undefined8 *)PTR_s_count_0114b840;
    puStack_128 = PTR_s_firstObject_0114b748;
    puStack_130 = PTR_s_objectForKeyedSubscript__0114ae80;
    puStack_138 = PTR_s_iconImageNamed__0114d6b0;
    puStack_140 = PTR_s_numberOfSegments_0114d6c0;
    puStack_148 = PTR_s_insertSegmentWithImage_atIndex_a_0114d6c8;
    lStack_118 = lStack_118 + -1;
    uStack_b4 = (uint)(*(long *)puVar3[2] == lStack_120);
    if (*(long *)puVar3[2] != lStack_120) {
      _objc_enumerationMutation(local_150);
    }
    thunk_FUN_001383f8(PTR__OBJC_CLASS___NSPredicate_0114ed68,puStack_100,
                       &PTR____CFConstantStringClassReference_0118f760,*(undefined8 *)puVar3[1]);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + (long)_tabs),puStack_108,uVar6);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar10 = _objc_msgSend(uVar6,puStack_110);
    uStack_cc = (uint)(lVar10 == 0);
                    /* WARNING: Could not recover jumptable at 0x00134d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar11 = (*(code *)(local_c8[uStack_cc] + (int)-(uRam0000000001190300 ^ 0x97ebfdf3)))();
    return IVar11;
  }
  _objc_release(local_150);
  _objc_release(IVar4);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uStack_160);
  return IVar11;
}


