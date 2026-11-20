/* Decompiled from supplied 5.2.2 arm package. VA 0x250710. FUN_00250710 */

void FUN_00250710(ulong *param_1,ulong *param_2,ulong *param_3,uint param_4,ulong *param_5,
                 int param_6)

{
  ulong uVar1;
  
  param_4 = ~param_4;
  while (param_4 = param_4 + 1, param_4 != 0) {
    param_1[0x20] = param_1[(long)param_6 * 2] ^ *param_3;
    param_1[0x21] = (param_1 + (long)param_6 * 2)[1] ^ param_3[1];
    FUN_00250b14(param_1,0,&DAT_012285b0,&DAT_01228bb0);
    if (param_5 != (ulong *)0x0) {
      param_1[0x1e] = param_1[0x1e] ^ *param_5;
      param_1[0x1f] = param_1[0x1f] ^ param_5[1];
      uVar1 = *param_3;
      param_5[1] = param_3[1];
      *param_5 = uVar1;
    }
    *param_2 = *param_1 ^ param_1[0x1e];
    param_3 = param_3 + 2;
    param_2[1] = param_1[1] ^ param_1[0x1f];
    param_2 = param_2 + 2;
  }
  return;
}


