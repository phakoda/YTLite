/* Decompiled from supplied 5.2.2 arm package. VA 0x24fdc8. _oggpack_read1 */

ulong _oggpack_read1(long *param_1)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  
  if (*param_1 < param_1[4]) {
    uVar1 = *(uint *)(param_1 + 1);
    bVar2 = *(byte *)param_1[3];
    *(uint *)(param_1 + 1) = uVar1 + 1;
    uVar3 = (ulong)(bVar2 >> (ulong)(uVar1 & 0x1f) & 1);
    if (6 < (int)uVar1) {
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


