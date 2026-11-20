/* Decompiled from supplied 5.2.2 arm package. VA 0x101144. showExtPlayerSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showExtPlayerSheet_withSender_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined **ppuVar7;
  ID IVar8;
  ID IVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 auStack_1d0 [6];
  undefined8 auStack_1a0 [6];
  undefined *puStack_170;
  undefined8 uStack_168;
  code *pcStack_160;
  undefined *puStack_158;
  undefined8 uStack_150;
  ID IStack_148;
  undefined *puStack_140;
  undefined8 *puStack_138;
  undefined **ppuStack_130;
  ID IStack_128;
  undefined *puStack_120;
  undefined *puStack_118;
  undefined8 *puStack_110;
  ID IStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **ppuStack_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_01189fe8;
  local_84 = (uint)(DAT_0122715c == 0);
  local_98 = &PTR_LAB_0118a008;
  local_90 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118a028;
  ppuStack_a8 = &PTR_LAB_011882f0;
  local_c8 = &PTR_LAB_0118a048;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118a068;
  ppuStack_d8 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_011882f0;
  DAT_0122715c = 1;
  puStack_110 = auStack_1a0;
  puStack_138 = auStack_1d0;
  _objc_retain(param_3);
  puVar1 = PTR_s_activeVideo_0114c788;
  IStack_128 = param_4;
  _objc_retain(param_4);
  _objc_msgSend(param_3,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,PTR_s_videoData_0114cfc0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,PTR_s_playbackData_0114cfc8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,PTR_s_video_0114cfd0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,PTR_s_streamingData_0114cfd8);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,PTR_s_HLSMasterPlaylistURL_0114cfe0);
  uStack_f8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  uStack_9c = (uint)(DAT_01227090 == 0);
  ppuStack_130 = &puStack_170;
  if (DAT_01227090 == 0) {
    DAT_01227090 = _objc_getClass(local_98[uStack_9c] + (int)-(DAT_0118a018 ^ 0x57d70b3),
                                  s_YTDefaultSheetController_011869b0);
  }
  uVar10 = _objc_retainAutorelease();
  _objc_msgSend(uVar10,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
  uStack_100 = _objc_retainAutoreleasedReturnValue();
  uStack_b4 = (uint)(DAT_012270a0 == 0);
  if (DAT_012270a0 == 0) {
    DAT_012270a0 = _objc_getClass(local_b0[uStack_b4] + (int)-(uRam000000000118a038 ^ 0x9931b94b),
                                  s_YTActionSheetAction_01186970);
  }
  lVar5 = DAT_012270a0;
  _objc_retainAutorelease(DAT_012270a0);
  puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_118 = PTR_s_localizedStringForKey_value_tabl_0114b278;
  _objc_msgSend(uVar11,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01186a70,0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                &PTR____CFConstantStringClassReference_01186b30);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  uVar10 = DAT_00c4c228;
  puStack_170 = PTR___NSConcreteStackBlock_01060660;
  uStack_168 = DAT_00c4c228;
  pcStack_160 = FUN_00101fac;
  puStack_158 = &DAT_01061c60;
  uStack_150 = _objc_retain(uStack_f8);
  _objc_retain(param_3);
  puStack_120 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
  IStack_148 = param_3;
  IStack_108 = param_3;
  _objc_msgSend(lVar5,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar12,uVar13,0,&puStack_170);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puStack_140 = PTR_s_addAction__0114b898;
  _objc_msgSend(uStack_100,PTR_s_addAction__0114b898,uVar14);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uStack_cc = (uint)(DAT_012270a0 == 0);
  if (DAT_012270a0 == 0) {
    DAT_012270a0 = _objc_getClass(local_c8[uStack_cc] + (int)-(uRam000000000118a058 ^ 0xf66d71ee),
                                  s_YTActionSheetAction_01186970);
  }
  lVar5 = DAT_012270a0;
  _objc_retainAutorelease(DAT_012270a0);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_118,&PTR____CFConstantStringClassReference_01186af0,0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_imageNamed_inBundle_compatibleWi_0114b5c8;
  _objc_msgSend(puVar3,PTR_s_imageNamed_inBundle_compatibleWi_0114b5c8,
                &PTR____CFConstantStringClassReference_01186ab0,uVar13,0);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puVar6 = puStack_110;
  *puStack_110 = PTR___NSConcreteStackBlock_01060660;
  puVar6[1] = uVar10;
  puVar6[2] = FUN_001020f0;
  puVar6[3] = &DAT_01061c60;
  uVar15 = _objc_retain(uStack_f8);
  puVar6[4] = uVar15;
  uVar15 = _objc_retain(IStack_108);
  puVar6[5] = uVar15;
  _objc_msgSend(lVar5,puStack_120,uVar12,uVar14,0,puVar6);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_140;
  _objc_msgSend(uStack_100,puStack_140,uVar15);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uStack_e4 = (uint)(DAT_012270a0 == 0);
  if (DAT_012270a0 == 0) {
    DAT_012270a0 = _objc_getClass(local_e0[uStack_e4] + (int)-(uRam000000000118a078 ^ 0xfff343a1),
                                  s_YTActionSheetAction_01186970);
  }
  lVar5 = DAT_012270a0;
  _objc_retainAutorelease(DAT_012270a0);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puStack_118,&PTR____CFConstantStringClassReference_01186a30,0,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar2,&PTR____CFConstantStringClassReference_011869f0,uVar14,0);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar6 = puStack_138;
  *puStack_138 = PTR___NSConcreteStackBlock_01060660;
  puVar6[1] = uVar10;
  puVar6[2] = FUN_001028cc;
  puVar6[3] = &DAT_01061c60;
  uVar11 = uStack_f8;
  IVar9 = IStack_108;
  puVar6[4] = uStack_f8;
  puVar6[5] = IVar9;
  _objc_retain(IVar9);
  _objc_retain(uVar11);
  _objc_msgSend(lVar5,puStack_120,uVar13,uVar15,0,puVar6);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  uVar10 = uStack_100;
  _objc_msgSend(uStack_100,puVar3,uVar16);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  IVar8 = IStack_128;
  _objc_msgSend(uVar10,PTR_s_setSourceView__0114b8b8,IStack_128);
  _objc_release(IVar8);
  _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,PTR_s_rootViewController_0114b968);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,PTR_s_presentFromViewController_animat_0114b8c0,uVar13,1,0);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(puVar6[5]);
  _objc_release(puVar6[4]);
  puVar6 = puStack_110;
  _objc_release(puStack_110[5]);
  _objc_release(puVar6[4]);
  ppuVar7 = ppuStack_130;
  _objc_release(ppuStack_130[5]);
  _objc_release(ppuVar7[4]);
  _objc_release(IVar9);
  _objc_release(uVar11);
  _objc_release(uVar10);
  CallSupervisor(0x64f8);
  return;
}


