// Decompiled implementation evidence for SBPlaybackController. Not compilable source.

// -[SBPlaybackController initWithPlayer:], 0x194914
/* Decompiled from supplied 5.2.2 arm package. VA 0x194914. initWithPlayer: */

/* Function Stack Size: 0x18 bytes */

ID SBPlaybackController::initWithPlayer_(ID param_1,SEL param_2,ID param_3)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR__objc_msgSend_011aaa18;
  _objc_retain(param_3);
  puStack_38 = PTR_SBPlaybackController_0114f0d8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_storeWeak(local_28[local_2c] + (int)-(DAT_011aaa28 ^ 0x8342a3ce),IVar1 + 8,param_3);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableSet_0114eee0,@selector(set));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(IVar1,@selector(requestSbSegments));
  }
  _objc_release(param_3);
  return IVar1;
}



// -[SBPlaybackController requestSbSegments], 0x194a04
/* Decompiled from supplied 5.2.2 arm package. VA 0x194a04. requestSbSegments */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::requestSbSegments(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = _objc_loadWeakRetained(param_1 + 8);
  _objc_msgSend(uVar1,@selector(contentVideoID));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00194a94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011aaa38)[lVar2 == 0] + (int)-(DAT_011aaa48 ^ 0x1e2e3322)))();
  return;
}



// -[SBPlaybackController shouldCheckSponsorBlock], 0x194c24
/* Decompiled from supplied 5.2.2 arm package. VA 0x194c24. shouldCheckSponsorBlock */

/* Function Stack Size: 0x10 bytes */

