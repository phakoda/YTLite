// Decompiled hook evidence for YTPlayerViewController. This is not compilable Logos source.

// -[YTPlayerViewController playbackController:didActivateVideo:withPlaybackData:], original IMP slot 0x1225850
/* Decompiled from supplied 5.2.2 arm package. VA 0x8c38. FUN_00008c38 */

void FUN_00008c38(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258a8 = 1;
  (*pcRam0000000001225850)(param_1);
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(@"YTInlineMutedPlaybackWatchViewController");
  uVar3 = FUN_0000bad8(uVar1,@selector(isKindOfClass:),uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0000916c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011512d0)[uVar3 & 0xffffffff] + (int)-(DAT_011512e0 ^ 0x762bd33b)))();
  return;
}



// -[YTPlayerViewController seekToTime:], original IMP slot 0x1225858
/* Decompiled from supplied 5.2.2 arm package. VA 0x92b8. FUN_000092b8 */

void FUN_000092b8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258ac = 1;
  (*pcRam0000000001225858)(param_1,param_2);
  _objc_msgSend(param_2,@selector(parentViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(@"YTInlineMutedPlaybackWatchViewController");
  uVar3 = FUN_0000bd10(uVar1,@selector(isKindOfClass:),uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000098ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151328)[uVar3 & 0xffffffff] + (int)-(uRam0000000001151338 ^ 0x8e2cc8e0)))()
  ;
  return;
}



// -[YTPlayerViewController seekToTime:seekSource:], original IMP slot 0x1225860
/* Decompiled from supplied 5.2.2 arm package. VA 0x9a00. recovered_hook_00009a00 */

void recovered_hook_00009a00(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uRam00000000012258b0 = 1;
  (*pcRam0000000001225860)(param_1,param_2);
  _objc_msgSend(param_2,@selector(parentViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(@"YTInlineMutedPlaybackWatchViewController");
  uVar3 = FUN_0000be88(uVar1,@selector(isKindOfClass:),uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00009ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151398)[uVar3 & 0xffffffff] + (int)-(DAT_011513a8 ^ 0xad76b9e9)))();
  return;
}



// -[YTPlayerViewController seekToTime:toleranceBefore:toleranceAfter:seekSource:], original IMP slot 0x1225868
/* Decompiled from supplied 5.2.2 arm package. VA 0xa14c. FUN_0000a14c */

void FUN_0000a14c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258b4 = 1;
  (*pcRam0000000001225868)(param_1,param_2);
  _objc_msgSend(param_2,@selector(parentViewController));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(@"YTInlineMutedPlaybackWatchViewController");
  uVar3 = FUN_0000c000(uVar1,@selector(isKindOfClass:),uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0000a748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151408)[uVar3 & 0xffffffff] + (int)-(uRam0000000001151418 ^ 0x7d3ed7eb)))()
  ;
  return;
}



// -[YTPlayerViewController singleVideo:currentVideoTimeDidChange:], original IMP slot 0x1225870
/* Decompiled from supplied 5.2.2 arm package. VA 0xa89c. FUN_0000a89c */

void FUN_0000a89c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_012258b8 = 1;
  _objc_retain(param_4);
  (*pcRam0000000001225870)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0000c110(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
                    /* WARNING: Could not recover jumptable at 0x0000aa50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151478)[uVar1 & 0xffffffff] + (int)-(DAT_01151488 ^ 0xe257a351)))();
  return;
}



// -[YTPlayerViewController potentiallyMutatedSingleVideo:currentVideoTimeDidChange:], original IMP slot 0x1225878
/* Decompiled from supplied 5.2.2 arm package. VA 0xaafc. FUN_0000aafc */

void FUN_0000aafc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_012258bc = 1;
  _objc_retain(param_4);
  (*pcRam0000000001225878)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0000c138(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
                    /* WARNING: Could not recover jumptable at 0x0000aca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011514b8)[uVar1 & 0xffffffff] + (int)-(uRam00000000011514c8 ^ 0x1f343ba7)))()
  ;
  return;
}



// -[YTPlayerViewController sbPlaybackController], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x1df7c. FUN_0001df7c */

void FUN_0001df7c(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0001df7c);
  return;
}



// -[YTPlayerViewController setSbPlaybackController:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x1df88. FUN_0001df88 */

undefined1  [16] FUN_0001df88(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0001df7c,param_3,1);
  CallSupervisor(0x1316);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTPlayerViewController playbackController:didActivateVideo:withPlaybackData:], original IMP slot 0x01225c28
