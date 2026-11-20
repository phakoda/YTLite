/* Decompiled from supplied 5.2.2 arm package. VA 0x24fe30. _oggpackB_read1 */

ulong _oggpackB_read1(long *param_1)

{
  int iVar1;
  byte bVar2;
  ulong uVar3;
  
  if (*param_1 < param_1[4]) {
    iVar1 = (int)param_1[1];
    bVar2 = *(byte *)param_1[3];
    *(int *)(param_1 + 1) = iVar1 + 1;
    uVar3 = (ulong)(bVar2 >> (ulong)(7U - iVar1 & 0x1f) & 1);
    if (6 < iVar1) {
      *(undefined4 *)(param_1 + 1) = 0;
      param_1[3] = (long)((byte *)param_1[3] + 1);
      *param_1 = *param_1 + 1;
    }
  }
  else {
    param_1[3] = 0;
    *param_1 = param_1[4];
    *(undefined4 *)(param_1 + 1) = 1;
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}


