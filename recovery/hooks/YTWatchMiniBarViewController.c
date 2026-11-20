// Decompiled hook evidence for YTWatchMiniBarViewController. This is not compilable Logos source.

// -[YTWatchMiniBarViewController updateMiniBarPlayerStateFromRenderer], original IMP slot 0x012264f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8f914. FUN_0008f914 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008f914(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226d50 = 1;
  iVar1 = FUN_000e0dcc(@"miniplayer");
  if (iVar1 == 0) {
    (*_DAT_012264f0)(param_1,param_2);
  }
  CallSupervisor(0xecb0);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


