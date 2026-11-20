/* Decompiled from supplied 5.2.2 arm package. VA 0x24c904. FUN_0024c904 */

void FUN_0024c904(ushort *param_1,int param_2,ushort *param_3)

{
  while (0 < param_2) {
    *param_3 = *param_1 >> 8 | *param_1 << 8;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
    param_2 = param_2 + -1;
  }
  return;
}


