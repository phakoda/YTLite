// Decompiled hook evidence for YTMainAppVideoPlayerOverlayViewController. This is not compilable Logos source.

// -[YTMainAppVideoPlayerOverlayViewController shouldShowAutonavEndscreen], original IMP slot 0x01226450
/* Decompiled from supplied 5.2.2 arm package. VA 0x891dc. FUN_000891dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000891dc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cf0 = 1;
  iVar1 = FUN_000df524(@"autonavEndScreenCards");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008940c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226450)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTMainAppVideoPlayerOverlayViewController setFeaturedChannelWatermarkImageView:], original IMP slot 0x01226458
/* Decompiled from supplied 5.2.2 arm package. VA 0x89424. FUN_00089424 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00089424(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226cf4 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000df548(@"noWatermarks");
  if (iVar1 == 0) {
    (*_DAT_01226458)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x2924);
  return ZEXT816(0x1f);
}



// -[YTMainAppVideoPlayerOverlayViewController setPaidContentWithPlayerData:], original IMP slot 0x01226460
/* Decompiled from supplied 5.2.2 arm package. VA 0x89610. FUN_00089610 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00089610(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226cf8 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000df56c(@"noPromotionCards");
  if (iVar1 == 0) {
    (*_DAT_01226460)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xbce4);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTMainAppVideoPlayerOverlayViewController playerOverlayProvider:didInsertPlayerOverlay:], original IMP slot 0x01226468
/* Decompiled from supplied 5.2.2 arm package. VA 0x89834. FUN_00089834 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_00089834(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  DAT_01226cfc = 1;
  _objc_retain(param_3);
  uVar5 = _objc_retain(param_4);
  puVar2 = @selector(overlayIdentifier);
  _objc_msgSend(uVar5,@selector(overlayIdentifier));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(isEqualToString:);
  uVar3 = FUN_000df5fc(uVar5,@selector(isEqualToString:),
                       @"player_overlay_paid_content");
  if (uVar3 == 0) {
    _objc_release(uVar5);
  }
  else {
    iVar4 = FUN_000df5b4((&PTR_LAB_0117dc30)[uVar3] + (int)-(DAT_0117dc40 ^ 0x79abde1),
                         @"noPromotionCards");
    _objc_release(uVar5);
    if (iVar4 != 0) goto LAB_00089f64;
  }
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_000df644(uVar5,puVar1,@"player_overlay_product_in_video");
  if (uVar3 == 0) {
    _objc_release(uVar5);
  }
  else {
    iVar4 = FUN_000df590((&PTR_LAB_0117dc68)[uVar3] + (int)-(uRam000000000117dc78 ^ 0xac4e0234),
                         @"noAds");
    _objc_release(uVar5);
    if (iVar4 != 0) goto LAB_00089f64;
  }
  (*_DAT_01226468)(param_1,param_2,param_3,param_4);
LAB_00089f64:
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x7888);
  return ZEXT816(0x1f);
}



// -[YTMainAppVideoPlayerOverlayViewController selectedVarispeedLabelText], original IMP slot 0x01226470
/* Decompiled from supplied 5.2.2 arm package. VA 0x89fa8. FUN_00089fa8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00089fa8(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double dVar7;
  
  puVar1 = @selector(currentPlaybackRate);
  DAT_01226d00 = 1;
  dVar7 = (double)_objc_msgSend(param_1,@selector(currentPlaybackRate));
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  if (dVar7 == 1.0) {
    (*_DAT_01226470)(param_1,param_2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,puVar1);
    _objc_msgSend(puVar2,@selector(numberWithDouble:));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(stringValue));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_000df6d8(puVar3,@selector(stringWithFormat:),
                       @"%@x",uVar6);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return;
}



// -[YTMainAppVideoPlayerOverlayViewController allowDoubleTapToSeekGestureRecognizer], original IMP slot 0x01226478
/* Decompiled from supplied 5.2.2 arm package. VA 0x8a190. FUN_0008a190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008a190(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d04 = 1;
  iVar1 = FUN_000df714(@"noDoubleTapToSeek");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008a380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226478)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTMainAppVideoPlayerOverlayViewController allowTwoFingerDoubleTapGestureRecognizer], original IMP slot 0x01226480
/* Decompiled from supplied 5.2.2 arm package. VA 0x8a398. FUN_0008a398 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008a398(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d08 = 1;
  iVar1 = FUN_000df738(@"noTwoFingerSnapToChapter");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008a5f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226480)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTMainAppVideoPlayerOverlayViewController didPressPause:], original IMP slot 0x01226488
/* Decompiled from supplied 5.2.2 arm package. VA 0x8a610. FUN_0008a610 */

