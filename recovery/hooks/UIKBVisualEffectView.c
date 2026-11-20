// Decompiled hook evidence for UIKBVisualEffectView. This is not compilable Logos source.

// -[UIKBVisualEffectView layoutSubviews], original IMP slot 0x012262c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x7e818. FUN_0007e818 */

void FUN_0007e818(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c08 = 1;
  (*DAT_012262c0)(param_1);
  uVar1 = FUN_000dd0ac(@"oledKeyboard");
                    /* WARNING: Could not recover jumptable at 0x0007e9c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117cba0)[uVar1 & 0xffffffff] + (int)-(DAT_0117cbb0 ^ 0xbc8abc99)))();
  return;
}


