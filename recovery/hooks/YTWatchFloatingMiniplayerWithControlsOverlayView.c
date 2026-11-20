// Decompiled hook evidence for YTWatchFloatingMiniplayerWithControlsOverlayView. This is not compilable Logos source.

// -[YTWatchFloatingMiniplayerWithControlsOverlayView layoutSubviews], original IMP slot 0x012258f0
/* Decompiled from supplied 5.2.2 arm package. VA 0xf74c. FUN_0000f74c */

void FUN_0000f74c(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  (*DAT_012258f0)();
  puVar1 = @selector(layer);
  _objc_msgSend(param_1,@selector(layer));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4028000000000000,uVar2,@selector(setCornerRadius:));
  _objc_release(uVar2);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setMasksToBounds:),1);
  _objc_release(uVar2);
  return;
}


