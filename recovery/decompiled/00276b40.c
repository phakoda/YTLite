/* Decompiled from supplied 5.2.2 arm package. VA 0x276b40. FUN_00276b40 */

void FUN_00276b40(long param_1,long param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  int *piVar22;
  int *piVar23;
  int local_158 [30];
  int local_e0 [30];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar2 = *(uint *)(param_1 + 4);
  lVar19 = (long)(int)uVar2;
  piVar22 = *(int **)(param_1 + 0x20);
  pcVar8 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar2 | 1)) * 8);
  piVar23 = piVar22;
  for (lVar5 = 0; lVar5 < lVar19; lVar5 = lVar5 + 1) {
    piVar12 = piVar23;
    for (lVar9 = 0; lVar9 != 0x78; lVar9 = lVar9 + 8) {
      *(undefined8 *)((long)local_158 + lVar9) = *(undefined8 *)(param_3 + (long)*piVar12 * 8);
      piVar12 = piVar12 + 1;
    }
    lVar10 = *(long *)(param_1 + 0x18);
    iVar6 = *(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4);
    lVar9 = -0x30;
    piVar12 = local_158;
    while (lVar9 + 8 != 0) {
      iVar1 = piVar12[2];
      iVar7 = piVar12[3];
      iVar3 = piVar12[4];
      iVar11 = piVar12[5];
      iVar4 = *piVar12;
      iVar13 = piVar12[1];
      iVar16 = iVar11 + iVar7;
      iVar14 = iVar3 + iVar1;
      *(int *)((long)local_e0 + lVar9 + 0x30) = iVar4 + iVar14;
      *(int *)((long)local_e0 + lVar9 + 0x34) = iVar13 + iVar16;
      lVar17 = (long)(int)_ff_cos_53_int32 * (long)(iVar7 - iVar11);
      lVar21 = (_ff_cos_53_int32 >> 0x20) * (long)(iVar1 - iVar3);
      lVar18 = (long)iVar14 * (long)DAT_01af77a8 + 0x40000000;
      lVar20 = (long)iVar16 * (long)DAT_01af77a8 + 0x40000000;
      *(int *)((long)local_e0 + lVar9 + 0x58) = iVar4 - (int)((ulong)(lVar18 + lVar17) >> 0x1f);
      *(int *)((long)local_e0 + lVar9 + 0x5c) = iVar13 - (int)((ulong)(lVar20 - lVar21) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa0 + lVar9) = iVar4 - (int)((ulong)(lVar18 - lVar17) >> 0x1f);
      *(int *)(&stack0xffffffffffffffa4 + lVar9) = iVar13 - (int)((ulong)(lVar20 + lVar21) >> 0x1f);
      lVar9 = lVar9 + 8;
      piVar12 = piVar12 + 6;
    }
    piVar12 = (int *)(lVar10 + (long)iVar6 * 8);
    iVar6 = local_e0[8] + local_e0[2];
    iVar16 = local_e0[9] + local_e0[3];
    iVar14 = local_e0[6] + local_e0[4];
    iVar1 = local_e0[7] + local_e0[5];
    *piVar12 = iVar14 + iVar6 + local_e0[0];
    piVar12[1] = iVar1 + iVar16 + local_e0[1];
    lVar9 = (long)(int)DAT_01af77b0;
    lVar10 = (long)(int)DAT_01af77b8;
    lVar17 = DAT_01af77b0 >> 0x20;
    lVar18 = DAT_01af77b8 >> 0x20;
    iVar11 = (int)((ulong)((lVar17 * (local_e0[5] - local_e0[7]) + 0x40000000) -
                          lVar18 * (local_e0[3] - local_e0[9])) >> 0x1f);
    iVar3 = (int)((ulong)((lVar17 * (local_e0[4] - local_e0[6]) + 0x40000000) -
                         lVar18 * (local_e0[2] - local_e0[8])) >> 0x1f);
    iVar15 = (int)(lVar18 * (local_e0[5] - local_e0[7]) + lVar17 * (local_e0[3] - local_e0[9]) +
                   0x40000000U >> 0x1f);
    iVar7 = (int)(lVar18 * (local_e0[4] - local_e0[6]) + lVar17 * (local_e0[2] - local_e0[8]) +
                  0x40000000U >> 0x1f);
    iVar13 = (int)((ulong)((lVar9 * iVar14 + 0x40000000) - lVar10 * iVar6) >> 0x1f);
    iVar4 = (int)((ulong)((lVar9 * iVar1 + 0x40000000) - lVar10 * iVar16) >> 0x1f);
    iVar14 = (int)((ulong)((lVar9 * iVar6 + 0x40000000) - lVar10 * iVar14) >> 0x1f);
    iVar6 = (int)((ulong)((lVar9 * iVar16 + 0x40000000) - lVar10 * iVar1) >> 0x1f);
    piVar12[lVar19 * 0xc] = iVar15 + local_e0[0] + iVar14;
    (piVar12 + lVar19 * 0xc)[1] = (local_e0[1] - iVar7) + iVar6;
    piVar12[lVar19 * 0x18] = (local_e0[0] - iVar11) + iVar13;
    (piVar12 + lVar19 * 0x18)[1] = iVar3 + local_e0[1] + iVar4;
    piVar12[lVar19 * 6] = iVar11 + local_e0[0] + iVar13;
    (piVar12 + lVar19 * 6)[1] = (local_e0[1] - iVar3) + iVar4;
    piVar12[lVar19 * 0x12] = (iVar14 - iVar15) + local_e0[0];
    (piVar12 + lVar19 * 0x12)[1] = iVar6 + iVar7 + local_e0[1];
    iVar6 = local_e0[0x12] + local_e0[0xc];
    iVar16 = local_e0[0x13] + local_e0[0xd];
    iVar14 = local_e0[0x10] + local_e0[0xe];
    iVar1 = local_e0[0x11] + local_e0[0xf];
    piVar12[lVar19 * 0x14] = iVar14 + iVar6 + local_e0[10];
    (piVar12 + lVar19 * 0x14)[1] = iVar1 + iVar16 + local_e0[0xb];
    lVar17 = (long)(int)DAT_01af77b0;
    lVar18 = (long)(int)DAT_01af77b8;
    lVar9 = DAT_01af77b0 >> 0x20;
    lVar10 = DAT_01af77b8 >> 0x20;
    iVar4 = (int)((ulong)((lVar9 * (local_e0[0xf] - local_e0[0x11]) + 0x40000000) -
                         lVar10 * (local_e0[0xd] - local_e0[0x13])) >> 0x1f);
    iVar3 = (int)((ulong)((lVar9 * (local_e0[0xe] - local_e0[0x10]) + 0x40000000) -
                         lVar10 * (local_e0[0xc] - local_e0[0x12])) >> 0x1f);
    iVar11 = (int)(lVar10 * (local_e0[0xf] - local_e0[0x11]) +
                   lVar9 * (local_e0[0xd] - local_e0[0x13]) + 0x40000000U >> 0x1f);
    iVar13 = (int)(lVar10 * (local_e0[0xe] - local_e0[0x10]) +
                   lVar9 * (local_e0[0xc] - local_e0[0x12]) + 0x40000000U >> 0x1f);
    iVar7 = (int)((ulong)((lVar17 * iVar14 + 0x40000000) - lVar18 * iVar6) >> 0x1f);
    iVar15 = (int)((ulong)((lVar17 * iVar1 + 0x40000000) - lVar18 * iVar16) >> 0x1f);
    iVar6 = (int)((ulong)((lVar17 * iVar6 + 0x40000000) - lVar18 * iVar14) >> 0x1f);
    iVar16 = (int)((ulong)((lVar17 * iVar16 + 0x40000000) - lVar18 * iVar1) >> 0x1f);
    piVar12[lVar19 * 2] = iVar11 + local_e0[10] + iVar6;
    (piVar12 + lVar19 * 2)[1] = (local_e0[0xb] - iVar13) + iVar16;
    piVar12[lVar19 * 0xe] = (local_e0[10] - iVar4) + iVar7;
    (piVar12 + lVar19 * 0xe)[1] = iVar3 + local_e0[0xb] + iVar15;
    piVar12[lVar19 * 0x1a] = iVar4 + local_e0[10] + iVar7;
    (piVar12 + lVar19 * 0x1a)[1] = (local_e0[0xb] - iVar3) + iVar15;
    piVar12[lVar19 * 8] = (iVar6 - iVar11) + local_e0[10];
    (piVar12 + lVar19 * 8)[1] = iVar16 + iVar13 + local_e0[0xb];
    iVar6 = local_e0[0x1c] + local_e0[0x16];
    iVar16 = local_e0[0x1d] + local_e0[0x17];
    iVar14 = local_e0[0x1a] + local_e0[0x18];
    iVar1 = local_e0[0x1b] + local_e0[0x19];
    piVar12[lVar19 * 10] = iVar14 + iVar6 + local_e0[0x14];
    (piVar12 + lVar19 * 10)[1] = iVar1 + iVar16 + local_e0[0x15];
    lVar17 = (long)(int)DAT_01af77b0;
    lVar18 = (long)(int)DAT_01af77b8;
    lVar9 = DAT_01af77b0 >> 0x20;
    lVar10 = DAT_01af77b8 >> 0x20;
    iVar4 = (int)(lVar10 * (local_e0[0x19] - local_e0[0x1b]) +
                  lVar9 * (local_e0[0x17] - local_e0[0x1d]) + 0x40000000U >> 0x1f);
    iVar7 = (int)((ulong)((lVar17 * iVar6 + 0x40000000) - lVar18 * iVar14) >> 0x1f);
    piVar12[lVar19 * 0x16] = iVar4 + local_e0[0x14] + iVar7;
    iVar3 = (int)(lVar10 * (local_e0[0x18] - local_e0[0x1a]) +
                  lVar9 * (local_e0[0x16] - local_e0[0x1c]) + 0x40000000U >> 0x1f);
    iVar11 = (int)((ulong)((lVar17 * iVar16 + 0x40000000) - lVar18 * iVar1) >> 0x1f);
    (piVar12 + lVar19 * 0x16)[1] = (local_e0[0x15] - iVar3) + iVar11;
    iVar13 = (int)((ulong)((lVar9 * (local_e0[0x19] - local_e0[0x1b]) + 0x40000000) -
                          lVar10 * (local_e0[0x17] - local_e0[0x1d])) >> 0x1f);
    iVar14 = (int)((ulong)((lVar17 * iVar14 + 0x40000000) - lVar18 * iVar6) >> 0x1f);
    piVar12[lVar19 * 4] = (local_e0[0x14] - iVar13) + iVar14;
    iVar6 = (int)((ulong)((lVar9 * (local_e0[0x18] - local_e0[0x1a]) + 0x40000000) -
                         lVar10 * (local_e0[0x16] - local_e0[0x1c])) >> 0x1f);
    iVar16 = (int)((ulong)((lVar17 * iVar1 + 0x40000000) - lVar18 * iVar16) >> 0x1f);
    (piVar12 + lVar19 * 4)[1] = iVar6 + local_e0[0x15] + iVar16;
    piVar12[lVar19 * 0x10] = iVar13 + local_e0[0x14] + iVar14;
    (piVar12 + lVar19 * 0x10)[1] = (local_e0[0x15] - iVar6) + iVar16;
    piVar12[lVar19 * 0x1c] = (iVar7 - iVar4) + local_e0[0x14];
    (piVar12 + lVar19 * 0x1c)[1] = iVar11 + iVar3 + local_e0[0x15];
    piVar23 = piVar23 + 0xf;
  }
  lVar9 = 0x10;
  lVar5 = 0;
  while (lVar9 = lVar9 + -1, lVar9 != 0) {
    (*pcVar8)(*(long *)(param_1 + 0x18) + lVar5);
    lVar5 = lVar5 + lVar19 * 8;
  }
  for (lVar5 = 0; lVar5 < lVar19 * 0xf; lVar5 = lVar5 + 1) {
    *(undefined8 *)(param_2 + lVar5 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar22[(int)(uVar2 * 0xf) + lVar5] * 8);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


