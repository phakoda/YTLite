// Decompiled hook evidence for YTInlineMutedPlaybackPlayerOverlayViewController. This is not compilable Logos source.

// -[YTInlineMutedPlaybackPlayerOverlayViewController scrubbingUIStyle], original IMP slot 0x012262f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x7f940. FUN_0007f940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007f940(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c20 = 1;
  uVar1 = FUN_000dd238(@"downloadManager");
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd25c((&PTR_LAB_0117cd68)[uVar1] + (int)-(uRam000000000117cd78 ^ 0xbbc1046),
                           @"sponsorBlock"), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007fc28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262f0)(param_1,param_2);
    return uVar3;
  }
  return 2;
}



// -[YTInlineMutedPlaybackPlayerOverlayViewController setPaidContentWithPlayerData:], original IMP slot 0x012262f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x7fc40. FUN_0007fc40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007fc40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226c24 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000dd280(@"noPromotionCards");
  if (iVar1 == 0) {
    (*_DAT_012262f8)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x97b9);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTInlineMutedPlaybackPlayerOverlayViewController viewDidLoad], original IMP slot 0x01226300
/* Decompiled from supplied 5.2.2 arm package. VA 0x7fe60. FUN_0007fe60 */

void FUN_0007fe60(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  (*DAT_01226300)();
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  uVar1 = _objc_msgSend(uVar1,@selector(initWithTarget:action:),param_1,
                        @selector(handleHorizontalPan:));
  _objc_msgSend(uVar1,@selector(setMinimumNumberOfTouches:),1);
  _objc_msgSend(uVar1,@selector(setMaximumNumberOfTouches:),1);
  _objc_msgSend(uVar1,@selector(setDelegate:),param_1);
  _objc_msgSend(param_1,@selector(view));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(addGestureRecognizer:),uVar1);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return;
}



// -[YTInlineMutedPlaybackPlayerOverlayViewController gestureRecognizerShouldBegin:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ff20. FUN_0007ff20 */

bool FUN_0007ff20(undefined1 param_1 [16],double param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  double dVar3;
  
  puVar1 = @selector(view);
  _objc_retain(param_5);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  dVar3 = (double)_objc_msgSend(param_5,@selector(velocityInView:),uVar2);
  _objc_release(param_5);
  _objc_release(uVar2);
  return ABS(param_2) < ABS(dVar3);
}



// -[YTInlineMutedPlaybackPlayerOverlayViewController gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ffb4. FUN_0007ffb4 */

undefined8 FUN_0007ffb4(void)

{
  return 1;
}



// -[YTInlineMutedPlaybackPlayerOverlayViewController handleHorizontalPan:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ffbc. FUN_0007ffbc */

undefined1  [16] FUN_0007ffbc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  float fVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined1 auVar16 [16];
  
  DAT_01226c34 = 1;
  _objc_retain(param_3);
  iVar5 = FUN_000dd3c4(@"seekAnywhereFeed");
  puVar1 = @selector(parentViewController);
  if (iVar5 != 0) {
    _objc_msgSend(param_1,@selector(parentViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    if (DAT_01226898 == 0) {
      DAT_01226898 = _objc_getClass((&PTR_LAB_0117ce18)[DAT_01226898 == 0] +
                                    (int)-(uRam000000000117ce28 ^ 0xcf551c09),
                                    s_YTPlayerViewController_011667a0);
    }
    lVar9 = DAT_01226898;
    _objc_retainAutorelease(DAT_01226898);
    uVar6 = FUN_000dd5cc(uVar7,@selector(isKindOfClass:),lVar9);
    _objc_release(uVar7);
    if (uVar6 != 0) {
      _objc_msgSend((&PTR_LAB_0117ce38)[uVar6] + (int)-(uRam000000000117ce48 ^ 0x8510a3),param_1,
                    puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(seekToTime:);
      iVar5 = FUN_000dd694(uVar7,@selector(respondsToSelector:),@selector(seekToTime:));
      if (iVar5 != 0) {
        dVar12 = (double)_objc_msgSend(param_1,@selector(totalTime));
        puVar2 = @selector(view);
        _objc_msgSend(param_1,@selector(view));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,@selector(bounds));
        dVar13 = (double)_CGRectGetWidth();
        _objc_release(uVar8);
        puVar3 = @selector(state);
        lVar9 = _objc_msgSend(param_3,@selector(state));
        puVar4 = PTR__OBJC_CLASS___NSNumber_0114eb00;
        if (lVar9 == 1) {
          _objc_msgSend(param_1,@selector(mediaTime));
          _objc_msgSend(puVar4,@selector(numberWithDouble:));
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_setAssociatedObject(param_1,s_initialPanTime_0116676f,uVar8,1);
          _objc_release(uVar8);
        }
        lVar9 = _objc_msgSend(param_3,puVar3);
        if (lVar9 == 2) {
          _objc_getAssociatedObject
                    ((&PTR_LAB_0117ce88)[lVar9 == 2] + (int)-(uRam000000000117ce98 ^ 0xf6c896bd),
                     param_1,s_initialPanTime_0116676f);
          lVar9 = _objc_retainAutoreleasedReturnValue();
          if (lVar9 == 0) {
            dVar14 = (double)_objc_msgSend(param_1,@selector(mediaTime));
          }
          else {
            dVar14 = (double)_objc_msgSend(lVar9,@selector(doubleValue));
          }
          dVar12 = (double)(long)dVar12;
          _objc_msgSend(param_1,puVar2);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          dVar15 = (double)_objc_msgSend(param_3,@selector(translationInView:),uVar8);
          _objc_release(uVar8);
          _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
          uVar8 = _objc_retainAutoreleasedReturnValue();
          fVar11 = (float)_objc_msgSend(uVar8,@selector(floatForKey:),
                                        @"seekSensitivity");
          _objc_release(uVar8);
          dVar15 = dVar15 * ((double)fVar11 / 10.0);
          lVar10 = _ytpInt(@"seekMethodIndex");
          if (lVar10 == 0) {
            dVar15 = (dVar12 / dVar13) * dVar15;
          }
          if (dVar14 + dVar15 <= dVar12) {
            dVar12 = dVar14 + dVar15;
          }
          if (dVar12 <= 0.0) {
            dVar12 = 0.0;
          }
          _objc_msgSend((&PTR__MSHookMessageEx_0117cec8)[lVar10 == 0] +
                        (int)-(uRam000000000117ced8 ^ 0x89261209),dVar12,uVar7,puVar1);
          _objc_release(lVar9);
        }
      }
      _objc_release(uVar7);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0x9715);
  auVar16._8_8_ = 0x1f;
  auVar16._0_8_ = 0x1a;
  return auVar16;
}