void FUN_0008a610(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d0c = 1;
  (*DAT_01226488)(param_1);
  uVar1 = FUN_000df808(@"copyWithTimestamp");
                    /* WARNING: Could not recover jumptable at 0x0008aa50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117dd90)[uVar1 & 0xffffffff] + (int)-(DAT_0117dda0 ^ 0xc563790b)))();
  return;
}



// -[YTMainAppVideoPlayerOverlayViewController setLoopMode:], original IMP slot 0x01226490
/* Decompiled from supplied 5.2.2 arm package. VA 0x8ab2c. FUN_0008ab2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008ab2c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  DAT_01226d10 = 1;
  (*_DAT_01226490)(param_1,param_2,param_3);
                    /* WARNING: Could not recover jumptable at 0x0008ac90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ddd0)[_canRememberLoopMode == '\0'] +
            (int)-(uRam000000000117dde0 ^ 0x38cefc01)))();
  return;
}



// -[YTMainAppVideoPlayerOverlayViewController viewDidLoad], original IMP slot 0x01226498
/* Decompiled from supplied 5.2.2 arm package. VA 0x8acfc. FUN_0008acfc */

undefined1  [16] FUN_0008acfc(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auVar13 [16];
  
  (*DAT_01226498)();
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  puVar4 = @selector(initWithTarget:action:);
  uVar8 = _objc_msgSend(uVar8,@selector(initWithTarget:action:),param_1,
                        @selector(handleTwoFingerTap:));
  _objc_msgSend(uVar8,@selector(setNumberOfTouchesRequired:),2);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(addGestureRecognizer:);
  _objc_msgSend(uVar9,@selector(addGestureRecognizer:),uVar8);
  _objc_release(uVar9);
  uVar9 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  uVar9 = _objc_msgSend(uVar9,puVar4,param_1,@selector(handleFingerPan:));
  puVar6 = @selector(setMinimumNumberOfTouches:);
  _objc_msgSend(uVar9,@selector(setMinimumNumberOfTouches:),1);
  puVar7 = @selector(setMaximumNumberOfTouches:);
  _objc_msgSend(uVar9,@selector(setMaximumNumberOfTouches:),1);
  puVar2 = @selector(setDelegate:);
  _objc_msgSend(uVar9,@selector(setDelegate:),param_1);
  _objc_msgSend(param_1,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar5,uVar9);
  _objc_release(uVar10);
  uVar10 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  puVar3 = @selector(handleHorizontalPan:);
  uVar10 = _objc_msgSend(uVar10,puVar4,param_1,@selector(handleHorizontalPan:));
  _objc_msgSend(uVar10,puVar6,1);
  _objc_msgSend(uVar10,puVar7,1);
  uVar11 = _objc_alloc_init(PTR_DVNHorizontalPanDelegate_0114eda0);
  _objc_setAssociatedObject(param_1,puVar3,uVar11,1);
  _objc_msgSend(uVar10,puVar2,uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar5,uVar10);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  CallSupervisor(0xaf51);
  auVar13._8_8_ = 0x1f;
  auVar13._0_8_ = 0x1a;
  return auVar13;
}



// -[YTMainAppVideoPlayerOverlayViewController handleTwoFingerTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x8af2c. FUN_0008af2c */

undefined1  [16] FUN_0008af2c(undefined8 param_1)

{
  int iVar1;
  
  DAT_01226d18 = 1;
  iVar1 = FUN_000dfb0c(@"twoFingerTap");
  if (iVar1 != 0) {
    _objc_msgSend(param_1,@selector(didTogglePlayPause));
  }
  CallSupervisor(0xd0fe);
  return ZEXT816(0x1f);
}



// -[YTMainAppVideoPlayerOverlayViewController gestureRecognizerShouldBegin:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x8b0e4. FUN_0008b0e4 */

uint FUN_0008b0e4(undefined1 param_1 [16],undefined1 param_2 [16],double param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  double dVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined *puVar7;
  float fVar8;
  double dVar9;
  
  DAT_01226d1c = 1;
  _objc_retain(param_6);
  uVar5 = _objc_msgSend(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90,@selector(class));
  uVar4 = FUN_000dfb94(param_6,@selector(isKindOfClass:),uVar5);
  puVar2 = @selector(view);
  puVar7 = (&PTR_LAB_0117de50)[uVar4] + (int)-(uRam000000000117de60 ^ 0x53a77bc8);
  if (uVar4 == 0) {
    uVar4 = 0;
    goto LAB_0008b658;
  }
  _objc_msgSend(param_4,@selector(view));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  dVar1 = (double)_objc_msgSend(param_6,@selector(locationInView:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(bounds));
  _objc_release(uVar5);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar5,@selector(floatForKey:),
                               @"gestWideness");
  dVar9 = (double)fVar8;
  _objc_release(uVar5);
  param_3 = param_3 - dVar9;
  if (dVar9 < dVar1) {
    uVar4 = 0;
    puVar7 = (&PTR_LAB_0117de88)[dVar1 < param_3] + (int)-(uRam000000000117de98 ^ 0x91555b07);
    uVar3 = 0;
    if (dVar1 < param_3) goto LAB_0008b650;
LAB_0008b600:
    lVar6 = _ytpInt(puVar7,@"rightGestureIndex");
    puVar7 = (undefined *)(ulong)(lVar6 != 0);
  }
  else {
    lVar6 = _ytpInt((&PTR_LAB_0117de68)[dVar9 < dVar1] + (int)-(uRam000000000117de78 ^ 0x344e9842),
                    @"leftGestureIndex");
    uVar4 = (uint)(lVar6 != 0);
    puVar7 = (&PTR_LAB_0117de88)[dVar1 < param_3] + (int)-(uRam000000000117de98 ^ 0x91555b07);
    uVar3 = uVar4;
    if (dVar1 >= param_3) goto LAB_0008b600;
LAB_0008b650:
    uVar4 = uVar3;
    puVar7 = (undefined *)0x0;
  }
  uVar4 = uVar4 | (uint)puVar7;
LAB_0008b658:
  _objc_release(puVar7,param_6);
  return uVar4;
}



// -[YTMainAppVideoPlayerOverlayViewController handleHorizontalPan:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x8b680. FUN_0008b680 */

void FUN_0008b680(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined *puVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  
  DAT_01226d20 = 1;
  _objc_retain(param_3);
  iVar8 = FUN_000dfffc(@"seekAnywhere");
  if (iVar8 == 0) goto LAB_0008c1f8;
  _objc_msgSend(param_1,@selector(playerBarController));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(playerBar));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar9);
  puVar5 = @selector(fineScrubberDidStartSeeking);
  puVar15 = @selector(respondsToSelector:);
  iVar8 = FUN_000e0064(uVar10,@selector(respondsToSelector:),
                       @selector(fineScrubberDidStartSeeking));
  puVar6 = @selector(fineScrubberDidSeekToTime:);
  if (((iVar8 != 0) &&
      (iVar8 = FUN_000dfea4(uVar10,puVar15,@selector(fineScrubberDidSeekToTime:)),
      puVar7 = @selector(fineScrubberDidEndSeekingWithSeekSource:), iVar8 != 0)) &&
     (iVar8 = FUN_000dff18(uVar10,puVar15,@selector(fineScrubberDidEndSeekingWithSeekSource:)),
     puVar4 = @selector(mediaTime), iVar8 != 0)) {
    dVar17 = (double)_objc_msgSend(param_1,@selector(mediaTime));
    dVar18 = (double)_objc_msgSend(param_1,@selector(maximumSeekableTime));
    puVar2 = @selector(view);
    _objc_msgSend(param_1,@selector(view));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(bounds));
    dVar19 = (double)_CGRectGetWidth();
    _objc_release(uVar9);
    puVar3 = @selector(state);
    lVar11 = _objc_msgSend(param_3,@selector(state));
    if (lVar11 == 1) {
      dVar17 = (double)_objc_msgSend((&PTR_LAB_0117df30)[lVar11 == 1] +
                                     (int)-(uRam000000000117df40 ^ 0x1b06245a),param_1,puVar4);
      _objc_msgSend(uVar10,puVar5);
    }
    else {
      dVar17 = (double)(long)dVar17;
    }
    lVar11 = _objc_msgSend(param_3,puVar3);
    if (lVar11 == 2) {
      dVar18 = (double)(long)dVar18;
      _objc_msgSend(param_1,puVar2);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      dVar20 = (double)_objc_msgSend(param_3,@selector(translationInView:),uVar9);
      _objc_release(uVar9);
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      fVar16 = (float)_objc_msgSend(uVar9,@selector(floatForKey:),
                                    @"seekSensitivity");
      _objc_release(uVar9);
      dVar20 = dVar20 * ((double)fVar16 / 10.0);
      lVar11 = _ytpInt(@"seekMethodIndex");
      if (lVar11 == 0) {
        dVar20 = (dVar18 / dVar19) * dVar20;
      }
      if (dVar17 + dVar20 <= dVar18) {
        dVar18 = dVar17 + dVar20;
      }
      if (dVar18 <= 0.0) {
        dVar18 = 0.0;
      }
      _objc_msgSend((&PTR_LAB_0117df68)[lVar11 == 0] + (int)-(DAT_0117df78 ^ 0x115fc05f),dVar18,
                    uVar10,puVar6);
      puVar5 = @selector(currentTimeLabel);
      iVar8 = FUN_000dfe5c(uVar10,puVar15,@selector(currentTimeLabel));
      if (iVar8 != 0) {
        uVar14 = (ulong)dVar18;
        iVar8 = (int)uVar14 +
                ((int)(SUB168(SEXT816((long)uVar14) * SEXT816(0x48d159e26af37c05),8) >> 10) -
                (SUB164(SEXT816((long)uVar14) * SEXT816(0x48d159e26af37c05),0xc) >> 0x1f)) * -0xe10;
        uVar1 = iVar8 + ((uint)((short)iVar8 * -0x7777) >> 0x10);
        if ((long)uVar14 < 0xe10) {
          thunk_FUN_000dfed8(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                             @"%ld:%02ld",
                             (long)(int)(((int)(uVar1 * 0x10000) >> 0x15) +
                                        ((uVar1 & 0x8000) >> 0xf)),(long)uVar14 % 0x3c);
          uVar9 = _objc_retainAutoreleasedReturnValue();
        }
        else {
          thunk_FUN_000e00b8(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                             @"%ld:%02ld:%02ld",uVar14 / 0xe10);
          uVar9 = _objc_retainAutoreleasedReturnValue();
        }
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,@selector(setText:),uVar9);
        _objc_release(uVar12);
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,@selector(sizeToFit));
        _objc_release(uVar12);
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,@selector(superview));
        uVar13 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x3ff0000000000000,uVar13,@selector(setAlpha:));
        _objc_release(uVar13);
        _objc_release(uVar12);
        _objc_release(uVar9);
      }
    }
    lVar11 = _objc_msgSend(param_3,puVar3);
    puVar15 = (&PTR_LAB_0117dfd0)[lVar11 == 3] + (int)-(DAT_0117dfe0 ^ 0x304febfa);
    if (lVar11 != 3) {
      lVar11 = _objc_msgSend(puVar15,param_3,puVar3);
      puVar15 = (&PTR_LAB_0117dfe8)[lVar11 == 4] + (int)-(uRam000000000117dff8 ^ 0x1b10e511);
      if (lVar11 != 4) goto LAB_0008c1f0;
    }
    _objc_msgSend(puVar15,uVar10,puVar7,0x19);
  }
