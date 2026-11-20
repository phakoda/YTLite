/* Decompiled from supplied 5.2.2 arm package. VA 0x271514. FUN_00271514 */

void FUN_00271514(double *param_1,long param_2,int param_3)

{
  long lVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  double *pdVar8;
  double *pdVar9;
  double *pdVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  
  uVar5 = param_3 << 2;
  uVar7 = param_3 * 6;
  pdVar8 = param_1 + (long)(int)uVar5 * 2;
  pdVar9 = param_1 + (long)(int)uVar7 * 2;
  dVar11 = *pdVar9;
  dVar14 = pdVar9[1];
  dVar12 = *pdVar8;
  dVar13 = pdVar8[1];
  dVar15 = dVar12 + dVar11;
  *pdVar8 = *param_1 - dVar15;
  uVar6 = param_3 << 1;
  pdVar10 = param_1 + (long)(int)uVar6 * 2;
  *param_1 = dVar15 + *param_1;
  dVar11 = dVar11 - dVar12;
  pdVar9[1] = pdVar10[1] - dVar11;
  dVar12 = dVar13 - dVar14;
  pdVar10[1] = dVar11 + pdVar10[1];
  *pdVar9 = *pdVar10 - dVar12;
  lVar1 = param_2 + (long)(int)uVar6 * 8;
  *pdVar10 = dVar12 + *pdVar10;
  pdVar9 = param_1 + (long)(int)(param_3 << 2 | 1) * 2;
  dVar13 = dVar13 + dVar14;
  pdVar8[1] = param_1[1] - dVar13;
  pdVar8 = param_1 + (long)(int)(uVar7 | 1) * 2;
  param_1[1] = dVar13 + param_1[1];
  dVar11 = *(double *)(param_2 + 8);
  dVar12 = *pdVar9;
  dVar13 = pdVar9[1];
  dVar14 = *(double *)(lVar1 + -8);
  dVar15 = *pdVar8;
  dVar16 = pdVar8[1];
  dVar17 = dVar12 * dVar11 + dVar13 * dVar14;
  dVar18 = dVar11 * dVar15 - dVar14 * dVar16;
  dVar19 = dVar17 + dVar18;
  *pdVar9 = param_1[2] - dVar19;
  pdVar10 = param_1 + (long)(int)(param_3 << 1 | 1) * 2;
  param_1[2] = param_1[2] + dVar19;
  dVar18 = dVar18 - dVar17;
  pdVar8[1] = pdVar10[1] - dVar18;
  dVar12 = dVar11 * dVar13 - dVar12 * dVar14;
  dVar11 = dVar14 * dVar15 + dVar11 * dVar16;
  dVar13 = dVar12 - dVar11;
  pdVar10[1] = dVar18 + pdVar10[1];
  *pdVar8 = *pdVar10 - dVar13;
  *pdVar10 = dVar13 + *pdVar10;
  dVar12 = dVar12 + dVar11;
  pdVar9[1] = param_1[3] - dVar12;
  param_3 = 1 - param_3;
  param_1[3] = dVar12 + param_1[3];
  pdVar8 = (double *)(param_2 + 0x18);
  pdVar9 = param_1 + 7;
  pdVar10 = (double *)(lVar1 + -0x18);
  do {
    pdVar2 = (double *)
             ((long)pdVar9 + (-(ulong)(uVar5 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar5 << 4));
    dVar11 = pdVar8[-1];
    dVar13 = pdVar10[1];
    pdVar3 = (double *)
             ((long)pdVar9 + (-(ulong)(uVar7 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar7 << 4));
    pdVar4 = (double *)
             ((long)pdVar9 + (-(ulong)(uVar6 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar6 << 4));
    dVar12 = pdVar2[-3];
    dVar14 = pdVar2[-2];
    dVar18 = pdVar3[-3];
    dVar16 = pdVar3[-2];
    dVar17 = dVar12 * dVar11 + dVar14 * dVar13;
    dVar15 = dVar11 * dVar18 - dVar13 * dVar16;
    dVar19 = dVar17 + dVar15;
    pdVar2[-3] = pdVar9[-3] - dVar19;
    pdVar9[-3] = pdVar9[-3] + dVar19;
    dVar12 = dVar11 * dVar14 - dVar12 * dVar13;
    dVar15 = dVar15 - dVar17;
    pdVar3[-2] = pdVar4[-2] - dVar15;
    dVar11 = dVar13 * dVar18 + dVar11 * dVar16;
    dVar13 = dVar12 - dVar11;
    pdVar4[-2] = dVar15 + pdVar4[-2];
    pdVar3[-3] = pdVar4[-3] - dVar13;
    pdVar4[-3] = dVar13 + pdVar4[-3];
    dVar12 = dVar12 + dVar11;
    pdVar2[-2] = pdVar9[-2] - dVar12;
    pdVar9[-2] = dVar12 + pdVar9[-2];
    dVar11 = pdVar2[-1];
    dVar12 = *pdVar8;
    dVar13 = *pdVar2;
    dVar15 = *pdVar10;
    dVar18 = pdVar3[-1];
    dVar16 = *pdVar3;
    dVar17 = dVar11 * dVar12 + dVar13 * dVar15;
    dVar14 = dVar12 * dVar18 - dVar15 * dVar16;
    dVar19 = dVar17 + dVar14;
    pdVar2[-1] = pdVar9[-1] - dVar19;
    pdVar9[-1] = pdVar9[-1] + dVar19;
    dVar11 = dVar12 * dVar13 - dVar11 * dVar15;
    dVar14 = dVar14 - dVar17;
    *pdVar3 = *pdVar4 - dVar14;
    dVar12 = dVar15 * dVar18 + dVar12 * dVar16;
    dVar13 = dVar11 - dVar12;
    *pdVar4 = dVar14 + *pdVar4;
    pdVar3[-1] = pdVar4[-1] - dVar13;
    pdVar4[-1] = dVar13 + pdVar4[-1];
    dVar11 = dVar11 + dVar12;
    *pdVar2 = *pdVar9 - dVar11;
    param_3 = param_3 + 1;
    *pdVar9 = dVar11 + *pdVar9;
    pdVar8 = pdVar8 + 2;
    pdVar9 = pdVar9 + 4;
    pdVar10 = pdVar10 + -2;
  } while (param_3 != 0);
  return;
}