/* Decompiled from supplied 5.2.2 arm package. VA 0x2039c. FUN_0002039c */

void FUN_0002039c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225cd8 = 1;
  (*DAT_01225c28)(param_1);
  uVar1 = FUN_00022d50(param_1,@selector(isPlayingAd));
                    /* WARNING: Could not recover jumptable at 0x00020780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156438)[uVar1 & 0xffffffff] + (int)-(DAT_01156448 ^ 0xf3251696)))();
  return;
}



// -[YTPlayerViewController singleVideo:currentVideoTimeDidChange:], original IMP slot 0x1225c30
/* Decompiled from supplied 5.2.2 arm package. VA 0x20920. FUN_00020920 */

void FUN_00020920(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_01225cdc = 1;
  _objc_retain(param_3);
  (*pcRam0000000001225c30)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_00022df8(@"sponsorBlock");
                    /* WARNING: Could not recover jumptable at 0x00020b94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011564e0)[uVar1 & 0xffffffff] + (int)-(uRam00000000011564f0 ^ 0x56491f80)))()
  ;
  return;
}



// -[YTPlayerViewController potentiallyMutatedSingleVideo:currentVideoTimeDidChange:], original IMP slot 0x1225c38
/* Decompiled from supplied 5.2.2 arm package. VA 0x20c50. FUN_00020c50 */

void FUN_00020c50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_01225ce0 = 1;
  _objc_retain(param_3);
  (*pcRam0000000001225c38)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_00022e1c(@"sponsorBlock");
                    /* WARNING: Could not recover jumptable at 0x00020f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156538)[uVar1 & 0xffffffff] + (int)-(uRam0000000001156548 ^ 0xea2bba1b)))()
  ;
  return;
}



// -[YTPlayerViewController playbackController:didActivateVideo:withPlaybackData:], original IMP slot 0x01226638
/* Decompiled from supplied 5.2.2 arm package. VA 0xa36d0. FUN_000a36d0 */

void FUN_000a36d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  
  puVar2 = PTR_YTPSleepTimer_0114eaf0;
  puVar1 = @selector(sharedTimer);
  DAT_01226e00 = 1;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(cancelIfPlayerClosed));
  _objc_release(uVar3);
  _canRememberLoopMode = 0;
  (*DAT_01226638)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  lVar4 = _ytpInt(@"wiFiQualityIndex");
                    /* WARNING: Could not recover jumptable at 0x000a3f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01180370)[lVar4 == 0] + (int)-(DAT_01180380 ^ 0xc5ebab7)))();
  return;
}



// -[YTPlayerViewController restoreLoopMode], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa4158. FUN_000a4158 */

