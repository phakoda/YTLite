// Decompiled hook evidence for YTReelContentModel. This is not compilable Logos source.

// +[YTReelContentModel makeContentModelForEntry:], original IMP slot 0x012265b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x98710. FUN_00098710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00098710(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_01226dbc = 1;
  (*_DAT_012265b8)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000e3460(uVar1,@selector(respondsToSelector:),@selector(videoType));
                    /* WARNING: Could not recover jumptable at 0x00098b4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f018)[uVar2] + (int)-(uRam000000000117f028 ^ 0x58a57928)))();
  return;
}


