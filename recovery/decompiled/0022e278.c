/* Decompiled from supplied 5.2.2 arm package. VA 0x22e278. FUN_0022e278 */

void FUN_0022e278(long param_1)

{
  if (DAT_012283cc != 0) {
    DAT_012283cc = 1;
                    /* WARNING: Could not recover jumptable at 0x0022e334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011d16a8)[*(char *)(param_1 + 0x30) == '\0'] +
              (int)-(uRam00000000011d16b8 ^ 0x44027d66)))(*(undefined8 *)(param_1 + 0x20));
    return;
  }
  s_Saved_011d0816[0] = DAT_011d0810 ^ 9;
  s_Saved_011d0816[1] = bRam00000000011d0811 ^ 0x3a;
  s_Saved_011d0816[2] = bRam00000000011d0812 ^ 0x33;
  s_Saved_011d0816[3] = bRam00000000011d0813 ^ 0xa2;
  s_Saved_011d0816[4] = bRam00000000011d0814 ^ 0x1c;
  s_Saved_011d0816[5] = bRam00000000011d0815 ^ 0x58;
  DAT_012283cc = 1;
                    /* WARNING: Could not recover jumptable at 0x0022e468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d16a8)[*(char *)(param_1 + 0x30) == '\0'] +
            (int)-(uRam00000000011d16b8 ^ 0x44027d66)))(*(undefined8 *)(param_1 + 0x20));
  return;
}


