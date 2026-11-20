// Decompiled hook evidence for YTReelWatchPlaybackOverlayView. This is not compilable Logos source.

// -[YTReelWatchPlaybackOverlayView layoutSubviews], original IMP slot 0x01226320
/* Decompiled from supplied 5.2.2 arm package. VA 0x83340. FUN_00083340 */

void FUN_00083340(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c4c = 1;
  (*DAT_01226320)(param_1);
  uVar1 = FUN_000de78c(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00083d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d1d0)[uVar1 & 0xffffffff] + (int)-(DAT_0117d1e0 ^ 0x7b6f0894)))();
  return;
}



// -[YTReelWatchPlaybackOverlayView setActionBarElementRenderer:], original IMP slot 0x01226328
/* Decompiled from supplied 5.2.2 arm package. VA 0x8429c. FUN_0008429c */

void FUN_0008429c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c50 = 1;
  (*DAT_01226328)(param_1);
  uVar1 = FUN_000de7b0(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00084938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d318)[uVar1 & 0xffffffff] + (int)-(DAT_0117d328 ^ 0xa3bfe7c9)))();
  return;
}



// -[YTReelWatchPlaybackOverlayView setReelLikeButton:], original IMP slot 0x01226330
/* Decompiled from supplied 5.2.2 arm package. VA 0x84ae4. FUN_00084ae4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00084ae4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  
  DAT_01226c54 = 1;
  _objc_retain(param_3);
  (*_DAT_01226330)(param_1,param_2,param_3);
  uVar1 = FUN_000de8dc(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00084cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d3d0)[uVar1 & 0xffffffff] + (int)-(uRam000000000117d3e0 ^ 0x7a6f9af0)))()
  ;
  return;
}



// -[YTReelWatchPlaybackOverlayView didTapYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x84d50. FUN_00084d50 */

undefined1  [16] FUN_00084d50(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01226c58 = 1;
  _objc_retain(param_3);
  puVar1 = @selector(parentResponder);
  _objc_msgSend(param_1,@selector(parentResponder));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_012268c8 == 0) {
    DAT_012268c8 = _objc_getClass((&PTR_LAB_0117d428)[DAT_012268c8 == 0] +
                                  (int)-(uRam000000000117d438 ^ 0x8ab84cee),
                                  s_YTReelPlayerViewController_01167360);
  }
  lVar2 = DAT_012268c8;
  _objc_retainAutorelease(DAT_012268c8);
  uVar3 = FUN_000de990(uVar4,@selector(isKindOfClass:),lVar2);
  _objc_release(uVar4);
  if (uVar3 != 0) {
    _objc_msgSend((&PTR_LAB_0117d448)[uVar3] + (int)-(DAT_0117d458 ^ 0x91dce70a),param_1,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(player));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,@selector(showDownloadSheetShorts:withSender:),
                  uVar5,param_3);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(param_3);
  CallSupervisor(0x2385);
  return ZEXT816(0x1f);
}


