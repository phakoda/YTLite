// Decompiled hook evidence for YTFullscreenActionsView. This is not compilable Logos source.

// -[YTFullscreenActionsView enabled], original IMP slot 0x012264a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8d64c. FUN_0008d64c */

uint FUN_0008d64c(void)

{
  uint uVar1;
  
  DAT_01226d28 = 1;
  uVar1 = FUN_000e057c(@"noFullscreenActions");
  return uVar1 ^ 1;
}



// -[YTFullscreenActionsView setEnabled:], original IMP slot 0x012264a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8d800. FUN_0008d800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008d800(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  
  DAT_01226d2c = 1;
  uVar1 = FUN_000e05a0(@"noFullscreenActions");
  (*_DAT_012264a8)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0x17be);
  return ZEXT816(0x1f);
}



// -[YTFullscreenActionsView layoutSubviews], original IMP slot 0x012264b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8da00. FUN_0008da00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008da00(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d30 = 1;
  (*_DAT_012264b0)(param_1);
  uVar1 = FUN_000e0624(@"noMoreVideos");
                    /* WARNING: Could not recover jumptable at 0x0008dfa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e1b8)[uVar1 & 0xffffffff] + (int)-(uRam000000000117e1c8 ^ 0x25564ece)))()
  ;
  return;
}


