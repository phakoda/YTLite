/* Decompiled from supplied 5.2.2 arm package. VA 0x24f0c0. FUN_0024f0c0 */

void FUN_0024f0c0(int *param_1,int param_2,int *param_3,uint param_4)

{
  if ((int)param_4 < 1) {
    while (0 < param_2) {
      *param_1 = *param_3 << (ulong)(-param_4 & 0x1f);
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  else {
    while (0 < param_2) {
      *param_1 = *param_3 >> (param_4 & 0x1f);
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  return;
}


