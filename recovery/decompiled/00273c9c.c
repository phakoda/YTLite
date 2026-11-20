/* Decompiled from supplied 5.2.2 arm package. VA 0x273c9c. FUN_00273c9c */

void FUN_00273c9c(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int *piVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  int *piVar14;
  int *piVar15;
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
  float fVar27;
  float local_158 [60];
  long local_68;
  
  param_4 = param_4 >> 2;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = *(uint *)(param_1 + 4);
  lVar13 = (long)(int)uVar3;
  lVar12 = *(long *)(param_1 + 0x10);
  piVar14 = *(int **)(param_1 + 0x20);
  pcVar4 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar15 = piVar14;
  for (lVar6 = 0; lVar6 < lVar13; lVar6 = lVar6 + 1) {
    piVar10 = piVar15;
    for (lVar5 = 0; lVar5 != 0x78; lVar5 = lVar5 + 8) {
      iVar7 = *piVar10;
      fVar17 = *(float *)(param_3 + (long)(int)(uVar3 * 0x1e + -1) * param_4 * 4 +
                         (long)iVar7 * param_4 * -4);
      fVar21 = *(float *)(param_3 + (long)iVar7 * param_4 * 4);
      pfVar8 = (float *)(lVar12 + (long)(iVar7 >> 1) * 8);
      fVar19 = *pfVar8;
      fVar22 = pfVar8[1];
      *(float *)((long)local_158 + lVar5) = fVar17 * fVar19 - fVar21 * fVar22;
      *(float *)((long)local_158 + lVar5 + 4) = fVar17 * fVar22 + fVar21 * fVar19;
      piVar10 = piVar10 + 1;
    }
    lVar11 = *(long *)(param_1 + 0x18);
    iVar7 = *(int *)(*(long *)(param_1 + 0x28) + lVar6 * 4);
    lVar5 = -0x30;
    pfVar8 = local_158;
    while (lVar5 + 8 != 0) {
      fVar16 = pfVar8[1];
      fVar18 = pfVar8[2] + pfVar8[4];
      fVar19 = pfVar8[3] + pfVar8[5];
      fVar21 = _ff_cos_53_float * (pfVar8[3] - pfVar8[5]);
      fVar17 = DAT_01a777a4 * (pfVar8[2] - pfVar8[4]);
      fVar22 = *pfVar8 - DAT_01a777a8 * fVar18;
      fVar20 = fVar16 - DAT_01a777a8 * fVar19;
      *(float *)((long)local_158 + lVar5 + 0xa8) = *pfVar8 + fVar18;
      *(float *)((long)local_158 + lVar5 + 0xac) = fVar19 + fVar16;
      *(float *)((long)local_158 + lVar5 + 0xd0) = fVar21 + fVar22;
      *(float *)((long)local_158 + lVar5 + 0xd4) = fVar20 - fVar17;
      *(float *)(&stack0xffffffffffffffa0 + lVar5) = fVar22 - fVar21;
      *(float *)(&stack0xffffffffffffffa4 + lVar5) = fVar17 + fVar20;
      lVar5 = lVar5 + 8;
      pfVar8 = pfVar8 + 6;
    }
    pfVar8 = (float *)(lVar11 + (long)iVar7 * 8);
    fVar16 = local_158[0x20] + local_158[0x26];
    fVar18 = local_158[0x21] + local_158[0x27];
    fVar20 = local_158[0x22] + local_158[0x24];
    *pfVar8 = fVar20 + fVar16 + local_158[0x1e];
    fVar23 = local_158[0x23] + local_158[0x25];
    pfVar8[1] = fVar23 + fVar18 + local_158[0x1f];
    fVar22 = DAT_01a777bc;
    fVar19 = DAT_01a777b8;
    fVar21 = DAT_01a777b4;
    fVar17 = DAT_01a777b0;
    fVar24 = fVar16 * DAT_01a777b0 - fVar20 * DAT_01a777b8;
    fVar26 = fVar18 * DAT_01a777b0 - fVar23 * DAT_01a777b8;
    fVar25 = (local_158[0x21] - local_158[0x27]) * DAT_01a777b4 +
             (local_158[0x23] - local_158[0x25]) * DAT_01a777bc;
    fVar27 = (local_158[0x20] - local_158[0x26]) * DAT_01a777b4 +
             (local_158[0x22] - local_158[0x24]) * DAT_01a777bc;
    pfVar8[lVar13 * 0xc] = local_158[0x1e] + fVar24 + fVar25;
    (pfVar8 + lVar13 * 0xc)[1] = local_158[0x1f] + (fVar26 - fVar27);
    fVar16 = fVar20 * fVar17 - fVar16 * fVar19;
    fVar19 = fVar23 * fVar17 - fVar18 * fVar19;
    fVar17 = (local_158[0x23] - local_158[0x25]) * fVar21 -
             (local_158[0x21] - local_158[0x27]) * fVar22;
    fVar21 = (local_158[0x22] - local_158[0x24]) * fVar21 -
             (local_158[0x20] - local_158[0x26]) * fVar22;
    pfVar8[lVar13 * 0x18] = local_158[0x1e] + (fVar16 - fVar17);
    (pfVar8 + lVar13 * 0x18)[1] = local_158[0x1f] + fVar19 + fVar21;
    pfVar8[lVar13 * 6] = local_158[0x1e] + fVar16 + fVar17;
    (pfVar8 + lVar13 * 6)[1] = local_158[0x1f] + (fVar19 - fVar21);
    pfVar8[lVar13 * 0x12] = local_158[0x1e] + (fVar24 - fVar25);
    (pfVar8 + lVar13 * 0x12)[1] = local_158[0x1f] + fVar26 + fVar27;
    fVar16 = local_158[0x2a] + local_158[0x30];
    fVar18 = local_158[0x2c] + local_158[0x2e];
    pfVar8[lVar13 * 0x14] = fVar18 + fVar16 + local_158[0x28];
    fVar20 = local_158[0x2b] + local_158[0x31];
    fVar23 = local_158[0x2d] + local_158[0x2f];
    (pfVar8 + lVar13 * 0x14)[1] = fVar23 + fVar20 + local_158[0x29];
    fVar22 = DAT_01a777bc;
    fVar19 = DAT_01a777b8;
    fVar21 = DAT_01a777b4;
    fVar17 = DAT_01a777b0;
    fVar24 = fVar16 * DAT_01a777b0 - fVar18 * DAT_01a777b8;
    fVar26 = fVar20 * DAT_01a777b0 - fVar23 * DAT_01a777b8;
    fVar25 = (local_158[0x2b] - local_158[0x31]) * DAT_01a777b4 +
             (local_158[0x2d] - local_158[0x2f]) * DAT_01a777bc;
    fVar27 = (local_158[0x2a] - local_158[0x30]) * DAT_01a777b4 +
             (local_158[0x2c] - local_158[0x2e]) * DAT_01a777bc;
    pfVar8[lVar13 * 2] = local_158[0x28] + fVar24 + fVar25;
    (pfVar8 + lVar13 * 2)[1] = local_158[0x29] + (fVar26 - fVar27);
    fVar18 = fVar18 * fVar17 - fVar16 * fVar19;
    fVar16 = fVar23 * fVar17 - fVar20 * fVar19;
    fVar19 = (local_158[0x2d] - local_158[0x2f]) * fVar21 -
             (local_158[0x2b] - local_158[0x31]) * fVar22;
    fVar17 = (local_158[0x2c] - local_158[0x2e]) * fVar21 -
             (local_158[0x2a] - local_158[0x30]) * fVar22;
    pfVar8[lVar13 * 0xe] = local_158[0x28] + (fVar18 - fVar19);
    (pfVar8 + lVar13 * 0xe)[1] = local_158[0x29] + fVar16 + fVar17;
    pfVar8[lVar13 * 0x1a] = local_158[0x28] + fVar18 + fVar19;
    (pfVar8 + lVar13 * 0x1a)[1] = local_158[0x29] + (fVar16 - fVar17);
    pfVar8[lVar13 * 8] = local_158[0x28] + (fVar24 - fVar25);
    (pfVar8 + lVar13 * 8)[1] = local_158[0x29] + fVar26 + fVar27;
    fVar17 = local_158[0x34] + local_158[0x3a];
    fVar21 = local_158[0x35] + local_158[0x3b];
    fVar19 = local_158[0x36] + local_158[0x38];
    pfVar8[lVar13 * 10] = fVar19 + fVar17 + local_158[0x32];
    fVar22 = local_158[0x37] + local_158[0x39];
    (pfVar8 + lVar13 * 10)[1] = fVar22 + fVar21 + local_158[0x33];
    fVar16 = fVar19 * DAT_01a777b0;
    fVar26 = fVar17 * DAT_01a777b8;
    fVar18 = fVar22 * DAT_01a777b0;
    fVar27 = fVar21 * DAT_01a777b8;
    fVar20 = (local_158[0x37] - local_158[0x39]) * DAT_01a777b4;
    fVar25 = (local_158[0x35] - local_158[0x3b]) * DAT_01a777bc;
    fVar23 = (local_158[0x36] - local_158[0x38]) * DAT_01a777b4;
    fVar24 = (local_158[0x34] - local_158[0x3a]) * DAT_01a777bc;
    fVar17 = fVar17 * DAT_01a777b0 - fVar19 * DAT_01a777b8;
    fVar19 = fVar21 * DAT_01a777b0 - fVar22 * DAT_01a777b8;
    fVar21 = (local_158[0x35] - local_158[0x3b]) * DAT_01a777b4 +
             (local_158[0x37] - local_158[0x39]) * DAT_01a777bc;
    fVar22 = (local_158[0x34] - local_158[0x3a]) * DAT_01a777b4 +
             (local_158[0x36] - local_158[0x38]) * DAT_01a777bc;
    pfVar8[lVar13 * 0x16] = local_158[0x32] + fVar17 + fVar21;
    (pfVar8 + lVar13 * 0x16)[1] = local_158[0x33] + (fVar19 - fVar22);
    fVar16 = fVar16 - fVar26;
    fVar18 = fVar18 - fVar27;
    fVar20 = fVar20 - fVar25;
    fVar23 = fVar23 - fVar24;
    pfVar8[lVar13 * 4] = local_158[0x32] + (fVar16 - fVar20);
    (pfVar8 + lVar13 * 4)[1] = local_158[0x33] + fVar18 + fVar23;
    pfVar8[lVar13 * 0x10] = local_158[0x32] + fVar16 + fVar20;
    (pfVar8 + lVar13 * 0x10)[1] = local_158[0x33] + (fVar18 - fVar23);
    pfVar8[lVar13 * 0x1c] = local_158[0x32] + (fVar17 - fVar21);
    (pfVar8 + lVar13 * 0x1c)[1] = local_158[0x33] + fVar19 + fVar22;
    piVar15 = piVar15 + 0xf;
  }
  iVar7 = (int)(uVar3 * 0xf) >> 1;
  lVar5 = 0x10;
  lVar6 = 0;
  while (lVar5 = lVar5 + -1, lVar5 != 0) {
    (*pcVar4)(*(long *)(param_1 + 0x18) + lVar6);
    lVar6 = lVar6 + lVar13 * 8;
  }
  lVar5 = (long)iVar7;
  pfVar8 = (float *)(param_2 + (long)iVar7 * 8 + 4);
  pfVar9 = (float *)(lVar12 + (long)iVar7 * 8 + 4);
  for (lVar6 = 0; iVar7 = iVar7 + -1, lVar6 < lVar5; lVar6 = lVar6 + 1) {
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) + (long)piVar14[lVar13 * 0xf + (long)iVar7] * 8);
    pfVar2 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)piVar14[lVar5 + (int)(uVar3 * 0xf) + lVar6] * 8);
    fVar17 = *pfVar1;
    fVar21 = pfVar1[1];
    pfVar1 = (float *)(lVar12 + (long)iVar7 * 8);
    fVar19 = pfVar1[1];
    fVar22 = *pfVar2;
    fVar16 = pfVar2[1];
    pfVar2 = (float *)(param_2 + (long)iVar7 * 8);
    *pfVar2 = fVar21 * fVar19 - fVar17 * *pfVar1;
    *pfVar8 = fVar21 * *pfVar1 + fVar17 * fVar19;
    fVar17 = *pfVar9;
    pfVar8[-1] = fVar16 * fVar17 - fVar22 * pfVar9[-1];
    pfVar8 = pfVar8 + 2;
    pfVar2[1] = fVar16 * pfVar9[-1] + fVar22 * fVar17;
    pfVar9 = pfVar9 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


