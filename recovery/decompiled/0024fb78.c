/* Decompiled from supplied 5.2.2 arm package. VA 0x24fb78. _oggpack_read */

ulong _oggpack_read(long *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  byte *pbVar6;
  uint uVar7;
  
  if (param_2 < 0x21) {
    uVar2 = *(uint *)(param_1 + 1);
    lVar5 = param_1[4];
    lVar4 = *param_1;
    uVar1 = uVar2 + param_2;
    if (lVar5 + -4 <= lVar4) {
      if (lVar5 - ((int)(uVar1 + 7) >> 3) < lVar4) goto LAB_0024fbb8;
      if (uVar1 == 0) {
        return 0;
      }
    }
    pbVar6 = (byte *)param_1[3];
    uVar7 = (uint)(*pbVar6 >> (ulong)(uVar2 & 0x1f));
    if ((((8 < (int)uVar1) &&
         (uVar7 = (uint)pbVar6[1] << (ulong)(8 - uVar2 & 0x1f) | uVar7, 0x10 < (int)uVar1)) &&
        (uVar7 = (uint)pbVar6[2] << (ulong)(0x10 - uVar2 & 0x1f) | uVar7, 0x18 < (int)uVar1)) &&
       ((uVar7 = (uint)pbVar6[3] << (ulong)(0x18 - uVar2 & 0x1f) | uVar7, 0x20 < (int)uVar1 &&
        (uVar2 != 0)))) {
      uVar7 = (uint)pbVar6[4] << (ulong)(0x20 - uVar2 & 0x1f) | uVar7;
    }
    uVar3 = (long)(int)uVar7 & *(ulong *)(&DAT_00c50150 + (long)(int)param_2 * 8);
    uVar2 = uVar1 + 7;
    if (-1 < (int)uVar1) {
      uVar2 = uVar1;
    }
    param_1[3] = (long)(pbVar6 + ((int)uVar2 >> 3));
    *param_1 = lVar4 + ((int)uVar2 >> 3);
    *(uint *)(param_1 + 1) = uVar1 & 7;
  }
  else {
    lVar5 = param_1[4];
LAB_0024fbb8:
    param_1[3] = 0;
    *param_1 = lVar5;
    *(undefined4 *)(param_1 + 1) = 1;
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}


