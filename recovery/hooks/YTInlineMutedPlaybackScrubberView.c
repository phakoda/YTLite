// Decompiled hook evidence for YTInlineMutedPlaybackScrubberView. This is not compilable Logos source.

// -[YTInlineMutedPlaybackScrubberView setMediaTime:], original IMP slot 0x01225c80
/* Decompiled from supplied 5.2.2 arm package. VA 0x22424. FUN_00022424 */

undefined1  [16] FUN_00022424(undefined8 param_1)

{
  (*DAT_01225c80)();
  _configureMutedPlayerBar(param_1);
  CallSupervisor(0xa103);
  return ZEXT816(0x1f);
}



// -[YTInlineMutedPlaybackScrubberView addGradient], original IMP slot 0x01225c88
/* Decompiled from supplied 5.2.2 arm package. VA 0x2246c. FUN_0002246c */

undefined1  [16] FUN_0002246c(undefined8 param_1)

{
  (*DAT_01225c88)();
  _configureMutedPlayerBar(param_1);
  CallSupervisor(0xd28c);
  return ZEXT816(0x1f);
}



// -[YTInlineMutedPlaybackScrubberView addGradient], original IMP slot 0x01226578
/* Decompiled from supplied 5.2.2 arm package. VA 0x94ef8. FUN_00094ef8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00094ef8(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  DAT_01226d9c = 1;
  lVar1 = _ytpInt(@"progressBarIndex");
  if (lVar1 == 0) {
    (*_DAT_01226578)(param_1,param_2);
  }
  CallSupervisor(0x7544);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTInlineMutedPlaybackScrubberView layoutSubviews], original IMP slot 0x01226580
/* Decompiled from supplied 5.2.2 arm package. VA 0x95104. FUN_00095104 */

void FUN_00095104(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226da0 = 1;
  (*DAT_01226580)(param_1);
  uVar1 = _objc_msgSend(param_1,@selector(class));
  lVar2 = _class_getInstanceVariable(uVar1,s__progressBarGradient_0116a590);
                    /* WARNING: Could not recover jumptable at 0x00095820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ec60)[lVar2 == 0] + (int)-(DAT_0117ec70 ^ 0x696f03e4)))();
  return;
}


