// Decompiled hook evidence for YTReelInfinitePlaybackDataSource. This is not compilable Logos source.

// -[YTReelInfinitePlaybackDataSource makeContentModelForEntry:], original IMP slot 0x012265c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x999d8. FUN_000999d8 */

void FUN_000999d8(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_01226dc4 = 1;
  (*DAT_012265c8)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000e3b00(uVar1,@selector(respondsToSelector:),@selector(videoType));
                    /* WARNING: Could not recover jumptable at 0x00099e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f408)[uVar2] + (int)-(DAT_0117f418 ^ 0x121ac09e)))();
  return;
}



// -[YTReelInfinitePlaybackDataSource reels], original IMP slot 0x012265d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x9a344. FUN_0009a344 */

void FUN_0009a344(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_000e3c5c(param_1,@selector(respondsToSelector:),
                       @selector(makeContentModelForEntry:));
  (*DAT_012265d0)(param_1,param_2);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0009a3e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f5e0)[uVar1 & 0xffffffff] + (int)-(DAT_0117f5f0 ^ 0x82c6dee4)))();
  return;
}


