/* Decompiled from supplied 5.2.2 arm package. VA 0x271808. FUN_00271808 */

void FUN_00271808(double *param_1,long param_2,int param_3)

{
  long lVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  double *pdVar9;
  double *pdVar10;
  double *pdVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  
  uVar5 = param_3 << 1;
  uVar6 = param_3 << 2;
  uVar7 = param_3 * 6;
  pdVar9 = param_1 + (long)(int)uVar6 * 2;
  pdVar10 = param_1 + (long)(int)uVar7 * 2;
  pdVar11 = param_1 + (long)(int)uVar5 * 2;
  dVar15 = *param_1;
  dVar16 = param_1[1];
  dVar17 = *pdVar11;
  dVar18 = pdVar11[1];
  dVar19 = *pdVar10 - *pdVar9;
  dVar12 = *pdVar9 + *pdVar10;
  dVar13 = pdVar9[1] - pdVar10[1];
  dVar14 = pdVar9[1] + pdVar10[1];
  *pdVar9 = dVar15 - dVar12;
  *param_1 = dVar12 + dVar15;
  pdVar10[1] = dVar18 - dVar19;
  pdVar11[1] = dVar19 + dVar18;
  *pdVar10 = dVar17 - dVar13;
  iVar8 = 1 - param_3;
  *pdVar11 = dVar13 + dVar17;
  pdVar9[1] = dVar16 - dVar14;
  lVar1 = param_2 + (long)(int)uVar5 * 8;
  pdVar9 = param_1 + (long)(int)(param_3 << 2 | 1) * 2;
  pdVar10 = param_1 + (long)(int)(param_3 << 1 | 1) * 2;
  param_1[1] = dVar14 + dVar16;
  dVar12 = *(double *)(param_2 + 8);
  pdVar11 = param_1 + (long)(int)(uVar7 | 1) * 2;
  dVar16 = *(double *)(lVar1 + -8);
  dVar15 = *pdVar9 * dVar12 + pdVar9[1] * dVar16;
  dVar18 = param_1[2];
  dVar19 = param_1[3];
  dVar13 = dVar12 * pdVar9[1] - *pdVar9 * dVar16;
  dVar14 = dVar12 * *pdVar11 - dVar16 * pdVar11[1];
  dVar17 = *pdVar10;
  dVar20 = pdVar10[1];
  dVar12 = dVar16 * *pdVar11 + dVar12 * pdVar11[1];
  dVar16 = dVar14 - dVar15;
  dVar15 = dVar15 + dVar14;
  dVar14 = dVar13 - dVar12;
  dVar13 = dVar13 + dVar12;
  *pdVar9 = dVar18 - dVar15;
  param_1[2] = dVar18 + dVar15;
  pdVar11[1] = dVar20 - dVar16;
  pdVar10[1] = dVar16 + dVar20;
  *pdVar11 = dVar17 - dVar14;
  *pdVar10 = dVar17 + dVar14;
  pdVar9[1] = dVar19 - dVar13;
  param_1[3] = dVar19 + dVar13;
  pdVar9 = (double *)(param_2 + 0x18);
  pdVar10 = (double *)(lVar1 + -0x18);
  pdVar11 = param_1 + 7;
  do {
    pdVar2 = (double *)
             ((long)pdVar11 + (-(ulong)(uVar6 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar6 << 4));
    dVar12 = pdVar9[-1];
    dVar14 = pdVar10[1];
    pdVar3 = (double *)
             ((long)pdVar11 + (-(ulong)(uVar7 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar7 << 4));
    dVar16 = pdVar2[-3] * dVar12 + pdVar2[-2] * dVar14;
    dVar18 = pdVar11[-3];
    dVar19 = pdVar11[-2];
    pdVar4 = (double *)
             ((long)pdVar11 + (-(ulong)(uVar5 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar5 << 4));
    iVar8 = iVar8 + 1;
    dVar13 = dVar12 * pdVar2[-2] - pdVar2[-3] * dVar14;
    dVar15 = dVar12 * pdVar3[-3] - dVar14 * pdVar3[-2];
    dVar17 = pdVar4[-3];
    dVar20 = pdVar4[-2];
    dVar12 = dVar14 * pdVar3[-3] + dVar12 * pdVar3[-2];
    dVar14 = dVar15 - dVar16;
    dVar16 = dVar16 + dVar15;
    dVar15 = dVar13 - dVar12;
    dVar13 = dVar13 + dVar12;
    pdVar2[-3] = dVar18 - dVar16;
    pdVar11[-3] = dVar18 + dVar16;
    pdVar3[-2] = dVar20 - dVar14;
    pdVar4[-2] = dVar14 + dVar20;
    pdVar3[-3] = dVar17 - dVar15;
    pdVar4[-3] = dVar17 + dVar15;
    pdVar2[-2] = dVar19 - dVar13;
    pdVar11[-2] = dVar19 + dVar13;
    dVar13 = *pdVar9;
    dVar15 = *pdVar10;
    dVar18 = pdVar11[-1];
    dVar17 = pdVar2[-1] * dVar13 + *pdVar2 * dVar15;
    dVar19 = *pdVar11;
    dVar12 = dVar13 * *pdVar2 - pdVar2[-1] * dVar15;
    dVar14 = pdVar4[-1];
    dVar16 = dVar13 * pdVar3[-1] - dVar15 * *pdVar3;
    dVar20 = *pdVar4;
    dVar13 = dVar15 * pdVar3[-1] + dVar13 * *pdVar3;
    dVar15 = dVar16 - dVar17;
    dVar17 = dVar17 + dVar16;
    dVar16 = dVar12 - dVar13;
    dVar12 = dVar12 + dVar13;
    pdVar2[-1] = dVar18 - dVar17;
    pdVar11[-1] = dVar18 + dVar17;
    *pdVar3 = dVar20 - dVar15;
    *pdVar4 = dVar15 + dVar20;
    pdVar3[-1] = dVar14 - dVar16;
    pdVar4[-1] = dVar14 + dVar16;
    *pdVar2 = dVar19 - dVar12;
    *pdVar11 = dVar19 + dVar12;
    pdVar9 = pdVar9 + 2;
    pdVar10 = pdVar10 + -2;
    pdVar11 = pdVar11 + 4;
  } while (iVar8 != 0);
  return;
}


