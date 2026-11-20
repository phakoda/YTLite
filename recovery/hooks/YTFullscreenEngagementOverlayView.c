// Decompiled hook evidence for YTFullscreenEngagementOverlayView. This is not compilable Logos source.

// -[YTFullscreenEngagementOverlayView setExpanded:], original IMP slot 0x01226258
/* Decompiled from supplied 5.2.2 arm package. VA 0x7884c. FUN_0007884c */

void FUN_0007884c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  DAT_01226bd0 = 1;
  (*DAT_01226258)(param_1,param_2,param_3);
  _objc_msgSend(param_1,@selector(superview));
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00079008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117c200)[DAT_01226838 == 0] + (int)-(DAT_0117c210 ^ 0x1fe698c2)))();
  return;
}