void FUN_000a4158(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  
  puVar2 = @selector(activeVideoPlayerOverlay);
  DAT_01226e04 = 1;
  _objc_msgSend(param_1,@selector(activeVideoPlayerOverlay));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_01180468)[DAT_01226890 == 0] +
                                  (int)-(uRam0000000001180478 ^ 0x5338d20a),
                                  s_YTMainAppVideoPlayerOverlayViewC_0116d2d0);
  }
  lVar7 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  puVar1 = @selector(isKindOfClass:);
  uVar4 = FUN_000e5d6c(uVar5,@selector(isKindOfClass:),lVar7);
  _objc_release(uVar5);
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_01180488)[uVar4] + (int)-(uRam0000000001180498 ^ 0x38527669),param_1,
                  puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar4 = FUN_000e5d24(uVar5,@selector(respondsToSelector:),@selector(loopMode));
    if (uVar4 != 0) {
      uVar6 = _ytpInt((&PTR_LAB_011804a0)[uVar4] + (int)-(uRam00000000011804b0 ^ 0xaf09b6a8),
                      @"loopMode");
      _objc_msgSend(uVar5,@selector(setLoopMode:),uVar6);
    }
    _objc_release(uVar5);
  }
  puVar3 = @selector(activeVideo);
  _objc_msgSend(param_1,@selector(activeVideo));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(delegate);
  _objc_msgSend(uVar5,@selector(delegate));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001226900 == 0) {
    lRam0000000001226900 =
         _objc_getClass((&PTR_LAB_011804c8)[lRam0000000001226900 == 0] +
                        (int)-(uRam00000000011804d8 ^ 0xe4349ad6),
                        s_YTLocalPlaybackController_0116d270);
  }
  lVar7 = lRam0000000001226900;
  _objc_retainAutorelease(lRam0000000001226900);
  uVar4 = FUN_000e5bd4(uVar6,puVar1,lVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011804e8)[uVar4] + (int)-(uRam00000000011804f8 ^ 0xeb9a0c76),param_1,
                  puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    uVar4 = FUN_000e5cbc(uVar6,@selector(respondsToSelector:),@selector(loopingEnabled));
    if ((uVar4 != 0) &&
       (lVar7 = _ytpInt((&PTR_LAB_01180500)[uVar4] + (int)-(uRam0000000001180510 ^ 0xc41b1599),
                        @"loopMode"), lVar7 != 0)) {
      _objc_msgSend(uVar6,@selector(setLoopingEnabled:),1);
    }
    _objc_release(uVar6);
  }
  _canRememberLoopMode = 1;
  return;
}



// -[YTPlayerViewController autoFullscreen], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa4a00. FUN_000a4a00 */

undefined1  [16] FUN_000a4a00(undefined8 param_1)

{
  undefined8 uVar1;
  
  DAT_01226e08 = 1;
  _objc_msgSend(param_1,@selector(valueForKey:),@"_UIDelegate")
  ;
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(showFullScreen));
  _objc_release(uVar1);
  CallSupervisor(0x4afd);
  return ZEXT816(0x1f);
}



// -[YTPlayerViewController setAutoSpeed], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa4b94. FUN_000a4b94 */

