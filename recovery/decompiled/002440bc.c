/* Decompiled from supplied 5.2.2 arm package. VA 0x2440bc. FUN_002440bc */

int FUN_002440bc(long param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  
  if (param_4 == 0) {
    return 0;
  }
  uVar7 = (ulong)param_4;
  if (param_4 < 0x10) {
    if (param_3 <= param_2) {
      return 0;
    }
    iVar6 = 0;
    lVar8 = (long)(int)param_2;
    uVar9 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar2 = *(int *)(param_1 + lVar8 * 4);
      piVar1 = (int *)(param_1 + uVar9);
      lVar8 = lVar8 + 2;
      uVar9 = uVar9 + 8;
      if (iVar2 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)*(byte *)(*(long *)(&DAT_01063318 + uVar7 * 0x20) +
                                     (ulong)(uint)(*piVar1 +
                                                  iVar2 * *(int *)(&DAT_01063304 + uVar7 * 0x20)));
    } while ((uint)lVar8 < param_3);
  }
  else {
    if (param_3 <= param_2) {
      return 0;
    }
    iVar6 = 0;
    lVar8 = (long)(int)param_2;
    uVar9 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar5 = *(int *)(param_1 + lVar8 * 4);
      iVar3 = 0xf;
      iVar2 = *(int *)(&DAT_01063308 + uVar7 * 0x20);
      if (iVar5 < 0xf) {
        iVar2 = 0;
        iVar3 = iVar5;
      }
      iVar4 = 0xf;
      iVar5 = *(int *)(&DAT_01063308 + uVar7 * 0x20);
      if (*(int *)(param_1 + uVar9) < 0xf) {
        iVar5 = 0;
        iVar4 = *(int *)(param_1 + uVar9);
      }
      lVar8 = lVar8 + 2;
      uVar9 = uVar9 + 8;
      iVar6 = iVar2 + iVar6 + iVar5 +
              (uint)*(byte *)(*(long *)(&DAT_01063318 + uVar7 * 0x20) +
                             (ulong)(uint)(iVar4 + iVar3 * *(int *)(&DAT_01063304 + uVar7 * 0x20)));
      if (iVar3 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (iVar4 != 0) {
        iVar6 = iVar6 + 1;
      }
    } while ((uint)lVar8 < param_3);
  }
  return iVar6;
}


