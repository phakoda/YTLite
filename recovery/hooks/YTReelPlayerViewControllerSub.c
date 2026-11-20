// Decompiled hook evidence for YTReelPlayerViewControllerSub. This is not compilable Logos source.

// -[YTReelPlayerViewControllerSub shouldEnablePlayerBar], original IMP slot 0x01226698
/* Decompiled from supplied 5.2.2 arm package. VA 0xb00b0. FUN_000b00b0 */

uint FUN_000b00b0(void)

{
  uint uVar1;
  
  DAT_01226e48 = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTReelPlayerViewControllerSub shouldAlwaysEnablePlayerBar], original IMP slot 0x012266a0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0224. FUN_000b0224 */

uint FUN_000b0224(void)

{
  uint uVar1;
  
  DAT_01226e4c = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTReelPlayerViewControllerSub shouldEnablePlayerBarOnlyOnPause], original IMP slot 0x012266a8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0384. FUN_000b0384 */

uint FUN_000b0384(void)

{
  uint uVar1;
  
  DAT_01226e50 = 1;
  uVar1 = FUN_000e8390(@"shortsProgress");
  return uVar1 ^ 1;
}


