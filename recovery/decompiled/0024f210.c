/* Decompiled from supplied 5.2.2 arm package. VA 0x24f210. FUN_0024f210 */

undefined4
FUN_0024f210(short *param_1,int param_2,short *param_3,int param_4,uint param_5,undefined2 *param_6,
            int param_7)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((((-1 < (int)param_5) && (param_1 != (short *)0x0)) && (param_3 != (short *)0x0)) &&
     ((param_6 != (undefined2 *)0x0 && (0 < param_7)))) {
    for (; param_7 != 0; param_7 = param_7 + -1) {
      *param_6 = (short)(((1 << (ulong)(param_5 & 0x1f)) >> 1) + *param_1 * param_2 +
                         *param_3 * param_4 >> (param_5 & 0x1f));
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_6 = param_6 + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


