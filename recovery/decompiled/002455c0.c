/* Decompiled from supplied 5.2.2 arm package. VA 0x2455c0. _shine_max_reservoir_bits */

int _shine_max_reservoir_bits(double *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  if (*param_2 != 0) {
    iVar2 = param_2[0x85] / *param_2;
  }
  iVar1 = 0xfff;
  if (iVar2 < 0x1000) {
    iVar1 = iVar2;
  }
  iVar3 = iVar1;
  if (param_2[0x21af] != 0) {
    iVar3 = (int)(*param_1 * DAT_00c4d728 - (double)iVar2);
    iVar2 = (int)*(ulong *)(param_2 + 0x21ae);
    if (iVar3 < 0x65) {
      iVar4 = 0;
    }
    else {
      iVar4 = (iVar2 * 6) / 10;
      if (iVar3 <= iVar4) {
        iVar4 = iVar3;
      }
    }
    iVar2 = iVar2 - (int)((uint)(*(ulong *)(param_2 + 0x21ae) >> 0x1d) & 0xfffffff8) / 10;
    if (iVar2 <= iVar4) {
      iVar2 = iVar4;
    }
    iVar3 = 0xfff;
    if (iVar2 + iVar1 < 0x1000) {
      iVar3 = iVar2 + iVar1;
    }
  }
  return iVar3;
}