LAB_0008c1f0:
  _objc_release(uVar10);
LAB_0008c1f8:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTMainAppVideoPlayerOverlayViewController handleFingerPan:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x8c228. FUN_0008c228 */

undefined1  [16]
FUN_0008c228(undefined1 param_1 [16],double param_2,double param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6)

{
  double *pdVar1;
  undefined *puVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  undefined **ppuVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  undefined1 auVar13 [16];
  
  DAT_01226d24 = 1;
  uVar4 = _objc_retain(param_6);
  puVar2 = @selector(state);
  lVar5 = _objc_msgSend(uVar4,@selector(state));
  puVar9 = @selector(view);
  if (lVar5 != 1) goto LAB_0008d2d8;
  _objc_msgSend((&PTR_LAB_0117e030)[lVar5 == 1] + (int)-(DAT_0117e040 ^ 0x4acf68ef),param_4,
                @selector(view));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  dVar12 = (double)_objc_msgSend(param_6,@selector(locationInView:),uVar4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar9);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(bounds));
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  fVar10 = (float)_objc_msgSend(uVar4,@selector(floatForKey:),
                                @"gestWideness");
  dVar11 = (double)fVar10;
  _objc_release(uVar4);
  puVar9 = (&PTR_LAB_0117e048)[dVar11 < dVar12] + (int)-(DAT_0117e058 ^ 0x3534a782);
  ppuVar6 = @"leftGestureIndex";
  if (dVar11 < dVar12) {
    bVar3 = dVar12 < param_3 - dVar11;
    puVar9 = (&PTR_LAB_0117e060)[bVar3] + (int)-(uRam000000000117e070 ^ 0x51fc75e);
    ppuVar6 = @"rightGestureIndex";
    if (!bVar3) goto LAB_0008d0b8;
    lRam000000000115cd20 = -1;
  }
  else {
LAB_0008d0b8:
    lRam000000000115cd20 = _ytpInt(puVar9,ppuVar6);
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  DAT_0115cd28 = (double)_objc_msgSend(uVar4,@selector(brightness));
  _objc_release(uVar4);
  if (DAT_012268d0 == 0) {
    DAT_012268d0 = _objc_getClass((&PTR_LAB_0117e080)[DAT_012268d0 == 0] +
                                  (int)-(DAT_0117e090 ^ 0x374cc5eb),s_LDVideoAdBlock_01168a20);
  }
  uVar4 = _objc_retainAutorelease();
  uVar4 = _objc_msgSend(uVar4,@selector(new));
  fVar10 = (float)_objc_msgSend(uVar4,@selector(systemVolume));
  DAT_0115cd30 = (double)fVar10;
  _objc_release(uVar4);
  lVar5 = lRam000000000115cd20;
  if (0 < lRam000000000115cd20) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    ppuVar6 = @"Toast.Brightness";
    if (lVar5 != 1) {
      ppuVar6 = @"Toast.Volume";
    }
    _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),ppuVar6,0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    bVar3 = lRam000000000115cd20 == 2;
    pdVar1 = &DAT_0115cd28;
    if (lRam000000000115cd20 != 1) {
      pdVar1 = &DAT_0115cd30;
    }
    dVar12 = *pdVar1;
    param_2 = 100.0;
    _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar7 = FUN_000e03f8(@"compactToast");
    _objc_msgSend((double)(long)(dVar12 * 100.0),uVar4,
                  @selector(showPlayerToastWithText:value:style:isCompact:),uVar8,(ulong)bVar3 << 1,uVar7);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
