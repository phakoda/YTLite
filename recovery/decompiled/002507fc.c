/* Decompiled from supplied 5.2.2 arm package. VA 0x2507fc. FUN_002507fc */

void FUN_002507fc(ulong *param_1,ulong *param_2,ulong *param_3,uint param_4,ulong *param_5,
                 int param_6)

{
  ulong uVar1;
  ulong uVar2;
  
  param_4 = ~param_4;
  while (param_4 = param_4 + 1, param_4 != 0) {
    uVar1 = param_1[(long)param_6 * 2] ^ *param_3;
    param_1[0x20] = uVar1;
    uVar2 = (param_1 + (long)param_6 * 2)[1] ^ param_3[1];
    param_1[0x21] = uVar2;
    if (param_5 == (ulong *)0x0) {
      FUN_00250b14(param_1,2,&DAT_012286b0,&DAT_012287b0);
      *param_2 = *param_1 ^ param_1[0x1e];
      param_2[1] = param_1[1] ^ param_1[0x1f];
    }
    else {
      param_1[0x20] = uVar1 ^ *param_5;
      param_1[0x21] = uVar2 ^ param_5[1];
      FUN_00250b14(param_1,2,&DAT_012286b0,&DAT_012287b0);
      *param_2 = *param_1 ^ param_1[0x1e];
      param_2[1] = param_1[1] ^ param_1[0x1f];
      uVar1 = *param_2;
      param_5[1] = param_2[1];
      *param_5 = uVar1;
    }
    param_3 = param_3 + 2;
    param_2 = param_2 + 2;
  }
  return;
}


