// Decompiled hook evidence for YTPlaybackConfig. This is not compilable Logos source.

// -[YTPlaybackConfig setStartPlayback:], original IMP slot 0x01226508
/* Decompiled from supplied 5.2.2 arm package. VA 0x8fe74. FUN_0008fe74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008fe74(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  
  DAT_01226d5c = 1;
  uVar1 = FUN_000e0e38(@"disableAutoplay");
  (*_DAT_01226508)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0x76e1);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


