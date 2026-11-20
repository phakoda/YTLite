/* Decompiled from supplied 5.2.2 arm package. VA 0xfeb1c. showInformationSheet:withSender: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showInformationSheet_withSender_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_350 [64];
  undefined1 auStack_310 [96];
  undefined1 auStack_2b0 [48];
  undefined8 auStack_280 [7];
  ID IStack_248;
  undefined4 uStack_23c;
  undefined8 uStack_238;
  undefined1 *puStack_230;
  long lStack_228;
  undefined8 uStack_220;
  undefined1 *puStack_218;
  ID IStack_210;
  undefined8 uStack_208;
  undefined8 *puStack_200;
  ID IStack_1f8;
  undefined1 *puStack_1f0;
  undefined *puStack_1e8;
  undefined *puStack_1e0;
  undefined *puStack_1d8;
  undefined *puStack_1d0;
  undefined *puStack_1c8;
  undefined8 uStack_1c0;
  undefined **local_1b8;
  undefined **local_1b0;
  undefined **ppuStack_1a8;
  undefined **local_198;
  undefined **local_188;
  undefined **ppuStack_180;
  undefined **local_170;
  undefined **local_168;
  undefined **ppuStack_160;
  undefined **local_150;
  undefined **local_140;
  undefined **ppuStack_138;
  uint uStack_12c;
  undefined **local_128;
  undefined **ppuStack_120;
  uint uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **local_f0;
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
  
  local_80 = &PTR_LAB_01189d38;
  local_84 = (uint)(DAT_01227144 == 0);
  local_98 = &PTR_LAB_01189d58;
  local_a8 = &PTR_LAB_01189d70;
  local_b8 = &PTR_numberOfSectionsInTableView__01189d88;
  local_c8 = &PTR_LAB_01189da0;
  local_e0 = &PTR_LAB_01189dc0;
  local_f8 = &PTR_LAB_01189de0;
  local_90 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_01189e00;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_01189e20;
  ppuStack_120 = &PTR_LAB_011882f0;
  local_140 = &PTR_LAB_01189e40;
  ppuStack_138 = &PTR_LAB_011882f0;
  local_150 = &PTR_LAB_01189e58;
  local_168 = &PTR_LAB_011882f0;
  ppuStack_160 = &PTR_LAB_011882f0;
  local_170 = &PTR_LAB_01189e80;
  local_188 = &PTR_LAB_01189ea0;
  ppuStack_180 = &PTR_LAB_011882f0;
  local_198 = &PTR_LAB_01189eb8;
  local_1b0 = &PTR_LAB_011882f0;
  ppuStack_1a8 = &PTR_LAB_011882f0;
  local_1b8 = &PTR_LAB_011882f0;
  if (DAT_01227144 == 0) {
    s___01186418._0_2_ = _DAT_01186414 ^ 0xf263;
    unique0x0003fe00 = uRam0000000001186416 ^ 0x23a2;
    s_CopyChannelName_01186404[0] = DAT_011863f4 ^ 0xbb;
    s_CopyChannelName_01186404[1] = DAT_011863f5 ^ 0x73;
    s_CopyChannelName_01186404[2] = DAT_011863f6 ^ 0x4c;
    s_CopyChannelName_01186404[3] = DAT_011863f7 ^ 0x1a;
    s_CopyChannelName_01186404[4] = DAT_011863f8 ^ 0x5d;
    s_CopyChannelName_01186404[5] = DAT_011863f9 ^ 0xae;
    s_CopyChannelName_01186404[6] = DAT_011863fa ^ 0x5e;
    s_CopyChannelName_01186404[7] = DAT_011863fb ^ 0xfa;
    s_CopyChannelName_01186404[8] = DAT_011863fc ^ 0xfc;
    s_CopyChannelName_01186404[9] = DAT_011863fd ^ 0xc2;
    s_CopyChannelName_01186404[10] = DAT_011863fe ^ 0x1e;
    s_CopyChannelName_01186404[0xb] = DAT_011863ff ^ 0x9a;
    s_CopyChannelName_01186404[0xc] = DAT_01186400 ^ 0xdf;
    s_CopyChannelName_01186404[0xd] = DAT_01186401 ^ 0xbc;
    s_CopyChannelName_01186404[0xe] = DAT_01186402 ^ 0x81;
    s_CopyChannelName_01186404[0xf] = DAT_01186403 ^ 0xe0;
    s_YTDefaultSheetController_011863a0[0] = DAT_01186380 ^ 0x43;
    s_YTDefaultSheetController_011863a0[1] = DAT_01186381 ^ 0x67;
    s_YTDefaultSheetController_011863a0[2] = DAT_01186382 ^ 0x8e;
    s_YTDefaultSheetController_011863a0[3] = DAT_01186383 ^ 0xa4;
    s_YTDefaultSheetController_011863a0[4] = DAT_01186384 ^ 0x13;
    s_YTDefaultSheetController_011863a0[5] = DAT_01186385 ^ 0xcb;
    s_YTDefaultSheetController_011863a0[6] = DAT_01186386 ^ 0x44;
    s_YTDefaultSheetController_011863a0[7] = DAT_01186387 ^ 0xe3;
    s_YTDefaultSheetController_011863a0[8] = DAT_01186388 ^ 0xe6;
    s_YTDefaultSheetController_011863a0[9] = DAT_01186389 ^ 0x12;
    s_YTDefaultSheetController_011863a0[10] = DAT_0118638a ^ 0xb;
    s_YTDefaultSheetController_011863a0[0xb] = DAT_0118638b ^ 0x2f;
    s_YTDefaultSheetController_011863a0[0xc] = DAT_0118638c ^ 0x55;
    s_YTDefaultSheetController_011863a0[0xd] = DAT_0118638d ^ 0xb2;
    s_YTDefaultSheetController_011863a0[0xe] = DAT_0118638e ^ 0xf9;
    s_YTDefaultSheetController_011863a0[0xf] = DAT_0118638f ^ 0xcf;
    s_YTDefaultSheetController_011863a0[0x10] = DAT_01186390 ^ 0xd5;
    s_YTDefaultSheetController_011863a0[0x11] = DAT_01186391 ^ 0xde;
    s_YTDefaultSheetController_011863a0[0x12] = DAT_01186392 ^ 0x20;
    s_YTDefaultSheetController_011863a0[0x13] = DAT_01186393 ^ 0x4e;
    s_YTDefaultSheetController_011863a0[0x14] = DAT_01186394 ^ 0xfe;
    s_YTDefaultSheetController_011863a0[0x15] = DAT_01186395 ^ 0x3a;
    s_YTDefaultSheetController_011863a0[0x16] = DAT_01186396 ^ 0x2c;
    s_YTDefaultSheetController_011863a0[0x17] = DAT_01186397 ^ 0xfa;
    s_YTDefaultSheetController_011863a0[0x18] = DAT_01186398 ^ 0xbe;
    s_CopyTranscript_01186353[0] = DAT_01186344 ^ 0x70;
    s_CopyTranscript_01186353[1] = DAT_01186345 ^ 0x18;
    s_CopyTranscript_01186353[2] = DAT_01186346 ^ 0xe3;
    s_CopyTranscript_01186353[3] = DAT_01186347 ^ 0xf7;
    s_CopyTranscript_01186353[4] = DAT_01186348 ^ 2;
    s_CopyTranscript_01186353[5] = DAT_01186349 ^ 0xef;
    s_CopyTranscript_01186353[6] = DAT_0118634a ^ 0xd8;
    s_CopyTranscript_01186353[7] = DAT_0118634b ^ 0x23;
    s_CopyTranscript_01186353[8] = DAT_0118634c ^ 0xbd;
    s_CopyTranscript_01186353[9] = DAT_0118634d ^ 0x20;
    s_CopyTranscript_01186353[10] = DAT_0118634e ^ 0xbd;
    s_CopyTranscript_01186353[0xb] = DAT_0118634f ^ 0xe9;
    s_CopyTranscript_01186353[0xc] = DAT_01186350 ^ 0xa8;
    s_CopyTranscript_01186353[0xd] = DAT_01186351 ^ 0x3a;
    s_CopyTranscript_01186353[0xe] = DAT_01186352 ^ 0x43;
    s_YTActionSheetAction_011863e0[0] = DAT_011863c0 ^ 0x1d;
    s_YTActionSheetAction_011863e0[1] = DAT_011863c1 ^ 0xcd;
    s_YTActionSheetAction_011863e0[2] = DAT_011863c2 ^ 0xf;
    s_YTActionSheetAction_011863e0[3] = DAT_011863c3 ^ 0xbd;
    s_YTActionSheetAction_011863e0[4] = DAT_011863c4 ^ 0xe8;
    s_YTActionSheetAction_011863e0[5] = DAT_011863c5 ^ 0x5c;
    s_YTActionSheetAction_011863e0[6] = DAT_011863c6 ^ 0x12;
    s_YTActionSheetAction_011863e0[7] = DAT_011863c7 ^ 0x8c;
    s_YTActionSheetAction_011863e0[8] = DAT_011863c8 ^ 0x46;
    s_YTActionSheetAction_011863e0[9] = DAT_011863c9 ^ 0x61;
    s_YTActionSheetAction_011863e0[10] = DAT_011863ca ^ 0x85;
    s_YTActionSheetAction_011863e0[0xb] = DAT_011863cb ^ 0x21;
    s_YTActionSheetAction_011863e0[0xc] = DAT_011863cc ^ 0xcc;
    s_YTActionSheetAction_011863e0[0xd] = DAT_011863cd ^ 0x44;
    s_YTActionSheetAction_011863e0[0xe] = DAT_011863ce ^ 0x22;
    s_YTActionSheetAction_011863e0[0xf] = DAT_011863cf ^ 0x28;
    s_YTActionSheetAction_011863e0[0x10] = DAT_011863d0 ^ 0x9b;
    s_YTActionSheetAction_011863e0[0x11] = DAT_011863d1 ^ 0x66;
    param_2 = 0x7d;
    s_YTActionSheetAction_011863e0[0x12] = DAT_011863d2 ^ 0x7d;
    s_YTActionSheetAction_011863e0[0x13] = DAT_011863d3 ^ 0x6f;
    s_copy_0118637b[0] = DAT_01186376 ^ 0x72;
    s_copy_0118637b[1] = DAT_01186377 ^ 2;
    s_copy_0118637b[2] = DAT_01186378 ^ 0xfa;
    s_copy_0118637b[3] = DAT_01186379 ^ 8;
    s_copy_0118637b[4] = DAT_0118637a ^ 199;
    s_CopyTitle_0118636c[0] = DAT_01186362 ^ 0xe5;
    s_CopyTitle_0118636c[1] = DAT_01186363 ^ 0x2c;
    s_CopyTitle_0118636c[2] = DAT_01186364 ^ 0x31;
    s_CopyTitle_0118636c[3] = DAT_01186365 ^ 0x77;
    s_CopyTitle_0118636c[4] = DAT_01186366 ^ 0x6a;
    s_CopyTitle_0118636c[5] = DAT_01186367 ^ 0xf9;
    s_CopyTitle_0118636c[6] = DAT_01186368 ^ 0xdc;
    s_CopyTitle_0118636c[7] = DAT_01186369 ^ 200;
    s_CopyTitle_0118636c[8] = DAT_0118636a ^ 0xce;
    s_CopyTitle_0118636c[9] = DAT_0118636b ^ 0x23;
    s_CopyDescription_01186334[0] = DAT_01186324 ^ 0xdb;
    s_CopyDescription_01186334[1] = DAT_01186325 ^ 0x10;
    s_CopyDescription_01186334[2] = DAT_01186326 ^ 0x9a;
    s_CopyDescription_01186334[3] = DAT_01186327 ^ 0x2b;
    s_CopyDescription_01186334[4] = DAT_01186328 ^ 0x5e;
    s_CopyDescription_01186334[5] = DAT_01186329 ^ 2;
    s_CopyDescription_01186334[6] = DAT_0118632a ^ 0x89;
    s_CopyDescription_01186334[7] = DAT_0118632b ^ 0x19;
    s_CopyDescription_01186334[8] = DAT_0118632c ^ 0x34;
    s_CopyDescription_01186334[9] = DAT_0118632d ^ 0x39;
    s_CopyDescription_01186334[10] = DAT_0118632e ^ 0x69;
    s_CopyDescription_01186334[0xb] = DAT_0118632f ^ 0x96;
    s_CopyDescription_01186334[0xc] = DAT_01186330 ^ 0x47;
    s_CopyDescription_01186334[0xd] = DAT_01186331 ^ 0xce;
    s_CopyDescription_01186334[0xe] = DAT_01186332 ^ 0xcf;
    s_CopyDescription_01186334[0xf] = DAT_01186333 ^ 0x30;
    s_CopyTimestampedLink_01186310[0] = DAT_011862f0 ^ 0x12;
    s_CopyTimestampedLink_01186310[1] = DAT_011862f1 ^ 0x3b;
    s_CopyTimestampedLink_01186310[2] = DAT_011862f2 ^ 0x85;
    s_CopyTimestampedLink_01186310[3] = DAT_011862f3 ^ 0x6b;
    s_CopyTimestampedLink_01186310[4] = DAT_011862f4 ^ 0x7d;
    s_CopyTimestampedLink_01186310[5] = DAT_011862f5 ^ 0x86;
    s_CopyTimestampedLink_01186310[6] = DAT_011862f6 ^ 0x57;
    s_CopyTimestampedLink_01186310[7] = DAT_011862f7 ^ 0xa8;
    s_CopyTimestampedLink_01186310[8] = DAT_011862f8 ^ 0xe9;
    s_CopyTimestampedLink_01186310[9] = DAT_011862f9 ^ 0x32;
    s_CopyTimestampedLink_01186310[10] = DAT_011862fa ^ 0x7c;
    s_CopyTimestampedLink_01186310[0xb] = DAT_011862fb ^ 0x60;
    s_CopyTimestampedLink_01186310[0xc] = DAT_011862fc ^ 0xce;
    s_CopyTimestampedLink_01186310[0xd] = DAT_011862fd ^ 0xf2;
    s_CopyTimestampedLink_01186310[0xe] = DAT_011862fe ^ 2;
    s_CopyTimestampedLink_01186310[0xf] = DAT_011862ff ^ 1;
    s_CopyTimestampedLink_01186310[0x10] = DAT_01186300 ^ 0x72;
    s_CopyTimestampedLink_01186310[0x11] = DAT_01186301 ^ 0x77;
    s_CopyTimestampedLink_01186310[0x12] = DAT_01186302 ^ 0xd9;
    s_CopyTimestampedLink_01186310[0x13] = DAT_01186303 ^ 0xba;
  }
  DAT_01227144 = 1;
  puStack_1f0 = auStack_350;
  _objc_retain(param_3,param_2);
  _objc_retain(param_4);
  puVar12 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_9c = FUN_00111464(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar11 = local_98[uStack_9c] + (int)-(DAT_01189d68 ^ 0x2115d05c);
  if (uStack_9c == 0) {
    uStack_ac = FUN_001112bc(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar11 = local_a8[uStack_ac] + (int)-(uRam0000000001189d80 ^ 0xa2b75d0b);
    puVar12 = puVar2;
    if (uStack_ac == 0) goto LAB_00100110;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_playerData_0114c7d0;
  uStack_bc = (uint)(lVar5 == 0);
  puVar11 = local_b8[uStack_bc] + (int)-(uRam0000000001189d98 ^ 0x98b32903);
  if (lVar5 != 0) {
    IStack_248 = param_1;
    puStack_230 = auStack_310;
    puStack_218 = auStack_2b0;
    IStack_210 = param_4;
    puStack_200 = auStack_280;
    _objc_msgSend(lVar5,PTR_s_playerData_0114c7d0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar11 = PTR_s_videoDetails_0114c7d8;
    _objc_msgSend(uVar6,PTR_s_videoDetails_0114c7d8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_title_0114c7f0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_author_0114c7e8);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_shortDescription_0114cf98);
    uStack_220 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    lStack_228 = lVar5;
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_23c = FUN_00111074(uVar7,PTR_s_hasShortDescription_0114cfa0);
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar11 = PTR_s_length_0114b438;
    uVar10 = _objc_msgSend(uVar9,PTR_s_length_0114b438);
    uStack_cc = (uint)(0x1e < uVar10);
    uStack_208 = uVar9;
    IStack_1f8 = param_3;
    if (0x1e < uVar10) {
      _objc_msgSend(local_c8[uStack_cc] + (int)-(DAT_01189db0 ^ 0x265139d1),uVar9,
                    PTR_s_substringToIndex__0114ce80,0x1e);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_stringByAppendingString__0114b380,
                    &PTR____CFConstantStringClassReference_011865c0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      _objc_release(uVar6);
      uStack_208 = uVar7;
    }
    uVar10 = _objc_msgSend(uVar8,puVar11);
    uStack_e4 = (uint)(200 < uVar10);
    if (uVar10 < 0xc9) {
      bVar4 = DAT_01227090 == 0;
      uStack_fc = (uint)bVar4;
      puVar11 = local_f8[uStack_fc] + (int)-(uRam0000000001189df0 ^ 0x7354d7af);
      uStack_238 = uVar8;
    }
    else {
      _objc_msgSend(local_e0[uStack_e4] + (int)-(DAT_01189dd0 ^ 0x20d05504),uVar8,
                    PTR_s_substringToIndex__0114ce80,200);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_stringByAppendingString__0114b380,
                    &PTR____CFConstantStringClassReference_011865c0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar6);
      bVar4 = DAT_01227090 == 0;
      uStack_fc = (uint)bVar4;
      puVar11 = local_f8[uStack_fc] + (int)-(uRam0000000001189df0 ^ 0x7354d7af);
      uStack_238 = uVar7;
    }
    if (bVar4) {
      DAT_01227090 = _objc_getClass(puVar11,s_YTDefaultSheetController_011863a0);
    }
    uVar6 = _objc_retainAutorelease();
    _objc_msgSend(uVar6,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
    uStack_1c0 = _objc_retainAutoreleasedReturnValue();
    uStack_114 = (uint)(DAT_012270a0 == 0);
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_110[uStack_114] + (int)-(DAT_01189e10 ^ 0x9c849656),
                                    s_YTActionSheetAction_011863e0);
    }
    lVar5 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    puStack_1c8 = PTR_s_ytl_defaultBundle_0114ae50;
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_1d0 = PTR_s_localizedStringForKey_value_tabl_0114b278;
    _objc_msgSend(uVar7,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01186580,0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puStack_1d8 = PTR_s_imageWithName__0114c5b0;
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_01186540);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_200;
    uVar6 = uStack_208;
    *puStack_200 = PTR___NSConcreteStackBlock_01060660;
    puVar3[1] = DAT_00c4c228;
    puVar3[2] = FUN_0010015c;
    puVar3[3] = &DAT_010618c0;
    uVar6 = _objc_retain(uVar6);
    puVar3[4] = uVar6;
    puStack_1e0 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
    _objc_msgSend(lVar5,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar8,uVar9,0,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_1e8 = PTR_s_addAction__0114b898;
    _objc_msgSend(uStack_1c0,PTR_s_addAction__0114b898,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    uStack_12c = (uint)(DAT_012270a0 == 0);
                    /* WARNING: Could not recover jumptable at 0x000ffa30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_128[uStack_12c] + (int)-(DAT_01189e30 ^ 0x4cb0c749)))();
    return;
  }
  uStack_bc = 1;
LAB_00100110:
  _objc_release(puVar11,param_4);
  _objc_release(param_3);
  CallSupervisor(0x9fbf);
  return;
}


