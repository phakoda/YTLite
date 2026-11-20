// Decompiled hook evidence for YTInlineMutedPlaybackShortsPlayerOverlayView. This is not compilable Logos source.

// -[YTInlineMutedPlaybackShortsPlayerOverlayView layoutSubviews], original IMP slot 0x01226338
/* Decompiled from supplied 5.2.2 arm package. VA 0x850e4. FUN_000850e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000850e4(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c5c = 1;
  (*_DAT_01226338)(param_1);
  uVar1 = FUN_000dea7c(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x000856a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__MSHookMessageEx_0117d488)[uVar1 & 0xffffffff] +
            (int)-(uRam000000000117d498 ^ 0xf4a0f45a)))();
  return;
}



// -[YTInlineMutedPlaybackShortsPlayerOverlayView didTapYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x85cd0. FUN_00085cd0 */

undefined1  [16] FUN_00085cd0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  DAT_01226c60 = 1;
  _objc_retain(param_3);
  puVar1 = @selector(parentResponder);
  _objc_msgSend(param_1,@selector(parentResponder));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226898 == 0) {
    DAT_01226898 = _objc_getClass((&PTR_LAB_0117d540)[DAT_01226898 == 0] +
                                  (int)-(uRam000000000117d550 ^ 0x67c35f59),
                                  s_YTPlayerViewController_01167510);
  }
  lVar3 = DAT_01226898;
  _objc_retainAutorelease(DAT_01226898);
  iVar4 = FUN_000defe4(uVar5,@selector(isKindOfClass:),lVar3);
  _objc_release(uVar5);
  puVar2 = PTR_DownloadMenuHelper_0114ed78;
  if (iVar4 != 0) {
    _objc_msgSend(param_1,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar2,@selector(showDownloadSheetShorts:withSender:),uVar5,param_3);
    _objc_release(uVar5);
  }
  _objc_release(param_3);
  CallSupervisor(0xd4b);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}


