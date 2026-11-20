// Decompiled implementation evidence for DownloadMenuHelper. Not compilable source.

// -[DownloadMenuHelper showVideoSheet:withSender:], 0xfb8a4
/* Decompiled from supplied 5.2.2 arm package. VA 0xfb8a4. showVideoSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showVideoSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_5d0 [128];
  undefined1 auStack_550 [64];
  undefined1 auStack_510 [32];
  undefined1 auStack_4f0 [160];
  undefined1 auStack_450 [128];
  undefined8 auStack_3d0 [8];
  long lStack_390;
  undefined1 *puStack_388;
  undefined1 *puStack_380;
  undefined *puStack_378;
  undefined8 uStack_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  undefined1 *puStack_358;
  undefined1 *puStack_350;
  ID IStack_348;
  undefined8 uStack_340;
  undefined1 *puStack_338;
  undefined *puStack_330;
  undefined *puStack_328;
  undefined *puStack_320;
  undefined *puStack_318;
  undefined *puStack_310;
  long lStack_300;
  uint uStack_2f4;
  undefined8 *puStack_2f0;
  undefined8 uStack_2e8;
  undefined8 uStack_2e0;
  undefined8 uStack_2d8;
  undefined8 uStack_2d0;
  ID IStack_2c8;
  long lStack_2c0;
  undefined *puStack_2b8;
  undefined *puStack_2b0;
  undefined *puStack_2a8;
  undefined *puStack_2a0;
  undefined *puStack_298;
  undefined *puStack_290;
  undefined *puStack_288;
  undefined *puStack_280;
  undefined *puStack_278;
  undefined *puStack_270;
  undefined *puStack_268;
  undefined *puStack_260;
  undefined *puStack_258;
  undefined *puStack_250;
  undefined *puStack_248;
  undefined8 uStack_240;
  undefined8 uStack_220;
  ID local_218;
  undefined *puStack_210;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **ppuStack_1d0;
  undefined **local_1c0;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **ppuStack_198;
  uint uStack_18c;
  undefined **local_188;
  undefined **local_178;
  undefined **local_168;
  undefined **local_160;
  undefined **local_150;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_01189960;
  local_8c = (uint)(DAT_01227120 == 0);
  local_a0 = &PTR_LAB_01189980;
  local_b0 = &PTR_LAB_01189998;
  local_c0 = &PTR_LAB_011899b0;
  local_d0 = &PTR_LAB_011899c8;
  local_e8 = &PTR_LAB_011899e8;
  local_98 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_011882f0;
  local_100 = &PTR_LAB_01189a08;
  ppuStack_f8 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_01189a30;
  local_130 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_01189a50;
  local_148 = &PTR_LAB_011882f0;
  local_150 = &PTR_LAB_01189a70;
  local_160 = &PTR_LAB_011882f0;
  local_168 = &PTR_LAB_01189a90;
  local_178 = &PTR_LAB_01189aa8;
  local_188 = &PTR_LAB_01189ac0;
  local_1a0 = &PTR_LAB_01189ae0;
  ppuStack_198 = &PTR_LAB_011882f0;
  local_1b8 = &PTR_LAB_011882f0;
  ppuStack_1b0 = &PTR_LAB_011882f0;
  local_1c0 = &PTR_LAB_01189b08;
  local_1d8 = &PTR_LAB_01189b28;
  ppuStack_1d0 = &PTR_LAB_011882f0;
  local_1e8 = &PTR_LAB_01189b40;
  local_1f8 = &PTR_LAB_011882f0;
  DAT_01227120 = 1;
  puStack_388 = auStack_450;
  puStack_350 = auStack_4f0;
  puStack_358 = auStack_510;
  puStack_338 = auStack_550;
  puStack_380 = auStack_5d0;
  local_218 = param_1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar12 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_a4 = FUN_0010ff38(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar11 = local_a0[uStack_a4] + (int)-(DAT_01189990 ^ 0x8f14101e);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_001103d4(param_3,puVar1,@selector(contentPlayerResponse));
    puVar11 = local_b0[uStack_b4] + (int)-(uRam00000000011899a8 ^ 0xe3b5511b);
    puVar12 = puVar2;
    if (uStack_b4 == 0) goto LAB_000fcdf8;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lStack_390 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = (uint)(lStack_390 == 0);
  puVar11 = local_c0[uStack_c4] + (int)-(uRam00000000011899c0 ^ 0xde087b55);
  if (lStack_390 != 0) {
    IStack_348 = param_4;
    puStack_2f0 = auStack_3d0;
    _objc_msgSend(lStack_390,@selector(videoID));
    uStack_2d0 = _objc_retainAutoreleasedReturnValue();
    puVar11 = @selector(playerData);
    _objc_msgSend(lStack_390,@selector(playerData));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(videoDetails);
    _objc_msgSend(uVar5,@selector(videoDetails));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(author));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lStack_390,puVar11);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(title));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar11 = @selector(length);
    uVar9 = _objc_msgSend(uVar7,@selector(length));
    uStack_d4 = (uint)(0x1e < uVar9);
    if (0x1e < uVar9) {
      _objc_msgSend(local_d0[uStack_d4] + (int)-(uRam00000000011899d8 ^ 0xa0355e94),uVar7,
                    @selector(substringToIndex:),0x1e);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_01185ef0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar7);
      _objc_release(uVar5);
      uVar7 = uVar6;
    }
    uStack_2d8 = uVar7;
    uVar9 = _objc_msgSend(uVar8,puVar11);
    puVar3 = puStack_2f0;
    uStack_ec = (uint)(200 < uVar9);
    uStack_2e0 = uVar8;
    if (200 < uVar9) {
      _objc_msgSend(local_e8[uStack_ec] + (int)-(uRam00000000011899f8 ^ 0x9524811c),uVar8,
                    @selector(substringToIndex:),200);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_01185ef0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar7);
      uStack_2e0 = uVar5;
    }
    IVar4 = local_218;
    _objc_msgSend(local_218,@selector(getVideoFormatsArray:isShorts:),param_3,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(getAudioFormatsArray:),param_3);
    uStack_2e8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(getBestAudioFormat:playerVC:),uStack_2e8,param_3);
    uStack_220 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,@selector(activeVideo));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(selectedAudioFormat));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(audioTrack));
    lVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_2f4 = (uint)(lVar10 != 0);
    _objc_release();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uStack_240 = _objc_retainAutoreleasedReturnValue();
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[3] = 0;
    puVar3[2] = 0;
    puVar3[5] = 0;
    puVar3[4] = 0;
    puVar3[7] = 0;
    puVar3[6] = 0;
    uVar5 = _objc_retain(uVar7);
    puStack_378 = @selector(countByEnumeratingWithState:objects:count:);
    uStack_340 = uVar7;
    lStack_2c0 = _objc_msgSend(uVar5,@selector(countByEnumeratingWithState:objects:count:),puVar3,
                               puStack_388,0x10);
    uStack_104 = (uint)(lStack_2c0 == 0);
    IStack_2c8 = param_3;
    if (lStack_2c0 == 0) {
      _objc_release(local_100[uStack_104] + (int)-(uRam0000000001189a18 ^ 0x6a0a20ad),uStack_340);
      uStack_18c = (uint)(DAT_01227090 == 0);
                    /* WARNING: Could not recover jumptable at 0x000fcb58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_188[uStack_18c] + (int)-(uRam0000000001189ad0 ^ 0x113df662)))();
      return;
    }
    lStack_300 = *(long *)puVar3[2];
    uStack_360 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
    uStack_368 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
    uStack_370 = *(undefined8 *)PTR__NSBaselineOffsetAttributeName_01060350;
    puStack_250 = @selector(hasPrefix:);
    puStack_248 = @selector(mimeType);
    puStack_260 = @selector(qualityLabel);
    puStack_258 = @selector(detailForMimeType:);
    puStack_270 = @selector(stringFromByteCount:countStyle:);
    puStack_268 = @selector(contentLength);
    puStack_280 = @selector(imageWithName:);
    puStack_278 = @selector(stringWithFormat:);
    puStack_210 = @selector(button);
    puStack_290 = @selector(currentAttributedTitle);
    puStack_288 = @selector(actionWithTitle:currentValue:iconImage:accessibilityIdentifier:handler:);
    puStack_2a0 = @selector(string);
    puStack_298 = @selector(mutableCopy);
    puStack_318 = @selector(systemFontOfSize:);
    puStack_310 = @selector(redColor);
    puStack_328 = @selector(dictionaryWithObjects:forKeys:count:);
    puStack_320 = @selector(numberWithInt:);
    puStack_330 = @selector(setAttributes:range:);
    puStack_2b0 = @selector(setAttributedTitle:forState:);
    puStack_2a8 = @selector(rangeOfString:options:);
    uStack_124 = (uint)(*(long *)puVar3[2] == lStack_300);
    lStack_2c0 = lStack_2c0 + -1;
    puStack_2b8 = @selector(addObject:);
                    /* WARNING: Could not recover jumptable at 0x000fc538. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_120[uStack_124] + (int)-(uRam0000000001189a40 ^ 0x6869cee7)))();
    return;
  }
  uStack_c4 = 1;
LAB_000fcdf8:
  _objc_release(puVar11,param_4);
  _objc_release(param_3);
  CallSupervisor(0x4c00);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[DownloadMenuHelper showImagesSheet:withSender:], 0xfd8cc
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
  puVar11 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_9c = FUN_00110a0c(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar10 = local_98[uStack_9c] + (int)-(DAT_01189c78 ^ 0xd134e1c8);
  if (uStack_9c == 0) {
    uStack_ac = FUN_001108c4(param_3,puVar1,@selector(contentPlayerResponse));
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
    _objc_msgSend(lVar3,@selector(playerData));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(videoDetails));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(thumbnail));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(thumbnailsArray));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_170 = uVar7;
    _objc_msgSend(uVar7,@selector(lastObject));
    uStack_178 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
    _objc_msgSend(uStack_178,@selector(URL));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(URLWithString:),uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uStack_cc = (uint)(DAT_01227090 == 0);
    if (DAT_01227090 == 0) {
      DAT_01227090 = _objc_getClass(local_c8[uStack_cc] + (int)-(DAT_01189cc0 ^ 0x3b50285b),
                                    s_YTDefaultSheetController_01186150);
    }
    uVar4 = _objc_retainAutorelease();
    _objc_msgSend(uVar4,@selector(sheetControllerWithParentResponder:),0);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_e4 = (uint)(DAT_012270a0 == 0);
    IStack_160 = param_4;
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_e0[uStack_e4] + (int)-(uRam0000000001189ce0 ^ 0x9a816514),
                                    s_YTActionSheetAction_01186110);
    }
    lVar3 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    puStack_138 = @selector(ytl_defaultBundle);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_140 = @selector(localizedStringForKey:value:table:);
    _objc_msgSend(uVar6,@selector(localizedStringForKey:value:table:),
                  @"DownloadThumbnail",0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_148 = @selector(imageWithName:);
    _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(imageWithName:),
                  @"image");
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar4 = DAT_00c4c228;
    puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1a8 = DAT_00c4c228;
    pcStack_1a0 = FUN_000fe8e4;
    puStack_198 = &DAT_010618c0;
    _objc_retain(uVar5);
    puStack_150 = @selector(actionWithTitle:iconImage:style:handler:);
    uStack_190 = uVar5;
    _objc_msgSend(lVar3,@selector(actionWithTitle:iconImage:style:handler:),uVar7,uVar8,0,&puStack_1b0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(addAction:);
    _objc_msgSend(uStack_130,@selector(addAction:),uVar9);
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
    _objc_msgSend(uVar6,puStack_140,@"ShowThumbnail",0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_148,@"show_image")
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
    _objc_msgSend(uVar6,puStack_140,@"CopyThumbnail",0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_148,@"image_library")
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
    _objc_msgSend(uVar4,@selector(setSourceView:),IStack_160);
    _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(rootViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(presentFromViewController:animated:completion:),uVar7,1,0);
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



// -[DownloadMenuHelper showInformationSheet:withSender:], 0xfeb1c
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
  puVar12 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_9c = FUN_00111464(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar11 = local_98[uStack_9c] + (int)-(DAT_01189d68 ^ 0x2115d05c);
  if (uStack_9c == 0) {
    uStack_ac = FUN_001112bc(param_3,puVar1,@selector(contentPlayerResponse));
    puVar11 = local_a8[uStack_ac] + (int)-(uRam0000000001189d80 ^ 0xa2b75d0b);
    puVar12 = puVar2;
    if (uStack_ac == 0) goto LAB_00100110;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(playerData);
  uStack_bc = (uint)(lVar5 == 0);
  puVar11 = local_b8[uStack_bc] + (int)-(uRam0000000001189d98 ^ 0x98b32903);
  if (lVar5 != 0) {
    IStack_248 = param_1;
    puStack_230 = auStack_310;
    puStack_218 = auStack_2b0;
    IStack_210 = param_4;
    puStack_200 = auStack_280;
    _objc_msgSend(lVar5,@selector(playerData));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar11 = @selector(videoDetails);
    _objc_msgSend(uVar6,@selector(videoDetails));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(title));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(author));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(shortDescription));
    uStack_220 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    lStack_228 = lVar5;
    _objc_msgSend(lVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar11);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_23c = FUN_00111074(uVar7,@selector(hasShortDescription));
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar11 = @selector(length);
    uVar10 = _objc_msgSend(uVar9,@selector(length));
    uStack_cc = (uint)(0x1e < uVar10);
    uStack_208 = uVar9;
    IStack_1f8 = param_3;
    if (0x1e < uVar10) {
      _objc_msgSend(local_c8[uStack_cc] + (int)-(DAT_01189db0 ^ 0x265139d1),uVar9,
                    @selector(substringToIndex:),0x1e);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(stringByAppendingString:),
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
                    @selector(substringToIndex:),200);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(stringByAppendingString:),
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
    _objc_msgSend(uVar6,@selector(sheetControllerWithParentResponder:),0);
    uStack_1c0 = _objc_retainAutoreleasedReturnValue();
    uStack_114 = (uint)(DAT_012270a0 == 0);
    if (DAT_012270a0 == 0) {
      DAT_012270a0 = _objc_getClass(local_110[uStack_114] + (int)-(DAT_01189e10 ^ 0x9c849656),
                                    s_YTActionSheetAction_011863e0);
    }
    lVar5 = DAT_012270a0;
    _objc_retainAutorelease(DAT_012270a0);
    puStack_1c8 = @selector(ytl_defaultBundle);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_1d0 = @selector(localizedStringForKey:value:table:);
    _objc_msgSend(uVar7,@selector(localizedStringForKey:value:table:),
                  @"CopyChannelName",0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puStack_1d8 = @selector(imageWithName:);
    _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(imageWithName:),
                  @"copy");
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_200;
    uVar6 = uStack_208;
    *puStack_200 = PTR___NSConcreteStackBlock_01060660;
    puVar3[1] = DAT_00c4c228;
    puVar3[2] = FUN_0010015c;
    puVar3[3] = &DAT_010618c0;
    uVar6 = _objc_retain(uVar6);
    puVar3[4] = uVar6;
    puStack_1e0 = @selector(actionWithTitle:iconImage:style:handler:);
    _objc_msgSend(lVar5,@selector(actionWithTitle:iconImage:style:handler:),uVar8,uVar9,0,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_1e8 = @selector(addAction:);
    _objc_msgSend(uStack_1c0,@selector(addAction:),uVar6);
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



// -[DownloadMenuHelper showExtPlayerSheet:withSender:], 0x101144
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
  puVar1 = @selector(activeVideo);
  IStack_128 = param_4;
  _objc_retain(param_4);
  _objc_msgSend(param_3,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,@selector(videoData));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(playbackData));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(video));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(streamingData));
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,@selector(HLSMasterPlaylistURL));
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
  _objc_msgSend(uVar10,@selector(sheetControllerWithParentResponder:),0);
  uStack_100 = _objc_retainAutoreleasedReturnValue();
  uStack_b4 = (uint)(DAT_012270a0 == 0);
  if (DAT_012270a0 == 0) {
    DAT_012270a0 = _objc_getClass(local_b0[uStack_b4] + (int)-(uRam000000000118a038 ^ 0x9931b94b),
                                  s_YTActionSheetAction_01186970);
  }
  lVar5 = DAT_012270a0;
  _objc_retainAutorelease(DAT_012270a0);
  puVar1 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_118 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar11,@selector(localizedStringForKey:value:table:),
                @"PlayInSystemPlayer",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(imageWithName:),
                @"player");
  uVar13 = _objc_retainAutoreleasedReturnValue();
  uVar10 = DAT_00c4c228;
  puStack_170 = PTR___NSConcreteStackBlock_01060660;
  uStack_168 = DAT_00c4c228;
  pcStack_160 = FUN_00101fac;
  puStack_158 = &DAT_01061c60;
  uStack_150 = _objc_retain(uStack_f8);
  _objc_retain(param_3);
  puStack_120 = @selector(actionWithTitle:iconImage:style:handler:);
  IStack_148 = param_3;
  IStack_108 = param_3;
  _objc_msgSend(lVar5,@selector(actionWithTitle:iconImage:style:handler:),uVar12,uVar13,0,&puStack_170);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puStack_140 = @selector(addAction:);
  _objc_msgSend(uStack_100,@selector(addAction:),uVar14);
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
  _objc_msgSend(uVar11,puStack_118,@"PlayInInfuse",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(imageNamed:inBundle:compatibleWithTraitCollection:);
  _objc_msgSend(puVar3,@selector(imageNamed:inBundle:compatibleWithTraitCollection:),
                @"infuse",uVar13,0);
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
  _objc_msgSend(uVar12,puStack_118,@"PlayInVLC",0,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar2,@"vlc",uVar14,0);
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
  _objc_msgSend(uVar10,@selector(setSourceView:),IStack_128);
  _objc_release(IVar8);
  _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(rootViewController));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,@selector(presentFromViewController:animated:completion:),uVar13,1,0);
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



// -[DownloadMenuHelper getVideoFormatsArray:isShorts:], 0x1030f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1030f8. getVideoFormatsArray:isShorts: */

