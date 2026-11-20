// Decompiled hook evidence for YTReelDataSource. This is not compilable Logos source.

// -[YTReelDataSource makeContentModelForEntry:], original IMP slot 0x012265c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x99070. FUN_00099070 */

void FUN_00099070(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_01226dc0 = 1;
  (*DAT_012265c0)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000e3840(uVar1,@selector(respondsToSelector:),@selector(videoType));
                    /* WARNING: Could not recover jumptable at 0x000994b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f210)[uVar2] + (int)-(DAT_0117f220 ^ 0x2b0dbc0e)))();
  return;
}


