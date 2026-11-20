/* Decompiled from supplied 5.2.2 arm package. VA 0x24fadc. _oggpack_adv */

void _oggpack_adv(long *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (int)param_1[1] + param_2;
  if (param_1[4] - (long)((int)(uVar2 + 7) >> 3) < *param_1) {
    param_1[3] = 0;
    *param_1 = param_1[4];
    uVar2 = 1;
  }
  else {
    uVar1 = uVar2 + 7;
    if (-1 < (int)uVar2) {
      uVar1 = uVar2;
    }
    *param_1 = *param_1 + (long)((int)uVar1 >> 3);
    param_1[3] = param_1[3] + (long)((int)uVar1 >> 3);
    uVar2 = uVar2 & 7;
  }
  *(uint *)(param_1 + 1) = uVar2;
  return;
}