LAB_0008d2d8:
  lVar5 = _objc_msgSend(param_6,puVar2);
  bVar3 = lVar5 != 2;
  if ((!bVar3 && lRam000000000115cd20 != 0) && (bVar3 || -1 < lRam000000000115cd20)) {
    _objc_msgSend((&PTR_LAB_0117e0c0)
                  [(!bVar3 && lRam000000000115cd20 != 0) && (bVar3 || -1 < lRam000000000115cd20)] +
                  (int)-(DAT_0117e0d0 ^ 0x5607fa93),param_4,@selector(view));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_6,@selector(translationInView:),uVar4);
    _objc_release(uVar4);
    if (lRam000000000115cd20 == 1) {
      dVar11 = DAT_0115cd28 + DAT_00c4c310 * -param_2;
      dVar12 = 1.0;
      if (dVar11 <= 1.0) {
        dVar12 = dVar11;
      }
      if (dVar12 <= 0.0) {
        dVar12 = 0.0;
      }
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),
                    @"Toast.Brightness",0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      dVar11 = DAT_0115cd30 + DAT_00c4c318 * -param_2;
      dVar12 = 1.0;
      if (dVar11 <= 1.0) {
        dVar12 = dVar11;
      }
      if (dVar12 <= 0.0) {
        dVar12 = 0.0;
      }
      _objc_msgSend();
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),
                    @"Toast.Volume",0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
    }
    _objc_release(uVar4);
    _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar12,uVar4,@selector(updateToastText:value:),uVar8);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
  lVar5 = _objc_msgSend(param_6,puVar2);
  if (lVar5 != 3) {
    lVar5 = _objc_msgSend((&PTR_LAB_0117e108)[lVar5 == 3] + (int)-(DAT_0117e118 ^ 0xd0719b5e),
                          param_6,puVar2);
    if (lVar5 != 4) {
      _objc_release((&PTR_LAB_0117e120)[lVar5 == 4] + (int)-(uRam000000000117e130 ^ 0x25e75bfe),
                    param_6);
      CallSupervisor(0x60f8);
      auVar13._8_8_ = 0x1f;
      auVar13._0_8_ = 0x1a;
      return auVar13;
    }
  }
  lRam000000000115cd20 = 0xffffffffffffffff;
  DAT_0115cd28 = -1.0;
  DAT_0115cd30 = -1.0;
  _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  dVar12 = (double)_objc_msgSend(uVar4,@selector(alpha));
  _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x0008d59c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar13 = (*(code *)((&PTR_LAB_0117e138)[dVar12 == 0.0] + (int)-(uRam000000000117e148 ^ 0x1475e04)
                      ))();
  return auVar13;
}


