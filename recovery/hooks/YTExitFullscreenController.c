// Decompiled hook evidence for YTExitFullscreenController. This is not compilable Logos source.

// -[YTExitFullscreenController gestureRecognizerShouldBegin:], original IMP slot 0x01226678
/* Decompiled from supplied 5.2.2 arm package. VA 0xab118. FUN_000ab118 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000ab118(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  double dVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float fVar6;
  
  DAT_01226e38 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(fullscreenExitGestureRecognizer));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(view));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  if (DAT_01226838 == 0) {
    DAT_01226838 = _objc_getClass((&PTR_LAB_01181218)[DAT_01226838 == 0] +
                                  (int)-(DAT_01181228 ^ 0x3b344de4),
                                  s_YTMainAppVideoPlayerOverlayView_0116e3c0);
  }
  lVar2 = DAT_01226838;
  _objc_retainAutorelease(DAT_01226838);
  iVar3 = FUN_000e7b60(uVar5,@selector(isKindOfClass:),lVar2);
  if (iVar3 == 0) {
    uVar4 = (*_DAT_01226678)(param_1,param_2,param_3);
    _objc_release(uVar5);
    _objc_release(param_3);
    return uVar4;
  }
  dVar1 = (double)_objc_msgSend(param_3,@selector(locationInView:),uVar5);
  _objc_msgSend(uVar5,@selector(bounds));
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  fVar6 = (float)_objc_msgSend(uVar4,@selector(floatForKey:),
                               @"gestWideness");
  _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x000ab848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*(code *)((&PTR_LAB_01181250)[(double)fVar6 < dVar1] +
                    (int)-(uRam0000000001181260 ^ 0xe74a112)))();
  return uVar4;
}


