// Decompiled implementation evidence for YTLUserDefaults. Not compilable source.

// -[YTLUserDefaults reset], 0x1e6a08
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e6a08. reset */

/* Function Stack Size: 0x10 bytes */

void YTLUserDefaults::reset(ID param_1,SEL param_2)

{
  DAT_01227ea0 = 1;
  _objc_msgSend(param_1,@selector(removePersistentDomainForName:),
                @"com.dvntm.ytlite");
  return;
}



// -[YTLUserDefaults registerDefaults], 0x1e6b88
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e6b88. registerDefaults */

/* Function Stack Size: 0x10 bytes */

void YTLUserDefaults::registerDefaults(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  ID IVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined **ppuStack_540;
  undefined **ppuStack_538;
  undefined **ppuStack_530;
  undefined **ppuStack_528;
  undefined **ppuStack_520;
  undefined **ppuStack_518;
  undefined **ppuStack_510;
  undefined **ppuStack_508;
  undefined **ppuStack_500;
  undefined **ppuStack_4f8;
  undefined **ppuStack_4f0;
  undefined **ppuStack_4e8;
  undefined **ppuStack_4e0;
  undefined **ppuStack_4d8;
  undefined **ppuStack_4d0;
  undefined **ppuStack_4c8;
  undefined **ppuStack_4c0;
  undefined **ppuStack_4b8;
  undefined **ppuStack_4b0;
  undefined **ppuStack_4a8;
  undefined **ppuStack_4a0;
  undefined **ppuStack_498;
  undefined **ppuStack_490;
  undefined **ppuStack_488;
  undefined **ppuStack_480;
  undefined **ppuStack_478;
  undefined **ppuStack_470;
  undefined **ppuStack_468;
  undefined **ppuStack_460;
  undefined **ppuStack_458;
  undefined **ppuStack_450;
  undefined **ppuStack_448;
  undefined **ppuStack_440;
  undefined **ppuStack_438;
  undefined **ppuStack_430;
  undefined **ppuStack_428;
  undefined **ppuStack_420;
  undefined **ppuStack_418;
  undefined **ppuStack_410;
  undefined **ppuStack_408;
  undefined **ppuStack_400;
  undefined **ppuStack_3f8;
  undefined **ppuStack_3f0;
  undefined **ppuStack_3e8;
  undefined **ppuStack_3e0;
  undefined **ppuStack_3d8;
  undefined **ppuStack_3d0;
  undefined **ppuStack_3c8;
  undefined **ppuStack_3c0;
  undefined **ppuStack_3b8;
  undefined **ppuStack_3b0;
  undefined **ppuStack_3a8;
  undefined **ppuStack_3a0;
  undefined **ppuStack_398;
  undefined **ppuStack_390;
  undefined8 uStack_380;
  undefined8 uStack_378;
  undefined8 uStack_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  undefined8 uStack_358;
  undefined8 uStack_350;
  undefined8 uStack_348;
  undefined8 uStack_340;
  undefined8 uStack_338;
  undefined8 uStack_330;
  undefined8 uStack_328;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined8 uStack_310;
  undefined8 uStack_308;
  undefined8 uStack_300;
  undefined8 uStack_2f8;
  undefined8 uStack_2f0;
  undefined8 uStack_2e8;
  undefined **ppuStack_2e0;
  undefined8 uStack_2d8;
  undefined8 uStack_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  undefined8 uStack_2b8;
  undefined8 uStack_2b0;
  undefined8 uStack_2a8;
  undefined8 uStack_2a0;
  undefined8 uStack_298;
  undefined8 uStack_290;
  undefined8 uStack_288;
  undefined8 uStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined ***pppuStack_170;
  undefined ***pppuStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
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
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  ID local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011bcfe8;
  local_7c = (uint)(DAT_01227ea4 == 0);
  local_88 = &PTR_LAB_011bce10;
  DAT_01227ea4 = 1;
  pppuStack_168 = &ppuStack_530;
  pppuStack_170 = &ppuStack_540;
  local_90 = param_1;
  _objc_msgSend(param_1,@selector(sbPrivateUserID));
  uStack_98 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(sbPublicUserID:),uStack_98);
  uStack_108 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(numberWithBool:);
  ppuStack_510 = @"noAds";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithBool:),1);
  uStack_380 = _objc_retainAutoreleasedReturnValue();
  ppuStack_508 = @"backgroundPlayback";
  uStack_a0 = uStack_380;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_378 = _objc_retainAutoreleasedReturnValue();
  ppuStack_500 = @"downloadManager";
  uStack_a8 = uStack_378;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_370 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4f8 = @"removeDownloadMenu";
  uStack_b0 = uStack_370;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_368 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4f0 = @"frostedPivot";
  uStack_b8 = uStack_368;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_360 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(numberWithInt:);
  ppuStack_4e8 = @"ytlAudioIndex";
  uStack_c0 = uStack_360;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithInt:),0);
  uStack_358 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4e0 = @"ytlButtonIndex";
  uStack_c8 = uStack_358;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_350 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4d8 = @"startupAnimation";
  uStack_d0 = uStack_350;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_348 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4d0 = @"speedIndex";
  uStack_d8 = uStack_348;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,1);
  uStack_340 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4c8 = @"playbackRate";
  uStack_e0 = uStack_340;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,2);
  uStack_338 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4c0 = @"autoSpeedIndex";
  uStack_e8 = uStack_338;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,3);
  uStack_330 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4b8 = @"wiFiQualityIndex";
  uStack_f0 = uStack_330;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_328 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4b0 = @"cellQualityIndex";
  uStack_f8 = uStack_328;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_320 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4a8 = @"rcSkipBackwardSec";
  uStack_100 = uStack_320;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,10);
  uStack_318 = _objc_retainAutoreleasedReturnValue();
  ppuStack_4a0 = @"rcSkipForwardSec";
  uStack_110 = uStack_318;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,10);
  uStack_310 = _objc_retainAutoreleasedReturnValue();
  ppuStack_498 = @"leftGestureIndex";
  uStack_118 = uStack_310;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_308 = _objc_retainAutoreleasedReturnValue();
  ppuStack_490 = @"rightGestureIndex";
  uStack_120 = uStack_308;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_300 = _objc_retainAutoreleasedReturnValue();
  ppuStack_488 = @"seekMethodIndex";
  uStack_128 = uStack_300;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_2f8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_480 = @"gestWideness";
  uStack_130 = uStack_2f8;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0x32);
  uStack_2f0 = _objc_retainAutoreleasedReturnValue();
  ppuStack_478 = @"seekSensitivity";
  uStack_138 = uStack_2f0;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,8);
  uStack_2e8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_2e0 = @"FEwhat_to_watch";
  ppuStack_470 = @"startupTab";
  ppuStack_468 = @"idiomIndex";
  uStack_140 = uStack_2e8;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_2d8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_460 = @"miniPlayerIndex";
  uStack_148 = uStack_2d8;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uStack_2d0 = _objc_retainAutoreleasedReturnValue();
  ppuStack_458 = @"noLinkTracking";
  puStack_1b0 = puVar2;
  uStack_150 = uStack_2d0;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_2c8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_450 = @"noShareChunk";
  uStack_158 = uStack_2c8;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_2c0 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(arrayWithObjects:count:);
  ppuStack_448 = @"activeTabs";
  ppuStack_530 = @"FEwhat_to_watch";
  ppuStack_528 = @"FEshorts";
  ppuStack_520 = @"FEsubscriptions";
  ppuStack_518 = @"FElibrary";
  uStack_160 = uStack_2c0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                pppuStack_168,4);
  uStack_2b8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_440 = @"inactiveTabs";
  ppuStack_540 = @"FEuploads";
  ppuStack_538 = @"FEexplore";
  pppuStack_168 = (undefined ***)uStack_2b8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,pppuStack_170,2);
  uStack_2b0 = _objc_retainAutoreleasedReturnValue();
  ppuStack_438 = @"progressBarIndex";
  pppuStack_170 = (undefined ***)uStack_2b0;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,1);
  uStack_2a8 = _objc_retainAutoreleasedReturnValue();
  IVar6 = local_90;
  puVar4 = @selector(colorForSegment:);
  ppuStack_430 = @"progressMainColor";
  uStack_178 = uStack_2a8;
  _objc_msgSend(local_90,@selector(colorForSegment:),
                @"mainProgress");
  uStack_2a0 = _objc_retainAutoreleasedReturnValue();
  ppuStack_428 = @"progressGradientColor";
  uStack_180 = uStack_2a0;
  _objc_msgSend(IVar6,puVar4,@"gradientProgress");
  uStack_298 = _objc_retainAutoreleasedReturnValue();
  ppuStack_420 = @"scrubberColor";
  uStack_188 = uStack_298;
  _objc_msgSend(IVar6,puVar4);
  uStack_290 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  puVar2 = @selector(indexOfPreferredLanguage);
  ppuStack_418 = @"customTrack";
  uStack_190 = uStack_290;
  uVar7 = _objc_msgSend(PTR_YTPDB_0114ecc0,@selector(indexOfPreferredLanguage));
  puVar3 = @selector(numberWithUnsignedInteger:);
  _objc_msgSend(puVar5,@selector(numberWithUnsignedInteger:),uVar7);
  uStack_288 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  ppuStack_410 = @"customCaption";
  uStack_198 = uStack_288;
  uVar7 = _objc_msgSend(PTR_YTPDB_0114ecc0,puVar2);
  _objc_msgSend(puVar5,puVar3,uVar7);
  uStack_280 = _objc_retainAutoreleasedReturnValue();
  puVar2 = puStack_1b0;
  ppuStack_408 = @"sponsorBlock";
  uStack_1a0 = uStack_280;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puStack_1b0,1);
  uStack_278 = _objc_retainAutoreleasedReturnValue();
  ppuStack_400 = @"sbNotifications";
  uStack_1a8 = uStack_278;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,1);
  uStack_270 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3f8 = @"sbDuration";
  puStack_1b0 = (undefined *)uStack_270;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,4);
  uStack_268 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3f0 = @"sbSkippedDuration";
  uStack_1b8 = uStack_268;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,4);
  uStack_260 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3e8 = @"sb_sponsor";
  uStack_1c0 = uStack_260;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,1);
  uStack_258 = _objc_retainAutoreleasedReturnValue();
  IVar6 = local_90;
  ppuStack_3e0 = @"sb_sponsor_color";
  uStack_1c8 = uStack_258;
  _objc_msgSend(local_90,puVar4,@"sponsor");
  uStack_250 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3d8 = @"sb_intro_color";
  uStack_1d0 = uStack_250;
  _objc_msgSend(IVar6,puVar4,@"intro");
  uStack_248 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3d0 = @"sb_outro_color";
  uStack_1d8 = uStack_248;
  _objc_msgSend(IVar6,puVar4,@"endcards");
  uStack_240 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3c8 = @"sb_interaction_color";
  uStack_1e0 = uStack_240;
  _objc_msgSend(IVar6,puVar4,@"interaction");
  uStack_238 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3c0 = @"sb_selfpromo_color";
  uStack_1e8 = uStack_238;
  _objc_msgSend(IVar6,puVar4,@"selfpromo");
  uVar8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3b8 = @"sb_music_offtopic_color";
  uStack_230 = uVar8;
  _objc_msgSend(IVar6,puVar4,@"nonmusic");
  uVar9 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3b0 = @"sb_preview_color";
  uStack_228 = uVar9;
  _objc_msgSend(IVar6,puVar4,@"preview");
  uVar10 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3a8 = @"sb_poi_highlight_color";
  uStack_220 = uVar10;
  _objc_msgSend(IVar6,puVar4,@"highlight");
  uVar11 = _objc_retainAutoreleasedReturnValue();
  ppuStack_3a0 = @"sb_filler_color";
  uStack_218 = uVar11;
  _objc_msgSend(IVar6,puVar4,@"jokes");
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar7 = uStack_108;
  uStack_208 = uStack_98;
  ppuStack_398 = @"sbPrivateUserID";
  ppuStack_390 = @"sbPublicUserID";
  uStack_200 = uStack_108;
  uStack_210 = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),&uStack_380,&ppuStack_510,0x31);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar6,@selector(registerDefaults:),uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uStack_1e8);
  _objc_release(uStack_1e0);
  _objc_release(uStack_1d8);
  _objc_release(uStack_1d0);
  _objc_release(uStack_1c8);
  _objc_release(uStack_1c0);
  _objc_release(uStack_1b8);
  _objc_release(puStack_1b0);
  _objc_release(uStack_1a8);
  _objc_release(uStack_1a0);
  _objc_release(uStack_198);
  _objc_release(uStack_190);
  _objc_release(uStack_188);
  _objc_release(uStack_180);
  _objc_release(uStack_178);
  _objc_release(pppuStack_170);
  _objc_release(pppuStack_168);
  _objc_release(uStack_160);
  _objc_release(uStack_158);
  _objc_release(uStack_150);
  _objc_release(uStack_148);
  _objc_release(uStack_140);
  _objc_release(uStack_138);
  _objc_release(uStack_130);
  _objc_release(uStack_128);
  _objc_release(uStack_120);
  _objc_release(uStack_118);
  _objc_release(uStack_110);
  _objc_release(uStack_100);
  _objc_release(uStack_f8);
  _objc_release(uStack_f0);
  _objc_release(uStack_e8);
  _objc_release(uStack_e0);
  _objc_release(uStack_d8);
  _objc_release(uStack_d0);
  _objc_release(uStack_c8);
  _objc_release(uStack_c0);
  _objc_release(uStack_b8);
  _objc_release(uStack_b0);
  _objc_release(uStack_a8);
  _objc_release(uStack_a0);
  _objc_release(uVar7);
  _objc_release(uStack_98);
  CallSupervisor(0x60f8);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[YTLUserDefaults colorForSegment:], 0x1eb10c
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
  puVar1 = @selector(colorWithRed:green:blue:alpha:);
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011bd008;
  local_84 = (uint)(DAT_01227ea8 == 0);
  local_98 = &PTR_LAB_011bd028;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bce10;
  DAT_01227ea8 = 1;
  puStack_c0 = &uStack_150;
  pppuStack_c8 = &ppuStack_1b0;
  ppuStack_1b0 = @"sponsor";
  IStack_b0 = param_3;
  _objc_retain(param_3);
  uVar4 = DAT_00c4c400;
  _objc_msgSend(DAT_00c4c3f0,DAT_00c4c3f8,DAT_00c4c400,DAT_00c4c2f8,puVar2,puVar1);
  uStack_150 = _objc_retainAutoreleasedReturnValue();
  uVar6 = DAT_00c4c368;
  ppuStack_1a8 = @"intro";
  uStack_b8 = uStack_150;
  _objc_msgSend(DAT_00c4c408,DAT_00c4c410,DAT_00c4c418,DAT_00c4c368,
                PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uStack_148 = _objc_retainAutoreleasedReturnValue();
  ppuStack_1a0 = @"endcards";
  uStack_d0 = uStack_148;
  _objc_msgSend(DAT_00c4c318,DAT_00c4c318,DAT_00c4c420,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uStack_140 = _objc_retainAutoreleasedReturnValue();
  ppuStack_198 = @"interaction";
  uStack_d8 = uStack_140;
  _objc_msgSend(DAT_00c4c428,DAT_00c4c430,DAT_00c4c438,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uStack_138 = _objc_retainAutoreleasedReturnValue();
  ppuStack_190 = @"selfpromo";
  uStack_e0 = uStack_138;
  _objc_msgSend(0x3ff0000000000000,0x3ff0000000000000,DAT_00c4c440,uVar6,
                PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uStack_130 = _objc_retainAutoreleasedReturnValue();
  ppuStack_188 = @"nonmusic";
  uStack_e8 = uStack_130;
  _objc_msgSend(DAT_00c4c448,DAT_00c4c450,DAT_00c4c458,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuStack_180 = @"preview";
  uStack_128 = uVar3;
  _objc_msgSend(uVar4,DAT_00c4c460,DAT_00c4c468,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuStack_178 = @"highlight";
  uStack_120 = uVar4;
  _objc_msgSend(DAT_00c4c470,DAT_00c4c478,DAT_00c4c480,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuStack_170 = @"jokes";
  uStack_118 = uVar5;
  _objc_msgSend(DAT_00c4c488,DAT_00c4c490,DAT_00c4c498,uVar6,PTR__OBJC_CLASS___UIColor_0114eb18,
                puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(redColor);
  ppuStack_168 = @"mainProgress";
  uStack_110 = uVar6;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(redColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  ppuStack_160 = @"gradientProgress";
  uStack_108 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  ppuStack_158 = @"scrubberColor";
  uStack_100 = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_f8 = uVar9;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),puStack_c0,pppuStack_c8,0xc);
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
  _objc_msgSend(uVar10,@selector(objectForKeyedSubscript:),IStack_b0);
  lVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(IVar12);
  uStack_9c = (uint)(lVar11 == 0);
  if (lVar11 == 0) {
    uVar6 = 0;
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSKeyedArchiver_0114ec48,
                  @selector(archivedDataWithRootObject:requiringSecureCoding:error:),lVar11,0,0);
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



// -[YTLUserDefaults sbPrivateUserID], 0x1ebdbc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ebdbc. sbPrivateUserID */

/* Function Stack Size: 0x10 bytes */

ID YTLUserDefaults::sbPrivateUserID(ID param_1,SEL param_2)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  byte abStack_e0 [52];
  undefined4 uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011bd048;
  local_74 = (uint)(DAT_01227eac == 0);
  local_88 = &PTR_LAB_011bd068;
  ppuStack_80 = &PTR_LAB_011bce10;
  local_a0 = &PTR_LAB_011bce10;
  ppuStack_98 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bd090;
  DAT_01227eac = 1;
  uVar5 = _SecRandomCopyBytes(*(undefined8 *)PTR__kSecRandomDefault_01060d88,0x24,abStack_e0);
  bVar4 = (int)uVar5 == 0;
  uStack_8c = (uint)bVar4;
  if (bVar4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,@selector(stringWithCapacity:),0x24
                 );
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(characterAtIndex:);
    puVar2 = @selector(appendFormat:);
    lVar8 = 0;
    while( true ) {
      bVar1 = abStack_e0[lVar8];
      uVar6 = _objc_msgSend(@"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",puVar3,
                            (uint)bVar1 + ((bVar1 >> 1) / 0x1f) * -0x3e & 0xff);
      thunk_FUN_001eeeb0(uVar5,puVar2,@"%c",uVar6);
      lVar8 = lVar8 + 1;
      if (lVar8 == 0x24) break;
      uStack_ac = 0;
    }
    uStack_ac = 1;
  }
  else {
    thunk_FUN_001eee64(local_88[uStack_8c] + (int)-(DAT_011bd078 ^ 0x4a96c68d),
                       @"YTL --- failed to gen random bytes: %d",uVar5);
    uVar5 = 0;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar7 = _objc_autoreleaseReturnValue(uVar5);
    return IVar7;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTLUserDefaults sbPublicUserID:], 0x1ec5dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ec5dc. sbPublicUserID: */

/* Function Stack Size: 0x18 bytes */

ID YTLUserDefaults::sbPublicUserID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  CC_LONG len;
  undefined8 uVar4;
  undefined8 uVar5;
  void *data;
  ID IVar6;
  undefined **ppuVar7;
  long lVar8;
  int iVar9;
  uchar auStack_d0 [36];
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011bd0a8;
  local_74 = (uint)(DAT_01227eb0 == 0);
  local_88 = &PTR_LAB_011bce10;
  ppuStack_80 = &PTR_LAB_011bce10;
  local_98 = &PTR_LAB_011bd0d8;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bd0f0;
  DAT_01227eb0 = 1;
  _objc_msgSend(param_3,@selector(dataUsingEncoding:),4);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(dataWithBytes:length:);
  puVar2 = @selector(bytes);
  puVar1 = @selector(length);
  ppuVar7 = &@selector(setTintColor:);
  iVar9 = 4999;
  while( true ) {
    uVar5 = _objc_retainAutorelease(ppuVar7,uVar4);
    data = (void *)_objc_msgSend(uVar5,puVar2);
    len = _objc_msgSend(uVar4,puVar1);
    _CC_SHA256(data,len,auStack_d0);
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,puVar3,auStack_d0,0x20);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uStack_9c = (uint)(iVar9 == 0);
    ppuVar7 = (undefined **)(local_98[uStack_9c] + (int)-(uRam00000000011bd0e8 ^ 0xcfc83ed7));
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    uStack_9c = 0;
    uVar4 = uVar5;
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,@selector(stringWithCapacity:),0x40);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(appendFormat:);
  lVar8 = 0;
  ppuVar7 = &@selector(setTintColor:);
  while( true ) {
    thunk_FUN_001eef7c(ppuVar7,uVar4,puVar1,@"%02x",
                       auStack_d0[lVar8]);
    uStack_ac = (uint)(lVar8 == 0x1f);
    ppuVar7 = (undefined **)(local_a8[uStack_ac] + (int)-(uRam00000000011bd100 ^ 0xfb58273d));
    if (lVar8 == 0x1f) break;
    lVar8 = lVar8 + 1;
    uStack_ac = 0;
  }
  _objc_release(uVar5);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
    return IVar6;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTLUserDefaults presentDocumentPicker:], 0x1ed5cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ed5cc. presentDocumentPicker: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::presentDocumentPicker_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined **appuStack_70 [2];
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  puVar1 = PTR__OBJC_CLASS___UIDocumentPickerViewController_0114ef38;
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011bd1d0;
  local_54 = (uint)(DAT_01227ec8 == 0);
  local_60 = &PTR_LAB_011bce10;
  DAT_01227ec8 = 1;
  _objc_retain(param_3,param_2,param_3,param_4);
  uVar2 = _objc_alloc(puVar1);
  appuStack_70[0] = @"com.apple.property-list";
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                appuStack_70,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar2,@selector(initWithDocumentTypes:inMode:),uVar3,0);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,@selector(setDelegate:),param_1);
  _objc_msgSend(uVar2,@selector(setAllowsMultipleSelection:),0);
  uVar3 = _NSClassFromString(@"YTUIUtils");
  _objc_msgSend(uVar3,@selector(topViewControllerForPresenting));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(presentViewController:animated:completion:),uVar2,1,0);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(setPrefsPickerCompletion:),param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x9c9f);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[YTLUserDefaults documentPicker:didPickDocumentAtURL:], 0x1ed9d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ed9d0. documentPicker:didPickDocumentAtURL: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::documentPicker_didPickDocumentAtURL_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  
  _objc_retain(param_4);
  puVar1 = @selector(prefsPickerCompletion);
  _objc_msgSend(param_1,@selector(prefsPickerCompletion));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011bd1f0)[lVar2 == 0] + (int)-(DAT_011bd200 ^ 0xb4b81dd1),param_1,puVar1
                 );
    lVar2 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))(lVar2,param_4);
    _objc_release(lVar2);
  }
  _objc_release(param_4);
  CallSupervisor(0x9fe3);
  return;
}



