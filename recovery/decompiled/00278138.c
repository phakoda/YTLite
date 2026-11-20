/* Decompiled from supplied 5.2.2 arm package. VA 0x278138. FUN_00278138 */

void FUN_00278138(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  long lVar13;
  long lVar14;
  undefined4 *puVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  long lVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  long lVar27;
  int local_158 [60];
  long local_68;
  
  param_4 = param_4 >> 2;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar4 = *(uint *)(param_1 + 4);
  lVar27 = (long)(int)uVar4;
  lVar24 = *(long *)(param_1 + 0x10);
  piVar5 = *(int **)(param_1 + 0x20);
  pcVar12 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar4 | 1)) * 8);
  piVar17 = piVar5;
  for (lVar9 = 0; lVar9 < lVar27; lVar9 = lVar9 + 1) {
    piVar18 = piVar17;
    for (lVar13 = 0; lVar13 != 0x78; lVar13 = lVar13 + 8) {
      iVar10 = *piVar18;
      piVar1 = (int *)(lVar24 + (long)(iVar10 >> 1) * 8);
      lVar26 = (long)*(int *)(param_3 + (long)(int)(uVar4 * 0x1e + -1) * param_4 * 4 +
                             (long)iVar10 * param_4 * -4);
      lVar14 = (long)*piVar1;
      lVar25 = (long)piVar1[1];
      lVar22 = (long)*(int *)(param_3 + (long)iVar10 * param_4 * 4);
      *(int *)((long)local_158 + lVar13) =
           (int)((ulong)((lVar14 * lVar26 + 0x40000000) - lVar25 * lVar22) >> 0x1f);
      *(int *)((long)local_158 + lVar13 + 4) =
           (int)(lVar14 * lVar22 + lVar25 * lVar26 + 0x40000000U >> 0x1f);
      piVar18 = piVar18 + 1;
    }
    lVar14 = *(long *)(param_1 + 0x18);
    iVar10 = *(int *)(*(long *)(param_1 + 0x28) + lVar9 * 4);
    lVar13 = -0x30;
    piVar18 = local_158;
    while (lVar13 + 8 != 0) {
      iVar3 = piVar18[2];
      iVar11 = piVar18[3];
      iVar7 = piVar18[4];
      iVar16 = piVar18[5];
      iVar8 = *piVar18;
      iVar19 = piVar18[1];
      iVar6 = iVar16 + iVar11;
      iVar20 = iVar7 + iVar3;
      *(int *)((long)local_158 + lVar13 + 0xa8) = iVar8 + iVar20;
      *(int *)((long)local_158 + lVar13 + 0xac) = iVar19 + iVar6;
      lVar26 = (long)(int)_ff_cos_53_int32 * (long)(iVar11 - iVar16);
      lVar23 = (_ff_cos_53_int32 >> 0x20) * (long)(iVar3 - iVar7);
      lVar22 = (long)iVar20 * (long)DAT_01af77a8 + 0x40000000;
      lVar25 = (long)iVar6 * (long)DAT_01af77a8 + 0x40000000;
      *(int *)((long)local_158 + lVar13 + 0xd0) = iVar8 - (int)((ulong)(lVar22 + lVar26) >> 0x1f);
      *(int *)((long)local_158 + lVar13 + 0xd4) = iVar19 - (int)((ulong)(lVar25 - lVar23) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa0 + lVar13) = iVar8 - (int)((ulong)(lVar22 - lVar26) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa4 + lVar13) = iVar19 - (int)((ulong)(lVar25 + lVar23) >> 0x1f)
      ;
      lVar13 = lVar13 + 8;
      piVar18 = piVar18 + 6;
    }
    piVar18 = (int *)(lVar14 + (long)iVar10 * 8);
    iVar10 = local_158[0x26] + local_158[0x20];
    iVar6 = local_158[0x27] + local_158[0x21];
    iVar20 = local_158[0x24] + local_158[0x22];
    iVar3 = local_158[0x25] + local_158[0x23];
    *piVar18 = iVar20 + iVar10 + local_158[0x1e];
    piVar18[1] = iVar3 + iVar6 + local_158[0x1f];
    lVar25 = (long)(int)DAT_01af77b0;
    lVar14 = (long)(int)DAT_01af77b8;
    lVar13 = DAT_01af77b0 >> 0x20;
    lVar26 = DAT_01af77b8 >> 0x20;
    iVar19 = (int)((ulong)((lVar13 * (local_158[0x23] - local_158[0x25]) + 0x40000000) -
                          lVar26 * (local_158[0x21] - local_158[0x27])) >> 0x1f);
    iVar16 = (int)((ulong)((lVar13 * (local_158[0x22] - local_158[0x24]) + 0x40000000) -
                          lVar26 * (local_158[0x20] - local_158[0x26])) >> 0x1f);
    iVar21 = (int)(lVar26 * (local_158[0x23] - local_158[0x25]) +
                   lVar13 * (local_158[0x21] - local_158[0x27]) + 0x40000000U >> 0x1f);
    iVar11 = (int)(lVar26 * (local_158[0x22] - local_158[0x24]) +
                   lVar13 * (local_158[0x20] - local_158[0x26]) + 0x40000000U >> 0x1f);
    iVar7 = (int)((ulong)((lVar25 * iVar20 + 0x40000000) - lVar14 * iVar10) >> 0x1f);
    iVar8 = (int)((ulong)((lVar25 * iVar3 + 0x40000000) - lVar14 * iVar6) >> 0x1f);
    iVar20 = (int)((ulong)((lVar25 * iVar10 + 0x40000000) - lVar14 * iVar20) >> 0x1f);
    iVar10 = (int)((ulong)((lVar25 * iVar6 + 0x40000000) - lVar14 * iVar3) >> 0x1f);
    piVar18[lVar27 * 0xc] = iVar21 + local_158[0x1e] + iVar20;
    (piVar18 + lVar27 * 0xc)[1] = (local_158[0x1f] - iVar11) + iVar10;
    piVar18[lVar27 * 0x18] = (local_158[0x1e] - iVar19) + iVar7;
    (piVar18 + lVar27 * 0x18)[1] = iVar16 + local_158[0x1f] + iVar8;
    piVar18[lVar27 * 6] = iVar19 + local_158[0x1e] + iVar7;
    (piVar18 + lVar27 * 6)[1] = (local_158[0x1f] - iVar16) + iVar8;
    piVar18[lVar27 * 0x12] = (iVar20 - iVar21) + local_158[0x1e];
    (piVar18 + lVar27 * 0x12)[1] = iVar10 + iVar11 + local_158[0x1f];
    iVar10 = local_158[0x30] + local_158[0x2a];
    iVar6 = local_158[0x31] + local_158[0x2b];
    iVar20 = local_158[0x2e] + local_158[0x2c];
    iVar3 = local_158[0x2f] + local_158[0x2d];
    piVar18[lVar27 * 0x14] = iVar20 + iVar10 + local_158[0x28];
    (piVar18 + lVar27 * 0x14)[1] = iVar3 + iVar6 + local_158[0x29];
    lVar25 = (long)(int)DAT_01af77b0;
    lVar26 = (long)(int)DAT_01af77b8;
    lVar13 = DAT_01af77b0 >> 0x20;
    lVar14 = DAT_01af77b8 >> 0x20;
    iVar8 = (int)((ulong)((lVar13 * (local_158[0x2d] - local_158[0x2f]) + 0x40000000) -
                         lVar14 * (local_158[0x2b] - local_158[0x31])) >> 0x1f);
    iVar7 = (int)((ulong)((lVar13 * (local_158[0x2c] - local_158[0x2e]) + 0x40000000) -
                         lVar14 * (local_158[0x2a] - local_158[0x30])) >> 0x1f);
    iVar16 = (int)(lVar14 * (local_158[0x2d] - local_158[0x2f]) +
                   lVar13 * (local_158[0x2b] - local_158[0x31]) + 0x40000000U >> 0x1f);
    iVar19 = (int)(lVar14 * (local_158[0x2c] - local_158[0x2e]) +
                   lVar13 * (local_158[0x2a] - local_158[0x30]) + 0x40000000U >> 0x1f);
    iVar11 = (int)((ulong)((lVar25 * iVar20 + 0x40000000) - lVar26 * iVar10) >> 0x1f);
    iVar21 = (int)((ulong)((lVar25 * iVar3 + 0x40000000) - lVar26 * iVar6) >> 0x1f);
    iVar10 = (int)((ulong)((lVar25 * iVar10 + 0x40000000) - lVar26 * iVar20) >> 0x1f);
    iVar6 = (int)((ulong)((lVar25 * iVar6 + 0x40000000) - lVar26 * iVar3) >> 0x1f);
    piVar18[lVar27 * 2] = iVar16 + local_158[0x28] + iVar10;
    (piVar18 + lVar27 * 2)[1] = (local_158[0x29] - iVar19) + iVar6;
    piVar18[lVar27 * 0xe] = (local_158[0x28] - iVar8) + iVar11;
    (piVar18 + lVar27 * 0xe)[1] = iVar7 + local_158[0x29] + iVar21;
    piVar18[lVar27 * 0x1a] = iVar8 + local_158[0x28] + iVar11;
    (piVar18 + lVar27 * 0x1a)[1] = (local_158[0x29] - iVar7) + iVar21;
    piVar18[lVar27 * 8] = (iVar10 - iVar16) + local_158[0x28];
    (piVar18 + lVar27 * 8)[1] = iVar6 + iVar19 + local_158[0x29];
    iVar10 = local_158[0x3a] + local_158[0x34];
    iVar6 = local_158[0x3b] + local_158[0x35];
    iVar20 = local_158[0x38] + local_158[0x36];
    iVar3 = local_158[0x39] + local_158[0x37];
    piVar18[lVar27 * 10] = iVar20 + iVar10 + local_158[0x32];
    (piVar18 + lVar27 * 10)[1] = iVar3 + iVar6 + local_158[0x33];
    lVar25 = (long)(int)DAT_01af77b0;
    lVar26 = (long)(int)DAT_01af77b8;
    lVar13 = DAT_01af77b0 >> 0x20;
    lVar14 = DAT_01af77b8 >> 0x20;
    iVar8 = (int)(lVar14 * (local_158[0x37] - local_158[0x39]) +
                  lVar13 * (local_158[0x35] - local_158[0x3b]) + 0x40000000U >> 0x1f);
    iVar11 = (int)((ulong)((lVar25 * iVar10 + 0x40000000) - lVar26 * iVar20) >> 0x1f);
    piVar18[lVar27 * 0x16] = iVar8 + local_158[0x32] + iVar11;
    iVar7 = (int)(lVar14 * (local_158[0x36] - local_158[0x38]) +
                  lVar13 * (local_158[0x34] - local_158[0x3a]) + 0x40000000U >> 0x1f);
    iVar16 = (int)((ulong)((lVar25 * iVar6 + 0x40000000) - lVar26 * iVar3) >> 0x1f);
    (piVar18 + lVar27 * 0x16)[1] = (local_158[0x33] - iVar7) + iVar16;
    iVar19 = (int)((ulong)((lVar13 * (local_158[0x37] - local_158[0x39]) + 0x40000000) -
                          lVar14 * (local_158[0x35] - local_158[0x3b])) >> 0x1f);
    iVar10 = (int)((ulong)((lVar25 * iVar20 + 0x40000000) - lVar26 * iVar10) >> 0x1f);
    piVar18[lVar27 * 4] = (local_158[0x32] - iVar19) + iVar10;
    iVar20 = (int)((ulong)((lVar13 * (local_158[0x36] - local_158[0x38]) + 0x40000000) -
                          lVar14 * (local_158[0x34] - local_158[0x3a])) >> 0x1f);
    iVar6 = (int)((ulong)((lVar25 * iVar3 + 0x40000000) - lVar26 * iVar6) >> 0x1f);
    (piVar18 + lVar27 * 4)[1] = iVar20 + local_158[0x33] + iVar6;
    piVar18[lVar27 * 0x10] = iVar19 + local_158[0x32] + iVar10;
    (piVar18 + lVar27 * 0x10)[1] = (local_158[0x33] - iVar20) + iVar6;
    piVar18[lVar27 * 0x1c] = (iVar11 - iVar8) + local_158[0x32];
    (piVar18 + lVar27 * 0x1c)[1] = iVar16 + iVar7 + local_158[0x33];
    piVar17 = piVar17 + 0xf;
  }
  iVar10 = (int)(uVar4 * 0xf) >> 1;
  lVar13 = 0x10;
  lVar9 = 0;
  while (lVar13 = lVar13 + -1, lVar13 != 0) {
    (*pcVar12)(*(long *)(param_1 + 0x18) + lVar9);
    lVar9 = lVar9 + lVar27 * 8;
  }
  lVar13 = (long)iVar10;
  puVar15 = (undefined4 *)(param_2 + (long)iVar10 * 8 + 4);
  piVar17 = (int *)(lVar24 + (long)iVar10 * 8 + 4);
  for (lVar9 = 0; iVar10 = iVar10 + -1, lVar9 < lVar13; lVar9 = lVar9 + 1) {
    piVar18 = (int *)(lVar24 + (long)iVar10 * 8);
    iVar6 = piVar18[1];
    piVar1 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar5[lVar27 * 0xf + (long)iVar10] * 8);
    lVar14 = (long)*piVar1;
    lVar26 = (long)piVar1[1];
    puVar2 = (undefined4 *)(param_2 + (long)iVar10 * 8);
    piVar1 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)piVar5[lVar13 + (int)(uVar4 * 0xf) + lVar9] * 8);
    lVar25 = (long)*piVar1;
    lVar22 = (long)piVar1[1];
    *puVar2 = (int)((ulong)((iVar6 * lVar26 + 0x40000000) - *piVar18 * lVar14) >> 0x1f);
    *puVar15 = (int)(iVar6 * lVar14 + *piVar18 * lVar26 + 0x40000000U >> 0x1f);
    iVar6 = *piVar17;
    puVar15[-1] = (int)((ulong)((iVar6 * lVar22 + 0x40000000) - piVar17[-1] * lVar25) >> 0x1f);
    puVar15 = puVar15 + 2;
    puVar2[1] = (int)(iVar6 * lVar25 + piVar17[-1] * lVar22 + 0x40000000U >> 0x1f);
    piVar17 = piVar17 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