/* Function Stack Size: 0x1c bytes */

ID DownloadMenuHelper::getVideoFormatsArray_isShorts_
             (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  ID IVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_2b0 [128];
  undefined8 uStack_230;
  undefined8 *puStack_228;
  long *plStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  long lStack_1e8;
  ID IStack_1e0;
  undefined *puStack_1d8;
  undefined1 *puStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  uint local_1b4;
  undefined8 uStack_1b0;
  long lStack_1a8;
  undefined8 uStack_1a0;
  ID local_198;
  long lStack_190;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined *puStack_178;
  undefined **local_170;
  undefined **ppuStack_168;
  uint uStack_15c;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118a198;
  local_7c = (uint)(DAT_01227180 == 0);
  local_90 = &PTR_LAB_0118a1b8;
  local_a0 = &PTR_LAB_0118a1d0;
  local_b0 = &PTR_LAB_0118a1e8;
  local_c0 = &PTR_LAB_0118a200;
  local_88 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118a228;
  local_f8 = &PTR_LAB_0118a248;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118a268;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118a280;
  local_138 = &PTR_LAB_0118a2a0;
  ppuStack_130 = &PTR_LAB_011882f0;
  local_148 = &PTR_LAB_0118a2b8;
  local_158 = &PTR_LAB_0118a2d0;
  local_170 = &PTR_LAB_011882f0;
  ppuStack_168 = &PTR_LAB_011882f0;
  DAT_01227180 = 1;
  puStack_1d0 = auStack_2b0;
  local_1b4 = param_4;
  local_198 = param_1;
  uVar6 = _objc_retain(param_3);
  puVar12 = @selector(playerResponse);
  puVar2 = @selector(respondsToSelector:);
  uStack_94 = FUN_001124a8(uVar6,@selector(respondsToSelector:),@selector(playerResponse));
  puVar3 = @selector(contentPlayerResponse);
  puVar11 = local_90[uStack_94] + (int)-(uRam000000000118a1c8 ^ 0x3736dfb0);
  if (uStack_94 == 0) {
    uStack_a4 = FUN_001121d0(param_3,puVar2,@selector(contentPlayerResponse));
    puVar11 = local_a0[uStack_a4] + (int)-(uRam000000000118a1e0 ^ 0x87398550);
    puVar12 = puVar3;
    if (uStack_a4 == 0) goto LAB_00103974;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lStack_1e8 = _objc_retainAutoreleasedReturnValue();
  uStack_b4 = (uint)(lStack_1e8 == 0);
  puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a1f8 ^ 0xa14bcfa7);
  if (lStack_1e8 != 0) {
    IStack_1e0 = param_3;
    _objc_msgSend(lStack_1e8,@selector(playerData));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(streamingData));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(adaptiveFormatsArray));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar11 = @selector(array);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uStack_1a0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,puVar11);
    uStack_1c0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,puVar11);
    uStack_1c8 = _objc_retainAutoreleasedReturnValue();
    puStack_228 = (undefined8 *)0x0;
    uStack_230 = 0;
    uStack_218 = 0;
    plStack_220 = (long *)0x0;
    uStack_208 = 0;
    uStack_210 = 0;
    uStack_1f8 = 0;
    uStack_200 = 0;
    uVar6 = _objc_retain(uVar8);
    puStack_1d8 = @selector(countByEnumeratingWithState:objects:count:);
    uStack_1b0 = uVar8;
    lStack_190 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),&uStack_230,
                               puStack_1d0,0x10);
    puVar2 = @selector(mimeType);
    puVar11 = @selector(hasPrefix:);
    uStack_c4 = (uint)(lStack_190 == 0);
    if (lStack_190 == 0) {
      _objc_release(local_c0[uStack_c4] + (int)-(uRam000000000118a210 ^ 0xdbe65a5d),uStack_1b0);
      lVar9 = _objc_msgSend(uStack_1c0,@selector(count));
      uStack_15c = local_1b4;
      if (lVar9 != 0) {
        uStack_15c = 1;
      }
                    /* WARNING: Could not recover jumptable at 0x00103900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar10 = (*(code *)(local_158[uStack_15c] + (int)-(uRam000000000118a2e0 ^ 0x3731106a)))();
      return IVar10;
    }
    lStack_1a8 = *plStack_220;
    puStack_188 = @selector(getResoForQuality:);
    puStack_180 = @selector(qualityLabel);
    puStack_178 = @selector(addObject:);
    lStack_190 = lStack_190 + -1;
    bVar4 = *plStack_220 == lStack_1a8;
    uStack_e4 = (uint)bVar4;
    if (!bVar4) {
      _objc_enumerationMutation
                (local_e0[bVar4] + (int)-(uRam000000000118a238 ^ 0x78992f85),uStack_1b0);
    }
    uVar7 = *puStack_228;
    _objc_msgSend(uVar7,puStack_180);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar9 = _objc_msgSend(local_198,puStack_188,uVar6);
    _objc_release(uVar6);
    _objc_msgSend(uVar7,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_00112318(uVar6,puVar11,@"video/mp4");
    _objc_release(uVar6);
    _objc_msgSend(uVar7,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    FUN_00112360(uVar6,puVar11,@"video/webm");
    _objc_release(uVar6);
    uVar1 = 0;
    if (0x8f < lVar9) {
      uVar1 = uVar5;
    }
    uStack_fc = 0;
    if (lVar9 < 0x439) {
      uStack_fc = uVar1;
    }
                    /* WARNING: Could not recover jumptable at 0x001036ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar10 = (*(code *)(local_f8[uStack_fc] + (int)-(DAT_0118a258 ^ 0xeb4326ee)))();
    return IVar10;
  }
  uStack_b4 = 1;
LAB_00103974:
  _objc_release(puVar11,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(0);
  return IVar10;
}



// -[DownloadMenuHelper getAudioFormatsArray:], 0x103a28
/* Decompiled from supplied 5.2.2 arm package. VA 0x103a28. getAudioFormatsArray: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::getAudioFormatsArray_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  long lVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  long lVar12;
  long lVar13;
  undefined1 auStack_220 [128];
  undefined8 uStack_1a0;
  long lStack_198;
  long *plStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  long lStack_160;
  ID IStack_158;
  undefined *puStack_150;
  undefined1 *puStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined4 uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  int iStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_0118a2f8;
  local_7c = (uint)(DAT_01227188 == 0);
  local_90 = &PTR__objc_msgSend_0118a318;
  local_a0 = &PTR_LAB_0118a330;
  local_b0 = &PTR_LAB_0118a348;
  local_c0 = &PTR_LAB_0118a360;
  local_88 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e0 = &PTR__objc_msgSend_0118a388;
  local_f8 = &PTR_LAB_0118a3a8;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118a3c8;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118a3e0;
  local_130 = &PTR_LAB_011882f0;
  DAT_01227188 = 1;
  puStack_148 = auStack_220;
  uVar4 = _objc_retain(param_3);
  puVar11 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_94 = FUN_00112660(uVar4,@selector(respondsToSelector:),@selector(playerResponse));
  puVar2 = @selector(contentPlayerResponse);
  puVar10 = local_90[uStack_94] + (int)-(uRam000000000118a328 ^ 0x403a1f5a);
  if (uStack_94 == 0) {
    uStack_a4 = FUN_00112598(param_3,puVar1,@selector(contentPlayerResponse));
    uVar4 = 0;
    puVar10 = local_a0[uStack_a4] + (int)-(uRam000000000118a340 ^ 0x9ffb4893);
    puVar11 = puVar2;
    if (uStack_a4 == 0) goto LAB_00104038;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  uVar4 = 0;
  uStack_b4 = (uint)(lVar5 == 0);
  puVar10 = local_b0[uStack_b4] + (int)-(uRam000000000118a358 ^ 0x218e395d);
  if (lVar5 != 0) {
    lStack_160 = lVar5;
    IStack_158 = param_3;
    _objc_msgSend(lVar5,@selector(playerData));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(streamingData));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(adaptiveFormatsArray));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uStack_140 = _objc_retainAutoreleasedReturnValue();
    lStack_198 = 0;
    uStack_1a0 = 0;
    uStack_188 = 0;
    plStack_190 = (long *)0x0;
    uStack_178 = 0;
    uStack_180 = 0;
    uStack_168 = 0;
    uStack_170 = 0;
    uVar4 = _objc_retain(uVar7);
    puStack_150 = @selector(countByEnumeratingWithState:objects:count:);
    uStack_138 = uVar7;
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_1a0,
                          puStack_148,0x10);
    uVar6 = uStack_138;
    puVar2 = @selector(mimeType);
    puVar11 = @selector(addObject:);
    puVar1 = @selector(hasPrefix:);
    uStack_c4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lVar13 = *plStack_190;
      lVar12 = 0;
      lVar9 = *plStack_190;
      while( true ) {
        uStack_e4 = (uint)(lVar9 == lVar13);
        if (lVar9 != lVar13) {
          _objc_enumerationMutation(uStack_138);
        }
        uVar6 = *(undefined8 *)(lStack_198 + lVar12 * 8);
        _objc_msgSend(uVar6,puVar2);
        uVar4 = _objc_retainAutoreleasedReturnValue();
        iVar3 = FUN_00112550(uVar4,puVar1,@"audio/mp4");
        _objc_release(uVar4);
        iStack_fc = iVar3;
        if (iVar3 != 0) {
          _objc_msgSend(uStack_140,puVar11,uVar6);
        }
        if (lVar5 + -1 == lVar12) break;
        uStack_114 = 0;
        lVar12 = lVar12 + 1;
        lVar9 = *plStack_190;
      }
      uStack_114 = 1;
      lVar5 = _objc_msgSend(uStack_138,puStack_150,&uStack_1a0,puStack_148,0x10);
      uStack_124 = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x00103e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar8 = (*(code *)(local_120[uStack_124] + (int)-(uRam000000000118a3f0 ^ 0x7054ba00)))();
      return IVar8;
    }
    _objc_release(uStack_138);
    uVar7 = uStack_140;
    _objc_msgSend(uStack_140,@selector(sortUsingComparator:),
                  &PTR___NSConcreteGlobalBlock_010622d0);
    uVar4 = _objc_msgSend(uVar7,@selector(copy));
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(lStack_160);
    puVar10 = &stack0xffffffffffffffa8;
    param_3 = IStack_158;
  }
LAB_00104038:
  _objc_release(puVar10,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
    return IVar8;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[DownloadMenuHelper getBestAudioFormat:playerVC:], 0x1040ec
/* Decompiled from supplied 5.2.2 arm package. VA 0x1040ec. getBestAudioFormat:playerVC: */

/* Function Stack Size: 0x20 bytes */

ID DownloadMenuHelper::getBestAudioFormat_playerVC_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ID IVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStack_270 [128];
  undefined8 uStack_1f0;
  undefined8 *puStack_1e8;
  long *plStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined1 *puStack_1a8;
  ID IStack_1a0;
  ID IStack_198;
  long lStack_190;
  undefined **local_188;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_168;
  uint uStack_15c;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
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
  local_78 = &PTR_LAB_0118a400;
  local_7c = (uint)(DAT_01227190 == 0);
  local_90 = &PTR_LAB_0118a420;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118a448;
  local_c8 = &PTR_LAB_0118a468;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118a480;
  local_e8 = &PTR_LAB_0118a498;
  local_f8 = &PTR_LAB_0118a4b0;
  local_108 = &PTR_LAB_0118a4c8;
  local_118 = &PTR_LAB_0118a4e0;
  local_128 = &PTR_LAB_0118a4f8;
  local_138 = &PTR_LAB_0118a510;
  local_148 = &PTR_LAB_0118a528;
  local_158 = &PTR_LAB_0118a540;
  local_168 = &PTR_LAB_0118a558;
  local_180 = &PTR_LAB_011882f0;
  ppuStack_178 = &PTR_LAB_011882f0;
  local_188 = &PTR_LAB_011882f0;
  DAT_01227190 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  puStack_1e8 = (undefined8 *)0x0;
  uStack_1f0 = 0;
  uStack_1d8 = 0;
  plStack_1e0 = (long *)0x0;
  uVar7 = _objc_retain(param_3);
  puVar2 = @selector(countByEnumeratingWithState:objects:count:);
  lVar8 = _objc_msgSend(uVar7,@selector(countByEnumeratingWithState:objects:count:),&uStack_1f0,
                        auStack_270,0x10);
  puVar4 = @selector(itag);
  puVar3 = @selector(mimeType);
  puVar1 = @selector(hasPrefix:);
  uStack_94 = (uint)(lVar8 == 0);
  if (lVar8 == 0) {
    _objc_release(local_90[uStack_94] + (int)-(DAT_0118a430 ^ 0xd570ae18),param_3);
    _objc_msgSend(param_4,@selector(activeVideo));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(selectedAudioFormat));
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,@selector(formatStream));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar7);
    _objc_release(param_4);
    _objc_release(param_3);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar9 = _objc_autoreleaseReturnValue(uVar10);
    return IVar9;
  }
  puStack_1b0 = puVar2;
  lStack_190 = *plStack_1e0;
  uStack_b4 = (uint)(*plStack_1e0 == lStack_190);
  puStack_1a8 = auStack_270;
  IStack_1a0 = param_4;
  IStack_198 = param_3;
  if (*plStack_1e0 != lStack_190) {
    _objc_enumerationMutation(local_b0[uStack_b4] + (int)-(DAT_0118a458 ^ 0xf8b4dcea),param_3);
  }
  uVar11 = *puStack_1e8;
  _objc_msgSend(uVar11,puVar3);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_0011294c(uVar7,puVar1,@"audio/mp4");
  _objc_release(uVar7);
  uStack_cc = uVar5;
  if (uVar5 != 0) {
    iVar6 = _objc_msgSend(local_c8[uVar5] + (int)-(uRam000000000118a478 ^ 0x642d41d0),uVar11,puVar4)
    ;
    uStack_dc = (uint)(iVar6 == 0x8c);
    if (iVar6 == 0x8c) {
      _objc_msgSend(uVar11,@selector(audioTrack));
      lVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
      uStack_ec = (uint)(lVar8 == 0);
                    /* WARNING: Could not recover jumptable at 0x001046f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar9 = (*(code *)(local_e8[uStack_ec] + (int)-(DAT_0118a4a8 ^ 0xfaa25672)))();
      return IVar9;
    }
    iVar6 = _objc_msgSend(local_d8[uStack_dc] + (int)-(uRam000000000118a490 ^ 0xff062e83),uVar11,
                          puVar4);
    uStack_11c = (uint)(iVar6 == 0x8b);
                    /* WARNING: Could not recover jumptable at 0x00104548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar9 = (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000118a4f0 ^ 0x895ad973)))();
    return IVar9;
  }
  uStack_15c = (uint)(lVar8 == 1);
                    /* WARNING: Could not recover jumptable at 0x0010457c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar9 = (*(code *)(local_158[uStack_15c] + (int)-(uRam000000000118a550 ^ 0xf54c3168)))();
  return IVar9;
}



// -[DownloadMenuHelper getDefaultAudioTrack:], 0x1048f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1048f4. getDefaultAudioTrack: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::getDefaultAudioTrack_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_0118a588;
  _objc_retain(param_3);
  uStack_118 = 0;
  local_120 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uVar1 = _objc_retain();
  lVar2 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x001049e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_100[local_104] + (int)-(DAT_0118a598 ^ 0x7bd35f81)))();
  return IVar3;
}



// -[DownloadMenuHelper getEnglishAudioTrack:], 0x104bf8
/* Decompiled from supplied 5.2.2 arm package. VA 0x104bf8. getEnglishAudioTrack: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::getEnglishAudioTrack_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  undefined *puVar11;
  long lVar12;
  undefined1 auStack_1e0 [128];
  undefined8 uStack_160;
  long lStack_158;
  long *plStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined *puStack_118;
  undefined1 *puStack_110;
  ID local_108;
  long lStack_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **ppuStack_d8;
  int iStack_cc;
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
  local_78 = &PTR_LAB_0118a620;
  local_7c = (uint)(DAT_01227198 == 0);
  local_90 = &PTR_LAB_0118a640;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118a668;
  local_c8 = &PTR_LAB_0118a688;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118a6a8;
  ppuStack_d8 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_0118a6c0;
  DAT_01227198 = 1;
  local_108 = param_3;
  _objc_retain(param_3);
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  lStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  plStack_150 = (long *)0x0;
  uVar6 = _objc_retain();
  puVar11 = @selector(countByEnumeratingWithState:objects:count:);
  lVar7 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),&uStack_160,
                        auStack_1e0,0x10);
  uVar6 = 0;
  uStack_94 = (uint)(lVar7 == 0);
  if (lVar7 == 0) {
LAB_00104fa8:
    IVar10 = local_108;
    _objc_release(local_108);
    _objc_release(IVar10);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
    return IVar10;
  }
  puStack_118 = puVar11;
  lStack_100 = *plStack_150;
  puStack_110 = auStack_1e0;
LAB_00104dd8:
  puVar3 = @selector(id_p);
  puVar2 = @selector(audioTrack);
  puVar1 = @selector(hasPrefix:);
  lVar12 = 0;
  uStack_b4 = (uint)(*plStack_150 == lStack_100);
  puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a678 ^ 0x9e028712);
  if (*plStack_150 == lStack_100) goto LAB_00104e24;
  do {
    _objc_enumerationMutation(puVar11,local_108);
LAB_00104e24:
    do {
      uVar6 = *(undefined8 *)(lStack_158 + lVar12 * 8);
      _objc_msgSend(uVar6,puVar2);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar3);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      iVar5 = FUN_00112b1c(uVar9,puVar1,@"en.4");
      _objc_release(uVar9);
      _objc_release(uVar8);
      iStack_cc = iVar5;
      if (iVar5 != 0) {
        _objc_msgSend(uVar6,@selector(itag));
        _objc_retain(uVar6);
        goto LAB_00104fa8;
      }
      bVar4 = lVar7 + -1 == lVar12;
      uStack_e4 = (uint)bVar4;
      if (bVar4) {
        lVar7 = _objc_msgSend(local_108,puStack_118,&uStack_160,puStack_110,0x10);
        uVar6 = 0;
        uStack_f4 = (uint)(lVar7 == 0);
        if (lVar7 == 0) goto LAB_00104fa8;
        goto LAB_00104dd8;
      }
      lVar12 = lVar12 + 1;
      uStack_b4 = (uint)(*plStack_150 == lStack_100);
      puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a678 ^ 0x9e028712);
    } while (*plStack_150 == lStack_100);
  } while( true );
}



// -[DownloadMenuHelper detailForMimeType:], 0x104ffc
/* Decompiled from supplied 5.2.2 arm package. VA 0x104ffc. detailForMimeType: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::detailForMimeType_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  undefined1 auVar9 [16];
  
  DAT_0122719c = 1;
  uVar3 = _objc_retain(param_3);
  puVar1 = @selector(rangeOfString:);
  auVar9 = _objc_msgSend(uVar3,@selector(rangeOfString:),
                         @"/");
  if (auVar9._0_8_ == 0x7fffffffffffffff) {
    lVar5 = 0;
  }
  else {
    _objc_msgSend(param_3,@selector(substringFromIndex:),auVar9._0_8_ + auVar9._8_8_);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(componentsSeparatedByString:),
                  @";");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(firstObject));
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  auVar9 = _objc_msgSend(param_3,puVar1,@"codecs=\"");
  uVar3 = 0;
  lVar8 = 0;
  if (auVar9._0_8_ != 0x7fffffffffffffff) {
    _objc_msgSend(param_3,@selector(substringFromIndex:),auVar9._0_8_ + auVar9._8_8_);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(componentsSeparatedByString:);
    _objc_msgSend(uVar3,@selector(componentsSeparatedByString:),
                  @"\"");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(firstObject);
    _objc_msgSend(uVar4,@selector(firstObject));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar6,puVar1,@".");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    lVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar6);
    _objc_release(uVar3);
    uVar3 = 0;
    if (lVar5 != 0 && lVar8 != 0) {
      thunk_FUN_00112b90(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                         &PTR____CFConstantStringClassReference_01187050,lVar5,lVar8);
      uVar3 = _objc_retainAutoreleasedReturnValue();
    }
  }
  _objc_release(lVar8);
  _objc_release(lVar5);
  _objc_release(param_3);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar7;
}



// -[DownloadMenuHelper getResoForQuality:], 0x1054dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1054dc. getResoForQuality: */

/* Function Stack Size: 0x18 bytes */

long_long DownloadMenuHelper::getResoForQuality_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long_long lVar3;
  
  DAT_012271a0 = 1;
  _objc_msgSend(param_3,@selector(componentsSeparatedByString:),
                @"p");
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(objectAtIndexedSubscript:),0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,@selector(integerValue));
  _objc_release(uVar2);
  _objc_release(uVar1);
  return lVar3;
}



