/* Decompiled from supplied 5.2.2 arm package. VA 0x24f8ac. _oggpack_look */

ulong _oggpack_look(long *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  if (0x20 < param_2) {
    return 0xffffffffffffffff;
  }
  uVar2 = *(uint *)(param_1 + 1);
  iVar1 = uVar2 + param_2;
  if (param_1[4] + -4 <= *param_1) {
    if (param_1[4] - (long)(iVar1 + 7 >> 3) < *param_1) {
      return 0xffffffffffffffff;
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  pbVar4 = (byte *)param_1[3];
  uVar3 = (uint)(*pbVar4 >> (ulong)(uVar2 & 0x1f));
  if ((((8 < iVar1) && (uVar3 = (uint)pbVar4[1] << (ulong)(8 - uVar2 & 0x1f) | uVar3, 0x10 < iVar1))
      && (uVar3 = (uint)pbVar4[2] << (ulong)(0x10 - uVar2 & 0x1f) | uVar3, 0x18 < iVar1)) &&
     ((uVar3 = (uint)pbVar4[3] << (ulong)(0x18 - uVar2 & 0x1f) | uVar3, 0x20 < iVar1 && (uVar2 != 0)
      ))) {
    uVar3 = (uint)pbVar4[4] << (ulong)(0x20 - uVar2 & 0x1f) | uVar3;
  }
  return (long)(int)uVar3 & *(ulong *)(&DAT_00c50150 + (long)(int)param_2 * 8);
}


