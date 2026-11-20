/* Decompiled from supplied 5.2.2 arm package. VA 0x246ab8. FUN_00246ab8 */

void FUN_00246ab8(long param_1,int param_2,short param_3,long param_4,long param_5,long param_6,
                 short *param_7,undefined4 *param_8,short *param_9)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  short sVar8;
  long lVar9;
  uint uVar10;
  
  if (param_3 == 0) {
    for (lVar9 = 0; (int)lVar9 < param_2; lVar9 = lVar9 + 1) {
      iVar3 = *(int *)(param_1 + lVar9 * 4);
      iVar1 = 0;
      if (-1 < iVar3) {
        iVar1 = iVar3;
      }
      *(int *)(param_1 + lVar9 * 4) = iVar1;
    }
  }
  uVar7 = (*DAT_0191b7d8)(param_1,param_2);
  if (uVar7 == 0) {
    sVar8 = 0;
  }
  else {
    uVar7 = uVar7 ^ (int)uVar7 >> 0x1f;
    uVar10 = 0;
    if (uVar7 >> 0xf == 0) {
      uVar10 = 0x10;
    }
    uVar2 = uVar10 | 8;
    if ((0xff800000U >> (ulong)uVar10 & uVar7) != 0) {
      uVar2 = uVar10;
    }
    uVar10 = uVar2 | 4;
    if ((0xf8000000U >> (ulong)uVar2 & uVar7) != 0) {
      uVar10 = uVar2;
    }
    uVar2 = uVar10 | 2;
    if ((0xe0000000U >> (ulong)uVar10 & uVar7) != 0) {
      uVar2 = uVar10;
    }
    sVar8 = (short)uVar2;
    if ((0xc0000000U >> (ulong)(uint)(int)sVar8 & uVar7) == 0) {
      sVar8 = sVar8 + 1;
    }
  }
  sVar6 = -0x8000;
  for (lVar9 = 0; (int)lVar9 < param_2; lVar9 = lVar9 + 1) {
    iVar1 = (*(int *)(param_1 + lVar9 * 4) << (ulong)((int)sVar8 & 0x1f)) >> 0x10;
    iVar1 = ((uint)(iVar1 * iVar1) >> 0x10) * (int)*(short *)(param_4 + lVar9 * 2);
    *(int *)(param_6 + lVar9 * 4) = iVar1;
    sVar4 = sVar6;
    if ((iVar1 != 0) && (sVar4 = *(short *)(param_5 + lVar9 * 2), sVar4 <= sVar6)) {
      sVar4 = sVar6;
    }
    sVar6 = sVar4;
  }
  lVar9 = 0;
  sVar4 = 0;
  if (sVar6 != -0x8000) {
    sVar4 = sVar6;
  }
  for (; (int)lVar9 < param_2; lVar9 = lVar9 + 1) {
    iVar3 = *(int *)(param_6 + lVar9 * 4);
    iVar5 = (int)sVar4 - (int)*(short *)(param_5 + lVar9 * 2);
    iVar1 = 0x10;
    if (iVar5 < 0x11) {
      iVar1 = iVar5;
    }
    iVar5 = iVar3 << (ulong)(-(int)(short)iVar1 & 0x1f);
    if (0xffff < iVar1 * 0x10000) {
      iVar5 = iVar3 >> ((int)(short)iVar1 & 0x1fU);
    }
    *(int *)(param_6 + lVar9 * 4) = iVar5;
  }
  sVar6 = FUN_0024eacc(param_6,param_2);
  *param_7 = sVar6;
  *param_8 = *(undefined4 *)(param_6 + (long)sVar6 * 4);
  *param_9 = sVar8 * -2 + 0x20 + sVar4;
  return;
}


