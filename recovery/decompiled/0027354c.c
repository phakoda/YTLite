/* Decompiled from supplied 5.2.2 arm package. VA 0x27354c. FUN_0027354c */

void FUN_0027354c(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  long lVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  code *pcVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float local_90 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 2;
  uVar3 = *(uint *)(param_1 + 4);
  lVar13 = (long)(int)uVar3;
  lVar12 = *(long *)(param_1 + 0x10);
  piVar6 = *(int **)(param_1 + 0x20);
  pcVar14 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar11 = piVar6;
  for (lVar7 = 0; lVar7 < lVar13; lVar7 = lVar7 + 1) {
    piVar5 = piVar11;
    for (lVar4 = 0; lVar4 != 0x28; lVar4 = lVar4 + 8) {
      iVar8 = *piVar5;
      fVar15 = *(float *)(param_3 + (long)(int)(uVar3 * 10 + -1) * param_4 * 4 +
                         (long)iVar8 * param_4 * -4);
      fVar16 = *(float *)(param_3 + (long)iVar8 * param_4 * 4);
      pfVar9 = (float *)(lVar12 + (long)(iVar8 >> 1) * 8);
      fVar17 = *pfVar9;
      fVar18 = pfVar9[1];
      *(float *)((long)local_90 + lVar4) = fVar15 * fVar17 - fVar16 * fVar18;
      *(float *)((long)local_90 + lVar4 + 4) = fVar15 * fVar18 + fVar16 * fVar17;
      piVar5 = piVar5 + 1;
    }
    fVar15 = local_90[2] + local_90[8];
    fVar16 = local_90[3] + local_90[9];
    fVar17 = local_90[4] + local_90[6];
    pfVar9 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar7 * 4) * 8);
    *pfVar9 = fVar17 + fVar15 + local_90[0];
    fVar18 = local_90[5] + local_90[7];
    pfVar9[1] = fVar18 + fVar16 + local_90[1];
    fVar22 = fVar17 * DAT_01a777b0;
    fVar23 = fVar15 * DAT_01a777b8;
    fVar24 = fVar18 * DAT_01a777b0;
    fVar25 = fVar16 * DAT_01a777b8;
    fVar19 = (local_90[5] - local_90[7]) * DAT_01a777b4;
    fVar21 = (local_90[3] - local_90[9]) * DAT_01a777bc;
    fVar26 = (local_90[4] - local_90[6]) * DAT_01a777b4;
    fVar20 = (local_90[2] - local_90[8]) * DAT_01a777bc;
    fVar15 = fVar15 * DAT_01a777b0 - fVar17 * DAT_01a777b8;
    fVar16 = fVar16 * DAT_01a777b0 - fVar18 * DAT_01a777b8;
    fVar17 = (local_90[3] - local_90[9]) * DAT_01a777b4 + (local_90[5] - local_90[7]) * DAT_01a777bc
    ;
    fVar18 = (local_90[2] - local_90[8]) * DAT_01a777b4 + (local_90[4] - local_90[6]) * DAT_01a777bc
    ;
    pfVar9[lVar13 * 2] = local_90[0] + fVar15 + fVar17;
    (pfVar9 + lVar13 * 2)[1] = local_90[1] + (fVar16 - fVar18);
    fVar22 = fVar22 - fVar23;
    fVar24 = fVar24 - fVar25;
    fVar19 = fVar19 - fVar21;
    fVar26 = fVar26 - fVar20;
    pfVar9[lVar13 * 4] = (fVar22 - fVar19) + local_90[0];
    (pfVar9 + lVar13 * 4)[1] = fVar24 + fVar26 + local_90[1];
    pfVar9[lVar13 * 6] = fVar22 + fVar19 + local_90[0];
    (pfVar9 + lVar13 * 6)[1] = (fVar24 - fVar26) + local_90[1];
    pfVar9[lVar13 * 8] = (fVar15 - fVar17) + local_90[0];
    (pfVar9 + lVar13 * 8)[1] = fVar16 + fVar18 + local_90[1];
    piVar11 = piVar11 + 5;
  }
  iVar8 = (int)(uVar3 * 5) >> 1;
  lVar4 = 6;
  lVar7 = 0;
  while (lVar4 = lVar4 + -1, lVar4 != 0) {
    (*pcVar14)(*(long *)(param_1 + 0x18) + lVar7);
    lVar7 = lVar7 + lVar13 * 8;
  }
  lVar4 = (long)iVar8;
  pfVar9 = (float *)(param_2 + (long)iVar8 * 8 + 4);
  pfVar10 = (float *)(lVar12 + (long)iVar8 * 8 + 4);
  for (lVar7 = 0; iVar8 = iVar8 + -1, lVar7 < lVar4; lVar7 = lVar7 + 1) {
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar6[lVar13 * 5 + (long)iVar8] * 8);
    pfVar2 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)piVar6[lVar4 + (int)(uVar3 * 5) + lVar7] * 8);
    fVar15 = *pfVar1;
    fVar16 = pfVar1[1];
    pfVar1 = (float *)(lVar12 + (long)iVar8 * 8);
    fVar17 = pfVar1[1];
    fVar18 = *pfVar2;
    fVar22 = pfVar2[1];
    pfVar2 = (float *)(param_2 + (long)iVar8 * 8);
    *pfVar2 = fVar16 * fVar17 - fVar15 * *pfVar1;
    *pfVar9 = fVar16 * *pfVar1 + fVar15 * fVar17;
    fVar15 = *pfVar10;
    pfVar9[-1] = fVar22 * fVar15 - fVar18 * pfVar10[-1];
    pfVar9 = pfVar9 + 2;
    pfVar2[1] = fVar22 * pfVar10[-1] + fVar18 * fVar15;
    pfVar10 = pfVar10 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


