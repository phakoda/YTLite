/* Decompiled from supplied 5.2.2 arm package. VA 0x2456b4. _shine_ResvFrameEnd */

void _shine_ResvFrameEnd(uint *param_1)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  uint *puVar6;
  uint uVar7;
  long lVar8;
  uint *puVar9;
  
  uVar3 = (ulong)*param_1;
  if ((*param_1 == 2) && ((param_1[0x85] & 1) != 0)) {
    param_1[0x21ae] = param_1[0x21ae] + 1;
  }
  iVar2 = param_1[0x21ae] - param_1[0x21af];
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  uVar4 = param_1[0x21ae] - iVar1;
  uVar7 = uVar4 + 7;
  if (-1 < (int)uVar4) {
    uVar7 = uVar4;
  }
  uVar4 = (int)uVar4 % 8 + iVar1;
  param_1[0x21ae] = uVar7 & 0xfffffff8;
  if (uVar4 != 0) {
    if (param_1[0x28] + uVar4 < 0xfff) {
      param_1[0x28] = param_1[0x28] + uVar4;
      return;
    }
    uVar7 = param_1[4];
    if (0 < (int)uVar7) {
      lVar5 = 0;
      puVar6 = param_1 + 0x28;
      do {
        if (0 < (int)uVar3) {
          lVar8 = 0;
          puVar9 = puVar6;
          do {
            if (uVar4 == 0) {
              uVar4 = 0;
              break;
            }
            uVar7 = 0xfff - *puVar9;
            if ((int)uVar4 <= (int)uVar7) {
              uVar7 = uVar4;
            }
            *puVar9 = uVar7 + *puVar9;
            uVar3 = (ulong)(int)*param_1;
            uVar4 = uVar4 - uVar7;
            lVar8 = lVar8 + 1;
            puVar9 = puVar9 + 0x17;
          } while (lVar8 < (long)uVar3);
          uVar7 = param_1[4];
        }
        lVar5 = lVar5 + 1;
        puVar6 = puVar6 + 0x2e;
      } while (lVar5 < (int)uVar7);
    }
    param_1[0x1f] = uVar4;
  }
  return;
}


