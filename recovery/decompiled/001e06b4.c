/* Decompiled from supplied 5.2.2 arm package. VA 0x1e06b4. initWithText: */

/* Function Stack Size: 0x18 bytes */

ID TranslatorVC::initWithText_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined8 auStack_1e0 [2];
  undefined **ppuStack_1d0;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1b8;
  undefined8 uStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined8 auStack_190 [2];
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined8 auStack_160 [2];
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined8 auStack_f0 [2];
  ID IStack_e0;
  undefined *puStack_d8;
  undefined *puStack_c8;
  undefined *puStack_c0;
  undefined8 *puStack_b8;
  undefined8 *puStack_b0;
  undefined8 *puStack_a8;
  ID IStack_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011ba738;
  local_74 = (uint)(DAT_01227e24 == 0);
  local_88 = &PTR_LAB_011ba758;
  ppuStack_80 = &PTR_LAB_011ba600;
  local_98 = &PTR_LAB_011ba600;
  DAT_01227e24 = 1;
  puStack_b8 = auStack_160;
  puStack_b0 = auStack_190;
  puStack_a8 = auStack_1e0;
  IStack_a0 = param_3;
  _objc_retain(param_3);
  puStack_d8 = PTR_TranslatorVC_0114f120;
  IStack_e0 = param_1;
  IVar4 = _objc_msgSendSuper2(&IStack_e0,PTR_s_initWithStyle__0114b790,2);
  uStack_8c = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_storeStrong(IVar4 + (long)_sourceText,IStack_a0);
    uVar5 = _objc_msgSend(PTR_YTPDB_0114ecc0,PTR_s_indexOfPreferredLanguage_0114c2d0);
    *(undefined8 *)(IVar4 + (long)_langIndex) = uVar5;
    ppuStack_150 = &PTR____CFConstantStringClassReference_011b9f00;
    puStack_c0 = PTR_s_ytl_localized_0114d190;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011b9f80);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    ppuStack_148 = &PTR____CFConstantStringClassReference_011b9d80;
    uStack_120 = uVar5;
    _objc_msgSend(PTR_YTPDB_0114ecc0,PTR_s_supportedLanguages_0114c2c8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    ppuStack_110 = &PTR____CFConstantStringClassReference_011b9e00;
    ppuStack_140 = &PTR____CFConstantStringClassReference_011b9f40;
    ppuStack_138 = &PTR____CFConstantStringClassReference_011b9e80;
    ppuStack_130 = &PTR____CFConstantStringClassReference_011b9dc0;
    ppuStack_108 = &PTR____CFConstantStringClassReference_011b9e40;
    ppuStack_100 = &PTR____CFConstantStringClassReference_011ba080;
    puStack_c8 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
    uStack_118 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_120,&ppuStack_150,5);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_arrayWithObjects_count__0114b600;
    auStack_f0[0] = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  auStack_f0,1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    lVar11 = (long)_type;
    uVar9 = *(undefined8 *)(IVar4 + lVar11);
    *(undefined8 *)(IVar4 + lVar11) = uVar8;
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar2 = puStack_c8;
    ppuStack_180 = &PTR____CFConstantStringClassReference_011b9f40;
    ppuStack_178 = &PTR____CFConstantStringClassReference_011b9dc0;
    ppuStack_170 = &PTR____CFConstantStringClassReference_011b9ec0;
    ppuStack_168 = &PTR____CFConstantStringClassReference_011b9fc0;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puStack_c8,&ppuStack_170,&ppuStack_180,2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_b8;
    *puStack_b8 = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar10 = (long)_translation;
    uVar7 = *(undefined8 *)(IVar4 + lVar10);
    *(undefined8 *)(IVar4 + lVar10) = uVar6;
    _objc_release(uVar7);
    _objc_release(uVar5);
    ppuStack_1d0 = &PTR____CFConstantStringClassReference_011b9f00;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011ba040,puStack_c0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    ppuStack_1a8 = &PTR____CFConstantStringClassReference_011ba000;
    ppuStack_1c8 = &PTR____CFConstantStringClassReference_011b9f40;
    ppuStack_1c0 = &PTR____CFConstantStringClassReference_011b9e80;
    ppuStack_1b8 = &PTR____CFConstantStringClassReference_011b9dc0;
    ppuStack_1a0 = &PTR____CFConstantStringClassReference_011b9d40;
    ppuStack_198 = &PTR____CFConstantStringClassReference_011b9d00;
    uStack_1b0 = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar2,&uStack_1b0,&ppuStack_1d0,4);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_b0;
    *puStack_b0 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = *(undefined8 *)(IVar4 + (long)_translate);
    *(undefined8 *)(IVar4 + (long)_translate) = uVar7;
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar3 = puStack_a8;
    *puStack_a8 = *(undefined8 *)(IVar4 + lVar11);
    puVar3[1] = *(undefined8 *)(IVar4 + lVar10);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = *(undefined8 *)(IVar4 + (long)_sections);
    *(undefined8 *)(IVar4 + (long)_sections) = uVar5;
    _objc_release(uVar6);
  }
  _objc_release(IStack_a0);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar4;
}


