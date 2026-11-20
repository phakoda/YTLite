/* Decompiled from supplied 5.2.2 arm package. VA 0x270308. FUN_00270308 */

void FUN_00270308(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
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
  double *pdVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  int *piVar17;
  int *piVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double local_248 [60];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar5 = *(uint *)(param_1 + 4);
  lVar15 = (long)(int)uVar5;
  lVar16 = *(long *)(param_1 + 0x10);
  piVar17 = *(int **)(param_1 + 0x20);
  iVar14 = uVar5 * 0xf;
  iVar12 = uVar5 * 0x2d + -1;
  pcVar8 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar5 | 1)) * 8);
  piVar18 = piVar17;
  for (lVar7 = 0; lVar7 < lVar15; lVar7 = lVar7 + 1) {
    piVar6 = piVar18;
    for (lVar9 = 0; lVar9 != 0xf0; lVar9 = lVar9 + 0x10) {
      iVar4 = *piVar6;
      if (iVar4 < iVar14) {
        dVar24 = *(double *)(param_3 + (long)(int)(iVar4 + uVar5 * 0x2d) * 8);
        dVar21 = *(double *)(param_3 + (long)((iVar14 + -1) - iVar4) * 8);
        dVar19 = -*(double *)(param_3 + (long)(iVar12 - iVar4) * 8);
      }
      else {
        dVar19 = *(double *)(param_3 + (long)(int)(iVar4 + uVar5 * -0xf) * 8);
        dVar24 = *(double *)(param_3 + (long)(iVar12 - iVar4) * 8);
        dVar21 = -*(double *)(param_3 + (long)(int)((uVar5 * 0x4b + -1) - iVar4) * 8);
      }
      dVar21 = dVar21 - *(double *)(param_3 + (long)(iVar4 + iVar14) * 8);
      pdVar13 = (double *)(lVar16 + (long)(iVar4 >> 1) * 0x10);
      dVar20 = *pdVar13;
      dVar23 = pdVar13[1];
      *(double *)((long)local_248 + lVar9) = dVar21 * dVar23 + (dVar19 - dVar24) * dVar20;
      *(double *)((long)local_248 + lVar9 + 8) = dVar21 * dVar20 - (dVar19 - dVar24) * dVar23;
      piVar6 = piVar6 + 1;
    }
    lVar10 = *(long *)(param_1 + 0x18);
    iVar4 = *(int *)(*(long *)(param_1 + 0x28) + lVar7 * 4);
    lVar9 = -0x60;
    pdVar13 = local_248;
    while (lVar9 + 0x10 != 0) {
      dVar23 = pdVar13[1];
      dVar22 = pdVar13[2] + pdVar13[4];
      dVar24 = pdVar13[3] + pdVar13[5];
      dVar19 = _ff_cos_53_double * (pdVar13[3] - pdVar13[5]);
      dVar21 = DAT_019d3708 * (pdVar13[2] - pdVar13[4]);
      dVar20 = *pdVar13 - DAT_019d3710 * dVar22;
      dVar25 = dVar23 - DAT_019d3710 * dVar24;
      *(double *)((long)local_248 + lVar9 + 0x150) = *pdVar13 + dVar22;
      *(double *)((long)local_248 + lVar9 + 0x158) = dVar24 + dVar23;
      *(double *)((long)local_248 + lVar9 + 0x1a0) = dVar19 + dVar20;
      *(double *)((long)local_248 + lVar9 + 0x1a8) = dVar25 - dVar21;
      *(double *)(&stack0xffffffffffffffa8 + lVar9) = dVar20 - dVar19;
      *(double *)(&stack0xffffffffffffffb0 + lVar9) = dVar21 + dVar25;
      lVar9 = lVar9 + 0x10;
      pdVar13 = pdVar13 + 6;
    }
    pdVar13 = (double *)(lVar10 + (long)iVar4 * 0x10);
    dVar23 = local_248[0x20] + local_248[0x26];
    dVar22 = local_248[0x21] + local_248[0x27];
    dVar25 = local_248[0x22] + local_248[0x24];
    *pdVar13 = dVar25 + dVar23 + local_248[0x1e];
    dVar26 = local_248[0x23] + local_248[0x25];
    pdVar13[1] = dVar26 + dVar22 + local_248[0x1f];
    dVar20 = DAT_019d3738;
    dVar24 = DAT_019d3730;
    dVar19 = DAT_019d3728;
    dVar21 = DAT_019d3720;
    dVar27 = dVar23 * DAT_019d3720 - dVar25 * DAT_019d3730;
    dVar29 = dVar22 * DAT_019d3720 - dVar26 * DAT_019d3730;
    dVar28 = (local_248[0x21] - local_248[0x27]) * DAT_019d3728 +
             (local_248[0x23] - local_248[0x25]) * DAT_019d3738;
    dVar30 = (local_248[0x20] - local_248[0x26]) * DAT_019d3728 +
             (local_248[0x22] - local_248[0x24]) * DAT_019d3738;
    pdVar13[lVar15 * 0xc] = local_248[0x1e] + dVar27 + dVar28;
    (pdVar13 + lVar15 * 0xc)[1] = local_248[0x1f] + (dVar29 - dVar30);
    dVar23 = dVar25 * dVar21 - dVar23 * dVar24;
    dVar24 = dVar26 * dVar21 - dVar22 * dVar24;
    dVar21 = (local_248[0x23] - local_248[0x25]) * dVar19 -
             (local_248[0x21] - local_248[0x27]) * dVar20;
    dVar19 = (local_248[0x22] - local_248[0x24]) * dVar19 -
             (local_248[0x20] - local_248[0x26]) * dVar20;
    pdVar13[lVar15 * 0x18] = local_248[0x1e] + (dVar23 - dVar21);
    (pdVar13 + lVar15 * 0x18)[1] = local_248[0x1f] + dVar24 + dVar19;
    pdVar13[lVar15 * 6] = local_248[0x1e] + dVar23 + dVar21;
    (pdVar13 + lVar15 * 6)[1] = local_248[0x1f] + (dVar24 - dVar19);
    pdVar13[lVar15 * 0x12] = local_248[0x1e] + (dVar27 - dVar28);
    (pdVar13 + lVar15 * 0x12)[1] = local_248[0x1f] + dVar29 + dVar30;
    dVar23 = local_248[0x2a] + local_248[0x30];
    dVar22 = local_248[0x2c] + local_248[0x2e];
    pdVar13[lVar15 * 0x14] = dVar22 + dVar23 + local_248[0x28];
    dVar25 = local_248[0x2b] + local_248[0x31];
    dVar26 = local_248[0x2d] + local_248[0x2f];
    (pdVar13 + lVar15 * 0x14)[1] = dVar26 + dVar25 + local_248[0x29];
    dVar20 = DAT_019d3738;
    dVar24 = DAT_019d3730;
    dVar19 = DAT_019d3728;
    dVar21 = DAT_019d3720;
    dVar27 = dVar23 * DAT_019d3720 - dVar22 * DAT_019d3730;
    dVar29 = dVar25 * DAT_019d3720 - dVar26 * DAT_019d3730;
    dVar28 = (local_248[0x2b] - local_248[0x31]) * DAT_019d3728 +
             (local_248[0x2d] - local_248[0x2f]) * DAT_019d3738;
    dVar30 = (local_248[0x2a] - local_248[0x30]) * DAT_019d3728 +
             (local_248[0x2c] - local_248[0x2e]) * DAT_019d3738;
    pdVar13[lVar15 * 2] = local_248[0x28] + dVar27 + dVar28;
    (pdVar13 + lVar15 * 2)[1] = local_248[0x29] + (dVar29 - dVar30);
    dVar22 = dVar22 * dVar21 - dVar23 * dVar24;
    dVar23 = dVar26 * dVar21 - dVar25 * dVar24;
    dVar24 = (local_248[0x2d] - local_248[0x2f]) * dVar19 -
             (local_248[0x2b] - local_248[0x31]) * dVar20;
    dVar21 = (local_248[0x2c] - local_248[0x2e]) * dVar19 -
             (local_248[0x2a] - local_248[0x30]) * dVar20;
    pdVar13[lVar15 * 0xe] = local_248[0x28] + (dVar22 - dVar24);
    (pdVar13 + lVar15 * 0xe)[1] = local_248[0x29] + dVar23 + dVar21;
    pdVar13[lVar15 * 0x1a] = local_248[0x28] + dVar22 + dVar24;
    (pdVar13 + lVar15 * 0x1a)[1] = local_248[0x29] + (dVar23 - dVar21);
    pdVar13[lVar15 * 8] = local_248[0x28] + (dVar27 - dVar28);
    (pdVar13 + lVar15 * 8)[1] = local_248[0x29] + dVar29 + dVar30;
    dVar21 = local_248[0x34] + local_248[0x3a];
    dVar19 = local_248[0x35] + local_248[0x3b];
    dVar24 = local_248[0x36] + local_248[0x38];
    pdVar13[lVar15 * 10] = dVar24 + dVar21 + local_248[0x32];
    dVar20 = local_248[0x37] + local_248[0x39];
    (pdVar13 + lVar15 * 10)[1] = dVar20 + dVar19 + local_248[0x33];
    dVar23 = dVar24 * DAT_019d3720;
    dVar29 = dVar21 * DAT_019d3730;
    dVar22 = dVar20 * DAT_019d3720;
    dVar30 = dVar19 * DAT_019d3730;
    dVar25 = (local_248[0x37] - local_248[0x39]) * DAT_019d3728;
    dVar28 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3738;
    dVar26 = (local_248[0x36] - local_248[0x38]) * DAT_019d3728;
    dVar27 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3738;
    dVar21 = dVar21 * DAT_019d3720 - dVar24 * DAT_019d3730;
    dVar24 = dVar19 * DAT_019d3720 - dVar20 * DAT_019d3730;
    dVar19 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3728 +
             (local_248[0x37] - local_248[0x39]) * DAT_019d3738;
    dVar20 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3728 +
             (local_248[0x36] - local_248[0x38]) * DAT_019d3738;
    pdVar13[lVar15 * 0x16] = local_248[0x32] + dVar21 + dVar19;
    (pdVar13 + lVar15 * 0x16)[1] = local_248[0x33] + (dVar24 - dVar20);
    dVar23 = dVar23 - dVar29;
    dVar22 = dVar22 - dVar30;
    dVar25 = dVar25 - dVar28;
    dVar26 = dVar26 - dVar27;
    pdVar13[lVar15 * 4] = local_248[0x32] + (dVar23 - dVar25);
    (pdVar13 + lVar15 * 4)[1] = local_248[0x33] + dVar22 + dVar26;
    pdVar13[lVar15 * 0x10] = local_248[0x32] + dVar23 + dVar25;
    (pdVar13 + lVar15 * 0x10)[1] = local_248[0x33] + (dVar22 - dVar26);
    pdVar13[lVar15 * 0x1c] = local_248[0x32] + (dVar21 - dVar19);
    (pdVar13 + lVar15 * 0x1c)[1] = local_248[0x33] + dVar24 + dVar20;
    piVar18 = piVar18 + 0xf;
  }
  uVar3 = iVar14 >> 1;
  param_4 = param_4 >> 3;
  lVar9 = 0x10;
  lVar7 = 0;
  while (lVar9 = lVar9 + -1, lVar9 != 0) {
    (*pcVar8)(*(long *)(param_1 + 0x18) + lVar7);
    lVar7 = lVar7 + lVar15 * 0x10;
  }
  uVar11 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar3 << 4;
  lVar9 = lVar16 + -8;
  iVar12 = uVar3 * 2;
  lVar16 = lVar16 + 8;
  lVar7 = (long)(int)uVar3 + (long)(int)(uVar5 * 0xf);
  lVar10 = -4;
  iVar14 = iVar12;
  for (lVar15 = 0; iVar14 = iVar14 + -2, lVar15 < (int)uVar3; lVar15 = lVar15 + 1) {
    pdVar13 = (double *)
              (*(long *)(param_1 + 0x18) + (long)*(int *)((long)piVar17 + lVar10 + lVar7 * 4) * 0x10
              );
    pdVar1 = (double *)(*(long *)(param_1 + 0x18) + (long)piVar17[lVar7 + lVar15] * 0x10);
    pdVar2 = (double *)(lVar16 + uVar11);
    dVar21 = *pdVar1;
    dVar19 = pdVar1[1];
    dVar24 = *pdVar13;
    dVar20 = pdVar13[1];
    *(double *)(param_2 + ((long)iVar14 * param_4 + param_4) * 8) =
         dVar21 * *pdVar2 - dVar19 * pdVar2[-1];
    pdVar13 = (double *)(lVar9 + uVar11);
    lVar9 = lVar9 + -0x10;
    *(double *)(param_2 + (long)iVar12 * param_4 * 8) = dVar21 * pdVar2[-1] + dVar19 * *pdVar2;
    *(double *)(param_2 + ((long)iVar12 * param_4 + param_4) * 8) =
         dVar24 * *pdVar13 - dVar20 * pdVar13[-1];
    lVar10 = lVar10 + -4;
    iVar12 = iVar12 + 2;
    *(double *)(param_2 + (long)iVar14 * param_4 * 8) = dVar24 * pdVar13[-1] + dVar20 * *pdVar13;
    lVar16 = lVar16 + 0x10;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


