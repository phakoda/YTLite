// Decompiled hook evidence for YTInlineMutedPlaybackAudioIconViewController. This is not compilable Logos source.

// -[YTInlineMutedPlaybackAudioIconViewController ytlButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b440. FUN_0004b440 */

void FUN_0004b440(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b440);
  return;
}



// -[YTInlineMutedPlaybackAudioIconViewController setYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b44c. FUN_0004b44c */

undefined1  [16] FUN_0004b44c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b440,param_3,1);
  CallSupervisor(0x361e);
  return ZEXT816(0x1f);
}



// -[YTInlineMutedPlaybackAudioIconViewController ytlIcon], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b484. FUN_0004b484 */

void FUN_0004b484(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b484);
  return;
}



// -[YTInlineMutedPlaybackAudioIconViewController setYtlIcon:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b490. FUN_0004b490 */

undefined1  [16] FUN_0004b490(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b484,param_3,1);
  CallSupervisor(0xd474);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTInlineMutedPlaybackAudioIconViewController viewDidLoad], original IMP slot 0x01226308
/* Decompiled from supplied 5.2.2 arm package. VA 0x80a50. FUN_00080a50 */

void FUN_00080a50(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c38 = 1;
  (*DAT_01226308)(param_1);
  uVar1 = FUN_000dda18(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00081154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117cf18)[uVar1 & 0xffffffff] + (int)-(DAT_0117cf28 ^ 0x272c11af)))();
  return;
}



// -[YTInlineMutedPlaybackAudioIconViewController handleYTLIconTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x81bd4. FUN_00081bd4 */

undefined1  [16] FUN_00081bd4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  puVar1 = @selector(parentResponder);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,@selector(showDownloadSheet:withSender:),uVar2,
                param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0xec22);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