bool SBPlaybackController::shouldCheckSponsorBlock(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined *puVar10;
  double dVar11;
  
  puVar3 = @selector(boolForKey:);
  DAT_01227834 = 1;
  uVar4 = FUN_001989cc(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"sbFeedPlayer");
  puVar10 = (&PTR_LAB_011aaa80)[uVar4] + (int)-(DAT_011aaa90 ^ 0x911b0a18);
  if (uVar4 == 0) {
    uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
    puVar1 = @selector(parentViewController);
    _objc_msgSend(uVar6,@selector(parentViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = _objc_getClass(s_YTWatchViewController_011a9cb0);
    puVar2 = @selector(isKindOfClass:);
    uVar4 = FUN_00198ba4(uVar7,@selector(isKindOfClass:),uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar10 = (&PTR_LAB_011aaa98)[uVar4] + (int)-(uRam00000000011aaaa8 ^ 0xfb9621c8);
    if (uVar4 == 0) {
      uVar4 = FUN_00198c0c(puVar10,PTR_YTLUserDefaults_0114ead8,puVar3,
                           @"sbMiniPlayer");
      puVar10 = (&PTR_LAB_011aaab0)[uVar4] + (int)-(uRam00000000011aaac0 ^ 0x9a413644);
      if (uVar4 == 0) {
        uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
        _objc_msgSend(uVar6,puVar1);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        uVar8 = _objc_getClass(s_YTWatchMiniBarViewController_011a9c70);
        uVar4 = FUN_00198b3c(uVar7,puVar2,uVar8);
        _objc_release(uVar7);
        _objc_release(uVar6);
        puVar10 = (&PTR_LAB_011aaac8)[uVar4] + (int)-(uRam00000000011aaad8 ^ 0xa6122f68);
        if (uVar4 == 0) {
          return 0;
        }
      }
    }
  }
  uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
  _objc_msgSend(uVar6,@selector(contentVideoID));
  lVar9 = _objc_retainAutoreleasedReturnValue();
  if (lVar9 == 0) {
    _objc_release((&PTR_LAB_011aaae0)[lVar9 == 0] + (int)-(uRam00000000011aaaf0 ^ 0xc55c4806),uVar6)
    ;
    return 0;
  }
  uVar7 = _objc_loadWeakRetained(param_1 + 8);
  dVar11 = (double)_objc_msgSend(uVar7,@selector(currentVideoMediaTime));
  _objc_release(uVar7);
  _objc_release(lVar9);
  _objc_release(uVar6);
                    /* WARNING: Could not recover jumptable at 0x001954b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar5 = (*(code *)((&PTR_LAB_011aaaf8)[dVar11 == 0.0] + (int)-(uRam00000000011aab08 ^ 0xfd59f773))
          )();
  return bVar5;
}



// -[SBPlaybackController skipSegmentIfNeeded], 0x1956f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1956f8. skipSegmentIfNeeded */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::skipSegmentIfNeeded(ID param_1,SEL param_2)

{
  double dVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined1 extraout_b0;
  undefined1 extraout_b0_00;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 auStack_300 [128];
  undefined8 uStack_280;
  undefined8 *puStack_278;
  long *plStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined **ppuStack_230;
  undefined **ppuStack_228;
  undefined **ppuStack_220;
  undefined **ppuStack_218;
  undefined **ppuStack_210;
  undefined **ppuStack_208;
  undefined1 *puStack_200;
  undefined *puStack_1f8;
  undefined *puStack_1f0;
  undefined *puStack_1e8;
  undefined *puStack_1e0;
  undefined *puStack_1d8;
  undefined8 uStack_1d0;
  undefined *puStack_1c8;
  undefined *puStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined *puStack_1a8;
  long lStack_1a0;
  ID local_198;
  undefined **local_190;
  undefined **local_180;
  uint uStack_174;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_148;
  undefined **ppuStack_140;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **ppuStack_118;
  uint uStack_10c;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011aab78;
  local_8c = (uint)(DAT_01227838 == 0);
  local_a0 = &PTR_LAB_011aab98;
  local_b0 = &PTR_LAB_011aabb0;
  local_98 = &PTR__objc_msgSend_011aa770;
  local_c8 = &PTR__objc_msgSend_011aa770;
  ppuStack_c0 = &PTR__objc_msgSend_011aa770;
  local_d0 = &PTR_LAB_011aabd8;
  local_e8 = &PTR_LAB_011aabf8;
  ppuStack_e0 = &PTR__objc_msgSend_011aa770;
  local_f8 = &PTR_LAB_011aac10;
  local_108 = &PTR_LAB_011aac28;
  local_120 = &PTR_LAB_011aac48;
  ppuStack_118 = &PTR__objc_msgSend_011aa770;
  local_130 = &PTR_LAB_011aac60;
  local_148 = &PTR_LAB_011aac80;
  ppuStack_140 = &PTR__objc_msgSend_011aa770;
  local_158 = &PTR_LAB_011aac98;
  local_170 = &PTR_LAB_011aacb8;
  ppuStack_168 = &PTR__objc_msgSend_011aa770;
  local_180 = &PTR_LAB_011aacd0;
  local_190 = &PTR__objc_msgSend_011aa770;
  DAT_01227838 = 1;
  local_198 = param_1;
  iStack_a4 = FUN_00198c7c(param_1,@selector(shouldCheckSponsorBlock));
  if (iStack_a4 != 0) {
    ppuStack_240 = @"sponsor";
    ppuStack_238 = @"intro";
    ppuStack_230 = @"outro";
    ppuStack_228 = @"interaction";
    ppuStack_220 = @"selfpromo";
    ppuStack_218 = @"music_offtopic";
    ppuStack_210 = @"preview";
    ppuStack_208 = @"filler";
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &ppuStack_240,8);
    uStack_1d0 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_SBManager_0114eee8,@selector(sharedManager));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(segments));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(objectForKey:),*(undefined8 *)(local_198 + 0x10));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_release(uVar7);
    uStack_258 = 0;
    uStack_260 = 0;
    uStack_248 = 0;
    uStack_250 = 0;
    puStack_278 = (undefined8 *)0x0;
    uStack_280 = 0;
    uStack_268 = 0;
    plStack_270 = (long *)0x0;
    uVar7 = _objc_retain(uVar9);
    puStack_1f8 = @selector(countByEnumeratingWithState:objects:count:);
    uStack_1b8 = uVar9;
    lVar10 = _objc_msgSend(uVar7,@selector(countByEnumeratingWithState:objects:count:),&uStack_280,
                           auStack_300,0x10);
    uVar7 = uStack_1b8;
    puVar3 = @selector(uuid);
    puVar2 = @selector(containsObject:);
    uStack_b4 = (uint)(lVar10 == 0);
    if (lVar10 != 0) {
      lStack_1a0 = *plStack_270;
      puStack_1b0 = @selector(isEqualToString:);
      puStack_1a8 = @selector(category);
      puStack_1c8 = @selector(start);
      puStack_1c0 = @selector(currentVideoMediaTime);
      puStack_1e8 = @selector(segmentMeetsMinimumDuration:);
      puStack_1e0 = @selector(end);
      puStack_1f0 = @selector(handleSkipSegment:);
      puStack_1d8 = @selector(handleHighlightSegment:);
      bVar5 = *plStack_270 == lStack_1a0;
      uStack_d4 = (uint)bVar5;
      puStack_200 = auStack_300;
      if (!bVar5) {
        _objc_enumerationMutation
                  (local_d0[bVar5] + (int)-(uRam00000000011aabe8 ^ 0x461c5bce),uStack_1b8);
      }
      uVar9 = *puStack_278;
      uVar8 = *(undefined8 *)(local_198 + 0x18);
      _objc_msgSend(uVar9,puVar3);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198f1c(uVar8,puVar2,uVar7);
      _objc_release(uVar7);
      puVar3 = puStack_1a8;
      uStack_ec = uVar6;
      if (uVar6 != 0) {
        uStack_174 = (uint)(lVar10 == 1);
                    /* WARNING: Could not recover jumptable at 0x00196370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_170[uStack_174] + (int)-(DAT_011aacc8 ^ 0xbc3db93e)))();
        return;
      }
      _objc_msgSend(local_e8[uVar6] + (int)-(uRam00000000011aac08 ^ 0xde812d4c),uVar9,puStack_1a8);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198cc4(uVar7,puStack_1b0,@"poi_highlight");
      _objc_release(uVar7);
      uStack_fc = uVar6;
      if (uVar6 != 0) {
        uVar7 = _objc_loadWeakRetained(local_198 + 8);
        _objc_msgSend(uVar7,puStack_1c0);
        dVar1 = (double)CONCAT17(extraout_var_11,
                                 CONCAT16(extraout_var_09,
                                          CONCAT15(extraout_var_07,
                                                   CONCAT14(extraout_var_05,
                                                            CONCAT13(extraout_var_03,
                                                                     CONCAT12(extraout_var_01,
                                                                              CONCAT11(extraout_var,
                                                                                       extraout_b0))
                                                                    )))));
        _objc_msgSend(uVar9,puStack_1c8);
        bVar5 = false;
        bVar4 = true;
        if (!NAN(dVar1) &&
            !NAN((double)CONCAT17(extraout_var_12,
                                  CONCAT16(extraout_var_10,
                                           CONCAT15(extraout_var_08,
                                                    CONCAT14(extraout_var_06,
                                                             CONCAT13(extraout_var_04,
                                                                      CONCAT12(extraout_var_02,
                                                                               CONCAT11(
                                                  extraout_var_00,extraout_b0_00))))))))) {
          bVar5 = dVar1 == (double)CONCAT17(extraout_var_12,
                                            CONCAT16(extraout_var_10,
                                                     CONCAT15(extraout_var_08,
                                                              CONCAT14(extraout_var_06,
                                                                       CONCAT13(extraout_var_04,
                                                                                CONCAT12(
                                                  extraout_var_02,
                                                  CONCAT11(extraout_var_00,extraout_b0_00)))))));
          bVar4 = (double)CONCAT17(extraout_var_12,
                                   CONCAT16(extraout_var_10,
                                            CONCAT15(extraout_var_08,
                                                     CONCAT14(extraout_var_06,
                                                              CONCAT13(extraout_var_04,
                                                                       CONCAT12(extraout_var_02,
                                                                                CONCAT11(
                                                  extraout_var_00,extraout_b0_00))))))) <= dVar1;
        }
        _objc_release(uVar7);
        uStack_10c = (uint)(bVar4 && !bVar5);
                    /* WARNING: Could not recover jumptable at 0x001962f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_108[uStack_10c] + (int)-(uRam00000000011aac38 ^ 0x1db31cdc)))();
        return;
      }
      _objc_msgSend(local_f8[uVar6] + (int)-(uRam00000000011aac20 ^ 0xeb074805),uVar9,puVar3);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_00198d0c(uStack_1d0,puVar2,uVar7);
      _objc_release(uVar7);
      uStack_124 = uVar6;
                    /* WARNING: Could not recover jumptable at 0x00196138. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_120[uVar6] + (int)-(uRam00000000011aac58 ^ 0x885dbcda)))();
      return;
    }
    _objc_release(local_b0[uStack_b4] + (int)-(uRam00000000011aabc0 ^ 0xf43bb043),uStack_1b8);
    _objc_release(uVar7);
    _objc_release(uStack_1d0);
  }
  CallSupervisor(0x23fc);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[SBPlaybackController segmentMeetsMinimumDuration:], 0x1964b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1964b8. segmentMeetsMinimumDuration: */

/* Function Stack Size: 0x18 bytes */

bool SBPlaybackController::segmentMeetsMinimumDuration_(ID param_1,SEL param_2,ID param_3)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  bVar3 = 1;
  DAT_0122783c = 1;
  _objc_retain(param_3);
  dVar4 = (double)_objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(floatForKey:),
                                @"sbSkipDuration");
  if (0.0 < dVar4) {
    _objc_msgSend(param_3,@selector(category));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    iVar1 = FUN_00199004(uVar2,@selector(isEqualToString:),
                         @"poi_highlight");
    _objc_release(uVar2);
    bVar3 = 1;
    if (iVar1 == 0) {
      dVar5 = (double)_objc_msgSend(param_3,@selector(end));
      dVar6 = (double)_objc_msgSend(param_3,@selector(start));
      bVar3 = (bool)(dVar4 <= dVar5 - dVar6);
    }
  }
  _objc_release(param_3);
  return bVar3;
}



// -[SBPlaybackController handleSkipSegment:], 0x196834
/* Decompiled from supplied 5.2.2 arm package. VA 0x196834. handleSkipSegment: */

/* Function Stack Size: 0x18 bytes */

void SBPlaybackController::handleSkipSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  DAT_01227840 = 1;
  uVar3 = _objc_retain(param_3);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  _objc_msgSend(uVar3,@selector(uuid));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(addObject:),uVar3);
  _objc_release(uVar3);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_YTLUserDefaults_0114ead8;
  _objc_msgSend(param_3,@selector(category));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00199078(puVar2,@selector(stringWithFormat:),
                     @"sb_%@",uVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  lVar4 = _objc_msgSend(puVar1,@selector(integerForKey:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar3);
  uVar3 = _objc_loadWeakRetained(param_1 + 8);
  uVar5 = _objc_msgSend(uVar3,@selector(currentVideoMediaTime));
  _objc_release(uVar3);
  if (lVar4 < 2) {
    if (lVar4 == 1) {
      uVar3 = _objc_msgSend(param_3,@selector(end));
      uVar5 = _objc_msgSend(param_3,@selector(start));
      _objc_msgSend(uVar3,uVar5,param_1,@selector(seekToTime:forSegment:undoTime:attempts:),param_3,1);
    }
  }
  else if (lVar4 == 2) {
    uVar3 = _objc_msgSend(param_3,@selector(end));
    _objc_msgSend(uVar5,uVar3,param_1,@selector(showSkipPromptToast:timeBeforeSkip:target:),param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[SBPlaybackController handleHighlightSegment:], 0x196b54
/* Decompiled from supplied 5.2.2 arm package. VA 0x196b54. handleHighlightSegment: */

/* Function Stack Size: 0x18 bytes */

void SBPlaybackController::handleHighlightSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  DAT_01227844 = 1;
  uVar3 = _objc_retain(param_3);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  _objc_msgSend(uVar3,@selector(uuid));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(addObject:),uVar3);
  _objc_release(uVar3);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_YTLUserDefaults_0114ead8;
  _objc_msgSend(param_3,@selector(category));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_001991e4(puVar2,@selector(stringWithFormat:),
                     @"sb_%@",uVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  lVar4 = _objc_msgSend(puVar1,@selector(integerForKey:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar3);
  uVar3 = _objc_loadWeakRetained(param_1 + 8);
  uVar5 = _objc_msgSend(uVar3,@selector(currentVideoMediaTime));
  _objc_release(uVar3);
  if (lVar4 < 2) {
    if (lVar4 == 1) {
      uVar3 = _objc_msgSend(param_3,@selector(start));
      _objc_msgSend(uVar3,uVar5,param_1,@selector(seekToTime:forSegment:undoTime:attempts:),param_3,1);
    }
  }
  else if (lVar4 == 2) {
    uVar3 = _objc_msgSend(param_3,@selector(start));
    _objc_msgSend(uVar5,uVar3,param_1,@selector(showSkipPromptToast:timeBeforeSkip:target:),param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xcbc4);
  return;
}



// -[SBPlaybackController seekToTime:forSegment:undoTime:attempts:], 0x196e7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x196e7c. seekToTime:forSegment:undoTime:attempts: */

/* Function Stack Size: 0x2c bytes */

void SBPlaybackController::seekToTime_forSegment_undoTime_attempts_
               (ID param_1,SEL param_2,double param_3,ID param_4,double param_5,int param_6)

{
  undefined8 uVar1;
  dispatch_time_t dVar2;
  undefined *puStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined *puStack_a0;
  ID IStack_98;
  ID IStack_90;
  undefined1 auStack_88 [8];
  double dStack_80;
  double dStack_78;
  int iStack_70;
  undefined1 auStack_68 [12];
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011aae48;
  _objc_retain(param_4);
  local_5c = (uint)((int)param_6 < 1);
  if (0 < (int)param_6) {
    uVar1 = _objc_loadWeakRetained
                      (local_58[local_5c] + (int)-(DAT_011aae58 ^ 0xc904f157),param_1 + 8);
    _objc_msgSend(param_3,uVar1,@selector(seekToTime:));
    _objc_release(uVar1);
    _objc_initWeak(auStack_68,param_1);
    dVar2 = _dispatch_time(0,300000000);
    puStack_b8 = PTR___NSConcreteStackBlock_01060660;
    uStack_b0 = DAT_00c4c228;
    pcStack_a8 = FUN_00197000;
    puStack_a0 = &UNK_01062820;
    _objc_copyWeak(auStack_88,auStack_68);
    IStack_98 = param_1;
    _objc_retain(param_4);
    IStack_90 = param_4;
    dStack_80 = param_3;
    dStack_78 = param_5;
    iStack_70 = param_6;
    _dispatch_after(dVar2,PTR___dispatch_main_q_01060760,&puStack_b8);
    _objc_release(IStack_90);
    _objc_destroyWeak(auStack_88);
    _objc_destroyWeak(auStack_68);
  }
  _objc_release(param_4);
  CallSupervisor(0x9b5d);
  return;
}



// -[SBPlaybackController showSkippedToast:undoTime:], 0x197448
/* Decompiled from supplied 5.2.2 arm package. VA 0x197448. showSkippedToast:undoTime: */

/* Function Stack Size: 0x20 bytes */

void SBPlaybackController::showSkippedToast_undoTime_
               (ID param_1,SEL param_2,ID param_3,double param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  double dStack_a8;
  undefined **local_a0;
  int iStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011aaf10;
  local_7c = (uint)(DAT_01227858 == 0);
  local_90 = &PTR_LAB_011aaf30;
  ppuStack_88 = &PTR__objc_msgSend_011aa770;
  local_a0 = &PTR__objc_msgSend_011aa770;
  DAT_01227858 = 1;
  _objc_retain(param_3);
  iStack_94 = FUN_00199564(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                           @"sbNotifications");
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  if (iStack_94 != 0) {
    _objc_msgSend(param_3,@selector(category));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(stringWithFormat:);
    thunk_FUN_00199418(puVar2,@selector(stringWithFormat:),
                       @"sb_%@",uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar11 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(floatForKey:),
                           @"sbSkippedDuration");
    uVar4 = _objc_alloc_init(PTR_ToastView_0114ec98);
    puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar2 = @selector(ytl_localized);
    _objc_msgSend(@"SegmentSkipped",@selector(ytl_localized));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001994c4(puVar3,puVar1,uVar6,uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(imageWithName:),
                  @"backward.circle");
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c228;
    pcStack_c0 = FUN_00197b84;
    puStack_b8 = &DAT_01061810;
    IStack_b0 = param_1;
    dStack_a8 = param_4;
    _objc_msgSend(uVar11,uVar4,@selector(showProgressiveToastWithText:duration:actionIcon:actionCompletion:),uVar8,uVar10,
                  &puStack_d0);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar5);
  }
  _objc_release(param_3);
  CallSupervisor(0x5500);
  return;
}



// -[SBPlaybackController showSkipPromptToast:timeBeforeSkip:target:], 0x197be0
/* Decompiled from supplied 5.2.2 arm package. VA 0x197be0. showSkipPromptToast:timeBeforeSkip:target: */

/* Function Stack Size: 0x28 bytes */

void SBPlaybackController::showSkipPromptToast_timeBeforeSkip_target_
               (ID param_1,SEL param_2,ID param_3,double param_4,double param_5)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  ID IStack_d8;
  double dStack_d0;
  double dStack_c8;
  ID IStack_b8;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  
  local_88 = &PTR_LAB_011aaf50;
  local_8c = (uint)(DAT_01227868 == 0);
  local_a0 = &PTR_LAB_011aaf70;
  ppuStack_98 = &PTR__objc_msgSend_011aa770;
  local_b0 = &PTR__objc_msgSend_011aa770;
  DAT_01227868 = 1;
  _objc_retain(param_3);
  iStack_a4 = FUN_0019976c(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                           @"sbNotifications");
  puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar3 = @selector(category);
  if (iStack_a4 != 0) {
    IStack_b8 = param_1;
    _objc_msgSend(param_3,@selector(category));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(stringWithFormat:);
    thunk_FUN_001995b8(puVar4,@selector(stringWithFormat:),
                       @"sb_%@",uVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    uVar14 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(floatForKey:),
                           @"sbDuration");
    _objc_msgSend(param_3,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar5 = FUN_00199638(uVar6,@selector(isEqualToString:),
                         @"poi_highlight");
    _objc_release(uVar6);
    puVar3 = PTR_ToastView_0114ec98;
    ppuVar1 = @"SkipToSegment";
    if (iVar5 == 0) {
      ppuVar1 = @"SkipSegment";
    }
    _objc_retain(ppuVar1);
    uVar6 = _objc_alloc_init(puVar3);
    puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar3 = @selector(ytl_localized);
    _objc_msgSend(@"SegmentDetected",@selector(ytl_localized));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar3);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(ppuVar1,puVar3);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_release(ppuVar1);
    thunk_FUN_001996cc(puVar4,puVar2,uVar8,uVar9,uVar10);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,@selector(imageWithName:),
                  @"forward.circle");
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puStack_100 = PTR___NSConcreteStackBlock_01060660;
    uStack_f8 = DAT_00c4c228;
    pcStack_f0 = FUN_001985c4;
    puStack_e8 = &DAT_01062850;
    IStack_e0 = IStack_b8;
    dStack_d0 = param_5;
    _objc_retain(param_3);
    IStack_d8 = param_3;
    dStack_c8 = param_4;
    _objc_msgSend(uVar14,uVar6,@selector(showProgressiveToastWithText:duration:actionIcon:actionCompletion:),uVar11,uVar13,
                  &puStack_100);
    _objc_release(uVar13);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(IStack_d8);
    _objc_release(uVar7);
  }
  _objc_release(param_3);
  return;
}



// -[SBPlaybackController playSkipAudioIfNeeded], 0x198608
/* Decompiled from supplied 5.2.2 arm package. VA 0x198608. playSkipAudioIfNeeded */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::playSkipAudioIfNeeded(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01227878 = 1;
  iVar1 = FUN_001997f4(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"sbAudio");
  if (iVar1 != 0) {
    _objc_msgSend(PTR_AudioManager_0114eef0,@selector(sharedInstance));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(playAudio));
    _objc_release(uVar2);
  }
  CallSupervisor(0x4a51);
  return;
}



// -[SBPlaybackController dealloc], 0x1987ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1987ac. dealloc */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::dealloc(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSObject_0114ebc0,@selector(cancelPreviousPerformRequestsWithTarget:),
                param_1);
  puStack_28 = PTR_SBPlaybackController_0114f0d8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(dealloc));
  return;
}



// -[SBPlaybackController .cxx_destruct], 0x198804
/* Decompiled from supplied 5.2.2 arm package. VA 0x198804. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_destroyWeak(param_1 + 8);
  CallSupervisor(0x3b13);
  return;
}


