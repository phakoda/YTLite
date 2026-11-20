// Decompiled hook evidence for YTWatchViewController. This is not compilable Logos source.

// -[YTWatchViewController setFullscreen:], original IMP slot 0x01225f58
/* Decompiled from supplied 5.2.2 arm package. VA 0x4ea5c. FUN_0004ea5c */

undefined1  [16] FUN_0004ea5c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  (*DAT_01225f58)();
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setIsFullscreen:),param_3);
  _objc_release(uVar1);
  CallSupervisor(0x9a8f);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTWatchViewController allowedFullScreenOrientations], original IMP slot 0x01226500
/* Decompiled from supplied 5.2.2 arm package. VA 0x8fc60. FUN_0008fc60 */

undefined8 FUN_0008fc60(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d58 = 1;
  iVar1 = FUN_000e0e14(@"portraitFullscreen");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008fe5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_01226500)(param_1,param_2);
    return uVar2;
  }
  return 0x1a;
}


