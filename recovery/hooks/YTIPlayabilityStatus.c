// Decompiled hook evidence for YTIPlayabilityStatus. This is not compilable Logos source.

// -[YTIPlayabilityStatus isPlayableInBackground], original IMP slot 0x01226000
/* Decompiled from supplied 5.2.2 arm package. VA 0x662c8. FUN_000662c8 */

uint FUN_000662c8(void)

{
  uint uVar1;
  
  DAT_01226a70 = 1;
  uVar1 = _ytpBool(@"backgroundPlayback");
  return uVar1 & 1;
}


