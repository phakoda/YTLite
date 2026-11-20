/* Decompiled from supplied 5.2.2 arm package. VA 0x18fbc. FUN_00018fbc */

void FUN_00018fbc(void)

{
  DAT_01225bac = 1;
  (*pcRam0000000001225a58)();
                    /* WARNING: Could not recover jumptable at 0x00019308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01155360)[_isYTPFirstTime == '\0'] +
            (int)-(uRam0000000001155370 ^ 0x7bc1d9ae)))();
  return;
}