void FUN_000a4b94(undefined8 param_1)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  float fVar13;
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
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_01180560;
  local_74 = (uint)(DAT_01226e0c == 0);
  local_88 = &PTR_LAB_01180580;
  ppuStack_80 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_011805a0;
  ppuStack_98 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01175340;
  DAT_01226e0c = 1;
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_8c = (uint)(DAT_01226908 == 0);
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass(local_88[uStack_8c] + (int)-(DAT_01180590 ^ 0xf7153a06),
                                  s_YTWatchViewController_0116d3e0);
  }
  lVar2 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  iVar3 = FUN_000e5df4(uVar4,@selector(isKindOfClass:),lVar2);
  _objc_release(uVar4);
  puVar1 = @selector(numberWithDouble:);
  iStack_a4 = iVar3;
  if (iVar3 != 0) {
    uStack_b8 = param_1;
    _objc_msgSend(0x3fd0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  @selector(numberWithDouble:));
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_c0 = uStack_130;
    _objc_msgSend(0x3fe0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uStack_128 = _objc_retainAutoreleasedReturnValue();
    uStack_c8 = uStack_128;
    _objc_msgSend(0x3fe8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uStack_120 = _objc_retainAutoreleasedReturnValue();
    uStack_d0 = uStack_120;
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_118 = uVar4;
    _objc_msgSend(0x3ff4000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_110 = uVar5;
    _objc_msgSend(0x3ff8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_108 = uVar6;
    _objc_msgSend(0x3ffc000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_100 = uVar7;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uStack_f8 = uVar8;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uStack_f0 = uVar9;
    _objc_msgSend(0x4010000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_e8 = uVar10;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uStack_e0 = uVar11;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_130,0xb);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uStack_d0);
    _objc_release(uStack_c8);
    _objc_release(uStack_c0);
    puVar1 = PTR_YTPSpeedMaster_0114eca0;
    uVar4 = _ytpInt(@"autoSpeedIndex");
    _objc_msgSend(uVar12,@selector(objectAtIndexedSubscript:),uVar4);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    fVar13 = (float)_objc_msgSend(uVar4,@selector(floatValue));
    _objc_msgSend((double)fVar13,puVar1,@selector(setPlaybackRate:forPlayer:),uStack_b8);
    _objc_release(uVar4);
    _objc_release(uVar12);
  }
  CallSupervisor(0x764f);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[YTPlayerViewController selectCaptions], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa51f0. FUN_000a51f0 */

void FUN_000a51f0(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  DAT_01226e10 = 1;
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass((&PTR_LAB_011805e0)[DAT_01226908 == 0] +
                                  (int)-(DAT_011805f0 ^ 0x7c824290),s_YTWatchViewController_0116d4c0
                                 );
  }
  lVar5 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  iVar2 = FUN_000e61e4(uVar4,@selector(isKindOfClass:),lVar5);
  _objc_release(uVar4);
  puVar1 = @selector(activeVideo);
  if (iVar2 != 0) {
    _objc_msgSend(param_1,@selector(activeVideo));
    lVar5 = _objc_retainAutoreleasedReturnValue();
    if (lVar5 != 0) {
      uVar3 = FUN_000e69e0(param_1,@selector(isMDXActive));
      _objc_release(lVar5);
      if (uVar3 == 0) {
        _objc_msgSend((&PTR_LAB_01180630)[uVar3] + (int)-(uRam0000000001180640 ^ 0x9a0c3819),param_1
                      ,puVar1);
        uVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar4,@selector(availableCaptionTracks));
        lVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_release();
        _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x000a5aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((&PTR_LAB_01180648)[lVar6 == 0] + (int)-(uRam0000000001180658 ^ 0x4f4fd53e)))();
        return;
      }
    }
  }
  CallSupervisor(0xb717);
  if (*(long *)PTR____stack_chk_guard_01060708 != lVar6) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[YTPlayerViewController autoQuality], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa6b30. FUN_000a6b30 */

void FUN_000a6b30(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puVar5;
  undefined1 auStack_5a0 [192];
  undefined1 auStack_4e0 [176];
  undefined1 auStack_430 [128];
  undefined1 auStack_3b0 [136];
  undefined1 *puStack_328;
  undefined1 *puStack_308;
  undefined1 *puStack_300;
  undefined1 *puStack_2e0;
  undefined **local_2d0;
  undefined **ppuStack_2c8;
  undefined **local_2b8;
  undefined **ppuStack_2b0;
  undefined **local_2a0;
  undefined **local_298;
  undefined **ppuStack_290;
  undefined **local_280;
  undefined **local_270;
  undefined **local_268;
  undefined **ppuStack_260;
  undefined **local_250;
  undefined **local_240;
  undefined **local_230;
  undefined **ppuStack_228;
  undefined **local_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b0;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01180a10;
  local_7c = (uint)(DAT_01226e14 == 0);
  local_90 = &PTR_LAB_01180a30;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a8 = &PTR_LAB_01180a50;
  ppuStack_a0 = &PTR_LAB_01175340;
  local_c0 = &PTR_LAB_01180a70;
  ppuStack_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR__objc_msgSend_01180a90;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_e8 = &PTR__objc_msgSend_01180aa8;
  local_100 = &PTR_LAB_01180ac8;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_110 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR_LAB_01180af0;
  local_130 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_01180b10;
  local_148 = &PTR_LAB_01180b28;
  local_160 = &PTR_LAB_01180b48;
  local_170 = &PTR__objc_msgSend_01180b60;
  local_180 = &PTR__objc_msgSend_01180b78;
  local_158 = &PTR_LAB_01175340;
  local_190 = &PTR_LAB_01180b90;
  local_1a8 = &PTR_LAB_01175340;
  ppuStack_1a0 = &PTR_LAB_01175340;
  local_1b0 = &PTR_LAB_01180bb8;
  local_1c8 = &PTR_LAB_01180bd8;
  ppuStack_1c0 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_01180bf0;
  local_1e8 = &PTR_LAB_01180c08;
  local_1f8 = &PTR__objc_msgSend_01180c20;
  local_210 = &PTR_LAB_01175340;
  ppuStack_208 = &PTR_LAB_01175340;
  local_218 = &PTR_LAB_01180c48;
  local_230 = &PTR_LAB_01180c68;
  ppuStack_228 = &PTR_LAB_01175340;
  local_240 = &PTR_LAB_01180c80;
  local_250 = &PTR_LAB_01180c98;
  local_268 = &PTR_LAB_01175340;
  ppuStack_260 = &PTR_LAB_01175340;
  local_270 = &PTR__objc_msgSend_01180cc0;
  local_280 = &PTR__objc_msgSend_01180cd8;
  local_298 = &PTR_LAB_01175340;
  ppuStack_290 = &PTR_LAB_01175340;
  local_2a0 = &PTR_LAB_01180d00;
  local_2b8 = &PTR_LAB_01180d20;
  ppuStack_2b0 = &PTR_LAB_01175340;
  local_2d0 = &PTR_LAB_01175340;
  ppuStack_2c8 = &PTR_LAB_01175340;
  DAT_01226e14 = 1;
  puStack_2e0 = auStack_3b0;
  puStack_300 = auStack_430;
  puStack_328 = auStack_5a0;
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(DAT_01226908 == 0);
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_01180a40 ^ 0x56cb3cab),
                                  s_YTWatchViewController_0116d720);
  }
  lVar4 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  uStack_ac = FUN_000e6f78(uVar3,@selector(isKindOfClass:),lVar4);
  puVar1 = @selector(activeVideo);
  puVar5 = local_a8[uStack_ac] + (int)-(DAT_01180a60 ^ 0xc53b702a);
  if (uStack_ac != 0) {
    _objc_msgSend(param_1,@selector(activeVideo));
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    puVar5 = local_c0[uStack_c4] + (int)-(uRam0000000001180a80 ^ 0xd0dadd2);
    if (lVar4 != 0) {
      puStack_308 = auStack_4e0;
      uVar2 = FUN_000e6a98(param_1,@selector(isMDXActive));
      _objc_release(lVar4);
      _objc_release(uVar3);
      uStack_dc = uVar2;
      if (uVar2 == 0) {
        _objc_msgSend(local_d8[uVar2] + (int)-(DAT_01180aa0 ^ 0xefbdff5f),param_1,puVar1);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,@selector(selectableVideoFormats));
        lVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_release();
        _objc_release(uVar3);
        uStack_ec = (uint)(lVar4 == 0);
                    /* WARNING: Could not recover jumptable at 0x000a7b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_e8[uStack_ec] + (int)-(DAT_01180ab8 ^ 0x7a37a251)))();
        return;
      }
      goto LAB_000a80a0;
    }
  }
  _objc_release(puVar5,uVar3);
LAB_000a80a0:
  CallSupervisor(0x79d);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[YTPlayerViewController selectAudioTrack], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa8894. FUN_000a8894 */

void FUN_000a8894(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 auStack_3c0 [272];
  undefined1 *puStack_2b0;
  undefined **local_288;
  undefined **ppuStack_280;
  undefined **local_270;
  undefined **local_268;
  undefined **ppuStack_260;
  undefined **local_250;
  undefined **ppuStack_248;
  undefined **local_238;
  undefined **local_228;
  undefined **ppuStack_220;
  undefined **local_210;
  undefined **local_200;
  undefined **ppuStack_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_168;
  undefined **local_160;
  undefined **ppuStack_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **ppuStack_108;
  undefined **local_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  undefined **local_d8;
  undefined **local_c8;
  undefined **ppuStack_c0;
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
  
  puVar1 = @selector(activeVideo);
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01180d48;
  local_7c = (uint)(DAT_01226e18 == 0);
  local_90 = &PTR_LAB_01180d68;
  local_a0 = &PTR_LAB_01180d80;
  local_b0 = &PTR_LAB_01180d98;
  local_88 = &PTR_LAB_01175340;
  local_c8 = &PTR_LAB_01180db8;
  ppuStack_c0 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01180dd0;
  local_f0 = &PTR_LAB_01175340;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_f8 = &PTR_LAB_01180df8;
  local_110 = &PTR_LAB_01180e18;
  ppuStack_108 = &PTR_LAB_01175340;
  local_128 = &PTR_LAB_01180e38;
  ppuStack_120 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_01180e50;
  local_148 = &PTR_LAB_01180e68;
  local_160 = &PTR_LAB_01175340;
  ppuStack_158 = &PTR_LAB_01175340;
  local_168 = &PTR_LAB_01180e90;
  local_180 = &PTR_LAB_01180eb0;
  ppuStack_178 = &PTR_LAB_01175340;
  local_190 = &PTR_LAB_01180ec8;
  local_1a8 = &PTR_LAB_01180ee8;
  ppuStack_1a0 = &PTR_LAB_01175340;
  local_1c0 = &PTR_LAB_01175340;
  ppuStack_1b8 = &PTR_LAB_01175340;
  local_1c8 = &PTR_LAB_01180f10;
  local_1d8 = &PTR_LAB_01180f28;
  local_1e8 = &PTR_LAB_01180f40;
  local_200 = &PTR_LAB_01180f60;
  ppuStack_1f8 = &PTR_LAB_01175340;
  local_210 = &PTR_LAB_01180f78;
  local_228 = &PTR_LAB_01180f98;
  ppuStack_220 = &PTR_LAB_01175340;
  local_238 = &PTR_LAB_01180fb0;
  local_250 = &PTR_LAB_01180fd0;
  ppuStack_248 = &PTR_LAB_01175340;
  local_268 = &PTR_LAB_01175340;
  ppuStack_260 = &PTR_LAB_01175340;
  local_270 = &PTR_LAB_01180ff8;
  local_288 = &PTR_LAB_01175340;
  ppuStack_280 = &PTR_LAB_01175340;
  DAT_01226e18 = 1;
  puStack_2b0 = auStack_3c0;
  _objc_msgSend(param_1,@selector(activeVideo));
  lVar3 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    uVar2 = FUN_000e7310(param_1,@selector(isMDXActive));
    _objc_release(lVar3);
    uStack_a4 = uVar2;
    if (uVar2 == 0) {
      _objc_msgSend(local_a0[uVar2] + (int)-(uRam0000000001180d90 ^ 0x6badf75c),param_1,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(selectableAudioFormats));
      lVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
      _objc_release(uVar4);
      uStack_b4 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x000a9158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_b0[uStack_b4] + (int)-(uRam0000000001180da8 ^ 0xc467b091)))();
      return;
    }
  }
  CallSupervisor(0x2936);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[YTPlayerViewController singleVideo:currentVideoTimeDidChange:], original IMP slot 0x01226640
