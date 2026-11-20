/* Decompiled from supplied 5.2.2 arm package. VA 0xfb450. FUN_000fb450 */

void FUN_000fb450(undefined8 param_1,long param_2)

{
  if (DAT_0122710c != 0) {
    DAT_0122710c = 1;
                    /* WARNING: Could not recover jumptable at 0x000fb510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_01189940)[param_2 == 0] + (int)-(uRam0000000001189950 ^ 0x28bcaec8)))();
    return;
  }
  s_________01185c78[0] = DAT_01185c70 ^ 0xdf;
  s_________01185c78[1] = bRam0000000001185c71 ^ 0x4d;
  s_________01185c78[2] = bRam0000000001185c72 ^ 0xf1;
  s_________01185c78[3] = bRam0000000001185c73 ^ 0x98;
  s_________01185c78[4] = bRam0000000001185c74 ^ 0x86;
  s_________01185c78[5] = bRam0000000001185c75 ^ 0xf8;
  s_________01185c78[6] = bRam0000000001185c76 ^ 0x23;
  s_________01185c78[7] = bRam0000000001185c77 ^ 0x99;
  DAT_0122710c = 1;
                    /* WARNING: Could not recover jumptable at 0x000fb6f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01189940)[param_2 == 0] + (int)-(uRam0000000001189950 ^ 0x28bcaec8)))();
  return;
}


