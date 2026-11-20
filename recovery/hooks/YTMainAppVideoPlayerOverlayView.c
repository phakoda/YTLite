// Decompiled hook evidence for YTMainAppVideoPlayerOverlayView. This is not compilable Logos source.

// -[YTMainAppVideoPlayerOverlayView setBackgroundVisible:isGradientBackground:], original IMP slot 0x01226420
/* Decompiled from supplied 5.2.2 arm package. VA 0x885a8. FUN_000885a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000885a8(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  DAT_01226cd4 = 1;
  uVar1 = FUN_000df350(@"noDarkBg");
  (*_DAT_01226420)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff),param_4);
  CallSupervisor(0x5688);
  return ZEXT816(0x1f);
}



// -[YTMainAppVideoPlayerOverlayView autonavPreviewView], original IMP slot 0x01226428
/* Decompiled from supplied 5.2.2 arm package. VA 0x88710. FUN_00088710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00088710(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cd8 = 1;
  iVar1 = FUN_000df374(@"autonavEndScreenCards");
  if (iVar1 == 0) {
    (*_DAT_01226428)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}



// -[YTMainAppVideoPlayerOverlayView isWatermarkEnabled], original IMP slot 0x01226430
/* Decompiled from supplied 5.2.2 arm package. VA 0x88954. FUN_00088954 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00088954(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cdc = 1;
  iVar1 = FUN_000df398(@"noWatermarks");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00088afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226430)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTMainAppVideoPlayerOverlayView featuredChannelWatermarkImageView], original IMP slot 0x01226438
/* Decompiled from supplied 5.2.2 arm package. VA 0x88b14. FUN_00088b14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00088b14(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ce0 = 1;
  iVar1 = FUN_000df3bc(@"noWatermarks");
  if (iVar1 == 0) {
    (*_DAT_01226438)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}



// -[YTMainAppVideoPlayerOverlayView setSeekAnywherePanGestureRecognizer:], original IMP slot 0x01226440
/* Decompiled from supplied 5.2.2 arm package. VA 0x88cd8. FUN_00088cd8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00088cd8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01226ce4 = 1;
  _objc_retain(param_3);
  lVar1 = _ytpInt(@"speedIndex");
  if (lVar1 == 0) {
    (*_DAT_01226440)(param_1,param_2,param_3);
  }
  else {
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___UILongPressGestureRecognizer_0114ed30);
    uVar2 = _objc_msgSend(uVar2,@selector(initWithTarget:action:),param_1,
                          @selector(speedmasterYtLite:));
    _objc_msgSend(DAT_00c4c2e0,uVar2,@selector(setMinimumPressDuration:));
    lVar1 = _ytpInt(@"speedIndex");
    if (lVar1 != 0) {
      _objc_msgSend(param_1,@selector(addGestureRecognizer:),uVar2);
    }
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0x5635);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}



// -[YTMainAppVideoPlayerOverlayView speedmasterYtLite:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x88f60. FUN_00088f60 */

undefined1  [16] FUN_00088f60(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  puVar2 = PTR_YTPSpeedMaster_0114eca0;
  puVar1 = @selector(sharedMaster);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(delegate));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(manageSpeedMaster:playerOverlayVC:),param_3,uVar4);
  _objc_release(param_3);
  _objc_release(uVar4);
  _objc_release(uVar3);
  CallSupervisor(0xa2ba);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


