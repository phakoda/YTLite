/* Decompiled from supplied 5.2.2 arm package. VA 0x999d8. FUN_000999d8 */

void FUN_000999d8(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_01226dc4 = 1;
  (*DAT_012265c8)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000e3b00(uVar1,PTR_s_respondsToSelector__0114af58,PTR_s_videoType_0114ca60);
                    /* WARNING: Could not recover jumptable at 0x00099e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117f408)[uVar2] + (int)-(DAT_0117f418 ^ 0x121ac09e)))();
  return;
}


