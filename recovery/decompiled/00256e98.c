/* Decompiled from supplied 5.2.2 arm package. VA 0x256e98. _av_dict_get */

long _av_dict_get(uint *param_1,long param_2,long param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ulong uVar3;
  long lVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 != (uint *)0x0) {
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (ulong)((int)((ulong)(param_3 - *(long *)(param_1 + 2)) >> 4) + 1);
    }
    for (; uVar3 < *param_1; uVar3 = uVar3 + 1) {
      uVar8 = 0;
      lVar4 = *(long *)(*(long *)(param_1 + 2) + uVar3 * 0x10);
      uVar7 = 0;
      if ((param_4 & 1) == 0) {
        do {
          bVar5 = *(byte *)(lVar4 + (ulong)uVar7);
          bVar6 = *(byte *)(param_2 + (ulong)uVar7);
          bVar1 = bVar5 ^ 0x20;
          if (0x19 < (int)(char)bVar5 - 0x61U) {
            bVar1 = bVar5;
          }
          bVar2 = bVar6 ^ 0x20;
          if (0x19 < (int)(char)bVar6 - 0x61U) {
            bVar2 = bVar6;
          }
        } while ((bVar6 != 0) && (uVar7 = uVar7 + 1, bVar1 == bVar2));
      }
      else {
        do {
          bVar5 = *(byte *)(lVar4 + (ulong)uVar8);
          bVar6 = *(byte *)(param_2 + (ulong)uVar8);
          if (bVar5 != bVar6) break;
          uVar8 = uVar8 + 1;
        } while (bVar6 != 0);
      }
      if ((bVar6 == 0) && ((param_4 & 2) != 0 || bVar5 == 0)) {
        return *(long *)(param_1 + 2) + uVar3 * 0x10;
      }
    }
  }
  return 0;
}


