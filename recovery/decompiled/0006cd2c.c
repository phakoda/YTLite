/* Decompiled from supplied 5.2.2 arm package. VA 0x6cd2c. FUN_0006cd2c */

undefined1  [16] FUN_0006cd2c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  undefined *puStack_240;
  undefined8 uStack_238;
  code *pcStack_230;
  undefined *puStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined *puStack_210;
  undefined8 uStack_208;
  code *pcStack_200;
  undefined *puStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined *puStack_1e0;
  undefined8 uStack_1d8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  undefined8 uStack_1c0;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  code *pcStack_1a0;
  undefined *puStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined **ppuStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined **local_120;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_0117b4b8;
  local_84 = (uint)(DAT_01226ad4 == 0);
  local_98 = &PTR_LAB_0117b4d8;
  local_a8 = &PTR_LAB_0117b4f0;
  local_c0 = &PTR_LAB_0117b510;
  local_90 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_0117b530;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_f0 = &PTR_LAB_0117b550;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_0117b570;
  ppuStack_100 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR_LAB_01175340;
  DAT_01226ad4 = 1;
  lVar2 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  uStack_9c = (uint)(lVar2 == 1);
  if (lVar2 == 1) {
    _objc_msgSend(param_1,PTR_s_keepalive_node_0114c568);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_copiedComment_0114c0d0);
    uStack_128 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_layer_0114ae60);
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    uStack_170 = uVar3;
    _objc_msgSend(uVar3,PTR_s_closestViewController_0114aec8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_view_0114b090);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_backgroundColor_0114c520);
    uStack_160 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
    uStack_ac = (uint)(lRam0000000001226868 == 0);
    if (lRam0000000001226868 == 0) {
      lRam0000000001226868 =
           _objc_getClass(local_a8[uStack_ac] + (int)-(uRam000000000117b500 ^ 0x2d91e111),
                          s_YTDefaultSheetController_011630d0);
    }
    uVar3 = _objc_retainAutorelease();
    _objc_msgSend(uVar3,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_c0[uStack_c4] + (int)-(uRam000000000117b520 ^ 0x3daede5),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    puStack_138 = PTR_s_ytl_defaultBundle_0114ae50;
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_140 = PTR_s_localizedStringForKey_value_tabl_0114b278;
    _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01163290,0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_localization_0114c5d0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar3 = DAT_00c4c228;
    puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1a8 = DAT_00c4c228;
    pcStack_1a0 = FUN_000c2724;
    puStack_198 = &DAT_01061cb0;
    uStack_190 = _objc_retain(uStack_128);
    puStack_148 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
    uStack_188 = param_1;
    _objc_msgSend(lVar2,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar5,uVar6,0,&puStack_1b0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_150 = PTR_s_addAction__0114b898;
    _objc_msgSend(uStack_130,PTR_s_addAction__0114b898,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_dc = (uint)(lRam0000000001226870 == 0);
    uStack_168 = param_1;
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_d8[uStack_dc] + (int)-(uRam000000000117b540 ^ 0xf5208888),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puStack_140,&PTR____CFConstantStringClassReference_01163190,0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_imageWithName__0114c5b0;
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_01163210);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_1e0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1d8 = uVar3;
    pcStack_1d0 = FUN_000c2c3c;
    puStack_1c8 = &DAT_010618c0;
    uStack_1c0 = _objc_retain(uStack_128);
    _objc_msgSend(lVar2,puStack_148,uVar5,uVar6,0,&puStack_1e0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_130,puStack_150,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_f4 = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_f0[uStack_f4] + (int)-(uRam000000000117b560 ^ 0xde4b5483),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    ppuStack_178 = &puStack_1e0;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puStack_140,&PTR____CFConstantStringClassReference_01163150,0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,&PTR____CFConstantStringClassReference_011631d0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_210 = PTR___NSConcreteStackBlock_01060660;
    uStack_208 = uVar3;
    pcStack_200 = FUN_000c2e9c;
    puStack_1f8 = &DAT_01061c60;
    uStack_1f0 = _objc_retain(uStack_158);
    uStack_1e8 = _objc_retain(uStack_160);
    _objc_msgSend(lVar2,puStack_148,uVar6,uVar7,0,&puStack_210);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar4 = uStack_130;
    _objc_msgSend(uStack_130,puStack_150,uVar8);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    uStack_10c = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_108[uStack_10c] + (int)-(uRam000000000117b580 ^ 0x6ddd4207),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_140,&PTR____CFConstantStringClassReference_01163250,0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,&PTR____CFConstantStringClassReference_01163110);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar6 = uStack_158;
    uVar5 = uStack_160;
    puStack_240 = PTR___NSConcreteStackBlock_01060660;
    uStack_238 = uVar3;
    pcStack_230 = FUN_000c34e0;
    puStack_228 = &DAT_01061c60;
    uStack_220 = uStack_158;
    uStack_218 = uStack_160;
    _objc_retain(uStack_160);
    _objc_retain(uVar6);
    _objc_msgSend(lVar2,puStack_148,uVar8,uVar9,0,&puStack_240);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puStack_150,uVar3);
    _objc_release(uVar3);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_msgSend(uVar4,PTR_s_setSourceView__0114b8b8,uStack_168);
    _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_rootViewController_0114b968);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_presentFromViewController_animat_0114b8c0,uVar7,1,0);
    _objc_release(uVar7);
    _objc_release(uVar3);
    _objc_release(uStack_218);
    _objc_release(uStack_220);
    _objc_release(uStack_1e8);
    _objc_release(uStack_1f0);
    _objc_release(ppuStack_178[4]);
    _objc_release(uStack_190);
    _objc_release(uVar5);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uStack_128);
    _objc_release(uStack_170);
  }
  CallSupervisor(0xfa2c);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


