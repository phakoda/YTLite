/* Decompiled from supplied 5.2.2 arm package. VA 0xfd8cc. showImagesSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showImagesSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined *puStack_210;
  undefined8 uStack_208;
  code *pcStack_200;
  undefined *puStack_1f8;
  undefined8 uStack_1f0;
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
  undefined8 uStack_178;
  undefined8 uStack_170;
  long lStack_168;
  ID IStack_160;
  ID IStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined8 uStack_130;
  undefined **local_128;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  uint uStack_bc;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_01189c48;
  local_84 = (uint)(DAT_01227134 == 0);
  local_98 = &PTR_LAB_01189c68;
  local_a8 = &PTR_LAB_01189c80;
  local_b8 = &PTR_LAB_01189c98;
  local_c8 = &PTR_LAB_01189cb0;
  local_e0 = &PTR_LAB_01189cd0;
  local_90 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_01189cf0;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_01189d10;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_011882f0;
  DAT_01227134 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar11 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_9c = FUN_00110a0c(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar10 = local_98[uStack_9c] + (int)-(DAT_01189c78 ^ 0xd134e1c8);
  if (uStack_9c == 0) {
    uStack_ac = FUN_001108c4(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar10 = local_a8[uStack_ac] + (int)-(uRam0000000001189c90 ^ 0xb309c40b);
    puVar11 = puVar2;
    if (uStack_ac == 0) goto LAB_000fe898;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  uStack_bc = (uint)(lVar3 == 0);
  puVar10 = local_b8[uStack_bc] + (int)-(uRam0000000001189ca8 ^ 0x82fcd0b3);
  if (lVar3 != 0) {
    lStack_168 = lVar3;
    IStack_158 = param_3;
    _objc_msgSend(lVar3,PTR_s_playerData_0114c7d0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_videoDetails_0114c7d8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_thumbnail_0114cf88);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_thumbnailsArray_0114cf90);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_170 = uVar7;
    _objc_msgSend(uVar7,PTR_s_lastObject_0114b250);
    uStack_178 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
    _objc_msgSend(uStack_178,PTR_s_URL_0114c578);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_URLWithString__0114b3d0,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uStack_cc = (uint)(DAT_01227090 == 0);
    if (DAT_01227090 == 0) {
      DAT_01227090 = _objc_getClass(local_c8[uStack_cc] + (int)-(DAT_01189cc0 ^ 0x3b50285b),
                                    s_YTDefaultSheetController_01186150);
    }
    uVar4 = _objc_retainAutorelease();
    _objc_msgSend(uVar4,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_e4 = (uint)(DAT_012270a0 == 0);
    IStack_160 = param_4;
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_e0[uStack_e4] + (int)-(uRam0000000001189ce0 ^ 0x9a816514),
                                    s_YTActionSheetAction_01186110);
    }
    lVar3 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    puStack_138 = PTR_s_ytl_defaultBundle_0114ae50;
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_140 = PTR_s_localizedStringForKey_value_tabl_0114b278;
    _objc_msgSend(uVar6,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_011862d0,0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_148 = PTR_s_imageWithName__0114c5b0;
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_01186250);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar4 = DAT_00c4c228;
    puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1a8 = DAT_00c4c228;
    pcStack_1a0 = FUN_000fe8e4;
    puStack_198 = &DAT_010618c0;
    _objc_retain(uVar5);
    puStack_150 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
    uStack_190 = uVar5;
    _objc_msgSend(lVar3,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar7,uVar8,0,&puStack_1b0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_addAction__0114b898;
    _objc_msgSend(uStack_130,PTR_s_addAction__0114b898,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    uStack_fc = (uint)(DAT_012270a0 == 0);
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_f8[uStack_fc] + (int)-(uRam0000000001189d00 ^ 0xe2cab57c),
                                    s_YTActionSheetAction_01186110);
    }
    lVar3 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puStack_140,&PTR____CFConstantStringClassReference_01186210,0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_148,&PTR____CFConstantStringClassReference_01186290)
    ;
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puStack_1e0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1d8 = uVar4;
    pcStack_1d0 = FUN_000fe92c;
    puStack_1c8 = &DAT_010618c0;
    _objc_retain(uVar5);
    uStack_1c0 = uVar5;
    _objc_msgSend(lVar3,puStack_150,uVar7,uVar8,0,&puStack_1e0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_130,puVar1,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    uStack_114 = (uint)(DAT_012270a0 == 0);
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_110[uStack_114] + (int)-(DAT_01189d20 ^ 0x10e043e4),
                                    s_YTActionSheetAction_01186110);
    }
    lVar3 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puStack_140,&PTR____CFConstantStringClassReference_011861d0,0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_148,&PTR____CFConstantStringClassReference_01186190)
    ;
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puStack_210 = PTR___NSConcreteStackBlock_01060660;
    uStack_208 = uVar4;
    pcStack_200 = FUN_000fead4;
    puStack_1f8 = &DAT_010618c0;
    uStack_1f0 = uVar5;
    _objc_retain(uVar5);
    _objc_msgSend(lVar3,puStack_150,uVar7,uVar8,0,&puStack_210);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar4 = uStack_130;
    _objc_msgSend(uStack_130,puVar1,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    param_4 = IStack_160;
    _objc_msgSend(uVar4,PTR_s_setSourceView__0114b8b8,IStack_160);
    _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_rootViewController_0114b968);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_presentFromViewController_animat_0114b8c0,uVar7,1,0);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uStack_1f0);
    _objc_release(uStack_1c0);
    _objc_release(uStack_190);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uStack_178);
    _objc_release(uStack_170);
    _objc_release(lStack_168);
    puVar10 = &stack0xffffffffffffffa8;
    param_3 = IStack_158;
  }
LAB_000fe898:
  _objc_release(puVar10,param_4);
  _objc_release(param_3);
  CallSupervisor(0x9396);
  return;
}


