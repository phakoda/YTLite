/* Decompiled from supplied 5.2.2 arm package. VA 0x24e3e8. FUN_0024e3e8 */

void FUN_0024e3e8(undefined2 *param_1,short *param_2,short *param_3,int param_4,uint param_5)

{
  while (0 < param_4) {
    *param_1 = (short)((int)*param_3 + (int)*param_2 >> (param_5 & 0x1f));
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
  }
  return;
}


