/* Decompiled from supplied 5.2.2 arm package. VA 0x24568c. _shine_ResvAdjust */

void _shine_ResvAdjust(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_2 != 0) {
    iVar1 = param_2[0x85] / *param_2;
  }
  param_2[0x21ae] = (iVar1 - *param_1) + param_2[0x21ae];
  return;
}