// -[DownloadMenuHelper downloadVideoWithFormat:withAudioFormats:fileName:extension:videoID:playerVC:sender:], 0x1055f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1055f4. downloadVideoWithFormat:withAudioFormats:fileName:extension:videoID:playerVC:sender: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x48 bytes */

void DownloadMenuHelper::
     downloadVideoWithFormat_withAudioFormats_fileName_extension_videoID_playerVC_sender_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               ID param_8,ID param_9)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined *puStack_2a0;
  undefined8 uStack_298;
  code *pcStack_290;
  undefined *puStack_288;
  undefined8 uStack_280;
  undefined8 *puStack_278;
  undefined *puStack_270;
  undefined8 uStack_268;
  code *pcStack_260;
  undefined *puStack_258;
  ID IStack_250;
  ID IStack_248;
  long lStack_240;
  undefined8 uStack_238;
  ID IStack_230;
  ID IStack_228;
  ID IStack_220;
  undefined8 uStack_218;
  undefined8 *puStack_210;
  undefined8 *puStack_208;
  undefined8 uStack_200;
  undefined8 *puStack_1f8;
  undefined8 uStack_1f0;
  code *pcStack_1e8;
  code *pcStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 *puStack_1c8;
  undefined8 uStack_1c0;
  code *pcStack_1b8;
  code *pcStack_1b0;
  undefined8 uStack_1a8;
  long lStack_198;
  ID local_190;
  ID IStack_188;
  ID IStack_180;
  ID IStack_178;
  undefined **local_170;
  undefined **local_168;
  undefined **local_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_148;
  uint uStack_13c;
  undefined **local_138;
  undefined **local_130;
  undefined **local_128;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
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
  
  local_80 = &PTR_LAB_0118a770;
  local_84 = (uint)(DAT_012271a4 == 0);
  local_98 = &PTR_LAB_0118a790;
  local_a8 = &PTR_LAB_0118a7a8;
  local_b8 = &PTR_LAB_0118a7c0;
  local_d0 = &PTR_LAB_0118a7e0;
  local_e0 = &PTR_LAB_0118a7f8;
  local_f0 = &PTR_LAB_0118a810;
  local_100 = &PTR_LAB_0118a828;
  local_110 = &PTR_LAB_0118a840;
  local_90 = &PTR_LAB_011882f0;
  local_c8 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_011882f0;
  local_130 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_0118a870;
  local_148 = &PTR_LAB_011882f0;
  local_150 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_011882f0;
  local_160 = &PTR_LAB_011882f0;
  local_168 = &PTR_LAB_011882f0;
  local_170 = &PTR_LAB_011882f0;
  DAT_012271a4 = 1;
  local_190 = param_1;
  IStack_178 = param_3;
  _objc_retain(param_3);
  IStack_188 = param_4;
  _objc_retain(param_4);
  IStack_180 = param_5;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_7);
  _objc_retain(param_8);
  _objc_retain(param_9);
  puVar8 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_9c = FUN_00112ed8(param_8,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar6 = local_98[uStack_9c] + (int)-(uRam000000000118a7a0 ^ 0x39ae2cc7);
  if (uStack_9c == 0) {
    uStack_ac = FUN_00112e70(param_8,puVar1,@selector(contentPlayerResponse));
    puVar6 = local_a8[uStack_ac] + (int)-(uRam000000000118a7b8 ^ 0x5c21ff8a);
    puVar8 = puVar2;
    if (uStack_ac == 0) goto LAB_00105ea8;
  }
  _objc_msgSend(puVar6,param_8,puVar8);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar6 = PTR___NSConcreteStackBlock_01060660;
  uVar5 = DAT_00c4c228;
  uStack_bc = (uint)(lVar3 == 0);
  if (lVar3 == 0) goto LAB_00105ea8;
  uStack_1d0 = 0;
  uStack_1c0 = _UNK_00c4c350;
  pcStack_1b8 = FUN_00105f50;
  pcStack_1b0 = FUN_00105f60;
  uStack_1a8 = 0;
  uStack_200 = 0;
  uStack_1f0 = _UNK_00c4c350;
  pcStack_1e8 = FUN_00105f50;
  pcStack_1e0 = FUN_00105f60;
  uStack_1d8 = 0;
  puStack_270 = PTR___NSConcreteStackBlock_01060660;
  uStack_268 = DAT_00c4c228;
  pcStack_260 = FUN_00105f90;
  puStack_258 = &UNK_010622f0;
  IStack_250 = local_190;
  puStack_210 = &uStack_200;
  puStack_1f8 = &uStack_200;
  puStack_1c8 = &uStack_1d0;
  _objc_retain(param_8);
  IStack_248 = param_8;
  _objc_retain(lVar3);
  lStack_240 = lVar3;
  uStack_238 = _objc_retain(IStack_178);
  puStack_208 = &uStack_1d0;
  _objc_retain(param_6);
  IStack_230 = param_6;
  _objc_retain(param_7);
  IStack_228 = param_7;
  _objc_retain(param_9);
  IStack_220 = param_9;
  uStack_218 = _objc_retain(IStack_180);
  lStack_198 = _objc_retainBlock(&puStack_270);
  lVar4 = _ytpInt(@"ytlAudioIndex");
  uStack_d4 = (uint)(lVar4 < 2);
  if (lVar4 < 2) {
    uStack_104 = (uint)(lVar4 < 1);
    if (lVar4 < 1) {
      uStack_114 = (uint)(lVar4 == 0);
      if (lVar4 != 0) goto LAB_00105e34;
      _objc_msgSend(local_190,@selector(getDefaultAudioTrack:),IStack_188);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      _objc_msgSend(local_190,@selector(getBestAudioFormat:playerVC:),IStack_188,param_8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    uVar7 = puStack_1c8[5];
    puStack_1c8[5] = uVar5;
    _objc_release(uVar7);
    (**(code **)(lStack_198 + 0x10))();
  }
  else {
    uStack_e4 = (uint)(lVar4 < 3);
    if (lVar4 < 3) {
      _objc_msgSend(local_190,@selector(getEnglishAudioTrack:),IStack_188);
      lVar3 = _objc_retainAutoreleasedReturnValue();
      uStack_13c = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00105d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_138[uStack_13c] + (int)-(uRam000000000118a880 ^ 0xee7e8dd2)))();
      return;
    }
    uStack_f4 = (uint)(lVar4 == 3);
    if (lVar4 == 3) {
      puStack_2a0 = puVar6;
      uStack_298 = uVar5;
      pcStack_290 = FUN_001066e4;
      puStack_288 = &UNK_01062320;
      puStack_278 = &uStack_1d0;
      uStack_280 = _objc_retain(lStack_198);
      _objc_msgSend(local_190,@selector(showAudioTrackSelector:sender:playerVC:completion:),IStack_188,param_9,
                    param_8,&puStack_2a0);
      _objc_release(uStack_280);
    }
  }
LAB_00105e34:
  _objc_release(lStack_198);
  _objc_release(uStack_218);
  _objc_release(IStack_220);
  _objc_release(IStack_228);
  _objc_release(IStack_230);
  _objc_release(uStack_238);
  _objc_release(lStack_240);
  _objc_release(IStack_248);
  __Block_object_dispose(&uStack_200,8);
  _objc_release(uStack_1d8);
  __Block_object_dispose(&uStack_1d0,8);
  _objc_release(uStack_1a8);
  _objc_release(lVar3);
LAB_00105ea8:
  _objc_release(param_9);
  _objc_release(param_8);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(IStack_180);
  _objc_release(IStack_188);
  _objc_release(IStack_178);
  return;
}



// -[DownloadMenuHelper downloadVideoWithFormat:audioFormat:fileName:extension:videoID:playerVC:sender:], 0x106840
/* Decompiled from supplied 5.2.2 arm package. VA 0x106840. downloadVideoWithFormat:audioFormat:fileName:extension:videoID:playerVC:sender: */

/* Function Stack Size: 0x48 bytes */

void DownloadMenuHelper::
     downloadVideoWithFormat_audioFormat_fileName_extension_videoID_playerVC_sender_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               ID param_8,ID param_9)

{
  undefined *puVar1;
  undefined *local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined *puStack_a0;
  ID local_98;
  ID local_90;
  ID local_88;
  ID local_80;
  ID local_78;
  ID local_70;
  ID local_68;
  
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_7);
  _objc_retain(param_8);
  puVar1 = @selector(getCaptionsUrlSheet:sender:completion:);
  local_b8 = PTR___NSConcreteStackBlock_01060660;
  local_b0 = DAT_00c4c228;
  local_a8 = FUN_001069d0;
  puStack_a0 = &DAT_01062350;
  local_98 = param_1;
  local_90 = param_3;
  local_88 = param_4;
  local_80 = param_5;
  local_78 = param_6;
  local_70 = param_7;
  local_68 = param_8;
  _objc_retain();
  _objc_retain(param_7);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,param_8,param_9,&local_b8);
  _objc_release(local_68);
  _objc_release(local_70);
  _objc_release(local_78);
  _objc_release(local_80);
  _objc_release(local_88);
  _objc_release(local_90);
  _objc_release(param_8);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xf950);
  return;
}



// -[DownloadMenuHelper downloadVideoWithUrl:audioUrl:fileName:extension:videoID:videoSize:audioSize:duration:captions:playerVC:], 0x106c80
/* Decompiled from supplied 5.2.2 arm package. VA 0x106c80. downloadVideoWithUrl:audioUrl:fileName:extension:videoID:videoSize:audioSize:duration:captions:playerVC: */

/* Function Stack Size: 0x60 bytes */

void DownloadMenuHelper::
     downloadVideoWithUrl_audioUrl_fileName_extension_videoID_videoSize_audioSize_duration_captions_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               unsigned_long_long param_8,unsigned_long_long param_9,unsigned_long_long param_10,
               ID param_11,ID param_12)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_012271d8 = 1;
  _objc_retain(param_12);
  puVar2 = PTR__OBJC_CLASS___UIApplication_0114ebc8;
  puVar1 = @selector(sharedApplication);
  _objc_retain(param_11);
  _objc_retain(param_7);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(delegate));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(window));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar6,@selector(rootViewController));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_alloc_init(PTR_YTLHelper_0114ed50);
  _objc_msgSend(uVar4,@selector(setHelper:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,@selector(helper));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  FUN_00113590(uVar5,@selector(downloadVideoWithUrl:audioUrl:fileName:format:videoID:videoSize:audioSize:duration:captions:),param_3,param_4,param_5,param_6
               ,param_7,param_8,param_9,param_10,param_11);
  _objc_release(param_11);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar5);
  if ((param_12 != 0) &&
     (iVar3 = FUN_00113454((&PTR_LAB_0118a998)[param_12 == 0] +
                           (int)-(uRam000000000118a9a8 ^ 0x4d38e521),
                           @"embedThumbnails"), iVar3 != 0)) {
    _objc_msgSend(param_1,@selector(getThumbnail:),param_12);
  }
  _objc_release(uVar4);
  _objc_release(uVar6);
  _objc_release(param_12);
  return;
}



// -[DownloadMenuHelper getThumbnail:], 0x107068
/* Decompiled from supplied 5.2.2 arm package. VA 0x107068. getThumbnail: */

/* Function Stack Size: 0x18 bytes */

