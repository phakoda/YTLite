/* Decompiled from supplied 5.2.2 arm package. VA 0x27432c. FUN_0027432c */

void FUN_0027432c(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  long lVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  int *piVar17;
  int *piVar18;
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
  float local_158 [60];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar5 = *(uint *)(param_1 + 4);
  lVar15 = (long)(int)uVar5;
  lVar16 = *(long *)(param_1 + 0x10);
  piVar17 = *(int **)(param_1 + 0x20);
  iVar14 = uVar5 * 0xf;
  iVar12 = uVar5 * 0x2d + -1;
  pcVar8 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar5 | 1)) * 8);
  piVar18 = piVar17;
  for (lVar7 = 0; lVar7 < lVar15; lVar7 = lVar7 + 1) {
    piVar6 = piVar18;
    for (lVar9 = 0; lVar9 != 0x78; lVar9 = lVar9 + 8) {
      iVar4 = *piVar6;
      if (iVar4 < iVar14) {
        fVar24 = *(float *)(param_3 + (long)(int)(iVar4 + uVar5 * 0x2d) * 4);
        fVar21 = *(float *)(param_3 + (long)((iVar14 + -1) - iVar4) * 4);
        fVar19 = -*(float *)(param_3 + (long)(iVar12 - iVar4) * 4);
      }
      else {
        fVar19 = *(float *)(param_3 + (long)(int)(iVar4 + uVar5 * -0xf) * 4);
        fVar24 = *(float *)(param_3 + (long)(iVar12 - iVar4) * 4);
        fVar21 = -*(float *)(param_3 + (long)(int)((uVar5 * 0x4b + -1) - iVar4) * 4);
      }
      fVar21 = fVar21 - *(float *)(param_3 + (long)(iVar4 + iVar14) * 4);
      pfVar13 = (float *)(lVar16 + (long)(iVar4 >> 1) * 8);
      fVar20 = *pfVar13;
      fVar23 = pfVar13[1];
      *(float *)((long)local_158 + lVar9) = fVar21 * fVar23 + (fVar19 - fVar24) * fVar20;
      *(float *)((long)local_158 + lVar9 + 4) = fVar21 * fVar20 - (fVar19 - fVar24) * fVar23;
      piVar6 = piVar6 + 1;
    }
    lVar10 = *(long *)(param_1 + 0x18);
    iVar4 = *(int *)(*(long *)(param_1 + 0x28) + lVar7 * 4);
    lVar9 = -0x30;
    pfVar13 = local_158;
    while (lVar9 + 8 != 0) {
      fVar23 = pfVar13[1];
      fVar22 = pfVar13[2] + pfVar13[4];
      fVar24 = pfVar13[3] + pfVar13[5];
      fVar19 = _ff_cos_53_float * (pfVar13[3] - pfVar13[5]);
      fVar21 = DAT_01a777a4 * (pfVar13[2] - pfVar13[4]);
      fVar20 = *pfVar13 - DAT_01a777a8 * fVar22;
      fVar25 = fVar23 - DAT_01a777a8 * fVar24;
      *(float *)((long)local_158 + lVar9 + 0xa8) = *pfVar13 + fVar22;
      *(float *)((long)local_158 + lVar9 + 0xac) = fVar24 + fVar23;
      *(float *)((long)local_158 + lVar9 + 0xd0) = fVar19 + fVar20;
      *(float *)((long)local_158 + lVar9 + 0xd4) = fVar25 - fVar21;
      *(float *)(&stack0xffffffffffffffa0 + lVar9) = fVar20 - fVar19;
      *(float *)(&stack0xffffffffffffffa4 + lVar9) = fVar21 + fVar25;
      lVar9 = lVar9 + 8;
      pfVar13 = pfVar13 + 6;
    }
    pfVar13 = (float *)(lVar10 + (long)iVar4 * 8);
    fVar23 = local_158[0x20] + local_158[0x26];
    fVar22 = local_158[0x21] + local_158[0x27];
    fVar25 = local_158[0x22] + local_158[0x24];
    *pfVar13 = fVar25 + fVar23 + local_158[0x1e];
    fVar26 = local_158[0x23] + local_158[0x25];
    pfVar13[1] = fVar26 + fVar22 + local_158[0x1f];
    fVar20 = DAT_01a777bc;
    fVar24 = DAT_01a777b8;
    fVar19 = DAT_01a777b4;
    fVar21 = DAT_01a777b0;
    fVar27 = fVar23 * DAT_01a777b0 - fVar25 * DAT_01a777b8;
    fVar29 = fVar22 * DAT_01a777b0 - fVar26 * DAT_01a777b8;
    fVar28 = (local_158[0x21] - local_158[0x27]) * DAT_01a777b4 +
             (local_158[0x23] - local_158[0x25]) * DAT_01a777bc;
    fVar30 = (local_158[0x20] - local_158[0x26]) * DAT_01a777b4 +
             (local_158[0x22] - local_158[0x24]) * DAT_01a777bc;
    pfVar13[lVar15 * 0xc] = local_158[0x1e] + fVar27 + fVar28;
    (pfVar13 + lVar15 * 0xc)[1] = local_158[0x1f] + (fVar29 - fVar30);
    fVar23 = fVar25 * fVar21 - fVar23 * fVar24;
    fVar24 = fVar26 * fVar21 - fVar22 * fVar24;
    fVar21 = (local_158[0x23] - local_158[0x25]) * fVar19 -
             (local_158[0x21] - local_158[0x27]) * fVar20;
    fVar19 = (local_158[0x22] - local_158[0x24]) * fVar19 -
             (local_158[0x20] - local_158[0x26]) * fVar20;
    pfVar13[lVar15 * 0x18] = local_158[0x1e] + (fVar23 - fVar21);
    (pfVar13 + lVar15 * 0x18)[1] = local_158[0x1f] + fVar24 + fVar19;
    pfVar13[lVar15 * 6] = local_158[0x1e] + fVar23 + fVar21;
    (pfVar13 + lVar15 * 6)[1] = local_158[0x1f] + (fVar24 - fVar19);
    pfVar13[lVar15 * 0x12] = local_158[0x1e] + (fVar27 - fVar28);
    (pfVar13 + lVar15 * 0x12)[1] = local_158[0x1f] + fVar29 + fVar30;
    fVar23 = local_158[0x2a] + local_158[0x30];
    fVar22 = local_158[0x2c] + local_158[0x2e];
    pfVar13[lVar15 * 0x14] = fVar22 + fVar23 + local_158[0x28];
    fVar25 = local_158[0x2b] + local_158[0x31];
    fVar26 = local_158[0x2d] + local_158[0x2f];
    (pfVar13 + lVar15 * 0x14)[1] = fVar26 + fVar25 + local_158[0x29];
    fVar20 = DAT_01a777bc;
    fVar24 = DAT_01a777b8;
    fVar19 = DAT_01a777b4;
    fVar21 = DAT_01a777b0;
    fVar27 = fVar23 * DAT_01a777b0 - fVar22 * DAT_01a777b8;
    fVar29 = fVar25 * DAT_01a777b0 - fVar26 * DAT_01a777b8;
    fVar28 = (local_158[0x2b] - local_158[0x31]) * DAT_01a777b4 +
             (local_158[0x2d] - local_158[0x2f]) * DAT_01a777bc;
    fVar30 = (local_158[0x2a] - local_158[0x30]) * DAT_01a777b4 +
             (local_158[0x2c] - local_158[0x2e]) * DAT_01a777bc;
    pfVar13[lVar15 * 2] = local_158[0x28] + fVar27 + fVar28;
    (pfVar13 + lVar15 * 2)[1] = local_158[0x29] + (fVar29 - fVar30);
    fVar22 = fVar22 * fVar21 - fVar23 * fVar24;
    fVar23 = fVar26 * fVar21 - fVar25 * fVar24;
    fVar24 = (local_158[0x2d] - local_158[0x2f]) * fVar19 -
             (local_158[0x2b] - local_158[0x31]) * fVar20;
    fVar21 = (local_158[0x2c] - local_158[0x2e]) * fVar19 -
             (local_158[0x2a] - local_158[0x30]) * fVar20;
    pfVar13[lVar15 * 0xe] = local_158[0x28] + (fVar22 - fVar24);
    (pfVar13 + lVar15 * 0xe)[1] = local_158[0x29] + fVar23 + fVar21;
    pfVar13[lVar15 * 0x1a] = local_158[0x28] + fVar22 + fVar24;
    (pfVar13 + lVar15 * 0x1a)[1] = local_158[0x29] + (fVar23 - fVar21);
    pfVar13[lVar15 * 8] = local_158[0x28] + (fVar27 - fVar28);
    (pfVar13 + lVar15 * 8)[1] = local_158[0x29] + fVar29 + fVar30;
    fVar21 = local_158[0x34] + local_158[0x3a];
    fVar19 = local_158[0x35] + local_158[0x3b];
    fVar24 = local_158[0x36] + local_158[0x38];
    pfVar13[lVar15 * 10] = fVar24 + fVar21 + local_158[0x32];
    fVar20 = local_158[0x37] + local_158[0x39];
    (pfVar13 + lVar15 * 10)[1] = fVar20 + fVar19 + local_158[0x33];
    fVar23 = fVar24 * DAT_01a777b0;
    fVar29 = fVar21 * DAT_01a777b8;
    fVar22 = fVar20 * DAT_01a777b0;
    fVar30 = fVar19 * DAT_01a777b8;
    fVar25 = (local_158[0x37] - local_158[0x39]) * DAT_01a777b4;
    fVar28 = (local_158[0x35] - local_158[0x3b]) * DAT_01a777bc;
    fVar26 = (local_158[0x36] - local_158[0x38]) * DAT_01a777b4;
    fVar27 = (local_158[0x34] - local_158[0x3a]) * DAT_01a777bc;
    fVar21 = fVar21 * DAT_01a777b0 - fVar24 * DAT_01a777b8;
    fVar24 = fVar19 * DAT_01a777b0 - fVar20 * DAT_01a777b8;
    fVar19 = (local_158[0x35] - local_158[0x3b]) * DAT_01a777b4 +
             (local_158[0x37] - local_158[0x39]) * DAT_01a777bc;
    fVar20 = (local_158[0x34] - local_158[0x3a]) * DAT_01a777b4 +
             (local_158[0x36] - local_158[0x38]) * DAT_01a777bc;
    pfVar13[lVar15 * 0x16] = local_158[0x32] + fVar21 + fVar19;
    (pfVar13 + lVar15 * 0x16)[1] = local_158[0x33] + (fVar24 - fVar20);
    fVar23 = fVar23 - fVar29;
    fVar22 = fVar22 - fVar30;
    fVar25 = fVar25 - fVar28;
    fVar26 = fVar26 - fVar27;
    pfVar13[lVar15 * 4] = local_158[0x32] + (fVar23 - fVar25);
    (pfVar13 + lVar15 * 4)[1] = local_158[0x33] + fVar22 + fVar26;
    pfVar13[lVar15 * 0x10] = local_158[0x32] + fVar23 + fVar25;
    (pfVar13 + lVar15 * 0x10)[1] = local_158[0x33] + (fVar22 - fVar26);
    pfVar13[lVar15 * 0x1c] = local_158[0x32] + (fVar21 - fVar19);
    (pfVar13 + lVar15 * 0x1c)[1] = local_158[0x33] + fVar24 + fVar20;
    piVar18 = piVar18 + 0xf;
  }
  uVar3 = iVar14 >> 1;
  param_4 = param_4 >> 2;
  lVar9 = 0x10;
  lVar7 = 0;
  while (lVar9 = lVar9 + -1, lVar9 != 0) {
    (*pcVar8)(*(long *)(param_1 + 0x18) + lVar7);
    lVar7 = lVar7 + lVar15 * 8;
  }
  uVar11 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3;
  lVar9 = lVar16 + -4;
  iVar12 = uVar3 * 2;
  lVar16 = lVar16 + 4;
  lVar7 = (long)(int)uVar3 + (long)(int)(uVar5 * 0xf);
  lVar10 = -4;
  iVar14 = iVar12;
  for (lVar15 = 0; iVar14 = iVar14 + -2, lVar15 < (int)uVar3; lVar15 = lVar15 + 1) {
    pfVar13 = (float *)(*(long *)(param_1 + 0x18) +
                       (long)*(int *)((long)piVar17 + lVar10 + lVar7 * 4) * 8);
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar17[lVar7 + lVar15] * 8);
    pfVar2 = (float *)(lVar16 + uVar11);
    fVar21 = *pfVar1;
    fVar19 = pfVar1[1];
    fVar24 = *pfVar13;
    fVar20 = pfVar13[1];
    *(float *)(param_2 + ((long)iVar14 * param_4 + param_4) * 4) =
         fVar21 * *pfVar2 - fVar19 * pfVar2[-1];
    pfVar13 = (float *)(lVar9 + uVar11);
    lVar9 = lVar9 + -8;
    *(float *)(param_2 + (long)iVar12 * param_4 * 4) = fVar21 * pfVar2[-1] + fVar19 * *pfVar2;
    *(float *)(param_2 + ((long)iVar12 * param_4 + param_4) * 4) =
         fVar24 * *pfVar13 - fVar20 * pfVar13[-1];
    lVar10 = lVar10 + -4;
    iVar12 = iVar12 + 2;
    *(float *)(param_2 + (long)iVar14 * param_4 * 4) = fVar24 * pfVar13[-1] + fVar20 * *pfVar13;
    lVar16 = lVar16 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


