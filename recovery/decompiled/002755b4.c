/* Decompiled from supplied 5.2.2 arm package. VA 0x2755b4. FUN_002755b4 */

void FUN_002755b4(float *param_1,long param_2,int param_3)

{
  long lVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  uVar5 = param_3 << 2;
  uVar7 = param_3 * 6;
  pfVar8 = param_1 + (long)(int)uVar5 * 2;
  pfVar9 = param_1 + (long)(int)uVar7 * 2;
  fVar11 = *pfVar9;
  fVar14 = pfVar9[1];
  fVar12 = *pfVar8;
  fVar13 = pfVar8[1];
  fVar15 = fVar12 + fVar11;
  *pfVar8 = *param_1 - fVar15;
  uVar6 = param_3 << 1;
  pfVar10 = param_1 + (long)(int)uVar6 * 2;
  *param_1 = fVar15 + *param_1;
  fVar11 = fVar11 - fVar12;
  pfVar9[1] = pfVar10[1] - fVar11;
  fVar12 = fVar13 - fVar14;
  pfVar10[1] = fVar11 + pfVar10[1];
  *pfVar9 = *pfVar10 - fVar12;
  lVar1 = param_2 + (long)(int)uVar6 * 4;
  *pfVar10 = fVar12 + *pfVar10;
  pfVar9 = param_1 + (long)(int)(param_3 << 2 | 1) * 2;
  fVar13 = fVar13 + fVar14;
  pfVar8[1] = param_1[1] - fVar13;
  pfVar8 = param_1 + (long)(int)(uVar7 | 1) * 2;
  param_1[1] = fVar13 + param_1[1];
  fVar11 = *(float *)(param_2 + 4);
  fVar12 = *pfVar9;
  fVar13 = pfVar9[1];
  fVar14 = *(float *)(lVar1 + -4);
  fVar15 = *pfVar8;
  fVar16 = pfVar8[1];
  fVar17 = fVar12 * fVar11 + fVar13 * fVar14;
  fVar18 = fVar11 * fVar15 - fVar14 * fVar16;
  fVar19 = fVar17 + fVar18;
  *pfVar9 = param_1[2] - fVar19;
  pfVar10 = param_1 + (long)(int)(param_3 << 1 | 1) * 2;
  param_1[2] = param_1[2] + fVar19;
  fVar18 = fVar18 - fVar17;
  pfVar8[1] = pfVar10[1] - fVar18;
  fVar12 = fVar11 * fVar13 - fVar12 * fVar14;
  fVar11 = fVar14 * fVar15 + fVar11 * fVar16;
  fVar13 = fVar12 - fVar11;
  pfVar10[1] = fVar18 + pfVar10[1];
  *pfVar8 = *pfVar10 - fVar13;
  *pfVar10 = fVar13 + *pfVar10;
  fVar12 = fVar12 + fVar11;
  pfVar9[1] = param_1[3] - fVar12;
  param_3 = 1 - param_3;
  param_1[3] = fVar12 + param_1[3];
  pfVar8 = (float *)(param_2 + 0xc);
  pfVar9 = param_1 + 7;
  pfVar10 = (float *)(lVar1 + -0xc);
  do {
    pfVar2 = (float *)((long)pfVar9 +
                      (-(ulong)(uVar5 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar5 << 3));
    fVar11 = pfVar8[-1];
    fVar13 = pfVar10[1];
    pfVar3 = (float *)((long)pfVar9 +
                      (-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3));
    pfVar4 = (float *)((long)pfVar9 +
                      (-(ulong)(uVar6 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar6 << 3));
    fVar12 = pfVar2[-3];
    fVar14 = pfVar2[-2];
    fVar18 = pfVar3[-3];
    fVar16 = pfVar3[-2];
    fVar17 = fVar12 * fVar11 + fVar14 * fVar13;
    fVar15 = fVar11 * fVar18 - fVar13 * fVar16;
    fVar19 = fVar17 + fVar15;
    pfVar2[-3] = pfVar9[-3] - fVar19;
    pfVar9[-3] = pfVar9[-3] + fVar19;
    fVar12 = fVar11 * fVar14 - fVar12 * fVar13;
    fVar15 = fVar15 - fVar17;
    pfVar3[-2] = pfVar4[-2] - fVar15;
    fVar11 = fVar13 * fVar18 + fVar11 * fVar16;
    fVar13 = fVar12 - fVar11;
    pfVar4[-2] = fVar15 + pfVar4[-2];
    pfVar3[-3] = pfVar4[-3] - fVar13;
    pfVar4[-3] = fVar13 + pfVar4[-3];
    fVar12 = fVar12 + fVar11;
    pfVar2[-2] = pfVar9[-2] - fVar12;
    pfVar9[-2] = fVar12 + pfVar9[-2];
    fVar11 = pfVar2[-1];
    fVar12 = *pfVar8;
    fVar13 = *pfVar2;
    fVar15 = *pfVar10;
    fVar18 = pfVar3[-1];
    fVar16 = *pfVar3;
    fVar17 = fVar11 * fVar12 + fVar13 * fVar15;
    fVar14 = fVar12 * fVar18 - fVar15 * fVar16;
    fVar19 = fVar17 + fVar14;
    pfVar2[-1] = pfVar9[-1] - fVar19;
    pfVar9[-1] = pfVar9[-1] + fVar19;
    fVar11 = fVar12 * fVar13 - fVar11 * fVar15;
    fVar14 = fVar14 - fVar17;
    *pfVar3 = *pfVar4 - fVar14;
    fVar12 = fVar15 * fVar18 + fVar12 * fVar16;
    fVar13 = fVar11 - fVar12;
    *pfVar4 = fVar14 + *pfVar4;
    pfVar3[-1] = pfVar4[-1] - fVar13;
    pfVar4[-1] = fVar13 + pfVar4[-1];
    fVar11 = fVar11 + fVar12;
    *pfVar2 = *pfVar9 - fVar11;
    param_3 = param_3 + 1;
    *pfVar9 = fVar11 + *pfVar9;
    pfVar8 = pfVar8 + 2;
    pfVar9 = pfVar9 + 4;
    pfVar10 = pfVar10 + -2;
  } while (param_3 != 0);
  return;
}


