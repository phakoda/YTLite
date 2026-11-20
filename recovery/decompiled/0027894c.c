/* Decompiled from supplied 5.2.2 arm package. VA 0x27894c. FUN_0027894c */

void FUN_0027894c(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  code *pcVar16;
  long lVar17;
  ulong uVar18;
  int iVar19;
  long lVar20;
  long lVar21;
  int *piVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  long lVar27;
  long lVar28;
  long lVar29;
  int local_158 [60];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar4 = *(uint *)(param_1 + 4);
  lVar27 = (long)(int)uVar4;
  lVar28 = *(long *)(param_1 + 0x10);
  piVar13 = *(int **)(param_1 + 0x20);
  iVar25 = uVar4 * 0xf;
  iVar19 = uVar4 * 0x2d + -1;
  pcVar16 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar4 | 1)) * 8);
  piVar14 = piVar13;
  for (lVar10 = 0; lVar10 < lVar27; lVar10 = lVar10 + 1) {
    piVar22 = piVar14;
    for (lVar20 = 0; lVar20 != 0x78; lVar20 = lVar20 + 8) {
      iVar5 = *piVar22;
      iVar7 = *(int *)(param_3 + (long)(iVar5 + iVar25) * 4);
      if (iVar5 < iVar25) {
        iVar7 = (0x20 - iVar7) + *(int *)(param_3 + (long)((iVar25 + -1) - iVar5) * 4);
        iVar24 = (0x20 - *(int *)(param_3 + (long)(int)(iVar5 + uVar4 * 0x2d) * 4)) -
                 *(int *)(param_3 + (long)(iVar19 - iVar5) * 4);
      }
      else {
        iVar7 = (0x20 - iVar7) - *(int *)(param_3 + (long)(int)((uVar4 * 0x4b + -1) - iVar5) * 4);
        iVar24 = (*(int *)(param_3 + (long)(int)(iVar5 + uVar4 * -0xf) * 4) + 0x20) -
                 *(int *)(param_3 + (long)(iVar19 - iVar5) * 4);
      }
      piVar1 = (int *)(lVar28 + (long)(iVar5 >> 1) * 8);
      lVar21 = (long)*piVar1;
      lVar17 = (long)piVar1[1];
      *(int *)((long)local_158 + lVar20 + 4) =
           (int)((ulong)((lVar21 * (iVar7 >> 6) + 0x40000000) - lVar17 * (iVar24 >> 6)) >> 0x1f);
      *(int *)((long)local_158 + lVar20) =
           (int)(lVar21 * (iVar24 >> 6) + lVar17 * (iVar7 >> 6) + 0x40000000U >> 0x1f);
      piVar22 = piVar22 + 1;
    }
    lVar21 = *(long *)(param_1 + 0x18);
    iVar5 = *(int *)(*(long *)(param_1 + 0x28) + lVar10 * 4);
    lVar20 = -0x30;
    piVar22 = local_158;
    while (lVar20 + 8 != 0) {
      iVar2 = piVar22[2];
      iVar12 = piVar22[3];
      iVar6 = piVar22[4];
      iVar15 = piVar22[5];
      iVar8 = *piVar22;
      iVar23 = piVar22[1];
      iVar7 = iVar15 + iVar12;
      iVar24 = iVar6 + iVar2;
      *(int *)((long)local_158 + lVar20 + 0xa8) = iVar8 + iVar24;
      *(int *)((long)local_158 + lVar20 + 0xac) = iVar23 + iVar7;
      lVar9 = (long)(int)_ff_cos_53_int32 * (long)(iVar12 - iVar15);
      lVar11 = (_ff_cos_53_int32 >> 0x20) * (long)(iVar2 - iVar6);
      lVar17 = (long)iVar24 * (long)DAT_01af77a8 + 0x40000000;
      lVar29 = (long)iVar7 * (long)DAT_01af77a8 + 0x40000000;
      *(int *)((long)local_158 + lVar20 + 0xd0) = iVar8 - (int)((ulong)(lVar17 + lVar9) >> 0x1f);
      *(int *)((long)local_158 + lVar20 + 0xd4) = iVar23 - (int)((ulong)(lVar29 - lVar11) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa0 + lVar20) = iVar8 - (int)((ulong)(lVar17 - lVar9) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa4 + lVar20) = iVar23 - (int)((ulong)(lVar29 + lVar11) >> 0x1f)
      ;
      lVar20 = lVar20 + 8;
      piVar22 = piVar22 + 6;
    }
    piVar22 = (int *)(lVar21 + (long)iVar5 * 8);
    iVar5 = local_158[0x26] + local_158[0x20];
    iVar7 = local_158[0x27] + local_158[0x21];
    iVar24 = local_158[0x24] + local_158[0x22];
    iVar2 = local_158[0x25] + local_158[0x23];
    *piVar22 = iVar24 + iVar5 + local_158[0x1e];
    piVar22[1] = iVar2 + iVar7 + local_158[0x1f];
    lVar17 = (long)(int)DAT_01af77b0;
    lVar29 = (long)(int)DAT_01af77b8;
    lVar20 = DAT_01af77b0 >> 0x20;
    lVar21 = DAT_01af77b8 >> 0x20;
    iVar15 = (int)((ulong)((lVar20 * (local_158[0x23] - local_158[0x25]) + 0x40000000) -
                          lVar21 * (local_158[0x21] - local_158[0x27])) >> 0x1f);
    iVar12 = (int)((ulong)((lVar20 * (local_158[0x22] - local_158[0x24]) + 0x40000000) -
                          lVar21 * (local_158[0x20] - local_158[0x26])) >> 0x1f);
    iVar8 = (int)(lVar21 * (local_158[0x23] - local_158[0x25]) +
                  lVar20 * (local_158[0x21] - local_158[0x27]) + 0x40000000U >> 0x1f);
    iVar26 = (int)(lVar21 * (local_158[0x22] - local_158[0x24]) +
                   lVar20 * (local_158[0x20] - local_158[0x26]) + 0x40000000U >> 0x1f);
    iVar23 = (int)((ulong)((lVar17 * iVar24 + 0x40000000) - lVar29 * iVar5) >> 0x1f);
    iVar6 = (int)((ulong)((lVar17 * iVar2 + 0x40000000) - lVar29 * iVar7) >> 0x1f);
    iVar24 = (int)((ulong)((lVar17 * iVar5 + 0x40000000) - lVar29 * iVar24) >> 0x1f);
    iVar5 = (int)((ulong)((lVar17 * iVar7 + 0x40000000) - lVar29 * iVar2) >> 0x1f);
    piVar22[lVar27 * 0xc] = iVar8 + local_158[0x1e] + iVar24;
    (piVar22 + lVar27 * 0xc)[1] = (local_158[0x1f] - iVar26) + iVar5;
    piVar22[lVar27 * 0x18] = (local_158[0x1e] - iVar15) + iVar23;
    (piVar22 + lVar27 * 0x18)[1] = iVar12 + local_158[0x1f] + iVar6;
    piVar22[lVar27 * 6] = iVar15 + local_158[0x1e] + iVar23;
    (piVar22 + lVar27 * 6)[1] = (local_158[0x1f] - iVar12) + iVar6;
    piVar22[lVar27 * 0x12] = (iVar24 - iVar8) + local_158[0x1e];
    (piVar22 + lVar27 * 0x12)[1] = iVar5 + iVar26 + local_158[0x1f];
    iVar5 = local_158[0x30] + local_158[0x2a];
    iVar7 = local_158[0x31] + local_158[0x2b];
    iVar24 = local_158[0x2e] + local_158[0x2c];
    iVar2 = local_158[0x2f] + local_158[0x2d];
    piVar22[lVar27 * 0x14] = iVar24 + iVar5 + local_158[0x28];
    (piVar22 + lVar27 * 0x14)[1] = iVar2 + iVar7 + local_158[0x29];
    lVar17 = (long)(int)DAT_01af77b0;
    lVar29 = (long)(int)DAT_01af77b8;
    lVar20 = DAT_01af77b0 >> 0x20;
    lVar21 = DAT_01af77b8 >> 0x20;
    iVar8 = (int)((ulong)((lVar20 * (local_158[0x2d] - local_158[0x2f]) + 0x40000000) -
                         lVar21 * (local_158[0x2b] - local_158[0x31])) >> 0x1f);
    iVar6 = (int)((ulong)((lVar20 * (local_158[0x2c] - local_158[0x2e]) + 0x40000000) -
                         lVar21 * (local_158[0x2a] - local_158[0x30])) >> 0x1f);
    iVar23 = (int)(lVar21 * (local_158[0x2d] - local_158[0x2f]) +
                   lVar20 * (local_158[0x2b] - local_158[0x31]) + 0x40000000U >> 0x1f);
    iVar15 = (int)(lVar21 * (local_158[0x2c] - local_158[0x2e]) +
                   lVar20 * (local_158[0x2a] - local_158[0x30]) + 0x40000000U >> 0x1f);
    iVar12 = (int)((ulong)((lVar17 * iVar24 + 0x40000000) - lVar29 * iVar5) >> 0x1f);
    iVar26 = (int)((ulong)((lVar17 * iVar2 + 0x40000000) - lVar29 * iVar7) >> 0x1f);
    iVar5 = (int)((ulong)((lVar17 * iVar5 + 0x40000000) - lVar29 * iVar24) >> 0x1f);
    iVar7 = (int)((ulong)((lVar17 * iVar7 + 0x40000000) - lVar29 * iVar2) >> 0x1f);
    piVar22[lVar27 * 2] = iVar23 + local_158[0x28] + iVar5;
    (piVar22 + lVar27 * 2)[1] = (local_158[0x29] - iVar15) + iVar7;
    piVar22[lVar27 * 0xe] = (local_158[0x28] - iVar8) + iVar12;
    (piVar22 + lVar27 * 0xe)[1] = iVar6 + local_158[0x29] + iVar26;
    piVar22[lVar27 * 0x1a] = iVar8 + local_158[0x28] + iVar12;
    (piVar22 + lVar27 * 0x1a)[1] = (local_158[0x29] - iVar6) + iVar26;
    piVar22[lVar27 * 8] = (iVar5 - iVar23) + local_158[0x28];
    (piVar22 + lVar27 * 8)[1] = iVar7 + iVar15 + local_158[0x29];
    iVar5 = local_158[0x3a] + local_158[0x34];
    iVar7 = local_158[0x3b] + local_158[0x35];
    iVar24 = local_158[0x38] + local_158[0x36];
    iVar2 = local_158[0x39] + local_158[0x37];
    piVar22[lVar27 * 10] = iVar24 + iVar5 + local_158[0x32];
    (piVar22 + lVar27 * 10)[1] = iVar2 + iVar7 + local_158[0x33];
    lVar17 = (long)(int)DAT_01af77b0;
    lVar29 = (long)(int)DAT_01af77b8;
    lVar20 = DAT_01af77b0 >> 0x20;
    lVar21 = DAT_01af77b8 >> 0x20;
    iVar8 = (int)(lVar21 * (local_158[0x37] - local_158[0x39]) +
                  lVar20 * (local_158[0x35] - local_158[0x3b]) + 0x40000000U >> 0x1f);
    iVar12 = (int)((ulong)((lVar17 * iVar5 + 0x40000000) - lVar29 * iVar24) >> 0x1f);
    piVar22[lVar27 * 0x16] = iVar8 + local_158[0x32] + iVar12;
    iVar6 = (int)(lVar21 * (local_158[0x36] - local_158[0x38]) +
                  lVar20 * (local_158[0x34] - local_158[0x3a]) + 0x40000000U >> 0x1f);
    iVar15 = (int)((ulong)((lVar17 * iVar7 + 0x40000000) - lVar29 * iVar2) >> 0x1f);
    (piVar22 + lVar27 * 0x16)[1] = (local_158[0x33] - iVar6) + iVar15;
    iVar23 = (int)((ulong)((lVar20 * (local_158[0x37] - local_158[0x39]) + 0x40000000) -
                          lVar21 * (local_158[0x35] - local_158[0x3b])) >> 0x1f);
    iVar5 = (int)((ulong)((lVar17 * iVar24 + 0x40000000) - lVar29 * iVar5) >> 0x1f);
    piVar22[lVar27 * 4] = (local_158[0x32] - iVar23) + iVar5;
    iVar24 = (int)((ulong)((lVar20 * (local_158[0x36] - local_158[0x38]) + 0x40000000) -
                          lVar21 * (local_158[0x34] - local_158[0x3a])) >> 0x1f);
    iVar7 = (int)((ulong)((lVar17 * iVar2 + 0x40000000) - lVar29 * iVar7) >> 0x1f);
    (piVar22 + lVar27 * 4)[1] = iVar24 + local_158[0x33] + iVar7;
    piVar22[lVar27 * 0x10] = iVar23 + local_158[0x32] + iVar5;
    (piVar22 + lVar27 * 0x10)[1] = (local_158[0x33] - iVar24) + iVar7;
    piVar22[lVar27 * 0x1c] = (iVar12 - iVar8) + local_158[0x32];
    (piVar22 + lVar27 * 0x1c)[1] = iVar15 + iVar6 + local_158[0x33];
    piVar14 = piVar14 + 0xf;
  }
  uVar3 = iVar25 >> 1;
  param_4 = param_4 >> 2;
  lVar20 = 0x10;
  lVar10 = 0;
  while (lVar20 = lVar20 + -1, lVar20 != 0) {
    (*pcVar16)(*(long *)(param_1 + 0x18) + lVar10);
    lVar10 = lVar10 + lVar27 * 8;
  }
  uVar18 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3;
  lVar20 = lVar28 + -4;
  iVar19 = uVar3 * 2;
  lVar28 = lVar28 + 4;
  lVar21 = -4;
  lVar10 = (long)(int)uVar3 + (long)(int)(uVar4 * 0xf);
  iVar25 = iVar19;
  for (lVar27 = 0; iVar25 = iVar25 + -2, lVar27 < (int)uVar3; lVar27 = lVar27 + 1) {
    piVar14 = (int *)(lVar28 + uVar18);
    piVar22 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar13[lVar10 + lVar27] * 8);
    lVar17 = (long)*piVar22;
    lVar9 = (long)piVar22[1];
    piVar22 = (int *)(*(long *)(param_1 + 0x18) +
                     (long)*(int *)((long)piVar13 + lVar21 + lVar10 * 4) * 8);
    lVar29 = (long)*piVar22;
    lVar11 = (long)piVar22[1];
    *(int *)(param_2 + ((long)iVar25 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar14 * lVar17 + 0x40000000) - piVar14[-1] * lVar9) >> 0x1f);
    piVar22 = (int *)(lVar20 + uVar18);
    lVar20 = lVar20 + -8;
    *(int *)(param_2 + (long)iVar19 * param_4 * 4) =
         (int)(*piVar14 * lVar9 + piVar14[-1] * lVar17 + 0x40000000U >> 0x1f);
    *(int *)(param_2 + ((long)iVar19 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar22 * lVar29 + 0x40000000) - piVar22[-1] * lVar11) >> 0x1f);
    lVar21 = lVar21 + -4;
    iVar19 = iVar19 + 2;
    *(int *)(param_2 + (long)iVar25 * param_4 * 4) =
         (int)(*piVar22 * lVar11 + piVar22[-1] * lVar29 + 0x40000000U >> 0x1f);
    lVar28 = lVar28 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


