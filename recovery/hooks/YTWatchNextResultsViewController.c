// Decompiled hook evidence for YTWatchNextResultsViewController. This is not compilable Logos source.

// -[YTWatchNextResultsViewController setVisibleSections:], original IMP slot 0x01226208
/* Decompiled from supplied 5.2.2 arm package. VA 0x70368. FUN_00070368 */

undefined1  [16] FUN_00070368(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226b80 = 1;
  iVar1 = FUN_000d8e28(@"noRelatedWatchNexts");
  if (iVar1 != 0) {
    param_3 = 1;
  }
  (*DAT_01226208)(param_1,param_2,param_3);
  CallSupervisor(0xefb0);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


