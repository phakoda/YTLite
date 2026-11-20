// Decompiled hook evidence for YTCreatorEndscreenView. This is not compilable Logos source.

// -[YTCreatorEndscreenView setHidden:], original IMP slot 0x01226448
/* Decompiled from supplied 5.2.2 arm package. VA 0x8901c. FUN_0008901c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008901c(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  
  DAT_01226cec = 1;
  uVar1 = FUN_000df500(@"endScreenCards");
  (*_DAT_01226448)(param_1,param_2,uVar1 | param_3);
  CallSupervisor(0x58e);
  return ZEXT816(0x1f);
}


