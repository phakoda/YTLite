/* Decompiled from supplied 5.2.2 arm package. VA 0x26fc7c. FUN_0026fc7c */

void FUN_0026fc7c(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  double *pdVar9;
  double *pdVar10;
  int *piVar11;
  int *piVar12;
  long lVar13;
  long lVar14;
  int *piVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double local_248 [60];
  long local_68;
  
  param_4 = param_4 >> 3;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = *(uint *)(param_1 + 4);
  lVar14 = (long)(int)uVar3;
  lVar13 = *(long *)(param_1 + 0x10);
  piVar15 = *(int **)(param_1 + 0x20);
  pcVar4 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar12 = piVar15;
  for (lVar7 = 0; lVar7 < lVar14; lVar7 = lVar7 + 1) {
    piVar11 = piVar12;
    for (lVar5 = 0; lVar5 != 0xf0; lVar5 = lVar5 + 0x10) {
      iVar8 = *piVar11;
      dVar17 = *(double *)
                (param_3 + (long)(int)(uVar3 * 0x1e + -1) * param_4 * 8 + (long)iVar8 * param_4 * -8
                );
      dVar21 = *(double *)(param_3 + (long)iVar8 * param_4 * 8);
      pdVar9 = (double *)(lVar13 + (long)(iVar8 >> 1) * 0x10);
      dVar19 = *pdVar9;
      dVar22 = pdVar9[1];
      *(double *)((long)local_248 + lVar5) = dVar17 * dVar19 - dVar21 * dVar22;
      *(double *)((long)local_248 + lVar5 + 8) = dVar17 * dVar22 + dVar21 * dVar19;
      piVar11 = piVar11 + 1;
    }
    lVar6 = *(long *)(param_1 + 0x18);
    iVar8 = *(int *)(*(long *)(param_1 + 0x28) + lVar7 * 4);
    pdVar9 = local_248;
    lVar5 = -0x60;
    while (lVar5 + 0x10 != 0) {
      dVar16 = pdVar9[1];
      dVar18 = pdVar9[2] + pdVar9[4];
      dVar19 = pdVar9[3] + pdVar9[5];
      dVar21 = _ff_cos_53_double * (pdVar9[3] - pdVar9[5]);
      dVar17 = DAT_019d3708 * (pdVar9[2] - pdVar9[4]);
      dVar22 = *pdVar9 - DAT_019d3710 * dVar18;
      dVar20 = dVar16 - DAT_019d3710 * dVar19;
      *(double *)((long)local_248 + lVar5 + 0x150) = *pdVar9 + dVar18;
      *(double *)((long)local_248 + lVar5 + 0x158) = dVar19 + dVar16;
      *(double *)((long)local_248 + lVar5 + 0x1a0) = dVar21 + dVar22;
      *(double *)((long)local_248 + lVar5 + 0x1a8) = dVar20 - dVar17;
      *(double *)(&stack0xffffffffffffffa8 + lVar5) = dVar22 - dVar21;
      *(double *)(&stack0xffffffffffffffb0 + lVar5) = dVar17 + dVar20;
      pdVar9 = pdVar9 + 6;
      lVar5 = lVar5 + 0x10;
    }
    pdVar9 = (double *)(lVar6 + (long)iVar8 * 0x10);
    dVar16 = local_248[0x20] + local_248[0x26];
    dVar18 = local_248[0x21] + local_248[0x27];
    dVar20 = local_248[0x22] + local_248[0x24];
    *pdVar9 = dVar20 + dVar16 + local_248[0x1e];
    dVar23 = local_248[0x23] + local_248[0x25];
    pdVar9[1] = dVar23 + dVar18 + local_248[0x1f];
    dVar22 = DAT_019d3738;
    dVar19 = DAT_019d3730;
    dVar21 = DAT_019d3728;
    dVar17 = DAT_019d3720;
    dVar24 = dVar16 * DAT_019d3720 - dVar20 * DAT_019d3730;
    dVar26 = dVar18 * DAT_019d3720 - dVar23 * DAT_019d3730;
    dVar25 = (local_248[0x21] - local_248[0x27]) * DAT_019d3728 +
             (local_248[0x23] - local_248[0x25]) * DAT_019d3738;
    dVar27 = (local_248[0x20] - local_248[0x26]) * DAT_019d3728 +
             (local_248[0x22] - local_248[0x24]) * DAT_019d3738;
    pdVar9[lVar14 * 0xc] = local_248[0x1e] + dVar24 + dVar25;
    (pdVar9 + lVar14 * 0xc)[1] = local_248[0x1f] + (dVar26 - dVar27);
    dVar16 = dVar20 * dVar17 - dVar16 * dVar19;
    dVar19 = dVar23 * dVar17 - dVar18 * dVar19;
    dVar17 = (local_248[0x23] - local_248[0x25]) * dVar21 -
             (local_248[0x21] - local_248[0x27]) * dVar22;
    dVar21 = (local_248[0x22] - local_248[0x24]) * dVar21 -
             (local_248[0x20] - local_248[0x26]) * dVar22;
    pdVar9[lVar14 * 0x18] = local_248[0x1e] + (dVar16 - dVar17);
    (pdVar9 + lVar14 * 0x18)[1] = local_248[0x1f] + dVar19 + dVar21;
    pdVar9[lVar14 * 6] = local_248[0x1e] + dVar16 + dVar17;
    (pdVar9 + lVar14 * 6)[1] = local_248[0x1f] + (dVar19 - dVar21);
    pdVar9[lVar14 * 0x12] = local_248[0x1e] + (dVar24 - dVar25);
    (pdVar9 + lVar14 * 0x12)[1] = local_248[0x1f] + dVar26 + dVar27;
    dVar16 = local_248[0x2a] + local_248[0x30];
    dVar18 = local_248[0x2c] + local_248[0x2e];
    pdVar9[lVar14 * 0x14] = dVar18 + dVar16 + local_248[0x28];
    dVar20 = local_248[0x2b] + local_248[0x31];
    dVar23 = local_248[0x2d] + local_248[0x2f];
    (pdVar9 + lVar14 * 0x14)[1] = dVar23 + dVar20 + local_248[0x29];
    dVar22 = DAT_019d3738;
    dVar19 = DAT_019d3730;
    dVar21 = DAT_019d3728;
    dVar17 = DAT_019d3720;
    dVar24 = dVar16 * DAT_019d3720 - dVar18 * DAT_019d3730;
    dVar26 = dVar20 * DAT_019d3720 - dVar23 * DAT_019d3730;
    dVar25 = (local_248[0x2b] - local_248[0x31]) * DAT_019d3728 +
             (local_248[0x2d] - local_248[0x2f]) * DAT_019d3738;
    dVar27 = (local_248[0x2a] - local_248[0x30]) * DAT_019d3728 +
             (local_248[0x2c] - local_248[0x2e]) * DAT_019d3738;
    pdVar9[lVar14 * 2] = local_248[0x28] + dVar24 + dVar25;
    (pdVar9 + lVar14 * 2)[1] = local_248[0x29] + (dVar26 - dVar27);
    dVar18 = dVar18 * dVar17 - dVar16 * dVar19;
    dVar16 = dVar23 * dVar17 - dVar20 * dVar19;
    dVar19 = (local_248[0x2d] - local_248[0x2f]) * dVar21 -
             (local_248[0x2b] - local_248[0x31]) * dVar22;
    dVar17 = (local_248[0x2c] - local_248[0x2e]) * dVar21 -
             (local_248[0x2a] - local_248[0x30]) * dVar22;
    pdVar9[lVar14 * 0xe] = local_248[0x28] + (dVar18 - dVar19);
    (pdVar9 + lVar14 * 0xe)[1] = local_248[0x29] + dVar16 + dVar17;
    pdVar9[lVar14 * 0x1a] = local_248[0x28] + dVar18 + dVar19;
    (pdVar9 + lVar14 * 0x1a)[1] = local_248[0x29] + (dVar16 - dVar17);
    pdVar9[lVar14 * 8] = local_248[0x28] + (dVar24 - dVar25);
    (pdVar9 + lVar14 * 8)[1] = local_248[0x29] + dVar26 + dVar27;
    dVar17 = local_248[0x34] + local_248[0x3a];
    dVar21 = local_248[0x35] + local_248[0x3b];
    dVar19 = local_248[0x36] + local_248[0x38];
    pdVar9[lVar14 * 10] = dVar19 + dVar17 + local_248[0x32];
    dVar22 = local_248[0x37] + local_248[0x39];
    (pdVar9 + lVar14 * 10)[1] = dVar22 + dVar21 + local_248[0x33];
    dVar16 = dVar19 * DAT_019d3720;
    dVar26 = dVar17 * DAT_019d3730;
    dVar18 = dVar22 * DAT_019d3720;
    dVar27 = dVar21 * DAT_019d3730;
    dVar20 = (local_248[0x37] - local_248[0x39]) * DAT_019d3728;
    dVar25 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3738;
    dVar23 = (local_248[0x36] - local_248[0x38]) * DAT_019d3728;
    dVar24 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3738;
    dVar17 = dVar17 * DAT_019d3720 - dVar19 * DAT_019d3730;
    dVar19 = dVar21 * DAT_019d3720 - dVar22 * DAT_019d3730;
    dVar21 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3728 +
             (local_248[0x37] - local_248[0x39]) * DAT_019d3738;
    dVar22 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3728 +
             (local_248[0x36] - local_248[0x38]) * DAT_019d3738;
    pdVar9[lVar14 * 0x16] = local_248[0x32] + dVar17 + dVar21;
    (pdVar9 + lVar14 * 0x16)[1] = local_248[0x33] + (dVar19 - dVar22);
    dVar16 = dVar16 - dVar26;
    dVar18 = dVar18 - dVar27;
    dVar20 = dVar20 - dVar25;
    dVar23 = dVar23 - dVar24;
    pdVar9[lVar14 * 4] = local_248[0x32] + (dVar16 - dVar20);
    (pdVar9 + lVar14 * 4)[1] = local_248[0x33] + dVar18 + dVar23;
    pdVar9[lVar14 * 0x10] = local_248[0x32] + dVar16 + dVar20;
    (pdVar9 + lVar14 * 0x10)[1] = local_248[0x33] + (dVar18 - dVar23);
    pdVar9[lVar14 * 0x1c] = local_248[0x32] + (dVar17 - dVar21);
    (pdVar9 + lVar14 * 0x1c)[1] = local_248[0x33] + dVar19 + dVar22;
    piVar12 = piVar12 + 0xf;
  }
  iVar8 = (int)(uVar3 * 0xf) >> 1;
  lVar5 = 0x10;
  lVar7 = 0;
  while (lVar5 = lVar5 + -1, lVar5 != 0) {
    (*pcVar4)(*(long *)(param_1 + 0x18) + lVar7);
    lVar7 = lVar7 + lVar14 * 0x10;
  }
  lVar5 = (long)iVar8;
  pdVar9 = (double *)(param_2 + (long)iVar8 * 0x10 + 8);
  pdVar10 = (double *)(lVar13 + (long)iVar8 * 0x10 + 8);
  for (lVar7 = 0; iVar8 = iVar8 + -1, lVar7 < lVar5; lVar7 = lVar7 + 1) {
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) + (long)piVar15[lVar14 * 0xf + (long)iVar8] * 0x10);
    pdVar2 = (double *)
             (*(long *)(param_1 + 0x18) + (long)piVar15[lVar5 + (int)(uVar3 * 0xf) + lVar7] * 0x10);
    dVar17 = *pdVar1;
    dVar21 = pdVar1[1];
    pdVar1 = (double *)(lVar13 + (long)iVar8 * 0x10);
    dVar19 = pdVar1[1];
    dVar22 = *pdVar2;
    dVar16 = pdVar2[1];
    pdVar2 = (double *)(param_2 + (long)iVar8 * 0x10);
    *pdVar2 = dVar21 * dVar19 - dVar17 * *pdVar1;
    *pdVar9 = dVar21 * *pdVar1 + dVar17 * dVar19;
    dVar17 = *pdVar10;
    pdVar9[-1] = dVar16 * dVar17 - dVar22 * pdVar10[-1];
    pdVar9 = pdVar9 + 2;
    pdVar2[1] = dVar16 * pdVar10[-1] + dVar22 * dVar17;
    pdVar10 = pdVar10 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


