// Decompiled hook evidence for YTInlineMutedPlaybackAudioIconView. This is not compilable Logos source.

// -[YTInlineMutedPlaybackAudioIconView updateColors], original IMP slot 0x01226310
/* Decompiled from supplied 5.2.2 arm package. VA 0x81c68. FUN_00081c68 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00081c68(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c40 = 1;
  (*_DAT_01226310)(param_1);
  uVar1 = FUN_000de164(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00081fd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117cfc0)[uVar1 & 0xffffffff] + (int)-(uRam000000000117cfd0 ^ 0x89423d8c)))()
  ;
  return;
}


