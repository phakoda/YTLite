// Decompiled hook evidence for UIInputView. This is not compilable Logos source.

// -[UIInputView layoutSubviews], original IMP slot 0x012262b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x7e294. FUN_0007e294 */

void FUN_0007e294(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226c04 = 1;
  (*DAT_012262b8)(param_1);
  uVar1 = FUN_000dcfa0(@"oledKeyboard");
                    /* WARNING: Could not recover jumptable at 0x0007e6f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117cb30)[uVar1 & 0xffffffff] + (int)-(DAT_0117cb40 ^ 0x35cd4498)))();
  return;
}


