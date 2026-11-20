// Decompiled hook evidence for YTWatchFloatingMiniplayerViewController. This is not compilable Logos source.

// -[YTWatchFloatingMiniplayerViewController updateMiniBarPlayerStateFromRenderer], original IMP slot 0x012264f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8fab8. FUN_0008fab8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008fab8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226d54 = 1;
  iVar1 = FUN_000e0df0(@"miniplayer");
  if (iVar1 == 0) {
    (*_DAT_012264f8)(param_1,param_2);
  }
  CallSupervisor(0xba69);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