void DownloadMenuHelper::getThumbnail_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puStack_68;
  undefined8 uStack_60;
  code *pcStack_58;
  undefined *puStack_50;
  long lStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118a9d0;
  _objc_retain(param_3);
  puVar7 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  local_3c = FUN_001135cc(param_3,@selector(respondsToSelector:),@selector(playerResponse));
  puVar2 = @selector(contentPlayerResponse);
  puVar6 = local_38[local_3c] + (int)-(DAT_0118a9e0 ^ 0x320f6bb5);
  if (local_3c == 0) {
    uVar3 = FUN_001135f4(param_3,puVar1,@selector(contentPlayerResponse));
    puVar6 = (&PTR_LAB_0118a9e8)[uVar3] + (int)-(DAT_0118a9f8 ^ 0x55ca9387);
    puVar7 = puVar2;
    if (uVar3 == 0) goto LAB_00107208;
  }
  _objc_msgSend(puVar6,param_3,puVar7);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  if (lVar4 != 0) {
    _dispatch_get_global_queue(0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puStack_68 = PTR___NSConcreteStackBlock_01060660;
    uStack_60 = DAT_00c4c228;
    pcStack_58 = FUN_0010723c;
    puStack_50 = &DAT_01061420;
    lStack_48 = lVar4;
    _objc_retain(lVar4);
    _dispatch_async(uVar5,&puStack_68);
    _objc_release(uVar5);
    _objc_release(lStack_48);
    _objc_release(lVar4);
  }
LAB_00107208:
  _objc_release(param_3);
  CallSupervisor(0x65c1);
  return;
}



// -[DownloadMenuHelper checkSpaceAvailabilityForMedia:completion:], 0x107a20
/* Decompiled from supplied 5.2.2 arm package. VA 0x107a20. checkSpaceAvailabilityForMedia:completion: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::checkSpaceAvailabilityForMedia_completion_
               (ID param_1,SEL param_2,long_long param_3,ID param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_012271e4 = 1;
  _objc_retain(param_4);
  if (DAT_012270b0 == 0) {
    DAT_012270b0 = _objc_getClass((&PTR_LAB_0118aac0)[DAT_012270b0 == 0] +
                                  (int)-(DAT_0118aad0 ^ 0x9ff40b07),
                                  s_YTAutoOfflineController_01187550);
  }
  _objc_retainAutorelease();
  uVar2 = _objc_alloc_init();
  lVar3 = _objc_msgSend(uVar2,@selector(freeDeviceStorageBytes));
  puVar1 = @selector(stringFromByteCount:countStyle:);
  _objc_msgSend(PTR__OBJC_CLASS___NSByteCountFormatter_0114edf0,
                @selector(stringFromByteCount:countStyle:),lVar3,0);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSByteCountFormatter_0114edf0,puVar1,param_3 * 2 - lVar3,0);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00107e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118aae0)[(long)(param_3 * 2) < lVar3] +
            (int)-(uRam000000000118aaf0 ^ 0x59a4dd44)))();
  return;
}



// -[DownloadMenuHelper showAudioTrackSelector:sender:playerVC:completion:], 0x107f1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x107f1c. showAudioTrackSelector:sender:playerVC:completion: */

/* Function Stack Size: 0x30 bytes */

void DownloadMenuHelper::showAudioTrackSelector_sender_playerVC_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
                    /* WARNING: Could not recover jumptable at 0x001080d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118ab08)[DAT_012271e8 == 0] + (int)-(DAT_0118ab18 ^ 0xd5f5c4b2)))();
  return;
}



// -[DownloadMenuHelper hasCaptions:], 0x109374
/* Decompiled from supplied 5.2.2 arm package. VA 0x109374. hasCaptions: */

/* Function Stack Size: 0x18 bytes */

bool DownloadMenuHelper::hasCaptions_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined1 *puStack_178;
  undefined *puStack_170;
  long lStack_168;
  long lStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_140;
  uint uStack_134;
  undefined **local_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  int iStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118adb8;
  local_7c = (uint)(DAT_012271f8 == 0);
  local_90 = &PTR_LAB_0118add8;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_0118adf8;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b8 = &PTR_LAB_0118ae10;
  local_d0 = &PTR_LAB_011882f0;
  ppuStack_c8 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118ae38;
  local_f0 = &PTR_LAB_0118ae58;
  ppuStack_e8 = &PTR_LAB_011882f0;
  local_100 = &PTR_LAB_0118ae70;
  local_110 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_0118ae90;
  local_128 = &PTR_LAB_011882f0;
  local_130 = &PTR_LAB_0118aeb0;
  local_140 = &PTR_LAB_0118aec8;
  local_150 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_011882f0;
  DAT_012271f8 = 1;
  _objc_msgSend(param_3,@selector(activeVideo));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(availableCaptionTracks));
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  iStack_94 = FUN_001140d4(@"addAutoCaps");
  if (iStack_94 == 0) {
    uStack_ac = (uint)(lVar7 == 0);
    if (lVar7 != 0) {
      uStack_198 = 0;
      uStack_1a0 = 0;
      uStack_188 = 0;
      uStack_190 = 0;
      puStack_1b8 = (undefined8 *)0x0;
      uStack_1c0 = 0;
      uStack_1a8 = 0;
      plStack_1b0 = (long *)0x0;
      uVar6 = _objc_retain(local_a8[uStack_ac] + (int)-(uRam000000000118ae08 ^ 0xc915f782),lVar7);
      puStack_170 = @selector(countByEnumeratingWithState:objects:count:);
      lStack_160 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),&uStack_1c0,
                                 auStack_240,0x10);
      puVar2 = @selector(VSSID);
      puVar1 = @selector(hasPrefix:);
      uStack_bc = (uint)(lStack_160 == 0);
      if (lStack_160 != 0) {
        lStack_168 = *plStack_1b0;
        lStack_160 = lStack_160 + -1;
        bVar3 = *plStack_1b0 == lStack_168;
        uStack_dc = (uint)bVar3;
        puStack_178 = auStack_240;
        if (!bVar3) {
          _objc_enumerationMutation
                    (local_d8[bVar3] + (int)-(uRam000000000118ae48 ^ 0xf1136a5b),lVar7);
        }
        uVar10 = *puStack_1b8;
        _objc_msgSend(uVar10,puVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        uStack_f4 = FUN_00114030(uVar6,puVar1,@"t.");
        if (uStack_f4 == 0) {
          _objc_msgSend(local_f0[uStack_f4] + (int)-(uRam000000000118ae68 ^ 0x74130b3),uVar10,puVar2
                       );
          uVar8 = _objc_retainAutoreleasedReturnValue();
          uStack_104 = FUN_00113fc8(uVar8,puVar1,@"a.");
          if (uStack_104 == 0) {
            _objc_msgSend(uVar10,puVar2);
            uVar10 = _objc_retainAutoreleasedReturnValue();
            uVar4 = FUN_0011411c(uVar10,puVar1,@"ta.");
            _objc_release(uVar10);
            _objc_release(uVar8);
            _objc_release(uVar6);
            uStack_11c = uVar4;
                    /* WARNING: Could not recover jumptable at 0x001098ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            bVar5 = (*(code *)(local_118[uVar4] + (int)-(uRam000000000118aea0 ^ 0xef9988f4)))();
            return bVar5;
          }
          _objc_release(local_100[uStack_104] + (int)-(uRam000000000118ae80 ^ 0x791603c2),uVar8);
        }
        _objc_release(uVar6);
        uStack_134 = (uint)(lStack_160 == 0);
                    /* WARNING: Could not recover jumptable at 0x00109998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        bVar5 = (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118aec0 ^ 0xa83fce8f)))();
        return bVar5;
      }
      _objc_release(local_b8[uStack_bc] + (int)-(uRam000000000118ae20 ^ 0xb3f641e1),lVar7);
    }
    bVar5 = 0;
  }
  else {
    lVar9 = _objc_msgSend(lVar7,@selector(count));
    bVar5 = (bool)(lVar9 != 0);
  }
  _objc_release(lVar7);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return bVar5;
}



// -[DownloadMenuHelper showTranscriptSheet:withSender:], 0x109acc
/* Decompiled from supplied 5.2.2 arm package. VA 0x109acc. showTranscriptSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showTranscriptSheet_withSender_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined *puStack_230;
  undefined8 uStack_228;
  code *pcStack_220;
  undefined *puStack_218;
  undefined8 uStack_210;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  ID IStack_138;
  undefined *puStack_130;
  undefined1 *puStack_128;
  undefined8 uStack_120;
  long lStack_118;
  ID local_110;
  undefined8 uStack_108;
  undefined *puStack_100;
  undefined *puStack_f8;
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
  local_88 = &PTR__objc_msgSend_0118aef0;
  local_8c = (uint)(DAT_012271fc == 0);
  local_a0 = &PTR__objc_msgSend_0118af10;
  local_98 = &PTR_LAB_011882f0;
  local_b8 = &PTR_LAB_011882f0;
  ppuStack_b0 = &PTR_LAB_011882f0;
  local_c0 = &PTR_LAB_0118af38;
  local_d8 = &PTR__objc_msgSend_0118af58;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e8 = &PTR_LAB_0118af70;
  DAT_012271fc = 1;
  IStack_138 = param_4;
  local_110 = param_1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(activeVideo));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(availableCaptionTracks));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  uVar5 = _NSClassFromString(@"YTDefaultSheetController");
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(localizedStringForKey:value:table:),
                @"SelectCaption",0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uVar8,0,0,0);
  uStack_108 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar8);
  _objc_release(uVar7);
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  lStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  plStack_170 = (long *)0x0;
  uVar5 = _objc_retain(uVar6);
  puStack_130 = @selector(countByEnumeratingWithState:objects:count:);
  puStack_128 = auStack_200;
  uStack_120 = uVar6;
  lVar9 = _objc_msgSend(uVar5,@selector(countByEnumeratingWithState:objects:count:),&uStack_180,
                        auStack_200,0x10);
  uVar5 = DAT_00c4c228;
  uStack_a4 = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
LAB_0010a37c:
    uVar5 = uStack_120;
    _objc_release(uStack_120);
    uVar6 = uStack_108;
    IVar3 = IStack_138;
    _objc_msgSend(uStack_108,@selector(setSourceView:),IStack_138);
    _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(rootViewController));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(presentFromViewController:animated:completion:),uVar8,1,0);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(IVar3);
    CallSupervisor(0x268a);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(0x1a,0x1f,0,0);
    }
    return;
  }
  lStack_118 = *plStack_170;
LAB_0010a148:
  puVar2 = @selector(actionWithTitle:iconImage:style:handler:);
  puVar1 = @selector(addAction:);
  lVar11 = 0;
  puStack_100 = @selector(imageWithName:);
  puStack_f8 = @selector(titleForCaption:);
  uStack_c4 = (uint)(*plStack_170 == lStack_118);
  if (*plStack_170 == lStack_118) goto LAB_0010a218;
  do {
    _objc_enumerationMutation(uStack_120);
LAB_0010a218:
    do {
      uVar10 = *(undefined8 *)(lStack_178 + lVar11 * 8);
      uVar6 = _NSClassFromString(@"YTActionSheetAction");
      _objc_msgSend(local_110,puStack_f8,uVar10);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_100,
                    @"captions");
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puStack_230 = PTR___NSConcreteStackBlock_01060660;
      uStack_228 = uVar5;
      pcStack_220 = FUN_0010a480;
      puStack_218 = &DAT_010618c0;
      uStack_210 = uVar10;
      _objc_msgSend(uVar6,puVar2,uVar7,uVar8,0,&puStack_230);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_108,puVar1,uVar6);
      _objc_release(uVar6);
      _objc_release(uVar8);
      _objc_release(uVar7);
      bVar4 = lVar9 + -1 == lVar11;
      uStack_dc = (uint)bVar4;
      if (bVar4) {
        lVar9 = _objc_msgSend(uStack_120,puStack_130,&uStack_180,puStack_128,0x10);
        uStack_ec = (uint)(lVar9 == 0);
        if (lVar9 != 0) goto LAB_0010a148;
        uStack_ec = 1;
        goto LAB_0010a37c;
      }
      lVar11 = lVar11 + 1;
      uStack_c4 = (uint)(*plStack_170 == lStack_118);
    } while (*plStack_170 == lStack_118);
  } while( true );
}



// -[DownloadMenuHelper showCaptionsSheet:withSender:], 0x10a9c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x10a9c4. showCaptionsSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showCaptionsSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  long lVar13;
  undefined *puStack_290;
  undefined8 uStack_288;
  code *pcStack_280;
  undefined *puStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  ID IStack_260;
  undefined8 uStack_258;
  undefined1 auStack_250 [128];
  undefined8 uStack_1d0;
  long lStack_1c8;
  long *plStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  long lStack_190;
  ID IStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  long lStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ID local_150;
  ID local_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined *puStack_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_0118aff0;
  local_8c = (uint)(DAT_01227208 == 0);
  local_a0 = &PTR_LAB_0118b010;
  local_b0 = &PTR_LAB_0118b028;
  local_c0 = &PTR_LAB_0118b040;
  local_d0 = &PTR_LAB_0118b058;
  local_98 = &PTR_LAB_011882f0;
  local_e8 = &PTR_LAB_011882f0;
  ppuStack_e0 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_0118b080;
  local_108 = &PTR_LAB_0118b0a0;
  ppuStack_100 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_0118b0b8;
  local_128 = &PTR_LAB_011882f0;
  DAT_01227208 = 1;
  puStack_178 = auStack_250;
  local_150 = param_1;
  local_148 = param_4;
  _objc_retain(param_3);
  _objc_retain(local_148);
  puVar11 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_a4 = FUN_0011478c(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar10 = local_a0[uStack_a4] + (int)-(DAT_0118b020 ^ 0xce93a321);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_001145a4(param_3,puVar1,@selector(contentPlayerResponse));
    puVar10 = local_b0[uStack_b4] + (int)-(uRam000000000118b038 ^ 0x72dd04c);
    puVar11 = puVar2;
    if (uStack_b4 == 0) goto LAB_0010b500;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    lStack_190 = lVar5;
    _objc_msgSend(lVar5,@selector(videoID));
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    IStack_188 = param_3;
    _objc_msgSend(param_3,@selector(activeVideo));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(availableCaptionTracks));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(local_150,@selector(captionsForDownloading:),uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    uVar6 = _NSClassFromString(@"YTDefaultSheetController");
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(localizedStringForKey:value:table:),
                  @"SelectCaption",0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uVar9,0,0,0);
    uStack_160 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar9);
    _objc_release(uVar7);
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    uStack_1a0 = 0;
    lStack_1c8 = 0;
    uStack_1d0 = 0;
    uStack_1b8 = 0;
    plStack_1c0 = (long *)0x0;
    uVar6 = _objc_retain(uVar8);
    puStack_180 = @selector(countByEnumeratingWithState:objects:count:);
    uStack_170 = uVar8;
    lVar5 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),&uStack_1d0,
                          puStack_178,0x10);
    IVar3 = local_150;
    uVar7 = uStack_170;
    puVar10 = @selector(addAction:);
    uVar6 = DAT_00c4c228;
    uStack_d4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lStack_168 = *plStack_1c0;
      lVar13 = 0;
      puStack_130 = @selector(titleForCaption:);
      puStack_138 = @selector(imageWithName:);
      puStack_140 = @selector(actionWithTitle:iconImage:style:handler:);
      uStack_f4 = (uint)(*plStack_1c0 == lStack_168);
      if (*plStack_1c0 == lStack_168) goto LAB_0010b298;
      do {
        _objc_enumerationMutation(uStack_170);
LAB_0010b298:
        do {
          uVar12 = *(undefined8 *)(lStack_1c8 + lVar13 * 8);
          uVar7 = _NSClassFromString(@"YTActionSheetAction");
          _objc_msgSend(IVar3,puStack_130,uVar12);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_138,
                        @"captions");
          uVar9 = _objc_retainAutoreleasedReturnValue();
          puStack_290 = PTR___NSConcreteStackBlock_01060660;
          uStack_288 = uVar6;
          pcStack_280 = FUN_0010b56c;
          puStack_278 = &UNK_01062430;
          uStack_270 = uVar12;
          uStack_268 = _objc_retain(uStack_158);
          IStack_260 = IVar3;
          uStack_258 = _objc_retain(local_148);
          _objc_msgSend(uVar7,puStack_140,uVar8,uVar9,0,&puStack_290);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uStack_160,puVar10,uVar7);
          _objc_release(uVar7);
          _objc_release(uVar9);
          _objc_release(uVar8);
          _objc_release(uStack_258);
          _objc_release(uStack_268);
          bVar4 = lVar5 + -1 == lVar13;
          uStack_10c = (uint)bVar4;
          if (bVar4) {
            lVar5 = _objc_msgSend(uStack_170,puStack_180,&uStack_1d0,puStack_178,0x10);
            uStack_11c = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x0010b294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000118b0c8 ^ 0xe8c2702c)))();
            return;
          }
          lVar13 = lVar13 + 1;
          uStack_f4 = (uint)(*plStack_1c0 == lStack_168);
          uStack_10c = 0;
        } while (*plStack_1c0 == lStack_168);
      } while( true );
    }
    _objc_release(uStack_170);
    uVar6 = uStack_160;
    _objc_msgSend(uStack_160,@selector(setSourceView:),local_148);
    _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(rootViewController));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(presentFromViewController:animated:completion:),uVar9,1,0);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar7);
    _objc_release(uStack_158);
    _objc_release(lStack_190);
    param_3 = IStack_188;
  }
LAB_0010b500:
  _objc_release(local_148);
  _objc_release(param_3);
  CallSupervisor(0xb3d);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[DownloadMenuHelper captionsForDownloading:], 0x10b9a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x10b9a4. captionsForDownloading: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::captionsForDownloading_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  undefined *puStack_168;
  ID local_160;
  undefined *puStack_158;
  long lStack_150;
  undefined *puStack_148;
  undefined **local_140;
  uint uStack_134;
  undefined **local_130;
  undefined **local_120;
  undefined **local_110;
  undefined **ppuStack_108;
  undefined **local_f8;
  undefined **ppuStack_f0;
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
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118b120;
  local_7c = (uint)(DAT_01227214 == 0);
  local_90 = &PTR_LAB_0118b140;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118b168;
  local_c8 = &PTR_LAB_0118b188;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118b1a8;
  ppuStack_d8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_0118b1c8;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118b1e8;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118b200;
  local_130 = &PTR_LAB_0118b218;
  local_140 = &PTR_LAB_011882f0;
  DAT_01227214 = 1;
  local_160 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uStack_170 = _objc_retainAutoreleasedReturnValue();
  puStack_1b8 = (undefined8 *)0x0;
  uStack_1c0 = 0;
  uStack_1a8 = 0;
  plStack_1b0 = (long *)0x0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_188 = 0;
  uStack_190 = 0;
  uVar2 = _objc_retain(param_3);
  puStack_180 = @selector(countByEnumeratingWithState:objects:count:);
  puStack_178 = auStack_240;
  lStack_150 = _objc_msgSend(uVar2,@selector(countByEnumeratingWithState:objects:count:),&uStack_1c0,
                             auStack_240,0x10);
  puVar1 = @selector(VSSID);
  uStack_94 = (uint)(lStack_150 == 0);
  if (lStack_150 == 0) {
    _objc_release(local_160);
    uStack_134 = FUN_00114a10(@"addAutoCaps");
                    /* WARNING: Could not recover jumptable at 0x0010c0c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar3 = (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118b228 ^ 0x27aea731)))();
    return IVar3;
  }
  puStack_148 = @selector(hasPrefix:);
  puStack_168 = @selector(addObject:);
  lStack_150 = lStack_150 + -1;
  uStack_b4 = (uint)(*plStack_1b0 == *plStack_1b0);
  puStack_158 = @selector(VSSID);
  if (*plStack_1b0 != *plStack_1b0) {
    _objc_enumerationMutation(local_160);
  }
  _objc_msgSend(*puStack_1b8,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uStack_cc = FUN_00114ac0(uVar2,puStack_148,@"t.");
                    /* WARNING: Could not recover jumptable at 0x0010be40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_c8[uStack_cc] + (int)-(uRam000000000118b198 ^ 0x9679f7ad)))();
  return IVar3;
}



// -[DownloadMenuHelper titleForCaption:], 0x10c14c
/* Decompiled from supplied 5.2.2 arm package. VA 0x10c14c. titleForCaption: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::titleForCaption_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  
  DAT_01227218 = 1;
  uVar6 = _objc_retain(param_3);
  puVar2 = @selector(VSSID);
  _objc_msgSend(uVar6,@selector(VSSID));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(hasPrefix:);
  uVar4 = FUN_00114bd0(uVar6,@selector(hasPrefix:),
                       @"t.");
  _objc_release(uVar6);
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  if (uVar4 == 0) {
    _objc_msgSend((&PTR_LAB_0118b258)[uVar4] + (int)-(uRam000000000118b268 ^ 0x8eee428f),param_3,
                  puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar5 = FUN_00114ca4(uVar6,puVar1,@"ta.");
    _objc_release(uVar6);
    puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
    if (iVar5 == 0) {
      _objc_msgSend(param_3,@selector(displayName));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      goto LAB_0010c6fc;
    }
    _objc_msgSend(param_3,@selector(displayName));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(localizedStringForKey:value:table:),
                  @"TranslatedAutoGen",0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_00114d18(puVar1,@selector(stringWithFormat:),
                       @"%@ (%@)",uVar7,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_3,@selector(displayName));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(localizedStringForKey:value:table:),
                  @"Translated",0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_00114c44(puVar3,@selector(stringWithFormat:),
                       @"%@ (%@)",uVar7,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
LAB_0010c6fc:
  _objc_release(param_3);
  IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
  return IVar10;
}



// -[DownloadMenuHelper getCaptionsUrlSheet:sender:completion:], 0x10c720
/* Decompiled from supplied 5.2.2 arm package. VA 0x10c720. getCaptionsUrlSheet:sender:completion: */

/* Function Stack Size: 0x28 bytes */

void DownloadMenuHelper::getCaptionsUrlSheet_sender_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined8 uVar11;
  long lVar12;
  undefined *puStack_2a0;
  undefined8 uStack_298;
  code *pcStack_290;
  undefined *puStack_288;
  undefined8 uStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined1 auStack_260 [128];
  undefined8 uStack_1e0;
  long lStack_1d8;
  long *plStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  long lStack_198;
  ID IStack_190;
  ID IStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  long lStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ID IStack_150;
  ID local_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_0118b2a0;
  local_8c = (uint)(DAT_0122721c == 0);
  local_a0 = &PTR_LAB_0118b2c0;
  local_b0 = &PTR_LAB_0118b2d8;
  local_c0 = &PTR_LAB_0118b2f0;
  local_98 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118b310;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_011882f0;
  ppuStack_e8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_0118b338;
  local_110 = &PTR_LAB_0118b358;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118b370;
  local_130 = &PTR_LAB_011882f0;
  DAT_0122721c = 1;
  puStack_178 = auStack_260;
  local_148 = param_1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar10 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_a4 = FUN_00114f38(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar9 = local_a0[uStack_a4] + (int)-(DAT_0118b2d0 ^ 0x9e0e7da9);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_00115000(param_3,puVar1,@selector(contentPlayerResponse));
    puVar9 = local_b0[uStack_b4] + (int)-(uRam000000000118b2e8 ^ 0x23c74c4e);
    puVar10 = puVar2;
    if (uStack_b4 != 0) goto LAB_0010cd24;
  }
  else {
LAB_0010cd24:
    _objc_msgSend(puVar9,param_3,puVar10);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    if (lVar4 != 0) {
      lStack_198 = lVar4;
      IStack_190 = param_4;
      IStack_150 = param_5;
      _objc_msgSend(lVar4,@selector(videoID));
      uStack_158 = _objc_retainAutoreleasedReturnValue();
      IStack_188 = param_3;
      _objc_msgSend(param_3,@selector(activeVideo));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(availableCaptionTracks));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(local_148,@selector(captionsForDownloading:),uVar6);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar6);
      _objc_release(uVar5);
      uVar5 = _NSClassFromString(@"YTDefaultSheetController");
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(localizedStringForKey:value:table:),
                    @"SelectCaption",0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uVar8,0,0,0);
      uStack_160 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar6);
      uStack_1b8 = 0;
      uStack_1c0 = 0;
      uStack_1a8 = 0;
      uStack_1b0 = 0;
      lStack_1d8 = 0;
      uStack_1e0 = 0;
      uStack_1c8 = 0;
      plStack_1d0 = (long *)0x0;
      uVar5 = _objc_retain(uVar7);
      puStack_180 = @selector(countByEnumeratingWithState:objects:count:);
      uStack_170 = uVar7;
      lVar4 = _objc_msgSend(uVar5,@selector(countByEnumeratingWithState:objects:count:),&uStack_1e0,
                            puStack_178,0x10);
      uVar6 = uStack_170;
      puVar1 = @selector(actionWithTitle:iconImage:style:handler:);
      puVar9 = @selector(addAction:);
      uVar5 = DAT_00c4c228;
      uStack_dc = (uint)(lVar4 == 0);
      if (lVar4 != 0) {
        lStack_168 = *plStack_1d0;
        lVar12 = 0;
        puStack_138 = @selector(titleForCaption:);
        puStack_140 = @selector(imageWithName:);
        uStack_fc = (uint)(*plStack_1d0 == lStack_168);
        if (*plStack_1d0 == lStack_168) goto LAB_0010cfbc;
        do {
          _objc_enumerationMutation(uStack_170);
LAB_0010cfbc:
          do {
            uVar11 = *(undefined8 *)(lStack_1d8 + lVar12 * 8);
            uVar6 = _NSClassFromString(@"YTActionSheetAction");
            _objc_msgSend(local_148,puStack_138,uVar11);
            uVar7 = _objc_retainAutoreleasedReturnValue();
            _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_140,
                          @"captions");
            uVar8 = _objc_retainAutoreleasedReturnValue();
            puStack_2a0 = PTR___NSConcreteStackBlock_01060660;
            uStack_298 = uVar5;
            pcStack_290 = FUN_0010d304;
            puStack_288 = &DAT_01062490;
            uStack_280 = uVar11;
            uStack_278 = _objc_retain(uStack_158);
            uStack_270 = _objc_retain(IStack_150);
            _objc_msgSend(uVar6,puVar1,uVar7,uVar8,0,&puStack_2a0);
            uVar6 = _objc_retainAutoreleasedReturnValue();
            _objc_msgSend(uStack_160,puVar9,uVar6);
            _objc_release(uVar6);
            _objc_release(uVar8);
            _objc_release(uVar7);
            _objc_release(uStack_270);
            _objc_release(uStack_278);
            bVar3 = lVar4 + -1 == lVar12;
            uStack_114 = (uint)bVar3;
            if (bVar3) {
              lVar4 = _objc_msgSend(uStack_170,puStack_180,&uStack_1e0,puStack_178,0x10);
              uStack_124 = (uint)(lVar4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0010d1a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(local_120[uStack_124] + (int)-(DAT_0118b380 ^ 0x38915086)))();
              return;
            }
            lVar12 = lVar12 + 1;
            uStack_fc = (uint)(*plStack_1d0 == lStack_168);
            uStack_114 = 0;
          } while (*plStack_1d0 == lStack_168);
        } while( true );
      }
      _objc_release(uStack_170);
      uVar5 = uStack_160;
      param_4 = IStack_190;
      _objc_msgSend(uStack_160,@selector(setSourceView:),IStack_190);
      _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,@selector(rootViewController));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(presentFromViewController:animated:completion:),uVar8,1,0);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar5);
      _objc_release(uVar6);
      _objc_release(uStack_158);
      _objc_release(lStack_198);
      param_3 = IStack_188;
      param_5 = IStack_150;
      goto LAB_0010d294;
    }
  }
  (**(code **)(param_5 + 0x10))(param_5,0);
