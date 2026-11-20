/* Decompiled from supplied 5.2.2 arm package. VA 0x270a84. FUN_00270a84 */

void FUN_00270a84(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  double *pdVar7;
  code *pcVar8;
  double *pdVar9;
  long lVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  
  lVar5 = 0;
  lVar10 = *(long *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 4);
  param_4 = param_4 >> 3;
  pcVar8 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  pdVar7 = (double *)(param_3 + param_4 * (long)(int)(uVar3 * 2 + -1) * 8);
  for (lVar6 = 0; lVar6 < (int)uVar3; lVar6 = lVar6 + 1) {
    dVar11 = *pdVar7;
    pdVar9 = (double *)(lVar10 + lVar5 * 8);
    dVar12 = *(double *)(param_3 + (long)(int)lVar5 * param_4 * 8);
    dVar13 = pdVar9[1];
    pdVar2 = (double *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar6 * 4) * 0x10);
    *pdVar2 = dVar11 * *pdVar9 - dVar12 * dVar13;
    lVar5 = lVar5 + 2;
    pdVar2[1] = dVar11 * dVar13 + dVar12 * *pdVar9;
    pdVar7 = pdVar7 + param_4 * -2;
  }
  iVar4 = (int)uVar3 >> 1;
  (*pcVar8)(param_2);
  lVar6 = (long)iVar4;
  pdVar7 = (double *)(lVar10 + (long)iVar4 * 0x10 + 8);
  pdVar9 = (double *)(param_2 + (long)iVar4 * 0x10 + 8);
  for (lVar5 = 0; iVar4 = iVar4 + -1, lVar5 < lVar6; lVar5 = lVar5 + 1) {
    pdVar1 = (double *)(param_2 + (long)iVar4 * 0x10);
    pdVar2 = (double *)(lVar10 + (long)iVar4 * 0x10);
    dVar11 = *pdVar1;
    dVar12 = pdVar2[1];
    dVar13 = *pdVar9;
    dVar14 = pdVar9[-1];
    *pdVar1 = pdVar1[1] * dVar12 - dVar11 * *pdVar2;
    *pdVar9 = pdVar1[1] * *pdVar2 + dVar11 * dVar12;
    dVar11 = *pdVar7;
    pdVar9[-1] = dVar13 * dVar11 - dVar14 * pdVar7[-1];
    pdVar2 = pdVar7 + -1;
    pdVar7 = pdVar7 + 2;
    pdVar1[1] = dVar13 * *pdVar2 + dVar14 * dVar11;
    pdVar9 = pdVar9 + 2;
  }
  return;
}