// -[YTLUserDefaults prefsPickerCompletion], 0x1ee4c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee4c4. prefsPickerCompletion */

/* Function Stack Size: 0x10 bytes */

ID YTLUserDefaults::prefsPickerCompletion(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_prefsPickerCompletion);
}



// -[YTLUserDefaults setPrefsPickerCompletion:], 0x1ee4d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee4d4. setPrefsPickerCompletion: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::setPrefsPickerCompletion_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x5a62);
  return;
}



// -[YTLUserDefaults .cxx_destruct], 0x1ee508
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee508. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTLUserDefaults::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_prefsPickerCompletion,0);
  CallSupervisor(0x71a);
  return;
}



// +[YTLUserDefaults standardUserDefaults], 0x1e677c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e677c. standardUserDefaults */

/* Function Stack Size: 0x10 bytes */

ID YTLUserDefaults::standardUserDefaults(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR_LAB_011bcf80;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001e6830;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227e88 == -1);
  local_28 = param_1;
  if (DAT_01227e88 != -1) {
    _dispatch_once((&PTR_LAB_011bcf80)[local_1c] + (int)-(DAT_011bcf90 ^ 0x48e13615),&DAT_01227e88,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(uRam0000000001227e90,param_2);
  return IVar1;
}



// +[YTLUserDefaults importYtlSettings:], 0x1ec890
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ec890. importYtlSettings: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::importYtlSettings_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID IStack_38;
  
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(param_1,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(presentDocumentPicker:);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001ec964;
  puStack_48 = &DAT_01062e70;
  local_40 = param_3;
  IStack_38 = param_1;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_60);
  _objc_release(uVar2);
  _objc_release(local_40);
  _objc_release(param_3);
  CallSupervisor(0xa857);
  return;
}



