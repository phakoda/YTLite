/* Decompiled from supplied 5.2.2 arm package. VA 0x24fca0. _oggpackB_read */

ulong _oggpackB_read(long *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar2 = 0x20 - param_2;
  if ((int)(uVar2 | param_2) < 0) {
    lVar5 = param_1[4];
LAB_0024fda4:
    param_1[3] = 0;
    *param_1 = lVar5;
    *(undefined4 *)(param_1 + 1) = 1;
    uVar3 = 0xffffffffffffffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 1);
    lVar4 = *param_1;
    lVar5 = param_1[4];
    param_2 = uVar1 + param_2;
    if (lVar5 <= lVar4 + 4) {
      if (lVar5 - ((int)(param_2 + 7) >> 3) < lVar4) goto LAB_0024fda4;
      if (param_2 == 0) {
        return 0;
      }
    }
    pbVar6 = (byte *)param_1[3];
    uVar7 = (uint)*pbVar6 << (ulong)(uVar1 + 0x18 & 0x1f);
    if ((((8 < (int)param_2) &&
         (uVar7 = (uint)pbVar6[1] << (ulong)(uVar1 + 0x10 & 0x1f) | uVar7, 0x10 < (int)param_2)) &&
        (uVar7 = (uint)pbVar6[2] << (ulong)(uVar1 + 8 & 0x1f) | uVar7, 0x18 < (int)param_2)) &&
       ((uVar7 = (uint)pbVar6[3] << (ulong)(uVar1 & 0x1f) | uVar7, 0x20 < (int)param_2 &&
        (uVar1 != 0)))) {
      uVar7 = pbVar6[4] >> (ulong)(8 - uVar1 & 0x1f) | uVar7;
    }
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    uVar3 = (ulong)((uVar7 >> ((long)(int)uVar2 >> 1 & 0x3fU)) >>
                   ((long)(int)uVar2 + 1 >> 1 & 0x3fU));
    param_1[3] = (long)(pbVar6 + ((int)uVar1 >> 3));
    *param_1 = lVar4 + ((int)uVar1 >> 3);
    *(uint *)(param_1 + 1) = param_2 & 7;
  }
  return uVar3;
}


