// Decompiled hook evidence for MLVideo. This is not compilable Logos source.

// -[MLVideo playableInBackground], original IMP slot 0x01226008
/* Decompiled from supplied 5.2.2 arm package. VA 0x66464. FUN_00066464 */

uint FUN_00066464(void)

{
  uint uVar1;
  
  DAT_01226a74 = 1;
  uVar1 = _ytpBool(@"backgroundPlayback");
  return uVar1 & 1;
}