// +[YTLUserDefaults exportYtlSettings:], 0x1edac4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1edac4. exportYtlSettings: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::exportYtlSettings_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  double in_d2;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 auStack_c0 [3];
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011bd210;
  local_84 = (uint)(DAT_01227ed0 == 0);
  local_98 = &PTR_LAB_011bd230;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bce10;
  DAT_01227ed0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(URLsForDirectory:inDomains:),5,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(firstObject));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar4,@selector(URLByAppendingPathComponent:),
                @"Preferences/com.dvntm.ytlite.plist");
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  puVar1 = @selector(arrayWithObjects:count:);
  auStack_c0[0] = uVar2;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),auStack_c0
                ,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar3,@selector(initWithActivityItems:applicationActivities:),uVar5,0);
  _objc_release(uVar5);
  uStack_d0 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_c8 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,&uStack_d0,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setExcludedActivityTypes:),uVar5);
  _objc_release(uVar5);
  uVar5 = _NSClassFromString(@"YTUIUtils");
  _objc_msgSend(uVar5,@selector(topViewControllerForPresenting));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(popoverPresentationController);
  _objc_msgSend(uVar3,@selector(popoverPresentationController));
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_9c = (uint)(lVar6 == 0);
  if (lVar6 != 0) {
    _objc_msgSend(local_98[uStack_9c] + (int)-(uRam00000000011bd240 ^ 0x7638df57),uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setSourceView:),param_3);
    _objc_release(uVar7);
    _objc_msgSend(param_3,@selector(bounds));
    _objc_msgSend(uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 + -5.0,0,0x3ff0000000000000,0x3ff0000000000000,uVar7,
                  @selector(setSourceRect:));
    _objc_release(uVar7);
    _objc_msgSend(uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setPermittedArrowDirections:),1);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar5,@selector(presentViewController:animated:completion:),uVar3,1,0);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0x3a38);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// +[YTLUserDefaults resetUserDefaults], 0x1ee158
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee158. resetUserDefaults */

