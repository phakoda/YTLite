// Decompiled hook evidence for YTPlayerBarScrubberDotDecorationViewV1. This is not compilable Logos source.

// -[YTPlayerBarScrubberDotDecorationViewV1 scrubberDot], original IMP slot 0x01226538
/* Decompiled from supplied 5.2.2 arm package. VA 0x90e90. FUN_00090e90 */

void FUN_00090e90(void)

{
  long lVar1;
  
  DAT_01226d7c = 1;
  (*DAT_01226538)();
  lVar1 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0009114c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e700)[lVar1 == 0] + (int)-(DAT_0117e710 ^ 0xb09579d9)))();
  return;
}


