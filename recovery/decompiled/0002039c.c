/* Decompiled from supplied 5.2.2 arm package. VA 0x2039c. FUN_0002039c */

void FUN_0002039c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225cd8 = 1;
  (*DAT_01225c28)(param_1);
  uVar1 = FUN_00022d50(param_1,PTR_s_isPlayingAd_0114b348);
                    /* WARNING: Could not recover jumptable at 0x00020780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156438)[uVar1 & 0xffffffff] + (int)-(DAT_01156448 ^ 0xf3251696)))();
  return;
}