/* Function Stack Size: 0x10 bytes */

void YTLUserDefaults::resetUserDefaults(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(reset));
  _objc_release(uVar1);
  CallSupervisor(0x4d7f);
  return;
}



// +[YTLUserDefaults boolForKey:], 0x1ee1b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee1b4. boolForKey: */

/* Function Stack Size: 0x18 bytes */

bool YTLUserDefaults::boolForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  bVar2 = FUN_001ef6ac(uVar3,@selector(boolForKey:),param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  return bVar2;
}



// +[YTLUserDefaults integerForKey:], 0x1ee22c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee22c. integerForKey: */

/* Function Stack Size: 0x18 bytes */

long_long YTLUserDefaults::integerForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long_long lVar3;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,@selector(integerForKey:),param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  return lVar3;
}



// +[YTLUserDefaults floatForKey:], 0x1ee2a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee2a4. floatForKey: */

/* Function Stack Size: 0x18 bytes */

double YTLUserDefaults::floatForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  float fVar3;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  fVar3 = (float)_objc_msgSend(uVar2,@selector(floatForKey:),param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  return (double)fVar3;
}



// +[YTLUserDefaults setBool:forKey:], 0x1ee328
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee328. setBool:forKey: */

/* Function Stack Size: 0x1c bytes */

void YTLUserDefaults::setBool_forKey_(ID param_1,SEL param_2,bool param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setBool:forKey:),param_3,param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  CallSupervisor(0xa961);
  return;
}



// +[YTLUserDefaults setInteger:forKey:], 0x1ee3b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee3b8. setInteger:forKey: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::setInteger_forKey_(ID param_1,SEL param_2,long_long param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setInteger:forKey:),param_3,param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  return;
}



// +[YTLUserDefaults setFloat:forKey:], 0x1ee42c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee42c. setFloat:forKey: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::setFloat_forKey_(ID param_1,SEL param_2,double param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = @selector(standardUserDefaults);
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((float)param_3,uVar2,@selector(setFloat:forKey:),param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  CallSupervisor(0xec62);
  return;
}


