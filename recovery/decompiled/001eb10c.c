/* Decompiled from supplied 5.2.2 arm package. VA 0x1eb10c. colorForSegment: */

/* Function Stack Size: 0x18 bytes */

ID YTLUserDefaults::colorForSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  ID IVar12;
  undefined **ppuStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined ***pppuStack_c8;
  undefined8 *puStack_c0;
  undefined8 uStack_b8;
  ID IStack_b0;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  puVar2 = PTR__OBJC_CLASS___UIColor_0114eb18;
  puVar1 = PTR_s_colorWithRed_green_blue_alpha__0114c5f8;
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011bd008;
  local_84 = (uint)(DAT_01227ea8 == 0);
  local_98 = &PTR_LAB_011bd028;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bce10;
  DAT_01227ea8 = 1;
  puStack_c0 = &uStack_150;
  pppuStack_c8 = &ppuStack_1b0;
  ppuStack_1b0 = &PTR____CFConstantStringClassReference_011bc830;
  IStack_b0 = param_3;
  _objc_retain(param_3);
  uVar4 = DAT_00c4c400;
  _objc_msgSend(DAT_00c4c3f0,DAT_00c4c3f8,DAT_00c4c400,DAT_00c4c2f8,puVar2,puVar1);
  uStack_150 = _objc_retainAutoreleasedReturnValue();
  uVar6 = DAT_00c4c368;
  ppuStack_1a8 = &PTR____CFConstantStringClassReference_011bc7f0;
  uStack_b8 = uStack_150;
  _objc_msgSend(DAT_00c4c408,DAT_00c4c410,DAT_00c4c418,DAT_00c4c368,
                PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uStack_148 = _objc_retainAutoreleasedReturnValue();
  ppuStack_1a0 = &PTR____CFConstantStringClassReference_011bc7b0;
  uStack_d0 = uStack_148;
  _objc_msgSend(DAT_00c4c318,DAT_00c4c318,DAT_00c4c420,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uStack_140 = _objc_retainAutoreleasedReturnValue();
  ppuStack_198 = &PTR____CFConstantStringClassReference_011bc730;
  uStack_d8 = uStack_140;
  _objc_msgSend(DAT_00c4c428,DAT_00c4c430,DAT_00c4c438,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uStack_138 = _objc_retainAutoreleasedReturnValue();
  ppuStack_190 = &PTR____CFConstantStringClassReference_011bc6f0;
  uStack_e0 = uStack_138;
  _objc_msgSend(0x3ff0000000000000,0x3ff0000000000000,DAT_00c4c440,uVar6,
                PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uStack_130 = _objc_retainAutoreleasedReturnValue();
  ppuStack_188 = &PTR____CFConstantStringClassReference_011bc5f0;
  uStack_e8 = uStack_130;
  _objc_msgSend(DAT_00c4c448,DAT_00c4c450,DAT_00c4c458,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuStack_180 = &PTR____CFConstantStringClassReference_011bc6b0;
  uStack_128 = uVar3;
  _objc_msgSend(uVar4,DAT_00c4c460,DAT_00c4c468,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuStack_178 = &PTR____CFConstantStringClassReference_011bc630;
  uStack_120 = uVar4;
  _objc_msgSend(DAT_00c4c470,DAT_00c4c478,DAT_00c4c480,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuStack_170 = &PTR____CFConstantStringClassReference_011bc770;
  uStack_118 = uVar5;
  _objc_msgSend(DAT_00c4c488,DAT_00c4c490,DAT_00c4c498,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_redColor_0114b540;
  ppuStack_168 = &PTR____CFConstantStringClassReference_011bc5b0;
  uStack_110 = uVar6;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_redColor_0114b540);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  ppuStack_160 = &PTR____CFConstantStringClassReference_011bc670;
  uStack_108 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_158 = &PTR____CFConstantStringClassReference_011bc570;
  uStack_100 = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_f8 = uVar9;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,puStack_c0,pppuStack_c8,0xc);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uStack_e8);
  _objc_release(uStack_e0);
  _objc_release(uStack_d8);
  _objc_release(uStack_d0);
  _objc_release(uStack_b8);
  IVar12 = IStack_b0;
  _objc_msgSend(uVar10,PTR_s_objectForKeyedSubscript__0114ae80,IStack_b0);
  lVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(IVar12);
  uStack_9c = (uint)(lVar11 == 0);
  if (lVar11 == 0) {
    uVar6 = 0;
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSKeyedArchiver_0114ec48,
                  PTR_s_archivedDataWithRootObject_requi_0114b6f8,lVar11,0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(lVar11);
  _objc_release(uVar10);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    IVar12 = _objc_autoreleaseReturnValue(uVar6);
    return IVar12;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