/* Decompiled from supplied 5.2.2 arm package. VA 0xa9c2c. FUN_000a9c2c */

undefined1  [16]
FUN_000a9c2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
  pcVar1 = DAT_01226640;
  _objc_retain(param_4);
  _objc_retain(param_3);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  _addEndTime(param_1,param_3,param_4);
  _autoSkipShortsLegacy(param_1,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xe00b);
  return ZEXT816(0x1f);
}



// -[YTPlayerViewController potentiallyMutatedSingleVideo:currentVideoTimeDidChange:], original IMP slot 0x01226648
/* Decompiled from supplied 5.2.2 arm package. VA 0xa9cd8. FUN_000a9cd8 */

undefined1  [16]
FUN_000a9cd8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
  pcVar1 = DAT_01226648;
  _objc_retain(param_4);
  _objc_retain(param_3);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  _addEndTime(param_1,param_3,param_4);
  _autoSkipShortsLegacy(param_1,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xb824);
  return ZEXT816(0x1f);
}



// -[YTPlayerViewController dealloc], original IMP slot 0x01226650
/* Decompiled from supplied 5.2.2 arm package. VA 0xa9d84. FUN_000a9d84 */

undefined1  [16] FUN_000a9d84(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  _objc_msgSend(PTR_YTPSleepTimer_0114eaf0,@selector(sharedTimer));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(cancelIfPlayerClosed));
  _objc_release(uVar1);
  (*DAT_01226650)(param_1,param_2);
  CallSupervisor(0x4c39);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


