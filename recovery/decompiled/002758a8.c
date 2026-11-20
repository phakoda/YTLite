/* Decompiled from supplied 5.2.2 arm package. VA 0x2758a8. FUN_002758a8 */

void FUN_002758a8(float *param_1,long param_2,int param_3)

{
  long lVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  uVar5 = param_3 << 1;
  uVar6 = param_3 << 2;
  uVar7 = param_3 * 6;
  pfVar9 = param_1 + (long)(int)uVar6 * 2;
  pfVar10 = param_1 + (long)(int)uVar7 * 2;
  pfVar11 = param_1 + (long)(int)uVar5 * 2;
  fVar15 = *param_1;
  fVar16 = param_1[1];
  fVar17 = *pfVar11;
  fVar18 = pfVar11[1];
  fVar19 = *pfVar10 - *pfVar9;
  fVar12 = *pfVar9 + *pfVar10;
  fVar13 = pfVar9[1] - pfVar10[1];
  fVar14 = pfVar9[1] + pfVar10[1];
  *pfVar9 = fVar15 - fVar12;
  *param_1 = fVar12 + fVar15;
  pfVar10[1] = fVar18 - fVar19;
  pfVar11[1] = fVar19 + fVar18;
  *pfVar10 = fVar17 - fVar13;
  iVar8 = 1 - param_3;
  *pfVar11 = fVar13 + fVar17;
  pfVar9[1] = fVar16 - fVar14;
  lVar1 = param_2 + (long)(int)uVar5 * 4;
  pfVar9 = param_1 + (long)(int)(param_3 << 2 | 1) * 2;
  pfVar10 = param_1 + (long)(int)(param_3 << 1 | 1) * 2;
  param_1[1] = fVar14 + fVar16;
  fVar12 = *(float *)(param_2 + 4);
  pfVar11 = param_1 + (long)(int)(uVar7 | 1) * 2;
  fVar16 = *(float *)(lVar1 + -4);
  fVar15 = *pfVar9 * fVar12 + pfVar9[1] * fVar16;
  fVar18 = param_1[2];
  fVar19 = param_1[3];
  fVar13 = fVar12 * pfVar9[1] - *pfVar9 * fVar16;
  fVar14 = fVar12 * *pfVar11 - fVar16 * pfVar11[1];
  fVar17 = *pfVar10;
  fVar20 = pfVar10[1];
  fVar12 = fVar16 * *pfVar11 + fVar12 * pfVar11[1];
  fVar16 = fVar14 - fVar15;
  fVar15 = fVar15 + fVar14;
  fVar14 = fVar13 - fVar12;
  fVar13 = fVar13 + fVar12;
  *pfVar9 = fVar18 - fVar15;
  param_1[2] = fVar18 + fVar15;
  pfVar11[1] = fVar20 - fVar16;
  pfVar10[1] = fVar16 + fVar20;
  *pfVar11 = fVar17 - fVar14;
  *pfVar10 = fVar17 + fVar14;
  pfVar9[1] = fVar19 - fVar13;
  param_1[3] = fVar19 + fVar13;
  pfVar9 = (float *)(param_2 + 0xc);
  pfVar10 = (float *)(lVar1 + -0xc);
  pfVar11 = param_1 + 7;
  do {
    pfVar2 = (float *)((long)pfVar11 +
                      (-(ulong)(uVar6 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar6 << 3));
    fVar12 = pfVar9[-1];
    fVar14 = pfVar10[1];
    pfVar3 = (float *)((long)pfVar11 +
                      (-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3));
    fVar16 = pfVar2[-3] * fVar12 + pfVar2[-2] * fVar14;
    fVar18 = pfVar11[-3];
    fVar19 = pfVar11[-2];
    pfVar4 = (float *)((long)pfVar11 +
                      (-(ulong)(uVar5 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar5 << 3));
    iVar8 = iVar8 + 1;
    fVar13 = fVar12 * pfVar2[-2] - pfVar2[-3] * fVar14;
    fVar15 = fVar12 * pfVar3[-3] - fVar14 * pfVar3[-2];
    fVar17 = pfVar4[-3];
    fVar20 = pfVar4[-2];
    fVar12 = fVar14 * pfVar3[-3] + fVar12 * pfVar3[-2];
    fVar14 = fVar15 - fVar16;
    fVar16 = fVar16 + fVar15;
    fVar15 = fVar13 - fVar12;
    fVar13 = fVar13 + fVar12;
    pfVar2[-3] = fVar18 - fVar16;
    pfVar11[-3] = fVar18 + fVar16;
    pfVar3[-2] = fVar20 - fVar14;
    pfVar4[-2] = fVar14 + fVar20;
    pfVar3[-3] = fVar17 - fVar15;
    pfVar4[-3] = fVar17 + fVar15;
    pfVar2[-2] = fVar19 - fVar13;
    pfVar11[-2] = fVar19 + fVar13;
    fVar13 = *pfVar9;
    fVar15 = *pfVar10;
    fVar18 = pfVar11[-1];
    fVar17 = pfVar2[-1] * fVar13 + *pfVar2 * fVar15;
    fVar19 = *pfVar11;
    fVar12 = fVar13 * *pfVar2 - pfVar2[-1] * fVar15;
    fVar14 = pfVar4[-1];
    fVar16 = fVar13 * pfVar3[-1] - fVar15 * *pfVar3;
    fVar20 = *pfVar4;
    fVar13 = fVar15 * pfVar3[-1] + fVar13 * *pfVar3;
    fVar15 = fVar16 - fVar17;
    fVar17 = fVar17 + fVar16;
    fVar16 = fVar12 - fVar13;
    fVar12 = fVar12 + fVar13;
    pfVar2[-1] = fVar18 - fVar17;
    pfVar11[-1] = fVar18 + fVar17;
    *pfVar3 = fVar20 - fVar15;
    *pfVar4 = fVar15 + fVar20;
    pfVar3[-1] = fVar14 - fVar16;
    pfVar4[-1] = fVar14 + fVar16;
    *pfVar2 = fVar19 - fVar12;
    *pfVar11 = fVar19 + fVar12;
    pfVar9 = pfVar9 + 2;
    pfVar10 = pfVar10 + -2;
    pfVar11 = pfVar11 + 4;
  } while (iVar8 != 0);
  return;
}