LAB_0010d294:
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x9c11);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[DownloadMenuHelper shareSRT:sourceView:], 0x10da34
/* Decompiled from supplied 5.2.2 arm package. VA 0x10da34. shareSRT:sourceView: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::shareSRT_sourceView_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *puStack_38;
  ID local_30;
  ID local_28;
  
  _objc_retain(param_3);
  _objc_retain(param_4);
  local_50 = PTR___NSConcreteStackBlock_01060660;
  local_48 = DAT_00c4c228;
  local_40 = FUN_0010daf0;
  puStack_38 = &DAT_01061f70;
  local_30 = param_3;
  local_28 = param_4;
  _objc_retain();
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_50);
  _objc_release(local_28);
  _objc_release(local_30);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x71b4);
  return;
}



// +[DownloadMenuHelper showDownloadSheetShorts:withSender:], 0xf5b28
/* Decompiled from supplied 5.2.2 arm package. VA 0xf5b28. showDownloadSheetShorts:withSender: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showDownloadSheetShorts_withSender_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined1 auStack_390 [48];
  undefined1 auStack_360 [64];
  undefined1 auStack_320 [200];
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  long lStack_218;
  undefined1 *puStack_210;
  undefined1 *puStack_208;
  undefined8 uStack_200;
  undefined *puStack_1e8;
  undefined1 *puStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  ID local_1c8;
  ID IStack_1c0;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **ppuStack_198;
  undefined **local_188;
  undefined **ppuStack_180;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_150;
  undefined **ppuStack_148;
  undefined **local_138;
  uint uStack_12c;
  undefined **local_128;
  undefined **ppuStack_120;
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
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_01189340;
  local_84 = (uint)(DAT_012270b8 == 0);
  local_a8 = &PTR_DAT_01189378;
  local_b8 = &PTR_LAB_01189390;
  local_c8 = &PTR_LAB_011893a8;
  local_e0 = &PTR_LAB_011893c8;
  local_98 = &PTR_LAB_01189360;
  ppuStack_90 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_011893e8;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_01189408;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_01189428;
  ppuStack_120 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_01189440;
  local_150 = &PTR_LAB_011882f0;
  ppuStack_148 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_01189468;
  local_170 = &PTR_LAB_01189488;
  ppuStack_168 = &PTR_LAB_011882f0;
  local_188 = &PTR_LAB_011894a8;
  ppuStack_180 = &PTR_LAB_011882f0;
  local_1a0 = &PTR_LAB_011894c8;
  ppuStack_198 = &PTR_LAB_011882f0;
  local_1b8 = &PTR_LAB_011882f0;
  ppuStack_1b0 = &PTR_LAB_011882f0;
  if (DAT_012270b8 == 0) {
    s_DownloadVideo_01185085[0] = DAT_01185077 ^ 0x74;
    s_DownloadVideo_01185085[1] = bRam0000000001185078 ^ 0x21;
    s_DownloadVideo_01185085[2] = bRam0000000001185079 ^ 0x87;
    s_DownloadVideo_01185085[3] = bRam000000000118507a ^ 0x32;
    s_DownloadVideo_01185085[4] = bRam000000000118507b ^ 0x6b;
    s_DownloadVideo_01185085[5] = bRam000000000118507c ^ 0x2d;
    s_DownloadVideo_01185085[6] = bRam000000000118507d ^ 0xbc;
    s_DownloadVideo_01185085[7] = bRam000000000118507e ^ 0xcc;
    s_DownloadVideo_01185085[8] = bRam000000000118507f ^ 0x6e;
    s_DownloadVideo_01185085[9] = bRam0000000001185080 ^ 0xf7;
    s_DownloadVideo_01185085[10] = bRam0000000001185081 ^ 0xb7;
    s_DownloadVideo_01185085[0xb] = bRam0000000001185082 ^ 0xeb;
    s_DownloadVideo_01185085[0xc] = bRam0000000001185083 ^ 0x51;
    s_DownloadVideo_01185085[0xd] = bRam0000000001185084 ^ 0x5a;
    s_FEshorts_0118506e[0] = DAT_01185065 ^ 0xf0;
    s_FEshorts_0118506e[1] = DAT_01185066 ^ 0x88;
    s_FEshorts_0118506e[2] = DAT_01185067 ^ 0xc9;
    s_FEshorts_0118506e[3] = DAT_01185068 ^ 0x91;
    s_FEshorts_0118506e[4] = DAT_01185069 ^ 0xf3;
    s_FEshorts_0118506e[5] = DAT_0118506a ^ 7;
    s_FEshorts_0118506e[6] = DAT_0118506b ^ 0xa8;
    s_FEshorts_0118506e[7] = DAT_0118506c ^ 199;
    s_FEshorts_0118506e[8] = DAT_0118506d ^ 0xdf;
    s_YTUIResources_01185057[0] = DAT_01185049 ^ 0x74;
    s_YTUIResources_01185057[1] = DAT_0118504a ^ 0x76;
    s_YTUIResources_01185057[2] = DAT_0118504b ^ 0xf0;
    s_YTUIResources_01185057[3] = DAT_0118504c ^ 0x57;
    s_YTUIResources_01185057[4] = DAT_0118504d ^ 5;
    s_YTUIResources_01185057[5] = DAT_0118504e ^ 0xc5;
    s_YTUIResources_01185057[6] = DAT_0118504f ^ 0x7f;
    s_YTUIResources_01185057[7] = DAT_01185050 ^ 0x93;
    s_YTUIResources_01185057[8] = DAT_01185051 ^ 0xe4;
    s_YTUIResources_01185057[9] = DAT_01185052 ^ 8;
    s_YTUIResources_01185057[10] = DAT_01185053 ^ 0x2d;
    s_YTUIResources_01185057[0xb] = DAT_01185054 ^ 0x86;
    s_YTUIResources_01185057[0xc] = DAT_01185055 ^ 0xb8;
    s_YTUIResources_01185057[0xd] = DAT_01185056 ^ 0x9b;
    s_fast_forward_01184fcd[0] = DAT_01184fc0 ^ 0x8c;
    s_fast_forward_01184fcd[1] = DAT_01184fc1 ^ 0xec;
    s_fast_forward_01184fcd[2] = DAT_01184fc2 ^ 0x97;
    s_fast_forward_01184fcd[3] = DAT_01184fc3 ^ 0x9a;
    s_fast_forward_01184fcd[4] = DAT_01184fc4 ^ 0x67;
    s_fast_forward_01184fcd[5] = DAT_01184fc5 ^ 0x40;
    s_fast_forward_01184fcd[6] = DAT_01184fc6 ^ 0xf1;
    s_fast_forward_01184fcd[7] = DAT_01184fc7 ^ 0x12;
    s_fast_forward_01184fcd[8] = DAT_01184fc8 ^ 0x9a;
    s_fast_forward_01184fcd[9] = DAT_01184fc9 ^ 0x43;
    s_fast_forward_01184fcd[10] = DAT_01184fca ^ 0x2b;
    s_fast_forward_01184fcd[0xb] = DAT_01184fcb ^ 0xbb;
    s_fast_forward_01184fcd[0xc] = DAT_01184fcc ^ 0xb6;
    s_image_01184fba[0] = DAT_01184fb4 ^ 0x5e;
    s_image_01184fba[1] = DAT_01184fb5 ^ 0xd3;
    s_image_01184fba[2] = DAT_01184fb6 ^ 0xb1;
    s_image_01184fba[3] = DAT_01184fb7 ^ 0x8f;
    s_image_01184fba[4] = DAT_01184fb8 ^ 0xe;
    s_image_01184fba[5] = DAT_01184fb9 ^ 0xf7;
    s_CopyInformation_01184fa4[0] = DAT_01184f94 ^ 0xa4;
    s_CopyInformation_01184fa4[1] = DAT_01184f95 ^ 0x2a;
    s_CopyInformation_01184fa4[2] = DAT_01184f96 ^ 0x8a;
    s_CopyInformation_01184fa4[3] = DAT_01184f97 ^ 0x72;
    s_CopyInformation_01184fa4[4] = DAT_01184f98 ^ 0x70;
    s_CopyInformation_01184fa4[5] = DAT_01184f99 ^ 0xeb;
    s_CopyInformation_01184fa4[6] = DAT_01184f9a ^ 0x1e;
    s_CopyInformation_01184fa4[7] = DAT_01184f9b ^ 0x72;
    s_CopyInformation_01184fa4[8] = DAT_01184f9c ^ 0xad;
    s_CopyInformation_01184fa4[9] = DAT_01184f9d ^ 0x89;
    s_CopyInformation_01184fa4[10] = DAT_01184f9e ^ 0xdb;
    s_CopyInformation_01184fa4[0xb] = DAT_01184f9f ^ 0x86;
    s_CopyInformation_01184fa4[0xc] = DAT_01184fa0 ^ 0xfe;
    s_CopyInformation_01184fa4[0xd] = DAT_01184fa1 ^ 0x4e;
    s_CopyInformation_01184fa4[0xe] = DAT_01184fa2 ^ 0x43;
    s_CopyInformation_01184fa4[0xf] = DAT_01184fa3 ^ 0x9b;
    s_SaveImage_01184fe4[0] = DAT_01184fda ^ 0xad;
    s_SaveImage_01184fe4[1] = DAT_01184fdb ^ 0x1c;
    param_2 = 0xcb;
    s_SaveImage_01184fe4[2] = DAT_01184fdc ^ 0xcb;
    s_SaveImage_01184fe4[3] = DAT_01184fdd ^ 0x1e;
    s_SaveImage_01184fe4[4] = DAT_01184fde ^ 0xa1;
    s_SaveImage_01184fe4[5] = DAT_01184fdf ^ 0x7f;
    s_SaveImage_01184fe4[6] = DAT_01184fe0 ^ 0x4b;
    s_SaveImage_01184fe4[7] = DAT_01184fe1 ^ 0xd6;
    s_SaveImage_01184fe4[8] = DAT_01184fe2 ^ 100;
    s_SaveImage_01184fe4[9] = DAT_01184fe3 ^ 0x65;
    s_YTActionSheetAction_01184f80[0] = DAT_01184f60 ^ 0xd6;
    s_YTActionSheetAction_01184f80[1] = DAT_01184f61 ^ 0x68;
    s_YTActionSheetAction_01184f80[2] = DAT_01184f62 ^ 0x48;
    s_YTActionSheetAction_01184f80[3] = DAT_01184f63 ^ 0xf;
    s_YTActionSheetAction_01184f80[4] = DAT_01184f64 ^ 0x9f;
    s_YTActionSheetAction_01184f80[5] = DAT_01184f65 ^ 0x9e;
    s_YTActionSheetAction_01184f80[6] = DAT_01184f66 ^ 0xca;
    s_YTActionSheetAction_01184f80[7] = DAT_01184f67 ^ 0x3a;
    s_YTActionSheetAction_01184f80[8] = DAT_01184f68 ^ 0x11;
    s_YTActionSheetAction_01184f80[9] = DAT_01184f69 ^ 0xad;
    s_YTActionSheetAction_01184f80[10] = DAT_01184f6a ^ 0x5c;
    s_YTActionSheetAction_01184f80[0xb] = DAT_01184f6b ^ 0x56;
    s_YTActionSheetAction_01184f80[0xc] = DAT_01184f6c ^ 0x2d;
    s_YTActionSheetAction_01184f80[0xd] = DAT_01184f6d ^ 0x20;
    s_YTActionSheetAction_01184f80[0xe] = DAT_01184f6e ^ 0xb;
    s_YTActionSheetAction_01184f80[0xf] = DAT_01184f6f ^ 0x66;
    s_YTActionSheetAction_01184f80[0x10] = DAT_01184f70 ^ 0x99;
    s_YTActionSheetAction_01184f80[0x11] = DAT_01184f71 ^ 0x70;
    s_YTActionSheetAction_01184f80[0x12] = DAT_01184f72 ^ 0xb3;
    s_YTActionSheetAction_01184f80[0x13] = DAT_01184f73 ^ 0x48;
    s_YTDefaultSheetController_01185030[0] = DAT_01185010 ^ 0x3b;
    s_YTDefaultSheetController_01185030[1] = DAT_01185011 ^ 0xb4;
    s_YTDefaultSheetController_01185030[2] = DAT_01185012 ^ 0x91;
    s_YTDefaultSheetController_01185030[3] = DAT_01185013 ^ 1;
    s_YTDefaultSheetController_01185030[4] = DAT_01185014 ^ 0xc;
    s_YTDefaultSheetController_01185030[5] = DAT_01185015 ^ 0x21;
    s_YTDefaultSheetController_01185030[6] = DAT_01185016 ^ 0xc3;
    s_YTDefaultSheetController_01185030[7] = DAT_01185017 ^ 0xd6;
    s_YTDefaultSheetController_01185030[8] = DAT_01185018 ^ 0xb8;
    s_YTDefaultSheetController_01185030[9] = DAT_01185019 ^ 0x4b;
    s_YTDefaultSheetController_01185030[10] = DAT_0118501a ^ 0x98;
    s_YTDefaultSheetController_01185030[0xb] = DAT_0118501b ^ 0x7a;
    s_YTDefaultSheetController_01185030[0xc] = DAT_0118501c ^ 0xe7;
    s_YTDefaultSheetController_01185030[0xd] = DAT_0118501d ^ 0x80;
    s_YTDefaultSheetController_01185030[0xe] = DAT_0118501e ^ 0xee;
    s_YTDefaultSheetController_01185030[0xf] = DAT_0118501f ^ 0x15;
    s_YTDefaultSheetController_01185030[0x10] = DAT_01185020 ^ 100;
    s_YTDefaultSheetController_01185030[0x11] = DAT_01185021 ^ 0xa5;
    s_YTDefaultSheetController_01185030[0x12] = DAT_01185022 ^ 0x40;
    s_YTDefaultSheetController_01185030[0x13] = DAT_01185023 ^ 0xb3;
    s_YTDefaultSheetController_01185030[0x14] = DAT_01185024 ^ 0x1f;
    s_YTDefaultSheetController_01185030[0x15] = DAT_01185025 ^ 0x56;
    s_YTDefaultSheetController_01185030[0x16] = DAT_01185026 ^ 0x46;
    s_YTDefaultSheetController_01185030[0x17] = DAT_01185027 ^ 0x6b;
    s_YTDefaultSheetController_01185030[0x18] = DAT_01185028 ^ 0x77;
    s_box_checkmark_01184e82[0] = DAT_01184e74 ^ 0xf9;
    s_box_checkmark_01184e82[1] = DAT_01184e75 ^ 0x49;
    s_box_checkmark_01184e82[2] = DAT_01184e76 ^ 0xc;
    s_box_checkmark_01184e82[3] = DAT_01184e77 ^ 0x8f;
    s_box_checkmark_01184e82[4] = DAT_01184e78 ^ 0x97;
    s_box_checkmark_01184e82[5] = DAT_01184e79 ^ 0xea;
    s_box_checkmark_01184e82[6] = DAT_01184e7a ^ 0x3a;
    s_box_checkmark_01184e82[7] = DAT_01184e7b ^ 0x5c;
    s_box_checkmark_01184e82[8] = DAT_01184e7c ^ 0xf1;
    s_box_checkmark_01184e82[9] = DAT_01184e7d ^ 0xf0;
    s_box_checkmark_01184e82[10] = DAT_01184e7e ^ 0xd6;
    s_box_checkmark_01184e82[0xb] = DAT_01184e7f ^ 0x18;
    s_box_checkmark_01184e82[0xc] = DAT_01184e80 ^ 0xd6;
    s_box_checkmark_01184e82[0xd] = DAT_01184e81 ^ 0xd5;
    s___01184f50._0_2_ = DAT_01184f4c ^ 0x525e;
    unique0x0003fe00 = DAT_01184f4e ^ 0xaaf0;
    s_AutoSkipShorts_01184f33[0] = DAT_01184f24 ^ 0xaa;
    s_AutoSkipShorts_01184f33[1] = DAT_01184f25 ^ 0xf0;
    s_AutoSkipShorts_01184f33[2] = DAT_01184f26 ^ 0x4a;
    s_AutoSkipShorts_01184f33[3] = DAT_01184f27 ^ 0x98;
    s_AutoSkipShorts_01184f33[4] = DAT_01184f28 ^ 0x53;
    s_AutoSkipShorts_01184f33[5] = DAT_01184f29 ^ 0xf5;
    s_AutoSkipShorts_01184f33[6] = DAT_01184f2a ^ 0x2c;
    s_AutoSkipShorts_01184f33[7] = DAT_01184f2b ^ 0x32;
    s_AutoSkipShorts_01184f33[8] = DAT_01184f2c ^ 0x57;
    s_AutoSkipShorts_01184f33[9] = DAT_01184f2d ^ 0xde;
    s_AutoSkipShorts_01184f33[10] = DAT_01184f2e ^ 0xa3;
    s_AutoSkipShorts_01184f33[0xb] = DAT_01184f2f ^ 0xd9;
    s_AutoSkipShorts_01184f33[0xc] = DAT_01184f30 ^ 0x88;
    s_AutoSkipShorts_01184f33[0xd] = DAT_01184f31 ^ 0xbb;
    s_AutoSkipShorts_01184f33[0xe] = DAT_01184f32 ^ 0x95;
    s_shortsPlaybackIndex_01184f10[0] = DAT_01184ef0 ^ 0x31;
    s_shortsPlaybackIndex_01184f10[1] = DAT_01184ef1 ^ 0x49;
    s_shortsPlaybackIndex_01184f10[2] = DAT_01184ef2 ^ 0xaa;
    s_shortsPlaybackIndex_01184f10[3] = DAT_01184ef3 ^ 0x5c;
    s_shortsPlaybackIndex_01184f10[4] = DAT_01184ef4 ^ 0x85;
    s_shortsPlaybackIndex_01184f10[5] = DAT_01184ef5 ^ 1;
    s_shortsPlaybackIndex_01184f10[6] = DAT_01184ef6 ^ 0x54;
    s_shortsPlaybackIndex_01184f10[7] = DAT_01184ef7 ^ 0x87;
    s_shortsPlaybackIndex_01184f10[8] = DAT_01184ef8 ^ 0xdb;
    s_shortsPlaybackIndex_01184f10[9] = DAT_01184ef9 ^ 0x29;
    s_shortsPlaybackIndex_01184f10[10] = DAT_01184efa ^ 1;
    s_shortsPlaybackIndex_01184f10[0xb] = DAT_01184efb ^ 0x78;
    s_shortsPlaybackIndex_01184f10[0xc] = DAT_01184efc ^ 0xd7;
    s_shortsPlaybackIndex_01184f10[0xd] = DAT_01184efd ^ 0x5f;
    s_shortsPlaybackIndex_01184f10[0xe] = DAT_01184efe ^ 0x86;
    s_shortsPlaybackIndex_01184f10[0xf] = DAT_01184eff ^ 0xa4;
    s_shortsPlaybackIndex_01184f10[0x10] = ~DAT_01184f00;
    s_shortsPlaybackIndex_01184f10[0x11] = DAT_01184f01 ^ 0xe4;
    s_shortsPlaybackIndex_01184f10[0x12] = DAT_01184f02 ^ 0xe0;
    s_shortsPlaybackIndex_01184f10[0x13] = DAT_01184f03 ^ 0xc3;
    s_copy_01184f47[0] = DAT_01184f42 ^ 0xa5;
    s_copy_01184f47[1] = DAT_01184f43 ^ 0x41;
    s_copy_01184f47[2] = DAT_01184f44 ^ 0x9e;
    s_copy_01184f47[3] = DAT_01184f45 ^ 0x76;
    s_copy_01184f47[4] = DAT_01184f46 ^ 0xa2;
    s_OpenAsRegularVideo_01184ed0[0] = DAT_01184eb0 ^ 0x17;
    s_OpenAsRegularVideo_01184ed0[1] = DAT_01184eb1 ^ 0xdd;
    s_OpenAsRegularVideo_01184ed0[2] = DAT_01184eb2 ^ 0xd6;
    s_OpenAsRegularVideo_01184ed0[3] = DAT_01184eb3 ^ 0xdb;
    s_OpenAsRegularVideo_01184ed0[4] = DAT_01184eb4 ^ 0x47;
    s_OpenAsRegularVideo_01184ed0[5] = DAT_01184eb5 ^ 0xab;
    s_OpenAsRegularVideo_01184ed0[6] = DAT_01184eb6 ^ 0x56;
    s_OpenAsRegularVideo_01184ed0[7] = DAT_01184eb7 ^ 0x6e;
    s_OpenAsRegularVideo_01184ed0[8] = DAT_01184eb8 ^ 0xeb;
    s_OpenAsRegularVideo_01184ed0[9] = DAT_01184eb9 ^ 0x34;
    s_OpenAsRegularVideo_01184ed0[10] = DAT_01184eba ^ 0x36;
    s_OpenAsRegularVideo_01184ed0[0xb] = DAT_01184ebb ^ 0x28;
    s_OpenAsRegularVideo_01184ed0[0xc] = DAT_01184ebc ^ 0x2f;
    s_OpenAsRegularVideo_01184ed0[0xd] = DAT_01184ebd ^ 0xee;
    s_OpenAsRegularVideo_01184ed0[0xe] = DAT_01184ebe ^ 0xf3;
    s_OpenAsRegularVideo_01184ed0[0xf] = DAT_01184ebf ^ 0xe4;
    s_OpenAsRegularVideo_01184ed0[0x10] = DAT_01184ec0 ^ 0xae;
    s_OpenAsRegularVideo_01184ed0[0x11] = DAT_01184ec1 ^ 0x6d;
    s_OpenAsRegularVideo_01184ed0[0x12] = DAT_01184ec2 ^ 0x80;
    s_youtube_logo_01184e9d[0] = DAT_01184e90 ^ 0xab;
    s_youtube_logo_01184e9d[1] = DAT_01184e91 ^ 0xca;
    s_youtube_logo_01184e9d[2] = DAT_01184e92 ^ 0xb7;
    s_youtube_logo_01184e9d[3] = DAT_01184e93 ^ 0xcb;
    s_youtube_logo_01184e9d[4] = DAT_01184e94 ^ 0x39;
    s_youtube_logo_01184e9d[5] = DAT_01184e95 ^ 0x59;
    s_youtube_logo_01184e9d[6] = DAT_01184e96 ^ 0x7d;
    s_youtube_logo_01184e9d[7] = DAT_01184e97 ^ 0xd5;
    s_youtube_logo_01184e9d[8] = DAT_01184e98 ^ 0xea;
    s_youtube_logo_01184e9d[9] = DAT_01184e99 ^ 0xe4;
    s_youtube_logo_01184e9d[10] = DAT_01184e9a ^ 0x8e;
    s_youtube_logo_01184e9d[0xb] = DAT_01184e9b ^ 0x42;
    s_youtube_logo_01184e9d[0xc] = DAT_01184e9c ^ 0x7c;
    s__headerView_01184ffa[0] = DAT_01184fee ^ 0xa3;
    s__headerView_01184ffa[1] = DAT_01184fef ^ 0xc1;
    s__headerView_01184ffa[2] = DAT_01184ff0 ^ 0xba;
    s__headerView_01184ffa[3] = DAT_01184ff1 ^ 0xeb;
    s__headerView_01184ffa[4] = DAT_01184ff2 ^ 0xae;
    s__headerView_01184ffa[5] = DAT_01184ff3 ^ 9;
    s__headerView_01184ffa[6] = DAT_01184ff4 ^ 0x2a;
    s__headerView_01184ffa[7] = DAT_01184ff5 ^ 0x1a;
    s__headerView_01184ffa[8] = DAT_01184ff6 ^ 0xf4;
    s__headerView_01184ffa[9] = DAT_01184ff7 ^ 0x53;
    s__headerView_01184ffa[10] = DAT_01184ff8 ^ 0xe9;
    s__headerView_01184ffa[0xb] = DAT_01184ff9 ^ 0x51;
    s_box_empty_01184e6a[0] = DAT_01184e60 ^ 0x5b;
    s_box_empty_01184e6a[1] = DAT_01184e61 ^ 0x83;
    s_box_empty_01184e6a[2] = DAT_01184e62 ^ 0x41;
    s_box_empty_01184e6a[3] = DAT_01184e63 ^ 0x18;
    s_box_empty_01184e6a[4] = DAT_01184e64 ^ 0xa6;
    s_box_empty_01184e6a[5] = DAT_01184e65 ^ 0x57;
    s_box_empty_01184e6a[6] = DAT_01184e66 ^ 0x90;
    s_box_empty_01184e6a[7] = DAT_01184e67 ^ 0x86;
    s_box_empty_01184e6a[8] = DAT_01184e68 ^ 0xf0;
    s_box_empty_01184e6a[9] = DAT_01184e69 ^ 0x33;
  }
  DAT_012270b8 = 1;
  puStack_1e0 = auStack_390;
  local_1c8 = param_4;
  IStack_1c0 = param_3;
  _objc_retain(param_3,param_2);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar4 = _objc_alloc_init(PTR_DownloadMenuHelper_0114ed78);
  puVar11 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_9c = FUN_0010e294(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar10 = local_98[uStack_9c] + (int)-(DAT_01189370 ^ 0x65b3186);
  if (uStack_9c == 0) {
    uStack_ac = FUN_0010e24c(param_3,puVar1,@selector(contentPlayerResponse));
    puVar10 = local_a8[uStack_ac] + (int)-(uRam0000000001189388 ^ 0x4619b873);
    puVar11 = puVar2;
    if (uStack_ac == 0) goto LAB_000f798c;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lStack_218 = _objc_retainAutoreleasedReturnValue();
  uStack_bc = (uint)(lStack_218 == 0);
  puVar10 = local_b8[uStack_bc] + (int)-(uRam00000000011893a0 ^ 0x2ccb8081);
  if (lStack_218 != 0) {
    puStack_210 = auStack_360;
    puStack_208 = auStack_320;
    _objc_msgSend(lStack_218,@selector(videoID));
    uStack_220 = _objc_retainAutoreleasedReturnValue();
    puVar10 = @selector(playerData);
    _objc_msgSend(lStack_218,@selector(playerData));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(videoDetails);
    _objc_msgSend(uVar5,@selector(videoDetails));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(title));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puStack_1e8 = puVar10;
    _objc_msgSend(lStack_218,puVar10);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(author));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_release(uVar6);
    puVar10 = @selector(length);
    uVar9 = _objc_msgSend(uVar5,@selector(length));
    uStack_cc = (uint)(0x1e < uVar9);
    if (0x1e < uVar9) {
      _objc_msgSend(local_c8[uStack_cc] + (int)-(DAT_011893b8 ^ 0x2cb6e6fa),uVar5,
                    @selector(substringToIndex:),0x1e);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_01185440);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
      _objc_release(uVar6);
      uVar5 = uVar8;
    }
    uStack_200 = uVar5;
    uVar9 = _objc_msgSend(uVar7,puVar10);
    uStack_e4 = (uint)(200 < uVar9);
    if (200 < uVar9) {
      _objc_msgSend(local_e0[uStack_e4] + (int)-(uRam00000000011893d8 ^ 0x39acfa13),uVar7,
                    @selector(substringToIndex:),200);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_01185440);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar7);
      _objc_release(uVar5);
      uVar7 = uVar6;
    }
    _objc_msgSend(uVar4,@selector(getVideoFormatsArray:isShorts:),param_3,1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(getAudioFormatsArray:),param_3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_250 = uVar5;
    _objc_msgSend(uVar5,@selector(objectAtIndexedSubscript:),0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_230 = uVar6;
    _objc_msgSend(uVar4,@selector(getBestAudioFormat:playerVC:),uVar6,param_3);
    uStack_240 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,@selector(activeVideo));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(selectedAudioFormat));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(audioTrack));
    _objc_retainAutoreleasedReturnValue();
    _objc_release();
    _objc_release(uVar8);
    _objc_release(uVar6);
    uStack_238 = uVar5;
    uVar5 = _objc_msgSend(uVar5,@selector(contentLength));
    _objc_msgSend(PTR__OBJC_CLASS___NSByteCountFormatter_0114edf0,
                  @selector(stringFromByteCount:countStyle:),uVar5,0);
    uStack_248 = _objc_retainAutoreleasedReturnValue();
    uStack_fc = (uint)(DAT_01227090 == 0);
    uStack_228 = uVar7;
    if (DAT_01227090 == 0) {
      DAT_01227090 = _objc_getClass(local_f8[uStack_fc] + (int)-(uRam00000000011893f8 ^ 0x83994ea),
                                    s_YTDefaultSheetController_01185030);
    }
    uVar5 = _objc_retainAutorelease();
    _objc_msgSend(uVar5,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uStack_200,uVar7,0,0);
    uStack_1d0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_1d0,@selector(valueForKey:),
                  @"_headerView");
    uStack_258 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_258,@selector(showHeaderDivider));
    uStack_114 = (uint)(lRam0000000001227098 == 0);
    if (lRam0000000001227098 == 0) {
      lRam0000000001227098 =
           _objc_getClass(local_110[uStack_114] + (int)-(uRam0000000001189418 ^ 0x650d1aad),
                          s_YTUIResources_01185057);
    }
    uVar5 = _objc_retainAutorelease();
    _objc_msgSend(uVar5,@selector(chevronRightImage));
    uStack_1d8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_1d8,@selector(setFlipsForRightToLeftLayoutDirection:),1);
    _objc_msgSend(lStack_218,puStack_1e8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_0010e59c(uVar5,@selector(isLivePlayback));
    _objc_release(uVar5);
    puStack_1e8 = (undefined *)uVar4;
    uStack_12c = uVar3;
                    /* WARNING: Could not recover jumptable at 0x000f705c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_128[uVar3] + (int)-(uRam0000000001189438 ^ 0x429ef5dd)))();
    return;
  }
  uStack_bc = 1;
LAB_000f798c:
  _objc_release(puVar10,uVar4);
  _objc_release(param_3);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xcb16);
  return;
}



// +[DownloadMenuHelper showDownloadSheet:withSender:], 0xf83b8
/* Decompiled from supplied 5.2.2 arm package. VA 0xf83b8. showDownloadSheet:withSender: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showDownloadSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStack_470 [112];
  undefined1 auStack_400 [64];
  undefined1 auStack_3c0 [64];
  undefined1 auStack_380 [64];
  undefined1 auStack_340 [140];
  uint uStack_2b4;
  undefined1 *puStack_2b0;
  undefined *puStack_2a8;
  undefined8 uStack_2a0;
  undefined8 uStack_298;
  undefined8 uStack_290;
  undefined8 uStack_288;
  undefined *puStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined1 *puStack_268;
  undefined1 *puStack_260;
  undefined1 *puStack_258;
  undefined8 uStack_248;
  long lStack_240;
  undefined1 *puStack_218;
  ID IStack_210;
  undefined8 uStack_208;
  undefined **local_200;
  undefined **local_1f8;
  undefined **ppuStack_1f0;
  undefined **local_1e0;
  undefined **local_1d0;
  undefined **ppuStack_1c8;
  undefined **local_1b8;
  undefined **local_1b0;
  undefined **ppuStack_1a8;
  undefined **local_198;
  undefined **local_188;
  undefined **ppuStack_180;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_150;
  undefined **ppuStack_148;
  undefined **local_138;
  uint uStack_12c;
  undefined **local_128;
  undefined **ppuStack_120;
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
  
  local_80 = &PTR_LAB_01189598;
  local_84 = (uint)(DAT_012270ec == 0);
  local_98 = &PTR_LAB_011895b8;
  local_a8 = &PTR_LAB_011895d0;
  local_b8 = &PTR_LAB_011895e8;
  local_c8 = &PTR_LAB_01189600;
  local_e0 = &PTR_LAB_01189620;
  local_90 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_01189640;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_01189660;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_01189680;
  ppuStack_120 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_01189698;
  local_150 = &PTR_LAB_011882f0;
  ppuStack_148 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_011896c0;
  local_170 = &PTR_LAB_011896e0;
  ppuStack_168 = &PTR_LAB_011882f0;
  local_188 = &PTR_LAB_01189700;
  ppuStack_180 = &PTR_LAB_011882f0;
  local_198 = &PTR_LAB_01189718;
  local_1b0 = &PTR_LAB_011882f0;
  ppuStack_1a8 = &PTR_LAB_011882f0;
  local_1b8 = &PTR_LAB_01189740;
  local_1d0 = &PTR_LAB_01189760;
  ppuStack_1c8 = &PTR_LAB_011882f0;
  local_1e0 = &PTR_LAB_01189778;
  local_1f8 = &PTR_LAB_011882f0;
  ppuStack_1f0 = &PTR_LAB_011882f0;
  local_200 = &PTR_LAB_011882f0;
  if (DAT_012270ec == 0) {
    s_DownloadVideo_01185763[0] = DAT_01185755 ^ 0x14;
    s_DownloadVideo_01185763[1] = bRam0000000001185756 ^ 0xac;
    s_DownloadVideo_01185763[2] = bRam0000000001185757 ^ 0x1b;
    s_DownloadVideo_01185763[3] = bRam0000000001185758 ^ 0xc0;
    s_DownloadVideo_01185763[4] = bRam0000000001185759 ^ 0xd7;
    s_DownloadVideo_01185763[5] = bRam000000000118575a ^ 0x5b;
    s_DownloadVideo_01185763[6] = bRam000000000118575b ^ 0x76;
    s_DownloadVideo_01185763[7] = bRam000000000118575c ^ 0xb5;
    s_DownloadVideo_01185763[8] = bRam000000000118575d ^ 0x44;
    s_DownloadVideo_01185763[9] = bRam000000000118575e ^ 0xd9;
    s_DownloadVideo_01185763[10] = bRam000000000118575f ^ 0x67;
    s_DownloadVideo_01185763[0xb] = bRam0000000001185760 ^ 0xd5;
    s_DownloadVideo_01185763[0xc] = bRam0000000001185761 ^ 0xe0;
    s_DownloadVideo_01185763[0xd] = bRam0000000001185762 ^ 0x98;
    s_YTDefaultSheetController_01185720[0] = bRam0000000001185700 ^ 0xb2;
    s_YTDefaultSheetController_01185720[1] = bRam0000000001185701 ^ 0xdb;
    s_YTDefaultSheetController_01185720[2] = bRam0000000001185702 ^ 0x1e;
    s_YTDefaultSheetController_01185720[3] = bRam0000000001185703 ^ 0x3a;
    s_YTDefaultSheetController_01185720[4] = bRam0000000001185704 ^ 0x1b;
    s_YTDefaultSheetController_01185720[5] = bRam0000000001185705 ^ 0xd2;
    s_YTDefaultSheetController_01185720[6] = bRam0000000001185706 ^ 0x79;
    s_YTDefaultSheetController_01185720[7] = bRam0000000001185707 ^ 0x48;
    s_YTDefaultSheetController_01185720[8] = bRam0000000001185708 ^ 0x28;
    s_YTDefaultSheetController_01185720[9] = bRam0000000001185709 ^ 0x2f;
    s_YTDefaultSheetController_01185720[10] = bRam000000000118570a ^ 0x1e;
    s_YTDefaultSheetController_01185720[0xb] = bRam000000000118570b ^ 0xf9;
    s_YTDefaultSheetController_01185720[0xc] = bRam000000000118570c ^ 0xba;
    s_YTDefaultSheetController_01185720[0xd] = bRam000000000118570d ^ 10;
    s_YTDefaultSheetController_01185720[0xe] = bRam000000000118570e ^ 0xd2;
    s_YTDefaultSheetController_01185720[0xf] = bRam000000000118570f ^ 0x8b;
    s_YTDefaultSheetController_01185720[0x10] = bRam0000000001185710 ^ 0x68;
    s_YTDefaultSheetController_01185720[0x11] = bRam0000000001185711 ^ 0x71;
    s_YTDefaultSheetController_01185720[0x12] = bRam0000000001185712 ^ 0x9d;
    s_YTDefaultSheetController_01185720[0x13] = bRam0000000001185713 ^ 0x7c;
    s_YTDefaultSheetController_01185720[0x14] = bRam0000000001185714 ^ 0x30;
    s_YTDefaultSheetController_01185720[0x15] = bRam0000000001185715 ^ 0x92;
    s_YTDefaultSheetController_01185720[0x16] = bRam0000000001185716 ^ 0x98;
    s_YTDefaultSheetController_01185720[0x17] = bRam0000000001185717 ^ 0xaa;
    s_YTDefaultSheetController_01185720[0x18] = bRam0000000001185718 ^ 0xd3;
    s_captions_011856db[0] = DAT_011856d2 ^ 0x32;
    s_captions_011856db[1] = bRam00000000011856d3 ^ 200;
    s_captions_011856db[2] = bRam00000000011856d4 ^ 0x68;
    s_captions_011856db[3] = bRam00000000011856d5 ^ 0xa1;
    s_captions_011856db[4] = bRam00000000011856d6 ^ 0x6c;
    s_captions_011856db[5] = bRam00000000011856d7 ^ 0xbf;
    s_captions_011856db[6] = bRam00000000011856d8 ^ 0xdd;
    s_captions_011856db[7] = bRam00000000011856d9 ^ 0xaa;
    s_captions_011856db[8] = bRam00000000011856da ^ 0x77;
    s_SaveImage_011856c8[0] = DAT_011856be ^ 0x4a;
    s_SaveImage_011856c8[1] = bRam00000000011856bf ^ 0x91;
    s_SaveImage_011856c8[2] = bRam00000000011856c0 ^ 0x87;
    s_SaveImage_011856c8[3] = bRam00000000011856c1 ^ 0x67;
    s_SaveImage_011856c8[4] = bRam00000000011856c2 ^ 0x7a;
    s_SaveImage_011856c8[5] = bRam00000000011856c3 ^ 0x33;
    s_SaveImage_011856c8[6] = bRam00000000011856c4 ^ 0xfb;
    s_SaveImage_011856c8[7] = bRam00000000011856c5 ^ 0xb7;
    s_SaveImage_011856c8[8] = bRam00000000011856c6 ^ 0x6f;
    s_SaveImage_011856c8[9] = bRam00000000011856c7 ^ 0xb5;
    s_player_011856b7[0] = DAT_011856b0 ^ 0x4f;
    s_player_011856b7[1] = bRam00000000011856b1 ^ 0x91;
    s_player_011856b7[2] = bRam00000000011856b2 ^ 0xbb;
    s_player_011856b7[3] = bRam00000000011856b3 ^ 0xd4;
    s_player_011856b7[4] = bRam00000000011856b4 ^ 0x66;
    s_player_011856b7[5] = bRam00000000011856b5 ^ 0x8d;
    s_player_011856b7[6] = bRam00000000011856b6 ^ 0x67;
    s_copy_01185636[0] = DAT_01185631 ^ 0xb5;
    s_copy_01185636[1] = bRam0000000001185632 ^ 0xd3;
    s_copy_01185636[2] = bRam0000000001185633 ^ 0x2c;
    s_copy_01185636[3] = bRam0000000001185634 ^ 0x40;
    s_copy_01185636[4] = bRam0000000001185635 ^ 0xf0;
    s___01185640._0_2_ = _DAT_0118563c ^ 0x5f46;
    unique0x0003fe00 = uRam000000000118563e ^ 0xb979;
    s_CopyInformation_01185694[0] = DAT_01185684 ^ 0x27;
    s_CopyInformation_01185694[1] = bRam0000000001185685 ^ 0xd5;
    s_CopyInformation_01185694[2] = bRam0000000001185686 ^ 0x88;
    s_CopyInformation_01185694[3] = bRam0000000001185687 ^ 0x81;
    s_CopyInformation_01185694[4] = bRam0000000001185688 ^ 0x14;
    s_CopyInformation_01185694[5] = bRam0000000001185689 ^ 0x2b;
    s_CopyInformation_01185694[6] = bRam000000000118568a ^ 0x31;
    s_CopyInformation_01185694[7] = bRam000000000118568b ^ 0xfd;
    s_CopyInformation_01185694[8] = bRam000000000118568c ^ 0xb4;
    s_CopyInformation_01185694[9] = bRam000000000118568d ^ 99;
    s_CopyInformation_01185694[10] = bRam000000000118568e ^ 0x5a;
    s_CopyInformation_01185694[0xb] = bRam000000000118568f ^ 0x6e;
    s_CopyInformation_01185694[0xc] = bRam0000000001185690 ^ 0xde;
    s_CopyInformation_01185694[0xd] = bRam0000000001185691 ^ 200;
    s_CopyInformation_01185694[0xe] = bRam0000000001185692 ^ 0x84;
    s_CopyInformation_01185694[0xf] = bRam0000000001185693 ^ 0x93;
    s_YTActionSheetAction_01185670[0] = bRam0000000001185650 ^ 0x7d;
    s_YTActionSheetAction_01185670[1] = bRam0000000001185651 ^ 0xa2;
    s_YTActionSheetAction_01185670[2] = bRam0000000001185652 ^ 0x35;
    s_YTActionSheetAction_01185670[3] = bRam0000000001185653 ^ 7;
    s_YTActionSheetAction_01185670[4] = bRam0000000001185654 ^ 0x34;
    s_YTActionSheetAction_01185670[5] = bRam0000000001185655 ^ 0xb4;
    s_YTActionSheetAction_01185670[6] = bRam0000000001185656 ^ 0x60;
    s_YTActionSheetAction_01185670[7] = bRam0000000001185657 ^ 0x27;
    s_YTActionSheetAction_01185670[8] = bRam0000000001185658 ^ 0xa7;
    s_YTActionSheetAction_01185670[9] = ~bRam0000000001185659;
    s_YTActionSheetAction_01185670[10] = bRam000000000118565a ^ 0xc2;
    s_YTActionSheetAction_01185670[0xb] = bRam000000000118565b ^ 0x88;
    s_YTActionSheetAction_01185670[0xc] = bRam000000000118565c ^ 0x20;
    s_YTActionSheetAction_01185670[0xd] = bRam000000000118565d ^ 0x7b;
    s_YTActionSheetAction_01185670[0xe] = bRam000000000118565e ^ 0x93;
    s_YTActionSheetAction_01185670[0xf] = bRam000000000118565f ^ 0x16;
    s_YTActionSheetAction_01185670[0x10] = bRam0000000001185660 ^ 0xf7;
    s_YTActionSheetAction_01185670[0x11] = bRam0000000001185661 ^ 0xb6;
    s_YTActionSheetAction_01185670[0x12] = bRam0000000001185662 ^ 0xe1;
    s_YTActionSheetAction_01185670[0x13] = bRam0000000001185663 ^ 0x99;
    s_DownloadCaptions_01185620[0] = DAT_01185600 ^ 100;
    s_DownloadCaptions_01185620[1] = bRam0000000001185601 ^ 0xec;
    s_DownloadCaptions_01185620[2] = bRam0000000001185602 ^ 0x73;
    s_DownloadCaptions_01185620[3] = bRam0000000001185603 ^ 0x45;
    s_DownloadCaptions_01185620[4] = bRam0000000001185604 ^ 0x9e;
    s_DownloadCaptions_01185620[5] = bRam0000000001185605 ^ 0x96;
    s_DownloadCaptions_01185620[6] = bRam0000000001185606 ^ 0xcd;
    s_DownloadCaptions_01185620[7] = ~bRam0000000001185607;
    s_DownloadCaptions_01185620[8] = bRam0000000001185608 ^ 0x2e;
    s_DownloadCaptions_01185620[9] = bRam0000000001185609 ^ 0x66;
    s_DownloadCaptions_01185620[10] = bRam000000000118560a ^ 0xf4;
    s_DownloadCaptions_01185620[0xb] = ~bRam000000000118560b;
    s_DownloadCaptions_01185620[0xc] = bRam000000000118560c ^ 0x5c;
    s_DownloadCaptions_01185620[0xd] = bRam000000000118560d ^ 0xb;
    s_DownloadCaptions_01185620[0xe] = bRam000000000118560e ^ 0x7c;
    s_DownloadCaptions_01185620[0xf] = bRam000000000118560f ^ 0xe1;
    s_DownloadCaptions_01185620[0x10] = bRam0000000001185610 ^ 0xaf;
    s_YTUIResources_01185747[0] = DAT_01185739 ^ 0x9b;
    s_YTUIResources_01185747[1] = DAT_0118573a ^ 0xd1;
    s_YTUIResources_01185747[2] = DAT_0118573b ^ 0x23;
    s_YTUIResources_01185747[3] = DAT_0118573c ^ 0x91;
    s_YTUIResources_01185747[4] = DAT_0118573d ^ 0xe1;
    s_YTUIResources_01185747[5] = DAT_0118573e ^ 0x1f;
    s_YTUIResources_01185747[6] = DAT_0118573f ^ 0xc3;
    s_YTUIResources_01185747[7] = DAT_01185740 ^ 0x21;
    s_YTUIResources_01185747[8] = DAT_01185741 ^ 0xd3;
    s_YTUIResources_01185747[9] = DAT_01185742 ^ 2;
    s_YTUIResources_01185747[10] = DAT_01185743 ^ 0x97;
    s_YTUIResources_01185747[0xb] = DAT_01185744 ^ 0x94;
    s_YTUIResources_01185747[0xc] = DAT_01185745 ^ 0x4d;
    s_YTUIResources_01185747[0xd] = DAT_01185746 ^ 0xec;
    s__headerView_011856f0[0] = DAT_011856e4 ^ 0xa4;
    s__headerView_011856f0[1] = DAT_011856e5 ^ 0x1a;
    s__headerView_011856f0[2] = DAT_011856e6 ^ 0x66;
    s__headerView_011856f0[3] = DAT_011856e7 ^ 0xb1;
    s__headerView_011856f0[4] = DAT_011856e8 ^ 0x83;
    s__headerView_011856f0[5] = DAT_011856e9 ^ 0x51;
    s__headerView_011856f0[6] = DAT_011856ea ^ 0xbb;
    s__headerView_011856f0[7] = DAT_011856eb ^ 0x7d;
    s__headerView_011856f0[8] = DAT_011856ec ^ 0x6d;
    s__headerView_011856f0[9] = DAT_011856ed ^ 0x77;
    s__headerView_011856f0[10] = DAT_011856ee ^ 0x62;
    s__headerView_011856f0[0xb] = DAT_011856ef ^ 0xd3;
    s_music_011855ba[0] = DAT_011855b4 ^ 0x23;
    s_music_011855ba[1] = DAT_011855b5 ^ 0xa9;
    s_music_011855ba[2] = DAT_011855b6 ^ 0x16;
    s_music_011855ba[3] = DAT_011855b7 ^ 0xdf;
    s_music_011855ba[4] = DAT_011855b8 ^ 0xdd;
    s_music_011855ba[5] = DAT_011855b9 ^ 0xb2;
    s_PlayInExternalPlayer_011855e0[0] = DAT_011855c0 ^ 0x23;
    s_PlayInExternalPlayer_011855e0[1] = DAT_011855c1 ^ 9;
    s_PlayInExternalPlayer_011855e0[2] = DAT_011855c2 ^ 0xd5;
    s_PlayInExternalPlayer_011855e0[3] = DAT_011855c3 ^ 0x88;
    s_PlayInExternalPlayer_011855e0[4] = DAT_011855c4 ^ 0x67;
    s_PlayInExternalPlayer_011855e0[5] = DAT_011855c5 ^ 0x52;
    s_PlayInExternalPlayer_011855e0[6] = DAT_011855c6 ^ 0x1d;
    s_PlayInExternalPlayer_011855e0[7] = DAT_011855c7 ^ 0x53;
    s_PlayInExternalPlayer_011855e0[8] = DAT_011855c8 ^ 200;
    s_PlayInExternalPlayer_011855e0[9] = DAT_011855c9 ^ 0xbc;
    s_PlayInExternalPlayer_011855e0[10] = DAT_011855ca ^ 0x9f;
    s_PlayInExternalPlayer_011855e0[0xb] = DAT_011855cb ^ 0x39;
    s_PlayInExternalPlayer_011855e0[0xc] = DAT_011855cc ^ 0xfa;
    s_PlayInExternalPlayer_011855e0[0xd] = DAT_011855cd ^ 0x56;
    s_PlayInExternalPlayer_011855e0[0xe] = DAT_011855ce ^ 0x38;
    s_PlayInExternalPlayer_011855e0[0xf] = DAT_011855cf ^ 0x77;
    s_PlayInExternalPlayer_011855e0[0x10] = DAT_011855d0 ^ 0xcf;
    s_PlayInExternalPlayer_011855e0[0x11] = DAT_011855d1 ^ 0xbe;
    s_PlayInExternalPlayer_011855e0[0x12] = DAT_011855d2 ^ 0x7d;
    s_PlayInExternalPlayer_011855e0[0x13] = DAT_011855d3 ^ 0x43;
    s_PlayInExternalPlayer_011855e0[0x14] = DAT_011855d4 ^ 0x4d;
    s_image_011856aa[0] = DAT_011856a4 ^ 10;
    s_image_011856aa[1] = DAT_011856a5 ^ 0x8b;
    s_image_011856aa[2] = DAT_011856a6 ^ 0x60;
    s_image_011856aa[3] = DAT_011856a7 ^ 0x30;
    s_image_011856aa[4] = DAT_011856a8 ^ 0xbf;
    s_image_011856aa[5] = DAT_011856a9 ^ 0x5f;
    s_play_circle_011855a8[0] = DAT_0118559c ^ 0x81;
    s_play_circle_011855a8[1] = DAT_0118559d ^ 0x49;
    s_play_circle_011855a8[2] = DAT_0118559e ^ 0xea;
    s_play_circle_011855a8[3] = DAT_0118559f ^ 0x94;
    s_play_circle_011855a8[4] = DAT_011855a0 ^ 0x95;
    s_play_circle_011855a8[5] = DAT_011855a1 ^ 0xfd;
    param_2 = 0x54;
    s_play_circle_011855a8[6] = DAT_011855a2 ^ 0x54;
    s_play_circle_011855a8[7] = DAT_011855a3 ^ 0x5f;
    s_play_circle_011855a8[8] = DAT_011855a4 ^ 0xfd;
    s_play_circle_011855a8[9] = DAT_011855a5 ^ 0xea;
    s_play_circle_011855a8[10] = DAT_011855a6 ^ 199;
    s_play_circle_011855a8[0xb] = DAT_011855a7 ^ 0xaa;
    s_DownloadAudio_0118558e[0] = DAT_01185580 ^ 0x48;
    s_DownloadAudio_0118558e[1] = DAT_01185581 ^ 0x5b;
    s_DownloadAudio_0118558e[2] = DAT_01185582 ^ 0x5f;
    s_DownloadAudio_0118558e[3] = DAT_01185583 ^ 0x59;
    s_DownloadAudio_0118558e[4] = DAT_01185584 ^ 0xe4;
    s_DownloadAudio_0118558e[5] = DAT_01185585 ^ 0x39;
    s_DownloadAudio_0118558e[6] = DAT_01185586 ^ 0xb1;
    s_DownloadAudio_0118558e[7] = DAT_01185587 ^ 0x3a;
    s_DownloadAudio_0118558e[8] = DAT_01185588 ^ 0xf3;
    s_DownloadAudio_0118558e[9] = DAT_01185589 ^ 0x1e;
    s_DownloadAudio_0118558e[10] = DAT_0118558a ^ 0xf1;
    s_DownloadAudio_0118558e[0xb] = DAT_0118558b ^ 3;
    s_DownloadAudio_0118558e[0xc] = DAT_0118558c ^ 0x71;
    s_DownloadAudio_0118558e[0xd] = DAT_0118558d ^ 0x61;
  }
  DAT_012270ec = 1;
  puStack_258 = auStack_3c0;
  puStack_218 = auStack_400;
  _objc_retain(param_3,param_2);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar4 = _objc_alloc_init(PTR_DownloadMenuHelper_0114ed78);
  puVar12 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uStack_9c = FUN_0010f44c(param_3,@selector(respondsToSelector:),@selector(playerResponse))
  ;
  puVar2 = @selector(contentPlayerResponse);
  puVar11 = local_98[uStack_9c] + (int)-(DAT_011895c8 ^ 0x285df92e);
  if (uStack_9c == 0) {
    uStack_ac = FUN_0010eefc(param_3,puVar1,@selector(contentPlayerResponse));
    puVar11 = local_a8[uStack_ac] + (int)-(DAT_011895e0 ^ 0x7bbd07e5);
    puVar12 = puVar2;
    if (uStack_ac == 0) goto LAB_000fa348;
  }
  _objc_msgSend(puVar11,param_3,puVar12);
  lStack_240 = _objc_retainAutoreleasedReturnValue();
  uStack_bc = (uint)(lStack_240 == 0);
  puVar11 = local_b8[uStack_bc] + (int)-(uRam00000000011895f8 ^ 0x6db36e2b);
  if (lStack_240 != 0) {
    puStack_2b0 = auStack_470;
    puStack_268 = auStack_380;
    puStack_260 = auStack_340;
    IStack_210 = param_4;
    _objc_msgSend(lStack_240,@selector(videoID));
    uStack_288 = _objc_retainAutoreleasedReturnValue();
    puVar11 = @selector(playerData);
    _objc_msgSend(lStack_240,@selector(playerData));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(videoDetails);
    _objc_msgSend(uVar5,@selector(videoDetails));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(title));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puStack_280 = puVar11;
    _objc_msgSend(lStack_240,puVar11);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(author));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_release(uVar6);
    puVar11 = @selector(length);
    uVar9 = _objc_msgSend(uVar5,@selector(length));
    uStack_cc = (uint)(0x1e < uVar9);
    if (0x1e < uVar9) {
      _objc_msgSend(local_c8[uStack_cc] + (int)-(DAT_01189610 ^ 0x9d4b9af7),uVar5,
                    @selector(substringToIndex:),0x1e);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_011858e0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
      _objc_release(uVar6);
      uVar5 = uVar8;
    }
    uStack_248 = uVar5;
    uVar9 = _objc_msgSend(uVar7,puVar11);
    uStack_e4 = (uint)(200 < uVar9);
    if (200 < uVar9) {
      _objc_msgSend(local_e0[uStack_e4] + (int)-(uRam0000000001189630 ^ 0xdda940d7),uVar7,
                    @selector(substringToIndex:),200);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(stringByAppendingString:),
                    &PTR____CFConstantStringClassReference_011858e0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar7);
      _objc_release(uVar5);
      uVar7 = uVar6;
    }
    _objc_msgSend(uVar4,@selector(getAudioFormatsArray:),param_3);
    uStack_298 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(getBestAudioFormat:playerVC:),uStack_298,param_3);
    uStack_270 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,@selector(activeVideo));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(selectedAudioFormat));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(audioTrack));
    lVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_2b4 = (uint)(lVar10 != 0);
    _objc_release();
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_fc = (uint)(DAT_01227090 == 0);
    if (DAT_01227090 == 0) {
      DAT_01227090 = _objc_getClass(local_f8[uStack_fc] + (int)-(uRam0000000001189650 ^ 0x7aced389),
                                    s_YTDefaultSheetController_01185720);
    }
    lVar10 = lStack_240;
    uVar4 = _objc_retainAutorelease();
    _objc_msgSend(uVar4,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uStack_248,uVar7,0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(valueForKey:),@"_headerView")
    ;
    uStack_2a0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_2a0,@selector(showHeaderDivider));
    uStack_114 = (uint)(lRam0000000001227098 == 0);
    uStack_278 = uVar4;
    if (lRam0000000001227098 == 0) {
      lRam0000000001227098 =
           _objc_getClass(local_110[uStack_114] + (int)-(uRam0000000001189670 ^ 0x66df73bf),
                          s_YTUIResources_01185747);
    }
    uVar4 = _objc_retainAutorelease();
    _objc_msgSend(uVar4,@selector(chevronRightImage));
    uStack_208 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_208,@selector(setFlipsForRightToLeftLayoutDirection:),1);
    _objc_msgSend(lVar10,puStack_280);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_2a8 = @selector(isLivePlayback);
    uVar3 = FUN_0010f264();
    _objc_release(uVar4);
    uStack_290 = uVar7;
    uStack_12c = uVar3;
                    /* WARNING: Could not recover jumptable at 0x000f9740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_128[uVar3] + (int)-(uRam0000000001189690 ^ 0xa00853e6)))();
    return;
  }
  uStack_bc = 1;
LAB_000fa348:
  _objc_release(puVar11,uVar4);
  _objc_release(param_3);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xf161);
  return;
}


