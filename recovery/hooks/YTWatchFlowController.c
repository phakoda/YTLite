// Decompiled hook evidence for YTWatchFlowController. This is not compilable Logos source.

// -[YTWatchFlowController shouldExitFullScreenOnFinish], original IMP slot 0x01226660
/* Decompiled from supplied 5.2.2 arm package. VA 0xaa0e8. FUN_000aa0e8 */

uint FUN_000aa0e8(void)

{
  uint uVar1;
  
  DAT_01226e2c = 1;
  uVar1 = _ytpBool(@"exitFullscreen");
  return uVar1 & 1;
}


