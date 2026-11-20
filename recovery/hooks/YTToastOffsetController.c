// Decompiled hook evidence for YTToastOffsetController. This is not compilable Logos source.

// -[YTToastOffsetController update], original IMP slot 0x01225f48
/* Decompiled from supplied 5.2.2 arm package. VA 0x4e934. FUN_0004e934 */

undefined1  [16] FUN_0004e934(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  (*DAT_01225f48)();
  puVar1 = @selector(sharedManager);
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setOffsetController:),param_1);
  _objc_release(uVar2);
  _objc_msgSend(PTR_ToastManager_0114ecd0,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(updateAllToasts));
  _objc_release(uVar2);
  CallSupervisor(0x8509);
  return ZEXT816(0x1f);
}



// -[YTToastOffsetController setWasPinnedTop:], original IMP slot 0x01225f50
/* Decompiled from supplied 5.2.2 arm package. VA 0x4e9e4. FUN_0004e9e4 */

undefined1  [16] FUN_0004e9e4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  (*DAT_01225f50)();
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setIsPinnedTop:),param_3);
  _objc_release(uVar1);
  CallSupervisor(0xba91);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


