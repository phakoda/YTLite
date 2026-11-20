/* Decompiled from supplied 5.2.2 arm package. VA 0x2738bc. FUN_002738bc */

void FUN_002738bc(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  long lVar9;
  int *piVar10;
  long lVar11;
  ulong uVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  code *pcVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float local_90 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *(uint *)(param_1 + 4);
  lVar16 = (long)(int)uVar6;
  lVar17 = *(long *)(param_1 + 0x10);
  piVar7 = *(int **)(param_1 + 0x20);
  iVar14 = uVar6 * 5;
  iVar13 = uVar6 * 0xf + -1;
  pcVar18 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar6 | 1)) * 8);
  piVar8 = piVar7;
  for (lVar11 = 0; lVar11 < lVar16; lVar11 = lVar11 + 1) {
    piVar10 = piVar8;
    for (lVar9 = 0; lVar9 != 0x28; lVar9 = lVar9 + 8) {
      iVar5 = *piVar10;
      if (iVar5 < iVar14) {
        fVar23 = *(float *)(param_3 + (long)(int)(iVar5 + uVar6 * 0xf) * 4);
        fVar21 = *(float *)(param_3 + (long)((iVar14 + -1) - iVar5) * 4);
        fVar19 = -*(float *)(param_3 + (long)(iVar13 - iVar5) * 4);
      }
      else {
        fVar19 = *(float *)(param_3 + (long)(int)(iVar5 + uVar6 * -5) * 4);
        fVar23 = *(float *)(param_3 + (long)(iVar13 - iVar5) * 4);
        fVar21 = -*(float *)(param_3 + (long)(int)((uVar6 * 0x19 + -1) - iVar5) * 4);
      }
      fVar21 = fVar21 - *(float *)(param_3 + (long)(iVar5 + iVar14) * 4);
      pfVar1 = (float *)(lVar17 + (long)(iVar5 >> 1) * 8);
      fVar20 = *pfVar1;
      fVar22 = pfVar1[1];
      *(float *)((long)local_90 + lVar9) = fVar21 * fVar22 + (fVar19 - fVar23) * fVar20;
      *(float *)((long)local_90 + lVar9 + 4) = fVar21 * fVar20 - (fVar19 - fVar23) * fVar22;
      piVar10 = piVar10 + 1;
    }
    fVar21 = local_90[2] + local_90[8];
    fVar19 = local_90[3] + local_90[9];
    fVar23 = local_90[4] + local_90[6];
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar11 * 4) * 8);
    *pfVar1 = fVar23 + fVar21 + local_90[0];
    fVar20 = local_90[5] + local_90[7];
    pfVar1[1] = fVar20 + fVar19 + local_90[1];
    fVar22 = fVar23 * DAT_01a777b0;
    fVar27 = fVar21 * DAT_01a777b8;
    fVar28 = fVar20 * DAT_01a777b0;
    fVar29 = fVar19 * DAT_01a777b8;
    fVar24 = (local_90[5] - local_90[7]) * DAT_01a777b4;
    fVar26 = (local_90[3] - local_90[9]) * DAT_01a777bc;
    fVar30 = (local_90[4] - local_90[6]) * DAT_01a777b4;
    fVar25 = (local_90[2] - local_90[8]) * DAT_01a777bc;
    fVar21 = fVar21 * DAT_01a777b0 - fVar23 * DAT_01a777b8;
    fVar19 = fVar19 * DAT_01a777b0 - fVar20 * DAT_01a777b8;
    fVar23 = (local_90[3] - local_90[9]) * DAT_01a777b4 + (local_90[5] - local_90[7]) * DAT_01a777bc
    ;
    fVar20 = (local_90[2] - local_90[8]) * DAT_01a777b4 + (local_90[4] - local_90[6]) * DAT_01a777bc
    ;
    pfVar1[lVar16 * 2] = local_90[0] + fVar21 + fVar23;
    (pfVar1 + lVar16 * 2)[1] = local_90[1] + (fVar19 - fVar20);
    fVar22 = fVar22 - fVar27;
    fVar28 = fVar28 - fVar29;
    fVar24 = fVar24 - fVar26;
    fVar30 = fVar30 - fVar25;
    pfVar1[lVar16 * 4] = (fVar22 - fVar24) + local_90[0];
    (pfVar1 + lVar16 * 4)[1] = fVar28 + fVar30 + local_90[1];
    pfVar1[lVar16 * 6] = fVar22 + fVar24 + local_90[0];
    (pfVar1 + lVar16 * 6)[1] = (fVar28 - fVar30) + local_90[1];
    pfVar1[lVar16 * 8] = (fVar21 - fVar23) + local_90[0];
    (pfVar1 + lVar16 * 8)[1] = fVar19 + fVar20 + local_90[1];
    piVar8 = piVar8 + 5;
  }
  uVar4 = iVar14 >> 1;
  param_4 = param_4 >> 2;
  lVar9 = 6;
  lVar11 = 0;
  while (lVar9 = lVar9 + -1, lVar9 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar11);
    lVar11 = lVar11 + lVar16 * 8;
  }
  uVar12 = -(ulong)(uVar4 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar4 << 3;
  lVar9 = lVar17 + -4;
  iVar13 = uVar4 * 2;
  lVar17 = lVar17 + 4;
  lVar11 = (long)(int)uVar4 + (long)(int)(uVar6 * 5);
  lVar15 = -4;
  iVar14 = iVar13;
  for (lVar16 = 0; iVar14 = iVar14 + -2, lVar16 < (int)uVar4; lVar16 = lVar16 + 1) {
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)((long)piVar7 + lVar15 + lVar11 * 4) * 8);
    pfVar2 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar7[lVar11 + lVar16] * 8);
    pfVar3 = (float *)(lVar17 + uVar12);
    fVar21 = *pfVar2;
    fVar19 = pfVar2[1];
    fVar23 = *pfVar1;
    fVar20 = pfVar1[1];
    *(float *)(param_2 + ((long)iVar14 * param_4 + param_4) * 4) =
         fVar21 * *pfVar3 - fVar19 * pfVar3[-1];
    pfVar1 = (float *)(lVar9 + uVar12);
    lVar9 = lVar9 + -8;
    *(float *)(param_2 + (long)iVar13 * param_4 * 4) = fVar21 * pfVar3[-1] + fVar19 * *pfVar3;
    *(float *)(param_2 + ((long)iVar13 * param_4 + param_4) * 4) =
         fVar23 * *pfVar1 - fVar20 * pfVar1[-1];
    lVar15 = lVar15 + -4;
    iVar13 = iVar13 + 2;
    *(float *)(param_2 + (long)iVar14 * param_4 * 4) = fVar23 * pfVar1[-1] + fVar20 * *pfVar1;
    lVar17 = lVar17 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


