/* Decompiled from supplied 5.2.2 arm package. VA 0x24f100. FUN_0024f100 */

void FUN_0024f100(undefined2 *param_1,int param_2,int *param_3,uint param_4)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  if ((int)param_4 < 0) {
    while (0 < param_2) {
      iVar3 = *param_3 << (ulong)(-param_4 & 0x1f);
      iVar1 = iVar3;
      if (iVar3 < -0x7fff) {
        iVar1 = -0x8000;
      }
      uVar2 = 0x7fff;
      if (iVar3 < 0x8000) {
        uVar2 = (short)iVar1;
      }
      *param_1 = uVar2;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  else {
    while (0 < param_2) {
      iVar1 = *param_3 >> (param_4 & 0x1f);
      iVar3 = iVar1;
      if (iVar1 < -0x7fff) {
        iVar3 = -0x8000;
      }
      uVar2 = 0x7fff;
      if (iVar1 < 0x8000) {
        uVar2 = (short)iVar3;
      }
      *param_1 = uVar2;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    }
  }
  return;
}


