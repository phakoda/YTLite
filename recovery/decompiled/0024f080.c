/* Decompiled from supplied 5.2.2 arm package. VA 0x24f080. FUN_0024f080 */

void FUN_0024f080(undefined2 *param_1,int param_2,short *param_3,uint param_4)

{
  if ((int)param_4 < 1) {
    while (0 < param_2) {
      *param_1 = (short)((int)*param_3 << (ulong)(-param_4 & 0x1f));
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  else {
    while (0 < param_2) {
      *param_1 = (short)((int)*param_3 >> (param_4 & 0x1f));
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  return;
}


