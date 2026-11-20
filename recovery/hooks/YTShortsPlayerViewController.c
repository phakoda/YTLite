// Decompiled hook evidence for YTShortsPlayerViewController. This is not compilable Logos source.

// -[YTShortsPlayerViewController shouldAlwaysEnablePlayerBar], original IMP slot 0x012266b0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0500. FUN_000b0500 */

uint FUN_000b0500(void)

{
  uint uVar1;
  
  DAT_01226e54 = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTShortsPlayerViewController shouldEnablePlayerBarOnlyOnPause], original IMP slot 0x012266b8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0654. FUN_000b0654 */

uint FUN_000b0654(void)

{
  uint uVar1;
  
  DAT_01226e58 = 1;
  uVar1 = FUN_000e83d8(@"shortsProgress");
  return uVar1 ^ 1;
}


