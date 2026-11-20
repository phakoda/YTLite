/* Decompiled from supplied 5.2.2 arm package. VA 0x24f314. _oggpackB_writetrunc */

void _oggpackB_writetrunc(long *param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  if (param_1[3] != 0) {
    lVar2 = param_2 >> 3;
    lVar3 = param_1[2];
    param_2 = param_2 + lVar2 * -8;
    *param_1 = lVar2;
    *(int *)(param_1 + 1) = (int)param_2;
    uVar1 = *(undefined4 *)(&DAT_00c50258 + param_2 * 4);
    param_1[3] = lVar3 + lVar2;
    *(byte *)(lVar3 + lVar2) = *(byte *)(lVar3 + lVar2) & (byte)uVar1;
  }
  return;
}


