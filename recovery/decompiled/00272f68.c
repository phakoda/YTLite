/* Decompiled from supplied 5.2.2 arm package. VA 0x272f68. FUN_00272f68 */

void FUN_00272f68(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int *piVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  code *pcVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float local_80 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 2;
  uVar3 = *(uint *)(param_1 + 4);
  lVar13 = (long)(int)uVar3;
  lVar12 = *(long *)(param_1 + 0x10);
  piVar4 = *(int **)(param_1 + 0x20);
  pcVar14 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar9 = piVar4;
  for (lVar5 = 0; lVar5 < lVar13; lVar5 = lVar5 + 1) {
    piVar11 = piVar9;
    for (lVar10 = 0; lVar10 != 0x18; lVar10 = lVar10 + 8) {
      iVar6 = *piVar11;
      fVar15 = *(float *)(param_3 + (long)(int)(uVar3 * 6 + -1) * param_4 * 4 +
                         (long)iVar6 * param_4 * -4);
      fVar16 = *(float *)(param_3 + (long)iVar6 * param_4 * 4);
      pfVar7 = (float *)(lVar12 + (long)(iVar6 >> 1) * 8);
      fVar17 = *pfVar7;
      fVar18 = pfVar7[1];
      *(float *)((long)local_80 + lVar10) = fVar15 * fVar17 - fVar16 * fVar18;
      *(float *)((long)local_80 + lVar10 + 4) = fVar15 * fVar18 + fVar16 * fVar17;
      piVar11 = piVar11 + 1;
    }
    pfVar7 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4) * 8);
    *pfVar7 = local_80[0] + local_80[2] + local_80[4];
    pfVar7[1] = local_80[3] + local_80[5] + local_80[1];
    fVar15 = (local_80[3] - local_80[5]) * _ff_cos_53_float;
    fVar16 = (local_80[2] - local_80[4]) * DAT_01a777a4;
    fVar18 = local_80[0] - (local_80[2] + local_80[4]) * DAT_01a777a8;
    fVar17 = local_80[1] - (local_80[3] + local_80[5]) * DAT_01a777a8;
    pfVar7[lVar13 * 2] = fVar15 + fVar18;
    (pfVar7 + lVar13 * 2)[1] = fVar17 - fVar16;
    pfVar7[lVar13 * 4] = fVar18 - fVar15;
    (pfVar7 + lVar13 * 4)[1] = fVar16 + fVar17;
    piVar9 = piVar9 + 3;
  }
  iVar6 = (int)(uVar3 * 3) >> 1;
  lVar10 = 4;
  lVar5 = 0;
  while (lVar10 = lVar10 + -1, lVar10 != 0) {
    (*pcVar14)(*(long *)(param_1 + 0x18) + lVar5);
    lVar5 = lVar5 + lVar13 * 8;
  }
  lVar10 = (long)iVar6;
  pfVar7 = (float *)(param_2 + (long)iVar6 * 8 + 4);
  pfVar8 = (float *)(lVar12 + (long)iVar6 * 8 + 4);
  for (lVar5 = 0; iVar6 = iVar6 + -1, lVar5 < lVar10; lVar5 = lVar5 + 1) {
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar4[lVar13 * 3 + (long)iVar6] * 8);
    pfVar2 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)piVar4[lVar10 + (int)(uVar3 * 3) + lVar5] * 8);
    fVar15 = *pfVar1;
    fVar16 = pfVar1[1];
    pfVar1 = (float *)(lVar12 + (long)iVar6 * 8);
    fVar17 = pfVar1[1];
    fVar18 = *pfVar2;
    fVar19 = pfVar2[1];
    pfVar2 = (float *)(param_2 + (long)iVar6 * 8);
    *pfVar2 = fVar16 * fVar17 - fVar15 * *pfVar1;
    *pfVar7 = fVar16 * *pfVar1 + fVar15 * fVar17;
    fVar15 = *pfVar8;
    pfVar7[-1] = fVar19 * fVar15 - fVar18 * pfVar8[-1];
    pfVar7 = pfVar7 + 2;
    pfVar2[1] = fVar19 * pfVar8[-1] + fVar18 * fVar15;
    pfVar8 = pfVar8 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


