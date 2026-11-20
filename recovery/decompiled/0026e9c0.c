/* Decompiled from supplied 5.2.2 arm package. VA 0x26e9c0. FUN_0026e9c0 */

void FUN_0026e9c0(long param_1,undefined8 *param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  int *piVar6;
  double *pdVar7;
  long lVar8;
  code *pcVar9;
  int *piVar10;
  int *piVar11;
  long lVar12;
  undefined8 uVar13;
  double dVar14;
  double dVar15;
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
  double local_248 [60];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar1 = *(uint *)(param_1 + 4);
  lVar8 = (long)(int)uVar1;
  piVar10 = *(int **)(param_1 + 0x20);
  pcVar9 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar1 | 1)) * 8);
  piVar11 = piVar10;
  for (lVar4 = 0; lVar4 < lVar8; lVar4 = lVar4 + 1) {
    piVar6 = piVar11;
    for (lVar5 = 0; lVar5 != 0xf0; lVar5 = lVar5 + 0x10) {
      puVar3 = (undefined8 *)(param_3 + (long)*piVar6 * 0x10);
      uVar13 = *puVar3;
      *(undefined8 *)((long)local_248 + lVar5 + 8) = puVar3[1];
      *(undefined8 *)((long)local_248 + lVar5) = uVar13;
      piVar6 = piVar6 + 1;
    }
    lVar12 = *(long *)(param_1 + 0x18);
    iVar2 = *(int *)(*(long *)(param_1 + 0x28) + lVar4 * 4);
    pdVar7 = local_248;
    lVar5 = -0x60;
    while (lVar5 + 0x10 != 0) {
      dVar14 = pdVar7[1];
      dVar16 = pdVar7[2] + pdVar7[4];
      dVar17 = pdVar7[3] + pdVar7[5];
      dVar19 = _ff_cos_53_double * (pdVar7[3] - pdVar7[5]);
      dVar15 = DAT_019d3708 * (pdVar7[2] - pdVar7[4]);
      dVar20 = *pdVar7 - DAT_019d3710 * dVar16;
      dVar18 = dVar14 - DAT_019d3710 * dVar17;
      *(double *)((long)local_248 + lVar5 + 0x150) = *pdVar7 + dVar16;
      *(double *)((long)local_248 + lVar5 + 0x158) = dVar17 + dVar14;
      *(double *)((long)local_248 + lVar5 + 0x1a0) = dVar19 + dVar20;
      *(double *)((long)local_248 + lVar5 + 0x1a8) = dVar18 - dVar15;
      *(double *)(&stack0xffffffffffffffa8 + lVar5) = dVar20 - dVar19;
      *(double *)(&stack0xffffffffffffffb0 + lVar5) = dVar15 + dVar18;
      pdVar7 = pdVar7 + 6;
      lVar5 = lVar5 + 0x10;
    }
    pdVar7 = (double *)(lVar12 + (long)iVar2 * 0x10);
    dVar14 = local_248[0x20] + local_248[0x26];
    dVar16 = local_248[0x21] + local_248[0x27];
    dVar18 = local_248[0x22] + local_248[0x24];
    *pdVar7 = dVar18 + dVar14 + local_248[0x1e];
    dVar21 = local_248[0x23] + local_248[0x25];
    pdVar7[1] = dVar21 + dVar16 + local_248[0x1f];
    dVar20 = DAT_019d3738;
    dVar17 = DAT_019d3730;
    dVar19 = DAT_019d3728;
    dVar15 = DAT_019d3720;
    dVar22 = dVar14 * DAT_019d3720 - dVar18 * DAT_019d3730;
    dVar24 = dVar16 * DAT_019d3720 - dVar21 * DAT_019d3730;
    dVar23 = (local_248[0x21] - local_248[0x27]) * DAT_019d3728 +
             (local_248[0x23] - local_248[0x25]) * DAT_019d3738;
    dVar25 = (local_248[0x20] - local_248[0x26]) * DAT_019d3728 +
             (local_248[0x22] - local_248[0x24]) * DAT_019d3738;
    pdVar7[lVar8 * 0xc] = local_248[0x1e] + dVar22 + dVar23;
    (pdVar7 + lVar8 * 0xc)[1] = local_248[0x1f] + (dVar24 - dVar25);
    dVar14 = dVar18 * dVar15 - dVar14 * dVar17;
    dVar17 = dVar21 * dVar15 - dVar16 * dVar17;
    dVar15 = (local_248[0x23] - local_248[0x25]) * dVar19 -
             (local_248[0x21] - local_248[0x27]) * dVar20;
    dVar19 = (local_248[0x22] - local_248[0x24]) * dVar19 -
             (local_248[0x20] - local_248[0x26]) * dVar20;
    pdVar7[lVar8 * 0x18] = local_248[0x1e] + (dVar14 - dVar15);
    (pdVar7 + lVar8 * 0x18)[1] = local_248[0x1f] + dVar17 + dVar19;
    pdVar7[lVar8 * 6] = local_248[0x1e] + dVar14 + dVar15;
    (pdVar7 + lVar8 * 6)[1] = local_248[0x1f] + (dVar17 - dVar19);
    pdVar7[lVar8 * 0x12] = local_248[0x1e] + (dVar22 - dVar23);
    (pdVar7 + lVar8 * 0x12)[1] = local_248[0x1f] + dVar24 + dVar25;
    dVar14 = local_248[0x2a] + local_248[0x30];
    dVar16 = local_248[0x2c] + local_248[0x2e];
    pdVar7[lVar8 * 0x14] = dVar16 + dVar14 + local_248[0x28];
    dVar18 = local_248[0x2b] + local_248[0x31];
    dVar21 = local_248[0x2d] + local_248[0x2f];
    (pdVar7 + lVar8 * 0x14)[1] = dVar21 + dVar18 + local_248[0x29];
    dVar20 = DAT_019d3738;
    dVar17 = DAT_019d3730;
    dVar19 = DAT_019d3728;
    dVar15 = DAT_019d3720;
    dVar22 = dVar14 * DAT_019d3720 - dVar16 * DAT_019d3730;
    dVar24 = dVar18 * DAT_019d3720 - dVar21 * DAT_019d3730;
    dVar23 = (local_248[0x2b] - local_248[0x31]) * DAT_019d3728 +
             (local_248[0x2d] - local_248[0x2f]) * DAT_019d3738;
    dVar25 = (local_248[0x2a] - local_248[0x30]) * DAT_019d3728 +
             (local_248[0x2c] - local_248[0x2e]) * DAT_019d3738;
    pdVar7[lVar8 * 2] = local_248[0x28] + dVar22 + dVar23;
    (pdVar7 + lVar8 * 2)[1] = local_248[0x29] + (dVar24 - dVar25);
    dVar16 = dVar16 * dVar15 - dVar14 * dVar17;
    dVar14 = dVar21 * dVar15 - dVar18 * dVar17;
    dVar17 = (local_248[0x2d] - local_248[0x2f]) * dVar19 -
             (local_248[0x2b] - local_248[0x31]) * dVar20;
    dVar15 = (local_248[0x2c] - local_248[0x2e]) * dVar19 -
             (local_248[0x2a] - local_248[0x30]) * dVar20;
    pdVar7[lVar8 * 0xe] = local_248[0x28] + (dVar16 - dVar17);
    (pdVar7 + lVar8 * 0xe)[1] = local_248[0x29] + dVar14 + dVar15;
    pdVar7[lVar8 * 0x1a] = local_248[0x28] + dVar16 + dVar17;
    (pdVar7 + lVar8 * 0x1a)[1] = local_248[0x29] + (dVar14 - dVar15);
    pdVar7[lVar8 * 8] = local_248[0x28] + (dVar22 - dVar23);
    (pdVar7 + lVar8 * 8)[1] = local_248[0x29] + dVar24 + dVar25;
    dVar15 = local_248[0x34] + local_248[0x3a];
    dVar19 = local_248[0x35] + local_248[0x3b];
    dVar17 = local_248[0x36] + local_248[0x38];
    pdVar7[lVar8 * 10] = dVar17 + dVar15 + local_248[0x32];
    dVar20 = local_248[0x37] + local_248[0x39];
    (pdVar7 + lVar8 * 10)[1] = dVar20 + dVar19 + local_248[0x33];
    dVar14 = dVar17 * DAT_019d3720;
    dVar24 = dVar15 * DAT_019d3730;
    dVar16 = dVar20 * DAT_019d3720;
    dVar25 = dVar19 * DAT_019d3730;
    dVar18 = (local_248[0x37] - local_248[0x39]) * DAT_019d3728;
    dVar23 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3738;
    dVar21 = (local_248[0x36] - local_248[0x38]) * DAT_019d3728;
    dVar22 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3738;
    dVar15 = dVar15 * DAT_019d3720 - dVar17 * DAT_019d3730;
    dVar17 = dVar19 * DAT_019d3720 - dVar20 * DAT_019d3730;
    dVar19 = (local_248[0x35] - local_248[0x3b]) * DAT_019d3728 +
             (local_248[0x37] - local_248[0x39]) * DAT_019d3738;
    dVar20 = (local_248[0x34] - local_248[0x3a]) * DAT_019d3728 +
             (local_248[0x36] - local_248[0x38]) * DAT_019d3738;
    pdVar7[lVar8 * 0x16] = local_248[0x32] + dVar15 + dVar19;
    (pdVar7 + lVar8 * 0x16)[1] = local_248[0x33] + (dVar17 - dVar20);
    dVar14 = dVar14 - dVar24;
    dVar16 = dVar16 - dVar25;
    dVar18 = dVar18 - dVar23;
    dVar21 = dVar21 - dVar22;
    pdVar7[lVar8 * 4] = local_248[0x32] + (dVar14 - dVar18);
    (pdVar7 + lVar8 * 4)[1] = local_248[0x33] + dVar16 + dVar21;
    pdVar7[lVar8 * 0x10] = local_248[0x32] + dVar14 + dVar18;
    (pdVar7 + lVar8 * 0x10)[1] = local_248[0x33] + (dVar16 - dVar21);
    pdVar7[lVar8 * 0x1c] = local_248[0x32] + (dVar15 - dVar19);
    (pdVar7 + lVar8 * 0x1c)[1] = local_248[0x33] + dVar17 + dVar20;
    piVar11 = piVar11 + 0xf;
  }
  lVar5 = 0x10;
  lVar4 = 0;
  while (lVar5 = lVar5 + -1, lVar5 != 0) {
    (*pcVar9)(*(long *)(param_1 + 0x18) + lVar4);
    lVar4 = lVar4 + lVar8 * 0x10;
  }
  for (lVar4 = 0; lVar4 < lVar8 * 0xf; lVar4 = lVar4 + 1) {
    puVar3 = (undefined8 *)
             (*(long *)(param_1 + 0x18) + (long)piVar10[(int)(uVar1 * 0xf) + lVar4] * 0x10);
    uVar13 = *puVar3;
    param_2[1] = puVar3[1];
    *param_2 = uVar13;
    param_2 = param_2 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


