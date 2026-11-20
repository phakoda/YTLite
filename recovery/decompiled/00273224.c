/* Decompiled from supplied 5.2.2 arm package. VA 0x273224. FUN_00273224 */

void FUN_00273224(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  int *piVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  int *piVar14;
  int *piVar15;
  long lVar16;
  long lVar17;
  code *pcVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float local_80 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *(uint *)(param_1 + 4);
  lVar17 = (long)(int)uVar6;
  lVar16 = *(long *)(param_1 + 0x10);
  piVar14 = *(int **)(param_1 + 0x20);
  iVar12 = uVar6 * 3;
  iVar11 = uVar6 * 9 + -1;
  pcVar18 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar6 | 1)) * 8);
  piVar15 = piVar14;
  for (lVar9 = 0; lVar9 < lVar17; lVar9 = lVar9 + 1) {
    piVar8 = piVar15;
    for (lVar7 = 0; lVar7 != 0x18; lVar7 = lVar7 + 8) {
      iVar5 = *piVar8;
      if (iVar5 < iVar12) {
        fVar23 = *(float *)(param_3 + (long)(int)(iVar5 + uVar6 * 9) * 4);
        fVar21 = *(float *)(param_3 + (long)((iVar12 + -1) - iVar5) * 4);
        fVar19 = -*(float *)(param_3 + (long)(iVar11 - iVar5) * 4);
      }
      else {
        fVar19 = *(float *)(param_3 + (long)(int)(iVar5 + uVar6 * -3) * 4);
        fVar23 = *(float *)(param_3 + (long)(iVar11 - iVar5) * 4);
        fVar21 = -*(float *)(param_3 + (long)(int)((uVar6 * 0xf + -1) - iVar5) * 4);
      }
      fVar21 = fVar21 - *(float *)(param_3 + (long)(iVar5 + iVar12) * 4);
      pfVar1 = (float *)(lVar16 + (long)(iVar5 >> 1) * 8);
      fVar20 = *pfVar1;
      fVar22 = pfVar1[1];
      *(float *)((long)local_80 + lVar7) = fVar21 * fVar22 + (fVar19 - fVar23) * fVar20;
      *(float *)((long)local_80 + lVar7 + 4) = fVar21 * fVar20 - (fVar19 - fVar23) * fVar22;
      piVar8 = piVar8 + 1;
    }
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar9 * 4) * 8);
    *pfVar1 = local_80[0] + local_80[2] + local_80[4];
    pfVar1[1] = local_80[3] + local_80[5] + local_80[1];
    fVar21 = (local_80[3] - local_80[5]) * _ff_cos_53_float;
    fVar19 = (local_80[2] - local_80[4]) * DAT_01a777a4;
    fVar20 = local_80[0] - (local_80[2] + local_80[4]) * DAT_01a777a8;
    fVar23 = local_80[1] - (local_80[3] + local_80[5]) * DAT_01a777a8;
    pfVar1[lVar17 * 2] = fVar21 + fVar20;
    (pfVar1 + lVar17 * 2)[1] = fVar23 - fVar19;
    pfVar1[lVar17 * 4] = fVar20 - fVar21;
    (pfVar1 + lVar17 * 4)[1] = fVar19 + fVar23;
    piVar15 = piVar15 + 3;
  }
  uVar4 = iVar12 >> 1;
  param_4 = param_4 >> 2;
  lVar7 = 4;
  lVar9 = 0;
  while (lVar7 = lVar7 + -1, lVar7 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar9);
    lVar9 = lVar9 + lVar17 * 8;
  }
  uVar10 = -(ulong)(uVar4 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar4 << 3;
  lVar7 = lVar16 + -4;
  iVar11 = uVar4 * 2;
  lVar16 = lVar16 + 4;
  lVar9 = (long)(int)uVar4 + (long)(int)(uVar6 * 3);
  lVar13 = -4;
  iVar12 = iVar11;
  for (lVar17 = 0; iVar12 = iVar12 + -2, lVar17 < (int)uVar4; lVar17 = lVar17 + 1) {
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)((long)piVar14 + lVar13 + lVar9 * 4) * 8);
    pfVar2 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar14[lVar9 + lVar17] * 8);
    pfVar3 = (float *)(lVar16 + uVar10);
    fVar21 = *pfVar2;
    fVar19 = pfVar2[1];
    fVar23 = *pfVar1;
    fVar20 = pfVar1[1];
    *(float *)(param_2 + ((long)iVar12 * param_4 + param_4) * 4) =
         fVar21 * *pfVar3 - fVar19 * pfVar3[-1];
    pfVar1 = (float *)(lVar7 + uVar10);
    lVar7 = lVar7 + -8;
    *(float *)(param_2 + (long)iVar11 * param_4 * 4) = fVar21 * pfVar3[-1] + fVar19 * *pfVar3;
    *(float *)(param_2 + ((long)iVar11 * param_4 + param_4) * 4) =
         fVar23 * *pfVar1 - fVar20 * pfVar1[-1];
    lVar13 = lVar13 + -4;
    iVar11 = iVar11 + 2;
    *(float *)(param_2 + (long)iVar12 * param_4 * 4) = fVar23 * pfVar1[-1] + fVar20 * *pfVar1;
    lVar16 = lVar16 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


